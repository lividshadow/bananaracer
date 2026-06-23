#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80072E28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073080: blez        $a0, L_800732BC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80073084: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_800732BC;
    }
    // 0x80073084: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80073088: addiu       $t6, $a0, 0x1F
    ctx->r14 = ADD32(ctx->r4, 0X1F);
    // 0x8007308C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80073090: beq         $a0, $zero, L_8007329C
    if (ctx->r4 == 0) {
        // 0x80073094: sllv        $v0, $t7, $t6
        ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
            goto L_8007329C;
    }
    // 0x80073094: sllv        $v0, $t7, $t6
    ctx->r2 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80073098: andi        $v1, $a0, 0x3
    ctx->r3 = ctx->r4 & 0X3;
    // 0x8007309C: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x800730A0: beq         $v1, $zero, L_80073128
    if (ctx->r3 == 0) {
        // 0x800730A4: addu        $a3, $v1, $a0
        ctx->r7 = ADD32(ctx->r3, ctx->r4);
            goto L_80073128;
    }
    // 0x800730A4: addu        $a3, $v1, $a0
    ctx->r7 = ADD32(ctx->r3, ctx->r4);
    // 0x800730A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800730AC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800730B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800730B4: addiu       $t0, $t0, 0x4774
    ctx->r8 = ADD32(ctx->r8, 0X4774);
    // 0x800730B8: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x800730BC: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x800730C0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_800730C4:
    // 0x800730C4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800730C8: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800730CC: bne         $a1, $zero, L_800730F8
    if (ctx->r5 != 0) {
        // 0x800730D0: and         $t7, $a2, $v0
        ctx->r15 = ctx->r6 & ctx->r2;
            goto L_800730F8;
    }
    // 0x800730D0: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x800730D4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800730D8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800730DC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800730E0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800730E4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800730E8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800730EC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800730F0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800730F4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800730F8:
    // 0x800730F8: beq         $t7, $zero, L_80073110
    if (ctx->r15 == 0) {
        // 0x800730FC: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_80073110;
    }
    // 0x800730FC: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x80073100: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80073104: nop

    // 0x80073108: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x8007310C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_80073110:
    // 0x80073110: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80073114: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80073118: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8007311C: bne         $a3, $v1, L_800730C4
    if (ctx->r7 != ctx->r3) {
        // 0x80073120: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800730C4;
    }
    // 0x80073120: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80073124: beq         $v1, $zero, L_8007329C
    if (ctx->r3 == 0) {
        // 0x80073128: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8007329C;
    }
L_80073128:
    // 0x80073128: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007312C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80073130: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80073134: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x80073138: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x8007313C: addiu       $t0, $t0, 0x4774
    ctx->r8 = ADD32(ctx->r8, 0X4774);
    // 0x80073140: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
L_80073144:
    // 0x80073144: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80073148: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x8007314C: bne         $a1, $zero, L_80073178
    if (ctx->r5 != 0) {
        // 0x80073150: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80073178;
    }
    // 0x80073150: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80073154: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80073158: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8007315C: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073160: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80073164: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80073168: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8007316C: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073170: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80073174: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
L_80073178:
    // 0x80073178: beq         $t9, $zero, L_80073190
    if (ctx->r25 == 0) {
        // 0x8007317C: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80073190;
    }
    // 0x8007317C: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80073180: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80073184: nop

    // 0x80073188: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x8007318C: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80073190:
    // 0x80073190: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x80073194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073198: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007319C: bne         $t6, $zero, L_800731C8
    if (ctx->r14 != 0) {
        // 0x800731A0: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800731C8;
    }
    // 0x800731A0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x800731A4: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x800731A8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800731AC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x800731B0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800731B4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800731B8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x800731BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800731C0: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x800731C4: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_800731C8:
    // 0x800731C8: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x800731CC: beq         $t7, $zero, L_800731E4
    if (ctx->r15 == 0) {
        // 0x800731D0: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_800731E4;
    }
    // 0x800731D0: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x800731D4: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800731D8: nop

    // 0x800731DC: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x800731E0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_800731E4:
    // 0x800731E4: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x800731E8: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800731EC: or          $a1, $t4, $zero
    ctx->r5 = ctx->r12 | 0;
    // 0x800731F0: bne         $t4, $zero, L_8007321C
    if (ctx->r12 != 0) {
        // 0x800731F4: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8007321C;
    }
    // 0x800731F4: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800731F8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800731FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80073200: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073204: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x80073208: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8007320C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80073210: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80073214: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80073218: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_8007321C:
    // 0x8007321C: and         $t9, $a2, $v0
    ctx->r25 = ctx->r6 & ctx->r2;
    // 0x80073220: beq         $t9, $zero, L_80073238
    if (ctx->r25 == 0) {
        // 0x80073224: srl         $t7, $v0, 1
        ctx->r15 = S32(U32(ctx->r2) >> 1);
            goto L_80073238;
    }
    // 0x80073224: srl         $t7, $v0, 1
    ctx->r15 = S32(U32(ctx->r2) >> 1);
    // 0x80073228: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8007322C: nop

    // 0x80073230: or          $t5, $t4, $a1
    ctx->r13 = ctx->r12 | ctx->r5;
    // 0x80073234: sw          $t5, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r13;
L_80073238:
    // 0x80073238: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x8007323C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80073240: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80073244: bne         $t6, $zero, L_80073270
    if (ctx->r14 != 0) {
        // 0x80073248: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80073270;
    }
    // 0x80073248: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007324C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x80073250: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80073254: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    // 0x80073258: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8007325C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80073260: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80073264: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80073268: sw          $t5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r13;
    // 0x8007326C: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80073270:
    // 0x80073270: and         $t7, $a2, $v0
    ctx->r15 = ctx->r6 & ctx->r2;
    // 0x80073274: beq         $t7, $zero, L_8007328C
    if (ctx->r15 == 0) {
        // 0x80073278: srl         $t9, $v0, 1
        ctx->r25 = S32(U32(ctx->r2) >> 1);
            goto L_8007328C;
    }
    // 0x80073278: srl         $t9, $v0, 1
    ctx->r25 = S32(U32(ctx->r2) >> 1);
    // 0x8007327C: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x80073280: nop

    // 0x80073284: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x80073288: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
L_8007328C:
    // 0x8007328C: srl         $t4, $a1, 1
    ctx->r12 = S32(U32(ctx->r5) >> 1);
    // 0x80073290: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x80073294: bne         $a0, $zero, L_80073144
    if (ctx->r4 != 0) {
        // 0x80073298: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80073144;
    }
    // 0x80073298: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_8007329C:
    // 0x8007329C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800732A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800732A4: addiu       $t2, $t2, 0x4770
    ctx->r10 = ADD32(ctx->r10, 0X4770);
    // 0x800732A8: addiu       $t1, $t1, 0x476C
    ctx->r9 = ADD32(ctx->r9, 0X476C);
    // 0x800732AC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800732B0: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800732B4: nop

    // 0x800732B8: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
L_800732BC:
    // 0x800732BC: jr          $ra
    // 0x800732C0: nop

    return;
    // 0x800732C0: nop

;}
RECOMP_FUNC void menu_trophy_race_rankings_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099510: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80099514: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099518: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8009951C: jal         0x8006ECD0
    // 0x80099520: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80099520: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_0:
    // 0x80099524: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80099528: addiu       $a1, $a1, -0x604
    ctx->r5 = ADD32(ctx->r5, -0X604);
    // 0x8009952C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80099530: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80099534: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    // 0x80099538: bne         $at, $zero, L_8009955C
    if (ctx->r1 != 0) {
        // 0x8009953C: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_8009955C;
    }
    // 0x8009953C: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80099540: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80099544: beq         $at, $zero, L_8009955C
    if (ctx->r1 == 0) {
        // 0x80099548: nop
    
            goto L_8009955C;
    }
    // 0x80099548: nop

    // 0x8009954C: jal         0x800993F8
    // 0x80099550: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    rankings_render_order(rdram, ctx);
        goto after_1;
    // 0x80099550: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80099554: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099558: nop

L_8009955C:
    // 0x8009955C: jal         0x8009C464
    // 0x80099560: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x80099560: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_2:
    // 0x80099564: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80099568: lw          $v0, 0x6980($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6980);
    // 0x8009956C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80099570: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80099574: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099578: beq         $v0, $zero, L_800995A8
    if (ctx->r2 == 0) {
        // 0x8009957C: addiu       $a1, $a1, -0x604
        ctx->r5 = ADD32(ctx->r5, -0X604);
            goto L_800995A8;
    }
    // 0x8009957C: addiu       $a1, $a1, -0x604
    ctx->r5 = ADD32(ctx->r5, -0X604);
    // 0x80099580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099584: beq         $v0, $at, L_800995F4
    if (ctx->r2 == ctx->r1) {
        // 0x80099588: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800995F4;
    }
    // 0x80099588: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009958C: beq         $v0, $at, L_80099628
    if (ctx->r2 == ctx->r1) {
        // 0x80099590: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80099628;
    }
    // 0x80099590: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099594: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80099598: beq         $v0, $at, L_80099860
    if (ctx->r2 == ctx->r1) {
        // 0x8009959C: nop
    
            goto L_80099860;
    }
    // 0x8009959C: nop

    // 0x800995A0: b           L_80099B28
    // 0x800995A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099B28;
    // 0x800995A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800995A8:
    // 0x800995A8: jal         0x8008239C
    // 0x800995AC: nop

    postrace_render(rdram, ctx);
        goto after_3;
    // 0x800995AC: nop

    after_3:
    // 0x800995B0: beq         $v0, $zero, L_80099B24
    if (ctx->r2 == 0) {
        // 0x800995B4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80099B24;
    }
    // 0x800995B4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800995B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800995BC: sw          $t6, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r14;
    // 0x800995C0: jal         0x80098CB0
    // 0x800995C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80098774(rdram, ctx);
        goto after_4;
    // 0x800995C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x800995C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800995CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800995D0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800995D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800995D8: addiu       $a0, $a0, 0x15C8
    ctx->r4 = ADD32(ctx->r4, 0X15C8);
    // 0x800995DC: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x800995E0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800995E4: jal         0x800822A4
    // 0x800995E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    postrace_offsets(rdram, ctx);
        goto after_5;
    // 0x800995E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_5:
    // 0x800995EC: b           L_80099B28
    // 0x800995F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099B28;
    // 0x800995F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800995F4:
    // 0x800995F4: jal         0x8008239C
    // 0x800995F8: nop

    postrace_render(rdram, ctx);
        goto after_6;
    // 0x800995F8: nop

    after_6:
    // 0x800995FC: beq         $v0, $zero, L_80099B24
    if (ctx->r2 == 0) {
        // 0x80099600: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80099B24;
    }
    // 0x80099600: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80099604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099608: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009960C: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
    // 0x80099610: addiu       $a1, $a1, 0x15C8
    ctx->r5 = ADD32(ctx->r5, 0X15C8);
    // 0x80099614: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80099618: jal         0x8008263C
    // 0x8009961C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    draw_menu_elements(rdram, ctx);
        goto after_7;
    // 0x8009961C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_7:
    // 0x80099620: b           L_80099B28
    // 0x80099624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099B28;
    // 0x80099624: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099628:
    // 0x80099628: addiu       $v1, $v1, 0x6978
    ctx->r3 = ADD32(ctx->r3, 0X6978);
    // 0x8009962C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80099630: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80099634: addu        $t9, $t8, $a0
    ctx->r25 = ADD32(ctx->r24, ctx->r4);
    // 0x80099638: slti        $at, $t9, 0xB
    ctx->r1 = SIGNED(ctx->r25) < 0XB ? 1 : 0;
    // 0x8009963C: bne         $at, $zero, L_800996D8
    if (ctx->r1 != 0) {
        // 0x80099640: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800996D8;
    }
    // 0x80099640: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80099644: addiu       $t5, $t9, -0xA
    ctx->r13 = ADD32(ctx->r25, -0XA);
    // 0x80099648: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8009964C: lw          $a3, 0x1564($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1564);
    // 0x80099650: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099654: blez        $a3, L_800996BC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80099658: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800996BC;
    }
    // 0x80099658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009965C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099660: addiu       $v1, $v1, 0x6998
    ctx->r3 = ADD32(ctx->r3, 0X6998);
    // 0x80099664: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
L_80099668:
    // 0x80099668: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8009966C: nop

    // 0x80099670: blez        $a0, L_800996AC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80099674: nop
    
            goto L_800996AC;
    }
    // 0x80099674: nop

    // 0x80099678: multu       $a1, $a2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8009967C: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x80099680: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80099684: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80099688: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009968C: mflo        $t7
    ctx->r15 = lo;
    // 0x80099690: addu        $v0, $t3, $t7
    ctx->r2 = ADD32(ctx->r11, ctx->r15);
    // 0x80099694: lw          $t8, 0x54($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X54);
    // 0x80099698: nop

    // 0x8009969C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800996A0: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
    // 0x800996A4: lw          $a3, 0x1564($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1564);
    // 0x800996A8: nop

L_800996AC:
    // 0x800996AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800996B0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800996B4: bne         $at, $zero, L_80099668
    if (ctx->r1 != 0) {
        // 0x800996B8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80099668;
    }
    // 0x800996B8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_800996BC:
    // 0x800996BC: beq         $t0, $zero, L_800996D8
    if (ctx->r8 == 0) {
        // 0x800996C0: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_800996D8;
    }
    // 0x800996C0: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x800996C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800996C8: jal         0x80001D04
    // 0x800996CC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800996CC: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_8:
    // 0x800996D0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800996D4: nop

L_800996D8:
    // 0x800996D8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800996DC: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x800996E0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800996E4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800996E8: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x800996EC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800996F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800996F4: blez        $t5, L_80099784
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800996F8: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_80099784;
    }
    // 0x800996F8: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800996FC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099700: addiu       $a3, $a3, 0x6A04
    ctx->r7 = ADD32(ctx->r7, 0X6A04);
L_80099704:
    // 0x80099704: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80099708: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8009970C: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x80099710: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80099714: jal         0x8006A794
    // 0x80099718: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    input_pressed(rdram, ctx);
        goto after_9;
    // 0x80099718: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_9:
    // 0x8009971C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80099720: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80099724: lb          $v1, 0x0($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X0);
    // 0x80099728: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8009972C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099730: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099734: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80099738: bgez        $v1, L_80099750
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8009973C: or          $t0, $t0, $v0
        ctx->r8 = ctx->r8 | ctx->r2;
            goto L_80099750;
    }
    // 0x8009973C: or          $t0, $t0, $v0
    ctx->r8 = ctx->r8 | ctx->r2;
    // 0x80099740: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80099744: nop

    // 0x80099748: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009974C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
L_80099750:
    // 0x80099750: blez        $v1, L_80099768
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80099754: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_80099768;
    }
    // 0x80099754: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80099758: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8009975C: nop

    // 0x80099760: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80099764: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80099768:
    // 0x80099768: lw          $t5, -0x5C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C4);
    // 0x8009976C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099770: slt         $at, $a1, $t5
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80099774: bne         $at, $zero, L_80099704
    if (ctx->r1 != 0) {
        // 0x80099778: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80099704;
    }
    // 0x80099778: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009977C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80099780: nop

L_80099784:
    // 0x80099784: bgez        $v0, L_80099794
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80099788: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80099794;
    }
    // 0x80099788: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009978C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80099790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80099794:
    // 0x80099794: lw          $v1, 0x71D4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X71D4);
    // 0x80099798: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009979C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800997A0: bne         $at, $zero, L_800997B0
    if (ctx->r1 != 0) {
        // 0x800997A4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800997B0;
    }
    // 0x800997A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800997A8: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800997AC: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_800997B0:
    // 0x800997B0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800997B4: nop

    // 0x800997B8: beq         $t7, $v0, L_800997DC
    if (ctx->r15 == ctx->r2) {
        // 0x800997BC: andi        $t8, $t0, 0x9000
        ctx->r24 = ctx->r8 & 0X9000;
            goto L_800997DC;
    }
    // 0x800997BC: andi        $t8, $t0, 0x9000
    ctx->r24 = ctx->r8 & 0X9000;
    // 0x800997C0: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x800997C4: jal         0x80001D04
    // 0x800997C8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800997C8: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_10:
    // 0x800997CC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800997D0: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800997D4: nop

    // 0x800997D8: andi        $t8, $t0, 0x9000
    ctx->r24 = ctx->r8 & 0X9000;
L_800997DC:
    // 0x800997DC: beq         $t8, $zero, L_80099B24
    if (ctx->r24 == 0) {
        // 0x800997E0: addiu       $a0, $zero, -0x80
        ctx->r4 = ADD32(0, -0X80);
            goto L_80099B24;
    }
    // 0x800997E0: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    // 0x800997E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800997E8: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800997EC: jal         0x80000C98
    // 0x800997F0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    music_fade(rdram, ctx);
        goto after_11;
    // 0x800997F0: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_11:
    // 0x800997F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800997F8: jal         0x800C06F8
    // 0x800997FC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x800997FC: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_12:
    // 0x80099800: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80099804: lw          $t5, 0x1564($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1564);
    // 0x80099808: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x8009980C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099810: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80099814: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099818: blez        $t5, L_80099B24
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8009981C: sw          $t9, 0x6980($at)
        MEM_W(0X6980, ctx->r1) = ctx->r25;
            goto L_80099B24;
    }
    // 0x8009981C: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
    // 0x80099820: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099824: addiu       $v1, $v1, 0x6998
    ctx->r3 = ADD32(ctx->r3, 0X6998);
    // 0x80099828: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_8009982C:
    // 0x8009982C: lw          $t6, 0x54($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X54);
    // 0x80099830: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80099834: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80099838: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8009983C: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x80099840: lw          $t9, 0x1564($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1564);
    // 0x80099844: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099848: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8009984C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80099850: bne         $at, $zero, L_8009982C
    if (ctx->r1 != 0) {
        // 0x80099854: addiu       $v0, $v0, 0x18
        ctx->r2 = ADD32(ctx->r2, 0X18);
            goto L_8009982C;
    }
    // 0x80099854: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x80099858: b           L_80099B28
    // 0x8009985C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099B28;
    // 0x8009985C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099860:
    // 0x80099860: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x80099864: nop

    // 0x80099868: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x8009986C: slti        $at, $t6, 0x1F
    ctx->r1 = SIGNED(ctx->r14) < 0X1F ? 1 : 0;
    // 0x80099870: bne         $at, $zero, L_80099B24
    if (ctx->r1 != 0) {
        // 0x80099874: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_80099B24;
    }
    // 0x80099874: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80099878: jal         0x80099B3C
    // 0x8009987C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    rankings_free(rdram, ctx);
        goto after_13;
    // 0x8009987C: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_13:
    // 0x80099880: jal         0x800C5B80
    // 0x80099884: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_14;
    // 0x80099884: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_14:
    // 0x80099888: jal         0x800C59F4
    // 0x8009988C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_15;
    // 0x8009988C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_15:
    // 0x80099890: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80099894: lw          $t8, 0x156C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X156C);
    // 0x80099898: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8009989C: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x800998A0: beq         $at, $zero, L_800998B8
    if (ctx->r1 == 0) {
        // 0x800998A4: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_800998B8;
    }
    // 0x800998A4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800998A8: jal         0x80081820
    // 0x800998AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    menu_init(rdram, ctx);
        goto after_16;
    // 0x800998AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_16:
    // 0x800998B0: b           L_80099B28
    // 0x800998B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80099B28;
    // 0x800998B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800998B8:
    // 0x800998B8: lw          $a3, 0x1564($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1564);
    // 0x800998BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800998C0: blez        $a3, L_80099970
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800998C4: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80099970;
    }
    // 0x800998C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800998C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800998CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800998D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800998D4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800998D8: addiu       $t0, $t0, 0x69D0
    ctx->r8 = ADD32(ctx->r8, 0X69D0);
    // 0x800998DC: addiu       $t2, $t2, 0x69D8
    ctx->r10 = ADD32(ctx->r10, 0X69D8);
    // 0x800998E0: addiu       $a2, $a2, 0x69C0
    ctx->r6 = ADD32(ctx->r6, 0X69C0);
    // 0x800998E4: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
L_800998E8:
    // 0x800998E8: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800998EC: addu        $t5, $t0, $a1
    ctx->r13 = ADD32(ctx->r8, ctx->r5);
    // 0x800998F0: beq         $t9, $zero, L_8009995C
    if (ctx->r25 == 0) {
        // 0x800998F4: nop
    
            goto L_8009995C;
    }
    // 0x800998F4: nop

    // 0x800998F8: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x800998FC: addu        $t8, $t2, $v1
    ctx->r24 = ADD32(ctx->r10, ctx->r3);
    // 0x80099900: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099904: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x80099908: mflo        $t7
    ctx->r15 = lo;
    // 0x8009990C: addu        $a0, $t3, $t7
    ctx->r4 = ADD32(ctx->r11, ctx->r15);
    // 0x80099910: lb          $v0, 0x59($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X59);
    // 0x80099914: bne         $v1, $zero, L_8009992C
    if (ctx->r3 != 0) {
        // 0x80099918: nop
    
            goto L_8009992C;
    }
    // 0x80099918: nop

    // 0x8009991C: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
    // 0x80099920: sb          $v0, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r2;
    // 0x80099924: b           L_8009995C
    // 0x80099928: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_8009995C;
    // 0x80099928: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8009992C:
    // 0x8009992C: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80099930: lw          $t9, 0x54($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X54);
    // 0x80099934: multu       $t6, $t1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80099938: addu        $t6, $t2, $v1
    ctx->r14 = ADD32(ctx->r10, ctx->r3);
    // 0x8009993C: mflo        $t7
    ctx->r15 = lo;
    // 0x80099940: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80099944: lw          $t5, 0x54($t8)
    ctx->r13 = MEM_W(ctx->r24, 0X54);
    // 0x80099948: nop

    // 0x8009994C: bne         $t9, $t5, L_8009995C
    if (ctx->r25 != ctx->r13) {
        // 0x80099950: nop
    
            goto L_8009995C;
    }
    // 0x80099950: nop

    // 0x80099954: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x80099958: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8009995C:
    // 0x8009995C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099960: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80099964: bne         $at, $zero, L_800998E8
    if (ctx->r1 != 0) {
        // 0x80099968: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800998E8;
    }
    // 0x80099968: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8009996C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
L_80099970:
    // 0x80099970: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80099974: lw          $t7, -0x5C4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5C4);
    // 0x80099978: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8009997C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80099984: bne         $t7, $at, L_800999B8
    if (ctx->r15 != ctx->r1) {
        // 0x80099988: addiu       $t2, $t2, 0x69D8
        ctx->r10 = ADD32(ctx->r10, 0X69D8);
            goto L_800999B8;
    }
    // 0x80099988: addiu       $t2, $t2, 0x69D8
    ctx->r10 = ADD32(ctx->r10, 0X69D8);
    // 0x8009998C: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80099990: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80099994: jal         0x8009F1C4
    // 0x80099998: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    is_in_two_player_adventure(rdram, ctx);
        goto after_17;
    // 0x80099998: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_17:
    // 0x8009999C: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800999A0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800999A4: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800999A8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800999AC: bne         $v0, $zero, L_800999B8
    if (ctx->r2 != 0) {
        // 0x800999B0: addiu       $t2, $t2, 0x69D8
        ctx->r10 = ADD32(ctx->r10, 0X69D8);
            goto L_800999B8;
    }
    // 0x800999B0: addiu       $t2, $t2, 0x69D8
    ctx->r10 = ADD32(ctx->r10, 0X69D8);
    // 0x800999B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800999B8:
    // 0x800999B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800999BC: addu        $t9, $t2, $v1
    ctx->r25 = ADD32(ctx->r10, ctx->r3);
    // 0x800999C0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800999C4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800999C8: lw          $t5, -0x5C8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5C8);
    // 0x800999CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800999D0: bne         $t5, $at, L_80099A04
    if (ctx->r13 != ctx->r1) {
        // 0x800999D4: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80099A04;
    }
    // 0x800999D4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800999D8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x800999DC: bne         $at, $zero, L_800999FC
    if (ctx->r1 != 0) {
        // 0x800999E0: addiu       $t6, $zero, 0x105
        ctx->r14 = ADD32(0, 0X105);
            goto L_800999FC;
    }
    // 0x800999E0: addiu       $t6, $zero, 0x105
    ctx->r14 = ADD32(0, 0X105);
    // 0x800999E4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x800999E8: jal         0x80081820
    // 0x800999EC: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    menu_init(rdram, ctx);
        goto after_18;
    // 0x800999EC: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_18:
    // 0x800999F0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800999F4: b           L_80099AC4
    // 0x800999F8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
        goto L_80099AC4;
    // 0x800999F8: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
L_800999FC:
    // 0x800999FC: b           L_80099AC0
    // 0x80099A00: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
        goto L_80099AC0;
    // 0x80099A00: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
L_80099A04:
    // 0x80099A04: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80099A08: lbu         $a0, 0x48($t3)
    ctx->r4 = MEM_BU(ctx->r11, 0X48);
    // 0x80099A0C: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80099A10: jal         0x8006B414
    // 0x80099A14: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    level_world_id(rdram, ctx);
        goto after_19;
    // 0x80099A14: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    after_19:
    // 0x80099A18: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80099A1C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80099A20: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099A24: addiu       $v1, $v1, -0x630
    ctx->r3 = ADD32(ctx->r3, -0X630);
    // 0x80099A28: sb          $v0, 0x49($t3)
    MEM_B(0X49, ctx->r11) = ctx->r2;
    // 0x80099A2C: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x80099A30: nop

    // 0x80099A34: beq         $t8, $zero, L_80099AC4
    if (ctx->r24 == 0) {
        // 0x80099A38: slti        $at, $t4, 0x3
        ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
            goto L_80099AC4;
    }
    // 0x80099A38: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80099A3C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x80099A40: lbu         $t9, 0x49($t3)
    ctx->r25 = MEM_BU(ctx->r11, 0X49);
    // 0x80099A44: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
    // 0x80099A48: ori         $t5, $t9, 0x200
    ctx->r13 = ctx->r25 | 0X200;
    // 0x80099A4C: beq         $at, $zero, L_80099AC0
    if (ctx->r1 == 0) {
        // 0x80099A50: sw          $t5, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r13;
            goto L_80099AC0;
    }
    // 0x80099A50: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
    // 0x80099A54: lbu         $a1, 0x48($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0X48);
    // 0x80099A58: lhu         $a0, 0xE($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0XE);
    // 0x80099A5C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80099A60: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80099A64: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80099A68: subu        $v0, $t8, $t4
    ctx->r2 = SUB32(ctx->r24, ctx->r12);
    // 0x80099A6C: srav        $v1, $a0, $t6
    ctx->r3 = S32(SIGNED(ctx->r4) >> (ctx->r14 & 31));
    // 0x80099A70: andi        $t7, $v1, 0x3
    ctx->r15 = ctx->r3 & 0X3;
    // 0x80099A74: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x80099A78: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80099A7C: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80099A80: beq         $at, $zero, L_80099AC0
    if (ctx->r1 == 0) {
        // 0x80099A84: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_80099AC0;
    }
    // 0x80099A84: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80099A88: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80099A8C: sllv        $t6, $t5, $t6
    ctx->r14 = S32(ctx->r13 << (ctx->r14 & 31));
    // 0x80099A90: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x80099A94: and         $t9, $a0, $t7
    ctx->r25 = ctx->r4 & ctx->r15;
    // 0x80099A98: sllv        $t5, $v0, $a1
    ctx->r13 = S32(ctx->r2 << (ctx->r5 & 31));
    // 0x80099A9C: sh          $t9, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r25;
    // 0x80099AA0: or          $t6, $t9, $t5
    ctx->r14 = ctx->r25 | ctx->r13;
    // 0x80099AA4: sh          $t6, 0xE($t3)
    MEM_H(0XE, ctx->r11) = ctx->r14;
    // 0x80099AA8: jal         0x8009C6E4
    // 0x80099AAC: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    get_save_file_index(rdram, ctx);
        goto after_20;
    // 0x80099AAC: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_20:
    // 0x80099AB0: jal         0x8006EE88
    // 0x80099AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_21;
    // 0x80099AB4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_21:
    // 0x80099AB8: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099ABC: nop

L_80099AC0:
    // 0x80099AC0: slti        $at, $t4, 0x3
    ctx->r1 = SIGNED(ctx->r12) < 0X3 ? 1 : 0;
L_80099AC4:
    // 0x80099AC4: beq         $at, $zero, L_80099B1C
    if (ctx->r1 == 0) {
        // 0x80099AC8: addiu       $a0, $zero, 0x1F
        ctx->r4 = ADD32(0, 0X1F);
            goto L_80099B1C;
    }
    // 0x80099AC8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80099ACC: jal         0x8001E2D0
    // 0x80099AD0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    get_misc_asset(rdram, ctx);
        goto after_22;
    // 0x80099AD0: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    after_22:
    // 0x80099AD4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80099AD8: lw          $t7, 0x1568($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1568);
    // 0x80099ADC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80099AE0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80099AE4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099AE8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80099AEC: addiu       $t2, $t2, 0x69D8
    ctx->r10 = ADD32(ctx->r10, 0X69D8);
    // 0x80099AF0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80099AF4: addu        $a1, $t8, $t4
    ctx->r5 = ADD32(ctx->r24, ctx->r12);
    // 0x80099AF8: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x80099AFC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80099B00: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80099B04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80099B08: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80099B0C: jal         0x8009B114
    // 0x80099B10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    cinematic_start(rdram, ctx);
        goto after_23;
    // 0x80099B10: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_23:
    // 0x80099B14: jal         0x80081820
    // 0x80099B18: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    menu_init(rdram, ctx);
        goto after_24;
    // 0x80099B18: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_24:
L_80099B1C:
    // 0x80099B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80099B20: sw          $zero, 0x1568($at)
    MEM_W(0X1568, ctx->r1) = 0;
L_80099B24:
    // 0x80099B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80099B28:
    // 0x80099B28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099B2C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80099B30: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80099B34: jr          $ra
    // 0x80099B38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80099B38: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void void_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002585C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80025860: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025864: lw          $t6, -0x260C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X260C);
    // 0x80025868: sll         $t7, $a2, 4
    ctx->r15 = S32(ctx->r6 << 4);
    // 0x8002586C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80025870: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80025874: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80025878: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8002587C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80025880: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80025884: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80025888: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x8002588C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80025890: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80025894: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80025898: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002589C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800258A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800258A4: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800258A8: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800258AC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800258B0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800258B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800258B8: addiu       $v1, $v1, -0x25F0
    ctx->r3 = ADD32(ctx->r3, -0X25F0);
    // 0x800258BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800258C0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800258C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800258C8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800258CC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800258D0: addiu       $t0, $t0, -0x2600
    ctx->r8 = ADD32(ctx->r8, -0X2600);
    // 0x800258D4: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800258D8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800258DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800258E0: addiu       $a0, $a0, -0x49E0
    ctx->r4 = ADD32(ctx->r4, -0X49E0);
    // 0x800258E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800258E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800258EC: jal         0x8007B918
    // 0x800258F0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800258F0: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    after_0:
    // 0x800258F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800258F8: sh          $zero, -0x25E4($at)
    MEM_H(-0X25E4, ctx->r1) = 0;
    // 0x800258FC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80025900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025904: addiu       $s0, $s0, -0x49D0
    ctx->r16 = ADD32(ctx->r16, -0X49D0);
    // 0x80025908: sh          $zero, -0x25E2($at)
    MEM_H(-0X25E2, ctx->r1) = 0;
    // 0x8002590C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80025910: nop

    // 0x80025914: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x80025918: nop

    // 0x8002591C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80025920: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80025924: jal         0x80070A04
    // 0x80025928: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x80025928: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x8002592C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80025930: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x80025934: lh          $a0, 0x0($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X0);
    // 0x80025938: nop

    // 0x8002593C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x80025940: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80025944: jal         0x80070A38
    // 0x80025948: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x80025948: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_2:
    // 0x8002594C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025950: lwc1        $f15, 0x63F0($at)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r1, 0X63F0);
    // 0x80025954: lwc1        $f14, 0x63F4($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X63F4);
    // 0x80025958: cvt.d.s     $f8, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f8.d = CVT_D_S(ctx->f26.fl);
    // 0x8002595C: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80025960: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80025964: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80025968: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002596C: addiu       $v1, $v1, -0x25D4
    ctx->r3 = ADD32(ctx->r3, -0X25D4);
    // 0x80025970: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025974: add.d       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f6.d + ctx->f10.d;
    // 0x80025978: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002597C: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x80025980: addiu       $a0, $a0, -0x25D0
    ctx->r4 = ADD32(ctx->r4, -0X25D0);
    // 0x80025984: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80025988: mul.d       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8002598C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x80025990: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80025994: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80025998: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002599C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800259A0: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800259A4: addiu       $a1, $a1, -0x25E0
    ctx->r5 = ADD32(ctx->r5, -0X25E0);
    // 0x800259A8: cvt.s.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f18.fl = CVT_S_D(ctx->f16.d);
    // 0x800259AC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800259B0: mul.s       $f4, $f26, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800259B4: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800259B8: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800259BC: addiu       $a2, $a2, -0x25DC
    ctx->r6 = ADD32(ctx->r6, -0X25DC);
    // 0x800259C0: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800259C4: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800259C8: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x800259CC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800259D0: swc1        $f26, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f26.u32l;
    // 0x800259D4: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800259D8: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800259DC: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x800259E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800259E4: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800259E8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800259EC: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800259F0: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x800259F4: neg.s       $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = -ctx->f22.fl;
    // 0x800259F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800259FC: add.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x80025A00: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x80025A04: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80025A08: blez        $t2, L_80025BB0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80025A0C: swc1        $f8, -0x25D8($at)
        MEM_W(-0X25D8, ctx->r1) = ctx->f8.u32l;
            goto L_80025BB0;
    }
    // 0x80025A0C: swc1        $f8, -0x25D8($at)
    MEM_W(-0X25D8, ctx->r1) = ctx->f8.u32l;
    // 0x80025A10: mtc1        $zero, $f21
    ctx->f_odd[(21 - 1) * 2] = 0;
    // 0x80025A14: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80025A18: addiu       $s3, $zero, 0x44
    ctx->r19 = ADD32(0, 0X44);
    // 0x80025A1C: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_80025A20:
    // 0x80025A20: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x80025A24: addu        $s1, $s2, $t3
    ctx->r17 = ADD32(ctx->r18, ctx->r11);
    // 0x80025A28: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80025A2C: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80025A30: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80025A34: subu        $t4, $t4, $v0
    ctx->r12 = SUB32(ctx->r12, ctx->r2);
    // 0x80025A38: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80025A3C: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x80025A40: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80025A44: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x80025A48: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025A4C: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80025A50: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025A54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025A58: mul.s       $f0, $f18, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f26.fl);
    // 0x80025A5C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025A60: mul.s       $f2, $f24, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80025A64: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80025A68: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80025A6C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80025A70: c.le.d      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.d <= ctx->f20.d;
    // 0x80025A74: nop

    // 0x80025A78: bc1f        L_80025A84
    if (!c1cs) {
        // 0x80025A7C: nop
    
            goto L_80025A84;
    }
    // 0x80025A7C: nop

    // 0x80025A80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025A84:
    // 0x80025A84: lh          $t2, 0x6($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X6);
    // 0x80025A88: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025A8C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80025A90: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025A94: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80025A98: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80025A9C: mul.s       $f12, $f26, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f26.fl, ctx->f16.fl);
    // 0x80025AA0: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80025AA4: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80025AA8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80025AAC: c.le.d      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.d <= ctx->f20.d;
    // 0x80025AB0: nop

    // 0x80025AB4: bc1f        L_80025AC0
    if (!c1cs) {
        // 0x80025AB8: nop
    
            goto L_80025AC0;
    }
    // 0x80025AB8: nop

    // 0x80025ABC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_80025AC0:
    // 0x80025AC0: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x80025AC4: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x80025AC8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80025ACC: sll         $t4, $a2, 16
    ctx->r12 = S32(ctx->r6 << 16);
    // 0x80025AD0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80025AD4: sra         $a2, $t4, 16
    ctx->r6 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025AD8: or          $t7, $zero, $zero
    ctx->r15 = 0 | 0;
    // 0x80025ADC: mul.s       $f14, $f24, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = MUL_S(ctx->f24.fl, ctx->f18.fl);
    // 0x80025AE0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80025AE4: add.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80025AE8: add.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80025AEC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80025AF0: c.le.d      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.d <= ctx->f20.d;
    // 0x80025AF4: add.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80025AF8: bc1f        L_80025B04
    if (!c1cs) {
        // 0x80025AFC: add.s       $f10, $f8, $f22
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
            goto L_80025B04;
    }
    // 0x80025AFC: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80025B00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80025B04:
    // 0x80025B04: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x80025B08: c.le.d      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.d <= ctx->f20.d;
    // 0x80025B0C: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x80025B10: sll         $t8, $a2, 16
    ctx->r24 = S32(ctx->r6 << 16);
    // 0x80025B14: bc1f        L_80025B20
    if (!c1cs) {
        // 0x80025B18: sra         $a2, $t8, 16
        ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80025B20;
    }
    // 0x80025B18: sra         $a2, $t8, 16
    ctx->r6 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025B1C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80025B20:
    // 0x80025B20: addu        $t4, $a2, $t2
    ctx->r12 = ADD32(ctx->r6, ctx->r10);
    // 0x80025B24: andi        $t5, $t4, 0x3
    ctx->r13 = ctx->r12 & 0X3;
    // 0x80025B28: beq         $t5, $zero, L_80025B94
    if (ctx->r13 == 0) {
        // 0x80025B2C: nop
    
            goto L_80025B94;
    }
    // 0x80025B2C: nop

    // 0x80025B30: multu       $v0, $s3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025B34: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80025B38: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025B3C: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B40: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B44: mflo        $t6
    ctx->r14 = lo;
    // 0x80025B48: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80025B4C: jal         0x80026470
    // 0x80025B50: nop

    func_80026430(rdram, ctx);
        goto after_3;
    // 0x80025B50: nop

    after_3:
    // 0x80025B54: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x80025B58: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025B5C: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80025B60: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80025B64: mflo        $t3
    ctx->r11 = lo;
    // 0x80025B68: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80025B6C: lw          $t5, 0x3C($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X3C);
    // 0x80025B70: nop

    // 0x80025B74: andi        $t6, $t5, 0x2
    ctx->r14 = ctx->r13 & 0X2;
    // 0x80025B78: beq         $t6, $zero, L_80025B94
    if (ctx->r14 == 0) {
        // 0x80025B7C: nop
    
            goto L_80025B94;
    }
    // 0x80025B7C: nop

    // 0x80025B80: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x80025B84: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x80025B88: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x80025B8C: jal         0x800260B0
    // 0x80025B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80026070(rdram, ctx);
        goto after_4;
    // 0x80025B90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80025B94:
    // 0x80025B94: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025B98: lw          $t2, 0xC4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XC4);
    // 0x80025B9C: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80025BA0: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80025BA4: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80025BA8: bne         $at, $zero, L_80025A20
    if (ctx->r1 != 0) {
        // 0x80025BAC: lw          $t3, 0xC0($sp)
        ctx->r11 = MEM_W(ctx->r29, 0XC0);
            goto L_80025A20;
    }
    // 0x80025BAC: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
L_80025BB0:
    // 0x80025BB0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80025BB4: addiu       $s4, $s4, -0x3178
    ctx->r20 = ADD32(ctx->r20, -0X3178);
    // 0x80025BB8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80025BBC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025BC0: lh          $a1, 0x40($t9)
    ctx->r5 = MEM_H(ctx->r25, 0X40);
    // 0x80025BC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025BC8: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025BCC: sll         $t3, $a1, 16
    ctx->r11 = S32(ctx->r5 << 16);
    // 0x80025BD0: jal         0x80026C54
    // 0x80025BD4: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    func_80026C14(rdram, ctx);
        goto after_5;
    // 0x80025BD4: sra         $a1, $t3, 16
    ctx->r5 = S32(SIGNED(ctx->r11) >> 16);
    after_5:
    // 0x80025BD8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80025BDC: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025BE0: lh          $a1, 0x40($t5)
    ctx->r5 = MEM_H(ctx->r13, 0X40);
    // 0x80025BE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80025BE8: addiu       $a1, $a1, -0xC3
    ctx->r5 = ADD32(ctx->r5, -0XC3);
    // 0x80025BEC: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80025BF0: jal         0x80026C54
    // 0x80025BF4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    func_80026C14(rdram, ctx);
        goto after_6;
    // 0x80025BF4: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    after_6:
    // 0x80025BF8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80025BFC: addiu       $a0, $zero, 0x12C
    ctx->r4 = ADD32(0, 0X12C);
    // 0x80025C00: lh          $a1, 0x42($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X42);
    // 0x80025C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025C08: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025C0C: sll         $t2, $a1, 16
    ctx->r10 = S32(ctx->r5 << 16);
    // 0x80025C10: jal         0x80026C54
    // 0x80025C14: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    func_80026C14(rdram, ctx);
        goto after_7;
    // 0x80025C14: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_7:
    // 0x80025C18: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80025C1C: addiu       $a0, $zero, -0x12C
    ctx->r4 = ADD32(0, -0X12C);
    // 0x80025C20: lh          $a1, 0x42($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X42);
    // 0x80025C24: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025C28: addiu       $a1, $a1, 0xC3
    ctx->r5 = ADD32(ctx->r5, 0XC3);
    // 0x80025C2C: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80025C30: jal         0x80026C54
    // 0x80025C34: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    func_80026C14(rdram, ctx);
        goto after_8;
    // 0x80025C34: sra         $a1, $t4, 16
    ctx->r5 = S32(SIGNED(ctx->r12) >> 16);
    after_8:
    // 0x80025C38: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80025C3C: addiu       $t1, $t1, -0x25E2
    ctx->r9 = ADD32(ctx->r9, -0X25E2);
    // 0x80025C40: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025C44: lh          $t6, -0x25C6($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X25C6);
    // 0x80025C48: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025C4C: nop

    // 0x80025C50: slt         $at, $a3, $t6
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80025C54: beq         $at, $zero, L_80026074
    if (ctx->r1 == 0) {
        // 0x80025C58: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80026074;
    }
    // 0x80025C58: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80025C5C: beq         $a3, $zero, L_80026070
    if (ctx->r7 == 0) {
        // 0x80025C60: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80026070;
    }
    // 0x80025C60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80025C64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025C68: addiu       $t0, $t0, -0x2608
    ctx->r8 = ADD32(ctx->r8, -0X2608);
    // 0x80025C6C: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025C70:
    // 0x80025C70: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025C74: blez        $a1, L_80025CE0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80025C78: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80025CE0;
    }
    // 0x80025C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80025C7C:
    // 0x80025C7C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025C80: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025C84: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025C88: lh          $t2, 0x8($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X8);
    // 0x80025C8C: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80025C90: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025C94: slt         $at, $t2, $t9
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80025C98: beq         $at, $zero, L_80025CCC
    if (ctx->r1 == 0) {
        // 0x80025C9C: sll         $t5, $s2, 16
        ctx->r13 = S32(ctx->r18 << 16);
            goto L_80025CCC;
    }
    // 0x80025C9C: sll         $t5, $s2, 16
    ctx->r13 = S32(ctx->r18 << 16);
    // 0x80025CA0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80025CA4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80025CA8: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80025CAC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80025CB0: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x80025CB4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80025CB8: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x80025CBC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80025CC0: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025CC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80025CC8: addiu       $a1, $a3, -0x1
    ctx->r5 = ADD32(ctx->r7, -0X1);
L_80025CCC:
    // 0x80025CCC: sra         $s2, $t5, 16
    ctx->r18 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80025CD0: slt         $at, $s2, $a1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80025CD4: bne         $at, $zero, L_80025C7C
    if (ctx->r1 != 0) {
        // 0x80025CD8: addiu       $v0, $v0, 0x8
        ctx->r2 = ADD32(ctx->r2, 0X8);
            goto L_80025C7C;
    }
    // 0x80025CD8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80025CDC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025CE0:
    // 0x80025CE0: beq         $a2, $zero, L_80025C70
    if (ctx->r6 == 0) {
        // 0x80025CE4: nop
    
            goto L_80025C70;
    }
    // 0x80025CE4: nop

    // 0x80025CE8: blez        $a3, L_80025D74
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025CEC: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80025D74;
    }
    // 0x80025CEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80025CF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025CF4: addiu       $a1, $a1, -0x2604
    ctx->r5 = ADD32(ctx->r5, -0X2604);
    // 0x80025CF8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80025CFC:
    // 0x80025CFC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80025D00: sll         $t8, $s2, 3
    ctx->r24 = S32(ctx->r18 << 3);
    // 0x80025D04: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80025D08: lb          $t2, 0x7($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X7);
    // 0x80025D0C: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x80025D10: sll         $t9, $t2, 17
    ctx->r25 = S32(ctx->r10 << 17);
    // 0x80025D14: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025D18: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x80025D1C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x80025D20: nop

    // 0x80025D24: bne         $a2, $t5, L_80025D50
    if (ctx->r6 != ctx->r13) {
        // 0x80025D28: nop
    
            goto L_80025D50;
    }
    // 0x80025D28: nop

    // 0x80025D2C: lb          $t6, 0x6($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6);
    // 0x80025D30: nop

    // 0x80025D34: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80025D38: sb          $t7, 0x6($a0)
    MEM_B(0X6, ctx->r4) = ctx->r15;
    // 0x80025D3C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80025D40: nop

    // 0x80025D44: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x80025D48: b           L_80025D54
    // 0x80025D4C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
        goto L_80025D54;
    // 0x80025D4C: sb          $s2, 0x0($t2)
    MEM_B(0X0, ctx->r10) = ctx->r18;
L_80025D50:
    // 0x80025D50: sb          $s2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r18;
L_80025D54:
    // 0x80025D54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025D58: lh          $a3, 0x0($t1)
    ctx->r7 = MEM_H(ctx->r9, 0X0);
    // 0x80025D5C: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x80025D60: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80025D64: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025D68: bne         $at, $zero, L_80025CFC
    if (ctx->r1 != 0) {
        // 0x80025D6C: nop
    
            goto L_80025CFC;
    }
    // 0x80025D6C: nop

    // 0x80025D70: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_80025D74:
    // 0x80025D74: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80025D78: addiu       $a0, $a0, -0x25CC
    ctx->r4 = ADD32(ctx->r4, -0X25CC);
    // 0x80025D7C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x80025D80: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025D84: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80025D88: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80025D8C: addu        $t8, $t8, $v1
    ctx->r24 = ADD32(ctx->r24, ctx->r3);
    // 0x80025D90: lw          $t8, -0x2600($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2600);
    // 0x80025D94: lh          $s3, 0x0($t4)
    ctx->r19 = MEM_H(ctx->r12, 0X0);
    // 0x80025D98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80025D9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025DA0: lw          $t6, -0x49D8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X49D8);
    // 0x80025DA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DA8: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80025DAC: lw          $t2, -0x25F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X25F0);
    // 0x80025DB0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80025DB4: sw          $t8, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r24;
    // 0x80025DB8: lw          $t7, -0x49D4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X49D4);
    // 0x80025DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80025DC4: subu        $t3, $t9, $v0
    ctx->r11 = SUB32(ctx->r25, ctx->r2);
    // 0x80025DC8: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025DCC: sw          $t2, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r10;
    // 0x80025DD0: sra         $t5, $s4, 16
    ctx->r13 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025DD4: sb          $t3, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r11;
    // 0x80025DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025DDC: lw          $t4, -0x49D8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X49D8);
    // 0x80025DE0: or          $s4, $t5, $zero
    ctx->r20 = ctx->r13 | 0;
    // 0x80025DE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80025DEC: lw          $t5, -0x49D4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X49D4);
    // 0x80025DF0: sw          $t4, -0x25F8($at)
    MEM_W(-0X25F8, ctx->r1) = ctx->r12;
    // 0x80025DF4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025DF8: sw          $t5, -0x25E8($at)
    MEM_W(-0X25E8, ctx->r1) = ctx->r13;
    // 0x80025DFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025E00: sh          $zero, -0x25CA($at)
    MEM_H(-0X25CA, ctx->r1) = 0;
    // 0x80025E04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80025E08: sh          $zero, -0x25C8($at)
    MEM_H(-0X25C8, ctx->r1) = 0;
    // 0x80025E0C: sw          $t6, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r14;
    // 0x80025E10: blez        $a3, L_80025F84
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80025E14: sw          $t7, 0xA8($sp)
        MEM_W(0XA8, ctx->r29) = ctx->r15;
            goto L_80025F84;
    }
    // 0x80025E14: sw          $t7, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r15;
    // 0x80025E18: addiu       $s1, $sp, 0x7C
    ctx->r17 = ADD32(ctx->r29, 0X7C);
    // 0x80025E1C: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025E20:
    // 0x80025E20: beq         $at, $zero, L_80025F0C
    if (ctx->r1 == 0) {
        // 0x80025E24: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F0C;
    }
    // 0x80025E24: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025E28: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80025E2C: sll         $t6, $s2, 3
    ctx->r14 = S32(ctx->r18 << 3);
    // 0x80025E30: addu        $a0, $a1, $t6
    ctx->r4 = ADD32(ctx->r5, ctx->r14);
    // 0x80025E34: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80025E38: nop

    // 0x80025E3C: bne         $s4, $t7, L_80025F0C
    if (ctx->r20 != ctx->r15) {
        // 0x80025E40: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F0C;
    }
    // 0x80025E40: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025E44:
    // 0x80025E44: lb          $t8, 0x6($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X6);
    // 0x80025E48: addu        $t3, $s1, $s0
    ctx->r11 = ADD32(ctx->r17, ctx->r16);
    // 0x80025E4C: andi        $t2, $t8, 0x2
    ctx->r10 = ctx->r24 & 0X2;
    // 0x80025E50: beq         $t2, $zero, L_80025E70
    if (ctx->r10 == 0) {
        // 0x80025E54: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80025E70;
    }
    // 0x80025E54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80025E58: lb          $t9, 0x7($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X7);
    // 0x80025E5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80025E60: sll         $t4, $s0, 16
    ctx->r12 = S32(ctx->r16 << 16);
    // 0x80025E64: sra         $s0, $t4, 16
    ctx->r16 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025E68: b           L_80025EDC
    // 0x80025E6C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
        goto L_80025EDC;
    // 0x80025E6C: sb          $t9, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r25;
L_80025E70:
    // 0x80025E70: blez        $s0, L_80025EDC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80025E74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80025EDC;
    }
    // 0x80025E74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80025E78: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025E7C:
    // 0x80025E7C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x80025E80: lb          $t8, 0x7($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X7);
    // 0x80025E84: nop

    // 0x80025E88: bne         $t7, $t8, L_80025EC4
    if (ctx->r15 != ctx->r24) {
        // 0x80025E8C: nop
    
            goto L_80025EC4;
    }
    // 0x80025E8C: nop

    // 0x80025E90: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80025E94: sll         $t2, $s0, 16
    ctx->r10 = S32(ctx->r16 << 16);
    // 0x80025E98: sra         $s0, $t2, 16
    ctx->r16 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80025E9C: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025EA0: beq         $at, $zero, L_80025EC4
    if (ctx->r1 == 0) {
        // 0x80025EA4: addu        $v0, $s1, $v1
        ctx->r2 = ADD32(ctx->r17, ctx->r3);
            goto L_80025EC4;
    }
L_80025EA4:
    // 0x80025EA4: addu        $v0, $s1, $v1
    ctx->r2 = ADD32(ctx->r17, ctx->r3);
    // 0x80025EA8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EAC: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x80025EB0: lb          $t3, 0x1($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1);
    // 0x80025EB4: sra         $v1, $t4, 16
    ctx->r3 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80025EB8: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025EBC: bne         $at, $zero, L_80025EA4
    if (ctx->r1 != 0) {
        // 0x80025EC0: sb          $t3, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r11;
            goto L_80025EA4;
    }
    // 0x80025EC0: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80025EC4:
    // 0x80025EC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80025EC8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x80025ECC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80025ED0: slt         $at, $v1, $s0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80025ED4: bne         $at, $zero, L_80025E7C
    if (ctx->r1 != 0) {
        // 0x80025ED8: addu        $t6, $s1, $v1
        ctx->r14 = ADD32(ctx->r17, ctx->r3);
            goto L_80025E7C;
    }
    // 0x80025ED8: addu        $t6, $s1, $v1
    ctx->r14 = ADD32(ctx->r17, ctx->r3);
L_80025EDC:
    // 0x80025EDC: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80025EE0: sra         $t2, $t8, 16
    ctx->r10 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80025EE4: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025EE8: beq         $at, $zero, L_80025F08
    if (ctx->r1 == 0) {
        // 0x80025EEC: or          $s2, $t2, $zero
        ctx->r18 = ctx->r10 | 0;
            goto L_80025F08;
    }
    // 0x80025EEC: or          $s2, $t2, $zero
    ctx->r18 = ctx->r10 | 0;
    // 0x80025EF0: sll         $t9, $t2, 3
    ctx->r25 = S32(ctx->r10 << 3);
    // 0x80025EF4: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
    // 0x80025EF8: lh          $t3, 0x0($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X0);
    // 0x80025EFC: nop

    // 0x80025F00: beq         $s4, $t3, L_80025E44
    if (ctx->r20 == ctx->r11) {
        // 0x80025F04: nop
    
            goto L_80025E44;
    }
    // 0x80025F04: nop

L_80025F08:
    // 0x80025F08: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F0C:
    // 0x80025F0C: beq         $at, $zero, L_80025F7C
    if (ctx->r1 == 0) {
        // 0x80025F10: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F7C;
    }
    // 0x80025F10: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025F14: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80025F18: sll         $t5, $s2, 3
    ctx->r13 = S32(ctx->r18 << 3);
    // 0x80025F1C: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80025F20: lh          $s3, 0x0($t6)
    ctx->r19 = MEM_H(ctx->r14, 0X0);
    // 0x80025F24: nop

    // 0x80025F28: beq         $s4, $s3, L_80025F7C
    if (ctx->r20 == ctx->r19) {
        // 0x80025F2C: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025F7C;
    }
    // 0x80025F2C: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80025F30: mtc1        $s3, $f16
    ctx->f16.u32l = ctx->r19;
    // 0x80025F34: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x80025F38: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80025F3C: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x80025F40: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80025F44: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80025F48: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x80025F4C: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80025F50: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80025F54: jal         0x80026E94
    // 0x80025F58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80026E54(rdram, ctx);
        goto after_9;
    // 0x80025F58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_9:
    // 0x80025F5C: sll         $s4, $s3, 16
    ctx->r20 = S32(ctx->r19 << 16);
    // 0x80025F60: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80025F64: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F68: sra         $t8, $s4, 16
    ctx->r24 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80025F6C: lh          $a3, -0x25E2($a3)
    ctx->r7 = MEM_H(ctx->r7, -0X25E2);
    // 0x80025F70: addiu       $t0, $t0, -0x2608
    ctx->r8 = ADD32(ctx->r8, -0X2608);
    // 0x80025F74: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x80025F78: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F7C:
    // 0x80025F7C: bne         $at, $zero, L_80025E20
    if (ctx->r1 != 0) {
        // 0x80025F80: slt         $at, $s2, $a3
        ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80025E20;
    }
    // 0x80025F80: slt         $at, $s2, $a3
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r7) ? 1 : 0;
L_80025F84:
    // 0x80025F84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80025F88: lh          $a2, -0x25CA($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X25CA);
    // 0x80025F8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80025F90: beq         $a2, $zero, L_80026058
    if (ctx->r6 == 0) {
        // 0x80025F94: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80026058;
    }
    // 0x80025F94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80025F98: addiu       $t0, $t0, -0x49E0
    ctx->r8 = ADD32(ctx->r8, -0X49E0);
    // 0x80025F9C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80025FA0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80025FA4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80025FA8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x80025FAC: lw          $t4, -0x25F8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X25F8);
    // 0x80025FB0: addiu       $t9, $a2, -0x1
    ctx->r25 = ADD32(ctx->r6, -0X1);
    // 0x80025FB4: addu        $t5, $t4, $a3
    ctx->r13 = ADD32(ctx->r12, ctx->r7);
    // 0x80025FB8: andi        $t6, $t5, 0x6
    ctx->r14 = ctx->r13 & 0X6;
    // 0x80025FBC: sll         $t3, $t9, 3
    ctx->r11 = S32(ctx->r25 << 3);
    // 0x80025FC0: or          $t7, $t3, $t6
    ctx->r15 = ctx->r11 | ctx->r14;
    // 0x80025FC4: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80025FC8: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80025FCC: sll         $t3, $t5, 1
    ctx->r11 = S32(ctx->r13 << 1);
    // 0x80025FD0: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80025FD4: sll         $t2, $t8, 16
    ctx->r10 = S32(ctx->r24 << 16);
    // 0x80025FD8: addiu       $t6, $t3, 0x8
    ctx->r14 = ADD32(ctx->r11, 0X8);
    // 0x80025FDC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80025FE0: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x80025FE4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80025FE8: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80025FEC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80025FF0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80025FF4: lw          $t2, -0x25F8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X25F8);
    // 0x80025FF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80025FFC: addu        $t4, $t2, $a3
    ctx->r12 = ADD32(ctx->r10, ctx->r7);
    // 0x80026000: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80026004: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80026008: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002600C: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80026010: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x80026014: lh          $a1, -0x25CA($a1)
    ctx->r5 = MEM_H(ctx->r5, -0X25CA);
    // 0x80026018: nop

    // 0x8002601C: sra         $t3, $a1, 1
    ctx->r11 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80026020: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80026024: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x80026028: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x8002602C: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80026030: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80026034: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80026038: or          $t2, $t8, $at
    ctx->r10 = ctx->r24 | ctx->r1;
    // 0x8002603C: or          $t3, $t2, $t5
    ctx->r11 = ctx->r10 | ctx->r13;
    // 0x80026040: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80026044: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80026048: lw          $t6, -0x25E8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X25E8);
    // 0x8002604C: nop

    // 0x80026050: addu        $t9, $t6, $a3
    ctx->r25 = ADD32(ctx->r14, ctx->r7);
    // 0x80026054: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80026058:
    // 0x80026058: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8002605C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80026060: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80026064: sw          $t7, -0x49D8($at)
    MEM_W(-0X49D8, ctx->r1) = ctx->r15;
    // 0x80026068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002606C: sw          $t8, -0x49D4($at)
    MEM_W(-0X49D4, ctx->r1) = ctx->r24;
L_80026070:
    // 0x80026070: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80026074:
    // 0x80026074: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80026078: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002607C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80026080: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80026084: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80026088: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002608C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80026090: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80026094: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80026098: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8002609C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800260A0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800260A4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800260A8: jr          $ra
    // 0x800260AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x800260AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void init_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C2F18: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C2F1C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C2F20: jal         0x80070EDC
    // 0x800C2F24: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C2F24: addiu       $a0, $zero, 0x780
    ctx->r4 = ADD32(0, 0X780);
    after_0:
    // 0x800C2F28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C2F2C: addiu       $v1, $v1, -0x5278
    ctx->r3 = ADD32(ctx->r3, -0X5278);
    // 0x800C2F30: addiu       $t7, $v0, 0x3C0
    ctx->r15 = ADD32(ctx->r2, 0X3C0);
    // 0x800C2F34: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C2F38: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800C2F3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F40: sw          $zero, -0x526C($at)
    MEM_W(-0X526C, ctx->r1) = 0;
    // 0x800C2F44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F48: sh          $zero, -0x528A($at)
    MEM_H(-0X528A, ctx->r1) = 0;
    // 0x800C2F4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F50: sh          $zero, -0x5298($at)
    MEM_H(-0X5298, ctx->r1) = 0;
    // 0x800C2F54: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x800C2F58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F5C: sh          $a0, -0x5296($at)
    MEM_H(-0X5296, ctx->r1) = ctx->r4;
    // 0x800C2F60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F64: sh          $zero, -0x5286($at)
    MEM_H(-0X5286, ctx->r1) = 0;
    // 0x800C2F68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F6C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800C2F70: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800C2F74: sh          $a0, -0x5292($at)
    MEM_H(-0X5292, ctx->r1) = ctx->r4;
    // 0x800C2F78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F7C: addiu       $t8, $zero, 0x120
    ctx->r24 = ADD32(0, 0X120);
    // 0x800C2F80: bne         $t9, $zero, L_800C2FA4
    if (ctx->r25 != 0) {
        // 0x800C2F84: sh          $t8, -0x528E($at)
        MEM_H(-0X528E, ctx->r1) = ctx->r24;
            goto L_800C2FA4;
    }
    // 0x800C2F84: sh          $t8, -0x528E($at)
    MEM_H(-0X528E, ctx->r1) = ctx->r24;
    // 0x800C2F88: addiu       $t0, $zero, 0xE0
    ctx->r8 = ADD32(0, 0XE0);
    // 0x800C2F8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F90: sh          $t0, -0x5290($at)
    MEM_H(-0X5290, ctx->r1) = ctx->r8;
    // 0x800C2F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2F98: addiu       $t1, $zero, 0xF8
    ctx->r9 = ADD32(0, 0XF8);
    // 0x800C2F9C: b           L_800C2FBC
    // 0x800C2FA0: sh          $t1, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r9;
        goto L_800C2FBC;
    // 0x800C2FA0: sh          $t1, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r9;
L_800C2FA4:
    // 0x800C2FA4: addiu       $t2, $zero, 0xCA
    ctx->r10 = ADD32(0, 0XCA);
    // 0x800C2FA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FAC: sh          $t2, -0x5290($at)
    MEM_H(-0X5290, ctx->r1) = ctx->r10;
    // 0x800C2FB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2FB4: addiu       $t3, $zero, 0xDE
    ctx->r11 = ADD32(0, 0XDE);
    // 0x800C2FB8: sh          $t3, -0x528C($at)
    MEM_H(-0X528C, ctx->r1) = ctx->r11;
L_800C2FBC:
    // 0x800C2FBC: jal         0x800C5C30
    // 0x800C2FC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_1;
    // 0x800C2FC0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_1:
    // 0x800C2FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C2FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C2FCC: jr          $ra
    // 0x800C2FD0: nop

    return;
    // 0x800C2FD0: nop

;}
RECOMP_FUNC void func_8007CA68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CEB8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007CEBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007CEC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007CEC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8007CEC8: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8007CECC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8007CED0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007CED4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8007CED8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8007CEDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8007CEE0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007CEE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8007CEE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007CEEC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8007CEF0: bltz        $a0, L_8007CF10
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007CEF4: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_8007CF10;
    }
    // 0x8007CEF4: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8007CEF8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007CEFC: lw          $t6, 0x68F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F4);
    // 0x8007CF00: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8007CF04: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007CF08: bne         $at, $zero, L_8007CF28
    if (ctx->r1 != 0) {
        // 0x8007CF0C: sll         $t0, $s0, 2
        ctx->r8 = S32(ctx->r16 << 2);
            goto L_8007CF28;
    }
    // 0x8007CF0C: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
L_8007CF10:
    // 0x8007CF10: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007CF14: nop

    // 0x8007CF18: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8007CF1C: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CF20: b           L_8007D0D0
    // 0x8007CF24: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
        goto L_8007D0D0;
    // 0x8007CF24: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
L_8007CF28:
    // 0x8007CF28: lw          $t9, 0x68E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X68E8);
    // 0x8007CF2C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007CF30: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8007CF34: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007CF38: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8007CF3C: lw          $s2, 0x68F0($s2)
    ctx->r18 = MEM_W(ctx->r18, 0X68F0);
    // 0x8007CF40: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8007CF44: subu        $a3, $t1, $a2
    ctx->r7 = SUB32(ctx->r9, ctx->r6);
    // 0x8007CF48: jal         0x80077190
    // 0x8007CF4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007CF4C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x8007CF50: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007CF54: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CF58: slt         $at, $t2, $s1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007CF5C: beq         $at, $zero, L_8007CF84
    if (ctx->r1 == 0) {
        // 0x8007CF60: addu        $fp, $s2, $s1
        ctx->r30 = ADD32(ctx->r18, ctx->r17);
            goto L_8007CF84;
    }
    // 0x8007CF60: addu        $fp, $s2, $s1
    ctx->r30 = ADD32(ctx->r18, ctx->r17);
L_8007CF64:
    // 0x8007CF64: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CF68:
    // 0x8007CF68: nop

    // 0x8007CF6C: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8007CF70: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8007CF74: nop

    // 0x8007CF78: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
    // 0x8007CF7C: b           L_8007D0D0
    // 0x8007CF80: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
        goto L_8007D0D0;
    // 0x8007CF80: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
L_8007CF84:
    // 0x8007CF84: lbu         $t5, 0xC($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CF88: lh          $t6, 0x0($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X0);
    // 0x8007CF8C: jal         0x8007B2C4
    // 0x8007CF90: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x8007CF90: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_1:
    // 0x8007CF94: bne         $v0, $zero, L_8007CFA8
    if (ctx->r2 != 0) {
        // 0x8007CF98: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CFA8;
    }
    // 0x8007CF98: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007CF9C: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CFA0: b           L_8007CF68
    // 0x8007CFA4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
        goto L_8007CF68;
    // 0x8007CFA4: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_8007CFA8:
    // 0x8007CFA8: lbu         $t7, 0xC($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CFAC: lh          $t8, 0x0($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X0);
    // 0x8007CFB0: jal         0x8007C9CC
    // 0x8007CFB4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    tex_asset_size(rdram, ctx);
        goto after_2;
    // 0x8007CFB4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8007CFB8: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8007CFBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007CFC0: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x8007CFC4: lh          $t0, 0x4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X4);
    // 0x8007CFC8: lb          $t9, 0x3($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X3);
    // 0x8007CFCC: lb          $t2, 0x4($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X4);
    // 0x8007CFD0: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8007CFD4: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007CFD8: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007CFDC: subu        $s3, $t9, $t0
    ctx->r19 = SUB32(ctx->r25, ctx->r8);
    // 0x8007CFE0: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8007CFE4: addu        $s5, $s3, $a1
    ctx->r21 = ADD32(ctx->r19, ctx->r5);
    // 0x8007CFE8: jal         0x8007B70C
    // 0x8007CFEC: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    tex_free(rdram, ctx);
        goto after_3;
    // 0x8007CFEC: subu        $s6, $s4, $a2
    ctx->r22 = SUB32(ctx->r20, ctx->r6);
    after_3:
    // 0x8007CFF0: lbu         $s1, 0xC($fp)
    ctx->r17 = MEM_BU(ctx->r30, 0XC);
    // 0x8007CFF4: lbu         $t3, 0xD($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0XD);
    // 0x8007CFF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007CFFC: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007D000: beq         $at, $zero, L_8007D0BC
    if (ctx->r1 == 0) {
        // 0x8007D004: lw          $t4, 0x48($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X48);
            goto L_8007D0BC;
    }
    // 0x8007D004: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007D008:
    // 0x8007D008: lh          $t4, 0x0($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X0);
    // 0x8007D00C: jal         0x8007B2C4
    // 0x8007D010: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    load_texture(rdram, ctx);
        goto after_4;
    // 0x8007D010: addu        $a0, $t4, $s1
    ctx->r4 = ADD32(ctx->r12, ctx->r17);
    after_4:
    // 0x8007D014: beq         $v0, $zero, L_8007CF64
    if (ctx->r2 == 0) {
        // 0x8007D018: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8007CF64;
    }
    // 0x8007D018: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8007D01C: lh          $t5, 0x0($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X0);
    // 0x8007D020: jal         0x8007C9CC
    // 0x8007D024: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    tex_asset_size(rdram, ctx);
        goto after_5;
    // 0x8007D024: addu        $a0, $t5, $s1
    ctx->r4 = ADD32(ctx->r13, ctx->r17);
    after_5:
    // 0x8007D028: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8007D02C: nop

    // 0x8007D030: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8007D034: sw          $t7, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r15;
    // 0x8007D038: lh          $t9, 0x4($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X4);
    // 0x8007D03C: lb          $t8, 0x3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X3);
    // 0x8007D040: lb          $t1, 0x4($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X4);
    // 0x8007D044: lh          $t0, 0x6($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X6);
    // 0x8007D048: subu        $v1, $t8, $t9
    ctx->r3 = SUB32(ctx->r24, ctx->r25);
    // 0x8007D04C: lbu         $a1, 0x0($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X0);
    // 0x8007D050: lbu         $a2, 0x1($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X1);
    // 0x8007D054: slt         $at, $v1, $s3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8007D058: beq         $at, $zero, L_8007D064
    if (ctx->r1 == 0) {
        // 0x8007D05C: subu        $a0, $t0, $t1
        ctx->r4 = SUB32(ctx->r8, ctx->r9);
            goto L_8007D064;
    }
    // 0x8007D05C: subu        $a0, $t0, $t1
    ctx->r4 = SUB32(ctx->r8, ctx->r9);
    // 0x8007D060: or          $s3, $v1, $zero
    ctx->r19 = ctx->r3 | 0;
L_8007D064:
    // 0x8007D064: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8007D068: slt         $at, $s5, $v0
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007D06C: beq         $at, $zero, L_8007D078
    if (ctx->r1 == 0) {
        // 0x8007D070: nop
    
            goto L_8007D078;
    }
    // 0x8007D070: nop

    // 0x8007D074: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
L_8007D078:
    // 0x8007D078: subu        $v0, $a0, $a2
    ctx->r2 = SUB32(ctx->r4, ctx->r6);
    // 0x8007D07C: slt         $at, $v0, $s6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8007D080: beq         $at, $zero, L_8007D090
    if (ctx->r1 == 0) {
        // 0x8007D084: slt         $at, $s4, $a0
        ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8007D090;
    }
    // 0x8007D084: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007D088: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8007D08C: slt         $at, $s4, $a0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r4) ? 1 : 0;
L_8007D090:
    // 0x8007D090: beq         $at, $zero, L_8007D09C
    if (ctx->r1 == 0) {
        // 0x8007D094: nop
    
            goto L_8007D09C;
    }
    // 0x8007D094: nop

    // 0x8007D098: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
L_8007D09C:
    // 0x8007D09C: jal         0x8007B70C
    // 0x8007D0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    tex_free(rdram, ctx);
        goto after_6;
    // 0x8007D0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8007D0A4: lbu         $t2, 0xD($fp)
    ctx->r10 = MEM_BU(ctx->r30, 0XD);
    // 0x8007D0A8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007D0AC: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8007D0B0: bne         $at, $zero, L_8007D008
    if (ctx->r1 != 0) {
        // 0x8007D0B4: nop
    
            goto L_8007D008;
    }
    // 0x8007D0B4: nop

    // 0x8007D0B8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
L_8007D0BC:
    // 0x8007D0BC: subu        $t3, $s5, $s3
    ctx->r11 = SUB32(ctx->r21, ctx->r19);
    // 0x8007D0C0: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x8007D0C4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8007D0C8: subu        $t5, $s4, $s6
    ctx->r13 = SUB32(ctx->r20, ctx->r22);
    // 0x8007D0CC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
L_8007D0D0:
    // 0x8007D0D0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8007D0D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007D0D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007D0DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007D0E0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8007D0E4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007D0E8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D0EC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8007D0F0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8007D0F4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007D0F8: jr          $ra
    // 0x8007D0FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8007D0FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void pausemenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094244: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80094248: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8009424C: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x80094250: addiu       $s3, $s3, 0xF04
    ctx->r19 = ADD32(ctx->r19, 0XF04);
    // 0x80094254: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80094258: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8009425C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80094260: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80094264: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80094268: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8009426C: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80094270: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80094274: blez        $v0, L_800942C4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80094278: addiu       $t0, $zero, 0xA0
        ctx->r8 = ADD32(0, 0XA0);
            goto L_800942C4;
    }
    // 0x80094278: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x8009427C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80094280: addiu       $s0, $s0, 0x7000
    ctx->r16 = ADD32(ctx->r16, 0X7000);
L_80094284:
    // 0x80094284: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80094288: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009428C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80094290: jal         0x800C5300
    // 0x80094294: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    get_text_width(rdram, ctx);
        goto after_0;
    // 0x80094294: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_0:
    // 0x80094298: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8009429C: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800942A0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800942A4: beq         $at, $zero, L_800942B0
    if (ctx->r1 == 0) {
        // 0x800942A8: nop
    
            goto L_800942B0;
    }
    // 0x800942A8: nop

    // 0x800942AC: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800942B0:
    // 0x800942B0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x800942B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800942B8: slt         $at, $s1, $v0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800942BC: bne         $at, $zero, L_80094284
    if (ctx->r1 != 0) {
        // 0x800942C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80094284;
    }
    // 0x800942C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800942C4:
    // 0x800942C4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800942C8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800942CC: sll         $s1, $v0, 4
    ctx->r17 = S32(ctx->r2 << 4);
    // 0x800942D0: bne         $t6, $zero, L_800942E0
    if (ctx->r14 != 0) {
        // 0x800942D4: addiu       $s1, $s1, 0x1C
        ctx->r17 = ADD32(ctx->r17, 0X1C);
            goto L_800942E0;
    }
    // 0x800942D4: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x800942D8: b           L_800942E4
    // 0x800942DC: addiu       $s2, $zero, 0x84
    ctx->r18 = ADD32(0, 0X84);
        goto L_800942E4;
    // 0x800942DC: addiu       $s2, $zero, 0x84
    ctx->r18 = ADD32(0, 0X84);
L_800942E0:
    // 0x800942E0: addiu       $s2, $zero, 0x78
    ctx->r18 = ADD32(0, 0X78);
L_800942E4:
    // 0x800942E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800942E8: jal         0x800C5C30
    // 0x800942EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_1;
    // 0x800942EC: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x800942F0: jal         0x800C59F4
    // 0x800942F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_2;
    // 0x800942F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x800942F8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800942FC: sra         $s0, $s1, 1
    ctx->r16 = S32(SIGNED(ctx->r17) >> 1);
    // 0x80094300: addu        $t8, $s0, $s2
    ctx->r24 = ADD32(ctx->r16, ctx->r18);
    // 0x80094304: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80094308: sra         $v0, $t0, 1
    ctx->r2 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8009430C: subu        $a1, $t7, $v0
    ctx->r5 = SUB32(ctx->r15, ctx->r2);
    // 0x80094310: addiu       $a3, $v0, 0xA0
    ctx->r7 = ADD32(ctx->r2, 0XA0);
    // 0x80094314: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80094318: subu        $a2, $s2, $s0
    ctx->r6 = SUB32(ctx->r18, ctx->r16);
    // 0x8009431C: jal         0x800C543C
    // 0x80094320: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_3;
    // 0x80094320: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x80094324: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x80094328: addiu       $s1, $s1, 0xF0C
    ctx->r17 = ADD32(ctx->r17, 0XF0C);
    // 0x8009432C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80094330: jal         0x8006A738
    // 0x80094334: nop

    input_player_id(rdram, ctx);
        goto after_4;
    // 0x80094334: nop

    after_4:
    // 0x80094338: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009433C: addiu       $t1, $t1, 0xF10
    ctx->r9 = ADD32(ctx->r9, 0XF10);
    // 0x80094340: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80094344: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80094348: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x8009434C: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x80094350: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x80094354: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x80094358: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009435C: jal         0x800C551C
    // 0x80094360: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x80094360: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x80094364: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094368: jal         0x800C54DC
    // 0x8009436C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_6;
    // 0x8009436C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80094370: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094374: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80094378: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8009437C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094380: jal         0x800C55B0
    // 0x80094384: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_7;
    // 0x80094384: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80094388: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8009438C: jal         0x8006A738
    // 0x80094390: nop

    input_player_id(rdram, ctx);
        goto after_8;
    // 0x80094390: nop

    after_8:
    // 0x80094394: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80094398: addiu       $t4, $t4, 0xF20
    ctx->r12 = ADD32(ctx->r12, 0XF20);
    // 0x8009439C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800943A0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x800943A4: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x800943A8: lbu         $a1, 0x0($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X0);
    // 0x800943AC: lbu         $a2, 0x1($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X1);
    // 0x800943B0: lbu         $a3, 0x2($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X2);
    // 0x800943B4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800943B8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x800943BC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800943C0: jal         0x800C5560
    // 0x800943C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    set_current_text_colour(rdram, ctx);
        goto after_9;
    // 0x800943C4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_9:
    // 0x800943C8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800943CC: lw          $s4, 0x695C($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X695C);
    // 0x800943D0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800943D4: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    // 0x800943D8: slti        $at, $t7, 0x100
    ctx->r1 = SIGNED(ctx->r15) < 0X100 ? 1 : 0;
    // 0x800943DC: bne         $at, $zero, L_800943EC
    if (ctx->r1 != 0) {
        // 0x800943E0: or          $s4, $t7, $zero
        ctx->r20 = ctx->r15 | 0;
            goto L_800943EC;
    }
    // 0x800943E0: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
    // 0x800943E4: addiu       $t8, $zero, 0x1FF
    ctx->r24 = ADD32(0, 0X1FF);
    // 0x800943E8: subu        $s4, $t8, $t7
    ctx->r20 = SUB32(ctx->r24, ctx->r15);
L_800943EC:
    // 0x800943EC: addiu       $s2, $s2, 0xF08
    ctx->r18 = ADD32(ctx->r18, 0XF08);
    // 0x800943F0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800943F4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800943F8: beq         $t9, $zero, L_8009457C
    if (ctx->r25 == 0) {
        // 0x800943FC: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_8009457C;
    }
    // 0x800943FC: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80094400: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80094404: lw          $t1, 0x1568($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1568);
    // 0x80094408: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009440C: beq         $t1, $zero, L_8009444C
    if (ctx->r9 == 0) {
        // 0x80094410: addiu       $a1, $zero, -0x8000
        ctx->r5 = ADD32(0, -0X8000);
            goto L_8009444C;
    }
    // 0x80094410: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80094414: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80094418: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x8009441C: addiu       $s1, $s0, -0x1A
    ctx->r17 = ADD32(ctx->r16, -0X1A);
    // 0x80094420: lw          $a3, 0x208($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X208);
    // 0x80094424: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80094428: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8009442C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80094430: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80094434: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // 0x80094438: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009443C: jal         0x800C56C8
    // 0x80094440: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    render_dialogue_text(rdram, ctx);
        goto after_10;
    // 0x80094440: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_10:
    // 0x80094444: b           L_80094478
    // 0x80094448: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
        goto L_80094478;
    // 0x80094448: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_8009444C:
    // 0x8009444C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80094450: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80094454: addiu       $s1, $s0, -0x1A
    ctx->r17 = ADD32(ctx->r16, -0X1A);
    // 0x80094458: lw          $a3, 0x210($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X210);
    // 0x8009445C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80094460: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80094464: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80094468: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009446C: jal         0x800C56C8
    // 0x80094470: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    render_dialogue_text(rdram, ctx);
        goto after_11;
    // 0x80094470: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    after_11:
    // 0x80094474: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
L_80094478:
    // 0x80094478: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009447C: bne         $t8, $at, L_800944AC
    if (ctx->r24 != ctx->r1) {
        // 0x80094480: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800944AC;
    }
    // 0x80094480: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094484: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80094488: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009448C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094490: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094494: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094498: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009449C: jal         0x800C5560
    // 0x800944A0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_12;
    // 0x800944A0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_12:
    // 0x800944A4: b           L_800944C8
    // 0x800944A8: nop

        goto L_800944C8;
    // 0x800944A8: nop

L_800944AC:
    // 0x800944AC: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800944B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800944B4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800944B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800944BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800944C0: jal         0x800C5560
    // 0x800944C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_13;
    // 0x800944C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_13:
L_800944C8:
    // 0x800944C8: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800944CC: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x800944D0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800944D4: lw          $a3, 0x218($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X218);
    // 0x800944D8: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800944DC: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800944E0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800944E4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800944E8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x800944EC: jal         0x800C56C8
    // 0x800944F0: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    render_dialogue_text(rdram, ctx);
        goto after_14;
    // 0x800944F0: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    after_14:
    // 0x800944F4: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800944F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800944FC: bne         $t5, $at, L_8009452C
    if (ctx->r13 != ctx->r1) {
        // 0x80094500: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009452C;
    }
    // 0x80094500: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094504: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80094508: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009450C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094510: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094514: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094518: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009451C: jal         0x800C5560
    // 0x80094520: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_15;
    // 0x80094520: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x80094524: b           L_80094548
    // 0x80094528: nop

        goto L_80094548;
    // 0x80094528: nop

L_8009452C:
    // 0x8009452C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80094530: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80094534: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80094538: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009453C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094540: jal         0x800C5560
    // 0x80094544: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_16;
    // 0x80094544: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_16:
L_80094548:
    // 0x80094548: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009454C: lw          $t8, -0x5E0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5E0);
    // 0x80094550: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80094554: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x80094558: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8009455C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x80094560: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80094564: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094568: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009456C: jal         0x800C56C8
    // 0x80094570: addiu       $a2, $s1, 0x2C
    ctx->r6 = ADD32(ctx->r17, 0X2C);
    render_dialogue_text(rdram, ctx);
        goto after_17;
    // 0x80094570: addiu       $a2, $s1, 0x2C
    ctx->r6 = ADD32(ctx->r17, 0X2C);
    after_17:
    // 0x80094574: b           L_8009464C
    // 0x80094578: nop

        goto L_8009464C;
    // 0x80094578: nop

L_8009457C:
    // 0x8009457C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80094580: lw          $t2, -0x5E0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E0);
    // 0x80094584: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80094588: lw          $a3, 0x214($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X214);
    // 0x8009458C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80094590: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80094594: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80094598: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009459C: jal         0x800C56C8
    // 0x800945A0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_18;
    // 0x800945A0: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_18:
    // 0x800945A4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800945A8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800945AC: blez        $t6, L_8009464C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800945B0: addiu       $s2, $zero, 0x20
        ctx->r18 = ADD32(0, 0X20);
            goto L_8009464C;
    }
    // 0x800945B0: addiu       $s2, $zero, 0x20
    ctx->r18 = ADD32(0, 0X20);
    // 0x800945B4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800945B8: addiu       $s0, $s0, 0x7000
    ctx->r16 = ADD32(ctx->r16, 0X7000);
L_800945BC:
    // 0x800945BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800945C0: lw          $t7, 0x7028($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7028);
    // 0x800945C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800945C8: bne         $s1, $t7, L_800945F8
    if (ctx->r17 != ctx->r15) {
        // 0x800945CC: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800945F8;
    }
    // 0x800945CC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800945D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800945D4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800945D8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800945DC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800945E0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800945E4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800945E8: jal         0x800C5560
    // 0x800945EC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    set_current_text_colour(rdram, ctx);
        goto after_19;
    // 0x800945EC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_19:
    // 0x800945F0: b           L_80094614
    // 0x800945F4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
        goto L_80094614;
    // 0x800945F4: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_800945F8:
    // 0x800945F8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800945FC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80094600: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80094604: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80094608: jal         0x800C5560
    // 0x8009460C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_20;
    // 0x8009460C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_20:
    // 0x80094610: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
L_80094614:
    // 0x80094614: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80094618: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009461C: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80094620: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80094624: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80094628: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009462C: jal         0x800C56C8
    // 0x80094630: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    render_dialogue_text(rdram, ctx);
        goto after_21;
    // 0x80094630: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_21:
    // 0x80094634: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x80094638: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009463C: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80094640: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80094644: bne         $at, $zero, L_800945BC
    if (ctx->r1 != 0) {
        // 0x80094648: addiu       $s2, $s2, 0x10
        ctx->r18 = ADD32(ctx->r18, 0X10);
            goto L_800945BC;
    }
    // 0x80094648: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
L_8009464C:
    // 0x8009464C: jal         0x800C5B54
    // 0x80094650: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    open_dialogue_box(rdram, ctx);
        goto after_22;
    // 0x80094650: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_22:
    // 0x80094654: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80094658: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8009465C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80094660: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80094664: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80094668: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8009466C: jr          $ra
    // 0x80094670: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80094670: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void trackmenu_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008F4C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F4C8: addiu       $a1, $a1, 0x6D70
    ctx->r5 = ADD32(ctx->r5, 0X6D70);
    // 0x8008F4CC: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8008F4D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008F4D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008F4D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008F4DC: beq         $v0, $at, L_8008F504
    if (ctx->r2 == ctx->r1) {
        // 0x8008F4E0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8008F504;
    }
    // 0x8008F4E0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8008F4E4: beq         $v0, $zero, L_8008F504
    if (ctx->r2 == 0) {
        // 0x8008F4E8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8008F504;
    }
    // 0x8008F4E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F4EC: bne         $v0, $at, L_8008F504
    if (ctx->r2 != ctx->r1) {
        // 0x8008F4F0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F504;
    }
    // 0x8008F4F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F4F4: jal         0x8009C9EC
    // 0x8008F4F8: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8008F4F8: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    after_0:
    // 0x8008F4FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008F500: addiu       $a1, $a1, 0x6D70
    ctx->r5 = ADD32(ctx->r5, 0X6D70);
L_8008F504:
    // 0x8008F504: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8008F508: nop

    // 0x8008F50C: bltz        $t6, L_8008F6D8
    if (SIGNED(ctx->r14) < 0) {
        // 0x8008F510: sw          $t6, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r14;
            goto L_8008F6D8;
    }
    // 0x8008F510: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8008F514: slti        $at, $t6, 0x2
    ctx->r1 = SIGNED(ctx->r14) < 0X2 ? 1 : 0;
    // 0x8008F518: beq         $at, $zero, L_8008F6DC
    if (ctx->r1 == 0) {
        // 0x8008F51C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8008F6DC;
    }
    // 0x8008F51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008F520: beq         $t6, $zero, L_8008F53C
    if (ctx->r14 == 0) {
        // 0x8008F524: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008F53C;
    }
    // 0x8008F524: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008F52C: beq         $t6, $at, L_8008F55C
    if (ctx->r14 == ctx->r1) {
        // 0x8008F530: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008F55C;
    }
    // 0x8008F530: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F534: b           L_8008F6DC
    // 0x8008F538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8008F6DC;
    // 0x8008F538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F53C:
    // 0x8008F53C: lwc1        $f4, 0x6F9C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F9C);
    // 0x8008F540: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F544: swc1        $f4, 0x6FA8($at)
    MEM_W(0X6FA8, ctx->r1) = ctx->f4.u32l;
    // 0x8008F548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F54C: lwc1        $f6, 0x6FA4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x8008F550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008F554: b           L_8008F6D8
    // 0x8008F558: swc1        $f6, 0x6FAC($at)
    MEM_W(0X6FAC, ctx->r1) = ctx->f6.u32l;
        goto L_8008F6D8;
    // 0x8008F558: swc1        $f6, 0x6FAC($at)
    MEM_W(0X6FAC, ctx->r1) = ctx->f6.u32l;
L_8008F55C:
    // 0x8008F55C: lw          $a0, -0x5BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5BC);
    // 0x8008F560: jal         0x8006B2EC
    // 0x8008F564: nop

    leveltable_vehicle_default(rdram, ctx);
        goto after_1;
    // 0x8008F564: nop

    after_1:
    // 0x8008F568: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8008F56C: lw          $a2, -0x5C4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5C4);
    // 0x8008F570: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008F574: blez        $a2, L_8008F5A4
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8008F578: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008F5A4;
    }
    // 0x8008F578: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008F57C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008F580: addiu       $v1, $t7, 0x6F80
    ctx->r3 = ADD32(ctx->r15, 0X6F80);
    // 0x8008F584: addu        $a1, $a2, $v1
    ctx->r5 = ADD32(ctx->r6, ctx->r3);
    // 0x8008F588: addiu       $a0, $a0, 0x6F84
    ctx->r4 = ADD32(ctx->r4, 0X6F84);
L_8008F58C:
    // 0x8008F58C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8008F590: sltu        $at, $v1, $a1
    ctx->r1 = ctx->r3 < ctx->r5 ? 1 : 0;
    // 0x8008F594: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8008F598: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
    // 0x8008F59C: bne         $at, $zero, L_8008F58C
    if (ctx->r1 != 0) {
        // 0x8008F5A0: sb          $v0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r2;
            goto L_8008F58C;
    }
    // 0x8008F5A0: sb          $v0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r2;
L_8008F5A4:
    // 0x8008F5A4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F5A8: sw          $zero, -0x600($at)
    MEM_W(-0X600, ctx->r1) = 0;
    // 0x8008F5AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F5B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5B4: sw          $t8, 0xF00($at)
    MEM_W(0XF00, ctx->r1) = ctx->r24;
    // 0x8008F5B8: jal         0x8009CBB8
    // 0x8008F5BC: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    menu_assetgroup_load(rdram, ctx);
        goto after_2;
    // 0x8008F5BC: addiu       $a0, $a0, 0xD68
    ctx->r4 = ADD32(ctx->r4, 0XD68);
    after_2:
    // 0x8008F5C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5C4: jal         0x8009CDE8
    // 0x8008F5C8: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, 0XDB0);
    menu_imagegroup_load(rdram, ctx);
        goto after_3;
    // 0x8008F5C8: addiu       $a0, $a0, 0xDB0
    ctx->r4 = ADD32(ctx->r4, 0XDB0);
    after_3:
    // 0x8008F5CC: jal         0x8008E914
    // 0x8008F5D0: nop

    menu_init_vehicle_textures(rdram, ctx);
        goto after_4;
    // 0x8008F5D0: nop

    after_4:
    // 0x8008F5D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008F5D8: addiu       $v0, $v0, 0x6AF0
    ctx->r2 = ADD32(ctx->r2, 0X6AF0);
    // 0x8008F5DC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008F5E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008F5E4: lw          $t9, 0x90($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X90);
    // 0x8008F5E8: lw          $t0, 0x94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X94);
    // 0x8008F5EC: lw          $t1, 0x98($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X98);
    // 0x8008F5F0: lw          $t2, 0x9C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X9C);
    // 0x8008F5F4: addiu       $a0, $a0, 0xA3C
    ctx->r4 = ADD32(ctx->r4, 0XA3C);
    // 0x8008F5F8: addiu       $v1, $v1, 0xA24
    ctx->r3 = ADD32(ctx->r3, 0XA24);
    // 0x8008F5FC: lw          $t3, 0x7C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X7C);
    // 0x8008F600: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F604: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8008F608: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x8008F60C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x8008F610: sw          $t2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r10;
    // 0x8008F614: sw          $t3, 0xA54($at)
    MEM_W(0XA54, ctx->r1) = ctx->r11;
    // 0x8008F618: lw          $t4, 0x78($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X78);
    // 0x8008F61C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F620: sw          $t4, 0xA64($at)
    MEM_W(0XA64, ctx->r1) = ctx->r12;
    // 0x8008F624: lw          $t5, 0x84($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X84);
    // 0x8008F628: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F62C: sw          $t5, 0xA74($at)
    MEM_W(0XA74, ctx->r1) = ctx->r13;
    // 0x8008F630: lw          $t6, 0x80($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X80);
    // 0x8008F634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F638: sw          $t6, 0xA84($at)
    MEM_W(0XA84, ctx->r1) = ctx->r14;
    // 0x8008F63C: lw          $t7, 0x8C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8C);
    // 0x8008F640: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F644: sw          $t7, 0xA94($at)
    MEM_W(0XA94, ctx->r1) = ctx->r15;
    // 0x8008F648: lw          $t8, 0x88($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X88);
    // 0x8008F64C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F650: sw          $t8, 0xAA4($at)
    MEM_W(0XAA4, ctx->r1) = ctx->r24;
    // 0x8008F654: lw          $t9, 0xA0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA0);
    // 0x8008F658: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F65C: sw          $t9, 0xAB4($at)
    MEM_W(0XAB4, ctx->r1) = ctx->r25;
    // 0x8008F660: lw          $t0, 0xA8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XA8);
    // 0x8008F664: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F668: sw          $t0, 0xAC4($at)
    MEM_W(0XAC4, ctx->r1) = ctx->r8;
    // 0x8008F66C: lw          $t1, 0xA4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XA4);
    // 0x8008F670: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F674: sw          $t1, 0xAD4($at)
    MEM_W(0XAD4, ctx->r1) = ctx->r9;
    // 0x8008F678: lw          $t2, 0xAC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XAC);
    // 0x8008F67C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F680: sw          $t2, 0xAE4($at)
    MEM_W(0XAE4, ctx->r1) = ctx->r10;
    // 0x8008F684: lw          $t3, 0xB0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XB0);
    // 0x8008F688: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F68C: sw          $t3, 0xAF4($at)
    MEM_W(0XAF4, ctx->r1) = ctx->r11;
    // 0x8008F690: lw          $t4, 0xB4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XB4);
    // 0x8008F694: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F698: sw          $t4, 0xB04($at)
    MEM_W(0XB04, ctx->r1) = ctx->r12;
    // 0x8008F69C: lw          $t5, 0xB8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XB8);
    // 0x8008F6A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6A4: sw          $t5, 0xB14($at)
    MEM_W(0XB14, ctx->r1) = ctx->r13;
    // 0x8008F6A8: lw          $t6, 0xBC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XBC);
    // 0x8008F6AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6B0: sw          $t6, 0xB24($at)
    MEM_W(0XB24, ctx->r1) = ctx->r14;
    // 0x8008F6B4: lw          $t7, 0xC0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC0);
    // 0x8008F6B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6BC: sw          $t7, 0xB34($at)
    MEM_W(0XB34, ctx->r1) = ctx->r15;
    // 0x8008F6C0: lw          $t8, 0xC4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC4);
    // 0x8008F6C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6C8: sw          $t8, 0xB44($at)
    MEM_W(0XB44, ctx->r1) = ctx->r24;
    // 0x8008F6CC: lw          $t9, 0x1A4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1A4);
    // 0x8008F6D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6D4: sw          $t9, 0xB94($at)
    MEM_W(0XB94, ctx->r1) = ctx->r25;
L_8008F6D8:
    // 0x8008F6D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8008F6DC:
    // 0x8008F6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008F6E0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x8008F6E4: jr          $ra
    // 0x8008F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8008F6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fileselect_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008D22C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8008D230: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008D234: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008D238: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008D23C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x8008D240: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x8008D244: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x8008D248: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x8008D24C: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x8008D250: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x8008D254: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x8008D258: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x8008D25C: bne         $t6, $zero, L_8008D26C
    if (ctx->r14 != 0) {
        // 0x8008D260: sw          $a0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r4;
            goto L_8008D26C;
    }
    // 0x8008D260: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8008D264: b           L_8008D270
    // 0x8008D268: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
        goto L_8008D270;
    // 0x8008D268: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
L_8008D26C:
    // 0x8008D26C: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_8008D270:
    // 0x8008D270: jal         0x8009C2A0
    // 0x8008D274: nop

    menu_camera_centre(rdram, ctx);
        goto after_0;
    // 0x8008D274: nop

    after_0:
    // 0x8008D278: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008D27C: addiu       $s7, $s7, 0x693C
    ctx->r23 = ADD32(ctx->r23, 0X693C);
    // 0x8008D280: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008D284: addiu       $a1, $a1, 0x6944
    ctx->r5 = ADD32(ctx->r5, 0X6944);
    // 0x8008D288: jal         0x8006816C
    // 0x8008D28C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_1;
    // 0x8008D28C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x8008D290: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008D294: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008D298: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008D29C: lui         $s3, 0xB0E0
    ctx->r19 = S32(0XB0E0 << 16);
    // 0x8008D2A0: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008D2A4: addiu       $s2, $s2, -0x5EC
    ctx->r18 = ADD32(ctx->r18, -0X5EC);
    // 0x8008D2A8: ori         $s3, $s3, 0xC0FF
    ctx->r19 = ctx->r19 | 0XC0FF;
    // 0x8008D2AC: addiu       $s5, $s5, 0x6AF0
    ctx->r21 = ADD32(ctx->r21, 0X6AF0);
    // 0x8008D2B0: addiu       $s0, $s0, 0x94C
    ctx->r16 = ADD32(ctx->r16, 0X94C);
    // 0x8008D2B4: addiu       $s1, $s1, 0x6A40
    ctx->r17 = ADD32(ctx->r17, 0X6A40);
    // 0x8008D2B8: addiu       $s4, $zero, 0x78
    ctx->r20 = ADD32(0, 0X78);
L_8008D2BC:
    // 0x8008D2BC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x8008D2C0: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D2C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D2C8: beq         $t7, $t8, L_8008D2E0
    if (ctx->r15 == ctx->r24) {
        // 0x8008D2CC: nop
    
            goto L_8008D2E0;
    }
    // 0x8008D2CC: nop

    // 0x8008D2D0: lbu         $t9, 0x1($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D2D4: lui         $v0, 0x6A90
    ctx->r2 = S32(0X6A90 << 16);
    // 0x8008D2D8: bne         $t9, $zero, L_8008D2E8
    if (ctx->r25 != 0) {
        // 0x8008D2DC: ori         $v0, $v0, 0x73FF
        ctx->r2 = ctx->r2 | 0X73FF;
            goto L_8008D2E8;
    }
    // 0x8008D2DC: ori         $v0, $v0, 0x73FF
    ctx->r2 = ctx->r2 | 0X73FF;
L_8008D2E0:
    // 0x8008D2E0: b           L_8008D2E8
    // 0x8008D2E4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_8008D2E8;
    // 0x8008D2E4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8008D2E8:
    // 0x8008D2E8: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008D2EC: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008D2F0: lh          $t1, 0x6($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X6);
    // 0x8008D2F4: lh          $t2, 0x8($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X8);
    // 0x8008D2F8: lh          $t3, 0xA($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XA);
    // 0x8008D2FC: lw          $t4, 0x10C($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X10C);
    // 0x8008D300: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008D304: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8008D308: addiu       $a1, $a1, -0xA0
    ctx->r5 = ADD32(ctx->r5, -0XA0);
    // 0x8008D30C: subu        $a2, $s4, $t0
    ctx->r6 = SUB32(ctx->r20, ctx->r8);
    // 0x8008D310: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D314: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8008D318: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008D31C: jal         0x800809D0
    // 0x8008D320: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    func_80080580(rdram, ctx);
        goto after_2;
    // 0x8008D320: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    after_2:
    // 0x8008D324: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D328: addiu       $t5, $t5, 0x97C
    ctx->r13 = ADD32(ctx->r13, 0X97C);
    // 0x8008D32C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008D330: sltu        $at, $s0, $t5
    ctx->r1 = ctx->r16 < ctx->r13 ? 1 : 0;
    // 0x8008D334: bne         $at, $zero, L_8008D2BC
    if (ctx->r1 != 0) {
        // 0x8008D338: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008D2BC;
    }
    // 0x8008D338: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
    // 0x8008D33C: jal         0x80081018
    // 0x8008D340: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    func_80080BC8(rdram, ctx);
        goto after_3;
    // 0x8008D340: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x8008D344: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008D348: lw          $t6, 0x6978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6978);
    // 0x8008D34C: nop

    // 0x8008D350: bne         $t6, $zero, L_8008D5B0
    if (ctx->r14 != 0) {
        // 0x8008D354: nop
    
            goto L_8008D5B0;
    }
    // 0x8008D354: nop

    // 0x8008D358: jal         0x800C484C
    // 0x8008D35C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_4;
    // 0x8008D35C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x8008D360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D364: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D368: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D36C: jal         0x800C492C
    // 0x8008D370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_5;
    // 0x8008D370: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8008D374: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008D378: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8008D37C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008D380: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8008D384: addiu       $s3, $s3, -0x324
    ctx->r19 = ADD32(ctx->r19, -0X324);
    // 0x8008D388: addiu       $s4, $s4, 0x97C
    ctx->r20 = ADD32(ctx->r20, 0X97C);
    // 0x8008D38C: addiu       $s0, $s0, 0x94C
    ctx->r16 = ADD32(ctx->r16, 0X94C);
    // 0x8008D390: addiu       $s1, $s1, 0x6A40
    ctx->r17 = ADD32(ctx->r17, 0X6A40);
    // 0x8008D394: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
L_8008D398:
    // 0x8008D398: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D39C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D3A0: beq         $t7, $zero, L_8008D550
    if (ctx->r15 == 0) {
        // 0x8008D3A4: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008D550;
    }
    // 0x8008D3A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D3A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D3AC: jal         0x8007C36C
    // 0x8008D3B0: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    sprite_opaque(rdram, ctx);
        goto after_6;
    // 0x8008D3B0: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    after_6:
    // 0x8008D3B4: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8008D3B8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D3BC: beq         $t8, $zero, L_8008D3C8
    if (ctx->r24 == 0) {
        // 0x8008D3C0: addiu       $t3, $zero, 0x80
        ctx->r11 = ADD32(0, 0X80);
            goto L_8008D3C8;
    }
    // 0x8008D3C0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x8008D3C4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_8008D3C8:
    // 0x8008D3C8: lh          $t9, 0x4($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X4);
    // 0x8008D3CC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008D3D0: lh          $t1, 0x6($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X6);
    // 0x8008D3D4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008D3D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8008D3DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D3E0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D3E4: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8008D3E8: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x8008D3EC: jal         0x8008D0E0
    // 0x8008D3F0: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    fileselect_render_element(rdram, ctx);
        goto after_7;
    // 0x8008D3F0: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_7:
    // 0x8008D3F4: jal         0x80068748
    // 0x8008D3F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_8;
    // 0x8008D3F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x8008D3FC: lhu         $t4, 0x2($s1)
    ctx->r12 = MEM_HU(ctx->r17, 0X2);
    // 0x8008D400: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8008D404: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x8008D408: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8008D40C: bne         $s5, $zero, L_8008D418
    if (ctx->r21 != 0) {
        // 0x8008D410: nop
    
            goto L_8008D418;
    }
    // 0x8008D410: nop

    // 0x8008D414: break       7
    do_break(2148062228);
L_8008D418:
    // 0x8008D418: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D41C: bne         $s5, $at, L_8008D430
    if (ctx->r21 != ctx->r1) {
        // 0x8008D420: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008D430;
    }
    // 0x8008D420: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D424: bne         $t4, $at, L_8008D430
    if (ctx->r12 != ctx->r1) {
        // 0x8008D428: nop
    
            goto L_8008D430;
    }
    // 0x8008D428: nop

    // 0x8008D42C: break       6
    do_break(2148062252);
L_8008D430:
    // 0x8008D430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D434: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D438: mflo        $t5
    ctx->r13 = lo;
    // 0x8008D43C: sh          $t5, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r13;
    // 0x8008D440: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8008D444: lh          $t7, 0xC($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XC);
    // 0x8008D448: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x8008D44C: lh          $t9, 0xE($s4)
    ctx->r25 = MEM_H(ctx->r20, 0XE);
    // 0x8008D450: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x8008D454: addiu       $a1, $a1, -0x6
    ctx->r5 = ADD32(ctx->r5, -0X6);
    // 0x8008D458: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008D45C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D460: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D464: jal         0x8008D0E0
    // 0x8008D468: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    fileselect_render_element(rdram, ctx);
        goto after_9;
    // 0x8008D468: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    after_9:
    // 0x8008D46C: lhu         $t2, 0x2($s1)
    ctx->r10 = MEM_HU(ctx->r17, 0X2);
    // 0x8008D470: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x8008D474: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x8008D478: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x8008D47C: bne         $s5, $zero, L_8008D488
    if (ctx->r21 != 0) {
        // 0x8008D480: nop
    
            goto L_8008D488;
    }
    // 0x8008D480: nop

    // 0x8008D484: break       7
    do_break(2148062340);
L_8008D488:
    // 0x8008D488: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008D48C: bne         $s5, $at, L_8008D4A0
    if (ctx->r21 != ctx->r1) {
        // 0x8008D490: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8008D4A0;
    }
    // 0x8008D490: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8008D494: bne         $t2, $at, L_8008D4A0
    if (ctx->r10 != ctx->r1) {
        // 0x8008D498: nop
    
            goto L_8008D4A0;
    }
    // 0x8008D498: nop

    // 0x8008D49C: break       6
    do_break(2148062364);
L_8008D4A0:
    // 0x8008D4A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D4A4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D4A8: mfhi        $t3
    ctx->r11 = hi;
    // 0x8008D4AC: sh          $t3, 0x18($t4)
    MEM_H(0X18, ctx->r12) = ctx->r11;
    // 0x8008D4B0: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8008D4B4: lh          $t5, 0xC($s4)
    ctx->r13 = MEM_H(ctx->r20, 0XC);
    // 0x8008D4B8: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8008D4BC: lh          $t7, 0xE($s4)
    ctx->r15 = MEM_H(ctx->r20, 0XE);
    // 0x8008D4C0: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x8008D4C4: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x8008D4C8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008D4CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D4D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D4D4: jal         0x8008D0E0
    // 0x8008D4D8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    fileselect_render_element(rdram, ctx);
        goto after_10;
    // 0x8008D4D8: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    after_10:
    // 0x8008D4DC: jal         0x80068748
    // 0x8008D4E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x8008D4E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8008D4E4: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8008D4E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D4EC: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x8008D4F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D4F4: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008D4F8: lh          $t3, 0x2($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X2);
    // 0x8008D4FC: lh          $t2, 0x12($s4)
    ctx->r10 = MEM_H(ctx->r20, 0X12);
    // 0x8008D500: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x8008D504: lh          $t0, 0x10($s4)
    ctx->r8 = MEM_H(ctx->r20, 0X10);
    // 0x8008D508: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x8008D50C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008D510: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8008D514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008D518: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8008D51C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008D520: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8008D524: jal         0x8008D0E0
    // 0x8008D528: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    fileselect_render_element(rdram, ctx);
        goto after_12;
    // 0x8008D528: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_12:
    // 0x8008D52C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8008D530: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D534: sb          $v0, -0x5D8($at)
    MEM_B(-0X5D8, ctx->r1) = ctx->r2;
    // 0x8008D538: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008D53C: sb          $v0, -0x5D4($at)
    MEM_B(-0X5D4, ctx->r1) = ctx->r2;
    // 0x8008D540: jal         0x8007C36C
    // 0x8008D544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_13;
    // 0x8008D544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_13:
    // 0x8008D548: b           L_8008D59C
    // 0x8008D54C: nop

        goto L_8008D59C;
    // 0x8008D54C: nop

L_8008D550:
    // 0x8008D550: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D554: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D558: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D55C: jal         0x800C48E4
    // 0x8008D560: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    set_text_colour(rdram, ctx);
        goto after_14;
    // 0x8008D560: addiu       $a3, $zero, 0x40
    ctx->r7 = ADD32(0, 0X40);
    after_14:
    // 0x8008D564: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008D568: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008D56C: lh          $t8, 0xA($s4)
    ctx->r24 = MEM_H(ctx->r20, 0XA);
    // 0x8008D570: lh          $t9, 0x2($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X2);
    // 0x8008D574: lh          $t6, 0x8($s4)
    ctx->r14 = MEM_H(ctx->r20, 0X8);
    // 0x8008D578: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8008D57C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D580: lw          $a3, 0x12C($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X12C);
    // 0x8008D584: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8008D588: addu        $a2, $t0, $s6
    ctx->r6 = ADD32(ctx->r8, ctx->r22);
    // 0x8008D58C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D590: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D594: jal         0x800C49A0
    // 0x8008D598: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_15;
    // 0x8008D598: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_15:
L_8008D59C:
    // 0x8008D59C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D5A0: addiu       $t3, $t3, 0x97C
    ctx->r11 = ADD32(ctx->r11, 0X97C);
    // 0x8008D5A4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8008D5A8: bne         $s0, $t3, L_8008D398
    if (ctx->r16 != ctx->r11) {
        // 0x8008D5AC: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8008D398;
    }
    // 0x8008D5AC: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8008D5B0:
    // 0x8008D5B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D5B4: lw          $v0, 0x695C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X695C);
    // 0x8008D5B8: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8008D5BC: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x8008D5C0: slti        $at, $t4, 0x100
    ctx->r1 = SIGNED(ctx->r12) < 0X100 ? 1 : 0;
    // 0x8008D5C4: addiu       $s4, $s4, 0x97C
    ctx->r20 = ADD32(ctx->r20, 0X97C);
    // 0x8008D5C8: bne         $at, $zero, L_8008D5D8
    if (ctx->r1 != 0) {
        // 0x8008D5CC: or          $v0, $t4, $zero
        ctx->r2 = ctx->r12 | 0;
            goto L_8008D5D8;
    }
    // 0x8008D5CC: or          $v0, $t4, $zero
    ctx->r2 = ctx->r12 | 0;
    // 0x8008D5D0: addiu       $t5, $zero, 0x1FF
    ctx->r13 = ADD32(0, 0X1FF);
    // 0x8008D5D4: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
L_8008D5D8:
    // 0x8008D5D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D5DC: jal         0x800C484C
    // 0x8008D5E0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    set_text_font(rdram, ctx);
        goto after_16;
    // 0x8008D5E0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_16:
    // 0x8008D5E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D5E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D5EC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D5F0: jal         0x800C492C
    // 0x8008D5F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_17;
    // 0x8008D5F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x8008D5F8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8008D5FC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D600: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D604: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D608: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D60C: jal         0x800C48E4
    // 0x8008D610: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_18;
    // 0x8008D610: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_18:
    // 0x8008D614: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008D618: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
L_8008D61C:
    // 0x8008D61C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008D620: lw          $t7, 0x6A24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A24);
    // 0x8008D624: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008D628: beq         $t7, $zero, L_8008D67C
    if (ctx->r15 == 0) {
        // 0x8008D62C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_8008D67C;
    }
    // 0x8008D62C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8008D630: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D634: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008D638: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D63C: bne         $v0, $zero, L_8008D65C
    if (ctx->r2 != 0) {
        // 0x8008D640: nop
    
            goto L_8008D65C;
    }
    // 0x8008D640: nop

    // 0x8008D644: lw          $t8, 0x6A2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A2C);
    // 0x8008D648: nop

    // 0x8008D64C: bne         $s3, $t8, L_8008D65C
    if (ctx->r19 != ctx->r24) {
        // 0x8008D650: nop
    
            goto L_8008D65C;
    }
    // 0x8008D650: nop

    // 0x8008D654: b           L_8008D6C8
    // 0x8008D658: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D658: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D65C:
    // 0x8008D65C: blez        $v0, L_8008D6C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008D660: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8008D6C8;
    }
    // 0x8008D660: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D664: lw          $t9, 0x6A30($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A30);
    // 0x8008D668: nop

    // 0x8008D66C: bne         $s3, $t9, L_8008D6C8
    if (ctx->r19 != ctx->r25) {
        // 0x8008D670: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D670: nop

    // 0x8008D674: b           L_8008D6C8
    // 0x8008D678: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D678: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D67C:
    // 0x8008D67C: lw          $t0, 0x6A28($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6A28);
    // 0x8008D680: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D684: beq         $t0, $zero, L_8008D6A4
    if (ctx->r8 == 0) {
        // 0x8008D688: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_8008D6A4;
    }
    // 0x8008D688: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D68C: lw          $t1, 0x6A2C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6A2C);
    // 0x8008D690: nop

    // 0x8008D694: bne         $s3, $t1, L_8008D6C8
    if (ctx->r19 != ctx->r9) {
        // 0x8008D698: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D698: nop

    // 0x8008D69C: b           L_8008D6C8
    // 0x8008D6A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8008D6C8;
    // 0x8008D6A0: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D6A4:
    // 0x8008D6A4: lw          $t2, 0x6980($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6980);
    // 0x8008D6A8: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D6AC: bne         $t2, $zero, L_8008D6C8
    if (ctx->r10 != 0) {
        // 0x8008D6B0: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D6B0: nop

    // 0x8008D6B4: lw          $t3, -0x5B4($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5B4);
    // 0x8008D6B8: nop

    // 0x8008D6BC: bne         $s3, $t3, L_8008D6C8
    if (ctx->r19 != ctx->r11) {
        // 0x8008D6C0: nop
    
            goto L_8008D6C8;
    }
    // 0x8008D6C0: nop

    // 0x8008D6C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8008D6C8:
    // 0x8008D6C8: beq         $s2, $zero, L_8008D72C
    if (ctx->r18 == 0) {
        // 0x8008D6CC: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D72C;
    }
    // 0x8008D6CC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D6D0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D6D4: addiu       $t5, $t5, 0x94C
    ctx->r13 = ADD32(ctx->r13, 0X94C);
    // 0x8008D6D8: sll         $t4, $s3, 4
    ctx->r12 = S32(ctx->r19 << 4);
    // 0x8008D6DC: addu        $s0, $t4, $t5
    ctx->r16 = ADD32(ctx->r12, ctx->r13);
    // 0x8008D6E0: lw          $v0, 0x7C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D6E4: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8008D6E8: or          $t0, $v0, $at
    ctx->r8 = ctx->r2 | ctx->r1;
    // 0x8008D6EC: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008D6F0: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8008D6F4: lh          $t8, 0x8($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X8);
    // 0x8008D6F8: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8008D6FC: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x8008D700: lh          $a3, 0x4($s0)
    ctx->r7 = MEM_H(ctx->r16, 0X4);
    // 0x8008D704: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8008D708: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8008D70C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8008D710: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8008D714: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8008D718: addu        $a2, $t6, $s6
    ctx->r6 = ADD32(ctx->r14, ctx->r22);
    // 0x8008D71C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D720: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8008D724: jal         0x800812E0
    // 0x8008D728: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    func_80080E90(rdram, ctx);
        goto after_19;
    // 0x8008D728: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_19:
L_8008D72C:
    // 0x8008D72C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008D730: lw          $t1, 0x7280($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7280);
    // 0x8008D734: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008D738: beq         $t1, $zero, L_8008D74C
    if (ctx->r9 == 0) {
        // 0x8008D73C: sll         $t3, $s3, 2
        ctx->r11 = S32(ctx->r19 << 2);
            goto L_8008D74C;
    }
    // 0x8008D73C: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x8008D740: lw          $t2, -0x5B4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5B4);
    // 0x8008D744: nop

    // 0x8008D748: beq         $s3, $t2, L_8008D7D0
    if (ctx->r19 == ctx->r10) {
        // 0x8008D74C: subu        $t3, $t3, $s3
        ctx->r11 = SUB32(ctx->r11, ctx->r19);
            goto L_8008D7D0;
    }
L_8008D74C:
    // 0x8008D74C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x8008D750: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D754: addiu       $t4, $t4, 0x6A40
    ctx->r12 = ADD32(ctx->r12, 0X6A40);
    // 0x8008D758: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8008D75C: addu        $s1, $t3, $t4
    ctx->r17 = ADD32(ctx->r11, ctx->r12);
    // 0x8008D760: addiu       $a0, $s1, 0x4
    ctx->r4 = ADD32(ctx->r17, 0X4);
    // 0x8008D764: jal         0x80097D0C
    // 0x8008D768: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_20;
    // 0x8008D768: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_20:
    // 0x8008D76C: lbu         $t5, 0x1($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X1);
    // 0x8008D770: sll         $t6, $s3, 2
    ctx->r14 = S32(ctx->r19 << 2);
    // 0x8008D774: bne         $t5, $zero, L_8008D78C
    if (ctx->r13 != 0) {
        // 0x8008D778: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008D78C;
    }
    // 0x8008D778: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008D77C: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x8008D780: lw          $a0, 0x930($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X930);
    // 0x8008D784: jal         0x80097D0C
    // 0x8008D788: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    filename_trim(rdram, ctx);
        goto after_21;
    // 0x8008D788: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_21:
L_8008D78C:
    // 0x8008D78C: beq         $s5, $zero, L_8008D7D0
    if (ctx->r21 == 0) {
        // 0x8008D790: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D7D0;
    }
    // 0x8008D790: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D794: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8008D798: addiu       $t8, $t8, 0x94C
    ctx->r24 = ADD32(ctx->r24, 0X94C);
    // 0x8008D79C: sll         $t7, $s3, 4
    ctx->r15 = S32(ctx->r19 << 4);
    // 0x8008D7A0: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x8008D7A4: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x8008D7A8: lh          $t1, 0x2($s4)
    ctx->r9 = MEM_H(ctx->r20, 0X2);
    // 0x8008D7AC: lh          $t0, 0x0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X0);
    // 0x8008D7B0: lh          $t9, 0x0($s4)
    ctx->r25 = MEM_H(ctx->r20, 0X0);
    // 0x8008D7B4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D7B8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8008D7BC: addu        $a2, $t3, $s6
    ctx->r6 = ADD32(ctx->r11, ctx->r22);
    // 0x8008D7C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D7C4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x8008D7C8: jal         0x800C49A0
    // 0x8008D7CC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    draw_text(rdram, ctx);
        goto after_22;
    // 0x8008D7CC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_22:
L_8008D7D0:
    // 0x8008D7D0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008D7D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008D7D8: bne         $s3, $at, L_8008D61C
    if (ctx->r19 != ctx->r1) {
        // 0x8008D7DC: nop
    
            goto L_8008D61C;
    }
    // 0x8008D7DC: nop

    // 0x8008D7E0: jal         0x800C484C
    // 0x8008D7E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_23;
    // 0x8008D7E4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_23:
    // 0x8008D7E8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8008D7EC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D7F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008D7F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008D7F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008D7FC: jal         0x800C48E4
    // 0x8008D800: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_24;
    // 0x8008D800: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_24:
    // 0x8008D804: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D808: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8008D80C: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8008D810: lw          $a3, 0x2F0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X2F0);
    // 0x8008D814: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D818: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D81C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008D820: jal         0x800C49A0
    // 0x8008D824: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    draw_text(rdram, ctx);
        goto after_25;
    // 0x8008D824: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    after_25:
    // 0x8008D828: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008D82C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008D830: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D834: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D838: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D83C: jal         0x800C48E4
    // 0x8008D840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_26;
    // 0x8008D840: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_26:
    // 0x8008D844: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8008D848: lw          $t9, -0x5E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5E0);
    // 0x8008D84C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8008D850: lw          $a3, 0x2F0($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X2F0);
    // 0x8008D854: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008D858: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D85C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D860: jal         0x800C49A0
    // 0x8008D864: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    draw_text(rdram, ctx);
        goto after_27;
    // 0x8008D864: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_27:
    // 0x8008D868: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008D86C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D870: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D874: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D878: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008D87C: jal         0x800C48E4
    // 0x8008D880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_28;
    // 0x8008D880: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8008D884: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8008D888: lw          $t2, 0x6A24($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A24);
    // 0x8008D88C: addiu       $s6, $s6, 0xBB
    ctx->r22 = ADD32(ctx->r22, 0XBB);
    // 0x8008D890: beq         $t2, $zero, L_8008D940
    if (ctx->r10 == 0) {
        // 0x8008D894: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8008D940;
    }
    // 0x8008D894: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008D898: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008D89C: lw          $v0, 0x6A34($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A34);
    // 0x8008D8A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D8A4: bne         $v0, $zero, L_8008D8E0
    if (ctx->r2 != 0) {
        // 0x8008D8A8: nop
    
            goto L_8008D8E0;
    }
    // 0x8008D8A8: nop

    // 0x8008D8AC: jal         0x800C484C
    // 0x8008D8B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_29;
    // 0x8008D8B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x8008D8B4: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008D8B8: lw          $t3, -0x5E0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5E0);
    // 0x8008D8BC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008D8C0: lw          $a3, 0x134($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X134);
    // 0x8008D8C4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008D8C8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D8CC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D8D0: jal         0x800C49A0
    // 0x8008D8D4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_30;
    // 0x8008D8D4: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_30:
    // 0x8008D8D8: b           L_8008DA88
    // 0x8008D8DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D8DC: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D8E0:
    // 0x8008D8E0: bne         $v0, $at, L_8008D91C
    if (ctx->r2 != ctx->r1) {
        // 0x8008D8E4: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8008D91C;
    }
    // 0x8008D8E4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D8E8: jal         0x800C484C
    // 0x8008D8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_31;
    // 0x8008D8EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_31:
    // 0x8008D8F0: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8008D8F4: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x8008D8F8: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8008D8FC: lw          $a3, 0x138($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X138);
    // 0x8008D900: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008D904: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D908: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D90C: jal         0x800C49A0
    // 0x8008D910: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_32;
    // 0x8008D910: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_32:
    // 0x8008D914: b           L_8008DA88
    // 0x8008D918: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D918: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D91C:
    // 0x8008D91C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D920: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D924: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008D928: addiu       $a3, $a3, -0x783C
    ctx->r7 = ADD32(ctx->r7, -0X783C);
    // 0x8008D92C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D930: jal         0x800C49A0
    // 0x8008D934: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_33;
    // 0x8008D934: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_33:
    // 0x8008D938: b           L_8008DA88
    // 0x8008D93C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D93C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D940:
    // 0x8008D940: lw          $t8, 0x6A28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6A28);
    // 0x8008D944: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008D948: beq         $t8, $zero, L_8008D9B4
    if (ctx->r24 == 0) {
        // 0x8008D94C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8008D9B4;
    }
    // 0x8008D94C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8008D950: lw          $t9, 0x6A34($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A34);
    // 0x8008D954: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D958: bne         $t9, $zero, L_8008D994
    if (ctx->r25 != 0) {
        // 0x8008D95C: addiu       $a1, $zero, 0xA0
        ctx->r5 = ADD32(0, 0XA0);
            goto L_8008D994;
    }
    // 0x8008D95C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D960: jal         0x800C484C
    // 0x8008D964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_34;
    // 0x8008D964: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_34:
    // 0x8008D968: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008D96C: lw          $t0, -0x5E0($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E0);
    // 0x8008D970: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008D974: lw          $a3, 0x13C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X13C);
    // 0x8008D978: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008D97C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008D980: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008D984: jal         0x800C49A0
    // 0x8008D988: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_35;
    // 0x8008D988: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_35:
    // 0x8008D98C: b           L_8008DA88
    // 0x8008D990: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D990: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D994:
    // 0x8008D994: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008D998: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008D99C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008D9A0: addiu       $a3, $a3, -0x7838
    ctx->r7 = ADD32(ctx->r7, -0X7838);
    // 0x8008D9A4: jal         0x800C49A0
    // 0x8008D9A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_36;
    // 0x8008D9A8: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_36:
    // 0x8008D9AC: b           L_8008DA88
    // 0x8008D9B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
        goto L_8008DA88;
    // 0x8008D9B0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008D9B4:
    // 0x8008D9B4: lw          $t3, 0x7280($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7280);
    // 0x8008D9B8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8008D9BC: bne         $t3, $zero, L_8008DA88
    if (ctx->r11 != 0) {
        // 0x8008D9C0: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8008DA88;
    }
    // 0x8008D9C0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8008D9C4: lw          $t4, 0x6980($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6980);
    // 0x8008D9C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008D9CC: bne         $t4, $at, L_8008D9EC
    if (ctx->r12 != ctx->r1) {
        // 0x8008D9D0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008D9EC;
    }
    // 0x8008D9D0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008D9D4: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008D9D8: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8008D9DC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008D9E0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008D9E4: jal         0x800C48E4
    // 0x8008D9E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_37;
    // 0x8008D9E8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_37:
L_8008D9EC:
    // 0x8008D9EC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008D9F0: lw          $t6, -0x5E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5E0);
    // 0x8008D9F4: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008D9F8: lw          $a3, 0x140($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X140);
    // 0x8008D9FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008DA00: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008DA04: addiu       $a1, $zero, 0x5A
    ctx->r5 = ADD32(0, 0X5A);
    // 0x8008DA08: jal         0x800C49A0
    // 0x8008DA0C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_38;
    // 0x8008DA0C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_38:
    // 0x8008DA10: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008DA14: lw          $t8, 0x6980($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6980);
    // 0x8008DA18: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008DA1C: bne         $t8, $at, L_8008DA48
    if (ctx->r24 != ctx->r1) {
        // 0x8008DA20: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_8008DA48;
    }
    // 0x8008DA20: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008DA24: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x8008DA28: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008DA2C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008DA30: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008DA34: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008DA38: jal         0x800C48E4
    // 0x8008DA3C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_39;
    // 0x8008DA3C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_39:
    // 0x8008DA40: b           L_8008DA60
    // 0x8008DA44: nop

        goto L_8008DA60;
    // 0x8008DA44: nop

L_8008DA48:
    // 0x8008DA48: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008DA4C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8008DA50: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008DA54: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008DA58: jal         0x800C48E4
    // 0x8008DA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_40;
    // 0x8008DA5C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_40:
L_8008DA60:
    // 0x8008DA60: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008DA64: lw          $t1, -0x5E0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5E0);
    // 0x8008DA68: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8008DA6C: lw          $a3, 0x144($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X144);
    // 0x8008DA70: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008DA74: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8008DA78: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8008DA7C: jal         0x800C49A0
    // 0x8008DA80: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    draw_text(rdram, ctx);
        goto after_41;
    // 0x8008DA80: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    after_41:
    // 0x8008DA84: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8008DA88:
    // 0x8008DA88: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8008DA8C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x8008DA90: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x8008DA94: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x8008DA98: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x8008DA9C: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8008DAA0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x8008DAA4: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x8008DAA8: jr          $ra
    // 0x8008DAAC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8008DAAC: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void alSynStartVoiceParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065E80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80065E84: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065E88: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80065E8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80065E90: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x80065E94: nop

    // 0x80065E98: beq         $t7, $zero, L_80065F74
    if (ctx->r15 == 0) {
        // 0x80065E9C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80065F74;
    }
    // 0x80065E9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065EA0: jal         0x800658A8
    // 0x80065EA4: nop

    __allocParam(rdram, ctx);
        goto after_0;
    // 0x80065EA4: nop

    after_0:
    // 0x80065EA8: beq         $v0, $zero, L_80065F70
    if (ctx->r2 == 0) {
        // 0x80065EAC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80065F70;
    }
    // 0x80065EAC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80065EB0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80065EB4: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80065EB8: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80065EBC: lw          $t9, 0x1C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X1C);
    // 0x80065EC0: lw          $t1, 0xD8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XD8);
    // 0x80065EC4: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x80065EC8: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x80065ECC: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80065ED0: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80065ED4: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x80065ED8: lh          $t4, 0x1A($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X1A);
    // 0x80065EDC: nop

    // 0x80065EE0: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x80065EE4: lbu         $a0, 0x37($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X37);
    // 0x80065EE8: jal         0x80065E2C
    // 0x80065EEC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    modify_panning(rdram, ctx);
        goto after_1;
    // 0x80065EEC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80065EF0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065EF4: nop

    // 0x80065EF8: sb          $v0, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r2;
    // 0x80065EFC: lh          $t5, 0x32($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X32);
    // 0x80065F00: nop

    // 0x80065F04: sh          $t5, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r13;
    // 0x80065F08: lbu         $t6, 0x3B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X3B);
    // 0x80065F0C: nop

    // 0x80065F10: sb          $t6, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r14;
    // 0x80065F14: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80065F18: nop

    // 0x80065F1C: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x80065F20: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80065F24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80065F28: jal         0x80065A04
    // 0x80065F2C: nop

    _timeToSamples(rdram, ctx);
        goto after_2;
    // 0x80065F2C: nop

    after_2:
    // 0x80065F30: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80065F34: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80065F38: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x80065F3C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80065F40: nop

    // 0x80065F44: sw          $t7, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r15;
    // 0x80065F48: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80065F4C: nop

    // 0x80065F50: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x80065F54: nop

    // 0x80065F58: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x80065F5C: nop

    // 0x80065F60: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80065F64: nop

    // 0x80065F68: jalr        $t9
    // 0x80065F6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80065F6C: nop

    after_3:
L_80065F70:
    // 0x80065F70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80065F74:
    // 0x80065F74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80065F78: jr          $ra
    // 0x80065F7C: nop

    return;
    // 0x80065F7C: nop

;}
RECOMP_FUNC void alCSPGetTempo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DF0: lw          $v1, 0x18($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X18);
    // 0x800C7DF4: bnel        $v1, $zero, L_800C7E08
    if (ctx->r3 != 0) {
        // 0x800C7DF8: lw          $t6, 0x24($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X24);
            goto L_800C7E08;
    }
    goto skip_0;
    // 0x800C7DF8: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x800C7DFC: jr          $ra
    // 0x800C7E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C7E00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7E04: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
L_800C7E08:
    // 0x800C7E08: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C7E0C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800C7E10: nop

    // 0x800C7E14: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C7E18: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C7E1C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800C7E20: mfc1        $v0, $f16
    ctx->r2 = (int32_t)ctx->f16.u32l;
    // 0x800C7E24: nop

    // 0x800C7E28: jr          $ra
    // 0x800C7E2C: nop

    return;
    // 0x800C7E2C: nop

;}
RECOMP_FUNC void obj_loop_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035C90: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80035C94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80035C98: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80035C9C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80035CA0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80035CA4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80035CA8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80035CAC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80035CB0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80035CB4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80035CB8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80035CBC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80035CC0: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x80035CC4: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80035CC8: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80035CCC: nop

    // 0x80035CD0: ori         $t9, $t8, 0x1000
    ctx->r25 = ctx->r24 | 0X1000;
    // 0x80035CD4: sh          $t9, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r25;
    // 0x80035CD8: jal         0x8001BAFC
    // 0x80035CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80035CDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80035CE0: lw          $t0, 0x4C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4C);
    // 0x80035CE4: lw          $t2, 0x78($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X78);
    // 0x80035CE8: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80035CEC: nop

    // 0x80035CF0: slt         $at, $t1, $t2
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80035CF4: beq         $at, $zero, L_80035E3C
    if (ctx->r1 == 0) {
        // 0x80035CF8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80035E3C;
    }
    // 0x80035CF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80035CFC: jal         0x8001BAA8
    // 0x80035D00: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80035D00: addiu       $a0, $sp, 0x54
    ctx->r4 = ADD32(ctx->r29, 0X54);
    after_1:
    // 0x80035D04: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80035D08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80035D0C: blez        $t3, L_80035E38
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80035D10: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_80035E38;
    }
    // 0x80035D10: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80035D14: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80035D18: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_80035D1C:
    // 0x80035D1C: lw          $s1, 0x0($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X0);
    // 0x80035D20: nop

    // 0x80035D24: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x80035D28: nop

    // 0x80035D2C: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035D30: nop

    // 0x80035D34: slti        $at, $t4, 0xF
    ctx->r1 = SIGNED(ctx->r12) < 0XF ? 1 : 0;
    // 0x80035D38: beq         $at, $zero, L_80035E28
    if (ctx->r1 == 0) {
        // 0x80035D3C: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035D3C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D40: lb          $t5, 0x1E2($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1E2);
    // 0x80035D44: nop

    // 0x80035D48: beq         $t5, $zero, L_80035E28
    if (ctx->r13 == 0) {
        // 0x80035D4C: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035D4C: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035D50: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80035D54: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80035D58: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80035D5C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035D60: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80035D64: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035D68: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035D6C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80035D70: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80035D74: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035D78: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035D7C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035D80: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035D84: jal         0x800CA030
    // 0x80035D88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035D88: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035D8C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80035D90: lw          $t8, 0x78($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X78);
    // 0x80035D94: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80035D98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035D9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035DA0: nop

    // 0x80035DA4: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035DA8: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x80035DAC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80035DB0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80035DB4: beq         $at, $zero, L_80035E28
    if (ctx->r1 == 0) {
        // 0x80035DB8: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035DB8: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035DBC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80035DC0: addiu       $a0, $zero, 0x107
    ctx->r4 = ADD32(0, 0X107);
    // 0x80035DC4: beq         $s5, $t9, L_80035DE0
    if (ctx->r21 == ctx->r25) {
        // 0x80035DC8: nop
    
            goto L_80035DE0;
    }
    // 0x80035DC8: nop

    // 0x80035DCC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x80035DD0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x80035DD4: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x80035DD8: jal         0x80001EA8
    // 0x80035DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x80035DDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
L_80035DE0:
    // 0x80035DE0: jal         0x8000C8B4
    // 0x80035DE4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x80035DE4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_4:
    // 0x80035DE8: lbu         $t0, 0x20C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X20C);
    // 0x80035DEC: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x80035DF0: beq         $t0, $zero, L_80035E08
    if (ctx->r8 == 0) {
        // 0x80035DF4: sb          $s6, 0x203($s0)
        MEM_B(0X203, ctx->r16) = ctx->r22;
            goto L_80035E08;
    }
    // 0x80035DF4: sb          $s6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r22;
    // 0x80035DF8: lb          $t1, 0x203($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X203);
    // 0x80035DFC: nop

    // 0x80035E00: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80035E04: sb          $t2, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r10;
L_80035E08:
    // 0x80035E08: lb          $t3, 0x1D8($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D8);
    // 0x80035E0C: nop

    // 0x80035E10: bne         $t3, $zero, L_80035E28
    if (ctx->r11 != 0) {
        // 0x80035E14: lw          $t4, 0x54($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X54);
            goto L_80035E28;
    }
    // 0x80035E14: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80035E18: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80035E1C: jal         0x80072594
    // 0x80035E20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_5;
    // 0x80035E20: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_5:
    // 0x80035E24: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
L_80035E28:
    // 0x80035E28: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80035E2C: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035E30: bne         $at, $zero, L_80035D1C
    if (ctx->r1 != 0) {
        // 0x80035E34: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80035D1C;
    }
    // 0x80035E34: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_80035E38:
    // 0x80035E38: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80035E3C:
    // 0x80035E3C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80035E40: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80035E44: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80035E48: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80035E4C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80035E50: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80035E54: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80035E58: jr          $ra
    // 0x80035E5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80035E5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void alCSeqNextEvent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8264: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C8268: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C826C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C8270: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C8274: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
    // 0x800C8278: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C827C: lw          $a2, 0x10($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X10);
    // 0x800C8280: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800C8284: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C8288: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C828C: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
L_800C8290:
    // 0x800C8290: srlv        $t7, $t6, $v0
    ctx->r15 = S32(U32(ctx->r14) >> (ctx->r2 & 31));
    // 0x800C8294: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800C8298: beql        $t8, $zero, L_800C82DC
    if (ctx->r24 == 0) {
        // 0x800C829C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C82DC;
    }
    goto skip_0;
    // 0x800C829C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800C82A0: lw          $t6, 0x14($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X14);
    // 0x800C82A4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C82A8: addu        $v1, $t4, $t9
    ctx->r3 = ADD32(ctx->r12, ctx->r25);
    // 0x800C82AC: beql        $t6, $zero, L_800C82C4
    if (ctx->r14 == 0) {
        // 0x800C82B0: lw          $a0, 0xB8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XB8);
            goto L_800C82C4;
    }
    goto skip_1;
    // 0x800C82B0: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
    skip_1:
    // 0x800C82B4: lw          $t7, 0xB8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XB8);
    // 0x800C82B8: subu        $t8, $t7, $a2
    ctx->r24 = SUB32(ctx->r15, ctx->r6);
    // 0x800C82BC: sw          $t8, 0xB8($v1)
    MEM_W(0XB8, ctx->r3) = ctx->r24;
    // 0x800C82C0: lw          $a0, 0xB8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XB8);
L_800C82C4:
    // 0x800C82C4: sltu        $at, $a0, $t1
    ctx->r1 = ctx->r4 < ctx->r9 ? 1 : 0;
    // 0x800C82C8: beql        $at, $zero, L_800C82DC
    if (ctx->r1 == 0) {
        // 0x800C82CC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800C82DC;
    }
    goto skip_2;
    // 0x800C82CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x800C82D0: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800C82D4: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x800C82D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800C82DC:
    // 0x800C82DC: bnel        $v0, $a1, L_800C8290
    if (ctx->r2 != ctx->r5) {
        // 0x800C82E0: lw          $t6, 0x4($t4)
        ctx->r14 = MEM_W(ctx->r12, 0X4);
            goto L_800C8290;
    }
    goto skip_3;
    // 0x800C82E0: lw          $t6, 0x4($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X4);
    skip_3:
    // 0x800C82E4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C82E8: jal         0x800C8140
    // 0x800C82EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_0;
    // 0x800C82EC: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_0:
    // 0x800C82F0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C82F4: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800C82F8: bne         $v0, $at, L_800C8464
    if (ctx->r2 != ctx->r1) {
        // 0x800C82FC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C8464;
    }
    // 0x800C82FC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C8300: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8304: jal         0x800C8140
    // 0x800C8308: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_1;
    // 0x800C8308: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_1:
    // 0x800C830C: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800C8310: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800C8314: bne         $v0, $at, L_800C8368
    if (ctx->r2 != ctx->r1) {
        // 0x800C8318: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800C8368;
    }
    // 0x800C8318: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C831C: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x800C8320: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C8324: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C8328: sb          $a2, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r6;
    // 0x800C832C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8330: jal         0x800C8140
    // 0x800C8334: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_2;
    // 0x800C8334: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x800C8338: sb          $v0, 0xB($s0)
    MEM_B(0XB, ctx->r16) = ctx->r2;
    // 0x800C833C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8340: jal         0x800C8140
    // 0x800C8344: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_3;
    // 0x800C8344: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_3:
    // 0x800C8348: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x800C834C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C8350: jal         0x800C8140
    // 0x800C8354: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_4;
    // 0x800C8354: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_4:
    // 0x800C8358: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x800C835C: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8360: b           L_800C8500
    // 0x800C8364: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
        goto L_800C8500;
    // 0x800C8364: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
L_800C8368:
    // 0x800C8368: addiu       $at, $zero, 0x2F
    ctx->r1 = ADD32(0, 0X2F);
    // 0x800C836C: bnel        $v1, $at, L_800C83A8
    if (ctx->r3 != ctx->r1) {
        // 0x800C8370: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800C83A8;
    }
    goto skip_4;
    // 0x800C8370: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_4:
    // 0x800C8374: lw          $t7, 0x4($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X4);
    // 0x800C8378: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C837C: sllv        $t9, $t8, $t3
    ctx->r25 = S32(ctx->r24 << (ctx->r11 & 31));
    // 0x800C8380: xor         $t6, $t7, $t9
    ctx->r14 = ctx->r15 ^ ctx->r25;
    // 0x800C8384: beq         $t6, $zero, L_800C8398
    if (ctx->r14 == 0) {
        // 0x800C8388: sw          $t6, 0x4($t4)
        MEM_W(0X4, ctx->r12) = ctx->r14;
            goto L_800C8398;
    }
    // 0x800C8388: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x800C838C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x800C8390: b           L_800C8500
    // 0x800C8394: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_800C8500;
    // 0x800C8394: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_800C8398:
    // 0x800C8398: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x800C839C: b           L_800C8500
    // 0x800C83A0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
        goto L_800C8500;
    // 0x800C83A0: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800C83A4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800C83A8:
    // 0x800C83A8: bne         $v1, $at, L_800C83D8
    if (ctx->r3 != ctx->r1) {
        // 0x800C83AC: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C83D8;
    }
    // 0x800C83AC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C83B0: jal         0x800C8140
    // 0x800C83B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_5;
    // 0x800C83B4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_5:
    // 0x800C83B8: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C83BC: jal         0x800C8140
    // 0x800C83C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_6;
    // 0x800C83C0: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_6:
    // 0x800C83C4: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C83C8: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C83CC: addiu       $t8, $zero, 0x13
    ctx->r24 = ADD32(0, 0X13);
    // 0x800C83D0: b           L_800C8500
    // 0x800C83D4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C8500;
    // 0x800C83D4: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C83D8:
    // 0x800C83D8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x800C83DC: bne         $v1, $at, L_800C8500
    if (ctx->r3 != ctx->r1) {
        // 0x800C83E0: sll         $t7, $t3, 2
        ctx->r15 = S32(ctx->r11 << 2);
            goto L_800C8500;
    }
    // 0x800C83E0: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800C83E4: addu        $t5, $t4, $t7
    ctx->r13 = ADD32(ctx->r12, ctx->r15);
    // 0x800C83E8: lw          $v0, 0x18($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X18);
    // 0x800C83EC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800C83F0: lbu         $a0, 0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X1);
    // 0x800C83F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C83F8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800C83FC: bne         $a0, $zero, L_800C8410
    if (ctx->r4 != 0) {
        // 0x800C8400: lbu         $a1, -0x1($v0)
        ctx->r5 = MEM_BU(ctx->r2, -0X1);
            goto L_800C8410;
    }
    // 0x800C8400: lbu         $a1, -0x1($v0)
    ctx->r5 = MEM_BU(ctx->r2, -0X1);
    // 0x800C8404: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800C8408: b           L_800C8450
    // 0x800C840C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
        goto L_800C8450;
    // 0x800C840C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C8410:
    // 0x800C8410: beq         $a0, $at, L_800C841C
    if (ctx->r4 == ctx->r1) {
        // 0x800C8414: addiu       $t6, $a0, -0x1
        ctx->r14 = ADD32(ctx->r4, -0X1);
            goto L_800C841C;
    }
    // 0x800C8414: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800C8418: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
L_800C841C:
    // 0x800C841C: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x800C8420: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x800C8424: lbu         $t6, 0x3($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X3);
    // 0x800C8428: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800C842C: sll         $t8, $v1, 24
    ctx->r24 = S32(ctx->r3 << 24);
    // 0x800C8430: lbu         $t7, 0x4($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X4);
    // 0x800C8434: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x800C8438: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800C843C: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800C8440: addiu       $v0, $v0, 0x5
    ctx->r2 = ADD32(ctx->r2, 0X5);
    // 0x800C8444: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C8448: subu        $t9, $v0, $v1
    ctx->r25 = SUB32(ctx->r2, ctx->r3);
    // 0x800C844C: sw          $t9, 0x18($t5)
    MEM_W(0X18, ctx->r13) = ctx->r25;
L_800C8450:
    // 0x800C8450: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8454: sb          $zero, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = 0;
    // 0x800C8458: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x800C845C: b           L_800C8500
    // 0x800C8460: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
        goto L_800C8500;
    // 0x800C8460: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_800C8464:
    // 0x800C8464: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C8468: andi        $t9, $v1, 0x80
    ctx->r25 = ctx->r3 & 0X80;
    // 0x800C846C: beq         $t9, $zero, L_800C8494
    if (ctx->r25 == 0) {
        // 0x800C8470: sh          $t7, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r15;
            goto L_800C8494;
    }
    // 0x800C8470: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800C8474: sb          $t2, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r10;
    // 0x800C8478: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C847C: jal         0x800C8140
    // 0x800C8480: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_7;
    // 0x800C8480: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_7:
    // 0x800C8484: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C8488: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x800C848C: b           L_800C84A4
    // 0x800C8490: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
        goto L_800C84A4;
    // 0x800C8490: sb          $t2, 0xA8($t6)
    MEM_B(0XA8, ctx->r14) = ctx->r10;
L_800C8494:
    // 0x800C8494: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x800C8498: lbu         $t7, 0xA8($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0XA8);
    // 0x800C849C: sb          $v0, 0x9($s0)
    MEM_B(0X9, ctx->r16) = ctx->r2;
    // 0x800C84A0: sb          $t7, 0x8($s0)
    MEM_B(0X8, ctx->r16) = ctx->r15;
L_800C84A4:
    // 0x800C84A4: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800C84A8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800C84AC: andi        $t9, $v0, 0xF0
    ctx->r25 = ctx->r2 & 0XF0;
    // 0x800C84B0: beq         $t9, $at, L_800C84FC
    if (ctx->r25 == ctx->r1) {
        // 0x800C84B4: addiu       $at, $zero, 0xD0
        ctx->r1 = ADD32(0, 0XD0);
            goto L_800C84FC;
    }
    // 0x800C84B4: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800C84B8: beq         $t9, $at, L_800C84FC
    if (ctx->r25 == ctx->r1) {
        // 0x800C84BC: or          $a0, $t4, $zero
        ctx->r4 = ctx->r12 | 0;
            goto L_800C84FC;
    }
    // 0x800C84BC: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800C84C0: jal         0x800C8140
    // 0x800C84C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    static_3_800C8140(rdram, ctx);
        goto after_8;
    // 0x800C84C4: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_8:
    // 0x800C84C8: lbu         $t6, 0x8($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X8);
    // 0x800C84CC: addiu       $at, $zero, 0x90
    ctx->r1 = ADD32(0, 0X90);
    // 0x800C84D0: sb          $v0, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r2;
    // 0x800C84D4: andi        $t8, $t6, 0xF0
    ctx->r24 = ctx->r14 & 0XF0;
    // 0x800C84D8: bne         $t8, $at, L_800C8500
    if (ctx->r24 != ctx->r1) {
        // 0x800C84DC: or          $t2, $t4, $zero
        ctx->r10 = ctx->r12 | 0;
            goto L_800C8500;
    }
    // 0x800C84DC: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C84E0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x800C84E4: jal         0x800C8204
    // 0x800C84E8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    static_3_800C8204(rdram, ctx);
        goto after_9;
    // 0x800C84E8: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    after_9:
    // 0x800C84EC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800C84F0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800C84F4: b           L_800C8500
    // 0x800C84F8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_800C8500;
    // 0x800C84F8: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800C84FC:
    // 0x800C84FC: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
L_800C8500:
    // 0x800C8500: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x800C8504: lw          $t7, 0xC($t4)
    ctx->r15 = MEM_W(ctx->r12, 0XC);
    // 0x800C8508: sw          $t1, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r9;
    // 0x800C850C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x800C8510: addu        $t9, $t7, $t1
    ctx->r25 = ADD32(ctx->r15, ctx->r9);
    // 0x800C8514: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
    // 0x800C8518: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x800C851C: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x800C8520: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x800C8524: beql        $t6, $at, L_800C8544
    if (ctx->r14 == ctx->r1) {
        // 0x800C8528: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800C8544;
    }
    goto skip_5;
    // 0x800C8528: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_5:
    // 0x800C852C: jal         0x800C8204
    // 0x800C8530: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    static_3_800C8204(rdram, ctx);
        goto after_10;
    // 0x800C8530: addu        $t5, $t4, $t8
    ctx->r13 = ADD32(ctx->r12, ctx->r24);
    after_10:
    // 0x800C8534: lw          $t7, 0xB8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0XB8);
    // 0x800C8538: addu        $t9, $t7, $v0
    ctx->r25 = ADD32(ctx->r15, ctx->r2);
    // 0x800C853C: sw          $t9, 0xB8($t5)
    MEM_W(0XB8, ctx->r13) = ctx->r25;
    // 0x800C8540: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800C8544:
    // 0x800C8544: sw          $t6, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r14;
    // 0x800C8548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C854C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C8550: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800C8554: jr          $ra
    // 0x800C8558: nop

    return;
    // 0x800C8558: nop

;}
RECOMP_FUNC void menu_logo_screen_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082FD4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082FD8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082FDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80082FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082FE4: bne         $t6, $zero, L_80083068
    if (ctx->r14 != 0) {
        // 0x80082FE8: sw          $a0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r4;
            goto L_80083068;
    }
    // 0x80082FE8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80082FEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082FF0: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x80082FF4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80082FF8: lwc1        $f4, -0x76E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76E4);
    // 0x80082FFC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80083000: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80083004: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x80083008: bc1f        L_80083040
    if (!c1cs) {
        // 0x8008300C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80083040;
    }
    // 0x8008300C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80083010: lw          $t8, -0x604($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X604);
    // 0x80083014: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083018: bne         $t8, $zero, L_80083044
    if (ctx->r24 != 0) {
        // 0x8008301C: lw          $t0, 0x30($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X30);
            goto L_80083044;
    }
    // 0x8008301C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80083020: jal         0x800C06F8
    // 0x80083024: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80083024: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    after_0:
    // 0x80083028: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008302C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80083030: sw          $t9, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r25;
    // 0x80083034: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083038: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008303C: nop

L_80083040:
    // 0x80083040: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
L_80083044:
    // 0x80083044: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80083048: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8008304C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80083050: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80083054: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083058: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8008305C: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x80083060: b           L_800830E0
    // 0x80083064: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
        goto L_800830E0;
    // 0x80083064: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
L_80083068:
    // 0x80083068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008306C: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x80083070: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083074: lwc1        $f4, -0x76E0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76E0);
    // 0x80083078: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8008307C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80083080: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80083084: bc1f        L_800830C0
    if (!c1cs) {
        // 0x80083088: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_800830C0;
    }
    // 0x80083088: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008308C: lw          $t1, -0x604($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X604);
    // 0x80083090: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80083094: bne         $t1, $zero, L_800830C0
    if (ctx->r9 != 0) {
        // 0x80083098: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_800830C0;
    }
    // 0x80083098: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8008309C: jal         0x800C06F8
    // 0x800830A0: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    transition_begin(rdram, ctx);
        goto after_1;
    // 0x800830A0: addiu       $a0, $a0, 0x2368
    ctx->r4 = ADD32(ctx->r4, 0X2368);
    after_1:
    // 0x800830A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800830A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800830AC: sw          $t2, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r10;
    // 0x800830B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830B4: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x800830B8: nop

    // 0x800830BC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_800830C0:
    // 0x800830C0: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800830C4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800830C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800830CC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800830D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830D4: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800830D8: sub.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800830DC: swc1        $f18, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->f18.u32l;
L_800830E0:
    // 0x800830E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800830E4: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x800830E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800830EC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800830F0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800830F4: nop

    // 0x800830F8: bc1f        L_80083144
    if (!c1cs) {
        // 0x800830FC: lui         $at, 0x4021
        ctx->r1 = S32(0X4021 << 16);
            goto L_80083144;
    }
    // 0x800830FC: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80083100: jal         0x80066AD4
    // 0x80083104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_2;
    // 0x80083104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80083108: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x8008310C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80083110: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80083114: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80083118: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x8008311C: jal         0x80066CE8
    // 0x80083120: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    set_viewport_properties(rdram, ctx);
        goto after_3;
    // 0x80083120: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    after_3:
    // 0x80083124: jal         0x800833FC
    // 0x80083128: nop

    init_title_screen_variables(rdram, ctx);
        goto after_4;
    // 0x80083128: nop

    after_4:
    // 0x8008312C: jal         0x80081820
    // 0x80083130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    menu_init(rdram, ctx);
        goto after_5;
    // 0x80083130: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80083134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083138: lwc1        $f0, 0x69F0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008313C: nop

    // 0x80083140: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
L_80083144:
    // 0x80083144: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80083148: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8008314C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80083150: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80083154: nop

    // 0x80083158: bc1f        L_800833F0
    if (!c1cs) {
        // 0x8008315C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800833F0;
    }
    // 0x8008315C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80083160: jal         0x800C484C
    // 0x80083164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x80083164: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80083168: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008316C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80083170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083174: jal         0x800C492C
    // 0x80083178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_7;
    // 0x80083178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x8008317C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80083180: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80083184: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083188: lwc1        $f10, 0x69F0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008318C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80083190: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80083194: c.lt.d      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.d < ctx->f12.d;
    // 0x80083198: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8008319C: bc1f        L_80083200
    if (!c1cs) {
        // 0x800831A0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_80083200;
    }
    // 0x800831A0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x800831A4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800831A8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800831AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800831B0: c.le.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d <= ctx->f0.d;
    // 0x800831B4: nop

    // 0x800831B8: bc1f        L_80083200
    if (!c1cs) {
        // 0x800831BC: nop
    
            goto L_80083200;
    }
    // 0x800831BC: nop

    // 0x800831C0: sub.d       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f12.d - ctx->f0.d;
    // 0x800831C4: lwc1        $f5, -0x76D8($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, -0X76D8);
    // 0x800831C8: lwc1        $f4, -0x76D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X76D4);
    // 0x800831CC: nop

    // 0x800831D0: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800831D4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800831D8: nop

    // 0x800831DC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800831E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800831E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800831E8: nop

    // 0x800831EC: cvt.w.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_D(ctx->f6.d);
    // 0x800831F0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800831F4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800831F8: b           L_8008327C
    // 0x800831FC: nop

        goto L_8008327C;
    // 0x800831FC: nop

L_80083200:
    // 0x80083200: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x80083204: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80083208: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008320C: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x80083210: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80083214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80083218: bc1f        L_8008327C
    if (!c1cs) {
        // 0x8008321C: nop
    
            goto L_8008327C;
    }
    // 0x8008321C: nop

    // 0x80083220: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80083224: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80083228: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008322C: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x80083230: nop

    // 0x80083234: bc1f        L_8008327C
    if (!c1cs) {
        // 0x80083238: nop
    
            goto L_8008327C;
    }
    // 0x80083238: nop

    // 0x8008323C: sub.d       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f0.d - ctx->f2.d;
    // 0x80083240: lwc1        $f19, -0x76D0($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X76D0);
    // 0x80083244: lwc1        $f18, -0x76CC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76CC);
    // 0x80083248: nop

    // 0x8008324C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80083250: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80083254: nop

    // 0x80083258: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8008325C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083260: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083264: nop

    // 0x80083268: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008326C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80083270: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80083274: b           L_8008327C
    // 0x80083278: nop

        goto L_8008327C;
    // 0x80083278: nop

L_8008327C:
    // 0x8008327C: beq         $v0, $zero, L_8008334C
    if (ctx->r2 == 0) {
        // 0x80083280: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_8008334C;
    }
    // 0x80083280: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80083284: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80083288: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008328C: jal         0x800C48E4
    // 0x80083290: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_8;
    // 0x80083290: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80083294: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083298: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008329C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832A0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800832A4: addiu       $a2, $a2, 0xD4
    ctx->r6 = ADD32(ctx->r6, 0XD4);
    // 0x800832A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800832AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800832B0: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832B4: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800832B8: jal         0x800C49A0
    // 0x800832BC: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    draw_text(rdram, ctx);
        goto after_9;
    // 0x800832BC: addiu       $a1, $zero, 0x9F
    ctx->r5 = ADD32(0, 0X9F);
    after_9:
    // 0x800832C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800832C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800832C8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832CC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x800832D0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800832D4: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832D8: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800832DC: jal         0x800C49A0
    // 0x800832E0: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    draw_text(rdram, ctx);
        goto after_10;
    // 0x800832E0: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    after_10:
    // 0x800832E4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800832E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800832EC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800832F0: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x800832F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800832F8: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800832FC: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80083300: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80083304: jal         0x800C49A0
    // 0x80083308: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    draw_text(rdram, ctx);
        goto after_11;
    // 0x80083308: addiu       $a2, $a2, 0xD3
    ctx->r6 = ADD32(ctx->r6, 0XD3);
    after_11:
    // 0x8008330C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80083310: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80083314: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80083318: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8008331C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80083320: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x80083324: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80083328: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8008332C: jal         0x800C49A0
    // 0x80083330: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    draw_text(rdram, ctx);
        goto after_12;
    // 0x80083330: addiu       $a2, $a2, 0xD5
    ctx->r6 = ADD32(ctx->r6, 0XD5);
    after_12:
    // 0x80083334: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80083338: lwc1        $f8, 0x69F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x8008333C: lui         $at, 0x4020
    ctx->r1 = S32(0X4020 << 16);
    // 0x80083340: mtc1        $at, $f13
    ctx->f_odd[(13 - 1) * 2] = ctx->r1;
    // 0x80083344: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80083348: cvt.d.s     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.d = CVT_D_S(ctx->f8.fl);
L_8008334C:
    // 0x8008334C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80083350: c.lt.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d < ctx->f0.d;
    // 0x80083354: addiu       $t2, $t1, 0xD4
    ctx->r10 = ADD32(ctx->r9, 0XD4);
    // 0x80083358: bc1f        L_800833AC
    if (!c1cs) {
        // 0x8008335C: sw          $t2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r10;
            goto L_800833AC;
    }
    // 0x8008335C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80083360: lui         $at, 0x4021
    ctx->r1 = S32(0X4021 << 16);
    // 0x80083364: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80083368: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8008336C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80083370: lwc1        $f19, -0x76C8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X76C8);
    // 0x80083374: lwc1        $f18, -0x76C4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X76C4);
    // 0x80083378: sub.d       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f10.d - ctx->f0.d;
    // 0x8008337C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80083380: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80083384: nop

    // 0x80083388: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x8008338C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80083390: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80083394: nop

    // 0x80083398: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8008339C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800833A0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800833A4: b           L_800833B4
    // 0x800833A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
        goto L_800833B4;
    // 0x800833A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800833AC:
    // 0x800833AC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800833B0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800833B4:
    // 0x800833B4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800833B8: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x800833BC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x800833C0: jal         0x800C48E4
    // 0x800833C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    set_text_colour(rdram, ctx);
        goto after_13;
    // 0x800833C4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
    // 0x800833C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800833CC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800833D0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800833D4: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x800833D8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800833DC: addiu       $a3, $a3, 0x2370
    ctx->r7 = ADD32(ctx->r7, 0X2370);
    // 0x800833E0: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x800833E4: jal         0x800C49A0
    // 0x800833E8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_14;
    // 0x800833E8: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_14:
    // 0x800833EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800833F0:
    // 0x800833F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800833F4: jr          $ra
    // 0x800833F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800833F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void transform_player_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E2B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000E2B8: addiu       $v1, $v1, -0x4D3C
    ctx->r3 = ADD32(ctx->r3, -0X4D3C);
    // 0x8000E2BC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E2C4: beq         $v0, $zero, L_8000E4AC
    if (ctx->r2 == 0) {
        // 0x8000E2C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000E4AC;
    }
    // 0x8000E2C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E2CC: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x8000E2D0: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
    // 0x8000E2D4: lb          $t7, 0x0($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X0);
    // 0x8000E2D8: nop

    // 0x8000E2DC: bne         $t7, $zero, L_8000E4B0
    if (ctx->r15 != 0) {
        // 0x8000E2E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E4B0;
    }
    // 0x8000E2E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000E2E4: jal         0x8006ECD0
    // 0x8000E2E8: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000E2E8: nop

    after_0:
    // 0x8000E2EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000E2F0: lb          $a0, -0x4D3B($a0)
    ctx->r4 = MEM_B(ctx->r4, -0X4D3B);
    // 0x8000E2F4: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000E2F8: slti        $at, $a0, 0x5
    ctx->r1 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8000E2FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8000E300: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x8000E304: beq         $at, $zero, L_8000E338
    if (ctx->r1 == 0) {
        // 0x8000E308: sb          $t8, 0x2D($sp)
        MEM_B(0X2D, ctx->r29) = ctx->r24;
            goto L_8000E338;
    }
    // 0x8000E308: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E30C: lb          $t9, 0x59($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X59);
    // 0x8000E310: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8000E314: addu        $t1, $t1, $a0
    ctx->r9 = ADD32(ctx->r9, ctx->r4);
    // 0x8000E318: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8000E31C: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8000E320: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x8000E324: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E328: addu        $v1, $v1, $t3
    ctx->r3 = ADD32(ctx->r3, ctx->r11);
    // 0x8000E32C: lh          $v1, -0x32E8($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X32E8);
    // 0x8000E330: b           L_8000E34C
    // 0x8000E334: nop

        goto L_8000E34C;
    // 0x8000E334: nop

L_8000E338:
    // 0x8000E338: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8000E33C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000E340: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x8000E344: lh          $v1, -0x328E($v1)
    ctx->r3 = MEM_H(ctx->r3, -0X328E);
    // 0x8000E348: nop

L_8000E34C:
    // 0x8000E34C: jal         0x8006DD54
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    set_level_default_vehicle(rdram, ctx);
        goto after_1;
    // 0x8000E350: sh          $v1, 0x22($sp)
    MEM_H(0X22, ctx->r29) = ctx->r3;
    after_1:
    // 0x8000E354: lh          $v1, 0x22($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X22);
    // 0x8000E358: lbu         $t5, 0x2D($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2D);
    // 0x8000E35C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E360: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000E364: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000E368: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8000E36C: andi        $t6, $v1, 0x100
    ctx->r14 = ctx->r3 & 0X100;
    // 0x8000E370: lh          $t9, -0x4D3A($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X4D3A);
    // 0x8000E374: lh          $t1, -0x4D38($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X4D38);
    // 0x8000E378: lh          $t0, -0x4D36($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X4D36);
    // 0x8000E37C: lh          $t2, -0x4D34($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X4D34);
    // 0x8000E380: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8000E384: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x8000E388: sb          $t8, 0x2D($sp)
    MEM_B(0X2D, ctx->r29) = ctx->r24;
    // 0x8000E38C: sh          $zero, 0x36($sp)
    MEM_H(0X36, ctx->r29) = 0;
    // 0x8000E390: sh          $zero, 0x34($sp)
    MEM_H(0X34, ctx->r29) = 0;
    // 0x8000E394: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000E398: sb          $v1, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r3;
    // 0x8000E39C: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    // 0x8000E3A0: sh          $t1, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r9;
    // 0x8000E3A4: sh          $t0, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r8;
    // 0x8000E3A8: jal         0x800521F8
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_2;
    // 0x8000E3AC: sh          $t2, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r10;
    after_2:
    // 0x8000E3B0: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8000E3B4: jal         0x8000EA54
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x8000E3B8: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    after_3:
    // 0x8000E3BC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E3C0: lw          $t4, -0x4B9C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B9C);
    // 0x8000E3C4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8000E3C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E3CC: sw          $t3, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = ctx->r11;
    // 0x8000E3D0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E3D4: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x8000E3D8: lw          $t6, -0x4B94($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B94);
    // 0x8000E3DC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E3E0: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000E3E4: lw          $t5, -0x4B98($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4B98);
    // 0x8000E3E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E3EC: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000E3F0: addiu       $a1, $a1, -0x4D3B
    ctx->r5 = ADD32(ctx->r5, -0X4D3B);
    // 0x8000E3F4: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000E3F8: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8000E3FC: nop

    // 0x8000E400: sb          $t7, 0x1D6($v1)
    MEM_B(0X1D6, ctx->r3) = ctx->r15;
    // 0x8000E404: lb          $t8, 0x0($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X0);
    // 0x8000E408: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8000E40C: sb          $t8, 0x1D7($v1)
    MEM_B(0X1D7, ctx->r3) = ctx->r24;
    // 0x8000E410: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8000E414: nop

    // 0x8000E418: lb          $t1, 0x59($t9)
    ctx->r9 = MEM_B(ctx->r25, 0X59);
    // 0x8000E41C: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000E420: sw          $zero, 0x118($v1)
    MEM_W(0X118, ctx->r3) = 0;
    // 0x8000E424: sb          $t1, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r9;
    // 0x8000E428: jal         0x8009C850
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    get_filtered_cheats(rdram, ctx);
        goto after_4;
    // 0x8000E42C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_4:
    // 0x8000E430: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E434: andi        $t0, $v0, 0x10
    ctx->r8 = ctx->r2 & 0X10;
    // 0x8000E438: beq         $t0, $zero, L_8000E454
    if (ctx->r8 == 0) {
        // 0x8000E43C: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000E454;
    }
    // 0x8000E43C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E440: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E444: lwc1        $f6, 0x573C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X573C);
    // 0x8000E448: nop

    // 0x8000E44C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000E450: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
L_8000E454:
    // 0x8000E454: jal         0x8009C850
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_5;
    // 0x8000E458: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_5:
    // 0x8000E45C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E460: andi        $t2, $v0, 0x20
    ctx->r10 = ctx->r2 & 0X20;
    // 0x8000E464: beq         $t2, $zero, L_8000E484
    if (ctx->r10 == 0) {
        // 0x8000E468: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8000E484;
    }
    // 0x8000E468: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E46C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000E470: lwc1        $f16, 0x5740($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X5740);
    // 0x8000E474: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8000E478: nop

    // 0x8000E47C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000E480: swc1        $f18, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f18.u32l;
L_8000E484:
    // 0x8000E484: sw          $zero, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = 0;
    // 0x8000E488: lh          $t3, -0x4D34($t3)
    ctx->r11 = MEM_H(ctx->r11, -0X4D34);
    // 0x8000E48C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000E490: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8000E494: lh          $t4, -0x4D38($t4)
    ctx->r12 = MEM_H(ctx->r12, -0X4D38);
    // 0x8000E498: nop

    // 0x8000E49C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8000E4A0: nop

    // 0x8000E4A4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000E4A8: swc1        $f6, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f6.u32l;
L_8000E4AC:
    // 0x8000E4AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E4B0:
    // 0x8000E4B0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000E4B4: jr          $ra
    // 0x8000E4B8: nop

    return;
    // 0x8000E4B8: nop

;}
RECOMP_FUNC void waves_visibility_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B90AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B90B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B90B4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B90B8: sw          $zero, 0x366C($at)
    MEM_W(0X366C, ctx->r1) = 0;
    // 0x800B90BC: addiu       $a1, $a1, -0x5964
    ctx->r5 = ADD32(ctx->r5, -0X5964);
    // 0x800B90C0: addiu       $a0, $a0, -0x5968
    ctx->r4 = ADD32(ctx->r4, -0X5968);
    // 0x800B90C4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B90C8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800B90CC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B90D0: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B90D4: addiu       $a2, $a2, 0x3664
    ctx->r6 = ADD32(ctx->r6, 0X3664);
    // 0x800B90D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B90DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B90E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800B90E4: blez        $t8, L_800B911C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800B90E8: nop
    
            goto L_800B911C;
    }
    // 0x800B90E8: nop

L_800B90EC:
    // 0x800B90EC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B90F0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B90F4: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800B90F8: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800B90FC: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800B9100: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800B9104: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800B9108: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B910C: mflo        $t3
    ctx->r11 = lo;
    // 0x800B9110: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B9114: bne         $at, $zero, L_800B90EC
    if (ctx->r1 != 0) {
        // 0x800B9118: nop
    
            goto L_800B90EC;
    }
    // 0x800B9118: nop

L_800B911C:
    // 0x800B911C: jr          $ra
    // 0x800B9120: nop

    return;
    // 0x800B9120: nop

;}
RECOMP_FUNC void debug_text_parse(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6A9C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800B6AA0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B6AA4: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B6AA8: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B6AAC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B6AB0: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B6AB4: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B6AB8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B6ABC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B6AC0: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B6AC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B6AC8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800B6ACC: lbu         $s1, 0x0($a1)
    ctx->r17 = MEM_BU(ctx->r5, 0X0);
    // 0x800B6AD0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x800B6AD4: beq         $s1, $zero, L_800B6E84
    if (ctx->r17 == 0) {
        // 0x800B6AD8: addiu       $s0, $a1, 0x1
        ctx->r16 = ADD32(ctx->r5, 0X1);
            goto L_800B6E84;
    }
    // 0x800B6AD8: addiu       $s0, $a1, 0x1
    ctx->r16 = ADD32(ctx->r5, 0X1);
    // 0x800B6ADC: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800B6AE0: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800B6AE4: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800B6AE8: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B6AEC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B6AF0: addiu       $s2, $s2, -0x7D94
    ctx->r18 = ADD32(ctx->r18, -0X7D94);
    // 0x800B6AF4: addiu       $s4, $s4, -0x7D92
    ctx->r20 = ADD32(ctx->r20, -0X7D92);
    // 0x800B6AF8: addiu       $s6, $s6, -0x7D90
    ctx->r22 = ADD32(ctx->r22, -0X7D90);
    // 0x800B6AFC: addiu       $s7, $s7, -0x7D8E
    ctx->r23 = ADD32(ctx->r23, -0X7D8E);
    // 0x800B6B00: addiu       $fp, $fp, -0x7D88
    ctx->r30 = ADD32(ctx->r30, -0X7D88);
    // 0x800B6B04: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B6B08:
    // 0x800B6B08: bne         $at, $zero, L_800B6B54
    if (ctx->r1 != 0) {
        // 0x800B6B0C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B6B54;
    }
    // 0x800B6B0C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B6B10: slti        $at, $s1, 0x21
    ctx->r1 = SIGNED(ctx->r17) < 0X21 ? 1 : 0;
    // 0x800B6B14: bne         $at, $zero, L_800B6B40
    if (ctx->r1 != 0) {
        // 0x800B6B18: addiu       $t6, $s1, -0x81
        ctx->r14 = ADD32(ctx->r17, -0X81);
            goto L_800B6B40;
    }
    // 0x800B6B18: addiu       $t6, $s1, -0x81
    ctx->r14 = ADD32(ctx->r17, -0X81);
    // 0x800B6B1C: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x800B6B20: beq         $at, $zero, L_800B6DDC
    if (ctx->r1 == 0) {
        // 0x800B6B24: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800B6DDC;
    }
    // 0x800B6B24: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B6B28: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B6B2C: addu        $at, $at, $t6
    gpr jr_addend_800B6B38 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B6B30: lw          $t6, -0x6C28($at)
    ctx->r14 = ADD32(ctx->r1, -0X6C28);
    // 0x800B6B34: nop

    // 0x800B6B38: jr          $t6
    // 0x800B6B3C: nop

    switch (jr_addend_800B6B38 >> 2) {
        case 0: goto L_800B6BB8; break;
        case 1: goto L_800B6CA0; break;
        case 2: goto L_800B6B74; break;
        case 3: goto L_800B6B94; break;
        case 4: goto L_800B6C2C; break;
        default: switch_error(__func__, 0x800B6B38, 0x800E93D8);
    }
    // 0x800B6B3C: nop

L_800B6B40:
    // 0x800B6B40: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800B6B44: beq         $s1, $at, L_800B6D24
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B48: addiu       $s3, $zero, 0x6
        ctx->r19 = ADD32(0, 0X6);
            goto L_800B6D24;
    }
    // 0x800B6B48: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x800B6B4C: b           L_800B6DE0
    // 0x800B6B50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6DE0;
    // 0x800B6B50: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6B54:
    // 0x800B6B54: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800B6B58: beq         $s1, $at, L_800B6D9C
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B5C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800B6D9C;
    }
    // 0x800B6B5C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6B60: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800B6B64: beq         $s1, $at, L_800B6D40
    if (ctx->r17 == ctx->r1) {
        // 0x800B6B68: nop
    
            goto L_800B6D40;
    }
    // 0x800B6B68: nop

    // 0x800B6B6C: b           L_800B6DE0
    // 0x800B6B70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
        goto L_800B6DE0;
    // 0x800B6B70: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6B74:
    // 0x800B6B74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6B78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6B7C: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6B80: sw          $zero, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = 0;
    // 0x800B6B84: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6B88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B6B8C: b           L_800B6E04
    // 0x800B6B90: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6B90: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6B94:
    // 0x800B6B94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800B6B98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6B9C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6BA0: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6BA4: sw          $t7, -0x7D8C($at)
    MEM_W(-0X7D8C, ctx->r1) = ctx->r15;
    // 0x800B6BA8: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6BAC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B6BB0: b           L_800B6E04
    // 0x800B6BB4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6BB4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6BB8:
    // 0x800B6BB8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B6BBC: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6BC0: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6BC4: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6BC8: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6BCC: beq         $t8, $zero, L_800B6C10
    if (ctx->r24 == 0) {
        // 0x800B6BD0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B6C10;
    }
    // 0x800B6BD0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6BD4: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B6BD8: andi        $t3, $a1, 0xFF
    ctx->r11 = ctx->r5 & 0XFF;
    // 0x800B6BDC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800B6BE0: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x800B6BE4: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800B6BE8: sll         $t2, $a0, 24
    ctx->r10 = S32(ctx->r4 << 24);
    // 0x800B6BEC: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x800B6BF0: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800B6BF4: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x800B6BF8: lui         $t0, 0xFB00
    ctx->r8 = S32(0XFB00 << 16);
    // 0x800B6BFC: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800B6C00: andi        $t9, $a3, 0xFF
    ctx->r25 = ctx->r7 & 0XFF;
    // 0x800B6C04: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800B6C08: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800B6C0C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
L_800B6C10:
    // 0x800B6C10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6C14: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6C18: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6C1C: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6C20: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6C24: b           L_800B6E04
    // 0x800B6C28: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6C28: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6C2C:
    // 0x800B6C2C: lw          $t1, 0x0($fp)
    ctx->r9 = MEM_W(ctx->r30, 0X0);
    // 0x800B6C30: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6C34: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6C38: lbu         $a2, 0x2($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6C3C: lbu         $a3, 0x3($s0)
    ctx->r7 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6C40: bne         $t1, $zero, L_800B6C84
    if (ctx->r9 != 0) {
        // 0x800B6C44: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800B6C84;
    }
    // 0x800B6C44: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6C48: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800B6C4C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800B6C50: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800B6C54: sw          $t3, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r11;
    // 0x800B6C58: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800B6C5C: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800B6C60: andi        $t9, $a2, 0xFF
    ctx->r25 = ctx->r6 & 0XFF;
    // 0x800B6C64: sll         $t0, $t9, 8
    ctx->r8 = S32(ctx->r25 << 8);
    // 0x800B6C68: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800B6C6C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800B6C70: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x800B6C74: andi        $t3, $a3, 0xFF
    ctx->r11 = ctx->r7 & 0XFF;
    // 0x800B6C78: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800B6C7C: or          $t2, $t1, $t3
    ctx->r10 = ctx->r9 | ctx->r11;
    // 0x800B6C80: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
L_800B6C84:
    // 0x800B6C84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6C88: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6C8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6C90: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6C94: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6C98: b           L_800B6E04
    // 0x800B6C9C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6C9C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6CA0:
    // 0x800B6CA0: lw          $t4, 0x0($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X0);
    // 0x800B6CA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6CA8: bne         $t4, $zero, L_800B6CCC
    if (ctx->r12 != 0) {
        // 0x800B6CAC: nop
    
            goto L_800B6CCC;
    }
    // 0x800B6CAC: nop

    // 0x800B6CB0: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6CB4: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6CB8: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6CBC: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6CC0: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6CC4: jal         0x800B6EBC
    // 0x800B6CC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_0;
    // 0x800B6CC8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
L_800B6CCC:
    // 0x800B6CCC: lbu         $t9, 0x0($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6CD0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6CD4: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800B6CD8: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800B6CDC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6CE0: sll         $t0, $t8, 8
    ctx->r8 = S32(ctx->r24 << 8);
    // 0x800B6CE4: or          $t1, $t9, $t0
    ctx->r9 = ctx->r25 | ctx->r8;
    // 0x800B6CE8: sh          $t1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r9;
    // 0x800B6CEC: lbu         $t2, 0x2($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X2);
    // 0x800B6CF0: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x800B6CF4: sh          $t2, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r10;
    // 0x800B6CF8: lbu         $t4, 0x3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X3);
    // 0x800B6CFC: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B6D00: sll         $t5, $t4, 8
    ctx->r13 = S32(ctx->r12 << 8);
    // 0x800B6D04: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800B6D08: sh          $t7, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r15;
    // 0x800B6D0C: sh          $t7, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r15;
    // 0x800B6D10: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D14: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D18: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800B6D1C: b           L_800B6E04
    // 0x800B6D20: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D20: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D24:
    // 0x800B6D24: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6D28: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D2C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6D30: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D34: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D38: b           L_800B6E04
    // 0x800B6D3C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D3C: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D40:
    // 0x800B6D40: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800B6D44: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6D48: bne         $t8, $zero, L_800B6D6C
    if (ctx->r24 != 0) {
        // 0x800B6D4C: nop
    
            goto L_800B6D6C;
    }
    // 0x800B6D4C: nop

    // 0x800B6D50: lhu         $t9, 0x0($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6D54: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6D58: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6D5C: lhu         $a3, 0x0($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D60: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x800B6D64: jal         0x800B6EBC
    // 0x800B6D68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    debug_text_background(rdram, ctx);
        goto after_1;
    // 0x800B6D68: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_1:
L_800B6D6C:
    // 0x800B6D6C: jal         0x800B7464
    // 0x800B6D70: nop

    debug_text_newline(rdram, ctx);
        goto after_2;
    // 0x800B6D70: nop

    after_2:
    // 0x800B6D74: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6D78: lhu         $t1, 0x0($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6D7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6D80: sh          $a0, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r4;
    // 0x800B6D84: sh          $t1, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r9;
    // 0x800B6D88: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6D8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6D90: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6D94: b           L_800B6E04
    // 0x800B6D98: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
        goto L_800B6E04;
    // 0x800B6D98: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6D9C:
    // 0x800B6D9C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6DA0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6DA4: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6DA8: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6DAC: bgez        $a0, L_800B6DC0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800B6DB0: andi        $v0, $a0, 0x1F
        ctx->r2 = ctx->r4 & 0X1F;
            goto L_800B6DC0;
    }
    // 0x800B6DB0: andi        $v0, $a0, 0x1F
    ctx->r2 = ctx->r4 & 0X1F;
    // 0x800B6DB4: beq         $v0, $zero, L_800B6DC0
    if (ctx->r2 == 0) {
        // 0x800B6DB8: nop
    
            goto L_800B6DC0;
    }
    // 0x800B6DB8: nop

    // 0x800B6DBC: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
L_800B6DC0:
    // 0x800B6DC0: bne         $v0, $zero, L_800B6DD0
    if (ctx->r2 != 0) {
        // 0x800B6DC4: addiu       $a1, $a1, -0x10
        ctx->r5 = ADD32(ctx->r5, -0X10);
            goto L_800B6DD0;
    }
    // 0x800B6DC4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800B6DC8: b           L_800B6E04
    // 0x800B6DCC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
        goto L_800B6E04;
    // 0x800B6DCC: addiu       $s3, $zero, 0x20
    ctx->r19 = ADD32(0, 0X20);
L_800B6DD0:
    // 0x800B6DD0: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800B6DD4: b           L_800B6E04
    // 0x800B6DD8: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
        goto L_800B6E04;
    // 0x800B6DD8: subu        $s3, $t3, $v0
    ctx->r19 = SUB32(ctx->r11, ctx->r2);
L_800B6DDC:
    // 0x800B6DDC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_800B6DE0:
    // 0x800B6DE0: jal         0x800B6F5C
    // 0x800B6DE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    debug_text_character(rdram, ctx);
        goto after_3;
    // 0x800B6DE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800B6DE8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6DEC: lhu         $a1, -0x7D70($a1)
    ctx->r5 = MEM_HU(ctx->r5, -0X7D70);
    // 0x800B6DF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800B6DF4: lw          $v1, -0x7D8C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7D8C);
    // 0x800B6DF8: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6DFC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800B6E00: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
L_800B6E04:
    // 0x800B6E04: beq         $v1, $zero, L_800B6E20
    if (ctx->r3 == 0) {
        // 0x800B6E08: slti        $at, $s1, 0x20
        ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
            goto L_800B6E20;
    }
    // 0x800B6E08: slti        $at, $s1, 0x20
    ctx->r1 = SIGNED(ctx->r17) < 0X20 ? 1 : 0;
    // 0x800B6E0C: bne         $at, $zero, L_800B6E20
    if (ctx->r1 != 0) {
        // 0x800B6E10: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_800B6E20;
    }
    // 0x800B6E10: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    // 0x800B6E14: beq         $at, $zero, L_800B6E24
    if (ctx->r1 == 0) {
        // 0x800B6E18: addu        $t4, $a0, $s3
        ctx->r12 = ADD32(ctx->r4, ctx->r19);
            goto L_800B6E24;
    }
    // 0x800B6E18: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
    // 0x800B6E1C: addiu       $s3, $zero, 0x7
    ctx->r19 = ADD32(0, 0X7);
L_800B6E20:
    // 0x800B6E20: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
L_800B6E24:
    // 0x800B6E24: andi        $a3, $t4, 0xFFFF
    ctx->r7 = ctx->r12 & 0XFFFF;
    // 0x800B6E28: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B6E2C: beq         $at, $zero, L_800B6E74
    if (ctx->r1 == 0) {
        // 0x800B6E30: sh          $t4, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r12;
            goto L_800B6E74;
    }
    // 0x800B6E30: sh          $t4, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r12;
    // 0x800B6E34: lw          $t2, 0x0($fp)
    ctx->r10 = MEM_W(ctx->r30, 0X0);
    // 0x800B6E38: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800B6E3C: bne         $t2, $zero, L_800B6E5C
    if (ctx->r10 != 0) {
        // 0x800B6E40: nop
    
            goto L_800B6E5C;
    }
    // 0x800B6E40: nop

    // 0x800B6E44: lhu         $t5, 0x0($s4)
    ctx->r13 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6E48: lhu         $a1, 0x0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X0);
    // 0x800B6E4C: lhu         $a2, 0x0($s7)
    ctx->r6 = MEM_HU(ctx->r23, 0X0);
    // 0x800B6E50: addiu       $t6, $t5, 0xA
    ctx->r14 = ADD32(ctx->r13, 0XA);
    // 0x800B6E54: jal         0x800B6EBC
    // 0x800B6E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    debug_text_background(rdram, ctx);
        goto after_4;
    // 0x800B6E58: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
L_800B6E5C:
    // 0x800B6E5C: jal         0x800B7464
    // 0x800B6E60: nop

    debug_text_newline(rdram, ctx);
        goto after_5;
    // 0x800B6E60: nop

    after_5:
    // 0x800B6E64: lhu         $t7, 0x0($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X0);
    // 0x800B6E68: lhu         $t8, 0x0($s4)
    ctx->r24 = MEM_HU(ctx->r20, 0X0);
    // 0x800B6E6C: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x800B6E70: sh          $t8, 0x0($s7)
    MEM_H(0X0, ctx->r23) = ctx->r24;
L_800B6E74:
    // 0x800B6E74: lbu         $s1, 0x0($s0)
    ctx->r17 = MEM_BU(ctx->r16, 0X0);
    // 0x800B6E78: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800B6E7C: bne         $s1, $zero, L_800B6B08
    if (ctx->r17 != 0) {
        // 0x800B6E80: slti        $at, $s1, 0xB
        ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
            goto L_800B6B08;
    }
    // 0x800B6E80: slti        $at, $s1, 0xB
    ctx->r1 = SIGNED(ctx->r17) < 0XB ? 1 : 0;
L_800B6E84:
    // 0x800B6E84: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x800B6E88: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B6E8C: subu        $v0, $s0, $t9
    ctx->r2 = SUB32(ctx->r16, ctx->r25);
    // 0x800B6E90: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B6E94: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B6E98: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B6E9C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B6EA0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B6EA4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B6EA8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B6EAC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B6EB0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B6EB4: jr          $ra
    // 0x800B6EB8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800B6EB8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void thread0_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B74B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B74B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B74B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B74BC: addiu       $t6, $t6, -0x6460
    ctx->r14 = ADD32(ctx->r14, -0X6460);
    // 0x800B74C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74C4: lui         $a2, 0x800B
    ctx->r6 = S32(0X800B << 16);
    // 0x800B74C8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800B74CC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800B74D0: addiu       $a2, $a2, 0x7524
    ctx->r6 = ADD32(ctx->r6, 0X7524);
    // 0x800B74D4: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    // 0x800B74D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800B74DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B74E0: jal         0x800C8DB0
    // 0x800B74E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800B74E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800B74E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74EC: jal         0x800C8F00
    // 0x800B74F0: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    osStartThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B74F0: addiu       $a0, $a0, -0x6460
    ctx->r4 = ADD32(ctx->r4, -0X6460);
    after_1:
    // 0x800B74F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B74F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800B74FC: addiu       $a0, $a0, -0x5A84
    ctx->r4 = ADD32(ctx->r4, -0X5A84);
    // 0x800B7500: addiu       $v0, $v0, -0x5A90
    ctx->r2 = ADD32(ctx->r2, -0X5A90);
    // 0x800B7504: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800B7508:
    // 0x800B7508: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800B750C: bne         $v0, $a0, L_800B7508
    if (ctx->r2 != ctx->r4) {
        // 0x800B7510: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800B7508;
    }
    // 0x800B7510: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800B7514: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7518: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800B751C: jr          $ra
    // 0x800B7520: nop

    return;
    // 0x800B7520: nop

;}
RECOMP_FUNC void alUnlink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8CC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C8CC4: beql        $v0, $zero, L_800C8CD8
    if (ctx->r2 == 0) {
        // 0x800C8CC8: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_800C8CD8;
    }
    goto skip_0;
    // 0x800C8CC8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800C8CCC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800C8CD0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800C8CD4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_800C8CD8:
    // 0x800C8CD8: beq         $v0, $zero, L_800C8CE8
    if (ctx->r2 == 0) {
        // 0x800C8CDC: nop
    
            goto L_800C8CE8;
    }
    // 0x800C8CDC: nop

    // 0x800C8CE0: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800C8CE4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800C8CE8:
    // 0x800C8CE8: jr          $ra
    // 0x800C8CEC: nop

    return;
    // 0x800C8CEC: nop

;}
RECOMP_FUNC void timetrial_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800599F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800599FC: lh          $v0, -0x24D4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X24D4);
    // 0x80059A00: jr          $ra
    // 0x80059A04: nop

    return;
    // 0x80059A04: nop

;}
RECOMP_FUNC void clear_object_pointers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C460: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000C464: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C468: sb          $v0, -0x4D5A($at)
    MEM_B(-0X4D5A, ctx->r1) = ctx->r2;
    // 0x8000C46C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C470: sw          $zero, -0x4D24($at)
    MEM_W(-0X4D24, ctx->r1) = 0;
    // 0x8000C474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C478: sw          $zero, -0x4D20($at)
    MEM_W(-0X4D20, ctx->r1) = 0;
    // 0x8000C47C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C480: sw          $zero, -0x4BB8($at)
    MEM_W(-0X4BB8, ctx->r1) = 0;
    // 0x8000C484: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C488: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x8000C48C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C490: sw          $zero, -0x4BB0($at)
    MEM_W(-0X4BB0, ctx->r1) = 0;
    // 0x8000C494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C498: sw          $zero, -0x4BAC($at)
    MEM_W(-0X4BAC, ctx->r1) = 0;
    // 0x8000C49C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A0: sw          $zero, -0x4B90($at)
    MEM_W(-0X4B90, ctx->r1) = 0;
    // 0x8000C4A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4A8: sh          $zero, -0x4C08($at)
    MEM_H(-0X4C08, ctx->r1) = 0;
    // 0x8000C4AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000C4B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C4B4: addiu       $a1, $a1, -0x4D5E
    ctx->r5 = ADD32(ctx->r5, -0X4D5E);
    // 0x8000C4B8: sb          $zero, -0x4D5F($at)
    MEM_B(-0X4D5F, ctx->r1) = 0;
    // 0x8000C4BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C4C0: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000C4C4: sb          $zero, 0x1($a1)
    MEM_B(0X1, ctx->r5) = 0;
    // 0x8000C4C8: addiu       $v1, $v1, -0x4B7C
    ctx->r3 = ADD32(ctx->r3, -0X4B7C);
    // 0x8000C4CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000C4D0:
    // 0x8000C4D0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C4D4: nop

    // 0x8000C4D8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C4DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000C4E0: slti        $at, $a0, 0x200
    ctx->r1 = SIGNED(ctx->r4) < 0X200 ? 1 : 0;
    // 0x8000C4E4: bne         $at, $zero, L_8000C4D0
    if (ctx->r1 != 0) {
        // 0x8000C4E8: sw          $zero, 0x0($t7)
        MEM_W(0X0, ctx->r15) = 0;
            goto L_8000C4D0;
    }
    // 0x8000C4E8: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x8000C4EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000C4F0: addiu       $a0, $a0, -0x4CB4
    ctx->r4 = ADD32(ctx->r4, -0X4CB4);
    // 0x8000C4F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000C4F8:
    // 0x8000C4F8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8000C4FC: nop

    // 0x8000C500: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8000C504: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000C508: slti        $at, $v1, 0x8
    ctx->r1 = SIGNED(ctx->r3) < 0X8 ? 1 : 0;
    // 0x8000C50C: bne         $at, $zero, L_8000C4F8
    if (ctx->r1 != 0) {
        // 0x8000C510: sb          $zero, 0x0($t9)
        MEM_B(0X0, ctx->r25) = 0;
            goto L_8000C4F8;
    }
    // 0x8000C510: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x8000C514: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C518: addiu       $v1, $v1, -0x4A8C
    ctx->r3 = ADD32(ctx->r3, -0X4A8C);
    // 0x8000C51C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000C520: addiu       $a1, $zero, 0x400
    ctx->r5 = ADD32(0, 0X400);
L_8000C524:
    // 0x8000C524: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8000C528: nop

    // 0x8000C52C: addu        $t1, $t0, $a0
    ctx->r9 = ADD32(ctx->r8, ctx->r4);
    // 0x8000C530: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8000C534: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8000C538: nop

    // 0x8000C53C: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x8000C540: sw          $zero, 0x40($t3)
    MEM_W(0X40, ctx->r11) = 0;
    // 0x8000C544: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8000C548: nop

    // 0x8000C54C: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8000C550: sw          $zero, 0x80($t5)
    MEM_W(0X80, ctx->r13) = 0;
    // 0x8000C554: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8000C558: nop

    // 0x8000C55C: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8000C560: addiu       $a0, $a0, 0x100
    ctx->r4 = ADD32(ctx->r4, 0X100);
    // 0x8000C564: bne         $a0, $a1, L_8000C524
    if (ctx->r4 != ctx->r5) {
        // 0x8000C568: sw          $zero, 0xC0($t7)
        MEM_W(0XC0, ctx->r15) = 0;
            goto L_8000C524;
    }
    // 0x8000C568: sw          $zero, 0xC0($t7)
    MEM_W(0XC0, ctx->r15) = 0;
    // 0x8000C56C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000C570: addiu       $v1, $v1, -0x4B78
    ctx->r3 = ADD32(ctx->r3, -0X4B78);
    // 0x8000C574: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8000C578: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x8000C57C: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x8000C580: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C584: sw          $zero, -0x4C24($at)
    MEM_W(-0X4C24, ctx->r1) = 0;
    // 0x8000C588: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C58C: sw          $zero, -0x4C20($at)
    MEM_W(-0X4C20, ctx->r1) = 0;
    // 0x8000C590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C594: sw          $zero, -0x4C1C($at)
    MEM_W(-0X4C1C, ctx->r1) = 0;
    // 0x8000C598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C59C: sw          $zero, -0x4BF8($at)
    MEM_W(-0X4BF8, ctx->r1) = 0;
    // 0x8000C5A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5A4: sb          $zero, -0x4CAC($at)
    MEM_B(-0X4CAC, ctx->r1) = 0;
    // 0x8000C5A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5AC: sh          $zero, -0x4C06($at)
    MEM_H(-0X4C06, ctx->r1) = 0;
    // 0x8000C5B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5B4: sb          $v0, -0x4C02($at)
    MEM_B(-0X4C02, ctx->r1) = ctx->r2;
    // 0x8000C5B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5BC: sh          $zero, -0x4C04($at)
    MEM_H(-0X4C04, ctx->r1) = 0;
    // 0x8000C5C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5C4: sb          $zero, -0x4D3C($at)
    MEM_B(-0X4D3C, ctx->r1) = 0;
    // 0x8000C5C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5CC: sb          $zero, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = 0;
    // 0x8000C5D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5D4: sb          $zero, -0x4B89($at)
    MEM_B(-0X4B89, ctx->r1) = 0;
    // 0x8000C5D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5DC: sw          $zero, -0x4B20($at)
    MEM_W(-0X4B20, ctx->r1) = 0;
    // 0x8000C5E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5E4: sb          $zero, -0x4C80($at)
    MEM_B(-0X4C80, ctx->r1) = 0;
    // 0x8000C5E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5EC: sb          $v0, -0x4C7F($at)
    MEM_B(-0X4C7F, ctx->r1) = ctx->r2;
    // 0x8000C5F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5F4: sb          $zero, -0x4D2D($at)
    MEM_B(-0X4D2D, ctx->r1) = 0;
    // 0x8000C5F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C5FC: jr          $ra
    // 0x8000C600: sb          $zero, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = 0;
    return;
    // 0x8000C600: sb          $zero, -0x4CAB($at)
    MEM_B(-0X4CAB, ctx->r1) = 0;
;}
RECOMP_FUNC void update_bubbler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005E660: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005E664: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8005E668: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005E66C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005E670: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005E674: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005E678: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005E67C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005E680: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005E684: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005E688: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005E68C: jal         0x8005CC18
    // 0x8005E690: addiu       $a0, $a0, -0x2C50
    ctx->r4 = ADD32(ctx->r4, -0X2C50);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005E690: addiu       $a0, $a0, -0x2C50
    ctx->r4 = ADD32(ctx->r4, -0X2C50);
    after_0:
    // 0x8005E694: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005E698: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E69C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005E6A0: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005E6A4: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005E6A8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005E6AC: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005E6B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005E6B4: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005E6B8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005E6BC: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E6C0: nop

    // 0x8005E6C4: sh          $t2, 0x56($sp)
    MEM_H(0X56, ctx->r29) = ctx->r10;
    // 0x8005E6C8: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005E6CC: nop

    // 0x8005E6D0: sh          $t3, 0x54($sp)
    MEM_H(0X54, ctx->r29) = ctx->r11;
    // 0x8005E6D4: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005E6D8: nop

    // 0x8005E6DC: sh          $t4, 0x52($sp)
    MEM_H(0X52, ctx->r29) = ctx->r12;
    // 0x8005E6E0: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E6E4: nop

    // 0x8005E6E8: bne         $t5, $at, L_8005E70C
    if (ctx->r13 != ctx->r1) {
        // 0x8005E6EC: lw          $t1, 0x70($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X70);
            goto L_8005E70C;
    }
    // 0x8005E6EC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E6F0: jal         0x80021434
    // 0x8005E6F4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_1;
    // 0x8005E6F4: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_1:
    // 0x8005E6F8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005E6FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E700: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005E704: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005E708: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
L_8005E70C:
    // 0x8005E70C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005E710: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005E714: nop

    // 0x8005E718: bne         $v1, $a0, L_8005E724
    if (ctx->r3 != ctx->r4) {
        // 0x8005E71C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005E724;
    }
    // 0x8005E71C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E720: sb          $zero, -0x2490($at)
    MEM_B(-0X2490, ctx->r1) = 0;
L_8005E724:
    // 0x8005E724: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005E728: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E72C: bne         $t0, $t8, L_8005E7A8
    if (ctx->r8 != ctx->r24) {
        // 0x8005E730: nop
    
            goto L_8005E7A8;
    }
    // 0x8005E730: nop

    // 0x8005E734: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005E738: nop

    // 0x8005E73C: beq         $a0, $v0, L_8005E7A8
    if (ctx->r4 == ctx->r2) {
        // 0x8005E740: addiu       $t9, $v0, -0x1E
        ctx->r25 = ADD32(ctx->r2, -0X1E);
            goto L_8005E7A8;
    }
    // 0x8005E740: addiu       $t9, $v0, -0x1E
    ctx->r25 = ADD32(ctx->r2, -0X1E);
    // 0x8005E744: bgez        $t9, L_8005E7A0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005E748: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005E7A0;
    }
    // 0x8005E748: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005E74C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005E750: lb          $t3, -0x248F($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X248F);
    // 0x8005E754: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005E758: bne         $t3, $zero, L_8005E780
    if (ctx->r11 != 0) {
        // 0x8005E75C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005E780;
    }
    // 0x8005E75C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005E760: jal         0x8005CCA4
    // 0x8005E764: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_2;
    // 0x8005E764: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_2:
    // 0x8005E768: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E76C: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8005E770: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E774: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8005E778: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005E77C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005E780:
    // 0x8005E780: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E784: sb          $t5, -0x248F($at)
    MEM_B(-0X248F, ctx->r1) = ctx->r13;
    // 0x8005E788: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005E78C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005E790: nop

    // 0x8005E794: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005E798: b           L_8005E7A8
    // 0x8005E79C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005E7A8;
    // 0x8005E79C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005E7A0:
    // 0x8005E7A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005E7A4: sb          $zero, -0x248F($at)
    MEM_B(-0X248F, ctx->r1) = 0;
L_8005E7A8:
    // 0x8005E7A8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x8005E7AC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005E7B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005E7B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005E7B8: jal         0x8004F834
    // 0x8005E7BC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_3;
    // 0x8005E7BC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005E7C0: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x8005E7C4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8005E7C8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E7CC: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005E7D0: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005E7D4: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8005E7D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E7DC: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005E7E0: lh          $t9, 0x56($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X56);
    // 0x8005E7E4: nop

    // 0x8005E7E8: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E7EC: lh          $t2, 0x54($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X54);
    // 0x8005E7F0: nop

    // 0x8005E7F4: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005E7F8: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005E7FC: nop

    // 0x8005E800: beq         $t3, $zero, L_8005E890
    if (ctx->r11 == 0) {
        // 0x8005E804: nop
    
            goto L_8005E890;
    }
    // 0x8005E804: nop

    // 0x8005E808: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E80C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E810: beq         $v0, $at, L_8005E890
    if (ctx->r2 == ctx->r1) {
        // 0x8005E814: addiu       $t4, $zero, 0x2
        ctx->r12 = ADD32(0, 0X2);
            goto L_8005E890;
    }
    // 0x8005E814: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8005E818: sb          $v0, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r2;
    // 0x8005E81C: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005E820: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005E824: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005E828: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005E82C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E830: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E834: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005E838: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E83C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8005E840: jal         0x8005CCA4
    // 0x8005E844: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    play_random_boss_sound(rdram, ctx);
        goto after_4;
    // 0x8005E844: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    after_4:
    // 0x8005E848: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005E84C: jal         0x80001D04
    // 0x8005E850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8005E850: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8005E854: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005E858: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005E85C: jal         0x8006A168
    // 0x8005E860: nop

    set_camera_shake(rdram, ctx);
        goto after_6;
    // 0x8005E860: nop

    after_6:
    // 0x8005E864: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005E868: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005E86C: lwc1        $f9, 0x7030($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7030);
    // 0x8005E870: lwc1        $f8, 0x7034($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7034);
    // 0x8005E874: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E878: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005E87C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E880: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005E884: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E888: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E88C: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
L_8005E890:
    // 0x8005E890: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005E894: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005E898: beq         $t5, $zero, L_8005E8DC
    if (ctx->r13 == 0) {
        // 0x8005E89C: nop
    
            goto L_8005E8DC;
    }
    // 0x8005E89C: nop

    // 0x8005E8A0: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005E8A4: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005E8A8: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005E8AC: nop

    // 0x8005E8B0: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005E8B4: nop

    // 0x8005E8B8: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005E8BC: nop

    // 0x8005E8C0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005E8C4: jal         0x800CA030
    // 0x8005E8C8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8005E8C8: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_7:
    // 0x8005E8CC: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005E8D0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005E8D4: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8005E8D8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8005E8DC:
    // 0x8005E8DC: lw          $t6, 0x68($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X68);
    // 0x8005E8E0: lb          $t8, 0x3B($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E8E4: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8005E8E8: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8005E8EC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005E8F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005E8F4: lw          $t7, 0x44($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X44);
    // 0x8005E8F8: nop

    // 0x8005E8FC: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x8005E900: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8005E904: sb          $t6, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r14;
    // 0x8005E908: lwc1        $f18, 0x5C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005E90C: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x8005E910: addiu       $t5, $t4, -0x11
    ctx->r13 = ADD32(ctx->r12, -0X11);
    // 0x8005E914: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8005E918: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E91C: cvt.d.s     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f2.d = CVT_D_S(ctx->f18.fl);
    // 0x8005E920: add.d       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f8.d = ctx->f2.d + ctx->f2.d;
    // 0x8005E924: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005E928: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005E92C: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005E930: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005E934: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x8005E938: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E93C: nop

    // 0x8005E940: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E944: nop

    // 0x8005E948: bc1f        L_8005E974
    if (!c1cs) {
        // 0x8005E94C: nop
    
            goto L_8005E974;
    }
    // 0x8005E94C: nop

L_8005E950:
    // 0x8005E950: add.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005E954: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x8005E958: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E95C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E960: nop

    // 0x8005E964: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005E968: nop

    // 0x8005E96C: bc1t        L_8005E950
    if (c1cs) {
        // 0x8005E970: nop
    
            goto L_8005E950;
    }
    // 0x8005E970: nop

L_8005E974:
    // 0x8005E974: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E978: nop

    // 0x8005E97C: bc1f        L_8005E9A8
    if (!c1cs) {
        // 0x8005E980: nop
    
            goto L_8005E9A8;
    }
    // 0x8005E980: nop

L_8005E984:
    // 0x8005E984: sub.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005E988: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x8005E98C: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005E990: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E994: nop

    // 0x8005E998: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005E99C: nop

    // 0x8005E9A0: bc1t        L_8005E984
    if (c1cs) {
        // 0x8005E9A4: nop
    
            goto L_8005E984;
    }
    // 0x8005E9A4: nop

L_8005E9A8:
    // 0x8005E9A8: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
    // 0x8005E9AC: nop

    // 0x8005E9B0: bne         $t0, $t8, L_8005E9D8
    if (ctx->r8 != ctx->r24) {
        // 0x8005E9B4: nop
    
            goto L_8005E9D8;
    }
    // 0x8005E9B4: nop

    // 0x8005E9B8: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005E9BC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005E9C0: bne         $t7, $at, L_8005E9D8
    if (ctx->r15 != ctx->r1) {
        // 0x8005E9C4: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8005E9D8;
    }
    // 0x8005E9C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005E9C8: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005E9CC: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005E9D0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005E9D4: nop

L_8005E9D8:
    // 0x8005E9D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005E9DC: nop

    // 0x8005E9E0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005E9E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005E9E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005E9EC: nop

    // 0x8005E9F0: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005E9F4: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8005E9F8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005E9FC: sh          $t3, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r11;
    // 0x8005EA00: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x8005EA04: nop

    // 0x8005EA08: bne         $t0, $t4, L_8005EA48
    if (ctx->r8 != ctx->r12) {
        // 0x8005EA0C: nop
    
            goto L_8005EA48;
    }
    // 0x8005EA0C: nop

    // 0x8005EA10: jal         0x8002359C
    // 0x8005EA14: nop

    func_80023568(rdram, ctx);
        goto after_8;
    // 0x8005EA14: nop

    after_8:
    // 0x8005EA18: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005EA1C: beq         $v0, $zero, L_8005EA48
    if (ctx->r2 == 0) {
        // 0x8005EA20: addiu       $at, $zero, 0x6
        ctx->r1 = ADD32(0, 0X6);
            goto L_8005EA48;
    }
    // 0x8005EA20: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8005EA24: bne         $v0, $at, L_8005EA30
    if (ctx->r2 != ctx->r1) {
        // 0x8005EA28: addiu       $a3, $zero, 0x110
        ctx->r7 = ADD32(0, 0X110);
            goto L_8005EA30;
    }
    // 0x8005EA28: addiu       $a3, $zero, 0x110
    ctx->r7 = ADD32(0, 0X110);
    // 0x8005EA2C: addiu       $a3, $zero, 0x12A
    ctx->r7 = ADD32(0, 0X12A);
L_8005EA30:
    // 0x8005EA30: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8005EA34: addiu       $t5, $zero, 0x245
    ctx->r13 = ADD32(0, 0X245);
    // 0x8005EA38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8005EA3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005EA40: jal         0x8005E3A4
    // 0x8005EA44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    spawn_boss_hazard(rdram, ctx);
        goto after_9;
    // 0x8005EA44: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_9:
L_8005EA48:
    // 0x8005EA48: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005EA4C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8005EA50: jal         0x800B019C
    // 0x8005EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_10;
    // 0x8005EA54: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8005EA58: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005EA5C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005EA60: jal         0x8005D1E8
    // 0x8005EA64: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_11;
    // 0x8005EA64: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_11:
    // 0x8005EA68: lb          $v0, 0x3B($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EA6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EA70: beq         $v0, $at, L_8005EA8C
    if (ctx->r2 == ctx->r1) {
        // 0x8005EA74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005EA8C;
    }
    // 0x8005EA74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005EA78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8005EA7C: beq         $v0, $at, L_8005EA94
    if (ctx->r2 == ctx->r1) {
        // 0x8005EA80: addiu       $a1, $zero, 0x100
        ctx->r5 = ADD32(0, 0X100);
            goto L_8005EA94;
    }
    // 0x8005EA80: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x8005EA84: b           L_8005EA94
    // 0x8005EA88: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
        goto L_8005EA94;
    // 0x8005EA88: addiu       $a1, $zero, 0x1500
    ctx->r5 = ADD32(0, 0X1500);
L_8005EA8C:
    // 0x8005EA8C: b           L_8005EA94
    // 0x8005EA90: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
        goto L_8005EA94;
    // 0x8005EA90: addiu       $a1, $zero, 0x2500
    ctx->r5 = ADD32(0, 0X2500);
L_8005EA94:
    // 0x8005EA94: jal         0x8001BAFC
    // 0x8005EA98: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_racer_object(rdram, ctx);
        goto after_12;
    // 0x8005EA98: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_12:
    // 0x8005EA9C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8005EAA0: lwc1        $f18, 0xC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005EAA4: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005EAA8: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005EAAC: sub.s       $f20, $f10, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005EAB0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005EAB4: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005EAB8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005EABC: swc1        $f14, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f14.u32l;
    // 0x8005EAC0: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005EAC4: jal         0x800CA030
    // 0x8005EAC8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_13;
    // 0x8005EAC8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_13:
    // 0x8005EACC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005EAD0: lwc1        $f5, 0x7038($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X7038);
    // 0x8005EAD4: lwc1        $f4, 0x703C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X703C);
    // 0x8005EAD8: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005EADC: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005EAE0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005EAE4: lwc1        $f14, 0x48($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8005EAE8: bc1f        L_8005EB64
    if (!c1cs) {
        // 0x8005EAEC: nop
    
            goto L_8005EB64;
    }
    // 0x8005EAEC: nop

    // 0x8005EAF0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8005EAF4: jal         0x80070990
    // 0x8005EAF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_14;
    // 0x8005EAF8: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_14:
    // 0x8005EAFC: lh          $t6, 0x0($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X0);
    // 0x8005EB00: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005EB04: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x8005EB08: subu        $v1, $v0, $t8
    ctx->r3 = SUB32(ctx->r2, ctx->r24);
    // 0x8005EB0C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005EB10: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8005EB14: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005EB18: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005EB1C: bne         $at, $zero, L_8005EB30
    if (ctx->r1 != 0) {
        // 0x8005EB20: negu        $v0, $a1
        ctx->r2 = SUB32(0, ctx->r5);
            goto L_8005EB30;
    }
    // 0x8005EB20: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x8005EB24: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005EB28: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005EB2C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005EB30:
    // 0x8005EB30: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005EB34: beq         $at, $zero, L_8005EB40
    if (ctx->r1 == 0) {
        // 0x8005EB38: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005EB40;
    }
    // 0x8005EB38: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005EB3C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005EB40:
    // 0x8005EB40: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005EB44: beq         $at, $zero, L_8005EB54
    if (ctx->r1 == 0) {
        // 0x8005EB48: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8005EB54;
    }
    // 0x8005EB48: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005EB4C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8005EB50: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8005EB54:
    // 0x8005EB54: beq         $at, $zero, L_8005EB60
    if (ctx->r1 == 0) {
        // 0x8005EB58: nop
    
            goto L_8005EB60;
    }
    // 0x8005EB58: nop

    // 0x8005EB5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8005EB60:
    // 0x8005EB60: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005EB64:
    // 0x8005EB64: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EB68: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EB6C: bne         $t7, $at, L_8005EB9C
    if (ctx->r15 != ctx->r1) {
        // 0x8005EB70: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005EB9C;
    }
    // 0x8005EB70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005EB74: lb          $t9, 0x1E7($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005EB78: nop

    // 0x8005EB7C: andi        $t2, $t9, 0x1F
    ctx->r10 = ctx->r25 & 0X1F;
    // 0x8005EB80: slti        $at, $t2, 0xA
    ctx->r1 = SIGNED(ctx->r10) < 0XA ? 1 : 0;
    // 0x8005EB84: beq         $at, $zero, L_8005EBA0
    if (ctx->r1 == 0) {
        // 0x8005EB88: lw          $v1, 0x30($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X30);
            goto L_8005EBA0;
    }
    // 0x8005EB88: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8005EB8C: lh          $t3, 0x16C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X16C);
    // 0x8005EB90: nop

    // 0x8005EB94: sra         $t4, $t3, 1
    ctx->r12 = S32(SIGNED(ctx->r11) >> 1);
    // 0x8005EB98: sh          $t4, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r12;
L_8005EB9C:
    // 0x8005EB9C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
L_8005EBA0:
    // 0x8005EBA0: addiu       $a1, $a1, -0x2490
    ctx->r5 = ADD32(ctx->r5, -0X2490);
    // 0x8005EBA4: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005EBA8: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005EBAC: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005EBB0: nop

    // 0x8005EBB4: bne         $s1, $t5, L_8005EBE4
    if (ctx->r17 != ctx->r13) {
        // 0x8005EBB8: nop
    
            goto L_8005EBE4;
    }
    // 0x8005EBB8: nop

    // 0x8005EBBC: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8005EBC0: nop

    // 0x8005EBC4: andi        $t8, $t6, 0x8
    ctx->r24 = ctx->r14 & 0X8;
    // 0x8005EBC8: beq         $t8, $zero, L_8005EBE4
    if (ctx->r24 == 0) {
        // 0x8005EBCC: nop
    
            goto L_8005EBE4;
    }
    // 0x8005EBCC: nop

    // 0x8005EBD0: lb          $t7, 0x3B($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X3B);
    // 0x8005EBD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005EBD8: bne         $t7, $at, L_8005EBE4
    if (ctx->r15 != ctx->r1) {
        // 0x8005EBDC: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8005EBE4;
    }
    // 0x8005EBDC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8005EBE0: sb          $t9, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r25;
L_8005EBE4:
    // 0x8005EBE4: lb          $t2, 0x1D8($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005EBE8: nop

    // 0x8005EBEC: beq         $t2, $zero, L_8005EC10
    if (ctx->r10 == 0) {
        // 0x8005EBF0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005EC10;
    }
    // 0x8005EBF0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005EBF4: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8005EBF8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8005EBFC: bne         $t3, $zero, L_8005EC0C
    if (ctx->r11 != 0) {
        // 0x8005EC00: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005EC0C;
    }
    // 0x8005EC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005EC04: jal         0x8005CD08
    // 0x8005EC08: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    racer_boss_finish(rdram, ctx);
        goto after_15;
    // 0x8005EC08: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    after_15:
L_8005EC0C:
    // 0x8005EC0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005EC10:
    // 0x8005EC10: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005EC14: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005EC18: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005EC1C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005EC20: jr          $ra
    // 0x8005EC24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005EC24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void timetrial_player_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B314: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B318: lw          $v0, -0x4D4C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4D4C);
    // 0x8001B31C: jr          $ra
    // 0x8001B320: nop

    return;
    // 0x8001B320: nop

;}
RECOMP_FUNC void cam_reset_fov(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800663D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800663D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800663DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800663E0: lwc1        $f6, 0x7634($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7634);
    // 0x800663E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800663E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800663EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800663F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800663F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800663F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800663FC: lui         $a3, 0x3FAA
    ctx->r7 = S32(0X3FAA << 16);
    // 0x80066400: ori         $a3, $a3, 0xAAAB
    ctx->r7 = ctx->r7 | 0XAAAB;
    // 0x80066404: addiu       $a1, $a1, 0x12EC
    ctx->r5 = ADD32(ctx->r5, 0X12EC);
    // 0x80066408: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    // 0x8006640C: lui         $a2, 0x4270
    ctx->r6 = S32(0X4270 << 16);
    // 0x80066410: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80066414: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80066418: jal         0x800CCE80
    // 0x8006641C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x8006641C: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x80066420: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066424: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80066428: addiu       $a1, $a1, 0x1560
    ctx->r5 = ADD32(ctx->r5, 0X1560);
    // 0x8006642C: jal         0x8006FAB0
    // 0x80066430: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    mtxf_to_mtx(rdram, ctx);
        goto after_1;
    // 0x80066430: addiu       $a0, $a0, 0x1460
    ctx->r4 = ADD32(ctx->r4, 0X1460);
    after_1:
    // 0x80066434: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80066438: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006643C: jr          $ra
    // 0x80066440: nop

    return;
    // 0x80066440: nop

;}
RECOMP_FUNC void read_game_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074074: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007407C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074084: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80074088: jal         0x80075B34
    // 0x8007408C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x8007408C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80074090: beq         $v0, $zero, L_800740B4
    if (ctx->r2 == 0) {
        // 0x80074094: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800740B4;
    }
    // 0x80074094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074098: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007409C: jal         0x80075D44
    // 0x800740A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x800740A0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x800740A4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800740A8: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x800740AC: b           L_800741A4
    // 0x800740B0: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_800741A4;
    // 0x800740B0: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_800740B4:
    // 0x800740B4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800740B8: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800740BC: addiu       $a1, $a1, 0x7C00
    ctx->r5 = ADD32(ctx->r5, 0X7C00);
    // 0x800740C0: jal         0x80076740
    // 0x800740C4: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x800740C4: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x800740C8: bne         $v0, $zero, L_80074180
    if (ctx->r2 != 0) {
        // 0x800740CC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074180;
    }
    // 0x800740CC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800740D0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800740D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800740D8: jal         0x80076B7C
    // 0x800740DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x800740DC: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x800740E0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800740E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800740E8: bne         $a0, $zero, L_800740F4
    if (ctx->r4 != 0) {
        // 0x800740EC: nop
    
            goto L_800740F4;
    }
    // 0x800740EC: nop

    // 0x800740F0: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_800740F4:
    // 0x800740F4: bne         $v1, $zero, L_80074180
    if (ctx->r3 != 0) {
        // 0x800740F8: nop
    
            goto L_80074180;
    }
    // 0x800740F8: nop

    // 0x800740FC: jal         0x80070EDC
    // 0x80074100: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x80074100: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x80074104: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80074108: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8007410C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80074110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074114: jal         0x80076868
    // 0x80074118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x80074118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x8007411C: bne         $v0, $zero, L_8007416C
    if (ctx->r2 != 0) {
        // 0x80074120: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007416C;
    }
    // 0x80074120: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80074124: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80074128: lui         $at, 0x4741
    ctx->r1 = S32(0X4741 << 16);
    // 0x8007412C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80074130: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x80074134: bne         $t7, $at, L_8007416C
    if (ctx->r15 != ctx->r1) {
        // 0x80074138: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_8007416C;
    }
    // 0x80074138: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x8007413C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80074140: addiu       $a1, $a2, 0x4
    ctx->r5 = ADD32(ctx->r6, 0X4);
    // 0x80074144: jal         0x800732C4
    // 0x80074148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    populate_settings_from_save_data(rdram, ctx);
        goto after_6;
    // 0x80074148: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x8007414C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80074150: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074154: lbu         $t9, 0x4B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X4B);
    // 0x80074158: nop

    // 0x8007415C: beq         $t9, $zero, L_80074170
    if (ctx->r25 == 0) {
        // 0x80074160: lw          $a0, 0x2C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X2C);
            goto L_80074170;
    }
    // 0x80074160: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80074164: b           L_8007416C
    // 0x80074168: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8007416C;
    // 0x80074168: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8007416C:
    // 0x8007416C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074170:
    // 0x80074170: jal         0x80071380
    // 0x80074174: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074174: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x80074178: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007417C: nop

L_80074180:
    // 0x80074180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074184: jal         0x80075D44
    // 0x80074188: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x80074188: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x8007418C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074190: sll         $t0, $s0, 30
    ctx->r8 = S32(ctx->r16 << 30);
    // 0x80074194: beq         $v1, $zero, L_800741A4
    if (ctx->r3 == 0) {
        // 0x80074198: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800741A4;
    }
    // 0x80074198: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007419C: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x800741A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800741A4:
    // 0x800741A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800741A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800741AC: jr          $ra
    // 0x800741B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800741B0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void try_to_collect_egg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036080: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80036084: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80036088: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003608C: lw          $v1, 0x4C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4C);
    // 0x80036090: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80036094: lbu         $t6, 0x13($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X13);
    // 0x80036098: nop

    // 0x8003609C: slti        $at, $t6, 0x28
    ctx->r1 = SIGNED(ctx->r14) < 0X28 ? 1 : 0;
    // 0x800360A0: beq         $at, $zero, L_800361C8
    if (ctx->r1 == 0) {
        // 0x800360A4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800360AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800360B0: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x800360B4: nop

    // 0x800360B8: lb          $t8, 0x54($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X54);
    // 0x800360BC: nop

    // 0x800360C0: bne         $a3, $t8, L_800361C8
    if (ctx->r7 != ctx->r24) {
        // 0x800360C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360C8: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800360CC: nop

    // 0x800360D0: lw          $t9, 0x144($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X144);
    // 0x800360D4: nop

    // 0x800360D8: bne         $t9, $zero, L_800361C8
    if (ctx->r25 != 0) {
        // 0x800360DC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800361C8;
    }
    // 0x800360DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800360E0: sb          $a3, 0xB($a1)
    MEM_B(0XB, ctx->r5) = ctx->r7;
    // 0x800360E4: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800360E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800360EC: ori         $t1, $t0, 0x4000
    ctx->r9 = ctx->r8 | 0X4000;
    // 0x800360F0: sh          $t1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r9;
    // 0x800360F4: sw          $a0, 0x144($v1)
    MEM_W(0X144, ctx->r3) = ctx->r4;
    // 0x800360F8: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800360FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80036100: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80036104: sh          $t3, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r11;
    // 0x80036108: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8003610C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80036110: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80036114: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
    // 0x80036118: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8003611C: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x80036120: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80036124: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x80036128: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003612C: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80036130: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80036134: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80036138: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003613C: nop

    // 0x80036140: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80036144: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80036148: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003614C: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80036150: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x80036154: jal         0x800700B4
    // 0x80036158: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80036158: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8003615C: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036160: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80036164: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80036168: addiu       $t8, $s0, 0xC
    ctx->r24 = ADD32(ctx->r16, 0XC);
    // 0x8003616C: addiu       $t9, $s0, 0x10
    ctx->r25 = ADD32(ctx->r16, 0X10);
    // 0x80036170: addiu       $t0, $s0, 0x14
    ctx->r8 = ADD32(ctx->r16, 0X14);
    // 0x80036174: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80036178: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003617C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80036180: jal         0x8006F88C
    // 0x80036184: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80036184: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x80036188: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
    // 0x8003618C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036190: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036194: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036198: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8003619C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800361A0: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800361A4: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800361A8: nop

    // 0x800361AC: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800361B0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
    // 0x800361B4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800361B8: nop

    // 0x800361BC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800361C0: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x800361C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800361C8:
    // 0x800361C8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800361CC: jr          $ra
    // 0x800361D0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800361D0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void music_tempo_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001538: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000153C: beq         $a0, $zero, L_800015A8
    if (ctx->r4 == 0) {
        // 0x80001540: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800015A8;
    }
    // 0x80001540: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001544: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80001548: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000154C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80001550: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80001554: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001558: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000155C: lwc1        $f16, 0x4F6C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4F6C);
    // 0x80001560: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001564: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001568: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8000156C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80001570: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80001574: nop

    // 0x80001578: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000157C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001580: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001584: nop

    // 0x80001588: cvt.w.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8000158C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80001590: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80001594: jal         0x800C7F40
    // 0x80001598: nop

    alCSPSetTempo(rdram, ctx);
        goto after_0;
    // 0x80001598: nop

    after_0:
    // 0x8000159C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800015A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800015A4: sh          $a2, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r6;
L_800015A8:
    // 0x800015A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800015B0: jr          $ra
    // 0x800015B4: nop

    return;
    // 0x800015B4: nop

;}
RECOMP_FUNC void obj_tick_anims(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800142B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800142BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800142C0: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x800142C4: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800142C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800142CC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800142D0: beq         $at, $zero, L_800143A0
    if (ctx->r1 == 0) {
        // 0x800142D4: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_800143A0;
    }
    // 0x800142D4: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800142D8: addiu       $t2, $t2, -0x4C28
    ctx->r10 = ADD32(ctx->r10, -0X4C28);
L_800142DC:
    // 0x800142DC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800142E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800142E4: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x800142E8: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800142EC: nop

    // 0x800142F0: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800142F4: nop

    // 0x800142F8: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800142FC: bne         $t9, $zero, L_80014398
    if (ctx->r25 != 0) {
        // 0x80014300: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014300: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80014304: lw          $a2, 0x40($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X40);
    // 0x80014308: nop

    // 0x8001430C: lb          $t3, 0x53($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X53);
    // 0x80014310: nop

    // 0x80014314: bne         $t3, $zero, L_80014398
    if (ctx->r11 != 0) {
        // 0x80014318: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80014398;
    }
    // 0x80014318: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001431C: lb          $t0, 0x55($a2)
    ctx->r8 = MEM_B(ctx->r6, 0X55);
    // 0x80014320: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80014324: blez        $t0, L_80014394
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80014328: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_80014394;
    }
    // 0x80014328: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001432C:
    // 0x8001432C: lw          $t4, 0x68($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X68);
    // 0x80014330: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80014334: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x80014338: lw          $v1, 0x0($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X0);
    // 0x8001433C: nop

    // 0x80014340: beq         $v1, $zero, L_80014380
    if (ctx->r3 == 0) {
        // 0x80014344: slt         $at, $a3, $t0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80014380;
    }
    // 0x80014344: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80014348: lb          $t1, 0x20($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X20);
    // 0x8001434C: nop

    // 0x80014350: blez        $t1, L_8001437C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80014354: andi        $t6, $t1, 0x3
        ctx->r14 = ctx->r9 & 0X3;
            goto L_8001437C;
    }
    // 0x80014354: andi        $t6, $t1, 0x3
    ctx->r14 = ctx->r9 & 0X3;
    // 0x80014358: sb          $t6, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r14;
    // 0x8001435C: lb          $t7, 0x20($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X20);
    // 0x80014360: nop

    // 0x80014364: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80014368: sb          $t8, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r24;
    // 0x8001436C: lw          $t9, 0x40($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X40);
    // 0x80014370: nop

    // 0x80014374: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x80014378: nop

L_8001437C:
    // 0x8001437C: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
L_80014380:
    // 0x80014380: bne         $at, $zero, L_8001432C
    if (ctx->r1 != 0) {
        // 0x80014384: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8001432C;
    }
    // 0x80014384: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80014388: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001438C: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80014390: nop

L_80014394:
    // 0x80014394: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80014398:
    // 0x80014398: bne         $at, $zero, L_800142DC
    if (ctx->r1 != 0) {
        // 0x8001439C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800142DC;
    }
    // 0x8001439C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_800143A0:
    // 0x800143A0: jr          $ra
    // 0x800143A4: nop

    return;
    // 0x800143A4: nop

;}
RECOMP_FUNC void func_8002125C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021290: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80021294: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80021298: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8002129C: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x800212A0: nop

    // 0x800212A4: bltz        $v0, L_800212F8
    if (SIGNED(ctx->r2) < 0) {
        // 0x800212A8: nop
    
            goto L_800212F8;
    }
    // 0x800212A8: nop

    // 0x800212AC: lb          $t6, 0x3B($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X3B);
    // 0x800212B0: nop

    // 0x800212B4: beq         $v0, $t6, L_800212D0
    if (ctx->r2 == ctx->r14) {
        // 0x800212B8: nop
    
            goto L_800212D0;
    }
    // 0x800212B8: nop

    // 0x800212BC: lbu         $t7, 0x16($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X16);
    // 0x800212C0: nop

    // 0x800212C4: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x800212C8: lb          $v0, 0x12($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X12);
    // 0x800212CC: nop

L_800212D0:
    // 0x800212D0: sb          $v0, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r2;
    // 0x800212D4: lb          $t8, 0x17($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X17);
    // 0x800212D8: nop

    // 0x800212DC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800212E0: nop

    // 0x800212E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800212E8: swc1        $f6, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->f6.u32l;
    // 0x800212EC: lbu         $t9, 0x18($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X18);
    // 0x800212F0: nop

    // 0x800212F4: sb          $t9, 0x2C($a2)
    MEM_B(0X2C, ctx->r6) = ctx->r25;
L_800212F8:
    // 0x800212F8: lb          $v0, 0x13($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X13);
    // 0x800212FC: nop

    // 0x80021300: bltz        $v0, L_8002130C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80021304: nop
    
            goto L_8002130C;
    }
    // 0x80021304: nop

    // 0x80021308: sb          $v0, 0x2F($a2)
    MEM_B(0X2F, ctx->r6) = ctx->r2;
L_8002130C:
    // 0x8002130C: lh          $a0, 0x24($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X24);
    // 0x80021310: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80021314: jal         0x8000C8B4
    // 0x80021318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x80021318: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8002131C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80021320: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80021324: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80021328: sh          $v0, 0x36($a2)
    MEM_H(0X36, ctx->r6) = ctx->r2;
    // 0x8002132C: lb          $t0, 0x2D($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X2D);
    // 0x80021330: nop

    // 0x80021334: sb          $t0, 0x3F($a2)
    MEM_B(0X3F, ctx->r6) = ctx->r8;
    // 0x80021338: lb          $t1, 0x26($a1)
    ctx->r9 = MEM_B(ctx->r5, 0X26);
    // 0x8002133C: nop

    // 0x80021340: sb          $t1, 0x3A($a2)
    MEM_B(0X3A, ctx->r6) = ctx->r9;
    // 0x80021344: lb          $t2, 0x1F($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1F);
    // 0x80021348: nop

    // 0x8002134C: sb          $t2, 0x39($a2)
    MEM_B(0X39, ctx->r6) = ctx->r10;
    // 0x80021350: lb          $t3, 0x30($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X30);
    // 0x80021354: nop

    // 0x80021358: sb          $t3, 0x43($a2)
    MEM_B(0X43, ctx->r6) = ctx->r11;
    // 0x8002135C: lbu         $t4, 0x1E($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1E);
    // 0x80021360: nop

    // 0x80021364: sb          $t4, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r12;
    // 0x80021368: lb          $t5, 0x29($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X29);
    // 0x8002136C: nop

    // 0x80021370: sb          $t5, 0x3B($a2)
    MEM_B(0X3B, ctx->r6) = ctx->r13;
    // 0x80021374: lb          $t6, 0x2E($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X2E);
    // 0x80021378: nop

    // 0x8002137C: sb          $t6, 0x40($a2)
    MEM_B(0X40, ctx->r6) = ctx->r14;
    // 0x80021380: lb          $t7, 0x2F($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X2F);
    // 0x80021384: nop

    // 0x80021388: sb          $t7, 0x41($a2)
    MEM_B(0X41, ctx->r6) = ctx->r15;
    // 0x8002138C: lb          $t8, 0x2B($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X2B);
    // 0x80021390: nop

    // 0x80021394: sb          $t8, 0x3C($a2)
    MEM_B(0X3C, ctx->r6) = ctx->r24;
    // 0x80021398: lbu         $a0, 0x27($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X27);
    // 0x8002139C: nop

    // 0x800213A0: beq         $a0, $at, L_800213B8
    if (ctx->r4 == ctx->r1) {
        // 0x800213A4: nop
    
            goto L_800213B8;
    }
    // 0x800213A4: nop

    // 0x800213A8: jal         0x800C3744
    // 0x800213AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x800213AC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x800213B0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213B4: nop

L_800213B8:
    // 0x800213B8: lb          $a0, 0x2A($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X2A);
    // 0x800213BC: nop

    // 0x800213C0: bltz        $a0, L_800213D8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800213C4: nop
    
            goto L_800213D8;
    }
    // 0x800213C4: nop

    // 0x800213C8: jal         0x8001E490
    // 0x800213CC: nop

    func_8001E45C(rdram, ctx);
        goto after_2;
    // 0x800213CC: nop

    after_2:
    // 0x800213D0: b           L_80021428
    // 0x800213D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80021428;
    // 0x800213D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800213D8:
    // 0x800213D8: lb          $a0, 0x15($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X15);
    // 0x800213DC: nop

    // 0x800213E0: bltz        $a0, L_800213F8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800213E4: nop
    
            goto L_800213F8;
    }
    // 0x800213E4: nop

    // 0x800213E8: jal         0x80021434
    // 0x800213EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_80021400(rdram, ctx);
        goto after_3;
    // 0x800213EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_3:
    // 0x800213F0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800213F4: nop

L_800213F8:
    // 0x800213F8: lb          $t9, 0x28($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X28);
    // 0x800213FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80021400: bltz        $t9, L_80021424
    if (SIGNED(ctx->r25) < 0) {
        // 0x80021404: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80021424;
    }
    // 0x80021404: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80021408: lb          $t0, -0x4D5F($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X4D5F);
    // 0x8002140C: addiu       $t1, $t1, -0x4D5E
    ctx->r9 = ADD32(ctx->r9, -0X4D5E);
    // 0x80021410: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80021414: lb          $t2, 0x0($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X0);
    // 0x80021418: nop

    // 0x8002141C: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80021420: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80021424:
    // 0x80021424: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80021428:
    // 0x80021428: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002142C: jr          $ra
    // 0x80021430: nop

    return;
    // 0x80021430: nop

;}
RECOMP_FUNC void func_8000E558(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E558: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x8000E55C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000E560: bne         $v0, $zero, L_8000E570
    if (ctx->r2 != 0) {
        // 0x8000E564: addiu       $a1, $a1, -0x4BE8
        ctx->r5 = ADD32(ctx->r5, -0X4BE8);
            goto L_8000E570;
    }
    // 0x8000E564: addiu       $a1, $a1, -0x4BE8
    ctx->r5 = ADD32(ctx->r5, -0X4BE8);
    // 0x8000E568: jr          $ra
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E56C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E570:
    // 0x8000E570: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8000E574: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000E578: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000E57C: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E580: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000E5A8;
    }
    // 0x8000E580: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E584: lw          $t6, -0x4BE0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BE0);
    // 0x8000E588: nop

    // 0x8000E58C: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x8000E590: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8000E594: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E598: bne         $at, $zero, L_8000E5A8
    if (ctx->r1 != 0) {
        // 0x8000E59C: nop
    
            goto L_8000E5A8;
    }
    // 0x8000E59C: nop

    // 0x8000E5A0: jr          $ra
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8000E5A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000E5A8:
    // 0x8000E5A8: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8000E5AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E5B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000E5B4: bne         $at, $zero, L_8000E5E0
    if (ctx->r1 != 0) {
        // 0x8000E5B8: nop
    
            goto L_8000E5E0;
    }
    // 0x8000E5B8: nop

    // 0x8000E5BC: lw          $t9, -0x4BDC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4BDC);
    // 0x8000E5C0: nop

    // 0x8000E5C4: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8000E5C8: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8000E5CC: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E5D0: bne         $at, $zero, L_8000E5E4
    if (ctx->r1 != 0) {
        // 0x8000E5D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8000E5E4;
    }
    // 0x8000E5D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000E5D8: jr          $ra
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8000E5DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E0:
    // 0x8000E5E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8000E5E4:
    // 0x8000E5E4: jr          $ra
    // 0x8000E5E8: nop

    return;
    // 0x8000E5E8: nop

;}
RECOMP_FUNC void mtxf_from_transform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FE70: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006FE74: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8006FE78: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x8006FE7C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8006FE80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8006FE84: jal         0x80070A70
    // 0x8006FE88: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    static_3_80070A70(rdram, ctx);
        goto after_0;
    // 0x8006FE88: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    after_0:
    // 0x8006FE8C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006FE90: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x8006FE94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006FE98: mul.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8006FE9C: jal         0x80070A6C
    // 0x8006FEA0: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x8006FEA0: nop

    after_1:
    // 0x8006FEA4: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006FEA8: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEAC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8006FEB0: mul.s       $f2, $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8006FEB4: jal         0x80070A70
    // 0x8006FEB8: nop

    static_3_80070A70(rdram, ctx);
        goto after_2;
    // 0x8006FEB8: nop

    after_2:
    // 0x8006FEBC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8006FEC0: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x8006FEC4: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006FEC8: mul.s       $f4, $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FECC: jal         0x80070A6C
    // 0x8006FED0: nop

    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8006FED0: nop

    after_3:
    // 0x8006FED4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8006FED8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEDC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006FEE0: mul.s       $f6, $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8006FEE4: jal         0x80070A70
    // 0x8006FEE8: nop

    static_3_80070A70(rdram, ctx);
        goto after_4;
    // 0x8006FEE8: nop

    after_4:
    // 0x8006FEEC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8006FEF0: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x8006FEF4: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8006FEF8: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8006FEFC: jal         0x80070A6C
    // 0x8006FF00: nop

    coss_s16(rdram, ctx);
        goto after_5;
    // 0x8006FF00: nop

    after_5:
    // 0x8006FF04: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8006FF08: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x8006FF0C: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x8006FF10: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006FF14: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8006FF18: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x8006FF1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8006FF20: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8006FF24: nop

    // 0x8006FF28: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FF2C: nop

    // 0x8006FF30: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FF34: nop

    // 0x8006FF38: mul.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006FF3C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FF40: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FF44: nop

    // 0x8006FF48: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF4C: swc1        $f16, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF50: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8006FF54: nop

    // 0x8006FF58: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF5C: swc1        $f16, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF60: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FF64: nop

    // 0x8006FF68: mul.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8006FF6C: nop

    // 0x8006FF70: mul.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8006FF74: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FF78: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FF7C: nop

    // 0x8006FF80: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FF84: swc1        $f16, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f16.u32l;
    // 0x8006FF88: mul.s       $f16, $f4, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006FF8C: nop

    // 0x8006FF90: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FF94: nop

    // 0x8006FF98: mul.s       $f18, $f8, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006FF9C: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006FFA0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FFA4: nop

    // 0x8006FFA8: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFAC: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFB0: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x8006FFB4: nop

    // 0x8006FFB8: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFBC: swc1        $f16, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFC0: mul.s       $f16, $f4, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006FFC4: nop

    // 0x8006FFC8: mul.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8006FFCC: nop

    // 0x8006FFD0: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8006FFD4: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006FFD8: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8006FFDC: nop

    // 0x8006FFE0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFE4: swc1        $f16, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFE8: mul.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006FFEC: nop

    // 0x8006FFF0: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8006FFF4: swc1        $f16, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f16.u32l;
    // 0x8006FFF8: mul.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x8006FFFC: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x80070000: swc1        $f16, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->f16.u32l;
    // 0x80070004: mul.s       $f16, $f6, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80070008: nop

    // 0x8007000C: mul.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80070010: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070014: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x80070018: lw          $t0, 0xC($a1)
    ctx->r8 = MEM_W(ctx->r5, 0XC);
    // 0x8007001C: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80070020: lw          $t0, 0x10($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X10);
    // 0x80070024: sw          $t0, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r8;
    // 0x80070028: lw          $t0, 0x14($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14);
    // 0x8007002C: swc1        $f18, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f18.u32l;
    // 0x80070030: sw          $t0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r8;
    // 0x80070034: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x80070038: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8007003C: jr          $ra
    // 0x80070040: nop

    return;
    // 0x80070040: nop

;}
RECOMP_FUNC void rumble_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800727C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800727C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800727CC: lbu         $t9, 0x4764($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4764);
    // 0x800727D0: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800727D4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800727D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800727DC: sll         $a3, $a1, 16
    ctx->r7 = S32(ctx->r5 << 16);
    // 0x800727E0: sra         $t8, $a3, 16
    ctx->r24 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800727E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800727E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800727EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800727F0: beq         $t9, $zero, L_800728B8
    if (ctx->r25 == 0) {
        // 0x800727F4: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_800728B8;
    }
    // 0x800727F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800727F8: bltz        $t7, L_800728B8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800727FC: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_800728B8;
    }
    // 0x800727FC: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072800: beq         $at, $zero, L_800728BC
    if (ctx->r1 == 0) {
        // 0x80072804: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800728BC;
    }
    // 0x80072804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072808: jal         0x80072490
    // 0x8007280C: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    input_get_id(rdram, ctx);
        goto after_0;
    // 0x8007280C: sh          $t8, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r24;
    after_0:
    // 0x80072810: lh          $a3, 0x1E($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X1E);
    // 0x80072814: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072818: multu       $a3, $a3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007281C: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80072820: addiu       $t0, $t0, 0x4766
    ctx->r8 = ADD32(ctx->r8, 0X4766);
    // 0x80072824: sra         $t2, $a0, 16
    ctx->r10 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80072828: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007282C: lbu         $t5, 0x0($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X0);
    // 0x80072830: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80072834: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80072838: addiu       $t1, $t1, 0x4767
    ctx->r9 = ADD32(ctx->r9, 0X4767);
    // 0x8007283C: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x80072840: nor         $t8, $t4, $zero
    ctx->r24 = ~(ctx->r12 | 0);
    // 0x80072844: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x80072848: mflo        $t4
    ctx->r12 = lo;
    // 0x8007284C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80072850: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80072854: sb          $t6, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r14;
    // 0x80072858: sb          $t9, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r25;
    // 0x8007285C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072860: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072864: lwc1        $f9, 0x7D70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X7D70);
    // 0x80072868: lwc1        $f8, 0x7D74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7D74);
    // 0x8007286C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x80072870: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80072874: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80072878: addu        $t2, $t2, $a0
    ctx->r10 = ADD32(ctx->r10, ctx->r4);
    // 0x8007287C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80072880: addiu       $t3, $t3, 0x4738
    ctx->r11 = ADD32(ctx->r11, 0X4738);
    // 0x80072884: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80072888: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8007288C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80072890: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80072894: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80072898: addu        $v1, $t2, $t3
    ctx->r3 = ADD32(ctx->r10, ctx->r11);
    // 0x8007289C: cvt.w.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_D(ctx->f10.d);
    // 0x800728A0: lh          $t6, 0x22($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X22);
    // 0x800728A4: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800728A8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800728AC: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x800728B0: sh          $a2, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r6;
    // 0x800728B4: sh          $a2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r6;
L_800728B8:
    // 0x800728B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800728BC:
    // 0x800728BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800728C0: jr          $ra
    // 0x800728C4: nop

    return;
    // 0x800728C4: nop

;}
RECOMP_FUNC void render_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012D5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80012D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80012D64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80012D68: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80012D6C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80012D70: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80012D74: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012D78: andi        $t7, $t6, 0x5000
    ctx->r15 = ctx->r14 & 0X5000;
    // 0x80012D7C: bne         $t7, $zero, L_80012E1C
    if (ctx->r15 != 0) {
        // 0x80012D80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80012E1C;
    }
    // 0x80012D80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80012D84: lh          $a1, 0x4A($a3)
    ctx->r5 = MEM_H(ctx->r7, 0X4A);
    // 0x80012D88: jal         0x800B7BD8
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80012D8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80012D90: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80012D94: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80012D98: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80012D9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DA0: sw          $t9, -0x4BF4($at)
    MEM_W(-0X4BF4, ctx->r1) = ctx->r25;
    // 0x80012DA4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80012DA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80012DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DB0: sw          $t1, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r9;
    // 0x80012DB4: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80012DB8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012DC0: sw          $t3, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r11;
    // 0x80012DC4: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80012DC8: jal         0x8001348C
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    render_object_parts(rdram, ctx);
        goto after_1;
    // 0x80012DCC: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80012DD0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80012DD4: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80012DD8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80012DDC: swc1        $f6, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f6.u32l;
    // 0x80012DE0: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80012DE4: lw          $t4, -0x4BF4($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BF4);
    // 0x80012DE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80012DEC: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x80012DF0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80012DF4: lw          $t6, -0x4BF0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4BF0);
    // 0x80012DF8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80012DFC: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x80012E00: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80012E04: lw          $t8, -0x4BEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BEC);
    // 0x80012E08: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80012E0C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80012E10: jal         0x800B7BD8
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    update_object_stack_trace(rdram, ctx);
        goto after_2;
    // 0x80012E14: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    after_2:
    // 0x80012E18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80012E1C:
    // 0x80012E1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80012E20: jr          $ra
    // 0x80012E24: nop

    return;
    // 0x80012E24: nop

;}
RECOMP_FUNC void modify_panning(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80065E30: lh          $v0, -0x2A40($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X2A40);
    // 0x80065E34: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80065E38: beq         $v0, $zero, L_80065E58
    if (ctx->r2 == 0) {
        // 0x80065E3C: nop
    
            goto L_80065E58;
    }
    // 0x80065E3C: nop

    // 0x80065E40: beq         $v0, $at, L_80065E6C
    if (ctx->r2 == ctx->r1) {
        // 0x80065E44: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80065E6C;
    }
    // 0x80065E44: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80065E48: beq         $v0, $at, L_80065E60
    if (ctx->r2 == ctx->r1) {
        // 0x80065E4C: addiu       $a0, $a0, -0x40
        ctx->r4 = ADD32(ctx->r4, -0X40);
            goto L_80065E60;
    }
    // 0x80065E4C: addiu       $a0, $a0, -0x40
    ctx->r4 = ADD32(ctx->r4, -0X40);
    // 0x80065E50: b           L_80065E70
    // 0x80065E54: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
        goto L_80065E70;
    // 0x80065E54: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065E58:
    // 0x80065E58: jr          $ra
    // 0x80065E5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80065E5C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80065E60:
    // 0x80065E60: sra         $t6, $a0, 1
    ctx->r14 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80065E64: jr          $ra
    // 0x80065E68: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
    return;
    // 0x80065E68: addiu       $v0, $t6, 0x40
    ctx->r2 = ADD32(ctx->r14, 0X40);
L_80065E6C:
    // 0x80065E6C: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
L_80065E70:
    // 0x80065E70: jr          $ra
    // 0x80065E74: nop

    return;
    // 0x80065E74: nop

;}
RECOMP_FUNC void func_80052988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800529C8: lw          $t6, 0x14($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X14);
    // 0x800529CC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800529D0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800529D4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800529D8: lw          $t9, -0x2524($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2524);
    // 0x800529DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800529E0: mflo        $t8
    ctx->r24 = lo;
    // 0x800529E4: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800529E8: bne         $t9, $at, L_80052A04
    if (ctx->r25 != ctx->r1) {
        // 0x800529EC: slti        $at, $a2, 0x3
        ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
            goto L_80052A04;
    }
    // 0x800529EC: slti        $at, $a2, 0x3
    ctx->r1 = SIGNED(ctx->r6) < 0X3 ? 1 : 0;
    // 0x800529F0: bne         $at, $zero, L_80052A04
    if (ctx->r1 != 0) {
        // 0x800529F4: nop
    
            goto L_80052A04;
    }
    // 0x800529F4: nop

    // 0x800529F8: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x800529FC: jr          $ra
    // 0x80052A00: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    return;
    // 0x80052A00: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
L_80052A04:
    // 0x80052A04: lb          $v0, 0x3B($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X3B);
    // 0x80052A08: nop

    // 0x80052A0C: bne         $v0, $zero, L_80052AB4
    if (ctx->r2 != 0) {
        // 0x80052A10: nop
    
            goto L_80052AB4;
    }
    // 0x80052A10: nop

    // 0x80052A14: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80052A18: nop

    // 0x80052A1C: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x80052A20: beq         $t0, $zero, L_80052A98
    if (ctx->r8 == 0) {
        // 0x80052A24: nop
    
            goto L_80052A98;
    }
    // 0x80052A24: nop

    // 0x80052A28: lh          $v0, 0x18($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X18);
    // 0x80052A2C: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80052A30: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x80052A34: bne         $at, $zero, L_80052A70
    if (ctx->r1 != 0) {
        // 0x80052A38: sll         $t6, $t5, 2
        ctx->r14 = S32(ctx->r13 << 2);
            goto L_80052A70;
    }
    // 0x80052A38: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80052A3C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80052A40: nop

    // 0x80052A44: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80052A48: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80052A4C: sh          $t3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r11;
    // 0x80052A50: lh          $t4, 0x18($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X18);
    // 0x80052A54: nop

    // 0x80052A58: slti        $at, $t4, 0x29
    ctx->r1 = SIGNED(ctx->r12) < 0X29 ? 1 : 0;
    // 0x80052A5C: beq         $at, $zero, L_80052B9C
    if (ctx->r1 == 0) {
        // 0x80052A60: nop
    
            goto L_80052B9C;
    }
    // 0x80052A60: nop

    // 0x80052A64: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A68: jr          $ra
    // 0x80052A6C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    return;
    // 0x80052A6C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
L_80052A70:
    // 0x80052A70: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x80052A74: sh          $t7, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r15;
    // 0x80052A78: lh          $t8, 0x18($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X18);
    // 0x80052A7C: nop

    // 0x80052A80: slti        $at, $t8, 0x28
    ctx->r1 = SIGNED(ctx->r24) < 0X28 ? 1 : 0;
    // 0x80052A84: bne         $at, $zero, L_80052B9C
    if (ctx->r1 != 0) {
        // 0x80052A88: nop
    
            goto L_80052B9C;
    }
    // 0x80052A88: nop

    // 0x80052A8C: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A90: jr          $ra
    // 0x80052A94: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    return;
    // 0x80052A94: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
L_80052A98:
    // 0x80052A98: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
    // 0x80052A9C: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x80052AA0: lbu         $t9, 0x1F3($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052AA4: nop

    // 0x80052AA8: andi        $t0, $t9, 0xFF7F
    ctx->r8 = ctx->r25 & 0XFF7F;
    // 0x80052AAC: jr          $ra
    // 0x80052AB0: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
    return;
    // 0x80052AB0: sb          $t0, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r8;
L_80052AB4:
    // 0x80052AB4: bne         $a2, $v0, L_80052B94
    if (ctx->r6 != ctx->r2) {
        // 0x80052AB8: nop
    
            goto L_80052B94;
    }
    // 0x80052AB8: nop

    // 0x80052ABC: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80052AC0: lw          $t8, 0x14($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14);
    // 0x80052AC4: andi        $t1, $v0, 0x2
    ctx->r9 = ctx->r2 & 0X2;
    // 0x80052AC8: beq         $t1, $zero, L_80052B5C
    if (ctx->r9 == 0) {
        // 0x80052ACC: nop
    
            goto L_80052B5C;
    }
    // 0x80052ACC: nop

    // 0x80052AD0: lbu         $t2, 0x1F3($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052AD4: lw          $t0, 0x14($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X14);
    // 0x80052AD8: andi        $t3, $t2, 0x80
    ctx->r11 = ctx->r10 & 0X80;
    // 0x80052ADC: beq         $t3, $zero, L_80052B1C
    if (ctx->r11 == 0) {
        // 0x80052AE0: nop
    
            goto L_80052B1C;
    }
    // 0x80052AE0: nop

    // 0x80052AE4: lh          $t4, 0x18($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X18);
    // 0x80052AE8: lw          $t5, 0x14($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X14);
    // 0x80052AEC: addiu       $t8, $zero, 0x28
    ctx->r24 = ADD32(0, 0X28);
    // 0x80052AF0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80052AF4: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    // 0x80052AF8: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80052AFC: nop

    // 0x80052B00: bgtz        $t7, L_80052B9C
    if (SIGNED(ctx->r15) > 0) {
        // 0x80052B04: nop
    
            goto L_80052B9C;
    }
    // 0x80052B04: nop

    // 0x80052B08: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80052B0C: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052B10: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x80052B14: jr          $ra
    // 0x80052B18: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    return;
    // 0x80052B18: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_80052B1C:
    // 0x80052B1C: lh          $t9, 0x18($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X18);
    // 0x80052B20: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80052B24: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80052B28: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
    // 0x80052B2C: lh          $t2, 0x18($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X18);
    // 0x80052B30: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x80052B34: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052B38: bne         $at, $zero, L_80052B9C
    if (ctx->r1 != 0) {
        // 0x80052B3C: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80052B9C;
    }
    // 0x80052B3C: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80052B40: bne         $t4, $zero, L_80052B9C
    if (ctx->r12 != 0) {
        // 0x80052B44: sh          $t3, 0x18($a0)
        MEM_H(0X18, ctx->r4) = ctx->r11;
            goto L_80052B9C;
    }
    // 0x80052B44: sh          $t3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r11;
    // 0x80052B48: lbu         $t5, 0x1F3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1F3);
    // 0x80052B4C: nop

    // 0x80052B50: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x80052B54: jr          $ra
    // 0x80052B58: sb          $t6, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r14;
    return;
    // 0x80052B58: sb          $t6, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = ctx->r14;
L_80052B5C:
    // 0x80052B5C: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80052B60: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x80052B64: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80052B68: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80052B6C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80052B70: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x80052B74: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80052B78: bne         $at, $zero, L_80052B9C
    if (ctx->r1 != 0) {
        // 0x80052B7C: nop
    
            goto L_80052B9C;
    }
    // 0x80052B7C: nop

    // 0x80052B80: sb          $zero, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = 0;
    // 0x80052B84: sb          $zero, 0x1F2($a1)
    MEM_B(0X1F2, ctx->r5) = 0;
    // 0x80052B88: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
    // 0x80052B8C: jr          $ra
    // 0x80052B90: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
    return;
    // 0x80052B90: sb          $zero, 0x1F3($a1)
    MEM_B(0X1F3, ctx->r5) = 0;
L_80052B94:
    // 0x80052B94: sh          $a3, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r7;
    // 0x80052B98: sb          $a2, 0x3B($a0)
    MEM_B(0X3B, ctx->r4) = ctx->r6;
L_80052B9C:
    // 0x80052B9C: jr          $ra
    // 0x80052BA0: nop

    return;
    // 0x80052BA0: nop

;}
RECOMP_FUNC void alCSeqGetTicks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87DC: jr          $ra
    // 0x800C87E0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    return;
    // 0x800C87E0: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
;}
RECOMP_FUNC void music_volume_config_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001A3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001A40: sltiu       $at, $a0, 0x101
    ctx->r1 = ctx->r4 < 0X101 ? 1 : 0;
    // 0x80001A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001A48: bne         $at, $zero, L_80001A54
    if (ctx->r1 != 0) {
        // 0x80001A4C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80001A54;
    }
    // 0x80001A4C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80001A50: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_80001A54:
    // 0x80001A54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80001A58: addiu       $v0, $v0, -0x343C
    ctx->r2 = ADD32(ctx->r2, -0X343C);
    // 0x80001A5C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x80001A60: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001A64: lbu         $t6, -0x3458($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X3458);
    // 0x80001A68: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80001A6C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001A70: lw          $t9, -0x3424($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3424);
    // 0x80001A74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001A78: lwc1        $f8, -0x3440($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3440);
    // 0x80001A7C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80001A80: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001A84: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80001A88: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001A8C: mflo        $t8
    ctx->r24 = lo;
    // 0x80001A90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80001A94: nop

    // 0x80001A98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001A9C: mul.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80001AA0: nop

    // 0x80001AA4: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80001AA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80001AAC: nop

    // 0x80001AB0: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80001AB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80001AB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80001ABC: nop

    // 0x80001AC0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80001AC4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80001AC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80001ACC: sra         $t1, $a1, 8
    ctx->r9 = S32(SIGNED(ctx->r5) >> 8);
    // 0x80001AD0: sll         $t2, $t1, 16
    ctx->r10 = S32(ctx->r9 << 16);
    // 0x80001AD4: jal         0x800C7DB0
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_0;
    // 0x80001AD8: sra         $a1, $t2, 16
    ctx->r5 = S32(SIGNED(ctx->r10) >> 16);
    after_0:
    // 0x80001ADC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001AE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001AE4: jr          $ra
    // 0x80001AE8: nop

    return;
    // 0x80001AE8: nop

;}
RECOMP_FUNC void menu_assetgroup_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CBB8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CBBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009CBC0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009CBC4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009CBC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CBCC: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CBD0: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CBD4: beq         $s2, $t6, L_8009CC04
    if (ctx->r18 == ctx->r14) {
        // 0x8009CBD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CC04;
    }
    // 0x8009CBD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CBDC: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CBE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CBE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CBE8:
    // 0x8009CBE8: jal         0x8009CC18
    // 0x8009CBEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_load(rdram, ctx);
        goto after_0;
    // 0x8009CBEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CBF0: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CBF4: nop

    // 0x8009CBF8: bne         $s2, $s1, L_8009CBE8
    if (ctx->r18 != ctx->r17) {
        // 0x8009CBFC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CBE8;
    }
    // 0x8009CBFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CC00: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CC04:
    // 0x8009CC04: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CC08: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CC0C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CC10: jr          $ra
    // 0x8009CC14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CC14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void __seqpStopOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AEFC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000AF00: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000AF04: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000AF08: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000AF0C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000AF10: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000AF14: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000AF18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000AF1C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000AF20: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000AF24: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x8000AF28: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8000AF2C: beq         $s0, $zero, L_8000AFE4
    if (ctx->r16 == 0) {
        // 0x8000AF30: or          $s5, $a0, $zero
        ctx->r21 = ctx->r4 | 0;
            goto L_8000AFE4;
    }
    // 0x8000AF30: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8000AF34: addiu       $s7, $zero, 0x17
    ctx->r23 = ADD32(0, 0X17);
    // 0x8000AF38: addiu       $s6, $zero, 0x16
    ctx->r22 = ADD32(0, 0X16);
L_8000AF3C:
    // 0x8000AF3C: lh          $s3, 0xC($s0)
    ctx->r19 = MEM_H(ctx->r16, 0XC);
    // 0x8000AF40: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x8000AF44: beq         $s3, $s6, L_8000AF54
    if (ctx->r19 == ctx->r22) {
        // 0x8000AF48: nop
    
            goto L_8000AF54;
    }
    // 0x8000AF48: nop

    // 0x8000AF4C: bne         $s3, $s7, L_8000AFDC
    if (ctx->r19 != ctx->r23) {
        // 0x8000AF50: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF50: nop

L_8000AF54:
    // 0x8000AF54: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x8000AF58: nop

    // 0x8000AF5C: bne         $s2, $t6, L_8000AFDC
    if (ctx->r18 != ctx->r14) {
        // 0x8000AF60: nop
    
            goto L_8000AFDC;
    }
    // 0x8000AF60: nop

    // 0x8000AF64: lw          $t9, 0x7C($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X7C);
    // 0x8000AF68: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8000AF6C: jalr        $t9
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8000AF70: addiu       $s4, $s5, 0x48
    ctx->r20 = ADD32(ctx->r21, 0X48);
    after_0:
    // 0x8000AF74: jal         0x800C8CC0
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x8000AF78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000AF7C: beq         $s1, $zero, L_8000AF98
    if (ctx->r17 == 0) {
        // 0x8000AF80: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000AF98;
    }
    // 0x8000AF80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000AF84: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x8000AF88: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000AF8C: nop

    // 0x8000AF90: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8000AF94: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_8000AF98:
    // 0x8000AF98: jal         0x800C8CF0
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x8000AF9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x8000AFA0: bne         $s3, $s6, L_8000AFBC
    if (ctx->r19 != ctx->r22) {
        // 0x8000AFA4: nop
    
            goto L_8000AFBC;
    }
    // 0x8000AFA4: nop

    // 0x8000AFA8: lbu         $t1, 0x37($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFAC: nop

    // 0x8000AFB0: andi        $t2, $t1, 0xFE
    ctx->r10 = ctx->r9 & 0XFE;
    // 0x8000AFB4: b           L_8000AFCC
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
        goto L_8000AFCC;
    // 0x8000AFB8: sb          $t2, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r10;
L_8000AFBC:
    // 0x8000AFBC: lbu         $t3, 0x37($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFC0: nop

    // 0x8000AFC4: andi        $t4, $t3, 0xFD
    ctx->r12 = ctx->r11 & 0XFD;
    // 0x8000AFC8: sb          $t4, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r12;
L_8000AFCC:
    // 0x8000AFCC: lbu         $t5, 0x37($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X37);
    // 0x8000AFD0: nop

    // 0x8000AFD4: beq         $t5, $zero, L_8000AFE8
    if (ctx->r13 == 0) {
        // 0x8000AFD8: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_8000AFE8;
    }
    // 0x8000AFD8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFDC:
    // 0x8000AFDC: bne         $s1, $zero, L_8000AF3C
    if (ctx->r17 != 0) {
        // 0x8000AFE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000AF3C;
    }
    // 0x8000AFE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_8000AFE4:
    // 0x8000AFE4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000AFE8:
    // 0x8000AFE8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000AFEC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000AFF0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AFF4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000AFF8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000AFFC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000B000: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B004: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000B008: jr          $ra
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000B00C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_current_text_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C55F4: blez        $a0, L_800C5630
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C55F8: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C5630;
    }
    // 0x800C55F8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C55FC: beq         $at, $zero, L_800C5630
    if (ctx->r1 == 0) {
        // 0x800C5600: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C5630;
    }
    // 0x800C5600: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5604: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C5608: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C560C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C5610: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C5614: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5618: lh          $t8, 0x20($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X20);
    // 0x800C561C: lh          $t0, 0x22($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X22);
    // 0x800C5620: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x800C5624: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x800C5628: sh          $t9, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r25;
    // 0x800C562C: sh          $t1, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r9;
L_800C5630:
    // 0x800C5630: jr          $ra
    // 0x800C5634: nop

    return;
    // 0x800C5634: nop

;}
RECOMP_FUNC void func_8000E5EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E5EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E5F0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E5F4: addiu       $t3, $t3, -0x4BE0
    ctx->r11 = ADD32(ctx->r11, -0X4BE0);
    // 0x8000E5F8: addiu       $a2, $a2, -0x4BE8
    ctx->r6 = ADD32(ctx->r6, -0X4BE8);
    // 0x8000E5FC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E600: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000E604: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x8000E608: lw          $a1, 0x4($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X4);
    // 0x8000E60C: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x8000E610: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E614: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E618: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E61C: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8000E620: addu        $t4, $t9, $a1
    ctx->r12 = ADD32(ctx->r25, ctx->r5);
    // 0x8000E624: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E628: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8000E62C: bne         $at, $zero, L_8000E648
    if (ctx->r1 != 0) {
        // 0x8000E630: sw          $t4, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r12;
            goto L_8000E648;
    }
    // 0x8000E630: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x8000E634: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000E638: beq         $at, $zero, L_8000E64C
    if (ctx->r1 == 0) {
        // 0x8000E63C: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000E64C;
    }
    // 0x8000E63C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000E640: b           L_8000E66C
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
        goto L_8000E66C;
    // 0x8000E644: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_8000E648:
    // 0x8000E648: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_8000E64C:
    // 0x8000E64C: bne         $at, $zero, L_8000E670
    if (ctx->r1 != 0) {
        // 0x8000E650: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E650: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E654: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8000E658: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000E65C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E660: beq         $at, $zero, L_8000E670
    if (ctx->r1 == 0) {
        // 0x8000E664: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_8000E670;
    }
    // 0x8000E664: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E668: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_8000E66C:
    // 0x8000E66C: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_8000E670:
    // 0x8000E670: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x8000E674: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8000E678: addu        $a3, $sp, $t8
    ctx->r7 = ADD32(ctx->r29, ctx->r24);
    // 0x8000E67C: lw          $a3, 0x2C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X2C);
    // 0x8000E680: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8000E684: sltu        $at, $a2, $a3
    ctx->r1 = ctx->r6 < ctx->r7 ? 1 : 0;
    // 0x8000E688: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000E68C: beq         $at, $zero, L_8000E6F0
    if (ctx->r1 == 0) {
        // 0x8000E690: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_8000E6F0;
    }
    // 0x8000E690: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x8000E694: subu        $t2, $a3, $a2
    ctx->r10 = SUB32(ctx->r7, ctx->r6);
    // 0x8000E698: andi        $t9, $t2, 0x3
    ctx->r25 = ctx->r10 & 0X3;
    // 0x8000E69C: beq         $t9, $zero, L_8000E6C0
    if (ctx->r25 == 0) {
        // 0x8000E6A0: addu        $t1, $t9, $a2
        ctx->r9 = ADD32(ctx->r25, ctx->r6);
            goto L_8000E6C0;
    }
    // 0x8000E6A0: addu        $t1, $t9, $a2
    ctx->r9 = ADD32(ctx->r25, ctx->r6);
L_8000E6A4:
    // 0x8000E6A4: lbu         $t4, 0x0($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6A8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E6AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000E6B0: bne         $t1, $a1, L_8000E6A4
    if (ctx->r9 != ctx->r5) {
        // 0x8000E6B4: sb          $t4, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r12;
            goto L_8000E6A4;
    }
    // 0x8000E6B4: sb          $t4, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r12;
    // 0x8000E6B8: beq         $a1, $a3, L_8000E6F0
    if (ctx->r5 == ctx->r7) {
        // 0x8000E6BC: nop
    
            goto L_8000E6F0;
    }
    // 0x8000E6BC: nop

L_8000E6C0:
    // 0x8000E6C0: lbu         $t5, 0x0($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X0);
    // 0x8000E6C4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8000E6C8: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x8000E6CC: lbu         $t6, -0x3($a1)
    ctx->r14 = MEM_BU(ctx->r5, -0X3);
    // 0x8000E6D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000E6D4: sb          $t6, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r14;
    // 0x8000E6D8: lbu         $t7, -0x2($a1)
    ctx->r15 = MEM_BU(ctx->r5, -0X2);
    // 0x8000E6DC: nop

    // 0x8000E6E0: sb          $t7, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r15;
    // 0x8000E6E4: lbu         $t8, -0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, -0X1);
    // 0x8000E6E8: bne         $a1, $a3, L_8000E6C0
    if (ctx->r5 != ctx->r7) {
        // 0x8000E6EC: sb          $t8, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r24;
            goto L_8000E6C0;
    }
    // 0x8000E6EC: sb          $t8, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r24;
L_8000E6F0:
    // 0x8000E6F0: addu        $v1, $t3, $t0
    ctx->r3 = ADD32(ctx->r11, ctx->r8);
    // 0x8000E6F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8000E6F8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E6FC: subu        $t4, $t9, $v0
    ctx->r12 = SUB32(ctx->r25, ctx->r2);
    // 0x8000E700: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8000E704: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E708: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000E70C: blez        $a2, L_8000E794
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8000E710: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8000E794;
    }
    // 0x8000E710: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000E714: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000E718: addiu       $t3, $t3, -0x4C28
    ctx->r11 = ADD32(ctx->r11, -0X4C28);
L_8000E71C:
    // 0x8000E71C: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8000E720: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000E724: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E728: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8000E72C: nop

    // 0x8000E730: beq         $v1, $zero, L_8000E78C
    if (ctx->r3 == 0) {
        // 0x8000E734: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E734: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E738: lw          $t1, 0x3C($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X3C);
    // 0x8000E73C: nop

    // 0x8000E740: beq         $t1, $zero, L_8000E788
    if (ctx->r9 == 0) {
        // 0x8000E744: slt         $at, $a0, $t1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8000E788;
    }
    // 0x8000E744: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8000E748: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E74C: or          $t2, $t1, $zero
        ctx->r10 = ctx->r9 | 0;
            goto L_8000E770;
    }
    // 0x8000E74C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x8000E750: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8000E754: beq         $at, $zero, L_8000E770
    if (ctx->r1 == 0) {
        // 0x8000E758: subu        $t7, $t1, $v0
        ctx->r15 = SUB32(ctx->r9, ctx->r2);
            goto L_8000E770;
    }
    // 0x8000E758: subu        $t7, $t1, $v0
    ctx->r15 = SUB32(ctx->r9, ctx->r2);
    // 0x8000E75C: sw          $t7, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->r15;
    // 0x8000E760: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E764: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E768: b           L_8000E78C
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
        goto L_8000E78C;
    // 0x8000E76C: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E770:
    // 0x8000E770: bne         $a0, $t2, L_8000E78C
    if (ctx->r4 != ctx->r10) {
        // 0x8000E774: slt         $at, $a1, $a2
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8000E78C;
    }
    // 0x8000E774: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000E778: sw          $zero, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = 0;
    // 0x8000E77C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E780: lw          $a2, -0x4C24($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4C24);
    // 0x8000E784: nop

L_8000E788:
    // 0x8000E788: slt         $at, $a1, $a2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r6) ? 1 : 0;
L_8000E78C:
    // 0x8000E78C: bne         $at, $zero, L_8000E71C
    if (ctx->r1 != 0) {
        // 0x8000E790: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E71C;
    }
    // 0x8000E790: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8000E794:
    // 0x8000E794: jr          $ra
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000E798: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void set_magic_code_flags(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C824: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C828: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009C82C: addiu       $v1, $v1, 0x31C
    ctx->r3 = ADD32(ctx->r3, 0X31C);
    // 0x8009C830: addiu       $v0, $v0, 0x318
    ctx->r2 = ADD32(ctx->r2, 0X318);
    // 0x8009C834: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8009C838: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8009C83C: or          $t7, $t6, $a0
    ctx->r15 = ctx->r14 | ctx->r4;
    // 0x8009C840: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x8009C844: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8009C848: jr          $ra
    // 0x8009C84C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x8009C84C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void func_8002A31C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A35C: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x8002A360: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x8002A364: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x8002A368: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x8002A36C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x8002A370: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x8002A374: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x8002A378: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x8002A37C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8002A380: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8002A384: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8002A388: swc1        $f31, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x8002A38C: swc1        $f30, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f30.u32l;
    // 0x8002A390: swc1        $f29, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002A394: swc1        $f28, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f28.u32l;
    // 0x8002A398: swc1        $f27, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8002A39C: swc1        $f26, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f26.u32l;
    // 0x8002A3A0: swc1        $f25, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002A3A4: swc1        $f24, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f24.u32l;
    // 0x8002A3A8: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002A3AC: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x8002A3B0: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002A3B4: jal         0x80069FE4
    // 0x8002A3B8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    get_projection_matrix_f32(rdram, ctx);
        goto after_0;
    // 0x8002A3B8: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8002A3BC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002A3C0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002A3C4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8002A3C8: addiu       $s1, $s1, -0x2988
    ctx->r17 = ADD32(ctx->r17, -0X2988);
    // 0x8002A3CC: addiu       $s0, $s0, -0x31E4
    ctx->r16 = ADD32(ctx->r16, -0X31E4);
    // 0x8002A3D0: addiu       $fp, $sp, 0xB8
    ctx->r30 = ADD32(ctx->r29, 0XB8);
    // 0x8002A3D4: addiu       $s7, $sp, 0xBC
    ctx->r23 = ADD32(ctx->r29, 0XBC);
    // 0x8002A3D8: addiu       $s6, $sp, 0xC0
    ctx->r22 = ADD32(ctx->r29, 0XC0);
    // 0x8002A3DC: addiu       $s5, $sp, 0xC4
    ctx->r21 = ADD32(ctx->r29, 0XC4);
    // 0x8002A3E0: addiu       $s4, $sp, 0xC8
    ctx->r20 = ADD32(ctx->r29, 0XC8);
    // 0x8002A3E4: addiu       $s3, $sp, 0xCC
    ctx->r19 = ADD32(ctx->r29, 0XCC);
L_8002A3E8:
    // 0x8002A3E8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8002A3EC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8002A3F0: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8002A3F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8002A3F8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8002A3FC: mfc1        $a3, $f12
    ctx->r7 = (int32_t)ctx->f12.u32l;
    // 0x8002A400: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A404: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8002A408: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x8002A40C: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x8002A410: swc1        $f0, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f0.u32l;
    // 0x8002A414: swc1        $f2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f2.u32l;
    // 0x8002A418: jal         0x8006F88C
    // 0x8002A41C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x8002A41C: swc1        $f12, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8002A420: lwc1        $f14, 0xC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8002A424: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8002A428: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8002A42C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002A430: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8002A434: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8002A438: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A43C: sw          $s6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r22;
    // 0x8002A440: sw          $s7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r23;
    // 0x8002A444: sw          $fp, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r30;
    // 0x8002A448: swc1        $f14, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f14.u32l;
    // 0x8002A44C: swc1        $f16, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f16.u32l;
    // 0x8002A450: jal         0x8006F88C
    // 0x8002A454: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x8002A454: swc1        $f18, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8002A458: lwc1        $f26, 0x18($s0)
    ctx->f26.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8002A45C: lwc1        $f28, 0x1C($s0)
    ctx->f28.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8002A460: lwc1        $f30, 0x20($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8002A464: addiu       $t6, $sp, 0xB4
    ctx->r14 = ADD32(ctx->r29, 0XB4);
    // 0x8002A468: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x8002A46C: addiu       $t8, $sp, 0xAC
    ctx->r24 = ADD32(ctx->r29, 0XAC);
    // 0x8002A470: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8002A474: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8002A478: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x8002A47C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8002A480: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002A484: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002A488: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002A48C: swc1        $f26, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f26.u32l;
    // 0x8002A490: swc1        $f28, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f28.u32l;
    // 0x8002A494: jal         0x8006F88C
    // 0x8002A498: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x8002A498: swc1        $f30, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f30.u32l;
    after_3:
    // 0x8002A49C: lwc1        $f18, 0xB8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8002A4A0: lwc1        $f30, 0xAC($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002A4A4: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A4A8: sub.s       $f4, $f18, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f30.fl;
    // 0x8002A4AC: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A4B0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8002A4B4: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8002A4B8: lwc1        $f28, 0xB0($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8002A4BC: lwc1        $f14, 0xC0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8002A4C0: sub.s       $f8, $f30, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f30.fl - ctx->f12.fl;
    // 0x8002A4C4: lwc1        $f26, 0xB4($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8002A4C8: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002A4CC: sub.s       $f8, $f12, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002A4D0: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A4D4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002A4D8: mul.s       $f6, $f28, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f28.fl, ctx->f8.fl);
    // 0x8002A4DC: sub.s       $f10, $f14, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f26.fl;
    // 0x8002A4E0: mul.s       $f8, $f10, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002A4E4: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8002A4E8: sub.s       $f4, $f26, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8002A4EC: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8002A4F0: sub.s       $f4, $f0, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x8002A4F4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002A4F8: mul.s       $f8, $f30, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f30.fl, ctx->f4.fl);
    // 0x8002A4FC: sub.s       $f6, $f16, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f28.fl;
    // 0x8002A500: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002A504: add.s       $f22, $f10, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002A508: sub.s       $f10, $f28, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f28.fl - ctx->f2.fl;
    // 0x8002A50C: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002A510: sub.s       $f10, $f2, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x8002A514: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A518: mul.s       $f4, $f26, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x8002A51C: nop

    // 0x8002A520: mul.s       $f8, $f20, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8002A524: add.s       $f24, $f6, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8002A528: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8002A52C: nop

    // 0x8002A530: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8002A534: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002A538: jal         0x800CA030
    // 0x8002A53C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8002A53C: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_4:
    // 0x8002A540: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8002A544: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002A548: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002A54C: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8002A550: nop

    // 0x8002A554: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8002A558: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002A55C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002A560: lwc1        $f0, 0xCC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x8002A564: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x8002A568: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x8002A56C: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x8002A570: nop

    // 0x8002A574: bc1f        L_8002A594
    if (!c1cs) {
        // 0x8002A578: nop
    
            goto L_8002A594;
    }
    // 0x8002A578: nop

    // 0x8002A57C: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8002A580: nop

    // 0x8002A584: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8002A588: nop

    // 0x8002A58C: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8002A590: nop

L_8002A594:
    // 0x8002A594: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8002A598: lwc1        $f2, 0xC8($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8002A59C: lwc1        $f12, 0xC4($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8002A5A0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002A5A4: mul.s       $f6, $f2, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8002A5A8: addiu       $t9, $t9, -0x2958
    ctx->r25 = ADD32(ctx->r25, -0X2958);
    // 0x8002A5AC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8002A5B0: swc1        $f20, -0x10($s1)
    MEM_W(-0X10, ctx->r17) = ctx->f20.u32l;
    // 0x8002A5B4: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002A5B8: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002A5BC: swc1        $f22, -0xC($s1)
    MEM_W(-0XC, ctx->r17) = ctx->f22.u32l;
    // 0x8002A5C0: swc1        $f24, -0x8($s1)
    MEM_W(-0X8, ctx->r17) = ctx->f24.u32l;
    // 0x8002A5C4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8002A5C8: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x8002A5CC: neg.s       $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = -ctx->f10.fl;
    // 0x8002A5D0: bne         $s1, $t9, L_8002A3E8
    if (ctx->r17 != ctx->r25) {
        // 0x8002A5D4: swc1        $f6, -0x4($s1)
        MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
            goto L_8002A3E8;
    }
    // 0x8002A5D4: swc1        $f6, -0x4($s1)
    MEM_W(-0X4, ctx->r17) = ctx->f6.u32l;
    // 0x8002A5D8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x8002A5DC: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002A5E0: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002A5E4: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8002A5E8: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002A5EC: lwc1        $f25, 0x38($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8002A5F0: lwc1        $f24, 0x3C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002A5F4: lwc1        $f27, 0x40($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x8002A5F8: lwc1        $f26, 0x44($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002A5FC: lwc1        $f29, 0x48($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X48);
    // 0x8002A600: lwc1        $f28, 0x4C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002A604: lwc1        $f31, 0x50($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X50);
    // 0x8002A608: lwc1        $f30, 0x54($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8002A60C: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8002A610: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8002A614: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8002A618: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x8002A61C: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x8002A620: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x8002A624: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x8002A628: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x8002A62C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x8002A630: jr          $ra
    // 0x8002A634: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x8002A634: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void rain_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD6A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD6A8: addiu       $v0, $v0, 0x31F0
    ctx->r2 = ADD32(ctx->r2, 0X31F0);
    // 0x800AD6AC: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x800AD6B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6B4: sw          $zero, 0x31F4($at)
    MEM_W(0X31F4, ctx->r1) = 0;
    // 0x800AD6B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AD6BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AD6C4: sw          $t6, 0x31F8($at)
    MEM_W(0X31F8, ctx->r1) = ctx->r14;
    // 0x800AD6C8: addiu       $v1, $v1, 0x31FC
    ctx->r3 = ADD32(ctx->r3, 0X31FC);
    // 0x800AD6CC: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800AD6D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6D4: sw          $zero, 0x3200($at)
    MEM_W(0X3200, ctx->r1) = 0;
    // 0x800AD6D8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AD6DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6E0: sw          $t7, 0x3204($at)
    MEM_W(0X3204, ctx->r1) = ctx->r15;
    // 0x800AD6E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6E8: sw          $zero, 0x3208($at)
    MEM_W(0X3208, ctx->r1) = 0;
    // 0x800AD6EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6F0: sw          $zero, 0x320C($at)
    MEM_W(0X320C, ctx->r1) = 0;
    // 0x800AD6F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD6F8: sw          $zero, 0x3210($at)
    MEM_W(0X3210, ctx->r1) = 0;
    // 0x800AD6FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD700: sw          $zero, 0x3214($at)
    MEM_W(0X3214, ctx->r1) = 0;
    // 0x800AD704: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800AD708: lw          $t8, 0x2EAC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2EAC);
    // 0x800AD70C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD710: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD714: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD718: sw          $zero, 0x3220($at)
    MEM_W(0X3220, ctx->r1) = 0;
    // 0x800AD71C: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x800AD720: jal         0x8007B2C4
    // 0x800AD724: nop

    load_texture(rdram, ctx);
        goto after_0;
    // 0x800AD724: nop

    after_0:
    // 0x800AD728: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800AD72C: lw          $t9, 0x2EAC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2EAC);
    // 0x800AD730: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD734: sw          $v0, 0x31C8($at)
    MEM_W(0X31C8, ctx->r1) = ctx->r2;
    // 0x800AD738: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800AD73C: jal         0x8007B2C4
    // 0x800AD740: nop

    load_texture(rdram, ctx);
        goto after_1;
    // 0x800AD740: nop

    after_1:
    // 0x800AD744: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AD748: lw          $t0, 0x2EAC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2EAC);
    // 0x800AD74C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD750: sw          $v0, 0x31E0($at)
    MEM_W(0X31E0, ctx->r1) = ctx->r2;
    // 0x800AD754: lw          $a0, 0xC($t0)
    ctx->r4 = MEM_W(ctx->r8, 0XC);
    // 0x800AD758: jal         0x8007C57C
    // 0x800AD75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_2;
    // 0x800AD75C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800AD760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD768: sw          $v0, 0x321C($at)
    MEM_W(0X321C, ctx->r1) = ctx->r2;
    // 0x800AD76C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD770: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AD774: sw          $t1, 0x31EC($at)
    MEM_W(0X31EC, ctx->r1) = ctx->r9;
    // 0x800AD778: jr          $ra
    // 0x800AD77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD77C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void disable_cutscene_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066764: jr          $ra
    // 0x80066768: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
    return;
    // 0x80066768: sb          $zero, 0x1294($at)
    MEM_B(0X1294, ctx->r1) = 0;
;}
RECOMP_FUNC void savemenu_move(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086E88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80086E8C: lw          $t6, 0x7194($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7194);
    // 0x80086E90: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80086E94: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80086E98: lw          $t7, 0x71A4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X71A4);
    // 0x80086E9C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086EA0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80086EA4: blez        $a0, L_80086F34
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80086EA8: cvt.s.w     $f2, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80086F34;
    }
    // 0x80086EA8: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80086EAC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80086EB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80086EB4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80086EB8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80086EBC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80086EC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80086EC4: lwc1        $f16, -0x765C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X765C);
    // 0x80086EC8: lw          $v1, 0x6980($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6980);
    // 0x80086ECC: lw          $v0, 0x6FC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6FC8);
    // 0x80086ED0: addiu       $a1, $a1, 0x719C
    ctx->r5 = ADD32(ctx->r5, 0X719C);
    // 0x80086ED4: addiu       $a2, $a2, 0x6FC0
    ctx->r6 = ADD32(ctx->r6, 0X6FC0);
    // 0x80086ED8: addiu       $a3, $a3, 0x71AC
    ctx->r7 = ADD32(ctx->r7, 0X71AC);
L_80086EDC:
    // 0x80086EDC: blez        $v0, L_80086EFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80086EE0: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_80086EFC;
    }
    // 0x80086EE0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80086EE4: lwc1        $f14, 0x0($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80086EE8: nop

    // 0x80086EEC: sub.s       $f12, $f0, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80086EF0: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086EF4: add.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x80086EF8: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_80086EFC:
    // 0x80086EFC: blez        $v1, L_80086F2C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80086F00: nop
    
            goto L_80086F2C;
    }
    // 0x80086F00: nop

    // 0x80086F04: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086F08: nop

    // 0x80086F0C: blez        $t8, L_80086F2C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086F10: nop
    
            goto L_80086F2C;
    }
    // 0x80086F10: nop

    // 0x80086F14: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x80086F18: nop

    // 0x80086F1C: sub.s       $f12, $f2, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80086F20: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80086F24: add.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f18.fl;
    // 0x80086F28: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
L_80086F2C:
    // 0x80086F2C: bgtz        $a0, L_80086EDC
    if (SIGNED(ctx->r4) > 0) {
        // 0x80086F30: nop
    
            goto L_80086EDC;
    }
    // 0x80086F30: nop

L_80086F34:
    // 0x80086F34: jr          $ra
    // 0x80086F38: nop

    return;
    // 0x80086F38: nop

;}
RECOMP_FUNC void mempool_print_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071F28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071F2C: lw          $v0, 0x3B40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3B40);
    // 0x80071F30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80071F34: beq         $v0, $a1, L_80071F68
    if (ctx->r2 == ctx->r5) {
        // 0x80071F38: addiu       $a0, $v0, 0x1
        ctx->r4 = ADD32(ctx->r2, 0X1);
            goto L_80071F68;
    }
    // 0x80071F38: addiu       $a0, $v0, 0x1
    ctx->r4 = ADD32(ctx->r2, 0X1);
    // 0x80071F3C: andi        $t6, $a0, 0x3
    ctx->r14 = ctx->r4 & 0X3;
    // 0x80071F40: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80071F44: beq         $a0, $zero, L_80071F5C
    if (ctx->r4 == 0) {
        // 0x80071F48: addu        $v1, $a0, $v0
        ctx->r3 = ADD32(ctx->r4, ctx->r2);
            goto L_80071F5C;
    }
    // 0x80071F48: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
L_80071F4C:
    // 0x80071F4C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80071F50: bne         $v1, $v0, L_80071F4C
    if (ctx->r3 != ctx->r2) {
        // 0x80071F54: nop
    
            goto L_80071F4C;
    }
    // 0x80071F54: nop

    // 0x80071F58: beq         $v0, $a1, L_80071F68
    if (ctx->r2 == ctx->r5) {
        // 0x80071F5C: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071F68;
    }
L_80071F5C:
    // 0x80071F5C: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071F60:
    // 0x80071F60: bne         $v0, $a1, L_80071F60
    if (ctx->r2 != ctx->r5) {
        // 0x80071F64: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_80071F60;
    }
    // 0x80071F64: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_80071F68:
    // 0x80071F68: jr          $ra
    // 0x80071F6C: nop

    return;
    // 0x80071F6C: nop

;}
RECOMP_FUNC void func_80024594(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245C8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800245CC: lw          $t6, -0x3390($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3390);
    // 0x800245D0: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800245D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800245D8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800245DC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800245E0: jr          $ra
    // 0x800245E4: addiu       $v0, $v0, -0x4E60
    ctx->r2 = ADD32(ctx->r2, -0X4E60);
    return;
    // 0x800245E4: addiu       $v0, $v0, -0x4E60
    ctx->r2 = ADD32(ctx->r2, -0X4E60);
;}
RECOMP_FUNC void func_8000CBF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CBF0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000CBF4: addiu       $t7, $t7, -0x4C78
    ctx->r15 = ADD32(ctx->r15, -0X4C78);
    // 0x8000CBF8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8000CBFC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8000CC00: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8000CC04: nop

    // 0x8000CC08: bne         $v1, $zero, L_8000CC18
    if (ctx->r3 != 0) {
        // 0x8000CC0C: nop
    
            goto L_8000CC18;
    }
    // 0x8000CC0C: nop

    // 0x8000CC10: jr          $ra
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    return;
    // 0x8000CC14: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_8000CC18:
    // 0x8000CC18: jr          $ra
    // 0x8000CC1C: nop

    return;
    // 0x8000CC1C: nop

;}
RECOMP_FUNC void menu_results_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800977E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800977E8: addiu       $v0, $v0, 0x695C
    ctx->r2 = ADD32(ctx->r2, 0X695C);
    // 0x800977EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800977F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800977F4: addu        $t8, $t6, $a0
    ctx->r24 = ADD32(ctx->r14, ctx->r4);
    // 0x800977F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800977FC: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x80097800: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80097804: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80097808: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8009780C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80097810: jal         0x8008E9A4
    // 0x80097814: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    menu_input(rdram, ctx);
        goto after_0;
    // 0x80097814: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80097818: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009781C: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x80097820: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80097824: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80097828: bgtz        $v1, L_80097878
    if (SIGNED(ctx->r3) > 0) {
        // 0x8009782C: addiu       $a3, $a3, 0x6978
        ctx->r7 = ADD32(ctx->r7, 0X6978);
            goto L_80097878;
    }
    // 0x8009782C: addiu       $a3, $a3, 0x6978
    ctx->r7 = ADD32(ctx->r7, 0X6978);
    // 0x80097830: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80097834: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80097838: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009783C: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80097840: slti        $at, $v0, 0x3C
    ctx->r1 = SIGNED(ctx->r2) < 0X3C ? 1 : 0;
    // 0x80097844: bne         $at, $zero, L_80097854
    if (ctx->r1 != 0) {
        // 0x80097848: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_80097854;
    }
    // 0x80097848: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8009784C: b           L_80097878
    // 0x80097850: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80097878;
    // 0x80097850: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80097854:
    // 0x80097854: bgez        $v1, L_80097878
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80097858: slti        $at, $v0, 0x15
        ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
            goto L_80097878;
    }
    // 0x80097858: slti        $at, $v0, 0x15
    ctx->r1 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8009785C: bne         $at, $zero, L_80097878
    if (ctx->r1 != 0) {
        // 0x80097860: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_80097878;
    }
    // 0x80097860: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80097864: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80097868: jal         0x80001D04
    // 0x8009786C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8009786C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80097870: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097874: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
L_80097878:
    // 0x80097878: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009787C: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x80097880: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80097884: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80097888: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8009788C: addiu       $a3, $a3, 0x6978
    ctx->r7 = ADD32(ctx->r7, 0X6978);
    // 0x80097890: beq         $at, $zero, L_80097930
    if (ctx->r1 == 0) {
        // 0x80097894: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80097930;
    }
    // 0x80097894: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80097898: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8009789C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800978A0: bgtz        $t5, L_8009790C
    if (SIGNED(ctx->r13) > 0) {
        // 0x800978A4: nop
    
            goto L_8009790C;
    }
    // 0x800978A4: nop

    // 0x800978A8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x800978AC: nop

    // 0x800978B0: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800978B4: bne         $at, $zero, L_80097930
    if (ctx->r1 != 0) {
        // 0x800978B8: addiu       $t6, $v0, -0x14
        ctx->r14 = ADD32(ctx->r2, -0X14);
            goto L_80097930;
    }
    // 0x800978B8: addiu       $t6, $v0, -0x14
    ctx->r14 = ADD32(ctx->r2, -0X14);
    // 0x800978BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800978C0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x800978C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800978C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800978CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800978D0: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800978D4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800978D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800978DC: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800978E0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800978E4: jal         0x80096E7C
    // 0x800978E8: nop

    results_render(rdram, ctx);
        goto after_2;
    // 0x800978E8: nop

    after_2:
    // 0x800978EC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800978F0: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x800978F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800978F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800978FC: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x80097900: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x80097904: b           L_80097930
    // 0x80097908: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80097930;
    // 0x80097908: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8009790C:
    // 0x8009790C: jal         0x80096E7C
    // 0x80097910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    results_render(rdram, ctx);
        goto after_3;
    // 0x80097910: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_3:
    // 0x80097914: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80097918: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009791C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80097920: lw          $v1, -0x604($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X604);
    // 0x80097924: addiu       $t1, $t1, -0x604
    ctx->r9 = ADD32(ctx->r9, -0X604);
    // 0x80097928: addiu       $a2, $a2, 0x6980
    ctx->r6 = ADD32(ctx->r6, 0X6980);
    // 0x8009792C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80097930:
    // 0x80097930: bne         $v1, $zero, L_80097B54
    if (ctx->r3 != 0) {
        // 0x80097934: lw          $t8, 0x28($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X28);
            goto L_80097B54;
    }
    // 0x80097934: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80097938: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8009793C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097940: bne         $t7, $zero, L_80097968
    if (ctx->r15 != 0) {
        // 0x80097944: addiu       $a0, $a0, 0xF08
        ctx->r4 = ADD32(ctx->r4, 0XF08);
            goto L_80097968;
    }
    // 0x80097944: addiu       $a0, $a0, 0xF08
    ctx->r4 = ADD32(ctx->r4, 0XF08);
    // 0x80097948: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009794C: lw          $t8, 0x6D88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D88);
    // 0x80097950: nop

    // 0x80097954: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x80097958: beq         $t9, $zero, L_80097AFC
    if (ctx->r25 == 0) {
        // 0x8009795C: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80097AFC;
    }
    // 0x8009795C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097960: b           L_80097AF8
    // 0x80097964: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
        goto L_80097AF8;
    // 0x80097964: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80097968:
    // 0x80097968: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8009796C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097970: beq         $v0, $zero, L_80097A28
    if (ctx->r2 == 0) {
        // 0x80097974: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80097A28;
    }
    // 0x80097974: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80097978: lw          $v1, 0x6D88($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D88);
    // 0x8009797C: nop

    // 0x80097980: andi        $t2, $v1, 0x9000
    ctx->r10 = ctx->r3 & 0X9000;
    // 0x80097984: beq         $t2, $zero, L_800979C8
    if (ctx->r10 == 0) {
        // 0x80097988: andi        $t4, $v1, 0x4000
        ctx->r12 = ctx->r3 & 0X4000;
            goto L_800979C8;
    }
    // 0x80097988: andi        $t4, $v1, 0x4000
    ctx->r12 = ctx->r3 & 0X4000;
    // 0x8009798C: bne         $t0, $v0, L_800979BC
    if (ctx->r8 != ctx->r2) {
        // 0x80097990: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_800979BC;
    }
    // 0x80097990: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80097994: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80097998: jal         0x80000C98
    // 0x8009799C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_4;
    // 0x8009799C: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_4:
    // 0x800979A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800979A4: jal         0x800C06F8
    // 0x800979A8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x800979A8: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_5:
    // 0x800979AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800979B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800979B4: b           L_80097AF8
    // 0x800979B8: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
        goto L_80097AF8;
    // 0x800979B8: sw          $t0, -0x604($at)
    MEM_W(-0X604, ctx->r1) = ctx->r8;
L_800979BC:
    // 0x800979BC: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800979C0: b           L_80097AF8
    // 0x800979C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80097AF8;
    // 0x800979C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800979C8:
    // 0x800979C8: beq         $t4, $zero, L_800979E0
    if (ctx->r12 == 0) {
        // 0x800979CC: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800979E0;
    }
    // 0x800979CC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800979D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800979D4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800979D8: b           L_80097AF8
    // 0x800979DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
        goto L_80097AF8;
    // 0x800979DC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_800979E0:
    // 0x800979E0: lh          $v1, 0x6DD8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD8);
    // 0x800979E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800979E8: blez        $v1, L_80097A00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800979EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80097A00;
    }
    // 0x800979EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800979F0: bne         $v0, $at, L_80097A00
    if (ctx->r2 != ctx->r1) {
        // 0x800979F4: nop
    
            goto L_80097A00;
    }
    // 0x800979F4: nop

    // 0x800979F8: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800979FC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80097A00:
    // 0x80097A00: bgez        $v1, L_80097A18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80097A04: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80097A18;
    }
    // 0x80097A04: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80097A08: bne         $t0, $v0, L_80097A18
    if (ctx->r8 != ctx->r2) {
        // 0x80097A0C: nop
    
            goto L_80097A18;
    }
    // 0x80097A0C: nop

    // 0x80097A10: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80097A14: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80097A18:
    // 0x80097A18: beq         $a1, $v0, L_80097AFC
    if (ctx->r5 == ctx->r2) {
        // 0x80097A1C: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80097AFC;
    }
    // 0x80097A1C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097A20: b           L_80097AF8
    // 0x80097A24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_80097AF8;
    // 0x80097A24: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80097A28:
    // 0x80097A28: lw          $t8, 0x6D88($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D88);
    // 0x80097A2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097A30: andi        $t9, $t8, 0x9000
    ctx->r25 = ctx->r24 & 0X9000;
    // 0x80097A34: beq         $t9, $zero, L_80097A9C
    if (ctx->r25 == 0) {
        // 0x80097A38: addiu       $a2, $a2, 0x7028
        ctx->r6 = ADD32(ctx->r6, 0X7028);
            goto L_80097A9C;
    }
    // 0x80097A38: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80097A3C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097A40: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80097A44: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80097A48: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80097A4C: lw          $t5, -0x5E0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E0);
    // 0x80097A50: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80097A54: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80097A58: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80097A5C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80097A60: lw          $t4, 0x71B0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X71B0);
    // 0x80097A64: lw          $t6, 0x70($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X70);
    // 0x80097A68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80097A6C: bne         $t4, $t6, L_80097A7C
    if (ctx->r12 != ctx->r14) {
        // 0x80097A70: nop
    
            goto L_80097A7C;
    }
    // 0x80097A70: nop

    // 0x80097A74: b           L_80097AF8
    // 0x80097A78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
        goto L_80097AF8;
    // 0x80097A78: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_80097A7C:
    // 0x80097A7C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80097A80: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x80097A84: jal         0x800C06F8
    // 0x80097A88: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    transition_begin(rdram, ctx);
        goto after_6;
    // 0x80097A88: addiu       $a0, $a0, -0x30C
    ctx->r4 = ADD32(ctx->r4, -0X30C);
    after_6:
    // 0x80097A8C: jal         0x80000C98
    // 0x80097A90: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_7;
    // 0x80097A90: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_7:
    // 0x80097A94: b           L_80097AFC
    // 0x80097A98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
        goto L_80097AFC;
    // 0x80097A98: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_80097A9C:
    // 0x80097A9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80097AA0: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80097AA4: lh          $v1, 0x6DD8($v1)
    ctx->r3 = MEM_H(ctx->r3, 0X6DD8);
    // 0x80097AA8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80097AAC: bgez        $v1, L_80097AD4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80097AB0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80097AD4;
    }
    // 0x80097AB0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80097AB4: lw          $t8, 0x71D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X71D4);
    // 0x80097AB8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80097ABC: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80097AC0: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80097AC4: beq         $at, $zero, L_80097AD4
    if (ctx->r1 == 0) {
        // 0x80097AC8: nop
    
            goto L_80097AD4;
    }
    // 0x80097AC8: nop

    // 0x80097ACC: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    // 0x80097AD0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_80097AD4:
    // 0x80097AD4: blez        $v1, L_80097AEC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80097AD8: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80097AEC;
    }
    // 0x80097AD8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80097ADC: blez        $v0, L_80097AEC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80097AE0: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80097AEC;
    }
    // 0x80097AE0: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80097AE4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80097AE8: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80097AEC:
    // 0x80097AEC: beq         $a1, $v0, L_80097AFC
    if (ctx->r5 == ctx->r2) {
        // 0x80097AF0: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80097AFC;
    }
    // 0x80097AF0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80097AF4: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
L_80097AF8:
    // 0x80097AF8: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_80097AFC:
    // 0x80097AFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80097B00: beq         $t4, $zero, L_80097B18
    if (ctx->r12 == 0) {
        // 0x80097B04: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80097B18;
    }
    // 0x80097B04: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80097B08: jal         0x80001D04
    // 0x80097B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x80097B0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80097B10: b           L_80097BEC
    // 0x80097B14: nop

        goto L_80097BEC;
    // 0x80097B14: nop

L_80097B18:
    // 0x80097B18: beq         $t6, $zero, L_80097B30
    if (ctx->r14 == 0) {
        // 0x80097B1C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80097B30;
    }
    // 0x80097B1C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80097B20: jal         0x80001D04
    // 0x80097B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x80097B24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80097B28: b           L_80097BEC
    // 0x80097B2C: nop

        goto L_80097BEC;
    // 0x80097B2C: nop

L_80097B30:
    // 0x80097B30: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80097B34: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80097B38: beq         $t7, $zero, L_80097BEC
    if (ctx->r15 == 0) {
        // 0x80097B3C: nop
    
            goto L_80097BEC;
    }
    // 0x80097B3C: nop

    // 0x80097B40: jal         0x80001D04
    // 0x80097B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80097B44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80097B48: b           L_80097BEC
    // 0x80097B4C: nop

        goto L_80097BEC;
    // 0x80097B4C: nop

    // 0x80097B50: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
L_80097B54:
    // 0x80097B54: nop

    // 0x80097B58: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x80097B5C: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x80097B60: bne         $at, $zero, L_80097BEC
    if (ctx->r1 != 0) {
        // 0x80097B64: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_80097BEC;
    }
    // 0x80097B64: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80097B68: jal         0x80097C08
    // 0x80097B6C: nop

    results_free(rdram, ctx);
        goto after_11;
    // 0x80097B6C: nop

    after_11:
    // 0x80097B70: jal         0x800C5B80
    // 0x80097B74: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_close(rdram, ctx);
        goto after_12;
    // 0x80097B74: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_12:
    // 0x80097B78: jal         0x800C59F4
    // 0x80097B7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_13;
    // 0x80097B7C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_13:
    // 0x80097B80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80097B84: addiu       $a2, $a2, 0x7028
    ctx->r6 = ADD32(ctx->r6, 0X7028);
    // 0x80097B88: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x80097B8C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80097B90: lw          $v1, -0x5E0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E0);
    // 0x80097B94: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80097B98: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80097B9C: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80097BA0: lw          $v0, 0x71B0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71B0);
    // 0x80097BA4: lw          $t4, 0x5C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X5C);
    // 0x80097BA8: nop

    // 0x80097BAC: bne         $v0, $t4, L_80097BBC
    if (ctx->r2 != ctx->r12) {
        // 0x80097BB0: nop
    
            goto L_80097BBC;
    }
    // 0x80097BB0: nop

    // 0x80097BB4: b           L_80097BF8
    // 0x80097BB8: addiu       $v0, $zero, 0x102
    ctx->r2 = ADD32(0, 0X102);
        goto L_80097BF8;
    // 0x80097BB8: addiu       $v0, $zero, 0x102
    ctx->r2 = ADD32(0, 0X102);
L_80097BBC:
    // 0x80097BBC: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x80097BC0: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80097BC4: bne         $v0, $t6, L_80097BE4
    if (ctx->r2 != ctx->r14) {
        // 0x80097BC8: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_80097BE4;
    }
    // 0x80097BC8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80097BCC: jal         0x8006E528
    // 0x80097BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_14;
    // 0x80097BD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_14:
    // 0x80097BD4: jal         0x80081820
    // 0x80097BD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x80097BD8: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_15:
    // 0x80097BDC: b           L_80097BF8
    // 0x80097BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80097BF8;
    // 0x80097BE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097BE4:
    // 0x80097BE4: b           L_80097BF8
    // 0x80097BE8: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
        goto L_80097BF8;
    // 0x80097BE8: addiu       $v0, $zero, 0x104
    ctx->r2 = ADD32(0, 0X104);
L_80097BEC:
    // 0x80097BEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80097BF0: sw          $zero, 0x6964($at)
    MEM_W(0X6964, ctx->r1) = 0;
    // 0x80097BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80097BF8:
    // 0x80097BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80097BFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80097C00: jr          $ra
    // 0x80097C04: nop

    return;
    // 0x80097C04: nop

;}
RECOMP_FUNC void timetrial_staff_ghost_check(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B3E0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8001B3E4: lw          $t6, -0x3378($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3378);
    // 0x8001B3E8: nop

    // 0x8001B3EC: xor         $v0, $a0, $t6
    ctx->r2 = ctx->r4 ^ ctx->r14;
    // 0x8001B3F0: jr          $ra
    // 0x8001B3F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x8001B3F4: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
