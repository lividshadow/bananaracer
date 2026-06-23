#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void obj_loop_unknown94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800421A0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800421A4: jr          $ra
    // 0x800421A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800421A8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void level_properties_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C530: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006C534: lh          $v0, -0x2768($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2768);
    // 0x8006C538: jr          $ra
    // 0x8006C53C: nop

    return;
    // 0x8006C53C: nop

;}
RECOMP_FUNC void fb_init_vi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A9A0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007A9A4: lw          $v0, 0x300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X300);
    // 0x8007A9A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A9AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007A9B0: bne         $v0, $zero, L_8007A9C4
    if (ctx->r2 != 0) {
        // 0x8007A9B4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007A9C4;
    }
    // 0x8007A9B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007A9B8: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x8007A9BC: b           L_8007A9D4
    // 0x8007A9C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
        goto L_8007A9D4;
    // 0x8007A9C0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8007A9C4:
    // 0x8007A9C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007A9C8: bne         $a1, $v0, L_8007A9D4
    if (ctx->r5 != ctx->r2) {
        // 0x8007A9CC: nop
    
            goto L_8007A9D4;
    }
    // 0x8007A9CC: nop

    // 0x8007A9D0: addiu       $v1, $zero, 0x1C
    ctx->r3 = ADD32(0, 0X1C);
L_8007A9D4:
    // 0x8007A9D4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007A9D8: lw          $t6, 0x686C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X686C);
    // 0x8007A9DC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8007A9E0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x8007A9E4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007A9E8: addu        $at, $at, $t7
    gpr jr_addend_8007A9F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8007A9EC: lw          $t7, -0x7F64($at)
    ctx->r15 = ADD32(ctx->r1, -0X7F64);
    // 0x8007A9F0: nop

    // 0x8007A9F4: jr          $t7
    // 0x8007A9F8: nop

    switch (jr_addend_8007A9F4 >> 2) {
        case 0: goto L_8007A9FC; break;
        case 1: goto L_8007AA20; break;
        case 2: goto L_8007AAA8; break;
        case 3: goto L_8007AB10; break;
        case 4: goto L_8007AB78; break;
        case 5: goto L_8007ABA0; break;
        case 6: goto L_8007ABC8; break;
        case 7: goto L_8007ABF0; break;
        default: switch_error(__func__, 0x8007A9F4, 0x800E809C);
    }
    // 0x8007A9F8: nop

L_8007A9FC:
    // 0x8007A9FC: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8007AA00: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x8007AA04: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007AA08: addiu       $t9, $t9, 0x3E90
    ctx->r25 = ADD32(ctx->r25, 0X3E90);
    // 0x8007AA0C: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x8007AA10: jal         0x800D2200
    // 0x8007AA14: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_0;
    // 0x8007AA14: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x8007AA18: b           L_8007AC10
    // 0x8007AA1C: nop

        goto L_8007AC10;
    // 0x8007AA1C: nop

L_8007AA20:
    // 0x8007AA20: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA24: bne         $v0, $zero, L_8007AA38
    if (ctx->r2 != 0) {
        // 0x8007AA28: addiu       $a0, $a0, 0x4BB0
        ctx->r4 = ADD32(ctx->r4, 0X4BB0);
            goto L_8007AA38;
    }
    // 0x8007AA28: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8007AA2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA30: b           L_8007AA48
    // 0x8007AA34: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
        goto L_8007AA48;
    // 0x8007AA34: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
L_8007AA38:
    // 0x8007AA38: bne         $a1, $v0, L_8007AA48
    if (ctx->r5 != ctx->r2) {
        // 0x8007AA3C: nop
    
            goto L_8007AA48;
    }
    // 0x8007AA3C: nop

    // 0x8007AA40: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AA44: addiu       $a0, $a0, 0x4C50
    ctx->r4 = ADD32(ctx->r4, 0X4C50);
L_8007AA48:
    // 0x8007AA48: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AA4C: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AA50: jal         0x8007B04C
    // 0x8007AA54: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_1;
    // 0x8007AA54: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_1:
    // 0x8007AA58: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x8007AA5C: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8007AA60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AA64: bne         $t0, $zero, L_8007AA98
    if (ctx->r8 != 0) {
        // 0x8007AA68: addiu       $a1, $a1, 0x6800
        ctx->r5 = ADD32(ctx->r5, 0X6800);
            goto L_8007AA98;
    }
    // 0x8007AA68: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AA6C: lw          $t1, 0x30($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X30);
    // 0x8007AA70: lw          $t3, 0x44($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X44);
    // 0x8007AA74: lui         $v0, 0x18
    ctx->r2 = S32(0X18 << 16);
    // 0x8007AA78: subu        $t2, $t1, $v0
    ctx->r10 = SUB32(ctx->r9, ctx->r2);
    // 0x8007AA7C: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8007AA80: sw          $t2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r10;
    // 0x8007AA84: sw          $t4, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r12;
    // 0x8007AA88: addiu       $t6, $t2, 0x18
    ctx->r14 = ADD32(ctx->r10, 0X18);
    // 0x8007AA8C: addiu       $t8, $t4, 0x18
    ctx->r24 = ADD32(ctx->r12, 0X18);
    // 0x8007AA90: sw          $t6, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r14;
    // 0x8007AA94: sw          $t8, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r24;
L_8007AA98:
    // 0x8007AA98: jal         0x800D2200
    // 0x8007AA9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    osViSetMode_recomp(rdram, ctx);
        goto after_2;
    // 0x8007AA9C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x8007AAA0: b           L_8007AC10
    // 0x8007AAA4: nop

        goto L_8007AC10;
    // 0x8007AAA4: nop

L_8007AAA8:
    // 0x8007AAA8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AAAC: bne         $v0, $zero, L_8007AAC0
    if (ctx->r2 != 0) {
        // 0x8007AAB0: addiu       $a0, $a0, 0x4BB0
        ctx->r4 = ADD32(ctx->r4, 0X4BB0);
            goto L_8007AAC0;
    }
    // 0x8007AAB0: addiu       $a0, $a0, 0x4BB0
    ctx->r4 = ADD32(ctx->r4, 0X4BB0);
    // 0x8007AAB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AAB8: b           L_8007AAD0
    // 0x8007AABC: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
        goto L_8007AAD0;
    // 0x8007AABC: addiu       $a0, $a0, 0x4C00
    ctx->r4 = ADD32(ctx->r4, 0X4C00);
L_8007AAC0:
    // 0x8007AAC0: bne         $a1, $v0, L_8007AAD0
    if (ctx->r5 != ctx->r2) {
        // 0x8007AAC4: nop
    
            goto L_8007AAD0;
    }
    // 0x8007AAC4: nop

    // 0x8007AAC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AACC: addiu       $a0, $a0, 0x4C50
    ctx->r4 = ADD32(ctx->r4, 0X4C50);
L_8007AAD0:
    // 0x8007AAD0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AAD4: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AAD8: jal         0x8007B04C
    // 0x8007AADC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_3;
    // 0x8007AADC: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_3:
    // 0x8007AAE0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AAE4: addiu       $a0, $a1, 0x6800
    ctx->r4 = ADD32(ctx->r5, 0X6800);
    // 0x8007AAE8: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007AAEC: addiu       $t9, $zero, 0x280
    ctx->r25 = ADD32(0, 0X280);
    // 0x8007AAF0: addiu       $t0, $zero, 0x400
    ctx->r8 = ADD32(0, 0X400);
    // 0x8007AAF4: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8007AAF8: sw          $t0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r8;
    // 0x8007AAFC: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007AB00: jal         0x800D2200
    // 0x8007AB04: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AB04: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_4:
    // 0x8007AB08: b           L_8007AC10
    // 0x8007AB0C: nop

        goto L_8007AC10;
    // 0x8007AB0C: nop

L_8007AB10:
    // 0x8007AB10: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB14: bne         $v0, $zero, L_8007AB28
    if (ctx->r2 != 0) {
        // 0x8007AB18: addiu       $a0, $a0, 0x4CA0
        ctx->r4 = ADD32(ctx->r4, 0X4CA0);
            goto L_8007AB28;
    }
    // 0x8007AB18: addiu       $a0, $a0, 0x4CA0
    ctx->r4 = ADD32(ctx->r4, 0X4CA0);
    // 0x8007AB1C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB20: b           L_8007AB38
    // 0x8007AB24: addiu       $a0, $a0, 0x4CF0
    ctx->r4 = ADD32(ctx->r4, 0X4CF0);
        goto L_8007AB38;
    // 0x8007AB24: addiu       $a0, $a0, 0x4CF0
    ctx->r4 = ADD32(ctx->r4, 0X4CF0);
L_8007AB28:
    // 0x8007AB28: bne         $a1, $v0, L_8007AB38
    if (ctx->r5 != ctx->r2) {
        // 0x8007AB2C: nop
    
            goto L_8007AB38;
    }
    // 0x8007AB2C: nop

    // 0x8007AB30: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007AB34: addiu       $a0, $a0, 0x4D40
    ctx->r4 = ADD32(ctx->r4, 0X4D40);
L_8007AB38:
    // 0x8007AB38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AB3C: addiu       $a1, $a1, 0x6800
    ctx->r5 = ADD32(ctx->r5, 0X6800);
    // 0x8007AB40: jal         0x8007B04C
    // 0x8007AB44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    fb_memcpy(rdram, ctx);
        goto after_5;
    // 0x8007AB44: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    after_5:
    // 0x8007AB48: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007AB4C: addiu       $a0, $a1, 0x6800
    ctx->r4 = ADD32(ctx->r5, 0X6800);
    // 0x8007AB50: addiu       $v0, $zero, 0x500
    ctx->r2 = ADD32(0, 0X500);
    // 0x8007AB54: addiu       $t1, $zero, 0x280
    ctx->r9 = ADD32(0, 0X280);
    // 0x8007AB58: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x8007AB5C: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x8007AB60: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8007AB64: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
    // 0x8007AB68: jal         0x800D2200
    // 0x8007AB6C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    osViSetMode_recomp(rdram, ctx);
        goto after_6;
    // 0x8007AB6C: sw          $v0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r2;
    after_6:
    // 0x8007AB70: b           L_8007AC10
    // 0x8007AB74: nop

        goto L_8007AC10;
    // 0x8007AB74: nop

L_8007AB78:
    // 0x8007AB78: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x8007AB7C: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x8007AB80: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x8007AB84: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8007AB88: addiu       $t5, $t5, 0x3E90
    ctx->r13 = ADD32(ctx->r13, 0X3E90);
    // 0x8007AB8C: addiu       $t4, $t3, 0x280
    ctx->r12 = ADD32(ctx->r11, 0X280);
    // 0x8007AB90: jal         0x800D2200
    // 0x8007AB94: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    osViSetMode_recomp(rdram, ctx);
        goto after_7;
    // 0x8007AB94: addu        $a0, $t4, $t5
    ctx->r4 = ADD32(ctx->r12, ctx->r13);
    after_7:
    // 0x8007AB98: b           L_8007AC10
    // 0x8007AB9C: nop

        goto L_8007AC10;
    // 0x8007AB9C: nop

L_8007ABA0:
    // 0x8007ABA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8007ABA4: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x8007ABA8: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8007ABAC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007ABB0: addiu       $t8, $t8, 0x3E90
    ctx->r24 = ADD32(ctx->r24, 0X3E90);
    // 0x8007ABB4: addiu       $t7, $t6, 0x320
    ctx->r15 = ADD32(ctx->r14, 0X320);
    // 0x8007ABB8: jal         0x800D2200
    // 0x8007ABBC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    osViSetMode_recomp(rdram, ctx);
        goto after_8;
    // 0x8007ABBC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_8:
    // 0x8007ABC0: b           L_8007AC10
    // 0x8007ABC4: nop

        goto L_8007AC10;
    // 0x8007ABC4: nop

L_8007ABC8:
    // 0x8007ABC8: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8007ABCC: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8007ABD0: sll         $t9, $t9, 4
    ctx->r25 = S32(ctx->r25 << 4);
    // 0x8007ABD4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007ABD8: addiu       $t1, $t1, 0x3E90
    ctx->r9 = ADD32(ctx->r9, 0X3E90);
    // 0x8007ABDC: addiu       $t0, $t9, 0x2D0
    ctx->r8 = ADD32(ctx->r25, 0X2D0);
    // 0x8007ABE0: jal         0x800D2200
    // 0x8007ABE4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    osViSetMode_recomp(rdram, ctx);
        goto after_9;
    // 0x8007ABE4: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    after_9:
    // 0x8007ABE8: b           L_8007AC10
    // 0x8007ABEC: nop

        goto L_8007AC10;
    // 0x8007ABEC: nop

L_8007ABF0:
    // 0x8007ABF0: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8007ABF4: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x8007ABF8: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x8007ABFC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007AC00: addiu       $t4, $t4, 0x3E90
    ctx->r12 = ADD32(ctx->r12, 0X3E90);
    // 0x8007AC04: addiu       $t3, $t2, 0x370
    ctx->r11 = ADD32(ctx->r10, 0X370);
    // 0x8007AC08: jal         0x800D2200
    // 0x8007AC0C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    osViSetMode_recomp(rdram, ctx);
        goto after_10;
    // 0x8007AC0C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    after_10:
L_8007AC10:
    // 0x8007AC10: jal         0x800D27C0
    // 0x8007AC14: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_11;
    // 0x8007AC14: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8007AC18: jal         0x800D27C0
    // 0x8007AC1C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_12;
    // 0x8007AC1C: addiu       $a0, $zero, 0x40
    ctx->r4 = ADD32(0, 0X40);
    after_12:
    // 0x8007AC20: jal         0x800D27C0
    // 0x8007AC24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    osViSetSpecialFeatures_recomp(rdram, ctx);
        goto after_13;
    // 0x8007AC24: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x8007AC28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007AC2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007AC30: jr          $ra
    // 0x8007AC34: nop

    return;
    // 0x8007AC34: nop

;}
RECOMP_FUNC void sound_volume_set_relative(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001FBC: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001FC0: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80001FC4: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001FC8: lw          $t8, 0x6298($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6298);
    // 0x80001FCC: addu        $t9, $t9, $t6
    ctx->r25 = ADD32(ctx->r25, ctx->r14);
    // 0x80001FD0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80001FD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001FD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001FDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001FE0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80001FE4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80001FE8: lbu         $t1, 0x2($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X2);
    // 0x80001FEC: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x80001FF0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80001FF4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80001FF8: bgez        $t1, L_80002010
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80001FFC: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80002010;
    }
    // 0x80001FFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80002000: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002004: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80002008: nop

    // 0x8000200C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80002010:
    // 0x80002010: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x80002014: bgez        $a2, L_8000202C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80002018: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000202C;
    }
    // 0x80002018: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000201C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002020: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80002024: nop

    // 0x80002028: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_8000202C:
    // 0x8000202C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80002030: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80002034: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80002038: div.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8000203C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80002040: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x80002044: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80002048: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8000204C: nop

    // 0x80002050: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80002054: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80002058: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000205C: nop

    // 0x80002060: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80002064: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80002068: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8000206C: beq         $t4, $zero, L_8000207C
    if (ctx->r12 == 0) {
        // 0x80002070: sll         $t3, $a3, 8
        ctx->r11 = S32(ctx->r7 << 8);
            goto L_8000207C;
    }
    // 0x80002070: sll         $t3, $a3, 8
    ctx->r11 = S32(ctx->r7 << 8);
    // 0x80002074: jal         0x800049F8
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x80002078: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    after_0:
L_8000207C:
    // 0x8000207C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002080: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002084: jr          $ra
    // 0x80002088: nop

    return;
    // 0x80002088: nop

;}
RECOMP_FUNC void obj_loop_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80039370: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80039374: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80039378: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003937C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80039380: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80039384: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x80039388: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    // 0x8003938C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80039390: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80039394: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80039398: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003939C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800393A0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800393A4: bne         $t7, $zero, L_800393C4
    if (ctx->r15 != 0) {
        // 0x800393A8: swc1        $f4, 0x98($sp)
        MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
            goto L_800393C4;
    }
    // 0x800393A8: swc1        $f4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f4.u32l;
    // 0x800393AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800393B0: lwc1        $f11, 0x65F0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X65F0);
    // 0x800393B4: lwc1        $f10, 0x65F4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65F4);
    // 0x800393B8: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800393BC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800393C0: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
L_800393C4:
    // 0x800393C4: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x800393C8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800393CC: jal         0x8006BFF0
    // 0x800393D0: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x800393D0: swc1        $f0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800393D4: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800393D8: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x800393DC: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x800393E0: bne         $t8, $zero, L_80039418
    if (ctx->r24 != 0) {
        // 0x800393E4: nop
    
            goto L_80039418;
    }
    // 0x800393E4: nop

    // 0x800393E8: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800393EC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800393F0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800393F4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800393F8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800393FC: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80039400: nop

    // 0x80039404: bc1f        L_80039418
    if (!c1cs) {
        // 0x80039408: nop
    
            goto L_80039418;
    }
    // 0x80039408: nop

    // 0x8003940C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039410: nop

    // 0x80039414: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
L_80039418:
    // 0x80039418: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003941C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039420: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
    // 0x80039424: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80039428: jal         0x8001BAFC
    // 0x8003942C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x8003942C: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80039430: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80039434: beq         $v0, $zero, L_8003949C
    if (ctx->r2 == 0) {
        // 0x80039438: sw          $v0, 0x90($sp)
        MEM_W(0X90, ctx->r29) = ctx->r2;
            goto L_8003949C;
    }
    // 0x80039438: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x8003943C: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x80039440: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80039444: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80039448: lwc1        $f10, 0x38($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003944C: lwc1        $f8, 0xC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80039450: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039454: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x80039458: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003945C: lwc1        $f6, 0x14($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80039460: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80039464: mul.s       $f8, $f10, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x80039468: sub.s       $f0, $f4, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8003946C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039470: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80039474: sub.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80039478: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x8003947C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80039480: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80039484: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x80039488: swc1        $f2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f2.u32l;
    // 0x8003948C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80039490: jal         0x800CA030
    // 0x80039494: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80039494: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
    after_2:
    // 0x80039498: swc1        $f0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f0.u32l;
L_8003949C:
    // 0x8003949C: jal         0x8006A794
    // 0x800394A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_3;
    // 0x800394A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800394A4: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x800394A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800394AC: bne         $t9, $zero, L_800395A0
    if (ctx->r25 != 0) {
        // 0x800394B0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800395A0;
    }
    // 0x800394B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800394B4: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800394B8: lwc1        $f17, 0x65F8($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X65F8);
    // 0x800394BC: lwc1        $f16, 0x65FC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X65FC);
    // 0x800394C0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800394C4: c.lt.d      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.d < ctx->f16.d;
    // 0x800394C8: nop

    // 0x800394CC: bc1f        L_800395A0
    if (!c1cs) {
        // 0x800394D0: nop
    
            goto L_800395A0;
    }
    // 0x800394D0: nop

    // 0x800394D4: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x800394D8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800394DC: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800394E0: andi        $t4, $v0, 0x2000
    ctx->r12 = ctx->r2 & 0X2000;
    // 0x800394E4: andi        $t1, $t0, 0x8
    ctx->r9 = ctx->r8 & 0X8;
    // 0x800394E8: beq         $t1, $zero, L_80039500
    if (ctx->r9 == 0) {
        // 0x800394EC: nop
    
            goto L_80039500;
    }
    // 0x800394EC: nop

    // 0x800394F0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800394F4: nop

    // 0x800394F8: beq         $t2, $t3, L_80039508
    if (ctx->r10 == ctx->r11) {
        // 0x800394FC: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_80039508;
    }
    // 0x800394FC: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_80039500:
    // 0x80039500: beq         $t4, $zero, L_800395A0
    if (ctx->r12 == 0) {
        // 0x80039504: andi        $t5, $v0, 0x2000
        ctx->r13 = ctx->r2 & 0X2000;
            goto L_800395A0;
    }
    // 0x80039504: andi        $t5, $v0, 0x2000
    ctx->r13 = ctx->r2 & 0X2000;
L_80039508:
    // 0x80039508: beq         $t5, $zero, L_8003952C
    if (ctx->r13 == 0) {
        // 0x8003950C: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_8003952C;
    }
    // 0x8003950C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80039510: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80039514: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x80039518: jal         0x80056970
    // 0x8003951C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    play_char_horn_sound(rdram, ctx);
        goto after_4;
    // 0x8003951C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_4:
    // 0x80039520: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039524: nop

    // 0x80039528: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_8003952C:
    // 0x8003952C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80039530: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039534: lwc1        $f4, 0xC($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0XC);
    // 0x80039538: lwc1        $f10, 0x14($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X14);
    // 0x8003953C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    // 0x80039540: sub.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80039544: jal         0x80070990
    // 0x80039548: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    arctan2_f(rdram, ctx);
        goto after_5;
    // 0x80039548: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    after_5:
    // 0x8003954C: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x80039550: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039554: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x80039558: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x8003955C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x80039560: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039564: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039568: bne         $at, $zero, L_8003957C
    if (ctx->r1 != 0) {
        // 0x8003956C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8003957C;
    }
    // 0x8003956C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039570: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x80039574: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80039578: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8003957C:
    // 0x8003957C: beq         $at, $zero, L_8003958C
    if (ctx->r1 == 0) {
        // 0x80039580: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_8003958C;
    }
    // 0x80039580: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80039584: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80039588: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
L_8003958C:
    // 0x8003958C: bne         $at, $zero, L_800395A0
    if (ctx->r1 != 0) {
        // 0x80039590: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_800395A0;
    }
    // 0x80039590: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80039594: beq         $at, $zero, L_800395A0
    if (ctx->r1 == 0) {
        // 0x80039598: nop
    
            goto L_800395A0;
    }
    // 0x80039598: nop

    // 0x8003959C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800395A0:
    // 0x800395A0: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800395A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800395A8: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x800395AC: jal         0x800521C8
    // 0x800395B0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    should_taj_teleport(rdram, ctx);
        goto after_6;
    // 0x800395B0: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_6:
    // 0x800395B4: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x800395B8: bne         $v0, $zero, L_800395C8
    if (ctx->r2 != 0) {
        // 0x800395BC: nop
    
            goto L_800395C8;
    }
    // 0x800395BC: nop

    // 0x800395C0: beq         $a2, $zero, L_800396E0
    if (ctx->r6 == 0) {
        // 0x800395C4: nop
    
            goto L_800396E0;
    }
    // 0x800395C4: nop

L_800395C8:
    // 0x800395C8: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800395CC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x800395D0: beq         $v0, $zero, L_800395E0
    if (ctx->r2 == 0) {
        // 0x800395D4: nop
    
            goto L_800395E0;
    }
    // 0x800395D4: nop

    // 0x800395D8: bne         $v0, $at, L_800396E0
    if (ctx->r2 != ctx->r1) {
        // 0x800395DC: nop
    
            goto L_800396E0;
    }
    // 0x800395DC: nop

L_800395E0:
    // 0x800395E0: jal         0x800012E8
    // 0x800395E4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    music_channel_reset_all(rdram, ctx);
        goto after_7;
    // 0x800395E4: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_7:
    // 0x800395E8: jal         0x80000BE0
    // 0x800395EC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_8;
    // 0x800395EC: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x800395F0: jal         0x80000B34
    // 0x800395F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800395F4: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_9:
    // 0x800395F8: lw          $t2, 0x90($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X90);
    // 0x800395FC: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039600: beq         $t2, $zero, L_8003961C
    if (ctx->r10 == 0) {
        // 0x80039604: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_8003961C;
    }
    // 0x80039604: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80039608: jal         0x80006AC8
    // 0x8003960C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x8003960C: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_10:
    // 0x80039610: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80039614: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039618: sw          $zero, 0x118($t3)
    MEM_W(0X118, ctx->r11) = 0;
L_8003961C:
    // 0x8003961C: jal         0x80008140
    // 0x80039620: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    audspat_jingle_off(rdram, ctx);
        goto after_11;
    // 0x80039620: sw          $a2, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r6;
    after_11:
    // 0x80039624: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x80039628: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003962C: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80039630: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80039634: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80039638: sub.s       $f12, $f8, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8003963C: jal         0x80070990
    // 0x80039640: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x80039640: sub.s       $f14, $f4, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f18.fl;
    after_12:
    // 0x80039644: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x80039648: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003964C: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x80039650: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80039654: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80039658: subu        $v1, $v0, $t6
    ctx->r3 = SUB32(ctx->r2, ctx->r14);
    // 0x8003965C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039660: bne         $at, $zero, L_80039668
    if (ctx->r1 != 0) {
        // 0x80039664: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80039668;
    }
    // 0x80039664: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80039668:
    // 0x80039668: beq         $a2, $zero, L_8003967C
    if (ctx->r6 == 0) {
        // 0x8003966C: addiu       $a1, $s1, 0x20
        ctx->r5 = ADD32(ctx->r17, 0X20);
            goto L_8003967C;
    }
    // 0x8003966C: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x80039670: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039674: b           L_8003968C
    // 0x80039678: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
        goto L_8003968C;
    // 0x80039678: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
L_8003967C:
    // 0x8003967C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80039680: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039684: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039688: sb          $t9, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r25;
L_8003968C:
    // 0x8003968C: addiu       $t0, $s1, 0x12
    ctx->r8 = ADD32(ctx->r17, 0X12);
    // 0x80039690: addiu       $t1, $s1, 0x13
    ctx->r9 = ADD32(ctx->r17, 0X13);
    // 0x80039694: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80039698: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8003969C: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x800396A0: jal         0x80030790
    // 0x800396A4: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_13;
    // 0x800396A4: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_13:
    // 0x800396A8: addiu       $t2, $zero, 0x3C0
    ctx->r10 = ADD32(0, 0X3C0);
    // 0x800396AC: addiu       $t3, $zero, 0x44C
    ctx->r11 = ADD32(0, 0X44C);
    // 0x800396B0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x800396B4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x800396B8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800396BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800396C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800396C4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800396C8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800396CC: jal         0x80030E20
    // 0x800396D0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    slowly_change_fog(rdram, ctx);
        goto after_14;
    // 0x800396D0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    after_14:
    // 0x800396D4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800396D8: nop

    // 0x800396DC: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_800396E0:
    // 0x800396E0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800396E4: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800396E8: beq         $v0, $zero, L_80039724
    if (ctx->r2 == 0) {
        // 0x800396EC: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80039724;
    }
    // 0x800396EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800396F0: beq         $v0, $at, L_80039720
    if (ctx->r2 == ctx->r1) {
        // 0x800396F4: addiu       $at, $zero, 0x14
        ctx->r1 = ADD32(0, 0X14);
            goto L_80039720;
    }
    // 0x800396F4: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x800396F8: beq         $v0, $at, L_80039720
    if (ctx->r2 == ctx->r1) {
        // 0x800396FC: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80039720;
    }
    // 0x800396FC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80039700: beq         $v0, $at, L_80039724
    if (ctx->r2 == ctx->r1) {
        // 0x80039704: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_80039724;
    }
    // 0x80039704: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039708: jal         0x8005A41C
    // 0x8003970C: nop

    disable_racer_input(rdram, ctx);
        goto after_15;
    // 0x8003970C: nop

    after_15:
    // 0x80039710: jal         0x800AB6F0
    // 0x80039714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_16;
    // 0x80039714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80039718: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003971C: nop

L_80039720:
    // 0x80039720: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_80039724:
    // 0x80039724: beq         $v0, $a3, L_80039744
    if (ctx->r2 == ctx->r7) {
        // 0x80039728: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039744;
    }
    // 0x80039728: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8003972C: beq         $v0, $at, L_80039744
    if (ctx->r2 == ctx->r1) {
        // 0x80039730: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80039744;
    }
    // 0x80039730: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80039734: beq         $v0, $at, L_80039744
    if (ctx->r2 == ctx->r1) {
        // 0x80039738: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_80039744;
    }
    // 0x80039738: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8003973C: bne         $v0, $at, L_80039758
    if (ctx->r2 != ctx->r1) {
        // 0x80039740: nop
    
            goto L_80039758;
    }
    // 0x80039740: nop

L_80039744:
    // 0x80039744: jal         0x8009D530
    // 0x80039748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    npc_dialogue_loop(rdram, ctx);
        goto after_17;
    // 0x80039748: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x8003974C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039750: b           L_80039768
    // 0x80039754: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
        goto L_80039768;
    // 0x80039754: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
L_80039758:
    // 0x80039758: jal         0x8009D4AC
    // 0x8003975C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_18;
    // 0x8003975C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_18:
    // 0x80039760: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039764: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_80039768:
    // 0x80039768: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8003976C: nop

    // 0x80039770: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x80039774: sltiu       $at, $t5, 0x15
    ctx->r1 = ctx->r13 < 0X15 ? 1 : 0;
    // 0x80039778: beq         $at, $zero, L_800397A8
    if (ctx->r1 == 0) {
        // 0x8003977C: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_800397A8;
    }
    // 0x8003977C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80039780: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039784: addu        $at, $at, $t5
    gpr jr_addend_80039790 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80039788: lw          $t5, 0x6600($at)
    ctx->r13 = ADD32(ctx->r1, 0X6600);
    // 0x8003978C: nop

    // 0x80039790: jr          $t5
    // 0x80039794: nop

    switch (jr_addend_80039790 >> 2) {
        case 0: goto L_80039798; break;
        case 1: goto L_80039798; break;
        case 2: goto L_80039798; break;
        case 3: goto L_80039798; break;
        case 4: goto L_800397A8; break;
        case 5: goto L_800397A8; break;
        case 6: goto L_80039798; break;
        case 7: goto L_800397A8; break;
        case 8: goto L_800397A8; break;
        case 9: goto L_80039798; break;
        case 10: goto L_80039798; break;
        case 11: goto L_800397A8; break;
        case 12: goto L_800397A8; break;
        case 13: goto L_800397A8; break;
        case 14: goto L_80039798; break;
        case 15: goto L_800397A8; break;
        case 16: goto L_800397A8; break;
        case 17: goto L_800397A8; break;
        case 18: goto L_800397A8; break;
        case 19: goto L_80039798; break;
        case 20: goto L_80039798; break;
        default: switch_error(__func__, 0x80039790, 0x800E6600);
    }
    // 0x80039794: nop

L_80039798:
    // 0x80039798: jal         0x8006F5C8
    // 0x8003979C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_19;
    // 0x8003979C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800397A0: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800397A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
L_800397A8:
    // 0x800397A8: beq         $v0, $zero, L_800397D4
    if (ctx->r2 == 0) {
        // 0x800397AC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397AC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397B0: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x800397B4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x800397B8: beq         $t6, $zero, L_800397D4
    if (ctx->r14 == 0) {
        // 0x800397BC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397BC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397C0: beq         $at, $zero, L_800397D4
    if (ctx->r1 == 0) {
        // 0x800397C4: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800397D4;
    }
    // 0x800397C4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800397C8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800397CC: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x800397D0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800397D4:
    // 0x800397D4: sltiu       $at, $t7, 0x1E
    ctx->r1 = ctx->r15 < 0X1E ? 1 : 0;
    // 0x800397D8: beq         $at, $zero, L_8003A5EC
    if (ctx->r1 == 0) {
        // 0x800397DC: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_8003A5EC;
    }
    // 0x800397DC: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800397E0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800397E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800397E8: addu        $at, $at, $t7
    gpr jr_addend_800397F4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800397EC: lw          $t7, 0x6654($at)
    ctx->r15 = ADD32(ctx->r1, 0X6654);
    // 0x800397F0: nop

    // 0x800397F4: jr          $t7
    // 0x800397F8: nop

    switch (jr_addend_800397F4 >> 2) {
        case 0: goto L_800397FC; break;
        case 1: goto L_800399B8; break;
        case 2: goto L_80039B20; break;
        case 3: goto L_80039BF8; break;
        case 4: goto L_80039E04; break;
        case 5: goto L_80039F18; break;
        case 6: goto L_8003A01C; break;
        case 7: goto L_8003A01C; break;
        case 8: goto L_8003A5EC; break;
        case 9: goto L_8003A10C; break;
        case 10: goto L_8003A228; break;
        case 11: goto L_8003A5EC; break;
        case 12: goto L_8003A5EC; break;
        case 13: goto L_8003A5EC; break;
        case 14: goto L_8003A2A8; break;
        case 15: goto L_8003A5EC; break;
        case 16: goto L_8003A5EC; break;
        case 17: goto L_8003A5EC; break;
        case 18: goto L_8003A5EC; break;
        case 19: goto L_8003A43C; break;
        case 20: goto L_8003A534; break;
        case 21: goto L_8003A5EC; break;
        case 22: goto L_8003A5EC; break;
        case 23: goto L_8003A5EC; break;
        case 24: goto L_8003A5EC; break;
        case 25: goto L_8003A5EC; break;
        case 26: goto L_8003A5EC; break;
        case 27: goto L_8003A5EC; break;
        case 28: goto L_8003A5EC; break;
        case 29: goto L_8003A5B4; break;
        default: switch_error(__func__, 0x800397F4, 0x800E6654);
    }
    // 0x800397F8: nop

L_800397FC:
    // 0x800397FC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039800: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80039804: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80039808: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8003980C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80039810: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x80039814: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80039818: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003981C: bc1f        L_80039840
    if (!c1cs) {
        // 0x80039820: sb          $t8, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r24;
            goto L_80039840;
    }
    // 0x80039820: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x80039824: swc1        $f1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x80039828: jal         0x8005A42C
    // 0x8003982C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_20;
    // 0x8003982C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x80039830: lwc1        $f1, 0x40($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80039834: lwc1        $f0, 0x44($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80039838: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003983C: nop

L_80039840:
    // 0x80039840: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80039844: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80039848: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003984C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039850: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80039854: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039858: bc1f        L_80039974
    if (!c1cs) {
        // 0x8003985C: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_80039974;
    }
    // 0x8003985C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80039860: nop

    // 0x80039864: div.s       $f12, $f16, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80039868: jal         0x80070990
    // 0x8003986C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    arctan2_f(rdram, ctx);
        goto after_21;
    // 0x8003986C: div.s       $f14, $f4, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    after_21:
    // 0x80039870: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039874: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039878: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x8003987C: subu        $v1, $v0, $t9
    ctx->r3 = SUB32(ctx->r2, ctx->r25);
    // 0x80039880: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039884: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039888: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003988C: bne         $at, $zero, L_8003989C
    if (ctx->r1 != 0) {
        // 0x80039890: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003989C;
    }
    // 0x80039890: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039894: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039898: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8003989C:
    // 0x8003989C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800398A0: beq         $at, $zero, L_800398AC
    if (ctx->r1 == 0) {
        // 0x800398A4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800398AC;
    }
    // 0x800398A4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800398A8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800398AC:
    // 0x800398AC: blez        $v1, L_800398C0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800398B0: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800398C0;
    }
    // 0x800398B0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800398B4: beq         $at, $zero, L_800398C4
    if (ctx->r1 == 0) {
        // 0x800398B8: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_800398C4;
    }
    // 0x800398B8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800398BC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800398C0:
    // 0x800398C0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_800398C4:
    // 0x800398C4: sra         $t0, $v1, 4
    ctx->r8 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800398C8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800398CC: addu        $t1, $a1, $t0
    ctx->r9 = ADD32(ctx->r5, ctx->r8);
    // 0x800398D0: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x800398D4: beq         $at, $zero, L_800398E4
    if (ctx->r1 == 0) {
        // 0x800398D8: sh          $t1, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r9;
            goto L_800398E4;
    }
    // 0x800398D8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x800398DC: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x800398E0: beq         $at, $zero, L_800398F0
    if (ctx->r1 == 0) {
        // 0x800398E4: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_800398F0;
    }
L_800398E4:
    // 0x800398E4: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x800398E8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800398EC: nop

L_800398F0:
    // 0x800398F0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800398F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800398F8: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800398FC: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80039900: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039904: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80039908: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x8003990C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80039910: add.d       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f18.d + ctx->f8.d;
    // 0x80039914: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039918: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8003991C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80039920: jal         0x80070A04
    // 0x80039924: nop

    sins_f(rdram, ctx);
        goto after_22;
    // 0x80039924: nop

    after_22:
    // 0x80039928: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003992C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80039930: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80039934: jal         0x80070A38
    // 0x80039938: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    coss_f(rdram, ctx);
        goto after_23;
    // 0x80039938: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    after_23:
    // 0x8003993C: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039940: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039944: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80039948: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003994C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039950: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80039954: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80039958: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003995C: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80039960: nop

    // 0x80039964: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039968: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003996C: b           L_80039980
    // 0x80039970: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
        goto L_80039980;
    // 0x80039970: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
L_80039974:
    // 0x80039974: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x80039978: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003997C: nop

L_80039980:
    // 0x80039980: lwc1        $f16, 0x1C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80039984: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80039988: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8003998C: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80039990: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039994: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80039998: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003999C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800399A0: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800399A4: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800399A8: jal         0x80011570
    // 0x800399AC: nop

    move_object(rdram, ctx);
        goto after_24;
    // 0x800399AC: nop

    after_24:
    // 0x800399B0: b           L_8003AB44
    // 0x800399B4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x800399B4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_800399B8:
    // 0x800399B8: jal         0x8005A42C
    // 0x800399BC: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_25;
    // 0x800399BC: nop

    after_25:
    // 0x800399C0: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800399C4: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x800399C8: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800399CC: cvt.d.s     $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.d = CVT_D_S(ctx->f14.fl);
    // 0x800399D0: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x800399D4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800399D8: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x800399DC: add.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f4.d + ctx->f10.d;
    // 0x800399E0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800399E4: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800399E8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800399EC: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x800399F0: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800399F4: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x800399F8: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x800399FC: subu        $v1, $t4, $t5
    ctx->r3 = SUB32(ctx->r12, ctx->r13);
    // 0x80039A00: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039A04: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039A08: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039A0C: bne         $at, $zero, L_80039A1C
    if (ctx->r1 != 0) {
        // 0x80039A10: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80039A1C;
    }
    // 0x80039A10: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039A14: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039A18: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039A1C:
    // 0x80039A1C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039A20: beq         $at, $zero, L_80039A2C
    if (ctx->r1 == 0) {
        // 0x80039A24: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80039A2C;
    }
    // 0x80039A24: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039A28: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039A2C:
    // 0x80039A2C: blez        $v1, L_80039A40
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039A30: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039A40;
    }
    // 0x80039A30: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039A34: beq         $at, $zero, L_80039A44
    if (ctx->r1 == 0) {
        // 0x80039A38: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80039A44;
    }
    // 0x80039A38: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80039A3C: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039A40:
    // 0x80039A40: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
L_80039A44:
    // 0x80039A44: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x80039A48: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x80039A4C: beq         $at, $zero, L_80039AAC
    if (ctx->r1 == 0) {
        // 0x80039A50: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_80039AAC;
    }
    // 0x80039A50: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x80039A54: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x80039A58: bne         $at, $zero, L_80039AAC
    if (ctx->r1 != 0) {
        // 0x80039A5C: nop
    
            goto L_80039AAC;
    }
    // 0x80039A5C: nop

    // 0x80039A60: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80039A64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80039A68: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039A6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039A70: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039A74: c.lt.d      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.d < ctx->f4.d;
    // 0x80039A78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80039A7C: bc1f        L_80039AAC
    if (!c1cs) {
        // 0x80039A80: nop
    
            goto L_80039AAC;
    }
    // 0x80039A80: nop

    // 0x80039A84: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039A88: sw          $a3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r7;
    // 0x80039A8C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039A90: lhu         $a0, -0x259E($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X259E);
    // 0x80039A94: jal         0x8003AC7C
    // 0x80039A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_26;
    // 0x80039A98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80039A9C: addiu       $t8, $zero, 0x10F
    ctx->r24 = ADD32(0, 0X10F);
    // 0x80039AA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039AA4: lwc1        $f14, 0xAC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039AA8: sh          $t8, -0x259E($at)
    MEM_H(-0X259E, ctx->r1) = ctx->r24;
L_80039AAC:
    // 0x80039AAC: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80039AB0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80039AB4: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80039AB8: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80039ABC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039AC0: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x80039AC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80039AC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039ACC: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80039AD0: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
    // 0x80039AD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039AD8: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80039ADC: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80039AE0: nop

    // 0x80039AE4: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039AE8: mul.d       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f12.d);
    // 0x80039AEC: nop

    // 0x80039AF0: mul.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80039AF4: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
    // 0x80039AF8: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80039AFC: mul.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80039B00: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80039B04: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80039B08: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80039B0C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80039B10: jal         0x80011570
    // 0x80039B14: nop

    move_object(rdram, ctx);
        goto after_27;
    // 0x80039B14: nop

    after_27:
    // 0x80039B18: b           L_8003AB44
    // 0x80039B1C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039B1C: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039B20:
    // 0x80039B20: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80039B24: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80039B28: sb          $t9, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r25;
    // 0x80039B2C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x80039B30: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039B34: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039B38: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80039B3C: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039B40: add.d       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f6.d + ctx->f16.d;
    // 0x80039B44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039B48: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x80039B4C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039B50: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039B54: lwc1        $f18, 0x66D4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X66D4);
    // 0x80039B58: lwc1        $f19, 0x66D0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X66D0);
    // 0x80039B5C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80039B60: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x80039B64: lui         $at, 0x429A
    ctx->r1 = S32(0X429A << 16);
    // 0x80039B68: bc1f        L_80039B8C
    if (!c1cs) {
        // 0x80039B6C: lw          $t0, 0x90($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X90);
            goto L_80039B8C;
    }
    // 0x80039B6C: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80039B70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039B74: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80039B78: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80039B7C: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039B80: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x80039B84: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x80039B88: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
L_80039B8C:
    // 0x80039B8C: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x80039B90: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x80039B94: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x80039B98: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80039B9C: subu        $v1, $t1, $t2
    ctx->r3 = SUB32(ctx->r9, ctx->r10);
    // 0x80039BA0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80039BA4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80039BA8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80039BAC: bne         $at, $zero, L_80039BBC
    if (ctx->r1 != 0) {
        // 0x80039BB0: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80039BBC;
    }
    // 0x80039BB0: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80039BB4: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80039BB8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039BBC:
    // 0x80039BBC: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80039BC0: beq         $at, $zero, L_80039BCC
    if (ctx->r1 == 0) {
        // 0x80039BC4: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80039BCC;
    }
    // 0x80039BC4: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80039BC8: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80039BCC:
    // 0x80039BCC: blez        $v1, L_80039BE0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80039BD0: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_80039BE0;
    }
    // 0x80039BD0: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80039BD4: beq         $at, $zero, L_80039BE4
    if (ctx->r1 == 0) {
        // 0x80039BD8: sra         $t3, $v1, 4
        ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
            goto L_80039BE4;
    }
    // 0x80039BD8: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80039BDC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_80039BE0:
    // 0x80039BE0: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
L_80039BE4:
    // 0x80039BE4: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x80039BE8: jal         0x8005A42C
    // 0x80039BEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_28;
    // 0x80039BEC: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    after_28:
    // 0x80039BF0: b           L_8003AB44
    // 0x80039BF4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039BF4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039BF8:
    // 0x80039BF8: sb          $v1, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r3;
    // 0x80039BFC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039C00: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039C04: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80039C08: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x80039C0C: add.d       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f8.d + ctx->f6.d;
    // 0x80039C10: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x80039C14: jal         0x8005A42C
    // 0x80039C18: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_29;
    // 0x80039C18: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    after_29:
    // 0x80039C1C: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039C20: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80039C24: beq         $a2, $a3, L_80039C30
    if (ctx->r6 == ctx->r7) {
        // 0x80039C28: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039C30;
    }
    // 0x80039C28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039C2C: bne         $a2, $at, L_80039CE8
    if (ctx->r6 != ctx->r1) {
        // 0x80039C30: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80039CE8;
    }
L_80039C30:
    // 0x80039C30: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80039C34: bne         $a2, $at, L_80039C48
    if (ctx->r6 != ctx->r1) {
        // 0x80039C38: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80039C48;
    }
    // 0x80039C38: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80039C3C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80039C40: b           L_80039C50
    // 0x80039C44: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
        goto L_80039C50;
    // 0x80039C44: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_80039C48:
    // 0x80039C48: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80039C4C: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
L_80039C50:
    // 0x80039C50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80039C54: lwc1        $f10, 0x66D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X66D8);
    // 0x80039C58: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    // 0x80039C5C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x80039C60: sb          $t7, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r15;
    // 0x80039C64: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x80039C68: jal         0x8003AC7C
    // 0x80039C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_30;
    // 0x80039C6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_30:
    // 0x80039C70: lh          $t8, 0x20($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X20);
    // 0x80039C74: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x80039C78: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x80039C7C: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80039C80: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80039C84: lh          $t9, 0x22($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X22);
    // 0x80039C88: addiu       $t0, $zero, 0xB4
    ctx->r8 = ADD32(0, 0XB4);
    // 0x80039C8C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80039C90: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80039C94: jal         0x80030E20
    // 0x80039C98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    slowly_change_fog(rdram, ctx);
        goto after_31;
    // 0x80039C98: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_31:
    // 0x80039C9C: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x80039CA0: nop

    // 0x80039CA4: lbu         $a0, 0xB3($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0XB3);
    // 0x80039CA8: jal         0x80000BE0
    // 0x80039CAC: nop

    music_voicelimit_set(rdram, ctx);
        goto after_32;
    // 0x80039CAC: nop

    after_32:
    // 0x80039CB0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80039CB4: nop

    // 0x80039CB8: lbu         $a0, 0x52($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X52);
    // 0x80039CBC: jal         0x80000B34
    // 0x80039CC0: nop

    music_play(rdram, ctx);
        goto after_33;
    // 0x80039CC0: nop

    after_33:
    // 0x80039CC4: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80039CC8: nop

    // 0x80039CCC: lhu         $a0, 0x54($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X54);
    // 0x80039CD0: jal         0x80001074
    // 0x80039CD4: nop

    music_dynamic_set(rdram, ctx);
        goto after_34;
    // 0x80039CD4: nop

    after_34:
    // 0x80039CD8: jal         0x80008168
    // 0x80039CDC: nop

    audspat_jingle_on(rdram, ctx);
        goto after_35;
    // 0x80039CDC: nop

    after_35:
    // 0x80039CE0: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039CE4: nop

L_80039CE8:
    // 0x80039CE8: andi        $t4, $a2, 0x80
    ctx->r12 = ctx->r6 & 0X80;
    // 0x80039CEC: beq         $t4, $zero, L_80039D60
    if (ctx->r12 == 0) {
        // 0x80039CF0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039D60;
    }
    // 0x80039CF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039CF4: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039CF8: andi        $t5, $a2, 0x7F
    ctx->r13 = ctx->r6 & 0X7F;
    // 0x80039CFC: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x80039D00: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x80039D04: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x80039D08: lb          $t7, 0x1D6($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X1D6);
    // 0x80039D0C: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x80039D10: beq         $t7, $t8, L_80039D50
    if (ctx->r15 == ctx->r24) {
        // 0x80039D14: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_80039D50;
    }
    // 0x80039D14: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039D18: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039D1C: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x80039D20: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x80039D24: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80039D28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039D2C: lb          $a0, 0x1D6($t0)
    ctx->r4 = MEM_B(ctx->r8, 0X1D6);
    // 0x80039D30: nop

    // 0x80039D34: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039D38: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x80039D3C: jal         0x8003AC7C
    // 0x80039D40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_36;
    // 0x80039D40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_36:
    // 0x80039D44: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D48: b           L_80039D60
    // 0x80039D4C: nop

        goto L_80039D60;
    // 0x80039D4C: nop

L_80039D50:
    // 0x80039D50: jal         0x8009D880
    // 0x80039D54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_37;
    // 0x80039D54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_37:
    // 0x80039D58: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80039D5C: nop

L_80039D60:
    // 0x80039D60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039D64: andi        $t2, $a2, 0x40
    ctx->r10 = ctx->r6 & 0X40;
    // 0x80039D68: beq         $t2, $zero, L_80039DFC
    if (ctx->r10 == 0) {
        // 0x80039D6C: addiu       $v1, $v1, -0x25A0
        ctx->r3 = ADD32(ctx->r3, -0X25A0);
            goto L_80039DFC;
    }
    // 0x80039D6C: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039D70: andi        $t3, $a2, 0xF
    ctx->r11 = ctx->r6 & 0XF;
    // 0x80039D74: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    // 0x80039D78: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80039D7C: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x80039D80: lb          $t5, 0x1D6($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X1D6);
    // 0x80039D84: addiu       $t0, $zero, 0xF
    ctx->r8 = ADD32(0, 0XF);
    // 0x80039D88: beq         $t5, $v0, L_80039DD0
    if (ctx->r13 == ctx->r2) {
        // 0x80039D8C: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80039DD0;
    }
    // 0x80039D8C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039D90: ori         $t6, $v0, 0x80
    ctx->r14 = ctx->r2 | 0X80;
    // 0x80039D94: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80039D98: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x80039D9C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80039DA0: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039DA4: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80039DA8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x80039DAC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80039DB0: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x80039DB4: nop

    // 0x80039DB8: addiu       $a0, $a0, 0x235
    ctx->r4 = ADD32(ctx->r4, 0X235);
    // 0x80039DBC: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x80039DC0: jal         0x8003AC7C
    // 0x80039DC4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    play_taj_voice_clip(rdram, ctx);
        goto after_38;
    // 0x80039DC4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_38:
    // 0x80039DC8: b           L_8003AB44
    // 0x80039DCC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039DCC: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039DD0:
    // 0x80039DD0: sw          $t0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r8;
    // 0x80039DD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80039DD8: sb          $t1, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r9;
    // 0x80039DDC: jal         0x800C06F8
    // 0x80039DE0: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    transition_begin(rdram, ctx);
        goto after_39;
    // 0x80039DE0: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    after_39:
    // 0x80039DE4: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039DE8: jal         0x8003AC7C
    // 0x80039DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_taj_voice_clip(rdram, ctx);
        goto after_40;
    // 0x80039DEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
    // 0x80039DF0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039DF4: nop

    // 0x80039DF8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80039DFC:
    // 0x80039DFC: b           L_8003AB44
    // 0x80039E00: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039E00: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039E04:
    // 0x80039E04: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80039E08: jal         0x8005A42C
    // 0x80039E0C: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_41;
    // 0x80039E0C: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    after_41:
    // 0x80039E10: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80039E14: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E18: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80039E1C: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x80039E20: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x80039E24: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80039E28: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039E2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039E30: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039E34: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80039E38: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039E3C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E40: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80039E44: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x80039E48: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80039E4C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039E50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039E54: bc1f        L_80039E70
    if (!c1cs) {
        // 0x80039E58: lui         $at, 0x404E
        ctx->r1 = S32(0X404E << 16);
            goto L_80039E70;
    }
    // 0x80039E58: lui         $at, 0x404E
    ctx->r1 = S32(0X404E << 16);
    // 0x80039E5C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80039E60: sw          $t3, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r11;
    // 0x80039E64: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E68: nop

    // 0x80039E6C: cvt.d.s     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f2.d = CVT_D_S(ctx->f10.fl);
L_80039E70:
    // 0x80039E70: c.lt.d      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.d < ctx->f2.d;
    // 0x80039E74: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80039E78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80039E7C: bc1f        L_80039E94
    if (!c1cs) {
        // 0x80039E80: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_80039E94;
    }
    // 0x80039E80: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80039E84: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x80039E88: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039E8C: nop

    // 0x80039E90: cvt.d.s     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f2.d = CVT_D_S(ctx->f8.fl);
L_80039E94:
    // 0x80039E94: c.lt.d      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.d < ctx->f2.d;
    // 0x80039E98: nop

    // 0x80039E9C: bc1f        L_80039F10
    if (!c1cs) {
        // 0x80039EA0: nop
    
            goto L_80039F10;
    }
    // 0x80039EA0: nop

    // 0x80039EA4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80039EA8: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80039EAC: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x80039EB0: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x80039EB4: lbu         $v0, 0x1F7($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1F7);
    // 0x80039EB8: sll         $t4, $v1, 4
    ctx->r12 = S32(ctx->r3 << 4);
    // 0x80039EBC: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80039EC0: beq         $at, $zero, L_80039ED4
    if (ctx->r1 == 0) {
        // 0x80039EC4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80039ED4;
    }
    // 0x80039EC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039EC8: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x80039ECC: b           L_8003AB40
    // 0x80039ED0: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
        goto L_8003AB40;
    // 0x80039ED0: sb          $t5, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = ctx->r13;
L_80039ED4:
    // 0x80039ED4: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039ED8: sb          $zero, 0x1F7($a2)
    MEM_B(0X1F7, ctx->r6) = 0;
    // 0x80039EDC: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x80039EE0: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80039EE4: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x80039EE8: jal         0x8000E1EC
    // 0x80039EEC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    despawn_player_racer(rdram, ctx);
        goto after_42;
    // 0x80039EEC: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_42:
    // 0x80039EF0: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80039EF4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x80039EF8: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    // 0x80039EFC: jal         0x80001D04
    // 0x80039F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_43;
    // 0x80039F00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_43:
    // 0x80039F04: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039F08: jal         0x800C06F8
    // 0x80039F0C: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    transition_begin(rdram, ctx);
        goto after_44;
    // 0x80039F0C: addiu       $a0, $a0, -0x3120
    ctx->r4 = ADD32(ctx->r4, -0X3120);
    after_44:
L_80039F10:
    // 0x80039F10: b           L_8003AB44
    // 0x80039F14: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x80039F14: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_80039F18:
    // 0x80039F18: jal         0x8005A42C
    // 0x80039F1C: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_45;
    // 0x80039F1C: nop

    after_45:
    // 0x80039F20: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80039F24: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80039F28: beq         $t8, $zero, L_8003A014
    if (ctx->r24 == 0) {
        // 0x80039F2C: nop
    
            goto L_8003A014;
    }
    // 0x80039F2C: nop

    // 0x80039F30: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039F34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80039F38: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80039F3C: c.eq.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl == ctx->f12.fl;
    // 0x80039F40: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80039F44: bc1t        L_80039F68
    if (c1cs) {
        // 0x80039F48: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_80039F68;
    }
    // 0x80039F48: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x80039F4C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80039F50: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80039F54: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x80039F58: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x80039F5C: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80039F60: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x80039F64: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_80039F68:
    // 0x80039F68: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80039F6C: slti        $at, $a2, 0x5
    ctx->r1 = SIGNED(ctx->r6) < 0X5 ? 1 : 0;
    // 0x80039F70: bne         $at, $zero, L_80039F7C
    if (ctx->r1 != 0) {
        // 0x80039F74: nop
    
            goto L_80039F7C;
    }
    // 0x80039F74: nop

    // 0x80039F78: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_80039F7C:
    // 0x80039F7C: lbu         $v0, 0x1F7($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1F7);
    // 0x80039F80: sll         $t0, $a2, 5
    ctx->r8 = S32(ctx->r6 << 5);
    // 0x80039F84: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80039F88: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80039F8C: beq         $at, $zero, L_80039F9C
    if (ctx->r1 == 0) {
        // 0x80039F90: addu        $t3, $v0, $t0
        ctx->r11 = ADD32(ctx->r2, ctx->r8);
            goto L_80039F9C;
    }
    // 0x80039F90: addu        $t3, $v0, $t0
    ctx->r11 = ADD32(ctx->r2, ctx->r8);
    // 0x80039F94: b           L_8003AB40
    // 0x80039F98: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
        goto L_8003AB40;
    // 0x80039F98: sb          $t3, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r11;
L_80039F9C:
    // 0x80039F9C: sb          $t4, 0x1F7($v1)
    MEM_B(0X1F7, ctx->r3) = ctx->r12;
    // 0x80039FA0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80039FA4: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80039FA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80039FAC: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80039FB0: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80039FB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80039FB8: bc1f        L_8003A014
    if (!c1cs) {
        // 0x80039FBC: addiu       $v1, $v1, -0x25A0
        ctx->r3 = ADD32(ctx->r3, -0X25A0);
            goto L_8003A014;
    }
    // 0x80039FBC: addiu       $v1, $v1, -0x25A0
    ctx->r3 = ADD32(ctx->r3, -0X25A0);
    // 0x80039FC0: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x80039FC4: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80039FC8: andi        $t6, $t5, 0x80
    ctx->r14 = ctx->r13 & 0X80;
    // 0x80039FCC: beq         $t6, $zero, L_8003A008
    if (ctx->r14 == 0) {
        // 0x80039FD0: addiu       $a0, $zero, 0x62
        ctx->r4 = ADD32(0, 0X62);
            goto L_8003A008;
    }
    // 0x80039FD0: addiu       $a0, $zero, 0x62
    ctx->r4 = ADD32(0, 0X62);
    // 0x80039FD4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80039FD8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80039FDC: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    // 0x80039FE0: jal         0x800C06F8
    // 0x80039FE4: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    transition_begin(rdram, ctx);
        goto after_46;
    // 0x80039FE4: addiu       $a0, $a0, -0x3118
    ctx->r4 = ADD32(ctx->r4, -0X3118);
    after_46:
    // 0x80039FE8: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x80039FEC: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x80039FF0: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x80039FF4: jal         0x80001D04
    // 0x80039FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_47;
    // 0x80039FF8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_47:
    // 0x80039FFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A000: b           L_8003AB40
    // 0x8003A004: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB40;
    // 0x8003A004: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8003A008:
    // 0x8003A008: sw          $t9, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r25;
    // 0x8003A00C: jal         0x8009D880
    // 0x8003A010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    set_menu_id_if_option_equal(rdram, ctx);
        goto after_48;
    // 0x8003A010: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_48:
L_8003A014:
    // 0x8003A014: b           L_8003AB44
    // 0x8003A018: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A018: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A01C:
    // 0x8003A01C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A020: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8003A024: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003A028: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x8003A02C: c.eq.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d == ctx->f2.d;
    // 0x8003A030: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A034: bc1t        L_8003A060
    if (c1cs) {
        // 0x8003A038: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003A060;
    }
    // 0x8003A038: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003A03C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8003A040: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A044: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A048: mul.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8003A04C: add.d       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f2.d + ctx->f16.d;
    // 0x8003A050: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A054: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A058: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A05C: nop

L_8003A060:
    // 0x8003A060: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003A064: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8003A068: c.eq.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl == ctx->f12.fl;
    // 0x8003A06C: nop

    // 0x8003A070: bc1f        L_8003AB40
    if (!c1cs) {
        // 0x8003A074: nop
    
            goto L_8003AB40;
    }
    // 0x8003A074: nop

    // 0x8003A078: sb          $t0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r8;
    // 0x8003A07C: lw          $t1, 0x78($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X78);
    // 0x8003A080: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8003A084: bne         $t1, $at, L_8003A0D8
    if (ctx->r9 != ctx->r1) {
        // 0x8003A088: addiu       $t2, $zero, 0x14
        ctx->r10 = ADD32(0, 0X14);
            goto L_8003A0D8;
    }
    // 0x8003A088: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8003A08C: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A090: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8003A094: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A098: lwc1        $f18, 0x38($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A09C: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A0A0: mul.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8003A0A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A0A8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A0AC: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003A0B0: mul.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8003A0B4: sub.s       $f10, $f4, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8003A0B8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A0BC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003A0C0: sub.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003A0C4: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003A0C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8003A0CC: jal         0x80022D30
    // 0x8003A0D0: nop

    obj_taj_create_balloon(rdram, ctx);
        goto after_49;
    // 0x8003A0D0: nop

    after_49:
    // 0x8003A0D4: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
L_8003A0D8:
    // 0x8003A0D8: sw          $t2, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r10;
    // 0x8003A0DC: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A0E0: jal         0x80001D04
    // 0x8003A0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_50;
    // 0x8003A0E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_50:
    // 0x8003A0E8: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A0EC: nop

    // 0x8003A0F0: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A0F4: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A0F8: jal         0x80004B40
    // 0x8003A0FC: nop

    racer_sound_init(rdram, ctx);
        goto after_51;
    // 0x8003A0FC: nop

    after_51:
    // 0x8003A100: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8003A104: b           L_8003AB40
    // 0x8003A108: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
        goto L_8003AB40;
    // 0x8003A108: sw          $v0, 0x118($t3)
    MEM_W(0X118, ctx->r11) = ctx->r2;
L_8003A10C:
    // 0x8003A10C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8003A110: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A114: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A118: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A11C: swc1        $f10, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f10.u32l;
    // 0x8003A120: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A124: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A128: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A12C: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A130: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A134: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8003A138: add.d       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f4.d + ctx->f6.d;
    // 0x8003A13C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A140: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A144: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A148: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    // 0x8003A14C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A150: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A154: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A158: addiu       $a0, $zero, 0x110
    ctx->r4 = ADD32(0, 0X110);
    // 0x8003A15C: bc1f        L_8003A170
    if (!c1cs) {
        // 0x8003A160: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8003A170;
    }
    // 0x8003A160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8003A164: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A168: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A16C: nop

L_8003A170:
    // 0x8003A170: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A174: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A178: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A17C: bc1f        L_8003A188
    if (!c1cs) {
        // 0x8003A180: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A188;
    }
    // 0x8003A180: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A188:
    // 0x8003A188: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A18C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A190: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A194: beq         $at, $zero, L_8003A1A4
    if (ctx->r1 == 0) {
        // 0x8003A198: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A1A4;
    }
    // 0x8003A198: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A19C: b           L_8003AB40
    // 0x8003A1A0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB40;
    // 0x8003A1A0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A1A4:
    // 0x8003A1A4: jal         0x80001D04
    // 0x8003A1A8: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_52;
    // 0x8003A1A8: sb          $t7, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r15;
    after_52:
    // 0x8003A1AC: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A1B0: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x8003A1B4: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x8003A1B8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8003A1BC: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A1C0: sw          $t8, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r24;
    // 0x8003A1C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003A1C8: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8003A1CC: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003A1D0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003A1D4: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A1D8: sub.s       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x8003A1DC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A1E0: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8003A1E4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003A1E8: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003A1EC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A1F0: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8003A1F4: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x8003A1F8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A1FC: jal         0x80029F58
    // 0x8003A200: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_53;
    // 0x8003A200: nop

    after_53:
    // 0x8003A204: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8003A208: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A20C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A210: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A214: nop

    // 0x8003A218: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A21C: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
    // 0x8003A220: b           L_8003AB44
    // 0x8003A224: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A224: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A228:
    // 0x8003A228: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A22C: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A230: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A234: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A238: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A23C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A240: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A244: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x8003A248: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A24C: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A250: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A254: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A258: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A25C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003A260: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8003A264: nop

    // 0x8003A268: bc1f        L_8003A278
    if (!c1cs) {
        // 0x8003A26C: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A278;
    }
    // 0x8003A26C: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A270: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A274: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A278:
    // 0x8003A278: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A27C: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A280: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A284: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A288: beq         $at, $zero, L_8003A298
    if (ctx->r1 == 0) {
        // 0x8003A28C: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A298;
    }
    // 0x8003A28C: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A290: b           L_8003AB40
    // 0x8003A294: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB40;
    // 0x8003A294: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A298:
    // 0x8003A298: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A29C: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    // 0x8003A2A0: b           L_8003AB44
    // 0x8003A2A4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A2A4: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A2A8:
    // 0x8003A2A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003A2AC: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A2B0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8003A2B4: sb          $t8, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r24;
    // 0x8003A2B8: swc1        $f16, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f16.u32l;
    // 0x8003A2BC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A2C0: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2C4: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
    // 0x8003A2C8: add.d       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A2CC: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A2D0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A2D4: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8003A2D8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A2DC: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
    // 0x8003A2E0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A2E4: swc1        $f16, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f16.u32l;
    // 0x8003A2E8: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A2EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A2F0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A2F4: nop

    // 0x8003A2F8: bc1f        L_8003A310
    if (!c1cs) {
        // 0x8003A2FC: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A310;
    }
    // 0x8003A2FC: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A300: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A304: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A308: nop

    // 0x8003A30C: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A310:
    // 0x8003A310: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x8003A314: sll         $t9, $a2, 3
    ctx->r25 = S32(ctx->r6 << 3);
    // 0x8003A318: bc1f        L_8003A324
    if (!c1cs) {
        // 0x8003A31C: or          $a2, $t9, $zero
        ctx->r6 = ctx->r25 | 0;
            goto L_8003A324;
    }
    // 0x8003A31C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8003A320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A324:
    // 0x8003A324: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A328: nop

    // 0x8003A32C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A330: beq         $at, $zero, L_8003A340
    if (ctx->r1 == 0) {
        // 0x8003A334: subu        $t0, $v0, $a2
        ctx->r8 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A340;
    }
    // 0x8003A334: subu        $t0, $v0, $a2
    ctx->r8 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A338: b           L_8003AB40
    // 0x8003A33C: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
        goto L_8003AB40;
    // 0x8003A33C: sb          $t0, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r8;
L_8003A340:
    // 0x8003A340: lw          $v0, 0x70($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X70);
    // 0x8003A344: nop

    // 0x8003A348: lb          $a0, 0x3($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X3);
    // 0x8003A34C: lb          $a1, 0x1D6($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1D6);
    // 0x8003A350: jal         0x80004B40
    // 0x8003A354: nop

    racer_sound_init(rdram, ctx);
        goto after_54;
    // 0x8003A354: nop

    after_54:
    // 0x8003A358: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8003A35C: addiu       $t4, $zero, 0xB4
    ctx->r12 = ADD32(0, 0XB4);
    // 0x8003A360: sw          $v0, 0x118($t1)
    MEM_W(0X118, ctx->r9) = ctx->r2;
    // 0x8003A364: lh          $t2, 0x20($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X20);
    // 0x8003A368: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x8003A36C: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x8003A370: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x8003A374: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003A378: lh          $t3, 0x22($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X22);
    // 0x8003A37C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8003A380: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003A384: jal         0x80030E20
    // 0x8003A388: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    slowly_change_fog(rdram, ctx);
        goto after_55;
    // 0x8003A388: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_55:
    // 0x8003A38C: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8003A390: nop

    // 0x8003A394: lbu         $a0, 0xB3($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0XB3);
    // 0x8003A398: jal         0x80000BE0
    // 0x8003A39C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_56;
    // 0x8003A39C: nop

    after_56:
    // 0x8003A3A0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003A3A4: nop

    // 0x8003A3A8: lbu         $a0, 0x52($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X52);
    // 0x8003A3AC: jal         0x80000B34
    // 0x8003A3B0: nop

    music_play(rdram, ctx);
        goto after_57;
    // 0x8003A3B0: nop

    after_57:
    // 0x8003A3B4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8003A3B8: nop

    // 0x8003A3BC: lhu         $a0, 0x54($t7)
    ctx->r4 = MEM_HU(ctx->r15, 0X54);
    // 0x8003A3C0: jal         0x80001074
    // 0x8003A3C4: nop

    music_dynamic_set(rdram, ctx);
        goto after_58;
    // 0x8003A3C4: nop

    after_58:
    // 0x8003A3C8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8003A3CC: nop

    // 0x8003A3D0: lb          $a0, 0x1D6($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X1D6);
    // 0x8003A3D4: jal         0x80022920
    // 0x8003A3D8: nop

    init_racer_for_challenge(rdram, ctx);
        goto after_59;
    // 0x8003A3D8: nop

    after_59:
    // 0x8003A3DC: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A3E0: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A3E4: jal         0x80023460
    // 0x8003A3E8: nop

    find_furthest_telepoint(rdram, ctx);
        goto after_60;
    // 0x8003A3E8: nop

    after_60:
    // 0x8003A3EC: beq         $v0, $zero, L_8003A430
    if (ctx->r2 == 0) {
        // 0x8003A3F0: addiu       $t3, $zero, 0x1E
        ctx->r11 = ADD32(0, 0X1E);
            goto L_8003A430;
    }
    // 0x8003A3F0: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x8003A3F4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A3F8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A3FC: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8003A400: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A404: nop

    // 0x8003A408: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x8003A40C: lh          $t9, 0x2E($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A410: nop

    // 0x8003A414: sh          $t9, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r25;
    // 0x8003A418: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8003A41C: nop

    // 0x8003A420: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8003A424: nop

    // 0x8003A428: addu        $t2, $t1, $at
    ctx->r10 = ADD32(ctx->r9, ctx->r1);
    // 0x8003A42C: sh          $t2, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r10;
L_8003A430:
    // 0x8003A430: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003A434: b           L_8003AB44
    // 0x8003A438: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A438: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A43C:
    // 0x8003A43C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8003A440: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A444: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8003A448: sb          $t4, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r12;
    // 0x8003A44C: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x8003A450: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A454: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A458: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A45C: add.d       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A460: lui         $at, 0x429E
    ctx->r1 = S32(0X429E << 16);
    // 0x8003A464: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A468: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x8003A46C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003A470: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8003A474: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8003A478: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8003A47C: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A480: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003A484: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8003A488: addiu       $t7, $zero, 0x15
    ctx->r15 = ADD32(0, 0X15);
    // 0x8003A48C: bc1f        L_8003A4A4
    if (!c1cs) {
        // 0x8003A490: lw          $a2, 0xB4($sp)
        ctx->r6 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A4A4;
    }
    // 0x8003A490: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A494: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A498: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A49C: nop

    // 0x8003A4A0: lw          $a2, 0xB4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XB4);
L_8003A4A4:
    // 0x8003A4A4: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x8003A4A8: sll         $t5, $a2, 3
    ctx->r13 = S32(ctx->r6 << 3);
    // 0x8003A4AC: bc1f        L_8003A4B8
    if (!c1cs) {
        // 0x8003A4B0: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8003A4B8;
    }
    // 0x8003A4B0: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8003A4B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8003A4B8:
    // 0x8003A4B8: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A4BC: nop

    // 0x8003A4C0: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003A4C4: beq         $at, $zero, L_8003A4D4
    if (ctx->r1 == 0) {
        // 0x8003A4C8: subu        $t6, $v0, $a2
        ctx->r14 = SUB32(ctx->r2, ctx->r6);
            goto L_8003A4D4;
    }
    // 0x8003A4C8: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x8003A4CC: b           L_8003AB40
    // 0x8003A4D0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
        goto L_8003AB40;
    // 0x8003A4D0: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
L_8003A4D4:
    // 0x8003A4D4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A4D8: lwc1        $f14, 0x14($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A4DC: sb          $zero, 0x39($s0)
    MEM_B(0X39, ctx->r16) = 0;
    // 0x8003A4E0: jal         0x80023460
    // 0x8003A4E4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    find_furthest_telepoint(rdram, ctx);
        goto after_61;
    // 0x8003A4E4: sw          $t7, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r15;
    after_61:
    // 0x8003A4E8: beq         $v0, $zero, L_8003A52C
    if (ctx->r2 == 0) {
        // 0x8003A4EC: nop
    
            goto L_8003A52C;
    }
    // 0x8003A4EC: nop

    // 0x8003A4F0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A4F4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A4F8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8003A4FC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A500: nop

    // 0x8003A504: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8003A508: lh          $t8, 0x2E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2E);
    // 0x8003A50C: nop

    // 0x8003A510: sh          $t8, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r24;
    // 0x8003A514: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x8003A518: nop

    // 0x8003A51C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x8003A520: nop

    // 0x8003A524: addu        $t1, $t0, $at
    ctx->r9 = ADD32(ctx->r8, ctx->r1);
    // 0x8003A528: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_8003A52C:
    // 0x8003A52C: b           L_8003AB44
    // 0x8003A530: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A530: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A534:
    // 0x8003A534: sb          $a3, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r7;
    // 0x8003A538: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A53C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A540: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8003A544: add.d       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f0.d + ctx->f0.d;
    // 0x8003A548: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003A54C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A550: sub.d       $f16, $f18, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f16.d = ctx->f18.d - ctx->f6.d;
    // 0x8003A554: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003A558: cvt.s.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f8.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A55C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8003A560: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x8003A564: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A568: nop

    // 0x8003A56C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8003A570: nop

    // 0x8003A574: bc1f        L_8003A584
    if (!c1cs) {
        // 0x8003A578: lw          $v1, 0xB4($sp)
        ctx->r3 = MEM_W(ctx->r29, 0XB4);
            goto L_8003A584;
    }
    // 0x8003A578: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A57C: swc1        $f2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f2.u32l;
    // 0x8003A580: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
L_8003A584:
    // 0x8003A584: lbu         $v0, 0x39($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X39);
    // 0x8003A588: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x8003A58C: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A590: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003A594: beq         $at, $zero, L_8003A5A4
    if (ctx->r1 == 0) {
        // 0x8003A598: addu        $t5, $v0, $t2
        ctx->r13 = ADD32(ctx->r2, ctx->r10);
            goto L_8003A5A4;
    }
    // 0x8003A598: addu        $t5, $v0, $t2
    ctx->r13 = ADD32(ctx->r2, ctx->r10);
    // 0x8003A59C: b           L_8003AB40
    // 0x8003A5A0: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
        goto L_8003AB40;
    // 0x8003A5A0: sb          $t5, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r13;
L_8003A5A4:
    // 0x8003A5A4: sb          $t6, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r14;
    // 0x8003A5A8: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003A5AC: b           L_8003AB44
    // 0x8003A5B0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
        goto L_8003AB44;
    // 0x8003A5B0: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003A5B4:
    // 0x8003A5B4: lw          $t7, 0x4C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4C);
    // 0x8003A5B8: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x8003A5BC: sh          $zero, 0x14($t7)
    MEM_H(0X14, ctx->r15) = 0;
    // 0x8003A5C0: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003A5C4: sb          $t8, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r24;
    // 0x8003A5C8: sb          $t9, 0x39($s0)
    MEM_B(0X39, ctx->r16) = ctx->r25;
    // 0x8003A5CC: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A5D0: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8003A5D4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8003A5D8: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A5DC: add.d       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f18.d + ctx->f16.d;
    // 0x8003A5E0: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A5E4: b           L_8003AB40
    // 0x8003A5E8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
        goto L_8003AB40;
    // 0x8003A5E8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_8003A5EC:
    // 0x8003A5EC: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003A5F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003A5F4: lbu         $t0, 0xD($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A5F8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A5FC: bne         $t0, $at, L_8003A66C
    if (ctx->r8 != ctx->r1) {
        // 0x8003A600: swc1        $f4, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
            goto L_8003A66C;
    }
    // 0x8003A600: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8003A604: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A608: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A60C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003A610: jal         0x8001C558
    // 0x8003A614: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_62;
    // 0x8003A614: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_62:
    // 0x8003A618: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A61C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003A620: beq         $a0, $at, L_8003A820
    if (ctx->r4 == ctx->r1) {
        // 0x8003A624: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_8003A820;
    }
    // 0x8003A624: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x8003A628: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003A62C: jal         0x8001CC7C
    // 0x8003A630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_63;
    // 0x8003A630: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_63:
    // 0x8003A634: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A638: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x8003A63C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A640: jal         0x8001CC7C
    // 0x8003A644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_64;
    // 0x8003A644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_64:
    // 0x8003A648: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x8003A64C: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x8003A650: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003A654: jal         0x8001CC7C
    // 0x8003A658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_65;
    // 0x8003A658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_65:
    // 0x8003A65C: lbu         $t1, 0xD($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0XD);
    // 0x8003A660: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x8003A664: b           L_8003A820
    // 0x8003A668: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
        goto L_8003A820;
    // 0x8003A668: sb          $t1, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r9;
L_8003A66C:
    // 0x8003A66C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x8003A670: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003A674: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A678: nop

    // 0x8003A67C: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x8003A680: nop

    // 0x8003A684: bc1f        L_8003A6C8
    if (!c1cs) {
        // 0x8003A688: nop
    
            goto L_8003A6C8;
    }
    // 0x8003A688: nop

    // 0x8003A68C: lh          $t2, 0x1C($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A690: lw          $t3, 0x90($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X90);
    // 0x8003A694: bne         $t2, $zero, L_8003A6C8
    if (ctx->r10 != 0) {
        // 0x8003A698: nop
    
            goto L_8003A6C8;
    }
    // 0x8003A698: nop

    // 0x8003A69C: beq         $t3, $zero, L_8003A6C8
    if (ctx->r11 == 0) {
        // 0x8003A6A0: addiu       $t4, $zero, 0xF0
        ctx->r12 = ADD32(0, 0XF0);
            goto L_8003A6C8;
    }
    // 0x8003A6A0: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x8003A6A4: sh          $t4, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r12;
    // 0x8003A6A8: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8003A6AC: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8003A6B0: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A6B4: div.s       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8003A6B8: jal         0x80070990
    // 0x8003A6BC: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    arctan2_f(rdram, ctx);
        goto after_66;
    // 0x8003A6BC: div.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    after_66:
    // 0x8003A6C0: addiu       $t5, $v0, 0x4000
    ctx->r13 = ADD32(ctx->r2, 0X4000);
    // 0x8003A6C4: sh          $t5, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r13;
L_8003A6C8:
    // 0x8003A6C8: lh          $v0, 0x1C($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A6CC: lw          $t6, 0xB4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A6D0: blez        $v0, L_8003A6E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003A6D4: subu        $t7, $v0, $t6
        ctx->r15 = SUB32(ctx->r2, ctx->r14);
            goto L_8003A6E0;
    }
    // 0x8003A6D4: subu        $t7, $v0, $t6
    ctx->r15 = SUB32(ctx->r2, ctx->r14);
    // 0x8003A6D8: b           L_8003A6E4
    // 0x8003A6DC: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
        goto L_8003A6E4;
    // 0x8003A6DC: sh          $t7, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r15;
L_8003A6E0:
    // 0x8003A6E0: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
L_8003A6E4:
    // 0x8003A6E4: lh          $t8, 0x1C($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1C);
    // 0x8003A6E8: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A6EC: slti        $at, $t8, 0x78
    ctx->r1 = SIGNED(ctx->r24) < 0X78 ? 1 : 0;
    // 0x8003A6F0: beq         $at, $zero, L_8003A720
    if (ctx->r1 == 0) {
        // 0x8003A6F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8003A720;
    }
    // 0x8003A6F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8003A6F8: lw          $a2, 0xAC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XAC);
    // 0x8003A6FC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8003A700: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8003A704: jal         0x8001C6F8
    // 0x8003A708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_67;
    // 0x8003A708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_67:
    // 0x8003A70C: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A710: nop

    // 0x8003A714: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8003A718: b           L_8003A820
    // 0x8003A71C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
        goto L_8003A820;
    // 0x8003A71C: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_8003A720:
    // 0x8003A720: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8003A724: lh          $t9, 0x1E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1E);
    // 0x8003A728: andi        $t0, $a1, 0xFFFF
    ctx->r8 = ctx->r5 & 0XFFFF;
    // 0x8003A72C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003A730: subu        $a2, $t9, $t0
    ctx->r6 = SUB32(ctx->r25, ctx->r8);
    // 0x8003A734: slt         $at, $a2, $at
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8003A738: bne         $at, $zero, L_8003A748
    if (ctx->r1 != 0) {
        // 0x8003A73C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8003A748;
    }
    // 0x8003A73C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8003A740: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8003A744: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A748:
    // 0x8003A748: slti        $at, $a2, -0x8000
    ctx->r1 = SIGNED(ctx->r6) < -0X8000 ? 1 : 0;
    // 0x8003A74C: beq         $at, $zero, L_8003A758
    if (ctx->r1 == 0) {
        // 0x8003A750: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8003A758;
    }
    // 0x8003A750: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8003A754: addu        $a2, $a2, $at
    ctx->r6 = ADD32(ctx->r6, ctx->r1);
L_8003A758:
    // 0x8003A758: multu       $a2, $t1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003A75C: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A760: mflo        $t2
    ctx->r10 = lo;
    // 0x8003A764: sra         $t3, $t2, 4
    ctx->r11 = S32(SIGNED(ctx->r10) >> 4);
    // 0x8003A768: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x8003A76C: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x8003A770: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A774: nop

    // 0x8003A778: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A77C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x8003A780: jal         0x80070A04
    // 0x8003A784: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_68;
    // 0x8003A784: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_68:
    // 0x8003A788: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8003A78C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003A790: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8003A794: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x8003A798: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x8003A79C: jal         0x80070A38
    // 0x8003A7A0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_69;
    // 0x8003A7A0: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_69:
    // 0x8003A7A4: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8003A7A8: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8003A7AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A7B0: mul.s       $f16, $f12, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f18.fl);
    // 0x8003A7B4: lwc1        $f3, 0x66E0($at)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r1, 0X66E0);
    // 0x8003A7B8: lwc1        $f2, 0x66E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X66E4);
    // 0x8003A7BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003A7C0: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A7C4: mul.d       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f2.d);
    // 0x8003A7C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8003A7CC: mul.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8003A7D0: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A7D4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003A7D8: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x8003A7DC: mul.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f2.d);
    // 0x8003A7E0: cvt.s.d     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f10.fl = CVT_S_D(ctx->f16.d);
    // 0x8003A7E4: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003A7E8: jal         0x80011570
    // 0x8003A7EC: nop

    move_object(rdram, ctx);
        goto after_70;
    // 0x8003A7EC: nop

    after_70:
    // 0x8003A7F0: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A7F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003A7F8: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8003A7FC: lwc1        $f7, 0x66E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X66E8);
    // 0x8003A800: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x8003A804: lwc1        $f6, 0x66EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X66EC);
    // 0x8003A808: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003A80C: mul.d       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003A810: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003A814: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x8003A818: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8003A81C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
L_8003A820:
    // 0x8003A820: jal         0x8001BAA8
    // 0x8003A824: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_71;
    // 0x8003A824: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_71:
    // 0x8003A828: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8003A82C: nop

    // 0x8003A830: beq         $t0, $zero, L_8003A9AC
    if (ctx->r8 == 0) {
        // 0x8003A834: nop
    
            goto L_8003A9AC;
    }
    // 0x8003A834: nop

    // 0x8003A838: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8003A83C: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A840: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A844: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003A848: sub.s       $f2, $f6, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x8003A84C: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003A850: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003A854: sub.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8003A858: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A85C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A860: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003A864: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A868: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003A86C: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003A870: jal         0x800CA030
    // 0x8003A874: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_72;
    // 0x8003A874: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_72:
    // 0x8003A878: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A87C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8003A880: nop

    // 0x8003A884: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8003A888: nop

    // 0x8003A88C: bc1f        L_8003A994
    if (!c1cs) {
        // 0x8003A890: nop
    
            goto L_8003A994;
    }
    // 0x8003A890: nop

    // 0x8003A894: sub.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8003A898: jal         0x80069FBC
    // 0x8003A89C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    cam_get_cameras(rdram, ctx);
        goto after_73;
    // 0x8003A89C: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    after_73:
    // 0x8003A8A0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003A8A4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003A8A8: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003A8AC: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003A8B0: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x8003A8B4: sub.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8003A8B8: jal         0x800090C0
    // 0x8003A8BC: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_74;
    // 0x8003A8BC: sub.s       $f14, $f6, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f16.fl;
    after_74:
    // 0x8003A8C0: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8003A8C4: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8003A8C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003A8CC: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8003A8D0: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8003A8D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003A8D8: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8003A8DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A8E0: div.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8003A8E4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8003A8E8: nop

    // 0x8003A8EC: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8003A8F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003A8F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003A8F8: nop

    // 0x8003A8FC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003A900: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8003A904: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8003A908: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    // 0x8003A90C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x8003A910: jal         0x80001268
    // 0x8003A914: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    music_channel_fade_set(rdram, ctx);
        goto after_75;
    // 0x8003A914: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_75:
    // 0x8003A918: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A91C: jal         0x80001268
    // 0x8003A920: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_fade_set(rdram, ctx);
        goto after_76;
    // 0x8003A920: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_76:
    // 0x8003A924: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A928: jal         0x80001268
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_fade_set(rdram, ctx);
        goto after_77;
    // 0x8003A92C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_77:
    // 0x8003A930: lbu         $a1, 0x57($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X57);
    // 0x8003A934: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8003A938: jal         0x800011A8
    // 0x8003A93C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    music_channel_pan_set(rdram, ctx);
        goto after_78;
    // 0x8003A93C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_78:
    // 0x8003A940: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A944: jal         0x800011A8
    // 0x8003A948: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_pan_set(rdram, ctx);
        goto after_79;
    // 0x8003A948: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_79:
    // 0x8003A94C: lbu         $a1, 0x3F($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X3F);
    // 0x8003A950: jal         0x800011A8
    // 0x8003A954: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_pan_set(rdram, ctx);
        goto after_80;
    // 0x8003A954: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_80:
    // 0x8003A958: jal         0x80001170
    // 0x8003A95C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_on(rdram, ctx);
        goto after_81;
    // 0x8003A95C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_81:
    // 0x8003A960: jal         0x80001170
    // 0x8003A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_on(rdram, ctx);
        goto after_82;
    // 0x8003A964: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_82:
    // 0x8003A968: jal         0x80001170
    // 0x8003A96C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_on(rdram, ctx);
        goto after_83;
    // 0x8003A96C: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_83:
    // 0x8003A970: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x8003A974: addiu       $t3, $zero, 0x7F
    ctx->r11 = ADD32(0, 0X7F);
    // 0x8003A978: subu        $a1, $t3, $t2
    ctx->r5 = SUB32(ctx->r11, ctx->r10);
    // 0x8003A97C: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x8003A980: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x8003A984: jal         0x80001268
    // 0x8003A988: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    music_channel_fade_set(rdram, ctx);
        goto after_84;
    // 0x8003A988: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_84:
    // 0x8003A98C: b           L_8003A9B0
    // 0x8003A990: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
        goto L_8003A9B0;
    // 0x8003A990: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A994:
    // 0x8003A994: jal         0x80001114
    // 0x8003A998: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    music_channel_off(rdram, ctx);
        goto after_85;
    // 0x8003A998: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_85:
    // 0x8003A99C: jal         0x80001114
    // 0x8003A9A0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    music_channel_off(rdram, ctx);
        goto after_86;
    // 0x8003A9A0: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_86:
    // 0x8003A9A4: jal         0x80001114
    // 0x8003A9A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    music_channel_off(rdram, ctx);
        goto after_87;
    // 0x8003A9A8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_87:
L_8003A9AC:
    // 0x8003A9AC: lb          $v1, 0x36($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X36);
L_8003A9B0:
    // 0x8003A9B0: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003A9B4: beq         $v1, $zero, L_8003A9CC
    if (ctx->r3 == 0) {
        // 0x8003A9B8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8003A9CC;
    }
    // 0x8003A9B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003A9BC: beq         $v1, $at, L_8003AAA4
    if (ctx->r3 == ctx->r1) {
        // 0x8003A9C0: nop
    
            goto L_8003AAA4;
    }
    // 0x8003A9C0: nop

    // 0x8003A9C4: b           L_8003AB30
    // 0x8003A9C8: nop

        goto L_8003AB30;
    // 0x8003A9C8: nop

L_8003A9CC:
    // 0x8003A9CC: lhu         $v1, 0x34($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A9D0: sll         $t5, $v0, 7
    ctx->r13 = S32(ctx->r2 << 7);
    // 0x8003A9D4: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003A9D8: beq         $at, $zero, L_8003AA10
    if (ctx->r1 == 0) {
        // 0x8003A9DC: addiu       $a0, $zero, 0xE
        ctx->r4 = ADD32(0, 0XE);
            goto L_8003AA10;
    }
    // 0x8003A9DC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9E0: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x8003A9E4: sh          $t6, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r14;
    // 0x8003A9E8: jal         0x80001170
    // 0x8003A9EC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_88;
    // 0x8003A9EC: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_88:
    // 0x8003A9F0: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003A9F4: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003A9F8: sra         $t7, $a1, 8
    ctx->r15 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003A9FC: jal         0x80001268
    // 0x8003AA00: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_89;
    // 0x8003AA00: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    after_89:
    // 0x8003AA04: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8003AA08: b           L_8003AA3C
    // 0x8003AA0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8003AA3C;
    // 0x8003AA0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8003AA10:
    // 0x8003AA10: jal         0x80001114
    // 0x8003AA14: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    music_channel_off(rdram, ctx);
        goto after_90;
    // 0x8003AA14: sh          $zero, 0x34($s1)
    MEM_H(0X34, ctx->r17) = 0;
    after_90:
    // 0x8003AA18: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x8003AA1C: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003AA20: bne         $v1, $zero, L_8003AA3C
    if (ctx->r3 != 0) {
        // 0x8003AA24: nop
    
            goto L_8003AA3C;
    }
    // 0x8003AA24: nop

    // 0x8003AA28: jal         0x8006FB8C
    // 0x8003AA2C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_91;
    // 0x8003AA2C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_91:
    // 0x8003AA30: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x8003AA34: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AA38: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003AA3C:
    // 0x8003AA3C: beq         $v1, $zero, L_8003AA98
    if (ctx->r3 == 0) {
        // 0x8003AA40: nop
    
            goto L_8003AA98;
    }
    // 0x8003AA40: nop

    // 0x8003AA44: jal         0x8000105C
    // 0x8003AA48: nop

    music_channel_get_mask(rdram, ctx);
        goto after_92;
    // 0x8003AA48: nop

    after_92:
    // 0x8003AA4C: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AA50: and         $t9, $v0, $at
    ctx->r25 = ctx->r2 & ctx->r1;
    // 0x8003AA54: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AA58: bne         $t9, $at, L_8003AA98
    if (ctx->r25 != ctx->r1) {
        // 0x8003AA5C: nop
    
            goto L_8003AA98;
    }
    // 0x8003AA5C: nop

    // 0x8003AA60: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AA64: lw          $t1, 0xB4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AA68: lw          $t2, 0x30($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X30);
    // 0x8003AA6C: addu        $t3, $t0, $t1
    ctx->r11 = ADD32(ctx->r8, ctx->r9);
    // 0x8003AA70: slt         $at, $t2, $t3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8003AA74: beq         $at, $zero, L_8003AB30
    if (ctx->r1 == 0) {
        // 0x8003AA78: sw          $t3, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r11;
            goto L_8003AB30;
    }
    // 0x8003AA78: sw          $t3, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r11;
    // 0x8003AA7C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003AA80: sb          $t5, 0x36($s1)
    MEM_B(0X36, ctx->r17) = ctx->r13;
    // 0x8003AA84: addiu       $a0, $zero, 0x258
    ctx->r4 = ADD32(0, 0X258);
    // 0x8003AA88: jal         0x8006FB8C
    // 0x8003AA8C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    rand_range(rdram, ctx);
        goto after_93;
    // 0x8003AA8C: addiu       $a1, $zero, 0x384
    ctx->r5 = ADD32(0, 0X384);
    after_93:
    // 0x8003AA90: b           L_8003AB30
    // 0x8003AA94: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
        goto L_8003AB30;
    // 0x8003AA94: sw          $v0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r2;
L_8003AA98:
    // 0x8003AA98: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AA9C: b           L_8003AB30
    // 0x8003AAA0: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
        goto L_8003AB30;
    // 0x8003AAA0: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AAA4:
    // 0x8003AAA4: jal         0x8000105C
    // 0x8003AAA8: nop

    music_channel_get_mask(rdram, ctx);
        goto after_94;
    // 0x8003AAA8: nop

    after_94:
    // 0x8003AAAC: addiu       $at, $zero, -0x4001
    ctx->r1 = ADD32(0, -0X4001);
    // 0x8003AAB0: and         $t6, $v0, $at
    ctx->r14 = ctx->r2 & ctx->r1;
    // 0x8003AAB4: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8003AAB8: bne         $t6, $at, L_8003AB24
    if (ctx->r14 != ctx->r1) {
        // 0x8003AABC: nop
    
            goto L_8003AB24;
    }
    // 0x8003AABC: nop

    // 0x8003AAC0: lw          $v0, 0xB4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AAC4: lhu         $t7, 0x34($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AAC8: sll         $t8, $v0, 7
    ctx->r24 = S32(ctx->r2 << 7);
    // 0x8003AACC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8003AAD0: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8003AAD4: slti        $at, $t0, 0x7F01
    ctx->r1 = SIGNED(ctx->r8) < 0X7F01 ? 1 : 0;
    // 0x8003AAD8: bne         $at, $zero, L_8003AAE8
    if (ctx->r1 != 0) {
        // 0x8003AADC: sh          $t9, 0x34($s1)
        MEM_H(0X34, ctx->r17) = ctx->r25;
            goto L_8003AAE8;
    }
    // 0x8003AADC: sh          $t9, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r25;
    // 0x8003AAE0: addiu       $t1, $zero, 0x7F00
    ctx->r9 = ADD32(0, 0X7F00);
    // 0x8003AAE4: sh          $t1, 0x34($s1)
    MEM_H(0X34, ctx->r17) = ctx->r9;
L_8003AAE8:
    // 0x8003AAE8: lw          $t3, 0x2C($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X2C);
    // 0x8003AAEC: nop

    // 0x8003AAF0: subu        $t2, $t3, $v0
    ctx->r10 = SUB32(ctx->r11, ctx->r2);
    // 0x8003AAF4: bgez        $t2, L_8003AB00
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8003AAF8: sw          $t2, 0x2C($s1)
        MEM_W(0X2C, ctx->r17) = ctx->r10;
            goto L_8003AB00;
    }
    // 0x8003AAF8: sw          $t2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->r10;
    // 0x8003AAFC: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
L_8003AB00:
    // 0x8003AB00: jal         0x80001170
    // 0x8003AB04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    music_channel_on(rdram, ctx);
        goto after_95;
    // 0x8003AB04: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_95:
    // 0x8003AB08: lhu         $a1, 0x34($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0X34);
    // 0x8003AB0C: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8003AB10: sra         $t5, $a1, 8
    ctx->r13 = S32(SIGNED(ctx->r5) >> 8);
    // 0x8003AB14: jal         0x80001268
    // 0x8003AB18: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_96;
    // 0x8003AB18: andi        $a1, $t5, 0xFF
    ctx->r5 = ctx->r13 & 0XFF;
    after_96:
    // 0x8003AB1C: b           L_8003AB30
    // 0x8003AB20: nop

        goto L_8003AB30;
    // 0x8003AB20: nop

L_8003AB24:
    // 0x8003AB24: sb          $zero, 0x36($s1)
    MEM_B(0X36, ctx->r17) = 0;
    // 0x8003AB28: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8003AB2C: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
L_8003AB30:
    // 0x8003AB30: jal         0x8000105C
    // 0x8003AB34: nop

    music_channel_get_mask(rdram, ctx);
        goto after_97;
    // 0x8003AB34: nop

    after_97:
    // 0x8003AB38: andi        $t7, $v0, 0xBFFF
    ctx->r15 = ctx->r2 & 0XBFFF;
    // 0x8003AB3C: sh          $t7, 0x28($s1)
    MEM_H(0X28, ctx->r17) = ctx->r15;
L_8003AB40:
    // 0x8003AB40: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
L_8003AB44:
    // 0x8003AB44: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x8003AB48: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003AB4C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AB50: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8003AB54: jal         0x8002B134
    // 0x8003AB58: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    func_8002B0F4(rdram, ctx);
        goto after_98;
    // 0x8003AB58: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_98:
    // 0x8003AB5C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x8003AB60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003AB64: beq         $v0, $zero, L_8003ABD8
    if (ctx->r2 == 0) {
        // 0x8003AB68: addiu       $a2, $v0, -0x1
        ctx->r6 = ADD32(ctx->r2, -0X1);
            goto L_8003ABD8;
    }
    // 0x8003AB68: addiu       $a2, $v0, -0x1
    ctx->r6 = ADD32(ctx->r2, -0X1);
    // 0x8003AB6C: bltz        $a2, L_8003ABD8
    if (SIGNED(ctx->r6) < 0) {
        // 0x8003AB70: sll         $a0, $a2, 2
        ctx->r4 = S32(ctx->r6 << 2);
            goto L_8003ABD8;
    }
    // 0x8003AB70: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    // 0x8003AB74: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8003AB78: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x8003AB7C: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003AB80:
    // 0x8003AB80: nop

    // 0x8003AB84: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x8003AB88: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x8003AB8C: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x8003AB90: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x8003AB94: nop

    // 0x8003AB98: beq         $a2, $v1, L_8003ABD0
    if (ctx->r6 == ctx->r3) {
        // 0x8003AB9C: nop
    
            goto L_8003ABD0;
    }
    // 0x8003AB9C: nop

    // 0x8003ABA0: beq         $a1, $v1, L_8003ABD0
    if (ctx->r5 == ctx->r3) {
        // 0x8003ABA4: nop
    
            goto L_8003ABD0;
    }
    // 0x8003ABA4: nop

    // 0x8003ABA8: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8003ABAC: nop

    // 0x8003ABB0: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8003ABB4: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8003ABB8: nop

    // 0x8003ABBC: bc1f        L_8003ABD0
    if (!c1cs) {
        // 0x8003ABC0: nop
    
            goto L_8003ABD0;
    }
    // 0x8003ABC0: nop

    // 0x8003ABC4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003ABC8: nop

    // 0x8003ABCC: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
L_8003ABD0:
    // 0x8003ABD0: bgez        $a0, L_8003AB80
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003ABD4: lw          $t8, 0x94($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X94);
            goto L_8003AB80;
    }
    // 0x8003ABD4: lw          $t8, 0x94($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X94);
L_8003ABD8:
    // 0x8003ABD8: lw          $t0, 0x78($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X78);
    // 0x8003ABDC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x8003ABE0: beq         $t0, $zero, L_8003ABF4
    if (ctx->r8 == 0) {
        // 0x8003ABE4: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_8003ABF4;
    }
    // 0x8003ABE4: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x8003ABE8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003ABEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ABF0: swc1        $f4, -0x25B0($at)
    MEM_W(-0X25B0, ctx->r1) = ctx->f4.u32l;
L_8003ABF4:
    // 0x8003ABF4: lb          $t1, 0x6B($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X6B);
    // 0x8003ABF8: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    // 0x8003ABFC: beq         $t1, $zero, L_8003AC24
    if (ctx->r9 == 0) {
        // 0x8003AC00: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8003AC24;
    }
    // 0x8003AC00: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003AC04: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003AC08: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003AC0C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003AC10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AC14: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003AC18: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8003AC1C: jal         0x8003FC84
    // 0x8003AC20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_99;
    // 0x8003AC20: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_99:
L_8003AC24:
    // 0x8003AC24: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8003AC28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003AC2C: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x8003AC30: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x8003AC34: nop

    // 0x8003AC38: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8003AC3C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003AC40: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003AC44: nop

    // 0x8003AC48: cvt.w.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_D(ctx->f10.d);
    // 0x8003AC4C: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8003AC50: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x8003AC54: jal         0x80061E4C
    // 0x8003AC58: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    func_80061C0C(rdram, ctx);
        goto after_100;
    // 0x8003AC58: sh          $t2, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r10;
    after_100:
    // 0x8003AC5C: lw          $a1, 0xB4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB4);
    // 0x8003AC60: jal         0x800B019C
    // 0x8003AC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_101;
    // 0x8003AC64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_101:
    // 0x8003AC68: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003AC6C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8003AC70: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8003AC74: jr          $ra
    // 0x8003AC78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8003AC78: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void func_8002FD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FDB4: lw          $a0, 0x10($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X10);
    // 0x8002FDB8: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8002FDBC: swc1        $f14, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f14.u32l;
    // 0x8002FDC0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8002FDC4: blez        $a0, L_8002FFA0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8002FDC8: sw          $a3, 0xC($sp)
        MEM_W(0XC, ctx->r29) = ctx->r7;
            goto L_8002FFA0;
    }
    // 0x8002FDC8: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8002FDCC: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x8002FDD0: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002FDD4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002FDD8: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002FDDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002FDE0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8002FDE4: bne         $at, $zero, L_8002FF50
    if (ctx->r1 != 0) {
        // 0x8002FDE8: mov.s       $f14, $f12
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
            goto L_8002FF50;
    }
    // 0x8002FDE8: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8002FDEC: addiu       $a1, $a0, -0x1
    ctx->r5 = ADD32(ctx->r4, -0X1);
    // 0x8002FDF0: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x8002FDF4: beq         $t6, $zero, L_8002FE6C
    if (ctx->r14 == 0) {
        // 0x8002FDF8: sll         $t8, $a0, 4
        ctx->r24 = S32(ctx->r4 << 4);
            goto L_8002FE6C;
    }
    // 0x8002FDF8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002FDFC: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
    // 0x8002FE00: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002FE04: nop

    // 0x8002FE08: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FE0C: nop

    // 0x8002FE10: bc1f        L_8002FE20
    if (!c1cs) {
        // 0x8002FE14: nop
    
            goto L_8002FE20;
    }
    // 0x8002FE14: nop

    // 0x8002FE18: b           L_8002FE34
    // 0x8002FE1C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FE34;
    // 0x8002FE1C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FE20:
    // 0x8002FE20: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FE24: nop

    // 0x8002FE28: bc1f        L_8002FE34
    if (!c1cs) {
        // 0x8002FE2C: nop
    
            goto L_8002FE34;
    }
    // 0x8002FE2C: nop

    // 0x8002FE30: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FE34:
    // 0x8002FE34: lwc1        $f16, 0x8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8002FE38: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8002FE3C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FE40: nop

    // 0x8002FE44: bc1f        L_8002FE54
    if (!c1cs) {
        // 0x8002FE48: nop
    
            goto L_8002FE54;
    }
    // 0x8002FE48: nop

    // 0x8002FE4C: b           L_8002FE68
    // 0x8002FE50: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FE68;
    // 0x8002FE50: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FE54:
    // 0x8002FE54: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FE58: nop

    // 0x8002FE5C: bc1f        L_8002FE68
    if (!c1cs) {
        // 0x8002FE60: nop
    
            goto L_8002FE68;
    }
    // 0x8002FE60: nop

    // 0x8002FE64: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FE68:
    // 0x8002FE68: beq         $v1, $a0, L_8002FF50
    if (ctx->r3 == ctx->r4) {
        // 0x8002FE6C: sll         $t7, $v1, 4
        ctx->r15 = S32(ctx->r3 << 4);
            goto L_8002FF50;
    }
L_8002FE6C:
    // 0x8002FE6C: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x8002FE70: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    // 0x8002FE74: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
L_8002FE78:
    // 0x8002FE78: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002FE7C: nop

    // 0x8002FE80: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FE84: nop

    // 0x8002FE88: bc1f        L_8002FE98
    if (!c1cs) {
        // 0x8002FE8C: nop
    
            goto L_8002FE98;
    }
    // 0x8002FE8C: nop

    // 0x8002FE90: b           L_8002FEAC
    // 0x8002FE94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FEAC;
    // 0x8002FE94: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FE98:
    // 0x8002FE98: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FE9C: nop

    // 0x8002FEA0: bc1f        L_8002FEAC
    if (!c1cs) {
        // 0x8002FEA4: nop
    
            goto L_8002FEAC;
    }
    // 0x8002FEA4: nop

    // 0x8002FEA8: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FEAC:
    // 0x8002FEAC: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8002FEB0: nop

    // 0x8002FEB4: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FEB8: nop

    // 0x8002FEBC: bc1f        L_8002FECC
    if (!c1cs) {
        // 0x8002FEC0: nop
    
            goto L_8002FECC;
    }
    // 0x8002FEC0: nop

    // 0x8002FEC4: b           L_8002FEE0
    // 0x8002FEC8: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FEE0;
    // 0x8002FEC8: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FECC:
    // 0x8002FECC: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FED0: nop

    // 0x8002FED4: bc1f        L_8002FEE0
    if (!c1cs) {
        // 0x8002FED8: nop
    
            goto L_8002FEE0;
    }
    // 0x8002FED8: nop

    // 0x8002FEDC: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FEE0:
    // 0x8002FEE0: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8002FEE4: nop

    // 0x8002FEE8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8002FEEC: nop

    // 0x8002FEF0: bc1f        L_8002FF00
    if (!c1cs) {
        // 0x8002FEF4: nop
    
            goto L_8002FF00;
    }
    // 0x8002FEF4: nop

    // 0x8002FEF8: b           L_8002FF14
    // 0x8002FEFC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
        goto L_8002FF14;
    // 0x8002FEFC: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
L_8002FF00:
    // 0x8002FF00: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8002FF04: nop

    // 0x8002FF08: bc1f        L_8002FF14
    if (!c1cs) {
        // 0x8002FF0C: nop
    
            goto L_8002FF14;
    }
    // 0x8002FF0C: nop

    // 0x8002FF10: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
L_8002FF14:
    // 0x8002FF14: lwc1        $f16, 0x18($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8002FF18: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8002FF1C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x8002FF20: nop

    // 0x8002FF24: bc1f        L_8002FF34
    if (!c1cs) {
        // 0x8002FF28: nop
    
            goto L_8002FF34;
    }
    // 0x8002FF28: nop

    // 0x8002FF2C: b           L_8002FF48
    // 0x8002FF30: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
        goto L_8002FF48;
    // 0x8002FF30: mov.s       $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = ctx->f16.fl;
L_8002FF34:
    // 0x8002FF34: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8002FF38: nop

    // 0x8002FF3C: bc1f        L_8002FF48
    if (!c1cs) {
        // 0x8002FF40: nop
    
            goto L_8002FF48;
    }
    // 0x8002FF40: nop

    // 0x8002FF44: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
L_8002FF48:
    // 0x8002FF48: bne         $a1, $a2, L_8002FE78
    if (ctx->r5 != ctx->r6) {
        // 0x8002FF4C: nop
    
            goto L_8002FE78;
    }
    // 0x8002FF4C: nop

L_8002FF50:
    // 0x8002FF50: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002FF54: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8002FF58: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8002FF5C: nop

    // 0x8002FF60: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF68: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x8002FF6C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8002FF70: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF78: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8002FF7C: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002FF80: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF88: c.le.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl <= ctx->f10.fl;
    // 0x8002FF8C: nop

    // 0x8002FF90: bc1f        L_8002FFA4
    if (!c1cs) {
        // 0x8002FF94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8002FFA4;
    }
    // 0x8002FF94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002FF98: jr          $ra
    // 0x8002FF9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8002FF9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8002FFA0:
    // 0x8002FFA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002FFA4:
    // 0x8002FFA4: jr          $ra
    // 0x8002FFA8: nop

    return;
    // 0x8002FFA8: nop

;}
RECOMP_FUNC void menu_audio_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800850AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800850B0: addiu       $v1, $v1, 0x695C
    ctx->r3 = ADD32(ctx->r3, 0X695C);
    // 0x800850B4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800850B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800850BC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800850C0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800850C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800850C8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800850CC: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800850D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800850D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800850D8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800850DC: beq         $v0, $zero, L_80085104
    if (ctx->r2 == 0) {
        // 0x800850E0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80085104;
    }
    // 0x800850E0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800850E4: blez        $v0, L_800850FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800850E8: subu        $t2, $v0, $a0
        ctx->r10 = SUB32(ctx->r2, ctx->r4);
            goto L_800850FC;
    }
    // 0x800850E8: subu        $t2, $v0, $a0
    ctx->r10 = SUB32(ctx->r2, ctx->r4);
    // 0x800850EC: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x800850F0: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800850F4: b           L_80085104
    // 0x800850F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80085104;
    // 0x800850F8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800850FC:
    // 0x800850FC: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
    // 0x80085100: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80085104:
    // 0x80085104: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80085108: bne         $at, $zero, L_80085128
    if (ctx->r1 != 0) {
        // 0x8008510C: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80085128;
    }
    // 0x8008510C: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80085110: beq         $at, $zero, L_80085128
    if (ctx->r1 == 0) {
        // 0x80085114: nop
    
            goto L_80085128;
    }
    // 0x80085114: nop

    // 0x80085118: jal         0x80084C8C
    // 0x8008511C: nop

    func_80084854(rdram, ctx);
        goto after_0;
    // 0x8008511C: nop

    after_0:
    // 0x80085120: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80085124: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
L_80085128:
    // 0x80085128: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008512C: lw          $t3, 0x6964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6964);
    // 0x80085130: nop

    // 0x80085134: bne         $t3, $zero, L_800855E8
    if (ctx->r11 != 0) {
        // 0x80085138: nop
    
            goto L_800855E8;
    }
    // 0x80085138: nop

    // 0x8008513C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80085140: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80085144: bne         $t4, $zero, L_800855E8
    if (ctx->r12 != 0) {
        // 0x80085148: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800855E8;
    }
    // 0x80085148: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008514C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80085150: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085154: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80085158: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008515C: addiu       $a1, $a1, 0x6A04
    ctx->r5 = ADD32(ctx->r5, 0X6A04);
    // 0x80085160: addiu       $v1, $v1, 0x69FC
    ctx->r3 = ADD32(ctx->r3, 0X69FC);
    // 0x80085164: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80085168:
    // 0x80085168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008516C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80085170: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80085174: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x80085178: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8008517C: jal         0x8006A794
    // 0x80085180: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80085180: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80085184: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80085188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8008518C: or          $t6, $t5, $v0
    ctx->r14 = ctx->r13 | ctx->r2;
    // 0x80085190: jal         0x8006A7DC
    // 0x80085194: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    input_clamp_stick_x(rdram, ctx);
        goto after_2;
    // 0x80085194: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    after_2:
    // 0x80085198: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8008519C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800851A0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800851A4: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x800851A8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800851AC: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x800851B0: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x800851B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800851B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800851BC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800851C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800851C4: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800851C8: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800851CC: bne         $s0, $at, L_80085168
    if (ctx->r16 != ctx->r1) {
        // 0x800851D0: addu        $a3, $a3, $t8
        ctx->r7 = ADD32(ctx->r7, ctx->r24);
            goto L_80085168;
    }
    // 0x800851D0: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800851D4: bgez        $a2, L_800851F0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800851D8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800851F0;
    }
    // 0x800851D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800851DC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x800851E0: blez        $a2, L_80085204
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800851E4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80085204;
    }
    // 0x800851E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800851E8: b           L_80085200
    // 0x800851EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80085200;
    // 0x800851EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800851F0:
    // 0x800851F0: addiu       $a2, $a2, -0x18
    ctx->r6 = ADD32(ctx->r6, -0X18);
    // 0x800851F4: bgez        $a2, L_80085204
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800851F8: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_80085204;
    }
    // 0x800851F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800851FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80085200:
    // 0x80085200: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
L_80085204:
    // 0x80085204: sra         $t9, $a2, 2
    ctx->r25 = S32(SIGNED(ctx->r6) >> 2);
    // 0x80085208: andi        $t2, $a0, 0x9000
    ctx->r10 = ctx->r4 & 0X9000;
    // 0x8008520C: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x80085210: beq         $t2, $zero, L_80085234
    if (ctx->r10 == 0) {
        // 0x80085214: or          $a0, $t2, $zero
        ctx->r4 = ctx->r10 | 0;
            goto L_80085234;
    }
    // 0x80085214: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80085218: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008521C: lh          $t4, 0x7206($t4)
    ctx->r12 = MEM_H(ctx->r12, 0X7206);
    // 0x80085220: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x80085224: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80085228: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8008522C: beq         $t3, $t5, L_8008524C
    if (ctx->r11 == ctx->r13) {
        // 0x80085230: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_8008524C;
    }
    // 0x80085230: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_80085234:
    // 0x80085234: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80085238: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008523C: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x80085240: beq         $t7, $zero, L_80085288
    if (ctx->r15 == 0) {
        // 0x80085244: addiu       $v1, $v1, 0x6980
        ctx->r3 = ADD32(ctx->r3, 0X6980);
            goto L_80085288;
    }
    // 0x80085244: addiu       $v1, $v1, 0x6980
    ctx->r3 = ADD32(ctx->r3, 0X6980);
    // 0x80085248: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_8008524C:
    // 0x8008524C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80085250: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085254: sw          $t8, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r24;
    // 0x80085258: jal         0x800C06F8
    // 0x8008525C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008525C: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_3:
    // 0x80085260: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80085264: lw          $t9, 0x6978($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6978);
    // 0x80085268: nop

    // 0x8008526C: bltz        $t9, L_80085280
    if (SIGNED(ctx->r25) < 0) {
        // 0x80085270: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_80085280;
    }
    // 0x80085270: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80085274: jal         0x80000C98
    // 0x80085278: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x80085278: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x8008527C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_80085280:
    // 0x80085280: b           L_80085538
    // 0x80085284: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
        goto L_80085538;
    // 0x80085284: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
L_80085288:
    // 0x80085288: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008528C: lh          $v0, 0x7206($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X7206);
    // 0x80085290: bgez        $a3, L_800852C0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80085294: nop
    
            goto L_800852C0;
    }
    // 0x80085294: nop

    // 0x80085298: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8008529C: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x800852A0: addiu       $t3, $t4, -0x1
    ctx->r11 = ADD32(ctx->r12, -0X1);
    // 0x800852A4: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800852A8: beq         $at, $zero, L_800852C0
    if (ctx->r1 == 0) {
        // 0x800852AC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800852C0;
    }
    // 0x800852AC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800852B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852B4: sh          $t5, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = ctx->r13;
    // 0x800852B8: b           L_80085538
    // 0x800852BC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085538;
    // 0x800852BC: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_800852C0:
    // 0x800852C0: blez        $a3, L_800852E4
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800852C4: nop
    
            goto L_800852E4;
    }
    // 0x800852C4: nop

    // 0x800852C8: blez        $v0, L_800852E4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800852CC: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800852E4;
    }
    // 0x800852CC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800852D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800852D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800852D8: sh          $t7, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = ctx->r15;
    // 0x800852DC: b           L_80085538
    // 0x800852E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80085538;
    // 0x800852E0: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800852E4:
    // 0x800852E4: bne         $v0, $zero, L_8008536C
    if (ctx->r2 != 0) {
        // 0x800852E8: nop
    
            goto L_8008536C;
    }
    // 0x800852E8: nop

    // 0x800852EC: beq         $t0, $zero, L_8008536C
    if (ctx->r8 == 0) {
        // 0x800852F0: nop
    
            goto L_8008536C;
    }
    // 0x800852F0: nop

    // 0x800852F4: bgez        $t0, L_80085318
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800852F8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_80085318;
    }
    // 0x800852F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800852FC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80085300: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x80085304: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80085308: nop

    // 0x8008530C: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x80085310: b           L_8008532C
    // 0x80085314: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_8008532C;
    // 0x80085314: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80085318:
    // 0x80085318: addiu       $v0, $v0, 0x48
    ctx->r2 = ADD32(ctx->r2, 0X48);
    // 0x8008531C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80085320: nop

    // 0x80085324: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80085328: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8008532C:
    // 0x8008532C: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80085330: nop

    // 0x80085334: bgez        $a0, L_80085348
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80085338: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80085348;
    }
    // 0x80085338: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x8008533C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80085340: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80085344: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
L_80085348:
    // 0x80085348: bne         $at, $zero, L_80085358
    if (ctx->r1 != 0) {
        // 0x8008534C: nop
    
            goto L_80085358;
    }
    // 0x8008534C: nop

    // 0x80085350: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80085354: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80085358:
    // 0x80085358: jal         0x80065E10
    // 0x8008535C: nop

    set_stereo_pan_mode(rdram, ctx);
        goto after_5;
    // 0x8008535C: nop

    after_5:
    // 0x80085360: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80085364: b           L_80085538
    // 0x80085368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
        goto L_80085538;
    // 0x80085368: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
L_8008536C:
    // 0x8008536C: beq         $a2, $zero, L_8008548C
    if (ctx->r6 == 0) {
        // 0x80085370: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008548C;
    }
    // 0x80085370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085374: beq         $v0, $at, L_80085380
    if (ctx->r2 == ctx->r1) {
        // 0x80085378: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80085380;
    }
    // 0x80085378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008537C: bne         $v0, $at, L_8008548C
    if (ctx->r2 != ctx->r1) {
        // 0x80085380: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008548C;
    }
L_80085380:
    // 0x80085380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085384: bne         $v0, $at, L_800853D4
    if (ctx->r2 != ctx->r1) {
        // 0x80085388: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800853D4;
    }
    // 0x80085388: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008538C: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
    // 0x80085390: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80085394: nop

    // 0x80085398: addu        $v0, $t7, $a2
    ctx->r2 = ADD32(ctx->r15, ctx->r6);
    // 0x8008539C: bgez        $v0, L_800853B0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800853A0: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800853B0;
    }
    // 0x800853A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800853A4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800853A8: b           L_800853C4
    // 0x800853AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800853C4;
    // 0x800853AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800853B0:
    // 0x800853B0: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800853B4: bne         $at, $zero, L_800853C4
    if (ctx->r1 != 0) {
        // 0x800853B8: nop
    
            goto L_800853C4;
    }
    // 0x800853B8: nop

    // 0x800853BC: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x800853C0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800853C4:
    // 0x800853C4: jal         0x80003160
    // 0x800853C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sndp_set_global_volume(rdram, ctx);
        goto after_6;
    // 0x800853C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800853CC: b           L_80085538
    // 0x800853D0: nop

        goto L_80085538;
    // 0x800853D0: nop

L_800853D4:
    // 0x800853D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800853D8: bne         $v0, $at, L_80085538
    if (ctx->r2 != ctx->r1) {
        // 0x800853DC: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80085538;
    }
    // 0x800853DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800853E0: addiu       $v1, $v1, 0x44
    ctx->r3 = ADD32(ctx->r3, 0X44);
    // 0x800853E4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800853E8: nop

    // 0x800853EC: addu        $v0, $t2, $a2
    ctx->r2 = ADD32(ctx->r10, ctx->r6);
    // 0x800853F0: bgez        $v0, L_80085404
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800853F4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80085404;
    }
    // 0x800853F4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800853F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800853FC: b           L_80085418
    // 0x80085400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085418;
    // 0x80085400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80085404:
    // 0x80085404: slti        $at, $v0, 0x101
    ctx->r1 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x80085408: bne         $at, $zero, L_80085418
    if (ctx->r1 != 0) {
        // 0x8008540C: nop
    
            goto L_80085418;
    }
    // 0x8008540C: nop

    // 0x80085410: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x80085414: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80085418:
    // 0x80085418: jal         0x80001A3C
    // 0x8008541C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    music_volume_config_set(rdram, ctx);
        goto after_7;
    // 0x8008541C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80085420: jal         0x800015C8
    // 0x80085424: nop

    music_is_playing(rdram, ctx);
        goto after_8;
    // 0x80085424: nop

    after_8:
    // 0x80085428: bne         $v0, $zero, L_80085538
    if (ctx->r2 != 0) {
        // 0x8008542C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80085538;
    }
    // 0x8008542C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80085430: lw          $t5, 0x6978($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6978);
    // 0x80085434: nop

    // 0x80085438: bltz        $t5, L_80085464
    if (SIGNED(ctx->r13) < 0) {
        // 0x8008543C: nop
    
            goto L_80085464;
    }
    // 0x8008543C: nop

    // 0x80085440: jal         0x80000B28
    // 0x80085444: nop

    music_change_on(rdram, ctx);
        goto after_9;
    // 0x80085444: nop

    after_9:
    // 0x80085448: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008544C: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x80085450: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x80085454: jal         0x80000B34
    // 0x80085458: nop

    music_play(rdram, ctx);
        goto after_10;
    // 0x80085458: nop

    after_10:
    // 0x8008545C: b           L_80085538
    // 0x80085460: nop

        goto L_80085538;
    // 0x80085460: nop

L_80085464:
    // 0x80085464: jal         0x80000B28
    // 0x80085468: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x80085468: nop

    after_11:
    // 0x8008546C: jal         0x80000BE0
    // 0x80085470: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_12;
    // 0x80085470: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_12:
    // 0x80085474: jal         0x80000B34
    // 0x80085478: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_13;
    // 0x80085478: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_13:
    // 0x8008547C: jal         0x80000B18
    // 0x80085480: nop

    music_change_off(rdram, ctx);
        goto after_14;
    // 0x80085480: nop

    after_14:
    // 0x80085484: b           L_80085538
    // 0x80085488: nop

        goto L_80085538;
    // 0x80085488: nop

L_8008548C:
    // 0x8008548C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80085490: nop

    // 0x80085494: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x80085498: bne         $at, $zero, L_80085538
    if (ctx->r1 != 0) {
        // 0x8008549C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80085538;
    }
    // 0x8008549C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800854A0: bne         $v0, $at, L_80085538
    if (ctx->r2 != ctx->r1) {
        // 0x800854A4: nop
    
            goto L_80085538;
    }
    // 0x800854A4: nop

    // 0x800854A8: bgez        $t0, L_800854D0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800854AC: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_800854D0;
    }
    // 0x800854AC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800854B0: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800854B4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800854B8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800854BC: blez        $v1, L_800854D0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800854C0: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_800854D0;
    }
    // 0x800854C0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800854C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800854C8: b           L_80085508
    // 0x800854CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
        goto L_80085508;
    // 0x800854CC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
L_800854D0:
    // 0x800854D0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800854D4: blez        $t0, L_80085508
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800854D8: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_80085508;
    }
    // 0x800854D8: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x800854DC: jal         0x80002110
    // 0x800854E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    music_sequence_count(rdram, ctx);
        goto after_15;
    // 0x800854E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_15:
    // 0x800854E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800854E8: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800854EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800854F0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800854F4: beq         $at, $zero, L_80085508
    if (ctx->r1 == 0) {
        // 0x800854F8: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80085508;
    }
    // 0x800854F8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800854FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80085500: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80085504: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
L_80085508:
    // 0x80085508: beq         $a0, $zero, L_80085538
    if (ctx->r4 == 0) {
        // 0x8008550C: nop
    
            goto L_80085538;
    }
    // 0x8008550C: nop

    // 0x80085510: jal         0x80000B28
    // 0x80085514: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x80085514: nop

    after_16:
    // 0x80085518: jal         0x80000BE0
    // 0x8008551C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_17;
    // 0x8008551C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_17:
    // 0x80085520: lbu         $a0, 0x3($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X3);
    // 0x80085524: jal         0x80000B34
    // 0x80085528: nop

    music_play(rdram, ctx);
        goto after_18;
    // 0x80085528: nop

    after_18:
    // 0x8008552C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80085530: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085534: sw          $t3, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r11;
L_80085538:
    // 0x80085538: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8008553C: lh          $t5, 0x7206($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X7206);
    // 0x80085540: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80085544: bne         $t5, $at, L_80085574
    if (ctx->r13 != ctx->r1) {
        // 0x80085548: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80085574;
    }
    // 0x80085548: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008554C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80085550: addiu       $a1, $a1, 0x6FBC
    ctx->r5 = ADD32(ctx->r5, 0X6FBC);
    // 0x80085554: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80085558: nop

    // 0x8008555C: bne         $t6, $zero, L_80085594
    if (ctx->r14 != 0) {
        // 0x80085560: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80085594;
    }
    // 0x80085560: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085564: jal         0x80001D04
    // 0x80085568: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    sound_play(rdram, ctx);
        goto after_19;
    // 0x80085568: addiu       $a0, $zero, 0x19B
    ctx->r4 = ADD32(0, 0X19B);
    after_19:
    // 0x8008556C: b           L_80085594
    // 0x80085570: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_80085594;
    // 0x80085570: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80085574:
    // 0x80085574: addiu       $a1, $a1, 0x6FBC
    ctx->r5 = ADD32(ctx->r5, 0X6FBC);
    // 0x80085578: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8008557C: nop

    // 0x80085580: beq         $a0, $zero, L_80085594
    if (ctx->r4 == 0) {
        // 0x80085584: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80085594;
    }
    // 0x80085584: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x80085588: jal         0x8000488C
    // 0x8008558C: nop

    sndp_stop(rdram, ctx);
        goto after_20;
    // 0x8008558C: nop

    after_20:
    // 0x80085590: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80085594:
    // 0x80085594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80085598: bne         $t7, $at, L_800855B0
    if (ctx->r15 != ctx->r1) {
        // 0x8008559C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_800855B0;
    }
    // 0x8008559C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800855A0: jal         0x80001D04
    // 0x800855A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_21;
    // 0x800855A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x800855A8: b           L_800855E8
    // 0x800855AC: nop

        goto L_800855E8;
    // 0x800855AC: nop

L_800855B0:
    // 0x800855B0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800855B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800855B8: bne         $t8, $at, L_800855D0
    if (ctx->r24 != ctx->r1) {
        // 0x800855BC: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_800855D0;
    }
    // 0x800855BC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800855C0: jal         0x80001D04
    // 0x800855C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_22;
    // 0x800855C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x800855C8: b           L_800855E8
    // 0x800855CC: nop

        goto L_800855E8;
    // 0x800855CC: nop

L_800855D0:
    // 0x800855D0: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800855D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800855D8: bne         $t9, $at, L_800855E8
    if (ctx->r25 != ctx->r1) {
        // 0x800855DC: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800855E8;
    }
    // 0x800855DC: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800855E0: jal         0x80001D04
    // 0x800855E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_23;
    // 0x800855E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_23:
L_800855E8:
    // 0x800855E8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800855EC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x800855F0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800855F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800855F8: slti        $at, $t2, -0x1E
    ctx->r1 = SIGNED(ctx->r10) < -0X1E ? 1 : 0;
    // 0x800855FC: beq         $at, $zero, L_8008561C
    if (ctx->r1 == 0) {
        // 0x80085600: nop
    
            goto L_8008561C;
    }
    // 0x80085600: nop

    // 0x80085604: jal         0x80085634
    // 0x80085608: nop

    soundoptions_free(rdram, ctx);
        goto after_24;
    // 0x80085608: nop

    after_24:
    // 0x8008560C: jal         0x80081820
    // 0x80085610: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_25;
    // 0x80085610: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_25:
    // 0x80085614: b           L_80085624
    // 0x80085618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80085624;
    // 0x80085618: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008561C:
    // 0x8008561C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80085620: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
L_80085624:
    // 0x80085624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80085628: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008562C: jr          $ra
    // 0x80085630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80085630: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void obj_init_smoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800389EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800389F0: jr          $ra
    // 0x800389F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800389F4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_spawn_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B019C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B01A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B01A4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800B01A8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800B01AC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B01B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B01B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B01B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B01BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B01C0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x800B01C4: lw          $s5, 0x74($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X74);
    // 0x800B01C8: lb          $a3, 0x57($t6)
    ctx->r7 = MEM_B(ctx->r14, 0X57);
    // 0x800B01CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800B01D0: or          $s6, $a1, $zero
    ctx->r22 = ctx->r5 | 0;
    // 0x800B01D4: blez        $a3, L_800B0394
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800B01D8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B0394;
    }
    // 0x800B01D8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B01DC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_800B01E0:
    // 0x800B01E0: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B01E4: andi        $t7, $s5, 0x1
    ctx->r15 = ctx->r21 & 0X1;
    // 0x800B01E8: beq         $t7, $zero, L_800B02B4
    if (ctx->r15 == 0) {
        // 0x800B01EC: addu        $v1, $a2, $s4
        ctx->r3 = ADD32(ctx->r6, ctx->r20);
            goto L_800B02B4;
    }
    // 0x800B01EC: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B01F0: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B01F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B01F8: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800B01FC: bne         $t8, $zero, L_800B0224
    if (ctx->r24 != 0) {
        // 0x800B0200: andi        $t9, $v0, 0x4000
        ctx->r25 = ctx->r2 & 0X4000;
            goto L_800B0224;
    }
    // 0x800B0200: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x800B0204: jal         0x800AFA8C
    // 0x800B0208: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_enable_emitter(rdram, ctx);
        goto after_0;
    // 0x800B0208: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800B020C: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0210: nop

    // 0x800B0214: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B0218: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B021C: nop

    // 0x800B0220: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
L_800B0224:
    // 0x800B0224: beq         $t9, $zero, L_800B0244
    if (ctx->r25 == 0) {
        // 0x800B0228: andi        $t1, $v0, 0x400
        ctx->r9 = ctx->r2 & 0X400;
            goto L_800B0244;
    }
    // 0x800B0228: andi        $t1, $v0, 0x400
    ctx->r9 = ctx->r2 & 0X400;
    // 0x800B022C: sll         $t0, $s3, 5
    ctx->r8 = S32(ctx->r19 << 5);
    // 0x800B0230: addu        $a1, $a2, $t0
    ctx->r5 = ADD32(ctx->r6, ctx->r8);
    // 0x800B0234: jal         0x800B03BC
    // 0x800B0238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_trigger_emitter(rdram, ctx);
        goto after_1;
    // 0x800B0238: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800B023C: b           L_800B02A4
    // 0x800B0240: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800B02A4;
    // 0x800B0240: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B0244:
    // 0x800B0244: beq         $t1, $zero, L_800B0260
    if (ctx->r9 == 0) {
        // 0x800B0248: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0260;
    }
    // 0x800B0248: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B024C: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800B0250: jal         0x800B03BC
    // 0x800B0254: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    obj_trigger_emitter(rdram, ctx);
        goto after_2;
    // 0x800B0254: addu        $a1, $a2, $t2
    ctx->r5 = ADD32(ctx->r6, ctx->r10);
    after_2:
    // 0x800B0258: b           L_800B02A4
    // 0x800B025C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
        goto L_800B02A4;
    // 0x800B025C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B0260:
    // 0x800B0260: lh          $t3, 0xA($v1)
    ctx->r11 = MEM_H(ctx->r3, 0XA);
    // 0x800B0264: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0268: addu        $t4, $t3, $s6
    ctx->r12 = ADD32(ctx->r11, ctx->r22);
    // 0x800B026C: sh          $t4, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r12;
    // 0x800B0270: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x800B0274: sll         $t8, $s3, 5
    ctx->r24 = S32(ctx->r19 << 5);
    // 0x800B0278: addu        $v1, $a2, $s4
    ctx->r3 = ADD32(ctx->r6, ctx->r20);
    // 0x800B027C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B0280: lh          $t5, 0xA($v1)
    ctx->r13 = MEM_H(ctx->r3, 0XA);
    // 0x800B0284: lh          $t7, 0x40($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X40);
    // 0x800B0288: nop

    // 0x800B028C: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B0290: bne         $at, $zero, L_800B02A0
    if (ctx->r1 != 0) {
        // 0x800B0294: nop
    
            goto L_800B02A0;
    }
    // 0x800B0294: nop

    // 0x800B0298: jal         0x800B03BC
    // 0x800B029C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    obj_trigger_emitter(rdram, ctx);
        goto after_3;
    // 0x800B029C: addu        $a1, $a2, $t8
    ctx->r5 = ADD32(ctx->r6, ctx->r24);
    after_3:
L_800B02A0:
    // 0x800B02A0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
L_800B02A4:
    // 0x800B02A4: nop

    // 0x800B02A8: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800B02AC: b           L_800B0380
    // 0x800B02B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B02B0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B02B4:
    // 0x800B02B4: lh          $v0, 0x4($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X4);
    // 0x800B02B8: nop

    // 0x800B02BC: andi        $t0, $v0, 0x8000
    ctx->r8 = ctx->r2 & 0X8000;
    // 0x800B02C0: beq         $t0, $zero, L_800B037C
    if (ctx->r8 == 0) {
        // 0x800B02C4: andi        $t1, $v0, 0x4000
        ctx->r9 = ctx->r2 & 0X4000;
            goto L_800B037C;
    }
    // 0x800B02C4: andi        $t1, $v0, 0x4000
    ctx->r9 = ctx->r2 & 0X4000;
    // 0x800B02C8: beq         $t1, $zero, L_800B0320
    if (ctx->r9 == 0) {
        // 0x800B02CC: andi        $t4, $v0, 0x400
        ctx->r12 = ctx->r2 & 0X400;
            goto L_800B0320;
    }
    // 0x800B02CC: andi        $t4, $v0, 0x400
    ctx->r12 = ctx->r2 & 0X400;
    // 0x800B02D0: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800B02D4: addu        $s1, $a2, $t2
    ctx->r17 = ADD32(ctx->r6, ctx->r10);
    // 0x800B02D8: lbu         $s0, 0x6($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X6);
    // 0x800B02DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B02E0: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x800B02E4: bgez        $s0, L_800B02F0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800B02E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B02F0;
    }
    // 0x800B02E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B02EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800B02F0:
    // 0x800B02F0: jal         0x800B03BC
    // 0x800B02F4: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    obj_trigger_emitter(rdram, ctx);
        goto after_4;
    // 0x800B02F4: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    after_4:
    // 0x800B02F8: bne         $s0, $zero, L_800B030C
    if (ctx->r16 != 0) {
        // 0x800B02FC: sb          $s0, 0x6($s1)
        MEM_B(0X6, ctx->r17) = ctx->r16;
            goto L_800B030C;
    }
    // 0x800B02FC: sb          $s0, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r16;
    // 0x800B0300: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0304: jal         0x800AFC44
    // 0x800B0308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_5;
    // 0x800B0308: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
L_800B030C:
    // 0x800B030C: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x800B0310: nop

    // 0x800B0314: lb          $a3, 0x57($t3)
    ctx->r7 = MEM_B(ctx->r11, 0X57);
    // 0x800B0318: b           L_800B0380
    // 0x800B031C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B031C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0320:
    // 0x800B0320: beq         $t4, $zero, L_800B0364
    if (ctx->r12 == 0) {
        // 0x800B0324: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800B0364;
    }
    // 0x800B0324: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0328: sll         $t6, $s3, 5
    ctx->r14 = S32(ctx->r19 << 5);
    // 0x800B032C: ori         $t5, $v0, 0x200
    ctx->r13 = ctx->r2 | 0X200;
    // 0x800B0330: addu        $a0, $a2, $t6
    ctx->r4 = ADD32(ctx->r6, ctx->r14);
    // 0x800B0334: sh          $t5, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r13;
    // 0x800B0338: lbu         $t7, 0x6($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X6);
    // 0x800B033C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800B0340: bne         $t7, $zero, L_800B0350
    if (ctx->r15 != 0) {
        // 0x800B0344: nop
    
            goto L_800B0350;
    }
    // 0x800B0344: nop

    // 0x800B0348: jal         0x800AFC44
    // 0x800B034C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_6;
    // 0x800B034C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800B0350:
    // 0x800B0350: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x800B0354: nop

    // 0x800B0358: lb          $a3, 0x57($t8)
    ctx->r7 = MEM_B(ctx->r24, 0X57);
    // 0x800B035C: b           L_800B0380
    // 0x800B0360: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800B0380;
    // 0x800B0360: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0364:
    // 0x800B0364: jal         0x800AFC44
    // 0x800B0368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    obj_disable_emitter(rdram, ctx);
        goto after_7;
    // 0x800B0368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800B036C: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x800B0370: nop

    // 0x800B0374: lb          $a3, 0x57($t9)
    ctx->r7 = MEM_B(ctx->r25, 0X57);
    // 0x800B0378: nop

L_800B037C:
    // 0x800B037C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800B0380:
    // 0x800B0380: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B0384: srl         $t0, $s5, 1
    ctx->r8 = S32(U32(ctx->r21) >> 1);
    // 0x800B0388: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    // 0x800B038C: bne         $at, $zero, L_800B01E0
    if (ctx->r1 != 0) {
        // 0x800B0390: or          $s5, $t0, $zero
        ctx->r21 = ctx->r8 | 0;
            goto L_800B01E0;
    }
    // 0x800B0390: or          $s5, $t0, $zero
    ctx->r21 = ctx->r8 | 0;
L_800B0394:
    // 0x800B0394: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B0398: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B039C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B03A0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B03A4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B03A8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B03AC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800B03B0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800B03B4: jr          $ra
    // 0x800B03B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B03B8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void obj_loop_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E670: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E674: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E678: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003E67C: nop

    // 0x8003E680: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    // 0x8003E684: nop

    // 0x8003E688: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x8003E68C: beq         $at, $zero, L_8003E6C4
    if (ctx->r1 == 0) {
        // 0x8003E690: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8003E6C4;
    }
    // 0x8003E690: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8003E694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003E698: addu        $at, $at, $t6
    gpr jr_addend_8003E6A4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8003E69C: lw          $t6, 0x6750($at)
    ctx->r14 = ADD32(ctx->r1, 0X6750);
    // 0x8003E6A0: nop

    // 0x8003E6A4: jr          $t6
    // 0x8003E6A8: nop

    switch (jr_addend_8003E6A4 >> 2) {
        case 0: goto L_8003E6AC; break;
        case 1: goto L_8003E6AC; break;
        case 2: goto L_8003E6BC; break;
        case 3: goto L_8003E6BC; break;
        case 4: goto L_8003E6C4; break;
        case 5: goto L_8003E6C4; break;
        case 6: goto L_8003E6C4; break;
        case 7: goto L_8003E6C4; break;
        case 8: goto L_8003E6C4; break;
        case 9: goto L_8003E6C4; break;
        case 10: goto L_8003E6BC; break;
        case 11: goto L_8003E6BC; break;
        default: switch_error(__func__, 0x8003E6A4, 0x800E6750);
    }
    // 0x8003E6A8: nop

L_8003E6AC:
    // 0x8003E6AC: jal         0x8003E6D4
    // 0x8003E6B0: nop

    weapon_projectile(rdram, ctx);
        goto after_0;
    // 0x8003E6B0: nop

    after_0:
    // 0x8003E6B4: b           L_8003E6C8
    // 0x8003E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8003E6C8;
    // 0x8003E6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E6BC:
    // 0x8003E6BC: jal         0x8003F328
    // 0x8003E6C0: nop

    weapon_trap(rdram, ctx);
        goto after_1;
    // 0x8003E6C0: nop

    after_1:
L_8003E6C4:
    // 0x8003E6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003E6C8:
    // 0x8003E6C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E6CC: jr          $ra
    // 0x8003E6D0: nop

    return;
    // 0x8003E6D0: nop

;}
RECOMP_FUNC void menu_title_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80083974: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80083978: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008397C: sw          $t6, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = ctx->r14;
    // 0x80083980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083984: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80083988: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x8008398C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80083990: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083994: jal         0x8009C698
    // 0x80083998: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    reset_character_id_slots(rdram, ctx);
        goto after_0;
    // 0x80083998: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    after_0:
    // 0x8008399C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839A0: sw          $zero, -0x5B4($at)
    MEM_W(-0X5B4, ctx->r1) = 0;
    // 0x800839A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839A8: sw          $zero, -0x624($at)
    MEM_W(-0X624, ctx->r1) = 0;
    // 0x800839AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839B0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800839B4: jal         0x8006A674
    // 0x800839B8: sw          $t7, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r15;
    input_assign_players(rdram, ctx);
        goto after_1;
    // 0x800839B8: sw          $t7, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r15;
    after_1:
    // 0x800839BC: jal         0x80000B34
    // 0x800839C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    music_play(rdram, ctx);
        goto after_2;
    // 0x800839C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x800839C4: jal         0x80001AEC
    // 0x800839C8: nop

    music_volume(rdram, ctx);
        goto after_3;
    // 0x800839C8: nop

    after_3:
    // 0x800839CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800839D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800839D4: sw          $v0, -0x320($at)
    MEM_W(-0X320, ctx->r1) = ctx->r2;
    // 0x800839D8: addiu       $v1, $v1, -0x628
    ctx->r3 = ADD32(ctx->r3, -0X628);
    // 0x800839DC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800839E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800839E4: beq         $t8, $zero, L_800839FC
    if (ctx->r24 == 0) {
        // 0x800839E8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800839FC;
    }
    // 0x800839E8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800839EC: sw          $zero, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = 0;
    // 0x800839F0: b           L_80083A04
    // 0x800839F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80083A04;
    // 0x800839F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800839F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800839FC:
    // 0x800839FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A00: sw          $t9, 0x6E0C($at)
    MEM_W(0X6E0C, ctx->r1) = ctx->r25;
L_80083A04:
    // 0x80083A04: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80083A08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A0C: swc1        $f4, 0x6E10($at)
    MEM_W(0X6E10, ctx->r1) = ctx->f4.u32l;
    // 0x80083A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083A14: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083A18: sw          $zero, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = 0;
    // 0x80083A1C: jal         0x8009CBB8
    // 0x80083A20: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    menu_assetgroup_load(rdram, ctx);
        goto after_4;
    // 0x80083A20: addiu       $a0, $a0, -0x2BC
    ctx->r4 = ADD32(ctx->r4, -0X2BC);
    after_4:
    // 0x80083A24: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80083A28: lh          $t0, -0x2BC($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X2BC);
    // 0x80083A2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083A30: addiu       $a0, $a0, 0x6AF0
    ctx->r4 = ADD32(ctx->r4, 0X6AF0);
    // 0x80083A34: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80083A38: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083A3C: lh          $t4, -0x2BA($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X2BA);
    // 0x80083A40: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80083A44: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80083A48: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083A4C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083A50: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80083A54: lh          $t8, -0x2B8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X2B8);
    // 0x80083A58: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083A5C: sw          $t3, -0x2A4($at)
    MEM_W(-0X2A4, ctx->r1) = ctx->r11;
    // 0x80083A60: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80083A64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083A68: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80083A6C: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x80083A70: sw          $t7, -0x29C($at)
    MEM_W(-0X29C, ctx->r1) = ctx->r15;
    // 0x80083A74: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80083A78: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80083A7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80083A80: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80083A84: addiu       $a1, $a1, -0x2A6
    ctx->r5 = ADD32(ctx->r5, -0X2A6);
    // 0x80083A88: addiu       $v0, $v0, -0x2B6
    ctx->r2 = ADD32(ctx->r2, -0X2B6);
    // 0x80083A8C: addiu       $v1, $v1, -0x28C
    ctx->r3 = ADD32(ctx->r3, -0X28C);
    // 0x80083A90: sw          $t1, -0x294($at)
    MEM_W(-0X294, ctx->r1) = ctx->r9;
L_80083A94:
    // 0x80083A94: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x80083A98: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80083A9C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80083AA0: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80083AA4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80083AA8: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x80083AAC: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x80083AB0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80083AB4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80083AB8: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80083ABC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80083AC0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80083AC4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80083AC8: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x80083ACC: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80083AD0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80083AD4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80083AD8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80083ADC: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x80083AE0: sw          $t9, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r25;
    // 0x80083AE4: sw          $t7, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r15;
    // 0x80083AE8: bne         $v0, $a1, L_80083A94
    if (ctx->r2 != ctx->r5) {
        // 0x80083AEC: sw          $t3, -0x10($v1)
        MEM_W(-0X10, ctx->r3) = ctx->r11;
            goto L_80083A94;
    }
    // 0x80083AEC: sw          $t3, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r11;
    // 0x80083AF0: jal         0x80000BE0
    // 0x80083AF4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    music_voicelimit_set(rdram, ctx);
        goto after_5;
    // 0x80083AF4: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    after_5:
    // 0x80083AF8: jal         0x80066300
    // 0x80083AFC: nop

    cam_shake_off(rdram, ctx);
        goto after_6;
    // 0x80083AFC: nop

    after_6:
    // 0x80083B00: jal         0x800C484C
    // 0x80083B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_7;
    // 0x80083B04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x80083B08: jal         0x800C46D0
    // 0x80083B0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x80083B0C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80083B10: jal         0x80000890
    // 0x80083B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_reset(rdram, ctx);
        goto after_9;
    // 0x80083B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
    // 0x80083B18: jal         0x8000E4BC
    // 0x80083B1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_time_trial_enabled(rdram, ctx);
        goto after_10;
    // 0x80083B1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80083B20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B24: sw          $zero, 0x6E04($at)
    MEM_W(0X6E04, ctx->r1) = 0;
    // 0x80083B28: jal         0x8001E2D0
    // 0x80083B2C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x80083B2C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_11:
    // 0x80083B30: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083B34: addiu       $a0, $a0, 0x6E14
    ctx->r4 = ADD32(ctx->r4, 0X6E14);
    // 0x80083B38: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x80083B3C: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x80083B40: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80083B44: addiu       $a2, $a2, 0x6E08
    ctx->r6 = ADD32(ctx->r6, 0X6E08);
    // 0x80083B48: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80083B4C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80083B50: bne         $a1, $at, L_80083B64
    if (ctx->r5 != ctx->r1) {
        // 0x80083B54: sh          $zero, 0x0($a2)
        MEM_H(0X0, ctx->r6) = 0;
            goto L_80083B64;
    }
    // 0x80083B54: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x80083B58: addiu       $t8, $zero, 0x258
    ctx->r24 = ADD32(0, 0X258);
    // 0x80083B5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083B60: sh          $t8, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r24;
L_80083B64:
    // 0x80083B64: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x80083B68: lb          $a2, 0x2($v1)
    ctx->r6 = MEM_B(ctx->r3, 0X2);
    // 0x80083B6C: jal         0x8006E528
    // 0x80083B70: nop

    load_level_for_menu(rdram, ctx);
        goto after_12;
    // 0x80083B70: nop

    after_12:
    // 0x80083B74: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80083B78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B7C: swc1        $f6, 0x6E98($at)
    MEM_W(0X6E98, ctx->r1) = ctx->f6.u32l;
    // 0x80083B80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B84: sw          $zero, 0x6EA0($at)
    MEM_W(0X6EA0, ctx->r1) = 0;
    // 0x80083B88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B8C: sw          $zero, 0x6E9C($at)
    MEM_W(0X6E9C, ctx->r1) = 0;
    // 0x80083B90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083B94: sw          $zero, -0x8C($at)
    MEM_W(-0X8C, ctx->r1) = 0;
    // 0x80083B98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80083BA0: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
    // 0x80083BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083BA8: sw          $zero, -0x5C8($at)
    MEM_W(-0X5C8, ctx->r1) = 0;
    // 0x80083BAC: jr          $ra
    // 0x80083BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80083BB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void obj_init_silvercoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DC9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DCA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DCA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DCA8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCAC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DCB0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DCB4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCB8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DCBC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DCC0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DCC4: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DCC8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DCCC: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DCD0: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8003DCD4: jal         0x8009C814
    // 0x8003DCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DCD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DCDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCE0: bne         $v0, $zero, L_8003DD20
    if (ctx->r2 != 0) {
        // 0x8003DCE4: nop
    
            goto L_8003DD20;
    }
    // 0x8003DCE4: nop

    // 0x8003DCE8: jal         0x8000E1DC
    // 0x8003DCEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DCEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DCF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DCF4: beq         $v0, $zero, L_8003DD1C
    if (ctx->r2 == 0) {
        // 0x8003DCF8: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DD1C;
    }
    // 0x8003DCF8: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DCFC: jal         0x8009F1B4
    // 0x8003DD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DD00: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DD04: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DD08: bne         $v0, $zero, L_8003DD1C
    if (ctx->r2 != 0) {
        // 0x8003DD0C: addiu       $t2, $zero, 0x3
        ctx->r10 = ADD32(0, 0X3);
            goto L_8003DD1C;
    }
    // 0x8003DD0C: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x8003DD10: b           L_8003DD20
    // 0x8003DD14: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DD20;
    // 0x8003DD14: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DD18: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
L_8003DD1C:
    // 0x8003DD1C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
L_8003DD20:
    // 0x8003DD20: lw          $t3, 0x78($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X78);
    // 0x8003DD24: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DD28: bne         $t3, $at, L_8003DD48
    if (ctx->r11 != ctx->r1) {
        // 0x8003DD2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DD48;
    }
    // 0x8003DD2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DD30: lh          $t4, 0x6($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X6);
    // 0x8003DD34: nop

    // 0x8003DD38: ori         $t5, $t4, 0x600
    ctx->r13 = ctx->r12 | 0X600;
    // 0x8003DD3C: jal         0x8000FFB8
    // 0x8003DD40: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DD40: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    after_3:
    // 0x8003DD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DD48:
    // 0x8003DD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DD4C: jr          $ra
    // 0x8003DD50: nop

    return;
    // 0x8003DD50: nop

;}
RECOMP_FUNC void despawn_player_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E1EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F0: sw          $a0, -0x4D40($at)
    MEM_W(-0X4D40, ctx->r1) = ctx->r4;
    // 0x8000E1F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E1F8: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8000E1FC: sb          $t6, -0x4D3C($at)
    MEM_B(-0X4D3C, ctx->r1) = ctx->r14;
    // 0x8000E200: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000E204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E208: sb          $a1, -0x4D3B($at)
    MEM_B(-0X4D3B, ctx->r1) = ctx->r5;
    // 0x8000E20C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000E210: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000E214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E21C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E220: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8000E224: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E228: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000E22C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000E230: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8000E234: nop

    // 0x8000E238: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000E23C: sh          $t8, -0x4D3A($at)
    MEM_H(-0X4D3A, ctx->r1) = ctx->r24;
    // 0x8000E240: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000E244: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E248: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E24C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8000E250: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E254: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000E258: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000E25C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000E260: nop

    // 0x8000E264: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8000E268: sh          $t0, -0x4D38($at)
    MEM_H(-0X4D38, ctx->r1) = ctx->r8;
    // 0x8000E26C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8000E270: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000E274: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000E278: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8000E27C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E280: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000E284: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x8000E288: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8000E28C: sh          $t2, -0x4D36($at)
    MEM_H(-0X4D36, ctx->r1) = ctx->r10;
    // 0x8000E290: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x8000E294: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E298: jal         0x8000FFB8
    // 0x8000E29C: sh          $t3, -0x4D34($at)
    MEM_H(-0X4D34, ctx->r1) = ctx->r11;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8000E29C: sh          $t3, -0x4D34($at)
    MEM_H(-0X4D34, ctx->r1) = ctx->r11;
    after_0:
    // 0x8000E2A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E2A8: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000E2AC: jr          $ra
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8000E2B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void __mapVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A71C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A724: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8000A728: lbu         $t0, 0x71($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A72C: lbu         $t9, 0x70($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X70);
    // 0x8000A730: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A734: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A738: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x8000A73C: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x8000A740: slt         $at, $t9, $t0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A744: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
    // 0x8000A748: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A74C: beq         $at, $zero, L_8000A75C
    if (ctx->r1 == 0) {
        // 0x8000A750: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_8000A75C;
    }
    // 0x8000A750: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000A754: jr          $ra
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000A758: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000A75C:
    // 0x8000A75C: beq         $v1, $zero, L_8000A7BC
    if (ctx->r3 == 0) {
        // 0x8000A760: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8000A7BC;
    }
    // 0x8000A760: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8000A764: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x8000A768: nop

    // 0x8000A76C: sw          $t1, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r9;
    // 0x8000A770: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8000A774: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x8000A778: nop

    // 0x8000A77C: bne         $t2, $zero, L_8000A78C
    if (ctx->r10 != 0) {
        // 0x8000A780: nop
    
            goto L_8000A78C;
    }
    // 0x8000A780: nop

    // 0x8000A784: b           L_8000A798
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
        goto L_8000A798;
    // 0x8000A788: sw          $v1, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r3;
L_8000A78C:
    // 0x8000A78C: lw          $t3, 0x68($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X68);
    // 0x8000A790: nop

    // 0x8000A794: sw          $v1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r3;
L_8000A798:
    // 0x8000A798: sw          $v1, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r3;
    // 0x8000A79C: sb          $a3, 0x31($v1)
    MEM_B(0X31, ctx->r3) = ctx->r7;
    // 0x8000A7A0: sb          $a1, 0x32($v1)
    MEM_B(0X32, ctx->r3) = ctx->r5;
    // 0x8000A7A4: sb          $a2, 0x33($v1)
    MEM_B(0X33, ctx->r3) = ctx->r6;
    // 0x8000A7A8: sw          $v1, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r3;
    // 0x8000A7AC: lbu         $t4, 0x71($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X71);
    // 0x8000A7B0: nop

    // 0x8000A7B4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8000A7B8: sb          $t5, 0x71($a0)
    MEM_B(0X71, ctx->r4) = ctx->r13;
L_8000A7BC:
    // 0x8000A7BC: jr          $ra
    // 0x8000A7C0: nop

    return;
    // 0x8000A7C0: nop

;}
RECOMP_FUNC void handle_racer_head_turning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052204: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80052208: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005220C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052210: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80052214: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80052218: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8005221C: jal         0x8002359C
    // 0x80052220: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    func_80023568(rdram, ctx);
        goto after_0;
    // 0x80052220: sb          $zero, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = 0;
    after_0:
    // 0x80052224: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x80052228: beq         $v0, $zero, L_8005225C
    if (ctx->r2 == 0) {
        // 0x8005222C: nop
    
            goto L_8005225C;
    }
    // 0x8005222C: nop

    // 0x80052230: jal         0x8001BAFC
    // 0x80052234: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x80052234: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80052238: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005223C: lui         $a3, 0x481C
    ctx->r7 = S32(0X481C << 16);
    // 0x80052240: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    // 0x80052244: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052248: jal         0x800523C8
    // 0x8005224C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    turn_head_towards_object(rdram, ctx);
        goto after_2;
    // 0x8005224C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x80052250: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x80052254: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80052258: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8005225C:
    // 0x8005225C: bne         $v1, $zero, L_800522AC
    if (ctx->r3 != 0) {
        // 0x80052260: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800522AC;
    }
    // 0x80052260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80052264: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80052268: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8005226C: jal         0x8001B7DC
    // 0x80052270: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_3;
    // 0x80052270: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_3:
    // 0x80052274: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x80052278: beq         $v0, $zero, L_800522AC
    if (ctx->r2 == 0) {
        // 0x8005227C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800522AC;
    }
    // 0x8005227C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80052280: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052284: lw          $t7, -0x2540($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2540);
    // 0x80052288: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005228C: bne         $t7, $zero, L_800522AC
    if (ctx->r15 != 0) {
        // 0x80052290: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800522AC;
    }
    // 0x80052290: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80052294: lui         $a3, 0x481C
    ctx->r7 = S32(0X481C << 16);
    // 0x80052298: jal         0x800523C8
    // 0x8005229C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    turn_head_towards_object(rdram, ctx);
        goto after_4;
    // 0x8005229C: ori         $a3, $a3, 0x4000
    ctx->r7 = ctx->r7 | 0X4000;
    after_4:
    // 0x800522A0: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x800522A4: sra         $t8, $v1, 24
    ctx->r24 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800522A8: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800522AC:
    // 0x800522AC: bne         $v1, $zero, L_800522FC
    if (ctx->r3 != 0) {
        // 0x800522B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800522FC;
    }
    // 0x800522B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800522B4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800522B8: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x800522BC: jal         0x8001B7DC
    // 0x800522C0: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    racer_find_nearest_opponent_relative(rdram, ctx);
        goto after_5;
    // 0x800522C0: sb          $v1, 0x2B($sp)
    MEM_B(0X2B, ctx->r29) = ctx->r3;
    after_5:
    // 0x800522C4: lb          $v1, 0x2B($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X2B);
    // 0x800522C8: beq         $v0, $zero, L_800522FC
    if (ctx->r2 == 0) {
        // 0x800522CC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800522FC;
    }
    // 0x800522CC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800522D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800522D4: lw          $t9, -0x2540($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2540);
    // 0x800522D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800522DC: bne         $t9, $zero, L_800522FC
    if (ctx->r25 != 0) {
        // 0x800522E0: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800522FC;
    }
    // 0x800522E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800522E4: lui         $a3, 0x46EA
    ctx->r7 = S32(0X46EA << 16);
    // 0x800522E8: jal         0x800523C8
    // 0x800522EC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    turn_head_towards_object(rdram, ctx);
        goto after_6;
    // 0x800522EC: ori         $a3, $a3, 0x6000
    ctx->r7 = ctx->r7 | 0X6000;
    after_6:
    // 0x800522F0: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x800522F4: sra         $t0, $v1, 24
    ctx->r8 = S32(SIGNED(ctx->r3) >> 24);
    // 0x800522F8: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
L_800522FC:
    // 0x800522FC: bne         $v1, $zero, L_80052380
    if (ctx->r3 != 0) {
        // 0x80052300: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80052380;
    }
    // 0x80052300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052304: lb          $t1, 0x1E7($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1E7);
    // 0x80052308: addiu       $t4, $zero, 0x2800
    ctx->r12 = ADD32(0, 0X2800);
    // 0x8005230C: andi        $t2, $t1, 0x1F
    ctx->r10 = ctx->r9 & 0X1F;
    // 0x80052310: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80052314: beq         $at, $zero, L_8005237C
    if (ctx->r1 == 0) {
        // 0x80052318: lui         $at, 0x44A0
        ctx->r1 = S32(0X44A0 << 16);
            goto L_8005237C;
    }
    // 0x80052318: lui         $at, 0x44A0
    ctx->r1 = S32(0X44A0 << 16);
    // 0x8005231C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80052320: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80052324: nop

    // 0x80052328: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8005232C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80052330: nop

    // 0x80052334: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80052338: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005233C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80052340: nop

    // 0x80052344: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80052348: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8005234C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80052350: bgez        $a1, L_80052360
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80052354: slti        $at, $a1, 0x2801
        ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
            goto L_80052360;
    }
    // 0x80052354: slti        $at, $a1, 0x2801
    ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
    // 0x80052358: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x8005235C: slti        $at, $a1, 0x2801
    ctx->r1 = SIGNED(ctx->r5) < 0X2801 ? 1 : 0;
L_80052360:
    // 0x80052360: bne         $at, $zero, L_80052370
    if (ctx->r1 != 0) {
        // 0x80052364: subu        $a1, $t4, $a1
        ctx->r5 = SUB32(ctx->r12, ctx->r5);
            goto L_80052370;
    }
    // 0x80052364: subu        $a1, $t4, $a1
    ctx->r5 = SUB32(ctx->r12, ctx->r5);
    // 0x80052368: addiu       $a1, $zero, 0x2800
    ctx->r5 = ADD32(0, 0X2800);
    // 0x8005236C: subu        $a1, $t4, $a1
    ctx->r5 = SUB32(ctx->r12, ctx->r5);
L_80052370:
    // 0x80052370: jal         0x8006FB8C
    // 0x80052374: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_7;
    // 0x80052374: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_7:
    // 0x80052378: sh          $v0, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r2;
L_8005237C:
    // 0x8005237C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80052380:
    // 0x80052380: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052384: jr          $ra
    // 0x80052388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80052388: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800CE6D4: beq         $a2, $zero, L_800CE6F4
    if (ctx->r6 == 0) {
        // 0x800CE6D8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800CE6F4;
    }
    // 0x800CE6D8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800CE6DC:
    // 0x800CE6DC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800CE6E0: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800CE6E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800CE6E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE6EC: bne         $a2, $zero, L_800CE6DC
    if (ctx->r6 != 0) {
        // 0x800CE6F0: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800CE6DC;
    }
    // 0x800CE6F0: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_800CE6F4:
    // 0x800CE6F4: jr          $ra
    // 0x800CE6F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x800CE6F8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void func_8008F618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FAD0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008FAD4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008FAD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008FADC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008FAE0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8008FAE4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008FAE8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008FAEC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008FAF0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008FAF4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008FAF8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008FAFC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008FB00: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008FB04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FB08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8008FB0C: jal         0x80066AD4
    // 0x8008FB10: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    camDisableUserView(rdram, ctx);
        goto after_0;
    // 0x8008FB10: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    after_0:
    // 0x8008FB14: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008FB18: jal         0x80066470
    // 0x8008FB1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    camera_init_tracks_menu(rdram, ctx);
        goto after_1;
    // 0x8008FB1C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8008FB20: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008FB24: jal         0x8006816C
    // 0x8008FB28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mtx_ortho(rdram, ctx);
        goto after_2;
    // 0x8008FB28: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8008FB2C: jal         0x8007B820
    // 0x8008FB30: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    rendermode_reset(rdram, ctx);
        goto after_3;
    // 0x8008FB30: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_3:
    // 0x8008FB34: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008FB38: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008FB3C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008FB40: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8008FB44: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8008FB48: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8008FB4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008FB50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008FB54: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8008FB58: lwc1        $f4, 0x6F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8008FB5C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8008FB60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008FB64: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008FB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008FB6C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8008FB70: lwc1        $f8, 0x6FA4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8008FB74: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8008FB78: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008FB7C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8008FB80: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008FB84: addiu       $t2, $t2, 0x6A20
    ctx->r10 = ADD32(ctx->r10, 0X6A20);
    // 0x8008FB88: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8008FB8C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008FB90: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008FB94: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8008FB98: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8008FB9C: sra         $t6, $t0, 3
    ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8008FBA0: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008FBA4: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8008FBA8: div         $zero, $a3, $t6
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r14)));
    // 0x8008FBAC: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8008FBB0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008FBB4: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008FBB8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008FBBC: addiu       $ra, $ra, 0x6A18
    ctx->r31 = ADD32(ctx->r31, 0X6A18);
    // 0x8008FBC0: addiu       $t1, $t1, 0xDC0
    ctx->r9 = ADD32(ctx->r9, 0XDC0);
    // 0x8008FBC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8008FBC8: bne         $t0, $zero, L_8008FBD4
    if (ctx->r8 != 0) {
        // 0x8008FBCC: nop
    
            goto L_8008FBD4;
    }
    // 0x8008FBCC: nop

    // 0x8008FBD0: break       7
    do_break(2148072400);
L_8008FBD4:
    // 0x8008FBD4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FBD8: bne         $t0, $at, L_8008FBEC
    if (ctx->r8 != ctx->r1) {
        // 0x8008FBDC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008FBEC;
    }
    // 0x8008FBDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008FBE0: bne         $a3, $at, L_8008FBEC
    if (ctx->r7 != ctx->r1) {
        // 0x8008FBE4: nop
    
            goto L_8008FBEC;
    }
    // 0x8008FBE4: nop

    // 0x8008FBE8: break       6
    do_break(2148072424);
L_8008FBEC:
    // 0x8008FBEC: mflo        $s7
    ctx->r23 = lo;
    // 0x8008FBF0: slti        $at, $s7, 0x2A
    ctx->r1 = SIGNED(ctx->r23) < 0X2A ? 1 : 0;
    // 0x8008FBF4: bne         $at, $zero, L_8008FC04
    if (ctx->r1 != 0) {
        // 0x8008FBF8: nop
    
            goto L_8008FC04;
    }
    // 0x8008FBF8: nop

    // 0x8008FBFC: b           L_8008FEDC
    // 0x8008FC00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8008FEDC;
    // 0x8008FC00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8008FC04:
    // 0x8008FC04: multu       $s7, $t0
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008FC08: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008FC0C: lw          $t8, 0x0($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X0);
    // 0x8008FC10: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8008FC14: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x8008FC18: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8008FC1C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8008FC20: addiu       $t6, $zero, -0x100
    ctx->r14 = ADD32(0, -0X100);
    // 0x8008FC24: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x8008FC28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8008FC2C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8008FC30: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008FC34: mflo        $t7
    ctx->r15 = lo;
    // 0x8008FC38: subu        $a3, $a3, $t7
    ctx->r7 = SUB32(ctx->r7, ctx->r15);
    // 0x8008FC3C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8008FC40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8008FC44: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008FC48: addu        $s4, $t8, $a3
    ctx->r20 = ADD32(ctx->r24, ctx->r7);
    // 0x8008FC4C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8008FC50: sw          $t8, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r24;
    // 0x8008FC54: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8008FC58: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008FC5C: lw          $a2, 0x6EE4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6EE4);
    // 0x8008FC60: lbu         $t8, 0x0($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X0);
    // 0x8008FC64: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8008FC68: addu        $s1, $s1, $t7
    ctx->r17 = ADD32(ctx->r17, ctx->r15);
    // 0x8008FC6C: addu        $s2, $s2, $t7
    ctx->r18 = ADD32(ctx->r18, ctx->r15);
    // 0x8008FC70: lw          $s1, 0xEE8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0XEE8);
    // 0x8008FC74: lw          $s2, 0xEF0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0XEF0);
    // 0x8008FC78: slt         $at, $t8, $s7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8008FC7C: beq         $at, $zero, L_8008FCA0
    if (ctx->r1 == 0) {
        // 0x8008FC80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8008FCA0;
    }
    // 0x8008FC80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8008FC84: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008FC88: addiu       $s0, $s0, 0xDC0
    ctx->r16 = ADD32(ctx->r16, 0XDC0);
L_8008FC8C:
    // 0x8008FC8C: lbu         $t9, 0x5($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X5);
    // 0x8008FC90: addiu       $v1, $v1, 0x5
    ctx->r3 = ADD32(ctx->r3, 0X5);
    // 0x8008FC94: slt         $at, $t9, $s7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r23) ? 1 : 0;
    // 0x8008FC98: bne         $at, $zero, L_8008FC8C
    if (ctx->r1 != 0) {
        // 0x8008FC9C: addiu       $s0, $s0, 0x5
        ctx->r16 = ADD32(ctx->r16, 0X5);
            goto L_8008FC8C;
    }
    // 0x8008FC9C: addiu       $s0, $s0, 0x5
    ctx->r16 = ADD32(ctx->r16, 0X5);
L_8008FCA0:
    // 0x8008FCA0: lw          $t6, 0x0($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X0);
    // 0x8008FCA4: addu        $s0, $t1, $v1
    ctx->r16 = ADD32(ctx->r9, ctx->r3);
    // 0x8008FCA8: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8008FCAC: slt         $at, $s4, $t7
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008FCB0: bne         $at, $zero, L_8008FED0
    if (ctx->r1 != 0) {
        // 0x8008FCB4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FED0;
    }
    // 0x8008FCB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FCB8: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x8008FCBC: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x8008FCC0: slti        $at, $a3, 0x2A
    ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
    // 0x8008FCC4: beq         $at, $zero, L_8008FED0
    if (ctx->r1 == 0) {
        // 0x8008FCC8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FED0;
    }
    // 0x8008FCC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FCCC: lw          $fp, 0x70($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X70);
    // 0x8008FCD0: nop

L_8008FCD4:
    // 0x8008FCD4: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x8008FCD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008FCDC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8008FCE0: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8008FCE4: lw          $a1, 0xCB0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XCB0);
    // 0x8008FCE8: sh          $s4, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r20;
    // 0x8008FCEC: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x8008FCF0: sh          $s4, 0xC($s1)
    MEM_H(0XC, ctx->r17) = ctx->r20;
    // 0x8008FCF4: sb          $t6, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r14;
    // 0x8008FCF8: lbu         $t7, 0x2($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X2);
    // 0x8008FCFC: or          $t0, $s1, $zero
    ctx->r8 = ctx->r17 | 0;
    // 0x8008FD00: sb          $t7, 0x13($s1)
    MEM_B(0X13, ctx->r17) = ctx->r15;
    // 0x8008FD04: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8008FD08: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x8008FD0C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8008FD10: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x8008FD14: sh          $t6, 0x16($s1)
    MEM_H(0X16, ctx->r17) = ctx->r14;
    // 0x8008FD18: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x8008FD1C: or          $s7, $a3, $zero
    ctx->r23 = ctx->r7 | 0;
    // 0x8008FD20: sb          $t7, 0x1D($s1)
    MEM_B(0X1D, ctx->r17) = ctx->r15;
    // 0x8008FD24: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8008FD28: or          $t1, $s2, $zero
    ctx->r9 = ctx->r18 | 0;
    // 0x8008FD2C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8008FD30: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x8008FD34: sh          $t6, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r14;
    // 0x8008FD38: lbu         $t7, 0x3($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X3);
    // 0x8008FD3C: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x8008FD40: sb          $t7, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r15;
    // 0x8008FD44: lbu         $t8, 0x3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X3);
    // 0x8008FD48: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008FD4C: beq         $a1, $zero, L_8008FD80
    if (ctx->r5 == 0) {
        // 0x8008FD50: addu        $a2, $a2, $t8
        ctx->r6 = ADD32(ctx->r6, ctx->r24);
            goto L_8008FD80;
    }
    // 0x8008FD50: addu        $a2, $a2, $t8
    ctx->r6 = ADD32(ctx->r6, ctx->r24);
    // 0x8008FD54: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8008FD58: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x8008FD5C: addiu       $t6, $t9, -0x1
    ctx->r14 = ADD32(ctx->r25, -0X1);
    // 0x8008FD60: lbu         $fp, 0x1($a1)
    ctx->r30 = MEM_BU(ctx->r5, 0X1);
    // 0x8008FD64: and         $s3, $t6, $t5
    ctx->r19 = ctx->r14 & ctx->r13;
    // 0x8008FD68: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x8008FD6C: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8008FD70: sll         $t6, $fp, 5
    ctx->r14 = S32(ctx->r30 << 5);
    // 0x8008FD74: addu        $s3, $t7, $t9
    ctx->r19 = ADD32(ctx->r15, ctx->r25);
    // 0x8008FD78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008FD7C: or          $fp, $t6, $zero
    ctx->r30 = ctx->r14 | 0;
L_8008FD80:
    // 0x8008FD80: addiu       $v0, $s3, 0x2800
    ctx->r2 = ADD32(ctx->r19, 0X2800);
    // 0x8008FD84: sh          $s3, 0x4($s2)
    MEM_H(0X4, ctx->r18) = ctx->r19;
    // 0x8008FD88: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x8008FD8C: sh          $s3, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r19;
    // 0x8008FD90: sh          $fp, 0xA($s2)
    MEM_H(0XA, ctx->r18) = ctx->r30;
    // 0x8008FD94: sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // 0x8008FD98: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x8008FD9C: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x8008FDA0: sh          $zero, 0x16($s2)
    MEM_H(0X16, ctx->r18) = 0;
    // 0x8008FDA4: sh          $s3, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r19;
    // 0x8008FDA8: sh          $fp, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r30;
    // 0x8008FDAC: sh          $v0, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r2;
    // 0x8008FDB0: sh          $fp, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r30;
    // 0x8008FDB4: beq         $a1, $zero, L_8008FDC4
    if (ctx->r5 == 0) {
        // 0x8008FDB8: addiu       $s2, $s2, 0x20
        ctx->r18 = ADD32(ctx->r18, 0X20);
            goto L_8008FDC4;
    }
    // 0x8008FDB8: addiu       $s2, $s2, 0x20
    ctx->r18 = ADD32(ctx->r18, 0X20);
    // 0x8008FDBC: b           L_8008FDC8
    // 0x8008FDC0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
        goto L_8008FDC8;
    // 0x8008FDC0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
L_8008FDC4:
    // 0x8008FDC4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8008FDC8:
    // 0x8008FDC8: addiu       $at, $zero, 0x1FE
    ctx->r1 = ADD32(0, 0X1FE);
    // 0x8008FDCC: bne         $a2, $at, L_8008FDDC
    if (ctx->r6 != ctx->r1) {
        // 0x8008FDD0: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_8008FDDC;
    }
    // 0x8008FDD0: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008FDD4: b           L_8008FDE4
    // 0x8008FDD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8008FDE4;
    // 0x8008FDD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8008FDDC:
    // 0x8008FDDC: lui         $a2, 0x800
    ctx->r6 = S32(0X800 << 16);
    // 0x8008FDE0: ori         $a2, $a2, 0x100
    ctx->r6 = ctx->r6 | 0X100;
L_8008FDE4:
    // 0x8008FDE4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008FDE8: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8008FDEC: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x8008FDF0: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x8008FDF4: jal         0x8007B938
    // 0x8008FDF8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    material_set(rdram, ctx);
        goto after_4;
    // 0x8008FDF8: sw          $t5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r13;
    after_4:
    // 0x8008FDFC: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8008FE00: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8008FE04: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008FE08: addu        $a0, $t0, $t3
    ctx->r4 = ADD32(ctx->r8, ctx->r11);
    // 0x8008FE0C: andi        $t8, $a0, 0x6
    ctx->r24 = ctx->r4 & 0X6;
    // 0x8008FE10: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x8008FE14: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8008FE18: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x8008FE1C: ori         $t9, $t8, 0x18
    ctx->r25 = ctx->r24 | 0X18;
    // 0x8008FE20: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8008FE24: sw          $t7, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r15;
    // 0x8008FE28: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x8008FE2C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8008FE30: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8008FE34: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8008FE38: ori         $t9, $t8, 0x50
    ctx->r25 = ctx->r24 | 0X50;
    // 0x8008FE3C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8008FE40: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8008FE44: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8008FE48: ori         $t7, $s5, 0x10
    ctx->r15 = ctx->r21 | 0X10;
    // 0x8008FE4C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8008FE50: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8008FE54: sw          $t6, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r14;
    // 0x8008FE58: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8008FE5C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8008FE60: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8008FE64: ori         $t7, $t6, 0x20
    ctx->r15 = ctx->r14 | 0X20;
    // 0x8008FE68: addu        $t8, $t1, $t3
    ctx->r24 = ADD32(ctx->r9, ctx->r11);
    // 0x8008FE6C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8008FE70: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8008FE74: lbu         $a3, 0x0($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X0);
    // 0x8008FE78: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008FE7C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x8008FE80: addiu       $ra, $ra, 0x6A18
    ctx->r31 = ADD32(ctx->r31, 0X6A18);
    // 0x8008FE84: beq         $s7, $a3, L_8008FE9C
    if (ctx->r23 == ctx->r7) {
        // 0x8008FE88: addiu       $t2, $t2, 0x6A20
        ctx->r10 = ADD32(ctx->r10, 0X6A20);
            goto L_8008FE9C;
    }
    // 0x8008FE88: addiu       $t2, $t2, 0x6A20
    ctx->r10 = ADD32(ctx->r10, 0X6A20);
    // 0x8008FE8C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8008FE90: nop

    // 0x8008FE94: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8008FE98: subu        $s4, $s4, $t6
    ctx->r20 = SUB32(ctx->r20, ctx->r14);
L_8008FE9C:
    // 0x8008FE9C: lw          $t7, 0x0($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X0);
    // 0x8008FEA0: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x8008FEA4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8008FEA8: slt         $at, $s4, $t8
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8008FEAC: bne         $at, $zero, L_8008FECC
    if (ctx->r1 != 0) {
        // 0x8008FEB0: slti        $at, $a3, 0x2A
        ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
            goto L_8008FECC;
    }
    // 0x8008FEB0: slti        $at, $a3, 0x2A
    ctx->r1 = SIGNED(ctx->r7) < 0X2A ? 1 : 0;
    // 0x8008FEB4: beq         $at, $zero, L_8008FECC
    if (ctx->r1 == 0) {
        // 0x8008FEB8: slti        $at, $t4, 0x40
        ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
            goto L_8008FECC;
    }
    // 0x8008FEB8: slti        $at, $t4, 0x40
    ctx->r1 = SIGNED(ctx->r12) < 0X40 ? 1 : 0;
    // 0x8008FEBC: bne         $at, $zero, L_8008FCD4
    if (ctx->r1 != 0) {
        // 0x8008FEC0: nop
    
            goto L_8008FCD4;
    }
    // 0x8008FEC0: nop

    // 0x8008FEC4: sw          $fp, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r30;
    // 0x8008FEC8: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
L_8008FECC:
    // 0x8008FECC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008FED0:
    // 0x8008FED0: jal         0x80066A58
    // 0x8008FED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_5;
    // 0x8008FED4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8008FED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008FEDC:
    // 0x8008FEDC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008FEE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008FEE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008FEE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008FEEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008FEF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008FEF4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008FEF8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008FEFC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF00: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008FF04: jr          $ra
    // 0x8008FF08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008FF08: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void charselect_new_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B810: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8008B814: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008B818: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008B81C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008B820: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008B824: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008B828: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008B82C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008B830: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008B834: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008B838: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008B83C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008B840: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008B844: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008B848: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008B84C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008B850: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008B854: addiu       $s7, $s7, 0x696C
    ctx->r23 = ADD32(ctx->r23, 0X696C);
    // 0x8008B858: addiu       $s5, $s5, 0x6D78
    ctx->r21 = ADD32(ctx->r21, 0X6D78);
    // 0x8008B85C: addiu       $s4, $s4, -0x5C4
    ctx->r20 = ADD32(ctx->r20, -0X5C4);
    // 0x8008B860: addiu       $s3, $s3, 0x6960
    ctx->r19 = ADD32(ctx->r19, 0X6960);
    // 0x8008B864: addiu       $s2, $s2, 0x6974
    ctx->r18 = ADD32(ctx->r18, 0X6974);
    // 0x8008B868: addiu       $s0, $s0, 0x6988
    ctx->r16 = ADD32(ctx->r16, 0X6988);
    // 0x8008B86C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008B870: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8008B874: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
L_8008B878:
    // 0x8008B878: lb          $t6, 0x0($s2)
    ctx->r14 = MEM_B(ctx->r18, 0X0);
    // 0x8008B87C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8008B880: bne         $t6, $zero, L_8008B940
    if (ctx->r14 != 0) {
        // 0x8008B884: addu        $t8, $s5, $t7
        ctx->r24 = ADD32(ctx->r21, ctx->r15);
            goto L_8008B940;
    }
    // 0x8008B884: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8008B888: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8008B88C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8008B890: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x8008B894: beq         $t0, $zero, L_8008B940
    if (ctx->r8 == 0) {
        // 0x8008B898: addu        $a3, $s0, $s1
        ctx->r7 = ADD32(ctx->r16, ctx->r17);
            goto L_8008B940;
    }
    // 0x8008B898: addu        $a3, $s0, $s1
    ctx->r7 = ADD32(ctx->r16, ctx->r17);
L_8008B89C:
    // 0x8008B89C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008B8A0: addiu       $t1, $t1, 0x6974
    ctx->r9 = ADD32(ctx->r9, 0X6974);
    // 0x8008B8A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008B8A8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008B8AC: addu        $v1, $zero, $t1
    ctx->r3 = ADD32(0, ctx->r9);
    // 0x8008B8B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8008B8B4:
    // 0x8008B8B4: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x8008B8B8: addu        $t3, $s0, $v0
    ctx->r11 = ADD32(ctx->r16, ctx->r2);
    // 0x8008B8BC: beq         $t2, $zero, L_8008B8D8
    if (ctx->r10 == 0) {
        // 0x8008B8C0: nop
    
            goto L_8008B8D8;
    }
    // 0x8008B8C0: nop

    // 0x8008B8C4: lb          $t4, 0x0($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X0);
    // 0x8008B8C8: nop

    // 0x8008B8CC: bne         $a2, $t4, L_8008B8D8
    if (ctx->r6 != ctx->r12) {
        // 0x8008B8D0: nop
    
            goto L_8008B8D8;
    }
    // 0x8008B8D0: nop

    // 0x8008B8D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008B8D8:
    // 0x8008B8D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008B8DC: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x8008B8E0: beq         $at, $zero, L_8008B8F0
    if (ctx->r1 == 0) {
        // 0x8008B8E4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8008B8F0;
    }
    // 0x8008B8E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008B8E8: bne         $a0, $zero, L_8008B8B4
    if (ctx->r4 != 0) {
        // 0x8008B8EC: nop
    
            goto L_8008B8B4;
    }
    // 0x8008B8EC: nop

L_8008B8F0:
    // 0x8008B8F0: beq         $a0, $zero, L_8008B89C
    if (ctx->r4 == 0) {
        // 0x8008B8F4: nop
    
            goto L_8008B89C;
    }
    // 0x8008B8F4: nop

    // 0x8008B8F8: sb          $a2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r6;
    // 0x8008B8FC: lb          $t8, 0x0($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X0);
    // 0x8008B900: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x8008B904: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8008B908: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8008B90C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8008B910: sb          $s6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r22;
    // 0x8008B914: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8008B918: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8008B91C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008B920: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B924: mflo        $t9
    ctx->r25 = lo;
    // 0x8008B928: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8008B92C: lh          $t1, 0xC($t0)
    ctx->r9 = MEM_H(ctx->r8, 0XC);
    // 0x8008B930: sh          $zero, 0x2($s3)
    MEM_H(0X2, ctx->r19) = 0;
    // 0x8008B934: sb          $t2, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r10;
    // 0x8008B938: jal         0x80001D04
    // 0x8008B93C: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x8008B93C: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
    after_0:
L_8008B940:
    // 0x8008B940: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008B944: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008B948: bne         $s1, $at, L_8008B878
    if (ctx->r17 != ctx->r1) {
        // 0x8008B94C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8008B878;
    }
    // 0x8008B94C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8008B950: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008B954: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008B958: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B95C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008B960: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008B964: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008B968: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008B96C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008B970: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008B974: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008B978: jr          $ra
    // 0x8008B97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8008B97C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void savemenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088328: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008832C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80088330: jal         0x800C478C
    // 0x80088334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80088334: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80088338: jal         0x800803D8
    // 0x8008833C: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008833C: nop

    after_1:
    // 0x80088340: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088344: jal         0x8009C9EC
    // 0x80088348: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    menu_assetgroup_free(rdram, ctx);
        goto after_2;
    // 0x80088348: addiu       $a0, $a0, 0x1F8
    ctx->r4 = ADD32(ctx->r4, 0X1F8);
    after_2:
    // 0x8008834C: jal         0x800C59F4
    // 0x80088350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80088350: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80088354: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088358: lw          $a0, 0x6FCC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FCC);
    // 0x8008835C: jal         0x80071380
    // 0x80088360: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80088360: nop

    after_4:
    // 0x80088364: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088368: lw          $a0, 0x7024($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7024);
    // 0x8008836C: jal         0x80071380
    // 0x80088370: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80088370: nop

    after_5:
    // 0x80088374: jal         0x800724D8
    // 0x80088378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_enable(rdram, ctx);
        goto after_6;
    // 0x80088378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x8008837C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80088380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80088384: jr          $ra
    // 0x80088388: nop

    return;
    // 0x80088388: nop

;}
RECOMP_FUNC void update_menu_scene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DE98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DE9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DEA0: jal         0x800C7940
    // 0x8006DEA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    bgload_active(rdram, ctx);
        goto after_0;
    // 0x8006DEA4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006DEA8: bne         $v0, $zero, L_8006DF2C
    if (ctx->r2 != 0) {
        // 0x8006DEAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8006DF2C;
    }
    // 0x8006DEAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DEB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DEB4: jal         0x80010994
    // 0x8006DEB8: nop

    obj_update(rdram, ctx);
        goto after_1;
    // 0x8006DEB8: nop

    after_1:
    // 0x8006DEBC: jal         0x8001004C
    // 0x8006DEC0: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_2;
    // 0x8006DEC0: nop

    after_2:
    // 0x8006DEC4: jal         0x8001BF54
    // 0x8006DEC8: nop

    ainode_update(rdram, ctx);
        goto after_3;
    // 0x8006DEC8: nop

    after_3:
    // 0x8006DECC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8006DED0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DED4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006DED8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006DEDC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8006DEE0: addiu       $a3, $a3, 0x17A8
    ctx->r7 = ADD32(ctx->r7, 0X17A8);
    // 0x8006DEE4: addiu       $a2, $a2, 0x1798
    ctx->r6 = ADD32(ctx->r6, 0X1798);
    // 0x8006DEE8: addiu       $a1, $a1, 0x1788
    ctx->r5 = ADD32(ctx->r5, 0X1788);
    // 0x8006DEEC: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    // 0x8006DEF0: jal         0x80024D94
    // 0x8006DEF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_scene(rdram, ctx);
        goto after_4;
    // 0x8006DEF4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006DEF8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DEFC: jal         0x800C3998
    // 0x8006DF00: nop

    process_onscreen_textbox(rdram, ctx);
        goto after_5;
    // 0x8006DF00: nop

    after_5:
    // 0x8006DF04: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF08: jal         0x800784A4
    // 0x8006DF0C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    rdp_init(rdram, ctx);
        goto after_6;
    // 0x8006DF0C: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_6:
    // 0x8006DF10: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF14: jal         0x800774A0
    // 0x8006DF18: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_draw(rdram, ctx);
        goto after_7;
    // 0x8006DF18: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_7:
    // 0x8006DF1C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006DF20: jal         0x800776B8
    // 0x8006DF24: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    divider_clear_coverage(rdram, ctx);
        goto after_8;
    // 0x8006DF24: addiu       $a0, $a0, 0x1778
    ctx->r4 = ADD32(ctx->r4, 0X1778);
    after_8:
    // 0x8006DF28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8006DF2C:
    // 0x8006DF2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006DF30: jr          $ra
    // 0x8006DF34: nop

    return;
    // 0x8006DF34: nop

;}
RECOMP_FUNC void checkpoint_is_passed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018618: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8001861C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80018620: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x80018624: sw          $a3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r7;
    // 0x80018628: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8001862C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80018630: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80018634: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80018638: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8001863C: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x80018640: bne         $v0, $zero, L_80018650
    if (ctx->r2 != 0) {
        // 0x80018644: sw          $a2, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r6;
            goto L_80018650;
    }
    // 0x80018644: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x80018648: b           L_80018C8C
    // 0x8001864C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80018C8C;
    // 0x8001864C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80018650:
    // 0x80018650: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x80018654: addiu       $t0, $zero, 0x3C
    ctx->r8 = ADD32(0, 0X3C);
    // 0x80018658: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001865C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80018660: lw          $a2, -0x4BB4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BB4);
    // 0x80018664: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80018668: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001866C: mflo        $t1
    ctx->r9 = lo;
    // 0x80018670: addu        $v1, $t1, $a2
    ctx->r3 = ADD32(ctx->r9, ctx->r6);
    // 0x80018674: beq         $t7, $zero, L_80018684
    if (ctx->r15 == 0) {
        // 0x80018678: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80018684;
    }
    // 0x80018678: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8001867C: b           L_80018694
    // 0x80018680: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
        goto L_80018694;
    // 0x80018680: addiu       $a0, $v1, -0x3C
    ctx->r4 = ADD32(ctx->r3, -0X3C);
L_80018684:
    // 0x80018684: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018688: mflo        $t8
    ctx->r24 = lo;
    // 0x8001868C: addu        $a0, $t8, $a2
    ctx->r4 = ADD32(ctx->r24, ctx->r6);
    // 0x80018690: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
L_80018694:
    // 0x80018694: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x80018698: nop

    // 0x8001869C: beq         $v1, $zero, L_800186E4
    if (ctx->r3 == 0) {
        // 0x800186A0: nop
    
            goto L_800186E4;
    }
    // 0x800186A0: nop

    // 0x800186A4: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x800186A8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800186AC: beq         $t2, $v0, L_800186C4
    if (ctx->r10 == ctx->r2) {
        // 0x800186B0: nop
    
            goto L_800186C4;
    }
    // 0x800186B0: nop

    // 0x800186B4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186B8: mflo        $t4
    ctx->r12 = lo;
    // 0x800186BC: addu        $a1, $t4, $a2
    ctx->r5 = ADD32(ctx->r12, ctx->r6);
    // 0x800186C0: nop

L_800186C4:
    // 0x800186C4: lb          $v0, 0x3A($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3A);
    // 0x800186C8: nop

    // 0x800186CC: beq         $t2, $v0, L_800186E4
    if (ctx->r10 == ctx->r2) {
        // 0x800186D0: nop
    
            goto L_800186E4;
    }
    // 0x800186D0: nop

    // 0x800186D4: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800186D8: mflo        $t5
    ctx->r13 = lo;
    // 0x800186DC: addu        $a0, $t5, $a2
    ctx->r4 = ADD32(ctx->r13, ctx->r6);
    // 0x800186E0: nop

L_800186E4:
    // 0x800186E4: bne         $v1, $zero, L_800187AC
    if (ctx->r3 != 0) {
        // 0x800186E8: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800187AC;
    }
    // 0x800186E8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800186EC: lb          $t6, 0x3A($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3A);
    // 0x800186F0: nop

    // 0x800186F4: bne         $t2, $t6, L_800187AC
    if (ctx->r10 != ctx->r14) {
        // 0x800186F8: nop
    
            goto L_800187AC;
    }
    // 0x800186F8: nop

    // 0x800186FC: lb          $v0, 0x3A($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X3A);
    // 0x80018700: nop

    // 0x80018704: beq         $t2, $v0, L_800187AC
    if (ctx->r10 == ctx->r2) {
        // 0x80018708: nop
    
            goto L_800187AC;
    }
    // 0x80018708: nop

    // 0x8001870C: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018710: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018714: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018718: mflo        $t7
    ctx->r15 = lo;
    // 0x8001871C: addu        $v1, $t7, $a2
    ctx->r3 = ADD32(ctx->r15, ctx->r6);
    // 0x80018720: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80018724: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80018728: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8001872C: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018730: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80018734: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80018738: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001873C: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80018740: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80018744: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80018748: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8001874C: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x80018750: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80018754: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80018758: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001875C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018760: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80018764: jal         0x800CA030
    // 0x80018768: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018768: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_0:
    // 0x8001876C: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80018770: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80018774: lh          $t8, 0x2C($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2C);
    // 0x80018778: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001877C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80018780: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80018784: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80018788: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x8001878C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80018790: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80018794: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80018798: bc1f        L_800187AC
    if (!c1cs) {
        // 0x8001879C: nop
    
            goto L_800187AC;
    }
    // 0x8001879C: nop

    // 0x800187A0: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800187A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800187A8: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_800187AC:
    // 0x800187AC: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800187B0: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800187B4: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800187B8: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800187BC: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187C0: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800187C4: sub.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800187C8: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800187CC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800187D0: sub.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800187D4: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x800187D8: swc1        $f2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f2.u32l;
    // 0x800187DC: mul.s       $f6, $f20, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800187E0: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800187E4: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800187E8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800187EC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800187F0: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800187F4: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800187F8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x800187FC: jal         0x800CA030
    // 0x80018800: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80018800: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_1:
    // 0x80018804: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80018808: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8001880C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80018810: c.lt.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d < ctx->f6.d;
    // 0x80018814: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80018818: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8001881C: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x80018820: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80018824: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80018828: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x8001882C: bc1f        L_80018860
    if (!c1cs) {
        // 0x80018830: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_80018860;
    }
    // 0x80018830: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80018834: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018838: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001883C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018840: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018844: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018848: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001884C: nop

    // 0x80018850: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80018854: swc1        $f10, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f10.u32l;
    // 0x80018858: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001885C: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_80018860:
    // 0x80018860: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018864: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018868: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001886C: mul.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80018870: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018874: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018878: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x8001887C: mul.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80018880: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80018884: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018888: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001888C: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018890: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018894: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018898: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001889C: mul.s       $f8, $f14, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x800188A0: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x800188A4: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800188A8: mul.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x800188AC: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800188B0: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800188B4: nop

    // 0x800188B8: mul.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800188BC: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800188C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800188C4: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x800188C8: neg.s       $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = -ctx->f6.fl;
    // 0x800188CC: nop

    // 0x800188D0: div.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800188D4: swc1        $f6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f6.u32l;
    // 0x800188D8: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800188DC: nop

    // 0x800188E0: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800188E4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800188E8: nop

    // 0x800188EC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800188F0: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800188F4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800188F8: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800188FC: lwc1        $f8, 0x3C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80018900: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80018904: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80018908: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001890C: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x80018910: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80018914: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80018918: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001891C: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018920: nop

    // 0x80018924: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80018928: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8001892C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018930: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018934: nop

    // 0x80018938: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8001893C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018940: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018944: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018948: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8001894C: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80018950: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018954: nop

    // 0x80018958: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8001895C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80018960: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80018964: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018968: nop

    // 0x8001896C: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80018970: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80018974: add.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80018978: nop

    // 0x8001897C: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018980: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018984: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80018988: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x8001898C: nop

    // 0x80018990: bc1t        L_800189A0
    if (c1cs) {
        // 0x80018994: nop
    
            goto L_800189A0;
    }
    // 0x80018994: nop

    // 0x80018998: b           L_800189A8
    // 0x8001899C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_800189A8;
    // 0x8001899C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_800189A0:
    // 0x800189A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800189A4: nop

L_800189A8:
    // 0x800189A8: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x800189AC: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x800189B0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800189B4: bne         $v1, $t9, L_80018A1C
    if (ctx->r3 != ctx->r25) {
        // 0x800189B8: nop
    
            goto L_80018A1C;
    }
    // 0x800189B8: nop

    // 0x800189BC: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x800189C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189C4: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800189C8: nop

    // 0x800189CC: bne         $t2, $t4, L_80018A1C
    if (ctx->r10 != ctx->r12) {
        // 0x800189D0: nop
    
            goto L_80018A1C;
    }
    // 0x800189D0: nop

    // 0x800189D4: lwc1        $f7, 0x5BB0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5BB0);
    // 0x800189D8: lwc1        $f6, 0x5BB4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5BB4);
    // 0x800189DC: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x800189E0: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x800189E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800189E8: bc1f        L_800189F8
    if (!c1cs) {
        // 0x800189EC: nop
    
            goto L_800189F8;
    }
    // 0x800189EC: nop

    // 0x800189F0: b           L_80018C8C
    // 0x800189F4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C8C;
    // 0x800189F4: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_800189F8:
    // 0x800189F8: lwc1        $f5, 0x5BB8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5BB8);
    // 0x800189FC: lwc1        $f4, 0x5BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5BBC);
    // 0x80018A00: nop

    // 0x80018A04: c.lt.d      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.d < ctx->f2.d;
    // 0x80018A08: nop

    // 0x80018A0C: bc1f        L_80018A1C
    if (!c1cs) {
        // 0x80018A10: nop
    
            goto L_80018A1C;
    }
    // 0x80018A10: nop

    // 0x80018A14: b           L_80018C8C
    // 0x80018A18: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
        goto L_80018C8C;
    // 0x80018A18: addiu       $v0, $zero, -0x64
    ctx->r2 = ADD32(0, -0X64);
L_80018A1C:
    // 0x80018A1C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80018A20: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80018A24: c.le.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl <= ctx->f2.fl;
    // 0x80018A28: nop

    // 0x80018A2C: bc1f        L_80018C4C
    if (!c1cs) {
        // 0x80018A30: nop
    
            goto L_80018C4C;
    }
    // 0x80018A30: nop

    // 0x80018A34: beq         $t3, $zero, L_80018A48
    if (ctx->r11 == 0) {
        // 0x80018A38: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80018A48;
    }
    // 0x80018A38: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80018A3C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x80018A40: b           L_80018A5C
    // 0x80018A44: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
        goto L_80018A5C;
    // 0x80018A44: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
L_80018A48:
    // 0x80018A48: lb          $t7, 0x3A($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X3A);
    // 0x80018A4C: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80018A50: bne         $t2, $t7, L_80018A5C
    if (ctx->r10 != ctx->r15) {
        // 0x80018A54: nop
    
            goto L_80018A5C;
    }
    // 0x80018A54: nop

    // 0x80018A58: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
L_80018A5C:
    // 0x80018A5C: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018A60: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80018A64: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018A68: mul.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018A6C: lwc1        $f10, 0x84($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80018A70: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80018A74: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018A78: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80018A7C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018A80: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018A84: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80018A88: lwc1        $f6, 0x88($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80018A8C: nop

    // 0x80018A90: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80018A94: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018A98: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018A9C: add.s       $f20, $f10, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018AA0: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x80018AA4: nop

    // 0x80018AA8: bc1f        L_80018C40
    if (!c1cs) {
        // 0x80018AAC: nop
    
            goto L_80018C40;
    }
    // 0x80018AAC: nop

    // 0x80018AB0: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80018AB4: nop

    // 0x80018AB8: bne         $v1, $t9, L_80018AD8
    if (ctx->r3 != ctx->r25) {
        // 0x80018ABC: nop
    
            goto L_80018AD8;
    }
    // 0x80018ABC: nop

    // 0x80018AC0: lbu         $v1, 0x3B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3B);
    // 0x80018AC4: lw          $v0, 0x64($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X64);
    // 0x80018AC8: beq         $v1, $zero, L_80018AD8
    if (ctx->r3 == 0) {
        // 0x80018ACC: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_80018AD8;
    }
    // 0x80018ACC: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x80018AD0: sb          $v1, 0x1F8($v0)
    MEM_B(0X1F8, ctx->r2) = ctx->r3;
    // 0x80018AD4: sb          $t4, 0x1F9($v0)
    MEM_B(0X1F9, ctx->r2) = ctx->r12;
L_80018AD8:
    // 0x80018AD8: lw          $t5, -0x4BB0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BB0);
    // 0x80018ADC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80018AE0: bne         $t0, $t5, L_80018AEC
    if (ctx->r8 != ctx->r13) {
        // 0x80018AE4: addiu       $t1, $t1, 0x3C
        ctx->r9 = ADD32(ctx->r9, 0X3C);
            goto L_80018AEC;
    }
    // 0x80018AE4: addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // 0x80018AE8: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80018AEC:
    // 0x80018AEC: lw          $t6, -0x4BB4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BB4);
    // 0x80018AF0: lwc1        $f0, 0xC($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80018AF4: addu        $a1, $t1, $t6
    ctx->r5 = ADD32(ctx->r9, ctx->r14);
    // 0x80018AF8: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80018AFC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80018B00: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80018B04: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80018B08: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80018B0C: lwc1        $f12, 0x14($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80018B10: mul.s       $f8, $f16, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80018B14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018B18: mul.s       $f6, $f18, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80018B1C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B20: lwc1        $f8, 0xC($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80018B24: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018B28: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80018B2C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B30: mul.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80018B34: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
    // 0x80018B38: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B3C: mul.s       $f8, $f16, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80018B40: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018B44: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80018B48: nop

    // 0x80018B4C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x80018B50: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018B54: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018B58: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B5C: neg.s       $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = -ctx->f10.fl;
    // 0x80018B60: nop

    // 0x80018B64: div.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80018B68: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80018B6C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80018B70: nop

    // 0x80018B74: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80018B78: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80018B7C: nop

    // 0x80018B80: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80018B84: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80018B88: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x80018B8C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80018B90: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80018B94: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x80018B98: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80018B9C: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80018BA0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x80018BA4: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80018BA8: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80018BAC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80018BB0: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80018BB4: nop

    // 0x80018BB8: mul.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80018BBC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018BC0: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018BC4: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80018BC8: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x80018BCC: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80018BD0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80018BD4: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80018BD8: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x80018BDC: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80018BE0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80018BE4: nop

    // 0x80018BE8: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80018BEC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80018BF0: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80018BF4: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80018BF8: nop

    // 0x80018BFC: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80018C00: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80018C04: add.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018C08: nop

    // 0x80018C0C: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80018C10: add.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80018C14: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80018C18: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80018C1C: nop

    // 0x80018C20: bc1t        L_80018C30
    if (c1cs) {
        // 0x80018C24: nop
    
            goto L_80018C30;
    }
    // 0x80018C24: nop

    // 0x80018C28: b           L_80018C38
    // 0x80018C2C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
        goto L_80018C38;
    // 0x80018C2C: div.s       $f0, $f12, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f2.fl);
L_80018C30:
    // 0x80018C30: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80018C34: nop

L_80018C38:
    // 0x80018C38: b           L_80018C8C
    // 0x80018C3C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
        goto L_80018C8C;
    // 0x80018C3C: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
L_80018C40:
    // 0x80018C40: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x80018C44: b           L_80018C8C
    // 0x80018C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80018C8C;
    // 0x80018C48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80018C4C:
    // 0x80018C4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80018C50: nop

    // 0x80018C54: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80018C58: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80018C5C: nop

    // 0x80018C60: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80018C64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80018C68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80018C6C: nop

    // 0x80018C70: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80018C74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80018C78: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80018C7C: bne         $v0, $zero, L_80018C88
    if (ctx->r2 != 0) {
        // 0x80018C80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80018C88;
    }
    // 0x80018C80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80018C84: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
L_80018C88:
    // 0x80018C88: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80018C8C:
    // 0x80018C8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80018C90: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80018C94: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80018C98: jr          $ra
    // 0x80018C9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80018C9C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void reformat_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007601C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076024: jal         0x80075B34
    // 0x80076028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80076028: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8007602C: beq         $v0, $zero, L_80076044
    if (ctx->r2 == 0) {
        // 0x80076030: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80076044;
    }
    // 0x80076030: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80076034: beq         $v0, $at, L_80076044
    if (ctx->r2 == ctx->r1) {
        // 0x80076038: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076044;
    }
    // 0x80076038: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007603C: bne         $v0, $at, L_8007609C
    if (ctx->r2 != ctx->r1) {
        // 0x80076040: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8007609C;
    }
    // 0x80076040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076044:
    // 0x80076044: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80076048: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007604C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x80076050: subu        $t6, $t6, $a2
    ctx->r14 = SUB32(ctx->r14, ctx->r6);
    // 0x80076054: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80076058: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007605C: addu        $t6, $t6, $a2
    ctx->r14 = ADD32(ctx->r14, ctx->r6);
    // 0x80076060: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80076064: lw          $a1, 0x4590($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4590);
    // 0x80076068: addiu       $t7, $t7, 0x4598
    ctx->r15 = ADD32(ctx->r15, 0X4598);
    // 0x8007606C: jal         0x800D04F0
    // 0x80076070: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    osPfsReFormat(rdram, ctx);
        goto after_1;
    // 0x80076070: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80076074: bne         $v0, $zero, L_80076084
    if (ctx->r2 != 0) {
        // 0x80076078: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80076084;
    }
    // 0x80076078: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007607C: b           L_8007609C
    // 0x80076080: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8007609C;
    // 0x80076080: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80076084:
    // 0x80076084: bne         $v0, $at, L_80076094
    if (ctx->r2 != ctx->r1) {
        // 0x80076088: nop
    
            goto L_80076094;
    }
    // 0x80076088: nop

    // 0x8007608C: b           L_8007609C
    // 0x80076090: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007609C;
    // 0x80076090: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_80076094:
    // 0x80076094: b           L_8007609C
    // 0x80076098: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8007609C;
    // 0x80076098: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8007609C:
    // 0x8007609C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800760A0: jal         0x80075D44
    // 0x800760A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x800760A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800760A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800760AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800760B0: jr          $ra
    // 0x800760B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800760B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800214E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002151C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021520: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x80021524: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80021528: lb          $t6, 0x3A($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X3A);
    // 0x8002152C: nop

    // 0x80021530: beq         $t6, $zero, L_80021548
    if (ctx->r14 == 0) {
        // 0x80021534: nop
    
            goto L_80021548;
    }
    // 0x80021534: nop

    // 0x80021538: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x8002153C: nop

    // 0x80021540: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80021544: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80021548:
    // 0x80021548: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x8002154C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80021550: bne         $v1, $v0, L_80021564
    if (ctx->r3 != ctx->r2) {
        // 0x80021554: nop
    
            goto L_80021564;
    }
    // 0x80021554: nop

    // 0x80021558: lb          $v0, 0x3A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X3A);
    // 0x8002155C: b           L_80021628
    // 0x80021560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80021628;
    // 0x80021560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021564:
    // 0x80021564: bltz        $v0, L_80021578
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021568: subu        $t9, $v0, $a1
        ctx->r25 = SUB32(ctx->r2, ctx->r5);
            goto L_80021578;
    }
    // 0x80021568: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x8002156C: sh          $t9, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r25;
    // 0x80021570: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021574: nop

L_80021578:
    // 0x80021578: bne         $v1, $v0, L_8002158C
    if (ctx->r3 != ctx->r2) {
        // 0x8002157C: addiu       $t0, $zero, -0x2
        ctx->r8 = ADD32(0, -0X2);
            goto L_8002158C;
    }
    // 0x8002157C: addiu       $t0, $zero, -0x2
    ctx->r8 = ADD32(0, -0X2);
    // 0x80021580: sh          $t0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r8;
    // 0x80021584: lh          $v0, 0x36($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X36);
    // 0x80021588: nop

L_8002158C:
    // 0x8002158C: bgtz        $v0, L_80021620
    if (SIGNED(ctx->r2) > 0) {
        // 0x80021590: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80021620;
    }
    // 0x80021590: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80021594: lh          $t1, 0x6($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X6);
    // 0x80021598: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002159C: ori         $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 | 0X4000;
    // 0x800215A0: sh          $t2, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r10;
    // 0x800215A4: lh          $a1, -0x4C08($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X4C08);
    // 0x800215A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800215AC: blez        $a1, L_80021600
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800215B0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80021600;
    }
    // 0x800215B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800215B4: lw          $a0, -0x4C0C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C0C);
    // 0x800215B8: lh          $v1, 0x28($a2)
    ctx->r3 = MEM_H(ctx->r6, 0X28);
    // 0x800215BC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800215C0: nop

    // 0x800215C4: lw          $t4, 0x7C($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X7C);
    // 0x800215C8: nop

    // 0x800215CC: beq         $v1, $t4, L_80021600
    if (ctx->r3 == ctx->r12) {
        // 0x800215D0: nop
    
            goto L_80021600;
    }
    // 0x800215D0: nop

L_800215D4:
    // 0x800215D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800215D8: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800215DC: beq         $at, $zero, L_80021600
    if (ctx->r1 == 0) {
        // 0x800215E0: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80021600;
    }
    // 0x800215E0: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800215E4: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x800215E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800215EC: nop

    // 0x800215F0: lw          $t8, 0x7C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X7C);
    // 0x800215F4: nop

    // 0x800215F8: bne         $v1, $t8, L_800215D4
    if (ctx->r3 != ctx->r24) {
        // 0x800215FC: nop
    
            goto L_800215D4;
    }
    // 0x800215FC: nop

L_80021600:
    // 0x80021600: lw          $t9, -0x4C0C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C0C);
    // 0x80021604: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x80021608: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8002160C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80021610: jal         0x8001EFD8
    // 0x80021614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_0;
    // 0x80021614: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
    // 0x80021618: b           L_80021624
    // 0x8002161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80021624;
    // 0x8002161C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80021620:
    // 0x80021620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80021624:
    // 0x80021624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021628:
    // 0x80021628: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002162C: jr          $ra
    // 0x80021630: nop

    return;
    // 0x80021630: nop

;}
RECOMP_FUNC void menu_caution_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C86C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x8008C870: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008C874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C878: sw          $t6, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = ctx->r14;
    // 0x8008C87C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C880: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C884: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008C888: jal         0x800C46D0
    // 0x8008C88C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008C88C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C890: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C894: jal         0x800C06F8
    // 0x8008C898: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x8008C898: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_1:
    // 0x8008C89C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C8A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008C8A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008C8A8: sw          $t7, -0x5E8($at)
    MEM_W(-0X5E8, ctx->r1) = ctx->r15;
    // 0x8008C8AC: jr          $ra
    // 0x8008C8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008C8B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void light_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032CAC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80032CB0: lw          $v0, -0x3134($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3134);
    // 0x80032CB4: jr          $ra
    // 0x80032CB8: nop

    return;
    // 0x80032CB8: nop

;}
RECOMP_FUNC void alRaw16Pull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CBC74: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CBC78: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBC7C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CBC80: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CBC84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CBC88: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800CBC8C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CBC90: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CBC94: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CBC98: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800CBC9C: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800CBCA0: bne         $a2, $zero, L_800CBCB0
    if (ctx->r6 != 0) {
        // 0x800CBCA4: or          $t1, $t0, $zero
        ctx->r9 = ctx->r8 | 0;
            goto L_800CBCB0;
    }
    // 0x800CBCA4: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x800CBCA8: b           L_800CC004
    // 0x800CBCAC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_800CC004;
    // 0x800CBCAC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_800CBCB0:
    // 0x800CBCB0: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800CBCB4: lw          $v1, 0x20($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X20);
    // 0x800CBCB8: addu        $t6, $v0, $s3
    ctx->r14 = ADD32(ctx->r2, ctx->r19);
    // 0x800CBCBC: sltu        $at, $v1, $t6
    ctx->r1 = ctx->r3 < ctx->r14 ? 1 : 0;
    // 0x800CBCC0: beql        $at, $zero, L_800CBED4
    if (ctx->r1 == 0) {
        // 0x800CBCC4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CBED4;
    }
    goto skip_0;
    // 0x800CBCC4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_0:
    // 0x800CBCC8: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x800CBCCC: subu        $s2, $v1, $v0
    ctx->r18 = SUB32(ctx->r3, ctx->r2);
    // 0x800CBCD0: beql        $t7, $zero, L_800CBED4
    if (ctx->r15 == 0) {
        // 0x800CBCD4: lw          $v0, 0x28($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X28);
            goto L_800CBED4;
    }
    goto skip_1;
    // 0x800CBCD4: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x800CBCD8: blez        $s2, L_800CBD54
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800CBCDC: sll         $s1, $s2, 1
        ctx->r17 = S32(ctx->r18 << 1);
            goto L_800CBD54;
    }
    // 0x800CBCDC: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CBCE0: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBCE4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBCE8: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CBCEC: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBCF0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CBCF4: jalr        $t9
    // 0x800CBCF8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CBCF8: nop

    after_0:
    // 0x800CBCFC: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CBD00: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CBD04: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBD08: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD0C: addu        $a3, $s1, $a2
    ctx->r7 = ADD32(ctx->r17, ctx->r6);
    // 0x800CBD10: andi        $t5, $a3, 0x7
    ctx->r13 = ctx->r7 & 0X7;
    // 0x800CBD14: subu        $t6, $a3, $t5
    ctx->r14 = SUB32(ctx->r7, ctx->r13);
    // 0x800CBD18: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBD1C: andi        $t3, $t8, 0xFFFF
    ctx->r11 = ctx->r24 & 0XFFFF;
    // 0x800CBD20: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x800CBD24: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800CBD28: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CBD2C: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800CBD30: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBD34: subu        $t3, $v0, $a2
    ctx->r11 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBD38: lui         $t8, 0x400
    ctx->r24 = S32(0X400 << 16);
    // 0x800CBD3C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CBD40: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800CBD44: sw          $t3, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r11;
    // 0x800CBD48: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800CBD4C: b           L_800CBD58
    // 0x800CBD50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CBD58;
    // 0x800CBD50: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBD54:
    // 0x800CBD54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CBD58:
    // 0x800CBD58: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD5C: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CBD60: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x800CBD64: sh          $t5, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r13;
    // 0x800CBD68: lw          $t6, 0x28($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X28);
    // 0x800CBD6C: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x800CBD70: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800CBD74: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800CBD78: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800CBD7C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800CBD80: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800CBD84: beq         $at, $zero, L_800CBEAC
    if (ctx->r1 == 0) {
        // 0x800CBD88: lh          $t0, 0x0($t2)
        ctx->r8 = MEM_H(ctx->r10, 0X0);
            goto L_800CBEAC;
    }
    // 0x800CBD88: lh          $t0, 0x0($t2)
    ctx->r8 = MEM_H(ctx->r10, 0X0);
    // 0x800CBD8C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
L_800CBD90:
    // 0x800CBD90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800CBD94: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x800CBD98: beq         $v0, $at, L_800CBDAC
    if (ctx->r2 == ctx->r1) {
        // 0x800CBD9C: subu        $s3, $s3, $s2
        ctx->r19 = SUB32(ctx->r19, ctx->r18);
            goto L_800CBDAC;
    }
    // 0x800CBD9C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x800CBDA0: beq         $v0, $zero, L_800CBDAC
    if (ctx->r2 == 0) {
        // 0x800CBDA4: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800CBDAC;
    }
    // 0x800CBDA4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800CBDA8: sw          $t3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r11;
L_800CBDAC:
    // 0x800CBDAC: lw          $t4, 0x20($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X20);
    // 0x800CBDB0: lw          $t5, 0x1C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X1C);
    // 0x800CBDB4: subu        $v0, $t4, $t5
    ctx->r2 = SUB32(ctx->r12, ctx->r13);
    // 0x800CBDB8: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800CBDBC: beq         $at, $zero, L_800CBDCC
    if (ctx->r1 == 0) {
        // 0x800CBDC0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800CBDCC;
    }
    // 0x800CBDC0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800CBDC4: b           L_800CBDCC
    // 0x800CBDC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
        goto L_800CBDCC;
    // 0x800CBDC8: or          $s2, $s3, $zero
    ctx->r18 = ctx->r19 | 0;
L_800CBDCC:
    // 0x800CBDCC: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBDD0: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBDD4: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x800CBDD8: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x800CBDDC: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBDE0: sll         $s1, $s2, 1
    ctx->r17 = S32(ctx->r18 << 1);
    // 0x800CBDE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800CBDE8: jalr        $t9
    // 0x800CBDEC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CBDEC: nop

    after_1:
    // 0x800CBDF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CBDF4: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x800CBDF8: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CBDFC: andi        $v1, $t0, 0x7
    ctx->r3 = ctx->r8 & 0X7;
    // 0x800CBE00: beq         $v1, $zero, L_800CBE14
    if (ctx->r3 == 0) {
        // 0x800CBE04: addu        $a3, $s1, $a1
        ctx->r7 = ADD32(ctx->r17, ctx->r5);
            goto L_800CBE14;
    }
    // 0x800CBE04: addu        $a3, $s1, $a1
    ctx->r7 = ADD32(ctx->r17, ctx->r5);
    // 0x800CBE08: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x800CBE0C: b           L_800CBE18
    // 0x800CBE10: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
        goto L_800CBE18;
    // 0x800CBE10: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
L_800CBE14:
    // 0x800CBE14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800CBE18:
    // 0x800CBE18: addu        $t7, $t0, $a2
    ctx->r15 = ADD32(ctx->r8, ctx->r6);
    // 0x800CBE1C: andi        $t4, $a3, 0x7
    ctx->r12 = ctx->r7 & 0X7;
    // 0x800CBE20: subu        $t5, $a3, $t4
    ctx->r13 = SUB32(ctx->r7, ctx->r12);
    // 0x800CBE24: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x800CBE28: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800CBE2C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBE30: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CBE34: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CBE38: addiu       $t9, $t5, 0x8
    ctx->r25 = ADD32(ctx->r13, 0X8);
    // 0x800CBE3C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x800CBE40: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBE44: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800CBE48: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800CBE4C: subu        $t8, $v0, $a1
    ctx->r24 = SUB32(ctx->r2, ctx->r5);
    // 0x800CBE50: lui         $t7, 0x400
    ctx->r15 = S32(0X400 << 16);
    // 0x800CBE54: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800CBE58: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CBE5C: bne         $a1, $zero, L_800CBE68
    if (ctx->r5 != 0) {
        // 0x800CBE60: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_800CBE68;
    }
    // 0x800CBE60: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800CBE64: beq         $a2, $zero, L_800CBEA0
    if (ctx->r6 == 0) {
        // 0x800CBE68: addu        $t3, $t0, $a1
        ctx->r11 = ADD32(ctx->r8, ctx->r5);
            goto L_800CBEA0;
    }
L_800CBE68:
    // 0x800CBE68: addu        $t3, $t0, $a1
    ctx->r11 = ADD32(ctx->r8, ctx->r5);
    // 0x800CBE6C: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBE70: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBE74: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x800CBE78: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x800CBE7C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBE80: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CBE84: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800CBE88: andi        $t8, $s1, 0xFFFF
    ctx->r24 = ctx->r17 & 0XFFFF;
    // 0x800CBE8C: or          $t3, $t7, $t8
    ctx->r11 = ctx->r15 | ctx->r24;
    // 0x800CBE90: or          $t9, $t5, $at
    ctx->r25 = ctx->r13 | ctx->r1;
    // 0x800CBE94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800CBE98: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800CBE9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBEA0:
    // 0x800CBEA0: slt         $at, $s2, $s3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800CBEA4: bnel        $at, $zero, L_800CBD90
    if (ctx->r1 != 0) {
        // 0x800CBEA8: lw          $v0, 0x24($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X24);
            goto L_800CBD90;
    }
    goto skip_2;
    // 0x800CBEA8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    skip_2:
L_800CBEAC:
    // 0x800CBEAC: lw          $t4, 0x38($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X38);
    // 0x800CBEB0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CBEB4: sll         $t6, $s3, 1
    ctx->r14 = S32(ctx->r19 << 1);
    // 0x800CBEB8: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x800CBEBC: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800CBEC0: sw          $t5, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r13;
    // 0x800CBEC4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800CBEC8: b           L_800CC004
    // 0x800CBECC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
        goto L_800CC004;
    // 0x800CBECC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBED0: lw          $v0, 0x28($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X28);
L_800CBED4:
    // 0x800CBED4: lw          $a0, 0x44($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X44);
    // 0x800CBED8: sll         $s1, $s3, 1
    ctx->r17 = S32(ctx->r19 << 1);
    // 0x800CBEDC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800CBEE0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x800CBEE4: addu        $v1, $a0, $s1
    ctx->r3 = ADD32(ctx->r4, ctx->r17);
    // 0x800CBEE8: subu        $t3, $v1, $t8
    ctx->r11 = SUB32(ctx->r3, ctx->r24);
    // 0x800CBEEC: subu        $s2, $t3, $t4
    ctx->r18 = SUB32(ctx->r11, ctx->r12);
    // 0x800CBEF0: bgezl       $s2, L_800CBF00
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800CBEF4: slt         $at, $s1, $s2
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800CBF00;
    }
    goto skip_3;
    // 0x800CBEF4: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
    skip_3:
    // 0x800CBEF8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800CBEFC: slt         $at, $s1, $s2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r18) ? 1 : 0;
L_800CBF00:
    // 0x800CBF00: beql        $at, $zero, L_800CBF10
    if (ctx->r1 == 0) {
        // 0x800CBF04: slt         $at, $s2, $s1
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
            goto L_800CBF10;
    }
    goto skip_4;
    // 0x800CBF04: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
    skip_4:
    // 0x800CBF08: or          $s2, $s1, $zero
    ctx->r18 = ctx->r17 | 0;
    // 0x800CBF0C: slt         $at, $s2, $s1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r17) ? 1 : 0;
L_800CBF10:
    // 0x800CBF10: beql        $at, $zero, L_800CBFC4
    if (ctx->r1 == 0) {
        // 0x800CBF14: sw          $v1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r3;
            goto L_800CBFC4;
    }
    goto skip_5;
    // 0x800CBF14: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
    skip_5:
    // 0x800CBF18: blez        $s3, L_800CBF98
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800CBF1C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800CBF98;
    }
    // 0x800CBF1C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CBF20: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800CBF24: subu        $a1, $s1, $s2
    ctx->r5 = SUB32(ctx->r17, ctx->r18);
    // 0x800CBF28: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800CBF2C: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    // 0x800CBF30: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800CBF34: jalr        $t9
    // 0x800CBF38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CBF38: nop

    after_2:
    // 0x800CBF3C: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x800CBF40: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CBF44: andi        $a2, $v0, 0x7
    ctx->r6 = ctx->r2 & 0X7;
    // 0x800CBF48: lh          $t5, 0x0($t2)
    ctx->r13 = MEM_H(ctx->r10, 0X0);
    // 0x800CBF4C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800CBF50: addu        $a3, $a3, $a2
    ctx->r7 = ADD32(ctx->r7, ctx->r6);
    // 0x800CBF54: andi        $t8, $a3, 0x7
    ctx->r24 = ctx->r7 & 0X7;
    // 0x800CBF58: subu        $t3, $a3, $t8
    ctx->r11 = SUB32(ctx->r7, ctx->r24);
    // 0x800CBF5C: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CBF60: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CBF64: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CBF68: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800CBF6C: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x800CBF70: andi        $t9, $t4, 0xFFFF
    ctx->r25 = ctx->r12 & 0XFFFF;
    // 0x800CBF74: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CBF78: subu        $t6, $v0, $a2
    ctx->r14 = SUB32(ctx->r2, ctx->r6);
    // 0x800CBF7C: lui         $t5, 0x400
    ctx->r13 = S32(0X400 << 16);
    // 0x800CBF80: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800CBF84: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x800CBF88: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800CBF8C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800CBF90: b           L_800CBF98
    // 0x800CBF94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_800CBF98;
    // 0x800CBF94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CBF98:
    // 0x800CBF98: lh          $t7, 0x0($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X0);
    // 0x800CBF9C: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800CBFA0: sh          $t8, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r24;
    // 0x800CBFA4: lw          $t3, 0x38($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X38);
    // 0x800CBFA8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x800CBFAC: addu        $t4, $t3, $s3
    ctx->r12 = ADD32(ctx->r11, ctx->r19);
    // 0x800CBFB0: addu        $t5, $t9, $s1
    ctx->r13 = ADD32(ctx->r25, ctx->r17);
    // 0x800CBFB4: sw          $t4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r12;
    // 0x800CBFB8: b           L_800CBFC4
    // 0x800CBFBC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
        goto L_800CBFC4;
    // 0x800CBFBC: sw          $t5, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r13;
    // 0x800CBFC0: sw          $v1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r3;
L_800CBFC4:
    // 0x800CBFC4: beq         $s2, $zero, L_800CC000
    if (ctx->r18 == 0) {
        // 0x800CBFC8: subu        $v1, $s1, $s2
        ctx->r3 = SUB32(ctx->r17, ctx->r18);
            goto L_800CC000;
    }
    // 0x800CBFC8: subu        $v1, $s1, $s2
    ctx->r3 = SUB32(ctx->r17, ctx->r18);
    // 0x800CBFCC: bgez        $v1, L_800CBFD8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800CBFD0: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800CBFD8;
    }
    // 0x800CBFD0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800CBFD4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800CBFD8:
    // 0x800CBFD8: lh          $t6, 0x0($t2)
    ctx->r14 = MEM_H(ctx->r10, 0X0);
    // 0x800CBFDC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CBFE0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CBFE4: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x800CBFE8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CBFEC: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x800CBFF0: or          $t3, $t8, $at
    ctx->r11 = ctx->r24 | ctx->r1;
    // 0x800CBFF4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800CBFF8: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800CBFFC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800CC000:
    // 0x800CC000: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_800CC004:
    // 0x800CC004: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CC008: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CC00C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CC010: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC014: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CC018: jr          $ra
    // 0x800CC01C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800CC01C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void obj_loop_dino_whale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003923C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80039240: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80039244: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80039248: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8003924C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80039250: blez        $v0, L_8003926C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80039254: or          $a2, $s0, $zero
        ctx->r6 = ctx->r16 | 0;
            goto L_8003926C;
    }
    // 0x80039254: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80039258: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8003925C: sll         $t7, $a1, 1
    ctx->r15 = S32(ctx->r5 << 1);
    // 0x80039260: sw          $t6, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r14;
    // 0x80039264: b           L_80039270
    // 0x80039268: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
        goto L_80039270;
    // 0x80039268: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8003926C:
    // 0x8003926C: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_80039270:
    // 0x80039270: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80039274: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039278: jal         0x8001F494
    // 0x8003927C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x8003927C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_0:
    // 0x80039280: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80039284: addiu       $t9, $zero, 0xAD
    ctx->r25 = ADD32(0, 0XAD);
    // 0x80039288: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8003928C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80039290: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80039294: jal         0x800113CC
    // 0x80039298: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_1;
    // 0x80039298: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_1:
    // 0x8003929C: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x800392A0: nop

    // 0x800392A4: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x800392A8: nop

    // 0x800392AC: slti        $at, $t1, 0xFF
    ctx->r1 = SIGNED(ctx->r9) < 0XFF ? 1 : 0;
    // 0x800392B0: beq         $at, $zero, L_800392EC
    if (ctx->r1 == 0) {
        // 0x800392B4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800392EC;
    }
    // 0x800392B4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800392B8: lw          $t2, 0x78($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X78);
    // 0x800392BC: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800392C0: bne         $t2, $zero, L_800392E8
    if (ctx->r10 != 0) {
        // 0x800392C4: addiu       $a0, $zero, 0x23B
        ctx->r4 = ADD32(0, 0X23B);
            goto L_800392E8;
    }
    // 0x800392C4: addiu       $a0, $zero, 0x23B
    ctx->r4 = ADD32(0, 0X23B);
    // 0x800392C8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800392CC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800392D0: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x800392D4: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x800392D8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800392DC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800392E0: jal         0x80009558
    // 0x800392E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x800392E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
L_800392E8:
    // 0x800392E8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800392EC:
    // 0x800392EC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800392F0: jr          $ra
    // 0x800392F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800392F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void savemenu_input_message(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087BA4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80087BA8: lw          $a2, 0x695C($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X695C);
    // 0x80087BAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80087BB0: sll         $t6, $a2, 3
    ctx->r14 = S32(ctx->r6 << 3);
    // 0x80087BB4: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80087BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087BBC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80087BC0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80087BC4: bne         $at, $zero, L_80087BD4
    if (ctx->r1 != 0) {
        // 0x80087BC8: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80087BD4;
    }
    // 0x80087BC8: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80087BCC: addiu       $t7, $zero, 0x1FF
    ctx->r15 = ADD32(0, 0X1FF);
    // 0x80087BD0: subu        $a2, $t7, $t6
    ctx->r6 = SUB32(ctx->r15, ctx->r14);
L_80087BD4:
    // 0x80087BD4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087BD8: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087BDC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80087BE0: lw          $t0, 0x0($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X0);
    // 0x80087BE4: addiu       $a1, $a1, 0x7034
    ctx->r5 = ADD32(ctx->r5, 0X7034);
    // 0x80087BE8: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80087BEC: andi        $t8, $t0, 0x7
    ctx->r24 = ctx->r8 & 0X7;
    // 0x80087BF0: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x80087BF4: blez        $a0, L_80087C48
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80087BF8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80087C48;
    }
    // 0x80087BF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80087BFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087C00: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087C04: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087C08: addiu       $v0, $v0, 0x7040
    ctx->r2 = ADD32(ctx->r2, 0X7040);
L_80087C0C:
    // 0x80087C0C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80087C10: nop

    // 0x80087C14: bne         $v1, $t9, L_80087C28
    if (ctx->r3 != ctx->r25) {
        // 0x80087C18: nop
    
            goto L_80087C28;
    }
    // 0x80087C18: nop

    // 0x80087C1C: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x80087C20: b           L_80087C34
    // 0x80087C24: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
        goto L_80087C34;
    // 0x80087C24: sb          $a2, 0x13($t2)
    MEM_B(0X13, ctx->r10) = ctx->r6;
L_80087C28:
    // 0x80087C28: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80087C2C: nop

    // 0x80087C30: sb          $zero, 0x13($t3)
    MEM_B(0X13, ctx->r11) = 0;
L_80087C34:
    // 0x80087C34: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80087C38: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80087C3C: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80087C40: bne         $at, $zero, L_80087C0C
    if (ctx->r1 != 0) {
        // 0x80087C44: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80087C0C;
    }
    // 0x80087C44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80087C48:
    // 0x80087C48: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80087C4C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087C50: andi        $t5, $t4, 0x4000
    ctx->r13 = ctx->r12 & 0X4000;
    // 0x80087C54: bne         $t5, $zero, L_80087C7C
    if (ctx->r13 != 0) {
        // 0x80087C58: addiu       $a3, $a3, 0x7038
        ctx->r7 = ADD32(ctx->r7, 0X7038);
            goto L_80087C7C;
    }
    // 0x80087C58: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087C5C: andi        $v0, $t4, 0x9000
    ctx->r2 = ctx->r12 & 0X9000;
    // 0x80087C60: beq         $v0, $zero, L_80087E34
    if (ctx->r2 == 0) {
        // 0x80087C64: nop
    
            goto L_80087E34;
    }
    // 0x80087C64: nop

    // 0x80087C68: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80087C6C: nop

    // 0x80087C70: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087C74: bne         $t7, $a0, L_80087E34
    if (ctx->r15 != ctx->r4) {
        // 0x80087C78: nop
    
            goto L_80087E34;
    }
    // 0x80087C78: nop

L_80087C7C:
    // 0x80087C7C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087C80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087C84: jal         0x80001D04
    // 0x80087C88: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087C88: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_0:
    // 0x80087C8C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087C90: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087C94: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80087C98: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087C9C: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80087CA0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80087CA4: beq         $t0, $zero, L_80087CD8
    if (ctx->r8 == 0) {
        // 0x80087CA8: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80087CD8;
    }
    // 0x80087CA8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80087CAC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087CB0: beq         $t0, $at, L_80087CFC
    if (ctx->r8 == ctx->r1) {
        // 0x80087CB4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_80087CFC;
    }
    // 0x80087CB4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80087CB8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087CBC: beq         $t0, $v0, L_80087D70
    if (ctx->r8 == ctx->r2) {
        // 0x80087CC0: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80087D70;
    }
    // 0x80087CC0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80087CC4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087CC8: beq         $t0, $at, L_80087DE4
    if (ctx->r8 == ctx->r1) {
        // 0x80087CCC: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_80087DE4;
    }
    // 0x80087CCC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80087CD0: b           L_80087FC4
    // 0x80087CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087FC4;
    // 0x80087CD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087CD8:
    // 0x80087CD8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80087CDC: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x80087CE0: andi        $t3, $t2, 0x9000
    ctx->r11 = ctx->r10 & 0X9000;
    // 0x80087CE4: bne         $t3, $zero, L_80087FC0
    if (ctx->r11 != 0) {
        // 0x80087CE8: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087FC0;
    }
    // 0x80087CE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087CEC: sw          $t5, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r13;
    // 0x80087CF0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087CF4: b           L_80087FC0
    // 0x80087CF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087FC0;
    // 0x80087CF8: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80087CFC:
    // 0x80087CFC: lw          $t6, 0x5C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5C);
    // 0x80087D00: nop

    // 0x80087D04: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80087D08: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x80087D0C: beq         $at, $zero, L_80087D60
    if (ctx->r1 == 0) {
        // 0x80087D10: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80087D60;
    }
    // 0x80087D10: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80087D14: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087D18: addu        $at, $at, $t7
    gpr jr_addend_80087D24 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80087D1C: lw          $t7, -0x7630($at)
    ctx->r15 = ADD32(ctx->r1, -0X7630);
    // 0x80087D20: nop

    // 0x80087D24: jr          $t7
    // 0x80087D28: nop

    switch (jr_addend_80087D24 >> 2) {
        case 0: goto L_80087D44; break;
        case 1: goto L_80087D44; break;
        case 2: goto L_80087D44; break;
        case 3: goto L_80087D60; break;
        case 4: goto L_80087D2C; break;
        case 5: goto L_80087D60; break;
        case 6: goto L_80087D50; break;
        case 7: goto L_80087D60; break;
        case 8: goto L_80087D44; break;
        default: switch_error(__func__, 0x80087D24, 0x800E89D0);
    }
    // 0x80087D28: nop

L_80087D2C:
    // 0x80087D2C: addiu       $t8, $zero, 0x5
    ctx->r24 = ADD32(0, 0X5);
    // 0x80087D30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D34: sw          $t8, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r24;
    // 0x80087D38: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087D3C: b           L_80087FC0
    // 0x80087D40: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_80087FC0;
    // 0x80087D40: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_80087D44:
    // 0x80087D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D48: b           L_80087FC0
    // 0x80087D4C: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087D4C: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
L_80087D50:
    // 0x80087D50: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80087D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D58: b           L_80087FC0
    // 0x80087D5C: sw          $t2, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r10;
        goto L_80087FC0;
    // 0x80087D5C: sw          $t2, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r10;
L_80087D60:
    // 0x80087D60: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80087D64: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D68: b           L_80087FC0
    // 0x80087D6C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
        goto L_80087FC0;
    // 0x80087D6C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
L_80087D70:
    // 0x80087D70: lw          $t5, 0x5C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5C);
    // 0x80087D74: nop

    // 0x80087D78: addiu       $t4, $t5, -0x1
    ctx->r12 = ADD32(ctx->r13, -0X1);
    // 0x80087D7C: sltiu       $at, $t4, 0x9
    ctx->r1 = ctx->r12 < 0X9 ? 1 : 0;
    // 0x80087D80: beq         $at, $zero, L_80087DD4
    if (ctx->r1 == 0) {
        // 0x80087D84: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_80087DD4;
    }
    // 0x80087D84: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80087D88: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087D8C: addu        $at, $at, $t4
    gpr jr_addend_80087D98 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80087D90: lw          $t4, -0x760C($at)
    ctx->r12 = ADD32(ctx->r1, -0X760C);
    // 0x80087D94: nop

    // 0x80087D98: jr          $t4
    // 0x80087D9C: nop

    switch (jr_addend_80087D98 >> 2) {
        case 0: goto L_80087DA0; break;
        case 1: goto L_80087DB8; break;
        case 2: goto L_80087DB8; break;
        case 3: goto L_80087DD4; break;
        case 4: goto L_80087DA0; break;
        case 5: goto L_80087DD4; break;
        case 6: goto L_80087DC4; break;
        case 7: goto L_80087DD4; break;
        case 8: goto L_80087DB8; break;
        default: switch_error(__func__, 0x80087D98, 0x800E89F4);
    }
    // 0x80087D9C: nop

L_80087DA0:
    // 0x80087DA0: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80087DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DA8: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x80087DAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80087DB0: b           L_80087FC0
    // 0x80087DB4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
        goto L_80087FC0;
    // 0x80087DB4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
L_80087DB8:
    // 0x80087DB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DBC: b           L_80087FC0
    // 0x80087DC0: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087DC0: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
L_80087DC4:
    // 0x80087DC4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80087DC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DCC: b           L_80087FC0
    // 0x80087DD0: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
        goto L_80087FC0;
    // 0x80087DD0: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
L_80087DD4:
    // 0x80087DD4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087DD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DDC: b           L_80087FC0
    // 0x80087DE0: sw          $t9, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r25;
        goto L_80087FC0;
    // 0x80087DE0: sw          $t9, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r25;
L_80087DE4:
    // 0x80087DE4: lw          $t2, 0x5C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5C);
    // 0x80087DE8: nop

    // 0x80087DEC: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x80087DF0: sltiu       $at, $t3, 0xA
    ctx->r1 = ctx->r11 < 0XA ? 1 : 0;
    // 0x80087DF4: beq         $at, $zero, L_80087FC0
    if (ctx->r1 == 0) {
        // 0x80087DF8: sll         $t3, $t3, 2
        ctx->r11 = S32(ctx->r11 << 2);
            goto L_80087FC0;
    }
    // 0x80087DF8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80087DFC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087E00: addu        $at, $at, $t3
    gpr jr_addend_80087E0C = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80087E04: lw          $t3, -0x75E8($at)
    ctx->r11 = ADD32(ctx->r1, -0X75E8);
    // 0x80087E08: nop

    // 0x80087E0C: jr          $t3
    // 0x80087E10: nop

    switch (jr_addend_80087E0C >> 2) {
        case 0: goto L_80087E14; break;
        case 1: goto L_80087E14; break;
        case 2: goto L_80087E14; break;
        case 3: goto L_80087FC0; break;
        case 4: goto L_80087E14; break;
        case 5: goto L_80087FC0; break;
        case 6: goto L_80087E14; break;
        case 7: goto L_80087FC0; break;
        case 8: goto L_80087E2C; break;
        case 9: goto L_80087E2C; break;
        default: switch_error(__func__, 0x80087E0C, 0x800E8A18);
    }
    // 0x80087E10: nop

L_80087E14:
    // 0x80087E14: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x80087E18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087E1C: sw          $t5, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r13;
    // 0x80087E20: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80087E24: b           L_80087FC0
    // 0x80087E28: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
        goto L_80087FC0;
    // 0x80087E28: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
L_80087E2C:
    // 0x80087E2C: b           L_80087FC0
    // 0x80087E30: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
        goto L_80087FC0;
    // 0x80087E30: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_80087E34:
    // 0x80087E34: beq         $v0, $zero, L_80087F40
    if (ctx->r2 == 0) {
        // 0x80087E38: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80087F40;
    }
    // 0x80087E38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80087E3C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087E40: jal         0x80001D04
    // 0x80087E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80087E48: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087E4C: addiu       $t1, $t1, 0x6980
    ctx->r9 = ADD32(ctx->r9, 0X6980);
    // 0x80087E50: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80087E54: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x80087E58: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80087E5C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80087E60: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087E64: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x80087E68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087E6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087E70: beq         $v0, $at, L_80087ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80087E74: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80087ED8;
    }
    // 0x80087E74: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087E78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80087E7C: beq         $v0, $at, L_80087E9C
    if (ctx->r2 == ctx->r1) {
        // 0x80087E80: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087E9C;
    }
    // 0x80087E80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087E84: beq         $v0, $at, L_80087F18
    if (ctx->r2 == ctx->r1) {
        // 0x80087E88: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80087F18;
    }
    // 0x80087E88: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80087E8C: beq         $v0, $at, L_80087ED8
    if (ctx->r2 == ctx->r1) {
        // 0x80087E90: nop
    
            goto L_80087ED8;
    }
    // 0x80087E90: nop

    // 0x80087E94: b           L_80087FC4
    // 0x80087E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80087FC4;
    // 0x80087E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087E9C:
    // 0x80087E9C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087EA0: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x80087EA4: jal         0x8007601C
    // 0x80087EA8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    reformat_controller_pak(rdram, ctx);
        goto after_2;
    // 0x80087EA8: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80087EAC: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087EB0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087EB4: bne         $t0, $v0, L_80087EC8
    if (ctx->r8 != ctx->r2) {
        // 0x80087EB8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80087EC8;
    }
    // 0x80087EB8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80087EBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087EC0: b           L_80087FC0
    // 0x80087EC4: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087EC4: sw          $zero, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = 0;
L_80087EC8:
    // 0x80087EC8: bne         $t0, $at, L_80087FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80087ECC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80087FC0;
    }
    // 0x80087ECC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087ED0: b           L_80087FC0
    // 0x80087ED4: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
        goto L_80087FC0;
    // 0x80087ED4: sw          $zero, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = 0;
L_80087ED8:
    // 0x80087ED8: lw          $a0, 0x60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X60);
    // 0x80087EDC: jal         0x80075F90
    // 0x80087EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    repair_controller_pak(rdram, ctx);
        goto after_3;
    // 0x80087EE0: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_3:
    // 0x80087EE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80087EE8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087EEC: bne         $t0, $v0, L_80087F04
    if (ctx->r8 != ctx->r2) {
        // 0x80087EF0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80087F04;
    }
    // 0x80087EF0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80087EF4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80087EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087EFC: b           L_80087FC0
    // 0x80087F00: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
        goto L_80087FC0;
    // 0x80087F00: sw          $t8, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r24;
L_80087F04:
    // 0x80087F04: bne         $t0, $at, L_80087FC0
    if (ctx->r8 != ctx->r1) {
        // 0x80087F08: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80087FC0;
    }
    // 0x80087F08: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087F0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F10: b           L_80087FC0
    // 0x80087F14: sw          $t9, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r25;
        goto L_80087FC0;
    // 0x80087F14: sw          $t9, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r25;
L_80087F18:
    // 0x80087F18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80087F1C: bne         $t0, $v0, L_80087F34
    if (ctx->r8 != ctx->r2) {
        // 0x80087F20: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_80087F34;
    }
    // 0x80087F20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80087F24: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80087F28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F2C: b           L_80087FC0
    // 0x80087F30: sw          $t2, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r10;
        goto L_80087FC0;
    // 0x80087F30: sw          $t2, 0x6FDC($at)
    MEM_W(0X6FDC, ctx->r1) = ctx->r10;
L_80087F34:
    // 0x80087F34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087F38: b           L_80087FC0
    // 0x80087F3C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
        goto L_80087FC0;
    // 0x80087F3C: sw          $t3, 0x6FD8($at)
    MEM_W(0X6FD8, ctx->r1) = ctx->r11;
L_80087F40:
    // 0x80087F40: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80087F44: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80087F48: bgez        $t5, L_80087F88
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80087F4C: nop
    
            goto L_80087F88;
    }
    // 0x80087F4C: nop

    // 0x80087F50: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80087F54: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80087F58: slt         $at, $t4, $t6
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80087F5C: beq         $at, $zero, L_80087F88
    if (ctx->r1 == 0) {
        // 0x80087F60: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087F88;
    }
    // 0x80087F60: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087F64: jal         0x80001D04
    // 0x80087F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80087F68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80087F6C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087F70: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087F74: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80087F78: nop

    // 0x80087F7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80087F80: b           L_80087FC0
    // 0x80087F84: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80087FC0;
    // 0x80087F84: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80087F88:
    // 0x80087F88: blez        $t9, L_80087FC4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80087F8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087FC4;
    }
    // 0x80087F8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087F90: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80087F94: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087F98: blez        $t2, L_80087FC4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80087F9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80087FC4;
    }
    // 0x80087F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087FA0: jal         0x80001D04
    // 0x80087FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80087FA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80087FA8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80087FAC: addiu       $a3, $a3, 0x7038
    ctx->r7 = ADD32(ctx->r7, 0X7038);
    // 0x80087FB0: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80087FB4: nop

    // 0x80087FB8: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x80087FBC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80087FC0:
    // 0x80087FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80087FC4:
    // 0x80087FC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80087FC8: jr          $ra
    // 0x80087FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087FCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void onscreen_ai_racer_physics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055AC4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80055AC8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80055ACC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80055AD0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80055AD4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80055AD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055ADC: lwc1        $f0, -0x2590($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2590);
    // 0x80055AE0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80055AE4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80055AE8: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80055AEC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80055AF0: bc1f        L_80055AFC
    if (!c1cs) {
        // 0x80055AF4: nop
    
            goto L_80055AFC;
    }
    // 0x80055AF4: nop

    // 0x80055AF8: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
L_80055AFC:
    // 0x80055AFC: jal         0x8001E2D0
    // 0x80055B00: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80055B00: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    after_0:
    // 0x80055B04: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80055B08: sb          $t6, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r14;
    // 0x80055B0C: lb          $t7, 0x1D7($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D7);
    // 0x80055B10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80055B14: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80055B18: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80055B1C: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x80055B20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055B24: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80055B28: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055B2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80055B30: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x80055B34: lwc1        $f10, 0x10($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055B38: nop

    // 0x80055B3C: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x80055B40: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055B44: swc1        $f0, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f0.u32l;
    // 0x80055B48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055B4C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055B50: swc1        $f0, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f0.u32l;
    // 0x80055B54: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80055B58: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80055B5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055B60: bne         $t1, $at, L_80055B7C
    if (ctx->r9 != ctx->r1) {
        // 0x80055B64: addiu       $t3, $sp, 0x48
        ctx->r11 = ADD32(ctx->r29, 0X48);
            goto L_80055B7C;
    }
    // 0x80055B64: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
    // 0x80055B68: lb          $t2, 0x1D7($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D7);
    // 0x80055B6C: nop

    // 0x80055B70: slti        $at, $t2, 0x5
    ctx->r1 = SIGNED(ctx->r10) < 0X5 ? 1 : 0;
    // 0x80055B74: beq         $at, $zero, L_80055BA8
    if (ctx->r1 == 0) {
        // 0x80055B78: addiu       $t3, $sp, 0x48
        ctx->r11 = ADD32(ctx->r29, 0X48);
            goto L_80055BA8;
    }
    // 0x80055B78: addiu       $t3, $sp, 0x48
    ctx->r11 = ADD32(ctx->r29, 0X48);
L_80055B7C:
    // 0x80055B7C: addiu       $t4, $sp, 0x40
    ctx->r12 = ADD32(ctx->r29, 0X40);
    // 0x80055B80: addiu       $t5, $sp, 0x3F
    ctx->r13 = ADD32(ctx->r29, 0X3F);
    // 0x80055B84: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x80055B88: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80055B8C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80055B90: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80055B94: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80055B98: addiu       $a2, $sp, 0x74
    ctx->r6 = ADD32(ctx->r29, 0X74);
    // 0x80055B9C: jal         0x8001727C
    // 0x80055BA0: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    collision_objectmodel(rdram, ctx);
        goto after_1;
    // 0x80055BA0: addiu       $a3, $s0, 0xD8
    ctx->r7 = ADD32(ctx->r16, 0XD8);
    after_1:
    // 0x80055BA4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80055BA8:
    // 0x80055BA8: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x80055BAC: beq         $t6, $zero, L_80055BE8
    if (ctx->r14 == 0) {
        // 0x80055BB0: addiu       $a1, $s0, 0xD8
        ctx->r5 = ADD32(ctx->r16, 0XD8);
            goto L_80055BE8;
    }
    // 0x80055BB0: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x80055BB4: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80055BB8: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80055BBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055BC0: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80055BC4: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80055BC8: swc1        $f10, -0x2538($at)
    MEM_W(-0X2538, ctx->r1) = ctx->f10.u32l;
    // 0x80055BCC: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80055BD0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80055BD4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055BD8: swc1        $f8, -0x2534($at)
    MEM_W(-0X2534, ctx->r1) = ctx->f8.u32l;
    // 0x80055BDC: addiu       $at, $zero, -0x81
    ctx->r1 = ADD32(0, -0X81);
    // 0x80055BE0: and         $t7, $v1, $at
    ctx->r15 = ctx->r3 & ctx->r1;
    // 0x80055BE4: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80055BE8:
    // 0x80055BE8: beq         $v1, $zero, L_80055C24
    if (ctx->r3 == 0) {
        // 0x80055BEC: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80055C24;
    }
    // 0x80055BEC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80055BF0: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80055BF4: lwc1        $f6, 0x10($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80055BF8: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x80055BFC: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80055C00: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80055C04: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80055C08: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80055C0C: sub.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f8.d - ctx->f10.d;
    // 0x80055C10: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x80055C14: nop

    // 0x80055C18: bc1f        L_80055C24
    if (!c1cs) {
        // 0x80055C1C: nop
    
            goto L_80055C24;
    }
    // 0x80055C1C: nop

    // 0x80055C20: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80055C24:
    // 0x80055C24: lb          $a3, 0x1D6($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055C28: sb          $t0, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r8;
    // 0x80055C2C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80055C30: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80055C34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80055C38: jal         0x80031170
    // 0x80055C3C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    generate_collision_candidates(rdram, ctx);
        goto after_2;
    // 0x80055C3C: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x80055C40: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80055C44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80055C48: addiu       $t9, $sp, 0x74
    ctx->r25 = ADD32(ctx->r29, 0X74);
    // 0x80055C4C: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x80055C50: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80055C54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80055C58: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80055C5C: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x80055C60: jal         0x80031640
    // 0x80055C64: addiu       $a3, $sp, 0x3F
    ctx->r7 = ADD32(ctx->r29, 0X3F);
    resolve_collisions(rdram, ctx);
        goto after_3;
    // 0x80055C64: addiu       $a3, $sp, 0x3F
    ctx->r7 = ADD32(ctx->r29, 0X3F);
    after_3:
    // 0x80055C68: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80055C6C: lb          $t0, 0x3E($sp)
    ctx->r8 = MEM_B(ctx->r29, 0X3E);
    // 0x80055C70: sb          $v0, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r2;
    // 0x80055C74: lb          $t1, 0x1E3($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055C78: sb          $v1, 0x1E4($s0)
    MEM_B(0X1E4, ctx->r16) = ctx->r3;
    // 0x80055C7C: or          $t2, $t1, $v1
    ctx->r10 = ctx->r9 | ctx->r3;
    // 0x80055C80: sb          $t2, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r10;
    // 0x80055C84: lb          $t3, 0x1E3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E3);
    // 0x80055C88: sb          $zero, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = 0;
    // 0x80055C8C: beq         $t3, $zero, L_80055CA4
    if (ctx->r11 == 0) {
        // 0x80055C90: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_80055CA4;
    }
    // 0x80055C90: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80055C94: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80055C98: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80055C9C: sb          $t4, 0x1E3($s0)
    MEM_B(0X1E3, ctx->r16) = ctx->r12;
    // 0x80055CA0: sb          $t5, 0x1E2($s0)
    MEM_B(0X1E2, ctx->r16) = ctx->r13;
L_80055CA4:
    // 0x80055CA4: beq         $t0, $zero, L_80055CD8
    if (ctx->r8 == 0) {
        // 0x80055CA8: addiu       $v0, $sp, 0x48
        ctx->r2 = ADD32(ctx->r29, 0X48);
            goto L_80055CD8;
    }
    // 0x80055CA8: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80055CAC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80055CB0: nop

    // 0x80055CB4: beq         $t6, $zero, L_80055CDC
    if (ctx->r14 == 0) {
        // 0x80055CB8: addiu       $a0, $sp, 0x54
        ctx->r4 = ADD32(ctx->r29, 0X54);
            goto L_80055CDC;
    }
    // 0x80055CB8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    // 0x80055CBC: lb          $t7, 0x1ED($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1ED);
    // 0x80055CC0: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80055CC4: bne         $t7, $zero, L_80055CD4
    if (ctx->r15 != 0) {
        // 0x80055CC8: addiu       $t9, $zero, 0x3C
        ctx->r25 = ADD32(0, 0X3C);
            goto L_80055CD4;
    }
    // 0x80055CC8: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80055CCC: b           L_80055CD8
    // 0x80055CD0: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
        goto L_80055CD8;
    // 0x80055CD0: sb          $t8, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r24;
L_80055CD4:
    // 0x80055CD4: sb          $t9, 0x1ED($s0)
    MEM_B(0X1ED, ctx->r16) = ctx->r25;
L_80055CD8:
    // 0x80055CD8: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
L_80055CDC:
    // 0x80055CDC: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80055CE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80055CE4: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80055CE8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055CEC: bne         $at, $zero, L_80055CDC
    if (ctx->r1 != 0) {
        // 0x80055CF0: swc1        $f8, 0xD4($v1)
        MEM_W(0XD4, ctx->r3) = ctx->f8.u32l;
            goto L_80055CDC;
    }
    // 0x80055CF0: swc1        $f8, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->f8.u32l;
    // 0x80055CF4: lb          $t1, 0x3F($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X3F);
    // 0x80055CF8: lwc1        $f10, 0xD8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XD8);
    // 0x80055CFC: sb          $t1, 0x1DC($s0)
    MEM_B(0X1DC, ctx->r16) = ctx->r9;
    // 0x80055D00: lb          $t2, 0x3F($sp)
    ctx->r10 = MEM_B(ctx->r29, 0X3F);
    // 0x80055D04: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x80055D08: sb          $t2, 0x1DD($s0)
    MEM_B(0X1DD, ctx->r16) = ctx->r10;
    // 0x80055D0C: lb          $t3, 0x3F($sp)
    ctx->r11 = MEM_B(ctx->r29, 0X3F);
    // 0x80055D10: addiu       $a1, $sp, 0x64
    ctx->r5 = ADD32(ctx->r29, 0X64);
    // 0x80055D14: sb          $t3, 0x1DE($s0)
    MEM_B(0X1DE, ctx->r16) = ctx->r11;
    // 0x80055D18: lb          $t4, 0x3F($sp)
    ctx->r12 = MEM_B(ctx->r29, 0X3F);
    // 0x80055D1C: nop

    // 0x80055D20: sb          $t4, 0x1DF($s0)
    MEM_B(0X1DF, ctx->r16) = ctx->r12;
    // 0x80055D24: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x80055D28: lwc1        $f4, 0xDC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XDC);
    // 0x80055D2C: nop

    // 0x80055D30: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x80055D34: lwc1        $f6, 0xE0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XE0);
    // 0x80055D38: nop

    // 0x80055D3C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x80055D40: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80055D44: nop

    // 0x80055D48: beq         $t5, $zero, L_80055E64
    if (ctx->r13 == 0) {
        // 0x80055D4C: nop
    
            goto L_80055E64;
    }
    // 0x80055D4C: nop

    // 0x80055D50: jal         0x8002AD14
    // 0x80055D54: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    get_collision_normal(rdram, ctx);
        goto after_4;
    // 0x80055D54: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x80055D58: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80055D5C: nop

    // 0x80055D60: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80055D64: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x80055D68: jal         0x80070A04
    // 0x80055D6C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x80055D6C: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    after_5:
    // 0x80055D70: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80055D74: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x80055D78: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80055D7C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80055D80: jal         0x80070A38
    // 0x80055D84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80055D84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_6:
    // 0x80055D88: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80055D8C: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80055D90: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80055D94: lwc1        $f18, 0x60($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80055D98: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80055D9C: mul.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80055DA0: nop

    // 0x80055DA4: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80055DA8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80055DAC: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80055DB0: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80055DB4: jal         0x80070990
    // 0x80055DB8: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    arctan2_f(rdram, ctx);
        goto after_7;
    // 0x80055DB8: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    after_7:
    // 0x80055DBC: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80055DC0: sra         $t1, $v1, 16
    ctx->r9 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80055DC4: negu        $v1, $t1
    ctx->r3 = SUB32(0, ctx->r9);
    // 0x80055DC8: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80055DCC: beq         $at, $zero, L_80055DE0
    if (ctx->r1 == 0) {
        // 0x80055DD0: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_80055DE0;
    }
    // 0x80055DD0: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80055DD4: bne         $at, $zero, L_80055DE0
    if (ctx->r1 != 0) {
        // 0x80055DD8: nop
    
            goto L_80055DE0;
    }
    // 0x80055DD8: nop

    // 0x80055DDC: sh          $v1, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r3;
L_80055DE0:
    // 0x80055DE0: lwc1        $f12, 0x60($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X60);
    // 0x80055DE4: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80055DE8: jal         0x80070990
    // 0x80055DEC: nop

    arctan2_f(rdram, ctx);
        goto after_8;
    // 0x80055DEC: nop

    after_8:
    // 0x80055DF0: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80055DF4: sra         $t2, $v1, 16
    ctx->r10 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80055DF8: negu        $v1, $t2
    ctx->r3 = SUB32(0, ctx->r10);
    // 0x80055DFC: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x80055E00: beq         $at, $zero, L_80055E14
    if (ctx->r1 == 0) {
        // 0x80055E04: slti        $at, $v1, -0x1FFF
        ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
            goto L_80055E14;
    }
    // 0x80055E04: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x80055E08: bne         $at, $zero, L_80055E14
    if (ctx->r1 != 0) {
        // 0x80055E0C: nop
    
            goto L_80055E14;
    }
    // 0x80055E0C: nop

    // 0x80055E10: sh          $v1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r3;
L_80055E14:
    // 0x80055E14: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055E18: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055E1C: bne         $t3, $at, L_80055E64
    if (ctx->r11 != ctx->r1) {
        // 0x80055E20: nop
    
            goto L_80055E64;
    }
    // 0x80055E20: nop

    // 0x80055E24: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055E28: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80055E2C: andi        $t4, $a0, 0xFFFF
    ctx->r12 = ctx->r4 & 0XFFFF;
    // 0x80055E30: subu        $v0, $v1, $t4
    ctx->r2 = SUB32(ctx->r3, ctx->r12);
    // 0x80055E34: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80055E38: bne         $at, $zero, L_80055E48
    if (ctx->r1 != 0) {
        // 0x80055E3C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80055E48;
    }
    // 0x80055E3C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80055E40: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80055E44: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80055E48:
    // 0x80055E48: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80055E4C: beq         $at, $zero, L_80055E58
    if (ctx->r1 == 0) {
        // 0x80055E50: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80055E58;
    }
    // 0x80055E50: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80055E54: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80055E58:
    // 0x80055E58: sra         $t5, $v0, 2
    ctx->r13 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80055E5C: addu        $t6, $a0, $t5
    ctx->r14 = ADD32(ctx->r4, ctx->r13);
    // 0x80055E60: sh          $t6, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r14;
L_80055E64:
    // 0x80055E64: lb          $v0, 0x1D6($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1D6);
    // 0x80055E68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80055E6C: beq         $v0, $at, L_80055EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E70: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80055EEC;
    }
    // 0x80055E70: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80055E74: beq         $v0, $at, L_80055EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E78: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80055EEC;
    }
    // 0x80055E78: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80055E7C: beq         $v0, $at, L_80055EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80055E80: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80055EEC;
    }
    // 0x80055E80: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80055E84: beq         $v0, $at, L_80055EF0
    if (ctx->r2 == ctx->r1) {
        // 0x80055E88: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055EF0;
    }
    // 0x80055E88: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055E8C: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055E90: addiu       $t7, $zero, 0x3400
    ctx->r15 = ADD32(0, 0X3400);
    // 0x80055E94: slti        $at, $v0, 0x3401
    ctx->r1 = SIGNED(ctx->r2) < 0X3401 ? 1 : 0;
    // 0x80055E98: bne         $at, $zero, L_80055EAC
    if (ctx->r1 != 0) {
        // 0x80055E9C: addiu       $t8, $zero, -0x3400
        ctx->r24 = ADD32(0, -0X3400);
            goto L_80055EAC;
    }
    // 0x80055E9C: addiu       $t8, $zero, -0x3400
    ctx->r24 = ADD32(0, -0X3400);
    // 0x80055EA0: sh          $t7, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r15;
    // 0x80055EA4: lh          $v0, 0x1A4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1A4);
    // 0x80055EA8: nop

L_80055EAC:
    // 0x80055EAC: slti        $at, $v0, -0x3400
    ctx->r1 = SIGNED(ctx->r2) < -0X3400 ? 1 : 0;
    // 0x80055EB0: beq         $at, $zero, L_80055EBC
    if (ctx->r1 == 0) {
        // 0x80055EB4: addiu       $t9, $zero, 0x3400
        ctx->r25 = ADD32(0, 0X3400);
            goto L_80055EBC;
    }
    // 0x80055EB4: addiu       $t9, $zero, 0x3400
    ctx->r25 = ADD32(0, 0X3400);
    // 0x80055EB8: sh          $t8, 0x1A4($s0)
    MEM_H(0X1A4, ctx->r16) = ctx->r24;
L_80055EBC:
    // 0x80055EBC: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055EC0: addiu       $t1, $zero, -0x3400
    ctx->r9 = ADD32(0, -0X3400);
    // 0x80055EC4: slti        $at, $a0, 0x3401
    ctx->r1 = SIGNED(ctx->r4) < 0X3401 ? 1 : 0;
    // 0x80055EC8: bne         $at, $zero, L_80055EE0
    if (ctx->r1 != 0) {
        // 0x80055ECC: slti        $at, $a0, -0x3400
        ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
            goto L_80055EE0;
    }
    // 0x80055ECC: slti        $at, $a0, -0x3400
    ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
    // 0x80055ED0: sh          $t9, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r25;
    // 0x80055ED4: lh          $a0, 0x2($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X2);
    // 0x80055ED8: nop

    // 0x80055EDC: slti        $at, $a0, -0x3400
    ctx->r1 = SIGNED(ctx->r4) < -0X3400 ? 1 : 0;
L_80055EE0:
    // 0x80055EE0: beq         $at, $zero, L_80055EF0
    if (ctx->r1 == 0) {
        // 0x80055EE4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80055EF0;
    }
    // 0x80055EE4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80055EE8: sh          $t1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r9;
L_80055EEC:
    // 0x80055EEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80055EF0:
    // 0x80055EF0: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80055EF4: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80055EF8: jr          $ra
    // 0x80055EFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80055EFC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void get_collision_candidate_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002ACE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002ACE4: lw          $t6, -0x2708($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2708);
    // 0x8002ACE8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002ACEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8002ACF0: lw          $t7, -0x2710($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2710);
    // 0x8002ACF4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002ACF8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8002ACFC: lw          $t8, -0x270C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X270C);
    // 0x8002AD00: jr          $ra
    // 0x8002AD04: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    return;
    // 0x8002AD04: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
;}
RECOMP_FUNC void play_random_character_voice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800570F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800570FC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80057100: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80057104: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80057108: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8005710C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80057110: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80057114: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80057118: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8005711C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80057120: lw          $t7, 0x108($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X108);
    // 0x80057124: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80057128: bne         $t7, $zero, L_80057244
    if (ctx->r15 != 0) {
        // 0x8005712C: andi        $t8, $a3, 0x80
        ctx->r24 = ctx->r7 & 0X80;
            goto L_80057244;
    }
    // 0x8005712C: andi        $t8, $a3, 0x80
    ctx->r24 = ctx->r7 & 0X80;
    // 0x80057130: beq         $t8, $zero, L_80057144
    if (ctx->r24 == 0) {
        // 0x80057134: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80057144;
    }
    // 0x80057134: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80057138: lw          $t9, -0x2524($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2524);
    // 0x8005713C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057140: beq         $t9, $at, L_80057244
    if (ctx->r25 == ctx->r1) {
        // 0x80057144: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80057244;
    }
L_80057144:
    // 0x80057144: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80057148: bne         $s0, $at, L_8005717C
    if (ctx->r16 != ctx->r1) {
        // 0x8005714C: nop
    
            goto L_8005717C;
    }
    // 0x8005714C: nop

    // 0x80057150: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    // 0x80057154: nop

    // 0x80057158: beq         $a0, $zero, L_8005717C
    if (ctx->r4 == 0) {
        // 0x8005715C: nop
    
            goto L_8005717C;
    }
    // 0x8005715C: nop

    // 0x80057160: lhu         $t1, 0x2A($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X2A);
    // 0x80057164: nop

    // 0x80057168: beq         $s3, $t1, L_8005717C
    if (ctx->r19 == ctx->r9) {
        // 0x8005716C: nop
    
            goto L_8005717C;
    }
    // 0x8005716C: nop

    // 0x80057170: jal         0x800096F8
    // 0x80057174: nop

    audspat_point_stop(rdram, ctx);
        goto after_0;
    // 0x80057174: nop

    after_0:
    // 0x80057178: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_8005717C:
    // 0x8005717C: lw          $t2, 0x24($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X24);
    // 0x80057180: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80057184: bne         $t2, $zero, L_80057248
    if (ctx->r10 != 0) {
        // 0x80057188: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80057248;
    }
    // 0x80057188: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005718C: bne         $s0, $at, L_800571A4
    if (ctx->r16 != ctx->r1) {
        // 0x80057190: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800571A4;
    }
    // 0x80057190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80057194: jal         0x8006FB8C
    // 0x80057198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x80057198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8005719C: beq         $v0, $zero, L_80057248
    if (ctx->r2 == 0) {
        // 0x800571A0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80057248;
    }
    // 0x800571A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800571A4:
    // 0x800571A4: sh          $s3, 0x2A($s2)
    MEM_H(0X2A, ctx->r18) = ctx->r19;
    // 0x800571A8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x800571AC: lb          $t3, 0x3($s2)
    ctx->r11 = MEM_B(ctx->r18, 0X3);
    // 0x800571B0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800571B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800571B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800571BC: jal         0x8006FB8C
    // 0x800571C0: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800571C0: addu        $s3, $s3, $t3
    ctx->r19 = ADD32(ctx->r19, ctx->r11);
    after_2:
    // 0x800571C4: addiu       $s0, $zero, 0xC
    ctx->r16 = ADD32(0, 0XC);
    // 0x800571C8: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800571CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800571D0: addu        $v1, $t4, $s3
    ctx->r3 = ADD32(ctx->r12, ctx->r19);
    // 0x800571D4: blez        $s1, L_8005720C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800571D8: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8005720C;
    }
    // 0x800571D8: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x800571DC: lhu         $t5, 0x28($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X28);
    // 0x800571E0: nop

    // 0x800571E4: bne         $v1, $t5, L_8005720C
    if (ctx->r3 != ctx->r13) {
        // 0x800571E8: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005720C;
    }
    // 0x800571E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800571EC:
    // 0x800571EC: jal         0x8006FB8C
    // 0x800571F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800571F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800571F4: multu       $v0, $s0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800571F8: lhu         $t7, 0x28($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X28);
    // 0x800571FC: mflo        $t6
    ctx->r14 = lo;
    // 0x80057200: addu        $t0, $t6, $s3
    ctx->r8 = ADD32(ctx->r14, ctx->r19);
    // 0x80057204: beq         $t0, $t7, L_800571EC
    if (ctx->r8 == ctx->r15) {
        // 0x80057208: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800571EC;
    }
    // 0x80057208: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005720C:
    // 0x8005720C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80057210: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80057214: lw          $a1, 0xC($t8)
    ctx->r5 = MEM_W(ctx->r24, 0XC);
    // 0x80057218: lw          $a2, 0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X10);
    // 0x8005721C: lw          $a3, 0x14($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14);
    // 0x80057220: addiu       $t1, $s2, 0x24
    ctx->r9 = ADD32(ctx->r18, 0X24);
    // 0x80057224: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80057228: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x8005722C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80057230: jal         0x80009558
    // 0x80057234: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_4;
    // 0x80057234: andi        $a0, $t0, 0xFFFF
    ctx->r4 = ctx->r8 & 0XFFFF;
    after_4:
    // 0x80057238: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005723C: nop

    // 0x80057240: sh          $t0, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r8;
L_80057244:
    // 0x80057244: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80057248:
    // 0x80057248: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8005724C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80057250: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80057254: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80057258: jr          $ra
    // 0x8005725C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005725C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void unset_eeprom_settings_value(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009F000: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009F004: addiu       $v0, $v0, 0x69E8
    ctx->r2 = ADD32(ctx->r2, 0X69E8);
    // 0x8009F008: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009F00C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8009F010: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009F014: nor         $t0, $a0, $zero
    ctx->r8 = ~(ctx->r4 | 0);
    // 0x8009F018: nor         $t1, $a1, $zero
    ctx->r9 = ~(ctx->r5 | 0);
    // 0x8009F01C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009F020: and         $t2, $t6, $t0
    ctx->r10 = ctx->r14 & ctx->r8;
    // 0x8009F024: and         $t3, $t7, $t1
    ctx->r11 = ctx->r15 & ctx->r9;
    // 0x8009F028: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8009F02C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009F030: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009F034: jal         0x8006EF20
    // 0x8009F038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    mark_write_eeprom_settings(rdram, ctx);
        goto after_0;
    // 0x8009F038: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009F03C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009F040: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009F044: jr          $ra
    // 0x8009F048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8009F048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void sndp_stop_all_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800049D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800049DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800049E0: jal         0x800048D8
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    sndp_stop_with_flags(rdram, ctx);
        goto after_0;
    // 0x800049E4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x800049E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800049EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800049F0: jr          $ra
    // 0x800049F4: nop

    return;
    // 0x800049F4: nop

;}
RECOMP_FUNC void traverse_segments_bsp_tree(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029B38: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80029B3C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80029B40: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80029B44: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80029B48: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80029B4C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x80029B50: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80029B54: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80029B58: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80029B5C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80029B60: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80029B64: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80029B68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029B6C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80029B70: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80029B74: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x80029B78: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
    // 0x80029B7C: addiu       $fp, $fp, -0x3178
    ctx->r30 = ADD32(ctx->r30, -0X3178);
    // 0x80029B80: addiu       $s7, $s7, -0x49D0
    ctx->r23 = ADD32(ctx->r23, -0X49D0);
    // 0x80029B84: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80029B88: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
L_80029B8C:
    // 0x80029B8C: lw          $t6, 0x0($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X0);
    // 0x80029B90: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
    // 0x80029B94: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80029B98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80029B9C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80029BA0: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x80029BA4: nop

    // 0x80029BA8: bne         $v0, $zero, L_80029BE0
    if (ctx->r2 != 0) {
        // 0x80029BAC: nop
    
            goto L_80029BE0;
    }
    // 0x80029BAC: nop

    // 0x80029BB0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80029BB4: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x80029BB8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80029BBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BC4: lwc1        $f4, 0xC($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80029BC8: nop

    // 0x80029BCC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80029BD0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80029BD4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80029BD8: b           L_80029C48
    // 0x80029BDC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C48;
    // 0x80029BDC: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029BE0:
    // 0x80029BE0: bne         $v0, $at, L_80029C18
    if (ctx->r2 != ctx->r1) {
        // 0x80029BE4: nop
    
            goto L_80029C18;
    }
    // 0x80029BE4: nop

    // 0x80029BE8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80029BEC: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    // 0x80029BF0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80029BF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029BF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029BFC: lwc1        $f8, 0x10($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X10);
    // 0x80029C00: nop

    // 0x80029C04: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80029C08: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80029C0C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80029C10: b           L_80029C48
    // 0x80029C14: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
        goto L_80029C48;
    // 0x80029C14: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029C18:
    // 0x80029C18: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80029C1C: lw          $t3, 0x0($s7)
    ctx->r11 = MEM_W(ctx->r23, 0X0);
    // 0x80029C20: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80029C24: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029C28: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029C2C: lwc1        $f16, 0x14($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80029C30: nop

    // 0x80029C34: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80029C38: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80029C3C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80029C40: nop

    // 0x80029C44: lh          $t5, 0x6($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X6);
L_80029C48:
    // 0x80029C48: nop

    // 0x80029C4C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80029C50: beq         $at, $zero, L_80029CC4
    if (ctx->r1 == 0) {
        // 0x80029C54: nop
    
            goto L_80029CC4;
    }
    // 0x80029C54: nop

    // 0x80029C58: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80029C5C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029C60: beq         $s6, $a0, L_80029C88
    if (ctx->r22 == ctx->r4) {
        // 0x80029C64: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029C88;
    }
    // 0x80029C64: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029C68: lbu         $a2, 0x5($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X5);
    // 0x80029C6C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029C70: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029C74: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x80029C78: jal         0x80029B38
    // 0x80029C7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_0;
    // 0x80029C7C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_0:
    // 0x80029C80: b           L_80029C94
    // 0x80029C84: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
        goto L_80029C94;
    // 0x80029C84: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C88:
    // 0x80029C88: jal         0x80029D54
    // 0x80029C8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_1;
    // 0x80029C8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_1:
    // 0x80029C90: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
L_80029C94:
    // 0x80029C94: nop

    // 0x80029C98: beq         $s6, $a0, L_80029CAC
    if (ctx->r22 == ctx->r4) {
        // 0x80029C9C: nop
    
            goto L_80029CAC;
    }
    // 0x80029C9C: nop

    // 0x80029CA0: lbu         $s4, 0x5($s0)
    ctx->r20 = MEM_BU(ctx->r16, 0X5);
    // 0x80029CA4: b           L_80029B8C
    // 0x80029CA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
        goto L_80029B8C;
    // 0x80029CA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
L_80029CAC:
    // 0x80029CAC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80029CB0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029CB4: jal         0x80029D54
    // 0x80029CB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_2;
    // 0x80029CB8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
    // 0x80029CBC: b           L_80029D28
    // 0x80029CC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_80029D28;
    // 0x80029CC0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029CC4:
    // 0x80029CC4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80029CC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029CCC: beq         $s6, $a0, L_80029CF0
    if (ctx->r22 == ctx->r4) {
        // 0x80029CD0: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_80029CF0;
    }
    // 0x80029CD0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80029CD4: lbu         $a1, 0x5($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X5);
    // 0x80029CD8: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80029CDC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029CE0: jal         0x80029B38
    // 0x80029CE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x80029CE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_3:
    // 0x80029CE8: b           L_80029CFC
    // 0x80029CEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
        goto L_80029CFC;
    // 0x80029CEC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CF0:
    // 0x80029CF0: jal         0x80029D54
    // 0x80029CF4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_4;
    // 0x80029CF4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_4:
    // 0x80029CF8: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
L_80029CFC:
    // 0x80029CFC: nop

    // 0x80029D00: beq         $s6, $a0, L_80029D14
    if (ctx->r22 == ctx->r4) {
        // 0x80029D04: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_80029D14;
    }
    // 0x80029D04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80029D08: lbu         $s5, 0x5($s0)
    ctx->r21 = MEM_BU(ctx->r16, 0X5);
    // 0x80029D0C: b           L_80029B8C
    // 0x80029D10: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
        goto L_80029B8C;
    // 0x80029D10: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80029D14:
    // 0x80029D14: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80029D18: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80029D1C: jal         0x80029D54
    // 0x80029D20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    add_segment_to_order(rdram, ctx);
        goto after_5;
    // 0x80029D20: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_5:
    // 0x80029D24: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80029D28:
    // 0x80029D28: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029D2C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029D30: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80029D34: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029D38: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029D3C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029D40: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80029D44: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80029D48: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80029D4C: jr          $ra
    // 0x80029D50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80029D50: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void _ldexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB7E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800CB7EC: beq         $a2, $zero, L_800CB81C
    if (ctx->r6 == 0) {
        // 0x800CB7F0: nop
    
            goto L_800CB81C;
    }
    // 0x800CB7F0: nop

    // 0x800CB7F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB7F8: sllv        $t7, $t6, $a2
    ctx->r15 = S32(ctx->r14 << (ctx->r6 & 31));
    // 0x800CB7FC: sw          $t7, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r15;
    // 0x800CB800: lw          $t8, 0x4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4);
    // 0x800CB804: nop

    // 0x800CB808: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800CB80C: nop

    // 0x800CB810: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800CB814: mul.d       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f6.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f6.d);
    // 0x800CB818: nop

L_800CB81C:
    // 0x800CB81C: b           L_800CB82C
    // 0x800CB820: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB82C;
    // 0x800CB820: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
    // 0x800CB824: b           L_800CB82C
    // 0x800CB828: nop

        goto L_800CB82C;
    // 0x800CB828: nop

L_800CB82C:
    // 0x800CB82C: jr          $ra
    // 0x800CB830: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800CB830: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void input_released(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A7BC: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A7C0: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7C4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A7C8: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8006A7CC: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x8006A7D0: lhu         $v0, 0x16C8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X16C8);
    // 0x8006A7D4: jr          $ra
    // 0x8006A7D8: nop

    return;
    // 0x8006A7D8: nop

;}
RECOMP_FUNC void func_80016748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001677C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80016780: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x80016784: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x80016788: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8001678C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x80016790: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80016794: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80016798: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8001679C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800167A0: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800167A4: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800167A8: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800167AC: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x800167B0: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800167B4: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x800167B8: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800167BC: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x800167C0: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800167C4: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x800167C8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800167CC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x800167D0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800167D4: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x800167D8: lw          $t6, 0x44($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X44);
    // 0x800167DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800167E0: beq         $t6, $zero, L_80016B98
    if (ctx->r14 == 0) {
        // 0x800167E4: or          $s5, $a1, $zero
        ctx->r21 = ctx->r5 | 0;
            goto L_80016B98;
    }
    // 0x800167E4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800167E8: lw          $t7, 0x68($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X68);
    // 0x800167EC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800167F0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800167F4: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800167F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800167FC: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x80016800: swc1        $f8, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f8.u32l;
    // 0x80016804: lwc1        $f16, 0x10($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80016808: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001680C: nop

    // 0x80016810: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80016814: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016818: swc1        $f18, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f18.u32l;
    // 0x8001681C: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80016820: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x80016824: mul.s       $f16, $f10, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80016828: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8001682C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80016830: mul.s       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x80016834: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016838: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8001683C: nop

    // 0x80016840: mul.s       $f10, $f8, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x80016844: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80016848: jal         0x800CA030
    // 0x8001684C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001684C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
    after_0:
    // 0x80016850: lwc1        $f18, 0x3C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X3C);
    // 0x80016854: lui         $at, 0x4049
    ctx->r1 = S32(0X4049 << 16);
    // 0x80016858: mtc1        $at, $f31
    ctx->f_odd[(31 - 1) * 2] = ctx->r1;
    // 0x8001685C: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x80016860: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80016864: add.d       $f4, $f16, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f30.d); 
    ctx->f4.d = ctx->f16.d + ctx->f30.d;
    // 0x80016868: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x8001686C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80016870: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80016874: nop

    // 0x80016878: bc1t        L_80016B9C
    if (c1cs) {
        // 0x8001687C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_80016B9C;
    }
    // 0x8001687C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x80016880: lw          $s6, 0x4C($s0)
    ctx->r22 = MEM_W(ctx->r16, 0X4C);
    // 0x80016884: lw          $s4, 0x4C($s5)
    ctx->r20 = MEM_W(ctx->r21, 0X4C);
    // 0x80016888: jal         0x8006FE70
    // 0x8001688C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x8001688C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x80016890: lh          $t8, 0x20($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X20);
    // 0x80016894: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80016898: blez        $t8, L_80016B98
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001689C: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80016B98;
    }
    // 0x8001689C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800168A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800168A4: lwc1        $f29, 0x5B88($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X5B88);
    // 0x800168A8: lwc1        $f28, 0x5B8C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X5B8C);
    // 0x800168AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800168B0: lwc1        $f27, 0x5B90($at)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r1, 0X5B90);
    // 0x800168B4: lwc1        $f26, 0x5B94($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X5B94);
    // 0x800168B8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800168BC: addiu       $s7, $zero, 0xA
    ctx->r23 = ADD32(0, 0XA);
L_800168C0:
    // 0x800168C0: lw          $t0, 0x1C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C);
    // 0x800168C4: lw          $t9, 0x44($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X44);
    // 0x800168C8: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x800168CC: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x800168D0: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800168D4: multu       $t2, $s7
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800168D8: mflo        $t3
    ctx->r11 = lo;
    // 0x800168DC: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800168E0: lh          $t5, 0x0($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X0);
    // 0x800168E4: nop

    // 0x800168E8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x800168EC: nop

    // 0x800168F0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800168F4: swc1        $f10, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f10.u32l;
    // 0x800168F8: lw          $t7, 0x1C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X1C);
    // 0x800168FC: lw          $t6, 0x44($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X44);
    // 0x80016900: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80016904: lh          $t0, 0x0($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X0);
    // 0x80016908: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x8001690C: multu       $t0, $s7
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016910: mflo        $t1
    ctx->r9 = lo;
    // 0x80016914: addu        $t2, $t6, $t1
    ctx->r10 = ADD32(ctx->r14, ctx->r9);
    // 0x80016918: lh          $t9, 0x2($t2)
    ctx->r25 = MEM_H(ctx->r10, 0X2);
    // 0x8001691C: addiu       $t2, $sp, 0xA4
    ctx->r10 = ADD32(ctx->r29, 0XA4);
    // 0x80016920: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80016924: addiu       $t9, $sp, 0xA0
    ctx->r25 = ADD32(ctx->r29, 0XA0);
    // 0x80016928: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8001692C: addiu       $t1, $sp, 0xA8
    ctx->r9 = ADD32(ctx->r29, 0XA8);
    // 0x80016930: swc1        $f16, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f16.u32l;
    // 0x80016934: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x80016938: lw          $t3, 0x44($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X44);
    // 0x8001693C: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80016940: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x80016944: lw          $a2, 0xA4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XA4);
    // 0x80016948: multu       $t7, $s7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001694C: mflo        $t8
    ctx->r24 = lo;
    // 0x80016950: addu        $t0, $t3, $t8
    ctx->r8 = ADD32(ctx->r11, ctx->r24);
    // 0x80016954: lh          $t6, 0x4($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X4);
    // 0x80016958: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8001695C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80016960: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80016964: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016968: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8001696C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016970: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80016974: jal         0x8006F88C
    // 0x80016978: nop

    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x80016978: nop

    after_2:
    // 0x8001697C: lw          $t4, 0x1C($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X1C);
    // 0x80016980: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80016984: addu        $t5, $t4, $s2
    ctx->r13 = ADD32(ctx->r12, ctx->r18);
    // 0x80016988: lh          $t7, 0x2($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X2);
    // 0x8001698C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80016990: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80016994: lwc1        $f4, 0x8($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80016998: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8001699C: nop

    // 0x800169A0: div.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800169A4: lwc1        $f18, 0xA8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x800169A8: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800169AC: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800169B0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800169B4: mul.d       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f30.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f30.d);
    // 0x800169B8: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800169BC: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800169C0: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x800169C4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800169C8: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x800169CC: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800169D0: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800169D4: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x800169D8: mul.s       $f6, $f4, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x800169DC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800169E0: nop

    // 0x800169E4: sub.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800169E8: mul.s       $f18, $f10, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800169EC: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x800169F0: mul.s       $f4, $f8, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800169F4: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800169F8: jal         0x800CA030
    // 0x800169FC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x800169FC: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_3:
    // 0x80016A00: lb          $t3, 0x10($s4)
    ctx->r11 = MEM_B(ctx->r20, 0X10);
    // 0x80016A04: nop

    // 0x80016A08: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80016A0C: nop

    // 0x80016A10: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80016A14: add.s       $f22, $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f6.fl;
    // 0x80016A18: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80016A1C: nop

    // 0x80016A20: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016A24: nop
    
            goto L_80016B84;
    }
    // 0x80016A24: nop

    // 0x80016A28: c.lt.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl < ctx->f0.fl;
    // 0x80016A2C: nop

    // 0x80016A30: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016A34: nop
    
            goto L_80016B84;
    }
    // 0x80016A34: nop

    // 0x80016A38: sub.s       $f18, $f22, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80016A3C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80016A40: div.s       $f20, $f18, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80016A44: lh          $t8, 0x14($s6)
    ctx->r24 = MEM_H(ctx->r22, 0X14);
    // 0x80016A48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016A4C: ori         $t0, $t8, 0x8
    ctx->r8 = ctx->r24 | 0X8;
    // 0x80016A50: sh          $t0, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r8;
    // 0x80016A54: lh          $t6, 0x14($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X14);
    // 0x80016A58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016A5C: ori         $t1, $t6, 0x8
    ctx->r9 = ctx->r14 | 0X8;
    // 0x80016A60: sh          $t1, 0x14($s4)
    MEM_H(0X14, ctx->r20) = ctx->r9;
    // 0x80016A64: sw          $s5, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r21;
    // 0x80016A68: sw          $s0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r16;
    // 0x80016A6C: sb          $zero, 0x13($s6)
    MEM_B(0X13, ctx->r22) = 0;
    // 0x80016A70: div.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016A74: sb          $zero, 0x13($s4)
    MEM_B(0X13, ctx->r20) = 0;
    // 0x80016A78: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016A7C: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016A80: lwc1        $f18, 0xA0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016A84: mul.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80016A88: nop

    // 0x80016A8C: mul.s       $f6, $f10, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80016A90: swc1        $f4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f4.u32l;
    // 0x80016A94: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80016A98: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
    // 0x80016A9C: swc1        $f8, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f8.u32l;
    // 0x80016AA0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016AA4: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016AA8: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016AAC: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016AB0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x80016AB4: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80016AB8: lh          $t2, 0x48($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X48);
    // 0x80016ABC: sub.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80016AC0: swc1        $f8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f8.u32l;
    // 0x80016AC4: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016AC8: nop

    // 0x80016ACC: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x80016AD0: bne         $t2, $at, L_80016B84
    if (ctx->r10 != ctx->r1) {
        // 0x80016AD4: swc1        $f10, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
            goto L_80016B84;
    }
    // 0x80016AD4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80016AD8: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80016ADC: nop

    // 0x80016AE0: lb          $t9, 0x1D8($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1D8);
    // 0x80016AE4: nop

    // 0x80016AE8: bne         $t9, $zero, L_80016AFC
    if (ctx->r25 != 0) {
        // 0x80016AEC: nop
    
            goto L_80016AFC;
    }
    // 0x80016AEC: nop

    // 0x80016AF0: lh          $a0, 0x0($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X0);
    // 0x80016AF4: jal         0x80072594
    // 0x80016AF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x80016AF8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_4:
L_80016AFC:
    // 0x80016AFC: lb          $t4, 0x1D6($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1D6);
    // 0x80016B00: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80016B04: bne         $t4, $at, L_80016B44
    if (ctx->r12 != ctx->r1) {
        // 0x80016B08: nop
    
            goto L_80016B44;
    }
    // 0x80016B08: nop

    // 0x80016B0C: cvt.d.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.d = CVT_D_S(ctx->f20.fl);
    // 0x80016B10: c.lt.d      $f26, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f26.d < ctx->f6.d;
    // 0x80016B14: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016B18: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016B1C: nop
    
            goto L_80016B84;
    }
    // 0x80016B1C: nop

    // 0x80016B20: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016B24: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016B28: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80016B2C: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x80016B30: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B34: nop

    // 0x80016B38: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80016B3C: b           L_80016B84
    // 0x80016B40: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
        goto L_80016B84;
    // 0x80016B40: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
L_80016B44:
    // 0x80016B44: cvt.d.s     $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f18.d = CVT_D_S(ctx->f20.fl);
    // 0x80016B48: c.lt.d      $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f28.d < ctx->f18.d;
    // 0x80016B4C: lwc1        $f16, 0xA8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x80016B50: bc1f        L_80016B84
    if (!c1cs) {
        // 0x80016B54: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80016B84;
    }
    // 0x80016B54: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80016B58: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80016B5C: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80016B60: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80016B64: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80016B68: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x80016B6C: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80016B70: mul.s       $f16, $f20, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80016B74: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80016B78: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80016B7C: swc1        $f16, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f16.u32l;
    // 0x80016B80: swc1        $f24, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f24.u32l;
L_80016B84:
    // 0x80016B84: lh          $t5, 0x20($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X20);
    // 0x80016B88: addiu       $fp, $fp, 0x2
    ctx->r30 = ADD32(ctx->r30, 0X2);
    // 0x80016B8C: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80016B90: bne         $at, $zero, L_800168C0
    if (ctx->r1 != 0) {
        // 0x80016B94: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800168C0;
    }
    // 0x80016B94: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016B98:
    // 0x80016B98: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_80016B9C:
    // 0x80016B9C: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016BA0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016BA4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016BA8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016BAC: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80016BB0: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80016BB4: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80016BB8: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80016BBC: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x80016BC0: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80016BC4: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x80016BC8: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80016BCC: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x80016BD0: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x80016BD4: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x80016BD8: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x80016BDC: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x80016BE0: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x80016BE4: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x80016BE8: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x80016BEC: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80016BF0: jr          $ra
    // 0x80016BF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x80016BF4: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void copy_framebuffer_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066EC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80066EC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80066EC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80066ECC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80066ED0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80066ED4: jal         0x8007A970
    // 0x80066ED8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x80066ED8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066EDC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80066EE0: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x80066EE4: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x80066EE8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80066EEC: srl         $t0, $v0, 16
    ctx->r8 = S32(U32(ctx->r2) >> 16);
    // 0x80066EF0: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x80066EF4: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80066EF8: nop

    // 0x80066EFC: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80066F00: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80066F04: nop

    // 0x80066F08: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80066F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80066F10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80066F14: jr          $ra
    // 0x80066F18: nop

    return;
    // 0x80066F18: nop

;}
RECOMP_FUNC void _bzero(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0A40: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x800D0A44: bne         $at, $zero, L_800D0ABC
    if (ctx->r1 != 0) {
        // 0x800D0A48: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_800D0ABC;
    }
    // 0x800D0A48: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800D0A4C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x800D0A50: beq         $v1, $zero, L_800D0A60
    if (ctx->r3 == 0) {
        // 0x800D0A54: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_800D0A60;
    }
    // 0x800D0A54: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x800D0A58: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x800D0A5C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_800D0A60:
    // 0x800D0A60: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x800D0A64: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0A68: beq         $a3, $zero, L_800D0A9C
    if (ctx->r7 == 0) {
        // 0x800D0A6C: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D0A9C;
    }
    // 0x800D0A6C: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D0A70: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0A74:
    // 0x800D0A74: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D0A78: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x800D0A7C: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x800D0A80: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x800D0A84: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x800D0A88: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x800D0A8C: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x800D0A90: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x800D0A94: bne         $a0, $a3, L_800D0A74
    if (ctx->r4 != ctx->r7) {
        // 0x800D0A98: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0A74;
    }
    // 0x800D0A98: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D0A9C:
    // 0x800D0A9C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800D0AA0: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x800D0AA4: beq         $a3, $zero, L_800D0ABC
    if (ctx->r7 == 0) {
        // 0x800D0AA8: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_800D0ABC;
    }
    // 0x800D0AA8: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x800D0AAC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_800D0AB0:
    // 0x800D0AB0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D0AB4: bne         $a0, $a3, L_800D0AB0
    if (ctx->r4 != ctx->r7) {
        // 0x800D0AB8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_800D0AB0;
    }
    // 0x800D0AB8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_800D0ABC:
    // 0x800D0ABC: blez        $a1, L_800D0AD4
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800D0AC0: nop
    
            goto L_800D0AD4;
    }
    // 0x800D0AC0: nop

    // 0x800D0AC4: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_800D0AC8:
    // 0x800D0AC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800D0ACC: bne         $a0, $a1, L_800D0AC8
    if (ctx->r4 != ctx->r5) {
        // 0x800D0AD0: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_800D0AC8;
    }
    // 0x800D0AD0: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_800D0AD4:
    // 0x800D0AD4: jr          $ra
    // 0x800D0AD8: nop

    return;
    // 0x800D0AD8: nop

;}
RECOMP_FUNC void open_dialogue_box(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5B54: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5B58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5B5C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5B60: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5B64: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5B68: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5B6C: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5B70: nop

    // 0x800C5B74: ori         $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 | 0X8000;
    // 0x800C5B78: jr          $ra
    // 0x800C5B7C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5B7C: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void audspat_point_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800096FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009700: lw          $v0, -0x5E3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E3C);
    // 0x80009704: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009708: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000970C: addiu       $v1, $zero, 0x28
    ctx->r3 = ADD32(0, 0X28);
L_80009710:
    // 0x80009710: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80009714: nop

    // 0x80009718: bne         $a0, $t6, L_80009730
    if (ctx->r4 != ctx->r14) {
        // 0x8000971C: nop
    
            goto L_80009730;
    }
    // 0x8000971C: nop

    // 0x80009720: jal         0x8000A2E8
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    audspat_point_stop_by_index(rdram, ctx);
        goto after_0;
    // 0x80009724: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80009728: b           L_80009740
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009740;
    // 0x8000972C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009730:
    // 0x80009730: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80009734: bne         $a1, $v1, L_80009710
    if (ctx->r5 != ctx->r3) {
        // 0x80009738: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80009710;
    }
    // 0x80009738: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000973C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009740:
    // 0x80009740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009744: jr          $ra
    // 0x80009748: nop

    return;
    // 0x80009748: nop

;}
RECOMP_FUNC void func_80016500(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016534: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80016538: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001653C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016540: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80016544: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80016548: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8001654C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80016550: lb          $t6, 0x1D6($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D6);
    // 0x80016554: lh          $v0, 0x1A0($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A0);
    // 0x80016558: bne         $t6, $zero, L_80016588
    if (ctx->r14 != 0) {
        // 0x8001655C: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016588;
    }
    // 0x8001655C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80016560: lb          $t7, 0x1E6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1E6);
    // 0x80016564: nop

    // 0x80016568: beq         $t7, $zero, L_80016588
    if (ctx->r15 == 0) {
        // 0x8001656C: negu        $a0, $v0
        ctx->r4 = SUB32(0, ctx->r2);
            goto L_80016588;
    }
    // 0x8001656C: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
    // 0x80016570: lw          $t8, 0x10C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10C);
    // 0x80016574: nop

    // 0x80016578: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8001657C: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x80016580: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80016584: negu        $a0, $v0
    ctx->r4 = SUB32(0, ctx->r2);
L_80016588:
    // 0x80016588: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x8001658C: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80016590: jal         0x80070A38
    // 0x80016594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80016594: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80016598: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8001659C: jal         0x80070A04
    // 0x800165A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800165A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800165A4: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x800165A8: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800165AC: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800165B0: lwc1        $f10, 0x24($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X24);
    // 0x800165B4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800165B8: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800165BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800165C0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800165C4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800165C8: swc1        $f18, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f18.u32l;
    // 0x800165CC: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800165D0: nop

    // 0x800165D4: lwc1        $f4, 0x1C($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x800165D8: lwc1        $f8, 0x24($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800165DC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800165E0: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800165E4: nop

    // 0x800165E8: mul.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800165EC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800165F0: beq         $t5, $at, L_8001676C
    if (ctx->r13 == ctx->r1) {
        // 0x800165F4: swc1        $f18, 0x2C($s0)
        MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
            goto L_8001676C;
    }
    // 0x800165F4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x800165F8: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800165FC: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x80016600: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x80016604: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80016608: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001660C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80016610: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80016614: nop

    // 0x80016618: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001661C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016620: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80016624: nop

    // 0x80016628: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001662C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80016630: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80016634: bgez        $v0, L_80016640
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80016638: nop
    
            goto L_80016640;
    }
    // 0x80016638: nop

    // 0x8001663C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_80016640:
    // 0x80016640: addiu       $v0, $v0, 0x23
    ctx->r2 = ADD32(ctx->r2, 0X23);
    // 0x80016644: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x80016648: bne         $at, $zero, L_80016654
    if (ctx->r1 != 0) {
        // 0x8001664C: addiu       $a0, $zero, 0xD
        ctx->r4 = ADD32(0, 0XD);
            goto L_80016654;
    }
    // 0x8001664C: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80016650: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80016654:
    // 0x80016654: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016658: addiu       $a1, $s0, 0x220
    ctx->r5 = ADD32(ctx->r16, 0X220);
    // 0x8001665C: bne         $v1, $zero, L_8001668C
    if (ctx->r3 != 0) {
        // 0x80016660: nop
    
            goto L_8001668C;
    }
    // 0x80016660: nop

    // 0x80016664: jal         0x80001D04
    // 0x80016668: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80016668: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_2:
    // 0x8001666C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016670: lw          $a1, 0x220($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X220);
    // 0x80016674: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    // 0x80016678: jal         0x80001FB8
    // 0x8001667C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    sound_volume_set_relative(rdram, ctx);
        goto after_3;
    // 0x8001667C: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    after_3:
    // 0x80016680: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80016684: lb          $v1, 0x1F6($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X1F6);
    // 0x80016688: nop

L_8001668C:
    // 0x8001668C: bne         $v1, $zero, L_800166D0
    if (ctx->r3 != 0) {
        // 0x80016690: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_800166D0;
    }
    // 0x80016690: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x80016694: bne         $at, $zero, L_800166D4
    if (ctx->r1 != 0) {
        // 0x80016698: slti        $at, $v0, 0x38
        ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
            goto L_800166D4;
    }
    // 0x80016698: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x8001669C: lb          $t7, 0x1D8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D8);
    // 0x800166A0: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x800166A4: bne         $t7, $zero, L_800166C0
    if (ctx->r15 != 0) {
        // 0x800166A8: nop
    
            goto L_800166C0;
    }
    // 0x800166A8: nop

    // 0x800166AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800166B0: jal         0x80072594
    // 0x800166B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    rumble_set(rdram, ctx);
        goto after_4;
    // 0x800166B4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_4:
    // 0x800166B8: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800166BC: nop

L_800166C0:
    // 0x800166C0: lbu         $t8, 0x1F3($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1F3);
    // 0x800166C4: nop

    // 0x800166C8: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x800166CC: sb          $t9, 0x1F3($s0)
    MEM_B(0X1F3, ctx->r16) = ctx->r25;
L_800166D0:
    // 0x800166D0: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
L_800166D4:
    // 0x800166D4: bne         $at, $zero, L_800166EC
    if (ctx->r1 != 0) {
        // 0x800166D8: addiu       $a1, $zero, 0x1C2
        ctx->r5 = ADD32(0, 0X1C2);
            goto L_800166EC;
    }
    // 0x800166D8: addiu       $a1, $zero, 0x1C2
    ctx->r5 = ADD32(0, 0X1C2);
    // 0x800166DC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800166E0: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800166E4: jal         0x800570F8
    // 0x800166E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    play_random_character_voice(rdram, ctx);
        goto after_5;
    // 0x800166E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
L_800166EC:
    // 0x800166EC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800166F0: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800166F4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800166F8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800166FC: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80016700: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80016704: nop

    // 0x80016708: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001670C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80016710: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80016714: nop

    // 0x80016718: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001671C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80016720: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80016724: bgez        $v1, L_80016734
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80016728: slti        $at, $v1, 0x4
        ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80016734;
    }
    // 0x80016728: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8001672C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80016730: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_80016734:
    // 0x80016734: bne         $at, $zero, L_80016740
    if (ctx->r1 != 0) {
        // 0x80016738: nop
    
            goto L_80016740;
    }
    // 0x80016738: nop

    // 0x8001673C: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80016740:
    // 0x80016740: sb          $t1, 0x1F6($s0)
    MEM_B(0X1F6, ctx->r16) = ctx->r9;
    // 0x80016744: jal         0x80066828
    // 0x80016748: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    set_active_camera(rdram, ctx);
        goto after_6;
    // 0x80016748: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_6:
    // 0x8001674C: jal         0x80069F60
    // 0x80016750: nop

    cam_get_active_camera(rdram, ctx);
        goto after_7;
    // 0x80016750: nop

    after_7:
    // 0x80016754: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80016758: nop

    // 0x8001675C: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x80016760: nop

    // 0x80016764: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80016768: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
L_8001676C:
    // 0x8001676C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80016770: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016774: jr          $ra
    // 0x80016778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80016778: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_wave_properties(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AD4C: lb          $v0, -0x2778($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X2778);
    // 0x8002AD50: beq         $a2, $zero, L_8002AD70
    if (ctx->r6 == 0) {
        // 0x8002AD54: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002AD70;
    }
    // 0x8002AD54: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AD58: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002AD5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002AD60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002AD64: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD68: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8002AD6C: swc1        $f4, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f4.u32l;
L_8002AD70:
    // 0x8002AD70: blez        $v0, L_8002AE84
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AD74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8002AE84;
    }
    // 0x8002AD74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002AD78: andi        $t1, $v0, 0x3
    ctx->r9 = ctx->r2 & 0X3;
    // 0x8002AD7C: beq         $t1, $zero, L_8002ADCC
    if (ctx->r9 == 0) {
        // 0x8002AD80: or          $a3, $t1, $zero
        ctx->r7 = ctx->r9 | 0;
            goto L_8002ADCC;
    }
    // 0x8002AD80: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8002AD84: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AD88: addiu       $t7, $t7, -0x27C8
    ctx->r15 = ADD32(ctx->r15, -0X27C8);
    // 0x8002AD8C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8002AD90: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AD94: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AD98: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
L_8002AD9C:
    // 0x8002AD9C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8002ADA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002ADA4: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002ADA8: nop

    // 0x8002ADAC: beq         $t3, $t2, L_8002ADBC
    if (ctx->r11 == ctx->r10) {
        // 0x8002ADB0: nop
    
            goto L_8002ADBC;
    }
    // 0x8002ADB0: nop

    // 0x8002ADB4: bne         $t4, $t2, L_8002ADC0
    if (ctx->r12 != ctx->r10) {
        // 0x8002ADB8: nop
    
            goto L_8002ADC0;
    }
    // 0x8002ADB8: nop

L_8002ADBC:
    // 0x8002ADBC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002ADC0:
    // 0x8002ADC0: bne         $a3, $v1, L_8002AD9C
    if (ctx->r7 != ctx->r3) {
        // 0x8002ADC4: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8002AD9C;
    }
    // 0x8002ADC4: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8002ADC8: beq         $v1, $v0, L_8002AE84
    if (ctx->r3 == ctx->r2) {
        // 0x8002ADCC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AE84;
    }
L_8002ADCC:
    // 0x8002ADCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002ADD0: addiu       $t5, $t5, -0x27C8
    ctx->r13 = ADD32(ctx->r13, -0X27C8);
    // 0x8002ADD4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8002ADD8: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8002ADDC: addu        $t0, $t6, $t5
    ctx->r8 = ADD32(ctx->r14, ctx->r13);
    // 0x8002ADE0: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8002ADE4: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002ADE8: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
L_8002ADEC:
    // 0x8002ADEC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8002ADF0: nop

    // 0x8002ADF4: lb          $t2, 0x10($t7)
    ctx->r10 = MEM_B(ctx->r15, 0X10);
    // 0x8002ADF8: nop

    // 0x8002ADFC: beq         $t3, $t2, L_8002AE0C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AE00: nop
    
            goto L_8002AE0C;
    }
    // 0x8002AE00: nop

    // 0x8002AE04: bne         $t4, $t2, L_8002AE10
    if (ctx->r12 != ctx->r10) {
        // 0x8002AE08: nop
    
            goto L_8002AE10;
    }
    // 0x8002AE08: nop

L_8002AE0C:
    // 0x8002AE0C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE10:
    // 0x8002AE10: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x8002AE14: nop

    // 0x8002AE18: lb          $t2, 0x10($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X10);
    // 0x8002AE1C: nop

    // 0x8002AE20: beq         $t3, $t2, L_8002AE30
    if (ctx->r11 == ctx->r10) {
        // 0x8002AE24: nop
    
            goto L_8002AE30;
    }
    // 0x8002AE24: nop

    // 0x8002AE28: bne         $t4, $t2, L_8002AE34
    if (ctx->r12 != ctx->r10) {
        // 0x8002AE2C: nop
    
            goto L_8002AE34;
    }
    // 0x8002AE2C: nop

L_8002AE30:
    // 0x8002AE30: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE34:
    // 0x8002AE34: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002AE38: nop

    // 0x8002AE3C: lb          $v1, 0x10($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X10);
    // 0x8002AE40: nop

    // 0x8002AE44: beq         $t3, $v1, L_8002AE54
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE48: nop
    
            goto L_8002AE54;
    }
    // 0x8002AE48: nop

    // 0x8002AE4C: bne         $t4, $v1, L_8002AE58
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE50: nop
    
            goto L_8002AE58;
    }
    // 0x8002AE50: nop

L_8002AE54:
    // 0x8002AE54: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE58:
    // 0x8002AE58: lw          $t6, 0xC($t0)
    ctx->r14 = MEM_W(ctx->r8, 0XC);
    // 0x8002AE5C: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8002AE60: lb          $v1, 0x10($t6)
    ctx->r3 = MEM_B(ctx->r14, 0X10);
    // 0x8002AE64: nop

    // 0x8002AE68: beq         $t3, $v1, L_8002AE78
    if (ctx->r11 == ctx->r3) {
        // 0x8002AE6C: nop
    
            goto L_8002AE78;
    }
    // 0x8002AE6C: nop

    // 0x8002AE70: bne         $t4, $v1, L_8002AE7C
    if (ctx->r12 != ctx->r3) {
        // 0x8002AE74: nop
    
            goto L_8002AE7C;
    }
    // 0x8002AE74: nop

L_8002AE78:
    // 0x8002AE78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8002AE7C:
    // 0x8002AE7C: bne         $t0, $a3, L_8002ADEC
    if (ctx->r8 != ctx->r7) {
        // 0x8002AE80: nop
    
            goto L_8002ADEC;
    }
    // 0x8002AE80: nop

L_8002AE84:
    // 0x8002AE84: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x8002AE88: bne         $a0, $zero, L_8002AE98
    if (ctx->r4 != 0) {
        // 0x8002AE8C: addiu       $t4, $zero, 0xE
        ctx->r12 = ADD32(0, 0XE);
            goto L_8002AE98;
    }
    // 0x8002AE8C: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x8002AE90: jr          $ra
    // 0x8002AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002AE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002AE98:
    // 0x8002AE98: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8002AE9C: blez        $v0, L_8002B0B0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002AEA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002B0B0;
    }
    // 0x8002AEA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002AEA4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8002AEA8: beq         $t0, $zero, L_8002AF34
    if (ctx->r8 == 0) {
        // 0x8002AEAC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002AF34;
    }
    // 0x8002AEAC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002AEB0: lw          $t5, -0x27C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X27C8);
    // 0x8002AEB4: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AEB8: lb          $v1, 0x10($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X10);
    // 0x8002AEBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002AEC0: beq         $t3, $v1, L_8002AED0
    if (ctx->r11 == ctx->r3) {
        // 0x8002AEC4: nop
    
            goto L_8002AED0;
    }
    // 0x8002AEC4: nop

    // 0x8002AEC8: bne         $t4, $v1, L_8002AF30
    if (ctx->r12 != ctx->r3) {
        // 0x8002AECC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AECC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AED0:
    // 0x8002AED0: lw          $t7, -0x27C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X27C8);
    // 0x8002AED4: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AED8: lwc1        $f8, 0x0($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002AEDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AEE0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AEE4: add.d       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f10.d + ctx->f2.d;
    // 0x8002AEE8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AEEC: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AEF0: c.lt.d      $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f6.d < ctx->f16.d;
    // 0x8002AEF4: nop

    // 0x8002AEF8: bc1f        L_8002AF30
    if (!c1cs) {
        // 0x8002AEFC: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AEFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002AF00: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x8002AF04: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AF08: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AF0C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8002AF10: c.lt.d      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.d < ctx->f8.d;
    // 0x8002AF14: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AF18: bc1t        L_8002AF28
    if (c1cs) {
        // 0x8002AF1C: nop
    
            goto L_8002AF28;
    }
    // 0x8002AF1C: nop

    // 0x8002AF20: bne         $a0, $at, L_8002AF30
    if (ctx->r4 != ctx->r1) {
        // 0x8002AF24: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8002AF30;
    }
    // 0x8002AF24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AF28:
    // 0x8002AF28: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002AF2C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8002AF30:
    // 0x8002AF30: beq         $v1, $v0, L_8002B0B0
    if (ctx->r3 == ctx->r2) {
        // 0x8002AF34: lui         $at, 0x4039
        ctx->r1 = S32(0X4039 << 16);
            goto L_8002B0B0;
    }
L_8002AF34:
    // 0x8002AF34: lui         $at, 0x4039
    ctx->r1 = S32(0X4039 << 16);
    // 0x8002AF38: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8002AF3C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8002AF40: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002AF44: addiu       $t9, $t9, -0x27C8
    ctx->r25 = ADD32(ctx->r25, -0X27C8);
    // 0x8002AF48: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8002AF4C: mtc1        $at, $f15
    ctx->f_odd[(15 - 1) * 2] = ctx->r1;
    // 0x8002AF50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002AF54: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8002AF58: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8002AF5C:
    // 0x8002AF5C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8002AF60: nop

    // 0x8002AF64: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002AF68: nop

    // 0x8002AF6C: beq         $t3, $t2, L_8002AF7C
    if (ctx->r11 == ctx->r10) {
        // 0x8002AF70: nop
    
            goto L_8002AF7C;
    }
    // 0x8002AF70: nop

    // 0x8002AF74: bne         $t4, $t2, L_8002AFD0
    if (ctx->r12 != ctx->r10) {
        // 0x8002AF78: nop
    
            goto L_8002AFD0;
    }
    // 0x8002AF78: nop

L_8002AF7C:
    // 0x8002AF7C: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AF80: cvt.d.s     $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AF84: cvt.d.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f16.d = CVT_D_S(ctx->f6.fl);
    // 0x8002AF88: add.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f16.d + ctx->f2.d;
    // 0x8002AF8C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002AF90: c.lt.d      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.d < ctx->f4.d;
    // 0x8002AF94: nop

    // 0x8002AF98: bc1f        L_8002B004
    if (!c1cs) {
        // 0x8002AF9C: nop
    
            goto L_8002B004;
    }
    // 0x8002AF9C: nop

    // 0x8002AFA0: lwc1        $f8, 0x8($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002AFA4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002AFA8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002AFAC: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8002AFB0: c.lt.d      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.d < ctx->f6.d;
    // 0x8002AFB4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002AFB8: bc1t        L_8002AFC8
    if (c1cs) {
        // 0x8002AFBC: nop
    
            goto L_8002AFC8;
    }
    // 0x8002AFBC: nop

    // 0x8002AFC0: bne         $a0, $at, L_8002B004
    if (ctx->r4 != ctx->r1) {
        // 0x8002AFC4: nop
    
            goto L_8002B004;
    }
    // 0x8002AFC4: nop

L_8002AFC8:
    // 0x8002AFC8: b           L_8002B004
    // 0x8002AFCC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
        goto L_8002B004;
    // 0x8002AFCC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_8002AFD0:
    // 0x8002AFD0: bltz        $a3, L_8002B004
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002AFD4: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002B004;
    }
    // 0x8002AFD4: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002AFD8: bne         $at, $zero, L_8002B004
    if (ctx->r1 != 0) {
        // 0x8002AFDC: nop
    
            goto L_8002B004;
    }
    // 0x8002AFDC: nop

    // 0x8002AFE0: lwc1        $f10, 0x0($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002AFE4: cvt.d.s     $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.d = CVT_D_S(ctx->f12.fl);
    // 0x8002AFE8: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x8002AFEC: sub.d       $f8, $f4, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = ctx->f4.d - ctx->f14.d;
    // 0x8002AFF0: c.lt.d      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.d < ctx->f8.d;
    // 0x8002AFF4: nop

    // 0x8002AFF8: bc1f        L_8002B004
    if (!c1cs) {
        // 0x8002AFFC: nop
    
            goto L_8002B004;
    }
    // 0x8002AFFC: nop

    // 0x8002B000: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002B004:
    // 0x8002B004: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8002B008: nop

    // 0x8002B00C: lb          $t2, 0x10($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X10);
    // 0x8002B010: lwc1        $f0, 0x0($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002B014: beq         $t3, $t2, L_8002B024
    if (ctx->r11 == ctx->r10) {
        // 0x8002B018: nop
    
            goto L_8002B024;
    }
    // 0x8002B018: nop

    // 0x8002B01C: bne         $t4, $t2, L_8002B074
    if (ctx->r12 != ctx->r10) {
        // 0x8002B020: nop
    
            goto L_8002B074;
    }
    // 0x8002B020: nop

L_8002B024:
    // 0x8002B024: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B028: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8002B02C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002B030: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8002B034: c.lt.d      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.d < ctx->f10.d;
    // 0x8002B038: nop

    // 0x8002B03C: bc1f        L_8002B0A4
    if (!c1cs) {
        // 0x8002B040: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B040: nop

    // 0x8002B044: lwc1        $f16, 0x8($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X8);
    // 0x8002B048: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8002B04C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B050: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x8002B054: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002B058: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002B05C: bc1t        L_8002B06C
    if (c1cs) {
        // 0x8002B060: nop
    
            goto L_8002B06C;
    }
    // 0x8002B060: nop

    // 0x8002B064: bne         $a0, $at, L_8002B0A4
    if (ctx->r4 != ctx->r1) {
        // 0x8002B068: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B068: nop

L_8002B06C:
    // 0x8002B06C: b           L_8002B0A4
    // 0x8002B070: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
        goto L_8002B0A4;
    // 0x8002B070: addiu       $a3, $v1, 0x1
    ctx->r7 = ADD32(ctx->r3, 0X1);
L_8002B074:
    // 0x8002B074: bltz        $a3, L_8002B0A4
    if (SIGNED(ctx->r7) < 0) {
        // 0x8002B078: slti        $at, $a0, 0x2
        ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
            goto L_8002B0A4;
    }
    // 0x8002B078: slti        $at, $a0, 0x2
    ctx->r1 = SIGNED(ctx->r4) < 0X2 ? 1 : 0;
    // 0x8002B07C: bne         $at, $zero, L_8002B0A4
    if (ctx->r1 != 0) {
        // 0x8002B080: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B080: nop

    // 0x8002B084: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B088: sub.d       $f10, $f18, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f18.d - ctx->f14.d;
    // 0x8002B08C: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x8002B090: c.lt.d      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.d < ctx->f10.d;
    // 0x8002B094: nop

    // 0x8002B098: bc1f        L_8002B0A4
    if (!c1cs) {
        // 0x8002B09C: nop
    
            goto L_8002B0A4;
    }
    // 0x8002B09C: nop

    // 0x8002B0A0: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8002B0A4:
    // 0x8002B0A4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8002B0A8: bne         $v1, $v0, L_8002AF5C
    if (ctx->r3 != ctx->r2) {
        // 0x8002B0AC: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8002AF5C;
    }
    // 0x8002B0AC: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_8002B0B0:
    // 0x8002B0B0: bgez        $a3, L_8002B0C0
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8002B0B4: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_8002B0C0;
    }
    // 0x8002B0B4: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8002B0B8: jr          $ra
    // 0x8002B0BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002B0BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002B0C0:
    // 0x8002B0C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002B0C4: addiu       $t5, $t5, -0x27C8
    ctx->r13 = ADD32(ctx->r13, -0X27C8);
    // 0x8002B0C8: addu        $v1, $t6, $t5
    ctx->r3 = ADD32(ctx->r14, ctx->r13);
    // 0x8002B0CC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0D0: nop

    // 0x8002B0D4: lwc1        $f16, 0x0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8002B0D8: beq         $a2, $zero, L_8002B11C
    if (ctx->r6 == 0) {
        // 0x8002B0DC: swc1        $f16, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
            goto L_8002B11C;
    }
    // 0x8002B0DC: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x8002B0E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0E4: nop

    // 0x8002B0E8: lwc1        $f4, 0x4($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X4);
    // 0x8002B0EC: nop

    // 0x8002B0F0: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x8002B0F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002B0F8: nop

    // 0x8002B0FC: lwc1        $f8, 0x8($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X8);
    // 0x8002B100: nop

    // 0x8002B104: swc1        $f8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f8.u32l;
    // 0x8002B108: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002B10C: nop

    // 0x8002B110: lwc1        $f18, 0xC($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8002B114: nop

    // 0x8002B118: swc1        $f18, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f18.u32l;
L_8002B11C:
    // 0x8002B11C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8002B120: nop

    // 0x8002B124: lb          $v0, 0x10($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X10);
    // 0x8002B128: nop

    // 0x8002B12C: jr          $ra
    // 0x8002B130: nop

    return;
    // 0x8002B130: nop

;}
RECOMP_FUNC void obj_init_silvercoin_adv2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DBE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DBE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DBE8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003DBEC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBF0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DBF4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DBF8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DBFC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DC00: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DC04: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DC08: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8003DC0C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DC10: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
    // 0x8003DC14: sw          $t1, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r9;
    // 0x8003DC18: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8003DC1C: jal         0x8009C814
    // 0x8003DC20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x8003DC20: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DC24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC28: bne         $v0, $zero, L_8003DC68
    if (ctx->r2 != 0) {
        // 0x8003DC2C: nop
    
            goto L_8003DC68;
    }
    // 0x8003DC2C: nop

    // 0x8003DC30: jal         0x8000E1DC
    // 0x8003DC34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    check_if_silver_coin_race(rdram, ctx);
        goto after_1;
    // 0x8003DC34: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8003DC38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC3C: beq         $v0, $zero, L_8003DC64
    if (ctx->r2 == 0) {
        // 0x8003DC40: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC64;
    }
    // 0x8003DC40: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC44: jal         0x8009F1B4
    // 0x8003DC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_adventure_two(rdram, ctx);
        goto after_2;
    // 0x8003DC48: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_2:
    // 0x8003DC4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8003DC50: beq         $v0, $zero, L_8003DC64
    if (ctx->r2 == 0) {
        // 0x8003DC54: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8003DC64;
    }
    // 0x8003DC54: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8003DC58: b           L_8003DC68
    // 0x8003DC5C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
        goto L_8003DC68;
    // 0x8003DC5C: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x8003DC60: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
L_8003DC64:
    // 0x8003DC64: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
L_8003DC68:
    // 0x8003DC68: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8003DC6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003DC70: bne         $t4, $at, L_8003DC90
    if (ctx->r12 != ctx->r1) {
        // 0x8003DC74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DC90;
    }
    // 0x8003DC74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003DC78: lh          $t5, 0x6($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X6);
    // 0x8003DC7C: nop

    // 0x8003DC80: ori         $t6, $t5, 0x600
    ctx->r14 = ctx->r13 | 0X600;
    // 0x8003DC84: jal         0x8000FFB8
    // 0x8003DC88: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    free_object(rdram, ctx);
        goto after_3;
    // 0x8003DC88: sh          $t6, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r14;
    after_3:
    // 0x8003DC8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DC90:
    // 0x8003DC90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003DC94: jr          $ra
    // 0x8003DC98: nop

    return;
    // 0x8003DC98: nop

;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE6FC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE700: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800CE704: beq         $t6, $zero, L_800CE71C
    if (ctx->r14 == 0) {
        // 0x800CE708: nop
    
            goto L_800CE71C;
    }
    // 0x800CE708: nop

    // 0x800CE70C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_800CE710:
    // 0x800CE710: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CE714: bnel        $t7, $zero, L_800CE710
    if (ctx->r15 != 0) {
        // 0x800CE718: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_800CE710;
    }
    goto skip_0;
    // 0x800CE718: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_800CE71C:
    // 0x800CE71C: jr          $ra
    // 0x800CE720: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x800CE720: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void get_current_viewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066460: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80066464: lw          $v0, 0x1264($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1264);
    // 0x80066468: jr          $ra
    // 0x8006646C: nop

    return;
    // 0x8006646C: nop

;}
RECOMP_FUNC void find_next_subtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C32C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C32C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C32CC: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C32D0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C32D4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C32D8: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C32DC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C32E0: addiu       $s1, $s1, -0x5270
    ctx->r17 = ADD32(ctx->r17, -0X5270);
    // 0x800C32E4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C32E8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C32EC: addiu       $s4, $s4, -0x5294
    ctx->r20 = ADD32(ctx->r20, -0X5294);
    // 0x800C32F0: addiu       $s3, $s3, -0x5288
    ctx->r19 = ADD32(ctx->r19, -0X5288);
    // 0x800C32F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C32F8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C32FC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C3300: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C3304: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C3308: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C330C: sh          $zero, 0x0($s3)
    MEM_H(0X0, ctx->r19) = 0;
    // 0x800C3310: sh          $zero, 0x0($s4)
    MEM_H(0X0, ctx->r20) = 0;
    // 0x800C3314: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3318: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C331C: beq         $v0, $zero, L_800C3430
    if (ctx->r2 == 0) {
        // 0x800C3320: addiu       $fp, $zero, 0xA
        ctx->r30 = ADD32(0, 0XA);
            goto L_800C3430;
    }
    // 0x800C3320: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x800C3324: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C3328: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C332C: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C3330: addiu       $s5, $s5, -0x5286
    ctx->r21 = ADD32(ctx->r21, -0X5286);
    // 0x800C3334: addiu       $s6, $s6, -0x5280
    ctx->r22 = ADD32(ctx->r22, -0X5280);
    // 0x800C3338: addiu       $s7, $zero, 0x6
    ctx->r23 = ADD32(0, 0X6);
    // 0x800C333C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C3340:
    // 0x800C3340: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x800C3344: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x800C3348: sh          $t6, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r14;
    // 0x800C334C: sw          $s0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r16;
    // 0x800C3350: lbu         $t9, 0x7($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X7);
    // 0x800C3354: nop

    // 0x800C3358: multu       $t9, $s7
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C335C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C3360: jal         0x8000C8B4
    // 0x800C3364: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800C3364: nop

    after_0:
    // 0x800C3368: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800C336C: sh          $v0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r2;
    // 0x800C3370: addiu       $s0, $t0, 0x8
    ctx->r16 = ADD32(ctx->r8, 0X8);
    // 0x800C3374: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C3378: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C337C: nop

    // 0x800C3380: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
L_800C3384:
    // 0x800C3384: beq         $t2, $zero, L_800C3398
    if (ctx->r10 == 0) {
        // 0x800C3388: addiu       $t4, $s0, 0x1
        ctx->r12 = ADD32(ctx->r16, 0X1);
            goto L_800C3398;
    }
    // 0x800C3388: addiu       $t4, $s0, 0x1
    ctx->r12 = ADD32(ctx->r16, 0X1);
    // 0x800C338C: addiu       $t3, $s0, 0x2
    ctx->r11 = ADD32(ctx->r16, 0X2);
    // 0x800C3390: b           L_800C339C
    // 0x800C3394: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
        goto L_800C339C;
    // 0x800C3394: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
L_800C3398:
    // 0x800C3398: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
L_800C339C:
    // 0x800C339C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800C33A0: nop

    // 0x800C33A4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C33A8: nop

    // 0x800C33AC: bne         $v1, $zero, L_800C3384
    if (ctx->r3 != 0) {
        // 0x800C33B0: andi        $t2, $v1, 0x80
        ctx->r10 = ctx->r3 & 0X80;
            goto L_800C3384;
    }
    // 0x800C33B0: andi        $t2, $v1, 0x80
    ctx->r10 = ctx->r3 & 0X80;
    // 0x800C33B4: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x800C33B8: addiu       $t7, $s0, 0x1
    ctx->r15 = ADD32(ctx->r16, 0X1);
    // 0x800C33BC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800C33C0: sh          $t6, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r14;
    // 0x800C33C4: lh          $a1, 0x0($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X0);
    // 0x800C33C8: nop

    // 0x800C33CC: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x800C33D0: bne         $at, $zero, L_800C33DC
    if (ctx->r1 != 0) {
        // 0x800C33D4: nop
    
            goto L_800C33DC;
    }
    // 0x800C33D4: nop

    // 0x800C33D8: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C33DC:
    // 0x800C33DC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800C33E0: lbu         $v0, 0x0($t7)
    ctx->r2 = MEM_BU(ctx->r15, 0X0);
    // 0x800C33E4: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800C33E8: bne         $fp, $v0, L_800C3404
    if (ctx->r30 != ctx->r2) {
        // 0x800C33EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C3404;
    }
    // 0x800C33EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C33F0: addiu       $s0, $t7, 0x1
    ctx->r16 = ADD32(ctx->r15, 0X1);
    // 0x800C33F4: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800C33F8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C33FC: b           L_800C3420
    // 0x800C3400: nop

        goto L_800C3420;
    // 0x800C3400: nop

L_800C3404:
    // 0x800C3404: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800C3408: bne         $v1, $at, L_800C3420
    if (ctx->r3 != ctx->r1) {
        // 0x800C340C: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_800C3420;
    }
    // 0x800C340C: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x800C3410: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800C3414: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x800C3418: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C341C: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
L_800C3420:
    // 0x800C3420: beq         $v0, $zero, L_800C3430
    if (ctx->r2 == 0) {
        // 0x800C3424: nop
    
            goto L_800C3430;
    }
    // 0x800C3424: nop

    // 0x800C3428: beq         $s2, $zero, L_800C3340
    if (ctx->r18 == 0) {
        // 0x800C342C: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C3340;
    }
    // 0x800C342C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
L_800C3430:
    // 0x800C3430: lh          $t0, 0x0($s3)
    ctx->r8 = MEM_H(ctx->r19, 0X0);
    // 0x800C3434: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800C3438: blez        $t0, L_800C3444
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800C343C: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C3444;
    }
    // 0x800C343C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3440: sh          $t1, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = ctx->r9;
L_800C3444:
    // 0x800C3444: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C3448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C344C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C3450: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C3454: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C3458: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C345C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C3460: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C3464: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C3468: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C346C: jr          $ra
    // 0x800C3470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C3470: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void level_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B490: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006B494: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006B498: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8006B49C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8006B4A0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8006B4A4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8006B4A8: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8006B4AC: jal         0x80072954
    // 0x8006B4B0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x8006B4B0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8006B4B4: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x8006B4B8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006B4BC: bne         $t6, $v0, L_8006B4CC
    if (ctx->r14 != ctx->r2) {
        // 0x8006B4C0: lw          $t7, 0x64($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X64);
            goto L_8006B4CC;
    }
    // 0x8006B4C0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4C4: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B4C8: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
L_8006B4CC:
    // 0x8006B4CC: nop

    // 0x8006B4D0: bne         $t7, $v0, L_8006B4E4
    if (ctx->r15 != ctx->r2) {
        // 0x8006B4D4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006B4E4;
    }
    // 0x8006B4D4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B4D8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8006B4DC: b           L_8006B4E8
    // 0x8006B4E0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
        goto L_8006B4E8;
    // 0x8006B4E0: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
L_8006B4E4:
    // 0x8006B4E4: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
L_8006B4E8:
    // 0x8006B4E8: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4EC: nop

    // 0x8006B4F0: bne         $t9, $zero, L_8006B50C
    if (ctx->r25 != 0) {
        // 0x8006B4F4: lw          $t2, 0x64($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X64);
            goto L_8006B50C;
    }
    // 0x8006B4F4: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006B4F8: jal         0x8000318C
    // 0x8006B4FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_1;
    // 0x8006B4FC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8006B500: b           L_8006B530
    // 0x8006B504: nop

        goto L_8006B530;
    // 0x8006B504: nop

    // 0x8006B508: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
L_8006B50C:
    // 0x8006B50C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B510: bne         $t2, $at, L_8006B528
    if (ctx->r10 != ctx->r1) {
        // 0x8006B514: nop
    
            goto L_8006B528;
    }
    // 0x8006B514: nop

    // 0x8006B518: jal         0x8000318C
    // 0x8006B51C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_2;
    // 0x8006B51C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_2:
    // 0x8006B520: b           L_8006B530
    // 0x8006B524: nop

        goto L_8006B530;
    // 0x8006B524: nop

L_8006B528:
    // 0x8006B528: jal         0x8000318C
    // 0x8006B52C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_3;
    // 0x8006B52C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
L_8006B530:
    // 0x8006B530: jal         0x8006ECD0
    // 0x8006B534: nop

    get_settings(rdram, ctx);
        goto after_4;
    // 0x8006B534: nop

    after_4:
    // 0x8006B538: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x8006B53C: jal         0x80076EE4
    // 0x8006B540: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_5;
    // 0x8006B540: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_5:
    // 0x8006B544: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006B548: addiu       $t1, $t1, 0x16E0
    ctx->r9 = ADD32(ctx->r9, 0X16E0);
    // 0x8006B54C: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8006B550: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8006B554: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8006B558: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B55C: beq         $t0, $t3, L_8006B574
    if (ctx->r8 == ctx->r11) {
        // 0x8006B560: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8006B574;
    }
    // 0x8006B560: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8006B564:
    // 0x8006B564: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8006B568: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B56C: bne         $t0, $t4, L_8006B564
    if (ctx->r8 != ctx->r12) {
        // 0x8006B570: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006B564;
    }
    // 0x8006B570: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006B574:
    // 0x8006B574: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x8006B578: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006B57C: slt         $at, $t5, $v1
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8006B580: bne         $at, $zero, L_8006B58C
    if (ctx->r1 != 0) {
        // 0x8006B584: lui         $a1, 0xFFFF
        ctx->r5 = S32(0XFFFF << 16);
            goto L_8006B58C;
    }
    // 0x8006B584: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B588: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
L_8006B58C:
    // 0x8006B58C: lw          $v1, 0x60($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X60);
    // 0x8006B590: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B594: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8006B598: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x8006B59C: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B5A0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8006B5A4: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x8006B5A8: subu        $a0, $t7, $s0
    ctx->r4 = SUB32(ctx->r15, ctx->r16);
    // 0x8006B5AC: jal         0x80070EDC
    // 0x8006B5B0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x8006B5B0: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_6:
    // 0x8006B5B4: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8006B5B8: addiu       $s1, $s1, 0x16E8
    ctx->r17 = ADD32(ctx->r17, 0X16E8);
    // 0x8006B5BC: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B5C0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B5C4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B5C8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B5CC: jal         0x80077190
    // 0x8006B5D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x8006B5D0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x8006B5D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B5D8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B5DC: sb          $zero, -0x2760($at)
    MEM_B(-0X2760, ctx->r1) = 0;
    // 0x8006B5E0: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B5E4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8006B5E8: lb          $t2, 0x4C($t9)
    ctx->r10 = MEM_B(ctx->r25, 0X4C);
    // 0x8006B5EC: nop

    // 0x8006B5F0: bne         $t2, $zero, L_8006B600
    if (ctx->r10 != 0) {
        // 0x8006B5F4: nop
    
            goto L_8006B600;
    }
    // 0x8006B5F4: nop

    // 0x8006B5F8: jal         0x8006C524
    // 0x8006B5FC: nop

    level_properties_reset(rdram, ctx);
        goto after_8;
    // 0x8006B5FC: nop

    after_8:
L_8006B600:
    // 0x8006B600: jal         0x8006C530
    // 0x8006B604: nop

    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8006B604: nop

    after_9:
    // 0x8006B608: bne         $v0, $zero, L_8006B870
    if (ctx->r2 != 0) {
        // 0x8006B60C: lui         $t3, 0x800E
        ctx->r11 = S32(0X800E << 16);
            goto L_8006B870;
    }
    // 0x8006B60C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8006B610: lh          $t3, -0x2764($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X2764);
    // 0x8006B614: nop

    // 0x8006B618: bne         $t3, $zero, L_8006B874
    if (ctx->r11 != 0) {
        // 0x8006B61C: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B61C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B620: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B624: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B628: lb          $t4, 0x4C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B62C: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B630: bne         $t4, $at, L_8006B72C
    if (ctx->r12 != ctx->r1) {
        // 0x8006B634: nop
    
            goto L_8006B72C;
    }
    // 0x8006B634: nop

    // 0x8006B638: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8006B63C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8006B640: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B644: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8006B648: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x8006B64C: beq         $a0, $zero, L_8006B660
    if (ctx->r4 == 0) {
        // 0x8006B650: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006B660;
    }
    // 0x8006B650: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B654: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B658: bne         $a0, $at, L_8006B668
    if (ctx->r4 != ctx->r1) {
        // 0x8006B65C: andi        $v1, $s0, 0x1
        ctx->r3 = ctx->r16 & 0X1;
            goto L_8006B668;
    }
    // 0x8006B65C: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B660:
    // 0x8006B660: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B664: andi        $v1, $s0, 0x1
    ctx->r3 = ctx->r16 & 0X1;
L_8006B668:
    // 0x8006B668: beq         $v1, $zero, L_8006B67C
    if (ctx->r3 == 0) {
        // 0x8006B66C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_8006B67C;
    }
    // 0x8006B66C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B670: beq         $v0, $zero, L_8006B72C
    if (ctx->r2 == 0) {
        // 0x8006B674: nop
    
            goto L_8006B72C;
    }
    // 0x8006B674: nop

    // 0x8006B678: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_8006B67C:
    // 0x8006B67C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B680: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B684: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B688: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x8006B68C: jal         0x8006C3EC
    // 0x8006B690: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    level_properties_push(rdram, ctx);
        goto after_10;
    // 0x8006B690: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_10:
    // 0x8006B694: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006B698: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006B69C: lbu         $t2, 0x48($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X48);
    // 0x8006B6A0: lhu         $t9, 0xC($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0XC);
    // 0x8006B6A4: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x8006B6A8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B6AC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B6B0: and         $t5, $t9, $t4
    ctx->r13 = ctx->r25 & ctx->r12;
    // 0x8006B6B4: beq         $t5, $zero, L_8006B6C8
    if (ctx->r13 == 0) {
        // 0x8006B6B8: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_8006B6C8;
    }
    // 0x8006B6B8: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8006B6BC: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x8006B6C0: b           L_8006B6CC
    // 0x8006B6C4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
        goto L_8006B6CC;
    // 0x8006B6C4: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006B6C8:
    // 0x8006B6C8: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006B6CC:
    // 0x8006B6CC: beq         $v0, $zero, L_8006B6E8
    if (ctx->r2 == 0) {
        // 0x8006B6D0: nop
    
            goto L_8006B6E8;
    }
    // 0x8006B6D0: nop

    // 0x8006B6D4: beq         $v1, $zero, L_8006B6E8
    if (ctx->r3 == 0) {
        // 0x8006B6D8: sw          $zero, 0x70($sp)
        MEM_W(0X70, ctx->r29) = 0;
            goto L_8006B6E8;
    }
    // 0x8006B6D8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B6DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8006B6E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B6E4: sb          $t8, -0x2760($at)
    MEM_B(-0X2760, ctx->r1) = ctx->r24;
L_8006B6E8:
    // 0x8006B6E8: jal         0x8001E2D0
    // 0x8006B6EC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    get_misc_asset(rdram, ctx);
        goto after_11;
    // 0x8006B6EC: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_11:
    // 0x8006B6F0: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8006B6F4: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8006B6F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8006B6FC: beq         $a1, $t3, L_8006B718
    if (ctx->r5 == ctx->r11) {
        // 0x8006B700: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006B718;
    }
    // 0x8006B700: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006B704: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_8006B708:
    // 0x8006B708: lb          $t2, 0x2($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X2);
    // 0x8006B70C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8006B710: bne         $a1, $t2, L_8006B708
    if (ctx->r5 != ctx->r10) {
        // 0x8006B714: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8006B708;
    }
    // 0x8006B714: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8006B718:
    // 0x8006B718: addu        $t9, $s0, $v0
    ctx->r25 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B71C: lb          $t4, 0x1($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X1);
    // 0x8006B720: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8006B724: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B728: sw          $t5, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r13;
L_8006B72C:
    // 0x8006B72C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B730: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B734: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B738: nop

    // 0x8006B73C: bne         $a1, $at, L_8006B7F0
    if (ctx->r5 != ctx->r1) {
        // 0x8006B740: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B740: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B744: lb          $a0, 0x0($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X0);
    // 0x8006B748: nop

    // 0x8006B74C: blez        $a0, L_8006B7EC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B750: slti        $at, $a0, 0x5
        ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
            goto L_8006B7EC;
    }
    // 0x8006B750: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8006B754: beq         $at, $zero, L_8006B7F0
    if (ctx->r1 == 0) {
        // 0x8006B758: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B758: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B75C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x8006B760: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006B764: lhu         $t7, 0x8($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X8);
    // 0x8006B768: sllv        $t3, $t8, $a0
    ctx->r11 = S32(ctx->r24 << (ctx->r4 & 31));
    // 0x8006B76C: and         $t2, $t7, $t3
    ctx->r10 = ctx->r15 & ctx->r11;
    // 0x8006B770: beq         $t2, $zero, L_8006B7EC
    if (ctx->r10 == 0) {
        // 0x8006B774: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_8006B7EC;
    }
    // 0x8006B774: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8006B778: lw          $t5, 0x10($t6)
    ctx->r13 = MEM_W(ctx->r14, 0X10);
    // 0x8006B77C: addiu       $t9, $a0, 0x1F
    ctx->r25 = ADD32(ctx->r4, 0X1F);
    // 0x8006B780: addiu       $t4, $zero, 0x4000
    ctx->r12 = ADD32(0, 0X4000);
    // 0x8006B784: sllv        $v0, $t4, $t9
    ctx->r2 = S32(ctx->r12 << (ctx->r25 & 31));
    // 0x8006B788: and         $t8, $t5, $v0
    ctx->r24 = ctx->r13 & ctx->r2;
    // 0x8006B78C: bne         $t8, $zero, L_8006B7F0
    if (ctx->r24 != 0) {
        // 0x8006B790: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8006B7F0;
    }
    // 0x8006B790: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006B794: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B798: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B79C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B7A0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B7A4: jal         0x8006C3EC
    // 0x8006B7A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8006B7A8: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    after_12:
    // 0x8006B7AC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006B7B0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8006B7B4: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x8006B7B8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B7BC: or          $t3, $t7, $v0
    ctx->r11 = ctx->r15 | ctx->r2;
    // 0x8006B7C0: jal         0x8001E2D0
    // 0x8006B7C4: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    get_misc_asset(rdram, ctx);
        goto after_13;
    // 0x8006B7C4: sw          $t3, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r11;
    after_13:
    // 0x8006B7C8: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x8006B7CC: lb          $t4, -0x1($t2)
    ctx->r12 = MEM_B(ctx->r10, -0X1);
    // 0x8006B7D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B7D4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006B7D8: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x8006B7DC: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
    // 0x8006B7E0: sw          $t4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r12;
    // 0x8006B7E4: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B7E8: nop

L_8006B7EC:
    // 0x8006B7EC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_8006B7F0:
    // 0x8006B7F0: bne         $a1, $at, L_8006B874
    if (ctx->r5 != ctx->r1) {
        // 0x8006B7F4: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B7F4: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B7F8: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8006B7FC: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x8006B800: bne         $t6, $zero, L_8006B874
    if (ctx->r14 != 0) {
        // 0x8006B804: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B804: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B808: lw          $t8, 0x10($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X10);
    // 0x8006B80C: nop

    // 0x8006B810: andi        $t7, $t8, 0x2000
    ctx->r15 = ctx->r24 & 0X2000;
    // 0x8006B814: bne         $t7, $zero, L_8006B874
    if (ctx->r15 != 0) {
        // 0x8006B818: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B818: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B81C: lbu         $t3, 0x17($t5)
    ctx->r11 = MEM_BU(ctx->r13, 0X17);
    // 0x8006B820: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8006B824: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x8006B828: bne         $at, $zero, L_8006B874
    if (ctx->r1 != 0) {
        // 0x8006B82C: lw          $t6, 0x44($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X44);
            goto L_8006B874;
    }
    // 0x8006B82C: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x8006B830: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8006B834: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8006B838: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8006B83C: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8006B840: jal         0x8006C3EC
    // 0x8006B844: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8006B844: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    after_14:
    // 0x8006B848: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006B84C: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x8006B850: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x8006B854: nop

    // 0x8006B858: ori         $t4, $t2, 0x2000
    ctx->r12 = ctx->r10 | 0X2000;
    // 0x8006B85C: jal         0x8001E2D0
    // 0x8006B860: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    get_misc_asset(rdram, ctx);
        goto after_15;
    // 0x8006B860: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    after_15:
    // 0x8006B864: lb          $t9, 0x4($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X4);
    // 0x8006B868: nop

    // 0x8006B86C: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
L_8006B870:
    // 0x8006B870: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
L_8006B874:
    // 0x8006B874: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006B878: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006B87C: beq         $t6, $t8, L_8006B8D8
    if (ctx->r14 == ctx->r24) {
        // 0x8006B880: sh          $zero, -0x2764($at)
        MEM_H(-0X2764, ctx->r1) = 0;
            goto L_8006B8D8;
    }
    // 0x8006B880: sh          $zero, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = 0;
    // 0x8006B884: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B888: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006B88C: jal         0x80071380
    // 0x8006B890: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8006B890: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_16:
    // 0x8006B894: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8006B898: lw          $t5, 0x16E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X16E0);
    // 0x8006B89C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x8006B8A0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006B8A4: addu        $v0, $t5, $t3
    ctx->r2 = ADD32(ctx->r13, ctx->r11);
    // 0x8006B8A8: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8006B8AC: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8006B8B0: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006B8B4: subu        $a0, $t2, $s0
    ctx->r4 = SUB32(ctx->r10, ctx->r16);
    // 0x8006B8B8: jal         0x80070EDC
    // 0x8006B8BC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_17;
    // 0x8006B8BC: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    after_17:
    // 0x8006B8C0: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8006B8C4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8006B8C8: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006B8CC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006B8D0: jal         0x80077190
    // 0x8006B8D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_18;
    // 0x8006B8D4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_18:
L_8006B8D8:
    // 0x8006B8D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006B8DC: lw          $a0, 0x16E0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X16E0);
    // 0x8006B8E0: jal         0x80071380
    // 0x8006B8E4: nop

    mempool_free(rdram, ctx);
        goto after_19;
    // 0x8006B8E4: nop

    after_19:
    // 0x8006B8E8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8006B8EC: jal         0x8006C208
    // 0x8006B8F0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    aitable_init(rdram, ctx);
        goto after_20;
    // 0x8006B8F0: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_20:
    // 0x8006B8F4: jal         0x8000CBC0
    // 0x8006B8F8: nop

    func_8000CBC0(rdram, ctx);
        goto after_21;
    // 0x8006B8F8: nop

    after_21:
    // 0x8006B8FC: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8006B900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006B904: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006B908: sw          $t4, 0x16E4($at)
    MEM_W(0X16E4, ctx->r1) = ctx->r12;
L_8006B90C:
    // 0x8006B90C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006B910: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006B914: addu        $t6, $t9, $v1
    ctx->r14 = ADD32(ctx->r25, ctx->r3);
    // 0x8006B918: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8006B91C: nop

    // 0x8006B920: beq         $a0, $at, L_8006B964
    if (ctx->r4 == ctx->r1) {
        // 0x8006B924: nop
    
            goto L_8006B964;
    }
    // 0x8006B924: nop

    // 0x8006B928: jal         0x8001E2D0
    // 0x8006B92C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_22;
    // 0x8006B92C: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_22:
    // 0x8006B930: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B934: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006B938: nop

    // 0x8006B93C: addu        $t7, $t8, $v1
    ctx->r15 = ADD32(ctx->r24, ctx->r3);
    // 0x8006B940: sw          $v0, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->r2;
    // 0x8006B944: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006B948: nop

    // 0x8006B94C: addu        $t3, $t5, $v1
    ctx->r11 = ADD32(ctx->r13, ctx->r3);
    // 0x8006B950: lw          $a0, 0x74($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X74);
    // 0x8006B954: jal         0x8007F638
    // 0x8006B958: nop

    func_8007F1E8(rdram, ctx);
        goto after_23;
    // 0x8006B958: nop

    after_23:
    // 0x8006B95C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x8006B960: nop

L_8006B964:
    // 0x8006B964: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006B968: slti        $at, $v1, 0x1C
    ctx->r1 = SIGNED(ctx->r3) < 0X1C ? 1 : 0;
    // 0x8006B96C: bne         $at, $zero, L_8006B90C
    if (ctx->r1 != 0) {
        // 0x8006B970: nop
    
            goto L_8006B90C;
    }
    // 0x8006B970: nop

    // 0x8006B974: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8006B978: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8006B97C: bne         $t2, $at, L_8006B9E4
    if (ctx->r10 != ctx->r1) {
        // 0x8006B980: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B980: nop

    // 0x8006B984: jal         0x80099B68
    // 0x8006B988: nop

    get_trophy_race_world_id(rdram, ctx);
        goto after_24;
    // 0x8006B988: nop

    after_24:
    // 0x8006B98C: beq         $v0, $zero, L_8006B9B4
    if (ctx->r2 == 0) {
        // 0x8006B990: nop
    
            goto L_8006B9B4;
    }
    // 0x8006B990: nop

    // 0x8006B994: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006B998: nop

    // 0x8006B99C: lb          $t9, 0x4C($t4)
    ctx->r25 = MEM_B(ctx->r12, 0X4C);
    // 0x8006B9A0: nop

    // 0x8006B9A4: bne         $t9, $zero, L_8006B9E4
    if (ctx->r25 != 0) {
        // 0x8006B9A8: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9A8: nop

    // 0x8006B9AC: b           L_8006B9E4
    // 0x8006B9B0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
        goto L_8006B9E4;
    // 0x8006B9B0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B9B4:
    // 0x8006B9B4: jal         0x8009C814
    // 0x8006B9B8: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_25;
    // 0x8006B9B8: nop

    after_25:
    // 0x8006B9BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006B9C0: bne         $v0, $at, L_8006B9E4
    if (ctx->r2 != ctx->r1) {
        // 0x8006B9C4: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9C4: nop

    // 0x8006B9C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006B9CC: nop

    // 0x8006B9D0: lb          $t8, 0x4C($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4C);
    // 0x8006B9D4: nop

    // 0x8006B9D8: bne         $t8, $zero, L_8006B9E4
    if (ctx->r24 != 0) {
        // 0x8006B9DC: nop
    
            goto L_8006B9E4;
    }
    // 0x8006B9DC: nop

    // 0x8006B9E0: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
L_8006B9E4:
    // 0x8006B9E4: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006B9E8: nop

    // 0x8006B9EC: lb          $a1, 0x4C($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X4C);
    // 0x8006B9F0: nop

    // 0x8006B9F4: beq         $a1, $zero, L_8006BA00
    if (ctx->r5 == 0) {
        // 0x8006B9F8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8006BA00;
    }
    // 0x8006B9F8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8006B9FC: bne         $a1, $at, L_8006BA10
    if (ctx->r5 != ctx->r1) {
        // 0x8006BA00: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8006BA10;
    }
L_8006BA00:
    // 0x8006BA00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006BA04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA08: b           L_8006BA18
    // 0x8006BA0C: sw          $t7, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = ctx->r15;
        goto L_8006BA18;
    // 0x8006BA0C: sw          $t7, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = ctx->r15;
L_8006BA10:
    // 0x8006BA10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BA14: sw          $zero, -0x2774($at)
    MEM_W(-0X2774, ctx->r1) = 0;
L_8006BA18:
    // 0x8006BA18: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8006BA1C: nop

    // 0x8006BA20: beq         $t5, $zero, L_8006BA44
    if (ctx->r13 == 0) {
        // 0x8006BA24: nop
    
            goto L_8006BA44;
    }
    // 0x8006BA24: nop

    // 0x8006BA28: lb          $t3, 0x4C($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X4C);
    // 0x8006BA2C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8006BA30: beq         $t3, $at, L_8006BA44
    if (ctx->r11 == ctx->r1) {
        // 0x8006BA34: addiu       $t2, $zero, 0x6
        ctx->r10 = ADD32(0, 0X6);
            goto L_8006BA44;
    }
    // 0x8006BA34: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x8006BA38: sb          $t2, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = ctx->r10;
    // 0x8006BA3C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA40: nop

L_8006BA44:
    // 0x8006BA44: lbu         $a0, 0xB3($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB3);
    // 0x8006BA48: jal         0x80000BE0
    // 0x8006BA4C: nop

    music_voicelimit_set(rdram, ctx);
        goto after_26;
    // 0x8006BA4C: nop

    after_26:
    // 0x8006BA50: jal         0x80000CBC
    // 0x8006BA54: nop

    music_volume_reset(rdram, ctx);
        goto after_27;
    // 0x8006BA54: nop

    after_27:
    // 0x8006BA58: jal         0x80031BF8
    // 0x8006BA5C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    lights_init(rdram, ctx);
        goto after_28;
    // 0x8006BA5C: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_28:
    // 0x8006BA60: lw          $t4, 0x6C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BA64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BA68: bltz        $t4, L_8006BA8C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8006BA6C: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_8006BA8C;
    }
    // 0x8006BA6C: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x8006BA70: beq         $at, $zero, L_8006BA8C
    if (ctx->r1 == 0) {
        // 0x8006BA74: nop
    
            goto L_8006BA8C;
    }
    // 0x8006BA74: nop

    // 0x8006BA78: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA7C: nop

    // 0x8006BA80: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x8006BA84: lb          $s0, 0x4F($t6)
    ctx->r16 = MEM_B(ctx->r14, 0X4F);
    // 0x8006BA88: nop

L_8006BA8C:
    // 0x8006BA8C: jal         0x80017EA8
    // 0x8006BA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    set_taj_challenge_type(rdram, ctx);
        goto after_29;
    // 0x8006BA90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_29:
    // 0x8006BA94: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006BA98: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006BA9C: lb          $a0, 0x0($t8)
    ctx->r4 = MEM_B(ctx->r24, 0X0);
    // 0x8006BAA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BAA4: lbu         $s0, 0x48($v1)
    ctx->r16 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAA8: beq         $a0, $at, L_8006BAB8
    if (ctx->r4 == ctx->r1) {
        // 0x8006BAAC: lw          $t7, 0x60($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X60);
            goto L_8006BAB8;
    }
    // 0x8006BAAC: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x8006BAB0: sb          $a0, 0x48($v1)
    MEM_B(0X48, ctx->r3) = ctx->r4;
    // 0x8006BAB4: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
L_8006BAB8:
    // 0x8006BAB8: bne         $s0, $zero, L_8006BAE4
    if (ctx->r16 != 0) {
        // 0x8006BABC: sb          $t7, 0x49($v1)
        MEM_B(0X49, ctx->r3) = ctx->r15;
            goto L_8006BAE4;
    }
    // 0x8006BABC: sb          $t7, 0x49($v1)
    MEM_B(0X49, ctx->r3) = ctx->r15;
    // 0x8006BAC0: lbu         $t5, 0x48($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAC4: nop

    // 0x8006BAC8: blez        $t5, L_8006BAE4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8006BACC: nop
    
            goto L_8006BAE4;
    }
    // 0x8006BACC: nop

    // 0x8006BAD0: jal         0x8006DD6C
    // 0x8006BAD4: nop

    get_level_default_vehicle(rdram, ctx);
        goto after_30;
    // 0x8006BAD4: nop

    after_30:
    // 0x8006BAD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BADC: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8006BAE0: sb          $v0, -0x277C($at)
    MEM_B(-0X277C, ctx->r1) = ctx->r2;
L_8006BAE4:
    // 0x8006BAE4: lbu         $t3, 0x48($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X48);
    // 0x8006BAE8: nop

    // 0x8006BAEC: bne         $t3, $zero, L_8006BB14
    if (ctx->r11 != 0) {
        // 0x8006BAF0: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006BB14;
    }
    // 0x8006BAF0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BAF4: blez        $s0, L_8006BB10
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8006BAF8: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8006BB10;
    }
    // 0x8006BAF8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006BAFC: lb          $v0, -0x277C($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X277C);
    // 0x8006BB00: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BB04: beq         $v0, $at, L_8006BB14
    if (ctx->r2 == ctx->r1) {
        // 0x8006BB08: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_8006BB14;
    }
    // 0x8006BB08: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BB0C: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
L_8006BB10:
    // 0x8006BB10: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
L_8006BB14:
    // 0x8006BB14: jal         0x8006DD60
    // 0x8006BB18: nop

    set_vehicle_id_for_menu(rdram, ctx);
        goto after_31;
    // 0x8006BB18: nop

    after_31:
    // 0x8006BB1C: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006BB20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006BB24: lb          $t9, 0x4C($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4C);
    // 0x8006BB28: nop

    // 0x8006BB2C: bne         $t9, $at, L_8006BC20
    if (ctx->r25 != ctx->r1) {
        // 0x8006BB30: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB30: nop

    // 0x8006BB34: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8006BB38: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8006BB3C: lbu         $a0, 0x48($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X48);
    // 0x8006BB40: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8006BB44: blez        $a0, L_8006BC20
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006BB48: addiu       $t4, $a0, 0x1F
        ctx->r12 = ADD32(ctx->r4, 0X1F);
            goto L_8006BC20;
    }
    // 0x8006BB48: addiu       $t4, $a0, 0x1F
    ctx->r12 = ADD32(ctx->r4, 0X1F);
    // 0x8006BB4C: bne         $a0, $at, L_8006BBA4
    if (ctx->r4 != ctx->r1) {
        // 0x8006BB50: sllv        $s0, $t6, $t4
        ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
            goto L_8006BBA4;
    }
    // 0x8006BB50: sllv        $s0, $t6, $t4
    ctx->r16 = S32(ctx->r14 << (ctx->r12 & 31));
    // 0x8006BB54: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8006BB58: nop

    // 0x8006BB5C: lh          $t7, 0x0($t8)
    ctx->r15 = MEM_H(ctx->r24, 0X0);
    // 0x8006BB60: nop

    // 0x8006BB64: slti        $at, $t7, 0x2F
    ctx->r1 = SIGNED(ctx->r15) < 0X2F ? 1 : 0;
    // 0x8006BB68: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BB6C: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB6C: nop

    // 0x8006BB70: lbu         $t5, 0x16($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X16);
    // 0x8006BB74: nop

    // 0x8006BB78: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x8006BB7C: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BB80: nop
    
            goto L_8006BC20;
    }
    // 0x8006BB80: nop

    // 0x8006BB84: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BB88: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8006BB8C: and         $t3, $v0, $s0
    ctx->r11 = ctx->r2 & ctx->r16;
    // 0x8006BB90: bne         $t3, $zero, L_8006BC20
    if (ctx->r11 != 0) {
        // 0x8006BB94: or          $t2, $v0, $s0
        ctx->r10 = ctx->r2 | ctx->r16;
            goto L_8006BC20;
    }
    // 0x8006BB94: or          $t2, $v0, $s0
    ctx->r10 = ctx->r2 | ctx->r16;
    // 0x8006BB98: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x8006BB9C: b           L_8006BC20
    // 0x8006BBA0: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
        goto L_8006BC20;
    // 0x8006BBA0: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006BBA4:
    // 0x8006BBA4: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8006BBA8: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8006BBAC: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x8006BBB0: lh          $v1, 0x0($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X0);
    // 0x8006BBB4: nop

    // 0x8006BBB8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8006BBBC: bne         $at, $zero, L_8006BBFC
    if (ctx->r1 != 0) {
        // 0x8006BBC0: slti        $at, $v1, 0x8
        ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
            goto L_8006BBFC;
    }
    // 0x8006BBC0: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8006BBC4: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BBC8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006BBCC: and         $t7, $v0, $s0
    ctx->r15 = ctx->r2 & ctx->r16;
    // 0x8006BBD0: bne         $t7, $zero, L_8006BBF8
    if (ctx->r15 != 0) {
        // 0x8006BBD4: or          $t5, $v0, $s0
        ctx->r13 = ctx->r2 | ctx->r16;
            goto L_8006BBF8;
    }
    // 0x8006BBD4: or          $t5, $v0, $s0
    ctx->r13 = ctx->r2 | ctx->r16;
    // 0x8006BBD8: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006BBDC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x8006BBE0: lbu         $t9, 0x48($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X48);
    // 0x8006BBE4: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8006BBE8: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8006BBEC: addu        $t4, $t2, $t6
    ctx->r12 = ADD32(ctx->r10, ctx->r14);
    // 0x8006BBF0: lh          $v1, 0x0($t4)
    ctx->r3 = MEM_H(ctx->r12, 0X0);
    // 0x8006BBF4: nop

L_8006BBF8:
    // 0x8006BBF8: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
L_8006BBFC:
    // 0x8006BBFC: bne         $at, $zero, L_8006BC20
    if (ctx->r1 != 0) {
        // 0x8006BC00: sll         $t8, $s0, 5
        ctx->r24 = S32(ctx->r16 << 5);
            goto L_8006BC20;
    }
    // 0x8006BC00: sll         $t8, $s0, 5
    ctx->r24 = S32(ctx->r16 << 5);
    // 0x8006BC04: lw          $v0, 0x10($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X10);
    // 0x8006BC08: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8006BC0C: and         $t7, $v0, $t8
    ctx->r15 = ctx->r2 & ctx->r24;
    // 0x8006BC10: bne         $t7, $zero, L_8006BC20
    if (ctx->r15 != 0) {
        // 0x8006BC14: or          $t5, $v0, $t8
        ctx->r13 = ctx->r2 | ctx->r24;
            goto L_8006BC20;
    }
    // 0x8006BC14: or          $t5, $v0, $t8
    ctx->r13 = ctx->r2 | ctx->r24;
    // 0x8006BC18: sw          $t5, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r13;
    // 0x8006BC1C: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
L_8006BC20:
    // 0x8006BC20: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC24: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8006BC28: lb          $a1, 0x4C($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X4C);
    // 0x8006BC2C: beq         $t2, $zero, L_8006BC40
    if (ctx->r10 == 0) {
        // 0x8006BC30: nop
    
            goto L_8006BC40;
    }
    // 0x8006BC30: nop

    // 0x8006BC34: bne         $a1, $zero, L_8006BC40
    if (ctx->r5 != 0) {
        // 0x8006BC38: addiu       $t6, $zero, 0x64
        ctx->r14 = ADD32(0, 0X64);
            goto L_8006BC40;
    }
    // 0x8006BC38: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8006BC3C: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
L_8006BC40:
    // 0x8006BC40: beq         $a1, $zero, L_8006BC50
    if (ctx->r5 == 0) {
        // 0x8006BC44: andi        $t4, $a1, 0x40
        ctx->r12 = ctx->r5 & 0X40;
            goto L_8006BC50;
    }
    // 0x8006BC44: andi        $t4, $a1, 0x40
    ctx->r12 = ctx->r5 & 0X40;
    // 0x8006BC48: beq         $t4, $zero, L_8006BC78
    if (ctx->r12 == 0) {
        // 0x8006BC4C: nop
    
            goto L_8006BC78;
    }
    // 0x8006BC4C: nop

L_8006BC50:
    // 0x8006BC50: jal         0x8009F1C4
    // 0x8006BC54: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_32;
    // 0x8006BC54: nop

    after_32:
    // 0x8006BC58: beq         $v0, $zero, L_8006BC78
    if (ctx->r2 == 0) {
        // 0x8006BC5C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8006BC78;
    }
    // 0x8006BC5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8006BC60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BC64: sb          $t8, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = ctx->r24;
    // 0x8006BC68: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC6C: addiu       $t7, $zero, 0x64
    ctx->r15 = ADD32(0, 0X64);
    // 0x8006BC70: b           L_8006BC88
    // 0x8006BC74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
        goto L_8006BC88;
    // 0x8006BC74: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
L_8006BC78:
    // 0x8006BC78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006BC7C: sb          $zero, -0x2778($at)
    MEM_B(-0X2778, ctx->r1) = 0;
    // 0x8006BC80: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BC84: nop

L_8006BC88:
    // 0x8006BC88: lb          $t5, 0x4C($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X4C);
    // 0x8006BC8C: nop

    // 0x8006BC90: bne         $t5, $zero, L_8006BCC0
    if (ctx->r13 != 0) {
        // 0x8006BC94: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BCC0;
    }
    // 0x8006BC94: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BC98: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8006BC9C: nop

    // 0x8006BCA0: bne         $t3, $zero, L_8006BCC0
    if (ctx->r11 != 0) {
        // 0x8006BCA4: lw          $a0, 0x70($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X70);
            goto L_8006BCC0;
    }
    // 0x8006BCA4: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x8006BCA8: jal         0x8000E4C8
    // 0x8006BCAC: nop

    is_time_trial_enabled(rdram, ctx);
        goto after_33;
    // 0x8006BCAC: nop

    after_33:
    // 0x8006BCB0: beq         $v0, $zero, L_8006BCBC
    if (ctx->r2 == 0) {
        // 0x8006BCB4: addiu       $t9, $zero, 0x64
        ctx->r25 = ADD32(0, 0X64);
            goto L_8006BCBC;
    }
    // 0x8006BCB4: addiu       $t9, $zero, 0x64
    ctx->r25 = ADD32(0, 0X64);
    // 0x8006BCB8: sw          $t9, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r25;
L_8006BCBC:
    // 0x8006BCBC: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_8006BCC0:
    // 0x8006BCC0: jal         0x8001E484
    // 0x8006BCC4: nop

    cutscene_id_set(rdram, ctx);
        goto after_34;
    // 0x8006BCC4: nop

    after_34:
    // 0x8006BCC8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCCC: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8006BCD0: lh          $a0, 0x34($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X34);
    // 0x8006BCD4: lh          $a1, 0x38($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X38);
    // 0x8006BCD8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BCDC: lh          $t6, 0x36($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X36);
    // 0x8006BCE0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8006BCE4: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BCE8: lh          $t4, 0xBA($v1)
    ctx->r12 = MEM_H(ctx->r3, 0XBA);
    // 0x8006BCEC: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8006BCF0: jal         0x80024A30
    // 0x8006BCF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    init_track(rdram, ctx);
        goto after_35;
    // 0x8006BCF4: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    after_35:
    // 0x8006BCF8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BCFC: nop

    // 0x8006BD00: lh          $t8, 0x3A($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BD04: nop

    // 0x8006BD08: bne         $t8, $zero, L_8006BD74
    if (ctx->r24 != 0) {
        // 0x8006BD0C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD0C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD10: lh          $t7, 0x3C($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BD14: nop

    // 0x8006BD18: bne         $t7, $zero, L_8006BD74
    if (ctx->r15 != 0) {
        // 0x8006BD1C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD1C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD20: lh          $t5, 0x3E($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X3E);
    // 0x8006BD24: nop

    // 0x8006BD28: bne         $t5, $zero, L_8006BD74
    if (ctx->r13 != 0) {
        // 0x8006BD2C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD30: lh          $t3, 0x40($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X40);
    // 0x8006BD34: nop

    // 0x8006BD38: bne         $t3, $zero, L_8006BD74
    if (ctx->r11 != 0) {
        // 0x8006BD3C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8006BD74;
    }
    // 0x8006BD3C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD40: lh          $t9, 0x42($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X42);
    // 0x8006BD44: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006BD48: bne         $t9, $zero, L_8006BD70
    if (ctx->r25 != 0) {
        // 0x8006BD4C: nop
    
            goto L_8006BD70;
    }
    // 0x8006BD4C: nop

L_8006BD50:
    // 0x8006BD50: jal         0x800307FC
    // 0x8006BD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    reset_fog(rdram, ctx);
        goto after_36;
    // 0x8006BD54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_36:
    // 0x8006BD58: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BD5C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BD60: bne         $s0, $at, L_8006BD50
    if (ctx->r16 != ctx->r1) {
        // 0x8006BD64: nop
    
            goto L_8006BD50;
    }
    // 0x8006BD64: nop

    // 0x8006BD68: b           L_8006BDAC
    // 0x8006BD6C: nop

        goto L_8006BDAC;
    // 0x8006BD6C: nop

L_8006BD70:
    // 0x8006BD70: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006BD74:
    // 0x8006BD74: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BD78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8006BD7C: lh          $t2, 0x40($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X40);
    // 0x8006BD80: lh          $a1, 0x3A($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X3A);
    // 0x8006BD84: lh          $a2, 0x3C($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X3C);
    // 0x8006BD88: lbu         $a3, 0x3F($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X3F);
    // 0x8006BD8C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006BD90: lh          $t6, 0x42($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X42);
    // 0x8006BD94: jal         0x800306A4
    // 0x8006BD98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    set_fog(rdram, ctx);
        goto after_37;
    // 0x8006BD98: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_37:
    // 0x8006BD9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8006BDA0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006BDA4: bne         $s0, $at, L_8006BD74
    if (ctx->r16 != ctx->r1) {
        // 0x8006BDA8: nop
    
            goto L_8006BD74;
    }
    // 0x8006BDA8: nop

L_8006BDAC:
    // 0x8006BDAC: jal         0x8006ECD0
    // 0x8006BDB0: nop

    get_settings(rdram, ctx);
        goto after_38;
    // 0x8006BDB0: nop

    after_38:
    // 0x8006BDB4: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8006BDB8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BDBC: lb          $a0, 0x0($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X0);
    // 0x8006BDC0: nop

    // 0x8006BDC4: beq         $a0, $at, L_8006BDD4
    if (ctx->r4 == ctx->r1) {
        // 0x8006BDC8: lw          $t8, 0x60($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X60);
            goto L_8006BDD4;
    }
    // 0x8006BDC8: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8006BDCC: sb          $a0, 0x48($v0)
    MEM_B(0X48, ctx->r2) = ctx->r4;
    // 0x8006BDD0: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
L_8006BDD4:
    // 0x8006BDD4: nop

    // 0x8006BDD8: sb          $t8, 0x49($v0)
    MEM_B(0X49, ctx->r2) = ctx->r24;
    // 0x8006BDDC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BDE0: nop

    // 0x8006BDE4: lh          $a1, 0x90($v1)
    ctx->r5 = MEM_H(ctx->r3, 0X90);
    // 0x8006BDE8: nop

    // 0x8006BDEC: blez        $a1, L_8006BE60
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8006BDF0: nop
    
            goto L_8006BE60;
    }
    // 0x8006BDF0: nop

    // 0x8006BDF4: lh          $t3, 0x9A($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X9A);
    // 0x8006BDF8: lh          $a2, 0x96($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X96);
    // 0x8006BDFC: lh          $a3, 0x98($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X98);
    // 0x8006BE00: lh          $a0, 0x92($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X92);
    // 0x8006BE04: sll         $t9, $t3, 8
    ctx->r25 = S32(ctx->r11 << 8);
    // 0x8006BE08: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8006BE0C: lbu         $t2, 0x94($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X94);
    // 0x8006BE10: addiu       $v0, $zero, 0x101
    ctx->r2 = ADD32(0, 0X101);
    // 0x8006BE14: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BE18: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8006BE1C: sll         $t5, $a3, 8
    ctx->r13 = S32(ctx->r7 << 8);
    // 0x8006BE20: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8006BE24: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8006BE28: mflo        $t6
    ctx->r14 = lo;
    // 0x8006BE2C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8006BE30: lbu         $t4, 0x95($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X95);
    // 0x8006BE34: nop

    // 0x8006BE38: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006BE3C: mflo        $t8
    ctx->r24 = lo;
    // 0x8006BE40: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8006BE44: jal         0x800ABA08
    // 0x8006BE48: nop

    weather_reset(rdram, ctx);
        goto after_39;
    // 0x8006BE48: nop

    after_39:
    // 0x8006BE4C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8006BE50: jal         0x800AB868
    // 0x8006BE54: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    weather_clip_planes(rdram, ctx);
        goto after_40;
    // 0x8006BE54: addiu       $a1, $zero, -0x200
    ctx->r5 = ADD32(0, -0X200);
    after_40:
    // 0x8006BE58: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE5C: nop

L_8006BE60:
    // 0x8006BE60: lb          $t7, 0x49($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X49);
    // 0x8006BE64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BE68: bne         $t7, $at, L_8006BEA8
    if (ctx->r15 != ctx->r1) {
        // 0x8006BE6C: nop
    
            goto L_8006BEA8;
    }
    // 0x8006BE6C: nop

    // 0x8006BE70: lw          $a0, 0xA4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XA4);
    // 0x8006BE74: jal         0x8007B2C4
    // 0x8006BE78: nop

    load_texture(rdram, ctx);
        goto after_41;
    // 0x8006BE78: nop

    after_41:
    // 0x8006BE7C: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE80: nop

    // 0x8006BE84: sw          $v0, 0xA4($t5)
    MEM_W(0XA4, ctx->r13) = ctx->r2;
    // 0x8006BE88: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE8C: nop

    // 0x8006BE90: sh          $zero, 0xA8($t3)
    MEM_H(0XA8, ctx->r11) = 0;
    // 0x8006BE94: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8006BE98: nop

    // 0x8006BE9C: sh          $zero, 0xAA($t9)
    MEM_H(0XAA, ctx->r25) = 0;
    // 0x8006BEA0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEA4: nop

L_8006BEA8:
    // 0x8006BEA8: lw          $a0, 0xAC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XAC);
    // 0x8006BEAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006BEB0: beq         $a0, $at, L_8006BEE8
    if (ctx->r4 == ctx->r1) {
        // 0x8006BEB4: nop
    
            goto L_8006BEE8;
    }
    // 0x8006BEB4: nop

    // 0x8006BEB8: jal         0x8001E2D0
    // 0x8006BEBC: nop

    get_misc_asset(rdram, ctx);
        goto after_42;
    // 0x8006BEBC: nop

    after_42:
    // 0x8006BEC0: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEC4: nop

    // 0x8006BEC8: sw          $v0, 0xAC($t2)
    MEM_W(0XAC, ctx->r10) = ctx->r2;
    // 0x8006BECC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8006BED0: nop

    // 0x8006BED4: lw          $a0, 0xAC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XAC);
    // 0x8006BED8: jal         0x8007F864
    // 0x8006BEDC: nop

    init_pulsating_light_data(rdram, ctx);
        goto after_43;
    // 0x8006BEDC: nop

    after_43:
    // 0x8006BEE0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BEE4: nop

L_8006BEE8:
    // 0x8006BEE8: lb          $t4, 0x9C($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X9C);
    // 0x8006BEEC: nop

    // 0x8006BEF0: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8006BEF4: jal         0x8006632C
    // 0x8006BEF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    cam_set_fov(rdram, ctx);
        goto after_44;
    // 0x8006BEF8: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_44:
    // 0x8006BEFC: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8006BF00: nop

    // 0x8006BF04: lbu         $a0, 0x9D($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X9D);
    // 0x8006BF08: lbu         $a1, 0x9E($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X9E);
    // 0x8006BF0C: lbu         $a2, 0x9F($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X9F);
    // 0x8006BF10: jal         0x80077F84
    // 0x8006BF14: nop

    bgdraw_primcolour(rdram, ctx);
        goto after_45;
    // 0x8006BF14: nop

    after_45:
    // 0x8006BF18: jal         0x8007ADC4
    // 0x8006BF1C: nop

    video_delta_reset(rdram, ctx);
        goto after_46;
    // 0x8006BF1C: nop

    after_46:
    // 0x8006BF20: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8006BF24: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8006BF28: nop

    // 0x8006BF2C: addu        $t5, $t8, $t7
    ctx->r13 = ADD32(ctx->r24, ctx->r15);
    // 0x8006BF30: lbu         $a0, 0x4($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X4);
    // 0x8006BF34: jal         0x8007AF74
    // 0x8006BF38: nop

    func_8007AB24(rdram, ctx);
        goto after_47;
    // 0x8006BF38: nop

    after_47:
    // 0x8006BF3C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BF40: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8006BF44: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8006BF48: jr          $ra
    // 0x8006BF4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006BF4C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void update_line_particle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2C40: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B2C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2C48: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x800B2C4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800B2C50: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2C54: beq         $t6, $zero, L_800B2C80
    if (ctx->r14 == 0) {
        // 0x800B2C58: sw          $t6, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r14;
            goto L_800B2C80;
    }
    // 0x800B2C58: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    // 0x800B2C5C: lw          $a3, 0x58($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X58);
    // 0x800B2C60: nop

    // 0x800B2C64: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800B2C68: nop

    // 0x800B2C6C: lw          $t9, 0x9C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X9C);
    // 0x800B2C70: nop

    // 0x800B2C74: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x800B2C78: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x800B2C7C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
L_800B2C80:
    // 0x800B2C80: lbu         $t0, 0x68($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2C84: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2C88: slti        $at, $t0, 0x2
    ctx->r1 = SIGNED(ctx->r8) < 0X2 ? 1 : 0;
    // 0x800B2C8C: beq         $at, $zero, L_800B33C8
    if (ctx->r1 == 0) {
        // 0x800B2C90: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B33C8;
    }
    // 0x800B2C90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B2C94: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x800B2C98: nop

    // 0x800B2C9C: beq         $t1, $zero, L_800B33C8
    if (ctx->r9 == 0) {
        // 0x800B2CA0: nop
    
            goto L_800B33C8;
    }
    // 0x800B2CA0: nop

    // 0x800B2CA4: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800B2CA8: nop

    // 0x800B2CAC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800B2CB0: nop

    // 0x800B2CB4: andi        $t4, $t3, 0x1000
    ctx->r12 = ctx->r11 & 0X1000;
    // 0x800B2CB8: beq         $t4, $zero, L_800B2D18
    if (ctx->r12 == 0) {
        // 0x800B2CBC: nop
    
            goto L_800B2D18;
    }
    // 0x800B2CBC: nop

    // 0x800B2CC0: lwc1        $f0, 0x1C($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x800B2CC4: lwc1        $f2, 0x20($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X20);
    // 0x800B2CC8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800B2CCC: lwc1        $f14, 0x24($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X24);
    // 0x800B2CD0: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B2CD4: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2CD8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800B2CDC: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2CE0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800B2CE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B2CE8: jal         0x800CA030
    // 0x800B2CEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800B2CEC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800B2CF0: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2CF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2CF8: lwc1        $f16, 0x8($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B2CFC: lwc1        $f4, -0x6E90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X6E90);
    // 0x800B2D00: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B2D04: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2D08: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2D0C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800B2D10: b           L_800B2D24
    // 0x800B2D14: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
        goto L_800B2D24;
    // 0x800B2D14: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B2D18:
    // 0x800B2D18: lwc1        $f2, 0x8($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800B2D1C: nop

    // 0x800B2D20: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
L_800B2D24:
    // 0x800B2D24: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800B2D28: andi        $t6, $t5, 0x4000
    ctx->r14 = ctx->r13 & 0X4000;
    // 0x800B2D2C: bne         $t6, $zero, L_800B2D9C
    if (ctx->r14 != 0) {
        // 0x800B2D30: addiu       $a1, $sp, 0x44
        ctx->r5 = ADD32(ctx->r29, 0X44);
            goto L_800B2D9C;
    }
    // 0x800B2D30: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B2D34: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B2D38: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2D3C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D40: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D44: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800B2D48: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B2D4C: nop

    // 0x800B2D50: beq         $v0, $at, L_800B2D70
    if (ctx->r2 == ctx->r1) {
        // 0x800B2D54: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800B2D70;
    }
    // 0x800B2D54: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B2D58: beq         $v0, $at, L_800B2D68
    if (ctx->r2 == ctx->r1) {
        // 0x800B2D5C: nop
    
            goto L_800B2D68;
    }
    // 0x800B2D5C: nop

    // 0x800B2D60: b           L_800B2D74
    // 0x800B2D64: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
        goto L_800B2D74;
    // 0x800B2D64: swc1        $f2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f2.u32l;
L_800B2D68:
    // 0x800B2D68: b           L_800B2D74
    // 0x800B2D6C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
        goto L_800B2D74;
    // 0x800B2D6C: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
L_800B2D70:
    // 0x800B2D70: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
L_800B2D74:
    // 0x800B2D74: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800B2D78: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2D7C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2D80: jal         0x80070560
    // 0x800B2D84: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B2D84: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B2D88: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2D8C: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2D90: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2D94: b           L_800B2E8C
    // 0x800B2D98: nop

        goto L_800B2E8C;
    // 0x800B2D98: nop

L_800B2D9C:
    // 0x800B2D9C: lwc1        $f6, 0x1C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800B2DA0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B2DA4: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800B2DA8: mul.s       $f16, $f6, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x800B2DAC: lwc1        $f8, 0x20($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800B2DB0: nop

    // 0x800B2DB4: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800B2DB8: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x800B2DBC: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B2DC0: lwc1        $f8, -0x6E8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X6E8C);
    // 0x800B2DC4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800B2DC8: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x800B2DCC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2DD0: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800B2DD4: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B2DD8: c.lt.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl < ctx->f8.fl;
    // 0x800B2DDC: nop

    // 0x800B2DE0: bc1f        L_800B2DF4
    if (!c1cs) {
        // 0x800B2DE4: nop
    
            goto L_800B2DF4;
    }
    // 0x800B2DE4: nop

    // 0x800B2DE8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800B2DEC: b           L_800B2E20
    // 0x800B2DF0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
        goto L_800B2E20;
    // 0x800B2DF0: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B2DF4:
    // 0x800B2DF4: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B2DF8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x800B2DFC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x800B2E00: jal         0x800CA030
    // 0x800B2E04: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x800B2E04: swc1        $f2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x800B2E08: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B2E0C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B2E10: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B2E14: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800B2E18: div.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800B2E1C: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
L_800B2E20:
    // 0x800B2E20: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2E24: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800B2E28: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800B2E30: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800B2E34: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B2E38: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800B2E3C: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B2E40: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2E44: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800B2E48: lb          $v0, 0x6A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X6A);
    // 0x800B2E4C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E50: beq         $v0, $zero, L_800B2E68
    if (ctx->r2 == 0) {
        // 0x800B2E54: nop
    
            goto L_800B2E68;
    }
    // 0x800B2E54: nop

    // 0x800B2E58: beq         $v0, $at, L_800B2E78
    if (ctx->r2 == ctx->r1) {
        // 0x800B2E5C: nop
    
            goto L_800B2E78;
    }
    // 0x800B2E5C: nop

    // 0x800B2E60: b           L_800B2E8C
    // 0x800B2E64: nop

        goto L_800B2E8C;
    // 0x800B2E64: nop

L_800B2E68:
    // 0x800B2E68: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800B2E6C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800B2E70: b           L_800B2E8C
    // 0x800B2E74: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
        goto L_800B2E8C;
    // 0x800B2E74: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B2E78:
    // 0x800B2E78: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2E7C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2E80: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x800B2E84: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800B2E88: swc1        $f12, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f12.u32l;
L_800B2E8C:
    // 0x800B2E8C: beq         $v1, $zero, L_800B31C8
    if (ctx->r3 == 0) {
        // 0x800B2E90: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B31C8;
    }
    // 0x800B2E90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B2E94: lbu         $t8, 0x68($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X68);
    // 0x800B2E98: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B2E9C: bne         $t8, $zero, L_800B31C8
    if (ctx->r24 != 0) {
        // 0x800B2EA0: nop
    
            goto L_800B31C8;
    }
    // 0x800B2EA0: nop

    // 0x800B2EA4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2EA8: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2EAC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B2EB0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2EB4: nop

    // 0x800B2EB8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2EBC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2EC0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2EC4: nop

    // 0x800B2EC8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2ECC: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B2ED0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B2ED4: sh          $t0, 0xA($t2)
    MEM_H(0XA, ctx->r10) = ctx->r8;
    // 0x800B2ED8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2EDC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B2EE0: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B2EE4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B2EE8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B2EEC: nop

    // 0x800B2EF0: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B2EF4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2EF8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2EFC: nop

    // 0x800B2F00: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2F04: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800B2F08: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B2F0C: sh          $t4, 0xC($t1)
    MEM_H(0XC, ctx->r9) = ctx->r12;
    // 0x800B2F10: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2F14: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B2F18: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F1C: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B2F20: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B2F24: nop

    // 0x800B2F28: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B2F2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2F30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2F34: nop

    // 0x800B2F38: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2F3C: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B2F40: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B2F44: sh          $t6, 0xE($t7)
    MEM_H(0XE, ctx->r15) = ctx->r14;
    // 0x800B2F48: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B2F50: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B2F54: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B2F58: sb          $t8, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r24;
    // 0x800B2F5C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F60: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2F64: lbu         $t9, 0x7($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X7);
    // 0x800B2F68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2F6C: sb          $t9, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r25;
    // 0x800B2F70: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F74: nop

    // 0x800B2F78: lbu         $t0, 0x8($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X8);
    // 0x800B2F7C: nop

    // 0x800B2F80: sb          $t0, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r8;
    // 0x800B2F84: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F88: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B2F8C: nop

    // 0x800B2F90: sb          $t2, 0x13($t3)
    MEM_B(0X13, ctx->r11) = ctx->r10;
    // 0x800B2F94: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B2F98: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B2F9C: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B2FA0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B2FA4: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x800B2FA8: nop

    // 0x800B2FAC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B2FB0: sh          $t1, 0x14($t5)
    MEM_H(0X14, ctx->r13) = ctx->r9;
    // 0x800B2FB4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B2FB8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2FBC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2FC0: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B2FC4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B2FC8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B2FCC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B2FD0: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B2FD4: nop

    // 0x800B2FD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B2FDC: sh          $t7, 0x16($t8)
    MEM_H(0X16, ctx->r24) = ctx->r15;
    // 0x800B2FE0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B2FE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B2FE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B2FEC: lwc1        $f10, 0x14($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B2FF0: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B2FF4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B2FF8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B2FFC: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B3000: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B3004: sh          $t0, 0x18($t2)
    MEM_H(0X18, ctx->r10) = ctx->r8;
    // 0x800B3008: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800B300C: nop

    // 0x800B3010: beq         $t3, $at, L_800B3084
    if (ctx->r11 == ctx->r1) {
        // 0x800B3014: nop
    
            goto L_800B3084;
    }
    // 0x800B3014: nop

    // 0x800B3018: lh          $t4, 0x1E($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1E);
    // 0x800B301C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3020: sll         $t1, $t4, 3
    ctx->r9 = S32(ctx->r12 << 3);
    // 0x800B3024: addu        $t5, $t3, $t1
    ctx->r13 = ADD32(ctx->r11, ctx->r9);
    // 0x800B3028: lbu         $t6, 0x14($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X14);
    // 0x800B302C: nop

    // 0x800B3030: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800B3034: lh          $t9, 0x1E($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1E);
    // 0x800B3038: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800B303C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x800B3040: addu        $t2, $t8, $t0
    ctx->r10 = ADD32(ctx->r24, ctx->r8);
    // 0x800B3044: lbu         $t4, 0x15($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X15);
    // 0x800B3048: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B304C: nop

    // 0x800B3050: sb          $t4, 0x1B($t3)
    MEM_B(0X1B, ctx->r11) = ctx->r12;
    // 0x800B3054: lh          $t5, 0x1E($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X1E);
    // 0x800B3058: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800B305C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x800B3060: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800B3064: lbu         $t9, 0x16($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X16);
    // 0x800B3068: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B306C: nop

    // 0x800B3070: sb          $t9, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r25;
    // 0x800B3074: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B3078: lbu         $t0, 0x6($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X6);
    // 0x800B307C: b           L_800B30C4
    // 0x800B3080: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
        goto L_800B30C4;
    // 0x800B3080: sb          $t0, 0x1D($t2)
    MEM_B(0X1D, ctx->r10) = ctx->r8;
L_800B3084:
    // 0x800B3084: lbu         $t4, 0x6C($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X6C);
    // 0x800B3088: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B308C: nop

    // 0x800B3090: sb          $t4, 0x1A($t3)
    MEM_B(0X1A, ctx->r11) = ctx->r12;
    // 0x800B3094: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B3098: lbu         $t5, 0x6D($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X6D);
    // 0x800B309C: nop

    // 0x800B30A0: sb          $t5, 0x1B($t1)
    MEM_B(0X1B, ctx->r9) = ctx->r13;
    // 0x800B30A4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B30A8: lbu         $t6, 0x6E($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X6E);
    // 0x800B30AC: nop

    // 0x800B30B0: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x800B30B4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x800B30B8: lbu         $t9, 0x6($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X6);
    // 0x800B30BC: nop

    // 0x800B30C0: sb          $t9, 0x1D($t8)
    MEM_B(0X1D, ctx->r24) = ctx->r25;
L_800B30C4:
    // 0x800B30C4: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B30C8: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B30CC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B30D0: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B30D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B30D8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800B30DC: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B30E0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800B30E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B30E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B30EC: nop

    // 0x800B30F0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B30F4: mfc1        $t2, $f18
    ctx->r10 = (int32_t)ctx->f18.u32l;
    // 0x800B30F8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800B30FC: sh          $t2, 0x1E($t4)
    MEM_H(0X1E, ctx->r12) = ctx->r10;
    // 0x800B3100: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B3104: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3108: lw          $t1, 0x8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X8);
    // 0x800B310C: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B3110: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800B3114: nop

    // 0x800B3118: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800B311C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3120: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3124: nop

    // 0x800B3128: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B312C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800B3130: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800B3134: sh          $t5, 0x20($t1)
    MEM_H(0X20, ctx->r9) = ctx->r13;
    // 0x800B3138: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B313C: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B3140: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B3144: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B3148: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800B314C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B3150: nop

    // 0x800B3154: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B3158: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B315C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3160: nop

    // 0x800B3164: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B3168: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800B316C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B3170: sh          $t7, 0x22($t9)
    MEM_H(0X22, ctx->r25) = ctx->r15;
    // 0x800B3174: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3178: nop

    // 0x800B317C: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B3180: nop

    // 0x800B3184: sb          $t8, 0x24($v0)
    MEM_B(0X24, ctx->r2) = ctx->r24;
    // 0x800B3188: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B318C: nop

    // 0x800B3190: lbu         $t0, 0x7($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X7);
    // 0x800B3194: nop

    // 0x800B3198: sb          $t0, 0x25($v0)
    MEM_B(0X25, ctx->r2) = ctx->r8;
    // 0x800B319C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B31A0: nop

    // 0x800B31A4: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800B31A8: nop

    // 0x800B31AC: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x800B31B0: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B31B4: lbu         $t4, 0x6($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X6);
    // 0x800B31B8: nop

    // 0x800B31BC: sb          $t4, 0x27($t3)
    MEM_B(0X27, ctx->r11) = ctx->r12;
    // 0x800B31C0: b           L_800B34C8
    // 0x800B31C4: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
        goto L_800B34C8;
    // 0x800B31C4: sb          $t5, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r13;
L_800B31C8:
    // 0x800B31C8: beq         $v1, $zero, L_800B33C0
    if (ctx->r3 == 0) {
        // 0x800B31CC: nop
    
            goto L_800B33C0;
    }
    // 0x800B31CC: nop

    // 0x800B31D0: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B31D4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B31D8: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B31DC: add.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800B31E0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B31E4: nop

    // 0x800B31E8: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B31EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B31F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B31F4: nop

    // 0x800B31F8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B31FC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B3200: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B3204: sh          $t6, 0x28($t7)
    MEM_H(0X28, ctx->r15) = ctx->r14;
    // 0x800B3208: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B320C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3210: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x800B3214: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800B3218: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B321C: nop

    // 0x800B3220: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B3224: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3228: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B322C: nop

    // 0x800B3230: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B3234: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800B3238: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B323C: sh          $t8, 0x2A($t0)
    MEM_H(0X2A, ctx->r8) = ctx->r24;
    // 0x800B3240: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B3244: lwc1        $f18, 0x14($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B3248: lw          $t3, 0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X8);
    // 0x800B324C: add.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3250: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B3254: nop

    // 0x800B3258: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B325C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3264: nop

    // 0x800B3268: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B326C: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800B3270: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B3274: sh          $t4, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r12;
    // 0x800B3278: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B327C: nop

    // 0x800B3280: lbu         $t5, 0x1A($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B3284: nop

    // 0x800B3288: sb          $t5, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r13;
    // 0x800B328C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3290: nop

    // 0x800B3294: lbu         $t1, 0x1B($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B3298: nop

    // 0x800B329C: sb          $t1, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r9;
    // 0x800B32A0: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B32A4: nop

    // 0x800B32A8: lbu         $t6, 0x1C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B32AC: nop

    // 0x800B32B0: sb          $t6, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r14;
    // 0x800B32B4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800B32B8: lbu         $t7, 0x6($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X6);
    // 0x800B32BC: nop

    // 0x800B32C0: sb          $t7, 0x31($t9)
    MEM_B(0X31, ctx->r25) = ctx->r15;
    // 0x800B32C4: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800B32C8: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800B32CC: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x800B32D0: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800B32D4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B32D8: nop

    // 0x800B32DC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B32E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B32E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B32E8: nop

    // 0x800B32EC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B32F0: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x800B32F4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B32F8: sh          $t0, 0x32($t2)
    MEM_H(0X32, ctx->r10) = ctx->r8;
    // 0x800B32FC: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800B3300: lwc1        $f10, 0x10($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800B3304: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x800B3308: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800B330C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B3310: nop

    // 0x800B3314: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B3318: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B331C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3320: nop

    // 0x800B3324: cvt.w.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B3328: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800B332C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B3330: sh          $t3, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r11;
    // 0x800B3334: lwc1        $f18, 0x4C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800B3338: lwc1        $f16, 0x14($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800B333C: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800B3340: sub.s       $f10, $f16, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B3344: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800B3348: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B334C: nop

    // 0x800B3350: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B3354: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3358: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B335C: nop

    // 0x800B3360: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B3364: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800B3368: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B336C: sh          $t6, 0x36($t7)
    MEM_H(0X36, ctx->r15) = ctx->r14;
    // 0x800B3370: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3374: nop

    // 0x800B3378: lbu         $t9, 0x1A($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1A);
    // 0x800B337C: nop

    // 0x800B3380: sb          $t9, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r25;
    // 0x800B3384: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B3388: nop

    // 0x800B338C: lbu         $t8, 0x1B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1B);
    // 0x800B3390: nop

    // 0x800B3394: sb          $t8, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r24;
    // 0x800B3398: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800B339C: nop

    // 0x800B33A0: lbu         $t0, 0x1C($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1C);
    // 0x800B33A4: nop

    // 0x800B33A8: sb          $t0, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r8;
    // 0x800B33AC: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x800B33B0: lbu         $t2, 0x6($a3)
    ctx->r10 = MEM_BU(ctx->r7, 0X6);
    // 0x800B33B4: nop

    // 0x800B33B8: sb          $t2, 0x3B($t4)
    MEM_B(0X3B, ctx->r12) = ctx->r10;
    // 0x800B33BC: sb          $t3, 0x68($a2)
    MEM_B(0X68, ctx->r6) = ctx->r11;
L_800B33C0:
    // 0x800B33C0: b           L_800B34C8
    // 0x800B33C4: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
        goto L_800B34C8;
    // 0x800B33C4: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
L_800B33C8:
    // 0x800B33C8: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B33CC: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x800B33D0: lh          $t5, 0x3A($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X3A);
    // 0x800B33D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800B33D8: subu        $t6, $t5, $t1
    ctx->r14 = SUB32(ctx->r13, ctx->r9);
    // 0x800B33DC: sh          $t6, 0x3A($a2)
    MEM_H(0X3A, ctx->r6) = ctx->r14;
    // 0x800B33E0: lh          $t7, 0x3A($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X3A);
    // 0x800B33E4: nop

    // 0x800B33E8: bgtz        $t7, L_800B3410
    if (SIGNED(ctx->r15) > 0) {
        // 0x800B33EC: nop
    
            goto L_800B3410;
    }
    // 0x800B33EC: nop

    // 0x800B33F0: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B33F4: jal         0x8000FFB8
    // 0x800B33F8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800B33F8: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    after_3:
    // 0x800B33FC: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3400: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B3404: lw          $a2, 0x50($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X50);
    // 0x800B3408: b           L_800B34C8
    // 0x800B340C: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
        goto L_800B34C8;
    // 0x800B340C: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
L_800B3410:
    // 0x800B3410: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B3414: nop

    // 0x800B3418: bne         $v0, $zero, L_800B348C
    if (ctx->r2 != 0) {
        // 0x800B341C: nop
    
            goto L_800B348C;
    }
    // 0x800B341C: nop

    // 0x800B3420: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800B3424: lh          $t8, 0x5E($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X5E);
    // 0x800B3428: lh          $t2, 0x5C($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X5C);
    // 0x800B342C: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3430: mflo        $t0
    ctx->r8 = lo;
    // 0x800B3434: addu        $t4, $t2, $t0
    ctx->r12 = ADD32(ctx->r10, ctx->r8);
    // 0x800B3438: sh          $t4, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r12;
    // 0x800B343C: lh          $t3, 0x5C($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5C);
    // 0x800B3440: nop

    // 0x800B3444: slti        $at, $t3, 0xFF
    ctx->r1 = SIGNED(ctx->r11) < 0XFF ? 1 : 0;
    // 0x800B3448: beq         $at, $zero, L_800B34C8
    if (ctx->r1 == 0) {
        // 0x800B344C: nop
    
            goto L_800B34C8;
    }
    // 0x800B344C: nop

    // 0x800B3450: lw          $t5, 0x40($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X40);
    // 0x800B3454: nop

    // 0x800B3458: andi        $t1, $t5, 0x1000
    ctx->r9 = ctx->r13 & 0X1000;
    // 0x800B345C: beq         $t1, $zero, L_800B3478
    if (ctx->r9 == 0) {
        // 0x800B3460: nop
    
            goto L_800B3478;
    }
    // 0x800B3460: nop

    // 0x800B3464: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x800B3468: nop

    // 0x800B346C: ori         $t7, $t6, 0x100
    ctx->r15 = ctx->r14 | 0X100;
    // 0x800B3470: b           L_800B34C8
    // 0x800B3474: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
        goto L_800B34C8;
    // 0x800B3474: sh          $t7, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r15;
L_800B3478:
    // 0x800B3478: lh          $t9, 0x6($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X6);
    // 0x800B347C: nop

    // 0x800B3480: ori         $t8, $t9, 0x80
    ctx->r24 = ctx->r25 | 0X80;
    // 0x800B3484: b           L_800B34C8
    // 0x800B3488: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
        goto L_800B34C8;
    // 0x800B3488: sh          $t8, 0x6($a2)
    MEM_H(0X6, ctx->r6) = ctx->r24;
L_800B348C:
    // 0x800B348C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B3490: nop

    // 0x800B3494: subu        $t0, $v0, $t2
    ctx->r8 = SUB32(ctx->r2, ctx->r10);
    // 0x800B3498: sh          $t0, 0x60($a2)
    MEM_H(0X60, ctx->r6) = ctx->r8;
    // 0x800B349C: lh          $v0, 0x60($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X60);
    // 0x800B34A0: nop

    // 0x800B34A4: bgez        $v0, L_800B34C8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800B34A8: nop
    
            goto L_800B34C8;
    }
    // 0x800B34A8: nop

    // 0x800B34AC: lh          $t3, 0x5E($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X5E);
    // 0x800B34B0: lh          $t4, 0x5C($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X5C);
    // 0x800B34B4: multu       $v0, $t3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B34B8: sh          $zero, 0x60($a2)
    MEM_H(0X60, ctx->r6) = 0;
    // 0x800B34BC: mflo        $t5
    ctx->r13 = lo;
    // 0x800B34C0: subu        $t1, $t4, $t5
    ctx->r9 = SUB32(ctx->r12, ctx->r13);
    // 0x800B34C4: sh          $t1, 0x5C($a2)
    MEM_H(0X5C, ctx->r6) = ctx->r9;
L_800B34C8:
    // 0x800B34C8: beq         $v1, $zero, L_800B3510
    if (ctx->r3 == 0) {
        // 0x800B34CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800B34D4: nop

    // 0x800B34D8: beq         $t6, $zero, L_800B3510
    if (ctx->r14 == 0) {
        // 0x800B34DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34E0: lw          $t7, 0x40($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X40);
    // 0x800B34E4: nop

    // 0x800B34E8: andi        $t9, $t7, 0x3
    ctx->r25 = ctx->r15 & 0X3;
    // 0x800B34EC: beq         $t9, $zero, L_800B3510
    if (ctx->r25 == 0) {
        // 0x800B34F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B34F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B34F4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800B34F8: nop

    // 0x800B34FC: blez        $t8, L_800B3510
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B3500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B3510;
    }
    // 0x800B3500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B3504: jal         0x800B351C
    // 0x800B3508: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    update_particle_texture_frame(rdram, ctx);
        goto after_4;
    // 0x800B3508: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x800B350C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B3510:
    // 0x800B3510: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800B3514: jr          $ra
    // 0x800B3518: nop

    return;
    // 0x800B3518: nop

;}
RECOMP_FUNC void obj_init_butterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040A08: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80040A0C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80040A10: bne         $a2, $zero, L_80040B00
    if (ctx->r6 != 0) {
        // 0x80040A14: addiu       $t6, $zero, 0x180
        ctx->r14 = ADD32(0, 0X180);
            goto L_80040B00;
    }
    // 0x80040A14: addiu       $t6, $zero, 0x180
    ctx->r14 = ADD32(0, 0X180);
    // 0x80040A18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80040A1C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80040A20: swc1        $f0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f0.u32l;
    // 0x80040A24: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80040A28: sb          $zero, 0xFE($v0)
    MEM_B(0XFE, ctx->r2) = 0;
    // 0x80040A2C: sw          $zero, 0x100($v0)
    MEM_W(0X100, ctx->r2) = 0;
    // 0x80040A30: sh          $zero, 0x104($v0)
    MEM_H(0X104, ctx->r2) = 0;
    // 0x80040A34: sb          $zero, 0xFD($v0)
    MEM_B(0XFD, ctx->r2) = 0;
    // 0x80040A38: sh          $t6, 0x106($v0)
    MEM_H(0X106, ctx->r2) = ctx->r14;
    // 0x80040A3C: addiu       $v1, $v1, -0x2F68
    ctx->r3 = ADD32(ctx->r3, -0X2F68);
    // 0x80040A40: addiu       $a2, $a2, -0x2FE8
    ctx->r6 = ADD32(ctx->r6, -0X2FE8);
    // 0x80040A44: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040A48: swc1        $f0, 0x108($v0)
    MEM_W(0X108, ctx->r2) = ctx->f0.u32l;
L_80040A4C:
    // 0x80040A4C: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x80040A50: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x80040A54: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x80040A58: lbu         $t8, -0xF($a2)
    ctx->r24 = MEM_BU(ctx->r6, -0XF);
    // 0x80040A5C: sltu        $at, $a2, $v1
    ctx->r1 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x80040A60: sb          $t8, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r24;
    // 0x80040A64: lbu         $t9, -0xE($a2)
    ctx->r25 = MEM_BU(ctx->r6, -0XE);
    // 0x80040A68: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80040A6C: sb          $t9, -0xE($a1)
    MEM_B(-0XE, ctx->r5) = ctx->r25;
    // 0x80040A70: lbu         $t1, -0xD($a2)
    ctx->r9 = MEM_BU(ctx->r6, -0XD);
    // 0x80040A74: bne         $at, $zero, L_80040A4C
    if (ctx->r1 != 0) {
        // 0x80040A78: sb          $t1, -0xD($a1)
        MEM_B(-0XD, ctx->r5) = ctx->r9;
            goto L_80040A4C;
    }
    // 0x80040A78: sb          $t1, -0xD($a1)
    MEM_B(-0XD, ctx->r5) = ctx->r9;
    // 0x80040A7C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80040A80: addiu       $a2, $a2, -0x2F68
    ctx->r6 = ADD32(ctx->r6, -0X2F68);
    // 0x80040A84: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80040A88: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040A8C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80040A90: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
L_80040A94:
    // 0x80040A94: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x80040A98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80040A9C: sh          $t2, 0x80($a1)
    MEM_H(0X80, ctx->r5) = ctx->r10;
    // 0x80040AA0: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x80040AA4: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
    // 0x80040AA8: sh          $t3, 0x78($a1)
    MEM_H(0X78, ctx->r5) = ctx->r11;
    // 0x80040AAC: lh          $t4, 0x4($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X4);
    // 0x80040AB0: sb          $a3, 0x7C($a1)
    MEM_B(0X7C, ctx->r5) = ctx->r7;
    // 0x80040AB4: sb          $a3, 0x7D($a1)
    MEM_B(0X7D, ctx->r5) = ctx->r7;
    // 0x80040AB8: sb          $a3, 0x7E($a1)
    MEM_B(0X7E, ctx->r5) = ctx->r7;
    // 0x80040ABC: sb          $a3, 0x7F($a1)
    MEM_B(0X7F, ctx->r5) = ctx->r7;
    // 0x80040AC0: sh          $t4, 0x7A($a1)
    MEM_H(0X7A, ctx->r5) = ctx->r12;
    // 0x80040AC4: lh          $t5, 0x0($a2)
    ctx->r13 = MEM_H(ctx->r6, 0X0);
    // 0x80040AC8: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
    // 0x80040ACC: sh          $t5, 0xB2($a1)
    MEM_H(0XB2, ctx->r5) = ctx->r13;
    // 0x80040AD0: lh          $t6, -0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X4);
    // 0x80040AD4: nop

    // 0x80040AD8: sh          $t6, 0xB4($a1)
    MEM_H(0XB4, ctx->r5) = ctx->r14;
    // 0x80040ADC: lh          $t7, -0x2($a2)
    ctx->r15 = MEM_H(ctx->r6, -0X2);
    // 0x80040AE0: sb          $a3, 0xB8($a1)
    MEM_B(0XB8, ctx->r5) = ctx->r7;
    // 0x80040AE4: sb          $a3, 0xB9($a1)
    MEM_B(0XB9, ctx->r5) = ctx->r7;
    // 0x80040AE8: sb          $a3, 0xBA($a1)
    MEM_B(0XBA, ctx->r5) = ctx->r7;
    // 0x80040AEC: sb          $a3, 0xBB($a1)
    MEM_B(0XBB, ctx->r5) = ctx->r7;
    // 0x80040AF0: bne         $v1, $t0, L_80040A94
    if (ctx->r3 != ctx->r8) {
        // 0x80040AF4: sh          $t7, 0xB6($a1)
        MEM_H(0XB6, ctx->r5) = ctx->r15;
            goto L_80040A94;
    }
    // 0x80040AF4: sh          $t7, 0xB6($a1)
    MEM_H(0XB6, ctx->r5) = ctx->r15;
    // 0x80040AF8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040AFC: sb          $t8, 0xFC($v0)
    MEM_B(0XFC, ctx->r2) = ctx->r24;
L_80040B00:
    // 0x80040B00: lw          $t9, 0x4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4);
    // 0x80040B04: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80040B08: lbu         $t1, 0xB($t9)
    ctx->r9 = MEM_BU(ctx->r25, 0XB);
    // 0x80040B0C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80040B10: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80040B14: bgez        $t1, L_80040B2C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80040B18: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80040B2C;
    }
    // 0x80040B18: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040B1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040B20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80040B24: nop

    // 0x80040B28: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80040B2C:
    // 0x80040B2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040B30: lwc1        $f10, 0x67A8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X67A8);
    // 0x80040B34: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80040B38: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80040B3C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80040B40: addiu       $a2, $a2, -0x2FE8
    ctx->r6 = ADD32(ctx->r6, -0X2FE8);
    // 0x80040B44: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x80040B48: lw          $t2, 0x4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4);
    // 0x80040B4C: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80040B50: lbu         $v1, 0xA($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0XA);
    // 0x80040B54: nop

    // 0x80040B58: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80040B5C: beq         $at, $zero, L_80040B7C
    if (ctx->r1 == 0) {
        // 0x80040B60: nop
    
            goto L_80040B7C;
    }
    // 0x80040B60: nop

    // 0x80040B64: lw          $t5, 0x68($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X68);
    // 0x80040B68: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80040B6C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80040B70: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80040B74: b           L_80040B90
    // 0x80040B78: sw          $t8, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r24;
        goto L_80040B90;
    // 0x80040B78: sw          $t8, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r24;
L_80040B7C:
    // 0x80040B7C: lw          $t9, 0x68($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X68);
    // 0x80040B80: nop

    // 0x80040B84: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80040B88: nop

    // 0x80040B8C: sw          $t1, 0xF8($v0)
    MEM_W(0XF8, ctx->r2) = ctx->r9;
L_80040B90:
    // 0x80040B90: lw          $v1, 0xF8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XF8);
    // 0x80040B94: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80040B98: beq         $v1, $zero, L_80040BC4
    if (ctx->r3 == 0) {
        // 0x80040B9C: addiu       $v0, $v0, -0x2F68
        ctx->r2 = ADD32(ctx->r2, -0X2F68);
            goto L_80040BC4;
    }
    // 0x80040B9C: addiu       $v0, $v0, -0x2F68
    ctx->r2 = ADD32(ctx->r2, -0X2F68);
    // 0x80040BA0: lbu         $a3, 0x0($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X0);
    // 0x80040BA4: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x80040BA8: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x80040BAC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80040BB0: sll         $t2, $a3, 5
    ctx->r10 = S32(ctx->r7 << 5);
    // 0x80040BB4: sll         $t3, $a0, 5
    ctx->r11 = S32(ctx->r4 << 5);
    // 0x80040BB8: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x80040BBC: b           L_80040BC8
    // 0x80040BC0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
        goto L_80040BC8;
    // 0x80040BC0: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_80040BC4:
    // 0x80040BC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80040BC8:
    // 0x80040BC8: lh          $t4, 0x4($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X4);
    // 0x80040BCC: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x80040BD0: and         $t5, $t4, $a3
    ctx->r13 = ctx->r12 & ctx->r7;
    // 0x80040BD4: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80040BD8: lh          $t6, -0x1A($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X1A);
    // 0x80040BDC: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x80040BE0: and         $t7, $t6, $a0
    ctx->r15 = ctx->r14 & ctx->r4;
    // 0x80040BE4: sh          $t7, -0x1A($a1)
    MEM_H(-0X1A, ctx->r5) = ctx->r15;
    // 0x80040BE8: lh          $t8, -0x18($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X18);
    // 0x80040BEC: nop

    // 0x80040BF0: and         $t9, $t8, $a3
    ctx->r25 = ctx->r24 & ctx->r7;
    // 0x80040BF4: sh          $t9, -0x18($a1)
    MEM_H(-0X18, ctx->r5) = ctx->r25;
    // 0x80040BF8: lh          $t1, -0x16($a2)
    ctx->r9 = MEM_H(ctx->r6, -0X16);
    // 0x80040BFC: nop

    // 0x80040C00: and         $t2, $t1, $a0
    ctx->r10 = ctx->r9 & ctx->r4;
    // 0x80040C04: sh          $t2, -0x16($a1)
    MEM_H(-0X16, ctx->r5) = ctx->r10;
    // 0x80040C08: lh          $t3, -0x14($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X14);
    // 0x80040C0C: nop

    // 0x80040C10: and         $t4, $t3, $a3
    ctx->r12 = ctx->r11 & ctx->r7;
    // 0x80040C14: sh          $t4, -0x14($a1)
    MEM_H(-0X14, ctx->r5) = ctx->r12;
    // 0x80040C18: lh          $t5, -0x12($a2)
    ctx->r13 = MEM_H(ctx->r6, -0X12);
    // 0x80040C1C: nop

    // 0x80040C20: and         $t6, $t5, $a0
    ctx->r14 = ctx->r13 & ctx->r4;
    // 0x80040C24: sh          $t6, -0x12($a1)
    MEM_H(-0X12, ctx->r5) = ctx->r14;
    // 0x80040C28: lh          $t7, -0xC($a2)
    ctx->r15 = MEM_H(ctx->r6, -0XC);
    // 0x80040C2C: nop

    // 0x80040C30: and         $t8, $t7, $a3
    ctx->r24 = ctx->r15 & ctx->r7;
    // 0x80040C34: sh          $t8, -0xC($a1)
    MEM_H(-0XC, ctx->r5) = ctx->r24;
    // 0x80040C38: lh          $t9, -0xA($a2)
    ctx->r25 = MEM_H(ctx->r6, -0XA);
    // 0x80040C3C: nop

    // 0x80040C40: and         $t1, $t9, $a0
    ctx->r9 = ctx->r25 & ctx->r4;
    // 0x80040C44: sh          $t1, -0xA($a1)
    MEM_H(-0XA, ctx->r5) = ctx->r9;
    // 0x80040C48: lh          $t2, -0x8($a2)
    ctx->r10 = MEM_H(ctx->r6, -0X8);
    // 0x80040C4C: nop

    // 0x80040C50: and         $t3, $t2, $a3
    ctx->r11 = ctx->r10 & ctx->r7;
    // 0x80040C54: sh          $t3, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r11;
    // 0x80040C58: lh          $t4, -0x6($a2)
    ctx->r12 = MEM_H(ctx->r6, -0X6);
    // 0x80040C5C: nop

    // 0x80040C60: and         $t5, $t4, $a0
    ctx->r13 = ctx->r12 & ctx->r4;
    // 0x80040C64: sh          $t5, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r13;
    // 0x80040C68: lh          $t6, -0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, -0X4);
    // 0x80040C6C: nop

    // 0x80040C70: and         $t7, $t6, $a3
    ctx->r15 = ctx->r14 & ctx->r7;
    // 0x80040C74: sh          $t7, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r15;
    // 0x80040C78: lh          $t8, -0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, -0X2);
    // 0x80040C7C: nop

    // 0x80040C80: and         $t9, $t8, $a0
    ctx->r25 = ctx->r24 & ctx->r4;
    // 0x80040C84: bne         $a2, $v0, L_80040BC8
    if (ctx->r6 != ctx->r2) {
        // 0x80040C88: sh          $t9, -0x2($a1)
        MEM_H(-0X2, ctx->r5) = ctx->r25;
            goto L_80040BC8;
    }
    // 0x80040C88: sh          $t9, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r25;
    // 0x80040C8C: jr          $ra
    // 0x80040C90: nop

    return;
    // 0x80040C90: nop

;}
