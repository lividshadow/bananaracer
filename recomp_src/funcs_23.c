#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void hud_main_hub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2C08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A2C0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A2C10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A2C14: jal         0x80066450
    // 0x800A2C18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800A2C18: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A2C1C: bne         $v0, $zero, L_800A2CB0
    if (ctx->r2 != 0) {
        // 0x800A2C20: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A2CB0;
    }
    // 0x800A2C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A2C24: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A2C28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A2C2C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x800A2C30: jal         0x80068748
    // 0x800A2C34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A2C34: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_1:
    // 0x800A2C38: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A2C3C: jal         0x800A76E8
    // 0x800A2C40: nop

    hud_balloons(rdram, ctx);
        goto after_2;
    // 0x800A2C40: nop

    after_2:
    // 0x800A2C44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800A2C48: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800A2C4C: jal         0x800A3DCC
    // 0x800A2C50: nop

    hud_speedometre(rdram, ctx);
        goto after_3;
    // 0x800A2C50: nop

    after_3:
    // 0x800A2C54: jal         0x8009F1C4
    // 0x800A2C58: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_4;
    // 0x800A2C58: nop

    after_4:
    // 0x800A2C5C: beq         $v0, $zero, L_800A2CA4
    if (ctx->r2 == 0) {
        // 0x800A2C60: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800A2CA4;
    }
    // 0x800A2C60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A2C64: lw          $a3, 0x729C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X729C);
    // 0x800A2C68: nop

    // 0x800A2C6C: addiu       $a3, $a3, 0x720
    ctx->r7 = ADD32(ctx->r7, 0X720);
    // 0x800A2C70: jal         0x8006ECD0
    // 0x800A2C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x800A2C74: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_5:
    // 0x800A2C78: lb          $t8, 0x71($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X71);
    // 0x800A2C7C: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800A2C80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A2C84: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A2C88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A2C8C: addiu       $t9, $t8, 0x38
    ctx->r25 = ADD32(ctx->r24, 0X38);
    // 0x800A2C90: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A2C94: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A2C98: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A2C9C: jal         0x800AAB5C
    // 0x800A2CA0: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A2CA0: sh          $t9, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r25;
    after_6:
L_800A2CA4:
    // 0x800A2CA4: jal         0x80068748
    // 0x800A2CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_7;
    // 0x800A2CA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A2CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A2CB0:
    // 0x800A2CB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A2CB4: jr          $ra
    // 0x800A2CB8: nop

    return;
    // 0x800A2CB8: nop

;}
RECOMP_FUNC void obj_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800101AC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800101B0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800101B4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800101B8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800101BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800101C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800101C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800101C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800101CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800101D0: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800101D4: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x800101D8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800101DC: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x800101E0: beq         $t7, $zero, L_8001020C
    if (ctx->r15 == 0) {
        // 0x800101E4: nop
    
            goto L_8001020C;
    }
    // 0x800101E4: nop

    // 0x800101E8: jal         0x800B25A0
    // 0x800101EC: nop

    particle_deallocate(rdram, ctx);
        goto after_0;
    // 0x800101EC: nop

    after_0:
    // 0x800101F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800101F4: addiu       $v0, $v0, -0x4C1C
    ctx->r2 = ADD32(ctx->r2, -0X4C1C);
    // 0x800101F8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800101FC: nop

    // 0x80010200: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80010204: b           L_8001096C
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_8001096C;
    // 0x80010208: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8001020C:
    // 0x8001020C: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x80010210: nop

    // 0x80010214: beq         $v1, $zero, L_800102E4
    if (ctx->r3 == 0) {
        // 0x80010218: nop
    
            goto L_800102E4;
    }
    // 0x80010218: nop

    // 0x8001021C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80010220: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010224: blez        $t0, L_800102E4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010228: nop
    
            goto L_800102E4;
    }
    // 0x80010228: nop

    // 0x8001022C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010230: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_80010234:
    // 0x80010234: lw          $s1, 0x4($t1)
    ctx->r17 = MEM_W(ctx->r9, 0X4);
    // 0x80010238: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001023C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x80010240: nop

    // 0x80010244: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x80010248: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x8001024C: bne         $a0, $zero, L_80010288
    if (ctx->r4 != 0) {
        // 0x80010250: nop
    
            goto L_80010288;
    }
    // 0x80010250: nop

    // 0x80010254: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80010258: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x80010258: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8001025C:
    // 0x8001025C: lw          $t2, 0x68($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X68);
    // 0x80010260: nop

    // 0x80010264: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x80010268: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x8001026C: jal         0x80060180
    // 0x80010270: nop

    free_3d_model(rdram, ctx);
        goto after_1;
    // 0x80010270: nop

    after_1:
    // 0x80010274: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010278: bne         $s3, $s2, L_8001025C
    if (ctx->r19 != ctx->r18) {
        // 0x8001027C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001025C;
    }
    // 0x8001027C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010280: b           L_800102B8
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
        goto L_800102B8;
    // 0x80010284: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_80010288:
    // 0x80010288: blez        $s2, L_800102B4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001028C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800102B4;
    }
    // 0x8001028C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010290:
    // 0x80010290: lw          $t4, 0x68($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X68);
    // 0x80010294: nop

    // 0x80010298: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x8001029C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800102A0: jal         0x8007D100
    // 0x800102A4: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800102A4: nop

    after_2:
    // 0x800102A8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800102AC: bne         $s3, $s2, L_80010290
    if (ctx->r19 != ctx->r18) {
        // 0x800102B0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010290;
    }
    // 0x800102B0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800102B4:
    // 0x800102B4: lh          $a0, 0x2C($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2C);
L_800102B8:
    // 0x800102B8: jal         0x8000C844
    // 0x800102BC: nop

    try_free_object_header(rdram, ctx);
        goto after_3;
    // 0x800102BC: nop

    after_3:
    // 0x800102C0: jal         0x80071380
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x800102C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800102C8: lw          $v1, 0x60($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X60);
    // 0x800102CC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800102D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800102D4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800102D8: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800102DC: bne         $at, $zero, L_80010234
    if (ctx->r1 != 0) {
        // 0x800102E0: addu        $t1, $v1, $s4
        ctx->r9 = ADD32(ctx->r3, ctx->r20);
            goto L_80010234;
    }
    // 0x800102E0: addu        $t1, $v1, $s4
    ctx->r9 = ADD32(ctx->r3, ctx->r20);
L_800102E4:
    // 0x800102E4: lw          $t7, 0x70($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X70);
    // 0x800102E8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800102EC: beq         $t7, $zero, L_80010344
    if (ctx->r15 == 0) {
        // 0x800102F0: nop
    
            goto L_80010344;
    }
    // 0x800102F0: nop

    // 0x800102F4: lw          $t8, 0x40($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X40);
    // 0x800102F8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800102FC: lb          $t9, 0x5A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X5A);
    // 0x80010300: nop

    // 0x80010304: blez        $t9, L_80010344
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80010308: nop
    
            goto L_80010344;
    }
    // 0x80010308: nop

    // 0x8001030C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_80010310:
    // 0x80010310: lw          $t0, 0x70($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X70);
    // 0x80010314: nop

    // 0x80010318: addu        $t1, $t0, $s4
    ctx->r9 = ADD32(ctx->r8, ctx->r20);
    // 0x8001031C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80010320: jal         0x80032BEC
    // 0x80010324: nop

    light_remove(rdram, ctx);
        goto after_5;
    // 0x80010324: nop

    after_5:
    // 0x80010328: lw          $t2, 0x40($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X40);
    // 0x8001032C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80010330: lb          $t3, 0x5A($t2)
    ctx->r11 = MEM_B(ctx->r10, 0X5A);
    // 0x80010334: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80010338: slt         $at, $s5, $t3
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001033C: bne         $at, $zero, L_80010310
    if (ctx->r1 != 0) {
        // 0x80010340: nop
    
            goto L_80010310;
    }
    // 0x80010340: nop

L_80010344:
    // 0x80010344: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010348: nop

    // 0x8001034C: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x80010350: sltiu       $at, $t4, 0x74
    ctx->r1 = ctx->r12 < 0X74 ? 1 : 0;
    // 0x80010354: beq         $at, $zero, L_800105F8
    if (ctx->r1 == 0) {
        // 0x80010358: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800105F8;
    }
    // 0x80010358: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8001035C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80010360: addu        $at, $at, $t4
    gpr jr_addend_8001036C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80010364: lw          $t4, 0x57E0($at)
    ctx->r12 = ADD32(ctx->r1, 0X57E0);
    // 0x80010368: nop

    // 0x8001036C: jr          $t4
    // 0x80010370: nop

    switch (jr_addend_8001036C >> 2) {
        case 0: goto L_80010374; break;
        case 1: goto L_800105F8; break;
        case 2: goto L_800105F8; break;
        case 3: goto L_800105F8; break;
        case 4: goto L_80010400; break;
        case 5: goto L_800105F8; break;
        case 6: goto L_800105F8; break;
        case 7: goto L_800105F8; break;
        case 8: goto L_800105F8; break;
        case 9: goto L_800105F8; break;
        case 10: goto L_800105F8; break;
        case 11: goto L_800105F8; break;
        case 12: goto L_800105F8; break;
        case 13: goto L_800105F8; break;
        case 14: goto L_800105F8; break;
        case 15: goto L_800105F8; break;
        case 16: goto L_800105F8; break;
        case 17: goto L_80010400; break;
        case 18: goto L_800105F8; break;
        case 19: goto L_800105F8; break;
        case 20: goto L_800105F8; break;
        case 21: goto L_800105F8; break;
        case 22: goto L_800105F8; break;
        case 23: goto L_800105F8; break;
        case 24: goto L_800105F8; break;
        case 25: goto L_800105F8; break;
        case 26: goto L_800105F8; break;
        case 27: goto L_800105F8; break;
        case 28: goto L_800105F8; break;
        case 29: goto L_800105F8; break;
        case 30: goto L_800105F8; break;
        case 31: goto L_800105F8; break;
        case 32: goto L_800104C0; break;
        case 33: goto L_800105F8; break;
        case 34: goto L_800105F8; break;
        case 35: goto L_800105A8; break;
        case 36: goto L_800105F8; break;
        case 37: goto L_800105F8; break;
        case 38: goto L_800105F8; break;
        case 39: goto L_800105F8; break;
        case 40: goto L_800105F8; break;
        case 41: goto L_800105F8; break;
        case 42: goto L_800105D0; break;
        case 43: goto L_800105E4; break;
        case 44: goto L_800105F8; break;
        case 45: goto L_800105F8; break;
        case 46: goto L_800105F8; break;
        case 47: goto L_800105F8; break;
        case 48: goto L_800104D8; break;
        case 49: goto L_800105F8; break;
        case 50: goto L_800105F8; break;
        case 51: goto L_800105F8; break;
        case 52: goto L_800105F8; break;
        case 53: goto L_800105F8; break;
        case 54: goto L_800105F8; break;
        case 55: goto L_800105F8; break;
        case 56: goto L_800105F8; break;
        case 57: goto L_800105F8; break;
        case 58: goto L_800104AC; break;
        case 59: goto L_800105F8; break;
        case 60: goto L_800105F8; break;
        case 61: goto L_800105F8; break;
        case 62: goto L_800105F8; break;
        case 63: goto L_800105F8; break;
        case 64: goto L_800105F8; break;
        case 65: goto L_800105F8; break;
        case 66: goto L_800105A8; break;
        case 67: goto L_800105F8; break;
        case 68: goto L_800105F8; break;
        case 69: goto L_800105F8; break;
        case 70: goto L_800105F8; break;
        case 71: goto L_800105F8; break;
        case 72: goto L_800105F8; break;
        case 73: goto L_800105F8; break;
        case 74: goto L_800105F8; break;
        case 75: goto L_800105F8; break;
        case 76: goto L_800105F8; break;
        case 77: goto L_800105F8; break;
        case 78: goto L_800105F8; break;
        case 79: goto L_800105F8; break;
        case 80: goto L_800105F8; break;
        case 81: goto L_800105F8; break;
        case 82: goto L_80010508; break;
        case 83: goto L_800105F8; break;
        case 84: goto L_80010374; break;
        case 85: goto L_800105F8; break;
        case 86: goto L_800105F8; break;
        case 87: goto L_800105F8; break;
        case 88: goto L_800105F8; break;
        case 89: goto L_800105F8; break;
        case 90: goto L_800105F8; break;
        case 91: goto L_800105F8; break;
        case 92: goto L_800105F8; break;
        case 93: goto L_800105F8; break;
        case 94: goto L_800105F8; break;
        case 95: goto L_8001047C; break;
        case 96: goto L_8001047C; break;
        case 97: goto L_800105F8; break;
        case 98: goto L_800105F8; break;
        case 99: goto L_800105F8; break;
        case 100: goto L_8001047C; break;
        case 101: goto L_8001047C; break;
        case 102: goto L_800105F8; break;
        case 103: goto L_800105F8; break;
        case 104: goto L_800105F8; break;
        case 105: goto L_800105F8; break;
        case 106: goto L_800105F8; break;
        case 107: goto L_800105F8; break;
        case 108: goto L_800105F8; break;
        case 109: goto L_800105F8; break;
        case 110: goto L_800105F8; break;
        case 111: goto L_800105F8; break;
        case 112: goto L_800105F8; break;
        case 113: goto L_800105F8; break;
        case 114: goto L_800105F8; break;
        case 115: goto L_8001044C; break;
        default: switch_error(__func__, 0x8001036C, 0x800E57E0);
    }
    // 0x80010370: nop

L_80010374:
    // 0x80010374: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80010378: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001037C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80010380: blez        $v1, L_800103F8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010384: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800103F8;
    }
    // 0x80010384: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80010388: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001038C: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
L_80010390:
    // 0x80010390: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80010394: lw          $t5, -0x4C28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4C28);
    // 0x80010398: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001039C: addu        $t6, $t5, $s4
    ctx->r14 = ADD32(ctx->r13, ctx->r20);
    // 0x800103A0: lw          $s1, 0x0($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X0);
    // 0x800103A4: nop

    // 0x800103A8: lh          $t7, 0x48($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X48);
    // 0x800103AC: nop

    // 0x800103B0: bne         $a0, $t7, L_800103E8
    if (ctx->r4 != ctx->r15) {
        // 0x800103B4: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103B4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103B8: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x800103BC: nop

    // 0x800103C0: lw          $t8, 0x100($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X100);
    // 0x800103C4: nop

    // 0x800103C8: bne         $s6, $t8, L_800103E8
    if (ctx->r22 != ctx->r24) {
        // 0x800103CC: slt         $at, $s5, $v1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800103E8;
    }
    // 0x800103CC: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800103D0: sw          $zero, 0x100($v0)
    MEM_W(0X100, ctx->r2) = 0;
    // 0x800103D4: sb          $a1, 0xFD($v0)
    MEM_B(0XFD, ctx->r2) = ctx->r5;
    // 0x800103D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800103DC: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800103E0: nop

    // 0x800103E4: slt         $at, $s5, $v1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r3) ? 1 : 0;
L_800103E8:
    // 0x800103E8: bne         $at, $zero, L_80010390
    if (ctx->r1 != 0) {
        // 0x800103EC: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80010390;
    }
    // 0x800103EC: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800103F0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800103F4: nop

L_800103F8:
    // 0x800103F8: b           L_800105FC
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800103FC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010400:
    // 0x80010400: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010404: nop

    // 0x80010408: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x8001040C: nop

    // 0x80010410: beq         $a0, $zero, L_80010444
    if (ctx->r4 == 0) {
        // 0x80010414: nop
    
            goto L_80010444;
    }
    // 0x80010414: nop

    // 0x80010418: jal         0x800096F8
    // 0x8001041C: nop

    audspat_point_stop(rdram, ctx);
        goto after_6;
    // 0x8001041C: nop

    after_6:
    // 0x80010420: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x80010424: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010428: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x8001042C: bne         $s4, $a1, L_80010444
    if (ctx->r20 != ctx->r5) {
        // 0x80010430: nop
    
            goto L_80010444;
    }
    // 0x80010430: nop

    // 0x80010434: jal         0x8003F11C
    // 0x80010438: nop

    decrease_rocket_sound_timer(rdram, ctx);
        goto after_7;
    // 0x80010438: nop

    after_7:
    // 0x8001043C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010440: nop

L_80010444:
    // 0x80010444: b           L_800105FC
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010448: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001044C:
    // 0x8001044C: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010450: nop

    // 0x80010454: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    // 0x80010458: nop

    // 0x8001045C: beq         $a0, $zero, L_80010474
    if (ctx->r4 == 0) {
        // 0x80010460: nop
    
            goto L_80010474;
    }
    // 0x80010460: nop

    // 0x80010464: jal         0x800096F8
    // 0x80010468: nop

    audspat_point_stop(rdram, ctx);
        goto after_8;
    // 0x80010468: nop

    after_8:
    // 0x8001046C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010470: nop

L_80010474:
    // 0x80010474: b           L_800105FC
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010478: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_8001047C:
    // 0x8001047C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010480: nop

    // 0x80010484: lw          $v1, 0x20($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X20);
    // 0x80010488: nop

    // 0x8001048C: beq         $v1, $zero, L_800104A4
    if (ctx->r3 == 0) {
        // 0x80010490: nop
    
            goto L_800104A4;
    }
    // 0x80010490: nop

    // 0x80010494: jal         0x800096F8
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    audspat_point_stop(rdram, ctx);
        goto after_9;
    // 0x80010498: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_9:
    // 0x8001049C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104A0: nop

L_800104A4:
    // 0x800104A4: b           L_800105FC
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104A8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104AC:
    // 0x800104AC: jal         0x800BF904
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    wavegen_destroy(rdram, ctx);
        goto after_10;
    // 0x800104B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_10:
    // 0x800104B4: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104B8: b           L_800105FC
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104BC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104C0:
    // 0x800104C0: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104C4: jal         0x80032BEC
    // 0x800104C8: nop

    light_remove(rdram, ctx);
        goto after_11;
    // 0x800104C8: nop

    after_11:
    // 0x800104CC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104D0: b           L_800105FC
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800104D4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800104D8:
    // 0x800104D8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800104DC: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800104E0: beq         $a0, $zero, L_80010500
    if (ctx->r4 == 0) {
        // 0x800104E4: nop
    
            goto L_80010500;
    }
    // 0x800104E4: nop

    // 0x800104E8: bne         $t9, $zero, L_80010500
    if (ctx->r25 != 0) {
        // 0x800104EC: nop
    
            goto L_80010500;
    }
    // 0x800104EC: nop

    // 0x800104F0: jal         0x8000FFB8
    // 0x800104F4: nop

    free_object(rdram, ctx);
        goto after_12;
    // 0x800104F4: nop

    after_12:
    // 0x800104F8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800104FC: nop

L_80010500:
    // 0x80010500: b           L_800105FC
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x80010504: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_80010508:
    // 0x80010508: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001050C: addiu       $a0, $a0, -0x4C80
    ctx->r4 = ADD32(ctx->r4, -0X4C80);
    // 0x80010510: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010514: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80010518: blez        $v1, L_80010554
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001051C: addiu       $s4, $zero, 0x12
        ctx->r20 = ADD32(0, 0X12);
            goto L_80010554;
    }
    // 0x8001051C: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
    // 0x80010520: lw          $t0, -0x4CA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4CA8);
    // 0x80010524: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80010528: beq         $s6, $t0, L_80010554
    if (ctx->r22 == ctx->r8) {
        // 0x8001052C: addiu       $v0, $v0, -0x4CA8
        ctx->r2 = ADD32(ctx->r2, -0X4CA8);
            goto L_80010554;
    }
    // 0x8001052C: addiu       $v0, $v0, -0x4CA8
    ctx->r2 = ADD32(ctx->r2, -0X4CA8);
L_80010530:
    // 0x80010530: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010534: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010538: beq         $at, $zero, L_80010554
    if (ctx->r1 == 0) {
        // 0x8001053C: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_80010554;
    }
    // 0x8001053C: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80010540: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80010544: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80010548: nop

    // 0x8001054C: bne         $s6, $t3, L_80010530
    if (ctx->r22 != ctx->r11) {
        // 0x80010550: nop
    
            goto L_80010530;
    }
    // 0x80010550: nop

L_80010554:
    // 0x80010554: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010558: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x8001055C: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_8001059C;
    }
    // 0x8001055C: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80010560: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80010564: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x80010568: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x8001056C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80010570: beq         $at, $zero, L_8001059C
    if (ctx->r1 == 0) {
        // 0x80010574: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001059C;
    }
    // 0x80010574: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80010578: addiu       $t6, $t6, -0x4CA8
    ctx->r14 = ADD32(ctx->r14, -0X4CA8);
    // 0x8001057C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x80010580: addu        $a0, $t7, $t6
    ctx->r4 = ADD32(ctx->r15, ctx->r14);
    // 0x80010584: addu        $v0, $t5, $t6
    ctx->r2 = ADD32(ctx->r13, ctx->r14);
L_80010588:
    // 0x80010588: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8001058C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80010590: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80010594: bne         $at, $zero, L_80010588
    if (ctx->r1 != 0) {
        // 0x80010598: sw          $t8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r24;
            goto L_80010588;
    }
    // 0x80010598: sw          $t8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r24;
L_8001059C:
    // 0x8001059C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105A0: b           L_800105FC
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
        goto L_800105FC;
    // 0x800105A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800105A8:
    // 0x800105A8: lw          $a0, 0x64($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X64);
    // 0x800105AC: nop

    // 0x800105B0: beq         $a0, $zero, L_800105C8
    if (ctx->r4 == 0) {
        // 0x800105B4: nop
    
            goto L_800105C8;
    }
    // 0x800105B4: nop

    // 0x800105B8: jal         0x80071380
    // 0x800105BC: nop

    mempool_free(rdram, ctx);
        goto after_13;
    // 0x800105BC: nop

    after_13:
    // 0x800105C0: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105C4: nop

L_800105C8:
    // 0x800105C8: b           L_800105FC
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105CC: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105D0:
    // 0x800105D0: jal         0x800ACDE0
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_remove(rdram, ctx);
        goto after_14;
    // 0x800105D4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_14:
    // 0x800105D8: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105DC: b           L_800105FC
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105E0: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105E4:
    // 0x800105E4: jal         0x800AD4F8
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    lensflare_override_remove(rdram, ctx);
        goto after_15;
    // 0x800105E8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_15:
    // 0x800105EC: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x800105F0: b           L_800105FC
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
        goto L_800105FC;
    // 0x800105F4: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105F8:
    // 0x800105F8: addiu       $s4, $zero, 0x12
    ctx->r20 = ADD32(0, 0X12);
L_800105FC:
    // 0x800105FC: slti        $at, $a1, 0xD
    ctx->r1 = SIGNED(ctx->r5) < 0XD ? 1 : 0;
    // 0x80010600: bne         $at, $zero, L_80010630
    if (ctx->r1 != 0) {
        // 0x80010604: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80010630;
    }
    // 0x80010604: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80010608: addiu       $t9, $v0, -0x32
    ctx->r25 = ADD32(ctx->r2, -0X32);
    // 0x8001060C: sltiu       $at, $t9, 0x46
    ctx->r1 = ctx->r25 < 0X46 ? 1 : 0;
    // 0x80010610: beq         $at, $zero, L_80010664
    if (ctx->r1 == 0) {
        // 0x80010614: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80010664;
    }
    // 0x80010614: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80010618: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001061C: addu        $at, $at, $t9
    gpr jr_addend_80010628 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80010620: lw          $t9, 0x59B0($at)
    ctx->r25 = ADD32(ctx->r1, 0X59B0);
    // 0x80010624: nop

    // 0x80010628: jr          $t9
    // 0x8001062C: nop

    switch (jr_addend_80010628 >> 2) {
        case 0: goto L_8001063C; break;
        case 1: goto L_8001063C; break;
        case 2: goto L_80010664; break;
        case 3: goto L_8001063C; break;
        case 4: goto L_8001063C; break;
        case 5: goto L_80010664; break;
        case 6: goto L_8001063C; break;
        case 7: goto L_80010664; break;
        case 8: goto L_80010664; break;
        case 9: goto L_80010664; break;
        case 10: goto L_80010664; break;
        case 11: goto L_80010664; break;
        case 12: goto L_80010664; break;
        case 13: goto L_80010664; break;
        case 14: goto L_80010664; break;
        case 15: goto L_80010664; break;
        case 16: goto L_80010664; break;
        case 17: goto L_80010664; break;
        case 18: goto L_80010664; break;
        case 19: goto L_80010664; break;
        case 20: goto L_8001063C; break;
        case 21: goto L_80010664; break;
        case 22: goto L_8001063C; break;
        case 23: goto L_80010664; break;
        case 24: goto L_80010664; break;
        case 25: goto L_80010664; break;
        case 26: goto L_80010664; break;
        case 27: goto L_80010664; break;
        case 28: goto L_80010664; break;
        case 29: goto L_80010664; break;
        case 30: goto L_8001063C; break;
        case 31: goto L_8001063C; break;
        case 32: goto L_80010664; break;
        case 33: goto L_80010664; break;
        case 34: goto L_8001063C; break;
        case 35: goto L_8001063C; break;
        case 36: goto L_8001063C; break;
        case 37: goto L_80010664; break;
        case 38: goto L_80010664; break;
        case 39: goto L_80010664; break;
        case 40: goto L_80010664; break;
        case 41: goto L_80010664; break;
        case 42: goto L_80010664; break;
        case 43: goto L_80010664; break;
        case 44: goto L_80010664; break;
        case 45: goto L_80010664; break;
        case 46: goto L_8001063C; break;
        case 47: goto L_8001063C; break;
        case 48: goto L_80010664; break;
        case 49: goto L_80010664; break;
        case 50: goto L_80010664; break;
        case 51: goto L_8001063C; break;
        case 52: goto L_8001063C; break;
        case 53: goto L_8001063C; break;
        case 54: goto L_8001063C; break;
        case 55: goto L_80010664; break;
        case 56: goto L_80010664; break;
        case 57: goto L_80010664; break;
        case 58: goto L_80010664; break;
        case 59: goto L_80010664; break;
        case 60: goto L_80010664; break;
        case 61: goto L_80010664; break;
        case 62: goto L_80010664; break;
        case 63: goto L_8001063C; break;
        case 64: goto L_80010664; break;
        case 65: goto L_8001063C; break;
        case 66: goto L_80010664; break;
        case 67: goto L_80010664; break;
        case 68: goto L_80010664; break;
        case 69: goto L_8001063C; break;
        default: switch_error(__func__, 0x80010628, 0x800E59B0);
    }
    // 0x8001062C: nop

L_80010630:
    // 0x80010630: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80010634: bne         $v0, $at, L_80010668
    if (ctx->r2 != ctx->r1) {
        // 0x80010638: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010638: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8001063C:
    // 0x8001063C: lw          $v0, 0x64($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X64);
    // 0x80010640: nop

    // 0x80010644: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80010648: nop

    // 0x8001064C: beq         $a0, $zero, L_80010668
    if (ctx->r4 == 0) {
        // 0x80010650: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80010668;
    }
    // 0x80010650: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80010654: jal         0x8000488C
    // 0x80010658: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x80010658: nop

    after_16:
    // 0x8001065C: lh          $a1, 0x48($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X48);
    // 0x80010660: nop

L_80010664:
    // 0x80010664: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80010668:
    // 0x80010668: bne         $a1, $at, L_800107F0
    if (ctx->r5 != ctx->r1) {
        // 0x8001066C: nop
    
            goto L_800107F0;
    }
    // 0x8001066C: nop

    // 0x80010670: lw          $s0, 0x64($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X64);
    // 0x80010674: nop

    // 0x80010678: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8001067C: nop

    // 0x80010680: beq         $v0, $zero, L_80010690
    if (ctx->r2 == 0) {
        // 0x80010684: nop
    
            goto L_80010690;
    }
    // 0x80010684: nop

    // 0x80010688: jal         0x8000488C
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_17;
    // 0x8001068C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_17:
L_80010690:
    // 0x80010690: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80010694: nop

    // 0x80010698: beq         $v0, $zero, L_800106A8
    if (ctx->r2 == 0) {
        // 0x8001069C: nop
    
            goto L_800106A8;
    }
    // 0x8001069C: nop

    // 0x800106A0: jal         0x8000488C
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_18;
    // 0x800106A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_18:
L_800106A8:
    // 0x800106A8: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x800106AC: nop

    // 0x800106B0: beq         $v0, $zero, L_800106C0
    if (ctx->r2 == 0) {
        // 0x800106B4: nop
    
            goto L_800106C0;
    }
    // 0x800106B4: nop

    // 0x800106B8: jal         0x8000488C
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_19;
    // 0x800106BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_19:
L_800106C0:
    // 0x800106C0: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800106C4: nop

    // 0x800106C8: beq         $v0, $zero, L_800106D8
    if (ctx->r2 == 0) {
        // 0x800106CC: nop
    
            goto L_800106D8;
    }
    // 0x800106CC: nop

    // 0x800106D0: jal         0x8000488C
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x800106D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_20:
L_800106D8:
    // 0x800106D8: lw          $v0, 0x20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X20);
    // 0x800106DC: nop

    // 0x800106E0: beq         $v0, $zero, L_800106F0
    if (ctx->r2 == 0) {
        // 0x800106E4: nop
    
            goto L_800106F0;
    }
    // 0x800106E4: nop

    // 0x800106E8: jal         0x8000488C
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_stop(rdram, ctx);
        goto after_21;
    // 0x800106EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
L_800106F0:
    // 0x800106F0: lw          $a0, 0x24($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X24);
    // 0x800106F4: nop

    // 0x800106F8: beq         $a0, $zero, L_80010708
    if (ctx->r4 == 0) {
        // 0x800106FC: nop
    
            goto L_80010708;
    }
    // 0x800106FC: nop

    // 0x80010700: jal         0x800096F8
    // 0x80010704: nop

    audspat_point_stop(rdram, ctx);
        goto after_22;
    // 0x80010704: nop

    after_22:
L_80010708:
    // 0x80010708: lw          $a0, 0x17C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X17C);
    // 0x8001070C: nop

    // 0x80010710: beq         $a0, $zero, L_80010720
    if (ctx->r4 == 0) {
        // 0x80010714: nop
    
            goto L_80010720;
    }
    // 0x80010714: nop

    // 0x80010718: jal         0x800096F8
    // 0x8001071C: nop

    audspat_point_stop(rdram, ctx);
        goto after_23;
    // 0x8001071C: nop

    after_23:
L_80010720:
    // 0x80010720: lw          $a0, 0x178($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X178);
    // 0x80010724: nop

    // 0x80010728: beq         $a0, $zero, L_80010738
    if (ctx->r4 == 0) {
        // 0x8001072C: nop
    
            goto L_80010738;
    }
    // 0x8001072C: nop

    // 0x80010730: jal         0x8000488C
    // 0x80010734: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80010734: nop

    after_24:
L_80010738:
    // 0x80010738: jal         0x80006AC8
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    racer_sound_free(rdram, ctx);
        goto after_25;
    // 0x8001073C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_25:
    // 0x80010740: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010744: addiu       $s5, $s5, -0x4C24
    ctx->r21 = ADD32(ctx->r21, -0X4C24);
    // 0x80010748: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x8001074C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80010750: blez        $t0, L_800107F0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80010754: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_800107F0;
    }
    // 0x80010754: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80010758: addiu       $s1, $zero, 0x4C
    ctx->r17 = ADD32(0, 0X4C);
L_8001075C:
    // 0x8001075C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80010760: lw          $t1, -0x4C28($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4C28);
    // 0x80010764: nop

    // 0x80010768: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8001076C: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x80010770: nop

    // 0x80010774: lh          $t3, 0x6($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X6);
    // 0x80010778: nop

    // 0x8001077C: andi        $t4, $t3, 0x8000
    ctx->r12 = ctx->r11 & 0X8000;
    // 0x80010780: beq         $t4, $zero, L_800107B0
    if (ctx->r12 == 0) {
        // 0x80010784: nop
    
            goto L_800107B0;
    }
    // 0x80010784: nop

    // 0x80010788: lw          $t5, 0x3C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X3C);
    // 0x8001078C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80010790: bne         $s6, $t5, L_800107B0
    if (ctx->r22 != ctx->r13) {
        // 0x80010794: nop
    
            goto L_800107B0;
    }
    // 0x80010794: nop

    // 0x80010798: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8001079C: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x800107A0: nop

    // 0x800107A4: addu        $t6, $t7, $s0
    ctx->r14 = ADD32(ctx->r15, ctx->r16);
    // 0x800107A8: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800107AC: nop

L_800107B0:
    // 0x800107B0: lh          $v0, 0x48($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X48);
    // 0x800107B4: nop

    // 0x800107B8: beq         $s4, $v0, L_800107D0
    if (ctx->r20 == ctx->r2) {
        // 0x800107BC: nop
    
            goto L_800107D0;
    }
    // 0x800107BC: nop

    // 0x800107C0: beq         $s1, $v0, L_800107D0
    if (ctx->r17 == ctx->r2) {
        // 0x800107C4: nop
    
            goto L_800107D0;
    }
    // 0x800107C4: nop

    // 0x800107C8: bne         $s2, $v0, L_800107D8
    if (ctx->r18 != ctx->r2) {
        // 0x800107CC: nop
    
            goto L_800107D8;
    }
    // 0x800107CC: nop

L_800107D0:
    // 0x800107D0: jal         0x8000FFB8
    // 0x800107D4: nop

    free_object(rdram, ctx);
        goto after_26;
    // 0x800107D4: nop

    after_26:
L_800107D8:
    // 0x800107D8: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x800107DC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800107E0: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800107E4: bne         $at, $zero, L_8001075C
    if (ctx->r1 != 0) {
        // 0x800107E8: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8001075C;
    }
    // 0x800107E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800107EC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800107F0:
    // 0x800107F0: lw          $v0, 0x50($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X50);
    // 0x800107F4: nop

    // 0x800107F8: beq         $v0, $zero, L_80010818
    if (ctx->r2 == 0) {
        // 0x800107FC: nop
    
            goto L_80010818;
    }
    // 0x800107FC: nop

    // 0x80010800: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80010804: nop

    // 0x80010808: beq         $a0, $zero, L_80010818
    if (ctx->r4 == 0) {
        // 0x8001080C: nop
    
            goto L_80010818;
    }
    // 0x8001080C: nop

    // 0x80010810: jal         0x8007B70C
    // 0x80010814: nop

    tex_free(rdram, ctx);
        goto after_27;
    // 0x80010814: nop

    after_27:
L_80010818:
    // 0x80010818: lw          $v0, 0x58($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X58);
    // 0x8001081C: nop

    // 0x80010820: beq         $v0, $zero, L_80010840
    if (ctx->r2 == 0) {
        // 0x80010824: nop
    
            goto L_80010840;
    }
    // 0x80010824: nop

    // 0x80010828: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8001082C: nop

    // 0x80010830: beq         $a0, $zero, L_80010840
    if (ctx->r4 == 0) {
        // 0x80010834: nop
    
            goto L_80010840;
    }
    // 0x80010834: nop

    // 0x80010838: jal         0x8007B70C
    // 0x8001083C: nop

    tex_free(rdram, ctx);
        goto after_28;
    // 0x8001083C: nop

    after_28:
L_80010840:
    // 0x80010840: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010844: nop

    // 0x80010848: lb          $a0, 0x53($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X53);
    // 0x8001084C: lb          $s2, 0x55($v0)
    ctx->r18 = MEM_B(ctx->r2, 0X55);
    // 0x80010850: bne         $a0, $zero, L_800108A0
    if (ctx->r4 != 0) {
        // 0x80010854: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800108A0;
    }
    // 0x80010854: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80010858: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001085C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x8001085C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80010860:
    // 0x80010860: lw          $t9, 0x68($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X68);
    // 0x80010864: nop

    // 0x80010868: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8001086C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80010870: nop

    // 0x80010874: beq         $v0, $zero, L_80010884
    if (ctx->r2 == 0) {
        // 0x80010878: nop
    
            goto L_80010884;
    }
    // 0x80010878: nop

    // 0x8001087C: jal         0x80060180
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_3d_model(rdram, ctx);
        goto after_29;
    // 0x80010880: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_29:
L_80010884:
    // 0x80010884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010888: bne         $s3, $s2, L_80010860
    if (ctx->r19 != ctx->r18) {
        // 0x8001088C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80010860;
    }
    // 0x8001088C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80010890: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010894: b           L_80010918
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x80010898: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
    // 0x8001089C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
L_800108A0:
    // 0x800108A0: bne         $a0, $at, L_800108E0
    if (ctx->r4 != ctx->r1) {
        // 0x800108A4: nop
    
            goto L_800108E0;
    }
    // 0x800108A4: nop

    // 0x800108A8: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108AC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108B0:
    // 0x800108B0: lw          $t1, 0x68($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X68);
    // 0x800108B4: nop

    // 0x800108B8: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800108BC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800108C0: jal         0x8007B70C
    // 0x800108C4: nop

    tex_free(rdram, ctx);
        goto after_30;
    // 0x800108C4: nop

    after_30:
    // 0x800108C8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800108CC: bne         $s3, $s2, L_800108B0
    if (ctx->r19 != ctx->r18) {
        // 0x800108D0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108B0;
    }
    // 0x800108D0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800108D4: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x800108D8: b           L_80010918
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
        goto L_80010918;
    // 0x800108DC: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_800108E0:
    // 0x800108E0: blez        $s2, L_80010914
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800108E4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80010914;
    }
    // 0x800108E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800108E8:
    // 0x800108E8: lw          $t3, 0x68($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X68);
    // 0x800108EC: nop

    // 0x800108F0: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800108F4: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x800108F8: jal         0x8007D100
    // 0x800108FC: nop

    sprite_free(rdram, ctx);
        goto after_31;
    // 0x800108FC: nop

    after_31:
    // 0x80010900: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010904: bne         $s3, $s2, L_800108E8
    if (ctx->r19 != ctx->r18) {
        // 0x80010908: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800108E8;
    }
    // 0x80010908: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001090C: lw          $v0, 0x40($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X40);
    // 0x80010910: nop

L_80010914:
    // 0x80010914: lb          $v1, 0x57($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X57);
L_80010918:
    // 0x80010918: nop

    // 0x8001091C: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010920: nop
    
            goto L_80010958;
    }
    // 0x80010920: nop

    // 0x80010924: blez        $v1, L_80010958
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80010928: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80010958;
    }
    // 0x80010928: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8001092C:
    // 0x8001092C: lw          $t5, 0x6C($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X6C);
    // 0x80010930: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x80010934: jal         0x800B27C0
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    emitter_cleanup(rdram, ctx);
        goto after_32;
    // 0x80010938: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
    after_32:
    // 0x8001093C: lw          $t6, 0x40($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X40);
    // 0x80010940: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010944: lb          $t8, 0x57($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X57);
    // 0x80010948: nop

    // 0x8001094C: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80010950: bne         $at, $zero, L_8001092C
    if (ctx->r1 != 0) {
        // 0x80010954: nop
    
            goto L_8001092C;
    }
    // 0x80010954: nop

L_80010958:
    // 0x80010958: lh          $a0, 0x2C($s6)
    ctx->r4 = MEM_H(ctx->r22, 0X2C);
    // 0x8001095C: jal         0x8000C844
    // 0x80010960: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x80010960: nop

    after_33:
    // 0x80010964: jal         0x80071380
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_34;
    // 0x80010968: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_34:
L_8001096C:
    // 0x8001096C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010970: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80010974: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80010978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001097C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80010980: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80010984: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80010988: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001098C: jr          $ra
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80010990: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void free_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FFB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FFBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FFC0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000FFC4: lh          $a0, 0x4A($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4A);
    // 0x8000FFC8: nop

    // 0x8000FFCC: ori         $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 | 0X8000;
    // 0x8000FFD0: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x8000FFD4: jal         0x800245E8
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x8000FFD8: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_0:
    // 0x8000FFDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000FFE0: addiu       $v0, $v0, -0x4BB8
    ctx->r2 = ADD32(ctx->r2, -0X4BB8);
    // 0x8000FFE4: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8000FFE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000FFEC: lw          $t1, -0x4BBC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BBC);
    // 0x8000FFF0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8000FFF4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000FFF8: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000FFFC: sw          $t0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r8;
    // 0x80010000: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80010004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80010008: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001000C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80010010: jr          $ra
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80010014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void set_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017EA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EAC: sh          $a0, -0x4BA8($at)
    MEM_H(-0X4BA8, ctx->r1) = ctx->r4;
    // 0x80017EB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EB4: jr          $ra
    // 0x80017EB8: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
    return;
    // 0x80017EB8: sw          $zero, -0x4CD4($at)
    MEM_W(-0X4CD4, ctx->r1) = 0;
;}
RECOMP_FUNC void alFxParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800641D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800641D8: bne         $a1, $at, L_800641E4
    if (ctx->r5 != ctx->r1) {
        // 0x800641DC: nop
    
            goto L_800641E4;
    }
    // 0x800641DC: nop

    // 0x800641E0: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
L_800641E4:
    // 0x800641E4: jr          $ra
    // 0x800641E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800641E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void get_loaded_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4878: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C487C: lw          $t7, -0x5260($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5260);
    // 0x800C4880: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800C4884: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C4888: beq         $at, $zero, L_800C48DC
    if (ctx->r1 == 0) {
        // 0x800C488C: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_800C48DC;
    }
    // 0x800C488C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800C4890: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C4894: lw          $t9, -0x525C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X525C);
    // 0x800C4898: sll         $t8, $a0, 10
    ctx->r24 = S32(ctx->r4 << 10);
    // 0x800C489C: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C48A0: lbu         $t0, 0x28($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X28);
    // 0x800C48A4: addiu       $a1, $t6, -0x20
    ctx->r5 = ADD32(ctx->r14, -0X20);
    // 0x800C48A8: beq         $t0, $zero, L_800C48DC
    if (ctx->r8 == 0) {
        // 0x800C48AC: andi        $t1, $a1, 0xFF
        ctx->r9 = ctx->r5 & 0XFF;
            goto L_800C48DC;
    }
    // 0x800C48AC: andi        $t1, $a1, 0xFF
    ctx->r9 = ctx->r5 & 0XFF;
    // 0x800C48B0: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800C48B4: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x800C48B8: lbu         $a0, 0x100($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X100);
    // 0x800C48BC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C48C0: beq         $a0, $at, L_800C48DC
    if (ctx->r4 == ctx->r1) {
        // 0x800C48C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C48DC;
    }
    // 0x800C48C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C48C8: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x800C48CC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800C48D0: lw          $v0, 0x80($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X80);
    // 0x800C48D4: jr          $ra
    // 0x800C48D8: nop

    return;
    // 0x800C48D8: nop

L_800C48DC:
    // 0x800C48DC: jr          $ra
    // 0x800C48E0: nop

    return;
    // 0x800C48E0: nop

;}
RECOMP_FUNC void menu_geometry_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800812BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800812C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800812C4: addiu       $v0, $v0, 0x2334
    ctx->r2 = ADD32(ctx->r2, 0X2334);
    // 0x800812C8: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x800812CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800812D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800812D4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800812D8: jr          $ra
    // 0x800812DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    return;
    // 0x800812DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void mempool_print_tags_screen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071D94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80071D98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80071D9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80071DA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071DA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80071DA8: jal         0x800B6814
    // 0x80071DAC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_0;
    // 0x80071DAC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_0:
    // 0x80071DB0: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071DB4: jal         0x80071C64
    // 0x80071DB8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_1;
    // 0x80071DB8: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_1:
    // 0x80071DBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DC0: addiu       $a0, $a0, 0x7AB8
    ctx->r4 = ADD32(ctx->r4, 0X7AB8);
    // 0x80071DC4: jal         0x800B643C
    // 0x80071DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_2;
    // 0x80071DC8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_2:
    // 0x80071DCC: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071DD0: jal         0x80071C64
    // 0x80071DD4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_3;
    // 0x80071DD4: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_3:
    // 0x80071DD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DDC: addiu       $a0, $a0, 0x7AC0
    ctx->r4 = ADD32(ctx->r4, 0X7AC0);
    // 0x80071DE0: jal         0x800B643C
    // 0x80071DE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_4;
    // 0x80071DE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80071DE8: jal         0x80071C64
    // 0x80071DEC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_5;
    // 0x80071DEC: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    after_5:
    // 0x80071DF0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071DF4: addiu       $a0, $a0, 0x7ACC
    ctx->r4 = ADD32(ctx->r4, 0X7ACC);
    // 0x80071DF8: jal         0x800B643C
    // 0x80071DFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_6;
    // 0x80071DFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x80071E00: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x80071E04: jal         0x80071C64
    // 0x80071E08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_7;
    // 0x80071E08: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_7:
    // 0x80071E0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E10: addiu       $a0, $a0, 0x7AD8
    ctx->r4 = ADD32(ctx->r4, 0X7AD8);
    // 0x80071E14: jal         0x800B643C
    // 0x80071E18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_8;
    // 0x80071E18: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x80071E1C: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x80071E20: jal         0x80071C64
    // 0x80071E24: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_9;
    // 0x80071E24: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_9:
    // 0x80071E28: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E2C: addiu       $a0, $a0, 0x7AE4
    ctx->r4 = ADD32(ctx->r4, 0X7AE4);
    // 0x80071E30: jal         0x800B643C
    // 0x80071E34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_10;
    // 0x80071E34: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_10:
    // 0x80071E38: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x80071E3C: jal         0x80071C64
    // 0x80071E40: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_11;
    // 0x80071E40: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_11:
    // 0x80071E44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E48: addiu       $a0, $a0, 0x7AF0
    ctx->r4 = ADD32(ctx->r4, 0X7AF0);
    // 0x80071E4C: jal         0x800B643C
    // 0x80071E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_12;
    // 0x80071E50: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80071E54: jal         0x80071C64
    // 0x80071E58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    get_memory_colour_tag_count(rdram, ctx);
        goto after_13;
    // 0x80071E58: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_13:
    // 0x80071E5C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E60: addiu       $a0, $a0, 0x7AFC
    ctx->r4 = ADD32(ctx->r4, 0X7AFC);
    // 0x80071E64: jal         0x800B643C
    // 0x80071E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_14;
    // 0x80071E68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x80071E6C: lui         $a0, 0x7F7F
    ctx->r4 = S32(0X7F7F << 16);
    // 0x80071E70: jal         0x80071C64
    // 0x80071E74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_15;
    // 0x80071E74: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_15:
    // 0x80071E78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E7C: addiu       $a0, $a0, 0x7B08
    ctx->r4 = ADD32(ctx->r4, 0X7B08);
    // 0x80071E80: jal         0x800B643C
    // 0x80071E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_16;
    // 0x80071E84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_16:
    // 0x80071E88: lui         $a0, 0xFF7F
    ctx->r4 = S32(0XFF7F << 16);
    // 0x80071E8C: jal         0x80071C64
    // 0x80071E90: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    get_memory_colour_tag_count(rdram, ctx);
        goto after_17;
    // 0x80071E90: ori         $a0, $a0, 0x7FFF
    ctx->r4 = ctx->r4 | 0X7FFF;
    after_17:
    // 0x80071E94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80071E98: addiu       $a0, $a0, 0x7B14
    ctx->r4 = ADD32(ctx->r4, 0X7B14);
    // 0x80071E9C: jal         0x800B643C
    // 0x80071EA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    render_printf(rdram, ctx);
        goto after_18;
    // 0x80071EA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_18:
    // 0x80071EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80071EA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80071EAC: jr          $ra
    // 0x80071EB0: nop

    return;
    // 0x80071EB0: nop

;}
RECOMP_FUNC void tex_disable_modes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B25C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B260: addiu       $v0, $v0, 0x6918
    ctx->r2 = ADD32(ctx->r2, 0X6918);
    // 0x8007B264: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007B268: nop

    // 0x8007B26C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8007B270: jr          $ra
    // 0x8007B274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8007B274: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void light_setup_colour_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032288: blez        $a2, L_800322D4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003228C: nop
    
            goto L_800322D4;
    }
    // 0x8003228C: nop

    // 0x80032290: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80032294: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032298: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8003229C: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x800322A0: sh          $a2, 0x3C($a0)
    MEM_H(0X3C, ctx->r4) = ctx->r6;
    // 0x800322A4: bne         $a2, $zero, L_800322B0
    if (ctx->r6 != 0) {
        // 0x800322A8: nop
    
            goto L_800322B0;
    }
    // 0x800322A8: nop

    // 0x800322AC: break       7
    do_break(2147689132);
L_800322B0:
    // 0x800322B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800322B4: bne         $a2, $at, L_800322C8
    if (ctx->r6 != ctx->r1) {
        // 0x800322B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800322C8;
    }
    // 0x800322B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800322BC: bne         $t8, $at, L_800322C8
    if (ctx->r24 != ctx->r1) {
        // 0x800322C0: nop
    
            goto L_800322C8;
    }
    // 0x800322C0: nop

    // 0x800322C4: break       6
    do_break(2147689156);
L_800322C8:
    // 0x800322C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800322CC: sw          $t9, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r25;
    // 0x800322D0: nop

L_800322D4:
    // 0x800322D4: lw          $v0, 0x10($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X10);
    // 0x800322D8: nop

    // 0x800322DC: blez        $v0, L_80032328
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800322E0: nop
    
            goto L_80032328;
    }
    // 0x800322E0: nop

    // 0x800322E4: lw          $t1, 0x20($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X20);
    // 0x800322E8: sll         $t0, $a3, 16
    ctx->r8 = S32(ctx->r7 << 16);
    // 0x800322EC: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x800322F0: div         $zero, $t2, $v0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r2)));
    // 0x800322F4: sh          $v0, 0x3E($a0)
    MEM_H(0X3E, ctx->r4) = ctx->r2;
    // 0x800322F8: bne         $v0, $zero, L_80032304
    if (ctx->r2 != 0) {
        // 0x800322FC: nop
    
            goto L_80032304;
    }
    // 0x800322FC: nop

    // 0x80032300: break       7
    do_break(2147689216);
L_80032304:
    // 0x80032304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032308: bne         $v0, $at, L_8003231C
    if (ctx->r2 != ctx->r1) {
        // 0x8003230C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8003231C;
    }
    // 0x8003230C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032310: bne         $t2, $at, L_8003231C
    if (ctx->r10 != ctx->r1) {
        // 0x80032314: nop
    
            goto L_8003231C;
    }
    // 0x80032314: nop

    // 0x80032318: break       6
    do_break(2147689240);
L_8003231C:
    // 0x8003231C: mflo        $t3
    ctx->r11 = lo;
    // 0x80032320: sw          $t3, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r11;
    // 0x80032324: nop

L_80032328:
    // 0x80032328: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003232C: lw          $t4, 0x14($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14);
    // 0x80032330: blez        $v0, L_8003237C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80032334: nop
    
            goto L_8003237C;
    }
    // 0x80032334: nop

    // 0x80032338: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8003233C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80032340: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x80032344: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80032348: sh          $v0, 0x40($a0)
    MEM_H(0X40, ctx->r4) = ctx->r2;
    // 0x8003234C: bne         $v0, $zero, L_80032358
    if (ctx->r2 != 0) {
        // 0x80032350: nop
    
            goto L_80032358;
    }
    // 0x80032350: nop

    // 0x80032354: break       7
    do_break(2147689300);
L_80032358:
    // 0x80032358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003235C: bne         $v0, $at, L_80032370
    if (ctx->r2 != ctx->r1) {
        // 0x80032360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80032370;
    }
    // 0x80032360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032364: bne         $t7, $at, L_80032370
    if (ctx->r15 != ctx->r1) {
        // 0x80032368: nop
    
            goto L_80032370;
    }
    // 0x80032368: nop

    // 0x8003236C: break       6
    do_break(2147689324);
L_80032370:
    // 0x80032370: mflo        $t8
    ctx->r24 = lo;
    // 0x80032374: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x80032378: nop

L_8003237C:
    // 0x8003237C: jr          $ra
    // 0x80032380: nop

    return;
    // 0x80032380: nop

;}
RECOMP_FUNC void load_tt_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059AB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059ABC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80059AC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059AC4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80059AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059ACC: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x80059AD0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059AD4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80059AD8: jal         0x80070EDC
    // 0x80059ADC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x80059ADC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_0:
    // 0x80059AE0: beq         $v0, $zero, L_80059B88
    if (ctx->r2 == 0) {
        // 0x80059AE4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80059B88;
    }
    // 0x80059AE4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80059AE8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059AEC: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80059AF0: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x80059AF4: jal         0x80077190
    // 0x80059AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_1;
    // 0x80059AF8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80059AFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059B00: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059B04: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80059B08: nop

    // 0x80059B0C: beq         $a0, $zero, L_80059B20
    if (ctx->r4 == 0) {
        // 0x80059B10: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80059B20;
    }
    // 0x80059B10: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80059B14: jal         0x80071380
    // 0x80059B18: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80059B18: nop

    after_2:
    // 0x80059B1C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_80059B20:
    // 0x80059B20: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80059B24: addiu       $a2, $a2, -0x8
    ctx->r6 = ADD32(ctx->r6, -0X8);
    // 0x80059B28: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80059B2C: jal         0x80070EDC
    // 0x80059B30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80059B30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x80059B34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80059B38: addiu       $v1, $v1, -0x24F0
    ctx->r3 = ADD32(ctx->r3, -0X24F0);
    // 0x80059B3C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80059B40: beq         $v0, $zero, L_80059B80
    if (ctx->r2 == 0) {
        // 0x80059B44: sw          $v0, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->r2;
            goto L_80059B80;
    }
    // 0x80059B44: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80059B48: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80059B4C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80059B50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059B54: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x80059B58: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80059B5C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80059B60: sh          $t9, -0x24DC($at)
    MEM_H(-0X24DC, ctx->r1) = ctx->r25;
    // 0x80059B64: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80059B68: jal         0x800CA300
    // 0x80059B6C: nop

    _bcopy(rdram, ctx);
        goto after_4;
    // 0x80059B6C: nop

    after_4:
    // 0x80059B70: jal         0x80071380
    // 0x80059B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80059B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80059B78: b           L_80059B8C
    // 0x80059B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80059B8C;
    // 0x80059B7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059B80:
    // 0x80059B80: jal         0x80071380
    // 0x80059B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80059B84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80059B88:
    // 0x80059B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80059B8C:
    // 0x80059B8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80059B90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80059B94: jr          $ra
    // 0x80059B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80059B98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void get_previous_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4B7C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4B80: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B4B84: addiu       $v1, $t6, -0x1
    ctx->r3 = ADD32(ctx->r14, -0X1);
    // 0x800B4B88: bgez        $v1, L_800B4BB0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800B4B8C: sw          $v1, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r3;
            goto L_800B4BB0;
    }
    // 0x800B4B8C: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4B90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B4B94: addiu       $v0, $v0, 0x3284
    ctx->r2 = ADD32(ctx->r2, 0X3284);
L_800B4B98:
    // 0x800B4B98: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800B4B9C: nop

    // 0x800B4BA0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800B4BA4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800B4BA8: bltz        $t9, L_800B4B98
    if (SIGNED(ctx->r25) < 0) {
        // 0x800B4BAC: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B4B98;
    }
    // 0x800B4BAC: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
L_800B4BB0:
    // 0x800B4BB0: lw          $t0, 0x328C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X328C);
    // 0x800B4BB4: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800B4BB8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B4BBC: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800B4BC0: jr          $ra
    // 0x800B4BC4: nop

    return;
    // 0x800B4BC4: nop

;}
RECOMP_FUNC void model_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800603BC: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800603C0: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800603C4: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800603C8: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800603CC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800603D0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800603D4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800603D8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800603DC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800603E0: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800603E4: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800603E8: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800603EC: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x800603F0: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800603F4: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800603F8: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800603FC: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80060400: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80060404: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80060408: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8006040C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80060410: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80060414: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80060418: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8006041C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060420: bne         $t6, $zero, L_80060AF0
    if (ctx->r14 != 0) {
        // 0x80060424: lui         $s0, 0xFF00
        ctx->r16 = S32(0XFF00 << 16);
            goto L_80060AF0;
    }
    // 0x80060424: lui         $s0, 0xFF00
    ctx->r16 = S32(0XFF00 << 16);
    // 0x80060428: lh          $a0, 0x28($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X28);
    // 0x8006042C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80060430: blez        $a0, L_80060478
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80060434: ori         $s0, $s0, 0xFF
        ctx->r16 = ctx->r16 | 0XFF;
            goto L_80060478;
    }
    // 0x80060434: ori         $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 | 0XFF;
    // 0x80060438: sll         $a2, $a0, 2
    ctx->r6 = S32(ctx->r4 << 2);
    // 0x8006043C: subu        $a2, $a2, $a0
    ctx->r6 = SUB32(ctx->r6, ctx->r4);
    // 0x80060440: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x80060444: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x80060448: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8006044C:
    // 0x8006044C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x80060450: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80060454: lh          $a0, 0x10($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X10);
    // 0x80060458: andi        $t8, $t7, 0x200
    ctx->r24 = ctx->r15 & 0X200;
    // 0x8006045C: bne         $t8, $zero, L_8006046C
    if (ctx->r24 != 0) {
        // 0x80060460: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8006046C;
    }
    // 0x80060460: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x80060464: addu        $t9, $s4, $a0
    ctx->r25 = ADD32(ctx->r20, ctx->r4);
    // 0x80060468: subu        $s4, $t9, $v1
    ctx->r20 = SUB32(ctx->r25, ctx->r3);
L_8006046C:
    // 0x8006046C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80060470: bne         $at, $zero, L_8006044C
    if (ctx->r1 != 0) {
        // 0x80060474: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8006044C;
    }
    // 0x80060474: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80060478:
    // 0x80060478: sll         $a0, $s4, 3
    ctx->r4 = S32(ctx->r20 << 3);
    // 0x8006047C: jal         0x80070F50
    // 0x80060480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x80060480: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80060484: beq         $v0, $zero, L_80060AF0
    if (ctx->r2 == 0) {
        // 0x80060488: sw          $v0, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->r2;
            goto L_80060AF0;
    }
    // 0x80060488: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x8006048C: sll         $a0, $s4, 6
    ctx->r4 = S32(ctx->r20 << 6);
    // 0x80060490: jal         0x80070F50
    // 0x80060494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x80060494: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80060498: bne         $v0, $zero, L_800604B4
    if (ctx->r2 != 0) {
        // 0x8006049C: sw          $v0, 0x10($s2)
        MEM_W(0X10, ctx->r18) = ctx->r2;
            goto L_800604B4;
    }
    // 0x8006049C: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800604A0: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800604A4: jal         0x80071380
    // 0x800604A8: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800604A8: nop

    after_2:
    // 0x800604AC: b           L_80060AF0
    // 0x800604B0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
        goto L_80060AF0;
    // 0x800604B0: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
L_800604B4:
    // 0x800604B4: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
    // 0x800604B8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x800604BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800604C0: blez        $a0, L_800607A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800604C4: addiu       $s7, $zero, 0xA
        ctx->r23 = ADD32(0, 0XA);
            goto L_800607A8;
    }
    // 0x800604C4: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800604C8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_800604CC:
    // 0x800604CC: lw          $t3, 0x38($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X38);
    // 0x800604D0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800604D4: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x800604D8: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800604DC: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x800604E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800604E4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800604E8: sw          $t5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r13;
    // 0x800604EC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x800604F0: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x800604F4: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x800604F8: beq         $t7, $zero, L_80060504
    if (ctx->r15 == 0) {
        // 0x800604FC: sll         $s1, $v1, 4
        ctx->r17 = S32(ctx->r3 << 4);
            goto L_80060504;
    }
    // 0x800604FC: sll         $s1, $v1, 4
    ctx->r17 = S32(ctx->r3 << 4);
    // 0x80060500: sw          $t8, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r24;
L_80060504:
    // 0x80060504: lw          $t9, 0xF4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF4);
    // 0x80060508: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x8006050C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80060510: beq         $at, $zero, L_80060788
    if (ctx->r1 == 0) {
        // 0x80060514: lw          $t5, 0xEC($sp)
        ctx->r13 = MEM_W(ctx->r29, 0XEC);
            goto L_80060788;
    }
    // 0x80060514: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_80060518:
    // 0x80060518: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x8006051C: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x80060520: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    // 0x80060524: lbu         $t4, 0x1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1);
    // 0x80060528: nop

    // 0x8006052C: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x80060530: multu       $t5, $s7
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060534: mflo        $t6
    ctx->r14 = lo;
    // 0x80060538: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006053C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80060540: nop

    // 0x80060544: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80060548: nop

    // 0x8006054C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060550: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x80060554: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80060558: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8006055C: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80060560: nop

    // 0x80060564: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80060568: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8006056C: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x80060570: lwc1        $f26, 0xC8($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060574: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80060578: nop

    // 0x8006057C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060580: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x80060584: lbu         $t3, 0x2($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2);
    // 0x80060588: lbu         $t9, 0x3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X3);
    // 0x8006058C: addu        $t4, $t3, $s5
    ctx->r12 = ADD32(ctx->r11, ctx->r21);
    // 0x80060590: multu       $t4, $s7
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060594: addu        $t3, $t9, $s5
    ctx->r11 = ADD32(ctx->r25, ctx->r21);
    // 0x80060598: lwc1        $f24, 0xC4($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8006059C: mflo        $t5
    ctx->r13 = lo;
    // 0x800605A0: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x800605A4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800605A8: multu       $t3, $s7
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800605AC: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800605B0: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800605B4: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800605B8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800605BC: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800605C0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800605C4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800605C8: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800605CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800605D0: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x800605D4: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800605D8: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x800605DC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800605E0: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800605E4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800605E8: swc1        $f10, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f10.u32l;
    // 0x800605EC: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800605F0: cvt.s.w     $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    ctx->f22.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800605F4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800605F8: lwc1        $f12, 0xB0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800605FC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060600: sub.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80060604: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80060608: sub.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006060C: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80060610: sub.s       $f10, $f24, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x80060614: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80060618: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8006061C: sub.s       $f4, $f14, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80060620: mul.s       $f10, $f4, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f24.fl);
    // 0x80060624: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80060628: swc1        $f20, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f20.u32l;
    // 0x8006062C: sub.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f22.fl - ctx->f2.fl;
    // 0x80060630: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80060634: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80060638: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8006063C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80060640: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80060644: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80060648: add.s       $f28, $f4, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8006064C: swc1        $f28, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f28.u32l;
    // 0x80060650: sub.s       $f4, $f12, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f26.fl;
    // 0x80060654: mul.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80060658: sub.s       $f4, $f26, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8006065C: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80060660: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80060664: nop

    // 0x80060668: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006066C: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80060670: swc1        $f30, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f30.u32l;
    // 0x80060674: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80060678: nop

    // 0x8006067C: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x80060680: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060684: jal         0x800CA030
    // 0x80060688: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80060688: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_3:
    // 0x8006068C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80060690: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80060694: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80060698: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8006069C: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800606A0: bc1f        L_800606C8
    if (!c1cs) {
        // 0x800606A4: sll         $v0, $s4, 4
        ctx->r2 = S32(ctx->r20 << 4);
            goto L_800606C8;
    }
    // 0x800606A4: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x800606A8: nop

    // 0x800606AC: div.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800606B0: nop

    // 0x800606B4: div.s       $f14, $f28, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x800606B8: swc1        $f16, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f16.u32l;
    // 0x800606BC: div.s       $f12, $f30, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800606C0: swc1        $f14, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f14.u32l;
    // 0x800606C4: swc1        $f12, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f12.u32l;
L_800606C8:
    // 0x800606C8: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x800606CC: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800606D0: lwc1        $f12, 0xA0($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800606D4: lwc1        $f14, 0xA4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800606D8: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800606DC: swc1        $f16, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f16.u32l;
    // 0x800606E0: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x800606E4: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800606E8: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800606EC: swc1        $f14, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f14.u32l;
    // 0x800606F0: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x800606F4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800606F8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800606FC: swc1        $f12, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f12.u32l;
    // 0x80060700: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060704: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x80060708: mul.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006070C: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060710: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80060714: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80060718: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8006071C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80060720: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060724: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x80060728: swc1        $f6, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f6.u32l;
    // 0x8006072C: lw          $t3, 0xC($s2)
    ctx->r11 = MEM_W(ctx->r18, 0XC);
    // 0x80060730: nop

    // 0x80060734: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80060738: sh          $s4, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r20;
    // 0x8006073C: lw          $t5, 0xC($s2)
    ctx->r13 = MEM_W(ctx->r18, 0XC);
    // 0x80060740: nop

    // 0x80060744: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80060748: sh          $s4, 0x2($t6)
    MEM_H(0X2, ctx->r14) = ctx->r20;
    // 0x8006074C: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80060750: nop

    // 0x80060754: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80060758: sh          $s4, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r20;
    // 0x8006075C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060760: nop

    // 0x80060764: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x80060768: sh          $s4, 0x6($t3)
    MEM_H(0X6, ctx->r11) = ctx->r20;
    // 0x8006076C: lw          $t4, 0xF4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XF4);
    // 0x80060770: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060774: bne         $s6, $t4, L_80060518
    if (ctx->r22 != ctx->r12) {
        // 0x80060778: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80060518;
    }
    // 0x80060778: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8006077C: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x80060780: nop

    // 0x80060784: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
L_80060788:
    // 0x80060788: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8006078C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80060790: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060794: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80060798: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x8006079C: bne         $at, $zero, L_800604CC
    if (ctx->r1 != 0) {
        // 0x800607A0: sw          $t6, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r14;
            goto L_800604CC;
    }
    // 0x800607A0: sw          $t6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r14;
    // 0x800607A4: sw          $zero, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = 0;
L_800607A8:
    // 0x800607A8: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
    // 0x800607AC: sh          $s4, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r20;
    // 0x800607B0: jal         0x80060B50
    // 0x800607B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_80060910(rdram, ctx);
        goto after_4;
    // 0x800607B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
    // 0x800607B8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x800607BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800607C0: blez        $a0, L_80060AF0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800607C4: addiu       $fp, $zero, 0x3
        ctx->r30 = ADD32(0, 0X3);
            goto L_80060AF0;
    }
    // 0x800607C4: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x800607C8: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_800607CC:
    // 0x800607CC: lw          $t9, 0x38($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X38);
    // 0x800607D0: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x800607D4: nop

    // 0x800607D8: addu        $v0, $t9, $t3
    ctx->r2 = ADD32(ctx->r25, ctx->r11);
    // 0x800607DC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x800607E0: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800607E4: lh          $s5, 0x2($v0)
    ctx->r21 = MEM_H(ctx->r2, 0X2);
    // 0x800607E8: lh          $a3, 0x10($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X10);
    // 0x800607EC: andi        $t5, $t4, 0x200
    ctx->r13 = ctx->r12 & 0X200;
    // 0x800607F0: beq         $t5, $zero, L_800607FC
    if (ctx->r13 == 0) {
        // 0x800607F4: sll         $v0, $s3, 3
        ctx->r2 = S32(ctx->r19 << 3);
            goto L_800607FC;
    }
    // 0x800607F4: sll         $v0, $s3, 3
    ctx->r2 = S32(ctx->r19 << 3);
    // 0x800607F8: addiu       $a3, $v1, -0x1
    ctx->r7 = ADD32(ctx->r3, -0X1);
L_800607FC:
    // 0x800607FC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80060800: beq         $at, $zero, L_80060AD0
    if (ctx->r1 == 0) {
        // 0x80060804: or          $s6, $v1, $zero
        ctx->r22 = ctx->r3 | 0;
            goto L_80060AD0;
    }
    // 0x80060804: or          $s6, $v1, $zero
    ctx->r22 = ctx->r3 | 0;
    // 0x80060808: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8006080C: sw          $a3, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r7;
L_80060810:
    // 0x80060810: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80060814: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x80060818: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x8006081C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80060820: lhu         $t6, 0x0($t8)
    ctx->r14 = MEM_HU(ctx->r24, 0X0);
    // 0x80060824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80060828: sll         $t3, $t6, 4
    ctx->r11 = S32(ctx->r14 << 4);
    // 0x8006082C: addu        $v1, $t9, $t3
    ctx->r3 = ADD32(ctx->r25, ctx->r11);
    // 0x80060830: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80060834: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80060838: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x8006083C: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80060840: nop

    // 0x80060844: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x80060848: lwc1        $f10, 0x8($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8006084C: nop

    // 0x80060850: swc1        $f10, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f10.u32l;
L_80060854:
    // 0x80060854: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x80060858: slti        $at, $s0, 0x3
    ctx->r1 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8006085C: lw          $a3, 0xC($s2)
    ctx->r7 = MEM_W(ctx->r18, 0XC);
    // 0x80060860: lw          $t0, 0x10($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X10);
    // 0x80060864: bne         $at, $zero, L_80060870
    if (ctx->r1 != 0) {
        // 0x80060868: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80060870;
    }
    // 0x80060868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006086C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80060870:
    // 0x80060870: lw          $t4, 0x8($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X8);
    // 0x80060874: sll         $t5, $s6, 4
    ctx->r13 = S32(ctx->r22 << 4);
    // 0x80060878: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8006087C: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80060880: lbu         $t8, 0x1($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1);
    // 0x80060884: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x80060888: addu        $t1, $t8, $s5
    ctx->r9 = ADD32(ctx->r24, ctx->r21);
    // 0x8006088C: multu       $t1, $s7
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80060890: addu        $t4, $a3, $t3
    ctx->r12 = ADD32(ctx->r7, ctx->r11);
    // 0x80060894: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060898: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x8006089C: addu        $t6, $v0, $a0
    ctx->r14 = ADD32(ctx->r2, ctx->r4);
    // 0x800608A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800608A4: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x800608A8: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x800608AC: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800608B0: lwc1        $f4, 0xA8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800608B4: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800608B8: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800608BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800608C0: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800608C4: addu        $t2, $t9, $s5
    ctx->r10 = ADD32(ctx->r25, ctx->r21);
    // 0x800608C8: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800608CC: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800608D0: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800608D4: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x800608D8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800608DC: add.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800608E0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800608E4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800608E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800608EC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800608F0: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x800608F4: swc1        $f10, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f10.u32l;
    // 0x800608F8: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800608FC: lh          $t3, 0x2($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X2);
    // 0x80060900: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060904: mflo        $t5
    ctx->r13 = lo;
    // 0x80060908: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8006090C: addu        $v0, $v1, $t5
    ctx->r2 = ADD32(ctx->r3, ctx->r13);
    // 0x80060910: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80060914: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80060918: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8006091C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80060920: mul.s       $f4, $f20, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f28.fl);
    // 0x80060924: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80060928: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x8006092C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    // 0x80060930: cvt.s.w     $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80060934: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80060938: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8006093C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80060940: swc1        $f30, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f30.u32l;
    // 0x80060944: mul.s       $f10, $f24, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f28.fl);
    // 0x80060948: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006094C: mul.s       $f6, $f26, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f28.fl);
    // 0x80060950: add.s       $f2, $f10, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f30.fl;
    // 0x80060954: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    // 0x80060958: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006095C: lwc1        $f8, 0xCC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060960: add.s       $f0, $f6, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80060964: add.s       $f22, $f4, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80060968: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    // 0x8006096C: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80060970: mul.s       $f10, $f4, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80060974: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x80060978: lwc1        $f0, 0xC8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8006097C: mul.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80060980: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80060984: sub.s       $f10, $f12, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80060988: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006098C: sub.s       $f10, $f14, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f22.fl;
    // 0x80060990: add.s       $f20, $f6, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80060994: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060998: mov.s       $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    ctx->f2.fl = ctx->f8.fl;
    // 0x8006099C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800609A0: sub.s       $f8, $f22, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800609A4: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800609A8: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800609AC: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800609B0: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x800609B4: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800609B8: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800609BC: nop

    // 0x800609C0: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800609C4: add.s       $f28, $f6, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800609C8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800609CC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800609D0: mul.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800609D4: sub.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800609D8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800609DC: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x800609E0: mov.s       $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    ctx->f24.fl = ctx->f28.fl;
    // 0x800609E4: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800609E8: add.s       $f30, $f8, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f30.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800609EC: mul.s       $f10, $f28, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x800609F0: mov.s       $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    ctx->f26.fl = ctx->f30.fl;
    // 0x800609F4: mul.s       $f6, $f30, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f30.fl, ctx->f30.fl);
    // 0x800609F8: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800609FC: jal         0x800CA030
    // 0x80060A00: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80060A00: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_5:
    // 0x80060A04: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80060A08: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80060A0C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80060A10: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80060A14: lwc1        $f2, 0xCC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80060A18: bc1f        L_80060A34
    if (!c1cs) {
        // 0x80060A1C: nop
    
            goto L_80060A34;
    }
    // 0x80060A1C: nop

    // 0x80060A20: div.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80060A24: nop

    // 0x80060A28: div.s       $f24, $f28, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80060A2C: nop

    // 0x80060A30: div.s       $f26, $f30, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
L_80060A34:
    // 0x80060A34: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80060A38: sll         $t3, $s3, 3
    ctx->r11 = S32(ctx->r19 << 3);
    // 0x80060A3C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80060A40: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80060A44: sh          $s4, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r20;
    // 0x80060A48: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x80060A4C: sll         $v0, $s4, 4
    ctx->r2 = S32(ctx->r20 << 4);
    // 0x80060A50: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x80060A54: swc1        $f20, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f20.u32l;
    // 0x80060A58: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x80060A5C: mul.s       $f8, $f2, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80060A60: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x80060A64: swc1        $f24, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f24.u32l;
    // 0x80060A68: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x80060A6C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80060A70: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x80060A74: swc1        $f26, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->f26.u32l;
    // 0x80060A78: lwc1        $f6, 0xC8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x80060A7C: lw          $t7, 0x10($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X10);
    // 0x80060A80: mul.s       $f4, $f6, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80060A84: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80060A88: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80060A8C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80060A90: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80060A94: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80060A98: mul.s       $f8, $f6, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f26.fl);
    // 0x80060A9C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80060AA0: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80060AA4: bne         $s0, $fp, L_80060854
    if (ctx->r16 != ctx->r30) {
        // 0x80060AA8: swc1        $f6, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
            goto L_80060854;
    }
    // 0x80060AA8: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x80060AAC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80060AB0: lw          $t3, 0xF4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF4);
    // 0x80060AB4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80060AB8: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80060ABC: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x80060AC0: bne         $s6, $t3, L_80060810
    if (ctx->r22 != ctx->r11) {
        // 0x80060AC4: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80060810;
    }
    // 0x80060AC4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80060AC8: lh          $a0, 0x28($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X28);
    // 0x80060ACC: nop

L_80060AD0:
    // 0x80060AD0: lw          $t4, 0xEC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XEC);
    // 0x80060AD4: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x80060AD8: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80060ADC: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80060AE0: addiu       $t8, $t7, 0xC
    ctx->r24 = ADD32(ctx->r15, 0XC);
    // 0x80060AE4: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80060AE8: bne         $at, $zero, L_800607CC
    if (ctx->r1 != 0) {
        // 0x80060AEC: sw          $t5, 0xEC($sp)
        MEM_W(0XEC, ctx->r29) = ctx->r13;
            goto L_800607CC;
    }
    // 0x80060AEC: sw          $t5, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r13;
L_80060AF0:
    // 0x80060AF0: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80060AF4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80060AF8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80060AFC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80060B00: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80060B04: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80060B08: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80060B0C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80060B10: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80060B14: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80060B18: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80060B1C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80060B20: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80060B24: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80060B28: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80060B2C: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80060B30: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80060B34: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80060B38: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80060B3C: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80060B40: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80060B44: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80060B48: jr          $ra
    // 0x80060B4C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80060B4C: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void create_general_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1690: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B1694: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B1698: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B169C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B16A0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800B16A4: lh          $t7, 0x8($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X8);
    // 0x800B16A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B16AC: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B16B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B16B4: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B16B8: lw          $a3, 0x0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X0);
    // 0x800B16BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800B16C0: lbu         $a2, 0x0($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X0);
    // 0x800B16C4: nop

    // 0x800B16C8: beq         $a2, $at, L_800B16D8
    if (ctx->r6 == ctx->r1) {
        // 0x800B16CC: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_800B16D8;
    }
    // 0x800B16CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800B16D0: bne         $a2, $at, L_800B16E0
    if (ctx->r6 != ctx->r1) {
        // 0x800B16D4: nop
    
            goto L_800B16E0;
    }
    // 0x800B16D4: nop

L_800B16D8:
    // 0x800B16D8: b           L_800B2204
    // 0x800B16DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2204;
    // 0x800B16DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B16E0:
    // 0x800B16E0: lw          $s1, 0x0($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X0);
    // 0x800B16E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B16E8: lw          $t0, 0x9C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X9C);
    // 0x800B16EC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B16F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B16F4: jal         0x800B2218
    // 0x800B16F8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    particle_allocate(rdram, ctx);
        goto after_0;
    // 0x800B16F8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_0:
    // 0x800B16FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1700: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1704: bne         $v0, $zero, L_800B1714
    if (ctx->r2 != 0) {
        // 0x800B1708: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B1714;
    }
    // 0x800B1708: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B170C: b           L_800B2204
    // 0x800B1710: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800B2204;
    // 0x800B1710: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800B1714:
    // 0x800B1714: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B1718: addiu       $t3, $zero, -0x8000
    ctx->r11 = ADD32(0, -0X8000);
    // 0x800B171C: lh          $t2, 0x2E($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2E);
    // 0x800B1720: sh          $t3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r11;
    // 0x800B1724: sh          $t2, 0x2E($v0)
    MEM_H(0X2E, ctx->r2) = ctx->r10;
    // 0x800B1728: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x800B172C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800B1730: sb          $t4, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r12;
    // 0x800B1734: lhu         $t5, 0x2($a3)
    ctx->r13 = MEM_HU(ctx->r7, 0X2);
    // 0x800B1738: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800B173C: andi        $t6, $t5, 0x800
    ctx->r14 = ctx->r13 & 0X800;
    // 0x800B1740: beq         $t6, $zero, L_800B1794
    if (ctx->r14 == 0) {
        // 0x800B1744: sw          $t5, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r13;
            goto L_800B1794;
    }
    // 0x800B1744: sw          $t5, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r13;
    // 0x800B1748: lw          $v1, 0x54($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X54);
    // 0x800B174C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800B1750: beq         $v1, $zero, L_800B1794
    if (ctx->r3 == 0) {
        // 0x800B1754: nop
    
            goto L_800B1794;
    }
    // 0x800B1754: nop

    // 0x800B1758: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800B175C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800B1760: nop

    // 0x800B1764: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800B1768: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B176C: nop

    // 0x800B1770: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B1774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B1778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B177C: nop

    // 0x800B1780: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B1784: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B1788: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B178C: b           L_800B1798
    // 0x800B1790: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
        goto L_800B1798;
    // 0x800B1790: sh          $t9, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r25;
L_800B1794:
    // 0x800B1794: sh          $t2, 0x4A($v0)
    MEM_H(0X4A, ctx->r2) = ctx->r10;
L_800B1798:
    // 0x800B1798: lw          $t3, 0x5C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X5C);
    // 0x800B179C: lwc1        $f16, 0x50($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800B17A0: sll         $t4, $t3, 14
    ctx->r12 = S32(ctx->r11 << 14);
    // 0x800B17A4: bgez        $t4, L_800B17FC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B17A8: nop
    
            goto L_800B17FC;
    }
    // 0x800B17A8: nop

    // 0x800B17AC: lw          $a1, 0x8C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8C);
    // 0x800B17B0: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B17B4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B17B8: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B17BC: jal         0x8006FB8C
    // 0x800B17C0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B17C0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B17C4: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B17C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B17CC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B17D0: lwc1        $f9, -0x6EB8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X6EB8);
    // 0x800B17D4: lwc1        $f8, -0x6EB4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6EB4);
    // 0x800B17D8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800B17DC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800B17E0: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B17E4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B17E8: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B17EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B17F0: add.d       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f18.d + ctx->f10.d;
    // 0x800B17F4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B17F8: cvt.s.d     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f16.fl = CVT_S_D(ctx->f4.d);
L_800B17FC:
    // 0x800B17FC: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B1800: nop

    // 0x800B1804: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800B1808: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x800B180C: lw          $t5, 0x5C($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1810: lwc1        $f16, 0x54($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800B1814: sll         $t7, $t5, 13
    ctx->r15 = S32(ctx->r13 << 13);
    // 0x800B1818: bgez        $t7, L_800B1870
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B181C: nop
    
            goto L_800B1870;
    }
    // 0x800B181C: nop

    // 0x800B1820: lw          $a1, 0x90($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X90);
    // 0x800B1824: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1828: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B182C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1830: jal         0x8006FB8C
    // 0x800B1834: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B1834: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B1838: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x800B183C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B1840: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B1844: lwc1        $f7, -0x6EB0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X6EB0);
    // 0x800B1848: lwc1        $f6, -0x6EAC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X6EAC);
    // 0x800B184C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800B1850: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800B1854: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B1858: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B185C: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800B1860: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B1864: add.d       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f18.d + ctx->f8.d;
    // 0x800B1868: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800B186C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
L_800B1870:
    // 0x800B1870: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800B1874: nop

    // 0x800B1878: andi        $t8, $t6, 0x1000
    ctx->r24 = ctx->r14 & 0X1000;
    // 0x800B187C: beq         $t8, $zero, L_800B18D8
    if (ctx->r24 == 0) {
        // 0x800B1880: nop
    
            goto L_800B18D8;
    }
    // 0x800B1880: nop

    // 0x800B1884: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B1888: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B188C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B1890: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B1894: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x800B1898: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B189C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B18A0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B18A4: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B18A8: add.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B18AC: jal         0x800CA030
    // 0x800B18B0: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800B18B0: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_3:
    // 0x800B18B4: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800B18B8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B18BC: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x800B18C0: lwc1        $f4, -0x6EA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6EA8);
    // 0x800B18C4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B18C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B18CC: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800B18D0: b           L_800B18E8
    // 0x800B18D4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
        goto L_800B18E8;
    // 0x800B18D4: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
L_800B18D8:
    // 0x800B18D8: lwc1        $f18, 0x10($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B18DC: nop

    // 0x800B18E0: mul.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800B18E4: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
L_800B18E8:
    // 0x800B18E8: lh          $a1, 0xA($a3)
    ctx->r5 = MEM_H(ctx->r7, 0XA);
    // 0x800B18EC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800B18F0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B18F4: jal         0x8006FB8C
    // 0x800B18F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B18F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B18FC: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1900: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1904: lh          $t9, 0x8($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X8);
    // 0x800B1908: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800B190C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B1910: addu        $t2, $v0, $t9
    ctx->r10 = ADD32(ctx->r2, ctx->r25);
    // 0x800B1914: sh          $t2, 0x3A($s0)
    MEM_H(0X3A, ctx->r16) = ctx->r10;
    // 0x800B1918: sb          $zero, 0x38($s0)
    MEM_B(0X38, ctx->r16) = 0;
    // 0x800B191C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B1920: swc1        $f10, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f10.u32l;
    // 0x800B1924: lw          $v1, 0x3290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3290);
    // 0x800B1928: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B192C: beq         $v1, $zero, L_800B193C
    if (ctx->r3 == 0) {
        // 0x800B1930: nop
    
            goto L_800B193C;
    }
    // 0x800B1930: nop

    // 0x800B1934: b           L_800B1A10
    // 0x800B1938: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
        goto L_800B1A10;
    // 0x800B1938: sw          $v1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r3;
L_800B193C:
    // 0x800B193C: beq         $t0, $at, L_800B19E0
    if (ctx->r8 == ctx->r1) {
        // 0x800B1940: nop
    
            goto L_800B19E0;
    }
    // 0x800B1940: nop

    // 0x800B1944: lh          $t3, 0x1E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1948: nop

    // 0x800B194C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B1950: sh          $t4, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = ctx->r12;
    // 0x800B1954: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800B1958: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B195C: nop

    // 0x800B1960: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1964: bne         $at, $zero, L_800B197C
    if (ctx->r1 != 0) {
        // 0x800B1968: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_800B197C;
    }
    // 0x800B1968: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B196C: sh          $zero, 0x1E($a2)
    MEM_H(0X1E, ctx->r6) = 0;
    // 0x800B1970: lh          $v0, 0x1E($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1974: nop

    // 0x800B1978: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
L_800B197C:
    // 0x800B197C: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B1980: lbu         $t8, 0x14($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X14);
    // 0x800B1984: nop

    // 0x800B1988: sb          $t8, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r24;
    // 0x800B198C: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B1990: nop

    // 0x800B1994: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B1998: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B199C: lbu         $t4, 0x15($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X15);
    // 0x800B19A0: nop

    // 0x800B19A4: sb          $t4, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r12;
    // 0x800B19A8: lh          $t5, 0x1E($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X1E);
    // 0x800B19AC: nop

    // 0x800B19B0: sll         $t7, $t5, 3
    ctx->r15 = S32(ctx->r13 << 3);
    // 0x800B19B4: addu        $t6, $t0, $t7
    ctx->r14 = ADD32(ctx->r8, ctx->r15);
    // 0x800B19B8: lbu         $t8, 0x16($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X16);
    // 0x800B19BC: nop

    // 0x800B19C0: sb          $t8, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r24;
    // 0x800B19C4: lh          $t9, 0x1E($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1E);
    // 0x800B19C8: nop

    // 0x800B19CC: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800B19D0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800B19D4: lbu         $t4, 0x17($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X17);
    // 0x800B19D8: b           L_800B1A10
    // 0x800B19DC: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
        goto L_800B1A10;
    // 0x800B19DC: sb          $t4, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r12;
L_800B19E0:
    // 0x800B19E0: lbu         $t5, 0x14($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X14);
    // 0x800B19E4: nop

    // 0x800B19E8: sb          $t5, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r13;
    // 0x800B19EC: lbu         $t7, 0x15($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X15);
    // 0x800B19F0: nop

    // 0x800B19F4: sb          $t7, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r15;
    // 0x800B19F8: lbu         $t6, 0x16($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X16);
    // 0x800B19FC: nop

    // 0x800B1A00: sb          $t6, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r14;
    // 0x800B1A04: lbu         $t8, 0x17($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X17);
    // 0x800B1A08: nop

    // 0x800B1A0C: sb          $t8, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r24;
L_800B1A10:
    // 0x800B1A10: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1A14: lui         $at, 0xF0
    ctx->r1 = S32(0XF0 << 16);
    // 0x800B1A18: and         $t9, $v1, $at
    ctx->r25 = ctx->r3 & ctx->r1;
    // 0x800B1A1C: beq         $t9, $zero, L_800B1AFC
    if (ctx->r25 == 0) {
        // 0x800B1A20: or          $v1, $t9, $zero
        ctx->r3 = ctx->r25 | 0;
            goto L_800B1AFC;
    }
    // 0x800B1A20: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800B1A24: sll         $t2, $t9, 11
    ctx->r10 = S32(ctx->r25 << 11);
    // 0x800B1A28: bgez        $t2, L_800B1A60
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B1A2C: sll         $t5, $v1, 10
        ctx->r13 = S32(ctx->r3 << 10);
            goto L_800B1A60;
    }
    // 0x800B1A2C: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
    // 0x800B1A30: lbu         $a1, 0x98($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X98);
    // 0x800B1A34: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1A38: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800B1A3C: jal         0x8006FB8C
    // 0x800B1A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B1A40: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B1A44: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B1A48: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1A4C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A50: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1A54: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800B1A58: sb          $t4, 0x6C($s0)
    MEM_B(0X6C, ctx->r16) = ctx->r12;
    // 0x800B1A5C: sll         $t5, $v1, 10
    ctx->r13 = S32(ctx->r3 << 10);
L_800B1A60:
    // 0x800B1A60: bgez        $t5, L_800B1A98
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B1A64: sll         $t8, $v1, 9
        ctx->r24 = S32(ctx->r3 << 9);
            goto L_800B1A98;
    }
    // 0x800B1A64: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
    // 0x800B1A68: lbu         $a1, 0x99($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X99);
    // 0x800B1A6C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1A70: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1A74: jal         0x8006FB8C
    // 0x800B1A78: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800B1A78: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_6:
    // 0x800B1A7C: lbu         $t7, 0x6D($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B1A80: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1A84: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1A88: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1A8C: addu        $t6, $t7, $v0
    ctx->r14 = ADD32(ctx->r15, ctx->r2);
    // 0x800B1A90: sb          $t6, 0x6D($s0)
    MEM_B(0X6D, ctx->r16) = ctx->r14;
    // 0x800B1A94: sll         $t8, $v1, 9
    ctx->r24 = S32(ctx->r3 << 9);
L_800B1A98:
    // 0x800B1A98: bgez        $t8, L_800B1AD0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800B1A9C: sll         $t3, $v1, 8
        ctx->r11 = S32(ctx->r3 << 8);
            goto L_800B1AD0;
    }
    // 0x800B1A9C: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
    // 0x800B1AA0: lbu         $a1, 0x9A($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9A);
    // 0x800B1AA4: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1AA8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1AAC: jal         0x8006FB8C
    // 0x800B1AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800B1AB0: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_7:
    // 0x800B1AB4: lbu         $t9, 0x6E($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B1AB8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1ABC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1AC0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1AC4: addu        $t2, $t9, $v0
    ctx->r10 = ADD32(ctx->r25, ctx->r2);
    // 0x800B1AC8: sb          $t2, 0x6E($s0)
    MEM_B(0X6E, ctx->r16) = ctx->r10;
    // 0x800B1ACC: sll         $t3, $v1, 8
    ctx->r11 = S32(ctx->r3 << 8);
L_800B1AD0:
    // 0x800B1AD0: bgez        $t3, L_800B1AFC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800B1AD4: nop
    
            goto L_800B1AFC;
    }
    // 0x800B1AD4: nop

    // 0x800B1AD8: lbu         $a1, 0x9B($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X9B);
    // 0x800B1ADC: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x800B1AE0: jal         0x8006FB8C
    // 0x800B1AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800B1AE4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_8:
    // 0x800B1AE8: lbu         $t4, 0x6F($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6F);
    // 0x800B1AEC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1AF0: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800B1AF4: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B1AF8: sb          $t5, 0x6F($s0)
    MEM_B(0X6F, ctx->r16) = ctx->r13;
L_800B1AFC:
    // 0x800B1AFC: lh          $t7, 0xE($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XE);
    // 0x800B1B00: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B1B04: sh          $t7, 0x60($s0)
    MEM_H(0X60, ctx->r16) = ctx->r15;
    // 0x800B1B08: addiu       $a0, $a0, 0x347C
    ctx->r4 = ADD32(ctx->r4, 0X347C);
    // 0x800B1B0C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B1B10: lbu         $t6, 0xC($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B14: nop

    // 0x800B1B18: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1B1C: mflo        $t9
    ctx->r25 = lo;
    // 0x800B1B20: sh          $t9, 0x5C($s0)
    MEM_H(0X5C, ctx->r16) = ctx->r25;
    // 0x800B1B24: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B28: nop

    // 0x800B1B2C: slti        $at, $t2, 0xFF
    ctx->r1 = SIGNED(ctx->r10) < 0XFF ? 1 : 0;
    // 0x800B1B30: beq         $at, $zero, L_800B1B70
    if (ctx->r1 == 0) {
        // 0x800B1B34: nop
    
            goto L_800B1B70;
    }
    // 0x800B1B34: nop

    // 0x800B1B38: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x800B1B3C: nop

    // 0x800B1B40: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B1B44: beq         $t4, $zero, L_800B1B60
    if (ctx->r12 == 0) {
        // 0x800B1B48: nop
    
            goto L_800B1B60;
    }
    // 0x800B1B48: nop

    // 0x800B1B4C: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
    // 0x800B1B50: nop

    // 0x800B1B54: ori         $t7, $t5, 0x100
    ctx->r15 = ctx->r13 | 0X100;
    // 0x800B1B58: b           L_800B1B70
    // 0x800B1B5C: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
        goto L_800B1B70;
    // 0x800B1B5C: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
L_800B1B60:
    // 0x800B1B60: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x800B1B64: nop

    // 0x800B1B68: ori         $t8, $t6, 0x80
    ctx->r24 = ctx->r14 | 0X80;
    // 0x800B1B6C: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_800B1B70:
    // 0x800B1B70: lh          $v0, 0x60($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X60);
    // 0x800B1B74: lh          $v1, 0x3A($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X3A);
    // 0x800B1B78: nop

    // 0x800B1B7C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B1B80: beq         $at, $zero, L_800B1BE4
    if (ctx->r1 == 0) {
        // 0x800B1B84: nop
    
            goto L_800B1BE4;
    }
    // 0x800B1B84: nop

    // 0x800B1B88: lbu         $t9, 0xD($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD);
    // 0x800B1B8C: lbu         $t2, 0xC($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0XC);
    // 0x800B1B90: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800B1B94: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x800B1B98: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B1B9C: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800B1BA0: mflo        $t5
    ctx->r13 = lo;
    // 0x800B1BA4: nop

    // 0x800B1BA8: nop

    // 0x800B1BAC: div         $zero, $t5, $t7
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r15)));
    // 0x800B1BB0: bne         $t7, $zero, L_800B1BBC
    if (ctx->r15 != 0) {
        // 0x800B1BB4: nop
    
            goto L_800B1BBC;
    }
    // 0x800B1BB4: nop

    // 0x800B1BB8: break       7
    do_break(2148211640);
L_800B1BBC:
    // 0x800B1BBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B1BC0: bne         $t7, $at, L_800B1BD4
    if (ctx->r15 != ctx->r1) {
        // 0x800B1BC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800B1BD4;
    }
    // 0x800B1BC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800B1BC8: bne         $t5, $at, L_800B1BD4
    if (ctx->r13 != ctx->r1) {
        // 0x800B1BCC: nop
    
            goto L_800B1BD4;
    }
    // 0x800B1BCC: nop

    // 0x800B1BD0: break       6
    do_break(2148211664);
L_800B1BD4:
    // 0x800B1BD4: mflo        $t6
    ctx->r14 = lo;
    // 0x800B1BD8: sh          $t6, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = ctx->r14;
    // 0x800B1BDC: b           L_800B1BEC
    // 0x800B1BE0: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
        goto L_800B1BEC;
    // 0x800B1BE0: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B1BE4:
    // 0x800B1BE4: sh          $zero, 0x5E($s0)
    MEM_H(0X5E, ctx->r16) = 0;
    // 0x800B1BE8: sb          $zero, 0x23($sp)
    MEM_B(0X23, ctx->r29) = 0;
L_800B1BEC:
    // 0x800B1BEC: lh          $t8, 0x6($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X6);
    // 0x800B1BF0: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1BF4: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B1BF8: bne         $v0, $at, L_800B1D14
    if (ctx->r2 != ctx->r1) {
        // 0x800B1BFC: sh          $t8, 0x1A($s0)
        MEM_H(0X1A, ctx->r16) = ctx->r24;
            goto L_800B1D14;
    }
    // 0x800B1BFC: sh          $t8, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r24;
    // 0x800B1C00: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B1C04: jal         0x8007C57C
    // 0x800B1C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x800B1C08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x800B1C0C: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1C10: beq         $v0, $zero, L_800B1D08
    if (ctx->r2 == 0) {
        // 0x800B1C14: sw          $v0, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r2;
            goto L_800B1D08;
    }
    // 0x800B1C14: sw          $v0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r2;
    // 0x800B1C18: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B1C1C: nop

    // 0x800B1C20: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B1C24: nop

    // 0x800B1C28: lh          $t4, 0x6($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X6);
    // 0x800B1C2C: nop

    // 0x800B1C30: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B1C34: beq         $t5, $zero, L_800B1C74
    if (ctx->r13 == 0) {
        // 0x800B1C38: nop
    
            goto L_800B1C74;
    }
    // 0x800B1C38: nop

    // 0x800B1C3C: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B1C40: nop

    // 0x800B1C44: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B1C48: beq         $t6, $zero, L_800B1C64
    if (ctx->r14 == 0) {
        // 0x800B1C4C: nop
    
            goto L_800B1C64;
    }
    // 0x800B1C4C: nop

    // 0x800B1C50: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B1C54: nop

    // 0x800B1C58: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B1C5C: b           L_800B1C74
    // 0x800B1C60: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1C74;
    // 0x800B1C60: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1C64:
    // 0x800B1C64: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1C68: nop

    // 0x800B1C6C: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B1C70: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1C74:
    // 0x800B1C74: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1C78: nop

    // 0x800B1C7C: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B1C80: beq         $t5, $zero, L_800B1CCC
    if (ctx->r13 == 0) {
        // 0x800B1C84: nop
    
            goto L_800B1CCC;
    }
    // 0x800B1C84: nop

    // 0x800B1C88: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B1C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1C90: lh          $a1, 0x0($t7)
    ctx->r5 = MEM_H(ctx->r15, 0X0);
    // 0x800B1C94: jal         0x8006FB8C
    // 0x800B1C98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800B1C98: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_10:
    // 0x800B1C9C: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x800B1CA0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1CA4: sll         $t6, $v0, 8
    ctx->r14 = S32(ctx->r2 << 8);
    // 0x800B1CA8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1CAC: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x800B1CB0: bne         $t9, $at, L_800B1E40
    if (ctx->r25 != ctx->r1) {
        // 0x800B1CB4: sh          $t6, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r14;
            goto L_800B1E40;
    }
    // 0x800B1CB4: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
    // 0x800B1CB8: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x800B1CBC: nop

    // 0x800B1CC0: ori         $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 | 0XFF;
    // 0x800B1CC4: b           L_800B1E40
    // 0x800B1CC8: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
        goto L_800B1E40;
    // 0x800B1CC8: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
L_800B1CCC:
    // 0x800B1CCC: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B1CD0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1CD4: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x800B1CD8: bne         $t5, $at, L_800B1D00
    if (ctx->r13 != ctx->r1) {
        // 0x800B1CDC: nop
    
            goto L_800B1D00;
    }
    // 0x800B1CDC: nop

    // 0x800B1CE0: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x800B1CE4: nop

    // 0x800B1CE8: lh          $t6, 0x0($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X0);
    // 0x800B1CEC: nop

    // 0x800B1CF0: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800B1CF4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B1CF8: b           L_800B1E40
    // 0x800B1CFC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B1E40;
    // 0x800B1CFC: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B1D00:
    // 0x800B1D00: b           L_800B1E40
    // 0x800B1D04: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B1E40;
    // 0x800B1D04: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B1D08:
    // 0x800B1D08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1D0C: b           L_800B1E40
    // 0x800B1D10: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
        goto L_800B1E40;
    // 0x800B1D10: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B1D14:
    // 0x800B1D14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1D18: beq         $v0, $at, L_800B1D28
    if (ctx->r2 == ctx->r1) {
        // 0x800B1D1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800B1D28;
    }
    // 0x800B1D1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1D20: bne         $v0, $at, L_800B1E44
    if (ctx->r2 != ctx->r1) {
        // 0x800B1D24: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B1E44;
    }
    // 0x800B1D24: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B1D28:
    // 0x800B1D28: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x800B1D2C: nop

    // 0x800B1D30: beq         $v1, $zero, L_800B1E44
    if (ctx->r3 == 0) {
        // 0x800B1D34: lb          $t3, 0x23($sp)
        ctx->r11 = MEM_B(ctx->r29, 0X23);
            goto L_800B1E44;
    }
    // 0x800B1D34: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
    // 0x800B1D38: lh          $a0, 0x4($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X4);
    // 0x800B1D3C: jal         0x8007B2C4
    // 0x800B1D40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_11;
    // 0x800B1D40: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_11:
    // 0x800B1D44: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800B1D48: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1D4C: beq         $v0, $zero, L_800B1E38
    if (ctx->r2 == 0) {
        // 0x800B1D50: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800B1E38;
    }
    // 0x800B1D50: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B1D54: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x800B1D58: nop

    // 0x800B1D5C: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800B1D60: beq         $t5, $zero, L_800B1DA0
    if (ctx->r13 == 0) {
        // 0x800B1D64: nop
    
            goto L_800B1DA0;
    }
    // 0x800B1D64: nop

    // 0x800B1D68: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x800B1D6C: nop

    // 0x800B1D70: andi        $t6, $t7, 0x1000
    ctx->r14 = ctx->r15 & 0X1000;
    // 0x800B1D74: beq         $t6, $zero, L_800B1D90
    if (ctx->r14 == 0) {
        // 0x800B1D78: nop
    
            goto L_800B1D90;
    }
    // 0x800B1D78: nop

    // 0x800B1D7C: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800B1D80: nop

    // 0x800B1D84: ori         $t9, $t8, 0x100
    ctx->r25 = ctx->r24 | 0X100;
    // 0x800B1D88: b           L_800B1DA0
    // 0x800B1D8C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_800B1DA0;
    // 0x800B1D8C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_800B1D90:
    // 0x800B1D90: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x800B1D94: nop

    // 0x800B1D98: ori         $t3, $t2, 0x80
    ctx->r11 = ctx->r10 | 0X80;
    // 0x800B1D9C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
L_800B1DA0:
    // 0x800B1DA0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1DA4: nop

    // 0x800B1DA8: andi        $t5, $t4, 0x800
    ctx->r13 = ctx->r12 & 0X800;
    // 0x800B1DAC: beq         $t5, $zero, L_800B1E00
    if (ctx->r13 == 0) {
        // 0x800B1DB0: nop
    
            goto L_800B1E00;
    }
    // 0x800B1DB0: nop

    // 0x800B1DB4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800B1DB8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B1DBC: lhu         $a1, 0x12($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X12);
    // 0x800B1DC0: nop

    // 0x800B1DC4: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B1DC8: jal         0x8006FB8C
    // 0x800B1DCC: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800B1DCC: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    after_12:
    // 0x800B1DD0: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800B1DD4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1DD8: sll         $t8, $v0, 8
    ctx->r24 = S32(ctx->r2 << 8);
    // 0x800B1DDC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1DE0: andi        $t2, $t9, 0x3
    ctx->r10 = ctx->r25 & 0X3;
    // 0x800B1DE4: bne         $t2, $at, L_800B1E40
    if (ctx->r10 != ctx->r1) {
        // 0x800B1DE8: sh          $t8, 0x18($s0)
        MEM_H(0X18, ctx->r16) = ctx->r24;
            goto L_800B1E40;
    }
    // 0x800B1DE8: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x800B1DEC: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800B1DF0: nop

    // 0x800B1DF4: ori         $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 | 0XFF;
    // 0x800B1DF8: b           L_800B1E40
    // 0x800B1DFC: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
        goto L_800B1E40;
    // 0x800B1DFC: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_800B1E00:
    // 0x800B1E00: lw          $t5, 0x40($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X40);
    // 0x800B1E04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1E08: andi        $t7, $t5, 0x3
    ctx->r15 = ctx->r13 & 0X3;
    // 0x800B1E0C: bne         $t7, $at, L_800B1E30
    if (ctx->r15 != ctx->r1) {
        // 0x800B1E10: nop
    
            goto L_800B1E30;
    }
    // 0x800B1E10: nop

    // 0x800B1E14: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B1E18: nop

    // 0x800B1E1C: lhu         $t8, 0x12($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X12);
    // 0x800B1E20: nop

    // 0x800B1E24: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800B1E28: b           L_800B1E40
    // 0x800B1E2C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
        goto L_800B1E40;
    // 0x800B1E2C: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_800B1E30:
    // 0x800B1E30: b           L_800B1E40
    // 0x800B1E34: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
        goto L_800B1E40;
    // 0x800B1E34: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
L_800B1E38:
    // 0x800B1E38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800B1E3C: sb          $t2, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r10;
L_800B1E40:
    // 0x800B1E40: lb          $t3, 0x23($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X23);
L_800B1E44:
    // 0x800B1E44: nop

    // 0x800B1E48: bne         $t3, $zero, L_800B1E94
    if (ctx->r11 != 0) {
        // 0x800B1E4C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1E94;
    }
    // 0x800B1E4C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1E50: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1E54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B1E58: bne         $v0, $at, L_800B1E78
    if (ctx->r2 != ctx->r1) {
        // 0x800B1E5C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B1E78;
    }
    // 0x800B1E5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B1E60: jal         0x800AF604
    // 0x800B1E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_triangle_texture_coords(rdram, ctx);
        goto after_13;
    // 0x800B1E64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x800B1E68: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1E6C: lh          $v0, 0x2C($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X2C);
    // 0x800B1E70: nop

    // 0x800B1E74: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800B1E78:
    // 0x800B1E78: bne         $v0, $at, L_800B1E94
    if (ctx->r2 != ctx->r1) {
        // 0x800B1E7C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B1E94;
    }
    // 0x800B1E7C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B1E80: jal         0x800AF650
    // 0x800B1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_rectangle_texture_coords(rdram, ctx);
        goto after_14;
    // 0x800B1E84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x800B1E88: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1E8C: nop

    // 0x800B1E90: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B1E94:
    // 0x800B1E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B1E98: jal         0x800B0920
    // 0x800B1E9C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_position(rdram, ctx);
        goto after_15;
    // 0x800B1E9C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_15:
    // 0x800B1EA0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800B1EA4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1EA8: andi        $t5, $t4, 0x80
    ctx->r13 = ctx->r12 & 0X80;
    // 0x800B1EAC: beq         $t5, $zero, L_800B1EDC
    if (ctx->r13 == 0) {
        // 0x800B1EB0: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_800B1EDC;
    }
    // 0x800B1EB0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B1EB4: lh          $t7, 0x44($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X44);
    // 0x800B1EB8: nop

    // 0x800B1EBC: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800B1EC0: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1EC4: nop

    // 0x800B1EC8: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x800B1ECC: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x800B1ED0: b           L_800B1F20
    // 0x800B1ED4: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
        goto L_800B1F20;
    // 0x800B1ED4: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x800B1ED8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_800B1EDC:
    // 0x800B1EDC: lh          $t3, 0x44($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X44);
    // 0x800B1EE0: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x800B1EE4: nop

    // 0x800B1EE8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1EEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x800B1EF0: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x800B1EF4: lh          $t6, 0x46($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X46);
    // 0x800B1EF8: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x800B1EFC: nop

    // 0x800B1F00: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B1F04: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800B1F08: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800B1F0C: lh          $t3, 0x48($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X48);
    // 0x800B1F10: lh          $t2, 0x4($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X4);
    // 0x800B1F14: nop

    // 0x800B1F18: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800B1F1C: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
L_800B1F20:
    // 0x800B1F20: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1F24: nop

    // 0x800B1F28: andi        $t5, $v1, 0x3800
    ctx->r13 = ctx->r3 & 0X3800;
    // 0x800B1F2C: beq         $t5, $zero, L_800B1FBC
    if (ctx->r13 == 0) {
        // 0x800B1F30: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800B1FBC;
    }
    // 0x800B1F30: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800B1F34: andi        $t7, $t5, 0x800
    ctx->r15 = ctx->r13 & 0X800;
    // 0x800B1F38: beq         $t7, $zero, L_800B1F68
    if (ctx->r15 == 0) {
        // 0x800B1F3C: andi        $t9, $v1, 0x1000
        ctx->r25 = ctx->r3 & 0X1000;
            goto L_800B1F68;
    }
    // 0x800B1F3C: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
    // 0x800B1F40: lh          $a1, 0x80($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X80);
    // 0x800B1F44: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x800B1F48: jal         0x8006FB8C
    // 0x800B1F4C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_16;
    // 0x800B1F4C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_16:
    // 0x800B1F50: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800B1F54: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F58: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1F5C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B1F60: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800B1F64: andi        $t9, $v1, 0x1000
    ctx->r25 = ctx->r3 & 0X1000;
L_800B1F68:
    // 0x800B1F68: beq         $t9, $zero, L_800B1F98
    if (ctx->r25 == 0) {
        // 0x800B1F6C: andi        $t4, $v1, 0x2000
        ctx->r12 = ctx->r3 & 0X2000;
            goto L_800B1F98;
    }
    // 0x800B1F6C: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x800B1F70: lh          $a1, 0x82($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X82);
    // 0x800B1F74: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B1F78: jal         0x8006FB8C
    // 0x800B1F7C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_17;
    // 0x800B1F7C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_17:
    // 0x800B1F80: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800B1F84: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B1F88: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1F8C: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B1F90: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
    // 0x800B1F94: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
L_800B1F98:
    // 0x800B1F98: beq         $t4, $zero, L_800B1FBC
    if (ctx->r12 == 0) {
        // 0x800B1F9C: nop
    
            goto L_800B1FBC;
    }
    // 0x800B1F9C: nop

    // 0x800B1FA0: lh          $a1, 0x84($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X84);
    // 0x800B1FA4: jal         0x8006FB8C
    // 0x800B1FA8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_18;
    // 0x800B1FA8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_18:
    // 0x800B1FAC: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x800B1FB0: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B1FB4: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800B1FB8: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
L_800B1FBC:
    // 0x800B1FBC: lh          $t6, 0x4A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4A);
    // 0x800B1FC0: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800B1FC4: sh          $t6, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r14;
    // 0x800B1FC8: lh          $t8, 0x4C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X4C);
    // 0x800B1FCC: ori         $at, $at, 0xC000
    ctx->r1 = ctx->r1 | 0XC000;
    // 0x800B1FD0: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B1FD4: lh          $t9, 0x4E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4E);
    // 0x800B1FD8: nop

    // 0x800B1FDC: sh          $t9, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r25;
    // 0x800B1FE0: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B1FE4: nop

    // 0x800B1FE8: and         $t2, $v1, $at
    ctx->r10 = ctx->r3 & ctx->r1;
    // 0x800B1FEC: beq         $t2, $zero, L_800B207C
    if (ctx->r10 == 0) {
        // 0x800B1FF0: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_800B207C;
    }
    // 0x800B1FF0: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800B1FF4: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x800B1FF8: beq         $t3, $zero, L_800B2028
    if (ctx->r11 == 0) {
        // 0x800B1FFC: andi        $t7, $v1, 0x8000
        ctx->r15 = ctx->r3 & 0X8000;
            goto L_800B2028;
    }
    // 0x800B1FFC: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800B2000: lh          $a1, 0x86($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X86);
    // 0x800B2004: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800B2008: jal         0x8006FB8C
    // 0x800B200C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_19;
    // 0x800B200C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_19:
    // 0x800B2010: lh          $t4, 0x62($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X62);
    // 0x800B2014: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2018: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B201C: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B2020: sh          $t5, 0x62($s0)
    MEM_H(0X62, ctx->r16) = ctx->r13;
    // 0x800B2024: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
L_800B2028:
    // 0x800B2028: beq         $t7, $zero, L_800B2058
    if (ctx->r15 == 0) {
        // 0x800B202C: sll         $t9, $v1, 15
        ctx->r25 = S32(ctx->r3 << 15);
            goto L_800B2058;
    }
    // 0x800B202C: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
    // 0x800B2030: lh          $a1, 0x88($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X88);
    // 0x800B2034: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B2038: jal         0x8006FB8C
    // 0x800B203C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_20;
    // 0x800B203C: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_20:
    // 0x800B2040: lh          $t6, 0x64($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X64);
    // 0x800B2044: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B2048: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B204C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x800B2050: sh          $t8, 0x64($s0)
    MEM_H(0X64, ctx->r16) = ctx->r24;
    // 0x800B2054: sll         $t9, $v1, 15
    ctx->r25 = S32(ctx->r3 << 15);
L_800B2058:
    // 0x800B2058: bgez        $t9, L_800B2080
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800B205C: lw          $a1, 0x40($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X40);
            goto L_800B2080;
    }
    // 0x800B205C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800B2060: lh          $a1, 0x8A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X8A);
    // 0x800B2064: jal         0x8006FB8C
    // 0x800B2068: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_21;
    // 0x800B2068: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_21:
    // 0x800B206C: lh          $t2, 0x66($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X66);
    // 0x800B2070: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B2074: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800B2078: sh          $t3, 0x66($s0)
    MEM_H(0X66, ctx->r16) = ctx->r11;
L_800B207C:
    // 0x800B207C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
L_800B2080:
    // 0x800B2080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B2084: jal         0x800B0570
    // 0x800B2088: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    setup_particle_velocity(rdram, ctx);
        goto after_22;
    // 0x800B2088: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_22:
    // 0x800B208C: lw          $t4, 0x40($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X40);
    // 0x800B2090: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2094: sra         $t5, $t4, 4
    ctx->r13 = S32(SIGNED(ctx->r12) >> 4);
    // 0x800B2098: andi        $t7, $t5, 0x7
    ctx->r15 = ctx->r13 & 0X7;
    // 0x800B209C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800B20A0: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B20A4: lwc1        $f4, 0x33BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X33BC);
    // 0x800B20A8: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x800B20AC: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B20B0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800B20B4: bne         $t8, $at, L_800B20EC
    if (ctx->r24 != ctx->r1) {
        // 0x800B20B8: swc1        $f4, 0x68($s0)
        MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
            goto L_800B20EC;
    }
    // 0x800B20B8: swc1        $f4, 0x68($s0)
    MEM_W(0X68, ctx->r16) = ctx->f4.u32l;
    // 0x800B20BC: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B20C0: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B20C4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B20C8: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B20CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B20D0: nop

    // 0x800B20D4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B20D8: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B20DC: jal         0x800CA030
    // 0x800B20E0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_23;
    // 0x800B20E0: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_23:
    // 0x800B20E4: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x800B20E8: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_800B20EC:
    // 0x800B20EC: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B20F0: nop

    // 0x800B20F4: andi        $t2, $t9, 0x2
    ctx->r10 = ctx->r25 & 0X2;
    // 0x800B20F8: beq         $t2, $zero, L_800B2168
    if (ctx->r10 == 0) {
        // 0x800B20FC: nop
    
            goto L_800B2168;
    }
    // 0x800B20FC: nop

    // 0x800B2100: lbu         $t3, 0x6($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X6);
    // 0x800B2104: nop

    // 0x800B2108: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B210C: sb          $t4, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r12;
    // 0x800B2110: lh          $t5, 0x1A($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A);
    // 0x800B2114: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B2118: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B211C: bne         $at, $zero, L_800B2168
    if (ctx->r1 != 0) {
        // 0x800B2120: nop
    
            goto L_800B2168;
    }
    // 0x800B2120: nop

    // 0x800B2124: lh          $t7, 0xC($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XC);
    // 0x800B2128: lh          $t6, 0x1C($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1C);
    // 0x800B212C: lh          $t9, 0xE($a2)
    ctx->r25 = MEM_H(ctx->r6, 0XE);
    // 0x800B2130: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B2134: sh          $t8, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r24;
    // 0x800B2138: lh          $t2, 0x1E($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1E);
    // 0x800B213C: lh          $t4, 0x10($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X10);
    // 0x800B2140: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B2144: sh          $t3, 0xE($a2)
    MEM_H(0XE, ctx->r6) = ctx->r11;
    // 0x800B2148: lh          $t5, 0x18($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X18);
    // 0x800B214C: nop

    // 0x800B2150: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B2154: sh          $t7, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r15;
    // 0x800B2158: lh          $t6, 0x1A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1A);
    // 0x800B215C: nop

    // 0x800B2160: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B2164: sb          $t8, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r24;
L_800B2168:
    // 0x800B2168: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x800B216C: nop

    // 0x800B2170: andi        $t2, $t9, 0x8
    ctx->r10 = ctx->r25 & 0X8;
    // 0x800B2174: beq         $t2, $zero, L_800B21E4
    if (ctx->r10 == 0) {
        // 0x800B2178: nop
    
            goto L_800B21E4;
    }
    // 0x800B2178: nop

    // 0x800B217C: lbu         $t3, 0x7($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0X7);
    // 0x800B2180: nop

    // 0x800B2184: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B2188: sb          $t4, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r12;
    // 0x800B218C: lh          $t5, 0x28($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X28);
    // 0x800B2190: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x800B2194: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2198: bne         $at, $zero, L_800B21E4
    if (ctx->r1 != 0) {
        // 0x800B219C: nop
    
            goto L_800B21E4;
    }
    // 0x800B219C: nop

    // 0x800B21A0: lh          $t7, 0x12($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X12);
    // 0x800B21A4: lh          $t6, 0x2A($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X2A);
    // 0x800B21A8: lh          $t9, 0x14($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X14);
    // 0x800B21AC: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800B21B0: sh          $t8, 0x12($a2)
    MEM_H(0X12, ctx->r6) = ctx->r24;
    // 0x800B21B4: lh          $t2, 0x2C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X2C);
    // 0x800B21B8: lh          $t4, 0x16($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X16);
    // 0x800B21BC: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x800B21C0: sh          $t3, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r11;
    // 0x800B21C4: lh          $t5, 0x2E($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X2E);
    // 0x800B21C8: nop

    // 0x800B21CC: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800B21D0: sh          $t7, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r15;
    // 0x800B21D4: lh          $t6, 0x28($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X28);
    // 0x800B21D8: nop

    // 0x800B21DC: subu        $t8, $v0, $t6
    ctx->r24 = SUB32(ctx->r2, ctx->r14);
    // 0x800B21E0: sb          $t8, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r24;
L_800B21E4:
    // 0x800B21E4: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800B21E8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B21EC: bne         $t9, $zero, L_800B2204
    if (ctx->r25 != 0) {
        // 0x800B21F0: nop
    
            goto L_800B2204;
    }
    // 0x800B21F0: nop

    // 0x800B21F4: jal         0x800B25A0
    // 0x800B21F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    particle_deallocate(rdram, ctx);
        goto after_24;
    // 0x800B21F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_24:
    // 0x800B21FC: b           L_800B2204
    // 0x800B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800B2204;
    // 0x800B2200: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800B2204:
    // 0x800B2204: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B2208: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B220C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B2210: jr          $ra
    // 0x800B2214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B2214: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void racer_sound_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005254: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x80005258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000525C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005260: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80005264: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80005268: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000526C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80005270: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80005274: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80005278: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000527C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80005280: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x80005284: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x80005288: sw          $a2, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r6;
    // 0x8000528C: sw          $a3, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r7;
    // 0x80005290: lb          $t6, 0x1FB($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X1FB);
    // 0x80005294: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80005298: beq         $t6, $zero, L_800052B0
    if (ctx->r14 == 0) {
        // 0x8000529C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_800052B0;
    }
    // 0x8000529C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800052A0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800052A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800052A8: b           L_800052BC
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
        goto L_800052BC;
    // 0x800052AC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052B0:
    // 0x800052B0: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x800052B4: nop

    // 0x800052B8: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
L_800052BC:
    // 0x800052BC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800052C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800052C4: bc1f        L_800052D0
    if (!c1cs) {
        // 0x800052C8: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800052D0;
    }
    // 0x800052C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800052CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800052D0:
    // 0x800052D0: nop

    // 0x800052D4: div.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800052D8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800052DC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800052E0: lw          $s2, 0xA8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA8);
    // 0x800052E4: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800052E8: andi        $t8, $s2, 0x8000
    ctx->r24 = ctx->r18 & 0X8000;
    // 0x800052EC: or          $s2, $t8, $zero
    ctx->r18 = ctx->r24 | 0;
    // 0x800052F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800052F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800052F8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800052FC: nop

    // 0x80005300: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80005304: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80005308: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000530C: nop

    // 0x80005310: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80005314: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80005318: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000531C: addiu       $s0, $v0, 0x5
    ctx->r16 = ADD32(ctx->r2, 0X5);
    // 0x80005320: slti        $at, $s0, 0x65
    ctx->r1 = SIGNED(ctx->r16) < 0X65 ? 1 : 0;
    // 0x80005324: bne         $at, $zero, L_80005330
    if (ctx->r1 != 0) {
        // 0x80005328: nop
    
            goto L_80005330;
    }
    // 0x80005328: nop

    // 0x8000532C: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
L_80005330:
    // 0x80005330: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005334: lwc1        $f21, 0x5188($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X5188);
    // 0x80005338: lwc1        $f20, 0x518C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X518C);
    // 0x8000533C: lw          $a3, -0x5E48($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5E48);
    // 0x80005340: addiu       $s1, $s1, -0x5E48
    ctx->r17 = ADD32(ctx->r17, -0X5E48);
L_80005344:
    // 0x80005344: addu        $t9, $a3, $t4
    ctx->r25 = ADD32(ctx->r7, ctx->r12);
    // 0x80005348: lhu         $t5, 0x0($t9)
    ctx->r13 = MEM_HU(ctx->r25, 0X0);
    // 0x8000534C: sll         $t6, $t1, 2
    ctx->r14 = S32(ctx->r9 << 2);
    // 0x80005350: beq         $t5, $zero, L_80005A0C
    if (ctx->r13 == 0) {
        // 0x80005354: addu        $t6, $t6, $t1
        ctx->r14 = ADD32(ctx->r14, ctx->r9);
            goto L_80005A0C;
    }
    // 0x80005354: addu        $t6, $t6, $t1
    ctx->r14 = ADD32(ctx->r14, ctx->r9);
    // 0x80005358: addu        $t0, $a3, $t6
    ctx->r8 = ADD32(ctx->r7, ctx->r14);
    // 0x8000535C: lbu         $t7, 0xE($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0XE);
    // 0x80005360: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005364: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80005368: bne         $at, $zero, L_8000538C
    if (ctx->r1 != 0) {
        // 0x8000536C: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_8000538C;
    }
    // 0x8000536C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80005370: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x80005374: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x80005378: addu        $a2, $a3, $t8
    ctx->r6 = ADD32(ctx->r7, ctx->r24);
    // 0x8000537C: lbu         $t9, 0xF($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XF);
    // 0x80005380: nop

    // 0x80005384: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005388: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x8000538C: sll         $t5, $t1, 2
        ctx->r13 = S32(ctx->r9 << 2);
            goto L_800053CC;
    }
L_8000538C:
    // 0x8000538C: sll         $t5, $t1, 2
    ctx->r13 = S32(ctx->r9 << 2);
    // 0x80005390: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x80005394: addu        $a2, $a3, $t5
    ctx->r6 = ADD32(ctx->r7, ctx->r13);
    // 0x80005398: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
L_8000539C:
    // 0x8000539C: lbu         $t6, 0xF($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XF);
    // 0x800053A0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800053A4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800053A8: bne         $at, $zero, L_800053C0
    if (ctx->r1 != 0) {
        // 0x800053AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800053C0;
    }
    // 0x800053AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800053B0: lbu         $t7, 0xF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0XF);
    // 0x800053B4: nop

    // 0x800053B8: slt         $at, $t7, $s0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800053BC: beq         $at, $zero, L_800053CC
    if (ctx->r1 == 0) {
        // 0x800053C0: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800053CC;
    }
L_800053C0:
    // 0x800053C0: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800053C4: bne         $at, $zero, L_8000539C
    if (ctx->r1 != 0) {
        // 0x800053C8: nop
    
            goto L_8000539C;
    }
    // 0x800053C8: nop

L_800053CC:
    // 0x800053CC: addu        $v0, $t0, $v1
    ctx->r2 = ADD32(ctx->r8, ctx->r3);
    // 0x800053D0: lbu         $a0, 0xE($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XE);
    // 0x800053D4: lbu         $t9, 0xF($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XF);
    // 0x800053D8: subu        $t8, $s0, $a0
    ctx->r24 = SUB32(ctx->r16, ctx->r4);
    // 0x800053DC: subu        $t5, $t9, $a0
    ctx->r13 = SUB32(ctx->r25, ctx->r4);
    // 0x800053E0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800053E4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800053E8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800053EC: lbu         $a1, 0x2C($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X2C);
    // 0x800053F0: lbu         $t6, 0x2D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2D);
    // 0x800053F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800053F8: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x800053FC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80005400: div.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005404: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005408: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8000540C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80005410: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005414: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005418: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000541C: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80005420: bgez        $a1, L_80005434
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80005424: nop
    
            goto L_80005434;
    }
    // 0x80005424: nop

    // 0x80005428: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000542C: nop

    // 0x80005430: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80005434:
    // 0x80005434: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80005438: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000543C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005440: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005444: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005448: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000544C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005450: nop

    // 0x80005454: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005458: beq         $t3, $zero, L_800054A4
    if (ctx->r11 == 0) {
        // 0x8000545C: nop
    
            goto L_800054A4;
    }
    // 0x8000545C: nop

    // 0x80005460: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005464: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80005468: sub.s       $f10, $f4, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000546C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005470: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80005474: nop

    // 0x80005478: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000547C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80005480: nop

    // 0x80005484: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80005488: bne         $t3, $zero, L_8000549C
    if (ctx->r11 != 0) {
        // 0x8000548C: nop
    
            goto L_8000549C;
    }
    // 0x8000548C: nop

    // 0x80005490: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80005494: b           L_800054B4
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800054B4;
    // 0x80005498: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_8000549C:
    // 0x8000549C: b           L_800054B4
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800054B4;
    // 0x800054A0: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_800054A4:
    // 0x800054A4: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800054A8: nop

    // 0x800054AC: bltz        $t3, L_8000549C
    if (SIGNED(ctx->r11) < 0) {
        // 0x800054B0: nop
    
            goto L_8000549C;
    }
    // 0x800054B0: nop

L_800054B4:
    // 0x800054B4: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x800054B8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800054BC: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800054C0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800054C4: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x800054C8: or          $t3, $t9, $zero
        ctx->r11 = ctx->r25 | 0;
            goto L_800054E0;
    }
    // 0x800054C8: or          $t3, $t9, $zero
    ctx->r11 = ctx->r25 | 0;
    // 0x800054CC: lbu         $t6, 0x5($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X5);
    // 0x800054D0: nop

    // 0x800054D4: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800054D8: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x800054DC: nop
    
            goto L_80005510;
    }
    // 0x800054DC: nop

L_800054E0:
    // 0x800054E0: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x800054E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800054E8: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800054EC: bne         $at, $zero, L_80005504
    if (ctx->r1 != 0) {
        // 0x800054F0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80005504;
    }
    // 0x800054F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800054F4: lbu         $t8, 0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X5);
    // 0x800054F8: nop

    // 0x800054FC: slt         $at, $t8, $s0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80005500: beq         $at, $zero, L_80005510
    if (ctx->r1 == 0) {
        // 0x80005504: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80005510;
    }
L_80005504:
    // 0x80005504: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80005508: bne         $at, $zero, L_800054E0
    if (ctx->r1 != 0) {
        // 0x8000550C: nop
    
            goto L_800054E0;
    }
    // 0x8000550C: nop

L_80005510:
    // 0x80005510: addu        $v0, $a2, $v1
    ctx->r2 = ADD32(ctx->r6, ctx->r3);
    // 0x80005514: lbu         $a0, 0x4($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X4);
    // 0x80005518: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x8000551C: lbu         $t5, 0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X5);
    // 0x80005520: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x80005524: subu        $t9, $s0, $a0
    ctx->r25 = SUB32(ctx->r16, ctx->r4);
    // 0x80005528: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8000552C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80005530: addu        $t8, $a3, $t7
    ctx->r24 = ADD32(ctx->r7, ctx->r15);
    // 0x80005534: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x80005538: subu        $t6, $t5, $a0
    ctx->r14 = SUB32(ctx->r13, ctx->r4);
    // 0x8000553C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    // 0x80005540: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80005544: lhu         $t5, 0x18($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X18);
    // 0x80005548: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000554C: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x80005550: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005554: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80005558: lwc1        $f0, 0x5190($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5190);
    // 0x8000555C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005560: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80005564: bgez        $t5, L_80005578
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80005568: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80005578;
    }
    // 0x80005568: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000556C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005570: nop

    // 0x80005574: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_80005578:
    // 0x80005578: lhu         $t6, 0x1A($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1A);
    // 0x8000557C: div.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80005580: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80005584: bgez        $t6, L_8000559C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80005588: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000559C;
    }
    // 0x80005588: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000558C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005594: nop

    // 0x80005598: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_8000559C:
    // 0x8000559C: slti        $at, $s0, 0x33
    ctx->r1 = SIGNED(ctx->r16) < 0X33 ? 1 : 0;
    // 0x800055A0: bne         $at, $zero, L_8000567C
    if (ctx->r1 != 0) {
        // 0x800055A4: div.s       $f18, $f8, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
            goto L_8000567C;
    }
    // 0x800055A4: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800055A8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800055AC: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x800055B0: nop

    // 0x800055B4: lb          $v0, 0x185($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X185);
    // 0x800055B8: nop

    // 0x800055BC: beq         $v0, $zero, L_8000567C
    if (ctx->r2 == 0) {
        // 0x800055C0: slti        $at, $v0, 0xB
        ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
            goto L_8000567C;
    }
    // 0x800055C0: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800055C4: beq         $at, $zero, L_800055D4
    if (ctx->r1 == 0) {
        // 0x800055C8: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800055D4;
    }
    // 0x800055C8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800055CC: b           L_800055D4
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800055D4;
    // 0x800055D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800055D4:
    // 0x800055D4: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800055D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800055DC: cvt.d.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.d = CVT_D_W(ctx->f10.u32l);
    // 0x800055E0: lwc1        $f5, 0x5198($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5198);
    // 0x800055E4: lwc1        $f4, 0x519C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X519C);
    // 0x800055E8: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800055EC: mul.d       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800055F0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800055F4: sll         $t7, $v1, 6
    ctx->r15 = S32(ctx->r3 << 6);
    // 0x800055F8: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x800055FC: nop

    // 0x80005600: bc1f        L_8000563C
    if (!c1cs) {
        // 0x80005604: nop
    
            goto L_8000563C;
    }
    // 0x80005604: nop

    // 0x80005608: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000560C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005610: cvt.d.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.d = CVT_D_W(ctx->f8.u32l);
    // 0x80005614: nop

    // 0x80005618: div.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f10.d);
    // 0x8000561C: add.d       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f2.d + ctx->f4.d;
    // 0x80005620: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005624: swc1        $f8, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f8.u32l;
    // 0x80005628: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000562C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005630: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005634: b           L_8000566C
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
        goto L_8000566C;
    // 0x80005638: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000563C:
    // 0x8000563C: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80005640: nop

    // 0x80005644: bc1f        L_80005668
    if (!c1cs) {
        // 0x80005648: nop
    
            goto L_80005668;
    }
    // 0x80005648: nop

    // 0x8000564C: cvt.s.d     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f10.fl = CVT_S_D(ctx->f0.d);
    // 0x80005650: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005654: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x80005658: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000565C: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005660: lwc1        $f12, 0x3C($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005664: nop

L_80005668:
    // 0x80005668: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
L_8000566C:
    // 0x8000566C: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x80005670: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x80005674: b           L_800056C0
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
        goto L_800056C0;
    // 0x80005678: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
L_8000567C:
    // 0x8000567C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005680: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x80005684: lwc1        $f7, 0x51A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X51A0);
    // 0x80005688: lwc1        $f6, 0x51A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51A4);
    // 0x8000568C: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80005690: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80005694: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80005698: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000569C: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800056A0: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800056A4: swc1        $f10, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f10.u32l;
    // 0x800056A8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800056AC: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x800056B0: add.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800056B4: lwc1        $f10, 0x3C($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800056B8: nop

    // 0x800056BC: add.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f10.fl;
L_800056C0:
    // 0x800056C0: lb          $t8, 0x1E6($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X1E6);
    // 0x800056C4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800056C8: beq         $t8, $zero, L_8000570C
    if (ctx->r24 == 0) {
        // 0x800056CC: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8000570C;
    }
    // 0x800056CC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800056D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800056D4: lwc1        $f7, 0x51A8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X51A8);
    // 0x800056D8: lwc1        $f6, 0x51AC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X51AC);
    // 0x800056DC: lwc1        $f4, 0x40($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800056E0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800056E4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800056E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800056EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800056F0: sub.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d - ctx->f0.d;
    // 0x800056F4: nop

    // 0x800056F8: div.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800056FC: add.d       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f0.d + ctx->f4.d;
    // 0x80005700: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x80005704: b           L_80005720
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
        goto L_80005720;
    // 0x80005708: swc1        $f8, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f8.u32l;
L_8000570C:
    // 0x8000570C: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x80005710: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005714: nop

    // 0x80005718: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000571C: swc1        $f6, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->f6.u32l;
L_80005720:
    // 0x80005720: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005724: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005728: lwc1        $f8, 0x40($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X40);
    // 0x8000572C: lb          $t9, 0x1E2($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1E2);
    // 0x80005730: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005734: bne         $t9, $zero, L_80005760
    if (ctx->r25 != 0) {
        // 0x80005738: add.s       $f2, $f2, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
            goto L_80005760;
    }
    // 0x80005738: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8000573C: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x80005740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80005744: beq         $t5, $at, L_80005760
    if (ctx->r13 == ctx->r1) {
        // 0x80005748: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005760;
    }
    // 0x80005748: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000574C: lwc1        $f5, 0x51B0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51B0);
    // 0x80005750: lwc1        $f4, 0x51B4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51B4);
    // 0x80005754: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80005758: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8000575C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
L_80005760:
    // 0x80005760: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80005764: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005768: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000576C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80005770: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x80005774: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005778: div.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000577C: bgez        $t3, L_80005790
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80005780: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005790;
    }
    // 0x80005780: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005784: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005788: nop

    // 0x8000578C: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80005790:
    // 0x80005790: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80005794: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80005798: lwc1        $f4, 0x54($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8000579C: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x800057A0: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800057A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800057A8: beq         $t6, $at, L_800058B4
    if (ctx->r14 == ctx->r1) {
        // 0x800057AC: div.s       $f14, $f6, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
            goto L_800058B4;
    }
    // 0x800057AC: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800057B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057B4: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057B8: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057BC: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057C0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800057C4: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x800057C8: jal         0x8006FB8C
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800057CC: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800057D0: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x800057D4: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800057D8: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800057DC: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800057E0: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800057E4: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x800057E8: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x800057EC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005868;
    }
    // 0x800057EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800057F0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800057F4: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x800057F8: sw          $t2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r10;
    // 0x800057FC: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x80005800: swc1        $f12, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f12.u32l;
    // 0x80005804: jal         0x8006FB8C
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80005808: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8000580C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005810: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80005814: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005818: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8000581C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80005820: addiu       $t9, $t8, -0x5
    ctx->r25 = ADD32(ctx->r24, -0X5);
    // 0x80005824: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x80005828: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000582C: lwc1        $f14, 0x78($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80005830: sb          $t9, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r25;
    // 0x80005834: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005838: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000583C: lb          $v1, 0x90($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X90);
    // 0x80005840: nop

    // 0x80005844: slti        $at, $v1, 0x6
    ctx->r1 = SIGNED(ctx->r3) < 0X6 ? 1 : 0;
    // 0x80005848: bne         $at, $zero, L_8000585C
    if (ctx->r1 != 0) {
        // 0x8000584C: slti        $at, $v1, -0x5
        ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
            goto L_8000585C;
    }
    // 0x8000584C: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
    // 0x80005850: b           L_80005868
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
        goto L_80005868;
    // 0x80005854: sb          $t5, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r13;
    // 0x80005858: slti        $at, $v1, -0x5
    ctx->r1 = SIGNED(ctx->r3) < -0X5 ? 1 : 0;
L_8000585C:
    // 0x8000585C: beq         $at, $zero, L_80005868
    if (ctx->r1 == 0) {
        // 0x80005860: addiu       $t6, $zero, -0x5
        ctx->r14 = ADD32(0, -0X5);
            goto L_80005868;
    }
    // 0x80005860: addiu       $t6, $zero, -0x5
    ctx->r14 = ADD32(0, -0X5);
    // 0x80005864: sb          $t6, 0x90($a3)
    MEM_B(0X90, ctx->r7) = ctx->r14;
L_80005868:
    // 0x80005868: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000586C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005870: lb          $t7, 0x90($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X90);
    // 0x80005874: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005878: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8000587C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005880: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005884: lwc1        $f11, 0x51B8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51B8);
    // 0x80005888: lwc1        $f10, 0x51BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51BC);
    // 0x8000588C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005890: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80005894: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80005898: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8000589C: mul.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x800058A0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800058A4: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800058A8: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800058AC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
    // 0x800058B0: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
L_800058B4:
    // 0x800058B4: beq         $s2, $zero, L_8000593C
    if (ctx->r18 == 0) {
        // 0x800058B8: nop
    
            goto L_8000593C;
    }
    // 0x800058B8: nop

    // 0x800058BC: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x800058C0: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800058C4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800058C8: c.lt.d      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.d < ctx->f20.d;
    // 0x800058CC: nop

    // 0x800058D0: bc1f        L_8000593C
    if (!c1cs) {
        // 0x800058D4: nop
    
            goto L_8000593C;
    }
    // 0x800058D4: nop

    // 0x800058D8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800058DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058E0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800058E4: lwc1        $f5, 0x51C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51C0);
    // 0x800058E8: lwc1        $f4, 0x51C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51C4);
    // 0x800058EC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800058F0: mul.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f4.d);
    // 0x800058F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800058F8: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x800058FC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80005900: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
    // 0x80005904: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005908: nop

    // 0x8000590C: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005910: nop

    // 0x80005914: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005918: c.lt.d      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.d < ctx->f10.d;
    // 0x8000591C: nop

    // 0x80005920: bc1f        L_8000593C
    if (!c1cs) {
        // 0x80005924: nop
    
            goto L_8000593C;
    }
    // 0x80005924: nop

    // 0x80005928: lwc1        $f8, 0x51C8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51C8);
    // 0x8000592C: nop

    // 0x80005930: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005934: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005938: nop

L_8000593C:
    // 0x8000593C: bne         $s2, $zero, L_800059B8
    if (ctx->r18 != 0) {
        // 0x80005940: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005940: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x80005944: lwc1        $f0, 0x94($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005948: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x8000594C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80005950: nop

    // 0x80005954: bc1f        L_800059B8
    if (!c1cs) {
        // 0x80005958: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x80005958: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8000595C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80005960: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005964: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005968: lwc1        $f9, 0x51D0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X51D0);
    // 0x8000596C: lwc1        $f8, 0x51D4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51D4);
    // 0x80005970: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80005974: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80005978: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8000597C: sub.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d - ctx->f6.d;
    // 0x80005980: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80005984: swc1        $f8, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f8.u32l;
    // 0x80005988: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x8000598C: nop

    // 0x80005990: lwc1        $f4, 0x94($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80005994: nop

    // 0x80005998: c.lt.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl < ctx->f22.fl;
    // 0x8000599C: nop

    // 0x800059A0: bc1f        L_800059B8
    if (!c1cs) {
        // 0x800059A4: addu        $v0, $a3, $t2
        ctx->r2 = ADD32(ctx->r7, ctx->r10);
            goto L_800059B8;
    }
    // 0x800059A4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x800059A8: swc1        $f22, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f22.u32l;
    // 0x800059AC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059B0: nop

    // 0x800059B4: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
L_800059B8:
    // 0x800059B8: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x800059BC: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800059C0: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x800059C4: beq         $s2, $zero, L_800059F4
    if (ctx->r18 == 0) {
        // 0x800059C8: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_800059F4;
    }
    // 0x800059C8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x800059CC: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x800059D0: nop

    // 0x800059D4: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800059D8: lwc1        $f8, 0x54($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800059DC: nop

    // 0x800059E0: add.s       $f4, $f8, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800059E4: swc1        $f4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f4.u32l;
    // 0x800059E8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800059EC: b           L_80005A10
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
        goto L_80005A10;
    // 0x800059F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800059F4:
    // 0x800059F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800059F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800059FC: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x80005A00: swc1        $f6, 0x54($t7)
    MEM_W(0X54, ctx->r15) = ctx->f6.u32l;
    // 0x80005A04: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005A08: nop

L_80005A0C:
    // 0x80005A0C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_80005A10:
    // 0x80005A10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005A14: bne         $t1, $at, L_80005344
    if (ctx->r9 != ctx->r1) {
        // 0x80005A18: addiu       $t4, $t4, 0x2
        ctx->r12 = ADD32(ctx->r12, 0X2);
            goto L_80005344;
    }
    // 0x80005A18: addiu       $t4, $t4, 0x2
    ctx->r12 = ADD32(ctx->r12, 0X2);
    // 0x80005A1C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80005A20: lw          $t0, -0x5E44($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E44);
    // 0x80005A24: nop

    // 0x80005A28: lw          $t8, 0x10($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X10);
    // 0x80005A2C: nop

    // 0x80005A30: bne         $t8, $zero, L_80005A80
    if (ctx->r24 != 0) {
        // 0x80005A34: nop
    
            goto L_80005A80;
    }
    // 0x80005A34: nop

    // 0x80005A38: lw          $t9, 0x14($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X14);
    // 0x80005A3C: lw          $t5, 0xA8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA8);
    // 0x80005A40: bne         $t9, $zero, L_80005A80
    if (ctx->r25 != 0) {
        // 0x80005A44: andi        $t6, $t5, 0x4000
        ctx->r14 = ctx->r13 & 0X4000;
            goto L_80005A80;
    }
    // 0x80005A44: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x80005A48: beq         $t6, $zero, L_80005A80
    if (ctx->r14 == 0) {
        // 0x80005A4C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80005A80;
    }
    // 0x80005A4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005A50: lwc1        $f8, 0x2C($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005A54: lwc1        $f11, 0x51D8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51D8);
    // 0x80005A58: lwc1        $f10, 0x51DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51DC);
    // 0x80005A5C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80005A60: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x80005A64: nop

    // 0x80005A68: bc1t        L_80005A80
    if (c1cs) {
        // 0x80005A6C: nop
    
            goto L_80005A80;
    }
    // 0x80005A6C: nop

    // 0x80005A70: lb          $t7, 0x1D6($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X1D6);
    // 0x80005A74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80005A78: bne         $t7, $at, L_80005ABC
    if (ctx->r15 != ctx->r1) {
        // 0x80005A7C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A7C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005A80:
    // 0x80005A80: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005A84: nop

    // 0x80005A88: beq         $a0, $zero, L_80005ABC
    if (ctx->r4 == 0) {
        // 0x80005A8C: lw          $t9, 0xA4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XA4);
            goto L_80005ABC;
    }
    // 0x80005A8C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80005A90: jal         0x8000488C
    // 0x80005A94: nop

    sndp_stop(rdram, ctx);
        goto after_2;
    // 0x80005A94: nop

    after_2:
    // 0x80005A98: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005A9C: nop

    // 0x80005AA0: sw          $zero, 0xA8($t8)
    MEM_W(0XA8, ctx->r24) = 0;
    // 0x80005AA4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005AA8: nop

    // 0x80005AAC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AB0: b           L_80005BA0
    // 0x80005AB4: nop

        goto L_80005BA0;
    // 0x80005AB4: nop

    // 0x80005AB8: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
L_80005ABC:
    // 0x80005ABC: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005AC0: andi        $t5, $t9, 0x4000
    ctx->r13 = ctx->r25 & 0X4000;
    // 0x80005AC4: beq         $t5, $zero, L_80005BA0
    if (ctx->r13 == 0) {
        // 0x80005AC8: nop
    
            goto L_80005BA0;
    }
    // 0x80005AC8: nop

    // 0x80005ACC: bne         $a0, $zero, L_80005BA0
    if (ctx->r4 != 0) {
        // 0x80005AD0: nop
    
            goto L_80005BA0;
    }
    // 0x80005AD0: nop

    // 0x80005AD4: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x80005AD8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005ADC: bltz        $t6, L_80005BA0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80005AE0: addiu       $a1, $a3, 0xA8
        ctx->r5 = ADD32(ctx->r7, 0XA8);
            goto L_80005BA0;
    }
    // 0x80005AE0: addiu       $a1, $a3, 0xA8
    ctx->r5 = ADD32(ctx->r7, 0XA8);
    // 0x80005AE4: lwc1        $f0, 0x2C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X2C);
    // 0x80005AE8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005AEC: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80005AF0: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80005AF4: bc1f        L_80005B04
    if (!c1cs) {
        // 0x80005AF8: nop
    
            goto L_80005B04;
    }
    // 0x80005AF8: nop

    // 0x80005AFC: b           L_80005B08
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
        goto L_80005B08;
    // 0x80005B00: neg.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = -ctx->f0.fl;
L_80005B04:
    // 0x80005B04: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_80005B08:
    // 0x80005B08: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x80005B0C: nop

    // 0x80005B10: bc1f        L_80005B20
    if (!c1cs) {
        // 0x80005B14: nop
    
            goto L_80005B20;
    }
    // 0x80005B14: nop

    // 0x80005B18: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80005B1C: nop

L_80005B20:
    // 0x80005B20: jal         0x80001F14
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    sound_play_direct(rdram, ctx);
        goto after_3;
    // 0x80005B24: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_3:
    // 0x80005B28: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80005B2C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80005B30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80005B34: cvt.d.s     $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f8.d = CVT_D_S(ctx->f20.fl);
    // 0x80005B38: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80005B3C: lui         $at, 0x4028
    ctx->r1 = S32(0X4028 << 16);
    // 0x80005B40: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80005B44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005B48: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B4C: div.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x80005B50: add.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f6.d + ctx->f0.d;
    // 0x80005B54: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80005B58: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80005B5C: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B60: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x80005B64: beq         $a0, $zero, L_80005B80
    if (ctx->r4 == 0) {
        // 0x80005B68: addiu       $t7, $zero, 0x6E
        ctx->r15 = ADD32(0, 0X6E);
            goto L_80005B80;
    }
    // 0x80005B68: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
    // 0x80005B6C: jal         0x800049F8
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80005B70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_4:
    // 0x80005B74: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B78: nop

    // 0x80005B7C: addiu       $t7, $zero, 0x6E
    ctx->r15 = ADD32(0, 0X6E);
L_80005B80:
    // 0x80005B80: sh          $t7, 0xAC($a3)
    MEM_H(0XAC, ctx->r7) = ctx->r15;
    // 0x80005B84: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80005B88: nop

    // 0x80005B8C: sb          $zero, 0xD0($t8)
    MEM_B(0XD0, ctx->r24) = 0;
    // 0x80005B90: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005B94: nop

    // 0x80005B98: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005B9C: nop

L_80005BA0:
    // 0x80005BA0: beq         $a0, $zero, L_80005C48
    if (ctx->r4 == 0) {
        // 0x80005BA4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80005C48;
    }
    // 0x80005BA4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80005BA8: lw          $t9, -0x5E44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E44);
    // 0x80005BAC: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80005BB0: lb          $t5, 0x1E2($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X1E2);
    // 0x80005BB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80005BB8: bne         $t5, $zero, L_80005BD4
    if (ctx->r13 != 0) {
        // 0x80005BBC: addiu       $a1, $zero, 0x8
        ctx->r5 = ADD32(0, 0X8);
            goto L_80005BD4;
    }
    // 0x80005BBC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80005BC0: lbu         $t6, 0xD0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BC4: nop

    // 0x80005BC8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80005BCC: b           L_80005BD8
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
        goto L_80005BD8;
    // 0x80005BD0: sb          $t8, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = ctx->r24;
L_80005BD4:
    // 0x80005BD4: sb          $zero, 0xD0($a3)
    MEM_B(0XD0, ctx->r7) = 0;
L_80005BD8:
    // 0x80005BD8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005BDC: nop

    // 0x80005BE0: lbu         $t9, 0xD0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XD0);
    // 0x80005BE4: nop

    // 0x80005BE8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80005BEC: bne         $at, $zero, L_80005C0C
    if (ctx->r1 != 0) {
        // 0x80005BF0: nop
    
            goto L_80005C0C;
    }
    // 0x80005BF0: nop

    // 0x80005BF4: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005BF8: jal         0x800049F8
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80005BFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80005C00: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C04: b           L_80005C48
    // 0x80005C08: nop

        goto L_80005C48;
    // 0x80005C08: nop

L_80005C0C:
    // 0x80005C0C: lhu         $a2, 0xAC($a3)
    ctx->r6 = MEM_HU(ctx->r7, 0XAC);
    // 0x80005C10: lw          $a0, 0xA8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XA8);
    // 0x80005C14: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80005C18: jal         0x800049F8
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80005C1C: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_6:
    // 0x80005C20: lw          $t7, 0xA0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA0);
    // 0x80005C24: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80005C28: lw          $a1, 0xC($t7)
    ctx->r5 = MEM_W(ctx->r15, 0XC);
    // 0x80005C2C: lw          $a2, 0x10($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X10);
    // 0x80005C30: lw          $a3, 0x14($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X14);
    // 0x80005C34: lw          $a0, 0xA8($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XA8);
    // 0x80005C38: jal         0x80009B7C
    // 0x80005C3C: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_7;
    // 0x80005C3C: nop

    after_7:
    // 0x80005C40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C44: nop

L_80005C48:
    // 0x80005C48: beq         $s2, $zero, L_80005CE0
    if (ctx->r18 == 0) {
        // 0x80005C4C: sb          $s0, 0xA0($a3)
        MEM_B(0XA0, ctx->r7) = ctx->r16;
            goto L_80005CE0;
    }
    // 0x80005C4C: sb          $s0, 0xA0($a3)
    MEM_B(0XA0, ctx->r7) = ctx->r16;
    // 0x80005C50: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x80005C54: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80005C58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C5C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C60: lwc1        $f4, 0x54($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X54);
    // 0x80005C64: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80005C68: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80005C6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005C70: nop

    // 0x80005C74: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005C78: beq         $t9, $zero, L_80005CC4
    if (ctx->r25 == 0) {
        // 0x80005C7C: nop
    
            goto L_80005CC4;
    }
    // 0x80005C7C: nop

    // 0x80005C80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80005C84: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80005C88: sub.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80005C8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80005C90: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80005C94: nop

    // 0x80005C98: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80005C9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80005CA0: nop

    // 0x80005CA4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80005CA8: bne         $t9, $zero, L_80005CBC
    if (ctx->r25 != 0) {
        // 0x80005CAC: nop
    
            goto L_80005CBC;
    }
    // 0x80005CAC: nop

    // 0x80005CB0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CB4: b           L_80005CD4
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80005CD4;
    // 0x80005CB8: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80005CBC:
    // 0x80005CBC: b           L_80005CD4
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80005CD4;
    // 0x80005CC0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_80005CC4:
    // 0x80005CC4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80005CC8: nop

    // 0x80005CCC: bltz        $t9, L_80005CBC
    if (SIGNED(ctx->r25) < 0) {
        // 0x80005CD0: nop
    
            goto L_80005CBC;
    }
    // 0x80005CD0: nop

L_80005CD4:
    // 0x80005CD4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80005CD8: sb          $t9, 0x98($a3)
    MEM_B(0X98, ctx->r7) = ctx->r25;
    // 0x80005CDC: nop

L_80005CE0:
    // 0x80005CE0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80005CE4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80005CE8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005CEC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80005CF0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005CF4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80005CF8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80005CFC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80005D00: jr          $ra
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x80005D04: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void delete_point_particle_from_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2B9C: lw          $v0, 0x70($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X70);
    // 0x800B2BA0: nop

    // 0x800B2BA4: beq         $v0, $zero, L_800B2C38
    if (ctx->r2 == 0) {
        // 0x800B2BA8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BA8: nop

    // 0x800B2BAC: lbu         $v1, 0x6($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2BB0: nop

    // 0x800B2BB4: beq         $v1, $zero, L_800B2C38
    if (ctx->r3 == 0) {
        // 0x800B2BB8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BB8: nop

    // 0x800B2BBC: lbu         $t7, 0x74($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2BC0: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x800B2BC4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B2BC8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800B2BCC: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x800B2BD0: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800B2BD4: bne         $a0, $t0, L_800B2C38
    if (ctx->r4 != ctx->r8) {
        // 0x800B2BD8: nop
    
            goto L_800B2C38;
    }
    // 0x800B2BD8: nop

    // 0x800B2BDC: sb          $t1, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r9;
    // 0x800B2BE0: lbu         $a1, 0x74($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X74);
    // 0x800B2BE4: andi        $t2, $t1, 0xFF
    ctx->r10 = ctx->r9 & 0XFF;
    // 0x800B2BE8: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2BEC: beq         $at, $zero, L_800B2C38
    if (ctx->r1 == 0) {
        // 0x800B2BF0: sll         $v1, $a1, 2
        ctx->r3 = S32(ctx->r5 << 2);
            goto L_800B2C38;
    }
    // 0x800B2BF0: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_800B2BF4:
    // 0x800B2BF4: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800B2BF8: nop

    // 0x800B2BFC: addu        $a2, $t3, $v1
    ctx->r6 = ADD32(ctx->r11, ctx->r3);
    // 0x800B2C00: lw          $t4, 0x4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4);
    // 0x800B2C04: nop

    // 0x800B2C08: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B2C0C: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x800B2C10: nop

    // 0x800B2C14: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800B2C18: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800B2C1C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B2C20: sb          $a1, 0x74($a0)
    MEM_B(0X74, ctx->r4) = ctx->r5;
    // 0x800B2C24: lbu         $t6, 0x6($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2C28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B2C2C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B2C30: bne         $at, $zero, L_800B2BF4
    if (ctx->r1 != 0) {
        // 0x800B2C34: nop
    
            goto L_800B2BF4;
    }
    // 0x800B2C34: nop

L_800B2C38:
    // 0x800B2C38: jr          $ra
    // 0x800B2C3C: nop

    return;
    // 0x800B2C3C: nop

;}
RECOMP_FUNC void audspat_calculate_echo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009B7C: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80009B80: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x80009B84: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80009B88: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80009B8C: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80009B90: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80009B94: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x80009B98: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80009B9C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009BA0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80009BA4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80009BA8: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80009BAC: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80009BB0: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80009BB4: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80009BB8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80009BBC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80009BC0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80009BC4: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009BC8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009BCC: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009BD0: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x80009BD4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009BD8: jal         0x80029F58
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x80009BDC: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_0:
    // 0x80009BE0: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80009BE4: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x80009BE8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80009BEC: addiu       $s6, $zero, 0x190
    ctx->r22 = ADD32(0, 0X190);
    // 0x80009BF0: addiu       $s7, $s7, -0x53A8
    ctx->r23 = ADD32(ctx->r23, -0X53A8);
    // 0x80009BF4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80009BF8:
    // 0x80009BF8: lbu         $t6, 0x0($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X0);
    // 0x80009BFC: sw          $s7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r23;
    // 0x80009C00: beq         $t6, $zero, L_80009CF8
    if (ctx->r14 == 0) {
        // 0x80009C04: sw          $v1, 0xD4($sp)
        MEM_W(0XD4, ctx->r29) = ctx->r3;
            goto L_80009CF8;
    }
    // 0x80009C04: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    // 0x80009C08: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    // 0x80009C0C: jal         0x80009AB4
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    audspat_reverb_validate(rdram, ctx);
        goto after_1;
    // 0x80009C10: sw          $v1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r3;
    after_1:
    // 0x80009C14: beq         $v0, $zero, L_80009CFC
    if (ctx->r2 == 0) {
        // 0x80009C18: lw          $v1, 0xD4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XD4);
            goto L_80009CFC;
    }
    // 0x80009C18: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x80009C1C: lb          $t7, 0xB8($s7)
    ctx->r15 = MEM_B(ctx->r23, 0XB8);
    // 0x80009C20: addiu       $fp, $s7, 0x4
    ctx->r30 = ADD32(ctx->r23, 0X4);
    // 0x80009C24: blez        $t7, L_80009CF8
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80009C28: sw          $zero, 0xD0($sp)
        MEM_W(0XD0, ctx->r29) = 0;
            goto L_80009CF8;
    }
    // 0x80009C28: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_80009C2C:
    // 0x80009C2C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C30: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x80009C34: addiu       $t9, $sp, 0xC0
    ctx->r25 = ADD32(ctx->r29, 0XC0);
    // 0x80009C38: addiu       $t0, $sp, 0xBC
    ctx->r8 = ADD32(ctx->r29, 0XBC);
    // 0x80009C3C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80009C40: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80009C44: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80009C48: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    // 0x80009C4C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80009C50: jal         0x800092A8
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    audspat_distance_to_segment(rdram, ctx);
        goto after_2;
    // 0x80009C54: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_2:
    // 0x80009C58: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x80009C5C: beq         $at, $zero, L_80009CD4
    if (ctx->r1 == 0) {
        // 0x80009C60: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80009CD4;
    }
    // 0x80009C60: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80009C64: lw          $a0, 0xB0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB0);
    // 0x80009C68: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x80009C6C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80009C70: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x80009C74: jal         0x8002BAF0
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    collision_get_y(rdram, ctx);
        goto after_3;
    // 0x80009C78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    after_3:
    // 0x80009C7C: blez        $v0, L_80009CD4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80009C80: addiu       $s0, $sp, 0x7C
        ctx->r16 = ADD32(ctx->r29, 0X7C);
            goto L_80009CD4;
    }
    // 0x80009C80: addiu       $s0, $sp, 0x7C
    ctx->r16 = ADD32(ctx->r29, 0X7C);
    // 0x80009C84: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80009C88: addu        $s4, $t2, $s0
    ctx->r20 = ADD32(ctx->r10, ctx->r16);
L_80009C8C:
    // 0x80009C8C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009C90: lw          $a1, 0xC4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC4);
    // 0x80009C94: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009C98: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80009C9C: bc1f        L_80009CC4
    if (!c1cs) {
        // 0x80009CA0: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80009CC4;
    }
    // 0x80009CA0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80009CA4: lw          $a3, 0xBC($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XBC);
    // 0x80009CA8: or          $s6, $s3, $zero
    ctx->r22 = ctx->r19 | 0;
    // 0x80009CAC: jal         0x80009D6C
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    audspat_reverb_get_strength_at_point(rdram, ctx);
        goto after_4;
    // 0x80009CB0: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    after_4:
    // 0x80009CB4: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80009CB8: beq         $at, $zero, L_80009CC4
    if (ctx->r1 == 0) {
        // 0x80009CBC: nop
    
            goto L_80009CC4;
    }
    // 0x80009CBC: nop

    // 0x80009CC0: andi        $s5, $v0, 0xFF
    ctx->r21 = ctx->r2 & 0XFF;
L_80009CC4:
    // 0x80009CC4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80009CC8: sltu        $at, $s0, $s4
    ctx->r1 = ctx->r16 < ctx->r20 ? 1 : 0;
    // 0x80009CCC: bne         $at, $zero, L_80009C8C
    if (ctx->r1 != 0) {
        // 0x80009CD0: nop
    
            goto L_80009C8C;
    }
    // 0x80009CD0: nop

L_80009CD4:
    // 0x80009CD4: lw          $v0, 0xD0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD0);
    // 0x80009CD8: lw          $t3, 0xCC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XCC);
    // 0x80009CDC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80009CE0: sw          $v0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r2;
    // 0x80009CE4: lb          $t4, 0xB8($t3)
    ctx->r12 = MEM_B(ctx->r11, 0XB8);
    // 0x80009CE8: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
    // 0x80009CEC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80009CF0: bne         $at, $zero, L_80009C2C
    if (ctx->r1 != 0) {
        // 0x80009CF4: nop
    
            goto L_80009C2C;
    }
    // 0x80009CF4: nop

L_80009CF8:
    // 0x80009CF8: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
L_80009CFC:
    // 0x80009CFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80009D00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80009D04: bne         $v1, $at, L_80009BF8
    if (ctx->r3 != ctx->r1) {
        // 0x80009D08: addiu       $s7, $s7, 0xC0
        ctx->r23 = ADD32(ctx->r23, 0XC0);
            goto L_80009BF8;
    }
    // 0x80009D08: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x80009D0C: lw          $a0, 0xD8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XD8);
    // 0x80009D10: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x80009D14: beq         $a0, $zero, L_80009D28
    if (ctx->r4 == 0) {
        // 0x80009D18: lw          $ra, 0x64($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X64);
            goto L_80009D28;
    }
    // 0x80009D18: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80009D1C: jal         0x800049F8
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80009D20: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80009D24: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80009D28:
    // 0x80009D28: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80009D2C: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80009D30: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80009D34: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80009D38: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80009D3C: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80009D40: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80009D44: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80009D48: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80009D4C: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80009D50: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80009D54: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x80009D58: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80009D5C: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80009D60: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80009D64: jr          $ra
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80009D68: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void music_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001AEC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001AF0: lbu         $v0, -0x3458($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3458);
    // 0x80001AF4: jr          $ra
    // 0x80001AF8: nop

    return;
    // 0x80001AF8: nop

;}
RECOMP_FUNC void init_title_screen_variables(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800833FC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083400: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x80083404: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80083408: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008340C: lw          $t6, 0x69E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69E8);
    // 0x80083410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083414: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80083418: andi        $t9, $t7, 0x2
    ctx->r25 = ctx->r15 & 0X2;
    // 0x8008341C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80083420: beq         $t9, $zero, L_8008344C
    if (ctx->r25 == 0) {
        // 0x80083424: lw          $t3, 0x1C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X1C);
            goto L_8008344C;
    }
    // 0x80083424: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80083428: jal         0x8009C824
    // 0x8008342C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_magic_code_flags(rdram, ctx);
        goto after_0;
    // 0x8008342C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80083430: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80083434: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80083438: lw          $t1, 0x69EC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X69EC);
    // 0x8008343C: lw          $t0, 0x69E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X69E8);
    // 0x80083440: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80083444: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80083448: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_8008344C:
    // 0x8008344C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x80083450: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083454: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x80083458: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8008345C: ori         $at, $at, 0xFFF0
    ctx->r1 = ctx->r1 | 0XFFF0;
    // 0x80083460: bne         $t5, $at, L_8008348C
    if (ctx->r13 != ctx->r1) {
        // 0x80083464: lw          $t9, 0x1C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X1C);
            goto L_8008348C;
    }
    // 0x80083464: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80083468: jal         0x8009C824
    // 0x8008346C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_magic_code_flags(rdram, ctx);
        goto after_1;
    // 0x8008346C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80083470: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80083474: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80083478: lw          $t7, 0x69EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69EC);
    // 0x8008347C: lw          $t6, 0x69E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X69E8);
    // 0x80083480: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80083484: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80083488: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
L_8008348C:
    // 0x8008348C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80083490: andi        $t1, $t9, 0x1
    ctx->r9 = ctx->r25 & 0X1;
    // 0x80083494: beq         $t1, $zero, L_800834A8
    if (ctx->r9 == 0) {
        // 0x80083498: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800834A8;
    }
    // 0x80083498: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008349C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800834A0: b           L_800834AC
    // 0x800834A4: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
        goto L_800834AC;
    // 0x800834A4: sw          $t2, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = ctx->r10;
L_800834A8:
    // 0x800834A8: sw          $zero, -0x5EC($at)
    MEM_W(-0X5EC, ctx->r1) = 0;
L_800834AC:
    // 0x800834AC: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x800834B0: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800834B4: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800834B8: bne         $t7, $zero, L_800834C8
    if (ctx->r15 != 0) {
        // 0x800834BC: nop
    
            goto L_800834C8;
    }
    // 0x800834BC: nop

    // 0x800834C0: jal         0x800C3014
    // 0x800834C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_subtitles(rdram, ctx);
        goto after_2;
    // 0x800834C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
L_800834C8:
    // 0x800834C8: jal         0x8009F064
    // 0x800834CC: nop

    get_language(rdram, ctx);
        goto after_3;
    // 0x800834CC: nop

    after_3:
    // 0x800834D0: jal         0x8007FD50
    // 0x800834D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_4;
    // 0x800834D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800834D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800834DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800834E0: jr          $ra
    // 0x800834E4: nop

    return;
    // 0x800834E4: nop

;}
RECOMP_FUNC void func_800210CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021100: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80021104: addiu       $v1, $v1, -0x4D43
    ctx->r3 = ADD32(ctx->r3, -0X4D43);
    // 0x80021108: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8002110C: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x80021110: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x80021114: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80021118: bne         $at, $zero, L_8002112C
    if (ctx->r1 != 0) {
        // 0x8002111C: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_8002112C;
    }
    // 0x8002111C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80021120: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x80021124: jr          $ra
    // 0x80021128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80021128: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8002112C:
    // 0x8002112C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80021130: jr          $ra
    // 0x80021134: nop

    return;
    // 0x80021134: nop

;}
RECOMP_FUNC void bgdraw_fillcolour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077FAC: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80077FB0: sll         $t8, $a1, 3
    ctx->r24 = S32(ctx->r5 << 3);
    // 0x80077FB4: andi        $t9, $t8, 0x7C0
    ctx->r25 = ctx->r24 & 0X7C0;
    // 0x80077FB8: andi        $t7, $t6, 0xF800
    ctx->r15 = ctx->r14 & 0XF800;
    // 0x80077FBC: sra         $t1, $a2, 2
    ctx->r9 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80077FC0: andi        $t2, $t1, 0x3E
    ctx->r10 = ctx->r9 & 0X3E;
    // 0x80077FC4: or          $t0, $t7, $t9
    ctx->r8 = ctx->r15 | ctx->r25;
    // 0x80077FC8: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80077FCC: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80077FD0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80077FD4: addiu       $v1, $v1, -0x15C4
    ctx->r3 = ADD32(ctx->r3, -0X15C4);
    // 0x80077FD8: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80077FDC: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80077FE0: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80077FE4: jr          $ra
    // 0x80077FE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    return;
    // 0x80077FE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
;}
RECOMP_FUNC void reset_character_id_slots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C698: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009C69C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C6A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009C6A4: sw          $t6, -0x5B8($at)
    MEM_W(-0X5B8, ctx->r1) = ctx->r14;
    // 0x8009C6A8: addiu       $v1, $v1, 0x6990
    ctx->r3 = ADD32(ctx->r3, 0X6990);
    // 0x8009C6AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8009C6B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_8009C6B4:
    // 0x8009C6B4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8009C6B8: addiu       $t8, $v0, 0x2
    ctx->r24 = ADD32(ctx->r2, 0X2);
    // 0x8009C6BC: addiu       $t9, $v0, 0x3
    ctx->r25 = ADD32(ctx->r2, 0X3);
    // 0x8009C6C0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8009C6C4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009C6C8: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8009C6CC: sb          $t8, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r24;
    // 0x8009C6D0: sb          $t7, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r15;
    // 0x8009C6D4: bne         $v0, $a0, L_8009C6B4
    if (ctx->r2 != ctx->r4) {
        // 0x8009C6D8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8009C6B4;
    }
    // 0x8009C6D8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8009C6DC: jr          $ra
    // 0x8009C6E0: nop

    return;
    // 0x8009C6E0: nop

;}
RECOMP_FUNC void get_ghost_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074D74: addiu       $v1, $zero, 0x1100
    ctx->r3 = ADD32(0, 0X1100);
    // 0x80074D78: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80074D7C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80074D80: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80074D84: jr          $ra
    // 0x80074D88: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    return;
    // 0x80074D88: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
;}
RECOMP_FUNC void menu_magic_codes_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A174: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8008A178: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A17C: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
    // 0x8008A180: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8008A184: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A188: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8008A18C: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x8008A190: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8008A194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008A198: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x8008A19C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8008A1A0: beq         $v0, $zero, L_8008A1B8
    if (ctx->r2 == 0) {
        // 0x8008A1A4: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_8008A1B8;
    }
    // 0x8008A1A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8008A1A8: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x8008A1AC: bgez        $t6, L_8008A1B8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008A1B0: sw          $t6, 0x0($t3)
        MEM_W(0X0, ctx->r11) = ctx->r14;
            goto L_8008A1B8;
    }
    // 0x8008A1B0: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8008A1B4: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
L_8008A1B8:
    // 0x8008A1B8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1BC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A1C0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A1C4: beq         $v0, $zero, L_8008A204
    if (ctx->r2 == 0) {
        // 0x8008A1C8: addiu       $v1, $v1, 0x695C
        ctx->r3 = ADD32(ctx->r3, 0X695C);
            goto L_8008A204;
    }
    // 0x8008A1C8: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x8008A1CC: blez        $v0, L_8008A1F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A1D0: subu        $t9, $v0, $a0
        ctx->r25 = SUB32(ctx->r2, ctx->r4);
            goto L_8008A1F0;
    }
    // 0x8008A1D0: subu        $t9, $v0, $a0
    ctx->r25 = SUB32(ctx->r2, ctx->r4);
    // 0x8008A1D4: addu        $t8, $v0, $a0
    ctx->r24 = ADD32(ctx->r2, ctx->r4);
    // 0x8008A1D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A1DC: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    // 0x8008A1E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1E4: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A1E8: b           L_8008A208
    // 0x8008A1EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
        goto L_8008A208;
    // 0x8008A1EC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8008A1F0:
    // 0x8008A1F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A1F4: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x8008A1F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A1FC: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A200: nop

L_8008A204:
    // 0x8008A204: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_8008A208:
    // 0x8008A208: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8008A20C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8008A210: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8008A214: bne         $at, $zero, L_8008A23C
    if (ctx->r1 != 0) {
        // 0x8008A218: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8008A23C;
    }
    // 0x8008A218: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8008A21C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8008A220: beq         $at, $zero, L_8008A23C
    if (ctx->r1 == 0) {
        // 0x8008A224: nop
    
            goto L_8008A23C;
    }
    // 0x8008A224: nop

    // 0x8008A228: jal         0x80089B40
    // 0x8008A22C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    cheatmenu_render(rdram, ctx);
        goto after_0;
    // 0x8008A22C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x8008A230: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A234: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A238: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
L_8008A23C:
    // 0x8008A23C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008A240: lw          $t9, 0x6964($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6964);
    // 0x8008A244: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8008A248: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8008A24C: bne         $t9, $zero, L_8008A2E4
    if (ctx->r25 != 0) {
        // 0x8008A250: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8008A2E4;
    }
    // 0x8008A250: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8008A254: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A258: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008A25C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008A260: bne         $t6, $zero, L_8008A2E4
    if (ctx->r14 != 0) {
        // 0x8008A264: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8008A2E4;
    }
    // 0x8008A264: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008A268: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A26C: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x8008A270: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
L_8008A274:
    // 0x8008A274: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008A278: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8008A27C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8008A280: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x8008A284: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8008A288: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x8008A28C: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8008A290: jal         0x8006A794
    // 0x8008A294: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8008A294: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    after_1:
    // 0x8008A298: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8008A29C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8008A2A0: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8008A2A4: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8008A2A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8008A2AC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8008A2B0: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8008A2B4: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8008A2B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008A2BC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A2C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008A2C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008A2C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008A2CC: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
    // 0x8008A2D0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x8008A2D4: bne         $a2, $at, L_8008A274
    if (ctx->r6 != ctx->r1) {
        // 0x8008A2D8: addu        $t1, $t1, $t8
        ctx->r9 = ADD32(ctx->r9, ctx->r24);
            goto L_8008A274;
    }
    // 0x8008A2D8: addu        $t1, $t1, $t8
    ctx->r9 = ADD32(ctx->r9, ctx->r24);
    // 0x8008A2DC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008A2E0: addiu       $t3, $t3, 0x6978
    ctx->r11 = ADD32(ctx->r11, 0X6978);
L_8008A2E4:
    // 0x8008A2E4: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008A2E8: addiu       $ra, $ra, 0x7206
    ctx->r31 = ADD32(ctx->r31, 0X7206);
    // 0x8008A2EC: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A2F0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008A2F4: bne         $v0, $at, L_8008A31C
    if (ctx->r2 != ctx->r1) {
        // 0x8008A2F8: addiu       $t4, $zero, 0x5
        ctx->r12 = ADD32(0, 0X5);
            goto L_8008A31C;
    }
    // 0x8008A2F8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8008A2FC: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8008A300: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x8008A304: beq         $t9, $zero, L_8008A314
    if (ctx->r25 == 0) {
        // 0x8008A308: nop
    
            goto L_8008A314;
    }
    // 0x8008A308: nop

    // 0x8008A30C: beq         $t6, $zero, L_8008A878
    if (ctx->r14 == 0) {
        // 0x8008A310: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A310: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A314:
    // 0x8008A314: b           L_8008A874
    // 0x8008A318: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
        goto L_8008A874;
    // 0x8008A318: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A31C:
    // 0x8008A31C: bne         $t4, $v0, L_8008A668
    if (ctx->r12 != ctx->r2) {
        // 0x8008A320: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_8008A668;
    }
    // 0x8008A320: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8008A324: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008A328: addiu       $v0, $v0, 0x7202
    ctx->r2 = ADD32(ctx->r2, 0X7202);
    // 0x8008A32C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A330: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A334: addiu       $a1, $a1, 0x7200
    ctx->r5 = ADD32(ctx->r5, 0X7200);
    // 0x8008A338: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A33C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8008A340: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8008A344: bgez        $t0, L_8008A370
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8008A348: or          $a2, $t8, $a0
        ctx->r6 = ctx->r24 | ctx->r4;
            goto L_8008A370;
    }
    // 0x8008A348: or          $a2, $t8, $a0
    ctx->r6 = ctx->r24 | ctx->r4;
    // 0x8008A34C: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    // 0x8008A350: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8008A354: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A358: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8008A35C: bgez        $v1, L_8008A370
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008A360: nop
    
            goto L_8008A370;
    }
    // 0x8008A360: nop

    // 0x8008A364: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x8008A368: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A36C: nop

L_8008A370:
    // 0x8008A370: blez        $t0, L_8008A39C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8008A374: addiu       $t7, $v1, 0x1
        ctx->r15 = ADD32(ctx->r3, 0X1);
            goto L_8008A39C;
    }
    // 0x8008A374: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x8008A378: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8008A37C: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A380: nop

    // 0x8008A384: slti        $at, $v1, 0x7
    ctx->r1 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8008A388: bne         $at, $zero, L_8008A39C
    if (ctx->r1 != 0) {
        // 0x8008A38C: nop
    
            goto L_8008A39C;
    }
    // 0x8008A38C: nop

    // 0x8008A390: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008A394: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8008A398: nop

L_8008A39C:
    // 0x8008A39C: andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // 0x8008A3A0: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x8008A3A4: bgez        $t1, L_8008A3D4
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A3A8: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_8008A3D4;
    }
    // 0x8008A3A8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8008A3AC: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8008A3B0: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x8008A3B4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3B8: nop

    // 0x8008A3BC: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8008A3C0: bne         $at, $zero, L_8008A3D4
    if (ctx->r1 != 0) {
        // 0x8008A3C4: nop
    
            goto L_8008A3D4;
    }
    // 0x8008A3C4: nop

    // 0x8008A3C8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8008A3CC: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3D0: nop

L_8008A3D4:
    // 0x8008A3D4: blez        $t1, L_8008A400
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A3D8: andi        $t9, $t2, 0x8000
        ctx->r25 = ctx->r10 & 0X8000;
            goto L_8008A400;
    }
    // 0x8008A3D8: andi        $t9, $t2, 0x8000
    ctx->r25 = ctx->r10 & 0X8000;
    // 0x8008A3DC: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8008A3E0: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8008A3E4: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3E8: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A3EC: bgez        $a0, L_8008A404
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8008A3F0: or          $t7, $v0, $a0
        ctx->r15 = ctx->r2 | ctx->r4;
            goto L_8008A404;
    }
    // 0x8008A3F0: or          $t7, $v0, $a0
    ctx->r15 = ctx->r2 | ctx->r4;
    // 0x8008A3F4: sh          $t5, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r13;
    // 0x8008A3F8: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8008A3FC: nop

L_8008A400:
    // 0x8008A400: or          $t7, $v0, $a0
    ctx->r15 = ctx->r2 | ctx->r4;
L_8008A404:
    // 0x8008A404: beq         $a2, $t7, L_8008A414
    if (ctx->r6 == ctx->r15) {
        // 0x8008A408: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A414;
    }
    // 0x8008A408: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A40C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A410: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8008A414:
    // 0x8008A414: beq         $t9, $zero, L_8008A49C
    if (ctx->r25 == 0) {
        // 0x8008A418: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8008A49C;
    }
    // 0x8008A418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008A41C: bne         $t5, $a0, L_8008A434
    if (ctx->r13 != ctx->r4) {
        // 0x8008A420: nop
    
            goto L_8008A434;
    }
    // 0x8008A420: nop

    // 0x8008A424: bne         $t4, $v1, L_8008A434
    if (ctx->r12 != ctx->r3) {
        // 0x8008A428: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A434;
    }
    // 0x8008A428: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A42C: b           L_8008A49C
    // 0x8008A430: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
        goto L_8008A49C;
    // 0x8008A430: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
L_8008A434:
    // 0x8008A434: bne         $t5, $a0, L_8008A44C
    if (ctx->r13 != ctx->r4) {
        // 0x8008A438: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8008A44C;
    }
    // 0x8008A438: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8008A43C: bne         $v1, $at, L_8008A44C
    if (ctx->r3 != ctx->r1) {
        // 0x8008A440: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008A44C;
    }
    // 0x8008A440: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A444: b           L_8008A49C
    // 0x8008A448: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
        goto L_8008A49C;
    // 0x8008A448: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
L_8008A44C:
    // 0x8008A44C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A450: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A454: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8008A458: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A45C: slti        $at, $v0, 0x13
    ctx->r1 = SIGNED(ctx->r2) < 0X13 ? 1 : 0;
    // 0x8008A460: beq         $at, $zero, L_8008A49C
    if (ctx->r1 == 0) {
        // 0x8008A464: sll         $t9, $a0, 3
        ctx->r25 = S32(ctx->r4 << 3);
            goto L_8008A49C;
    }
    // 0x8008A464: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8008A468: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x8008A46C: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8008A470: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A474: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8008A478: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8008A47C: addiu       $t7, $t6, 0x41
    ctx->r15 = ADD32(ctx->r14, 0X41);
    // 0x8008A480: sb          $t7, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = ctx->r15;
    // 0x8008A484: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8008A488: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8008A48C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8008A490: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A494: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008A498: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
L_8008A49C:
    // 0x8008A49C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A4A0: andi        $t6, $t2, 0x4000
    ctx->r14 = ctx->r10 & 0X4000;
    // 0x8008A4A4: beq         $t6, $zero, L_8008A4C8
    if (ctx->r14 == 0) {
        // 0x8008A4A8: addiu       $a2, $a2, 0x7204
        ctx->r6 = ADD32(ctx->r6, 0X7204);
            goto L_8008A4C8;
    }
    // 0x8008A4A8: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A4AC: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x8008A4B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A4B4: blez        $t7, L_8008A4C4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8008A4B8: nop
    
            goto L_8008A4C4;
    }
    // 0x8008A4B8: nop

    // 0x8008A4BC: b           L_8008A4C8
    // 0x8008A4C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
        goto L_8008A4C8;
    // 0x8008A4C0: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
L_8008A4C4:
    // 0x8008A4C4: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A4C8:
    // 0x8008A4C8: andi        $t9, $t2, 0x1000
    ctx->r25 = ctx->r10 & 0X1000;
    // 0x8008A4CC: beq         $t9, $zero, L_8008A4D8
    if (ctx->r25 == 0) {
        // 0x8008A4D0: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A4D8;
    }
    // 0x8008A4D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A4D4: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
L_8008A4D8:
    // 0x8008A4D8: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x8008A4DC: addiu       $a0, $zero, 0xAE
    ctx->r4 = ADD32(0, 0XAE);
    // 0x8008A4E0: beq         $t7, $zero, L_8008A52C
    if (ctx->r15 == 0) {
        // 0x8008A4E4: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_8008A52C;
    }
    // 0x8008A4E4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008A4E8: jal         0x80001D04
    // 0x8008A4EC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8008A4EC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_2:
    // 0x8008A4F0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A4F4: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A4F8: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x8008A4FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8008A500: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008A504: addiu       $ra, $ra, 0x7206
    ctx->r31 = ADD32(ctx->r31, 0X7206);
    // 0x8008A508: blez        $v0, L_8008A528
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008A50C: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A528;
    }
    // 0x8008A50C: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A510: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8008A514: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
    // 0x8008A518: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x8008A51C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A520: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8008A524: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
L_8008A528:
    // 0x8008A528: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_8008A52C:
    // 0x8008A52C: nop

    // 0x8008A530: beq         $t6, $zero, L_8008A878
    if (ctx->r14 == 0) {
        // 0x8008A534: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A534: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A538: lh          $t8, 0x0($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X0);
    // 0x8008A53C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A540: bne         $t8, $zero, L_8008A550
    if (ctx->r24 != 0) {
        // 0x8008A544: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_8008A550;
    }
    // 0x8008A544: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8008A548: b           L_8008A874
    // 0x8008A54C: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
        goto L_8008A874;
    // 0x8008A54C: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
L_8008A550:
    // 0x8008A550: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008A554: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008A558: lw          $t1, 0x71F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X71F0);
    // 0x8008A55C: addiu       $t4, $t4, 0x720C
    ctx->r12 = ADD32(ctx->r12, 0X720C);
    // 0x8008A560: sh          $zero, 0x0($t4)
    MEM_H(0X0, ctx->r12) = 0;
    // 0x8008A564: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008A568: lw          $t2, 0x71F8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X71F8);
    // 0x8008A56C: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8008A570: addiu       $t3, $t1, 0x2
    ctx->r11 = ADD32(ctx->r9, 0X2);
    // 0x8008A574: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008A578: beq         $at, $zero, L_8008A604
    if (ctx->r1 == 0) {
        // 0x8008A57C: nop
    
            goto L_8008A604;
    }
    // 0x8008A57C: nop

L_8008A580:
    // 0x8008A580: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A584: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A588: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8008A58C: addiu       $a1, $a1, 0x7217
    ctx->r5 = ADD32(ctx->r5, 0X7217);
    // 0x8008A590: mflo        $t9
    ctx->r25 = lo;
    // 0x8008A594: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8008A598: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8008A59C: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8008A5A0: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8008A5A4: addu        $v0, $t8, $t1
    ctx->r2 = ADD32(ctx->r24, ctx->r9);
    // 0x8008A5A8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
L_8008A5AC:
    // 0x8008A5AC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8008A5B0: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8008A5B4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008A5B8: beq         $v0, $v1, L_8008A5C4
    if (ctx->r2 == ctx->r3) {
        // 0x8008A5BC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_8008A5C4;
    }
    // 0x8008A5BC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008A5C0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008A5C4:
    // 0x8008A5C4: beq         $a3, $zero, L_8008A5DC
    if (ctx->r7 == 0) {
        // 0x8008A5C8: nop
    
            goto L_8008A5DC;
    }
    // 0x8008A5C8: nop

    // 0x8008A5CC: beq         $v0, $zero, L_8008A5DC
    if (ctx->r2 == 0) {
        // 0x8008A5D0: nop
    
            goto L_8008A5DC;
    }
    // 0x8008A5D0: nop

    // 0x8008A5D4: bne         $v1, $zero, L_8008A5AC
    if (ctx->r3 != 0) {
        // 0x8008A5D8: nop
    
            goto L_8008A5AC;
    }
    // 0x8008A5D8: nop

L_8008A5DC:
    // 0x8008A5DC: bne         $a3, $zero, L_8008A5F4
    if (ctx->r7 != 0) {
        // 0x8008A5E0: slt         $at, $t0, $t2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_8008A5F4;
    }
    // 0x8008A5E0: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8008A5E4: sh          $t9, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r25;
    // 0x8008A5E8: lh          $t0, 0x0($t4)
    ctx->r8 = MEM_H(ctx->r12, 0X0);
    // 0x8008A5EC: nop

    // 0x8008A5F0: slt         $at, $t0, $t2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r10) ? 1 : 0;
L_8008A5F4:
    // 0x8008A5F4: beq         $at, $zero, L_8008A604
    if (ctx->r1 == 0) {
        // 0x8008A5F8: nop
    
            goto L_8008A604;
    }
    // 0x8008A5F8: nop

    // 0x8008A5FC: beq         $a3, $zero, L_8008A580
    if (ctx->r7 == 0) {
        // 0x8008A600: nop
    
            goto L_8008A580;
    }
    // 0x8008A600: nop

L_8008A604:
    // 0x8008A604: bne         $a3, $zero, L_8008A614
    if (ctx->r7 != 0) {
        // 0x8008A608: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_8008A614;
    }
    // 0x8008A608: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008A60C: b           L_8008A650
    // 0x8008A610: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
        goto L_8008A650;
    // 0x8008A610: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
L_8008A614:
    // 0x8008A614: multu       $t0, $t5
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008A618: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A61C: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8008A620: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A624: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A628: sllv        $v0, $t7, $t0
    ctx->r2 = S32(ctx->r15 << (ctx->r8 & 31));
    // 0x8008A62C: or          $t9, $t8, $v0
    ctx->r25 = ctx->r24 | ctx->r2;
    // 0x8008A630: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A634: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A638: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x8008A63C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A640: or          $t7, $t6, $v0
    ctx->r15 = ctx->r14 | ctx->r2;
    // 0x8008A644: mflo        $t8
    ctx->r24 = lo;
    // 0x8008A648: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
    // 0x8008A64C: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
L_8008A650:
    // 0x8008A650: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8008A654: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
    // 0x8008A658: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8008A65C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A660: b           L_8008A874
    // 0x8008A664: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
        goto L_8008A874;
    // 0x8008A664: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
L_8008A668:
    // 0x8008A668: bne         $a1, $v0, L_8008A690
    if (ctx->r5 != ctx->r2) {
        // 0x8008A66C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008A690;
    }
    // 0x8008A66C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008A670: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8008A674: andi        $t8, $t2, 0x9000
    ctx->r24 = ctx->r10 & 0X9000;
    // 0x8008A678: beq         $t7, $zero, L_8008A688
    if (ctx->r15 == 0) {
        // 0x8008A67C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A688;
    }
    // 0x8008A67C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A680: beq         $t8, $zero, L_8008A878
    if (ctx->r24 == 0) {
        // 0x8008A684: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A684: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A688:
    // 0x8008A688: b           L_8008A874
    // 0x8008A68C: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
        goto L_8008A874;
    // 0x8008A68C: sh          $t9, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r25;
L_8008A690:
    // 0x8008A690: addiu       $a0, $a0, 0x6980
    ctx->r4 = ADD32(ctx->r4, 0X6980);
    // 0x8008A694: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008A698: andi        $t6, $t2, 0x9000
    ctx->r14 = ctx->r10 & 0X9000;
    // 0x8008A69C: beq         $v1, $zero, L_8008A750
    if (ctx->r3 == 0) {
        // 0x8008A6A0: andi        $t9, $t2, 0x9000
        ctx->r25 = ctx->r10 & 0X9000;
            goto L_8008A750;
    }
    // 0x8008A6A0: andi        $t9, $t2, 0x9000
    ctx->r25 = ctx->r10 & 0X9000;
    // 0x8008A6A4: beq         $t6, $zero, L_8008A6FC
    if (ctx->r14 == 0) {
        // 0x8008A6A8: andi        $t8, $t2, 0x4000
        ctx->r24 = ctx->r10 & 0X4000;
            goto L_8008A6FC;
    }
    // 0x8008A6A8: andi        $t8, $t2, 0x4000
    ctx->r24 = ctx->r10 & 0X4000;
    // 0x8008A6AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A6B0: bne         $v1, $at, L_8008A6EC
    if (ctx->r3 != ctx->r1) {
        // 0x8008A6B4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8008A6EC;
    }
    // 0x8008A6B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A6B8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008A6BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A6C0: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8008A6C4: sw          $zero, 0x318($at)
    MEM_W(0X318, ctx->r1) = 0;
    // 0x8008A6C8: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008A6CC: sh          $a1, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r5;
    // 0x8008A6D0: andi        $t9, $t8, 0x3
    ctx->r25 = ctx->r24 & 0X3;
    // 0x8008A6D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008A6D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A6DC: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8008A6E0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8008A6E4: b           L_8008A6F4
    // 0x8008A6E8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
        goto L_8008A6F4;
    // 0x8008A6E8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
L_8008A6EC:
    // 0x8008A6EC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008A6F0: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
L_8008A6F4:
    // 0x8008A6F4: b           L_8008A874
    // 0x8008A6F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A874;
    // 0x8008A6F8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A6FC:
    // 0x8008A6FC: beq         $t8, $zero, L_8008A710
    if (ctx->r24 == 0) {
        // 0x8008A700: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A710;
    }
    // 0x8008A700: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A704: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x8008A708: b           L_8008A874
    // 0x8008A70C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_8008A874;
    // 0x8008A70C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_8008A710:
    // 0x8008A710: bgez        $t1, L_8008A730
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A714: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008A730;
    }
    // 0x8008A714: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A718: bne         $v1, $at, L_8008A730
    if (ctx->r3 != ctx->r1) {
        // 0x8008A71C: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A730;
    }
    // 0x8008A71C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A720: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8008A724: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8008A728: b           L_8008A874
    // 0x8008A72C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_8008A874;
    // 0x8008A72C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8008A730:
    // 0x8008A730: blez        $t1, L_8008A874
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A734: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8008A874;
    }
    // 0x8008A734: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A738: bne         $v1, $at, L_8008A874
    if (ctx->r3 != ctx->r1) {
        // 0x8008A73C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A874;
    }
    // 0x8008A73C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A740: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A744: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8008A748: b           L_8008A874
    // 0x8008A74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
        goto L_8008A874;
    // 0x8008A74C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8008A750:
    // 0x8008A750: bgez        $t1, L_8008A780
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8008A754: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8008A780;
    }
    // 0x8008A754: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8008A758: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8008A75C: sh          $t6, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r14;
    // 0x8008A760: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A764: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A768: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008A76C: bne         $at, $zero, L_8008A780
    if (ctx->r1 != 0) {
        // 0x8008A770: nop
    
            goto L_8008A780;
    }
    // 0x8008A770: nop

    // 0x8008A774: sh          $t5, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r13;
    // 0x8008A778: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A77C: nop

L_8008A780:
    // 0x8008A780: blez        $t1, L_8008A7AC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8008A784: addiu       $t5, $zero, 0x3
        ctx->r13 = ADD32(0, 0X3);
            goto L_8008A7AC;
    }
    // 0x8008A784: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8008A788: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8008A78C: sh          $t7, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r15;
    // 0x8008A790: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A794: nop

    // 0x8008A798: bgez        $v0, L_8008A7AC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8008A79C: nop
    
            goto L_8008A7AC;
    }
    // 0x8008A79C: nop

    // 0x8008A7A0: sh          $zero, 0x0($ra)
    MEM_H(0X0, ctx->r31) = 0;
    // 0x8008A7A4: lh          $v0, 0x0($ra)
    ctx->r2 = MEM_H(ctx->r31, 0X0);
    // 0x8008A7A8: nop

L_8008A7AC:
    // 0x8008A7AC: beq         $a2, $v0, L_8008A7B8
    if (ctx->r6 == ctx->r2) {
        // 0x8008A7B0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008A7B8;
    }
    // 0x8008A7B0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008A7B4: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_8008A7B8:
    // 0x8008A7B8: beq         $t9, $zero, L_8008A830
    if (ctx->r25 == 0) {
        // 0x8008A7BC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8008A830;
    }
    // 0x8008A7BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008A7C0: bne         $t5, $v0, L_8008A7D4
    if (ctx->r13 != ctx->r2) {
        // 0x8008A7C4: sw          $t6, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r14;
            goto L_8008A7D4;
    }
    // 0x8008A7C4: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x8008A7C8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A7CC: b           L_8008A830
    // 0x8008A7D0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
        goto L_8008A830;
    // 0x8008A7D0: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A7D4:
    // 0x8008A7D4: bne         $v0, $zero, L_8008A80C
    if (ctx->r2 != 0) {
        // 0x8008A7D8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8008A80C;
    }
    // 0x8008A7D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008A7DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008A7E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008A7E4: addiu       $a2, $a2, 0x7204
    ctx->r6 = ADD32(ctx->r6, 0X7204);
    // 0x8008A7E8: addiu       $v0, $v0, 0x7202
    ctx->r2 = ADD32(ctx->r2, 0X7202);
    // 0x8008A7EC: addiu       $a1, $a1, 0x7200
    ctx->r5 = ADD32(ctx->r5, 0X7200);
    // 0x8008A7F0: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x8008A7F4: sh          $zero, 0x0($v0)
    MEM_H(0X0, ctx->r2) = 0;
    // 0x8008A7F8: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8008A7FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A800: sb          $zero, 0x7218($at)
    MEM_B(0X7218, ctx->r1) = 0;
    // 0x8008A804: b           L_8008A830
    // 0x8008A808: sh          $t4, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r12;
        goto L_8008A830;
    // 0x8008A808: sh          $t4, 0x0($ra)
    MEM_H(0X0, ctx->r31) = ctx->r12;
L_8008A80C:
    // 0x8008A80C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008A810: bne         $v0, $at, L_8008A820
    if (ctx->r2 != ctx->r1) {
        // 0x8008A814: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_8008A820;
    }
    // 0x8008A814: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8008A818: b           L_8008A830
    // 0x8008A81C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_8008A830;
    // 0x8008A81C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_8008A820:
    // 0x8008A820: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008A824: bne         $v0, $at, L_8008A830
    if (ctx->r2 != ctx->r1) {
        // 0x8008A828: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008A830;
    }
    // 0x8008A828: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A82C: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_8008A830:
    // 0x8008A830: andi        $t6, $t2, 0x4000
    ctx->r14 = ctx->r10 & 0X4000;
    // 0x8008A834: beq         $t6, $zero, L_8008A840
    if (ctx->r14 == 0) {
        // 0x8008A838: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8008A840;
    }
    // 0x8008A838: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008A83C: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
L_8008A840:
    // 0x8008A840: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8008A844: nop

    // 0x8008A848: beq         $t8, $zero, L_8008A878
    if (ctx->r24 == 0) {
        // 0x8008A84C: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_8008A878;
    }
    // 0x8008A84C: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8008A850: bgez        $t8, L_8008A860
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8008A854: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008A860;
    }
    // 0x8008A854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A858: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A85C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
L_8008A860:
    // 0x8008A860: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8008A864: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A868: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    // 0x8008A86C: jal         0x800C06F8
    // 0x8008A870: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A870: sw          $t6, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r14;
    after_3:
L_8008A874:
    // 0x8008A874: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_8008A878:
    // 0x8008A878: nop

    // 0x8008A87C: beq         $t7, $zero, L_8008A894
    if (ctx->r15 == 0) {
        // 0x8008A880: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8008A894;
    }
    // 0x8008A880: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8008A884: jal         0x80001D04
    // 0x8008A888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8008A888: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8008A88C: b           L_8008A8C4
    // 0x8008A890: nop

        goto L_8008A8C4;
    // 0x8008A890: nop

L_8008A894:
    // 0x8008A894: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x8008A898: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8008A89C: beq         $t8, $zero, L_8008A8B4
    if (ctx->r24 == 0) {
        // 0x8008A8A0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8008A8B4;
    }
    // 0x8008A8A0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008A8A4: jal         0x80001D04
    // 0x8008A8A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8008A8A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8008A8AC: b           L_8008A8C4
    // 0x8008A8B0: nop

        goto L_8008A8C4;
    // 0x8008A8B0: nop

L_8008A8B4:
    // 0x8008A8B4: beq         $t9, $zero, L_8008A8C4
    if (ctx->r25 == 0) {
        // 0x8008A8B8: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8008A8C4;
    }
    // 0x8008A8B8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008A8BC: jal         0x80001D04
    // 0x8008A8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8008A8C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_8008A8C4:
    // 0x8008A8C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008A8C8: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008A8CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A8D0: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x8008A8D4: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x8008A8D8: bne         $at, $zero, L_8008A8E8
    if (ctx->r1 != 0) {
        // 0x8008A8DC: slti        $at, $v0, 0x1F
        ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
            goto L_8008A8E8;
    }
    // 0x8008A8DC: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8008A8E0: bne         $at, $zero, L_8008A96C
    if (ctx->r1 != 0) {
        // 0x8008A8E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008A96C;
    }
    // 0x8008A8E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A8E8:
    // 0x8008A8E8: jal         0x8008A978
    // 0x8008A8EC: nop

    cheatmenu_free(rdram, ctx);
        goto after_7;
    // 0x8008A8EC: nop

    after_7:
    // 0x8008A8F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A8F4: lw          $t6, -0x604($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X604);
    // 0x8008A8F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008A8FC: bgez        $t6, L_8008A960
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008A900: nop
    
            goto L_8008A960;
    }
    // 0x8008A900: nop

    // 0x8008A904: lw          $t7, 0x318($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X318);
    // 0x8008A908: nop

    // 0x8008A90C: andi        $t8, $t7, 0x400
    ctx->r24 = ctx->r15 & 0X400;
    // 0x8008A910: beq         $t8, $zero, L_8008A950
    if (ctx->r24 == 0) {
        // 0x8008A914: nop
    
            goto L_8008A950;
    }
    // 0x8008A914: nop

    // 0x8008A918: jal         0x80000B28
    // 0x8008A91C: nop

    music_change_on(rdram, ctx);
        goto after_8;
    // 0x8008A91C: nop

    after_8:
    // 0x8008A920: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008A924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A928: sw          $t9, 0x20CC($at)
    MEM_W(0X20CC, ctx->r1) = ctx->r25;
    // 0x8008A92C: jal         0x80081820
    // 0x8008A930: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    menu_init(rdram, ctx);
        goto after_9;
    // 0x8008A930: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_9:
    // 0x8008A934: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008A938: lw          $t6, 0x318($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X318);
    // 0x8008A93C: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x8008A940: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8008A944: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A948: b           L_8008A968
    // 0x8008A94C: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
        goto L_8008A968;
    // 0x8008A94C: sw          $t7, 0x318($at)
    MEM_W(0X318, ctx->r1) = ctx->r15;
L_8008A950:
    // 0x8008A950: jal         0x80081820
    // 0x8008A954: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_10;
    // 0x8008A954: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_10:
    // 0x8008A958: b           L_8008A96C
    // 0x8008A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008A96C;
    // 0x8008A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A960:
    // 0x8008A960: jal         0x80081820
    // 0x8008A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    menu_init(rdram, ctx);
        goto after_11;
    // 0x8008A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_11:
L_8008A968:
    // 0x8008A968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008A96C:
    // 0x8008A96C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8008A970: jr          $ra
    // 0x8008A974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8008A974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void weapon_trap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F328: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003F32C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003F330: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003F334: sw          $a1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r5;
    // 0x8003F338: lw          $t6, 0x64($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X64);
    // 0x8003F33C: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003F340: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8003F344: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8003F348: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8003F34C: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003F350: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8003F354: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8003F358: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003F35C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003F360: bne         $t3, $zero, L_8003F380
    if (ctx->r11 != 0) {
        // 0x8003F364: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_8003F380;
    }
    // 0x8003F364: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x8003F368: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F36C: lwc1        $f9, 0x6790($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6790);
    // 0x8003F370: lwc1        $f8, 0x6794($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6794);
    // 0x8003F374: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x8003F378: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003F37C: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8003F380:
    // 0x8003F380: addiu       $t0, $s0, 0x78
    ctx->r8 = ADD32(ctx->r16, 0X78);
    // 0x8003F384: lbu         $t4, 0x4($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F388: nop

    // 0x8003F38C: bne         $t4, $zero, L_8003F594
    if (ctx->r12 != 0) {
        // 0x8003F390: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F594;
    }
    // 0x8003F390: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F394: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003F398: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F39C: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8003F3A0: lui         $at, 0x4110
    ctx->r1 = S32(0X4110 << 16);
    // 0x8003F3A4: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8003F3A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003F3AC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8003F3B0: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x8003F3B4: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8003F3B8: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003F3BC: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F3C0: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003F3C4: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8003F3C8: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8003F3CC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003F3D0: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x8003F3D4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003F3D8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003F3DC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003F3E0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8003F3E4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F3E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8003F3EC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8003F3F0: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x8003F3F4: jal         0x80031170
    // 0x8003F3F8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    generate_collision_candidates(rdram, ctx);
        goto after_0;
    // 0x8003F3F8: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8003F3FC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8003F400: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8003F404: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F408: addiu       $t7, $sp, 0x4C
    ctx->r15 = ADD32(ctx->r29, 0X4C);
    // 0x8003F40C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x8003F410: sb          $t5, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r13;
    // 0x8003F414: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003F418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003F41C: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8003F420: addiu       $a2, $sp, 0x54
    ctx->r6 = ADD32(ctx->r29, 0X54);
    // 0x8003F424: jal         0x80031640
    // 0x8003F428: addiu       $a3, $sp, 0x47
    ctx->r7 = ADD32(ctx->r29, 0X47);
    resolve_collisions(rdram, ctx);
        goto after_1;
    // 0x8003F428: addiu       $a3, $sp, 0x47
    ctx->r7 = ADD32(ctx->r29, 0X47);
    after_1:
    // 0x8003F42C: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003F430: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F434: lwc1        $f0, 0x50($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8003F438: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x8003F43C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F440: div.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003F444: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F448: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8003F44C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F450: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x8003F454: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8003F458: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003F45C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003F460: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003F464: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003F468: sub.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x8003F46C: nop

    // 0x8003F470: div.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003F474: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8003F478: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003F47C: nop

    // 0x8003F480: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8003F484: nop

    // 0x8003F488: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003F48C: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8003F490: lwc1        $f16, 0x58($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8003F494: nop

    // 0x8003F498: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003F49C: lwc1        $f6, 0x5C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003F4A0: nop

    // 0x8003F4A4: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x8003F4A8: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8003F4AC: nop

    // 0x8003F4B0: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003F4B4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8003F4B8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003F4BC: bne         $t8, $zero, L_8003F4D4
    if (ctx->r24 != 0) {
        // 0x8003F4C0: nop
    
            goto L_8003F4D4;
    }
    // 0x8003F4C0: nop

    // 0x8003F4C4: lb          $t2, 0x1D6($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X1D6);
    // 0x8003F4C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F4CC: bne         $t2, $at, L_8003F51C
    if (ctx->r10 != ctx->r1) {
        // 0x8003F4D0: nop
    
            goto L_8003F51C;
    }
    // 0x8003F4D0: nop

L_8003F4D4:
    // 0x8003F4D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003F4D8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F4DC: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x8003F4E0: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x8003F4E4: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003F4E8: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x8003F4EC: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8003F4F0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003F4F4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F4F8: lbu         $t5, 0x18($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X18);
    // 0x8003F4FC: nop

    // 0x8003F500: bne         $t5, $at, L_8003F51C
    if (ctx->r13 != ctx->r1) {
        // 0x8003F504: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003F51C;
    }
    // 0x8003F504: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003F508: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F50C: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F510: nop

    // 0x8003F514: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003F518: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003F51C:
    // 0x8003F51C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F520: lwc1        $f4, 0x6798($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6798);
    // 0x8003F524: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F528: jal         0x8002B9FC
    // 0x8003F52C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    func_8002B9BC(rdram, ctx);
        goto after_2;
    // 0x8003F52C: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8003F530: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F534: beq         $v0, $zero, L_8003F594
    if (ctx->r2 == 0) {
        // 0x8003F538: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F594;
    }
    // 0x8003F538: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F53C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F540: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8003F544: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F548: c.lt.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl < ctx->f8.fl;
    // 0x8003F54C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003F550: bc1f        L_8003F594
    if (!c1cs) {
        // 0x8003F554: lw          $t2, 0x40($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X40);
            goto L_8003F594;
    }
    // 0x8003F554: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x8003F558: sb          $t6, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r14;
    // 0x8003F55C: sb          $t7, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r15;
    // 0x8003F560: sh          $zero, 0x6($t0)
    MEM_H(0X6, ctx->r8) = 0;
    // 0x8003F564: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8003F568: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F56C: lbu         $t9, 0x18($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X18);
    // 0x8003F570: nop

    // 0x8003F574: bne         $t9, $at, L_8003F590
    if (ctx->r25 != ctx->r1) {
        // 0x8003F578: lui         $at, 0x4180
        ctx->r1 = S32(0X4180 << 16);
            goto L_8003F590;
    }
    // 0x8003F578: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8003F57C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003F580: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F584: nop

    // 0x8003F588: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8003F58C: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
L_8003F590:
    // 0x8003F590: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
L_8003F594:
    // 0x8003F594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F598: lbu         $t3, 0x18($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X18);
    // 0x8003F59C: nop

    // 0x8003F5A0: bne         $t3, $at, L_8003F6A0
    if (ctx->r11 != ctx->r1) {
        // 0x8003F5A4: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F6A0;
    }
    // 0x8003F5A4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F5A8: lbu         $v0, 0x4($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F5AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F5B0: beq         $v0, $zero, L_8003F6A0
    if (ctx->r2 == 0) {
        // 0x8003F5B4: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F6A0;
    }
    // 0x8003F5B4: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F5B8: bne         $v0, $at, L_8003F5F0
    if (ctx->r2 != ctx->r1) {
        // 0x8003F5BC: nop
    
            goto L_8003F5F0;
    }
    // 0x8003F5BC: nop

    // 0x8003F5C0: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F5C4: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8003F5C8: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8003F5CC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8003F5D0: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
    // 0x8003F5D4: lh          $t7, 0x6($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X6);
    // 0x8003F5D8: nop

    // 0x8003F5DC: slti        $at, $t7, 0xD
    ctx->r1 = SIGNED(ctx->r15) < 0XD ? 1 : 0;
    // 0x8003F5E0: bne         $at, $zero, L_8003F62C
    if (ctx->r1 != 0) {
        // 0x8003F5E4: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_8003F62C;
    }
    // 0x8003F5E4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003F5E8: b           L_8003F628
    // 0x8003F5EC: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
        goto L_8003F628;
    // 0x8003F5EC: sh          $t8, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r24;
L_8003F5F0:
    // 0x8003F5F0: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F5F4: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003F5F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003F5FC: subu        $t3, $t9, $t2
    ctx->r11 = SUB32(ctx->r25, ctx->r10);
    // 0x8003F600: sh          $t3, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r11;
    // 0x8003F604: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F608: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F60C: bgtz        $t4, L_8003F62C
    if (SIGNED(ctx->r12) > 0) {
        // 0x8003F610: lw          $t6, 0x64($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X64);
            goto L_8003F62C;
    }
    // 0x8003F610: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003F614: sh          $t5, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r13;
    // 0x8003F618: jal         0x8000FFB8
    // 0x8003F61C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003F61C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_3:
    // 0x8003F620: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F624: nop

L_8003F628:
    // 0x8003F628: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
L_8003F62C:
    // 0x8003F62C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F630: lb          $t7, 0x1D6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1D6);
    // 0x8003F634: nop

    // 0x8003F638: beq         $t7, $at, L_8003F6A0
    if (ctx->r15 == ctx->r1) {
        // 0x8003F63C: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003F6A0;
    }
    // 0x8003F63C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F640: lbu         $t8, 0x5($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X5);
    // 0x8003F644: lh          $v0, 0x6($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X6);
    // 0x8003F648: beq         $t8, $zero, L_8003F670
    if (ctx->r24 == 0) {
        // 0x8003F64C: nop
    
            goto L_8003F670;
    }
    // 0x8003F64C: nop

    // 0x8003F650: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003F654: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F658: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003F65C: lwc1        $f8, 0x679C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X679C);
    // 0x8003F660: lw          $t9, 0x58($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X58);
    // 0x8003F664: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003F668: b           L_8003F68C
    // 0x8003F66C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
        goto L_8003F68C;
    // 0x8003F66C: swc1        $f18, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f18.u32l;
L_8003F670:
    // 0x8003F670: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8003F674: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F678: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003F67C: lwc1        $f4, 0x67A0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X67A0);
    // 0x8003F680: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x8003F684: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x8003F688: swc1        $f10, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f10.u32l;
L_8003F68C:
    // 0x8003F68C: lh          $t3, 0x6($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X6);
    // 0x8003F690: nop

    // 0x8003F694: ori         $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 | 0X1000;
    // 0x8003F698: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x8003F69C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003F6A0:
    // 0x8003F6A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F6A4: lbu         $t6, 0x18($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X18);
    // 0x8003F6A8: nop

    // 0x8003F6AC: bne         $t6, $at, L_8003F888
    if (ctx->r14 != ctx->r1) {
        // 0x8003F6B0: nop
    
            goto L_8003F888;
    }
    // 0x8003F6B0: nop

    // 0x8003F6B4: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8003F6B8: nop

    // 0x8003F6BC: beq         $t7, $zero, L_8003F70C
    if (ctx->r15 == 0) {
        // 0x8003F6C0: nop
    
            goto L_8003F70C;
    }
    // 0x8003F6C0: nop

    // 0x8003F6C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003F6C8: nop

    // 0x8003F6CC: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8003F6D0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8003F6D4: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8003F6D8: jal         0x80011560
    // 0x8003F6DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    ignore_bounds_check(rdram, ctx);
        goto after_4;
    // 0x8003F6DC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_4:
    // 0x8003F6E0: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8003F6E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F6E8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8003F6EC: nop

    // 0x8003F6F0: lw          $a1, 0xC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XC);
    // 0x8003F6F4: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x8003F6F8: lw          $a3, 0x14($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X14);
    // 0x8003F6FC: jal         0x80011570
    // 0x8003F700: nop

    move_object(rdram, ctx);
        goto after_5;
    // 0x8003F700: nop

    after_5:
    // 0x8003F704: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F708: nop

L_8003F70C:
    // 0x8003F70C: lbu         $v0, 0x4($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F710: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F714: beq         $v0, $at, L_8003F724
    if (ctx->r2 == ctx->r1) {
        // 0x8003F718: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003F724;
    }
    // 0x8003F718: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F71C: bne         $v0, $at, L_8003F750
    if (ctx->r2 != ctx->r1) {
        // 0x8003F720: nop
    
            goto L_8003F750;
    }
    // 0x8003F720: nop

L_8003F724:
    // 0x8003F724: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F728: lw          $t2, 0x74($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X74);
    // 0x8003F72C: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x8003F730: addu        $t3, $t9, $t2
    ctx->r11 = ADD32(ctx->r25, ctx->r10);
    // 0x8003F734: sh          $t3, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r11;
    // 0x8003F738: lh          $t4, 0x6($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X6);
    // 0x8003F73C: nop

    // 0x8003F740: slti        $at, $t4, 0x15
    ctx->r1 = SIGNED(ctx->r12) < 0X15 ? 1 : 0;
    // 0x8003F744: bne         $at, $zero, L_8003F750
    if (ctx->r1 != 0) {
        // 0x8003F748: nop
    
            goto L_8003F750;
    }
    // 0x8003F748: nop

    // 0x8003F74C: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
L_8003F750:
    // 0x8003F750: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F754: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F758: bne         $t5, $at, L_8003F7DC
    if (ctx->r13 != ctx->r1) {
        // 0x8003F75C: nop
    
            goto L_8003F7DC;
    }
    // 0x8003F75C: nop

    // 0x8003F760: lbu         $t7, 0x5($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X5);
    // 0x8003F764: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003F768: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003F76C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003F770: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x8003F774: slti        $at, $t2, 0x79
    ctx->r1 = SIGNED(ctx->r10) < 0X79 ? 1 : 0;
    // 0x8003F778: bne         $at, $zero, L_8003F7DC
    if (ctx->r1 != 0) {
        // 0x8003F77C: sb          $t9, 0x5($t0)
        MEM_B(0X5, ctx->r8) = ctx->r25;
            goto L_8003F7DC;
    }
    // 0x8003F77C: sb          $t9, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r25;
    // 0x8003F780: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003F784: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003F788: nop

    // 0x8003F78C: lw          $a0, 0x1C($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X1C);
    // 0x8003F790: nop

    // 0x8003F794: beq         $a0, $zero, L_8003F7B0
    if (ctx->r4 == 0) {
        // 0x8003F798: nop
    
            goto L_8003F7B0;
    }
    // 0x8003F798: nop

    // 0x8003F79C: jal         0x800096F8
    // 0x8003F7A0: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    audspat_point_stop(rdram, ctx);
        goto after_6;
    // 0x8003F7A0: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_6:
    // 0x8003F7A4: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003F7A8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F7AC: sw          $zero, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = 0;
L_8003F7B0:
    // 0x8003F7B0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003F7B4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003F7B8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003F7BC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003F7C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003F7C4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F7C8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003F7CC: jal         0x80009558
    // 0x8003F7D0: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_7;
    // 0x8003F7D0: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_7:
    // 0x8003F7D4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F7D8: nop

L_8003F7DC:
    // 0x8003F7DC: lbu         $t7, 0x4($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F7E0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F7E4: bne         $t7, $at, L_8003F848
    if (ctx->r15 != ctx->r1) {
        // 0x8003F7E8: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8003F848;
    }
    // 0x8003F7E8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003F7EC: sw          $t8, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r24;
    // 0x8003F7F0: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x8003F7F4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003F7F8: jal         0x800B019C
    // 0x8003F7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_8;
    // 0x8003F7FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8003F800: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x8003F804: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F808: ori         $t2, $t9, 0x4000
    ctx->r10 = ctx->r25 | 0X4000;
    // 0x8003F80C: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x8003F810: lw          $t4, 0x74($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X74);
    // 0x8003F814: lh          $t3, 0x6($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X6);
    // 0x8003F818: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003F81C: subu        $t6, $t3, $t4
    ctx->r14 = SUB32(ctx->r11, ctx->r12);
    // 0x8003F820: sh          $t6, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r14;
    // 0x8003F824: lh          $t5, 0x6($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X6);
    // 0x8003F828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003F82C: bgtz        $t5, L_8003F848
    if (SIGNED(ctx->r13) > 0) {
        // 0x8003F830: nop
    
            goto L_8003F848;
    }
    // 0x8003F830: nop

    // 0x8003F834: sh          $t7, 0x6($t0)
    MEM_H(0X6, ctx->r8) = ctx->r15;
    // 0x8003F838: jal         0x8000FFB8
    // 0x8003F83C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    free_object(rdram, ctx);
        goto after_9;
    // 0x8003F83C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_9:
    // 0x8003F840: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F844: nop

L_8003F848:
    // 0x8003F848: lbu         $t8, 0x4($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F84C: nop

    // 0x8003F850: beq         $t8, $zero, L_8003F878
    if (ctx->r24 == 0) {
        // 0x8003F854: lw          $t3, 0x74($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X74);
            goto L_8003F878;
    }
    // 0x8003F854: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003F858: lh          $t9, 0x6($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X6);
    // 0x8003F85C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003F860: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003F864: lwc1        $f16, 0x67A4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X67A4);
    // 0x8003F868: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003F86C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8003F870: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8003F874: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
L_8003F878:
    // 0x8003F878: lh          $t2, 0x18($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X18);
    // 0x8003F87C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8003F880: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x8003F884: sh          $t6, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r14;
L_8003F888:
    // 0x8003F888: lbu         $t5, 0x4($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X4);
    // 0x8003F88C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8003F890: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x8003F894: beq         $at, $zero, L_8003FC78
    if (ctx->r1 == 0) {
        // 0x8003F898: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FC78;
    }
    // 0x8003F898: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F89C: lb          $t8, 0x1D6($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1D6);
    // 0x8003F8A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F8A4: beq         $t8, $at, L_8003F8FC
    if (ctx->r24 == ctx->r1) {
        // 0x8003F8A8: addiu       $a1, $zero, 0x3C
        ctx->r5 = ADD32(0, 0X3C);
            goto L_8003F8FC;
    }
    // 0x8003F8A8: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x8003F8AC: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003F8B0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003F8B4: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003F8B8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003F8BC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003F8C0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003F8C4: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003F8C8: lwc1        $f2, 0x24($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003F8CC: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x8003F8D0: sub.d       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f18.d = ctx->f10.d - ctx->f8.d;
    // 0x8003F8D4: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    // 0x8003F8D8: div.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8003F8DC: cvt.s.d     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f16.fl = CVT_S_D(ctx->f18.d);
    // 0x8003F8E0: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x8003F8E4: div.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8003F8E8: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8003F8EC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x8003F8F0: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8003F8F4: b           L_8003F91C
    // 0x8003F8F8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
        goto L_8003F91C;
    // 0x8003F8F8: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
L_8003F8FC:
    // 0x8003F8FC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003F900: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8003F904: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    // 0x8003F908: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8003F90C: nop

    // 0x8003F910: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x8003F914: addu        $t4, $t9, $t2
    ctx->r12 = ADD32(ctx->r25, ctx->r10);
    // 0x8003F918: sh          $t4, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r12;
L_8003F91C:
    // 0x8003F91C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003F920: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003F924: lbu         $v0, 0x18($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X18);
    // 0x8003F928: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8003F92C: beq         $v0, $at, L_8003F940
    if (ctx->r2 == ctx->r1) {
        // 0x8003F930: sra         $t5, $a1, 1
        ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8003F940;
    }
    // 0x8003F930: sra         $t5, $a1, 1
    ctx->r13 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8003F934: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003F938: bne         $v0, $at, L_8003F944
    if (ctx->r2 != ctx->r1) {
        // 0x8003F93C: nop
    
            goto L_8003F944;
    }
    // 0x8003F93C: nop

L_8003F940:
    // 0x8003F940: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
L_8003F944:
    // 0x8003F944: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F948: nop

    // 0x8003F94C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8003F950: nop

    // 0x8003F954: beq         $a0, $zero, L_8003FBA8
    if (ctx->r4 == 0) {
        // 0x8003F958: nop
    
            goto L_8003FBA8;
    }
    // 0x8003F958: nop

    // 0x8003F95C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8003F960: nop

    // 0x8003F964: bne         $a0, $t8, L_8003F99C
    if (ctx->r4 != ctx->r24) {
        // 0x8003F968: addiu       $a0, $zero, 0x1C2
        ctx->r4 = ADD32(0, 0X1C2);
            goto L_8003F99C;
    }
    // 0x8003F968: addiu       $a0, $zero, 0x1C2
    ctx->r4 = ADD32(0, 0X1C2);
    // 0x8003F96C: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x8003F970: jal         0x8000C8B4
    // 0x8003F974: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_10;
    // 0x8003F974: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_10:
    // 0x8003F978: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003F97C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8003F980: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x8003F984: nop

    // 0x8003F988: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003F98C: beq         $at, $zero, L_8003FBA8
    if (ctx->r1 == 0) {
        // 0x8003F990: nop
    
            goto L_8003FBA8;
    }
    // 0x8003F990: nop

    // 0x8003F994: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8003F998: nop

L_8003F99C:
    // 0x8003F99C: lbu         $t9, 0x13($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X13);
    // 0x8003F9A0: nop

    // 0x8003F9A4: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003F9A8: beq         $at, $zero, L_8003FBA8
    if (ctx->r1 == 0) {
        // 0x8003F9AC: nop
    
            goto L_8003FBA8;
    }
    // 0x8003F9AC: nop

    // 0x8003F9B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003F9B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003F9B8: lw          $t2, 0x40($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X40);
    // 0x8003F9BC: nop

    // 0x8003F9C0: lb          $t4, 0x54($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X54);
    // 0x8003F9C4: nop

    // 0x8003F9C8: bne         $t4, $at, L_8003FBA8
    if (ctx->r12 != ctx->r1) {
        // 0x8003F9CC: nop
    
            goto L_8003FBA8;
    }
    // 0x8003F9CC: nop

    // 0x8003F9D0: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x8003F9D4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8003F9D8: sb          $t6, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r14;
    // 0x8003F9DC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003F9E0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8003F9E4: lbu         $v0, 0x18($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X18);
    // 0x8003F9E8: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003F9EC: bne         $v0, $at, L_8003FA34
    if (ctx->r2 != ctx->r1) {
        // 0x8003F9F0: addiu       $t7, $zero, 0x11
        ctx->r15 = ADD32(0, 0X11);
            goto L_8003FA34;
    }
    // 0x8003F9F0: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8003F9F4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003F9F8: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003F9FC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003FA00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003FA04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8003FA08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8003FA0C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8003FA10: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FA14: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003FA18: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FA1C: jal         0x8003FC84
    // 0x8003FA20: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_11;
    // 0x8003FA20: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_11:
    // 0x8003FA24: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FA28: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FA2C: b           L_8003FB04
    // 0x8003FA30: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
        goto L_8003FB04;
    // 0x8003FA30: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003FA34:
    // 0x8003FA34: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003FA38: bne         $v0, $at, L_8003FAEC
    if (ctx->r2 != ctx->r1) {
        // 0x8003FA3C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003FAEC;
    }
    // 0x8003FA3C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FA40: lh          $t3, 0x18E($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X18E);
    // 0x8003FA44: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8003FA48: blez        $t3, L_8003FA9C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8003FA4C: addiu       $a0, $zero, 0x152
        ctx->r4 = ADD32(0, 0X152);
            goto L_8003FA9C;
    }
    // 0x8003FA4C: addiu       $a0, $zero, 0x152
    ctx->r4 = ADD32(0, 0X152);
    // 0x8003FA50: lb          $t9, 0x189($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X189);
    // 0x8003FA54: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003FA58: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x8003FA5C: bne         $at, $zero, L_8003FA9C
    if (ctx->r1 != 0) {
        // 0x8003FA60: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8003FA9C;
    }
    // 0x8003FA60: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8003FA64: sb          $t2, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r10;
    // 0x8003FA68: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003FA6C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003FA70: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003FA74: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FA78: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8003FA7C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003FA80: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003FA84: jal         0x80009558
    // 0x8003FA88: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_12;
    // 0x8003FA88: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_12:
    // 0x8003FA8C: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FA90: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FA94: b           L_8003FB04
    // 0x8003FA98: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
        goto L_8003FB04;
    // 0x8003FA98: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003FA9C:
    // 0x8003FA9C: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x8003FAA0: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x8003FAA4: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x8003FAA8: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x8003FAAC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8003FAB0: addiu       $t7, $t6, 0x1C
    ctx->r15 = ADD32(ctx->r14, 0X1C);
    // 0x8003FAB4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8003FAB8: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8003FABC: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FAC0: jal         0x80009558
    // 0x8003FAC4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_13;
    // 0x8003FAC4: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_13:
    // 0x8003FAC8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FACC: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FAD0: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8003FAD4: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003FAD8: sb          $t8, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r24;
    // 0x8003FADC: sb          $t3, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r11;
    // 0x8003FAE0: b           L_8003FB00
    // 0x8003FAE4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
        goto L_8003FB00;
    // 0x8003FAE4: sb          $zero, 0x5($t0)
    MEM_B(0X5, ctx->r8) = 0;
    // 0x8003FAE8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8003FAEC:
    // 0x8003FAEC: bne         $v0, $at, L_8003FB00
    if (ctx->r2 != ctx->r1) {
        // 0x8003FAF0: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8003FB00;
    }
    // 0x8003FAF0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003FAF4: sb          $t9, 0x187($t1)
    MEM_B(0X187, ctx->r9) = ctx->r25;
    // 0x8003FAF8: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003FAFC: sb          $t2, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r10;
L_8003FB00:
    // 0x8003FB00: lb          $t4, 0x1D8($t1)
    ctx->r12 = MEM_B(ctx->r9, 0X1D8);
L_8003FB04:
    // 0x8003FB04: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8003FB08: bne         $t4, $zero, L_8003FB30
    if (ctx->r12 != 0) {
        // 0x8003FB0C: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003FB30;
    }
    // 0x8003FB0C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8003FB10: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x8003FB14: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x8003FB18: jal         0x80072594
    // 0x8003FB1C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    rumble_set(rdram, ctx);
        goto after_14;
    // 0x8003FB1C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_14:
    // 0x8003FB20: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FB24: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x8003FB28: nop

    // 0x8003FB2C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FB30:
    // 0x8003FB30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8003FB34: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8003FB38: nop

    // 0x8003FB3C: lw          $t7, 0x64($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X64);
    // 0x8003FB40: nop

    // 0x8003FB44: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x8003FB48: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x8003FB4C: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8003FB50: bne         $v0, $t8, L_8003FB68
    if (ctx->r2 != ctx->r24) {
        // 0x8003FB54: nop
    
            goto L_8003FB68;
    }
    // 0x8003FB54: nop

    // 0x8003FB58: lh          $t3, 0x0($t7)
    ctx->r11 = MEM_H(ctx->r15, 0X0);
    // 0x8003FB5C: nop

    // 0x8003FB60: beq         $v0, $t3, L_8003FB7C
    if (ctx->r2 == ctx->r11) {
        // 0x8003FB64: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8003FB7C;
    }
    // 0x8003FB64: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FB68:
    // 0x8003FB68: lbu         $t2, 0x1EF($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X1EF);
    // 0x8003FB6C: nop

    // 0x8003FB70: ori         $t4, $t2, 0x2
    ctx->r12 = ctx->r10 | 0X2;
    // 0x8003FB74: sb          $t4, 0x1EF($t9)
    MEM_B(0X1EF, ctx->r25) = ctx->r12;
    // 0x8003FB78: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8003FB7C:
    // 0x8003FB7C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FB80: lbu         $v0, 0x18($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X18);
    // 0x8003FB84: nop

    // 0x8003FB88: beq         $v0, $at, L_8003FBA8
    if (ctx->r2 == ctx->r1) {
        // 0x8003FB8C: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_8003FBA8;
    }
    // 0x8003FB8C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003FB90: beq         $v0, $at, L_8003FBA8
    if (ctx->r2 == ctx->r1) {
        // 0x8003FB94: nop
    
            goto L_8003FBA8;
    }
    // 0x8003FB94: nop

    // 0x8003FB98: jal         0x8000FFB8
    // 0x8003FB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_15;
    // 0x8003FB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8003FBA0: b           L_8003FC78
    // 0x8003FBA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FC78;
    // 0x8003FBA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FBA8:
    // 0x8003FBA8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8003FBAC: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8003FBB0: lbu         $t3, 0x4($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X4);
    // 0x8003FBB4: subu        $t7, $t6, $t8
    ctx->r15 = SUB32(ctx->r14, ctx->r24);
    // 0x8003FBB8: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x8003FBBC: beq         $at, $zero, L_8003FC74
    if (ctx->r1 == 0) {
        // 0x8003FBC0: sw          $t7, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r15;
            goto L_8003FC74;
    }
    // 0x8003FBC0: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8003FBC4: addiu       $a0, $zero, -0x528
    ctx->r4 = ADD32(0, -0X528);
    // 0x8003FBC8: jal         0x8000C8B4
    // 0x8003FBCC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    normalise_time(rdram, ctx);
        goto after_16;
    // 0x8003FBCC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_16:
    // 0x8003FBD0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8003FBD4: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003FBD8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8003FBDC: nop

    // 0x8003FBE0: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003FBE4: beq         $at, $zero, L_8003FC78
    if (ctx->r1 == 0) {
        // 0x8003FBE8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003FC78;
    }
    // 0x8003FBE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003FBEC: lbu         $v0, 0x18($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X18);
    // 0x8003FBF0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003FBF4: bne         $v0, $at, L_8003FC04
    if (ctx->r2 != ctx->r1) {
        // 0x8003FBF8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8003FC04;
    }
    // 0x8003FBF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003FBFC: b           L_8003FC74
    // 0x8003FC00: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
        goto L_8003FC74;
    // 0x8003FC00: sb          $t9, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r25;
L_8003FC04:
    // 0x8003FC04: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8003FC08: bne         $v0, $at, L_8003FC40
    if (ctx->r2 != ctx->r1) {
        // 0x8003FC0C: addiu       $a3, $zero, 0x2C
        ctx->r7 = ADD32(0, 0X2C);
            goto L_8003FC40;
    }
    // 0x8003FC0C: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003FC10: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x8003FC14: sb          $t5, 0x4($t0)
    MEM_B(0X4, ctx->r8) = ctx->r13;
    // 0x8003FC18: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003FC1C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003FC20: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003FC24: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8003FC28: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003FC2C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003FC30: jal         0x80009558
    // 0x8003FC34: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_17;
    // 0x8003FC34: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_17:
    // 0x8003FC38: b           L_8003FC78
    // 0x8003FC3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_8003FC78;
    // 0x8003FC3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FC40:
    // 0x8003FC40: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003FC44: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003FC48: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003FC4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003FC50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003FC54: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x8003FC58: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003FC5C: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8003FC60: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003FC64: jal         0x8003FC84
    // 0x8003FC68: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_18;
    // 0x8003FC68: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_18:
    // 0x8003FC6C: jal         0x8000FFB8
    // 0x8003FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_19;
    // 0x8003FC70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
L_8003FC74:
    // 0x8003FC74: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003FC78:
    // 0x8003FC78: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003FC7C: jr          $ra
    // 0x8003FC80: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003FC80: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_800BBDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC2FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800BC300: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800BC304: jal         0x800BC328
    // 0x800BC308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_800BBE08(rdram, ctx);
        goto after_0;
    // 0x800BC308: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800BC30C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800BC310: jal         0x800BC498
    // 0x800BC314: nop

    func_800BBF78(rdram, ctx);
        goto after_1;
    // 0x800BC314: nop

    after_1:
    // 0x800BC318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800BC31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800BC320: jr          $ra
    // 0x800BC324: nop

    return;
    // 0x800BC324: nop

;}
RECOMP_FUNC void ainode_tail_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D1F0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001D1F4: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8001D1F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8001D1FC: nop

    // 0x8001D200: beq         $a0, $v0, L_8001D210
    if (ctx->r4 == ctx->r2) {
        // 0x8001D204: nop
    
            goto L_8001D210;
    }
    // 0x8001D204: nop

    // 0x8001D208: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8001D20C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_8001D210:
    // 0x8001D210: jr          $ra
    // 0x8001D214: nop

    return;
    // 0x8001D214: nop

;}
RECOMP_FUNC void fileselect_render_element(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D0E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008D0E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008D0E8: addiu       $t2, $t2, -0x5D4
    ctx->r10 = ADD32(ctx->r10, -0X5D4);
    // 0x8008D0EC: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x8008D0F0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008D0F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D0F8: addiu       $t3, $t3, -0x31C
    ctx->r11 = ADD32(ctx->r11, -0X31C);
    // 0x8008D0FC: addiu       $t0, $t0, -0x5DC
    ctx->r8 = ADD32(ctx->r8, -0X5DC);
    // 0x8008D100: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8008D104: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8008D108: lw          $t9, 0x0($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X0);
    // 0x8008D10C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D110: addiu       $t8, $a1, -0x9F
    ctx->r24 = ADD32(ctx->r5, -0X9F);
    // 0x8008D114: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008D118: addiu       $t1, $t1, -0x5D8
    ctx->r9 = ADD32(ctx->r9, -0X5D8);
    // 0x8008D11C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008D120: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x8008D124: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8008D128: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x8008D12C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8008D130: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x8008D134: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D138: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8008D13C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8008D140: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008D144: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8008D148: sb          $t4, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r12;
    // 0x8008D14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008D150: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8008D154: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8008D158: sb          $a3, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r7;
    // 0x8008D15C: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8008D160: sb          $t5, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r13;
    // 0x8008D164: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8008D168: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008D16C: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x8008D170: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008D174: addiu       $t6, $zero, 0x77
    ctx->r14 = ADD32(0, 0X77);
    // 0x8008D178: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x8008D17C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8008D180: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8008D184: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8008D188: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8008D18C: swc1        $f10, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f10.u32l;
    // 0x8008D190: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8008D194: jal         0x8009CFA4
    // 0x8008D198: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_0;
    // 0x8008D198: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008D19C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8008D1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1A4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8008D1A8: sb          $t4, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r12;
    // 0x8008D1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1B0: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8008D1B4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8008D1B8: sb          $t6, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r14;
    // 0x8008D1BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008D1C4: sb          $t5, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r13;
    // 0x8008D1C8: addiu       $t9, $t8, -0xA1
    ctx->r25 = ADD32(ctx->r24, -0XA1);
    // 0x8008D1CC: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8008D1D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008D1D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D1D8: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x8008D1DC: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    // 0x8008D1E0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008D1E4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8008D1E8: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008D1EC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008D1F0: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x8008D1F4: swc1        $f18, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f18.u32l;
    // 0x8008D1F8: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x8008D1FC: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x8008D200: subu        $t8, $t7, $t5
    ctx->r24 = SUB32(ctx->r15, ctx->r13);
    // 0x8008D204: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8008D208: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8008D20C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008D210: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x8008D214: jal         0x8009CFA4
    // 0x8008D218: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_1;
    // 0x8008D218: swc1        $f6, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->f6.u32l;
    after_1:
    // 0x8008D21C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008D220: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8008D224: jr          $ra
    // 0x8008D228: nop

    return;
    // 0x8008D228: nop

;}
RECOMP_FUNC void obj_init_lensflareswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004098C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040990: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040994: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040998: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8004099C: jal         0x800AD4C0
    // 0x800409A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    lensflare_override_add(rdram, ctx);
        goto after_0;
    // 0x800409A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800409A4: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800409A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800409AC: lh          $t7, 0x8($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X8);
    // 0x800409B0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800409B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800409B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800409BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800409C0: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800409C4: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800409C8: nop

    // 0x800409CC: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800409D0: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800409D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800409D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800409DC: jr          $ra
    // 0x800409E0: nop

    return;
    // 0x800409E0: nop

;}
RECOMP_FUNC void render_bubble_trap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800138A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800138AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800138B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800138B4: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800138B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800138BC: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800138C0: addiu       $a1, $a2, 0xC
    ctx->r5 = ADD32(ctx->r6, 0XC);
    // 0x800138C4: jal         0x80070560
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800138C8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x800138CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800138D0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800138D4: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800138D8: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800138DC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800138E0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800138E4: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800138E8: lwc1        $f18, 0x10($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800138EC: nop

    // 0x800138F0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800138F4: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800138F8: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800138FC: nop

    // 0x80013900: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80013904: jal         0x80069F60
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    cam_get_active_camera(rdram, ctx);
        goto after_1;
    // 0x80013908: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    after_1:
    // 0x8001390C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80013910: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80013914: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80013918: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8001391C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013920: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80013924: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80013928: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001392C: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80013930: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80013934: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80013938: swc1        $f14, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f14.u32l;
    // 0x8001393C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80013940: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80013944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80013948: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x8001394C: jal         0x800CA030
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80013950: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80013954: mtc1        $zero, $f19
    ctx->f_odd[(19 - 1) * 2] = 0;
    // 0x80013958: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8001395C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80013960: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x80013964: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80013968: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8001396C: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80013970: bc1f        L_800139AC
    if (!c1cs) {
        // 0x80013974: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800139AC;
    }
    // 0x80013974: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80013978: lh          $t6, 0x1A($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A);
    // 0x8001397C: nop

    // 0x80013980: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80013984: nop

    // 0x80013988: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001398C: nop

    // 0x80013990: div.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80013994: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80013998: nop

    // 0x8001399C: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x800139A0: nop

    // 0x800139A4: mul.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800139A8: nop

L_800139AC:
    // 0x800139AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800139B0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800139B4: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800139B8: add.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800139BC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800139C0: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800139C4: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800139C8: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800139CC: swc1        $f6, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f6.u32l;
    // 0x800139D0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800139D4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800139D8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800139DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800139E0: addiu       $a2, $a2, -0x4BEC
    ctx->r6 = ADD32(ctx->r6, -0X4BEC);
    // 0x800139E4: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x800139E8: addiu       $a0, $a0, -0x4BF4
    ctx->r4 = ADD32(ctx->r4, -0X4BF4);
    // 0x800139EC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800139F0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800139F4: jal         0x80068754
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    render_sprite_billboard(rdram, ctx);
        goto after_3;
    // 0x800139F8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x800139FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013A00: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80013A04: jr          $ra
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80013A08: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sndp_end(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000410C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80004110: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004114: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80004118: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x8000411C: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80004120: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x80004124: beq         $t8, $zero, L_80004158
    if (ctx->r24 == 0) {
        // 0x80004128: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_80004158;
    }
    // 0x80004128: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000412C: lw          $t9, -0x33D4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X33D4);
    // 0x80004130: addiu       $a1, $t6, 0xC
    ctx->r5 = ADD32(ctx->r14, 0XC);
    // 0x80004134: lw          $a0, 0x38($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X38);
    // 0x80004138: jal         0x800C9E10
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    alSynStopVoice(rdram, ctx);
        goto after_0;
    // 0x8000413C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80004140: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80004144: lw          $t0, -0x33D4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X33D4);
    // 0x80004148: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000414C: lw          $a0, 0x38($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X38);
    // 0x80004150: jal         0x800C9E90
    // 0x80004154: nop

    alSynFreeVoice(rdram, ctx);
        goto after_1;
    // 0x80004154: nop

    after_1:
L_80004158:
    // 0x80004158: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8000415C: jal         0x80004520
    // 0x80004160: nop

    sndp_deallocate(rdram, ctx);
        goto after_2;
    // 0x80004160: nop

    after_2:
    // 0x80004164: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80004168: lw          $a0, -0x33D4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X33D4);
    // 0x8000416C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80004170: ori         $a2, $zero, 0xFFFF
    ctx->r6 = 0 | 0XFFFF;
    // 0x80004174: jal         0x800041FC
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    static_3_800041FC(rdram, ctx);
        goto after_3;
    // 0x80004178: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x8000417C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80004184: jr          $ra
    // 0x80004188: nop

    return;
    // 0x80004188: nop

;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6C60: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800D6C64: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800D6C68: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800D6C6C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x800D6C70: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800D6C74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800D6C78: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800D6C7C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800D6C80: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800D6C84: bne         $v1, $v0, L_800D6C98
    if (ctx->r3 != ctx->r2) {
        // 0x800D6C88: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800D6C98;
    }
    // 0x800D6C88: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800D6C8C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D6C90: b           L_800D6CA0
    // 0x800D6C94: addiu       $s3, $s3, 0x4EC4
    ctx->r19 = ADD32(ctx->r19, 0X4EC4);
        goto L_800D6CA0;
    // 0x800D6C94: addiu       $s3, $s3, 0x4EC4
    ctx->r19 = ADD32(ctx->r19, 0X4EC4);
L_800D6C98:
    // 0x800D6C98: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800D6C9C: addiu       $s3, $s3, 0x4EB0
    ctx->r19 = ADD32(ctx->r19, 0X4EB0);
L_800D6CA0:
    // 0x800D6CA0: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800D6CA4: bne         $v0, $at, L_800D6CB4
    if (ctx->r2 != ctx->r1) {
        // 0x800D6CA8: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800D6CB4;
    }
    // 0x800D6CA8: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800D6CAC: b           L_800D6CD4
    // 0x800D6CB0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800D6CD4;
    // 0x800D6CB0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800D6CB4:
    // 0x800D6CB4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D6CB8: beq         $v0, $at, L_800D6CD0
    if (ctx->r2 == ctx->r1) {
        // 0x800D6CBC: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800D6CD0;
    }
    // 0x800D6CBC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800D6CC0: beq         $v1, $v0, L_800D6CD0
    if (ctx->r3 == ctx->r2) {
        // 0x800D6CC4: nop
    
            goto L_800D6CD0;
    }
    // 0x800D6CC4: nop

    // 0x800D6CC8: b           L_800D6CD0
    // 0x800D6CCC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800D6CD0;
    // 0x800D6CCC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800D6CD0:
    // 0x800D6CD0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800D6CD4:
    // 0x800D6CD4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D6CD8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D6CDC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800D6CE0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D6CE4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D6CE8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D6CEC: beq         $v0, $at, L_800D6D00
    if (ctx->r2 == ctx->r1) {
        // 0x800D6CF0: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_800D6D00;
    }
    // 0x800D6CF0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D6CF4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x800D6CF8: bnel        $v0, $at, L_800D6D3C
    if (ctx->r2 != ctx->r1) {
        // 0x800D6CFC: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D3C;
    }
    goto skip_0;
    // 0x800D6CFC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_800D6D00:
    // 0x800D6D00: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D6D04: bgtzl       $t4, L_800D6D3C
    if (SIGNED(ctx->r12) > 0) {
        // 0x800D6D08: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D3C;
    }
    goto skip_1;
    // 0x800D6D08: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x800D6D0C: bltz        $t4, L_800D6D1C
    if (SIGNED(ctx->r12) < 0) {
        // 0x800D6D10: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D1C;
    }
    // 0x800D6D10: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800D6D14: b           L_800D6D3C
    // 0x800D6D18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_800D6D3C;
    // 0x800D6D18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D6D1C:
    // 0x800D6D1C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D20: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x800D6D24: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x800D6D28: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x800D6D2C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x800D6D30: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D6D34: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D6D38: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_800D6D3C:
    // 0x800D6D3C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D40: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x800D6D44: bne         $t2, $zero, L_800D6D60
    if (ctx->r10 != 0) {
        // 0x800D6D48: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800D6D60;
    }
    // 0x800D6D48: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D6D4C: bnel        $t3, $zero, L_800D6D64
    if (ctx->r11 != 0) {
        // 0x800D6D50: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_800D6D64;
    }
    goto skip_2;
    // 0x800D6D50: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x800D6D54: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x800D6D58: beql        $t4, $zero, L_800D6D9C
    if (ctx->r12 == 0) {
        // 0x800D6D5C: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800D6D9C;
    }
    goto skip_3;
    // 0x800D6D5C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_800D6D60:
    // 0x800D6D60: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_800D6D64:
    // 0x800D6D64: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6D68: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D6D6C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6D70: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800D6D74: jal         0x800CEFEC
    // 0x800D6D78: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800D6D78: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x800D6D7C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6D80: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x800D6D84: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800D6D88: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800D6D8C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6D90: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800D6D94: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D6D98: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800D6D9C:
    // 0x800D6D9C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800D6DA0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800D6DA4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800D6DA8: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6DAC: jal         0x800CF028
    // 0x800D6DB0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800D6DB0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800D6DB4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800D6DB8: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800D6DBC: bltz        $v0, L_800D6E6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800D6DC0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_800D6E6C;
    }
    // 0x800D6DC0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800D6DC4: bgtz        $v0, L_800D6DD4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6DC8: nop
    
            goto L_800D6DD4;
    }
    // 0x800D6DC8: nop

    // 0x800D6DCC: beql        $v1, $zero, L_800D6E70
    if (ctx->r3 == 0) {
        // 0x800D6DD0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6E70;
    }
    goto skip_4;
    // 0x800D6DD0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800D6DD4:
    // 0x800D6DD4: blez        $s0, L_800D6E6C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6DD8: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_800D6E6C;
    }
    // 0x800D6DD8: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800D6DDC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800D6DE0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800D6DE4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800D6DE8: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800D6DEC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800D6DF0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D6DF4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_800D6DF8:
    // 0x800D6DF8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6DFC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800D6E00: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800D6E04: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800D6E08: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D6E0C: jal         0x800D79D0
    // 0x800D6E10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x800D6E10: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x800D6E14: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D6E18: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x800D6E1C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800D6E20: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800D6E24: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x800D6E28: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x800D6E2C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x800D6E30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D6E34: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x800D6E38: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800D6E3C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x800D6E40: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800D6E44: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800D6E48: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800D6E4C: bltz        $t8, L_800D6E6C
    if (SIGNED(ctx->r24) < 0) {
        // 0x800D6E50: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_800D6E6C;
    }
    // 0x800D6E50: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800D6E54: bgtz        $t8, L_800D6E64
    if (SIGNED(ctx->r24) > 0) {
        // 0x800D6E58: nop
    
            goto L_800D6E64;
    }
    // 0x800D6E58: nop

    // 0x800D6E5C: beql        $t9, $zero, L_800D6E70
    if (ctx->r25 == 0) {
        // 0x800D6E60: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_800D6E70;
    }
    goto skip_5;
    // 0x800D6E60: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_800D6E64:
    // 0x800D6E64: bgtzl       $s0, L_800D6DF8
    if (SIGNED(ctx->r16) > 0) {
        // 0x800D6E68: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_800D6DF8;
    }
    goto skip_6;
    // 0x800D6E68: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_800D6E6C:
    // 0x800D6E6C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_800D6E70:
    // 0x800D6E70: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x800D6E74: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x800D6E78: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x800D6E7C: jal         0x800CE6D0
    // 0x800D6E80: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D6E80: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x800D6E84: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x800D6E88: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x800D6E8C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800D6E90: beq         $at, $zero, L_800D6E9C
    if (ctx->r1 == 0) {
        // 0x800D6E94: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800D6E9C;
    }
    // 0x800D6E94: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800D6E98: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800D6E9C:
    // 0x800D6E9C: bgezl       $a0, L_800D6EE0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800D6EA0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6EE0;
    }
    goto skip_7;
    // 0x800D6EA0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x800D6EA4: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x800D6EA8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D6EAC: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800D6EB0: bnel        $t7, $at, L_800D6EE0
    if (ctx->r15 != ctx->r1) {
        // 0x800D6EB4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800D6EE0;
    }
    goto skip_8;
    // 0x800D6EB4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x800D6EB8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x800D6EBC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800D6EC0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800D6EC4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6EC8: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800D6ECC: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800D6ED0: blez        $s0, L_800D6EDC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800D6ED4: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800D6EDC;
    }
    // 0x800D6ED4: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800D6ED8: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800D6EDC:
    // 0x800D6EDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800D6EE0:
    // 0x800D6EE0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6EE4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800D6EE8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800D6EEC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800D6EF0: jr          $ra
    // 0x800D6EF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800D6EF4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_boost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004214C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042150: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042154: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80042158: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8004215C: jal         0x8001E2D0
    // 0x80042160: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80042160: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x80042164: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80042168: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8004216C: lb          $t7, 0x8($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X8);
    // 0x80042170: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x80042174: sll         $t8, $t7, 7
    ctx->r24 = S32(ctx->r15 << 7);
    // 0x80042178: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8004217C: sw          $t9, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->r25;
    // 0x80042180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042188: jr          $ra
    // 0x8004218C: nop

    return;
    // 0x8004218C: nop

;}
RECOMP_FUNC void unload_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CE54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CE58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CE5C: jal         0x800712F0
    // 0x8006CE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_0;
    // 0x8006CE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006CE64: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8006CE68: lb          $t6, -0x2704($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X2704);
    // 0x8006CE6C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006CE70: bne         $t6, $zero, L_8006CE9C
    if (ctx->r14 != 0) {
        // 0x8006CE74: nop
    
            goto L_8006CE9C;
    }
    // 0x8006CE74: nop

    // 0x8006CE78: lb          $t7, -0x26A0($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X26A0);
    // 0x8006CE7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006CE80: beq         $t7, $at, L_8006CE94
    if (ctx->r15 == ctx->r1) {
        // 0x8006CE84: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006CE94;
    }
    // 0x8006CE84: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006CE88: jal         0x80077EA4
    // 0x8006CE8C: nop

    gfxtask_wait(rdram, ctx);
        goto after_1;
    // 0x8006CE8C: nop

    after_1:
    // 0x8006CE90: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
L_8006CE94:
    // 0x8006CE94: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006CE98: sb          $t8, -0x2704($at)
    MEM_B(-0X2704, ctx->r1) = ctx->r24;
L_8006CE9C:
    // 0x8006CE9C: jal         0x8006C13C
    // 0x8006CEA0: nop

    level_free(rdram, ctx);
        goto after_2;
    // 0x8006CEA0: nop

    after_2:
    // 0x8006CEA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006CEA8: jal         0x800C06F8
    // 0x8006CEAC: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8006CEAC: addiu       $a0, $a0, -0x269C
    ctx->r4 = ADD32(ctx->r4, -0X269C);
    after_3:
    // 0x8006CEB0: jal         0x800AE7D0
    // 0x8006CEB4: nop

    reset_particles(rdram, ctx);
        goto after_4;
    // 0x8006CEB4: nop

    after_4:
    // 0x8006CEB8: jal         0x800A057C
    // 0x8006CEBC: nop

    hud_free(rdram, ctx);
        goto after_5;
    // 0x8006CEBC: nop

    after_5:
    // 0x8006CEC0: jal         0x800C3624
    // 0x8006CEC4: nop

    free_game_text_table(rdram, ctx);
        goto after_6;
    // 0x8006CEC4: nop

    after_6:
    // 0x8006CEC8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006CECC: lw          $t9, 0x3A68($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3A68);
    // 0x8006CED0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006CED4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8006CED8: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8006CEDC: lw          $t1, 0x1770($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1770);
    // 0x8006CEE0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CEE4: addiu       $v1, $v1, 0x1778
    ctx->r3 = ADD32(ctx->r3, 0X1778);
    // 0x8006CEE8: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8006CEEC: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x8006CEF0: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006CEF4: lui         $t3, 0xE900
    ctx->r11 = S32(0XE900 << 16);
    // 0x8006CEF8: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006CEFC: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8006CF00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006CF04: lui         $t5, 0xB800
    ctx->r13 = S32(0XB800 << 16);
    // 0x8006CF08: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8006CF0C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8006CF10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006CF14: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006CF18: jal         0x800712F0
    // 0x8006CF1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    mempool_free_timer(rdram, ctx);
        goto after_7;
    // 0x8006CF1C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_7:
    // 0x8006CF20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CF24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CF28: jr          $ra
    // 0x8006CF2C: nop

    return;
    // 0x8006CF2C: nop

;}
RECOMP_FUNC void light_add_from_level_object_entry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031CEC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80031CF0: addiu       $v1, $v1, -0x3134
    ctx->r3 = ADD32(ctx->r3, -0X3134);
    // 0x80031CF4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80031CF8: lw          $t6, -0x3138($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3138);
    // 0x80031CFC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80031D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80031D04: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80031D08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80031D0C: beq         $at, $zero, L_80031FB8
    if (ctx->r1 == 0) {
        // 0x80031D10: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80031FB8;
    }
    // 0x80031D10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80031D14: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80031D18: lw          $t7, -0x3140($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3140);
    // 0x80031D1C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80031D20: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80031D24: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x80031D28: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80031D2C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80031D30: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x80031D34: nop

    // 0x80031D38: andi        $t3, $t2, 0xF0
    ctx->r11 = ctx->r10 & 0XF0;
    // 0x80031D3C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80031D40: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x80031D44: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x80031D48: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80031D4C: andi        $t6, $t5, 0xF
    ctx->r14 = ctx->r13 & 0XF;
    // 0x80031D50: sb          $t6, 0x3($a2)
    MEM_B(0X3, ctx->r6) = ctx->r14;
    // 0x80031D54: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D58: nop

    // 0x80031D5C: andi        $t8, $t7, 0xE0
    ctx->r24 = ctx->r15 & 0XE0;
    // 0x80031D60: sra         $t9, $t8, 5
    ctx->r25 = S32(SIGNED(ctx->r24) >> 5);
    // 0x80031D64: sb          $t9, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r25;
    // 0x80031D68: lbu         $t1, 0x9($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X9);
    // 0x80031D6C: sb          $t3, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r11;
    // 0x80031D70: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80031D74: sb          $t2, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r10;
    // 0x80031D78: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x80031D7C: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x80031D80: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x80031D84: beq         $a0, $zero, L_80031DB0
    if (ctx->r4 == 0) {
        // 0x80031D88: sh          $zero, 0xA($a2)
        MEM_H(0XA, ctx->r6) = 0;
            goto L_80031DB0;
    }
    // 0x80031D88: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x80031D8C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80031D90: nop

    // 0x80031D94: swc1        $f4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f4.u32l;
    // 0x80031D98: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80031D9C: nop

    // 0x80031DA0: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x80031DA4: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80031DA8: b           L_80031DF8
    // 0x80031DAC: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
        goto L_80031DF8;
    // 0x80031DAC: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031DB0:
    // 0x80031DB0: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x80031DB4: nop

    // 0x80031DB8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80031DBC: nop

    // 0x80031DC0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031DC4: swc1        $f16, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f16.u32l;
    // 0x80031DC8: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x80031DCC: nop

    // 0x80031DD0: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x80031DD4: nop

    // 0x80031DD8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031DDC: swc1        $f4, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f4.u32l;
    // 0x80031DE0: lh          $t6, 0x6($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X6);
    // 0x80031DE4: nop

    // 0x80031DE8: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80031DEC: nop

    // 0x80031DF0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031DF4: swc1        $f8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f8.u32l;
L_80031DF8:
    // 0x80031DF8: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x80031DFC: sw          $zero, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = 0;
    // 0x80031E00: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80031E04: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
    // 0x80031E08: sh          $zero, 0x3C($a2)
    MEM_H(0X3C, ctx->r6) = 0;
    // 0x80031E0C: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x80031E10: sw          $zero, 0x30($a2)
    MEM_W(0X30, ctx->r6) = 0;
    // 0x80031E14: sll         $t1, $t9, 16
    ctx->r9 = S32(ctx->r25 << 16);
    // 0x80031E18: sw          $t1, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r9;
    // 0x80031E1C: sh          $zero, 0x3E($a2)
    MEM_H(0X3E, ctx->r6) = 0;
    // 0x80031E20: lbu         $t2, 0xC($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XC);
    // 0x80031E24: sw          $zero, 0x34($a2)
    MEM_W(0X34, ctx->r6) = 0;
    // 0x80031E28: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80031E2C: sw          $t3, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r11;
    // 0x80031E30: sh          $zero, 0x40($a2)
    MEM_H(0X40, ctx->r6) = 0;
    // 0x80031E34: lbu         $t4, 0xD($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0XD);
    // 0x80031E38: sw          $zero, 0x38($a2)
    MEM_W(0X38, ctx->r6) = 0;
    // 0x80031E3C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80031E40: sw          $t5, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r13;
    // 0x80031E44: sh          $zero, 0x42($a2)
    MEM_H(0X42, ctx->r6) = 0;
    // 0x80031E48: sw          $zero, 0x44($a2)
    MEM_W(0X44, ctx->r6) = 0;
    // 0x80031E4C: lbu         $t6, 0x1C($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E50: nop

    // 0x80031E54: slti        $at, $t6, 0x7
    ctx->r1 = SIGNED(ctx->r14) < 0X7 ? 1 : 0;
    // 0x80031E58: beq         $at, $zero, L_80031EDC
    if (ctx->r1 == 0) {
        // 0x80031E5C: nop
    
            goto L_80031EDC;
    }
    // 0x80031E5C: nop

    // 0x80031E60: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80031E64: jal         0x8006BFF0
    // 0x80031E68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80031E68: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80031E6C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80031E70: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031E74: lbu         $t7, 0x1C($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1C);
    // 0x80031E78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80031E7C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80031E80: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80031E84: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80031E88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80031E8C: beq         $t0, $at, L_80031EDC
    if (ctx->r8 == ctx->r1) {
        // 0x80031E90: addiu       $t2, $t0, 0x14
        ctx->r10 = ADD32(ctx->r8, 0X14);
            goto L_80031EDC;
    }
    // 0x80031E90: addiu       $t2, $t0, 0x14
    ctx->r10 = ADD32(ctx->r8, 0X14);
    // 0x80031E94: sw          $t0, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r8;
    // 0x80031E98: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80031E9C: sh          $zero, 0x4A($a2)
    MEM_H(0X4A, ctx->r6) = 0;
    // 0x80031EA0: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80031EA4: sh          $zero, 0x4C($a2)
    MEM_H(0X4C, ctx->r6) = 0;
    // 0x80031EA8: sh          $zero, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = 0;
    // 0x80031EAC: sw          $t2, 0x44($a2)
    MEM_W(0X44, ctx->r6) = ctx->r10;
    // 0x80031EB0: blez        $a0, L_80031EDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80031EB4: sh          $t1, 0x48($a2)
        MEM_H(0X48, ctx->r6) = ctx->r9;
            goto L_80031EDC;
    }
    // 0x80031EB4: sh          $t1, 0x48($a2)
    MEM_H(0X48, ctx->r6) = ctx->r9;
    // 0x80031EB8: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80031EBC:
    // 0x80031EBC: lhu         $t3, 0x4E($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X4E);
    // 0x80031EC0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80031EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80031EC8: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80031ECC: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80031ED0: sh          $t5, 0x4E($a2)
    MEM_H(0X4E, ctx->r6) = ctx->r13;
    // 0x80031ED4: bne         $at, $zero, L_80031EBC
    if (ctx->r1 != 0) {
        // 0x80031ED8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80031EBC;
    }
    // 0x80031ED8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
L_80031EDC:
    // 0x80031EDC: lh          $t6, 0xE($a1)
    ctx->r14 = MEM_H(ctx->r5, 0XE);
    // 0x80031EE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031EE4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80031EE8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80031EEC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80031EF0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80031EF4: swc1        $f16, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->f16.u32l;
    // 0x80031EF8: lh          $t7, 0x10($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X10);
    // 0x80031EFC: lwc1        $f0, 0x5C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X5C);
    // 0x80031F00: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80031F04: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80031F08: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80031F0C: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x80031F10: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80031F14: swc1        $f4, 0x60($a2)
    MEM_W(0X60, ctx->r6) = ctx->f4.u32l;
    // 0x80031F18: lh          $t8, 0x12($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X12);
    // 0x80031F1C: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80031F20: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80031F24: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80031F28: swc1        $f10, 0x68($a2)
    MEM_W(0X68, ctx->r6) = ctx->f10.u32l;
    // 0x80031F2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80031F30: swc1        $f18, 0x6C($a2)
    MEM_W(0X6C, ctx->r6) = ctx->f18.u32l;
    // 0x80031F34: swc1        $f8, 0x64($a2)
    MEM_W(0X64, ctx->r6) = ctx->f8.u32l;
    // 0x80031F38: lh          $t9, 0x14($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X14);
    // 0x80031F3C: nop

    // 0x80031F40: sh          $t9, 0x70($a2)
    MEM_H(0X70, ctx->r6) = ctx->r25;
    // 0x80031F44: lh          $t1, 0x18($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X18);
    // 0x80031F48: nop

    // 0x80031F4C: sh          $t1, 0x74($a2)
    MEM_H(0X74, ctx->r6) = ctx->r9;
    // 0x80031F50: lh          $t2, 0x18($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X18);
    // 0x80031F54: nop

    // 0x80031F58: beq         $t2, $zero, L_80031F68
    if (ctx->r10 == 0) {
        // 0x80031F5C: nop
    
            goto L_80031F68;
    }
    // 0x80031F5C: nop

    // 0x80031F60: b           L_80031F6C
    // 0x80031F64: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
        goto L_80031F6C;
    // 0x80031F64: sh          $t3, 0x78($a2)
    MEM_H(0X78, ctx->r6) = ctx->r11;
L_80031F68:
    // 0x80031F68: sh          $zero, 0x78($a2)
    MEM_H(0X78, ctx->r6) = 0;
L_80031F6C:
    // 0x80031F6C: lh          $t4, 0x16($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X16);
    // 0x80031F70: nop

    // 0x80031F74: sh          $t4, 0x72($a2)
    MEM_H(0X72, ctx->r6) = ctx->r12;
    // 0x80031F78: lh          $t5, 0x1A($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F7C: nop

    // 0x80031F80: sh          $t5, 0x76($a2)
    MEM_H(0X76, ctx->r6) = ctx->r13;
    // 0x80031F84: lh          $t6, 0x1A($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X1A);
    // 0x80031F88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80031F8C: beq         $t6, $zero, L_80031FA0
    if (ctx->r14 == 0) {
        // 0x80031F90: nop
    
            goto L_80031FA0;
    }
    // 0x80031F90: nop

    // 0x80031F94: sh          $t7, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = ctx->r15;
    // 0x80031F98: b           L_80031FA4
    // 0x80031F9C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
        goto L_80031FA4;
    // 0x80031F9C: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031FA0:
    // 0x80031FA0: sh          $zero, 0x7A($a2)
    MEM_H(0X7A, ctx->r6) = 0;
L_80031FA4:
    // 0x80031FA4: sb          $t8, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r24;
    // 0x80031FA8: jal         0x80032464
    // 0x80031FAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    light_update(rdram, ctx);
        goto after_1;
    // 0x80031FAC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x80031FB0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80031FB4: nop

L_80031FB8:
    // 0x80031FB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80031FBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80031FC0: jr          $ra
    // 0x80031FC4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x80031FC4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void func_80087F14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008838C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80088390: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80088394: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80088398: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8008839C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800883A0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800883A4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800883A8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800883AC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800883B0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800883B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800883B8: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800883BC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800883C0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800883C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800883C8: sw          $a0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r4;
    // 0x800883CC: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x800883D0: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x800883D4: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800883D8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800883DC: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800883E0: addiu       $s4, $s4, 0x6FFC
    ctx->r20 = ADD32(ctx->r20, 0X6FFC);
    // 0x800883E4: addiu       $s3, $s3, 0x6FF8
    ctx->r19 = ADD32(ctx->r19, 0X6FF8);
    // 0x800883E8: addiu       $s2, $s2, 0x6FF4
    ctx->r18 = ADD32(ctx->r18, 0X6FF4);
    // 0x800883EC: addiu       $s0, $s0, 0x6FF0
    ctx->r16 = ADD32(ctx->r16, 0X6FF0);
    // 0x800883F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800883F4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_800883F8:
    // 0x800883F8: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
    // 0x800883FC: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
    // 0x80088400: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
    // 0x80088404: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80088408: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8008840C: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    // 0x80088410: jal         0x800763EC
    // 0x80088414: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x80088414: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_0:
    // 0x80088418: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x8008841C: bne         $v0, $zero, L_80088468
    if (ctx->r2 != 0) {
        // 0x80088420: andi        $t2, $v0, 0xFF
        ctx->r10 = ctx->r2 & 0XFF;
            goto L_80088468;
    }
    // 0x80088420: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80088424: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80088428: sb          $s5, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r21;
    // 0x8008842C: beq         $t6, $zero, L_80088444
    if (ctx->r14 == 0) {
        // 0x80088430: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80088444;
    }
    // 0x80088430: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088434: lw          $t7, 0x70($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X70);
    // 0x80088438: nop

    // 0x8008843C: bne         $t7, $zero, L_80088460
    if (ctx->r15 != 0) {
        // 0x80088440: nop
    
            goto L_80088460;
    }
    // 0x80088440: nop

L_80088444:
    // 0x80088444: sb          $s5, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r21;
    // 0x80088448: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x8008844C: lbu         $t8, 0x7020($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X7020);
    // 0x80088450: nop

    // 0x80088454: bne         $t8, $zero, L_80088460
    if (ctx->r24 != 0) {
        // 0x80088458: nop
    
            goto L_80088460;
    }
    // 0x80088458: nop

    // 0x8008845C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80088460:
    // 0x80088460: b           L_800884B4
    // 0x80088464: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_800884B4;
    // 0x80088464: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_80088468:
    // 0x80088468: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008846C: bne         $t2, $at, L_8008847C
    if (ctx->r10 != ctx->r1) {
        // 0x80088470: sb          $zero, 0x0($s0)
        MEM_B(0X0, ctx->r16) = 0;
            goto L_8008847C;
    }
    // 0x80088470: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80088474: sb          $s5, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r21;
    // 0x80088478: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8008847C:
    // 0x8008847C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088480: bne         $t2, $at, L_800884A0
    if (ctx->r10 != ctx->r1) {
        // 0x80088484: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800884A0;
    }
    // 0x80088484: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80088488: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    // 0x8008848C: jal         0x80075F90
    // 0x80088490: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    repair_controller_pak(rdram, ctx);
        goto after_1;
    // 0x80088490: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_1:
    // 0x80088494: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x80088498: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x8008849C: nop

L_800884A0:
    // 0x800884A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800884A4: bne         $t2, $at, L_800884B4
    if (ctx->r10 != ctx->r1) {
        // 0x800884A8: nop
    
            goto L_800884B4;
    }
    // 0x800884A8: nop

    // 0x800884AC: sb          $s5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r21;
    // 0x800884B0: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
L_800884B4:
    // 0x800884B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800884B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800884BC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800884C0: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800884C4: blez        $s1, L_800883F8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800884C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800883F8;
    }
    // 0x800884C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800884CC: beq         $fp, $zero, L_800884EC
    if (ctx->r30 == 0) {
        // 0x800884D0: nop
    
            goto L_800884EC;
    }
    // 0x800884D0: nop

    // 0x800884D4: bne         $s6, $zero, L_800884EC
    if (ctx->r22 != 0) {
        // 0x800884D8: nop
    
            goto L_800884EC;
    }
    // 0x800884D8: nop

    // 0x800884DC: bne         $s7, $zero, L_800884EC
    if (ctx->r23 != 0) {
        // 0x800884E0: nop
    
            goto L_800884EC;
    }
    // 0x800884E0: nop

    // 0x800884E4: beq         $v1, $zero, L_800884F4
    if (ctx->r3 == 0) {
        // 0x800884E8: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_800884F4;
    }
    // 0x800884E8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
L_800884EC:
    // 0x800884EC: b           L_80088774
    // 0x800884F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80088774;
    // 0x800884F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800884F4:
    // 0x800884F4: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800884F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800884FC: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80088500: addiu       $a2, $a2, 0x70A0
    ctx->r6 = ADD32(ctx->r6, 0X70A0);
    // 0x80088504: bgez        $v0, L_80088544
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80088508: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80088544;
    }
    // 0x80088508: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8008850C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80088510: addiu       $t6, $t6, 0x6FF0
    ctx->r14 = ADD32(ctx->r14, 0X6FF0);
    // 0x80088514: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_80088518:
    // 0x80088518: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008851C: blez        $s1, L_8008852C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80088520: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8008852C;
    }
    // 0x80088520: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088524: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088528: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8008852C:
    // 0x8008852C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80088530: nop

    // 0x80088534: beq         $t7, $zero, L_80088518
    if (ctx->r15 == 0) {
        // 0x80088538: nop
    
            goto L_80088518;
    }
    // 0x80088538: nop

    // 0x8008853C: b           L_800885D0
    // 0x80088540: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_800885D0;
    // 0x80088540: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_80088544:
    // 0x80088544: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088548: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8008854C: lbu         $t8, 0x6FF0($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6FF0);
    // 0x80088550: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x80088554: beq         $t8, $zero, L_80088560
    if (ctx->r24 == 0) {
        // 0x80088558: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80088560;
    }
    // 0x80088558: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008855C: blez        $t9, L_80088594
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80088560: addiu       $t6, $t6, 0x6FF0
        ctx->r14 = ADD32(ctx->r14, 0X6FF0);
            goto L_80088594;
    }
L_80088560:
    // 0x80088560: addiu       $t6, $t6, 0x6FF0
    ctx->r14 = ADD32(ctx->r14, 0X6FF0);
    // 0x80088564: addu        $s0, $s1, $t6
    ctx->r16 = ADD32(ctx->r17, ctx->r14);
L_80088568:
    // 0x80088568: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008856C: blez        $s1, L_8008857C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80088570: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8008857C;
    }
    // 0x80088570: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80088574: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80088578: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_8008857C:
    // 0x8008857C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x80088580: nop

    // 0x80088584: beq         $t7, $zero, L_80088568
    if (ctx->r15 == 0) {
        // 0x80088588: nop
    
            goto L_80088568;
    }
    // 0x80088588: nop

    // 0x8008858C: b           L_800885D0
    // 0x80088590: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
        goto L_800885D0;
    // 0x80088590: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_80088594:
    // 0x80088594: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
    // 0x80088598: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008859C: bgez        $t8, L_800885CC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800885A0: addiu       $t9, $t9, 0x6FF0
        ctx->r25 = ADD32(ctx->r25, 0X6FF0);
            goto L_800885CC;
    }
    // 0x800885A0: addiu       $t9, $t9, 0x6FF0
    ctx->r25 = ADD32(ctx->r25, 0X6FF0);
    // 0x800885A4: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
L_800885A8:
    // 0x800885A8: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800885AC: bgez        $s1, L_800885BC
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800885B0: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800885BC;
    }
    // 0x800885B0: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800885B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800885B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800885BC:
    // 0x800885BC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800885C0: nop

    // 0x800885C4: beq         $t6, $zero, L_800885A8
    if (ctx->r14 == 0) {
        // 0x800885C8: nop
    
            goto L_800885A8;
    }
    // 0x800885C8: nop

L_800885CC:
    // 0x800885CC: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
L_800885D0:
    // 0x800885D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800885D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800885D8: addiu       $t9, $t9, 0x7120
    ctx->r25 = ADD32(ctx->r25, 0X7120);
    // 0x800885DC: addiu       $t8, $t8, 0x7130
    ctx->r24 = ADD32(ctx->r24, 0X7130);
    // 0x800885E0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800885E4: sw          $s1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r17;
    // 0x800885E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800885EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800885F0: addiu       $a3, $a3, 0x70E0
    ctx->r7 = ADD32(ctx->r7, 0X70E0);
    // 0x800885F4: jal         0x800760B8
    // 0x800885F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    get_controller_pak_file_list(rdram, ctx);
        goto after_2;
    // 0x800885F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800885FC: bne         $v0, $zero, L_80088770
    if (ctx->r2 != 0) {
        // 0x80088600: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80088770;
    }
    // 0x80088600: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80088604: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80088608: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008860C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80088610: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80088614: addiu       $ra, $ra, 0x70A0
    ctx->r31 = ADD32(ctx->r31, 0X70A0);
    // 0x80088618: addiu       $a1, $a1, 0x7060
    ctx->r5 = ADD32(ctx->r5, 0X7060);
    // 0x8008861C: addiu       $t0, $t0, 0x70A0
    ctx->r8 = ADD32(ctx->r8, 0X70A0);
    // 0x80088620: addiu       $t1, $t1, 0x7130
    ctx->r9 = ADD32(ctx->r9, 0X7130);
    // 0x80088624: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80088628: addiu       $t5, $zero, 0x2D
    ctx->r13 = ADD32(0, 0X2D);
    // 0x8008862C: addiu       $t4, $zero, 0x2E
    ctx->r12 = ADD32(0, 0X2E);
L_80088630:
    // 0x80088630: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80088634: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x80088638: srl         $t7, $t6, 8
    ctx->r15 = S32(U32(ctx->r14) >> 8);
    // 0x8008863C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80088640: beq         $a3, $zero, L_80088704
    if (ctx->r7 == 0) {
        // 0x80088644: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80088704;
    }
    // 0x80088644: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80088648: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x8008864C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80088650: addiu       $t8, $t8, 0x70E0
    ctx->r24 = ADD32(ctx->r24, 0X70E0);
    // 0x80088654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80088658: beq         $t9, $zero, L_80088690
    if (ctx->r25 == 0) {
        // 0x8008865C: addu        $a2, $t3, $t8
        ctx->r6 = ADD32(ctx->r11, ctx->r24);
            goto L_80088690;
    }
    // 0x8008865C: addu        $a2, $t3, $t8
    ctx->r6 = ADD32(ctx->r11, ctx->r24);
    // 0x80088660: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_80088664:
    // 0x80088664: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088668: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008866C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80088670: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x80088674: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80088678: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008867C: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x80088680: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80088684: nop

    // 0x80088688: bne         $v1, $zero, L_80088664
    if (ctx->r3 != 0) {
        // 0x8008868C: nop
    
            goto L_80088664;
    }
    // 0x8008868C: nop

L_80088690:
    // 0x80088690: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80088694: nop

    // 0x80088698: beq         $a3, $zero, L_80088704
    if (ctx->r7 == 0) {
        // 0x8008869C: nop
    
            goto L_80088704;
    }
    // 0x8008869C: nop

    // 0x800886A0: lbu         $t6, 0x0($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X0);
    // 0x800886A4: nop

    // 0x800886A8: beq         $t6, $zero, L_80088704
    if (ctx->r14 == 0) {
        // 0x800886AC: nop
    
            goto L_80088704;
    }
    // 0x800886AC: nop

    // 0x800886B0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800886B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800886B8: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800886BC: sb          $t4, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r12;
    // 0x800886C0: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x800886C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800886C8: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800886CC: nop

    // 0x800886D0: beq         $t9, $zero, L_80088704
    if (ctx->r25 == 0) {
        // 0x800886D4: andi        $v1, $t9, 0xFF
        ctx->r3 = ctx->r25 & 0XFF;
            goto L_80088704;
    }
    // 0x800886D4: andi        $v1, $t9, 0xFF
    ctx->r3 = ctx->r25 & 0XFF;
L_800886D8:
    // 0x800886D8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800886DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800886E0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800886E4: sb          $v1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r3;
    // 0x800886E8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800886EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800886F0: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800886F4: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800886F8: nop

    // 0x800886FC: bne         $v1, $zero, L_800886D8
    if (ctx->r3 != 0) {
        // 0x80088700: nop
    
            goto L_800886D8;
    }
    // 0x80088700: nop

L_80088704:
    // 0x80088704: bne         $a0, $zero, L_80088720
    if (ctx->r4 != 0) {
        // 0x80088708: addiu       $t3, $t3, 0x4
        ctx->r11 = ADD32(ctx->r11, 0X4);
            goto L_80088720;
    }
    // 0x80088708: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8008870C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80088710: nop

    // 0x80088714: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80088718: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x8008871C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80088720:
    // 0x80088720: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80088724: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80088728: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8008872C: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80088730: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80088734: bne         $a1, $ra, L_80088630
    if (ctx->r5 != ctx->r31) {
        // 0x80088738: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_80088630;
    }
    // 0x80088738: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8008873C: jal         0x800763BC
    // 0x80088740: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    cpak_free_files(rdram, ctx);
        goto after_3;
    // 0x80088740: sw          $t2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r10;
    after_3:
    // 0x80088744: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80088748: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008874C: addiu       $s0, $s0, 0x7170
    ctx->r16 = ADD32(ctx->r16, 0X7170);
    // 0x80088750: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x80088754: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80088758: jal         0x800763EC
    // 0x8008875C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_free_space(rdram, ctx);
        goto after_4;
    // 0x8008875C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80088760: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80088764: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x80088768: srl         $t8, $t7, 8
    ctx->r24 = S32(U32(ctx->r15) >> 8);
    // 0x8008876C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_80088770:
    // 0x80088770: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80088774:
    // 0x80088774: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80088778: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8008877C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80088780: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80088784: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80088788: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8008878C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80088790: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80088794: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80088798: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8008879C: jr          $ra
    // 0x800887A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800887A0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void _loadOutputBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80064464: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80064468: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006446C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80064470: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80064474: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80064478: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8006447C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80064480: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x80064484: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80064488: beq         $t6, $zero, L_80064694
    if (ctx->r14 == 0) {
        // 0x8006448C: or          $s2, $a3, $zero
        ctx->r18 = ctx->r7 | 0;
            goto L_80064694;
    }
    // 0x8006448C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80064490: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80064494: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80064498: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006449C: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800644A0: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x800644A4: jal         0x80064AC4
    // 0x800644A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    _doModFunc(rdram, ctx);
        goto after_0;
    // 0x800644A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x800644AC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800644B0: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800644B4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800644B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800644BC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800644C0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800644C4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800644C8: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800644CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800644D0: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x800644D4: addiu       $a2, $zero, 0x280
    ctx->r6 = ADD32(0, 0X280);
    // 0x800644D8: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800644DC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800644E0: nop

    // 0x800644E4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800644E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800644EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800644F0: nop

    // 0x800644F4: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800644F8: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800644FC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80064500: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x80064504: nop

    // 0x80064508: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006450C: nop

    // 0x80064510: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80064514: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x80064518: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8006451C: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x80064520: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80064524: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80064528: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8006452C: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80064530: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80064534: nop

    // 0x80064538: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006453C: nop

    // 0x80064540: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80064544: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80064548: nop

    // 0x8006454C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80064550: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064558: nop

    // 0x8006455C: cvt.w.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80064560: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x80064564: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80064568: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x8006456C: nop

    // 0x80064570: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80064574: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x80064578: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8006457C: lw          $t7, 0x18($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X18);
    // 0x80064580: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x80064584: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x80064588: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8006458C: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80064590: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80064594: addu        $s1, $t3, $t2
    ctx->r17 = ADD32(ctx->r11, ctx->r10);
    // 0x80064598: andi        $v1, $s1, 0x7
    ctx->r3 = ctx->r17 & 0X7;
    // 0x8006459C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800645A0: sra         $t4, $v1, 1
    ctx->r12 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800645A4: sll         $t1, $t4, 1
    ctx->r9 = S32(ctx->r12 << 1);
    // 0x800645A8: subu        $a1, $s1, $t1
    ctx->r5 = SUB32(ctx->r17, ctx->r9);
    // 0x800645AC: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x800645B0: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
    // 0x800645B4: addu        $a3, $t0, $t4
    ctx->r7 = ADD32(ctx->r8, ctx->r12);
    // 0x800645B8: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800645BC: jal         0x800646E0
    // 0x800645C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    _loadBuffer(rdram, ctx);
        goto after_1;
    // 0x800645C0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_1:
    // 0x800645C4: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x800645C8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800645CC: addiu       $t6, $t1, 0x280
    ctx->r14 = ADD32(ctx->r9, 0X280);
    // 0x800645D0: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800645D4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800645D8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800645DC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x800645E0: sll         $t4, $s2, 1
    ctx->r12 = S32(ctx->r18 << 1);
    // 0x800645E4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800645E8: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800645EC: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x800645F0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800645F4: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800645F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800645FC: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80064600: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80064604: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x80064608: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8006460C: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x80064610: addiu       $s1, $v0, 0x10
    ctx->r17 = ADD32(ctx->r2, 0X10);
    // 0x80064614: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80064618: lw          $t2, 0x24($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X24);
    // 0x8006461C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80064620: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80064624: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80064628: andi        $t5, $t2, 0xFF
    ctx->r13 = ctx->r10 & 0XFF;
    // 0x8006462C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80064630: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80064634: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80064638: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8006463C: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80064640: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80064644: andi        $t3, $t9, 0xFFFF
    ctx->r11 = ctx->r25 & 0XFFFF;
    // 0x80064648: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8006464C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80064650: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80064654: nop

    // 0x80064658: lw          $a0, 0x14($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X14);
    // 0x8006465C: jal         0x800C9250
    // 0x80064660: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80064660: nop

    after_2:
    // 0x80064664: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80064668: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8006466C: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80064670: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x80064674: nop

    // 0x80064678: sw          $zero, 0x24($t2)
    MEM_W(0X24, ctx->r10) = 0;
    // 0x8006467C: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x80064680: nop

    // 0x80064684: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x80064688: subu        $t7, $t6, $s2
    ctx->r15 = SUB32(ctx->r14, ctx->r18);
    // 0x8006468C: b           L_800646C4
    // 0x80064690: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
        goto L_800646C4;
    // 0x80064690: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
L_80064694:
    // 0x80064694: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80064698: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8006469C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800646A0: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x800646A4: negu        $t4, $t9
    ctx->r12 = SUB32(0, ctx->r25);
    // 0x800646A8: sll         $t2, $t4, 1
    ctx->r10 = S32(ctx->r12 << 1);
    // 0x800646AC: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x800646B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800646B4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800646B8: jal         0x800646E0
    // 0x800646BC: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    _loadBuffer(rdram, ctx);
        goto after_3;
    // 0x800646BC: addu        $a1, $t8, $t2
    ctx->r5 = ADD32(ctx->r24, ctx->r10);
    after_3:
    // 0x800646C0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800646C4:
    // 0x800646C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800646C8: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800646CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800646D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800646D4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800646D8: jr          $ra
    // 0x800646DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800646DC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void obj_init_animation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037A58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80037A5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80037A60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80037A64: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80037A68: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x80037A6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80037A70: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80037A74: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80037A78: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80037A7C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80037A80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80037A84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80037A88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037A8C: bc1f        L_80037A98
    if (!c1cs) {
        // 0x80037A90: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80037A98;
    }
    // 0x80037A90: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80037A94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80037A98:
    // 0x80037A98: nop

    // 0x80037A9C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80037AA0: lw          $t8, 0x40($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X40);
    // 0x80037AA4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037AA8: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80037AAC: nop

    // 0x80037AB0: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80037AB4: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x80037AB8: lbu         $t9, 0xA($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0XA);
    // 0x80037ABC: nop

    // 0x80037AC0: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x80037AC4: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80037AC8: lbu         $t1, 0x9($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X9);
    // 0x80037ACC: nop

    // 0x80037AD0: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x80037AD4: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x80037AD8: lbu         $t3, 0x8($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X8);
    // 0x80037ADC: nop

    // 0x80037AE0: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80037AE4: sh          $t4, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r12;
    // 0x80037AE8: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037AEC: nop

    // 0x80037AF0: bne         $a0, $at, L_80037B0C
    if (ctx->r4 != ctx->r1) {
        // 0x80037AF4: nop
    
            goto L_80037B0C;
    }
    // 0x80037AF4: nop

    // 0x80037AF8: jal         0x8001F3EC
    // 0x80037AFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3B8(rdram, ctx);
        goto after_0;
    // 0x80037AFC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80037B00: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B04: b           L_80037B38
    // 0x80037B08: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
        goto L_80037B38;
    // 0x80037B08: sb          $v0, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r2;
L_80037B0C:
    // 0x80037B0C: bgez        $a0, L_80037B28
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80037B10: slti        $at, $a0, -0x2
        ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
            goto L_80037B28;
    }
    // 0x80037B10: slti        $at, $a0, -0x2
    ctx->r1 = SIGNED(ctx->r4) < -0X2 ? 1 : 0;
    // 0x80037B14: bne         $at, $zero, L_80037B28
    if (ctx->r1 != 0) {
        // 0x80037B18: nop
    
            goto L_80037B28;
    }
    // 0x80037B18: nop

    // 0x80037B1C: sb          $zero, 0x10($a3)
    MEM_B(0X10, ctx->r7) = 0;
    // 0x80037B20: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037B24: nop

L_80037B28:
    // 0x80037B28: jal         0x8001F3FC
    // 0x80037B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3C8(rdram, ctx);
        goto after_1;
    // 0x80037B2C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80037B30: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B34: nop

L_80037B38:
    // 0x80037B38: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037B3C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037B40: bne         $v1, $at, L_80037B68
    if (ctx->r3 != ctx->r1) {
        // 0x80037B44: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80037B68;
    }
    // 0x80037B44: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037B48: jal         0x8001E474
    // 0x80037B4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_2;
    // 0x80037B4C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80037B50: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B54: nop

    // 0x80037B58: sb          $v0, 0x21($a3)
    MEM_B(0X21, ctx->r7) = ctx->r2;
    // 0x80037B5C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037B60: nop

    // 0x80037B64: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
L_80037B68:
    // 0x80037B68: bne         $v1, $at, L_80037B80
    if (ctx->r3 != ctx->r1) {
        // 0x80037B6C: nop
    
            goto L_80037B80;
    }
    // 0x80037B6C: nop

    // 0x80037B70: lb          $t5, 0x10($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X10);
    // 0x80037B74: nop

    // 0x80037B78: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80037B7C: sb          $t6, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r14;
L_80037B80:
    // 0x80037B80: lb          $a0, 0x10($a3)
    ctx->r4 = MEM_B(ctx->r7, 0X10);
    // 0x80037B84: jal         0x8001F420
    // 0x80037B88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F3EC(rdram, ctx);
        goto after_3;
    // 0x80037B88: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_3:
    // 0x80037B8C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037B90: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80037B94: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037B98: nop

    // 0x80037B9C: bne         $v1, $at, L_80037BC0
    if (ctx->r3 != ctx->r1) {
        // 0x80037BA0: nop
    
            goto L_80037BC0;
    }
    // 0x80037BA0: nop

    // 0x80037BA4: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037BA8: lb          $t7, 0x11($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X11);
    // 0x80037BAC: nop

    // 0x80037BB0: bgez        $t7, L_80037BE8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80037BB4: nop
    
            goto L_80037BE8;
    }
    // 0x80037BB4: nop

    // 0x80037BB8: b           L_80037BE8
    // 0x80037BBC: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
        goto L_80037BE8;
    // 0x80037BBC: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037BC0:
    // 0x80037BC0: bltz        $v0, L_80037BDC
    if (SIGNED(ctx->r2) < 0) {
        // 0x80037BC4: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80037BDC;
    }
    // 0x80037BC4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80037BC8: bne         $at, $zero, L_80037BDC
    if (ctx->r1 != 0) {
        // 0x80037BCC: nop
    
            goto L_80037BDC;
    }
    // 0x80037BCC: nop

    // 0x80037BD0: sb          $v0, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r2;
    // 0x80037BD4: lb          $v1, 0x11($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X11);
    // 0x80037BD8: nop

L_80037BDC:
    // 0x80037BDC: bgez        $v1, L_80037BE8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037BE0: nop
    
            goto L_80037BE8;
    }
    // 0x80037BE0: nop

    // 0x80037BE4: sb          $zero, 0x11($a3)
    MEM_B(0X11, ctx->r7) = 0;
L_80037BE8:
    // 0x80037BE8: jal         0x80011390
    // 0x80037BEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    path_enable(rdram, ctx);
        goto after_4;
    // 0x80037BEC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x80037BF0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037BF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80037BF8: lb          $t8, 0x10($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X10);
    // 0x80037BFC: nop

    // 0x80037C00: sw          $t8, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r24;
    // 0x80037C04: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80037C08: nop

    // 0x80037C0C: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80037C10: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80037C14: nop

    // 0x80037C18: beq         $t0, $zero, L_80037C3C
    if (ctx->r8 == 0) {
        // 0x80037C1C: nop
    
            goto L_80037C3C;
    }
    // 0x80037C1C: nop

    // 0x80037C20: jal         0x8006A794
    // 0x80037C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    input_pressed(rdram, ctx);
        goto after_5;
    // 0x80037C24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_5:
    // 0x80037C28: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C2C: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80037C30: beq         $t1, $zero, L_80037C3C
    if (ctx->r9 == 0) {
        // 0x80037C34: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80037C3C;
    }
    // 0x80037C34: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80037C38: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
L_80037C3C:
    // 0x80037C3C: jal         0x8001E474
    // 0x80037C40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x80037C40: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_6:
    // 0x80037C44: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037C48: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x80037C4C: lb          $v1, 0x21($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X21);
    // 0x80037C50: nop

    // 0x80037C54: beq         $v0, $v1, L_80037C64
    if (ctx->r2 == ctx->r3) {
        // 0x80037C58: nop
    
            goto L_80037C64;
    }
    // 0x80037C58: nop

    // 0x80037C5C: bne         $v1, $at, L_80037CA8
    if (ctx->r3 != ctx->r1) {
        // 0x80037C60: nop
    
            goto L_80037CA8;
    }
    // 0x80037C60: nop

L_80037C64:
    // 0x80037C64: lw          $t3, 0x64($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X64);
    // 0x80037C68: nop

    // 0x80037C6C: bne         $t3, $zero, L_80037CA8
    if (ctx->r11 != 0) {
        // 0x80037C70: nop
    
            goto L_80037CA8;
    }
    // 0x80037C70: nop

    // 0x80037C74: lb          $t4, 0x11($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X11);
    // 0x80037C78: nop

    // 0x80037C7C: bne         $t4, $zero, L_80037CA8
    if (ctx->r12 != 0) {
        // 0x80037C80: nop
    
            goto L_80037CA8;
    }
    // 0x80037C80: nop

    // 0x80037C84: lh          $t5, 0xC($a3)
    ctx->r13 = MEM_H(ctx->r7, 0XC);
    // 0x80037C88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037C8C: beq         $t5, $at, L_80037CA8
    if (ctx->r13 == ctx->r1) {
        // 0x80037C90: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80037CA8;
    }
    // 0x80037C90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037C94: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80037C98: jal         0x8001F270
    // 0x80037C9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_8001F23C(rdram, ctx);
        goto after_7;
    // 0x80037C9C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_7:
    // 0x80037CA0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037CA4: nop

L_80037CA8:
    // 0x80037CA8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80037CAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80037CB0: beq         $v0, $zero, L_80037CFC
    if (ctx->r2 == 0) {
        // 0x80037CB4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80037CFC;
    }
    // 0x80037CB4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80037CB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80037CBC: jal         0x8001EFD8
    // 0x80037CC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    obj_init_animobject(rdram, ctx);
        goto after_8;
    // 0x80037CC0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_8:
    // 0x80037CC4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80037CC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037CCC: lb          $t6, 0x11($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X11);
    // 0x80037CD0: nop

    // 0x80037CD4: bne         $t6, $zero, L_80037CF0
    if (ctx->r14 != 0) {
        // 0x80037CD8: nop
    
            goto L_80037CF0;
    }
    // 0x80037CD8: nop

    // 0x80037CDC: lh          $t7, 0xC($a3)
    ctx->r15 = MEM_H(ctx->r7, 0XC);
    // 0x80037CE0: lh          $t8, 0x4A($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X4A);
    // 0x80037CE4: nop

    // 0x80037CE8: beq         $t7, $t8, L_80037CFC
    if (ctx->r15 == ctx->r24) {
        // 0x80037CEC: nop
    
            goto L_80037CFC;
    }
    // 0x80037CEC: nop

L_80037CF0:
    // 0x80037CF0: jal         0x8000FFB8
    // 0x80037CF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    free_object(rdram, ctx);
        goto after_9;
    // 0x80037CF4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_9:
    // 0x80037CF8: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_80037CFC:
    // 0x80037CFC: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x80037D00: jal         0x80021634
    // 0x80037D04: nop

    func_80021600(rdram, ctx);
        goto after_10;
    // 0x80037D04: nop

    after_10:
    // 0x80037D08: beq         $v0, $zero, L_80037D1C
    if (ctx->r2 == 0) {
        // 0x80037D0C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80037D1C;
    }
    // 0x80037D0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80037D10: jal         0x8001EEA8
    // 0x80037D14: nop

    func_8001EE74(rdram, ctx);
        goto after_11;
    // 0x80037D14: nop

    after_11:
    // 0x80037D18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80037D1C:
    // 0x80037D1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80037D20: jr          $ra
    // 0x80037D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80037D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void menu_number_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082054: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80082058: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008205C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80082060: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80082064: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80082068: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008206C: lui         $s0, 0x3B9A
    ctx->r16 = S32(0X3B9A << 16);
    // 0x80082070: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80082074: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80082078: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008207C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80082080: ori         $s0, $s0, 0xCA00
    ctx->r16 = ctx->r16 | 0XCA00;
    // 0x80082084: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80082088: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8008208C: addiu       $v1, $sp, 0x38
    ctx->r3 = ADD32(ctx->r29, 0X38);
    // 0x80082090: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
L_80082094:
    // 0x80082094: bne         $at, $zero, L_800820F0
    if (ctx->r1 != 0) {
        // 0x80082098: nop
    
            goto L_800820F0;
    }
    // 0x80082098: nop

    // 0x8008209C: div         $zero, $s1, $s0
    lo = S32(S64(S32(ctx->r17)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r17)) % S64(S32(ctx->r16)));
    // 0x800820A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800820A4: bne         $s0, $zero, L_800820B0
    if (ctx->r16 != 0) {
        // 0x800820A8: nop
    
            goto L_800820B0;
    }
    // 0x800820A8: nop

    // 0x800820AC: break       7
    do_break(2148016300);
L_800820B0:
    // 0x800820B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800820B4: bne         $s0, $at, L_800820C8
    if (ctx->r16 != ctx->r1) {
        // 0x800820B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800820C8;
    }
    // 0x800820B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800820BC: bne         $s1, $at, L_800820C8
    if (ctx->r17 != ctx->r1) {
        // 0x800820C0: nop
    
            goto L_800820C8;
    }
    // 0x800820C0: nop

    // 0x800820C4: break       6
    do_break(2148016324);
L_800820C8:
    // 0x800820C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800820CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800820D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800820D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800820D8: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
    // 0x800820DC: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800820E0: mflo        $t6
    ctx->r14 = lo;
    // 0x800820E4: subu        $s1, $s1, $t6
    ctx->r17 = SUB32(ctx->r17, ctx->r14);
    // 0x800820E8: b           L_80082104
    // 0x800820EC: nop

        goto L_80082104;
    // 0x800820EC: nop

L_800820F0:
    // 0x800820F0: beq         $t0, $zero, L_80082104
    if (ctx->r8 == 0) {
        // 0x800820F4: nop
    
            goto L_80082104;
    }
    // 0x800820F4: nop

    // 0x800820F8: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800820FC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80082100: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80082104:
    // 0x80082104: div         $zero, $s0, $a1
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r5)));
    // 0x80082108: bne         $a1, $zero, L_80082114
    if (ctx->r5 != 0) {
        // 0x8008210C: nop
    
            goto L_80082114;
    }
    // 0x8008210C: nop

    // 0x80082110: break       7
    do_break(2148016400);
L_80082114:
    // 0x80082114: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80082118: bne         $a1, $at, L_8008212C
    if (ctx->r5 != ctx->r1) {
        // 0x8008211C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008212C;
    }
    // 0x8008211C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80082120: bne         $s0, $at, L_8008212C
    if (ctx->r16 != ctx->r1) {
        // 0x80082124: nop
    
            goto L_8008212C;
    }
    // 0x80082124: nop

    // 0x80082128: break       6
    do_break(2148016424);
L_8008212C:
    // 0x8008212C: mflo        $s0
    ctx->r16 = lo;
    // 0x80082130: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x80082134: beq         $at, $zero, L_80082094
    if (ctx->r1 == 0) {
        // 0x80082138: slt         $at, $s1, $s0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_80082094;
    }
    // 0x80082138: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8008213C: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x80082140: sb          $s1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r17;
    // 0x80082144: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x80082148: beq         $t7, $zero, L_80082168
    if (ctx->r15 == 0) {
        // 0x8008214C: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80082168;
    }
    // 0x8008214C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80082150: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80082154: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x80082158: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8008215C: subu        $s4, $s4, $t8
    ctx->r20 = SUB32(ctx->r20, ctx->r24);
    // 0x80082160: b           L_80082190
    // 0x80082164: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
        goto L_80082190;
    // 0x80082164: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80082168:
    // 0x80082168: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8008216C: beq         $t9, $zero, L_8008218C
    if (ctx->r25 == 0) {
        // 0x80082170: sll         $t1, $s3, 2
        ctx->r9 = S32(ctx->r19 << 2);
            goto L_8008218C;
    }
    // 0x80082170: sll         $t1, $s3, 2
    ctx->r9 = S32(ctx->r19 << 2);
    // 0x80082174: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80082178: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8008217C: subu        $t1, $t1, $s3
    ctx->r9 = SUB32(ctx->r9, ctx->r19);
    // 0x80082180: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x80082184: b           L_80082190
    // 0x80082188: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
        goto L_80082190;
    // 0x80082188: subu        $s4, $s4, $t2
    ctx->r20 = SUB32(ctx->r20, ctx->r10);
L_8008218C:
    // 0x8008218C: addiu       $s4, $s4, 0x6
    ctx->r20 = ADD32(ctx->r20, 0X6);
L_80082190:
    // 0x80082190: andi        $t3, $v0, 0x8
    ctx->r11 = ctx->r2 & 0X8;
    // 0x80082194: beq         $t3, $zero, L_800821A4
    if (ctx->r11 == 0) {
        // 0x80082198: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800821A4;
    }
    // 0x80082198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008219C: b           L_800821B4
    // 0x800821A0: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
        goto L_800821B4;
    // 0x800821A0: addiu       $a2, $a2, 0x7
    ctx->r6 = ADD32(ctx->r6, 0X7);
L_800821A4:
    // 0x800821A4: andi        $t4, $v0, 0x10
    ctx->r12 = ctx->r2 & 0X10;
    // 0x800821A8: beq         $t4, $zero, L_800821B8
    if (ctx->r12 == 0) {
        // 0x800821AC: lw          $t5, 0x70($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X70);
            goto L_800821B8;
    }
    // 0x800821AC: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800821B0: addiu       $a2, $a2, -0x7
    ctx->r6 = ADD32(ctx->r6, -0X7);
L_800821B4:
    // 0x800821B4: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
L_800821B8:
    // 0x800821B8: sb          $a3, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r7;
    // 0x800821BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821C0: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800821C4: sb          $t5, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r13;
    // 0x800821C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821CC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800821D0: sb          $t6, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r14;
    // 0x800821D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800821D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800821DC: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800821E0: jal         0x8007C36C
    // 0x800821E4: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x800821E4: sw          $t7, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r15;
    after_0:
    // 0x800821E8: jal         0x80068748
    // 0x800821EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800821EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800821F0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800821F4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800821F8: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800821FC: addiu       $s2, $s2, -0x324
    ctx->r18 = ADD32(ctx->r18, -0X324);
    // 0x80082200: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80082204: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80082208: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008220C: blez        $s3, L_8008224C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80082210: swc1        $f6, 0x10($t8)
        MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
            goto L_8008224C;
    }
    // 0x80082210: swc1        $f6, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f6.u32l;
    // 0x80082214: addiu       $s1, $sp, 0x38
    ctx->r17 = ADD32(ctx->r29, 0X38);
L_80082218:
    // 0x80082218: mtc1        $s4, $f8
    ctx->f8.u32l = ctx->r20;
    // 0x8008221C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80082220: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80082224: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082228: swc1        $f10, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f10.u32l;
    // 0x8008222C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80082230: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x80082234: jal         0x8009CFA4
    // 0x80082238: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    menu_element_render(rdram, ctx);
        goto after_2;
    // 0x80082238: sh          $t1, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r9;
    after_2:
    // 0x8008223C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80082240: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80082244: bne         $s0, $s3, L_80082218
    if (ctx->r16 != ctx->r19) {
        // 0x80082248: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_80082218;
    }
    // 0x80082248: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
L_8008224C:
    // 0x8008224C: jal         0x8007C36C
    // 0x80082250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_3;
    // 0x80082250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80082254: jal         0x80068748
    // 0x80082258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_4;
    // 0x80082258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8008225C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80082260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082264: sb          $v0, -0x5DC($at)
    MEM_B(-0X5DC, ctx->r1) = ctx->r2;
    // 0x80082268: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008226C: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x80082270: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082274: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80082278: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008227C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082280: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80082284: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80082288: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008228C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80082290: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80082294: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80082298: sw          $t3, -0x31C($at)
    MEM_W(-0X31C, ctx->r1) = ctx->r11;
    // 0x8008229C: jr          $ra
    // 0x800822A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800822A0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void obj_loop_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80035E78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80035E7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80035E80: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80035E84: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80035E88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80035E8C: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80035E90: jal         0x8001139C
    // 0x80035E94: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80035E94: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    after_0:
    // 0x80035E98: bne         $v0, $zero, L_80035EB4
    if (ctx->r2 != 0) {
        // 0x80035E9C: nop
    
            goto L_80035EB4;
    }
    // 0x80035E9C: nop

    // 0x80035EA0: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80035EA4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80035EA8: nop

    // 0x80035EAC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80035EB0: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
L_80035EB4:
    // 0x80035EB4: jal         0x80059E90
    // 0x80035EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    timetrial_ghost_read(rdram, ctx);
        goto after_1;
    // 0x80035EB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80035EBC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80035EC0: jal         0x800B019C
    // 0x80035EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_2;
    // 0x80035EC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80035EC8: jal         0x8001BAFC
    // 0x80035ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_3;
    // 0x80035ECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80035ED0: lw          $v1, 0x60($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X60);
    // 0x80035ED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80035ED8: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80035EDC: lw          $a0, 0x64($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X64);
    // 0x80035EE0: bne         $a1, $t0, L_80035F2C
    if (ctx->r5 != ctx->r8) {
        // 0x80035EE4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035F2C;
    }
    // 0x80035EE4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80035EE8: lb          $v0, 0x1D6($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1D6);
    // 0x80035EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80035EF0: beq         $v0, $a1, L_80035F00
    if (ctx->r2 == ctx->r5) {
        // 0x80035EF4: nop
    
            goto L_80035F00;
    }
    // 0x80035EF4: nop

    // 0x80035EF8: bne         $v0, $at, L_80035F2C
    if (ctx->r2 != ctx->r1) {
        // 0x80035EFC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80035F2C;
    }
    // 0x80035EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035F00:
    // 0x80035F00: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80035F04: addiu       $t1, $zero, 0x4000
    ctx->r9 = ADD32(0, 0X4000);
    // 0x80035F08: lb          $t2, 0x3A($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X3A);
    // 0x80035F0C: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80035F10: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80035F14: sb          $t3, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r11;
    // 0x80035F18: lb          $t4, 0x3A($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X3A);
    // 0x80035F1C: nop

    // 0x80035F20: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x80035F24: sb          $t5, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r13;
    // 0x80035F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80035F2C:
    // 0x80035F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035F30: jr          $ra
    // 0x80035F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80035F34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void bgdraw_texture_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800785C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785C4: sw          $a0, -0x15BC($at)
    MEM_W(-0X15BC, ctx->r1) = ctx->r4;
    // 0x800785C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785CC: sw          $a1, -0x15B8($at)
    MEM_W(-0X15B8, ctx->r1) = ctx->r5;
    // 0x800785D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800785D4: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800785D8: jr          $ra
    // 0x800785DC: sw          $t6, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r14;
    return;
    // 0x800785DC: sw          $t6, -0x15C0($at)
    MEM_W(-0X15C0, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void decrease_rocket_sound_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F11C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003F120: addiu       $v0, $v0, -0x25A4
    ctx->r2 = ADD32(ctx->r2, -0X25A4);
    // 0x8003F124: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8003F128: nop

    // 0x8003F12C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003F130: jr          $ra
    // 0x8003F134: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8003F134: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void savemenu_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086F3C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80086F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80086F44: jal         0x8006ECD0
    // 0x80086F48: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80086F48: nop

    after_0:
    // 0x80086F4C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086F50: lw          $t7, 0x7194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7194);
    // 0x80086F54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086F58: lw          $t6, 0x6FCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6FCC);
    // 0x80086F5C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086F60: addu        $a3, $t6, $t8
    ctx->r7 = ADD32(ctx->r14, ctx->r24);
    // 0x80086F64: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x80086F68: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80086F6C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80086F70: sltiu       $at, $t2, 0xA
    ctx->r1 = ctx->r10 < 0XA ? 1 : 0;
    // 0x80086F74: beq         $at, $zero, L_80087634
    if (ctx->r1 == 0) {
        // 0x80086F78: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_80087634;
    }
    // 0x80086F78: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80086F7C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086F80: addu        $at, $at, $t2
    gpr jr_addend_80086F8C = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80086F84: lw          $t2, -0x7658($at)
    ctx->r10 = ADD32(ctx->r1, -0X7658);
    // 0x80086F88: nop

    // 0x80086F8C: jr          $t2
    // 0x80086F90: nop

    switch (jr_addend_80086F8C >> 2) {
        case 0: goto L_80086F94; break;
        case 1: goto L_8008711C; break;
        case 2: goto L_800871BC; break;
        case 3: goto L_800873DC; break;
        case 4: goto L_800874F4; break;
        case 5: goto L_80087580; break;
        case 6: goto L_80087634; break;
        case 7: goto L_80087634; break;
        case 8: goto L_80087634; break;
        case 9: goto L_800875C8; break;
        default: switch_error(__func__, 0x80086F8C, 0x800E89A8);
    }
    // 0x80086F90: nop

L_80086F94:
    // 0x80086F94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086F98: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80086F9C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086FA0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80086FA4: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80086FA8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80086FAC: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086FB0: addu        $v1, $t3, $t5
    ctx->r3 = ADD32(ctx->r11, ctx->r13);
    // 0x80086FB4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80086FB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80086FBC: beq         $v0, $at, L_80086FDC
    if (ctx->r2 == ctx->r1) {
        // 0x80086FC0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086FDC;
    }
    // 0x80086FC0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086FC4: beq         $v0, $at, L_800870D4
    if (ctx->r2 == ctx->r1) {
        // 0x80086FC8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800870D4;
    }
    // 0x80086FC8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80086FCC: beq         $v0, $at, L_800870C0
    if (ctx->r2 == ctx->r1) {
        // 0x80086FD0: nop
    
            goto L_800870C0;
    }
    // 0x80086FD0: nop

    // 0x80086FD4: b           L_8008763C
    // 0x80086FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80086FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80086FDC:
    // 0x80086FDC: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x80086FE0: jal         0x8006EE58
    // 0x80086FE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_1;
    // 0x80086FE4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_1:
    // 0x80086FE8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80086FEC: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80086FF0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80086FF4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80086FF8: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80086FFC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087000: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80087004: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x80087008: lbu         $t4, 0x6($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X6);
    // 0x8008700C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087010: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087014: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087018: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x8008701C: addu        $t5, $v1, $t3
    ctx->r13 = ADD32(ctx->r3, ctx->r11);
    // 0x80087020: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x80087024: lw          $t7, 0x10($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X10);
    // 0x80087028: nop

    // 0x8008702C: sw          $t7, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->r15;
    // 0x80087030: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80087034: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087038: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x8008703C: addu        $t4, $t6, $t2
    ctx->r12 = ADD32(ctx->r14, ctx->r10);
    // 0x80087040: lbu         $t3, 0x6($t4)
    ctx->r11 = MEM_BU(ctx->r12, 0X6);
    // 0x80087044: nop

    // 0x80087048: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8008704C: addu        $t7, $v1, $t5
    ctx->r15 = ADD32(ctx->r3, ctx->r13);
    // 0x80087050: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80087054: nop

    // 0x80087058: sb          $zero, 0x4B($t8)
    MEM_B(0X4B, ctx->r24) = 0;
    // 0x8008705C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80087060: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80087064: sll         $t3, $t4, 4
    ctx->r11 = S32(ctx->r12 << 4);
    // 0x80087068: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x8008706C: lbu         $t7, 0x6($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X6);
    // 0x80087070: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80087074: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80087078: lh          $t6, 0x0($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X0);
    // 0x8008707C: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80087080: lw          $t4, 0x0($t9)
    ctx->r12 = MEM_W(ctx->r25, 0X0);
    // 0x80087084: nop

    // 0x80087088: lw          $t2, 0x0($t4)
    ctx->r10 = MEM_W(ctx->r12, 0X0);
    // 0x8008708C: nop

    // 0x80087090: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x80087094: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80087098: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8008709C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800870A0: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800870A4: lbu         $t4, 0x6($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X6);
    // 0x800870A8: lw          $t3, 0x50($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X50);
    // 0x800870AC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x800870B0: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x800870B4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800870B8: b           L_80087638
    // 0x800870BC: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
        goto L_80087638;
    // 0x800870BC: sw          $t3, 0x50($t7)
    MEM_W(0X50, ctx->r15) = ctx->r11;
L_800870C0:
    // 0x800870C0: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x800870C4: jal         0x800741B4
    // 0x800870C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_game_data_to_controller_pak(rdram, ctx);
        goto after_2;
    // 0x800870C8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_2:
    // 0x800870CC: b           L_80087638
    // 0x800870D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800870D0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800870D4:
    // 0x800870D4: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800870D8: jal         0x8006EEEC
    // 0x800870DC: nop

    mark_save_file_to_erase(rdram, ctx);
        goto after_3;
    // 0x800870DC: nop

    after_3:
    // 0x800870E0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800870E4: lw          $t9, 0x7194($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7194);
    // 0x800870E8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800870EC: lw          $t8, 0x6FCC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6FCC);
    // 0x800870F0: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800870F4: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x800870F8: lbu         $t2, 0x6($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X6);
    // 0x800870FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087100: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087104: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80087108: addu        $t7, $v1, $t3
    ctx->r15 = ADD32(ctx->r3, ctx->r11);
    // 0x8008710C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80087110: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80087114: b           L_80087638
    // 0x80087118: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
        goto L_80087638;
    // 0x80087118: sb          $t5, 0x4B($t9)
    MEM_B(0X4B, ctx->r25) = ctx->r13;
L_8008711C:
    // 0x8008711C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087120: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087124: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087128: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8008712C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087130: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80087134: sll         $t6, $t4, 4
    ctx->r14 = S32(ctx->r12 << 4);
    // 0x80087138: addu        $v1, $t8, $t6
    ctx->r3 = ADD32(ctx->r24, ctx->r14);
    // 0x8008713C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80087140: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087144: beq         $v0, $at, L_8008716C
    if (ctx->r2 == ctx->r1) {
        // 0x80087148: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_8008716C;
    }
    // 0x80087148: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8008714C: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087150: bne         $v0, $at, L_8008763C
    if (ctx->r2 != ctx->r1) {
        // 0x80087154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x80087154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087158: lbu         $a0, 0x6($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X6);
    // 0x8008715C: jal         0x800743A0
    // 0x80087160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_4;
    // 0x80087160: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
    // 0x80087164: b           L_80087638
    // 0x80087168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x80087168: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_8008716C:
    // 0x8008716C: jal         0x8006E9B0
    // 0x80087170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    clear_lap_records(rdram, ctx);
        goto after_5;
    // 0x80087170: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_5:
    // 0x80087174: jal         0x8006EE3C
    // 0x80087178: nop

    mark_to_write_flap_and_course_times(rdram, ctx);
        goto after_6;
    // 0x80087178: nop

    after_6:
    // 0x8008717C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80087180: ori         $a1, $a1, 0xFFF0
    ctx->r5 = ctx->r5 | 0XFFF0;
    // 0x80087184: jal         0x8009F000
    // 0x80087188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    unset_eeprom_settings_value(rdram, ctx);
        goto after_7;
    // 0x80087188: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    after_7:
    // 0x8008718C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80087190: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80087194: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x80087198: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x8008719C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800871A0: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800871A4: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x800871A8: and         $t3, $t2, $a0
    ctx->r11 = ctx->r10 & ctx->r4;
    // 0x800871AC: and         $t5, $t7, $a0
    ctx->r13 = ctx->r15 & ctx->r4;
    // 0x800871B0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800871B4: b           L_80087638
    // 0x800871B8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80087638;
    // 0x800871B8: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800871BC:
    // 0x800871BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800871C0: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800871C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800871C8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800871CC: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800871D0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800871D4: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x800871D8: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800871DC: lbu         $v0, 0x0($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X0);
    // 0x800871E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800871E4: beq         $v0, $at, L_80087204
    if (ctx->r2 == ctx->r1) {
        // 0x800871E8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087204;
    }
    // 0x800871E8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800871EC: beq         $v0, $at, L_800873C4
    if (ctx->r2 == ctx->r1) {
        // 0x800871F0: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800873C4;
    }
    // 0x800871F0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800871F4: beq         $v0, $at, L_80087364
    if (ctx->r2 == ctx->r1) {
        // 0x800871F8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80087364;
    }
    // 0x800871F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800871FC: b           L_8008763C
    // 0x80087200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087200: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087204:
    // 0x80087204: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087208: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x8008720C: jal         0x80074074
    // 0x80087210: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_game_data_from_controller_pak(rdram, ctx);
        goto after_8;
    // 0x80087210: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_8:
    // 0x80087214: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087218: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008721C: lw          $t2, 0x10($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X10);
    // 0x80087220: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087224: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087228: andi        $t3, $t2, 0x4
    ctx->r11 = ctx->r10 & 0X4;
    // 0x8008722C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087230: beq         $t3, $zero, L_80087260
    if (ctx->r11 == 0) {
        // 0x80087234: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087260;
    }
    // 0x80087234: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087238: jal         0x8009F1A4
    // 0x8008723C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    is_adventure_two_unlocked(rdram, ctx);
        goto after_9;
    // 0x8008723C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_9:
    // 0x80087240: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087244: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087248: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008724C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087250: bne         $v0, $zero, L_80087260
    if (ctx->r2 != 0) {
        // 0x80087254: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087260;
    }
    // 0x80087254: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087258: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8008725C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
L_80087260:
    // 0x80087260: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80087264: nop

    // 0x80087268: bne         $t5, $zero, L_8008763C
    if (ctx->r13 != 0) {
        // 0x8008726C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x8008726C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087270: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80087274: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80087278: sll         $t8, $t9, 4
    ctx->r24 = S32(ctx->r25 << 4);
    // 0x8008727C: addu        $t6, $t4, $t8
    ctx->r14 = ADD32(ctx->r12, ctx->r24);
    // 0x80087280: lbu         $a0, 0x6($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X6);
    // 0x80087284: jal         0x8006EE58
    // 0x80087288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    force_mark_write_save_file(rdram, ctx);
        goto after_10;
    // 0x80087288: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_10:
    // 0x8008728C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087290: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087298: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8008729C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800872A0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800872A4: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x800872A8: addu        $t9, $t3, $t5
    ctx->r25 = ADD32(ctx->r11, ctx->r13);
    // 0x800872AC: lbu         $t4, 0x6($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X6);
    // 0x800872B0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800872B4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800872B8: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x800872BC: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x800872C0: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800872C4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800872C8: lw          $t2, 0x10($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X10);
    // 0x800872CC: nop

    // 0x800872D0: sw          $t2, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->r10;
    // 0x800872D4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800872D8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800872DC: sll         $t9, $t5, 4
    ctx->r25 = S32(ctx->r13 << 4);
    // 0x800872E0: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x800872E4: lbu         $t8, 0x6($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X6);
    // 0x800872E8: nop

    // 0x800872EC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800872F0: addu        $t2, $v1, $t6
    ctx->r10 = ADD32(ctx->r3, ctx->r14);
    // 0x800872F4: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800872F8: nop

    // 0x800872FC: sb          $zero, 0x4B($t7)
    MEM_B(0X4B, ctx->r15) = 0;
    // 0x80087300: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80087304: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80087308: sll         $t8, $t4, 4
    ctx->r24 = S32(ctx->r12 << 4);
    // 0x8008730C: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x80087310: lbu         $t2, 0x6($t6)
    ctx->r10 = MEM_BU(ctx->r14, 0X6);
    // 0x80087314: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80087318: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8008731C: lh          $t3, 0x0($t5)
    ctx->r11 = MEM_H(ctx->r13, 0X0);
    // 0x80087320: addu        $t5, $v1, $t7
    ctx->r13 = ADD32(ctx->r3, ctx->r15);
    // 0x80087324: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x80087328: nop

    // 0x8008732C: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80087330: nop

    // 0x80087334: sh          $t3, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r11;
    // 0x80087338: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8008733C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087340: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x80087344: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x80087348: lbu         $t4, 0x6($t5)
    ctx->r12 = MEM_BU(ctx->r13, 0X6);
    // 0x8008734C: lw          $t8, 0x50($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X50);
    // 0x80087350: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x80087354: addu        $t9, $v1, $t3
    ctx->r25 = ADD32(ctx->r3, ctx->r11);
    // 0x80087358: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8008735C: b           L_80087638
    // 0x80087360: sw          $t8, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r24;
        goto L_80087638;
    // 0x80087360: sw          $t8, 0x50($t2)
    MEM_W(0X50, ctx->r10) = ctx->r24;
L_80087364:
    // 0x80087364: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087368: lw          $a2, 0xC($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XC);
    // 0x8008736C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087370: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x80087374: jal         0x80074074
    // 0x80087378: nop

    read_game_data_from_controller_pak(rdram, ctx);
        goto after_11;
    // 0x80087378: nop

    after_11:
    // 0x8008737C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087380: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087384: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087388: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x8008738C: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087390: addiu       $v1, $v1, 0x6AD0
    ctx->r3 = ADD32(ctx->r3, 0X6AD0);
    // 0x80087394: bne         $v0, $zero, L_80087638
    if (ctx->r2 != 0) {
        // 0x80087398: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_80087638;
    }
    // 0x80087398: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8008739C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800873A0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800873A4: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x800873A8: addu        $t4, $t6, $t5
    ctx->r12 = ADD32(ctx->r14, ctx->r13);
    // 0x800873AC: lbu         $a0, 0x6($t4)
    ctx->r4 = MEM_BU(ctx->r12, 0X6);
    // 0x800873B0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x800873B4: jal         0x800741B4
    // 0x800873B8: nop

    write_game_data_to_controller_pak(rdram, ctx);
        goto after_12;
    // 0x800873B8: nop

    after_12:
    // 0x800873BC: b           L_80087638
    // 0x800873C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800873C0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800873C4:
    // 0x800873C4: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800873C8: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800873CC: jal         0x80076520
    // 0x800873D0: nop

    delete_file(rdram, ctx);
        goto after_13;
    // 0x800873D0: nop

    after_13:
    // 0x800873D4: b           L_80087638
    // 0x800873D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800873D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800873DC:
    // 0x800873DC: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800873E0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800873E4: lbu         $t3, 0x0($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X0);
    // 0x800873E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800873EC: beq         $t3, $zero, L_80087408
    if (ctx->r11 == 0) {
        // 0x800873F0: addiu       $t0, $t0, 0x6FC4
        ctx->r8 = ADD32(ctx->r8, 0X6FC4);
            goto L_80087408;
    }
    // 0x800873F0: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800873F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800873F8:
    // 0x800873F8: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800873FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80087400: bne         $t9, $zero, L_800873F8
    if (ctx->r25 != 0) {
        // 0x80087404: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800873F8;
    }
    // 0x80087404: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80087408:
    // 0x80087408: blez        $v1, L_80087420
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8008740C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80087420;
    }
    // 0x8008740C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087410: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x80087414: lbu         $t2, -0x1($t8)
    ctx->r10 = MEM_BU(ctx->r24, -0X1);
    // 0x80087418: b           L_80087428
    // 0x8008741C: sb          $t2, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r10;
        goto L_80087428;
    // 0x8008741C: sb          $t2, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r10;
L_80087420:
    // 0x80087420: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x80087424: sb          $t7, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r15;
L_80087428:
    // 0x80087428: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x8008742C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80087430: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80087434: sll         $t4, $t5, 4
    ctx->r12 = S32(ctx->r13 << 4);
    // 0x80087438: sb          $zero, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = 0;
    // 0x8008743C: addu        $t3, $t6, $t4
    ctx->r11 = ADD32(ctx->r14, ctx->r12);
    // 0x80087440: lbu         $v0, 0x0($t3)
    ctx->r2 = MEM_BU(ctx->r11, 0X0);
    // 0x80087444: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087448: beq         $v0, $at, L_80087468
    if (ctx->r2 == ctx->r1) {
        // 0x8008744C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087468;
    }
    // 0x8008744C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087450: beq         $v0, $at, L_800874DC
    if (ctx->r2 == ctx->r1) {
        // 0x80087454: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800874DC;
    }
    // 0x80087454: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087458: beq         $v0, $at, L_80087484
    if (ctx->r2 == ctx->r1) {
        // 0x8008745C: addiu       $a1, $sp, 0x2C
        ctx->r5 = ADD32(ctx->r29, 0X2C);
            goto L_80087484;
    }
    // 0x8008745C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80087460: b           L_8008763C
    // 0x80087464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087468:
    // 0x80087468: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x8008746C: jal         0x80074270
    // 0x80087470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_14;
    // 0x80087470: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_14:
    // 0x80087474: jal         0x8006EE3C
    // 0x80087478: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    mark_to_write_flap_and_course_times(rdram, ctx);
        goto after_15;
    // 0x80087478: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_15:
    // 0x8008747C: b           L_8008763C
    // 0x80087480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x80087480: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087484:
    // 0x80087484: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087488: jal         0x80074270
    // 0x8008748C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    read_time_data_from_controller_pak(rdram, ctx);
        goto after_16;
    // 0x8008748C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_16:
    // 0x80087490: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80087494: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087498: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008749C: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800874A0: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800874A4: bne         $v0, $zero, L_800874CC
    if (ctx->r2 != 0) {
        // 0x800874A8: sw          $v0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r2;
            goto L_800874CC;
    }
    // 0x800874A8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800874AC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800874B0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800874B4: sll         $t2, $t8, 4
    ctx->r10 = S32(ctx->r24 << 4);
    // 0x800874B8: addu        $t7, $t9, $t2
    ctx->r15 = ADD32(ctx->r25, ctx->r10);
    // 0x800874BC: lbu         $a0, 0x6($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X6);
    // 0x800874C0: jal         0x800743A0
    // 0x800874C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    write_time_data_to_controller_pak(rdram, ctx);
        goto after_17;
    // 0x800874C4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_17:
    // 0x800874C8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800874CC:
    // 0x800874CC: jal         0x8006ED9C
    // 0x800874D0: nop

    mark_to_read_flap_and_course_times(rdram, ctx);
        goto after_18;
    // 0x800874D0: nop

    after_18:
    // 0x800874D4: b           L_8008763C
    // 0x800874D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008763C;
    // 0x800874D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800874DC:
    // 0x800874DC: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800874E0: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800874E4: jal         0x80076520
    // 0x800874E8: nop

    delete_file(rdram, ctx);
        goto after_19;
    // 0x800874E8: nop

    after_19:
    // 0x800874EC: b           L_80087638
    // 0x800874F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800874F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800874F4:
    // 0x800874F4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800874F8: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800874FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80087500: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80087504: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087508: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8008750C: sll         $t4, $t6, 4
    ctx->r12 = S32(ctx->r14 << 4);
    // 0x80087510: addu        $v1, $t5, $t4
    ctx->r3 = ADD32(ctx->r13, ctx->r12);
    // 0x80087514: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80087518: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8008751C: beq         $v0, $at, L_80087568
    if (ctx->r2 == ctx->r1) {
        // 0x80087520: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80087568;
    }
    // 0x80087520: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80087524: beq         $v0, $at, L_8008754C
    if (ctx->r2 == ctx->r1) {
        // 0x80087528: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_8008754C;
    }
    // 0x80087528: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8008752C: bne         $v0, $at, L_80087638
    if (ctx->r2 != ctx->r1) {
        // 0x80087530: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_80087638;
    }
    // 0x80087530: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087534: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087538: sw          $t3, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r11;
    // 0x8008753C: lbu         $t8, 0x6($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X6);
    // 0x80087540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087544: b           L_80087638
    // 0x80087548: sw          $t8, 0x6A70($at)
    MEM_W(0X6A70, ctx->r1) = ctx->r24;
        goto L_80087638;
    // 0x80087548: sw          $t8, 0x6A70($at)
    MEM_W(0X6A70, ctx->r1) = ctx->r24;
L_8008754C:
    // 0x8008754C: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x80087550: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087554: lbu         $a2, 0x6($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X6);
    // 0x80087558: jal         0x800765E0
    // 0x8008755C: nop

    copy_controller_pak_data(rdram, ctx);
        goto after_20;
    // 0x8008755C: nop

    after_20:
    // 0x80087560: b           L_80087638
    // 0x80087564: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x80087564: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087568:
    // 0x80087568: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x8008756C: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x80087570: jal         0x80076520
    // 0x80087574: nop

    delete_file(rdram, ctx);
        goto after_21;
    // 0x80087574: nop

    after_21:
    // 0x80087578: b           L_80087638
    // 0x8008757C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x8008757C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_80087580:
    // 0x80087580: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087584: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x80087588: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008758C: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80087590: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x80087594: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80087598: sll         $t7, $t2, 4
    ctx->r15 = S32(ctx->r10 << 4);
    // 0x8008759C: addu        $t6, $t9, $t7
    ctx->r14 = ADD32(ctx->r25, ctx->r15);
    // 0x800875A0: lbu         $t5, 0x0($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X0);
    // 0x800875A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800875A8: bne         $t5, $at, L_8008763C
    if (ctx->r13 != ctx->r1) {
        // 0x800875AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008763C;
    }
    // 0x800875AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800875B0: lbu         $a0, 0x6($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X6);
    // 0x800875B4: lbu         $a1, 0x7($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X7);
    // 0x800875B8: jal         0x80076520
    // 0x800875BC: nop

    delete_file(rdram, ctx);
        goto after_22;
    // 0x800875BC: nop

    after_22:
    // 0x800875C0: b           L_80087638
    // 0x800875C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
        goto L_80087638;
    // 0x800875C4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
L_800875C8:
    // 0x800875C8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800875CC: addiu       $t1, $t1, 0x71A4
    ctx->r9 = ADD32(ctx->r9, 0X71A4);
    // 0x800875D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800875D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800875D8: addiu       $t0, $t0, 0x6FC4
    ctx->r8 = ADD32(ctx->r8, 0X6FC4);
    // 0x800875DC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800875E0: sll         $t8, $t3, 4
    ctx->r24 = S32(ctx->r11 << 4);
    // 0x800875E4: addu        $t2, $t4, $t8
    ctx->r10 = ADD32(ctx->r12, ctx->r24);
    // 0x800875E8: lbu         $t9, 0x0($t2)
    ctx->r25 = MEM_BU(ctx->r10, 0X0);
    // 0x800875EC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800875F0: bne         $t9, $at, L_80087638
    if (ctx->r25 != ctx->r1) {
        // 0x800875F4: addiu       $a0, $zero, 0x0
        ctx->r4 = ADD32(0, 0X0);
            goto L_80087638;
    }
    // 0x800875F4: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x800875F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800875FC: jal         0x8009F000
    // 0x80087600: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    unset_eeprom_settings_value(rdram, ctx);
        goto after_23;
    // 0x80087600: ori         $a1, $a1, 0xFFF3
    ctx->r5 = ctx->r5 | 0XFFF3;
    after_23:
    // 0x80087604: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80087608: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008760C: addiu       $a1, $a1, 0x31C
    ctx->r5 = ADD32(ctx->r5, 0X31C);
    // 0x80087610: addiu       $v1, $v1, 0x318
    ctx->r3 = ADD32(ctx->r3, 0X318);
    // 0x80087614: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80087618: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x8008761C: addiu       $a0, $zero, -0x4
    ctx->r4 = ADD32(0, -0X4);
    // 0x80087620: and         $t6, $t7, $a0
    ctx->r14 = ctx->r15 & ctx->r4;
    // 0x80087624: and         $t3, $t5, $a0
    ctx->r11 = ctx->r13 & ctx->r4;
    // 0x80087628: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8008762C: b           L_80087638
    // 0x80087630: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
        goto L_80087638;
    // 0x80087630: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
L_80087634:
    // 0x80087634: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_80087638:
    // 0x80087638: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008763C:
    // 0x8008763C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80087640: jr          $ra
    // 0x80087644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80087644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void __osPfsDeclearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1A24: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D1A28: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1A2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D1A30: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800D1A34: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800D1A38: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800D1A3C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800D1A40: blez        $t6, L_800D1A54
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800D1A44: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_800D1A54;
    }
    // 0x800D1A44: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800D1A48: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1A4C: b           L_800D1A60
    // 0x800D1A50: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_800D1A60;
    // 0x800D1A50: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_800D1A54:
    // 0x800D1A54: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800D1A58: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x800D1A5C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_800D1A60:
    // 0x800D1A60: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800D1A64: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x800D1A68: beq         $at, $zero, L_800D1AA4
    if (ctx->r1 == 0) {
        // 0x800D1A6C: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800D1AA4;
    }
    // 0x800D1A6C: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800D1A70:
    // 0x800D1A70: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1A74: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800D1A78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1A7C: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800D1A80: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800D1A84: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x800D1A88: beq         $t5, $at, L_800D1AA4
    if (ctx->r13 == ctx->r1) {
        // 0x800D1A8C: nop
    
            goto L_800D1AA4;
    }
    // 0x800D1A8C: nop

    // 0x800D1A90: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1A94: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800D1A98: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800D1A9C: bne         $at, $zero, L_800D1A70
    if (ctx->r1 != 0) {
        // 0x800D1AA0: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_800D1A70;
    }
    // 0x800D1AA0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_800D1AA4:
    // 0x800D1AA4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1AA8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D1AAC: bne         $t8, $at, L_800D1AC8
    if (ctx->r24 != ctx->r1) {
        // 0x800D1AB0: nop
    
            goto L_800D1AC8;
    }
    // 0x800D1AB0: nop

    // 0x800D1AB4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1AB8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800D1ABC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800D1AC0: b           L_800D1C78
    // 0x800D1AC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1C78;
    // 0x800D1AC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1AC8:
    // 0x800D1AC8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800D1ACC:
    // 0x800D1ACC: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x800D1AD0: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x800D1AD4: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x800D1AD8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D1ADC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800D1AE0: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x800D1AE4: bne         $at, $zero, L_800D1ACC
    if (ctx->r1 != 0) {
        // 0x800D1AE8: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_800D1ACC;
    }
    // 0x800D1AE8: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x800D1AEC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1AF0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800D1AF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D1AF8: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x800D1AFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800D1B00: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B04: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x800D1B08: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D1B0C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D1B10: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800D1B14: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800D1B18: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x800D1B1C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D1B20: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1B24: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_800D1BF4;
    }
    // 0x800D1B24: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800D1B28: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1B2C: nop
    
            goto L_800D1BF4;
    }
    // 0x800D1B2C: nop

L_800D1B30:
    // 0x800D1B30: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B34: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800D1B38: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D1B3C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800D1B40: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800D1B44: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800D1B48: bne         $t7, $at, L_800D1BC0
    if (ctx->r15 != ctx->r1) {
        // 0x800D1B4C: nop
    
            goto L_800D1BC0;
    }
    // 0x800D1B4C: nop

    // 0x800D1B50: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B54: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1B58: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800D1B5C: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800D1B60: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x800D1B64: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x800D1B68: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B6C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800D1B70: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1B74: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D1B78: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x800D1B7C: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x800D1B80: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1B84: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D1B88: jal         0x800D1C88
    // 0x800D1B8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    static_3_800D1C88(rdram, ctx);
        goto after_0;
    // 0x800D1B8C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800D1B90: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1B94: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1B98: beq         $t2, $zero, L_800D1BA8
    if (ctx->r10 == 0) {
        // 0x800D1B9C: nop
    
            goto L_800D1BA8;
    }
    // 0x800D1B9C: nop

    // 0x800D1BA0: b           L_800D1C78
    // 0x800D1BA4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800D1C78;
    // 0x800D1BA4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_800D1BA8:
    // 0x800D1BA8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BAC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800D1BB0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x800D1BB4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800D1BB8: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x800D1BBC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_800D1BC0:
    // 0x800D1BC0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BC4: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800D1BC8: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800D1BCC: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800D1BD0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800D1BD4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800D1BD8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D1BDC: beq         $at, $zero, L_800D1BF4
    if (ctx->r1 == 0) {
        // 0x800D1BE0: nop
    
            goto L_800D1BF4;
    }
    // 0x800D1BE0: nop

    // 0x800D1BE4: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1BE8: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x800D1BEC: bne         $at, $zero, L_800D1B30
    if (ctx->r1 != 0) {
        // 0x800D1BF0: nop
    
            goto L_800D1B30;
    }
    // 0x800D1BF0: nop

L_800D1BF4:
    // 0x800D1BF4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800D1BF8: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800D1BFC: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800D1C00: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x800D1C04: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800D1C08: bne         $t1, $at, L_800D1C3C
    if (ctx->r9 != ctx->r1) {
        // 0x800D1C0C: nop
    
            goto L_800D1C3C;
    }
    // 0x800D1C0C: nop

    // 0x800D1C10: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x800D1C14: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800D1C18: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x800D1C1C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800D1C20: beq         $at, $zero, L_800D1C3C
    if (ctx->r1 == 0) {
        // 0x800D1C24: nop
    
            goto L_800D1C3C;
    }
    // 0x800D1C24: nop

    // 0x800D1C28: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C2C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800D1C30: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800D1C34: b           L_800D1C78
    // 0x800D1C38: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_800D1C78;
    // 0x800D1C38: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1C3C:
    // 0x800D1C3C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C40: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800D1C44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D1C48: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x800D1C4C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x800D1C50: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x800D1C54: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x800D1C58: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800D1C5C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800D1C60: jal         0x800D1C88
    // 0x800D1C64: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    static_3_800D1C88(rdram, ctx);
        goto after_1;
    // 0x800D1C64: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x800D1C68: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800D1C6C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800D1C70: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x800D1C74: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_800D1C78:
    // 0x800D1C78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D1C7C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800D1C80: jr          $ra
    // 0x800D1C84: nop

    return;
    // 0x800D1C84: nop

;}
RECOMP_FUNC void wavegen_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0174: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800C0178: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800C017C: beq         $a0, $zero, L_800C03B0
    if (ctx->r4 == 0) {
        // 0x800C0180: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_800C03B0;
    }
    // 0x800C0180: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800C0184: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C0188: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800C018C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800C0190: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800C0194: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
    // 0x800C0198: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C019C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800C01A0: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800C01A4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800C01A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C01AC: bc1f        L_800C01C8
    if (!c1cs) {
        // 0x800C01B0: nop
    
            goto L_800C01C8;
    }
    // 0x800C01B0: nop

    // 0x800C01B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C01B8: nop

    // 0x800C01BC: swc1        $f10, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f10.u32l;
    // 0x800C01C0: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800C01C4: nop

L_800C01C8:
    // 0x800C01C8: lwc1        $f2, 0xC($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C01CC: lwc1        $f6, 0x28($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C01D0: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800C01D4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C01D8: add.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C01DC: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800C01E0: add.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f14.fl;
    // 0x800C01E4: swc1        $f4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f4.u32l;
    // 0x800C01E8: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800C01EC: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C01F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C01F4: bne         $t6, $zero, L_800C02A4
    if (ctx->r14 != 0) {
        // 0x800C01F8: nop
    
            goto L_800C02A4;
    }
    // 0x800C01F8: nop

    // 0x800C01FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C0200: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C0204: lwc1        $f5, -0x67C8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X67C8);
    // 0x800C0208: lwc1        $f4, -0x67C4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X67C4);
    // 0x800C020C: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800C0210: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C0214: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0218: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C021C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800C0220: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0224: nop

    // 0x800C0228: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C022C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0230: nop

    // 0x800C0234: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0238: beq         $t8, $zero, L_800C0288
    if (ctx->r24 == 0) {
        // 0x800C023C: nop
    
            goto L_800C0288;
    }
    // 0x800C023C: nop

    // 0x800C0240: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C0244: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C0248: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C024C: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800C0250: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0258: nop

    // 0x800C025C: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C0260: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0264: nop

    // 0x800C0268: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C026C: bne         $t8, $zero, L_800C0280
    if (ctx->r24 != 0) {
        // 0x800C0270: nop
    
            goto L_800C0280;
    }
    // 0x800C0270: nop

    // 0x800C0274: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800C0278: b           L_800C0298
    // 0x800C027C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C0298;
    // 0x800C027C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C0280:
    // 0x800C0280: b           L_800C0298
    // 0x800C0284: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C0298;
    // 0x800C0284: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800C0288:
    // 0x800C0288: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800C028C: nop

    // 0x800C0290: bltz        $t8, L_800C0280
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C0294: nop
    
            goto L_800C0280;
    }
    // 0x800C0294: nop

L_800C0298:
    // 0x800C0298: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C029C: b           L_800C0348
    // 0x800C02A0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
        goto L_800C0348;
    // 0x800C02A0: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
L_800C02A4:
    // 0x800C02A4: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800C02A8: lwc1        $f5, -0x67C0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X67C0);
    // 0x800C02AC: lwc1        $f4, -0x67BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X67BC);
    // 0x800C02B0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800C02B4: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800C02B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C02BC: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800C02C0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C02C4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C02C8: nop

    // 0x800C02CC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800C02D0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C02D4: nop

    // 0x800C02D8: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C02DC: beq         $t0, $zero, L_800C032C
    if (ctx->r8 == 0) {
        // 0x800C02E0: nop
    
            goto L_800C032C;
    }
    // 0x800C02E0: nop

    // 0x800C02E4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800C02E8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800C02EC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C02F0: sub.d       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f6.d - ctx->f8.d;
    // 0x800C02F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C02F8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800C02FC: nop

    // 0x800C0300: cvt.w.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_D(ctx->f8.d);
    // 0x800C0304: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800C0308: nop

    // 0x800C030C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800C0310: bne         $t0, $zero, L_800C0324
    if (ctx->r8 != 0) {
        // 0x800C0314: nop
    
            goto L_800C0324;
    }
    // 0x800C0314: nop

    // 0x800C0318: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800C031C: b           L_800C033C
    // 0x800C0320: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800C033C;
    // 0x800C0320: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800C0324:
    // 0x800C0324: b           L_800C033C
    // 0x800C0328: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800C033C;
    // 0x800C0328: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800C032C:
    // 0x800C032C: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800C0330: nop

    // 0x800C0334: bltz        $t0, L_800C0324
    if (SIGNED(ctx->r8) < 0) {
        // 0x800C0338: nop
    
            goto L_800C0324;
    }
    // 0x800C0338: nop

L_800C033C:
    // 0x800C033C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C0340: sw          $t0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r8;
    // 0x800C0344: nop

L_800C0348:
    // 0x800C0348: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C034C: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C0350: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C0354: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x800C0358: swc1        $f4, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f4.u32l;
    // 0x800C035C: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C0360: nop

    // 0x800C0364: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800C0368: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x800C036C: nop

    // 0x800C0370: bc1f        L_800C038C
    if (!c1cs) {
        // 0x800C0374: nop
    
            goto L_800C038C;
    }
    // 0x800C0374: nop

    // 0x800C0378: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C037C: nop

    // 0x800C0380: swc1        $f8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f8.u32l;
    // 0x800C0384: lwc1        $f0, 0x2C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x800C0388: nop

L_800C038C:
    // 0x800C038C: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800C0390: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0394: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800C0398: div.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800C039C: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x800C03A0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C03A4: nop

    // 0x800C03A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C03AC: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800C03B0:
    // 0x800C03B0: jr          $ra
    // 0x800C03B4: nop

    return;
    // 0x800C03B4: nop

;}
RECOMP_FUNC void obj_init_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003C688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003C68C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8003C690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8003C694: lb          $a2, 0x9($a1)
    ctx->r6 = MEM_B(ctx->r5, 0X9);
    // 0x8003C698: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C69C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003C6A0: bne         $a2, $at, L_8003C6B8
    if (ctx->r6 != ctx->r1) {
        // 0x8003C6A4: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_8003C6B8;
    }
    // 0x8003C6A4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8003C6A8: jal         0x8000CC20
    // 0x8003C6AC: nop

    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003C6AC: nop

    after_0:
    // 0x8003C6B0: b           L_8003C6C4
    // 0x8003C6B4: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
        goto L_8003C6C4;
    // 0x8003C6B4: sb          $v0, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r2;
L_8003C6B8:
    // 0x8003C6B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003C6BC: jal         0x8000CBF0
    // 0x8003C6C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003C6C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_1:
L_8003C6C4:
    // 0x8003C6C4: lb          $t6, 0x9($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X9);
    // 0x8003C6C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003C6CC: bne         $t6, $at, L_8003C6DC
    if (ctx->r14 != ctx->r1) {
        // 0x8003C6D0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003C6DC;
    }
    // 0x8003C6D0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003C6D4: jal         0x800CA2B4
    // 0x8003C6D8: addiu       $a0, $a0, 0x6558
    ctx->r4 = ADD32(ctx->r4, 0X6558);
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003C6D8: addiu       $a0, $a0, 0x6558
    ctx->r4 = ADD32(ctx->r4, 0X6558);
    after_2:
L_8003C6DC:
    // 0x8003C6DC: lbu         $t8, 0x8($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C6E0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003C6E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8003C6E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003C6EC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003C6F0: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003C6F4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003C6F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003C6FC: nop

    // 0x8003C700: bc1f        L_8003C710
    if (!c1cs) {
        // 0x8003C704: nop
    
            goto L_8003C710;
    }
    // 0x8003C704: nop

    // 0x8003C708: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003C70C: nop

L_8003C710:
    // 0x8003C710: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003C714: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C718: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8003C71C: lbu         $t0, 0xA($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XA);
    // 0x8003C720: nop

    // 0x8003C724: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8003C728: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003C72C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C730: jal         0x80070A04
    // 0x8003C734: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x8003C734: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_3:
    // 0x8003C738: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C73C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003C740: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003C744: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003C748: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003C74C: jal         0x80070A38
    // 0x8003C750: nop

    coss_f(rdram, ctx);
        goto after_4;
    // 0x8003C750: nop

    after_4:
    // 0x8003C754: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8003C758: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8003C75C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003C760: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C764: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003C768: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C76C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003C770: nop

    // 0x8003C774: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003C778: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003C77C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003C780: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003C784: lbu         $t2, 0x8($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C788: nop

    // 0x8003C78C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8003C790: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x8003C794: nop

    // 0x8003C798: sb          $t3, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r11;
    // 0x8003C79C: lw          $t5, 0x4C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7A0: nop

    // 0x8003C7A4: sh          $t4, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r12;
    // 0x8003C7A8: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7AC: nop

    // 0x8003C7B0: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x8003C7B4: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7B8: lbu         $t7, 0x8($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X8);
    // 0x8003C7BC: nop

    // 0x8003C7C0: sb          $t7, 0x10($t8)
    MEM_B(0X10, ctx->r24) = ctx->r15;
    // 0x8003C7C4: lw          $t9, 0x4C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4C);
    // 0x8003C7C8: nop

    // 0x8003C7CC: sb          $zero, 0x12($t9)
    MEM_B(0X12, ctx->r25) = 0;
    // 0x8003C7D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003C7D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8003C7D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8003C7DC: jr          $ra
    // 0x8003C7E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003C7E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void play_char_horn_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80056978: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8005697C: jal         0x8009C850
    // 0x80056980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80056980: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80056984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80056988: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8005698C: beq         $t6, $zero, L_800569A8
    if (ctx->r14 == 0) {
        // 0x80056990: addiu       $a1, $zero, 0x162
        ctx->r5 = ADD32(0, 0X162);
            goto L_800569A8;
    }
    // 0x80056990: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80056994: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80056998: jal         0x800570F8
    // 0x8005699C: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x8005699C: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_1:
    // 0x800569A0: b           L_800569C0
    // 0x800569A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800569C0;
    // 0x800569A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800569A8:
    // 0x800569A8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800569AC: nop

    // 0x800569B0: lb          $a1, 0x3($t7)
    ctx->r5 = MEM_B(ctx->r15, 0X3);
    // 0x800569B4: jal         0x80057088
    // 0x800569B8: addiu       $a1, $a1, 0x156
    ctx->r5 = ADD32(ctx->r5, 0X156);
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x800569B8: addiu       $a1, $a1, 0x156
    ctx->r5 = ADD32(ctx->r5, 0X156);
    after_2:
    // 0x800569BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800569C0:
    // 0x800569C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800569C4: jr          $ra
    // 0x800569C8: nop

    return;
    // 0x800569C8: nop

;}
RECOMP_FUNC void vec3f_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070560: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070564: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070568: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007056C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80070570: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80070574: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80070578: jal         0x80070A04
    // 0x8007057C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8007057C: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    after_0:
    // 0x80070580: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070584: lh          $a0, 0x4($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X4);
    // 0x80070588: mul.s       $f12, $f6, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8007058C: jal         0x80070A38
    // 0x80070590: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80070590: nop

    after_1:
    // 0x80070594: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80070598: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x8007059C: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705A0: sub.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800705A4: jal         0x80070A04
    // 0x800705A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800705A8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    after_2:
    // 0x800705AC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705B0: lh          $a0, 0x2($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X2);
    // 0x800705B4: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705B8: jal         0x80070A38
    // 0x800705BC: nop

    coss_f(rdram, ctx);
        goto after_3;
    // 0x800705BC: nop

    after_3:
    // 0x800705C0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800705C4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800705C8: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705CC: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800705D0: jal         0x80070A04
    // 0x800705D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    sins_f(rdram, ctx);
        goto after_4;
    // 0x800705D4: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    after_4:
    // 0x800705D8: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800705DC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800705E0: mul.s       $f12, $f8, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705E4: jal         0x80070A38
    // 0x800705E8: nop

    coss_f(rdram, ctx);
        goto after_5;
    // 0x800705E8: nop

    after_5:
    // 0x800705EC: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800705F0: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800705F4: mul.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800705F8: add.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800705FC: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80070600: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x80070604: swc1        $f8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f8.u32l;
    // 0x80070608: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007060C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070610: jr          $ra
    // 0x80070614: nop

    return;
    // 0x80070614: nop

;}
RECOMP_FUNC void is_game_paused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ECE0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ECE4: lb          $v0, 0x3A95($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3A95);
    // 0x8006ECE8: jr          $ra
    // 0x8006ECEC: nop

    return;
    // 0x8006ECEC: nop

;}
RECOMP_FUNC void apply_vehicle_rotation_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80050890: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80050894: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80050898: lbu         $t4, 0x1F1($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X1F1);
    // 0x8005089C: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x800508A0: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800508A4: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800508A8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800508AC: bne         $t4, $zero, L_80050A60
    if (ctx->r12 != 0) {
        // 0x800508B0: or          $a3, $t9, $zero
        ctx->r7 = ctx->r25 | 0;
            goto L_80050A60;
    }
    // 0x800508B0: or          $a3, $t9, $zero
    ctx->r7 = ctx->r25 | 0;
    // 0x800508B4: lh          $v1, 0x160($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X160);
    // 0x800508B8: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x800508BC: andi        $t5, $v1, 0xFFFF
    ctx->r13 = ctx->r3 & 0XFFFF;
    // 0x800508C0: subu        $v0, $t7, $t5
    ctx->r2 = SUB32(ctx->r15, ctx->r13);
    // 0x800508C4: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800508C8: bne         $at, $zero, L_800508DC
    if (ctx->r1 != 0) {
        // 0x800508CC: sh          $t9, 0x166($a0)
        MEM_H(0X166, ctx->r4) = ctx->r25;
            goto L_800508DC;
    }
    // 0x800508CC: sh          $t9, 0x166($a0)
    MEM_H(0X166, ctx->r4) = ctx->r25;
    // 0x800508D0: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x800508D4: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x800508D8: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
L_800508DC:
    // 0x800508DC: lui         $t1, 0xFFFF
    ctx->r9 = S32(0XFFFF << 16);
    // 0x800508E0: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800508E4: beq         $at, $zero, L_800508F4
    if (ctx->r1 == 0) {
        // 0x800508E8: ori         $t1, $t1, 0x1
        ctx->r9 = ctx->r9 | 0X1;
            goto L_800508F4;
    }
    // 0x800508E8: ori         $t1, $t1, 0x1
    ctx->r9 = ctx->r9 | 0X1;
    // 0x800508EC: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800508F0: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_800508F4:
    // 0x800508F4: blez        $v0, L_80050924
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800508F8: ori         $t2, $zero, 0xFFFF
        ctx->r10 = 0 | 0XFFFF;
            goto L_80050924;
    }
    // 0x800508F8: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800508FC: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x80050900: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050904: mflo        $a2
    ctx->r6 = lo;
    // 0x80050908: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005090C: beq         $at, $zero, L_8005091C
    if (ctx->r1 == 0) {
        // 0x80050910: addu        $t6, $v1, $v0
        ctx->r14 = ADD32(ctx->r3, ctx->r2);
            goto L_8005091C;
    }
    // 0x80050910: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x80050914: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050918: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
L_8005091C:
    // 0x8005091C: b           L_80050950
    // 0x80050920: sh          $t6, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r14;
        goto L_80050950;
    // 0x80050920: sh          $t6, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r14;
L_80050924:
    // 0x80050924: bgez        $v0, L_80050950
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050928: addiu       $t3, $zero, 0x600
        ctx->r11 = ADD32(0, 0X600);
            goto L_80050950;
    }
    // 0x80050928: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x8005092C: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050930: mflo        $a2
    ctx->r6 = lo;
    // 0x80050934: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80050938: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8005093C: beq         $at, $zero, L_8005094C
    if (ctx->r1 == 0) {
        // 0x80050940: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_8005094C;
    }
    // 0x80050940: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x80050944: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050948: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
L_8005094C:
    // 0x8005094C: sh          $t7, 0x160($a0)
    MEM_H(0X160, ctx->r4) = ctx->r15;
L_80050950:
    // 0x80050950: lh          $v1, 0x162($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X162);
    // 0x80050954: addiu       $t3, $zero, 0x600
    ctx->r11 = ADD32(0, 0X600);
    // 0x80050958: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x8005095C: subu        $v0, $a3, $t8
    ctx->r2 = SUB32(ctx->r7, ctx->r24);
    // 0x80050960: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80050964: bne         $at, $zero, L_80050974
    if (ctx->r1 != 0) {
        // 0x80050968: slti        $at, $v0, -0x8000
        ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
            goto L_80050974;
    }
    // 0x80050968: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005096C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80050970: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
L_80050974:
    // 0x80050974: beq         $at, $zero, L_80050980
    if (ctx->r1 == 0) {
        // 0x80050978: nop
    
            goto L_80050980;
    }
    // 0x80050978: nop

    // 0x8005097C: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80050980:
    // 0x80050980: blez        $v0, L_800509AC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050984: nop
    
            goto L_800509AC;
    }
    // 0x80050984: nop

    // 0x80050988: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005098C: mflo        $a2
    ctx->r6 = lo;
    // 0x80050990: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80050994: beq         $at, $zero, L_800509A4
    if (ctx->r1 == 0) {
        // 0x80050998: addu        $t9, $v1, $v0
        ctx->r25 = ADD32(ctx->r3, ctx->r2);
            goto L_800509A4;
    }
    // 0x80050998: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
    // 0x8005099C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800509A0: addu        $t9, $v1, $v0
    ctx->r25 = ADD32(ctx->r3, ctx->r2);
L_800509A4:
    // 0x800509A4: b           L_800509D8
    // 0x800509A8: sh          $t9, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r25;
        goto L_800509D8;
    // 0x800509A8: sh          $t9, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r25;
L_800509AC:
    // 0x800509AC: bgez        $v0, L_800509D8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800509B0: nop
    
            goto L_800509D8;
    }
    // 0x800509B0: nop

    // 0x800509B4: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800509B8: mflo        $a2
    ctx->r6 = lo;
    // 0x800509BC: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x800509C0: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800509C4: beq         $at, $zero, L_800509D4
    if (ctx->r1 == 0) {
        // 0x800509C8: addu        $t4, $v1, $v0
        ctx->r12 = ADD32(ctx->r3, ctx->r2);
            goto L_800509D4;
    }
    // 0x800509C8: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
    // 0x800509CC: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800509D0: addu        $t4, $v1, $v0
    ctx->r12 = ADD32(ctx->r3, ctx->r2);
L_800509D4:
    // 0x800509D4: sh          $t4, 0x162($a0)
    MEM_H(0X162, ctx->r4) = ctx->r12;
L_800509D8:
    // 0x800509D8: lh          $v1, 0x164($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X164);
    // 0x800509DC: lh          $t5, 0x12($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X12);
    // 0x800509E0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800509E4: subu        $v0, $t5, $t6
    ctx->r2 = SUB32(ctx->r13, ctx->r14);
    // 0x800509E8: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800509EC: bne         $at, $zero, L_800509FC
    if (ctx->r1 != 0) {
        // 0x800509F0: slti        $at, $v0, -0x8000
        ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
            goto L_800509FC;
    }
    // 0x800509F0: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x800509F4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800509F8: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
L_800509FC:
    // 0x800509FC: beq         $at, $zero, L_80050A08
    if (ctx->r1 == 0) {
        // 0x80050A00: nop
    
            goto L_80050A08;
    }
    // 0x80050A00: nop

    // 0x80050A04: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
L_80050A08:
    // 0x80050A08: blez        $v0, L_80050A34
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80050A0C: nop
    
            goto L_80050A34;
    }
    // 0x80050A0C: nop

    // 0x80050A10: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050A14: mflo        $a2
    ctx->r6 = lo;
    // 0x80050A18: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80050A1C: beq         $at, $zero, L_80050A2C
    if (ctx->r1 == 0) {
        // 0x80050A20: addu        $t7, $v1, $v0
        ctx->r15 = ADD32(ctx->r3, ctx->r2);
            goto L_80050A2C;
    }
    // 0x80050A20: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x80050A24: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050A28: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
L_80050A2C:
    // 0x80050A2C: jr          $ra
    // 0x80050A30: sh          $t7, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r15;
    return;
    // 0x80050A30: sh          $t7, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r15;
L_80050A34:
    // 0x80050A34: bgez        $v0, L_80050A60
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80050A38: nop
    
            goto L_80050A60;
    }
    // 0x80050A38: nop

    // 0x80050A3C: multu       $a1, $t3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80050A40: mflo        $a2
    ctx->r6 = lo;
    // 0x80050A44: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
    // 0x80050A48: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80050A4C: beq         $at, $zero, L_80050A5C
    if (ctx->r1 == 0) {
        // 0x80050A50: addu        $t8, $v1, $v0
        ctx->r24 = ADD32(ctx->r3, ctx->r2);
            goto L_80050A5C;
    }
    // 0x80050A50: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
    // 0x80050A54: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80050A58: addu        $t8, $v1, $v0
    ctx->r24 = ADD32(ctx->r3, ctx->r2);
L_80050A5C:
    // 0x80050A5C: sh          $t8, 0x164($a0)
    MEM_H(0X164, ctx->r4) = ctx->r24;
L_80050A60:
    // 0x80050A60: jr          $ra
    // 0x80050A64: nop

    return;
    // 0x80050A64: nop

;}
