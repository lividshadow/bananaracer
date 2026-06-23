#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80012C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C98: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012C9C: addiu       $a1, $a1, -0x4CDC
    ctx->r5 = ADD32(ctx->r5, -0X4CDC);
    // 0x80012CA0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80012CA4: nop

    // 0x80012CA8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CAC: beq         $at, $zero, L_80012CE0
    if (ctx->r1 == 0) {
        // 0x80012CB0: nop
    
            goto L_80012CE0;
    }
    // 0x80012CB0: nop

    // 0x80012CB4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012CB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012CBC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012CC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012CC4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012CC8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80012CCC: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x80012CD0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80012CD4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012CD8: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80012CDC: sw          $t8, -0x4D08($at)
    MEM_W(-0X4D08, ctx->r1) = ctx->r24;
L_80012CE0:
    // 0x80012CE0: jr          $ra
    // 0x80012CE4: nop

    return;
    // 0x80012CE4: nop

;}
RECOMP_FUNC void postrace_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094B8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80094B90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80094B94: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80094B98: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80094B9C: jal         0x800724E4
    // 0x80094BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_0;
    // 0x80094BA0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80094BA4: jal         0x8006BFF0
    // 0x80094BA8: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x80094BA8: nop

    after_1:
    // 0x80094BAC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80094BB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094BB4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80094BB8: jal         0x8009F1C4
    // 0x80094BBC: sb          $t6, 0x71E8($at)
    MEM_B(0X71E8, ctx->r1) = ctx->r14;
    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x80094BBC: sb          $t6, 0x71E8($at)
    MEM_B(0X71E8, ctx->r1) = ctx->r14;
    after_2:
    // 0x80094BC0: beq         $v0, $zero, L_80094BD0
    if (ctx->r2 == 0) {
        // 0x80094BC4: nop
    
            goto L_80094BD0;
    }
    // 0x80094BC4: nop

    // 0x80094BC8: jal         0x80024A20
    // 0x80094BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_scene_viewport_num(rdram, ctx);
        goto after_3;
    // 0x80094BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
L_80094BD0:
    // 0x80094BD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094BD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80094BD8: lw          $t7, -0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C4);
    // 0x80094BDC: sw          $zero, 0x7050($at)
    MEM_W(0X7050, ctx->r1) = 0;
    // 0x80094BE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094BE4: bne         $t7, $at, L_80094CE4
    if (ctx->r15 != ctx->r1) {
        // 0x80094BE8: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80094CE4;
    }
    // 0x80094BE8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80094BEC: lw          $t8, 0x1568($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1568);
    // 0x80094BF0: nop

    // 0x80094BF4: bne         $t8, $zero, L_80094CE8
    if (ctx->r24 != 0) {
        // 0x80094BF8: addiu       $t3, $zero, 0x7
        ctx->r11 = ADD32(0, 0X7);
            goto L_80094CE8;
    }
    // 0x80094BF8: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80094BFC: jal         0x8009C814
    // 0x80094C00: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_4;
    // 0x80094C00: nop

    after_4:
    // 0x80094C04: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80094C08: bne         $v0, $a2, L_80094C50
    if (ctx->r2 != ctx->r6) {
        // 0x80094C0C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80094C50;
    }
    // 0x80094C0C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094C10: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094C14: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80094C18: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094C1C: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80094C20: addiu       $a1, $a1, 0x71B0
    ctx->r5 = ADD32(ctx->r5, 0X71B0);
    // 0x80094C24: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80094C28: lw          $t0, 0x60($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X60);
    // 0x80094C2C: addiu       $a0, $a0, 0x71D4
    ctx->r4 = ADD32(ctx->r4, 0X71D4);
    // 0x80094C30: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x80094C34: lw          $t1, 0x68($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X68);
    // 0x80094C38: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80094C3C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80094C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094C44: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x80094C48: b           L_80094CBC
    // 0x80094C4C: sw          $a2, 0x7050($at)
    MEM_W(0X7050, ctx->r1) = ctx->r6;
        goto L_80094CBC;
    // 0x80094C4C: sw          $a2, 0x7050($at)
    MEM_W(0X7050, ctx->r1) = ctx->r6;
L_80094C50:
    // 0x80094C50: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x80094C54: nop

    // 0x80094C58: bne         $t3, $zero, L_80094C84
    if (ctx->r11 != 0) {
        // 0x80094C5C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80094C84;
    }
    // 0x80094C5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094C60: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80094C64: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094C68: lw          $t4, 0x5C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X5C);
    // 0x80094C6C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094C70: addiu       $a1, $a1, 0x71B0
    ctx->r5 = ADD32(ctx->r5, 0X71B0);
    // 0x80094C74: addiu       $a0, $a0, 0x71D4
    ctx->r4 = ADD32(ctx->r4, 0X71D4);
    // 0x80094C78: sw          $a2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r6;
    // 0x80094C7C: b           L_80094CA0
    // 0x80094C80: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
        goto L_80094CA0;
    // 0x80094C80: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_80094C84:
    // 0x80094C84: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094C88: addiu       $a0, $a0, 0x71D4
    ctx->r4 = ADD32(ctx->r4, 0X71D4);
    // 0x80094C8C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80094C90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80094C94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094C98: lw          $v0, -0x5E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E0);
    // 0x80094C9C: addiu       $a1, $a1, 0x71B0
    ctx->r5 = ADD32(ctx->r5, 0X71B0);
L_80094CA0:
    // 0x80094CA0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80094CA4: lw          $t5, 0x64($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X64);
    // 0x80094CA8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80094CAC: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80094CB0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80094CB4: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x80094CB8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80094CBC:
    // 0x80094CBC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80094CC0: lw          $t9, 0x70($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X70);
    // 0x80094CC4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80094CC8: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x80094CCC: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x80094CD0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80094CD4: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80094CD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094CDC: b           L_80094CF0
    // 0x80094CE0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
        goto L_80094CF0;
    // 0x80094CE0: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
L_80094CE4:
    // 0x80094CE4: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
L_80094CE8:
    // 0x80094CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094CEC: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
L_80094CF0:
    // 0x80094CF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094CF4: sw          $zero, 0x7280($at)
    MEM_W(0X7280, ctx->r1) = 0;
    // 0x80094CF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094CFC: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80094D00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D04: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80094D08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094D0C: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80094D10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094D14: sw          $zero, -0x620($at)
    MEM_W(-0X620, ctx->r1) = 0;
    // 0x80094D18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D1C: sw          $zero, 0x7028($at)
    MEM_W(0X7028, ctx->r1) = 0;
    // 0x80094D20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D24: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80094D28: sw          $t4, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r12;
    // 0x80094D2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80094D34: sw          $t6, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = ctx->r14;
    // 0x80094D38: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094D3C: sw          $zero, 0xF08($at)
    MEM_W(0XF08, ctx->r1) = 0;
    // 0x80094D40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D44: sw          $zero, 0x71DC($at)
    MEM_W(0X71DC, ctx->r1) = 0;
    // 0x80094D48: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80094D4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D50: sw          $zero, 0x7058($at)
    MEM_W(0X7058, ctx->r1) = 0;
    // 0x80094D54: lb          $t7, 0x4C($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X4C);
    // 0x80094D58: nop

    // 0x80094D5C: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80094D60: beq         $t8, $zero, L_80094D78
    if (ctx->r24 == 0) {
        // 0x80094D64: nop
    
            goto L_80094D78;
    }
    // 0x80094D64: nop

    // 0x80094D68: jal         0x8000C8B4
    // 0x80094D6C: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80094D6C: addiu       $a0, $zero, 0xF0
    ctx->r4 = ADD32(0, 0XF0);
    after_5:
    // 0x80094D70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D74: sw          $v0, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r2;
L_80094D78:
    // 0x80094D78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80094D7C: lb          $t0, 0x71E8($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X71E8);
    // 0x80094D80: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80094D84: beq         $t0, $zero, L_80094D9C
    if (ctx->r8 == 0) {
        // 0x80094D88: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80094D9C;
    }
    // 0x80094D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094D8C: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
    // 0x80094D90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80094D94: addiu       $t1, $zero, 0x64
    ctx->r9 = ADD32(0, 0X64);
    // 0x80094D98: sw          $t1, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r9;
L_80094D9C:
    // 0x80094D9C: jal         0x8006DC4C
    // 0x80094DA0: nop

    get_game_mode(rdram, ctx);
        goto after_6;
    // 0x80094DA0: nop

    after_6:
    // 0x80094DA4: beq         $v0, $zero, L_80094DB4
    if (ctx->r2 == 0) {
        // 0x80094DA8: addiu       $t2, $zero, 0x7
        ctx->r10 = ADD32(0, 0X7);
            goto L_80094DB4;
    }
    // 0x80094DA8: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80094DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094DB0: sw          $t2, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r10;
L_80094DB4:
    // 0x80094DB4: jal         0x8009C3A0
    // 0x80094DB8: nop

    reset_controller_sticks(rdram, ctx);
        goto after_7;
    // 0x80094DB8: nop

    after_7:
    // 0x80094DBC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80094DC0: jal         0x8006DB20
    // 0x80094DC4: nop

    race_postrace_type(rdram, ctx);
        goto after_8;
    // 0x80094DC4: nop

    after_8:
    // 0x80094DC8: jal         0x8007A970
    // 0x80094DCC: nop

    fb_size(rdram, ctx);
        goto after_9;
    // 0x80094DCC: nop

    after_9:
    // 0x80094DD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094DD4: addiu       $a1, $a1, 0x6A1C
    ctx->r5 = ADD32(ctx->r5, 0X6A1C);
    // 0x80094DD8: sra         $t3, $v0, 16
    ctx->r11 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80094DDC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x80094DE0: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x80094DE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094DE8: sw          $t4, 0x6A20($at)
    MEM_W(0X6A20, ctx->r1) = ctx->r12;
    // 0x80094DEC: andi        $t6, $v0, 0xFFFF
    ctx->r14 = ctx->r2 & 0XFFFF;
    // 0x80094DF0: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80094DF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80094DF8: lw          $t8, 0x6A20($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A20);
    // 0x80094DFC: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80094E00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094E04: sw          $t7, 0x6A14($at)
    MEM_W(0X6A14, ctx->r1) = ctx->r15;
    // 0x80094E08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094E0C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80094E10: sra         $t0, $t8, 1
    ctx->r8 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80094E14: lw          $t9, -0x5C4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5C4);
    // 0x80094E18: sw          $t0, 0x6A18($at)
    MEM_W(0X6A18, ctx->r1) = ctx->r8;
    // 0x80094E1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80094E20: bne         $t9, $at, L_80094F48
    if (ctx->r25 != ctx->r1) {
        // 0x80094E24: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_80094F48;
    }
    // 0x80094E24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80094E28: lw          $t1, 0x1568($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1568);
    // 0x80094E2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094E30: bne         $t1, $zero, L_80094F48
    if (ctx->r9 != 0) {
        // 0x80094E34: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80094F48;
    }
    // 0x80094E34: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80094E38: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80094E3C: sw          $zero, 0x7230($at)
    MEM_W(0X7230, ctx->r1) = 0;
    // 0x80094E40: lb          $v0, 0x0($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X0);
    // 0x80094E44: addiu       $t6, $t6, 0xC90
    ctx->r14 = ADD32(ctx->r14, 0XC90);
    // 0x80094E48: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80094E4C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80094E50: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80094E54: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80094E58: addu        $v1, $t4, $t6
    ctx->r3 = ADD32(ctx->r12, ctx->r14);
    // 0x80094E5C: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80094E60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094E64: beq         $a0, $at, L_80094E98
    if (ctx->r4 == ctx->r1) {
        // 0x80094E68: nop
    
            goto L_80094E98;
    }
    // 0x80094E68: nop

    // 0x80094E6C: jal         0x8009CC18
    // 0x80094E70: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    menu_asset_load(rdram, ctx);
        goto after_10;
    // 0x80094E70: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_10:
    // 0x80094E74: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80094E78: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80094E7C: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80094E80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094E84: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80094E88: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80094E8C: lw          $t8, 0x6AF0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6AF0);
    // 0x80094E90: b           L_80094EA0
    // 0x80094E94: sw          $t8, 0x7178($at)
    MEM_W(0X7178, ctx->r1) = ctx->r24;
        goto L_80094EA0;
    // 0x80094E94: sw          $t8, 0x7178($at)
    MEM_W(0X7178, ctx->r1) = ctx->r24;
L_80094E98:
    // 0x80094E98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094E9C: sw          $zero, 0x7178($at)
    MEM_W(0X7178, ctx->r1) = 0;
L_80094EA0:
    // 0x80094EA0: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80094EA4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80094EA8: beq         $a0, $at, L_80094EDC
    if (ctx->r4 == ctx->r1) {
        // 0x80094EAC: nop
    
            goto L_80094EDC;
    }
    // 0x80094EAC: nop

    // 0x80094EB0: jal         0x8009CC18
    // 0x80094EB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    menu_asset_load(rdram, ctx);
        goto after_11;
    // 0x80094EB4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_11:
    // 0x80094EB8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80094EBC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80094EC0: lh          $t0, 0x2($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X2);
    // 0x80094EC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094EC8: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80094ECC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x80094ED0: lw          $t1, 0x6AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6AF0);
    // 0x80094ED4: b           L_80094EE4
    // 0x80094ED8: sw          $t1, 0x717C($at)
    MEM_W(0X717C, ctx->r1) = ctx->r9;
        goto L_80094EE4;
    // 0x80094ED8: sw          $t1, 0x717C($at)
    MEM_W(0X717C, ctx->r1) = ctx->r9;
L_80094EDC:
    // 0x80094EDC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094EE0: sw          $zero, 0x717C($at)
    MEM_W(0X717C, ctx->r1) = 0;
L_80094EE4:
    // 0x80094EE4: lh          $t2, 0x4($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X4);
    // 0x80094EE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094EEC: jal         0x8006DC4C
    // 0x80094EF0: sw          $t2, 0x7180($at)
    MEM_W(0X7180, ctx->r1) = ctx->r10;
    get_game_mode(rdram, ctx);
        goto after_12;
    // 0x80094EF0: sw          $t2, 0x7180($at)
    MEM_W(0X7180, ctx->r1) = ctx->r10;
    after_12:
    // 0x80094EF4: bne         $v0, $zero, L_80094F18
    if (ctx->r2 != 0) {
        // 0x80094EF8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80094F18;
    }
    // 0x80094EF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80094EFC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80094F00: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80094F04: lw          $a2, 0x7180($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X7180);
    // 0x80094F08: lw          $a1, 0x717C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X717C);
    // 0x80094F0C: lw          $a0, 0x7178($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7178);
    // 0x80094F10: jal         0x800785C0
    // 0x80094F14: nop

    bgdraw_texture_init(rdram, ctx);
        goto after_13;
    // 0x80094F14: nop

    after_13:
L_80094F18:
    // 0x80094F18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094F1C: jal         0x80066A58
    // 0x80094F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_14;
    // 0x80094F20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80094F24: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80094F28: lw          $t3, 0x6A20($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A20);
    // 0x80094F2C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80094F30: lw          $a3, 0x6A1C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6A1C);
    // 0x80094F34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80094F38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094F3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80094F40: jal         0x80066B80
    // 0x80094F44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_menu_set(rdram, ctx);
        goto after_15;
    // 0x80094F44: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_15:
L_80094F48:
    // 0x80094F48: jal         0x80000968
    // 0x80094F4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    sound_volume_change(rdram, ctx);
        goto after_16;
    // 0x80094F4C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_16:
    // 0x80094F50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80094F54: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80094F58: jr          $ra
    // 0x80094F5C: nop

    return;
    // 0x80094F5C: nop

;}
RECOMP_FUNC void menu_track_select_unload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F9EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8008F9F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8008F9F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008F9F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008F9FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008FA00: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FA04: jal         0x80066AD4
    // 0x8008FA08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_0;
    // 0x8008FA08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8008FA0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008FA10: jal         0x8009C9EC
    // 0x8008FA14: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    menu_assetgroup_free(rdram, ctx);
        goto after_1;
    // 0x8008FA14: addiu       $a0, $a0, 0xD44
    ctx->r4 = ADD32(ctx->r4, 0XD44);
    after_1:
    // 0x8008FA18: jal         0x800712F0
    // 0x8008FA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_2;
    // 0x8008FA1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8008FA20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008FA24: lw          $a0, 0xEF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XEF0);
    // 0x8008FA28: jal         0x80071380
    // 0x8008FA2C: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x8008FA2C: nop

    after_3:
    // 0x8008FA30: jal         0x800712F0
    // 0x8008FA34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_4;
    // 0x8008FA34: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8008FA38: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008FA3C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008FA40: addiu       $s2, $s2, 0xCAE
    ctx->r18 = ADD32(ctx->r18, 0XCAE);
    // 0x8008FA44: addiu       $s0, $s0, 0xC90
    ctx->r16 = ADD32(ctx->r16, 0XC90);
    // 0x8008FA48: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
L_8008FA4C:
    // 0x8008FA4C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8008FA50: nop

    // 0x8008FA54: beq         $s1, $a0, L_8008FA64
    if (ctx->r17 == ctx->r4) {
        // 0x8008FA58: nop
    
            goto L_8008FA64;
    }
    // 0x8008FA58: nop

    // 0x8008FA5C: jal         0x8009CA4C
    // 0x8008FA60: nop

    menu_asset_free(rdram, ctx);
        goto after_5;
    // 0x8008FA60: nop

    after_5:
L_8008FA64:
    // 0x8008FA64: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x8008FA68: nop

    // 0x8008FA6C: beq         $s1, $a0, L_8008FA7C
    if (ctx->r17 == ctx->r4) {
        // 0x8008FA70: nop
    
            goto L_8008FA7C;
    }
    // 0x8008FA70: nop

    // 0x8008FA74: jal         0x8009CA4C
    // 0x8008FA78: nop

    menu_asset_free(rdram, ctx);
        goto after_6;
    // 0x8008FA78: nop

    after_6:
L_8008FA7C:
    // 0x8008FA7C: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
    // 0x8008FA80: bne         $s0, $s2, L_8008FA4C
    if (ctx->r16 != ctx->r18) {
        // 0x8008FA84: nop
    
            goto L_8008FA4C;
    }
    // 0x8008FA84: nop

    // 0x8008FA88: jal         0x800C478C
    // 0x8008FA8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_7;
    // 0x8008FA8C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_7:
    // 0x8008FA90: jal         0x800803D8
    // 0x8008FA94: nop

    menu_button_free(rdram, ctx);
        goto after_8;
    // 0x8008FA94: nop

    after_8:
    // 0x8008FA98: jal         0x80000B28
    // 0x8008FA9C: nop

    music_change_on(rdram, ctx);
        goto after_9;
    // 0x8008FA9C: nop

    after_9:
    // 0x8008FAA0: jal         0x80000C2C
    // 0x8008FAA4: nop

    music_voicelimit_change_on(rdram, ctx);
        goto after_10;
    // 0x8008FAA4: nop

    after_10:
    // 0x8008FAA8: jal         0x80001844
    // 0x8008FAAC: nop

    music_stop(rdram, ctx);
        goto after_11;
    // 0x8008FAAC: nop

    after_11:
    // 0x8008FAB0: jal         0x8006F7A4
    // 0x8008FAB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_gIntDisFlag(rdram, ctx);
        goto after_12;
    // 0x8008FAB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8008FAB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8008FABC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008FAC0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FAC4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008FAC8: jr          $ra
    // 0x8008FACC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8008FACC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void tex_get_table_3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B2A8: lw          $v0, 0x68DC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X68DC);
    // 0x8007B2AC: jr          $ra
    // 0x8007B2B0: nop

    return;
    // 0x8007B2B0: nop

;}
RECOMP_FUNC void reset_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE7D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE7D8: jal         0x800AE8D4
    // 0x800AE7DC: nop

    free_particle_buffers(rdram, ctx);
        goto after_0;
    // 0x800AE7DC: nop

    after_0:
    // 0x800AE7E0: jal         0x800AE998
    // 0x800AE7E4: nop

    free_particle_vertices_triangles(rdram, ctx);
        goto after_1;
    // 0x800AE7E4: nop

    after_1:
    // 0x800AE7E8: jal         0x800AE838
    // 0x800AE7EC: nop

    particle_free_dummy(rdram, ctx);
        goto after_2;
    // 0x800AE7EC: nop

    after_2:
    // 0x800AE7F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE7F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE7F8: jr          $ra
    // 0x800AE7FC: nop

    return;
    // 0x800AE7FC: nop

;}
RECOMP_FUNC void skydome_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028C50: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C54: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028C58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80028C5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80028C60: beq         $t6, $zero, L_80028D00
    if (ctx->r14 == 0) {
        // 0x80028C64: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80028D00;
    }
    // 0x80028C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80028C68: jal         0x80069F60
    // 0x80028C6C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028C6C: nop

    after_0:
    // 0x80028C70: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80028C74: lw          $t7, -0x3174($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3174);
    // 0x80028C78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028C7C: lb          $t8, 0x49($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X49);
    // 0x80028C80: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028C84: bne         $t8, $zero, L_80028CBC
    if (ctx->r24 != 0) {
        // 0x80028C88: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80028CBC;
    }
    // 0x80028C88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028C8C: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80028C90: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80028C94: nop

    // 0x80028C98: swc1        $f4, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f4.u32l;
    // 0x80028C9C: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80028CA0: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80028CA4: nop

    // 0x80028CA8: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80028CAC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80028CB0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80028CB4: nop

    // 0x80028CB8: swc1        $f8, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->f8.u32l;
L_80028CBC:
    // 0x80028CBC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028CC0: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x80028CC4: jal         0x80068648
    // 0x80028CC8: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    mtx_world_origin(rdram, ctx);
        goto after_1;
    // 0x80028CC8: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    after_1:
    // 0x80028CCC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80028CD0: lw          $t2, -0x49A4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X49A4);
    // 0x80028CD4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80028CD8: beq         $t2, $zero, L_80028D00
    if (ctx->r10 == 0) {
        // 0x80028CDC: addiu       $v1, $v1, -0x49C8
        ctx->r3 = ADD32(ctx->r3, -0X49C8);
            goto L_80028D00;
    }
    // 0x80028CDC: addiu       $v1, $v1, -0x49C8
    ctx->r3 = ADD32(ctx->r3, -0X49C8);
    // 0x80028CE0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80028CE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80028CE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80028CEC: lw          $a3, 0x0($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X0);
    // 0x80028CF0: addiu       $a2, $a2, -0x49D8
    ctx->r6 = ADD32(ctx->r6, -0X49D8);
    // 0x80028CF4: addiu       $a1, $a1, -0x49DC
    ctx->r5 = ADD32(ctx->r5, -0X49DC);
    // 0x80028CF8: jal         0x80012D5C
    // 0x80028CFC: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    render_object(rdram, ctx);
        goto after_2;
    // 0x80028CFC: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    after_2:
L_80028D00:
    // 0x80028D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80028D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80028D08: jr          $ra
    // 0x80028D0C: nop

    return;
    // 0x80028D0C: nop

;}
RECOMP_FUNC void write_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074734: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074738: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007473C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074740: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074744: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074748: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007474C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074750: jal         0x8006A340
    // 0x80074754: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074754: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x80074758: jal         0x800CE770
    // 0x8007475C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x8007475C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074760: bne         $v0, $zero, L_80074770
    if (ctx->r2 != 0) {
        // 0x80074764: addiu       $s2, $zero, 0x5
        ctx->r18 = ADD32(0, 0X5);
            goto L_80074770;
    }
    // 0x80074764: addiu       $s2, $zero, 0x5
    ctx->r18 = ADD32(0, 0X5);
    // 0x80074768: b           L_8007480C
    // 0x8007476C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8007480C;
    // 0x8007476C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074770:
    // 0x80074770: beq         $s0, $zero, L_80074794
    if (ctx->r16 == 0) {
        // 0x80074774: addiu       $a0, $zero, 0x28
        ctx->r4 = ADD32(0, 0X28);
            goto L_80074794;
    }
    // 0x80074774: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80074778: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007477C: beq         $s0, $at, L_8007479C
    if (ctx->r16 == ctx->r1) {
        // 0x80074780: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007479C;
    }
    // 0x80074780: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80074784: beq         $s0, $at, L_800747A4
    if (ctx->r16 == ctx->r1) {
        // 0x80074788: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800747A4;
    }
    // 0x80074788: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x8007478C: b           L_800747A4
    // 0x80074790: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800747A4;
    // 0x80074790: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_80074794:
    // 0x80074794: b           L_800747A4
    // 0x80074798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800747A4;
    // 0x80074798: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8007479C:
    // 0x8007479C: b           L_800747A4
    // 0x800747A0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_800747A4;
    // 0x800747A0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800747A4:
    // 0x800747A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800747A8: jal         0x80070EDC
    // 0x800747AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800747AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800747B0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800747B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800747B8: jal         0x80073540
    // 0x800747BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800732E8(rdram, ctx);
        goto after_3;
    // 0x800747BC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x800747C0: jal         0x8006ED00
    // 0x800747C4: nop

    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x800747C4: nop

    after_4:
    // 0x800747C8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800747CC: bne         $v0, $zero, L_80074800
    if (ctx->r2 != 0) {
        // 0x800747D0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074800;
    }
    // 0x800747D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800747D4: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
L_800747D8:
    // 0x800747D8: jal         0x8006A340
    // 0x800747DC: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x800747DC: nop

    after_5:
    // 0x800747E0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800747E4: addu        $a2, $t6, $s3
    ctx->r6 = ADD32(ctx->r14, ctx->r19);
    // 0x800747E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800747EC: jal         0x800CEAE0
    // 0x800747F0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x800747F0: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_6:
    // 0x800747F4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800747F8: bne         $s0, $s2, L_800747D8
    if (ctx->r16 != ctx->r18) {
        // 0x800747FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800747D8;
    }
    // 0x800747FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80074800:
    // 0x80074800: jal         0x80071380
    // 0x80074804: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074804: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_7:
    // 0x80074808: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007480C:
    // 0x8007480C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074810: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074814: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074818: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007481C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80074820: jr          $ra
    // 0x80074824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void weather_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC3C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AC3CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AC3D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800AC3D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800AC3D8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800AC3DC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x800AC3E0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800AC3E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC3E8: sw          $t7, -0x7E34($at)
    MEM_W(-0X7E34, ctx->r1) = ctx->r15;
    // 0x800AC3EC: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800AC3F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC3F4: sw          $t9, -0x7E30($at)
    MEM_W(-0X7E30, ctx->r1) = ctx->r25;
    // 0x800AC3F8: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800AC3FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC400: sw          $t1, -0x7E2C($at)
    MEM_W(-0X7E2C, ctx->r1) = ctx->r9;
    // 0x800AC404: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800AC408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC40C: jal         0x80069F60
    // 0x800AC410: sw          $t3, -0x7E28($at)
    MEM_W(-0X7E28, ctx->r1) = ctx->r11;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x800AC410: sw          $t3, -0x7E28($at)
    MEM_W(-0X7E28, ctx->r1) = ctx->r11;
    after_0:
    // 0x800AC414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC418: jal         0x80069FFC
    // 0x800AC41C: sw          $v0, -0x7E24($at)
    MEM_W(-0X7E24, ctx->r1) = ctx->r2;
    get_camera_matrix(rdram, ctx);
        goto after_1;
    // 0x800AC41C: sw          $v0, -0x7E24($at)
    MEM_W(-0X7E24, ctx->r1) = ctx->r2;
    after_1:
    // 0x800AC420: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800AC424: lw          $t4, 0x31EC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X31EC);
    // 0x800AC428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC42C: beq         $t4, $zero, L_800AC448
    if (ctx->r12 == 0) {
        // 0x800AC430: sw          $v0, -0x7E20($at)
        MEM_W(-0X7E20, ctx->r1) = ctx->r2;
            goto L_800AC448;
    }
    // 0x800AC430: sw          $v0, -0x7E20($at)
    MEM_W(-0X7E20, ctx->r1) = ctx->r2;
    // 0x800AC434: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC438: jal         0x800ADA18
    // 0x800AC43C: nop

    rain_update(rdram, ctx);
        goto after_2;
    // 0x800AC43C: nop

    after_2:
    // 0x800AC440: b           L_800AC5D4
    // 0x800AC444: nop

        goto L_800AC5D4;
    // 0x800AC444: nop

L_800AC448:
    // 0x800AC448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC44C: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800AC450: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x800AC454: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC458: blez        $v1, L_800AC518
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800AC45C: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800AC518;
    }
    // 0x800AC45C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800AC460: beq         $at, $zero, L_800AC4EC
    if (ctx->r1 == 0) {
        // 0x800AC464: nop
    
            goto L_800AC4EC;
    }
    // 0x800AC464: nop

    // 0x800AC468: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800AC46C: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x800AC470: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC474: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x800AC478: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AC47C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x800AC480: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x800AC484: mflo        $t7
    ctx->r15 = lo;
    // 0x800AC488: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800AC48C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AC490: multu       $t0, $a0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC494: lw          $t8, 0x28($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X28);
    // 0x800AC498: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800AC49C: mflo        $t1
    ctx->r9 = lo;
    // 0x800AC4A0: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x800AC4A4: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800AC4A8: multu       $t4, $a0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4AC: lw          $t2, 0x34($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X34);
    // 0x800AC4B0: lw          $t1, 0x30($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X30);
    // 0x800AC4B4: mflo        $t6
    ctx->r14 = lo;
    // 0x800AC4B8: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x800AC4BC: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800AC4C0: multu       $t8, $a0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4C4: sw          $t5, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r13;
    // 0x800AC4C8: sw          $t6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r14;
    // 0x800AC4CC: mflo        $t0
    ctx->r8 = lo;
    // 0x800AC4D0: addu        $t9, $t7, $t0
    ctx->r25 = ADD32(ctx->r15, ctx->r8);
    // 0x800AC4D4: sw          $t9, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r25;
    // 0x800AC4D8: multu       $t2, $a0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC4DC: mflo        $t4
    ctx->r12 = lo;
    // 0x800AC4E0: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800AC4E4: b           L_800AC518
    // 0x800AC4E8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
        goto L_800AC518;
    // 0x800AC4E8: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_800AC4EC:
    // 0x800AC4EC: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x800AC4F0: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x800AC4F4: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800AC4F8: lw          $t0, 0x2C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2C);
    // 0x800AC4FC: lw          $t9, 0x38($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X38);
    // 0x800AC500: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800AC504: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800AC508: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800AC50C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x800AC510: sw          $t0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r8;
    // 0x800AC514: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_800AC518:
    // 0x800AC518: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800AC51C: lw          $t2, -0x7E90($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7E90);
    // 0x800AC520: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AC524: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC528: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC52C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AC530: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AC534: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800AC538: mflo        $t4
    ctx->r12 = lo;
    // 0x800AC53C: sra         $t3, $t4, 16
    ctx->r11 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800AC540: sw          $t3, -0x7E8C($at)
    MEM_W(-0X7E8C, ctx->r1) = ctx->r11;
    // 0x800AC544: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x800AC548: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x800AC54C: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x800AC550: subu        $t5, $t6, $v1
    ctx->r13 = SUB32(ctx->r14, ctx->r3);
    // 0x800AC554: multu       $t5, $t8
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AC558: mflo        $t7
    ctx->r15 = lo;
    // 0x800AC55C: addu        $t0, $v1, $t7
    ctx->r8 = ADD32(ctx->r3, ctx->r15);
    // 0x800AC560: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AC564: jal         0x800AC628
    // 0x800AC568: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    snow_update(rdram, ctx);
        goto after_3;
    // 0x800AC568: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    after_3:
    // 0x800AC56C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800AC570: lw          $t2, -0x7E8C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7E8C);
    // 0x800AC574: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800AC578: blez        $t2, L_800AC5D4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800AC57C: addiu       $a1, $a1, -0x7E48
        ctx->r5 = ADD32(ctx->r5, -0X7E48);
            goto L_800AC5D4;
    }
    // 0x800AC57C: addiu       $a1, $a1, -0x7E48
    ctx->r5 = ADD32(ctx->r5, -0X7E48);
    // 0x800AC580: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800AC584: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800AC588: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800AC58C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800AC590: beq         $at, $zero, L_800AC5D4
    if (ctx->r1 == 0) {
        // 0x800AC594: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_800AC5D4;
    }
    // 0x800AC594: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AC598: lw          $t3, -0x7E38($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E38);
    // 0x800AC59C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC5A0: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x800AC5A4: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x800AC5A8: lw          $t5, 0x2EA4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2EA4);
    // 0x800AC5AC: jal         0x800AC77C
    // 0x800AC5B0: sw          $t5, 0x2E94($at)
    MEM_W(0X2E94, ctx->r1) = ctx->r13;
    snow_vertices(rdram, ctx);
        goto after_4;
    // 0x800AC5B0: sw          $t5, 0x2E94($at)
    MEM_W(0X2E94, ctx->r1) = ctx->r13;
    after_4:
    // 0x800AC5B4: jal         0x800ACB04
    // 0x800AC5B8: nop

    snow_render(rdram, ctx);
        goto after_5;
    // 0x800AC5B8: nop

    after_5:
    // 0x800AC5BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AC5C0: addiu       $v0, $v0, -0x7E38
    ctx->r2 = ADD32(ctx->r2, -0X7E38);
    // 0x800AC5C4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AC5C8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AC5CC: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x800AC5D0: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_800AC5D4:
    // 0x800AC5D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800AC5D8: lw          $t9, -0x7E34($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7E34);
    // 0x800AC5DC: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800AC5E0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800AC5E4: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800AC5E8: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800AC5EC: lw          $t1, -0x7E30($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X7E30);
    // 0x800AC5F0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800AC5F4: sw          $t1, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r9;
    // 0x800AC5F8: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800AC5FC: lw          $t3, -0x7E2C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7E2C);
    // 0x800AC600: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800AC604: sw          $t3, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r11;
    // 0x800AC608: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x800AC60C: lw          $t5, -0x7E28($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7E28);
    // 0x800AC610: nop

    // 0x800AC614: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x800AC618: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AC61C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AC620: jr          $ra
    // 0x800AC624: nop

    return;
    // 0x800AC624: nop

;}
RECOMP_FUNC void func_8007F1E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F638: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x8007F63C: lbu         $t7, 0x15($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X15);
    // 0x8007F640: lbu         $t8, 0x16($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X16);
    // 0x8007F644: lbu         $t9, 0x17($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X17);
    // 0x8007F648: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007F64C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007F650: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8007F654: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8007F658: sb          $t6, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r14;
    // 0x8007F65C: sb          $t7, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r15;
    // 0x8007F660: sb          $t8, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r24;
    // 0x8007F664: blez        $v1, L_8007F694
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007F668: sb          $t9, 0x13($a0)
        MEM_B(0X13, ctx->r4) = ctx->r25;
            goto L_8007F694;
    }
    // 0x8007F668: sb          $t9, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r25;
    // 0x8007F66C: sll         $t0, $v1, 3
    ctx->r8 = S32(ctx->r3 << 3);
    // 0x8007F670: addu        $a1, $t0, $a0
    ctx->r5 = ADD32(ctx->r8, ctx->r4);
    // 0x8007F674: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8007F678:
    // 0x8007F678: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x8007F67C: lw          $t2, 0x18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X18);
    // 0x8007F680: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8007F684: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8007F688: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007F68C: bne         $at, $zero, L_8007F678
    if (ctx->r1 != 0) {
        // 0x8007F690: sw          $t3, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r11;
            goto L_8007F678;
    }
    // 0x8007F690: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_8007F694:
    // 0x8007F694: jr          $ra
    // 0x8007F698: nop

    return;
    // 0x8007F698: nop

;}
RECOMP_FUNC void drm_vehicle_traction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005C3FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C400: lwc1        $f4, 0x6F94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F94);
    // 0x8005C404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C408: jr          $ra
    // 0x8005C40C: swc1        $f4, -0x2EF4($at)
    MEM_W(-0X2EF4, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x8005C40C: swc1        $f4, -0x2EF4($at)
    MEM_W(-0X2EF4, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void racer_ai_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800444BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444C0: sw          $zero, -0x2554($at)
    MEM_W(-0X2554, ctx->r1) = 0;
    // 0x800444C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444C8: sw          $zero, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = 0;
    // 0x800444CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444D0: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800444D4: sw          $zero, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = 0;
    // 0x800444D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444DC: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x800444E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800444E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800444E8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x800444EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800444F0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800444F4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800444F8: sw          $zero, -0x2548($at)
    MEM_W(-0X2548, ctx->r1) = 0;
    // 0x800444FC: jal         0x8001BAA8
    // 0x80044500: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80044500: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x80044504: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80044508: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004450C: bne         $t6, $at, L_8004515C
    if (ctx->r14 != ctx->r1) {
        // 0x80044510: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8004515C;
    }
    // 0x80044510: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80044514: jal         0x8006BFF0
    // 0x80044518: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x80044518: nop

    after_1:
    // 0x8004451C: lb          $t7, 0x4C($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X4C);
    // 0x80044520: addiu       $t8, $v0, 0x2A
    ctx->r24 = ADD32(ctx->r2, 0X2A);
    // 0x80044524: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80044528: sb          $t7, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r15;
    // 0x8004452C: lbu         $t9, 0x1CD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044530: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80044534: bne         $t9, $zero, L_80044578
    if (ctx->r25 != 0) {
        // 0x80044538: nop
    
            goto L_80044578;
    }
    // 0x80044538: nop

    // 0x8004453C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80044540: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80044544: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80044548: jal         0x8001C558
    // 0x8004454C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_2;
    // 0x8004454C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80044550: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044554: beq         $v0, $at, L_80044578
    if (ctx->r2 == ctx->r1) {
        // 0x80044558: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_80044578;
    }
    // 0x80044558: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8004455C: jal         0x8001D248
    // 0x80044560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ainode_get(rdram, ctx);
        goto after_3;
    // 0x80044560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80044564: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80044568: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8004456C: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044570: sb          $t4, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r12;
    // 0x80044574: sb          $t5, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r13;
L_80044578:
    // 0x80044578: lw          $a2, 0x154($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X154);
    // 0x8004457C: nop

    // 0x80044580: beq         $a2, $zero, L_8004464C
    if (ctx->r6 == 0) {
        // 0x80044584: nop
    
            goto L_8004464C;
    }
    // 0x80044584: nop

    // 0x80044588: lw          $t6, 0x3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X3C);
    // 0x8004458C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80044590: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x80044594: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80044598: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004459C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800445A0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800445A4: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800445A8: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800445AC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800445B0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800445B4: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x800445B8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800445BC: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x800445C0: jal         0x800CA030
    // 0x800445C4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x800445C4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_4:
    // 0x800445C8: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800445CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800445D0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800445D4: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800445D8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800445DC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800445E0: bc1f        L_8004464C
    if (!c1cs) {
        // 0x800445E4: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_8004464C;
    }
    // 0x800445E4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800445E8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800445EC: jal         0x80070990
    // 0x800445F0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    arctan2_f(rdram, ctx);
        goto after_5;
    // 0x800445F0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    after_5:
    // 0x800445F4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800445F8: addu        $t7, $v0, $at
    ctx->r15 = ADD32(ctx->r2, ctx->r1);
    // 0x800445FC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80044600: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80044604: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80044608: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8004460C: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x80044610: subu        $v1, $t8, $t4
    ctx->r3 = SUB32(ctx->r24, ctx->r12);
    // 0x80044614: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80044618: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8004461C: bne         $at, $zero, L_8004462C
    if (ctx->r1 != 0) {
        // 0x80044620: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004462C;
    }
    // 0x80044620: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80044624: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80044628: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004462C:
    // 0x8004462C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80044630: beq         $at, $zero, L_8004463C
    if (ctx->r1 == 0) {
        // 0x80044634: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004463C;
    }
    // 0x80044634: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044638: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004463C:
    // 0x8004463C: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x80044640: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80044644: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044648: sw          $t6, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = ctx->r14;
L_8004464C:
    // 0x8004464C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80044650: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80044654: nop

    // 0x80044658: beq         $t7, $zero, L_80044664
    if (ctx->r15 == 0) {
        // 0x8004465C: nop
    
            goto L_80044664;
    }
    // 0x8004465C: nop

    // 0x80044660: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_80044664:
    // 0x80044664: lbu         $v1, 0x1CD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044668: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004466C: beq         $v1, $at, L_80044684
    if (ctx->r3 == ctx->r1) {
        // 0x80044670: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80044684;
    }
    // 0x80044670: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044674: beq         $v1, $at, L_80044684
    if (ctx->r3 == ctx->r1) {
        // 0x80044678: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80044684;
    }
    // 0x80044678: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8004467C: bne         $v1, $at, L_800446A4
    if (ctx->r3 != ctx->r1) {
        // 0x80044680: lw          $t4, 0x78($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X78);
            goto L_800446A4;
    }
    // 0x80044680: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_80044684:
    // 0x80044684: lh          $v0, 0x1C6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044688: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x8004468C: blez        $v0, L_8004469C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80044690: subu        $t8, $v0, $t9
        ctx->r24 = SUB32(ctx->r2, ctx->r25);
            goto L_8004469C;
    }
    // 0x80044690: subu        $t8, $v0, $t9
    ctx->r24 = SUB32(ctx->r2, ctx->r25);
    // 0x80044694: b           L_800446A0
    // 0x80044698: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_800446A0;
    // 0x80044698: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_8004469C:
    // 0x8004469C: sh          $zero, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = 0;
L_800446A0:
    // 0x800446A0: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
L_800446A4:
    // 0x800446A4: nop

    // 0x800446A8: lwc1        $f12, 0x10($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X10);
    // 0x800446AC: jal         0x8001C44C
    // 0x800446B0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    obj_elevation(rdram, ctx);
        goto after_6;
    // 0x800446B0: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    after_6:
    // 0x800446B4: lbu         $v1, 0x1CD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1CD);
    // 0x800446B8: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x800446BC: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x800446C0: sltiu       $at, $t5, 0x7
    ctx->r1 = ctx->r13 < 0X7 ? 1 : 0;
    // 0x800446C4: sb          $v0, 0x212($s0)
    MEM_B(0X212, ctx->r16) = ctx->r2;
    // 0x800446C8: beq         $at, $zero, L_80044FE0
    if (ctx->r1 == 0) {
        // 0x800446CC: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80044FE0;
    }
    // 0x800446CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800446D0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800446D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800446D8: addu        $at, $at, $t5
    gpr jr_addend_800446E4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x800446DC: lw          $t5, 0x68A8($at)
    ctx->r13 = ADD32(ctx->r1, 0X68A8);
    // 0x800446E0: nop

    // 0x800446E4: jr          $t5
    // 0x800446E8: nop

    switch (jr_addend_800446E4 >> 2) {
        case 0: goto L_800446EC; break;
        case 1: goto L_80044A44; break;
        case 2: goto L_80044A44; break;
        case 3: goto L_80044A44; break;
        case 4: goto L_80044A44; break;
        case 5: goto L_80044F94; break;
        case 6: goto L_80044A44; break;
        default: switch_error(__func__, 0x800446E4, 0x800E68A8);
    }
    // 0x800446E8: nop

L_800446EC:
    // 0x800446EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800446F0: jal         0x8006FB8C
    // 0x800446F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800446F4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    after_7:
    // 0x800446F8: lb          $t6, 0x173($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X173);
    // 0x800446FC: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80044700: bne         $t6, $zero, L_800447D8
    if (ctx->r14 != 0) {
        // 0x80044704: nop
    
            goto L_800447D8;
    }
    // 0x80044704: nop

    // 0x80044708: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8004470C: nop

    // 0x80044710: lb          $a0, 0x3($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X3);
    // 0x80044714: jal         0x80044490
    // 0x80044718: nop

    roll_percent_chance(rdram, ctx);
        goto after_8;
    // 0x80044718: nop

    after_8:
    // 0x8004471C: beq         $v0, $zero, L_8004472C
    if (ctx->r2 == 0) {
        // 0x80044720: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_8004472C;
    }
    // 0x80044720: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80044724: b           L_80044FE0
    // 0x80044728: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
        goto L_80044FE0;
    // 0x80044728: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
L_8004472C:
    // 0x8004472C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80044730: nop

    // 0x80044734: lb          $a0, 0x6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X6);
    // 0x80044738: jal         0x80044490
    // 0x8004473C: nop

    roll_percent_chance(rdram, ctx);
        goto after_9;
    // 0x8004473C: nop

    after_9:
    // 0x80044740: beq         $v0, $zero, L_80044778
    if (ctx->r2 == 0) {
        // 0x80044744: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044778;
    }
    // 0x80044744: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80044748: lb          $t4, 0x3F($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X3F);
    // 0x8004474C: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80044750: bne         $t4, $at, L_80044778
    if (ctx->r12 != ctx->r1) {
        // 0x80044754: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044778;
    }
    // 0x80044754: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80044758: lb          $t5, 0x185($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X185);
    // 0x8004475C: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80044760: slti        $at, $t5, 0x2
    ctx->r1 = SIGNED(ctx->r13) < 0X2 ? 1 : 0;
    // 0x80044764: bne         $at, $zero, L_80044778
    if (ctx->r1 != 0) {
        // 0x80044768: lw          $t7, 0x38($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X38);
            goto L_80044778;
    }
    // 0x80044768: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8004476C: b           L_80044FE0
    // 0x80044770: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
        goto L_80044FE0;
    // 0x80044770: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
    // 0x80044774: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
L_80044778:
    // 0x80044778: nop

    // 0x8004477C: lb          $a0, 0x5($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X5);
    // 0x80044780: jal         0x80044490
    // 0x80044784: nop

    roll_percent_chance(rdram, ctx);
        goto after_10;
    // 0x80044784: nop

    after_10:
    // 0x80044788: beq         $v0, $zero, L_800447C4
    if (ctx->r2 == 0) {
        // 0x8004478C: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800447C4;
    }
    // 0x8004478C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80044790: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x80044794: addiu       $t8, $t8, -0x24F4
    ctx->r24 = ADD32(ctx->r24, -0X24F4);
    // 0x80044798: addu        $v0, $t9, $t8
    ctx->r2 = ADD32(ctx->r25, ctx->r24);
    // 0x8004479C: lb          $t4, 0x0($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X0);
    // 0x800447A0: addiu       $t5, $zero, 0x4B0
    ctx->r13 = ADD32(0, 0X4B0);
    // 0x800447A4: beq         $t4, $zero, L_800447C4
    if (ctx->r12 == 0) {
        // 0x800447A8: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_800447C4;
    }
    // 0x800447A8: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800447AC: sh          $t5, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r13;
    // 0x800447B0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x800447B4: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x800447B8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800447BC: b           L_80044FE0
    // 0x800447C0: sb          $t7, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r15;
        goto L_80044FE0;
    // 0x800447C0: sb          $t7, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r15;
L_800447C4:
    // 0x800447C4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800447C8: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x800447CC: sb          $t8, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r24;
    // 0x800447D0: b           L_80044FE0
    // 0x800447D4: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
        goto L_80044FE0;
    // 0x800447D4: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
L_800447D8:
    // 0x800447D8: lb          $a0, 0x6($t5)
    ctx->r4 = MEM_B(ctx->r13, 0X6);
    // 0x800447DC: jal         0x80044490
    // 0x800447E0: nop

    roll_percent_chance(rdram, ctx);
        goto after_11;
    // 0x800447E0: nop

    after_11:
    // 0x800447E4: beq         $v0, $zero, L_8004481C
    if (ctx->r2 == 0) {
        // 0x800447E8: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_8004481C;
    }
    // 0x800447E8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800447EC: lb          $t6, 0x3F($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X3F);
    // 0x800447F0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800447F4: bne         $t6, $at, L_8004481C
    if (ctx->r14 != ctx->r1) {
        // 0x800447F8: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_8004481C;
    }
    // 0x800447F8: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800447FC: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x80044800: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80044804: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x80044808: bne         $at, $zero, L_8004481C
    if (ctx->r1 != 0) {
        // 0x8004480C: lw          $t8, 0x38($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X38);
            goto L_8004481C;
    }
    // 0x8004480C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80044810: b           L_80044FE0
    // 0x80044814: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
        goto L_80044FE0;
    // 0x80044814: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x80044818: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
L_8004481C:
    // 0x8004481C: nop

    // 0x80044820: lb          $a0, 0x0($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X0);
    // 0x80044824: jal         0x80044490
    // 0x80044828: nop

    roll_percent_chance(rdram, ctx);
        goto after_12;
    // 0x80044828: nop

    after_12:
    // 0x8004482C: beq         $v0, $zero, L_80044A34
    if (ctx->r2 == 0) {
        // 0x80044830: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80044A34;
    }
    // 0x80044830: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80044834: jal         0x80044490
    // 0x80044838: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    roll_percent_chance(rdram, ctx);
        goto after_13;
    // 0x80044838: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_13:
    // 0x8004483C: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80044840: beq         $v0, $zero, L_80044850
    if (ctx->r2 == 0) {
        // 0x80044844: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80044850;
    }
    // 0x80044844: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80044848: b           L_80044850
    // 0x8004484C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_80044850;
    // 0x8004484C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80044850:
    // 0x80044850: lb          $a0, 0x1($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X1);
    // 0x80044854: jal         0x80044490
    // 0x80044858: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    roll_percent_chance(rdram, ctx);
        goto after_14;
    // 0x80044858: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    after_14:
    // 0x8004485C: lh          $t2, 0x4C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4C);
    // 0x80044860: beq         $v0, $zero, L_80044870
    if (ctx->r2 == 0) {
        // 0x80044864: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_80044870;
    }
    // 0x80044864: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80044868: b           L_80044874
    // 0x8004486C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80044874;
    // 0x8004486C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80044870:
    // 0x80044870: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044874:
    // 0x80044874: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80044878: sll         $t5, $a3, 20
    ctx->r13 = S32(ctx->r7 << 20);
    // 0x8004487C: sra         $a3, $t5, 16
    ctx->r7 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80044880: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044884:
    // 0x80044884: beq         $t2, $zero, L_800448A0
    if (ctx->r10 == 0) {
        // 0x80044888: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800448A0;
    }
    // 0x80044888: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8004488C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80044890: subu        $a2, $t7, $a1
    ctx->r6 = SUB32(ctx->r15, ctx->r5);
    // 0x80044894: sll         $t9, $a2, 16
    ctx->r25 = S32(ctx->r6 << 16);
    // 0x80044898: b           L_800448AC
    // 0x8004489C: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
        goto L_800448AC;
    // 0x8004489C: sra         $a2, $t9, 16
    ctx->r6 = S32(SIGNED(ctx->r25) >> 16);
L_800448A0:
    // 0x800448A0: sll         $a2, $a1, 16
    ctx->r6 = S32(ctx->r5 << 16);
    // 0x800448A4: sra         $t4, $a2, 16
    ctx->r12 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800448A8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
L_800448AC:
    // 0x800448AC: addu        $t5, $t5, $a2
    ctx->r13 = ADD32(ctx->r13, ctx->r6);
    // 0x800448B0: lb          $t5, -0x24F4($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X24F4);
    // 0x800448B4: nop

    // 0x800448B8: bne         $t5, $zero, L_80044970
    if (ctx->r13 != 0) {
        // 0x800448BC: nop
    
            goto L_80044970;
    }
    // 0x800448BC: nop

    // 0x800448C0: lb          $t6, 0x2($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X2);
    // 0x800448C4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800448C8: beq         $a2, $t6, L_80044970
    if (ctx->r6 == ctx->r14) {
        // 0x800448CC: nop
    
            goto L_80044970;
    }
    // 0x800448CC: nop

    // 0x800448D0: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    // 0x800448D4: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x800448D8: sh          $a3, 0x48($sp)
    MEM_H(0X48, ctx->r29) = ctx->r7;
    // 0x800448DC: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    // 0x800448E0: sh          $t1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r9;
    // 0x800448E4: jal         0x8001BAFC
    // 0x800448E8: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    get_racer_object(rdram, ctx);
        goto after_15;
    // 0x800448E8: sh          $t2, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = ctx->r10;
    after_15:
    // 0x800448EC: lh          $t1, 0x46($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X46);
    // 0x800448F0: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x800448F4: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x800448F8: lh          $a3, 0x48($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X48);
    // 0x800448FC: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x80044900: lh          $t2, 0x4C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X4C);
    // 0x80044904: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80044908: bne         $t1, $zero, L_80044940
    if (ctx->r9 != 0) {
        // 0x8004490C: nop
    
            goto L_80044940;
    }
    // 0x8004490C: nop

    // 0x80044910: lb          $v0, 0x185($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X185);
    // 0x80044914: nop

    // 0x80044918: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004491C: beq         $at, $zero, L_80044970
    if (ctx->r1 == 0) {
        // 0x80044920: nop
    
            goto L_80044970;
    }
    // 0x80044920: nop

    // 0x80044924: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x80044928: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x8004492C: sra         $t7, $a3, 16
    ctx->r15 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80044930: sra         $t9, $t0, 16
    ctx->r25 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80044934: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x80044938: b           L_80044970
    // 0x8004493C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
        goto L_80044970;
    // 0x8004493C: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_80044940:
    // 0x80044940: lb          $v0, 0x185($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X185);
    // 0x80044944: nop

    // 0x80044948: blez        $v0, L_80044970
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8004494C: slt         $at, $v0, $a3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80044970;
    }
    // 0x8004494C: slt         $at, $v0, $a3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80044950: beq         $at, $zero, L_80044970
    if (ctx->r1 == 0) {
        // 0x80044954: nop
    
            goto L_80044970;
    }
    // 0x80044954: nop

    // 0x80044958: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8004495C: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x80044960: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80044964: sra         $t4, $t0, 16
    ctx->r12 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80044968: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8004496C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
L_80044970:
    // 0x80044970: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80044974: sll         $t5, $a1, 16
    ctx->r13 = S32(ctx->r5 << 16);
    // 0x80044978: sra         $a1, $t5, 16
    ctx->r5 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8004497C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80044980: bne         $at, $zero, L_80044884
    if (ctx->r1 != 0) {
        // 0x80044984: nop
    
            goto L_80044884;
    }
    // 0x80044984: nop

    // 0x80044988: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x8004498C: nop

    // 0x80044990: lb          $a0, 0x2($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X2);
    // 0x80044994: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    // 0x80044998: jal         0x80044490
    // 0x8004499C: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    roll_percent_chance(rdram, ctx);
        goto after_16;
    // 0x8004499C: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    after_16:
    // 0x800449A0: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x800449A4: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x800449A8: beq         $v0, $zero, L_800449F0
    if (ctx->r2 == 0) {
        // 0x800449AC: nop
    
            goto L_800449F0;
    }
    // 0x800449AC: nop

    // 0x800449B0: sh          $a2, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r6;
    // 0x800449B4: jal         0x80066450
    // 0x800449B8: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    cam_get_viewport_layout(rdram, ctx);
        goto after_17;
    // 0x800449B8: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_17:
    // 0x800449BC: lh          $a2, 0x50($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X50);
    // 0x800449C0: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x800449C4: bne         $v0, $zero, L_800449F0
    if (ctx->r2 != 0) {
        // 0x800449C8: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_800449F0;
    }
    // 0x800449C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800449CC: jal         0x8001BAFC
    // 0x800449D0: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    get_racer_object(rdram, ctx);
        goto after_18;
    // 0x800449D0: sh          $t0, 0x4A($sp)
    MEM_H(0X4A, ctx->r29) = ctx->r8;
    after_18:
    // 0x800449D4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800449D8: lh          $t0, 0x4A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4A);
    // 0x800449DC: lb          $t9, 0x185($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X185);
    // 0x800449E0: nop

    // 0x800449E4: blez        $t9, L_800449F0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800449E8: nop
    
            goto L_800449F0;
    }
    // 0x800449E8: nop

    // 0x800449EC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800449F0:
    // 0x800449F0: bltz        $t0, L_80044A24
    if (SIGNED(ctx->r8) < 0) {
        // 0x800449F4: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80044A24;
    }
    // 0x800449F4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800449F8: lb          $t8, 0x2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X2);
    // 0x800449FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044A00: sb          $t0, 0x1CF($s0)
    MEM_B(0X1CF, ctx->r16) = ctx->r8;
    // 0x80044A04: addu        $at, $at, $t0
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x80044A08: addiu       $t4, $t8, 0x1
    ctx->r12 = ADD32(ctx->r24, 0X1);
    // 0x80044A0C: sb          $t4, -0x24F4($at)
    MEM_B(-0X24F4, ctx->r1) = ctx->r12;
    // 0x80044A10: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80044A14: addiu       $t6, $zero, 0x4B0
    ctx->r14 = ADD32(0, 0X4B0);
    // 0x80044A18: sb          $t5, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r13;
    // 0x80044A1C: b           L_80044FE0
    // 0x80044A20: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
        goto L_80044FE0;
    // 0x80044A20: sh          $t6, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r14;
L_80044A24:
    // 0x80044A24: addiu       $t9, $zero, 0x4B0
    ctx->r25 = ADD32(0, 0X4B0);
    // 0x80044A28: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x80044A2C: b           L_80044FE0
    // 0x80044A30: sh          $t9, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r25;
        goto L_80044FE0;
    // 0x80044A30: sh          $t9, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r25;
L_80044A34:
    // 0x80044A34: addiu       $t4, $zero, 0x12C
    ctx->r12 = ADD32(0, 0X12C);
    // 0x80044A38: sb          $t8, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r24;
    // 0x80044A3C: b           L_80044FE0
    // 0x80044A40: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
        goto L_80044FE0;
    // 0x80044A40: sh          $t4, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r12;
L_80044A44:
    // 0x80044A44: addiu       $t5, $v1, -0x2
    ctx->r13 = ADD32(ctx->r3, -0X2);
    // 0x80044A48: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80044A4C: beq         $at, $zero, L_80044B1C
    if (ctx->r1 == 0) {
        // 0x80044A50: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80044B1C;
    }
    // 0x80044A50: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80044A54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044A58: addu        $at, $at, $t5
    gpr jr_addend_80044A64 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80044A5C: lw          $t5, 0x68C4($at)
    ctx->r13 = ADD32(ctx->r1, 0X68C4);
    // 0x80044A60: nop

    // 0x80044A64: jr          $t5
    // 0x80044A68: nop

    switch (jr_addend_80044A64 >> 2) {
        case 0: goto L_80044A6C; break;
        case 1: goto L_80044A84; break;
        case 2: goto L_80044AA0; break;
        case 3: goto L_80044AD4; break;
        case 4: goto L_80044B1C; break;
        case 5: goto L_80044B08; break;
        default: switch_error(__func__, 0x80044A64, 0x800E68C4);
    }
    // 0x80044A68: nop

L_80044A6C:
    // 0x80044A6C: lh          $t6, 0x1C6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044A70: nop

    // 0x80044A74: bne         $t6, $zero, L_80044B1C
    if (ctx->r14 != 0) {
        // 0x80044A78: nop
    
            goto L_80044B1C;
    }
    // 0x80044A78: nop

    // 0x80044A7C: b           L_80044B1C
    // 0x80044A80: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
        goto L_80044B1C;
    // 0x80044A80: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044A84:
    // 0x80044A84: lb          $t7, 0x172($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X172);
    // 0x80044A88: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80044A8C: beq         $t7, $zero, L_80044B1C
    if (ctx->r15 == 0) {
        // 0x80044A90: addiu       $t8, $zero, 0xB4
        ctx->r24 = ADD32(0, 0XB4);
            goto L_80044B1C;
    }
    // 0x80044A90: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x80044A94: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x80044A98: b           L_80044B1C
    // 0x80044A9C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
        goto L_80044B1C;
    // 0x80044A9C: sh          $t8, 0x1C6($s0)
    MEM_H(0X1C6, ctx->r16) = ctx->r24;
L_80044AA0:
    // 0x80044AA0: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x80044AA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044AA8: beq         $t4, $zero, L_80044AC0
    if (ctx->r12 == 0) {
        // 0x80044AAC: nop
    
            goto L_80044AC0;
    }
    // 0x80044AAC: nop

    // 0x80044AB0: lh          $t5, 0x1C6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044AB4: nop

    // 0x80044AB8: bne         $t5, $zero, L_80044B1C
    if (ctx->r13 != 0) {
        // 0x80044ABC: nop
    
            goto L_80044B1C;
    }
    // 0x80044ABC: nop

L_80044AC0:
    // 0x80044AC0: lb          $t6, 0x1CF($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044AC4: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
    // 0x80044AC8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80044ACC: b           L_80044B1C
    // 0x80044AD0: sb          $zero, -0x24F4($at)
    MEM_B(-0X24F4, ctx->r1) = 0;
        goto L_80044B1C;
    // 0x80044AD0: sb          $zero, -0x24F4($at)
    MEM_B(-0X24F4, ctx->r1) = 0;
L_80044AD4:
    // 0x80044AD4: lb          $t7, 0x2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X2);
    // 0x80044AD8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80044ADC: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80044AE0: lb          $t9, -0x24F4($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X24F4);
    // 0x80044AE4: nop

    // 0x80044AE8: beq         $t9, $zero, L_80044B00
    if (ctx->r25 == 0) {
        // 0x80044AEC: nop
    
            goto L_80044B00;
    }
    // 0x80044AEC: nop

    // 0x80044AF0: lh          $t8, 0x1C6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C6);
    // 0x80044AF4: nop

    // 0x80044AF8: bne         $t8, $zero, L_80044B1C
    if (ctx->r24 != 0) {
        // 0x80044AFC: nop
    
            goto L_80044B1C;
    }
    // 0x80044AFC: nop

L_80044B00:
    // 0x80044B00: b           L_80044B1C
    // 0x80044B04: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
        goto L_80044B1C;
    // 0x80044B04: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044B08:
    // 0x80044B08: lb          $t4, 0x185($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X185);
    // 0x80044B0C: nop

    // 0x80044B10: bne         $t4, $zero, L_80044B1C
    if (ctx->r12 != 0) {
        // 0x80044B14: nop
    
            goto L_80044B1C;
    }
    // 0x80044B14: nop

    // 0x80044B18: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
L_80044B1C:
    // 0x80044B1C: lbu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044B20: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044B24: beq         $a0, $at, L_80044BC0
    if (ctx->r4 == ctx->r1) {
        // 0x80044B28: nop
    
            goto L_80044BC0;
    }
    // 0x80044B28: nop

    // 0x80044B2C: lb          $v1, 0x212($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X212);
    // 0x80044B30: sw          $a2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r6;
    // 0x80044B34: jal         0x8001D248
    // 0x80044B38: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    ainode_get(rdram, ctx);
        goto after_19;
    // 0x80044B38: sh          $v1, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r3;
    after_19:
    // 0x80044B3C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044B40: lw          $t2, 0x3C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X3C);
    // 0x80044B44: lb          $a0, 0xE($t3)
    ctx->r4 = MEM_B(ctx->r11, 0XE);
    // 0x80044B48: lb          $a1, 0xE($t2)
    ctx->r5 = MEM_B(ctx->r10, 0XE);
    // 0x80044B4C: lh          $v1, 0x4E($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X4E);
    // 0x80044B50: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x80044B54: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80044B58: beq         $at, $zero, L_80044B7C
    if (ctx->r1 == 0) {
        // 0x80044B5C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_80044B7C;
    }
    // 0x80044B5C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80044B60: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80044B64: bne         $at, $zero, L_80044B74
    if (ctx->r1 != 0) {
        // 0x80044B68: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80044B74;
    }
    // 0x80044B68: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80044B6C: beq         $at, $zero, L_80044B94
    if (ctx->r1 == 0) {
        // 0x80044B70: nop
    
            goto L_80044B94;
    }
    // 0x80044B70: nop

L_80044B74:
    // 0x80044B74: b           L_80044B94
    // 0x80044B78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_80044B94;
    // 0x80044B78: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044B7C:
    // 0x80044B7C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80044B80: bne         $at, $zero, L_80044B90
    if (ctx->r1 != 0) {
        // 0x80044B84: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80044B90;
    }
    // 0x80044B84: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80044B88: beq         $at, $zero, L_80044B94
    if (ctx->r1 == 0) {
        // 0x80044B8C: nop
    
            goto L_80044B94;
    }
    // 0x80044B8C: nop

L_80044B90:
    // 0x80044B90: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_80044B94:
    // 0x80044B94: beq         $t1, $zero, L_80044BC0
    if (ctx->r9 == 0) {
        // 0x80044B98: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80044BC0;
    }
    // 0x80044B98: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80044B9C: lbu         $t5, 0x1CD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044BA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044BA4: bne         $t5, $at, L_80044BBC
    if (ctx->r13 != ctx->r1) {
        // 0x80044BA8: nop
    
            goto L_80044BBC;
    }
    // 0x80044BA8: nop

    // 0x80044BAC: lb          $t6, 0x1CF($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044BB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044BB4: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80044BB8: sb          $zero, -0x24F4($at)
    MEM_B(-0X24F4, ctx->r1) = 0;
L_80044BBC:
    // 0x80044BBC: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
L_80044BC0:
    // 0x80044BC0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80044BC4: lw          $v0, -0x254C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X254C);
    // 0x80044BC8: nop

    // 0x80044BCC: slti        $at, $v0, -0x1D
    ctx->r1 = SIGNED(ctx->r2) < -0X1D ? 1 : 0;
    // 0x80044BD0: bne         $at, $zero, L_80044C0C
    if (ctx->r1 != 0) {
        // 0x80044BD4: slti        $at, $v0, 0x1E
        ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
            goto L_80044C0C;
    }
    // 0x80044BD4: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80044BD8: beq         $at, $zero, L_80044C0C
    if (ctx->r1 == 0) {
        // 0x80044BDC: nop
    
            goto L_80044C0C;
    }
    // 0x80044BDC: nop

    // 0x80044BE0: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044BE4: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80044BE8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80044BEC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80044BF0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x80044BF4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x80044BF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044BFC: bc1f        L_80044C6C
    if (!c1cs) {
        // 0x80044C00: ori         $t9, $zero, 0x8000
        ctx->r25 = 0 | 0X8000;
            goto L_80044C6C;
    }
    // 0x80044C00: ori         $t9, $zero, 0x8000
    ctx->r25 = 0 | 0X8000;
    // 0x80044C04: b           L_80044C6C
    // 0x80044C08: sw          $t9, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r25;
        goto L_80044C6C;
    // 0x80044C08: sw          $t9, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r25;
L_80044C0C:
    // 0x80044C0C: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044C10: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80044C14: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80044C18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80044C1C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80044C20: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80044C24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044C28: bc1f        L_80044C40
    if (!c1cs) {
        // 0x80044C2C: addiu       $t4, $zero, 0x4000
        ctx->r12 = ADD32(0, 0X4000);
            goto L_80044C40;
    }
    // 0x80044C2C: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x80044C30: ori         $t8, $zero, 0xC000
    ctx->r24 = 0 | 0XC000;
    // 0x80044C34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044C38: b           L_80044C48
    // 0x80044C3C: sw          $t8, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r24;
        goto L_80044C48;
    // 0x80044C3C: sw          $t8, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r24;
L_80044C40:
    // 0x80044C40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044C44: sw          $t4, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r12;
L_80044C48:
    // 0x80044C48: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044C4C: lui         $at, 0xBFF0
    ctx->r1 = S32(0XBFF0 << 16);
    // 0x80044C50: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80044C54: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80044C58: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x80044C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044C60: bc1f        L_80044C6C
    if (!c1cs) {
        // 0x80044C64: ori         $t5, $zero, 0x8000
        ctx->r13 = 0 | 0X8000;
            goto L_80044C6C;
    }
    // 0x80044C64: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x80044C68: sw          $t5, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r13;
L_80044C6C:
    // 0x80044C6C: lw          $t0, 0x158($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X158);
    // 0x80044C70: nop

    // 0x80044C74: beq         $t0, $zero, L_80044D64
    if (ctx->r8 == 0) {
        // 0x80044C78: nop
    
            goto L_80044D64;
    }
    // 0x80044C78: nop

    // 0x80044C7C: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80044C80: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80044C84: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80044C88: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80044C8C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80044C90: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80044C94: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80044C98: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x80044C9C: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80044CA0: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80044CA4: jal         0x800CA030
    // 0x80044CA8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x80044CA8: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_20:
    // 0x80044CAC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80044CB0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80044CB4: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80044CB8: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80044CBC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80044CC0: bc1f        L_80044D64
    if (!c1cs) {
        // 0x80044CC4: nop
    
            goto L_80044D64;
    }
    // 0x80044CC4: nop

    // 0x80044CC8: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80044CCC: jal         0x80070990
    // 0x80044CD0: nop

    arctan2_f(rdram, ctx);
        goto after_21;
    // 0x80044CD0: nop

    after_21:
    // 0x80044CD4: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80044CD8: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x80044CDC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80044CE0: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x80044CE4: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80044CE8: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80044CEC: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80044CF0: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x80044CF4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80044CF8: bne         $at, $zero, L_80044D08
    if (ctx->r1 != 0) {
        // 0x80044CFC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80044D08;
    }
    // 0x80044CFC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80044D00: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80044D04: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80044D08:
    // 0x80044D08: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80044D0C: beq         $at, $zero, L_80044D18
    if (ctx->r1 == 0) {
        // 0x80044D10: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80044D18;
    }
    // 0x80044D10: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80044D14: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80044D18:
    // 0x80044D18: slti        $at, $v1, 0x1501
    ctx->r1 = SIGNED(ctx->r3) < 0X1501 ? 1 : 0;
    // 0x80044D1C: beq         $at, $zero, L_80044D2C
    if (ctx->r1 == 0) {
        // 0x80044D20: slti        $at, $v1, -0x1500
        ctx->r1 = SIGNED(ctx->r3) < -0X1500 ? 1 : 0;
            goto L_80044D2C;
    }
    // 0x80044D20: slti        $at, $v1, -0x1500
    ctx->r1 = SIGNED(ctx->r3) < -0X1500 ? 1 : 0;
    // 0x80044D24: beq         $at, $zero, L_80044D64
    if (ctx->r1 == 0) {
        // 0x80044D28: nop
    
            goto L_80044D64;
    }
    // 0x80044D28: nop

L_80044D2C:
    // 0x80044D2C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80044D30: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80044D34: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80044D38: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044D3C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80044D40: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x80044D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044D48: bc1f        L_80044D60
    if (!c1cs) {
        // 0x80044D4C: addiu       $t5, $zero, 0x4000
        ctx->r13 = ADD32(0, 0X4000);
            goto L_80044D60;
    }
    // 0x80044D4C: addiu       $t5, $zero, 0x4000
    ctx->r13 = ADD32(0, 0X4000);
    // 0x80044D50: ori         $t4, $zero, 0xC000
    ctx->r12 = 0 | 0XC000;
    // 0x80044D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80044D58: b           L_80044D64
    // 0x80044D5C: sw          $t4, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r12;
        goto L_80044D64;
    // 0x80044D5C: sw          $t4, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r12;
L_80044D60:
    // 0x80044D60: sw          $t5, -0x2558($at)
    MEM_W(-0X2558, ctx->r1) = ctx->r13;
L_80044D64:
    // 0x80044D64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80044D68: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80044D6C: lwc1        $f19, 0x68E0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X68E0);
    // 0x80044D70: lwc1        $f18, 0x68E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X68E4);
    // 0x80044D74: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80044D78: c.lt.d      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.d < ctx->f18.d;
    // 0x80044D7C: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044D80: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x80044D84: bc1f        L_80044F20
    if (!c1cs) {
        // 0x80044D88: swc1        $f5, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_80044F20;
    }
    // 0x80044D88: swc1        $f5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
    // 0x80044D8C: lw          $t6, 0x158($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X158);
    // 0x80044D90: nop

    // 0x80044D94: bne         $t6, $zero, L_80044F24
    if (ctx->r14 != 0) {
        // 0x80044D98: lui         $at, 0x4049
        ctx->r1 = S32(0X4049 << 16);
            goto L_80044F24;
    }
    // 0x80044D98: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80044D9C: lbu         $v0, 0x1CD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1CD);
    // 0x80044DA0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80044DA4: beq         $v0, $at, L_80044DDC
    if (ctx->r2 == ctx->r1) {
        // 0x80044DA8: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80044DDC;
    }
    // 0x80044DA8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80044DAC: beq         $v0, $at, L_80044DF8
    if (ctx->r2 == ctx->r1) {
        // 0x80044DB0: nop
    
            goto L_80044DF8;
    }
    // 0x80044DB0: nop

    // 0x80044DB4: lbu         $t9, 0x1CE($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044DB8: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044DBC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80044DC0: beq         $v0, $at, L_80044E80
    if (ctx->r2 == ctx->r1) {
        // 0x80044DC4: sw          $t9, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r25;
            goto L_80044E80;
    }
    // 0x80044DC4: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80044DC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80044DCC: beq         $v0, $at, L_80044E98
    if (ctx->r2 == ctx->r1) {
        // 0x80044DD0: nop
    
            goto L_80044E98;
    }
    // 0x80044DD0: nop

    // 0x80044DD4: b           L_80044EB4
    // 0x80044DD8: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
        goto L_80044EB4;
    // 0x80044DD8: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
L_80044DDC:
    // 0x80044DDC: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044DE0: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044DE4: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044DE8: jal         0x8001CD5C
    // 0x80044DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001CD28(rdram, ctx);
        goto after_22;
    // 0x80044DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80044DF0: b           L_80044EC4
    // 0x80044DF4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044EC4;
    // 0x80044DF4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044DF8:
    // 0x80044DF8: lb          $a0, 0x1CF($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1CF);
    // 0x80044DFC: jal         0x8001BAFC
    // 0x80044E00: nop

    get_racer_object(rdram, ctx);
        goto after_23;
    // 0x80044E00: nop

    after_23:
    // 0x80044E04: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80044E08: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80044E0C: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80044E10: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x80044E14: bne         $t7, $at, L_80044E48
    if (ctx->r15 != ctx->r1) {
        // 0x80044E18: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80044E48;
    }
    // 0x80044E18: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80044E1C: lw          $t0, 0x154($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X154);
    // 0x80044E20: lbu         $a0, 0x9($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X9);
    // 0x80044E24: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x80044E28: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044E2C: lbu         $a1, 0x9($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X9);
    // 0x80044E30: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044E34: ori         $t4, $a1, 0x100
    ctx->r12 = ctx->r5 | 0X100;
    // 0x80044E38: jal         0x8001CD5C
    // 0x80044E3C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    func_8001CD28(rdram, ctx);
        goto after_24;
    // 0x80044E3C: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    after_24:
    // 0x80044E40: b           L_80044EC4
    // 0x80044E44: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044EC4;
    // 0x80044E44: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E48:
    // 0x80044E48: lwc1        $f12, 0xC($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80044E4C: lwc1        $f14, 0x10($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80044E50: lw          $a2, 0x14($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X14);
    // 0x80044E54: jal         0x8001C558
    // 0x80044E58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_25;
    // 0x80044E58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_25:
    // 0x80044E5C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044E60: lw          $t5, 0x6C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X6C);
    // 0x80044E64: lb          $a3, 0x2($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X2);
    // 0x80044E68: lbu         $a2, 0x1CE($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044E6C: lbu         $a0, 0x9($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X9);
    // 0x80044E70: jal         0x8001CD5C
    // 0x80044E74: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    func_8001CD28(rdram, ctx);
        goto after_26;
    // 0x80044E74: ori         $a1, $v0, 0x100
    ctx->r5 = ctx->r2 | 0X100;
    after_26:
    // 0x80044E78: b           L_80044EC4
    // 0x80044E7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044EC4;
    // 0x80044E7C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E80:
    // 0x80044E80: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044E84: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80044E88: jal         0x8001CD5C
    // 0x80044E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_8001CD28(rdram, ctx);
        goto after_27;
    // 0x80044E8C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80044E90: b           L_80044EC4
    // 0x80044E94: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044EC4;
    // 0x80044E94: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044E98:
    // 0x80044E98: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
    // 0x80044E9C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80044EA0: jal         0x8001CD5C
    // 0x80044EA4: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    func_8001CD28(rdram, ctx);
        goto after_28;
    // 0x80044EA4: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    after_28:
    // 0x80044EA8: b           L_80044EC4
    // 0x80044EAC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
        goto L_80044EC4;
    // 0x80044EAC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044EB0: lbu         $a0, 0x9($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X9);
L_80044EB4:
    // 0x80044EB4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80044EB8: jal         0x8001CC7C
    // 0x80044EBC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    ainode_find_next(rdram, ctx);
        goto after_29;
    // 0x80044EBC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_29:
    // 0x80044EC0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
L_80044EC4:
    // 0x80044EC4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044EC8: beq         $v0, $at, L_80044EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80044ECC: nop
    
            goto L_80044EEC;
    }
    // 0x80044ECC: nop

    // 0x80044ED0: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x80044ED4: jal         0x8001D248
    // 0x80044ED8: nop

    ainode_get(rdram, ctx);
        goto after_30;
    // 0x80044ED8: nop

    after_30:
    // 0x80044EDC: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    // 0x80044EE0: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044EE4: b           L_80044F24
    // 0x80044EE8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
        goto L_80044F24;
    // 0x80044EE8: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044EEC:
    // 0x80044EEC: lbu         $a0, 0x1CE($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1CE);
    // 0x80044EF0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044EF4: beq         $a0, $at, L_80044F14
    if (ctx->r4 == ctx->r1) {
        // 0x80044EF8: nop
    
            goto L_80044F14;
    }
    // 0x80044EF8: nop

    // 0x80044EFC: jal         0x8001D248
    // 0x80044F00: nop

    ainode_get(rdram, ctx);
        goto after_31;
    // 0x80044F00: nop

    after_31:
    // 0x80044F04: sw          $v0, 0x158($s0)
    MEM_W(0X158, ctx->r16) = ctx->r2;
    // 0x80044F08: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044F0C: b           L_80044F24
    // 0x80044F10: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
        goto L_80044F24;
    // 0x80044F10: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044F14:
    // 0x80044F14: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
    // 0x80044F18: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x80044F1C: nop

L_80044F20:
    // 0x80044F20: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
L_80044F24:
    // 0x80044F24: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80044F28: lwc1        $f9, 0x20($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80044F2C: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80044F30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80044F34: lui         $at, 0x4074
    ctx->r1 = S32(0X4074 << 16);
    // 0x80044F38: c.lt.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d < ctx->f6.d;
    // 0x80044F3C: nop

    // 0x80044F40: bc1t        L_80044F74
    if (c1cs) {
        // 0x80044F44: nop
    
            goto L_80044F74;
    }
    // 0x80044F44: nop

    // 0x80044F48: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80044F4C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80044F50: nop

    // 0x80044F54: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80044F58: nop

    // 0x80044F5C: bc1f        L_80044FE4
    if (!c1cs) {
        // 0x80044F60: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80044FE4;
    }
    // 0x80044F60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80044F64: lw          $t6, 0x158($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X158);
    // 0x80044F68: nop

    // 0x80044F6C: beq         $t6, $zero, L_80044FE4
    if (ctx->r14 == 0) {
        // 0x80044F70: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80044FE4;
    }
    // 0x80044F70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044F74:
    // 0x80044F74: lbu         $t9, 0x9($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X9);
    // 0x80044F78: lw          $v0, 0x158($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X158);
    // 0x80044F7C: sb          $t9, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r25;
    // 0x80044F80: bne         $v0, $zero, L_80044F8C
    if (ctx->r2 != 0) {
        // 0x80044F84: sw          $v0, 0x154($s0)
        MEM_W(0X154, ctx->r16) = ctx->r2;
            goto L_80044F8C;
    }
    // 0x80044F84: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044F88: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
L_80044F8C:
    // 0x80044F8C: b           L_80044FE0
    // 0x80044F90: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
        goto L_80044FE0;
    // 0x80044F90: sw          $zero, 0x158($s0)
    MEM_W(0X158, ctx->r16) = 0;
L_80044F94:
    // 0x80044F94: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80044F98: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80044F9C: lwc1        $f12, 0xC($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0XC);
    // 0x80044FA0: lwc1        $f14, 0x10($t7)
    ctx->f14.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80044FA4: lw          $a2, 0x14($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X14);
    // 0x80044FA8: jal         0x8001C558
    // 0x80044FAC: nop

    ainode_find_nearest(rdram, ctx);
        goto after_32;
    // 0x80044FAC: nop

    after_32:
    // 0x80044FB0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80044FB4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044FB8: beq         $v0, $at, L_80044FDC
    if (ctx->r2 == ctx->r1) {
        // 0x80044FBC: sw          $v0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r2;
            goto L_80044FDC;
    }
    // 0x80044FBC: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x80044FC0: jal         0x8001D248
    // 0x80044FC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ainode_get(rdram, ctx);
        goto after_33;
    // 0x80044FC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_33:
    // 0x80044FC8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80044FCC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80044FD0: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80044FD4: sb          $a1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r5;
    // 0x80044FD8: sb          $t8, 0x1CE($s0)
    MEM_B(0X1CE, ctx->r16) = ctx->r24;
L_80044FDC:
    // 0x80044FDC: sb          $a1, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = ctx->r5;
L_80044FE0:
    // 0x80044FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80044FE4:
    // 0x80044FE4: lb          $t4, 0x2($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X2);
    // 0x80044FE8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80044FEC: beq         $a1, $t4, L_80045140
    if (ctx->r5 == ctx->r12) {
        // 0x80044FF0: nop
    
            goto L_80045140;
    }
    // 0x80044FF0: nop

    // 0x80044FF4: jal         0x8001BAFC
    // 0x80044FF8: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_34;
    // 0x80044FF8: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    after_34:
    // 0x80044FFC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80045000: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x80045004: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x80045008: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004500C: beq         $t5, $at, L_80045024
    if (ctx->r13 == ctx->r1) {
        // 0x80045010: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80045024;
    }
    // 0x80045010: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80045014: lb          $t6, 0x212($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X212);
    // 0x80045018: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8004501C: addu        $at, $at, $a1
    ctx->r1 = ADD32(ctx->r1, ctx->r5);
    // 0x80045020: sb          $t6, -0x24CC($at)
    MEM_B(-0X24CC, ctx->r1) = ctx->r14;
L_80045024:
    // 0x80045024: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80045028: lb          $t9, 0x2($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X2);
    // 0x8004502C: addiu       $t7, $t7, -0x24CC
    ctx->r15 = ADD32(ctx->r15, -0X24CC);
    // 0x80045030: addu        $t5, $a1, $t7
    ctx->r13 = ADD32(ctx->r5, ctx->r15);
    // 0x80045034: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x80045038: lb          $t4, 0x0($t8)
    ctx->r12 = MEM_B(ctx->r24, 0X0);
    // 0x8004503C: lb          $t6, 0x0($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X0);
    // 0x80045040: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80045044: bne         $t4, $t6, L_80045140
    if (ctx->r12 != ctx->r14) {
        // 0x80045048: nop
    
            goto L_80045140;
    }
    // 0x80045048: nop

    // 0x8004504C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80045050: lwc1        $f4, 0xC($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0XC);
    // 0x80045054: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80045058: sub.s       $f0, $f16, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8004505C: lwc1        $f6, 0x14($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80045060: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80045064: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80045068: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8004506C: swc1        $f14, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f14.u32l;
    // 0x80045070: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80045074: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    // 0x80045078: jal         0x800CA030
    // 0x8004507C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_35;
    // 0x8004507C: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
    after_35:
    // 0x80045080: lui         $at, 0x4089
    ctx->r1 = S32(0X4089 << 16);
    // 0x80045084: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80045088: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8004508C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80045090: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80045094: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x80045098: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8004509C: bc1f        L_80045140
    if (!c1cs) {
        // 0x800450A0: nop
    
            goto L_80045140;
    }
    // 0x800450A0: nop

    // 0x800450A4: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800450A8: jal         0x80070990
    // 0x800450AC: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_36;
    // 0x800450AC: sh          $a1, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r5;
    after_36:
    // 0x800450B0: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800450B4: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x800450B8: lh          $t8, 0x0($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X0);
    // 0x800450BC: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800450C0: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800450C4: subu        $t5, $v0, $t7
    ctx->r13 = SUB32(ctx->r2, ctx->r15);
    // 0x800450C8: lh          $a1, 0x52($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X52);
    // 0x800450CC: slt         $at, $t5, $at
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800450D0: bne         $at, $zero, L_800450E4
    if (ctx->r1 != 0) {
        // 0x800450D4: sw          $t5, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r13;
            goto L_800450E4;
    }
    // 0x800450D4: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x800450D8: lui         $t6, 0xFFFF
    ctx->r14 = S32(0XFFFF << 16);
    // 0x800450DC: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x800450E0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
L_800450E4:
    // 0x800450E4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800450E8: ori         $t8, $zero, 0xFFFF
    ctx->r24 = 0 | 0XFFFF;
    // 0x800450EC: slti        $at, $t9, -0x8000
    ctx->r1 = SIGNED(ctx->r25) < -0X8000 ? 1 : 0;
    // 0x800450F0: beq         $at, $zero, L_800450FC
    if (ctx->r1 == 0) {
        // 0x800450F4: addiu       $v1, $zero, 0x800
        ctx->r3 = ADD32(0, 0X800);
            goto L_800450FC;
    }
    // 0x800450F4: addiu       $v1, $zero, 0x800
    ctx->r3 = ADD32(0, 0X800);
    // 0x800450F8: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
L_800450FC:
    // 0x800450FC: lb          $t7, 0x174($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X174);
    // 0x80045100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80045104: bne         $t7, $at, L_80045114
    if (ctx->r15 != ctx->r1) {
        // 0x80045108: nop
    
            goto L_80045114;
    }
    // 0x80045108: nop

    // 0x8004510C: b           L_80045114
    // 0x80045110: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
        goto L_80045114;
    // 0x80045110: addiu       $v1, $zero, 0x1000
    ctx->r3 = ADD32(0, 0X1000);
L_80045114:
    // 0x80045114: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80045118: negu        $t5, $v1
    ctx->r13 = SUB32(0, ctx->r3);
    // 0x8004511C: slt         $at, $t5, $t4
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80045120: beq         $at, $zero, L_80045140
    if (ctx->r1 == 0) {
        // 0x80045124: slt         $at, $t4, $v1
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80045140;
    }
    // 0x80045124: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80045128: beq         $at, $zero, L_80045140
    if (ctx->r1 == 0) {
        // 0x8004512C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80045140;
    }
    // 0x8004512C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80045130: lw          $t6, -0x2550($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2550);
    // 0x80045134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80045138: ori         $t9, $t6, 0x2000
    ctx->r25 = ctx->r14 | 0X2000;
    // 0x8004513C: sw          $t9, -0x2550($at)
    MEM_W(-0X2550, ctx->r1) = ctx->r25;
L_80045140:
    // 0x80045140: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80045144: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80045148: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8004514C: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80045150: bne         $at, $zero, L_80044FE4
    if (ctx->r1 != 0) {
        // 0x80045154: nop
    
            goto L_80044FE4;
    }
    // 0x80045154: nop

    // 0x80045158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8004515C:
    // 0x8004515C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80045160: jr          $ra
    // 0x80045164: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80045164: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void thread3_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006C574: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006C578: jal         0x8006C620
    // 0x8006C57C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    init_game(rdram, ctx);
        goto after_0;
    // 0x8006C57C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006C580: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C584: lw          $a0, -0x2714($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2714);
    // 0x8006C588: jal         0x8006A404
    // 0x8006C58C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    input_update(rdram, ctx);
        goto after_1;
    // 0x8006C58C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8006C590: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C594: sw          $v0, -0x2714($at)
    MEM_W(-0X2714, ctx->r1) = ctx->r2;
    // 0x8006C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C59C: sw          $zero, 0x3AA0($at)
    MEM_W(0X3AA0, ctx->r1) = 0;
    // 0x8006C5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006C5A4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8006C5A8: sw          $t6, 0x3A6C($at)
    MEM_W(0X3A6C, ctx->r1) = ctx->r14;
L_8006C5AC:
    // 0x8006C5AC: jal         0x8006ED00
    // 0x8006C5B0: nop

    is_reset_pressed(rdram, ctx);
        goto after_2;
    // 0x8006C5B0: nop

    after_2:
    // 0x8006C5B4: beq         $v0, $zero, L_8006C5F0
    if (ctx->r2 == 0) {
        // 0x8006C5B8: nop
    
            goto L_8006C5F0;
    }
    // 0x8006C5B8: nop

    // 0x8006C5BC: jal         0x80072954
    // 0x8006C5C0: nop

    rumble_kill(rdram, ctx);
        goto after_3;
    // 0x8006C5C0: nop

    after_3:
    // 0x8006C5C4: jal         0x80002A74
    // 0x8006C5C8: nop

    audioStopThread(rdram, ctx);
        goto after_4;
    // 0x8006C5C8: nop

    after_4:
    // 0x8006C5CC: jal         0x800C791C
    // 0x8006C5D0: nop

    bgload_kill(rdram, ctx);
        goto after_5;
    // 0x8006C5D0: nop

    after_5:
    // 0x8006C5D4: lui         $a0, 0xAA
    ctx->r4 = S32(0XAA << 16);
    // 0x8006C5D8: jal         0x800CD7A0
    // 0x8006C5DC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    __osSpSetStatus_recomp(rdram, ctx);
        goto after_6;
    // 0x8006C5DC: ori         $a0, $a0, 0xAA82
    ctx->r4 = ctx->r4 | 0XAA82;
    after_6:
    // 0x8006C5E0: jal         0x800CD7B0
    // 0x8006C5E4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    osDpSetStatus_recomp(rdram, ctx);
        goto after_7;
    // 0x8006C5E4: addiu       $a0, $zero, 0x1D6
    ctx->r4 = ADD32(0, 0X1D6);
    after_7:
L_8006C5E8:
    // 0x8006C5E8: b           L_8006C5E8
    pause_self(rdram);
    // 0x8006C5EC: nop

L_8006C5F0:
    // 0x8006C5F0: jal         0x8006C84C
    // 0x8006C5F4: nop

    main_game_loop(rdram, ctx);
        goto after_8;
    // 0x8006C5F4: nop

    after_8:
    // 0x8006C5F8: jal         0x80066070
    // 0x8006C5FC: nop

    thread3_verify_stack(rdram, ctx);
        goto after_9;
    // 0x8006C5FC: nop

    after_9:
    // 0x8006C600: b           L_8006C5AC
    // 0x8006C604: nop

        goto L_8006C5AC;
    // 0x8006C604: nop

    // 0x8006C608: nop

    // 0x8006C60C: nop

    // 0x8006C610: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006C614: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006C618: jr          $ra
    // 0x8006C61C: nop

    return;
    // 0x8006C61C: nop

;}
RECOMP_FUNC void alEnvmixerNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80065098: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8006509C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800650A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800650A4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800650A8: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x800650AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800650B0: addiu       $a2, $a2, -0x5024
    ctx->r6 = ADD32(ctx->r6, -0X5024);
    // 0x800650B4: addiu       $a1, $a1, -0x59D0
    ctx->r5 = ADD32(ctx->r5, -0X59D0);
    // 0x800650B8: jal         0x800CA610
    // 0x800650BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800650BC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_0:
    // 0x800650C0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800650C4: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x800650C8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800650CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800650D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800650D4: jal         0x800C7D50
    // 0x800650D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_1;
    // 0x800650D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x800650DC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800650E0: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800650E4: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x800650E8: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x800650EC: sh          $v1, 0x1A($s0)
    MEM_H(0X1A, ctx->r16) = ctx->r3;
    // 0x800650F0: sh          $v1, 0x28($s0)
    MEM_H(0X28, ctx->r16) = ctx->r3;
    // 0x800650F4: sh          $v1, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r3;
    // 0x800650F8: sh          $v1, 0x1C($s0)
    MEM_H(0X1C, ctx->r16) = ctx->r3;
    // 0x800650FC: sh          $v1, 0x1E($s0)
    MEM_H(0X1E, ctx->r16) = ctx->r3;
    // 0x80065100: sh          $zero, 0x20($s0)
    MEM_H(0X20, ctx->r16) = 0;
    // 0x80065104: sh          $zero, 0x22($s0)
    MEM_H(0X22, ctx->r16) = 0;
    // 0x80065108: sh          $v1, 0x26($s0)
    MEM_H(0X26, ctx->r16) = ctx->r3;
    // 0x8006510C: sh          $zero, 0x24($s0)
    MEM_H(0X24, ctx->r16) = 0;
    // 0x80065110: sw          $zero, 0x30($s0)
    MEM_W(0X30, ctx->r16) = 0;
    // 0x80065114: sw          $zero, 0x34($s0)
    MEM_W(0X34, ctx->r16) = 0;
    // 0x80065118: sh          $zero, 0x18($s0)
    MEM_H(0X18, ctx->r16) = 0;
    // 0x8006511C: sw          $zero, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = 0;
    // 0x80065120: sw          $zero, 0x40($s0)
    MEM_W(0X40, ctx->r16) = 0;
    // 0x80065124: sw          $zero, 0x44($s0)
    MEM_W(0X44, ctx->r16) = 0;
    // 0x80065128: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006512C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80065130: jr          $ra
    // 0x80065134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065134: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mode_lockup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7CF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B7CF8: addiu       $v0, $v0, 0x35B8
    ctx->r2 = ADD32(ctx->r2, 0X35B8);
    // 0x800B7CFC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B7D00: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7D04: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800B7D08: slti        $at, $t7, 0x3D
    ctx->r1 = SIGNED(ctx->r15) < 0X3D ? 1 : 0;
    // 0x800B7D0C: bne         $at, $zero, L_800B7D28
    if (ctx->r1 != 0) {
        // 0x800B7D10: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_800B7D28;
    }
    // 0x800B7D10: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B7D14: addiu       $v1, $v1, 0x35B4
    ctx->r3 = ADD32(ctx->r3, 0X35B4);
    // 0x800B7D18: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800B7D1C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7D20: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B7D24: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800B7D28:
    // 0x800B7D28: jr          $ra
    // 0x800B7D2C: nop

    return;
    // 0x800B7D2C: nop

;}
RECOMP_FUNC void obj_init_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038DA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80038DA4: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DA8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80038DAC: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80038DB0: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DB4: addiu       $t9, $zero, 0xF
    ctx->r25 = ADD32(0, 0XF);
    // 0x80038DB8: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80038DBC: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DC0: nop

    // 0x80038DC4: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x80038DC8: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80038DCC: nop

    // 0x80038DD0: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x80038DD4: jal         0x8006ECD0
    // 0x80038DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80038DD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038DDC: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80038DE0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038DE4: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80038DE8: beq         $t3, $zero, L_80038DF4
    if (ctx->r11 == 0) {
        // 0x80038DEC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80038DF4;
    }
    // 0x80038DEC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80038DF0: sw          $t4, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r12;
L_80038DF4:
    // 0x80038DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038DF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038DFC: jr          $ra
    // 0x80038E00: nop

    return;
    // 0x80038E00: nop

;}
RECOMP_FUNC void add_shading_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D2D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D2DC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8001D2E0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8001D2E4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D2E8: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D2EC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D2F0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D2F4: beq         $s0, $zero, L_8001D4D4
    if (ctx->r16 == 0) {
        // 0x8001D2F8: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_8001D4D4;
    }
    // 0x8001D2F8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8001D2FC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D300: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001D304: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8001D308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001D30C: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x8001D310: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D314: nop

    // 0x8001D318: lwc1        $f0, 0x28($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8001D31C: nop

    // 0x8001D320: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D324: nop

    // 0x8001D328: bc1f        L_8001D340
    if (!c1cs) {
        // 0x8001D32C: nop
    
            goto L_8001D340;
    }
    // 0x8001D32C: nop

    // 0x8001D330: swc1        $f2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f2.u32l;
    // 0x8001D334: lw          $s0, 0x54($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X54);
    // 0x8001D338: b           L_8001D368
    // 0x8001D33C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
        goto L_8001D368;
    // 0x8001D33C: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D340:
    // 0x8001D340: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8001D344: nop

    // 0x8001D348: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001D34C: nop

    // 0x8001D350: bc1f        L_8001D364
    if (!c1cs) {
        // 0x8001D354: nop
    
            goto L_8001D364;
    }
    // 0x8001D354: nop

    // 0x8001D358: swc1        $f12, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f12.u32l;
    // 0x8001D35C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D360: nop

L_8001D364:
    // 0x8001D364: lwc1        $f8, 0x2C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X2C);
L_8001D368:
    // 0x8001D368: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8001D36C: add.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x8001D370: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001D374: swc1        $f10, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f10.u32l;
    // 0x8001D378: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D37C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001D380: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D384: nop

    // 0x8001D388: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001D38C: nop

    // 0x8001D390: bc1f        L_8001D3AC
    if (!c1cs) {
        // 0x8001D394: nop
    
            goto L_8001D3AC;
    }
    // 0x8001D394: nop

    // 0x8001D398: swc1        $f2, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f2.u32l;
    // 0x8001D39C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D3A0: nop

    // 0x8001D3A4: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D3A8: nop

L_8001D3AC:
    // 0x8001D3AC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x8001D3B0: nop

    // 0x8001D3B4: bc1f        L_8001D3D8
    if (!c1cs) {
        // 0x8001D3B8: nop
    
            goto L_8001D3D8;
    }
    // 0x8001D3B8: nop

    // 0x8001D3BC: lwc1        $f18, 0x5BF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5BF0);
    // 0x8001D3C0: nop

    // 0x8001D3C4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8001D3C8: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D3CC: nop

    // 0x8001D3D0: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8001D3D4: nop

L_8001D3D8:
    // 0x8001D3D8: lh          $t0, 0x24($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X24);
    // 0x8001D3DC: lh          $t1, 0x3A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X3A);
    // 0x8001D3E0: lh          $t6, 0x22($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X22);
    // 0x8001D3E4: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x8001D3E8: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8001D3EC: lh          $t7, 0x36($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X36);
    // 0x8001D3F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8001D3F4: lh          $t3, 0x26($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X26);
    // 0x8001D3F8: lh          $t4, 0x3E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X3E);
    // 0x8001D3FC: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D400: sll         $t8, $a3, 16
    ctx->r24 = S32(ctx->r7 << 16);
    // 0x8001D404: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8001D408: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8001D40C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8001D410: sra         $a3, $t8, 16
    ctx->r7 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8001D414: jal         0x8001D4E8
    // 0x8001D418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_shading_properties(rdram, ctx);
        goto after_0;
    // 0x8001D418: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8001D41C: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x8001D420: nop

    // 0x8001D424: lbu         $t6, 0x3D($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3D);
    // 0x8001D428: nop

    // 0x8001D42C: beq         $t6, $zero, L_8001D4D8
    if (ctx->r14 == 0) {
        // 0x8001D430: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8001D4D8;
    }
    // 0x8001D430: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D434: lbu         $t7, 0x3A($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3A);
    // 0x8001D438: lw          $t8, 0x54($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X54);
    // 0x8001D43C: nop

    // 0x8001D440: sb          $t7, 0x4($t8)
    MEM_B(0X4, ctx->r24) = ctx->r15;
    // 0x8001D444: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8001D448: lw          $t1, 0x54($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X54);
    // 0x8001D44C: lbu         $t0, 0x3B($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X3B);
    // 0x8001D450: nop

    // 0x8001D454: sb          $t0, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r8;
    // 0x8001D458: lw          $t2, 0x40($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X40);
    // 0x8001D45C: lw          $t4, 0x54($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X54);
    // 0x8001D460: lbu         $t3, 0x3C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X3C);
    // 0x8001D464: nop

    // 0x8001D468: sb          $t3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r11;
    // 0x8001D46C: lw          $t5, 0x40($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X40);
    // 0x8001D470: lw          $t7, 0x54($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X54);
    // 0x8001D474: lbu         $t6, 0x3D($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X3D);
    // 0x8001D478: nop

    // 0x8001D47C: sb          $t6, 0x7($t7)
    MEM_B(0X7, ctx->r15) = ctx->r14;
    // 0x8001D480: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D484: nop

    // 0x8001D488: lh          $t8, 0x1C($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1C);
    // 0x8001D48C: nop

    // 0x8001D490: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8001D494: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x8001D498: sh          $t0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r8;
    // 0x8001D49C: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D4A0: nop

    // 0x8001D4A4: lh          $t1, 0x1E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1E);
    // 0x8001D4A8: nop

    // 0x8001D4AC: sra         $t2, $t1, 1
    ctx->r10 = S32(SIGNED(ctx->r9) >> 1);
    // 0x8001D4B0: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8001D4B4: sh          $t3, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r11;
    // 0x8001D4B8: lw          $s0, 0x54($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X54);
    // 0x8001D4BC: nop

    // 0x8001D4C0: lh          $t4, 0x20($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X20);
    // 0x8001D4C4: nop

    // 0x8001D4C8: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x8001D4CC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8001D4D0: sh          $t6, 0xC($s0)
    MEM_H(0XC, ctx->r16) = ctx->r14;
L_8001D4D4:
    // 0x8001D4D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8001D4D8:
    // 0x8001D4D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D4DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8001D4E0: jr          $ra
    // 0x8001D4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8001D4E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mempool_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071554: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80071558: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007155C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80071560: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80071564: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80071568: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007156C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80071570: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80071574: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80071578: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007157C: jal         0x8006F750
    // 0x80071580: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x80071580: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80071584: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80071588: lw          $s2, 0x3B40($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X3B40);
    // 0x8007158C: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80071590: beq         $s2, $s6, L_80071644
    if (ctx->r18 == ctx->r22) {
        // 0x80071594: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80071644;
    }
    // 0x80071594: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80071598: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007159C: addiu       $t7, $t7, 0x3B00
    ctx->r15 = ADD32(ctx->r15, 0X3B00);
    // 0x800715A0: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x800715A4: addu        $s5, $t6, $t7
    ctx->r21 = ADD32(ctx->r14, ctx->r15);
    // 0x800715A8: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800715AC: addiu       $s7, $zero, 0x14
    ctx->r23 = ADD32(0, 0X14);
    // 0x800715B0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800715B4:
    // 0x800715B4: lw          $s4, 0x8($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X8);
    // 0x800715B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800715BC:
    // 0x800715BC: multu       $s0, $s7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800715C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800715C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800715C8: addu        $s1, $t8, $s4
    ctx->r17 = ADD32(ctx->r24, ctx->r20);
    // 0x800715CC: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800715D0: nop

    // 0x800715D4: bne         $s3, $v0, L_800715EC
    if (ctx->r19 != ctx->r2) {
        // 0x800715D8: nop
    
            goto L_800715EC;
    }
    // 0x800715D8: nop

    // 0x800715DC: jal         0x8007188C
    // 0x800715E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_1;
    // 0x800715E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x800715E4: lh          $v0, 0x8($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X8);
    // 0x800715E8: nop

L_800715EC:
    // 0x800715EC: bne         $fp, $v0, L_80071628
    if (ctx->r30 != ctx->r2) {
        // 0x800715F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80071628;
    }
    // 0x800715F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800715F4: lw          $t9, 0x4($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X4);
    // 0x800715F8: nop

    // 0x800715FC: bne         $s3, $t9, L_80071614
    if (ctx->r19 != ctx->r25) {
        // 0x80071600: nop
    
            goto L_80071614;
    }
    // 0x80071600: nop

    // 0x80071604: jal         0x8007188C
    // 0x80071608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_slot_clear(rdram, ctx);
        goto after_2;
    // 0x80071608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8007160C: b           L_8007162C
    // 0x80071610: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
        goto L_8007162C;
    // 0x80071610: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_80071614:
    // 0x80071614: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071618: jal         0x8006F77C
    // 0x8007161C: nop

    interrupts_enable(rdram, ctx);
        goto after_3;
    // 0x8007161C: nop

    after_3:
    // 0x80071620: b           L_80071654
    // 0x80071624: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80071654;
    // 0x80071624: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80071628:
    // 0x80071628: lh          $s0, 0xC($s1)
    ctx->r16 = MEM_H(ctx->r17, 0XC);
L_8007162C:
    // 0x8007162C: nop

    // 0x80071630: bne         $s0, $s6, L_800715BC
    if (ctx->r16 != ctx->r22) {
        // 0x80071634: nop
    
            goto L_800715BC;
    }
    // 0x80071634: nop

    // 0x80071638: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8007163C: bne         $s2, $s6, L_800715B4
    if (ctx->r18 != ctx->r22) {
        // 0x80071640: addiu       $s5, $s5, -0x10
        ctx->r21 = ADD32(ctx->r21, -0X10);
            goto L_800715B4;
    }
    // 0x80071640: addiu       $s5, $s5, -0x10
    ctx->r21 = ADD32(ctx->r21, -0X10);
L_80071644:
    // 0x80071644: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80071648: jal         0x8006F77C
    // 0x8007164C: nop

    interrupts_enable(rdram, ctx);
        goto after_4;
    // 0x8007164C: nop

    after_4:
    // 0x80071650: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80071654:
    // 0x80071654: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80071658: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007165C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80071660: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80071664: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80071668: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007166C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80071670: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80071674: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80071678: jr          $ra
    // 0x8007167C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8007167C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void racer_attack_handler_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C180: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8004C184: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8004C188: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8004C18C: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8004C190: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004C194: bne         $t6, $at, L_8004C1A4
    if (ctx->r14 != ctx->r1) {
        // 0x8004C198: or          $s0, $a1, $zero
        ctx->r16 = ctx->r5 | 0;
            goto L_8004C1A4;
    }
    // 0x8004C198: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8004C19C: b           L_8004C1AC
    // 0x8004C1A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8004C1AC;
    // 0x8004C1A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8004C1A4:
    // 0x8004C1A4: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x8004C1A8: nop

L_8004C1AC:
    // 0x8004C1AC: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x8004C1B0: nop

    // 0x8004C1B4: beq         $v0, $zero, L_8004C1CC
    if (ctx->r2 == 0) {
        // 0x8004C1B8: nop
    
            goto L_8004C1CC;
    }
    // 0x8004C1B8: nop

    // 0x8004C1BC: lh          $t7, 0x18E($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18E);
    // 0x8004C1C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8004C1C4: blez        $t7, L_8004C1D4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8004C1C8: nop
    
            goto L_8004C1D4;
    }
    // 0x8004C1C8: nop

L_8004C1CC:
    // 0x8004C1CC: b           L_8004C2E0
    // 0x8004C1D0: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_8004C2E0;
    // 0x8004C1D0: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C1D4:
    // 0x8004C1D4: beq         $v0, $at, L_8004C1F8
    if (ctx->r2 == ctx->r1) {
        // 0x8004C1D8: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_8004C1F8;
    }
    // 0x8004C1D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8004C1DC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8004C1E0: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x8004C1E4: jal         0x80057720
    // 0x8004C1E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    drop_bananas(rdram, ctx);
        goto after_0;
    // 0x8004C1E8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8004C1EC: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x8004C1F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004C1F4: nop

L_8004C1F8:
    // 0x8004C1F8: lbu         $t9, 0x1C9($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1C9);
    // 0x8004C1FC: addiu       $t8, $zero, 0x168
    ctx->r24 = ADD32(0, 0X168);
    // 0x8004C200: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8004C204: bne         $t9, $at, L_8004C210
    if (ctx->r25 != ctx->r1) {
        // 0x8004C208: sh          $t8, 0x18C($s0)
        MEM_H(0X18C, ctx->r16) = ctx->r24;
            goto L_8004C210;
    }
    // 0x8004C208: sh          $t8, 0x18C($s0)
    MEM_H(0X18C, ctx->r16) = ctx->r24;
    // 0x8004C20C: sb          $zero, 0x1C9($s0)
    MEM_B(0X1C9, ctx->r16) = 0;
L_8004C210:
    // 0x8004C210: lb          $t0, 0x1D6($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D6);
    // 0x8004C214: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x8004C218: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x8004C21C: beq         $at, $zero, L_8004C2E0
    if (ctx->r1 == 0) {
        // 0x8004C220: addiu       $a2, $zero, 0x8
        ctx->r6 = ADD32(0, 0X8);
            goto L_8004C2E0;
    }
    // 0x8004C220: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x8004C224: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x8004C228: sb          $v1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r3;
    // 0x8004C22C: jal         0x800570F8
    // 0x8004C230: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    play_random_character_voice(rdram, ctx);
        goto after_1;
    // 0x8004C230: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
    // 0x8004C234: lb          $v0, 0x187($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X187);
    // 0x8004C238: lb          $v1, 0x27($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X27);
    // 0x8004C23C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8004C240: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8004C244: beq         $v0, $at, L_8004C26C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C248: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8004C26C;
    }
    // 0x8004C248: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8004C24C: beq         $v0, $at, L_8004C26C
    if (ctx->r2 == ctx->r1) {
        // 0x8004C250: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8004C26C;
    }
    // 0x8004C250: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004C254: beq         $v0, $at, L_8004C288
    if (ctx->r2 == ctx->r1) {
        // 0x8004C258: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8004C288;
    }
    // 0x8004C258: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8004C25C: beq         $v0, $at, L_8004C2A4
    if (ctx->r2 == ctx->r1) {
        // 0x8004C260: addiu       $t5, $zero, 0x78
        ctx->r13 = ADD32(0, 0X78);
            goto L_8004C2A4;
    }
    // 0x8004C260: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8004C264: b           L_8004C2E0
    // 0x8004C268: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
        goto L_8004C2E0;
    // 0x8004C268: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C26C:
    // 0x8004C26C: beq         $v1, $zero, L_8004C280
    if (ctx->r3 == 0) {
        // 0x8004C270: addiu       $t2, $zero, 0x3C
        ctx->r10 = ADD32(0, 0X3C);
            goto L_8004C280;
    }
    // 0x8004C270: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8004C274: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x8004C278: b           L_8004C2DC
    // 0x8004C27C: sb          $t1, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r9;
        goto L_8004C2DC;
    // 0x8004C27C: sb          $t1, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r9;
L_8004C280:
    // 0x8004C280: b           L_8004C2DC
    // 0x8004C284: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
        goto L_8004C2DC;
    // 0x8004C284: sb          $t2, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r10;
L_8004C288:
    // 0x8004C288: beq         $v1, $zero, L_8004C29C
    if (ctx->r3 == 0) {
        // 0x8004C28C: addiu       $t4, $zero, 0x3C
        ctx->r12 = ADD32(0, 0X3C);
            goto L_8004C29C;
    }
    // 0x8004C28C: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x8004C290: addiu       $t3, $zero, 0x28
    ctx->r11 = ADD32(0, 0X28);
    // 0x8004C294: b           L_8004C2DC
    // 0x8004C298: sb          $t3, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r11;
        goto L_8004C2DC;
    // 0x8004C298: sb          $t3, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r11;
L_8004C29C:
    // 0x8004C29C: b           L_8004C2DC
    // 0x8004C2A0: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
        goto L_8004C2DC;
    // 0x8004C2A0: sb          $t4, 0x1DB($s0)
    MEM_B(0X1DB, ctx->r16) = ctx->r12;
L_8004C2A4:
    // 0x8004C2A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8004C2A8: lwc1        $f1, 0x6AE0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6AE0);
    // 0x8004C2AC: lwc1        $f0, 0x6AE4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6AE4);
    // 0x8004C2B0: sh          $t5, 0x204($s0)
    MEM_H(0X204, ctx->r16) = ctx->r13;
    // 0x8004C2B4: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8004C2B8: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8004C2BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004C2C0: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8004C2C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8004C2C8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8004C2CC: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8004C2D0: swc1        $f10, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f10.u32l;
    // 0x8004C2D4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8004C2D8: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
L_8004C2DC:
    // 0x8004C2DC: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
L_8004C2E0:
    // 0x8004C2E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004C2E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8004C2E8: jr          $ra
    // 0x8004C2EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8004C2EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_init_wizpigship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80037DB0: jr          $ra
    // 0x80037DB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80037DB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_8001F460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F494: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x8001F498: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001F49C: lh          $t6, -0x4C06($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X4C06);
    // 0x8001F4A0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8001F4A4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8001F4A8: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001F4AC: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8001F4B0: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8001F4B4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8001F4B8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8001F4BC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001F4C0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001F4C4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001F4C8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001F4CC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8001F4D0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001F4D4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8001F4D8: bgez        $t6, L_8001F4E8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001F4DC: sw          $a1, 0x19C($sp)
        MEM_W(0X19C, ctx->r29) = ctx->r5;
            goto L_8001F4E8;
    }
    // 0x8001F4DC: sw          $a1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r5;
    // 0x8001F4E0: b           L_800210C8
    // 0x8001F4E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800210C8;
    // 0x8001F4E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8001F4E8:
    // 0x8001F4E8: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F4EC: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8001F4F0: slti        $at, $t7, 0x9
    ctx->r1 = SIGNED(ctx->r15) < 0X9 ? 1 : 0;
    // 0x8001F4F4: bne         $at, $zero, L_8001F500
    if (ctx->r1 != 0) {
        // 0x8001F4F8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8001F500;
    }
    // 0x8001F4F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001F4FC: sw          $t8, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r24;
L_8001F500:
    // 0x8001F500: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F504: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8001F508: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8001F50C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8001F510: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001F514: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001F518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F51C: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    // 0x8001F520: lw          $s3, 0x64($s6)
    ctx->r19 = MEM_W(ctx->r22, 0X64);
    // 0x8001F524: bne         $t6, $zero, L_8001F544
    if (ctx->r14 != 0) {
        // 0x8001F528: addiu       $s1, $zero, 0x4
        ctx->r17 = ADD32(0, 0X4);
            goto L_8001F544;
    }
    // 0x8001F528: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8001F52C: lwc1        $f9, 0x5C00($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5C00);
    // 0x8001F530: lwc1        $f8, 0x5C04($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5C04);
    // 0x8001F534: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8001F538: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8001F53C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x8001F540: swc1        $f4, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f4.u32l;
L_8001F544:
    // 0x8001F544: lh          $t7, 0x2A($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F548: nop

    // 0x8001F54C: bgez        $t7, L_8001F5B4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001F550: nop
    
            goto L_8001F5B4;
    }
    // 0x8001F550: nop

    // 0x8001F554: lbu         $v0, 0x34($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X34);
    // 0x8001F558: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F55C: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x8001F560: beq         $t8, $zero, L_8001F56C
    if (ctx->r24 == 0) {
        // 0x8001F564: andi        $t9, $v0, 0x2
        ctx->r25 = ctx->r2 & 0X2;
            goto L_8001F56C;
    }
    // 0x8001F564: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x8001F568: ori         $t0, $zero, 0x8000
    ctx->r8 = 0 | 0X8000;
L_8001F56C:
    // 0x8001F56C: beq         $t9, $zero, L_8001F57C
    if (ctx->r25 == 0) {
        // 0x8001F570: andi        $t7, $v0, 0x4
        ctx->r15 = ctx->r2 & 0X4;
            goto L_8001F57C;
    }
    // 0x8001F570: andi        $t7, $v0, 0x4
    ctx->r15 = ctx->r2 & 0X4;
    // 0x8001F574: ori         $t6, $t0, 0x4000
    ctx->r14 = ctx->r8 | 0X4000;
    // 0x8001F578: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
L_8001F57C:
    // 0x8001F57C: beq         $t7, $zero, L_8001F588
    if (ctx->r15 == 0) {
        // 0x8001F580: ori         $t8, $t0, 0x1000
        ctx->r24 = ctx->r8 | 0X1000;
            goto L_8001F588;
    }
    // 0x8001F580: ori         $t8, $t0, 0x1000
    ctx->r24 = ctx->r8 | 0X1000;
    // 0x8001F584: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_8001F588:
    // 0x8001F588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001F58C: jal         0x8006A794
    // 0x8001F590: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x8001F590: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    after_0:
    // 0x8001F594: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F598: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F59C: bne         $s0, $s1, L_8001F588
    if (ctx->r16 != ctx->r17) {
        // 0x8001F5A0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_8001F588;
    }
    // 0x8001F5A0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x8001F5A4: and         $t9, $s2, $t0
    ctx->r25 = ctx->r18 & ctx->r8;
    // 0x8001F5A8: beq         $t9, $zero, L_8001F5B4
    if (ctx->r25 == 0) {
        // 0x8001F5AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8001F5B4;
    }
    // 0x8001F5AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F5B0: sh          $t6, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r14;
L_8001F5B4:
    // 0x8001F5B4: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5B8: nop

    // 0x8001F5BC: bltz        $v0, L_8001F620
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001F5C0: nop
    
            goto L_8001F620;
    }
    // 0x8001F5C0: nop

    // 0x8001F5C4: lb          $t7, 0x45($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X45);
    // 0x8001F5C8: lw          $t8, 0x19C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F5CC: bne         $t7, $zero, L_8001F620
    if (ctx->r15 != 0) {
        // 0x8001F5D0: subu        $t9, $v0, $t8
        ctx->r25 = SUB32(ctx->r2, ctx->r24);
            goto L_8001F620;
    }
    // 0x8001F5D0: subu        $t9, $v0, $t8
    ctx->r25 = SUB32(ctx->r2, ctx->r24);
    // 0x8001F5D4: sh          $t9, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = ctx->r25;
    // 0x8001F5D8: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F5DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001F5E0: bgtz        $v0, L_8001F620
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001F5E4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8001F620;
    }
    // 0x8001F5E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F5E8: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x8001F5EC: sb          $t6, 0x45($s3)
    MEM_B(0X45, ctx->r19) = ctx->r14;
    // 0x8001F5F0: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001F5F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8001F5F8: jal         0x80021138
    // 0x8001F5FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    func_80021104(rdram, ctx);
        goto after_1;
    // 0x8001F5FC: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8001F600: sh          $zero, 0x2A($s3)
    MEM_H(0X2A, ctx->r19) = 0;
    // 0x8001F604: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8001F608: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001F60C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8001F610: jal         0x80021290
    // 0x8001F614: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    func_8002125C(rdram, ctx);
        goto after_2;
    // 0x8001F614: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    after_2:
    // 0x8001F618: lh          $v0, 0x2A($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X2A);
    // 0x8001F61C: nop

L_8001F620:
    // 0x8001F620: beq         $v0, $zero, L_8001F658
    if (ctx->r2 == 0) {
        // 0x8001F624: nop
    
            goto L_8001F658;
    }
    // 0x8001F624: nop

    // 0x8001F628: lb          $t8, 0x3A($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X3A);
    // 0x8001F62C: nop

    // 0x8001F630: beq         $t8, $zero, L_8001F650
    if (ctx->r24 == 0) {
        // 0x8001F634: nop
    
            goto L_8001F650;
    }
    // 0x8001F634: nop

    // 0x8001F638: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8001F640: ori         $t6, $t9, 0x4000
    ctx->r14 = ctx->r25 | 0X4000;
    // 0x8001F644: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8001F648: b           L_800210C8
    // 0x8001F64C: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
        goto L_800210C8;
    // 0x8001F64C: sb          $zero, 0x42($s3)
    MEM_B(0X42, ctx->r19) = 0;
L_8001F650:
    // 0x8001F650: b           L_800210C8
    // 0x8001F654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800210C8;
    // 0x8001F654: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001F658:
    // 0x8001F658: lh          $t7, 0x6($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X6);
    // 0x8001F65C: addiu       $s0, $zero, -0x4001
    ctx->r16 = ADD32(0, -0X4001);
    // 0x8001F660: andi        $t8, $t7, 0xBFFF
    ctx->r24 = ctx->r15 & 0XBFFF;
    // 0x8001F664: sh          $t8, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r24;
    // 0x8001F668: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F66C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8001F670: blez        $v1, L_8001F6B4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001F674: nop
    
            goto L_8001F6B4;
    }
    // 0x8001F674: nop

    // 0x8001F678: jal         0x80001918
    // 0x8001F67C: nop

    music_current_sequence(rdram, ctx);
        goto after_3;
    // 0x8001F67C: nop

    after_3:
    // 0x8001F680: lb          $v1, 0x39($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X39);
    // 0x8001F684: nop

    // 0x8001F688: beq         $v1, $v0, L_8001F6A4
    if (ctx->r3 == ctx->r2) {
        // 0x8001F68C: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_8001F6A4;
    }
    // 0x8001F68C: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
    // 0x8001F690: jal         0x80000B34
    // 0x8001F694: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8001F694: andi        $a0, $v1, 0xFF
    ctx->r4 = ctx->r3 & 0XFF;
    after_4:
    // 0x8001F698: jal         0x80000B18
    // 0x8001F69C: nop

    music_change_off(rdram, ctx);
        goto after_5;
    // 0x8001F69C: nop

    after_5:
    // 0x8001F6A0: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_8001F6A4:
    // 0x8001F6A4: jal         0x80000CBC
    // 0x8001F6A8: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    music_volume_reset(rdram, ctx);
        goto after_6;
    // 0x8001F6A8: sb          $t9, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r25;
    after_6:
    // 0x8001F6AC: b           L_8001F6D0
    // 0x8001F6B0: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
        goto L_8001F6D0;
    // 0x8001F6B0: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F6B4:
    // 0x8001F6B4: bne         $v1, $at, L_8001F6CC
    if (ctx->r3 != ctx->r1) {
        // 0x8001F6B8: nop
    
            goto L_8001F6CC;
    }
    // 0x8001F6B8: nop

    // 0x8001F6BC: jal         0x80000B28
    // 0x8001F6C0: nop

    music_change_on(rdram, ctx);
        goto after_7;
    // 0x8001F6C0: nop

    after_7:
    // 0x8001F6C4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8001F6C8: sb          $t6, 0x39($s3)
    MEM_B(0X39, ctx->r19) = ctx->r14;
L_8001F6CC:
    // 0x8001F6CC: lb          $v1, 0x38($s3)
    ctx->r3 = MEM_B(ctx->r19, 0X38);
L_8001F6D0:
    // 0x8001F6D0: nop

    // 0x8001F6D4: beq         $v1, $zero, L_8001F74C
    if (ctx->r3 == 0) {
        // 0x8001F6D8: nop
    
            goto L_8001F74C;
    }
    // 0x8001F6D8: nop

    // 0x8001F6DC: lh          $t7, 0x24($s3)
    ctx->r15 = MEM_H(ctx->r19, 0X24);
    // 0x8001F6E0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x8001F6E4: bne         $t7, $zero, L_8001F74C
    if (ctx->r15 != 0) {
        // 0x8001F6E8: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_8001F74C;
    }
    // 0x8001F6E8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8001F6EC: bne         $v0, $at, L_8001F714
    if (ctx->r2 != ctx->r1) {
        // 0x8001F6F0: nop
    
            goto L_8001F714;
    }
    // 0x8001F6F0: nop

    // 0x8001F6F4: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F6F8: nop

    // 0x8001F6FC: beq         $a0, $zero, L_8001F748
    if (ctx->r4 == 0) {
        // 0x8001F700: nop
    
            goto L_8001F748;
    }
    // 0x8001F700: nop

    // 0x8001F704: jal         0x8000488C
    // 0x8001F708: nop

    sndp_stop(rdram, ctx);
        goto after_8;
    // 0x8001F708: nop

    after_8:
    // 0x8001F70C: b           L_8001F74C
    // 0x8001F710: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
        goto L_8001F74C;
    // 0x8001F710: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F714:
    // 0x8001F714: lw          $a0, 0x18($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X18);
    // 0x8001F718: nop

    // 0x8001F71C: beq         $a0, $zero, L_8001F73C
    if (ctx->r4 == 0) {
        // 0x8001F720: nop
    
            goto L_8001F73C;
    }
    // 0x8001F720: nop

    // 0x8001F724: jal         0x8000488C
    // 0x8001F728: nop

    sndp_stop(rdram, ctx);
        goto after_9;
    // 0x8001F728: nop

    after_9:
    // 0x8001F72C: lb          $v0, 0x38($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X38);
    // 0x8001F730: nop

    // 0x8001F734: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8001F738: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8001F73C:
    // 0x8001F73C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8001F740: jal         0x80001D04
    // 0x8001F744: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8001F744: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    after_10:
L_8001F748:
    // 0x8001F748: sb          $zero, 0x38($s3)
    MEM_B(0X38, ctx->r19) = 0;
L_8001F74C:
    // 0x8001F74C: lb          $v0, 0x43($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X43);
    // 0x8001F750: nop

    // 0x8001F754: beq         $v0, $zero, L_8001F768
    if (ctx->r2 == 0) {
        // 0x8001F758: nop
    
            goto L_8001F768;
    }
    // 0x8001F758: nop

    // 0x8001F75C: jal         0x80000C98
    // 0x8001F760: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    music_fade(rdram, ctx);
        goto after_11;
    // 0x8001F760: sll         $a0, $v0, 8
    ctx->r4 = S32(ctx->r2 << 8);
    after_11:
    // 0x8001F764: sb          $zero, 0x43($s3)
    MEM_B(0X43, ctx->r19) = 0;
L_8001F768:
    // 0x8001F768: lb          $v0, 0x41($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X41);
    // 0x8001F76C: lbu         $t0, 0x42($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X42);
    // 0x8001F770: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x8001F774: beq         $t9, $zero, L_8001F7B8
    if (ctx->r25 == 0) {
        // 0x8001F778: andi        $t6, $v0, 0x2
        ctx->r14 = ctx->r2 & 0X2;
            goto L_8001F7B8;
    }
    // 0x8001F778: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F77C: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8001F780: lw          $v0, 0x19C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F784: beq         $t6, $zero, L_8001F790
    if (ctx->r14 == 0) {
        // 0x8001F788: sll         $t7, $v0, 3
        ctx->r15 = S32(ctx->r2 << 3);
            goto L_8001F790;
    }
    // 0x8001F788: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x8001F78C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001F790:
    // 0x8001F790: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001F794: beq         $at, $zero, L_8001F7A4
    if (ctx->r1 == 0) {
        // 0x8001F798: nop
    
            goto L_8001F7A4;
    }
    // 0x8001F798: nop

    // 0x8001F79C: b           L_8001F7EC
    // 0x8001F7A0: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
        goto L_8001F7EC;
    // 0x8001F7A0: subu        $t0, $t0, $t7
    ctx->r8 = SUB32(ctx->r8, ctx->r15);
L_8001F7A4:
    // 0x8001F7A4: lh          $t8, 0x6($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X6);
    // 0x8001F7A8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001F7AC: ori         $t9, $t8, 0x4000
    ctx->r25 = ctx->r24 | 0X4000;
    // 0x8001F7B0: b           L_8001F7EC
    // 0x8001F7B4: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
        goto L_8001F7EC;
    // 0x8001F7B4: sh          $t9, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r25;
L_8001F7B8:
    // 0x8001F7B8: lw          $t7, 0x19C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X19C);
    // 0x8001F7BC: beq         $t6, $zero, L_8001F7C8
    if (ctx->r14 == 0) {
        // 0x8001F7C0: sll         $t8, $t7, 3
        ctx->r24 = S32(ctx->r15 << 3);
            goto L_8001F7C8;
    }
    // 0x8001F7C0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8001F7C4: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F7C8:
    // 0x8001F7C8: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x8001F7CC: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x8001F7D0: bne         $at, $zero, L_8001F7DC
    if (ctx->r1 != 0) {
        // 0x8001F7D4: nop
    
            goto L_8001F7DC;
    }
    // 0x8001F7D4: nop

    // 0x8001F7D8: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_8001F7DC:
    // 0x8001F7DC: lh          $t9, 0x6($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X6);
    // 0x8001F7E0: nop

    // 0x8001F7E4: and         $t6, $t9, $s0
    ctx->r14 = ctx->r25 & ctx->r16;
    // 0x8001F7E8: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
L_8001F7EC:
    // 0x8001F7EC: lbu         $v0, 0x3B($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F7F0: addiu       $at, $zero, 0x7F
    ctx->r1 = ADD32(0, 0X7F);
    // 0x8001F7F4: andi        $s2, $v0, 0x7F
    ctx->r18 = ctx->r2 & 0X7F;
    // 0x8001F7F8: beq         $s2, $at, L_8001F9BC
    if (ctx->r18 == ctx->r1) {
        // 0x8001F7FC: sb          $t0, 0x42($s3)
        MEM_B(0X42, ctx->r19) = ctx->r8;
            goto L_8001F9BC;
    }
    // 0x8001F7FC: sb          $t0, 0x42($s3)
    MEM_B(0X42, ctx->r19) = ctx->r8;
    // 0x8001F800: slti        $at, $s2, 0x8
    ctx->r1 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x8001F804: bne         $at, $zero, L_8001F8A0
    if (ctx->r1 != 0) {
        // 0x8001F808: slti        $at, $s2, 0x6
        ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
            goto L_8001F8A0;
    }
    // 0x8001F808: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8001F80C: jal         0x8001E2D0
    // 0x8001F810: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8001F810: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_12:
    // 0x8001F814: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x8001F818: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x8001F81C: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x8001F820: addiu       $s1, $v1, -0x28
    ctx->r17 = ADD32(ctx->r3, -0X28);
    // 0x8001F824: lb          $t0, 0x0($s1)
    ctx->r8 = MEM_B(ctx->r17, 0X0);
    // 0x8001F828: lb          $s0, 0x1($s1)
    ctx->r16 = MEM_B(ctx->r17, 0X1);
    // 0x8001F82C: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x8001F830: addiu       $t0, $t8, 0x384
    ctx->r8 = ADD32(ctx->r24, 0X384);
    // 0x8001F834: andi        $t9, $s0, 0xFF
    ctx->r25 = ctx->r16 & 0XFF;
    // 0x8001F838: addiu       $s0, $t9, 0x384
    ctx->r16 = ADD32(ctx->r25, 0X384);
    // 0x8001F83C: sw          $t0, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r8;
    // 0x8001F840: jal         0x8000C8B4
    // 0x8001F844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_13;
    // 0x8001F844: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_13:
    // 0x8001F848: lw          $t0, 0x174($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X174);
    // 0x8001F84C: lb          $a1, 0x2($s1)
    ctx->r5 = MEM_B(ctx->r17, 0X2);
    // 0x8001F850: lb          $a2, 0x3($s1)
    ctx->r6 = MEM_B(ctx->r17, 0X3);
    // 0x8001F854: lb          $a3, 0x4($s1)
    ctx->r7 = MEM_B(ctx->r17, 0X4);
    // 0x8001F858: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F85C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8001F860: lbu         $t9, 0x3C($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F864: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8001F868: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F86C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8001F870: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8001F874: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8001F878: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8001F87C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8001F880: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001F884: mflo        $t6
    ctx->r14 = lo;
    // 0x8001F888: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001F88C: jal         0x80030E20
    // 0x8001F890: nop

    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x8001F890: nop

    after_14:
    // 0x8001F894: b           L_8001F9B8
    // 0x8001F898: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F9B8;
    // 0x8001F898: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F89C: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
L_8001F8A0:
    // 0x8001F8A0: bne         $at, $zero, L_8001F90C
    if (ctx->r1 != 0) {
        // 0x8001F8A4: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8001F90C;
    }
    // 0x8001F8A4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8001F8A8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x8001F8AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8001F8B0: bne         $s2, $at, L_8001F8D4
    if (ctx->r18 != ctx->r1) {
        // 0x8001F8B4: sb          $t7, 0xA4($sp)
        MEM_B(0XA4, ctx->r29) = ctx->r15;
            goto L_8001F8D4;
    }
    // 0x8001F8B4: sb          $t7, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r15;
    // 0x8001F8B8: addiu       $t8, $zero, 0xC8
    ctx->r24 = ADD32(0, 0XC8);
    // 0x8001F8BC: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x8001F8C0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8001F8C4: sb          $t6, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r14;
    // 0x8001F8C8: sb          $t9, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r25;
    // 0x8001F8CC: b           L_8001F8EC
    // 0x8001F8D0: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
        goto L_8001F8EC;
    // 0x8001F8D0: sb          $t8, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r24;
L_8001F8D4:
    // 0x8001F8D4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8001F8D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8001F8DC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8001F8E0: sb          $t9, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r25;
    // 0x8001F8E4: sb          $t8, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r24;
    // 0x8001F8E8: sb          $t7, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r15;
L_8001F8EC:
    // 0x8001F8EC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8001F8F0: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8001F8F4: sh          $t6, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r14;
    // 0x8001F8F8: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
    // 0x8001F8FC: jal         0x800C06F8
    // 0x8001F900: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_15;
    // 0x8001F900: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_15:
    // 0x8001F904: b           L_8001F9B8
    // 0x8001F908: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
        goto L_8001F9B8;
    // 0x8001F908: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F90C:
    // 0x8001F90C: jal         0x8001E2D0
    // 0x8001F910: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    get_misc_asset(rdram, ctx);
        goto after_16;
    // 0x8001F910: sb          $v0, 0xA4($sp)
    MEM_B(0XA4, ctx->r29) = ctx->r2;
    after_16:
    // 0x8001F914: lb          $t8, 0x40($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X40);
    // 0x8001F918: nop

    // 0x8001F91C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001F920: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x8001F924: addu        $s1, $v0, $t9
    ctx->r17 = ADD32(ctx->r2, ctx->r25);
    // 0x8001F928: lb          $t6, 0x0($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X0);
    // 0x8001F92C: nop

    // 0x8001F930: sb          $t6, 0xA5($sp)
    MEM_B(0XA5, ctx->r29) = ctx->r14;
    // 0x8001F934: lb          $t7, 0x1($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1);
    // 0x8001F938: nop

    // 0x8001F93C: sb          $t7, 0xA6($sp)
    MEM_B(0XA6, ctx->r29) = ctx->r15;
    // 0x8001F940: lb          $t8, 0x2($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X2);
    // 0x8001F944: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x8001F948: sb          $t8, 0xA7($sp)
    MEM_B(0XA7, ctx->r29) = ctx->r24;
    // 0x8001F94C: lbu         $t9, 0x3B($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X3B);
    // 0x8001F950: nop

    // 0x8001F954: andi        $t6, $t9, 0x80
    ctx->r14 = ctx->r25 & 0X80;
    // 0x8001F958: beq         $t6, $zero, L_8001F968
    if (ctx->r14 == 0) {
        // 0x8001F95C: nop
    
            goto L_8001F968;
    }
    // 0x8001F95C: nop

    // 0x8001F960: b           L_8001F96C
    // 0x8001F964: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
        goto L_8001F96C;
    // 0x8001F964: sh          $zero, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = 0;
L_8001F968:
    // 0x8001F968: sh          $t7, 0xAA($sp)
    MEM_H(0XAA, ctx->r29) = ctx->r15;
L_8001F96C:
    // 0x8001F96C: jal         0x8000C8B4
    // 0x8001F970: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    normalise_time(rdram, ctx);
        goto after_17;
    // 0x8001F970: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_17:
    // 0x8001F974: lbu         $t8, 0x3C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X3C);
    // 0x8001F978: nop

    // 0x8001F97C: multu       $v0, $t8
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001F980: mflo        $t9
    ctx->r25 = lo;
    // 0x8001F984: sh          $t9, 0xA8($sp)
    MEM_H(0XA8, ctx->r29) = ctx->r25;
    // 0x8001F988: jal         0x800C06AC
    // 0x8001F98C: nop

    check_fadeout_transition(rdram, ctx);
        goto after_18;
    // 0x8001F98C: nop

    after_18:
    // 0x8001F990: beq         $v0, $zero, L_8001F9AC
    if (ctx->r2 == 0) {
        // 0x8001F994: nop
    
            goto L_8001F9AC;
    }
    // 0x8001F994: nop

    // 0x8001F998: lbu         $t6, 0xA4($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XA4);
    // 0x8001F99C: nop

    // 0x8001F9A0: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x8001F9A4: beq         $t7, $zero, L_8001F9B8
    if (ctx->r15 == 0) {
        // 0x8001F9A8: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8001F9B8;
    }
    // 0x8001F9A8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F9AC:
    // 0x8001F9AC: jal         0x800C06F8
    // 0x8001F9B0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    transition_begin(rdram, ctx);
        goto after_19;
    // 0x8001F9B0: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    after_19:
    // 0x8001F9B4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
L_8001F9B8:
    // 0x8001F9B8: sb          $t8, 0x3B($s3)
    MEM_B(0X3B, ctx->r19) = ctx->r24;
L_8001F9BC:
    // 0x8001F9BC: lbu         $t9, 0x2E($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2E);
    // 0x8001F9C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001F9C4: bne         $t9, $at, L_8001FAC0
    if (ctx->r25 != ctx->r1) {
        // 0x8001F9C8: nop
    
            goto L_8001FAC0;
    }
    // 0x8001F9C8: nop

    // 0x8001F9CC: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001F9D0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x8001F9D4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001F9D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001F9DC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001F9E0: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8001F9E4: lb          $t7, 0x31($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X31);
    // 0x8001F9E8: lh          $t6, 0x0($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X0);
    // 0x8001F9EC: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001F9F0: lh          $t7, 0x2($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X2);
    // 0x8001F9F4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001F9F8: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    // 0x8001F9FC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA04: nop

    // 0x8001FA08: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA0C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA14: nop

    // 0x8001FA18: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA1C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA20: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA24: nop

    // 0x8001FA28: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FA2C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    // 0x8001FA30: lb          $t6, 0x32($s3)
    ctx->r14 = MEM_B(ctx->r19, 0X32);
    // 0x8001FA34: nop

    // 0x8001FA38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8001FA3C: lh          $t6, 0x4($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X4);
    // 0x8001FA40: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA44: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA48: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA4C: nop

    // 0x8001FA50: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FA58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FA5C: nop

    // 0x8001FA60: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FA64: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FA68: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FA6C: nop

    // 0x8001FA70: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001FA74: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8001FA78: lb          $t7, 0x33($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X33);
    // 0x8001FA7C: nop

    // 0x8001FA80: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8001FA84: nop

    // 0x8001FA88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FA8C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001FA90: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001FA94: nop

    // 0x8001FA98: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001FA9C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FAA0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FAA4: nop

    // 0x8001FAA8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8001FAAC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001FAB0: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8001FAB4: nop

    // 0x8001FAB8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FABC: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
L_8001FAC0:
    // 0x8001FAC0: beq         $s4, $zero, L_8001FDD8
    if (ctx->r20 == 0) {
        // 0x8001FAC4: nop
    
            goto L_8001FDD8;
    }
    // 0x8001FAC4: nop

    // 0x8001FAC8: lw          $t7, 0x40($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X40);
    // 0x8001FACC: nop

    // 0x8001FAD0: lb          $t6, 0x53($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X53);
    // 0x8001FAD4: nop

    // 0x8001FAD8: bne         $t6, $zero, L_8001FDD8
    if (ctx->r14 != 0) {
        // 0x8001FADC: nop
    
            goto L_8001FDD8;
    }
    // 0x8001FADC: nop

    // 0x8001FAE0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8001FAE4: lb          $t8, 0x3B($s6)
    ctx->r24 = MEM_B(ctx->r22, 0X3B);
    // 0x8001FAE8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FAEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FAF0: sb          $t8, 0x3B($s4)
    MEM_B(0X3B, ctx->r20) = ctx->r24;
    // 0x8001FAF4: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FAF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FAFC: lh          $v0, 0x18($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X18);
    // 0x8001FB00: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FB04: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001FB08: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FB0C: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8001FB10: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001FB14: beq         $v0, $t8, L_8001FB34
    if (ctx->r2 == ctx->r24) {
        // 0x8001FB18: nop
    
            goto L_8001FB34;
    }
    // 0x8001FB18: nop

    // 0x8001FB1C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8001FB20: nop

    // 0x8001FB24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FB28: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FB2C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FB30: nop

L_8001FB34:
    // 0x8001FB34: lb          $t7, 0x3A($s4)
    ctx->r15 = MEM_B(ctx->r20, 0X3A);
    // 0x8001FB38: lw          $t9, 0x68($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X68);
    // 0x8001FB3C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8001FB40: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB44: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8001FB48: nop

    // 0x8001FB4C: beq         $v1, $zero, L_8001FDAC
    if (ctx->r3 == 0) {
        // 0x8001FB50: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB50: nop

    // 0x8001FB54: lb          $v0, 0x3B($s4)
    ctx->r2 = MEM_B(ctx->r20, 0X3B);
    // 0x8001FB58: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8001FB5C: bltz        $v0, L_8001FDAC
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FB60: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB60: nop

    // 0x8001FB64: lh          $t7, 0x48($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X48);
    // 0x8001FB68: nop

    // 0x8001FB6C: slt         $at, $v0, $t7
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8001FB70: beq         $at, $zero, L_8001FDAC
    if (ctx->r1 == 0) {
        // 0x8001FB74: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FB74: nop

    // 0x8001FB78: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x8001FB7C: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x8001FB80: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FB84: lw          $s5, 0x4($t8)
    ctx->r21 = MEM_W(ctx->r24, 0X4);
    // 0x8001FB88: lbu         $v1, 0x2C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2C);
    // 0x8001FB8C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x8001FB90: sll         $t7, $s5, 4
    ctx->r15 = S32(ctx->r21 << 4);
    // 0x8001FB94: beq         $v1, $zero, L_8001FBC0
    if (ctx->r3 == 0) {
        // 0x8001FB98: or          $s5, $t7, $zero
        ctx->r21 = ctx->r15 | 0;
            goto L_8001FBC0;
    }
    // 0x8001FB98: or          $s5, $t7, $zero
    ctx->r21 = ctx->r15 | 0;
    // 0x8001FB9C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001FBA0: beq         $v1, $at, L_8001FC60
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBA4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8001FC60;
    }
    // 0x8001FBA4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001FBA8: beq         $v1, $at, L_8001FC0C
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBAC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8001FC0C;
    }
    // 0x8001FBAC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001FBB0: beq         $v1, $at, L_8001FD08
    if (ctx->r3 == ctx->r1) {
        // 0x8001FBB4: nop
    
            goto L_8001FD08;
    }
    // 0x8001FBB4: nop

    // 0x8001FBB8: b           L_8001FDB0
    // 0x8001FBBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FBBC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FBC0:
    // 0x8001FBC0: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FBC4: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FBC8: nop

    // 0x8001FBCC: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FBD0: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FBD4: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FBD8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FBDC: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FBE0: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FBE4: nop

    // 0x8001FBE8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FBEC: nop

    // 0x8001FBF0: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FBF4: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FBF4: nop

    // 0x8001FBF8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8001FBFC: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FC00: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC04: b           L_8001FDB0
    // 0x8001FC08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FC08: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC0C:
    // 0x8001FC0C: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC10: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FC18: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001FC1C: mtc1        $s5, $f8
    ctx->f8.u32l = ctx->r21;
    // 0x8001FC20: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001FC24: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001FC28: swc1        $f6, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f6.u32l;
    // 0x8001FC2C: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC30: nop

    // 0x8001FC34: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC38: nop

    // 0x8001FC3C: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FC40: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FC40: nop

    // 0x8001FC44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001FC48: nop

    // 0x8001FC4C: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8001FC50: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC54: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC58: b           L_8001FDB0
    // 0x8001FC5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FC5C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FC60:
    // 0x8001FC60: lbu         $t9, 0x2D($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FC64: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC68: bne         $t9, $zero, L_8001FCCC
    if (ctx->r25 != 0) {
        // 0x8001FC6C: nop
    
            goto L_8001FCCC;
    }
    // 0x8001FC6C: nop

    // 0x8001FC70: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FC74: lwc1        $f8, 0x114($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FC78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FC7C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001FC80: mtc1        $s5, $f6
    ctx->f6.u32l = ctx->r21;
    // 0x8001FC84: add.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001FC88: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001FC8C: swc1        $f4, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f4.u32l;
    // 0x8001FC90: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FC94: nop

    // 0x8001FC98: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FC9C: nop

    // 0x8001FCA0: bc1f        L_8001FCC4
    if (!c1cs) {
        // 0x8001FCA4: nop
    
            goto L_8001FCC4;
    }
    // 0x8001FCA4: nop

    // 0x8001FCA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001FCAC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8001FCB0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x8001FCB4: sb          $t6, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r14;
    // 0x8001FCB8: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FCBC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCC0: nop

L_8001FCC4:
    // 0x8001FCC4: b           L_8001FDB0
    // 0x8001FCC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FCC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FCCC:
    // 0x8001FCCC: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FCD0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FCD4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FCD8: sub.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f8.fl;
    // 0x8001FCDC: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FCE0: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FCE4: nop

    // 0x8001FCE8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FCEC: nop

    // 0x8001FCF0: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FCF4: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FCF4: nop

    // 0x8001FCF8: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FCFC: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD00: b           L_8001FDAC
    // 0x8001FD04: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
        goto L_8001FDAC;
    // 0x8001FD04: sb          $zero, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = 0;
L_8001FD08:
    // 0x8001FD08: lbu         $t8, 0x2D($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X2D);
    // 0x8001FD0C: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FD10: bne         $t8, $zero, L_8001FD74
    if (ctx->r24 != 0) {
        // 0x8001FD14: nop
    
            goto L_8001FD74;
    }
    // 0x8001FD14: nop

    // 0x8001FD18: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FD1C: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x8001FD20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001FD24: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001FD28: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8001FD2C: add.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8001FD30: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001FD34: swc1        $f10, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f10.u32l;
    // 0x8001FD38: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD3C: nop

    // 0x8001FD40: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8001FD44: nop

    // 0x8001FD48: bc1f        L_8001FD6C
    if (!c1cs) {
        // 0x8001FD4C: nop
    
            goto L_8001FD6C;
    }
    // 0x8001FD4C: nop

    // 0x8001FD50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8001FD54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001FD58: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8001FD5C: sb          $t7, 0x2D($s3)
    MEM_B(0X2D, ctx->r19) = ctx->r15;
    // 0x8001FD60: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD64: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD68: nop

L_8001FD6C:
    // 0x8001FD6C: b           L_8001FDB0
    // 0x8001FD70: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8001FDB0;
    // 0x8001FD70: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FD74:
    // 0x8001FD74: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001FD78: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FD7C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8001FD80: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8001FD84: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8001FD88: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FD8C: nop

    // 0x8001FD90: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x8001FD94: nop

    // 0x8001FD98: bc1f        L_8001FDAC
    if (!c1cs) {
        // 0x8001FD9C: nop
    
            goto L_8001FDAC;
    }
    // 0x8001FD9C: nop

    // 0x8001FDA0: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8001FDA4: lwc1        $f2, 0x10($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001FDA8: nop

L_8001FDAC:
    // 0x8001FDAC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8001FDB0:
    // 0x8001FDB0: nop

    // 0x8001FDB4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8001FDB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001FDBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001FDC0: nop

    // 0x8001FDC4: cvt.w.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.u32l = CVT_W_S(ctx->f2.fl);
    // 0x8001FDC8: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8001FDCC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8001FDD0: sh          $t6, 0x18($s4)
    MEM_H(0X18, ctx->r20) = ctx->r14;
    // 0x8001FDD4: nop

L_8001FDD8:
    // 0x8001FDD8: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8001FDDC: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8001FDE0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001FDE4: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FDE8: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x8001FDEC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001FDF0: bc1f        L_8001FE0C
    if (!c1cs) {
        // 0x8001FDF4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8001FE0C;
    }
    // 0x8001FDF4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001FDF8: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FDFC: jal         0x80021518
    // 0x8001FE00: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_20;
    // 0x8001FE00: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_20:
    // 0x8001FE04: b           L_800210CC
    // 0x8001FE08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FE08: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FE0C:
    // 0x8001FE0C: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x8001FE10: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x8001FE14: blez        $v1, L_8001FE70
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001FE18: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001FE70;
    }
    // 0x8001FE18: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001FE1C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FE20: addiu       $a3, $a3, -0x4C0C
    ctx->r7 = ADD32(ctx->r7, -0X4C0C);
    // 0x8001FE24: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FE28: nop

    // 0x8001FE2C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001FE30: nop

    // 0x8001FE34: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE38: nop

    // 0x8001FE3C: beq         $a1, $t7, L_8001FE70
    if (ctx->r5 == ctx->r15) {
        // 0x8001FE40: nop
    
            goto L_8001FE70;
    }
    // 0x8001FE40: nop

L_8001FE44:
    // 0x8001FE44: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001FE48: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE4C: beq         $at, $zero, L_8001FE70
    if (ctx->r1 == 0) {
        // 0x8001FE50: sll         $t9, $s4, 2
        ctx->r25 = S32(ctx->r20 << 2);
            goto L_8001FE70;
    }
    // 0x8001FE50: sll         $t9, $s4, 2
    ctx->r25 = S32(ctx->r20 << 2);
    // 0x8001FE54: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8001FE58: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8001FE5C: nop

    // 0x8001FE60: lw          $t7, 0x7C($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X7C);
    // 0x8001FE64: nop

    // 0x8001FE68: bne         $a1, $t7, L_8001FE44
    if (ctx->r5 != ctx->r15) {
        // 0x8001FE6C: nop
    
            goto L_8001FE44;
    }
    // 0x8001FE6C: nop

L_8001FE70:
    // 0x8001FE70: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001FE74: slt         $at, $s4, $v1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE78: bne         $at, $zero, L_8001FE94
    if (ctx->r1 != 0) {
        // 0x8001FE7C: addiu       $a3, $a3, -0x4C0C
        ctx->r7 = ADD32(ctx->r7, -0X4C0C);
            goto L_8001FE94;
    }
    // 0x8001FE7C: addiu       $a3, $a3, -0x4C0C
    ctx->r7 = ADD32(ctx->r7, -0X4C0C);
    // 0x8001FE80: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FE84: jal         0x80021518
    // 0x8001FE88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_21;
    // 0x8001FE88: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_21:
    // 0x8001FE8C: b           L_800210CC
    // 0x8001FE90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FE90: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FE94:
    // 0x8001FE94: addiu       $t9, $s4, 0x1
    ctx->r25 = ADD32(ctx->r20, 0X1);
    // 0x8001FE98: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FE9C: beq         $at, $zero, L_8001FEF4
    if (ctx->r1 == 0) {
        // 0x8001FEA0: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FEA0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8001FEA4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8001FEA8: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8001FEAC: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    // 0x8001FEB0: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8001FEB4: addu        $v0, $s4, $s5
    ctx->r2 = ADD32(ctx->r20, ctx->r21);
    // 0x8001FEB8: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FEBC: nop

    // 0x8001FEC0: bne         $a1, $t9, L_8001FEF4
    if (ctx->r5 != ctx->r25) {
        // 0x8001FEC4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FEC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FEC8:
    // 0x8001FEC8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001FECC: beq         $at, $zero, L_8001FEF4
    if (ctx->r1 == 0) {
        // 0x8001FED0: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8001FEF4;
    }
    // 0x8001FED0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8001FED4: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FED8: addu        $t8, $a0, $t6
    ctx->r24 = ADD32(ctx->r4, ctx->r14);
    // 0x8001FEDC: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8001FEE0: nop

    // 0x8001FEE4: lw          $t9, 0x7C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X7C);
    // 0x8001FEE8: nop

    // 0x8001FEEC: beq         $a1, $t9, L_8001FEC8
    if (ctx->r5 == ctx->r25) {
        // 0x8001FEF0: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001FEC8;
    }
    // 0x8001FEF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001FEF4:
    // 0x8001FEF4: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x8001FEF8: beq         $at, $zero, L_8001FF14
    if (ctx->r1 == 0) {
        // 0x8001FEFC: nop
    
            goto L_8001FF14;
    }
    // 0x8001FEFC: nop

    // 0x8001FF00: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FF04: jal         0x80021518
    // 0x8001FF08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_22;
    // 0x8001FF08: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_22:
    // 0x8001FF0C: b           L_800210CC
    // 0x8001FF10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FF10: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FF14:
    // 0x8001FF14: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001FF18: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001FF1C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8001FF20: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8001FF24: lw          $t8, 0x40($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X40);
    // 0x8001FF28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001FF2C: lwc1        $f6, 0xC($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001FF30: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x8001FF34: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x8001FF38: nop

    // 0x8001FF3C: div.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f10.d, ctx->f4.d);
    // 0x8001FF40: sll         $t6, $s5, 2
    ctx->r14 = S32(ctx->r21 << 2);
    // 0x8001FF44: addu        $t9, $a2, $t7
    ctx->r25 = ADD32(ctx->r6, ctx->r15);
    // 0x8001FF48: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x8001FF4C: slti        $at, $s5, 0x3
    ctx->r1 = SIGNED(ctx->r21) < 0X3 ? 1 : 0;
    // 0x8001FF50: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8001FF54: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8001FF58: swc1        $f6, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f6.u32l;
    // 0x8001FF5C: lw          $t7, -0x4($t8)
    ctx->r15 = MEM_W(ctx->r24, -0X4);
    // 0x8001FF60: nop

    // 0x8001FF64: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x8001FF68: bne         $at, $zero, L_8001FF90
    if (ctx->r1 != 0) {
        // 0x8001FF6C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF90;
    }
    // 0x8001FF6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF70: lb          $v0, 0x1D($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D);
    // 0x8001FF74: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001FF78: bltz        $v0, L_8001FF8C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FF7C: slt         $at, $v0, $t9
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_8001FF8C;
    }
    // 0x8001FF7C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001FF80: beq         $at, $zero, L_8001FF90
    if (ctx->r1 == 0) {
        // 0x8001FF84: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8001FF90;
    }
    // 0x8001FF84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001FF88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8001FF8C:
    // 0x8001FF8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8001FF90:
    // 0x8001FF90: bne         $v1, $at, L_8001FFC0
    if (ctx->r3 != ctx->r1) {
        // 0x8001FF94: nop
    
            goto L_8001FFC0;
    }
    // 0x8001FF94: nop

    // 0x8001FF98: lh          $t6, 0x26($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X26);
    // 0x8001FF9C: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x8001FFA0: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001FFA4: bne         $at, $zero, L_8001FFC0
    if (ctx->r1 != 0) {
        // 0x8001FFA8: nop
    
            goto L_8001FFC0;
    }
    // 0x8001FFA8: nop

    // 0x8001FFAC: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FFB0: jal         0x80021518
    // 0x8001FFB4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    func_800214E4(rdram, ctx);
        goto after_23;
    // 0x8001FFB4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_23:
    // 0x8001FFB8: b           L_800210CC
    // 0x8001FFBC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_800210CC;
    // 0x8001FFBC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001FFC0:
    // 0x8001FFC0: lh          $v0, 0x36($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X36);
    // 0x8001FFC4: sw          $v1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r3;
    // 0x8001FFC8: bltz        $v0, L_8001FFF0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001FFCC: addiu       $t1, $sp, 0x154
        ctx->r9 = ADD32(ctx->r29, 0X154);
            goto L_8001FFF0;
    }
    // 0x8001FFCC: addiu       $t1, $sp, 0x154
    ctx->r9 = ADD32(ctx->r29, 0X154);
    // 0x8001FFD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001FFD4: lb          $t7, -0x4D2D($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4D2D);
    // 0x8001FFD8: lw          $t9, 0x19C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X19C);
    // 0x8001FFDC: bne         $t7, $zero, L_8001FFE8
    if (ctx->r15 != 0) {
        // 0x8001FFE0: subu        $t6, $v0, $t9
        ctx->r14 = SUB32(ctx->r2, ctx->r25);
            goto L_8001FFE8;
    }
    // 0x8001FFE0: subu        $t6, $v0, $t9
    ctx->r14 = SUB32(ctx->r2, ctx->r25);
    // 0x8001FFE4: sh          $t6, 0x36($s3)
    MEM_H(0X36, ctx->r19) = ctx->r14;
L_8001FFE8:
    // 0x8001FFE8: b           L_800210C8
    // 0x8001FFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800210C8;
    // 0x8001FFEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001FFF0:
    // 0x8001FFF0: lh          $s0, 0x26($s3)
    ctx->r16 = MEM_H(ctx->r19, 0X26);
    // 0x8001FFF4: addiu       $t2, $sp, 0x140
    ctx->r10 = ADD32(ctx->r29, 0X140);
    // 0x8001FFF8: addiu       $t3, $sp, 0x12C
    ctx->r11 = ADD32(ctx->r29, 0X12C);
    // 0x8001FFFC: addiu       $t5, $sp, 0xE0
    ctx->r13 = ADD32(ctx->r29, 0XE0);
    // 0x80020000: addiu       $t4, $sp, 0xCC
    ctx->r12 = ADD32(ctx->r29, 0XCC);
    // 0x80020004: addiu       $ra, $sp, 0xB8
    ctx->r31 = ADD32(ctx->r29, 0XB8);
    // 0x80020008: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8002000C: addiu       $s2, $sp, 0x108
    ctx->r18 = ADD32(ctx->r29, 0X108);
    // 0x80020010: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_80020014:
    // 0x80020014: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020018: bne         $s0, $at, L_800201C4
    if (ctx->r16 != ctx->r1) {
        // 0x8002001C: slt         $at, $s0, $s5
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
            goto L_800201C4;
    }
    // 0x8002001C: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020020: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x80020024: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020028: beq         $t8, $zero, L_80020108
    if (ctx->r24 == 0) {
        // 0x8002002C: addu        $t6, $s4, $s5
        ctx->r14 = ADD32(ctx->r20, ctx->r21);
            goto L_80020108;
    }
    // 0x8002002C: addu        $t6, $s4, $s5
    ctx->r14 = ADD32(ctx->r20, ctx->r21);
    // 0x80020030: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x80020034: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020038: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002003C: lwc1        $f0, 0xC($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80020040: lwc1        $f10, 0xC($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80020044: nop

    // 0x80020048: sub.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8002004C: add.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020050: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x80020054: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020058: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002005C: lwc1        $f2, 0x10($t8)
    ctx->f2.u32l = MEM_W(ctx->r24, 0X10);
    // 0x80020060: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020064: nop

    // 0x80020068: sub.s       $f10, $f2, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x8002006C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x80020070: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020074: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020078: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002007C: lwc1        $f12, 0x14($t9)
    ctx->f12.u32l = MEM_W(ctx->r25, 0X14);
    // 0x80020080: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020084: nop

    // 0x80020088: sub.s       $f6, $f12, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x8002008C: add.s       $f10, $f6, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f12.fl;
    // 0x80020090: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020094: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80020098: nop

    // 0x8002009C: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x800200A0: nop

    // 0x800200A4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800200A8: nop

    // 0x800200AC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800200B0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800200B4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800200B8: nop

    // 0x800200BC: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x800200C0: nop

    // 0x800200C4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800200C8: nop

    // 0x800200CC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800200D0: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800200D4: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800200D8: nop

    // 0x800200DC: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x800200E0: nop

    // 0x800200E4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800200E8: nop

    // 0x800200EC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800200F0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800200F4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800200F8: nop

    // 0x800200FC: lwc1        $f6, 0x8($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80020100: b           L_8002052C
    // 0x80020104: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_8002052C;
    // 0x80020104: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_80020108:
    // 0x80020108: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8002010C: addu        $v0, $a2, $t8
    ctx->r2 = ADD32(ctx->r6, ctx->r24);
    // 0x80020110: lw          $t7, -0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X4);
    // 0x80020114: nop

    // 0x80020118: lwc1        $f10, 0xC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XC);
    // 0x8002011C: nop

    // 0x80020120: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020124: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80020128: nop

    // 0x8002012C: lwc1        $f4, 0x10($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80020130: nop

    // 0x80020134: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80020138: lw          $t6, -0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X4);
    // 0x8002013C: nop

    // 0x80020140: lwc1        $f8, 0x14($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X14);
    // 0x80020144: nop

    // 0x80020148: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x8002014C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80020150: nop

    // 0x80020154: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x80020158: nop

    // 0x8002015C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80020160: nop

    // 0x80020164: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020168: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x8002016C: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x80020170: nop

    // 0x80020174: lh          $t6, 0x2($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X2);
    // 0x80020178: nop

    // 0x8002017C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80020180: nop

    // 0x80020184: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020188: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x8002018C: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80020190: nop

    // 0x80020194: lh          $t7, 0x4($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X4);
    // 0x80020198: nop

    // 0x8002019C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800201A0: nop

    // 0x800201A4: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800201A8: swc1        $f10, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f10.u32l;
    // 0x800201AC: lw          $t9, -0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X4);
    // 0x800201B0: nop

    // 0x800201B4: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x800201B8: b           L_8002052C
    // 0x800201BC: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_8002052C;
    // 0x800201BC: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x800201C0: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
L_800201C4:
    // 0x800201C4: bne         $at, $zero, L_800203F8
    if (ctx->r1 != 0) {
        // 0x800201C8: addu        $a1, $s0, $s4
        ctx->r5 = ADD32(ctx->r16, ctx->r20);
            goto L_800203F8;
    }
    // 0x800201C8: addu        $a1, $s0, $s4
    ctx->r5 = ADD32(ctx->r16, ctx->r20);
    // 0x800201CC: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x800201D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800201D4: bne         $t6, $at, L_8002032C
    if (ctx->r14 != ctx->r1) {
        // 0x800201D8: addu        $v0, $s5, $s4
        ctx->r2 = ADD32(ctx->r21, ctx->r20);
            goto L_8002032C;
    }
    // 0x800201D8: addu        $v0, $s5, $s4
    ctx->r2 = ADD32(ctx->r21, ctx->r20);
    // 0x800201DC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x800201E0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x800201E4: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800201E8: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800201EC: lw          $s1, 0x3C($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X3C);
    // 0x800201F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800201F4: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800201F8: addiu       $s0, $s5, -0x1
    ctx->r16 = ADD32(ctx->r21, -0X1);
    // 0x800201FC: bne         $t6, $at, L_80020268
    if (ctx->r14 != ctx->r1) {
        // 0x80020200: addiu       $a1, $a1, -0x4
        ctx->r5 = ADD32(ctx->r5, -0X4);
            goto L_80020268;
    }
    // 0x80020200: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80020204: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x80020208: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x8002020C: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x80020210: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80020214: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80020218: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x8002021C: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80020220: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80020224: jal         0x80066828
    // 0x80020228: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    set_active_camera(rdram, ctx);
        goto after_24;
    // 0x80020228: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_24:
    // 0x8002022C: jal         0x80069F3C
    // 0x80020230: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_25;
    // 0x80020230: nop

    after_25:
    // 0x80020234: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020238: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x8002023C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80020240: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80020244: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020248: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x8002024C: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80020250: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80020254: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020258: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x8002025C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020260: b           L_80020274
    // 0x80020264: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020274;
    // 0x80020264: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020268:
    // 0x80020268: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
    // 0x8002026C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80020270: nop

L_80020274:
    // 0x80020274: lw          $t8, -0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, -0X4);
    // 0x80020278: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002027C: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80020280: nop

    // 0x80020284: sub.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x80020288: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8002028C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020290: lw          $t7, -0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, -0X4);
    // 0x80020294: lwc1        $f2, 0x10($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020298: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8002029C: nop

    // 0x800202A0: sub.s       $f8, $f2, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x800202A4: add.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800202A8: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x800202AC: lw          $t9, -0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, -0X4);
    // 0x800202B0: lwc1        $f12, 0x14($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800202B4: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x800202B8: nop

    // 0x800202BC: sub.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f10.fl;
    // 0x800202C0: add.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x800202C4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800202C8: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x800202CC: nop

    // 0x800202D0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800202D4: nop

    // 0x800202D8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800202DC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800202E0: lh          $t8, 0x4($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X4);
    // 0x800202E4: nop

    // 0x800202E8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800202EC: nop

    // 0x800202F0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800202F4: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800202F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800202FC: nop

    // 0x80020300: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80020304: nop

    // 0x80020308: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8002030C: nop

    // 0x80020310: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80020314: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x80020318: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8002031C: nop

    // 0x80020320: lwc1        $f4, 0x8($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X8);
    // 0x80020324: b           L_8002052C
    // 0x80020328: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
        goto L_8002052C;
    // 0x80020328: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_8002032C:
    // 0x8002032C: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x80020330: nop

    // 0x80020334: addu        $t8, $s4, $t6
    ctx->r24 = ADD32(ctx->r20, ctx->r14);
    // 0x80020338: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x8002033C: subu        $t9, $t7, $s5
    ctx->r25 = SUB32(ctx->r15, ctx->r21);
    // 0x80020340: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80020344: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80020348: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002034C: nop

    // 0x80020350: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80020354: nop

    // 0x80020358: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
    // 0x8002035C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80020360: nop

    // 0x80020364: lwc1        $f6, 0x10($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X10);
    // 0x80020368: nop

    // 0x8002036C: swc1        $f6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f6.u32l;
    // 0x80020370: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80020374: nop

    // 0x80020378: lwc1        $f10, 0x14($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X14);
    // 0x8002037C: nop

    // 0x80020380: swc1        $f10, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f10.u32l;
    // 0x80020384: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80020388: nop

    // 0x8002038C: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x80020390: nop

    // 0x80020394: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80020398: nop

    // 0x8002039C: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800203A0: swc1        $f8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f8.u32l;
    // 0x800203A4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800203A8: nop

    // 0x800203AC: lh          $t9, 0x2($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X2);
    // 0x800203B0: nop

    // 0x800203B4: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800203B8: nop

    // 0x800203BC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800203C0: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800203C4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800203C8: nop

    // 0x800203CC: lh          $t8, 0x4($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X4);
    // 0x800203D0: nop

    // 0x800203D4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800203D8: nop

    // 0x800203DC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800203E0: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800203E4: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800203E8: nop

    // 0x800203EC: lwc1        $f6, 0x8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800203F0: b           L_8002052C
    // 0x800203F4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_8002052C;
    // 0x800203F4: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_800203F8:
    // 0x800203F8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800203FC: addu        $a0, $a2, $t9
    ctx->r4 = ADD32(ctx->r6, ctx->r25);
    // 0x80020400: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80020404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80020408: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x8002040C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80020410: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x80020414: nop

    // 0x80020418: bne         $t6, $at, L_80020484
    if (ctx->r14 != ctx->r1) {
        // 0x8002041C: nop
    
            goto L_80020484;
    }
    // 0x8002041C: nop

    // 0x80020420: lb          $a0, 0x30($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X30);
    // 0x80020424: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80020428: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x8002042C: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80020430: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x80020434: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    // 0x80020438: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x8002043C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80020440: jal         0x80066828
    // 0x80020444: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    set_active_camera(rdram, ctx);
        goto after_26;
    // 0x80020444: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    after_26:
    // 0x80020448: jal         0x80069F3C
    // 0x8002044C: nop

    cam_get_active_camera_no_cutscenes(rdram, ctx);
        goto after_27;
    // 0x8002044C: nop

    after_27:
    // 0x80020450: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020454: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x80020458: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x8002045C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80020460: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80020464: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80020468: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x8002046C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80020470: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x80020474: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80020478: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8002047C: b           L_80020484
    // 0x80020480: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
        goto L_80020484;
    // 0x80020480: addu        $a0, $a2, $a1
    ctx->r4 = ADD32(ctx->r6, ctx->r5);
L_80020484:
    // 0x80020484: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80020488: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002048C: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
    // 0x80020490: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80020494: nop

    // 0x80020498: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x8002049C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800204A0: nop

    // 0x800204A4: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
    // 0x800204A8: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x800204AC: nop

    // 0x800204B0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800204B4: nop

    // 0x800204B8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800204BC: swc1        $f10, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f10.u32l;
    // 0x800204C0: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x800204C4: nop

    // 0x800204C8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800204CC: nop

    // 0x800204D0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800204D4: swc1        $f8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->f8.u32l;
    // 0x800204D8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800204DC: nop

    // 0x800204E0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800204E4: nop

    // 0x800204E8: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800204EC: nop

    // 0x800204F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800204F4: swc1        $f10, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f10.u32l;
    // 0x800204F8: lb          $t6, 0x22($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X22);
    // 0x800204FC: nop

    // 0x80020500: bne         $t6, $at, L_80020518
    if (ctx->r14 != ctx->r1) {
        // 0x80020504: nop
    
            goto L_80020518;
    }
    // 0x80020504: nop

    // 0x80020508: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x8002050C: nop

    // 0x80020510: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x80020514: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
L_80020518:
    // 0x80020518: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8002051C: nop

    // 0x80020520: lwc1        $f6, 0x8($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X8);
    // 0x80020524: nop

    // 0x80020528: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
L_8002052C:
    // 0x8002052C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80020530: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x80020534: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x80020538: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x8002053C: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020540: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020544: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020548: bne         $a3, $s2, L_80020014
    if (ctx->r7 != ctx->r18) {
        // 0x8002054C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80020014;
    }
    // 0x8002054C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020550: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80020554: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020558: c.eq.s      $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f22.fl == ctx->f10.fl;
    // 0x8002055C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80020560: bc1f        L_80020578
    if (!c1cs) {
        // 0x80020564: addiu       $s1, $sp, 0x154
        ctx->r17 = ADD32(ctx->r29, 0X154);
            goto L_80020578;
    }
    // 0x80020564: addiu       $s1, $sp, 0x154
    ctx->r17 = ADD32(ctx->r29, 0X154);
    // 0x80020568: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002056C: lwc1        $f4, 0x5C08($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5C08);
    // 0x80020570: nop

    // 0x80020574: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_80020578:
    // 0x80020578: lwc1        $f8, 0x4($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8002057C: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x80020580: lwc1        $f4, 0x0($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80020584: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80020588: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002058C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80020590: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80020594: add.s       $f20, $f4, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80020598: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002059C: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x800205A0: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x800205A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800205A8: bc1f        L_800205C4
    if (!c1cs) {
        // 0x800205AC: nop
    
            goto L_800205C4;
    }
    // 0x800205AC: nop

    // 0x800205B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800205B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800205B8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800205BC: sub.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f0.d - ctx->f6.d;
    // 0x800205C0: cvt.s.d     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f20.fl = CVT_S_D(ctx->f4.d);
L_800205C4:
    // 0x800205C4: lb          $t7, 0x3F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X3F);
    // 0x800205C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800205CC: bne         $t7, $zero, L_80020610
    if (ctx->r15 != 0) {
        // 0x800205D0: nop
    
            goto L_80020610;
    }
    // 0x800205D0: nop

    // 0x800205D4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205D8: jal         0x80022574
    // 0x800205DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_28;
    // 0x800205DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_28:
    // 0x800205E0: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205E4: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x800205E8: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800205EC: jal         0x80022574
    // 0x800205F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_29;
    // 0x800205F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_29:
    // 0x800205F4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800205F8: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x800205FC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020600: jal         0x80022574
    // 0x80020604: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_30;
    // 0x80020604: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x80020608: b           L_80020648
    // 0x8002060C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
        goto L_80020648;
    // 0x8002060C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_80020610:
    // 0x80020610: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020614: jal         0x800228BC
    // 0x80020618: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_31;
    // 0x80020618: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_31:
    // 0x8002061C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020620: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x80020624: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020628: jal         0x800228BC
    // 0x8002062C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_32;
    // 0x8002062C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_32:
    // 0x80020630: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020634: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020638: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002063C: jal         0x800228BC
    // 0x80020640: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    lerp(rdram, ctx);
        goto after_33;
    // 0x80020640: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x80020644: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
L_80020648:
    // 0x80020648: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8002064C: lwc1        $f8, 0xC($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020650: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020654: sub.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80020658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002065C: swc1        $f6, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f6.u32l;
    // 0x80020660: lwc1        $f10, 0x10($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020664: nop

    // 0x80020668: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002066C: swc1        $f8, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f8.u32l;
    // 0x80020670: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020674: nop

    // 0x80020678: sub.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8002067C: beq         $s0, $at, L_800206D8
    if (ctx->r16 == ctx->r1) {
        // 0x80020680: swc1        $f10, 0x11C($sp)
        MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
            goto L_800206D8;
    }
    // 0x80020680: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
    // 0x80020684: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80020688: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8002068C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80020690: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80020694: nop

    // 0x80020698: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8002069C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800206A0: jal         0x800CA030
    // 0x800206A4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_34;
    // 0x800206A4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_34:
    // 0x800206A8: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800206AC: nop

    // 0x800206B0: div.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800206B4: c.eq.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl == ctx->f2.fl;
    // 0x800206B8: nop

    // 0x800206BC: bc1t        L_800206D8
    if (c1cs) {
        // 0x800206C0: nop
    
            goto L_800206D8;
    }
    // 0x800206C0: nop

    // 0x800206C4: lwc1        $f6, 0x8($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X8);
    // 0x800206C8: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x800206CC: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800206D0: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800206D4: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
L_800206D8:
    // 0x800206D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800206DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800206E0: bne         $s0, $at, L_80020578
    if (ctx->r16 != ctx->r1) {
        // 0x800206E4: nop
    
            goto L_80020578;
    }
    // 0x800206E4: nop

    // 0x800206E8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800206EC: addiu       $a0, $sp, 0xF4
    ctx->r4 = ADD32(ctx->r29, 0XF4);
    // 0x800206F0: jal         0x80022574
    // 0x800206F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_35;
    // 0x800206F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_35:
    // 0x800206F8: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800206FC: lw          $t9, 0x40($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X40);
    // 0x80020700: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80020704: lwc1        $f8, 0xC($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80020708: nop

    // 0x8002070C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80020710: beq         $s2, $zero, L_800207A4
    if (ctx->r18 == 0) {
        // 0x80020714: swc1        $f4, 0x8($s6)
        MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
            goto L_800207A4;
    }
    // 0x80020714: swc1        $f4, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f4.u32l;
    // 0x80020718: lw          $t6, 0x168($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X168);
    // 0x8002071C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020720: bne         $t6, $at, L_800207A4
    if (ctx->r14 != ctx->r1) {
        // 0x80020724: nop
    
            goto L_800207A4;
    }
    // 0x80020724: nop

    // 0x80020728: lh          $t8, 0x26($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X26);
    // 0x8002072C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020730: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x80020734: bne         $s5, $t7, L_800207A4
    if (ctx->r21 != ctx->r15) {
        // 0x80020738: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800207A4;
    }
    // 0x80020738: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002073C: jal         0x80022574
    // 0x80020740: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_36;
    // 0x80020740: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_36:
    // 0x80020744: swc1        $f0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f0.u32l;
    // 0x80020748: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x8002074C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020750: jal         0x80022574
    // 0x80020754: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    catmull_rom_interpolation(rdram, ctx);
        goto after_37;
    // 0x80020754: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_37:
    // 0x80020758: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x8002075C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80020760: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80020764: jal         0x80022574
    // 0x80020768: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    catmull_rom_interpolation(rdram, ctx);
        goto after_38;
    // 0x80020768: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    after_38:
    // 0x8002076C: swc1        $f0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f0.u32l;
    // 0x80020770: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80020774: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020778: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x8002077C: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80020780: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80020784: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80020788: nop

    // 0x8002078C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020790: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x80020794: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80020798: nop

    // 0x8002079C: sub.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800207A0: swc1        $f4, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f4.u32l;
L_800207A4:
    // 0x800207A4: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800207A8: lwc1        $f10, 0x114($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800207B0: div.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800207B4: swc1        $f8, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->f8.u32l;
    // 0x800207B8: lwc1        $f4, 0x120($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800207BC: lwc1        $f6, 0x114($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207C0: nop

    // 0x800207C4: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800207C8: swc1        $f10, 0x20($s6)
    MEM_W(0X20, ctx->r22) = ctx->f10.u32l;
    // 0x800207CC: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800207D0: lwc1        $f4, 0x114($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X114);
    // 0x800207D4: nop

    // 0x800207D8: div.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800207DC: swc1        $f6, 0x24($s6)
    MEM_W(0X24, ctx->r22) = ctx->f6.u32l;
    // 0x800207E0: lw          $a3, 0x11C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X11C);
    // 0x800207E4: lw          $a2, 0x120($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X120);
    // 0x800207E8: lw          $a1, 0x124($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X124);
    // 0x800207EC: jal         0x80011570
    // 0x800207F0: nop

    move_object(rdram, ctx);
        goto after_39;
    // 0x800207F0: nop

    after_39:
    // 0x800207F4: lbu         $v1, 0x2E($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2E);
    // 0x800207F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800207FC: beq         $v1, $at, L_80020D6C
    if (ctx->r3 == ctx->r1) {
        // 0x80020800: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80020D6C;
    }
    // 0x80020800: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80020804: beq         $v1, $at, L_8002081C
    if (ctx->r3 == ctx->r1) {
        // 0x80020808: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8002081C;
    }
    // 0x80020808: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002080C: beq         $v1, $at, L_80020D6C
    if (ctx->r3 == ctx->r1) {
        // 0x80020810: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80020D6C;
    }
    // 0x80020810: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80020814: b           L_80020954
    // 0x80020818: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
        goto L_80020954;
    // 0x80020818: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
L_8002081C:
    // 0x8002081C: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x80020820: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020824: bne         $t9, $zero, L_80020870
    if (ctx->r25 != 0) {
        // 0x80020828: or          $a1, $s2, $zero
        ctx->r5 = ctx->r18 | 0;
            goto L_80020870;
    }
    // 0x80020828: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002082C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020830: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80020834: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020838: jal         0x80022670
    // 0x8002083C: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    cubic_spline_interpolation(rdram, ctx);
        goto after_40;
    // 0x8002083C: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_40:
    // 0x80020840: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020844: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020848: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002084C: jal         0x80022670
    // 0x80020850: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    cubic_spline_interpolation(rdram, ctx);
        goto after_41;
    // 0x80020850: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_41:
    // 0x80020854: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020858: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x8002085C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020860: jal         0x80022670
    // 0x80020864: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_42;
    // 0x80020864: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_42:
    // 0x80020868: b           L_800208A8
    // 0x8002086C: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
        goto L_800208A8;
    // 0x8002086C: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_80020870:
    // 0x80020870: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020874: jal         0x800228E4
    // 0x80020878: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    lerp_and_get_derivative(rdram, ctx);
        goto after_43;
    // 0x80020878: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_43:
    // 0x8002087C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020880: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x80020884: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020888: jal         0x800228E4
    // 0x8002088C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    lerp_and_get_derivative(rdram, ctx);
        goto after_44;
    // 0x8002088C: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    after_44:
    // 0x80020890: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020894: addiu       $a0, $sp, 0x12C
    ctx->r4 = ADD32(ctx->r29, 0X12C);
    // 0x80020898: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8002089C: jal         0x800228E4
    // 0x800208A0: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    lerp_and_get_derivative(rdram, ctx);
        goto after_45;
    // 0x800208A0: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    after_45:
    // 0x800208A4: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
L_800208A8:
    // 0x800208A8: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800208AC: mul.s       $f8, $f10, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800208B0: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208B4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800208B8: nop

    // 0x800208BC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800208C0: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800208C4: jal         0x800CA030
    // 0x800208C8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_46;
    // 0x800208C8: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_46:
    // 0x800208CC: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x800208D0: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x800208D4: bc1t        L_8002091C
    if (c1cs) {
        // 0x800208D8: nop
    
            goto L_8002091C;
    }
    // 0x800208D8: nop

    // 0x800208DC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800208E0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800208E4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800208E8: nop

    // 0x800208EC: div.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f4.d);
    // 0x800208F0: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800208F4: lwc1        $f2, 0x120($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800208F8: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800208FC: cvt.s.d     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f12.fl = CVT_S_D(ctx->f6.d);
    // 0x80020900: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80020904: nop

    // 0x80020908: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8002090C: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
    // 0x80020910: mul.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x80020914: swc1        $f2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f2.u32l;
    // 0x80020918: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_8002091C:
    // 0x8002091C: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020920: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020924: jal         0x80070990
    // 0x80020928: nop

    arctan2_f(rdram, ctx);
        goto after_47;
    // 0x80020928: nop

    after_47:
    // 0x8002092C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80020930: addu        $t6, $v0, $at
    ctx->r14 = ADD32(ctx->r2, ctx->r1);
    // 0x80020934: sh          $t6, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r14;
    // 0x80020938: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8002093C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80020940: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80020944: jal         0x80070990
    // 0x80020948: nop

    arctan2_f(rdram, ctx);
        goto after_48;
    // 0x80020948: nop

    after_48:
    // 0x8002094C: b           L_80020D6C
    // 0x80020950: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
        goto L_80020D6C;
    // 0x80020950: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_80020954:
    // 0x80020954: lui         $at, 0xC0E0
    ctx->r1 = S32(0XC0E0 << 16);
    // 0x80020958: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002095C: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80020960: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80020964: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x80020968: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002096C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80020970: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80020974: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80020978: addiu       $t4, $sp, 0xD0
    ctx->r12 = ADD32(ctx->r29, 0XD0);
    // 0x8002097C: addiu       $ra, $sp, 0xBC
    ctx->r31 = ADD32(ctx->r29, 0XBC);
    // 0x80020980: addiu       $a3, $sp, 0xCC
    ctx->r7 = ADD32(ctx->r29, 0XCC);
    // 0x80020984: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x80020988: addiu       $a1, $sp, 0xF4
    ctx->r5 = ADD32(ctx->r29, 0XF4);
L_8002098C:
    // 0x8002098C: lwc1        $f4, 0x0($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0X0);
    // 0x80020990: lwc1        $f6, -0x4($t5)
    ctx->f6.u32l = MEM_W(ctx->r13, -0X4);
    // 0x80020994: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x80020998: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8002099C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x800209A0: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x800209A4: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x800209A8: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x800209AC: bc1f        L_800209C4
    if (!c1cs) {
        // 0x800209B0: addiu       $t8, $zero, 0x5
        ctx->r24 = ADD32(0, 0X5);
            goto L_800209C4;
    }
    // 0x800209B0: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x800209B4: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x800209B8: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x800209BC: b           L_800209E0
    // 0x800209C0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_800209E0;
    // 0x800209C0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_800209C4:
    // 0x800209C4: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x800209C8: nop

    // 0x800209CC: bc1f        L_800209E0
    if (!c1cs) {
        // 0x800209D0: nop
    
            goto L_800209E0;
    }
    // 0x800209D0: nop

    // 0x800209D4: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x800209D8: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x800209DC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_800209E0:
    // 0x800209E0: beq         $at, $zero, L_80020A6C
    if (ctx->r1 == 0) {
        // 0x800209E4: or          $s0, $t0, $zero
        ctx->r16 = ctx->r8 | 0;
            goto L_80020A6C;
    }
    // 0x800209E4: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
    // 0x800209E8: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x800209EC: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x800209F0: beq         $t7, $zero, L_80020A24
    if (ctx->r15 == 0) {
        // 0x800209F4: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_80020A24;
    }
    // 0x800209F4: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x800209F8: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x800209FC: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x80020A00: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020A04:
    // 0x80020A04: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A08: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020A0C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A10: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020A14: bne         $v1, $s0, L_80020A04
    if (ctx->r3 != ctx->r16) {
        // 0x80020A18: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020A04;
    }
    // 0x80020A18: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020A1C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020A20: beq         $s0, $at, L_80020A68
    if (ctx->r16 == ctx->r1) {
        // 0x80020A24: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020A68;
    }
L_80020A24:
    // 0x80020A24: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020A28: addiu       $t7, $sp, 0xE0
    ctx->r15 = ADD32(ctx->r29, 0XE0);
    // 0x80020A2C: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020A30:
    // 0x80020A30: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020A34: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020A38: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A3C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020A40: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A44: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020A48: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020A4C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020A50: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020A54: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020A58: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020A5C: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020A60: bne         $v0, $a1, L_80020A30
    if (ctx->r2 != ctx->r5) {
        // 0x80020A64: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020A30;
    }
    // 0x80020A64: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020A68:
    // 0x80020A68: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020A6C:
    // 0x80020A6C: lwc1        $f4, 0x0($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80020A70: lwc1        $f6, -0x4($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, -0X4);
    // 0x80020A74: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80020A78: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020A7C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020A80: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020A84: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020A88: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020A8C: bc1f        L_80020AA4
    if (!c1cs) {
        // 0x80020A90: addiu       $t9, $zero, 0x5
        ctx->r25 = ADD32(0, 0X5);
            goto L_80020AA4;
    }
    // 0x80020A90: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80020A94: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020A98: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020A9C: b           L_80020AC0
    // 0x80020AA0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020AC0;
    // 0x80020AA0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020AA4:
    // 0x80020AA4: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020AA8: nop

    // 0x80020AAC: bc1f        L_80020AC0
    if (!c1cs) {
        // 0x80020AB0: nop
    
            goto L_80020AC0;
    }
    // 0x80020AB0: nop

    // 0x80020AB4: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020AB8: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020ABC: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020AC0:
    // 0x80020AC0: beq         $at, $zero, L_80020B48
    if (ctx->r1 == 0) {
        // 0x80020AC4: subu        $a0, $t9, $t0
        ctx->r4 = SUB32(ctx->r25, ctx->r8);
            goto L_80020B48;
    }
    // 0x80020AC4: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80020AC8: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80020ACC: beq         $t6, $zero, L_80020B00
    if (ctx->r14 == 0) {
        // 0x80020AD0: addu        $v1, $t6, $t0
        ctx->r3 = ADD32(ctx->r14, ctx->r8);
            goto L_80020B00;
    }
    // 0x80020AD0: addu        $v1, $t6, $t0
    ctx->r3 = ADD32(ctx->r14, ctx->r8);
    // 0x80020AD4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020AD8: addiu       $t7, $sp, 0xCC
    ctx->r15 = ADD32(ctx->r29, 0XCC);
    // 0x80020ADC: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020AE0:
    // 0x80020AE0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020AE4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020AE8: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020AEC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020AF0: bne         $v1, $s0, L_80020AE0
    if (ctx->r3 != ctx->r16) {
        // 0x80020AF4: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020AE0;
    }
    // 0x80020AF4: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020AF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020AFC: beq         $s0, $at, L_80020B44
    if (ctx->r16 == ctx->r1) {
        // 0x80020B00: sll         $t9, $s0, 2
        ctx->r25 = S32(ctx->r16 << 2);
            goto L_80020B44;
    }
L_80020B00:
    // 0x80020B00: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020B04: addiu       $t6, $sp, 0xCC
    ctx->r14 = ADD32(ctx->r29, 0XCC);
    // 0x80020B08: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020B0C:
    // 0x80020B0C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020B10: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020B14: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020B18: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020B1C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B20: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020B24: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020B28: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020B2C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020B30: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020B34: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020B38: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020B3C: bne         $v0, $a2, L_80020B0C
    if (ctx->r2 != ctx->r6) {
        // 0x80020B40: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020B0C;
    }
    // 0x80020B40: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020B44:
    // 0x80020B44: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80020B48:
    // 0x80020B48: lwc1        $f4, 0x0($ra)
    ctx->f4.u32l = MEM_W(ctx->r31, 0X0);
    // 0x80020B4C: lwc1        $f6, -0x4($ra)
    ctx->f6.u32l = MEM_W(ctx->r31, -0X4);
    // 0x80020B50: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80020B54: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80020B58: subu        $a0, $t8, $t0
    ctx->r4 = SUB32(ctx->r24, ctx->r8);
    // 0x80020B5C: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80020B60: c.lt.d      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.d < ctx->f2.d;
    // 0x80020B64: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    // 0x80020B68: bc1f        L_80020B80
    if (!c1cs) {
        // 0x80020B6C: slti        $at, $t0, 0x5
        ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
            goto L_80020B80;
    }
    // 0x80020B6C: slti        $at, $t0, 0x5
    ctx->r1 = SIGNED(ctx->r8) < 0X5 ? 1 : 0;
    // 0x80020B70: cvt.d.s     $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B74: sub.d       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f10.d - ctx->f14.d;
    // 0x80020B78: b           L_80020B9C
    // 0x80020B7C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
        goto L_80020B9C;
    // 0x80020B7C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80020B80:
    // 0x80020B80: c.lt.d      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.d < ctx->f18.d;
    // 0x80020B84: nop

    // 0x80020B88: bc1f        L_80020B9C
    if (!c1cs) {
        // 0x80020B8C: nop
    
            goto L_80020B9C;
    }
    // 0x80020B8C: nop

    // 0x80020B90: cvt.d.s     $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f4.d = CVT_D_S(ctx->f22.fl);
    // 0x80020B94: add.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = ctx->f4.d + ctx->f14.d;
    // 0x80020B98: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80020B9C:
    // 0x80020B9C: beq         $at, $zero, L_80020C1C
    if (ctx->r1 == 0) {
        // 0x80020BA0: andi        $t7, $a0, 0x3
        ctx->r15 = ctx->r4 & 0X3;
            goto L_80020C1C;
    }
    // 0x80020BA0: andi        $t7, $a0, 0x3
    ctx->r15 = ctx->r4 & 0X3;
    // 0x80020BA4: beq         $t7, $zero, L_80020BD8
    if (ctx->r15 == 0) {
        // 0x80020BA8: addu        $v1, $t7, $t0
        ctx->r3 = ADD32(ctx->r15, ctx->r8);
            goto L_80020BD8;
    }
    // 0x80020BA8: addu        $v1, $t7, $t0
    ctx->r3 = ADD32(ctx->r15, ctx->r8);
    // 0x80020BAC: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80020BB0: addiu       $t6, $sp, 0xB8
    ctx->r14 = ADD32(ctx->r29, 0XB8);
    // 0x80020BB4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
L_80020BB8:
    // 0x80020BB8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020BBC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80020BC0: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BC4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80020BC8: bne         $v1, $s0, L_80020BB8
    if (ctx->r3 != ctx->r16) {
        // 0x80020BCC: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020BB8;
    }
    // 0x80020BCC: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020BD0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020BD4: beq         $s0, $at, L_80020C1C
    if (ctx->r16 == ctx->r1) {
        // 0x80020BD8: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_80020C1C;
    }
L_80020BD8:
    // 0x80020BD8: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80020BDC: addiu       $t7, $sp, 0xB8
    ctx->r15 = ADD32(ctx->r29, 0XB8);
    // 0x80020BE0: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
L_80020BE4:
    // 0x80020BE4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80020BE8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80020BEC: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020BF0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80020BF4: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020BF8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80020BFC: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80020C00: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80020C04: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80020C08: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80020C0C: add.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80020C10: swc1        $f6, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f6.u32l;
    // 0x80020C14: bne         $v0, $a3, L_80020BE4
    if (ctx->r2 != ctx->r7) {
        // 0x80020C18: swc1        $f8, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
            goto L_80020BE4;
    }
    // 0x80020C18: swc1        $f8, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f8.u32l;
L_80020C1C:
    // 0x80020C1C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020C20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80020C24: bne         $t0, $at, L_8002098C
    if (ctx->r8 != ctx->r1) {
        // 0x80020C28: addiu       $ra, $ra, 0x4
        ctx->r31 = ADD32(ctx->r31, 0X4);
            goto L_8002098C;
    }
    // 0x80020C28: addiu       $ra, $ra, 0x4
    ctx->r31 = ADD32(ctx->r31, 0X4);
    // 0x80020C2C: lb          $t9, 0x3F($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3F);
    // 0x80020C30: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C34: bne         $t9, $zero, L_80020CD4
    if (ctx->r25 != 0) {
        // 0x80020C38: addiu       $a0, $sp, 0xE0
        ctx->r4 = ADD32(ctx->r29, 0XE0);
            goto L_80020CD4;
    }
    // 0x80020C38: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80020C3C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C40: jal         0x80022574
    // 0x80020C44: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    catmull_rom_interpolation(rdram, ctx);
        goto after_49;
    // 0x80020C44: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    after_49:
    // 0x80020C48: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020C4C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C50: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020C54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C5C: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020C60: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C64: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C68: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020C6C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020C70: jal         0x80022574
    // 0x80020C74: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    catmull_rom_interpolation(rdram, ctx);
        goto after_50;
    // 0x80020C74: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    after_50:
    // 0x80020C78: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020C7C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020C80: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020C84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020C88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020C8C: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020C90: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020C94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020C98: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020C9C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020CA0: jal         0x80022574
    // 0x80020CA4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    catmull_rom_interpolation(rdram, ctx);
        goto after_51;
    // 0x80020CA4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    after_51:
    // 0x80020CA8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020CAC: nop

    // 0x80020CB0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020CB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CBC: nop

    // 0x80020CC0: cvt.w.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CC4: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80020CC8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020CCC: b           L_80020D6C
    // 0x80020CD0: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
        goto L_80020D6C;
    // 0x80020CD0: sh          $t8, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r24;
L_80020CD4:
    // 0x80020CD4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CD8: jal         0x800228BC
    // 0x80020CDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    lerp(rdram, ctx);
        goto after_52;
    // 0x80020CDC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_52:
    // 0x80020CE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020CE4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020CE8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020CEC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020CF0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020CF4: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x80020CF8: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020CFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020D00: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80020D04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020D08: jal         0x800228BC
    // 0x80020D0C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    lerp(rdram, ctx);
        goto after_53;
    // 0x80020D0C: sh          $t9, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r25;
    after_53:
    // 0x80020D10: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80020D14: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80020D18: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80020D1C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020D20: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020D24: addiu       $a0, $sp, 0xB8
    ctx->r4 = ADD32(ctx->r29, 0XB8);
    // 0x80020D28: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020D2C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80020D30: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80020D34: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80020D38: jal         0x800228BC
    // 0x80020D3C: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    lerp(rdram, ctx);
        goto after_54;
    // 0x80020D3C: sh          $t8, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r24;
    after_54:
    // 0x80020D40: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80020D44: nop

    // 0x80020D48: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80020D4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80020D50: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80020D54: nop

    // 0x80020D58: cvt.w.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80020D5C: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80020D60: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80020D64: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x80020D68: nop

L_80020D6C:
    // 0x80020D6C: lw          $v1, 0x168($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X168);
    // 0x80020D70: lh          $t0, 0x26($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X26);
    // 0x80020D74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020D78: beq         $v1, $at, L_80020D90
    if (ctx->r3 == ctx->r1) {
        // 0x80020D7C: swc1        $f20, 0x0($s3)
        MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
            goto L_80020D90;
    }
    // 0x80020D7C: swc1        $f20, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f20.u32l;
    // 0x80020D80: slt         $at, $t0, $s5
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020D84: bne         $at, $zero, L_80020D90
    if (ctx->r1 != 0) {
        // 0x80020D88: subu        $t6, $t0, $s5
        ctx->r14 = SUB32(ctx->r8, ctx->r21);
            goto L_80020D90;
    }
    // 0x80020D88: subu        $t6, $t0, $s5
    ctx->r14 = SUB32(ctx->r8, ctx->r21);
    // 0x80020D8C: addu        $t0, $t6, $v1
    ctx->r8 = ADD32(ctx->r14, ctx->r3);
L_80020D90:
    // 0x80020D90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020D94: addiu       $t1, $t1, -0x4C0C
    ctx->r9 = ADD32(ctx->r9, -0X4C0C);
    // 0x80020D98: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020D9C: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020DA0: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80020DA4: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020DA8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020DAC: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020DB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80020DB4: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020DB8: lwc1        $f1, 0x5C10($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X5C10);
    // 0x80020DBC: lb          $t9, 0x14($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X14);
    // 0x80020DC0: lwc1        $f0, 0x5C14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5C14);
    // 0x80020DC4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80020DC8: nop

    // 0x80020DCC: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020DD0: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020DD4: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020DD8: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020DDC: c.lt.s      $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f10.fl < ctx->f22.fl;
    // 0x80020DE0: swc1        $f10, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f10.u32l;
    // 0x80020DE4: bc1f        L_80020DF8
    if (!c1cs) {
        // 0x80020DE8: nop
    
            goto L_80020DF8;
    }
    // 0x80020DE8: nop

    // 0x80020DEC: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80020DF0: b           L_80020E04
    // 0x80020DF4: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
        goto L_80020E04;
    // 0x80020DF4: swc1        $f8, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f8.u32l;
L_80020DF8:
    // 0x80020DF8: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020DFC: nop

    // 0x80020E00: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
L_80020E04:
    // 0x80020E04: lwc1        $f6, 0x124($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E08: nop

    // 0x80020E0C: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80020E10: nop

    // 0x80020E14: bc1f        L_80020EBC
    if (!c1cs) {
        // 0x80020E18: nop
    
            goto L_80020EBC;
    }
    // 0x80020E18: nop

    // 0x80020E1C: bne         $s2, $zero, L_80020EBC
    if (ctx->r18 != 0) {
        // 0x80020E20: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_80020EBC;
    }
    // 0x80020E20: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80020E24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020E28: beq         $v1, $at, L_80020E40
    if (ctx->r3 == ctx->r1) {
        // 0x80020E2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80020E40;
    }
    // 0x80020E2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80020E30: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E34: bne         $at, $zero, L_80020E40
    if (ctx->r1 != 0) {
        // 0x80020E38: subu        $t6, $v0, $s5
        ctx->r14 = SUB32(ctx->r2, ctx->r21);
            goto L_80020E40;
    }
    // 0x80020E38: subu        $t6, $v0, $s5
    ctx->r14 = SUB32(ctx->r2, ctx->r21);
    // 0x80020E3C: addu        $s0, $t6, $v1
    ctx->r16 = ADD32(ctx->r14, ctx->r3);
L_80020E40:
    // 0x80020E40: slt         $at, $s0, $s5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020E44: beq         $at, $zero, L_80020EA0
    if (ctx->r1 == 0) {
        // 0x80020E48: sll         $t7, $s4, 2
        ctx->r15 = S32(ctx->r20 << 2);
            goto L_80020EA0;
    }
    // 0x80020E48: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80020E4C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020E50: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80020E54: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80020E58: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x80020E5C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80020E60: lwc1        $f14, 0x124($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020E64: lw          $s1, 0x3C($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X3C);
    // 0x80020E68: nop

    // 0x80020E6C: lb          $v0, 0x14($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X14);
    // 0x80020E70: nop

    // 0x80020E74: bltz        $v0, L_80020E9C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80020E78: nop
    
            goto L_80020E9C;
    }
    // 0x80020E78: nop

    // 0x80020E7C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80020E80: nop

    // 0x80020E84: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80020E88: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80020E8C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80020E90: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80020E94: b           L_80020EA0
    // 0x80020E98: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
        goto L_80020EA0;
    // 0x80020E98: swc1        $f10, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f10.u32l;
L_80020E9C:
    // 0x80020E9C: swc1        $f14, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f14.u32l;
L_80020EA0:
    // 0x80020EA0: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80020EA4: lwc1        $f4, 0x124($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80020EA8: nop

    // 0x80020EAC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80020EB0: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80020EB4: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80020EB8: swc1        $f8, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f8.u32l;
L_80020EBC:
    // 0x80020EBC: beq         $s2, $zero, L_80020F7C
    if (ctx->r18 == 0) {
        // 0x80020EC0: nop
    
            goto L_80020F7C;
    }
    // 0x80020EC0: nop

    // 0x80020EC4: lh          $t9, 0x26($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X26);
    // 0x80020EC8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80020ECC: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80020ED0: bne         $v1, $at, L_80020F24
    if (ctx->r3 != ctx->r1) {
        // 0x80020ED4: sh          $t6, 0x26($s3)
        MEM_H(0X26, ctx->r19) = ctx->r14;
            goto L_80020F24;
    }
    // 0x80020ED4: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020ED8: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020EDC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x80020EE0: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020EE4: bne         $at, $zero, L_80020EF8
    if (ctx->r1 != 0) {
        // 0x80020EE8: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80020EF8;
    }
    // 0x80020EE8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80020EEC: addiu       $t8, $s5, -0x1
    ctx->r24 = ADD32(ctx->r21, -0X1);
    // 0x80020EF0: b           L_80020F7C
    // 0x80020EF4: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
        goto L_80020F7C;
    // 0x80020EF4: sh          $t8, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r24;
L_80020EF8:
    // 0x80020EF8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020EFC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020F00: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020F04: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x80020F08: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020F0C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020F10: lw          $a1, 0x3C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X3C);
    // 0x80020F14: jal         0x80021290
    // 0x80020F18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_55;
    // 0x80020F18: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_55:
    // 0x80020F1C: b           L_80020F80
    // 0x80020F20: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
        goto L_80020F80;
    // 0x80020F20: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020F24:
    // 0x80020F24: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020F28: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x80020F2C: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80020F30: beq         $at, $zero, L_80020F44
    if (ctx->r1 == 0) {
        // 0x80020F34: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_80020F44;
    }
    // 0x80020F34: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80020F38: sh          $t6, 0x26($s3)
    MEM_H(0X26, ctx->r19) = ctx->r14;
    // 0x80020F3C: lh          $v0, 0x26($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X26);
    // 0x80020F40: nop

L_80020F44:
    // 0x80020F44: slt         $at, $v0, $s5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80020F48: bne         $at, $zero, L_80020F58
    if (ctx->r1 != 0) {
        // 0x80020F4C: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80020F58;
    }
    // 0x80020F4C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80020F50: subu        $t8, $v0, $s5
    ctx->r24 = SUB32(ctx->r2, ctx->r21);
    // 0x80020F54: addu        $s2, $t8, $v1
    ctx->r18 = ADD32(ctx->r24, ctx->r3);
L_80020F58:
    // 0x80020F58: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80020F5C: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
    // 0x80020F60: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x80020F64: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80020F68: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80020F6C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80020F70: lw          $a1, 0x3C($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X3C);
    // 0x80020F74: jal         0x80021290
    // 0x80020F78: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    func_8002125C(rdram, ctx);
        goto after_56;
    // 0x80020F78: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_56:
L_80020F7C:
    // 0x80020F7C: lbu         $t7, 0x2E($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X2E);
L_80020F80:
    // 0x80020F80: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80020F84: bne         $t7, $at, L_800210AC
    if (ctx->r15 != ctx->r1) {
        // 0x80020F88: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800210AC;
    }
    // 0x80020F88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80020F8C: lh          $v1, -0x4C08($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X4C08);
    // 0x80020F90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80020F94: blez        $v1, L_80020FEC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80020F98: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80020FEC;
    }
    // 0x80020F98: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80020F9C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80020FA0: lw          $a2, -0x4C0C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C0C);
    // 0x80020FA4: lb          $v0, 0x3E($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X3E);
    // 0x80020FA8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80020FAC: nop

    // 0x80020FB0: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020FB4: nop

    // 0x80020FB8: beq         $v0, $t6, L_80020FEC
    if (ctx->r2 == ctx->r14) {
        // 0x80020FBC: nop
    
            goto L_80020FEC;
    }
    // 0x80020FBC: nop

L_80020FC0:
    // 0x80020FC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80020FC4: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80020FC8: beq         $at, $zero, L_80020FEC
    if (ctx->r1 == 0) {
        // 0x80020FCC: sll         $t8, $t0, 2
        ctx->r24 = S32(ctx->r8 << 2);
            goto L_80020FEC;
    }
    // 0x80020FCC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80020FD0: addu        $t7, $a2, $t8
    ctx->r15 = ADD32(ctx->r6, ctx->r24);
    // 0x80020FD4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80020FD8: nop

    // 0x80020FDC: lw          $t6, 0x7C($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X7C);
    // 0x80020FE0: nop

    // 0x80020FE4: bne         $v0, $t6, L_80020FC0
    if (ctx->r2 != ctx->r14) {
        // 0x80020FE8: nop
    
            goto L_80020FC0;
    }
    // 0x80020FE8: nop

L_80020FEC:
    // 0x80020FEC: beq         $t0, $v1, L_800210AC
    if (ctx->r8 == ctx->r3) {
        // 0x80020FF0: addiu       $t1, $t1, -0x4C0C
        ctx->r9 = ADD32(ctx->r9, -0X4C0C);
            goto L_800210AC;
    }
    // 0x80020FF0: addiu       $t1, $t1, -0x4C0C
    ctx->r9 = ADD32(ctx->r9, -0X4C0C);
    // 0x80020FF4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80020FF8: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80020FFC: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80021000: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80021004: nop

    // 0x80021008: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x8002100C: nop

    // 0x80021010: beq         $v1, $zero, L_800210AC
    if (ctx->r3 == 0) {
        // 0x80021014: nop
    
            goto L_800210AC;
    }
    // 0x80021014: nop

    // 0x80021018: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002101C: lwc1        $f10, 0xC($s6)
    ctx->f10.u32l = MEM_W(ctx->r22, 0XC);
    // 0x80021020: nop

    // 0x80021024: sub.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80021028: swc1        $f4, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->f4.u32l;
    // 0x8002102C: lwc1        $f6, 0x10($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X10);
    // 0x80021030: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80021034: nop

    // 0x80021038: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8002103C: swc1        $f10, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f10.u32l;
    // 0x80021040: lwc1        $f8, 0x14($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X14);
    // 0x80021044: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80021048: lwc1        $f10, 0x124($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X124);
    // 0x8002104C: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80021050: lwc1        $f8, 0x120($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X120);
    // 0x80021054: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80021058: swc1        $f6, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f6.u32l;
    // 0x8002105C: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80021060: lwc1        $f8, 0x11C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x80021064: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80021068: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8002106C: jal         0x800CA030
    // 0x80021070: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_57;
    // 0x80021070: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_57:
    // 0x80021074: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80021078: lwc1        $f14, 0x11C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x8002107C: bc1f        L_800210AC
    if (!c1cs) {
        // 0x80021080: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800210AC;
    }
    // 0x80021080: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80021084: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x80021088: jal         0x80070990
    // 0x8002108C: nop

    arctan2_f(rdram, ctx);
        goto after_58;
    // 0x8002108C: nop

    after_58:
    // 0x80021090: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x80021094: addu        $t8, $v0, $at
    ctx->r24 = ADD32(ctx->r2, ctx->r1);
    // 0x80021098: sh          $t8, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r24;
    // 0x8002109C: lwc1        $f12, 0x120($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X120);
    // 0x800210A0: jal         0x80070990
    // 0x800210A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_59;
    // 0x800210A4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_59:
    // 0x800210A8: sh          $v0, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r2;
L_800210AC:
    // 0x800210AC: lb          $t7, 0x2F($s3)
    ctx->r15 = MEM_B(ctx->r19, 0X2F);
    // 0x800210B0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800210B4: sw          $t7, 0x74($s6)
    MEM_W(0X74, ctx->r22) = ctx->r15;
    // 0x800210B8: lw          $a1, 0x19C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X19C);
    // 0x800210BC: jal         0x800B019C
    // 0x800210C0: nop

    obj_spawn_particle(rdram, ctx);
        goto after_60;
    // 0x800210C0: nop

    after_60:
    // 0x800210C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800210C8:
    // 0x800210C8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_800210CC:
    // 0x800210CC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800210D0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800210D4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800210D8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800210DC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800210E0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800210E4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800210E8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800210EC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800210F0: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800210F4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800210F8: jr          $ra
    // 0x800210FC: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x800210FC: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void get_inside_segment_count_xz(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A09C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002A0A0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A0A4: lw          $a3, -0x3178($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3178);
    // 0x8002A0A8: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8002A0AC: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8002A0B0: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A0B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002A0B8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8002A0BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002A0C0: blez        $t0, L_8002A160
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8002A0C4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002A160;
    }
    // 0x8002A0C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002A0C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8002A0CC:
    // 0x8002A0CC: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
    // 0x8002A0D0: nop

    // 0x8002A0D4: addu        $a0, $t6, $a1
    ctx->r4 = ADD32(ctx->r14, ctx->r5);
    // 0x8002A0D8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8002A0DC: nop

    // 0x8002A0E0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8002A0E4: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002A0E8: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A0EC: nop
    
            goto L_8002A150;
    }
    // 0x8002A0EC: nop

    // 0x8002A0F0: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x8002A0F4: nop

    // 0x8002A0F8: addiu       $t1, $t9, -0x4
    ctx->r9 = ADD32(ctx->r25, -0X4);
    // 0x8002A0FC: slt         $at, $t1, $s0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8002A100: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A104: nop
    
            goto L_8002A150;
    }
    // 0x8002A104: nop

    // 0x8002A108: lh          $t2, 0xA($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XA);
    // 0x8002A10C: nop

    // 0x8002A110: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x8002A114: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8002A118: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A11C: nop
    
            goto L_8002A150;
    }
    // 0x8002A11C: nop

    // 0x8002A120: lh          $t4, 0x4($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X4);
    // 0x8002A124: nop

    // 0x8002A128: addiu       $t5, $t4, -0x4
    ctx->r13 = ADD32(ctx->r12, -0X4);
    // 0x8002A12C: slt         $at, $t5, $s1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8002A130: beq         $at, $zero, L_8002A150
    if (ctx->r1 == 0) {
        // 0x8002A134: nop
    
            goto L_8002A150;
    }
    // 0x8002A134: nop

    // 0x8002A138: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x8002A13C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8002A140: lw          $a3, -0x3178($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3178);
    // 0x8002A144: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002A148: lh          $t0, 0x1A($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X1A);
    // 0x8002A14C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8002A150:
    // 0x8002A150: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002A154: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002A158: bne         $at, $zero, L_8002A0CC
    if (ctx->r1 != 0) {
        // 0x8002A15C: addiu       $a1, $a1, 0xC
        ctx->r5 = ADD32(ctx->r5, 0XC);
            goto L_8002A0CC;
    }
    // 0x8002A15C: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
L_8002A160:
    // 0x8002A160: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002A164: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002A168: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x8002A16C: jr          $ra
    // 0x8002A170: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8002A170: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void obj_loop_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003568C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80035690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035694: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80035698: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003569C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800356A0: bne         $t6, $zero, L_80035760
    if (ctx->r14 != 0) {
        // 0x800356A4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035760;
    }
    // 0x800356A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800356A8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800356AC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800356B0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800356B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356BC: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800356C0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800356C4: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x800356C8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800356CC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800356D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800356D4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800356D8: sh          $t8, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r24;
    // 0x800356DC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800356E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800356E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800356E8: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800356EC: nop

    // 0x800356F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800356F4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800356F8: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800356FC: nop

    // 0x80035700: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80035704: sh          $t0, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r8;
    // 0x80035708: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003570C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035714: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80035718: sb          $t3, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r11;
    // 0x8003571C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80035720: sb          $t4, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r12;
    // 0x80035724: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x80035728: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003572C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80035730: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80035734: jal         0x8000EA54
    // 0x80035738: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x80035738: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    after_0:
    // 0x8003573C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80035740: beq         $v0, $zero, L_80035760
    if (ctx->r2 == 0) {
        // 0x80035744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035760;
    }
    // 0x80035744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035748: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8003574C: nop

    // 0x80035750: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80035754: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
    // 0x80035758: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003575C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035760:
    // 0x80035760: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80035764: jr          $ra
    // 0x80035768: nop

    return;
    // 0x80035768: nop

;}
RECOMP_FUNC void charselect_prev(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B36C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8008B370: beq         $a0, $v0, L_8008B394
    if (ctx->r4 == ctx->r2) {
        // 0x8008B374: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_8008B394;
    }
    // 0x8008B374: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8008B378: beq         $a0, $v1, L_8008B3A0
    if (ctx->r4 == ctx->r3) {
        // 0x8008B37C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008B3A0;
    }
    // 0x8008B37C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B380: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B384: beq         $a0, $at, L_8008B394
    if (ctx->r4 == ctx->r1) {
        // 0x8008B388: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8008B394;
    }
    // 0x8008B388: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B38C: jr          $ra
    // 0x8008B390: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
    return;
    // 0x8008B390: sw          $zero, 0x550($at)
    MEM_W(0X550, ctx->r1) = 0;
L_8008B394:
    // 0x8008B394: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B398: jr          $ra
    // 0x8008B39C: sw          $v0, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r2;
    return;
    // 0x8008B39C: sw          $v0, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r2;
L_8008B3A0:
    // 0x8008B3A0: sw          $v1, 0x550($at)
    MEM_W(0X550, ctx->r1) = ctx->r3;
    // 0x8008B3A4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8008B3A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B3AC: sw          $t6, 0x554($at)
    MEM_W(0X554, ctx->r1) = ctx->r14;
    // 0x8008B3B0: jr          $ra
    // 0x8008B3B4: nop

    return;
    // 0x8008B3B4: nop

;}
RECOMP_FUNC void dialogue_open_stub(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EEE4: jr          $ra
    // 0x8009EEE8: nop

    return;
    // 0x8009EEE8: nop

;}
RECOMP_FUNC void get_particle_asset_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B49E8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B49EC: lw          $v1, 0x3278($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3278);
    // 0x800B49F0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B49F4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B49F8: beq         $at, $zero, L_800B4A18
    if (ctx->r1 == 0) {
        // 0x800B49FC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B4A18;
    }
    // 0x800B49FC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4A00: lw          $t6, 0x3280($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3280);
    // 0x800B4A04: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B4A08: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4A0C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800B4A10: jr          $ra
    // 0x800B4A14: nop

    return;
    // 0x800B4A14: nop

L_800B4A18:
    // 0x800B4A18: lw          $t9, 0x3280($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X3280);
    // 0x800B4A1C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4A20: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4A24: lw          $v0, -0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X4);
    // 0x800B4A28: nop

    // 0x800B4A2C: jr          $ra
    // 0x800B4A30: nop

    return;
    // 0x800B4A30: nop

;}
RECOMP_FUNC void update_pulsating_light_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F8B0: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F8B4: nop

    // 0x8007F8B8: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8007F8BC: bne         $at, $zero, L_8007F9DC
    if (ctx->r1 != 0) {
        // 0x8007F8C0: nop
    
            goto L_8007F9DC;
    }
    // 0x8007F8C0: nop

    // 0x8007F8C4: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F8C8: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x8007F8CC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8007F8D0: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8007F8D4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F8D8: bne         $at, $zero, L_8007F8F4
    if (ctx->r1 != 0) {
        // 0x8007F8DC: sh          $t8, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r24;
            goto L_8007F8F4;
    }
    // 0x8007F8DC: sh          $t8, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r24;
L_8007F8E0:
    // 0x8007F8E0: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x8007F8E4: andi        $v0, $t9, 0xFFFF
    ctx->r2 = ctx->r25 & 0XFFFF;
    // 0x8007F8E8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007F8EC: beq         $at, $zero, L_8007F8E0
    if (ctx->r1 == 0) {
        // 0x8007F8F0: sh          $t9, 0x4($a0)
        MEM_H(0X4, ctx->r4) = ctx->r25;
            goto L_8007F8E0;
    }
    // 0x8007F8F0: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
L_8007F8F4:
    // 0x8007F8F4: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x8007F8F8: nop

    // 0x8007F8FC: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8007F900: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8007F904: lhu         $a1, 0xE($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0XE);
    // 0x8007F908: nop

    // 0x8007F90C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F910: bne         $at, $zero, L_8007F960
    if (ctx->r1 != 0) {
        // 0x8007F914: nop
    
            goto L_8007F960;
    }
    // 0x8007F914: nop

L_8007F918:
    // 0x8007F918: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F91C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8007F920: andi        $v1, $t3, 0xFFFF
    ctx->r3 = ctx->r11 & 0XFFFF;
    // 0x8007F924: subu        $t2, $v0, $a1
    ctx->r10 = SUB32(ctx->r2, ctx->r5);
    // 0x8007F928: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007F92C: sh          $t2, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r10;
    // 0x8007F930: bne         $at, $zero, L_8007F940
    if (ctx->r1 != 0) {
        // 0x8007F934: sh          $t3, 0x2($a0)
        MEM_H(0X2, ctx->r4) = ctx->r11;
            goto L_8007F940;
    }
    // 0x8007F934: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x8007F938: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x8007F93C: andi        $v1, $zero, 0xFFFF
    ctx->r3 = 0 & 0XFFFF;
L_8007F940:
    // 0x8007F940: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8007F944: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x8007F948: lhu         $a1, 0xE($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0XE);
    // 0x8007F94C: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007F950: nop

    // 0x8007F954: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8007F958: beq         $at, $zero, L_8007F918
    if (ctx->r1 == 0) {
        // 0x8007F95C: nop
    
            goto L_8007F918;
    }
    // 0x8007F95C: nop

L_8007F960:
    // 0x8007F960: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x8007F964: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
    // 0x8007F968: slt         $at, $a3, $t7
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8007F96C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8007F970: bne         $at, $zero, L_8007F97C
    if (ctx->r1 != 0) {
        // 0x8007F974: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_8007F97C;
    }
    // 0x8007F974: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007F978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8007F97C:
    // 0x8007F97C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8007F980: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007F984: lhu         $t1, 0xC($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0XC);
    // 0x8007F988: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x8007F98C: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007F990: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8007F994: lhu         $t3, 0xE($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0XE);
    // 0x8007F998: lhu         $t5, 0xC($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0XC);
    // 0x8007F99C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007F9A0: nop

    // 0x8007F9A4: nop

    // 0x8007F9A8: div         $zero, $t2, $t3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r11)));
    // 0x8007F9AC: bne         $t3, $zero, L_8007F9B8
    if (ctx->r11 != 0) {
        // 0x8007F9B0: nop
    
            goto L_8007F9B8;
    }
    // 0x8007F9B0: nop

    // 0x8007F9B4: break       7
    do_break(2148006324);
L_8007F9B8:
    // 0x8007F9B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007F9BC: bne         $t3, $at, L_8007F9D0
    if (ctx->r11 != ctx->r1) {
        // 0x8007F9C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007F9D0;
    }
    // 0x8007F9C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F9C4: bne         $t2, $at, L_8007F9D0
    if (ctx->r10 != ctx->r1) {
        // 0x8007F9C8: nop
    
            goto L_8007F9D0;
    }
    // 0x8007F9C8: nop

    // 0x8007F9CC: break       6
    do_break(2148006348);
L_8007F9D0:
    // 0x8007F9D0: mflo        $t4
    ctx->r12 = lo;
    // 0x8007F9D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8007F9D8: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
L_8007F9DC:
    // 0x8007F9DC: jr          $ra
    // 0x8007F9E0: nop

    return;
    // 0x8007F9E0: nop

;}
RECOMP_FUNC void menu_button_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800803D8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800803DC: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
    // 0x800803E0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800803E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800803E8: beq         $a0, $zero, L_80080404
    if (ctx->r4 == 0) {
        // 0x800803EC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80080404;
    }
    // 0x800803EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800803F0: jal         0x80071380
    // 0x800803F4: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800803F4: nop

    after_0:
    // 0x800803F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800803FC: addiu       $v0, $v0, 0x232C
    ctx->r2 = ADD32(ctx->r2, 0X232C);
    // 0x80080400: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80080404:
    // 0x80080404: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80080408: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008040C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80080410: sw          $zero, 0x71EC($at)
    MEM_W(0X71EC, ctx->r1) = 0;
    // 0x80080414: addiu       $v1, $v1, 0x2324
    ctx->r3 = ADD32(ctx->r3, 0X2324);
    // 0x80080418: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008041C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80080420: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80080428: sw          $zero, 0x2338($at)
    MEM_W(0X2338, ctx->r1) = 0;
    // 0x8008042C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80080430: sw          $zero, 0x233C($at)
    MEM_W(0X233C, ctx->r1) = 0;
    // 0x80080434: jr          $ra
    // 0x80080438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80080438: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void transition_begin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C06F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C06FC: lw          $t6, 0x3730($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3730);
    // 0x800C0700: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C0704: beq         $t6, $zero, L_800C0714
    if (ctx->r14 == 0) {
        // 0x800C0708: sw          $ra, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r31;
            goto L_800C0714;
    }
    // 0x800C0708: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C070C: b           L_800C09A4
    // 0x800C0710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C09A4;
    // 0x800C0710: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0714:
    // 0x800C0714: jal         0x800C0C44
    // 0x800C0718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    transition_end(rdram, ctx);
        goto after_0;
    // 0x800C0718: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C071C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800C0720: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C0724: bne         $a0, $zero, L_800C0734
    if (ctx->r4 != 0) {
        // 0x800C0728: addiu       $v1, $v1, 0x374C
        ctx->r3 = ADD32(ctx->r3, 0X374C);
            goto L_800C0734;
    }
    // 0x800C0728: addiu       $v1, $v1, 0x374C
    ctx->r3 = ADD32(ctx->r3, 0X374C);
    // 0x800C072C: b           L_800C09A4
    // 0x800C0730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C09A4;
    // 0x800C0730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C0734:
    // 0x800C0734: lhu         $t7, 0x4($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0738: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800C073C: addiu       $a2, $a2, 0x3740
    ctx->r6 = ADD32(ctx->r6, 0X3740);
    // 0x800C0740: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    // 0x800C0744: lhu         $t8, 0x4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X4);
    // 0x800C0748: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C074C: sh          $t8, 0x3748($at)
    MEM_H(0X3748, ctx->r1) = ctx->r24;
    // 0x800C0750: lhu         $t9, 0x6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X6);
    // 0x800C0754: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0758: sh          $t9, 0x3744($at)
    MEM_H(0X3744, ctx->r1) = ctx->r25;
    // 0x800C075C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0760: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0764: andi        $t0, $v0, 0x80
    ctx->r8 = ctx->r2 & 0X80;
    // 0x800C0768: sltiu       $t1, $t0, 0x1
    ctx->r9 = ctx->r8 < 0X1 ? 1 : 0;
    // 0x800C076C: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x800C0770: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0774: addiu       $a3, $a3, -0x5310
    ctx->r7 = ADD32(ctx->r7, -0X5310);
    // 0x800C0778: andi        $t3, $t2, 0x3F
    ctx->r11 = ctx->r10 & 0X3F;
    // 0x800C077C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x800C0780: lbu         $t4, 0x0($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0784: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C0788: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x800C078C: sw          $t5, 0x3738($at)
    MEM_W(0X3738, ctx->r1) = ctx->r13;
    // 0x800C0790: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800C0794: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0798: addiu       $a1, $a1, 0x3734
    ctx->r5 = ADD32(ctx->r5, 0X3734);
    // 0x800C079C: bne         $t6, $zero, L_800C07AC
    if (ctx->r14 != 0) {
        // 0x800C07A0: sw          $zero, 0x0($a1)
        MEM_W(0X0, ctx->r5) = 0;
            goto L_800C07AC;
    }
    // 0x800C07A0: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x800C07A4: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800C07A8: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_800C07AC:
    // 0x800C07AC: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800C07B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C07B4: blez        $t9, L_800C0998
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800C07B8: addiu       $v0, $v0, -0x530C
        ctx->r2 = ADD32(ctx->r2, -0X530C);
            goto L_800C0998;
    }
    // 0x800C07B8: addiu       $v0, $v0, -0x530C
    ctx->r2 = ADD32(ctx->r2, -0X530C);
    // 0x800C07BC: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800C07C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C07C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07C8: addiu       $v1, $v1, -0x530B
    ctx->r3 = ADD32(ctx->r3, -0X530B);
    // 0x800C07CC: sw          $t0, -0x5308($at)
    MEM_W(-0X5308, ctx->r1) = ctx->r8;
    // 0x800C07D0: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x800C07D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C07D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07DC: addiu       $a1, $a1, -0x530A
    ctx->r5 = ADD32(ctx->r5, -0X530A);
    // 0x800C07E0: sw          $t1, -0x5304($at)
    MEM_W(-0X5304, ctx->r1) = ctx->r9;
    // 0x800C07E4: lbu         $t2, 0x0($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X0);
    // 0x800C07E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07EC: sw          $t2, -0x5300($at)
    MEM_W(-0X5300, ctx->r1) = ctx->r10;
    // 0x800C07F0: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x800C07F4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800C07F8: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x800C07FC: lbu         $t4, 0x2($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X2);
    // 0x800C0800: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x800C0804: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x800C0808: lbu         $t5, 0x3($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X3);
    // 0x800C080C: beq         $at, $zero, L_800C0998
    if (ctx->r1 == 0) {
        // 0x800C0810: sb          $t5, 0x0($a1)
        MEM_B(0X0, ctx->r5) = ctx->r13;
            goto L_800C0998;
    }
    // 0x800C0810: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
    // 0x800C0814: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800C0818: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C081C: addu        $at, $at, $t6
    gpr jr_addend_800C0828 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800C0820: lw          $t6, -0x67B0($at)
    ctx->r14 = ADD32(ctx->r1, -0X67B0);
    // 0x800C0824: nop

    // 0x800C0828: jr          $t6
    // 0x800C082C: nop

    switch (jr_addend_800C0828 >> 2) {
        case 0: goto L_800C0830; break;
        case 1: goto L_800C0840; break;
        case 2: goto L_800C0890; break;
        case 3: goto L_800C08E0; break;
        case 4: goto L_800C08F0; break;
        case 5: goto L_800C0940; break;
        case 6: goto L_800C0990; break;
        default: switch_error(__func__, 0x800C0828, 0x800E9850);
    }
    // 0x800C082C: nop

L_800C0830:
    // 0x800C0830: jal         0x800C0CA0
    // 0x800C0834: nop

    transition_fullscreen_start(rdram, ctx);
        goto after_1;
    // 0x800C0834: nop

    after_1:
    // 0x800C0838: b           L_800C0998
    // 0x800C083C: nop

        goto L_800C0998;
    // 0x800C083C: nop

L_800C0840:
    // 0x800C0840: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0844: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C0848: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C084C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C0850: addiu       $v0, $v0, 0x3860
    ctx->r2 = ADD32(ctx->r2, 0X3860);
    // 0x800C0854: addiu       $t9, $t9, 0x3848
    ctx->r25 = ADD32(ctx->r25, 0X3848);
    // 0x800C0858: addiu       $t8, $t8, 0x383C
    ctx->r24 = ADD32(ctx->r24, 0X383C);
    // 0x800C085C: addiu       $t7, $t7, 0x3830
    ctx->r15 = ADD32(ctx->r15, 0X3830);
    // 0x800C0860: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0864: addiu       $a3, $a3, 0x37C0
    ctx->r7 = ADD32(ctx->r7, 0X37C0);
    // 0x800C0868: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C086C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800C0870: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800C0874: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0878: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C087C: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C0880: jal         0x800C1020
    // 0x800C0884: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_2;
    // 0x800C0884: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_2:
    // 0x800C0888: b           L_800C0998
    // 0x800C088C: nop

        goto L_800C0998;
    // 0x800C088C: nop

L_800C0890:
    // 0x800C0890: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0894: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C0898: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C089C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C08A0: addiu       $v0, $v0, 0x3860
    ctx->r2 = ADD32(ctx->r2, 0X3860);
    // 0x800C08A4: addiu       $t2, $t2, 0x3848
    ctx->r10 = ADD32(ctx->r10, 0X3848);
    // 0x800C08A8: addiu       $t1, $t1, 0x383C
    ctx->r9 = ADD32(ctx->r9, 0X383C);
    // 0x800C08AC: addiu       $t0, $t0, 0x3830
    ctx->r8 = ADD32(ctx->r8, 0X3830);
    // 0x800C08B0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C08B4: addiu       $a3, $a3, 0x37F8
    ctx->r7 = ADD32(ctx->r7, 0X37F8);
    // 0x800C08B8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800C08BC: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800C08C0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800C08C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C08C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C08CC: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800C08D0: jal         0x800C1020
    // 0x800C08D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    transition_init_shape(rdram, ctx);
        goto after_3;
    // 0x800C08D4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x800C08D8: b           L_800C0998
    // 0x800C08DC: nop

        goto L_800C0998;
    // 0x800C08DC: nop

L_800C08E0:
    // 0x800C08E0: jal         0x800C1AF4
    // 0x800C08E4: nop

    transition_init_circle(rdram, ctx);
        goto after_4;
    // 0x800C08E4: nop

    after_4:
    // 0x800C08E8: b           L_800C0998
    // 0x800C08EC: nop

        goto L_800C0998;
    // 0x800C08EC: nop

L_800C08F0:
    // 0x800C08F0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C08F4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C08F8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C08FC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800C0900: addiu       $v0, $v0, 0x3A88
    ctx->r2 = ADD32(ctx->r2, 0X3A88);
    // 0x800C0904: addiu       $t5, $t5, 0x3AE4
    ctx->r13 = ADD32(ctx->r13, 0X3AE4);
    // 0x800C0908: addiu       $t4, $t4, 0x39D0
    ctx->r12 = ADD32(ctx->r12, 0X39D0);
    // 0x800C090C: addiu       $t3, $t3, 0x3A2C
    ctx->r11 = ADD32(ctx->r11, 0X3A2C);
    // 0x800C0910: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0914: addiu       $a3, $a3, 0x38D4
    ctx->r7 = ADD32(ctx->r7, 0X38D4);
    // 0x800C0918: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800C091C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800C0920: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800C0924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0928: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C092C: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x800C0930: jal         0x800C1020
    // 0x800C0934: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    transition_init_shape(rdram, ctx);
        goto after_5;
    // 0x800C0934: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x800C0938: b           L_800C0998
    // 0x800C093C: nop

        goto L_800C0998;
    // 0x800C093C: nop

L_800C0940:
    // 0x800C0940: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C0944: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C0948: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C094C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C0950: addiu       $v0, $v0, 0x38C8
    ctx->r2 = ADD32(ctx->r2, 0X38C8);
    // 0x800C0954: addiu       $t8, $t8, 0x38B4
    ctx->r24 = ADD32(ctx->r24, 0X38B4);
    // 0x800C0958: addiu       $t7, $t7, 0x38A8
    ctx->r15 = ADD32(ctx->r15, 0X38A8);
    // 0x800C095C: addiu       $t6, $t6, 0x389C
    ctx->r14 = ADD32(ctx->r14, 0X389C);
    // 0x800C0960: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C0964: addiu       $a3, $a3, 0x386C
    ctx->r7 = ADD32(ctx->r7, 0X386C);
    // 0x800C0968: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C096C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C0970: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x800C0974: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C0978: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C097C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C0980: jal         0x800C1020
    // 0x800C0984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    transition_init_shape(rdram, ctx);
        goto after_6;
    // 0x800C0984: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_6:
    // 0x800C0988: b           L_800C0998
    // 0x800C098C: nop

        goto L_800C0998;
    // 0x800C098C: nop

L_800C0990:
    // 0x800C0990: jal         0x800C2B60
    // 0x800C0994: nop

    transition_init_blank(rdram, ctx);
        goto after_7;
    // 0x800C0994: nop

    after_7:
L_800C0998:
    // 0x800C0998: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C099C: lw          $v0, 0x373C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X373C);
    // 0x800C09A0: nop

L_800C09A4:
    // 0x800C09A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C09A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C09AC: jr          $ra
    // 0x800C09B0: nop

    return;
    // 0x800C09B0: nop

;}
RECOMP_FUNC void force_mark_write_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EE58: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EE5C: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EE60: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EE64: addiu       $at, $zero, -0xC01
    ctx->r1 = ADD32(0, -0XC01);
    // 0x8006EE68: andi        $t0, $a0, 0x3
    ctx->r8 = ctx->r4 & 0X3;
    // 0x8006EE6C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x8006EE70: ori         $t9, $t7, 0x40
    ctx->r25 = ctx->r15 | 0X40;
    // 0x8006EE74: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x8006EE78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8006EE7C: or          $t2, $t9, $t1
    ctx->r10 = ctx->r25 | ctx->r9;
    // 0x8006EE80: jr          $ra
    // 0x8006EE84: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    return;
    // 0x8006EE84: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void postrace_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096C94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80096C98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096C9C: jal         0x8006BFF0
    // 0x80096CA0: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x80096CA0: nop

    after_0:
    // 0x80096CA4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096CA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80096CAC: jal         0x8009C9EC
    // 0x80096CB0: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    menu_assetgroup_free(rdram, ctx);
        goto after_1;
    // 0x80096CB0: addiu       $a0, $a0, 0xFA4
    ctx->r4 = ADD32(ctx->r4, 0XFA4);
    after_1:
    // 0x80096CB4: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80096CB8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80096CBC: lw          $t7, 0x7178($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7178);
    // 0x80096CC0: lb          $v0, 0x0($t6)
    ctx->r2 = MEM_B(ctx->r14, 0X0);
    // 0x80096CC4: beq         $t7, $zero, L_80096CF4
    if (ctx->r15 == 0) {
        // 0x80096CC8: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80096CF4;
    }
    // 0x80096CC8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80096CCC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80096CD0: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x80096CD4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80096CD8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096CDC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80096CE0: lh          $a0, 0xC90($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XC90);
    // 0x80096CE4: jal         0x8009CA4C
    // 0x80096CE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    menu_asset_free(rdram, ctx);
        goto after_2;
    // 0x80096CE8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80096CEC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80096CF0: nop

L_80096CF4:
    // 0x80096CF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80096CF8: lw          $t0, 0x717C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X717C);
    // 0x80096CFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D00: beq         $t0, $zero, L_80096D28
    if (ctx->r8 == 0) {
        // 0x80096D04: sw          $zero, 0x7178($at)
        MEM_W(0X7178, ctx->r1) = 0;
            goto L_80096D28;
    }
    // 0x80096D04: sw          $zero, 0x7178($at)
    MEM_W(0X7178, ctx->r1) = 0;
    // 0x80096D08: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x80096D0C: subu        $t1, $t1, $v0
    ctx->r9 = SUB32(ctx->r9, ctx->r2);
    // 0x80096D10: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x80096D14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096D18: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    // 0x80096D1C: lh          $a0, 0xC92($a0)
    ctx->r4 = MEM_H(ctx->r4, 0XC92);
    // 0x80096D20: jal         0x8009CA4C
    // 0x80096D24: nop

    menu_asset_free(rdram, ctx);
        goto after_3;
    // 0x80096D24: nop

    after_3:
L_80096D28:
    // 0x80096D28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096D2C: jal         0x80098724
    // 0x80096D30: sw          $zero, 0x717C($at)
    MEM_W(0X717C, ctx->r1) = 0;
    menu_unload_bigfont(rdram, ctx);
        goto after_4;
    // 0x80096D30: sw          $zero, 0x717C($at)
    MEM_W(0X717C, ctx->r1) = 0;
    after_4:
    // 0x80096D34: jal         0x80000968
    // 0x80096D38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_5;
    // 0x80096D38: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80096D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80096D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80096D44: jr          $ra
    // 0x80096D48: nop

    return;
    // 0x80096D48: nop

;}
RECOMP_FUNC void render_subtitles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3020: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C3024: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C3028: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C302C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C3030: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C3034: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C3038: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C303C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C3040: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C3044: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C3048: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C304C: jal         0x800C59F4
    // 0x800C3050: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    dialogue_clear(rdram, ctx);
        goto after_0;
    // 0x800C3050: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_0:
    // 0x800C3054: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C3058: lh          $t6, -0x5288($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X5288);
    // 0x800C305C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C3060: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x800C3064: bne         $at, $zero, L_800C3084
    if (ctx->r1 != 0) {
        // 0x800C3068: addiu       $s1, $s1, -0x528C
        ctx->r17 = ADD32(ctx->r17, -0X528C);
            goto L_800C3084;
    }
    // 0x800C3068: addiu       $s1, $s1, -0x528C
    ctx->r17 = ADD32(ctx->r17, -0X528C);
    // 0x800C306C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3070: addiu       $s0, $s0, -0x5290
    ctx->r16 = ADD32(ctx->r16, -0X5290);
    // 0x800C3074: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800C3078: nop

    // 0x800C307C: addiu       $t8, $t7, -0xE
    ctx->r24 = ADD32(ctx->r15, -0XE);
    // 0x800C3080: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C3084:
    // 0x800C3084: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3088: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C308C: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C3090: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x800C3094: addiu       $s7, $s7, -0x528E
    ctx->r23 = ADD32(ctx->r23, -0X528E);
    // 0x800C3098: addiu       $s6, $s6, -0x5292
    ctx->r22 = ADD32(ctx->r22, -0X5292);
    // 0x800C309C: addiu       $s0, $s0, -0x5290
    ctx->r16 = ADD32(ctx->r16, -0X5290);
    // 0x800C30A0: lh          $a2, 0x0($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X0);
    // 0x800C30A4: lh          $a1, 0x0($s6)
    ctx->r5 = MEM_H(ctx->r22, 0X0);
    // 0x800C30A8: lh          $a3, 0x0($s7)
    ctx->r7 = MEM_H(ctx->r23, 0X0);
    // 0x800C30AC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30B0: jal         0x800C543C
    // 0x800C30B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C30B4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x800C30B8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C30BC: addiu       $s5, $s5, -0x5298
    ctx->r21 = ADD32(ctx->r21, -0X5298);
    // 0x800C30C0: lh          $t0, 0x0($s5)
    ctx->r8 = MEM_H(ctx->r21, 0X0);
    // 0x800C30C4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800C30CC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800C30D0: sll         $t1, $t1, 5
    ctx->r9 = S32(ctx->r9 << 5);
    // 0x800C30D4: sra         $t2, $t1, 8
    ctx->r10 = S32(SIGNED(ctx->r9) >> 8);
    // 0x800C30D8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C30DC: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800C30E0: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x800C30E4: jal         0x800C551C
    // 0x800C30E8: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C30E8: addiu       $a3, $zero, 0x60
    ctx->r7 = ADD32(0, 0X60);
    after_2:
    // 0x800C30EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C30F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C30F4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C30F8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C30FC: jal         0x800C55B0
    // 0x800C3100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_3;
    // 0x800C3100: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x800C3104: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3108: lh          $v0, -0x5288($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5288);
    // 0x800C310C: lh          $v1, 0x0($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X0);
    // 0x800C3110: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x800C3114: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800C3118: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800C311C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800C3120: subu        $t4, $t3, $v1
    ctx->r12 = SUB32(ctx->r11, ctx->r3);
    // 0x800C3124: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C3128: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C312C: subu        $s3, $t6, $t7
    ctx->r19 = SUB32(ctx->r14, ctx->r15);
    // 0x800C3130: addiu       $s3, $s3, 0x2
    ctx->r19 = ADD32(ctx->r19, 0X2);
    // 0x800C3134: sra         $t8, $s3, 1
    ctx->r24 = S32(SIGNED(ctx->r19) >> 1);
    // 0x800C3138: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800C313C: bne         $at, $zero, L_800C314C
    if (ctx->r1 != 0) {
        // 0x800C3140: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800C314C;
    }
    // 0x800C3140: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x800C3144: addiu       $t9, $v1, 0xE
    ctx->r25 = ADD32(ctx->r3, 0XE);
    // 0x800C3148: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
L_800C314C:
    // 0x800C314C: blez        $v0, L_800C328C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C3150: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800C328C;
    }
    // 0x800C3150: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800C3154: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C3158: addiu       $s2, $s2, -0x5280
    ctx->r18 = ADD32(ctx->r18, -0X5280);
    // 0x800C315C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
L_800C3160:
    // 0x800C3160: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800C3164: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C3168: lbu         $a1, 0x5($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0X5);
    // 0x800C316C: jal         0x800C54DC
    // 0x800C3170: nop

    set_dialogue_font(rdram, ctx);
        goto after_4;
    // 0x800C3170: nop

    after_4:
    // 0x800C3174: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800C3178: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C317C: lbu         $s0, 0x6($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X6);
    // 0x800C3180: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800C3184: bne         $s0, $fp, L_800C31A8
    if (ctx->r16 != ctx->r30) {
        // 0x800C3188: nop
    
            goto L_800C31A8;
    }
    // 0x800C3188: nop

    // 0x800C318C: lh          $t1, 0x0($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X0);
    // 0x800C3190: lh          $t2, 0x0($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X0);
    // 0x800C3194: nop

    // 0x800C3198: subu        $s1, $t1, $t2
    ctx->r17 = SUB32(ctx->r9, ctx->r10);
    // 0x800C319C: sra         $t3, $s1, 1
    ctx->r11 = S32(SIGNED(ctx->r17) >> 1);
    // 0x800C31A0: b           L_800C31C8
    // 0x800C31A4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
        goto L_800C31C8;
    // 0x800C31A4: or          $s1, $t3, $zero
    ctx->r17 = ctx->r11 | 0;
L_800C31A8:
    // 0x800C31A8: bne         $s0, $at, L_800C31C8
    if (ctx->r16 != ctx->r1) {
        // 0x800C31AC: addiu       $s1, $zero, 0x8
        ctx->r17 = ADD32(0, 0X8);
            goto L_800C31C8;
    }
    // 0x800C31AC: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x800C31B0: lh          $t4, 0x0($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X0);
    // 0x800C31B4: lh          $t5, 0x0($s6)
    ctx->r13 = MEM_H(ctx->r22, 0X0);
    // 0x800C31B8: nop

    // 0x800C31BC: subu        $s1, $t4, $t5
    ctx->r17 = SUB32(ctx->r12, ctx->r13);
    // 0x800C31C0: b           L_800C31C8
    // 0x800C31C4: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
        goto L_800C31C8;
    // 0x800C31C4: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
L_800C31C8:
    // 0x800C31C8: lbu         $a1, 0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X1);
    // 0x800C31CC: lbu         $a2, 0x2($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X2);
    // 0x800C31D0: lbu         $a3, 0x3($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X3);
    // 0x800C31D4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C31D8: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C31DC: lh          $t8, 0x0($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X0);
    // 0x800C31E0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C31E4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C31E8: mflo        $t9
    ctx->r25 = lo;
    // 0x800C31EC: sra         $t0, $t9, 8
    ctx->r8 = S32(SIGNED(ctx->r25) >> 8);
    // 0x800C31F0: jal         0x800C5560
    // 0x800C31F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    set_current_text_colour(rdram, ctx);
        goto after_5;
    // 0x800C31F4: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_5:
    // 0x800C31F8: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C31FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C3200: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800C3204: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C3208: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C320C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800C3210: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3214: jal         0x800C56C8
    // 0x800C3218: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C3218: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_6:
    // 0x800C321C: lh          $t3, 0x0($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X0);
    // 0x800C3220: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3224: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x800C3228: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x800C322C: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800C3230: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800C3234: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800C3238: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C323C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3240: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C3244: jal         0x800C5560
    // 0x800C3248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_text_colour(rdram, ctx);
        goto after_7;
    // 0x800C3248: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x800C324C: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800C3250: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C3254: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800C3258: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C325C: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x800C3260: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800C3264: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C3268: jal         0x800C56C8
    // 0x800C326C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_8;
    // 0x800C326C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_8:
    // 0x800C3270: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3274: lh          $t7, -0x5288($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X5288);
    // 0x800C3278: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C327C: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C3280: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800C3284: bne         $at, $zero, L_800C3160
    if (ctx->r1 != 0) {
        // 0x800C3288: addiu       $s3, $s3, 0xE
        ctx->r19 = ADD32(ctx->r19, 0XE);
            goto L_800C3160;
    }
    // 0x800C3288: addiu       $s3, $s3, 0xE
    ctx->r19 = ADD32(ctx->r19, 0XE);
L_800C328C:
    // 0x800C328C: jal         0x800C5B54
    // 0x800C3290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    open_dialogue_box(rdram, ctx);
        goto after_9;
    // 0x800C3290: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_9:
    // 0x800C3294: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C3298: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C329C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C32A0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C32A4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C32A8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C32AC: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C32B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C32B4: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C32B8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C32BC: jr          $ra
    // 0x800C32C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C32C0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void static_3_800041FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800041FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80004200: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004204: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80004208: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000420C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004210: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004214: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004218: andi        $s4, $a2, 0xFFFF
    ctx->r20 = ctx->r6 & 0XFFFF;
    // 0x8000421C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004220: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004224: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80004228: jal         0x800C9F90
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8000422C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80004230: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80004234: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x80004238: nop

    // 0x8000423C: beq         $s0, $zero, L_800042A4
    if (ctx->r16 == 0) {
        // 0x80004240: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_800042A4;
    }
    // 0x80004240: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_80004244:
    // 0x80004244: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x80004248: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000424C: bne         $s3, $t6, L_80004298
    if (ctx->r19 != ctx->r14) {
        // 0x80004250: nop
    
            goto L_80004298;
    }
    // 0x80004250: nop

    // 0x80004254: lhu         $t7, 0xC($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0XC);
    // 0x80004258: nop

    // 0x8000425C: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x80004260: beq         $t8, $zero, L_80004298
    if (ctx->r24 == 0) {
        // 0x80004264: nop
    
            goto L_80004298;
    }
    // 0x80004264: nop

    // 0x80004268: beq         $s1, $zero, L_80004284
    if (ctx->r17 == 0) {
        // 0x8000426C: nop
    
            goto L_80004284;
    }
    // 0x8000426C: nop

    // 0x80004270: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80004274: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x80004278: nop

    // 0x8000427C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80004280: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
L_80004284:
    // 0x80004284: jal         0x800C8CC0
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80004288: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000428C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80004290: jal         0x800C8CF0
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x80004294: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_80004298:
    // 0x80004298: bne         $s1, $zero, L_80004244
    if (ctx->r17 != 0) {
        // 0x8000429C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80004244;
    }
    // 0x8000429C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800042A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
L_800042A4:
    // 0x800042A4: jal         0x800C9F90
    // 0x800042A8: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800042A8: nop

    after_3:
    // 0x800042AC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800042B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800042B4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800042B8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800042BC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800042C0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800042C4: jr          $ra
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800042C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void static_3_80065994(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065994: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80065998: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8006599C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800659A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800659A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800659A8: lwc1        $f5, 0x7450($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7450);
    // 0x800659AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800659B0: lwc1        $f4, 0x7454($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7454);
    // 0x800659B4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800659B8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800659BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800659C0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800659C4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x800659C8: nop

    // 0x800659CC: div.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = DIV_D(ctx->f18.d, ctx->f4.d);
    // 0x800659D0: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800659D4: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x800659D8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800659DC: nop

    // 0x800659E0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800659E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800659E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800659EC: nop

    // 0x800659F0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800659F4: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800659F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800659FC: jr          $ra
    // 0x80065A00: nop

    return;
    // 0x80065A00: nop

;}
RECOMP_FUNC void static_3_80065A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065A2C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
    // 0x80065A30: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80065A34: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x80065A38: beq         $v1, $zero, L_80065A84
    if (ctx->r3 == 0) {
        // 0x80065A3C: ori         $v0, $v0, 0xFFFF
        ctx->r2 = ctx->r2 | 0XFFFF;
            goto L_80065A84;
    }
    // 0x80065A3C: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x80065A40: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x80065A44: nop

L_80065A48:
    // 0x80065A48: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80065A4C: nop

    // 0x80065A50: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x80065A54: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80065A58: beq         $at, $zero, L_80065A74
    if (ctx->r1 == 0) {
        // 0x80065A5C: nop
    
            goto L_80065A74;
    }
    // 0x80065A5C: nop

    // 0x80065A60: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80065A64: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    // 0x80065A68: lw          $a2, 0x20($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X20);
    // 0x80065A6C: nop

    // 0x80065A70: subu        $v0, $t8, $a2
    ctx->r2 = SUB32(ctx->r24, ctx->r6);
L_80065A74:
    // 0x80065A74: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80065A78: nop

    // 0x80065A7C: bne         $v1, $zero, L_80065A48
    if (ctx->r3 != 0) {
        // 0x80065A80: nop
    
            goto L_80065A48;
    }
    // 0x80065A80: nop

L_80065A84:
    // 0x80065A84: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x80065A88: nop

    // 0x80065A8C: lw          $v0, 0x10($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X10);
    // 0x80065A90: jr          $ra
    // 0x80065A94: nop

    return;
    // 0x80065A94: nop

    // 0x80065A98: nop

    // 0x80065A9C: nop

;}
RECOMP_FUNC void static_3_80070A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_3_80070AD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void static_3_8007A3F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A3F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A3FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A400: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A404: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8007A408: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8007A40C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A410: beq         $a1, $zero, L_8007A488
    if (ctx->r5 == 0) {
        // 0x8007A414: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8007A488;
    }
    // 0x8007A414: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8007A418: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x8007A41C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007A420: bne         $t6, $at, L_8007A440
    if (ctx->r14 != ctx->r1) {
        // 0x8007A424: nop
    
            goto L_8007A440;
    }
    // 0x8007A424: nop

    // 0x8007A428: jal         0x800D1E00
    // 0x8007A42C: nop

    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A42C: nop

    after_0:
    // 0x8007A430: jal         0x800C7E30
    // 0x8007A434: nop

    osGetCount_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A434: nop

    after_1:
    // 0x8007A438: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A43C: sw          $v0, 0x66C0($at)
    MEM_W(0X66C0, ctx->r1) = ctx->r2;
L_8007A440:
    // 0x8007A440: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x8007A444: addiu       $at, $zero, -0x31
    ctx->r1 = ADD32(0, -0X31);
    // 0x8007A448: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8007A44C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x8007A450: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    // 0x8007A454: jal         0x800D256C
    // 0x8007A458: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_2;
    // 0x8007A458: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x8007A45C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8007A460: jal         0x800D26CC
    // 0x8007A464: nop

    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_3;
    // 0x8007A464: nop

    after_3:
    // 0x8007A468: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A46C: sw          $zero, -0x132C($at)
    MEM_W(-0X132C, ctx->r1) = 0;
    // 0x8007A470: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007A474: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A478: sw          $zero, -0x1328($at)
    MEM_W(-0X1328, ctx->r1) = 0;
    // 0x8007A47C: bne         $s0, $s1, L_8007A488
    if (ctx->r16 != ctx->r17) {
        // 0x8007A480: sw          $s0, 0x274($t9)
        MEM_W(0X274, ctx->r25) = ctx->r16;
            goto L_8007A488;
    }
    // 0x8007A480: sw          $s0, 0x274($t9)
    MEM_W(0X274, ctx->r25) = ctx->r16;
    // 0x8007A484: sw          $s1, 0x278($t9)
    MEM_W(0X278, ctx->r25) = ctx->r17;
L_8007A488:
    // 0x8007A488: beq         $s1, $zero, L_8007A4C0
    if (ctx->r17 == 0) {
        // 0x8007A48C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A4C0;
    }
    // 0x8007A48C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A490: beq         $s1, $s0, L_8007A4C0
    if (ctx->r17 == ctx->r16) {
        // 0x8007A494: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A4C0;
    }
    // 0x8007A494: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A498: lw          $t0, 0x3C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X3C);
    // 0x8007A49C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007A4A0: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x8007A4A4: lw          $a3, 0x4($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X4);
    // 0x8007A4A8: jal         0x800D1E40
    // 0x8007A4AC: nop

    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_4;
    // 0x8007A4AC: nop

    after_4:
    // 0x8007A4B0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A4B4: nop

    // 0x8007A4B8: sw          $s1, 0x278($t1)
    MEM_W(0X278, ctx->r9) = ctx->r17;
    // 0x8007A4BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A4C0:
    // 0x8007A4C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A4C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A4C8: jr          $ra
    // 0x8007A4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007A4CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void static_3_8007A4D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A4D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A4D8: lw          $v0, 0x274($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X274);
    // 0x8007A4DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007A4E0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8007A4E4: nop

    // 0x8007A4E8: bne         $t6, $at, L_8007A518
    if (ctx->r14 != ctx->r1) {
        // 0x8007A4EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007A518;
    }
    // 0x8007A4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007A4F0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8007A4F4: nop

    // 0x8007A4F8: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x8007A4FC: jal         0x800D2710
    // 0x8007A500: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    osGetTime_recomp(rdram, ctx);
        goto after_0;
    // 0x8007A500: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    after_0:
    // 0x8007A504: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A508: sw          $v0, 0x66B8($at)
    MEM_W(0X66B8, ctx->r1) = ctx->r2;
    // 0x8007A50C: jal         0x800D27A0
    // 0x8007A510: sw          $v1, 0x66BC($at)
    MEM_W(0X66BC, ctx->r1) = ctx->r3;
    osSpTaskYield_recomp(rdram, ctx);
        goto after_1;
    // 0x8007A510: sw          $v1, 0x66BC($at)
    MEM_W(0X66BC, ctx->r1) = ctx->r3;
    after_1:
    // 0x8007A514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007A518:
    // 0x8007A518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007A51C: jr          $ra
    // 0x8007A520: nop

    return;
    // 0x8007A520: nop

;}
RECOMP_FUNC void static_3_8007A524(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A524: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007A528: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007A52C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007A530: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A534: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007A538: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
L_8007A53C:
    // 0x8007A53C: lw          $t6, 0x284($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X284);
    // 0x8007A540: lw          $s0, 0x268($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X268);
    // 0x8007A544: lw          $v0, 0x264($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X264);
    // 0x8007A548: beq         $t6, $zero, L_8007A5A4
    if (ctx->r14 == 0) {
        // 0x8007A54C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007A5A4;
    }
    // 0x8007A54C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007A550: andi        $t7, $a3, 0x2
    ctx->r15 = ctx->r7 & 0X2;
    // 0x8007A554: beq         $t7, $zero, L_8007A5A8
    if (ctx->r15 == 0) {
        // 0x8007A558: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8007A5A8;
    }
    // 0x8007A558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007A55C: beq         $s0, $zero, L_8007A580
    if (ctx->r16 == 0) {
        // 0x8007A560: nop
    
            goto L_8007A580;
    }
    // 0x8007A560: nop

    // 0x8007A564: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8007A568: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A56C: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x8007A570: beq         $t9, $zero, L_8007A580
    if (ctx->r25 == 0) {
        // 0x8007A574: nop
    
            goto L_8007A580;
    }
    // 0x8007A574: nop

    // 0x8007A578: b           L_8007A6F4
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_8007A6F4;
    // 0x8007A57C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_8007A580:
    // 0x8007A580: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8007A584: lw          $t2, 0x264($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X264);
    // 0x8007A588: sw          $zero, 0x284($s1)
    MEM_W(0X284, ctx->r17) = 0;
    // 0x8007A58C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007A590: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A594: bne         $t3, $zero, L_8007A6F4
    if (ctx->r11 != 0) {
        // 0x8007A598: sw          $t3, 0x264($s1)
        MEM_W(0X264, ctx->r17) = ctx->r11;
            goto L_8007A6F4;
    }
    // 0x8007A598: sw          $t3, 0x264($s1)
    MEM_W(0X264, ctx->r17) = ctx->r11;
    // 0x8007A59C: b           L_8007A6F4
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A5A0: sw          $zero, 0x26C($s1)
    MEM_W(0X26C, ctx->r17) = 0;
L_8007A5A4:
    // 0x8007A5A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8007A5A8:
    // 0x8007A5A8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8007A5AC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8007A5B0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8007A5B4: jal         0x8007A238
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    __scTaskReady(rdram, ctx);
        goto after_0;
    // 0x8007A5B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007A5BC: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8007A5C0: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007A5C4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8007A5C8: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8007A5CC: addiu       $t0, $zero, -0x3
    ctx->r8 = ADD32(0, -0X3);
    // 0x8007A5D0: beq         $v0, $zero, L_8007A6F4
    if (ctx->r2 == 0) {
        // 0x8007A5D4: addiu       $t1, $zero, -0x2
        ctx->r9 = ADD32(0, -0X2);
            goto L_8007A6F4;
    }
    // 0x8007A5D4: addiu       $t1, $zero, -0x2
    ctx->r9 = ADD32(0, -0X2);
    // 0x8007A5D8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x8007A5DC: nop

    // 0x8007A5E0: andi        $t6, $t5, 0x7
    ctx->r14 = ctx->r13 & 0X7;
    // 0x8007A5E4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007A5E8: sltiu       $at, $t7, 0x7
    ctx->r1 = ctx->r15 < 0X7 ? 1 : 0;
    // 0x8007A5EC: beq         $at, $zero, L_8007A6F4
    if (ctx->r1 == 0) {
        // 0x8007A5F0: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8007A6F4;
    }
    // 0x8007A5F0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A5F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007A5F8: addu        $at, $at, $t7
    gpr jr_addend_8007A604 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A5FC: lw          $t7, 0x7F00($at)
    ctx->r15 = ADD32(ctx->r1, 0X7F00);
    // 0x8007A600: nop

    // 0x8007A604: jr          $t7
    // 0x8007A608: nop

    switch (jr_addend_8007A604 >> 2) {
        case 0: goto L_8007A6F4; break;
        case 1: goto L_8007A698; break;
        case 2: goto L_8007A60C; break;
        case 3: goto L_8007A6F4; break;
        case 4: goto L_8007A6F4; break;
        case 5: goto L_8007A698; break;
        case 6: goto L_8007A698; break;
        default: switch_error(__func__, 0x8007A604, 0x800E7F00);
    }
    // 0x8007A608: nop

L_8007A60C:
    // 0x8007A60C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8007A610: andi        $t2, $a3, 0x2
    ctx->r10 = ctx->r7 & 0X2;
    // 0x8007A614: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x8007A618: beq         $t9, $zero, L_8007A668
    if (ctx->r25 == 0) {
        // 0x8007A61C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8007A668;
    }
    // 0x8007A61C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007A620: beq         $t2, $zero, L_8007A6F4
    if (ctx->r10 == 0) {
        // 0x8007A624: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A624: nop

    // 0x8007A628: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A62C: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8007A630: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A634: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8007A638: beq         $t4, $zero, L_8007A648
    if (ctx->r12 == 0) {
        // 0x8007A63C: nop
    
            goto L_8007A648;
    }
    // 0x8007A63C: nop

    // 0x8007A640: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A644: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
L_8007A648:
    // 0x8007A648: lw          $t5, 0x268($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X268);
    // 0x8007A64C: nop

    // 0x8007A650: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8007A654: nop

    // 0x8007A658: bne         $t6, $zero, L_8007A6F4
    if (ctx->r14 != 0) {
        // 0x8007A65C: sw          $t6, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r14;
            goto L_8007A6F4;
    }
    // 0x8007A65C: sw          $t6, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r14;
    // 0x8007A660: b           L_8007A6F4
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A664: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A668:
    // 0x8007A668: bne         $a3, $at, L_8007A6F4
    if (ctx->r7 != ctx->r1) {
        // 0x8007A66C: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A66C: nop

    // 0x8007A670: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A674: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A678: lw          $t8, 0x268($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X268);
    // 0x8007A67C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8007A680: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8007A684: and         $v1, $a3, $at
    ctx->r3 = ctx->r7 & ctx->r1;
    // 0x8007A688: bne         $t9, $zero, L_8007A6F4
    if (ctx->r25 != 0) {
        // 0x8007A68C: sw          $t9, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r25;
            goto L_8007A6F4;
    }
    // 0x8007A68C: sw          $t9, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r25;
    // 0x8007A690: b           L_8007A6F4
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
        goto L_8007A6F4;
    // 0x8007A694: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A698:
    // 0x8007A698: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A69C: andi        $t4, $a3, 0x2
    ctx->r12 = ctx->r7 & 0X2;
    // 0x8007A6A0: andi        $t3, $v0, 0x2
    ctx->r11 = ctx->r2 & 0X2;
    // 0x8007A6A4: beq         $t3, $zero, L_8007A6C4
    if (ctx->r11 == 0) {
        // 0x8007A6A8: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6A8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6AC: beq         $t4, $zero, L_8007A6C4
    if (ctx->r12 == 0) {
        // 0x8007A6B0: andi        $t5, $v0, 0x1
        ctx->r13 = ctx->r2 & 0X1;
            goto L_8007A6C4;
    }
    // 0x8007A6B0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8007A6B4: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x8007A6B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8007A6BC: and         $v1, $a3, $t0
    ctx->r3 = ctx->r7 & ctx->r8;
    // 0x8007A6C0: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
L_8007A6C4:
    // 0x8007A6C4: beq         $t5, $zero, L_8007A6F4
    if (ctx->r13 == 0) {
        // 0x8007A6C8: andi        $t6, $v1, 0x1
        ctx->r14 = ctx->r3 & 0X1;
            goto L_8007A6F4;
    }
    // 0x8007A6C8: andi        $t6, $v1, 0x1
    ctx->r14 = ctx->r3 & 0X1;
    // 0x8007A6CC: beq         $t6, $zero, L_8007A6F4
    if (ctx->r14 == 0) {
        // 0x8007A6D0: nop
    
            goto L_8007A6F4;
    }
    // 0x8007A6D0: nop

    // 0x8007A6D4: sw          $s0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r16;
    // 0x8007A6D8: lw          $t7, 0x268($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X268);
    // 0x8007A6DC: and         $v1, $v1, $t1
    ctx->r3 = ctx->r3 & ctx->r9;
    // 0x8007A6E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007A6E4: nop

    // 0x8007A6E8: bne         $t8, $zero, L_8007A6F4
    if (ctx->r24 != 0) {
        // 0x8007A6EC: sw          $t8, 0x268($s1)
        MEM_W(0X268, ctx->r17) = ctx->r24;
            goto L_8007A6F4;
    }
    // 0x8007A6EC: sw          $t8, 0x268($s1)
    MEM_W(0X268, ctx->r17) = ctx->r24;
    // 0x8007A6F0: sw          $zero, 0x270($s1)
    MEM_W(0X270, ctx->r17) = 0;
L_8007A6F4:
    // 0x8007A6F4: beq         $v1, $a3, L_8007A708
    if (ctx->r3 == ctx->r7) {
        // 0x8007A6F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8007A708;
    }
    // 0x8007A6F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A6FC: b           L_8007A53C
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8007A53C;
    // 0x8007A700: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x8007A704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8007A708:
    // 0x8007A708: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007A70C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007A710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007A714: jr          $ra
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8007A718: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007A71C: nop

;}
RECOMP_FUNC void static_3_800C7B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B10: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x800C7B14: bne         $t6, $zero, L_800C7BF4
    if (ctx->r14 != 0) {
        // 0x800C7B18: nop
    
            goto L_800C7BF4;
    }
    // 0x800C7B18: nop

    // 0x800C7B1C: lh          $t7, 0xE($a0)
    ctx->r15 = MEM_H(ctx->r4, 0XE);
    // 0x800C7B20: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C7B24: sb          $t1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r9;
    // 0x800C7B28: blez        $t7, L_800C7BF4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800C7B2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7BF4;
    }
    // 0x800C7B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7B30: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7B34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C7B38: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
L_800C7B3C:
    // 0x800C7B3C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C7B40: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C7B44: lbu         $t6, 0xE($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0XE);
    // 0x800C7B48: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x800C7B4C: bnel        $t6, $zero, L_800C7BE0
    if (ctx->r14 != 0) {
        // 0x800C7B50: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_0;
    // 0x800C7B50: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_0:
    // 0x800C7B54: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800C7B58: sb          $t1, 0xE($t9)
    MEM_B(0XE, ctx->r25) = ctx->r9;
    // 0x800C7B5C: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7B60: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800C7B64: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x800C7B68: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x800C7B6C: addu        $t6, $t9, $a1
    ctx->r14 = ADD32(ctx->r25, ctx->r5);
    // 0x800C7B70: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x800C7B74: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800C7B78: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x800C7B7C: lbu         $t9, 0x9($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X9);
    // 0x800C7B80: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800C7B84: bnel        $t9, $zero, L_800C7BE0
    if (ctx->r25 != 0) {
        // 0x800C7B88: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_1;
    // 0x800C7B88: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_1:
    // 0x800C7B8C: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800C7B90: lbu         $a2, 0x8($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X8);
    // 0x800C7B94: sb          $t1, 0x9($t8)
    MEM_B(0X9, ctx->r24) = ctx->r9;
    // 0x800C7B98: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C7B9C: bne         $a2, $zero, L_800C7BC4
    if (ctx->r6 != 0) {
        // 0x800C7BA0: sw          $t7, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->r15;
            goto L_800C7BC4;
    }
    // 0x800C7BA0: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800C7BA4: lw          $t8, 0x10($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X10);
    // 0x800C7BA8: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C7BAC: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C7BB0: beq         $a2, $zero, L_800C7BDC
    if (ctx->r6 == 0) {
        // 0x800C7BB4: sw          $t9, 0x10($t0)
        MEM_W(0X10, ctx->r8) = ctx->r25;
            goto L_800C7BDC;
    }
    // 0x800C7BB4: sw          $t9, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r25;
    // 0x800C7BB8: addu        $t6, $a2, $a1
    ctx->r14 = ADD32(ctx->r6, ctx->r5);
    // 0x800C7BBC: b           L_800C7BDC
    // 0x800C7BC0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
        goto L_800C7BDC;
    // 0x800C7BC0: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
L_800C7BC4:
    // 0x800C7BC4: bnel        $t2, $a2, L_800C7BE0
    if (ctx->r10 != ctx->r6) {
        // 0x800C7BC8: lh          $t8, 0xE($a0)
        ctx->r24 = MEM_H(ctx->r4, 0XE);
            goto L_800C7BE0;
    }
    goto skip_2;
    // 0x800C7BC8: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    skip_2:
    // 0x800C7BCC: lw          $a2, 0xC($t0)
    ctx->r6 = MEM_W(ctx->r8, 0XC);
    // 0x800C7BD0: beq         $a2, $zero, L_800C7BDC
    if (ctx->r6 == 0) {
        // 0x800C7BD4: addu        $t7, $a2, $a1
        ctx->r15 = ADD32(ctx->r6, ctx->r5);
            goto L_800C7BDC;
    }
    // 0x800C7BD4: addu        $t7, $a2, $a1
    ctx->r15 = ADD32(ctx->r6, ctx->r5);
    // 0x800C7BD8: sw          $t7, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r15;
L_800C7BDC:
    // 0x800C7BDC: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
L_800C7BE0:
    // 0x800C7BE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7BE4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C7BE8: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800C7BEC: bnel        $at, $zero, L_800C7B3C
    if (ctx->r1 != 0) {
        // 0x800C7BF0: lw          $t8, 0x10($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X10);
            goto L_800C7B3C;
    }
    goto skip_3;
    // 0x800C7BF0: lw          $t8, 0x10($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X10);
    skip_3:
L_800C7BF4:
    // 0x800C7BF4: jr          $ra
    // 0x800C7BF8: nop

    return;
    // 0x800C7BF8: nop

    // 0x800C7BFC: jr          $ra
    // 0x800C7C00: nop

    return;
    // 0x800C7C00: nop

;}
RECOMP_FUNC void static_3_800C8140(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8140: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800C8144: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C8148: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C814C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C8150: beql        $t6, $zero, L_800C8188
    if (ctx->r14 == 0) {
        // 0x800C8154: lw          $a3, 0x18($a2)
        ctx->r7 = MEM_W(ctx->r6, 0X18);
            goto L_800C8188;
    }
    goto skip_0;
    // 0x800C8154: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
    skip_0:
    // 0x800C8158: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C815C: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x800C8160: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C8164: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C8168: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C816C: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C8170: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x800C8174: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x800C8178: sb          $t6, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r14;
    // 0x800C817C: jr          $ra
    // 0x800C8180: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C8180: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800C8184: lw          $a3, 0x18($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X18);
L_800C8188:
    // 0x800C8188: addiu       $t0, $zero, 0xFE
    ctx->r8 = ADD32(0, 0XFE);
    // 0x800C818C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C8190: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C8194: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x800C8198: bne         $t0, $v1, L_800C81FC
    if (ctx->r8 != ctx->r3) {
        // 0x800C819C: nop
    
            goto L_800C81FC;
    }
    // 0x800C819C: nop

    // 0x800C81A0: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x800C81A4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800C81A8: sw          $t9, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r25;
    // 0x800C81AC: beq         $t0, $a0, L_800C81FC
    if (ctx->r8 == ctx->r4) {
        // 0x800C81B0: addiu       $t6, $t9, 0x1
        ctx->r14 = ADD32(ctx->r25, 0X1);
            goto L_800C81FC;
    }
    // 0x800C81B0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C81B4: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C81B8: sw          $t6, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r14;
    // 0x800C81BC: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800C81C0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800C81C4: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x800C81C8: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x800C81CC: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x800C81D0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800C81D4: addiu       $t9, $t7, -0x4
    ctx->r25 = ADD32(ctx->r15, -0X4);
    // 0x800C81D8: sw          $t9, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r25;
    // 0x800C81DC: sb          $a1, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r5;
    // 0x800C81E0: lw          $a3, 0x58($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X58);
    // 0x800C81E4: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C81E8: addiu       $t8, $a3, 0x1
    ctx->r24 = ADD32(ctx->r7, 0X1);
    // 0x800C81EC: sw          $t8, 0x58($a2)
    MEM_W(0X58, ctx->r6) = ctx->r24;
    // 0x800C81F0: lbu         $t6, 0x98($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X98);
    // 0x800C81F4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800C81F8: sb          $t7, 0x98($v0)
    MEM_B(0X98, ctx->r2) = ctx->r15;
L_800C81FC:
    // 0x800C81FC: jr          $ra
    // 0x800C8200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800C8200: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void static_3_800C8204(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8204: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C8208: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C820C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C8210: jal         0x800C8140
    // 0x800C8214: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_0;
    // 0x800C8214: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C8218: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x800C821C: beq         $t6, $zero, L_800C8248
    if (ctx->r14 == 0) {
        // 0x800C8220: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_800C8248;
    }
    // 0x800C8220: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x800C8224: andi        $t1, $v0, 0x7F
    ctx->r9 = ctx->r2 & 0X7F;
L_800C8228:
    // 0x800C8228: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800C822C: jal         0x800C8140
    // 0x800C8230: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_1;
    // 0x800C8230: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C8234: sll         $t7, $t1, 7
    ctx->r15 = S32(ctx->r9 << 7);
    // 0x800C8238: andi        $t8, $v0, 0x7F
    ctx->r24 = ctx->r2 & 0X7F;
    // 0x800C823C: andi        $t9, $v0, 0x80
    ctx->r25 = ctx->r2 & 0X80;
    // 0x800C8240: bne         $t9, $zero, L_800C8228
    if (ctx->r25 != 0) {
        // 0x800C8244: addu        $t1, $t7, $t8
        ctx->r9 = ADD32(ctx->r15, ctx->r24);
            goto L_800C8228;
    }
    // 0x800C8244: addu        $t1, $t7, $t8
    ctx->r9 = ADD32(ctx->r15, ctx->r24);
L_800C8248:
    // 0x800C8248: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C824C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C8250: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800C8254: jr          $ra
    // 0x800C8258: nop

    return;
    // 0x800C8258: nop

    // 0x800C825C: jr          $ra
    // 0x800C8260: nop

    return;
    // 0x800C8260: nop

;}
RECOMP_FUNC void static_3_800CB1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB1BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CB1C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB1C4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800CB1C8: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CB1CC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800CB1D0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CB1D4: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800CB1D8: nop

    // 0x800CB1DC: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800CB1E0: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800CB1E4: nop

    // 0x800CB1E8: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CB1EC: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB1F0: nop

    // 0x800CB1F4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800CB1F8: nop

    // 0x800CB1FC: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800CB200: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB204: nop

    // 0x800CB208: bne         $t0, $zero, L_800CB21C
    if (ctx->r8 != 0) {
        // 0x800CB20C: nop
    
            goto L_800CB21C;
    }
    // 0x800CB20C: nop

    // 0x800CB210: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB214: b           L_800CB654
    // 0x800CB218: nop

        goto L_800CB654;
    // 0x800CB218: nop

L_800CB21C:
    // 0x800CB21C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800CB220: nop

    // 0x800CB224: beq         $t1, $zero, L_800CB234
    if (ctx->r9 == 0) {
        // 0x800CB228: nop
    
            goto L_800CB234;
    }
    // 0x800CB228: nop

    // 0x800CB22C: b           L_800CB24C
    // 0x800CB230: nop

        goto L_800CB24C;
    // 0x800CB230: nop

L_800CB234:
    // 0x800CB234: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CB238: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CB23C: addiu       $a1, $a1, -0x64D8
    ctx->r5 = ADD32(ctx->r5, -0X64D8);
    // 0x800CB240: addiu       $a0, $a0, -0x64E0
    ctx->r4 = ADD32(ctx->r4, -0X64E0);
    // 0x800CB244: jal         0x800B74A0
    // 0x800CB248: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    __assert_recomp(rdram, ctx);
        goto after_0;
    // 0x800CB248: addiu       $a2, $zero, 0x175
    ctx->r6 = ADD32(0, 0X175);
    after_0:
L_800CB24C:
    // 0x800CB24C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800CB250: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800CB254: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CB258: lw          $t9, 0x4($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X4);
    // 0x800CB25C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800CB260: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB264: lw          $a3, 0x60($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X60);
    // 0x800CB268: jalr        $t9
    // 0x800CB26C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB26C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_1:
    // 0x800CB270: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800CB274: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB278: nop

    // 0x800CB27C: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CB280: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CB284: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
    // 0x800CB288: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CB28C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB290: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x800CB294: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CB298: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CB29C: or          $t0, $t8, $at
    ctx->r8 = ctx->r24 | ctx->r1;
    // 0x800CB2A0: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x800CB2A4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CB2A8: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB2AC: lh          $t2, 0x0($t3)
    ctx->r10 = MEM_H(ctx->r11, 0X0);
    // 0x800CB2B0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CB2B4: addiu       $t9, $t2, 0x440
    ctx->r25 = ADD32(ctx->r10, 0X440);
    // 0x800CB2B8: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CB2BC: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800CB2C0: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800CB2C4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CB2C8: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x800CB2CC: sw          $t0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r8;
    // 0x800CB2D0: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB2D4: nop

    // 0x800CB2D8: addiu       $t2, $t3, 0x8
    ctx->r10 = ADD32(ctx->r11, 0X8);
    // 0x800CB2DC: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800CB2E0: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CB2E4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CB2E8: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800CB2EC: lh          $t4, 0x0($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X0);
    // 0x800CB2F0: lui         $at, 0x808
    ctx->r1 = S32(0X808 << 16);
    // 0x800CB2F4: addiu       $t6, $t4, 0x580
    ctx->r14 = ADD32(ctx->r12, 0X580);
    // 0x800CB2F8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CB2FC: or          $t5, $t7, $at
    ctx->r13 = ctx->r15 | ctx->r1;
    // 0x800CB300: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x800CB304: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CB308: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800CB30C: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800CB310: nop

    // 0x800CB314: addiu       $t9, $t1, 0x6C0
    ctx->r25 = ADD32(ctx->r9, 0X6C0);
    // 0x800CB318: andi        $t4, $t9, 0xFFFF
    ctx->r12 = ctx->r25 & 0XFFFF;
    // 0x800CB31C: addiu       $t3, $t1, 0x800
    ctx->r11 = ADD32(ctx->r9, 0X800);
    // 0x800CB320: andi        $t2, $t3, 0xFFFF
    ctx->r10 = ctx->r11 & 0XFFFF;
    // 0x800CB324: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x800CB328: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x800CB32C: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x800CB330: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB334: nop

    // 0x800CB338: lw          $t0, 0x38($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X38);
    // 0x800CB33C: nop

    // 0x800CB340: beq         $t0, $zero, L_800CB5E8
    if (ctx->r8 == 0) {
        // 0x800CB344: nop
    
            goto L_800CB5E8;
    }
    // 0x800CB344: nop

    // 0x800CB348: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CB34C: nop

    // 0x800CB350: sw          $zero, 0x38($t3)
    MEM_W(0X38, ctx->r11) = 0;
    // 0x800CB354: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB358: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CB35C: lh          $t9, 0x18($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X18);
    // 0x800CB360: lh          $t6, 0x1A($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X1A);
    // 0x800CB364: sll         $t4, $t9, 1
    ctx->r12 = S32(ctx->r25 << 1);
    // 0x800CB368: addu        $t2, $t2, $t4
    ctx->r10 = ADD32(ctx->r10, ctx->r12);
    // 0x800CB36C: lh          $t2, 0x3D30($t2)
    ctx->r10 = MEM_H(ctx->r10, 0X3D30);
    // 0x800CB370: nop

    // 0x800CB374: multu       $t2, $t6
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB378: mflo        $t7
    ctx->r15 = lo;
    // 0x800CB37C: sra         $t5, $t7, 15
    ctx->r13 = S32(SIGNED(ctx->r15) >> 15);
    // 0x800CB380: sh          $t5, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r13;
    // 0x800CB384: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB388: nop

    // 0x800CB38C: lh          $t0, 0x1C($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X1C);
    // 0x800CB390: lh          $t3, 0x28($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X28);
    // 0x800CB394: lw          $t9, 0x34($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X34);
    // 0x800CB398: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800CB39C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CB3A0: addiu       $t4, $t8, 0x24
    ctx->r12 = ADD32(ctx->r24, 0X24);
    // 0x800CB3A4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800CB3A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800CB3AC: cvt.d.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CB3B0: jal         0x800CB834
    // 0x800CB3B4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    static_3_800CB834(rdram, ctx);
        goto after_2;
    // 0x800CB3B4: cvt.d.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.d = CVT_D_W(ctx->f6.u32l);
    after_2:
    // 0x800CB3B8: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3BC: nop

    // 0x800CB3C0: sh          $v0, 0x26($t2)
    MEM_H(0X26, ctx->r10) = ctx->r2;
    // 0x800CB3C4: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3C8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CB3CC: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CB3D0: lh          $t3, 0x1A($t6)
    ctx->r11 = MEM_H(ctx->r14, 0X1A);
    // 0x800CB3D4: negu        $t5, $t7
    ctx->r13 = SUB32(0, ctx->r15);
    // 0x800CB3D8: sll         $t1, $t5, 1
    ctx->r9 = S32(ctx->r13 << 1);
    // 0x800CB3DC: addu        $t0, $t0, $t1
    ctx->r8 = ADD32(ctx->r8, ctx->r9);
    // 0x800CB3E0: lh          $t0, 0x3E2E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3E2E);
    // 0x800CB3E4: nop

    // 0x800CB3E8: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB3EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800CB3F0: sra         $t8, $t9, 15
    ctx->r24 = S32(SIGNED(ctx->r25) >> 15);
    // 0x800CB3F4: sh          $t8, 0x2E($t6)
    MEM_H(0X2E, ctx->r14) = ctx->r24;
    // 0x800CB3F8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x800CB3FC: nop

    // 0x800CB400: lh          $t2, 0x1E($t4)
    ctx->r10 = MEM_H(ctx->r12, 0X1E);
    // 0x800CB404: lh          $t7, 0x2E($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X2E);
    // 0x800CB408: lw          $t5, 0x34($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X34);
    // 0x800CB40C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800CB410: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CB414: addiu       $t1, $t4, 0x2A
    ctx->r9 = ADD32(ctx->r12, 0X2A);
    // 0x800CB418: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CB41C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800CB420: cvt.d.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.d = CVT_D_W(ctx->f8.u32l);
    // 0x800CB424: jal         0x800CB834
    // 0x800CB428: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    static_3_800CB834(rdram, ctx);
        goto after_3;
    // 0x800CB428: cvt.d.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.d = CVT_D_W(ctx->f10.u32l);
    after_3:
    // 0x800CB42C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CB430: nop

    // 0x800CB434: sh          $v0, 0x2C($t0)
    MEM_H(0X2C, ctx->r8) = ctx->r2;
    // 0x800CB438: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB43C: nop

    // 0x800CB440: addiu       $t9, $t3, 0x8
    ctx->r25 = ADD32(ctx->r11, 0X8);
    // 0x800CB444: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x800CB448: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    // 0x800CB44C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB450: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CB454: lh          $t6, 0x1C($t8)
    ctx->r14 = MEM_H(ctx->r24, 0X1C);
    // 0x800CB458: lui         $at, 0x906
    ctx->r1 = S32(0X906 << 16);
    // 0x800CB45C: andi        $t2, $t6, 0xFFFF
    ctx->r10 = ctx->r14 & 0XFFFF;
    // 0x800CB460: or          $t7, $t2, $at
    ctx->r15 = ctx->r10 | ctx->r1;
    // 0x800CB464: sw          $t7, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r15;
    // 0x800CB468: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CB46C: nop

    // 0x800CB470: sw          $zero, 0x4($t4)
    MEM_W(0X4, ctx->r12) = 0;
    // 0x800CB474: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB478: nop

    // 0x800CB47C: addiu       $t0, $t1, 0x8
    ctx->r8 = ADD32(ctx->r9, 0X8);
    // 0x800CB480: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CB484: sw          $t1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r9;
    // 0x800CB488: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CB48C: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800CB490: lh          $t9, 0x1E($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X1E);
    // 0x800CB494: lui         $at, 0x904
    ctx->r1 = S32(0X904 << 16);
    // 0x800CB498: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800CB49C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800CB4A0: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800CB4A4: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800CB4A8: nop

    // 0x800CB4AC: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800CB4B0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB4B4: nop

    // 0x800CB4B8: addiu       $t4, $t5, 0x8
    ctx->r12 = ADD32(ctx->r13, 0X8);
    // 0x800CB4BC: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CB4C0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x800CB4C4: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB4C8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800CB4CC: lh          $t0, 0x28($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X28);
    // 0x800CB4D0: lui         $at, 0x902
    ctx->r1 = S32(0X902 << 16);
    // 0x800CB4D4: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CB4D8: or          $t9, $t3, $at
    ctx->r25 = ctx->r11 | ctx->r1;
    // 0x800CB4DC: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x800CB4E0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800CB4E4: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800CB4E8: lh          $t2, 0x26($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X26);
    // 0x800CB4EC: lhu         $t4, 0x24($t6)
    ctx->r12 = MEM_HU(ctx->r14, 0X24);
    // 0x800CB4F0: andi        $t7, $t2, 0xFFFF
    ctx->r15 = ctx->r10 & 0XFFFF;
    // 0x800CB4F4: sll         $t5, $t7, 16
    ctx->r13 = S32(ctx->r15 << 16);
    // 0x800CB4F8: andi        $t1, $t4, 0xFFFF
    ctx->r9 = ctx->r12 & 0XFFFF;
    // 0x800CB4FC: or          $t0, $t5, $t1
    ctx->r8 = ctx->r13 | ctx->r9;
    // 0x800CB500: sw          $t0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r8;
    // 0x800CB504: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB508: nop

    // 0x800CB50C: addiu       $t8, $t9, 0x8
    ctx->r24 = ADD32(ctx->r25, 0X8);
    // 0x800CB510: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CB514: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800CB518: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB51C: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB520: lh          $t7, 0x2E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X2E);
    // 0x800CB524: lui         $at, 0x900
    ctx->r1 = S32(0X900 << 16);
    // 0x800CB528: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CB52C: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x800CB530: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x800CB534: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CB538: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB53C: lh          $t0, 0x2C($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X2C);
    // 0x800CB540: lhu         $t8, 0x2A($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X2A);
    // 0x800CB544: andi        $t3, $t0, 0xFFFF
    ctx->r11 = ctx->r8 & 0XFFFF;
    // 0x800CB548: sll         $t9, $t3, 16
    ctx->r25 = S32(ctx->r11 << 16);
    // 0x800CB54C: andi        $t2, $t8, 0xFFFF
    ctx->r10 = ctx->r24 & 0XFFFF;
    // 0x800CB550: or          $t7, $t9, $t2
    ctx->r15 = ctx->r25 | ctx->r10;
    // 0x800CB554: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800CB558: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB55C: nop

    // 0x800CB560: addiu       $t5, $t4, 0x8
    ctx->r13 = ADD32(ctx->r12, 0X8);
    // 0x800CB564: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x800CB568: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CB56C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CB570: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CB574: lh          $t3, 0x20($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X20);
    // 0x800CB578: lui         $at, 0x908
    ctx->r1 = S32(0X908 << 16);
    // 0x800CB57C: andi        $t1, $t3, 0xFFFF
    ctx->r9 = ctx->r11 & 0XFFFF;
    // 0x800CB580: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800CB584: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x800CB588: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CB58C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CB590: lh          $t7, 0x22($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X22);
    // 0x800CB594: nop

    // 0x800CB598: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800CB59C: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800CB5A0: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB5A4: nop

    // 0x800CB5A8: addiu       $t0, $t5, 0x8
    ctx->r8 = ADD32(ctx->r13, 0X8);
    // 0x800CB5AC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x800CB5B0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800CB5B4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800CB5B8: lui         $t3, 0x309
    ctx->r11 = S32(0X309 << 16);
    // 0x800CB5BC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x800CB5C0: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CB5C4: nop

    // 0x800CB5C8: lw          $a0, 0x14($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X14);
    // 0x800CB5CC: jal         0x800C9250
    // 0x800CB5D0: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x800CB5D0: nop

    after_4:
    // 0x800CB5D4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB5D8: nop

    // 0x800CB5DC: sw          $v0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r2;
    // 0x800CB5E0: b           L_800CB628
    // 0x800CB5E4: nop

        goto L_800CB628;
    // 0x800CB5E4: nop

L_800CB5E8:
    // 0x800CB5E8: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB5EC: nop

    // 0x800CB5F0: addiu       $t7, $t2, 0x8
    ctx->r15 = ADD32(ctx->r10, 0X8);
    // 0x800CB5F4: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800CB5F8: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800CB5FC: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800CB600: lui         $t6, 0x308
    ctx->r14 = S32(0X308 << 16);
    // 0x800CB604: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x800CB608: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800CB60C: nop

    // 0x800CB610: lw          $a0, 0x14($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X14);
    // 0x800CB614: jal         0x800C9250
    // 0x800CB618: nop

    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x800CB618: nop

    after_5:
    // 0x800CB61C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB620: nop

    // 0x800CB624: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
L_800CB628:
    // 0x800CB628: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x800CB62C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800CB630: lh          $t1, 0x0($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X0);
    // 0x800CB634: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800CB638: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x800CB63C: sh          $t2, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r10;
    // 0x800CB640: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x800CB644: b           L_800CB654
    // 0x800CB648: nop

        goto L_800CB654;
    // 0x800CB648: nop

    // 0x800CB64C: b           L_800CB654
    // 0x800CB650: nop

        goto L_800CB654;
    // 0x800CB650: nop

L_800CB654:
    // 0x800CB654: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB658: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CB65C: jr          $ra
    // 0x800CB660: nop

    return;
    // 0x800CB660: nop

;}
RECOMP_FUNC void static_3_800CB9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB9F8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800CB9FC: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800CBA00: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CBA04: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800CBA08: sll         $t6, $a2, 16
    ctx->r14 = S32(ctx->r6 << 16);
    // 0x800CBA0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800CBA10: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800CBA14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CBA18: bgez        $a3, L_800CBA30
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800CBA1C: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800CBA30;
    }
    // 0x800CBA1C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CBA20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CBA24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800CBA28: nop

    // 0x800CBA2C: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800CBA30:
    // 0x800CBA30: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CBA34: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x800CBA38: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CBA3C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CBA40: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800CBA44: nop

    // 0x800CBA48: div.d       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800CBA4C: cvt.s.d     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f6.fl = CVT_S_D(ctx->f16.d);
    // 0x800CBA50: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CBA54: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800CBA58: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CBA5C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CBA60: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CBA64: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CBA68: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800CBA6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CBA70: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x800CBA74: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800CBA78: nop

    // 0x800CBA7C: div.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f6.d);
    // 0x800CBA80: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x800CBA84: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x800CBA88: b           L_800CBA98
    // 0x800CBA8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_800CBA98;
    // 0x800CBA8C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x800CBA90: b           L_800CBA98
    // 0x800CBA94: nop

        goto L_800CBA98;
    // 0x800CBA94: nop

L_800CBA98:
    // 0x800CBA98: jr          $ra
    // 0x800CBA9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CBA9C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void static_3_800CC020(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC020: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CC024: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CC028: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800CC02C: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800CC030: sll         $t8, $s5, 16
    ctx->r24 = S32(ctx->r21 << 16);
    // 0x800CC034: sra         $s5, $t8, 16
    ctx->r21 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800CC038: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CC03C: blez        $s1, L_800CC0A8
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800CC040: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800CC0A8;
    }
    // 0x800CC040: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC044: lw          $t9, 0x30($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X30);
    // 0x800CC048: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x800CC04C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CC050: jalr        $t9
    // 0x800CC054: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC054: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_0:
    // 0x800CC058: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CC05C: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x800CC060: andi        $t6, $s3, 0xFFFF
    ctx->r14 = ctx->r19 & 0XFFFF;
    // 0x800CC064: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC068: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC06C: andi        $t8, $s1, 0x7
    ctx->r24 = ctx->r17 & 0X7;
    // 0x800CC070: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC074: subu        $t9, $s1, $t8
    ctx->r25 = SUB32(ctx->r17, ctx->r24);
    // 0x800CC078: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800CC07C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CC080: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC084: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CC088: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CC08C: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC090: subu        $t9, $v0, $a2
    ctx->r25 = SUB32(ctx->r2, ctx->r6);
    // 0x800CC094: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CC098: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800CC09C: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800CC0A0: b           L_800CC0AC
    // 0x800CC0A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800CC0AC;
    // 0x800CC0A4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CC0A8:
    // 0x800CC0A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CC0AC:
    // 0x800CC0AC: andi        $t6, $s4, 0x2
    ctx->r14 = ctx->r20 & 0X2;
    // 0x800CC0B0: beq         $t6, $zero, L_800CC0D8
    if (ctx->r14 == 0) {
        // 0x800CC0B4: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800CC0D8;
    }
    // 0x800CC0B4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CC0B8: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x800CC0BC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC0C0: lw          $t8, 0x18($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X18);
    // 0x800CC0C4: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC0C8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC0CC: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800CC0D0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800CC0D4: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800CC0D8:
    // 0x800CC0D8: addu        $t6, $s3, $a2
    ctx->r14 = ADD32(ctx->r19, ctx->r6);
    // 0x800CC0DC: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CC0E0: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC0E4: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800CC0E8: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800CC0EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800CC0F0: sll         $t7, $s6, 1
    ctx->r15 = S32(ctx->r22 << 1);
    // 0x800CC0F4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CC0F8: sll         $t6, $s5, 16
    ctx->r14 = S32(ctx->r21 << 16);
    // 0x800CC0FC: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800CC100: andi        $t7, $s4, 0xFF
    ctx->r15 = ctx->r20 & 0XFF;
    // 0x800CC104: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC108: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800CC10C: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800CC110: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800CC114: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800CC118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800CC11C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CC120: lw          $t9, 0x14($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X14);
    // 0x800CC124: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800CC128: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC12C: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800CC130: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x800CC134: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x800CC138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CC13C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800CC140: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CC144: jr          $ra
    // 0x800CC148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800CC148: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void static_3_800D1C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D1C88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D1C8C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D1C90: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800D1C94: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x800D1C98: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D1C9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D1CA0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D1CA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800D1CA8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800D1CAC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D1CB0: jal         0x800D653C
    // 0x800D1CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800D1CB4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x800D1CB8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1CBC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800D1CC0: beq         $t8, $zero, L_800D1CD0
    if (ctx->r24 == 0) {
        // 0x800D1CC4: nop
    
            goto L_800D1CD0;
    }
    // 0x800D1CC4: nop

    // 0x800D1CC8: b           L_800D1D38
    // 0x800D1CCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D1D38;
    // 0x800D1CCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D1CD0:
    // 0x800D1CD0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_800D1CD4:
    // 0x800D1CD4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800D1CD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800D1CDC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800D1CE0: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D1CE4: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D1CE8: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D1CEC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D1CF0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800D1CF4: jal         0x800CDE50
    // 0x800D1CF8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x800D1CF8: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D1CFC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1D00: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800D1D04: bne         $t3, $zero, L_800D1D20
    if (ctx->r11 != 0) {
        // 0x800D1D08: nop
    
            goto L_800D1D20;
    }
    // 0x800D1D08: nop

    // 0x800D1D0C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800D1D10: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800D1D14: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x800D1D18: bne         $at, $zero, L_800D1CD4
    if (ctx->r1 != 0) {
        // 0x800D1D1C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_800D1CD4;
    }
    // 0x800D1D1C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_800D1D20:
    // 0x800D1D20: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800D1D24: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x800D1D28: jal         0x800D653C
    // 0x800D1D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D1D2C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x800D1D30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800D1D34: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_800D1D38:
    // 0x800D1D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D1D3C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D1D40: jr          $ra
    // 0x800D1D44: nop

    return;
    // 0x800D1D44: nop

    // 0x800D1D48: nop

    // 0x800D1D4C: nop

;}
RECOMP_FUNC void static_3_800D3E00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D3E04: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800D3E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3E0C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800D3E10: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x800D3E14: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800D3E18: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800D3E1C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800D3E20: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800D3E24: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800D3E28: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x800D3E2C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800D3E30: bne         $at, $zero, L_800D3E5C
    if (ctx->r1 != 0) {
        // 0x800D3E34: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800D3E5C;
    }
    // 0x800D3E34: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800D3E38: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x800D3E3C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800D3E40: beq         $at, $zero, L_800D4448
    if (ctx->r1 == 0) {
        // 0x800D3E44: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800D4448;
    }
    // 0x800D3E44: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800D3E48: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D3E4C: addu        $at, $at, $t7
    gpr jr_addend_800D3E54 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800D3E50: lw          $t7, -0x639C($at)
    ctx->r15 = ADD32(ctx->r1, -0X639C);
    // 0x800D3E54: jr          $t7
    // 0x800D3E58: nop

    switch (jr_addend_800D3E54 >> 2) {
        case 0: goto L_800D4168; break;
        case 1: goto L_800D4448; break;
        case 2: goto L_800D4168; break;
        case 3: goto L_800D4448; break;
        case 4: goto L_800D4448; break;
        case 5: goto L_800D4448; break;
        case 6: goto L_800D4448; break;
        case 7: goto L_800D4448; break;
        case 8: goto L_800D4448; break;
        case 9: goto L_800D4448; break;
        case 10: goto L_800D4448; break;
        case 11: goto L_800D4448; break;
        case 12: goto L_800D4448; break;
        case 13: goto L_800D4448; break;
        case 14: goto L_800D4448; break;
        case 15: goto L_800D4448; break;
        case 16: goto L_800D4448; break;
        case 17: goto L_800D4448; break;
        case 18: goto L_800D4448; break;
        case 19: goto L_800D4018; break;
        case 20: goto L_800D4448; break;
        case 21: goto L_800D4448; break;
        case 22: goto L_800D4448; break;
        case 23: goto L_800D4448; break;
        case 24: goto L_800D4448; break;
        case 25: goto L_800D4448; break;
        case 26: goto L_800D4448; break;
        case 27: goto L_800D4448; break;
        case 28: goto L_800D4448; break;
        case 29: goto L_800D4448; break;
        case 30: goto L_800D3E70; break;
        case 31: goto L_800D3EA8; break;
        case 32: goto L_800D4168; break;
        case 33: goto L_800D4168; break;
        case 34: goto L_800D4168; break;
        case 35: goto L_800D4448; break;
        case 36: goto L_800D3EA8; break;
        case 37: goto L_800D4448; break;
        case 38: goto L_800D4448; break;
        case 39: goto L_800D4448; break;
        case 40: goto L_800D4448; break;
        case 41: goto L_800D42CC; break;
        case 42: goto L_800D4018; break;
        case 43: goto L_800D439C; break;
        case 44: goto L_800D4448; break;
        case 45: goto L_800D4448; break;
        case 46: goto L_800D43E4; break;
        case 47: goto L_800D4448; break;
        case 48: goto L_800D4018; break;
        case 49: goto L_800D4448; break;
        case 50: goto L_800D4448; break;
        case 51: goto L_800D4018; break;
        default: switch_error(__func__, 0x800D3E54, 0x800E9C64);
    }
    // 0x800D3E58: nop

L_800D3E5C:
    // 0x800D3E5C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800D3E60: beql        $v1, $at, L_800D442C
    if (ctx->r3 == ctx->r1) {
        // 0x800D3E64: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D442C;
    }
    goto skip_0;
    // 0x800D3E64: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800D3E68: b           L_800D444C
    // 0x800D3E6C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_800D444C;
    // 0x800D3E6C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D3E70:
    // 0x800D3E70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D3E74: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3E78: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D3E7C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800D3E80: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800D3E84: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D3E88: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3E8C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D3E90: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800D3E94: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3E98: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3E9C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D3EA0: b           L_800D4460
    // 0x800D3EA4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D4460;
    // 0x800D3EA4: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D3EA8:
    // 0x800D3EA8: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3EAC: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D3EB0: bnel        $v0, $at, L_800D3EE8
    if (ctx->r2 != ctx->r1) {
        // 0x800D3EB4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D3EE8;
    }
    goto skip_1;
    // 0x800D3EB4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800D3EB8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D3EBC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3EC0: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800D3EC4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3EC8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D3ECC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D3ED0: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x800D3ED4: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D3ED8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3EDC: b           L_800D3F44
    // 0x800D3EE0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_800D3F44;
    // 0x800D3EE0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800D3EE4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D3EE8:
    // 0x800D3EE8: bnel        $v0, $at, L_800D3F20
    if (ctx->r2 != ctx->r1) {
        // 0x800D3EEC: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D3F20;
    }
    goto skip_2;
    // 0x800D3EEC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x800D3EF0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D3EF4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D3EF8: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800D3EFC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D3F00: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800D3F04: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3F08: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800D3F0C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x800D3F10: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F14: b           L_800D3F44
    // 0x800D3F18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D3F44;
    // 0x800D3F18: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D3F1C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D3F20:
    // 0x800D3F20: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D3F24: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x800D3F28: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x800D3F2C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D3F30: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D3F34: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D3F38: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3F3C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F40: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_800D3F44:
    // 0x800D3F44: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x800D3F48: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D3F4C: bnel        $t7, $at, L_800D3F70
    if (ctx->r15 != ctx->r1) {
        // 0x800D3F50: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_800D3F70;
    }
    goto skip_3;
    // 0x800D3F50: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x800D3F54: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D3F58: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800D3F5C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800D3F60: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D3F64: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D3F68: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D3F6C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_800D3F70:
    // 0x800D3F70: bgtzl       $t6, L_800D3FAC
    if (SIGNED(ctx->r14) > 0) {
        // 0x800D3F74: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D3FAC;
    }
    goto skip_4;
    // 0x800D3F74: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800D3F78: bltzl       $t6, L_800D3F8C
    if (SIGNED(ctx->r14) < 0) {
        // 0x800D3F7C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D3F8C;
    }
    goto skip_5;
    // 0x800D3F7C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x800D3F80: b           L_800D3FAC
    // 0x800D3F84: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_800D3FAC;
    // 0x800D3F84: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x800D3F88: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D3F8C:
    // 0x800D3F8C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D3F90: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D3F94: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D3F98: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3F9C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D3FA0: b           L_800D3FFC
    // 0x800D3FA4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800D3FFC;
    // 0x800D3FA4: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D3FA8: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D3FAC:
    // 0x800D3FAC: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800D3FB0: beq         $t8, $zero, L_800D3FD8
    if (ctx->r24 == 0) {
        // 0x800D3FB4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800D3FD8;
    }
    // 0x800D3FB4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D3FB8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FBC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800D3FC0: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800D3FC4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D3FC8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FCC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D3FD0: b           L_800D3FFC
    // 0x800D3FD4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800D3FFC;
    // 0x800D3FD4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800D3FD8:
    // 0x800D3FD8: beql        $t6, $zero, L_800D4000
    if (ctx->r14 == 0) {
        // 0x800D3FDC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800D4000;
    }
    goto skip_6;
    // 0x800D3FDC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x800D3FE0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FE4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800D3FE8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D3FEC: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D3FF0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D3FF4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D3FF8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D3FFC:
    // 0x800D3FFC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800D4000:
    // 0x800D4000: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4004: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800D4008: jal         0x800D6C60
    // 0x800D400C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x800D400C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x800D4010: b           L_800D4464
    // 0x800D4014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D4014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4018:
    // 0x800D4018: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D401C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800D4020: bnel        $v0, $at, L_800D4058
    if (ctx->r2 != ctx->r1) {
        // 0x800D4024: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D4058;
    }
    goto skip_7;
    // 0x800D4024: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x800D4028: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800D402C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4030: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x800D4034: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D4038: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x800D403C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4040: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x800D4044: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800D4048: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D404C: b           L_800D40B4
    // 0x800D4050: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800D40B4;
    // 0x800D4050: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800D4054: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D4058:
    // 0x800D4058: bnel        $v0, $at, L_800D4090
    if (ctx->r2 != ctx->r1) {
        // 0x800D405C: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_800D4090;
    }
    goto skip_8;
    // 0x800D405C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x800D4060: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D4064: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D4068: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800D406C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x800D4070: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800D4074: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4078: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D407C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800D4080: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800D4084: b           L_800D40B4
    // 0x800D4088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800D40B4;
    // 0x800D4088: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D408C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_800D4090:
    // 0x800D4090: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4094: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x800D4098: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800D409C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800D40A0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D40A4: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800D40A8: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800D40AC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D40B0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800D40B4:
    // 0x800D40B4: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D40B8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D40BC: bne         $v0, $at, L_800D40DC
    if (ctx->r2 != ctx->r1) {
        // 0x800D40C0: nop
    
            goto L_800D40DC;
    }
    // 0x800D40C0: nop

    // 0x800D40C4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800D40C8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800D40CC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800D40D0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800D40D4: b           L_800D40F4
    // 0x800D40D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800D40F4;
    // 0x800D40D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D40DC:
    // 0x800D40DC: bnel        $v0, $zero, L_800D40F8
    if (ctx->r2 != 0) {
        // 0x800D40E0: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_800D40F8;
    }
    goto skip_9;
    // 0x800D40E0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x800D40E4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800D40E8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D40EC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D40F0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800D40F4:
    // 0x800D40F4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_800D40F8:
    // 0x800D40F8: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800D40FC: beql        $t6, $zero, L_800D4150
    if (ctx->r14 == 0) {
        // 0x800D4100: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D4150;
    }
    goto skip_10;
    // 0x800D4100: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x800D4104: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4108: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800D410C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800D4110: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x800D4114: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x800D4118: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D411C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D4120: beq         $v1, $at, L_800D4134
    if (ctx->r3 == ctx->r1) {
        // 0x800D4124: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_800D4134;
    }
    // 0x800D4124: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D4128: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x800D412C: bnel        $v1, $at, L_800D4150
    if (ctx->r3 != ctx->r1) {
        // 0x800D4130: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D4150;
    }
    goto skip_11;
    // 0x800D4130: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_800D4134:
    // 0x800D4134: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D4138: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D413C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x800D4140: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4144: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800D4148: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x800D414C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D4150:
    // 0x800D4150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4154: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x800D4158: jal         0x800D6C60
    // 0x800D415C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x800D415C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x800D4160: b           L_800D4464
    // 0x800D4164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D4164: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4168:
    // 0x800D4168: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x800D416C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x800D4170: bnel        $t6, $at, L_800D41D8
    if (ctx->r14 != ctx->r1) {
        // 0x800D4174: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_800D41D8;
    }
    goto skip_12;
    // 0x800D4174: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x800D4178: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800D417C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800D4180: beq         $t9, $zero, L_800D4198
    if (ctx->r25 == 0) {
        // 0x800D4184: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D4198;
    }
    // 0x800D4184: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D4188: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x800D418C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D4190: b           L_800D41C8
    // 0x800D4194: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800D41C8;
    // 0x800D4194: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_800D4198:
    // 0x800D4198: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800D419C: beq         $t7, $zero, L_800D41B4
    if (ctx->r15 == 0) {
        // 0x800D41A0: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800D41B4;
    }
    // 0x800D41A0: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x800D41A4: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x800D41A8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D41AC: b           L_800D41C4
    // 0x800D41B0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800D41C4;
    // 0x800D41B0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800D41B4:
    // 0x800D41B4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D41B8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D41BC: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800D41C0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D41C4:
    // 0x800D41C4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D41C8:
    // 0x800D41C8: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800D41CC: b           L_800D422C
    // 0x800D41D0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_800D422C;
    // 0x800D41D0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800D41D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800D41D8:
    // 0x800D41D8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800D41DC: beq         $t6, $zero, L_800D41F4
    if (ctx->r14 == 0) {
        // 0x800D41E0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D41F4;
    }
    // 0x800D41E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800D41E4: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800D41E8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D41EC: b           L_800D4224
    // 0x800D41F0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_800D4224;
    // 0x800D41F0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800D41F4:
    // 0x800D41F4: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800D41F8: beq         $t8, $zero, L_800D4210
    if (ctx->r24 == 0) {
        // 0x800D41FC: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_800D4210;
    }
    // 0x800D41FC: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800D4200: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800D4204: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800D4208: b           L_800D4220
    // 0x800D420C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_800D4220;
    // 0x800D420C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_800D4210:
    // 0x800D4210: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800D4214: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x800D4218: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x800D421C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800D4220:
    // 0x800D4220: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800D4224:
    // 0x800D4224: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x800D4228: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_800D422C:
    // 0x800D422C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x800D4230: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x800D4234: beql        $t6, $zero, L_800D4260
    if (ctx->r14 == 0) {
        // 0x800D4238: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_800D4260;
    }
    goto skip_13;
    // 0x800D4238: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x800D423C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800D4240: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x800D4244: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800D4248: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800D424C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4250: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800D4254: b           L_800D42B0
    // 0x800D4258: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D42B0;
    // 0x800D4258: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x800D425C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_800D4260:
    // 0x800D4260: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x800D4264: beq         $t9, $zero, L_800D428C
    if (ctx->r25 == 0) {
        // 0x800D4268: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_800D428C;
    }
    // 0x800D4268: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800D426C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800D4270: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x800D4274: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x800D4278: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800D427C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4280: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800D4284: b           L_800D42B0
    // 0x800D4288: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_800D42B0;
    // 0x800D4288: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_800D428C:
    // 0x800D428C: beql        $t7, $zero, L_800D42B4
    if (ctx->r15 == 0) {
        // 0x800D4290: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_800D42B4;
    }
    goto skip_14;
    // 0x800D4290: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x800D4294: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800D4298: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800D429C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x800D42A0: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D42A4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D42A8: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D42AC: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_800D42B0:
    // 0x800D42B0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D42B4:
    // 0x800D42B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D42B8: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x800D42BC: jal         0x800D7470
    // 0x800D42C0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x800D42C0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x800D42C4: b           L_800D4464
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D42C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D42CC:
    // 0x800D42CC: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800D42D0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800D42D4: bnel        $v0, $at, L_800D4308
    if (ctx->r2 != ctx->r1) {
        // 0x800D42D8: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_800D4308;
    }
    goto skip_15;
    // 0x800D42D8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x800D42DC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D42E0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D42E4: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D42E8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D42EC: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D42F0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D42F4: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x800D42F8: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D42FC: b           L_800D4460
    // 0x800D4300: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_800D4460;
    // 0x800D4300: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x800D4304: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_800D4308:
    // 0x800D4308: bnel        $v0, $at, L_800D433C
    if (ctx->r2 != ctx->r1) {
        // 0x800D430C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800D433C;
    }
    goto skip_16;
    // 0x800D430C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x800D4310: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D4314: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D4318: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x800D431C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D4320: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x800D4324: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800D4328: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x800D432C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4330: b           L_800D4460
    // 0x800D4334: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_800D4460;
    // 0x800D4334: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D4338: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800D433C:
    // 0x800D433C: bnel        $v0, $at, L_800D4378
    if (ctx->r2 != ctx->r1) {
        // 0x800D4340: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_800D4378;
    }
    goto skip_17;
    // 0x800D4340: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x800D4344: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800D4348: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D434C: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x800D4350: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800D4354: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800D4358: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D435C: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x800D4360: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4364: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800D4368: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x800D436C: b           L_800D4460
    // 0x800D4370: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_800D4460;
    // 0x800D4370: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x800D4374: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_800D4378:
    // 0x800D4378: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D437C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x800D4380: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800D4384: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x800D4388: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D438C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x800D4390: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x800D4394: b           L_800D4460
    // 0x800D4398: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_800D4460;
    // 0x800D4398: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_800D439C:
    // 0x800D439C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800D43A0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D43A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D43A8: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x800D43AC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800D43B0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x800D43B4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800D43B8: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x800D43BC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D43C0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x800D43C4: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x800D43C8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800D43CC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x800D43D0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800D43D4: jal         0x800D6C60
    // 0x800D43D8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x800D43D8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x800D43DC: b           L_800D4464
    // 0x800D43E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800D4464;
    // 0x800D43E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D43E4:
    // 0x800D43E4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800D43E8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D43EC: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800D43F0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x800D43F4: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x800D43F8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800D43FC: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x800D4400: jal         0x800CE6FC
    // 0x800D4404: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x800D4404: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x800D4408: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x800D440C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x800D4410: bltz        $v1, L_800D4460
    if (SIGNED(ctx->r3) < 0) {
        // 0x800D4414: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D4460;
    }
    // 0x800D4414: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D4418: beql        $at, $zero, L_800D4464
    if (ctx->r1 == 0) {
        // 0x800D441C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D4464;
    }
    goto skip_18;
    // 0x800D441C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x800D4420: b           L_800D4460
    // 0x800D4424: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_800D4460;
    // 0x800D4424: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x800D4428: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_800D442C:
    // 0x800D442C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x800D4430: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800D4434: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D4438: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D443C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D4440: b           L_800D4460
    // 0x800D4444: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_800D4460;
    // 0x800D4444: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D4448:
    // 0x800D4448: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800D444C:
    // 0x800D444C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x800D4450: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x800D4454: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D4458: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D445C: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800D4460:
    // 0x800D4460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D4464:
    // 0x800D4464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4468: jr          $ra
    // 0x800D446C: nop

    return;
    // 0x800D446C: nop

;}
RECOMP_FUNC void static_3_800D6F00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6F00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6F04: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800D6F08: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D6F0C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D6F10: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D6F14: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D6F18: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6F1C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x800D6F20: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x800D6F24: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x800D6F28: bgtz        $s3, L_800D6F3C
    if (SIGNED(ctx->r19) > 0) {
        // 0x800D6F2C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800D6F3C;
    }
    // 0x800D6F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6F30: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800D6F34: addiu       $s1, $s1, -0x61D0
    ctx->r17 = ADD32(ctx->r17, -0X61D0);
    // 0x800D6F38: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_800D6F3C:
    // 0x800D6F3C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x800D6F40: beq         $v0, $s4, L_800D6F74
    if (ctx->r2 == ctx->r20) {
        // 0x800D6F44: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_800D6F74;
    }
    // 0x800D6F44: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x800D6F48: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800D6F4C: beq         $a0, $v1, L_800D6F58
    if (ctx->r4 == ctx->r3) {
        // 0x800D6F50: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D6F58;
    }
    // 0x800D6F50: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D6F54: bne         $v1, $at, L_800D71B0
    if (ctx->r3 != ctx->r1) {
        // 0x800D6F58: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800D71B0;
    }
L_800D6F58:
    // 0x800D6F58: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x800D6F5C: bne         $at, $zero, L_800D71B0
    if (ctx->r1 != 0) {
        // 0x800D6F60: nop
    
            goto L_800D71B0;
    }
    // 0x800D6F60: nop

    // 0x800D6F64: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800D6F68: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800D6F6C: beq         $at, $zero, L_800D71B0
    if (ctx->r1 == 0) {
        // 0x800D6F70: nop
    
            goto L_800D71B0;
    }
    // 0x800D6F70: nop

L_800D6F74:
    // 0x800D6F74: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800D6F78: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x800D6F7C: beq         $v0, $v1, L_800D6FB8
    if (ctx->r2 == ctx->r3) {
        // 0x800D6F80: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800D6FB8;
    }
    // 0x800D6F80: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D6F84: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6F88: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6F8C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800D6F90: bne         $t7, $zero, L_800D6FA8
    if (ctx->r15 != 0) {
        // 0x800D6F94: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800D6FA8;
    }
    // 0x800D6F94: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D6F98: beql        $at, $zero, L_800D6FAC
    if (ctx->r1 == 0) {
        // 0x800D6F9C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800D6FAC;
    }
    goto skip_0;
    // 0x800D6F9C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800D6FA0: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D6FA4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800D6FA8:
    // 0x800D6FA8: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800D6FAC:
    // 0x800D6FAC: bgez        $t8, L_800D6FB8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D6FB0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D6FB8;
    }
    // 0x800D6FB0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D6FB4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D6FB8:
    // 0x800D6FB8: bgtz        $s2, L_800D7088
    if (SIGNED(ctx->r18) > 0) {
        // 0x800D6FBC: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800D7088;
    }
    // 0x800D6FBC: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800D6FC0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D6FC4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D6FC8: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D6FCC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D6FD0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800D6FD4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D6FD8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D6FDC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D6FE0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D6FE4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800D6FE8: bgtz        $v0, L_800D7000
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D6FEC: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_800D7000;
    }
    // 0x800D6FEC: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x800D6FF0: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800D6FF4: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x800D6FF8: beql        $t9, $zero, L_800D7028
    if (ctx->r25 == 0) {
        // 0x800D6FFC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800D7028;
    }
    goto skip_1;
    // 0x800D6FFC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_800D7000:
    // 0x800D7000: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D7004: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D7008: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x800D700C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800D7010: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800D7014: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7018: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D701C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800D7020: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D7024: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_800D7028:
    // 0x800D7028: beql        $at, $zero, L_800D7044
    if (ctx->r1 == 0) {
        // 0x800D702C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_800D7044;
    }
    goto skip_2;
    // 0x800D702C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x800D7030: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x800D7034: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x800D7038: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D703C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800D7040: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_800D7044:
    // 0x800D7044: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D7048: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x800D704C: beq         $at, $zero, L_800D7060
    if (ctx->r1 == 0) {
        // 0x800D7050: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800D7060;
    }
    // 0x800D7050: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800D7054: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x800D7058: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D705C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D7060:
    // 0x800D7060: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D7064: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7068: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800D706C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D7070: jal         0x800CE6D0
    // 0x800D7074: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800D7074: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x800D7078: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x800D707C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800D7080: b           L_800D740C
    // 0x800D7084: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800D740C;
    // 0x800D7084: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800D7088:
    // 0x800D7088: beq         $at, $zero, L_800D7100
    if (ctx->r1 == 0) {
        // 0x800D708C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D7100;
    }
    // 0x800D708C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D7090: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D7094: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7098: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D709C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D70A0: jal         0x800CE6D0
    // 0x800D70A4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800D70A4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800D70A8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D70AC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D70B0: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800D70B4: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800D70B8: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D70BC: bgtz        $v0, L_800D70D4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D70C0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800D70D4;
    }
    // 0x800D70C0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800D70C4: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D70C8: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800D70CC: beq         $t8, $zero, L_800D70F8
    if (ctx->r24 == 0) {
        // 0x800D70D0: nop
    
            goto L_800D70F8;
    }
    // 0x800D70D0: nop

L_800D70D4:
    // 0x800D70D4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D70D8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D70DC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D70E0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D70E4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x800D70E8: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x800D70EC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D70F0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D70F4: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D70F8:
    // 0x800D70F8: b           L_800D740C
    // 0x800D70FC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800D740C;
    // 0x800D70FC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_800D7100:
    // 0x800D7100: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x800D7104: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7108: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800D710C: jal         0x800CE6D0
    // 0x800D7110: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x800D7110: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x800D7114: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7118: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D711C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800D7120: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800D7124: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800D7128: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x800D712C: bgtz        $v0, L_800D7144
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D7130: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_800D7144;
    }
    // 0x800D7130: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D7134: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x800D7138: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x800D713C: beql        $t9, $zero, L_800D716C
    if (ctx->r25 == 0) {
        // 0x800D7140: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_800D716C;
    }
    goto skip_3;
    // 0x800D7140: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_800D7144:
    // 0x800D7144: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D7148: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D714C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x800D7150: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x800D7154: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800D7158: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D715C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D7160: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D7164: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D7168: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_800D716C:
    // 0x800D716C: beq         $at, $zero, L_800D7180
    if (ctx->r1 == 0) {
        // 0x800D7170: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800D7180;
    }
    // 0x800D7170: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x800D7174: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D7178: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D717C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800D7180:
    // 0x800D7180: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D7184: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7188: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D718C: jal         0x800CE6D0
    // 0x800D7190: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800D7190: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800D7194: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7198: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D719C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800D71A0: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D71A4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800D71A8: b           L_800D740C
    // 0x800D71AC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800D740C;
    // 0x800D71AC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800D71B0:
    // 0x800D71B0: beq         $a0, $v1, L_800D71C0
    if (ctx->r4 == ctx->r3) {
        // 0x800D71B4: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800D71C0;
    }
    // 0x800D71B4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800D71B8: bnel        $v1, $at, L_800D7200
    if (ctx->r3 != ctx->r1) {
        // 0x800D71BC: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800D7200;
    }
    goto skip_4;
    // 0x800D71BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800D71C0:
    // 0x800D71C0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D71C4: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800D71C8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800D71CC: beql        $at, $zero, L_800D71E0
    if (ctx->r1 == 0) {
        // 0x800D71D0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800D71E0;
    }
    goto skip_5;
    // 0x800D71D0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800D71D4: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800D71D8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800D71DC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800D71E0:
    // 0x800D71E0: bgez        $t7, L_800D71EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800D71E4: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800D71EC;
    }
    // 0x800D71E4: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800D71E8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800D71EC:
    // 0x800D71EC: bne         $a0, $v1, L_800D71FC
    if (ctx->r4 != ctx->r3) {
        // 0x800D71F0: nop
    
            goto L_800D71FC;
    }
    // 0x800D71F0: nop

    // 0x800D71F4: b           L_800D71FC
    // 0x800D71F8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800D71FC;
    // 0x800D71F8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800D71FC:
    // 0x800D71FC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800D7200:
    // 0x800D7200: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7204: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800D7208: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D720C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x800D7210: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x800D7214: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7218: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D721C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800D7220: bgtz        $v0, L_800D7238
    if (SIGNED(ctx->r2) > 0) {
        // 0x800D7224: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_800D7238;
    }
    // 0x800D7224: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D7228: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800D722C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x800D7230: beq         $t6, $zero, L_800D725C
    if (ctx->r14 == 0) {
        // 0x800D7234: nop
    
            goto L_800D725C;
    }
    // 0x800D7234: nop

L_800D7238:
    // 0x800D7238: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800D723C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7240: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x800D7244: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7248: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x800D724C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D7250: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800D7254: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x800D7258: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_800D725C:
    // 0x800D725C: blezl       $v0, L_800D72B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800D7260: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800D72B8;
    }
    goto skip_6;
    // 0x800D7260: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x800D7264: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800D7268: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x800D726C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800D7270: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800D7274: beq         $at, $zero, L_800D7288
    if (ctx->r1 == 0) {
        // 0x800D7278: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D7288;
    }
    // 0x800D7278: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D727C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800D7280: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800D7284: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800D7288:
    // 0x800D7288: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800D728C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800D7290: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800D7294: jal         0x800CE6D0
    // 0x800D7298: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800D7298: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800D729C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800D72A0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800D72A4: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800D72A8: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800D72AC: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800D72B0: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800D72B4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800D72B8:
    // 0x800D72B8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D72BC: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800D72C0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D72C4: bltz        $s2, L_800D72DC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800D72C8: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800D72DC;
    }
    // 0x800D72C8: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800D72CC: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800D72D0: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800D72D4: b           L_800D72F8
    // 0x800D72D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800D72F8;
    // 0x800D72D8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D72DC:
    // 0x800D72DC: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800D72E0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D72E4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800D72E8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D72EC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D72F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D72F4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800D72F8:
    // 0x800D72F8: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800D72FC: bnel        $at, $zero, L_800D73A8
    if (ctx->r1 != 0) {
        // 0x800D7300: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_800D73A8;
    }
    goto skip_7;
    // 0x800D7300: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800D7304: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800D7308: bne         $at, $zero, L_800D7358
    if (ctx->r1 != 0) {
        // 0x800D730C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_800D7358;
    }
    // 0x800D730C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x800D7310: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D7314: bne         $v0, $zero, L_800D7320
    if (ctx->r2 != 0) {
        // 0x800D7318: nop
    
            goto L_800D7320;
    }
    // 0x800D7318: nop

    // 0x800D731C: break       7
    do_break(2148365084);
L_800D7320:
    // 0x800D7320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7324: bne         $v0, $at, L_800D7338
    if (ctx->r2 != ctx->r1) {
        // 0x800D7328: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7338;
    }
    // 0x800D7328: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D732C: bne         $s2, $at, L_800D7338
    if (ctx->r18 != ctx->r1) {
        // 0x800D7330: nop
    
            goto L_800D7338;
    }
    // 0x800D7330: nop

    // 0x800D7334: break       6
    do_break(2148365108);
L_800D7338:
    // 0x800D7338: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D733C: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D7340: mflo        $t9
    ctx->r25 = lo;
    // 0x800D7344: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D7348: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D734C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D7350: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D7354: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D7358:
    // 0x800D7358: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800D735C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D7360: bne         $v0, $zero, L_800D736C
    if (ctx->r2 != 0) {
        // 0x800D7364: nop
    
            goto L_800D736C;
    }
    // 0x800D7364: nop

    // 0x800D7368: break       7
    do_break(2148365160);
L_800D736C:
    // 0x800D736C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D7370: bne         $v0, $at, L_800D7384
    if (ctx->r2 != ctx->r1) {
        // 0x800D7374: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D7384;
    }
    // 0x800D7374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D7378: bne         $s2, $at, L_800D7384
    if (ctx->r18 != ctx->r1) {
        // 0x800D737C: nop
    
            goto L_800D7384;
    }
    // 0x800D737C: nop

    // 0x800D7380: break       6
    do_break(2148365184);
L_800D7384:
    // 0x800D7384: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D7388: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D738C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D7390: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D7394: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D7398: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D739C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D73A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D73A4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_800D73A8:
    // 0x800D73A8: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x800D73AC: bne         $v0, $zero, L_800D73B8
    if (ctx->r2 != 0) {
        // 0x800D73B0: nop
    
            goto L_800D73B8;
    }
    // 0x800D73B0: nop

    // 0x800D73B4: break       7
    do_break(2148365236);
L_800D73B8:
    // 0x800D73B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D73BC: bne         $v0, $at, L_800D73D0
    if (ctx->r2 != ctx->r1) {
        // 0x800D73C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D73D0;
    }
    // 0x800D73C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D73C4: bne         $s2, $at, L_800D73D0
    if (ctx->r18 != ctx->r1) {
        // 0x800D73C8: nop
    
            goto L_800D73D0;
    }
    // 0x800D73C8: nop

    // 0x800D73CC: break       6
    do_break(2148365260);
L_800D73D0:
    // 0x800D73D0: mfhi        $s2
    ctx->r18 = hi;
    // 0x800D73D4: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800D73D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800D73DC: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800D73E0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800D73E4: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800D73E8: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800D73EC: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800D73F0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800D73F4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800D73F8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800D73FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800D7400: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800D7404: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800D7408: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800D740C:
    // 0x800D740C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x800D7410: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800D7414: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x800D7418: bnel        $t6, $at, L_800D745C
    if (ctx->r14 != ctx->r1) {
        // 0x800D741C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D745C;
    }
    goto skip_8;
    // 0x800D741C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x800D7420: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800D7424: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800D7428: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x800D742C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x800D7430: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7434: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x800D7438: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800D743C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x800D7440: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800D7444: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x800D7448: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800D744C: beq         $at, $zero, L_800D7458
    if (ctx->r1 == 0) {
        // 0x800D7450: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_800D7458;
    }
    // 0x800D7450: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x800D7454: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_800D7458:
    // 0x800D7458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D745C:
    // 0x800D745C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7460: jr          $ra
    // 0x800D7464: nop

    return;
    // 0x800D7464: nop

    // 0x800D7468: jr          $ra
    // 0x800D746C: nop

    return;
    // 0x800D746C: nop

;}
RECOMP_FUNC void static_3_800CB834(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB834: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB838: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800CB83C: nop

    // 0x800CB840: bne         $t6, $zero, L_800CB888
    if (ctx->r14 != 0) {
        // 0x800CB844: nop
    
            goto L_800CB888;
    }
    // 0x800CB844: nop

    // 0x800CB848: c.le.d      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.d <= ctx->f14.d;
    // 0x800CB84C: nop

    // 0x800CB850: bc1f        L_800CB874
    if (!c1cs) {
        // 0x800CB854: nop
    
            goto L_800CB874;
    }
    // 0x800CB854: nop

    // 0x800CB858: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB85C: ori         $t7, $zero, 0xFFFF
    ctx->r15 = 0 | 0XFFFF;
    // 0x800CB860: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB864: b           L_800CB9F0
    // 0x800CB868: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
        goto L_800CB9F0;
    // 0x800CB868: addiu       $v0, $zero, 0x7FFF
    ctx->r2 = ADD32(0, 0X7FFF);
    // 0x800CB86C: b           L_800CB888
    // 0x800CB870: nop

        goto L_800CB888;
    // 0x800CB870: nop

L_800CB874:
    // 0x800CB874: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x800CB878: nop

    // 0x800CB87C: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x800CB880: b           L_800CB9F0
    // 0x800CB884: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
        goto L_800CB9F0;
    // 0x800CB884: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
L_800CB888:
    // 0x800CB888: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CB88C: sub.d       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = ctx->f14.d - ctx->f12.d;
    // 0x800CB890: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800CB894: nop

    // 0x800CB898: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CB89C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800CB8A0: nop

    // 0x800CB8A4: div.d       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f4.d, ctx->f10.d);
    // 0x800CB8A8: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800CB8AC: swc1        $f17, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(17 - 1) * 2];
    // 0x800CB8B0: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x800CB8B4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB8B8: lwc1        $f19, 0x0($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB8BC: lwc1        $f18, 0x4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB8C0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB8C4: nop

    // 0x800CB8C8: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x800CB8CC: swc1        $f8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f8.u32l;
    // 0x800CB8D0: swc1        $f9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
    // 0x800CB8D4: lwc1        $f5, 0x0($sp)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB8D8: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB8DC: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800CB8E0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CB8E4: nop

    // 0x800CB8E8: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x800CB8EC: nop

    // 0x800CB8F0: bc1f        L_800CB91C
    if (!c1cs) {
        // 0x800CB8F4: nop
    
            goto L_800CB91C;
    }
    // 0x800CB8F4: nop

    // 0x800CB8F8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB8FC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800CB900: lwc1        $f17, 0x0($sp)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB904: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB908: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800CB90C: nop

    // 0x800CB910: sub.d       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f16.d - ctx->f18.d;
    // 0x800CB914: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800CB918: swc1        $f7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB91C:
    // 0x800CB91C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CB920: lwc1        $f9, 0x0($sp)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB924: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800CB928: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB92C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB930: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB934: nop

    // 0x800CB938: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x800CB93C: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800CB940: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CB944: sh          $t2, 0xE($sp)
    MEM_H(0XE, ctx->r29) = ctx->r10;
    // 0x800CB948: nop

    // 0x800CB94C: lh          $t3, 0xE($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XE);
    // 0x800CB950: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB954: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x800CB958: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB95C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CB960: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CB964: lwc1        $f5, -0x6488($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X6488);
    // 0x800CB968: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800CB96C: lwc1        $f4, -0x6484($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6484);
    // 0x800CB970: sub.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d - ctx->f6.d;
    // 0x800CB974: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800CB978: mul.d       $f16, $f8, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800CB97C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CB980: nop

    // 0x800CB984: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800CB988: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB98C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB990: nop

    // 0x800CB994: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800CB998: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800CB99C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CB9A0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800CB9A4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CB9A8: sh          $t7, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r15;
    // 0x800CB9AC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CB9B0: lwc1        $f11, 0x0($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X0);
    // 0x800CB9B4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800CB9B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CB9BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CB9C0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800CB9C4: nop

    // 0x800CB9C8: cvt.w.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_D(ctx->f10.d);
    // 0x800CB9CC: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800CB9D0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CB9D4: sll         $t0, $v0, 16
    ctx->r8 = S32(ctx->r2 << 16);
    // 0x800CB9D8: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800CB9DC: sra         $t1, $v0, 16
    ctx->r9 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800CB9E0: b           L_800CB9F0
    // 0x800CB9E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CB9F0;
    // 0x800CB9E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CB9E8: b           L_800CB9F0
    // 0x800CB9EC: nop

        goto L_800CB9F0;
    // 0x800CB9EC: nop

L_800CB9F0:
    // 0x800CB9F0: jr          $ra
    // 0x800CB9F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB9F4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
