#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void __osSetHWIntrRoutine(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4D50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800D4D54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D4D58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800D4D5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800D4D60: jal         0x800D2AC0
    // 0x800D4D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    __osDisableInt_recomp(rdram, ctx);
        goto after_0;
    // 0x800D4D64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800D4D68: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D4D6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D4D70: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800D4D74: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800D4D78: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800D4D7C: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800D4D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D4D84: jal         0x800D2AE0
    // 0x800D4D88: sw          $t6, 0x4E30($at)
    MEM_W(0X4E30, ctx->r1) = ctx->r14;
    __osRestoreInt_recomp(rdram, ctx);
        goto after_1;
    // 0x800D4D88: sw          $t6, 0x4E30($at)
    MEM_W(0X4E30, ctx->r1) = ctx->r14;
    after_1:
    // 0x800D4D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D4D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D4D94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800D4D98: jr          $ra
    // 0x800D4D9C: nop

    return;
    // 0x800D4D9C: nop

;}
RECOMP_FUNC void transition_render_barndoor_hor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C1904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C1908: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C190C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C1910: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C1914: jal         0x8007B820
    // 0x800C1918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C1918: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C191C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1920: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C1924: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1928: addiu       $t8, $t8, 0x3BD8
    ctx->r24 = ADD32(ctx->r24, 0X3BD8);
    // 0x800C192C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1930: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C1934: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1938: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C193C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1940: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1944: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1948: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C194C: addiu       $a3, $a3, 0x3760
    ctx->r7 = ADD32(ctx->r7, 0X3760);
    // 0x800C1950: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C1954: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1958: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C195C: addiu       $t1, $t1, 0x3750
    ctx->r9 = ADD32(ctx->r9, 0X3750);
    // 0x800C1960: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C1964: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1968: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C196C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1970: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C1974: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1978: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C197C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1980: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C1984: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1988: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C198C: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1990: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C1994: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1998: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C199C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C19A0: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C19A4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C19A8: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C19AC: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C19B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C19B4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C19B8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C19BC: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C19C0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C19C4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C19C8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C19CC: nop

    // 0x800C19D0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C19D4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C19D8: lw          $t6, 0x3758($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3758);
    // 0x800C19DC: nop

    // 0x800C19E0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C19E4: jal         0x8007B820
    // 0x800C19E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C19E8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C19EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C19F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C19F4: jr          $ra
    // 0x800C19F8: nop

    return;
    // 0x800C19F8: nop

;}
RECOMP_FUNC void get_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076B7C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076B80: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80076B84: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80076B88: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076B8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076B90: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80076B94: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80076B98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076B9C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80076BA0: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076BA4: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076BA8: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076BAC: jal         0x800D0AE0
    // 0x80076BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    osPfsFileState_recomp(rdram, ctx);
        goto after_0;
    // 0x80076BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80076BB4: bne         $v0, $zero, L_80076BD4
    if (ctx->r2 != 0) {
        // 0x80076BB8: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_80076BD4;
    }
    // 0x80076BB8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076BBC: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80076BC0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80076BC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80076BC8: b           L_80076BD4
    // 0x80076BCC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_80076BD4;
    // 0x80076BCC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80076BD0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076BD4:
    // 0x80076BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076BD8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80076BDC: jr          $ra
    // 0x80076BE0: nop

    return;
    // 0x80076BE0: nop

;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AD98: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8000AD9C: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADA0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000ADA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000ADA8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000ADAC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x8000ADB0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADB4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8000ADB8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADBC: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x8000ADC0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADC4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8000ADC8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000ADCC: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x8000ADD0: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADD4: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x8000ADD8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000ADDC: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x8000ADE0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADE4: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8000ADE8: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADEC: jr          $ra
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void hud_timer_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8518: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A851C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A8520: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A8524: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A8528: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A852C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8530: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A8534: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A8538: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800A853C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A8540: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800A8544: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800A8548: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A854C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A8550: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A8554: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A8558: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A855C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A8560: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800A8564: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800A8568: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A856C: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A8570: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x800A8574: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x800A8578: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x800A857C: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x800A8580: bne         $t6, $zero, L_800A85AC
    if (ctx->r14 != 0) {
        // 0x800A8584: swc1        $f18, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
            goto L_800A85AC;
    }
    // 0x800A8584: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800A8588: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800A858C: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800A8590: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800A8594: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A8598: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800A859C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A85A0: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x800A85A4: b           L_800A85CC
    // 0x800A85A8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_800A85CC;
    // 0x800A85A8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_800A85AC:
    // 0x800A85AC: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800A85B0: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800A85B4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A85B8: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800A85BC: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x800A85C0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A85C4: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x800A85C8: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800A85CC:
    // 0x800A85CC: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800A85D0: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x800A85D4: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x800A85D8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A85DC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A85E0: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A85E4: addiu       $s2, $s2, 0x72C4
    ctx->r18 = ADD32(ctx->r18, 0X72C4);
    // 0x800A85E8: addiu       $s1, $s1, 0x72C0
    ctx->r17 = ADD32(ctx->r17, 0X72C0);
    // 0x800A85EC: addiu       $s0, $s0, 0x72BC
    ctx->r16 = ADD32(ctx->r16, 0X72BC);
    // 0x800A85F0: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x800A85F4: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A85F8: bne         $s5, $zero, L_800A8604
    if (ctx->r21 != 0) {
        // 0x800A85FC: nop
    
            goto L_800A8604;
    }
    // 0x800A85FC: nop

    // 0x800A8600: break       7
    do_break(2148173312);
L_800A8604:
    // 0x800A8604: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8608: bne         $s5, $at, L_800A861C
    if (ctx->r21 != ctx->r1) {
        // 0x800A860C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A861C;
    }
    // 0x800A860C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8610: bne         $t2, $at, L_800A861C
    if (ctx->r10 != ctx->r1) {
        // 0x800A8614: nop
    
            goto L_800A861C;
    }
    // 0x800A8614: nop

    // 0x800A8618: break       6
    do_break(2148173336);
L_800A861C:
    // 0x800A861C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8620: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8628: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A862C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800A8630: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800A8634: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800A8638: mflo        $t3
    ctx->r11 = lo;
    // 0x800A863C: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x800A8640: jal         0x800AAB5C
    // 0x800A8644: nop

    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A8644: nop

    after_0:
    // 0x800A8648: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800A864C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800A8650: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A8654: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A8658: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A865C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8660: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A8664: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A8668: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A866C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A8670: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800A8674: bne         $s5, $zero, L_800A8680
    if (ctx->r21 != 0) {
        // 0x800A8678: nop
    
            goto L_800A8680;
    }
    // 0x800A8678: nop

    // 0x800A867C: break       7
    do_break(2148173436);
L_800A8680:
    // 0x800A8680: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8684: bne         $s5, $at, L_800A8698
    if (ctx->r21 != ctx->r1) {
        // 0x800A8688: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8698;
    }
    // 0x800A8688: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A868C: bne         $t4, $at, L_800A8698
    if (ctx->r12 != ctx->r1) {
        // 0x800A8690: nop
    
            goto L_800A8698;
    }
    // 0x800A8690: nop

    // 0x800A8694: break       6
    do_break(2148173460);
L_800A8698:
    // 0x800A8698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A869C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A86A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A86A4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A86A8: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A86AC: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A86B0: jal         0x800AAB5C
    // 0x800A86B4: nop

    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A86B4: nop

    after_1:
    // 0x800A86B8: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A86BC: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A86C0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A86C4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A86C8: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A86CC: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A86D0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A86D4: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A86D8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800A86DC: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A86E0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A86E4: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800A86E8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A86EC: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A86F0: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A86F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A86F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A86FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8700: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8704: jal         0x800AAB5C
    // 0x800A8708: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A8708: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    after_2:
    // 0x800A870C: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8710: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800A8714: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x800A8718: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800A871C: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8720: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8724: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8728: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A872C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A8730: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A8734: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800A8738: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A873C: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800A8740: bne         $s5, $zero, L_800A874C
    if (ctx->r21 != 0) {
        // 0x800A8744: nop
    
            goto L_800A874C;
    }
    // 0x800A8744: nop

    // 0x800A8748: break       7
    do_break(2148173640);
L_800A874C:
    // 0x800A874C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8750: bne         $s5, $at, L_800A8764
    if (ctx->r21 != ctx->r1) {
        // 0x800A8754: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8764;
    }
    // 0x800A8754: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8758: bne         $t8, $at, L_800A8764
    if (ctx->r24 != ctx->r1) {
        // 0x800A875C: nop
    
            goto L_800A8764;
    }
    // 0x800A875C: nop

    // 0x800A8760: break       6
    do_break(2148173664);
L_800A8764:
    // 0x800A8764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8768: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A876C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8770: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8774: mflo        $t9
    ctx->r25 = lo;
    // 0x800A8778: sh          $t9, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r25;
    // 0x800A877C: jal         0x800AAB5C
    // 0x800A8780: nop

    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A8780: nop

    after_3:
    // 0x800A8784: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A8788: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A878C: div         $zero, $t1, $s5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r21)));
    // 0x800A8790: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8794: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8798: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A879C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A87A0: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800A87A4: bne         $s5, $zero, L_800A87B0
    if (ctx->r21 != 0) {
        // 0x800A87A8: nop
    
            goto L_800A87B0;
    }
    // 0x800A87A8: nop

    // 0x800A87AC: break       7
    do_break(2148173740);
L_800A87B0:
    // 0x800A87B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A87B4: bne         $s5, $at, L_800A87C8
    if (ctx->r21 != ctx->r1) {
        // 0x800A87B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A87C8;
    }
    // 0x800A87B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A87BC: bne         $t1, $at, L_800A87C8
    if (ctx->r9 != ctx->r1) {
        // 0x800A87C0: nop
    
            goto L_800A87C8;
    }
    // 0x800A87C0: nop

    // 0x800A87C4: break       6
    do_break(2148173764);
L_800A87C8:
    // 0x800A87C8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A87CC: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A87D0: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A87D4: sh          $t2, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r10;
    // 0x800A87D8: jal         0x800AAB5C
    // 0x800A87DC: nop

    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A87DC: nop

    after_4:
    // 0x800A87E0: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A87E4: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A87E8: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A87EC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800A87F0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A87F4: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A87F8: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A87FC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A8800: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A8804: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8808: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A880C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8810: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8814: jal         0x800AAB5C
    // 0x800A8818: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A8818: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    after_5:
    // 0x800A881C: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800A8820: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8824: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A8828: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A882C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8830: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A8834: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A8838: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800A883C: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800A8840: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A8844: bne         $s5, $zero, L_800A8850
    if (ctx->r21 != 0) {
        // 0x800A8848: nop
    
            goto L_800A8850;
    }
    // 0x800A8848: nop

    // 0x800A884C: break       7
    do_break(2148173900);
L_800A8850:
    // 0x800A8850: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8854: bne         $s5, $at, L_800A8868
    if (ctx->r21 != ctx->r1) {
        // 0x800A8858: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8868;
    }
    // 0x800A8858: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A885C: bne         $t4, $at, L_800A8868
    if (ctx->r12 != ctx->r1) {
        // 0x800A8860: nop
    
            goto L_800A8868;
    }
    // 0x800A8860: nop

    // 0x800A8864: break       6
    do_break(2148173924);
L_800A8868:
    // 0x800A8868: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A886C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8870: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8874: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8878: mflo        $t5
    ctx->r13 = lo;
    // 0x800A887C: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A8880: jal         0x800AAB5C
    // 0x800A8884: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A8884: nop

    after_6:
    // 0x800A8888: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800A888C: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8890: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800A8894: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A889C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A88A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A88A4: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A88A8: bne         $s5, $zero, L_800A88B4
    if (ctx->r21 != 0) {
        // 0x800A88AC: nop
    
            goto L_800A88B4;
    }
    // 0x800A88AC: nop

    // 0x800A88B0: break       7
    do_break(2148174000);
L_800A88B4:
    // 0x800A88B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A88B8: bne         $s5, $at, L_800A88CC
    if (ctx->r21 != ctx->r1) {
        // 0x800A88BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A88CC;
    }
    // 0x800A88BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A88C0: bne         $t6, $at, L_800A88CC
    if (ctx->r14 != ctx->r1) {
        // 0x800A88C4: nop
    
            goto L_800A88CC;
    }
    // 0x800A88C4: nop

    // 0x800A88C8: break       6
    do_break(2148174024);
L_800A88CC:
    // 0x800A88CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A88D0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A88D4: mfhi        $t7
    ctx->r15 = hi;
    // 0x800A88D8: sh          $t7, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r15;
    // 0x800A88DC: jal         0x800AAB5C
    // 0x800A88E0: nop

    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A88E0: nop

    after_7:
    // 0x800A88E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A88E8: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A88EC: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A88F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A88F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A88F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A88FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A8900: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800A8904: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x800A8908: jr          $ra
    // 0x800A890C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A890C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void particle_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2218: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B221C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B2220: beq         $a0, $a1, L_800B22FC
    if (ctx->r4 == ctx->r5) {
        // 0x800B2224: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B22FC;
    }
    // 0x800B2224: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B2228: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800B222C: beq         $a0, $a3, L_800B23A4
    if (ctx->r4 == ctx->r7) {
        // 0x800B2230: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B23A4;
    }
    // 0x800B2230: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2234: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800B2238: beq         $a0, $a3, L_800B2448
    if (ctx->r4 == ctx->r7) {
        // 0x800B223C: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B2448;
    }
    // 0x800B223C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2240: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B2244: beq         $a0, $a2, L_800B24EC
    if (ctx->r4 == ctx->r6) {
        // 0x800B2248: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_800B24EC;
    }
    // 0x800B2248: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B224C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800B2250: bne         $a0, $a3, L_800B258C
    if (ctx->r4 != ctx->r7) {
        // 0x800B2254: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B258C;
    }
    // 0x800B2254: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B2258: addiu       $t0, $t0, 0x3250
    ctx->r8 = ADD32(ctx->r8, 0X3250);
    // 0x800B225C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B2260: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B2264: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2268: addiu       $t1, $t1, 0x3248
        ctx->r9 = ADD32(ctx->r9, 0X3248);
            goto L_800B258C;
    }
    // 0x800B2268: addiu       $t1, $t1, 0x3248
    ctx->r9 = ADD32(ctx->r9, 0X3248);
    // 0x800B226C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B2270: lw          $t7, 0x33E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X33E4);
    // 0x800B2274: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B2278: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B227C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B2280: bne         $at, $zero, L_800B22A8
    if (ctx->r1 != 0) {
        // 0x800B2284: nop
    
            goto L_800B22A8;
    }
    // 0x800B2284: nop

    // 0x800B2288: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B228C: addiu       $v0, $v0, 0x324C
    ctx->r2 = ADD32(ctx->r2, 0X324C);
    // 0x800B2290: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B2294: nop

    // 0x800B2298: bne         $t9, $zero, L_800B258C
    if (ctx->r25 != 0) {
        // 0x800B229C: nop
    
            goto L_800B258C;
    }
    // 0x800B229C: nop

    // 0x800B22A0: b           L_800B258C
    // 0x800B22A4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B22A4: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B22A8:
    // 0x800B22A8: lh          $t2, 0x2C($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2C);
    // 0x800B22AC: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800B22B0: beq         $t2, $zero, L_800B22D0
    if (ctx->r10 == 0) {
        // 0x800B22B4: subu        $t3, $t3, $v0
        ctx->r11 = SUB32(ctx->r11, ctx->r2);
            goto L_800B22D0;
    }
    // 0x800B22B4: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800B22B8: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800B22BC: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_800B22C0:
    // 0x800B22C0: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B22C4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B22C8: bne         $t4, $zero, L_800B22C0
    if (ctx->r12 != 0) {
        // 0x800B22CC: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B22C0;
    }
    // 0x800B22CC: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B22D0:
    // 0x800B22D0: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B22D4: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B22D8: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B22DC: addu        $t5, $a0, $a2
    ctx->r13 = ADD32(ctx->r4, ctx->r6);
    // 0x800B22E0: sh          $a3, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = ctx->r7;
    // 0x800B22E4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B22E8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B22EC: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800B22F0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B22F4: b           L_800B258C
    // 0x800B22F8: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
        goto L_800B258C;
    // 0x800B22F8: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
L_800B22FC:
    // 0x800B22FC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B2300: addiu       $a3, $a3, 0x3238
    ctx->r7 = ADD32(ctx->r7, 0X3238);
    // 0x800B2304: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B2308: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B230C: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2310: addiu       $t0, $t0, 0x3230
        ctx->r8 = ADD32(ctx->r8, 0X3230);
            goto L_800B258C;
    }
    // 0x800B2310: addiu       $t0, $t0, 0x3230
    ctx->r8 = ADD32(ctx->r8, 0X3230);
    // 0x800B2314: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B2318: lw          $t2, 0x33DC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X33DC);
    // 0x800B231C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B2320: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B2324: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B2328: bne         $at, $zero, L_800B2350
    if (ctx->r1 != 0) {
        // 0x800B232C: nop
    
            goto L_800B2350;
    }
    // 0x800B232C: nop

    // 0x800B2330: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2334: addiu       $v0, $v0, 0x3234
    ctx->r2 = ADD32(ctx->r2, 0X3234);
    // 0x800B2338: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B233C: nop

    // 0x800B2340: bne         $t4, $zero, L_800B258C
    if (ctx->r12 != 0) {
        // 0x800B2344: nop
    
            goto L_800B258C;
    }
    // 0x800B2344: nop

    // 0x800B2348: b           L_800B258C
    // 0x800B234C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B234C: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B2350:
    // 0x800B2350: lh          $t5, 0x2C($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2354: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B2358: beq         $t5, $zero, L_800B2378
    if (ctx->r13 == 0) {
        // 0x800B235C: subu        $t7, $t7, $v0
        ctx->r15 = SUB32(ctx->r15, ctx->r2);
            goto L_800B2378;
    }
    // 0x800B235C: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800B2360: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B2364: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
L_800B2368:
    // 0x800B2368: lh          $t6, 0x9C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X9C);
    // 0x800B236C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B2370: bne         $t6, $zero, L_800B2368
    if (ctx->r14 != 0) {
        // 0x800B2374: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B2368;
    }
    // 0x800B2374: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B2378:
    // 0x800B2378: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B237C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B2380: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B2384: addu        $t8, $a0, $a2
    ctx->r24 = ADD32(ctx->r4, ctx->r6);
    // 0x800B2388: sh          $a1, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = ctx->r5;
    // 0x800B238C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B2390: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800B2394: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x800B2398: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B239C: b           L_800B258C
    // 0x800B23A0: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
        goto L_800B258C;
    // 0x800B23A0: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
L_800B23A4:
    // 0x800B23A4: addiu       $t0, $t0, 0x3244
    ctx->r8 = ADD32(ctx->r8, 0X3244);
    // 0x800B23A8: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B23AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B23B0: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B23B4: addiu       $t1, $t1, 0x323C
        ctx->r9 = ADD32(ctx->r9, 0X323C);
            goto L_800B258C;
    }
    // 0x800B23B4: addiu       $t1, $t1, 0x323C
    ctx->r9 = ADD32(ctx->r9, 0X323C);
    // 0x800B23B8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B23BC: lw          $t5, 0x33E0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X33E0);
    // 0x800B23C0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800B23C4: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x800B23C8: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B23CC: bne         $at, $zero, L_800B23F4
    if (ctx->r1 != 0) {
        // 0x800B23D0: nop
    
            goto L_800B23F4;
    }
    // 0x800B23D0: nop

    // 0x800B23D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B23D8: addiu       $v0, $v0, 0x3240
    ctx->r2 = ADD32(ctx->r2, 0X3240);
    // 0x800B23DC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B23E0: nop

    // 0x800B23E4: bne         $t6, $zero, L_800B258C
    if (ctx->r14 != 0) {
        // 0x800B23E8: nop
    
            goto L_800B258C;
    }
    // 0x800B23E8: nop

    // 0x800B23EC: b           L_800B258C
    // 0x800B23F0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B23F0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B23F4:
    // 0x800B23F4: lh          $t8, 0x2C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2C);
    // 0x800B23F8: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800B23FC: beq         $t8, $zero, L_800B241C
    if (ctx->r24 == 0) {
        // 0x800B2400: subu        $t2, $t2, $v0
        ctx->r10 = SUB32(ctx->r10, ctx->r2);
            goto L_800B241C;
    }
    // 0x800B2400: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B2404: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800B2408: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B240C:
    // 0x800B240C: lh          $t9, 0x9C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X9C);
    // 0x800B2410: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B2414: bne         $t9, $zero, L_800B240C
    if (ctx->r25 != 0) {
        // 0x800B2418: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B240C;
    }
    // 0x800B2418: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B241C:
    // 0x800B241C: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B2420: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B2424: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B2428: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800B242C: sh          $a3, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r7;
    // 0x800B2430: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800B2434: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B2438: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800B243C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800B2440: b           L_800B258C
    // 0x800B2444: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
        goto L_800B258C;
    // 0x800B2444: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
L_800B2448:
    // 0x800B2448: addiu       $t0, $t0, 0x325C
    ctx->r8 = ADD32(ctx->r8, 0X325C);
    // 0x800B244C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B2450: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B2454: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B2458: addiu       $t1, $t1, 0x3254
        ctx->r9 = ADD32(ctx->r9, 0X3254);
            goto L_800B258C;
    }
    // 0x800B2458: addiu       $t1, $t1, 0x3254
    ctx->r9 = ADD32(ctx->r9, 0X3254);
    // 0x800B245C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B2460: lw          $t8, 0x33E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X33E8);
    // 0x800B2464: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B2468: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x800B246C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B2470: bne         $at, $zero, L_800B2498
    if (ctx->r1 != 0) {
        // 0x800B2474: nop
    
            goto L_800B2498;
    }
    // 0x800B2474: nop

    // 0x800B2478: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B247C: addiu       $v0, $v0, 0x3258
    ctx->r2 = ADD32(ctx->r2, 0X3258);
    // 0x800B2480: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B2484: nop

    // 0x800B2488: bne         $t9, $zero, L_800B258C
    if (ctx->r25 != 0) {
        // 0x800B248C: nop
    
            goto L_800B258C;
    }
    // 0x800B248C: nop

    // 0x800B2490: b           L_800B258C
    // 0x800B2494: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B2494: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B2498:
    // 0x800B2498: lh          $t3, 0x2C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2C);
    // 0x800B249C: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800B24A0: beq         $t3, $zero, L_800B24C0
    if (ctx->r11 == 0) {
        // 0x800B24A4: subu        $t5, $t5, $v0
        ctx->r13 = SUB32(ctx->r13, ctx->r2);
            goto L_800B24C0;
    }
    // 0x800B24A4: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800B24A8: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800B24AC: addu        $v1, $a0, $t5
    ctx->r3 = ADD32(ctx->r4, ctx->r13);
L_800B24B0:
    // 0x800B24B0: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B24B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B24B8: bne         $t4, $zero, L_800B24B0
    if (ctx->r12 != 0) {
        // 0x800B24BC: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B24B0;
    }
    // 0x800B24BC: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B24C0:
    // 0x800B24C0: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B24C4: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B24C8: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B24CC: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x800B24D0: sh          $a3, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r7;
    // 0x800B24D4: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B24D8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B24DC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B24E0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B24E4: b           L_800B258C
    // 0x800B24E8: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
        goto L_800B258C;
    // 0x800B24E8: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
L_800B24EC:
    // 0x800B24EC: addiu       $a3, $a3, 0x3268
    ctx->r7 = ADD32(ctx->r7, 0X3268);
    // 0x800B24F0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B24F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B24F8: beq         $a0, $zero, L_800B258C
    if (ctx->r4 == 0) {
        // 0x800B24FC: addiu       $t0, $t0, 0x3260
        ctx->r8 = ADD32(ctx->r8, 0X3260);
            goto L_800B258C;
    }
    // 0x800B24FC: addiu       $t0, $t0, 0x3260
    ctx->r8 = ADD32(ctx->r8, 0X3260);
    // 0x800B2500: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B2504: lw          $t3, 0x33EC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X33EC);
    // 0x800B2508: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B250C: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800B2510: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B2514: bne         $at, $zero, L_800B253C
    if (ctx->r1 != 0) {
        // 0x800B2518: nop
    
            goto L_800B253C;
    }
    // 0x800B2518: nop

    // 0x800B251C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2520: addiu       $v0, $v0, 0x3264
    ctx->r2 = ADD32(ctx->r2, 0X3264);
    // 0x800B2524: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B2528: nop

    // 0x800B252C: bne         $t4, $zero, L_800B258C
    if (ctx->r12 != 0) {
        // 0x800B2530: nop
    
            goto L_800B258C;
    }
    // 0x800B2530: nop

    // 0x800B2534: b           L_800B258C
    // 0x800B2538: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B258C;
    // 0x800B2538: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B253C:
    // 0x800B253C: lh          $t7, 0x2C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2C);
    // 0x800B2540: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800B2544: beq         $t7, $zero, L_800B2564
    if (ctx->r15 == 0) {
        // 0x800B2548: subu        $t8, $t8, $v0
        ctx->r24 = SUB32(ctx->r24, ctx->r2);
            goto L_800B2564;
    }
    // 0x800B2548: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800B254C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B2550: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
L_800B2554:
    // 0x800B2554: lh          $t6, 0xA4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA4);
    // 0x800B2558: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B255C: bne         $t6, $zero, L_800B2554
    if (ctx->r14 != 0) {
        // 0x800B2560: addiu       $v1, $v1, 0x78
        ctx->r3 = ADD32(ctx->r3, 0X78);
            goto L_800B2554;
    }
    // 0x800B2560: addiu       $v1, $v1, 0x78
    ctx->r3 = ADD32(ctx->r3, 0X78);
L_800B2564:
    // 0x800B2564: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x800B2568: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B256C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800B2570: addu        $t2, $a0, $a1
    ctx->r10 = ADD32(ctx->r4, ctx->r5);
    // 0x800B2574: sh          $a2, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r6;
    // 0x800B2578: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800B257C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800B2580: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800B2584: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B2588: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_800B258C:
    // 0x800B258C: beq         $v1, $zero, L_800B2598
    if (ctx->r3 == 0) {
        // 0x800B2590: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B2598;
    }
    // 0x800B2590: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B2594: sh          $t4, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r12;
L_800B2598:
    // 0x800B2598: jr          $ra
    // 0x800B259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B259C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void sndp_get_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80004A40: lw          $t7, -0x5E58($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5E58);
    // 0x80004A44: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80004A48: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80004A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80004A50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80004A54: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x80004A58: jr          $ra
    // 0x80004A5C: nop

    return;
    // 0x80004A5C: nop

;}
RECOMP_FUNC void stop_all_threads_except_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7680: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B7684: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B7688: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B768C: jal         0x800D29D0
    // 0x800B7690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B7690: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B7694: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B7698: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800B769C: beq         $s1, $t6, L_800B76D8
    if (ctx->r17 == ctx->r14) {
        // 0x800B76A0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B76D8;
    }
    // 0x800B76A0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B76A4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800B76A8:
    // 0x800B76A8: blez        $v0, L_800B76C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B76AC: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B76C0;
    }
    // 0x800B76AC: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B76B0: beq         $at, $zero, L_800B76C0
    if (ctx->r1 == 0) {
        // 0x800B76B4: nop
    
            goto L_800B76C0;
    }
    // 0x800B76B4: nop

    // 0x800B76B8: jal         0x800C9050
    // 0x800B76BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B76BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800B76C0:
    // 0x800B76C0: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    // 0x800B76C4: nop

    // 0x800B76C8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800B76CC: nop

    // 0x800B76D0: bne         $s1, $v0, L_800B76A8
    if (ctx->r17 != ctx->r2) {
        // 0x800B76D4: nop
    
            goto L_800B76A8;
    }
    // 0x800B76D4: nop

L_800B76D8:
    // 0x800B76D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B76DC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B76E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B76E4: jr          $ra
    // 0x800B76E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B76E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void waves_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B83D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B83D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B83DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B83E0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B83E4: jal         0x800B8240
    // 0x800B83E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    waves_free(rdram, ctx);
        goto after_0;
    // 0x800B83E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B83EC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B83F0: addiu       $s2, $s2, -0x5A78
    ctx->r18 = ADD32(ctx->r18, -0X5A78);
    // 0x800B83F4: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x800B83F8: lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // 0x800B83FC: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x800B8400: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B8404: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B8408: jal         0x80070EDC
    // 0x800B840C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800B840C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800B8410: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8414: sw          $v0, 0x35D0($at)
    MEM_W(0X35D0, ctx->r1) = ctx->r2;
    // 0x800B8418: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B841C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B8420: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800B8424: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8428: mflo        $a0
    ctx->r4 = lo;
    // 0x800B842C: jal         0x80070EDC
    // 0x800B8430: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800B8430: nop

    after_2:
    // 0x800B8434: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8438: sw          $v0, 0x35D4($at)
    MEM_W(0X35D4, ctx->r1) = ctx->r2;
    // 0x800B843C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8440: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B8444: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8448: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800B844C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8450: mflo        $a0
    ctx->r4 = lo;
    // 0x800B8454: jal         0x80070EDC
    // 0x800B8458: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800B8458: nop

    after_3:
    // 0x800B845C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B8460: sw          $v0, 0x35D8($at)
    MEM_W(0X35D8, ctx->r1) = ctx->r2;
    // 0x800B8464: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8468: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B846C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8470: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800B8474: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8478: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B847C: mflo        $s0
    ctx->r16 = lo;
    // 0x800B8480: nop

    // 0x800B8484: nop

    // 0x800B8488: multu       $s0, $ra
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B848C: mflo        $a0
    ctx->r4 = lo;
    // 0x800B8490: jal         0x80070EDC
    // 0x800B8494: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800B8494: nop

    after_4:
    // 0x800B8498: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B849C: addiu       $a0, $a0, 0x35DC
    ctx->r4 = ADD32(ctx->r4, 0X35DC);
    // 0x800B84A0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B84A4: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800B84A8: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B84AC: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B84B0: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x800B84B4: addiu       $v1, $v1, 0x35E0
    ctx->r3 = ADD32(ctx->r3, 0X35E0);
    // 0x800B84B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B84BC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B84C0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800B84C4: sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16 << 1);
    // 0x800B84C8: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800B84CC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800B84D0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800B84D4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
L_800B84D8:
    // 0x800B84D8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B84DC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B84E0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800B84E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B84E8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B84EC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800B84F0: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B84F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B84F8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B84FC: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x800B8500: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800B8504: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8508: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B850C: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800B8510: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x800B8514: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800B8518: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x800B851C: bne         $a1, $ra, L_800B84D8
    if (ctx->r5 != ctx->r31) {
        // 0x800B8520: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B84D8;
    }
    // 0x800B8520: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B8524: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8528: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B852C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8530: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x800B8534: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B8538: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B853C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8540: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B8544: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8548: lw          $t7, -0x59C8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X59C8);
    // 0x800B854C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8550: mflo        $s0
    ctx->r16 = lo;
    // 0x800B8554: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B8558: beq         $t7, $at, L_800B8580
    if (ctx->r15 == ctx->r1) {
        // 0x800B855C: nop
    
            goto L_800B8580;
    }
    // 0x800B855C: nop

    // 0x800B8560: jal         0x80070EDC
    // 0x800B8564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800B8564: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800B8568: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B856C: addiu       $v1, $v1, 0x3600
    ctx->r3 = ADD32(ctx->r3, 0X3600);
    // 0x800B8570: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8574: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8578: b           L_800B85B0
    // 0x800B857C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_800B85B0;
    // 0x800B857C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800B8580:
    // 0x800B8580: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B8584: jal         0x80070EDC
    // 0x800B8588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800B8588: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800B858C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8590: addiu       $v1, $v1, 0x3600
    ctx->r3 = ADD32(ctx->r3, 0X3600);
    // 0x800B8594: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8598: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B859C: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B85A0: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B85A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B85A8: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B85AC: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
L_800B85B0:
    // 0x800B85B0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B85B4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B85B8: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x800B85BC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B85C0: lw          $t9, -0x59C8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X59C8);
    // 0x800B85C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B85C8: mflo        $s0
    ctx->r16 = lo;
    // 0x800B85CC: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B85D0: beq         $t9, $at, L_800B85F8
    if (ctx->r25 == ctx->r1) {
        // 0x800B85D4: nop
    
            goto L_800B85F8;
    }
    // 0x800B85D4: nop

    // 0x800B85D8: jal         0x80070EDC
    // 0x800B85DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800B85DC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800B85E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B85E4: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B85E8: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B85EC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B85F0: b           L_800B8628
    // 0x800B85F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_800B8628;
    // 0x800B85F4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800B85F8:
    // 0x800B85F8: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B85FC: jal         0x80070EDC
    // 0x800B8600: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800B8600: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B8604: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8608: addiu       $v1, $v1, 0x3610
    ctx->r3 = ADD32(ctx->r3, 0X3610);
    // 0x800B860C: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8610: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B8614: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B8618: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B861C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8620: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8624: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_800B8628:
    // 0x800B8628: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x800B862C: jal         0x8007B2C4
    // 0x800B8630: nop

    load_texture(rdram, ctx);
        goto after_9;
    // 0x800B8630: nop

    after_9:
    // 0x800B8634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B8638: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B863C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8640: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8644: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B8648: sw          $v0, 0x3660($at)
    MEM_W(0X3660, ctx->r1) = ctx->r2;
    // 0x800B864C: jr          $ra
    // 0x800B8650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B8650: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void move_particle_basic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3A10: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B3A14: addiu       $a1, $a1, -0x7DC0
    ctx->r5 = ADD32(ctx->r5, -0X7DC0);
    // 0x800B3A18: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B3A1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B3A20: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B3A24: beq         $t6, $zero, L_800B3ABC
    if (ctx->r14 == 0) {
        // 0x800B3A28: nop
    
            goto L_800B3ABC;
    }
    // 0x800B3A28: nop

L_800B3A2C:
    // 0x800B3A2C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B3A30: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B3A34: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B3A38: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B3A3C: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B3A40: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3A44: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B3A48: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B3A4C: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800B3A50: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B3A54: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800B3A58: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B3A5C: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3A60: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B3A64: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800B3A68: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B3A6C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x800B3A70: lh          $t1, 0x64($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X64);
    // 0x800B3A74: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x800B3A78: lh          $t4, 0x66($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X66);
    // 0x800B3A7C: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B3A80: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3A84: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3A88: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3A8C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3A90: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3A94: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3A98: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B3A9C: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800B3AA0: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x800B3AA4: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B3AA8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B3AAC: nop

    // 0x800B3AB0: slt         $v0, $v1, $t6
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3AB4: bne         $v0, $zero, L_800B3A2C
    if (ctx->r2 != 0) {
        // 0x800B3AB8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B3A2C;
    }
    // 0x800B3AB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800B3ABC:
    // 0x800B3ABC: jr          $ra
    // 0x800B3AC0: nop

    return;
    // 0x800B3AC0: nop

;}
RECOMP_FUNC void racer_sound_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800063F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800063F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800063F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800063FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80006400: jal         0x8001139C
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80006408: bne         $v0, $zero, L_80006448
    if (ctx->r2 != 0) {
        // 0x8000640C: nop
    
            goto L_80006448;
    }
    // 0x8000640C: nop

    // 0x80006410: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80006414: nop

    // 0x80006418: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000641C: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80006420: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006424: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80006428: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000642C: nop

    // 0x80006430: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006434: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006438: jal         0x800CA030
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006440: b           L_80006450
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_80006450;
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_80006448:
    // 0x80006448: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000644C: nop

L_80006450:
    // 0x80006450: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006458: nop

    // 0x8000645C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80006460: nop

    // 0x80006464: bc1f        L_800064B8
    if (!c1cs) {
        // 0x80006468: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800064B8;
    }
    // 0x80006468: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000646C: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006470: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006474: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006478: lbu         $t6, 0x37($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X37);
    // 0x8000647C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006480: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80006484: bgez        $t6, L_80006498
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80006488: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80006498;
    }
    // 0x80006488: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000648C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006490: nop

    // 0x80006494: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80006498:
    // 0x80006498: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8000649C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800064A0: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800064A4: nop

    // 0x800064A8: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064AC: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800064B0: b           L_800066FC
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
        goto L_800066FC;
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
L_800064B8:
    // 0x800064B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800064BC: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x800064C0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800064C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800064C8: lwc1        $f6, 0x5208($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5208);
    // 0x800064CC: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800064D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800064D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800064DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800064E0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800064E4: nop

    // 0x800064E8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800064EC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800064F0: nop

    // 0x800064F4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800064F8: beq         $a1, $zero, L_80006544
    if (ctx->r5 == 0) {
        // 0x800064FC: nop
    
            goto L_80006544;
    }
    // 0x800064FC: nop

    // 0x80006500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006508: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000650C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006510: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80006514: nop

    // 0x80006518: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000651C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80006520: nop

    // 0x80006524: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80006528: bne         $a1, $zero, L_8000653C
    if (ctx->r5 != 0) {
        // 0x8000652C: nop
    
            goto L_8000653C;
    }
    // 0x8000652C: nop

    // 0x80006530: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006534: b           L_80006554
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80006554;
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_8000653C:
    // 0x8000653C: b           L_80006554
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80006554;
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80006544:
    // 0x80006544: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006548: nop

    // 0x8000654C: bltz        $a1, L_8000653C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006550: nop
    
            goto L_8000653C;
    }
    // 0x80006550: nop

L_80006554:
    // 0x80006554: lhu         $t9, 0x18($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X18);
    // 0x80006558: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x8000655C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80006560: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80006564: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x80006568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006598;
    }
    // 0x80006568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000656C:
    // 0x8000656C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006570: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80006574: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80006578: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8000657C: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x80006580: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80006584: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80006588: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x8000658C: slti        $at, $t2, 0x4
        ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
            goto L_80006598;
    }
    // 0x8000658C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80006590: bne         $at, $zero, L_8000656C
    if (ctx->r1 != 0) {
        // 0x80006594: nop
    
            goto L_8000656C;
    }
    // 0x80006594: nop

L_80006598:
    // 0x80006598: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000659C: bne         $v0, $at, L_800065B4
    if (ctx->r2 != ctx->r1) {
        // 0x800065A0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800065B4;
    }
    // 0x800065A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800065A4: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800065A8: lbu         $t0, 0x2C($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2C);
    // 0x800065AC: b           L_800066C4
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
        goto L_800066C4;
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800065B4:
    // 0x800065B4: beq         $a1, $zero, L_800065C8
    if (ctx->r5 == 0) {
        // 0x800065B8: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_800065C8;
    }
    // 0x800065B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800065BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800065C0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x800065C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800065C8:
    // 0x800065C8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800065CC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800065D0: sll         $t3, $a1, 1
    ctx->r11 = S32(ctx->r5 << 1);
    // 0x800065D4: lhu         $a2, 0x18($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X18);
    // 0x800065D8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800065DC: lhu         $t5, 0x1A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1A);
    // 0x800065E0: subu        $t2, $a0, $a2
    ctx->r10 = SUB32(ctx->r4, ctx->r6);
    // 0x800065E4: subu        $t6, $t5, $a2
    ctx->r14 = SUB32(ctx->r13, ctx->r6);
    // 0x800065E8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800065EC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800065F0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800065F4: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x800065F8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800065FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006600: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80006604: lbu         $t9, 0x2D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2D);
    // 0x80006608: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000660C: subu        $t2, $t9, $a3
    ctx->r10 = SUB32(ctx->r25, ctx->r7);
    // 0x80006610: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80006614: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80006618: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000661C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80006620: bgez        $a3, L_80006634
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80006624: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80006634;
    }
    // 0x80006624: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000662C: nop

    // 0x80006630: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80006634:
    // 0x80006634: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000663C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80006640: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006644: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006648: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000664C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006650: nop

    // 0x80006654: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006658: beq         $t0, $zero, L_800066A4
    if (ctx->r8 == 0) {
        // 0x8000665C: nop
    
            goto L_800066A4;
    }
    // 0x8000665C: nop

    // 0x80006660: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006664: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006668: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000666C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006670: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006674: nop

    // 0x80006678: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000667C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006680: nop

    // 0x80006684: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006688: bne         $t0, $zero, L_8000669C
    if (ctx->r8 != 0) {
        // 0x8000668C: nop
    
            goto L_8000669C;
    }
    // 0x8000668C: nop

    // 0x80006690: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006694: b           L_800066B4
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800066B4;
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8000669C:
    // 0x8000669C: b           L_800066B4
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800066B4;
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800066A4:
    // 0x800066A4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800066A8: nop

    // 0x800066AC: bltz        $t0, L_8000669C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800066B0: nop
    
            goto L_8000669C;
    }
    // 0x800066B0: nop

L_800066B4:
    // 0x800066B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800066B8: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x800066BC: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x800066C0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800066C4:
    // 0x800066C4: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800066C8: bgez        $t0, L_800066E0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800066CC: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800066E0;
    }
    // 0x800066CC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800066D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800066D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800066D8: nop

    // 0x800066DC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800066E0:
    // 0x800066E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800066E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800066E8: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800066EC: nop

    // 0x800066F0: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800066F4: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800066F8: swc1        $f4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f4.u32l;
L_800066FC:
    // 0x800066FC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006700: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80006704: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80006708: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000670C: beq         $t6, $zero, L_80006778
    if (ctx->r14 == 0) {
        // 0x80006710: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80006778;
    }
    // 0x80006710: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006714: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80006718: lwc1        $f10, 0xB0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x8000671C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80006720: nop

    // 0x80006724: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006728: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000672C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006730: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006734: swc1        $f10, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f10.u32l;
    // 0x80006738: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000673C: nop

    // 0x80006740: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80006744: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80006748: nop

    // 0x8000674C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006750: nop

    // 0x80006754: bc1f        L_800067A8
    if (!c1cs) {
        // 0x80006758: nop
    
            goto L_800067A8;
    }
    // 0x80006758: nop

    // 0x8000675C: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80006760: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006764: nop

    // 0x80006768: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000676C: b           L_800067AC
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_800067AC;
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80006774: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80006778:
    // 0x80006778: lwc1        $f8, 0xB4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8000677C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80006780: nop

    // 0x80006784: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006788: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000678C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80006790: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80006794: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80006798: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000679C: nop

    // 0x800067A0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800067A4: nop

L_800067A8:
    // 0x800067A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800067AC:
    // 0x800067AC: nop

    // 0x800067B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800067B4: nop

    // 0x800067B8: bc1f        L_800067C4
    if (!c1cs) {
        // 0x800067BC: nop
    
            goto L_800067C4;
    }
    // 0x800067BC: nop

    // 0x800067C0: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_800067C4:
    // 0x800067C4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800067C8: jal         0x800A06D0
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_2;
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800067D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800067D4: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800067D8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800067DC: bne         $v0, $zero, L_800067F4
    if (ctx->r2 != 0) {
        // 0x800067E0: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_800067F4;
    }
    // 0x800067E0: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x800067E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800067E8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800067EC: nop

    // 0x800067F0: swc1        $f4, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f4.u32l;
L_800067F4:
    // 0x800067F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800067F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800067FC: lwc1        $f6, 0xA4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XA4);
    // 0x80006800: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    // 0x80006804: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80006808: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8000680C: jal         0x80070A04
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80006814: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80006818: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8000681C: lh          $a0, 0x4($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X4);
    // 0x80006820: jal         0x80070A04
    // 0x80006824: nop

    sins_f(rdram, ctx);
        goto after_4;
    // 0x80006824: nop

    after_4:
    // 0x80006828: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000682C: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006830: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006834: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80006838: lwc1        $f10, 0xC4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8000683C: lwc1        $f4, 0xC0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x80006840: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006844: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006848: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000684C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80006850: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80006854: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80006858: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000685C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80006860: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80006864: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80006868: bc1f        L_80006874
    if (!c1cs) {
        // 0x8000686C: cvt.d.s     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
            goto L_80006874;
    }
    // 0x8000686C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80006870: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80006874:
    // 0x80006874: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80006878: add.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8000687C: bc1f        L_80006890
    if (!c1cs) {
        // 0x80006880: add.s       $f14, $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
            goto L_80006890;
    }
    // 0x80006880: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80006884: sub.d       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f0.d - ctx->f16.d;
    // 0x80006888: b           L_80006898
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80006898;
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80006890:
    // 0x80006890: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80006894: nop

L_80006898:
    // 0x80006898: lwc1        $f4, 0xCC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x8000689C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800068A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800068A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800068A8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800068AC: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x800068B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068B4: bc1t        L_80006980
    if (c1cs) {
        // 0x800068B8: add.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_80006980;
    }
    // 0x800068B8: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800068BC: lw          $t5, -0x5E44($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5E44);
    // 0x800068C0: nop

    // 0x800068C4: lb          $v0, 0x185($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X185);
    // 0x800068C8: nop

    // 0x800068CC: beq         $v0, $zero, L_80006980
    if (ctx->r2 == 0) {
        // 0x800068D0: nop
    
            goto L_80006980;
    }
    // 0x800068D0: nop

    // 0x800068D4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800068D8: beq         $at, $zero, L_800068E8
    if (ctx->r1 == 0) {
        // 0x800068DC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800068E8;
    }
    // 0x800068DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800068E0: b           L_800068E8
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800068E8;
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800068E8:
    // 0x800068E8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800068EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068F0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800068F4: lwc1        $f5, 0x5210($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5210);
    // 0x800068F8: lwc1        $f4, 0x5214($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5214);
    // 0x800068FC: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006900: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80006904: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006908: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x8000690C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006910: nop

    // 0x80006914: bc1f        L_80006950
    if (!c1cs) {
        // 0x80006918: nop
    
            goto L_80006950;
    }
    // 0x80006918: nop

    // 0x8000691C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80006920: nop

    // 0x80006924: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006928: nop

    // 0x8000692C: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006930: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x80006934: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006938: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8000693C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006940: nop

    // 0x80006944: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006948: b           L_800069B0
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006950:
    // 0x80006950: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80006954: nop

    // 0x80006958: bc1f        L_80006978
    if (!c1cs) {
        // 0x8000695C: nop
    
            goto L_80006978;
    }
    // 0x8000695C: nop

    // 0x80006960: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80006964: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006968: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000696C: nop

    // 0x80006970: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006974: nop

L_80006978:
    // 0x80006978: b           L_800069B0
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006980:
    // 0x80006980: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006984: lwc1        $f9, 0x5218($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5218);
    // 0x80006988: lwc1        $f8, 0x521C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X521C);
    // 0x8000698C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006990: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006994: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80006998: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x8000699C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069A0: nop

    // 0x800069A4: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800069A8: nop

    // 0x800069AC: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800069B0:
    // 0x800069B0: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800069B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800069BC: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800069C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069C4: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800069C8: add.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800069CC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x800069D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069D4: lwc1        $f8, 0x5224($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5224);
    // 0x800069D8: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069DC: lwc1        $f9, 0x5220($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5220);
    // 0x800069E0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800069E4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x800069E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069EC: bc1f        L_80006A08
    if (!c1cs) {
        // 0x800069F0: nop
    
            goto L_80006A08;
    }
    // 0x800069F0: nop

    // 0x800069F4: lwc1        $f10, 0x5228($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5228);
    // 0x800069F8: nop

    // 0x800069FC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x80006A00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A04: nop

L_80006A08:
    // 0x80006A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006A0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006A10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80006A14: swc1        $f6, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f6.u32l;
    // 0x80006A18: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80006A1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006A20: swc1        $f8, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f8.u32l;
    // 0x80006A24: lw          $v0, -0x5E44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5E44);
    // 0x80006A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80006A2C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80006A30: nop

    // 0x80006A34: beq         $t8, $at, L_80006A7C
    if (ctx->r24 == ctx->r1) {
        // 0x80006A38: nop
    
            goto L_80006A7C;
    }
    // 0x80006A38: nop

    // 0x80006A3C: lb          $t9, 0x1DB($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A40: nop

    // 0x80006A44: beq         $t9, $zero, L_80006A7C
    if (ctx->r25 == 0) {
        // 0x80006A48: nop
    
            goto L_80006A7C;
    }
    // 0x80006A48: nop

    // 0x80006A4C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80006A54: lbu         $t2, 0xD8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XD8);
    // 0x80006A58: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    // 0x80006A5C: bne         $t2, $zero, L_80006A7C
    if (ctx->r10 != 0) {
        // 0x80006A60: nop
    
            goto L_80006A7C;
    }
    // 0x80006A60: nop

    // 0x80006A64: sb          $t3, 0xD8($v1)
    MEM_B(0XD8, ctx->r3) = ctx->r11;
    // 0x80006A68: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80006A6C: jal         0x80001D04
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    after_5:
    // 0x80006A74: b           L_80006ABC
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006ABC;
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A7C:
    // 0x80006A7C: lb          $t4, 0x1DB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A80: nop

    // 0x80006A84: bne         $t4, $zero, L_80006ABC
    if (ctx->r12 != 0) {
        // 0x80006A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006A8C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80006A90: nop

    // 0x80006A94: sb          $zero, 0xD8($t5)
    MEM_B(0XD8, ctx->r13) = 0;
    // 0x80006A98: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80006A9C: nop

    // 0x80006AA0: lw          $a0, 0xDC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XDC);
    // 0x80006AA4: nop

    // 0x80006AA8: beq         $a0, $zero, L_80006ABC
    if (ctx->r4 == 0) {
        // 0x80006AAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006AB0: jal         0x8000488C
    // 0x80006AB4: nop

    sndp_stop(rdram, ctx);
        goto after_6;
    // 0x80006AB4: nop

    after_6:
    // 0x80006AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006ABC:
    // 0x80006ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006AC0: jr          $ra
    // 0x80006AC4: nop

    return;
    // 0x80006AC4: nop

;}
RECOMP_FUNC void free_model_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060298: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006029C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800602A0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800602A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800602A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800602AC: lh          $v0, 0x22($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X22);
    // 0x800602B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800602B4: blez        $v0, L_800602FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800602B8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800602FC;
    }
    // 0x800602B8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800602BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800602C0:
    // 0x800602C0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800602C4: nop

    // 0x800602C8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800602CC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800602D0: nop

    // 0x800602D4: beq         $a0, $zero, L_800602EC
    if (ctx->r4 == 0) {
        // 0x800602D8: nop
    
            goto L_800602EC;
    }
    // 0x800602D8: nop

    // 0x800602DC: jal         0x8007B70C
    // 0x800602E0: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800602E0: nop

    after_0:
    // 0x800602E4: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x800602E8: nop

L_800602EC:
    // 0x800602EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800602F0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800602F4: bne         $at, $zero, L_800602C0
    if (ctx->r1 != 0) {
        // 0x800602F8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_800602C0;
    }
    // 0x800602F8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800602FC:
    // 0x800602FC: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x80060300: nop

    // 0x80060304: beq         $a0, $zero, L_80060314
    if (ctx->r4 == 0) {
        // 0x80060308: nop
    
            goto L_80060314;
    }
    // 0x80060308: nop

    // 0x8006030C: jal         0x80071380
    // 0x80060310: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80060310: nop

    after_1:
L_80060314:
    // 0x80060314: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x80060318: nop

    // 0x8006031C: beq         $a0, $zero, L_8006032C
    if (ctx->r4 == 0) {
        // 0x80060320: nop
    
            goto L_8006032C;
    }
    // 0x80060320: nop

    // 0x80060324: jal         0x80071380
    // 0x80060328: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x80060328: nop

    after_2:
L_8006032C:
    // 0x8006032C: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    // 0x80060330: nop

    // 0x80060334: beq         $a0, $zero, L_80060344
    if (ctx->r4 == 0) {
        // 0x80060338: nop
    
            goto L_80060344;
    }
    // 0x80060338: nop

    // 0x8006033C: jal         0x80071380
    // 0x80060340: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80060340: nop

    after_3:
L_80060344:
    // 0x80060344: lw          $t8, 0x44($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X44);
    // 0x80060348: nop

    // 0x8006034C: beq         $t8, $zero, L_8006039C
    if (ctx->r24 == 0) {
        // 0x80060350: nop
    
            goto L_8006039C;
    }
    // 0x80060350: nop

    // 0x80060354: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80060358: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006035C: beq         $t9, $zero, L_8006039C
    if (ctx->r25 == 0) {
        // 0x80060360: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006039C;
    }
    // 0x80060360: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060364:
    // 0x80060364: lw          $t0, 0x44($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X44);
    // 0x80060368: nop

    // 0x8006036C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80060370: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80060374: jal         0x80071380
    // 0x80060378: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80060378: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    after_4:
    // 0x8006037C: lh          $t2, 0x48($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X48);
    // 0x80060380: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80060384: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80060388: bne         $at, $zero, L_80060364
    if (ctx->r1 != 0) {
        // 0x8006038C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80060364;
    }
    // 0x8006038C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80060390: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80060394: jal         0x80071380
    // 0x80060398: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80060398: nop

    after_5:
L_8006039C:
    // 0x8006039C: jal         0x80071380
    // 0x800603A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800603A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x800603A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800603A8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800603AC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800603B0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800603B4: jr          $ra
    // 0x800603B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800603B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_channel_volume_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001C60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001C64: sll         $s1, $a0, 8
    ctx->r17 = S32(ctx->r4 << 8);
    // 0x80001C68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001C6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001C70: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80001C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001C78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001C7C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80001C80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001C84: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    // 0x80001C88: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80001C8C:
    // 0x80001C8C: jal         0x80004A60
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x80001C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001C98: bne         $s0, $s2, L_80001C8C
    if (ctx->r16 != ctx->r18) {
        // 0x80001C9C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80001C8C;
    }
    // 0x80001C9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80001CA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001CAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001CB0: jr          $ra
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void minimap_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB6F0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB6F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB6F8: sb          $t6, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = ctx->r14;
    // 0x800AB6FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB700: jr          $ra
    // 0x800AB704: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
    return;
    // 0x800AB704: sb          $a0, 0x7293($at)
    MEM_B(0X7293, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037720: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80037724: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037728: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8003772C: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x80037730: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80037734: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80037738: jal         0x8002C804
    // 0x8003773C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x8003773C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80037740: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037744: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80037748: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003774C: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x80037750: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80037754: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80037758: lb          $t7, 0x9($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X9);
    // 0x8003775C: nop

    // 0x80037760: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80037764: lb          $t8, 0xA($a1)
    ctx->r24 = MEM_B(ctx->r5, 0XA);
    // 0x80037768: nop

    // 0x8003776C: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x80037770: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x80037774: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80037778: lwc1        $f12, 0xC($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003777C: jal         0x80029F58
    // 0x80037780: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_1;
    // 0x80037780: nop

    after_1:
    // 0x80037784: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80037788: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8003778C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80037790: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80037794: nop

    // 0x80037798: bne         $t9, $zero, L_800377A8
    if (ctx->r25 != 0) {
        // 0x8003779C: nop
    
            goto L_800377A8;
    }
    // 0x8003779C: nop

    // 0x800377A0: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x800377A4: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_800377A8:
    // 0x800377A8: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800377AC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800377B0: beq         $v0, $at, L_8003780C
    if (ctx->r2 == ctx->r1) {
        // 0x800377B4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8003780C;
    }
    // 0x800377B4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800377B8: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800377BC: nop

    // 0x800377C0: bgez        $a0, L_800377DC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800377C4: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_800377DC;
    }
    // 0x800377C4: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800377C8: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x800377CC: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x800377D0: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x800377D4: nop

    // 0x800377D8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_800377DC:
    // 0x800377DC: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800377E0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800377E4: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800377E8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800377EC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800377F0: lh          $a1, 0x20($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X20);
    // 0x800377F4: nop

    // 0x800377F8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800377FC: bne         $at, $zero, L_80037808
    if (ctx->r1 != 0) {
        // 0x80037800: addiu       $t4, $a1, -0x1
        ctx->r12 = ADD32(ctx->r5, -0X1);
            goto L_80037808;
    }
    // 0x80037800: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x80037804: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_80037808:
    // 0x80037808: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_8003780C:
    // 0x8003780C: jal         0x80037824
    // 0x80037810: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    obj_loop_animator(rdram, ctx);
        goto after_2;
    // 0x80037810: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_2:
    // 0x80037814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80037818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003781C: jr          $ra
    // 0x80037820: nop

    return;
    // 0x80037820: nop

;}
RECOMP_FUNC void sndp_get_state_counts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800042D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800042D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800042D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800042DC: jal         0x800C9F90
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800042E4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800042E8: addiu       $a3, $a3, -0x33E0
    ctx->r7 = ADD32(ctx->r7, -0X33E0);
    // 0x800042EC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800042F0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800042F4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x800042F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800042FC: beq         $v1, $zero, L_80004318
    if (ctx->r3 == 0) {
        // 0x80004300: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80004318;
    }
    // 0x80004300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80004304:
    // 0x80004304: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80004308: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000430C: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x80004310: bne         $v1, $zero, L_80004304
    if (ctx->r3 != 0) {
        // 0x80004314: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80004304;
    }
    // 0x80004314: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_80004318:
    // 0x80004318: beq         $a0, $zero, L_80004334
    if (ctx->r4 == 0) {
        // 0x8000431C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004334;
    }
    // 0x8000431C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004320:
    // 0x80004320: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80004324: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004328: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8000432C: bne         $a0, $zero, L_80004320
    if (ctx->r4 != 0) {
        // 0x80004330: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80004320;
    }
    // 0x80004330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80004334:
    // 0x80004334: beq         $a1, $zero, L_80004350
    if (ctx->r5 == 0) {
        // 0x80004338: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80004350;
    }
    // 0x80004338: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000433C:
    // 0x8000433C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x80004340: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004344: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80004348: bne         $a1, $zero, L_8000433C
    if (ctx->r5 != 0) {
        // 0x8000434C: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000433C;
    }
    // 0x8000434C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80004350:
    // 0x80004350: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80004354: nop

    // 0x80004358: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x8000435C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80004360: nop

    // 0x80004364: sh          $a2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r6;
    // 0x80004368: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000436C: jal         0x800C9F90
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    after_1:
    // 0x80004374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004378: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8000437C: jr          $ra
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void timetrial_ghost_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059C44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059C48: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059C4C: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80059C50: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80059C54: lh          $a0, 0x164($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X164);
    // 0x80059C58: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80059C5C: jal         0x80070A38
    // 0x80059C60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80059C60: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059C64: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C68: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80059C6C: lh          $t7, 0x166($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X166);
    // 0x80059C70: lh          $t6, 0x162($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X162);
    // 0x80059C74: nop

    // 0x80059C78: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80059C7C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80059C80: jal         0x80070A38
    // 0x80059C84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80059C84: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80059C88: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80059C8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059C90: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80059C94: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059C98: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C9C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80059CA0: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80059CA4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80059CA8: bc1f        L_80059CC8
    if (!c1cs) {
        // 0x80059CAC: addiu       $t1, $t1, -0x24E2
        ctx->r9 = ADD32(ctx->r9, -0X24E2);
            goto L_80059CC8;
    }
    // 0x80059CAC: addiu       $t1, $t1, -0x24E2
    ctx->r9 = ADD32(ctx->r9, -0X24E2);
    // 0x80059CB0: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80059CB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80059CB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80059CBC: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80059CC0: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059CC4: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
L_80059CC8:
    // 0x80059CC8: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80059CCC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80059CD0: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80059CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059CD8: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80059CDC: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80059CE0: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80059CE4: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059CE8: nop

    // 0x80059CEC: bgtz        $a0, L_80059E60
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CF0: sub.s       $f2, $f0, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_80059E60;
    }
    // 0x80059CF0: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80059CF4: bgtz        $a0, L_80059E60
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CF8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80059E60;
    }
    // 0x80059CF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059CFC: lb          $a1, -0x24E4($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X24E4);
    // 0x80059D00: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059D04: addiu       $t6, $t6, -0x24E0
    ctx->r14 = ADD32(ctx->r14, -0X24E0);
    // 0x80059D08: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059D0C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059D10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059D14: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80059D18: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80059D1C: addiu       $t2, $t2, -0x24E4
    ctx->r10 = ADD32(ctx->r10, -0X24E4);
    // 0x80059D20: addiu       $t4, $t4, -0x24F0
    ctx->r12 = ADD32(ctx->r12, -0X24F0);
    // 0x80059D24: addiu       $t5, $t5, -0x24E0
    ctx->r13 = ADD32(ctx->r13, -0X24E0);
    // 0x80059D28: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_80059D2C:
    // 0x80059D2C: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x80059D30: addiu       $t7, $a0, 0x1E
    ctx->r15 = ADD32(ctx->r4, 0X1E);
    // 0x80059D34: slti        $at, $a3, 0x168
    ctx->r1 = SIGNED(ctx->r7) < 0X168 ? 1 : 0;
    // 0x80059D38: bne         $at, $zero, L_80059D70
    if (ctx->r1 != 0) {
        // 0x80059D3C: sh          $t7, 0x0($t1)
        MEM_H(0X0, ctx->r9) = ctx->r15;
            goto L_80059D70;
    }
    // 0x80059D3C: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80059D40: jal         0x8006ECF0
    // 0x80059D44: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x80059D44: nop

    after_2:
    // 0x80059D48: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059D4C: bne         $v0, $zero, L_80059E60
    if (ctx->r2 != 0) {
        // 0x80059D50: addiu       $t2, $t2, -0x24E4
        ctx->r10 = ADD32(ctx->r10, -0X24E4);
            goto L_80059E60;
    }
    // 0x80059D50: addiu       $t2, $t2, -0x24E4
    ctx->r10 = ADD32(ctx->r10, -0X24E4);
    // 0x80059D54: lb          $t9, 0x0($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X0);
    // 0x80059D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059D5C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80059D60: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80059D64: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80059D68: b           L_80059E60
    // 0x80059D6C: sh          $t8, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = ctx->r24;
        goto L_80059E60;
    // 0x80059D6C: sh          $t8, -0x24D8($at)
    MEM_H(-0X24D8, ctx->r1) = ctx->r24;
L_80059D70:
    // 0x80059D70: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059D74: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059D78: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x80059D7C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059D80: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80059D84: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059D88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059D8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059D90: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80059D94: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80059D98: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80059D9C: mflo        $t7
    ctx->r15 = lo;
    // 0x80059DA0: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80059DA4: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80059DA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059DAC: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80059DB0: nop

    // 0x80059DB4: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80059DB8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80059DBC: nop

    // 0x80059DC0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80059DC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059DC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059DCC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059DD0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80059DD4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059DD8: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80059DDC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80059DE0: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80059DE4: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80059DE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059DEC: nop

    // 0x80059DF0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80059DF4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80059DF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059DFC: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80059E00: lh          $t6, 0x160($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X160);
    // 0x80059E04: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x80059E08: nop

    // 0x80059E0C: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80059E10: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80059E14: lh          $t7, 0x162($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X162);
    // 0x80059E18: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80059E1C: nop

    // 0x80059E20: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80059E24: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80059E28: lh          $t8, 0x164($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X164);
    // 0x80059E2C: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x80059E30: nop

    // 0x80059E34: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80059E38: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x80059E3C: lb          $a1, 0x0($t2)
    ctx->r5 = MEM_B(ctx->r10, 0X0);
    // 0x80059E40: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059E44: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059E48: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80059E4C: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80059E50: nop

    // 0x80059E54: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80059E58: blez        $a0, L_80059D2C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80059E5C: sh          $t8, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r24;
            goto L_80059D2C;
    }
    // 0x80059E5C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_80059E60:
    // 0x80059E60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059E68: jr          $ra
    // 0x80059E6C: nop

    return;
    // 0x80059E6C: nop

;}
RECOMP_FUNC void handle_base_steering(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579F0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800579F4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800579F8: lw          $t6, -0x254C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X254C);
    // 0x800579FC: lb          $v1, 0x1E1($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1E1);
    // 0x80057A00: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80057A04: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x80057A08: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80057A0C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80057A10: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80057A14: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80057A18: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80057A1C: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80057A20: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80057A24: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80057A28: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80057A2C: nop

    // 0x80057A30: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80057A34: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057A38: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057A3C: nop

    // 0x80057A40: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x80057A44: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80057A48: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80057A4C: beq         $v0, $zero, L_80057A74
    if (ctx->r2 == 0) {
        // 0x80057A50: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80057A74;
    }
    // 0x80057A50: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80057A54: bne         $a2, $zero, L_80057A78
    if (ctx->r6 != 0) {
        // 0x80057A58: addu        $t8, $v1, $a1
        ctx->r24 = ADD32(ctx->r3, ctx->r5);
            goto L_80057A78;
    }
    // 0x80057A58: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x80057A5C: blez        $v0, L_80057A68
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80057A60: nop
    
            goto L_80057A68;
    }
    // 0x80057A60: nop

    // 0x80057A64: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80057A68:
    // 0x80057A68: bgez        $v0, L_80057A78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80057A6C: addu        $t8, $v1, $a1
        ctx->r24 = ADD32(ctx->r3, ctx->r5);
            goto L_80057A78;
    }
    // 0x80057A6C: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x80057A70: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80057A74:
    // 0x80057A74: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
L_80057A78:
    // 0x80057A78: jr          $ra
    // 0x80057A7C: sb          $t8, 0x1E1($a0)
    MEM_B(0X1E1, ctx->r4) = ctx->r24;
    return;
    // 0x80057A7C: sb          $t8, 0x1E1($a0)
    MEM_B(0X1E1, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void disable_racer_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A41C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A420: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A424: jr          $ra
    // 0x8005A428: sb          $t6, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = ctx->r14;
    return;
    // 0x8005A428: sb          $t6, -0x24FC($at)
    MEM_B(-0X24FC, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void sound_is_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800021B0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800021B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800021B8: blez        $t6, L_800021F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800021BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800021F0;
    }
    // 0x800021BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800021C0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800021C4: lw          $t7, 0x6294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6294);
    // 0x800021C8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800021CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800021D0: nop

    // 0x800021D4: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800021D8: nop

    // 0x800021DC: lh          $t9, 0xE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XE);
    // 0x800021E0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800021E4: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800021E8: beq         $at, $zero, L_800021F8
    if (ctx->r1 == 0) {
        // 0x800021EC: nop
    
            goto L_800021F8;
    }
    // 0x800021EC: nop

L_800021F0:
    // 0x800021F0: jr          $ra
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800021F8:
    // 0x800021F8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800021FC: nop

    // 0x80002200: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80002204: nop

    // 0x80002208: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x8000220C: nop

    // 0x80002210: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80002214: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80002218: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x8000221C: jr          $ra
    // 0x80002220: nop

    return;
    // 0x80002220: nop

;}
RECOMP_FUNC void timetrial_ghost_staff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B674: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B678: lw          $v0, -0x3378($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3378);
    // 0x8001B67C: jr          $ra
    // 0x8001B680: nop

    return;
    // 0x8001B680: nop

;}
RECOMP_FUNC void charselect_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C7B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C7BC: jr          $ra
    // 0x8009C7C0: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
    return;
    // 0x8009C7C0: addiu       $v0, $v0, 0x697C
    ctx->r2 = ADD32(ctx->r2, 0X697C);
;}
RECOMP_FUNC void gzip_huft_build(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C67D4: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x800C67D8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C67DC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C67E0: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x800C67E4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C67E8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C67EC: sw          $a1, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r5;
    // 0x800C67F0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C67F4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C67F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C67FC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C6800: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C6804: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C6808: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C680C: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x800C6810: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x800C6814: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800C6818: jal         0x800D0A40
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x800C681C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800C6820: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6824: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6828: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C682C: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C6830: beq         $v0, $zero, L_800C6868
    if (ctx->r2 == 0) {
        // 0x800C6834: or          $ra, $t6, $zero
        ctx->r31 = ctx->r14 | 0;
            goto L_800C6868;
    }
    // 0x800C6834: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800C6838: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
L_800C683C:
    // 0x800C683C: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6840: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C6844: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6848: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C684C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C6850: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6854: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6858: bne         $v1, $ra, L_800C683C
    if (ctx->r3 != ctx->r31) {
        // 0x800C685C: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C683C;
    }
    // 0x800C685C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6860: beq         $ra, $zero, L_800C68F0
    if (ctx->r31 == 0) {
        // 0x800C6864: lw          $t7, 0x5FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5FC);
            goto L_800C68F0;
    }
    // 0x800C6864: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C6868:
    // 0x800C6868: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C686C: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x800C6870: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6874: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6878: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C687C: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6880: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6884: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6888: lw          $t7, -0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, -0XC);
    // 0x800C688C: nop

    // 0x800C6890: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6894: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6898: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C689C: nop

    // 0x800C68A0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68A8: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x800C68AC: nop

    // 0x800C68B0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68B4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68B8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68BC: nop

    // 0x800C68C0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68C8: lw          $t7, -0x4($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X4);
    // 0x800C68CC: nop

    // 0x800C68D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C68D4: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C68D8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C68DC: nop

    // 0x800C68E0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C68E4: bne         $ra, $zero, L_800C6868
    if (ctx->r31 != 0) {
        // 0x800C68E8: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C6868;
    }
    // 0x800C68E8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C68EC: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C68F0:
    // 0x800C68F0: lw          $t8, 0x5B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5B0);
    // 0x800C68F4: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C68F8: bne         $t7, $t8, L_800C6918
    if (ctx->r15 != ctx->r24) {
        // 0x800C68FC: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C6918;
    }
    // 0x800C68FC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C6900: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C6904: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6908: nop

    // 0x800C690C: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C6910: b           L_800C6DEC
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800C6DEC;
    // 0x800C6914: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800C6918:
    // 0x800C6918: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800C691C: addiu       $a0, $sp, 0x5B4
    ctx->r4 = ADD32(ctx->r29, 0X5B4);
    // 0x800C6920: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C6924:
    // 0x800C6924: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C6928: nop

    // 0x800C692C: bne         $t9, $zero, L_800C6944
    if (ctx->r25 != 0) {
        // 0x800C6930: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_800C6944;
    }
    // 0x800C6930: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C6934: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6938: bne         $a3, $v0, L_800C6924
    if (ctx->r7 != ctx->r2) {
        // 0x800C693C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C6924;
    }
    // 0x800C693C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C6940: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_800C6944:
    // 0x800C6944: beq         $at, $zero, L_800C6950
    if (ctx->r1 == 0) {
        // 0x800C6948: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_800C6950;
    }
    // 0x800C6948: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C694C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_800C6950:
    // 0x800C6950: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x800C6954: addiu       $v1, $sp, 0x5F0
    ctx->r3 = ADD32(ctx->r29, 0X5F0);
L_800C6958:
    // 0x800C6958: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C695C: nop

    // 0x800C6960: bne         $t6, $zero, L_800C6978
    if (ctx->r14 != 0) {
        // 0x800C6964: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_800C6978;
    }
    // 0x800C6964: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    // 0x800C6968: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C696C: bne         $ra, $zero, L_800C6958
    if (ctx->r31 != 0) {
        // 0x800C6970: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6958;
    }
    // 0x800C6970: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6974: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_800C6978:
    // 0x800C6978: beq         $at, $zero, L_800C6984
    if (ctx->r1 == 0) {
        // 0x800C697C: sw          $ra, 0x5A8($sp)
        MEM_W(0X5A8, ctx->r29) = ctx->r31;
            goto L_800C6984;
    }
    // 0x800C697C: sw          $ra, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r31;
    // 0x800C6980: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_800C6984:
    // 0x800C6984: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6988: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x800C698C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C6990: beq         $at, $zero, L_800C69C0
    if (ctx->r1 == 0) {
        // 0x800C6994: sllv        $v0, $t7, $a3
        ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
            goto L_800C69C0;
    }
    // 0x800C6994: sllv        $v0, $t7, $a3
    ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6998: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x800C699C: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C69A0: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_800C69A4:
    // 0x800C69A4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C69A8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C69AC: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x800C69B0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C69B4: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x800C69B8: bne         $at, $zero, L_800C69A4
    if (ctx->r1 != 0) {
        // 0x800C69BC: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C69A4;
    }
    // 0x800C69BC: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800C69C0:
    // 0x800C69C0: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800C69C4: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C69C8: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C69CC: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x800C69D0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C69D4: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800C69D8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C69DC: addiu       $fp, $sp, 0x5B4
    ctx->r30 = ADD32(ctx->r29, 0X5B4);
    // 0x800C69E0: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800C69E4: beq         $ra, $zero, L_800C6A74
    if (ctx->r31 == 0) {
        // 0x800C69E8: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6A74;
    }
    // 0x800C69E8: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C69EC: andi        $a1, $ra, 0x3
    ctx->r5 = ctx->r31 & 0X3;
    // 0x800C69F0: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800C69F4: beq         $a1, $zero, L_800C6A2C
    if (ctx->r5 == 0) {
        // 0x800C69F8: addu        $v0, $a1, $ra
        ctx->r2 = ADD32(ctx->r5, ctx->r31);
            goto L_800C6A2C;
    }
    // 0x800C69F8: addu        $v0, $a1, $ra
    ctx->r2 = ADD32(ctx->r5, ctx->r31);
    // 0x800C69FC: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C6A00: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A04: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
L_800C6A08:
    // 0x800C6A08: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A0C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6A10: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A14: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A18: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6A1C: bne         $a0, $v1, L_800C6A08
    if (ctx->r4 != ctx->r3) {
        // 0x800C6A20: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_800C6A08;
    }
    // 0x800C6A20: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A24: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6A28: beq         $v1, $t8, L_800C6A74
    if (ctx->r3 == ctx->r24) {
        // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
        ctx->r2 = ADD32(ctx->r29, 0X5B0);
            goto L_800C6A74;
    }
L_800C6A2C:
    // 0x800C6A2C: addiu       $v0, $sp, 0x5B0
    ctx->r2 = ADD32(ctx->r29, 0X5B0);
L_800C6A30:
    // 0x800C6A30: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A34: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x800C6A38: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800C6A3C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C6A40: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x800C6A44: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800C6A48: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800C6A4C: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x800C6A50: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x800C6A54: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6A58: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C6A5C: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x800C6A60: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x800C6A64: nop

    // 0x800C6A68: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800C6A6C: bne         $v1, $v0, L_800C6A30
    if (ctx->r3 != ctx->r2) {
        // 0x800C6A70: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_800C6A30;
    }
    // 0x800C6A70: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_800C6A74:
    // 0x800C6A74: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6A78: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6A7C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800C6A80: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
L_800C6A84:
    // 0x800C6A84: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x800C6A88: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6A8C: beq         $a3, $zero, L_800C6AB4
    if (ctx->r7 == 0) {
        // 0x800C6A90: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800C6AB4;
    }
    // 0x800C6A90: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800C6A94: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x800C6A98: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800C6A9C: nop

    // 0x800C6AA0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C6AA4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800C6AA8: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x800C6AAC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800C6AB0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800C6AB4:
    // 0x800C6AB4: lw          $t9, 0x5FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6AB8: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800C6ABC: sltu        $at, $ra, $t9
    ctx->r1 = ctx->r31 < ctx->r25 ? 1 : 0;
    // 0x800C6AC0: bne         $at, $zero, L_800C6A84
    if (ctx->r1 != 0) {
        // 0x800C6AC4: nop
    
            goto L_800C6A84;
    }
    // 0x800C6AC4: nop

    // 0x800C6AC8: lw          $t6, 0x5A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6ACC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6AD0: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6AD4: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800C6AD8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800C6ADC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800C6AE0: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x800C6AE4: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x800C6AE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C6AEC: bne         $at, $zero, L_800C6DEC
    if (ctx->r1 != 0) {
        // 0x800C6AF0: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800C6DEC;
    }
    // 0x800C6AF0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C6AF4: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800C6AF8: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6AFC: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800C6B00: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C6B04: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C6B08: addiu       $s2, $s2, -0x4F68
    ctx->r18 = ADD32(ctx->r18, -0X4F68);
    // 0x800C6B0C: addiu       $s7, $s7, 0x3CF0
    ctx->r23 = ADD32(ctx->r23, 0X3CF0);
    // 0x800C6B10: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B14: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
L_800C6B18:
    // 0x800C6B18: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x800C6B1C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C6B20: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800C6B24: beq         $s6, $zero, L_800C6DD4
    if (ctx->r22 == 0) {
        // 0x800C6B28: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6DD4;
    }
    // 0x800C6B28: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6B2C: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6B30: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800C6B34: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C6B38: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B3C: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x800C6B40: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C6B44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6B48: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x800C6B4C: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800C6B50: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800C6B54: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800C6B58: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800C6B5C:
    // 0x800C6B5C: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6B60: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6B64: beq         $at, $zero, L_800C6C84
    if (ctx->r1 == 0) {
        // 0x800C6B68: addiu       $s1, $s6, 0x1
        ctx->r17 = ADD32(ctx->r22, 0X1);
            goto L_800C6C84;
    }
    // 0x800C6B68: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x800C6B6C: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x800C6B70: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6B74: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6B78:
    // 0x800C6B78: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6B7C: subu        $t0, $t7, $v1
    ctx->r8 = SUB32(ctx->r15, ctx->r3);
    // 0x800C6B80: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800C6B84: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800C6B88: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C6B8C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C6B90: beq         $at, $zero, L_800C6B9C
    if (ctx->r1 == 0) {
        // 0x800C6B94: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800C6B9C;
    }
    // 0x800C6B94: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800C6B98: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_800C6B9C:
    // 0x800C6B9C: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6BA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6BA4: sllv        $a0, $t6, $v0
    ctx->r4 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x800C6BA8: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800C6BAC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BB0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800C6BF8;
    }
    // 0x800C6BB0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C6BB4: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x800C6BB8: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x800C6BBC: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800C6BC0: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6BC4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BC8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C6BCC: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BD0: addu        $a2, $t8, $t9
        ctx->r6 = ADD32(ctx->r24, ctx->r25);
            goto L_800C6BF8;
    }
    // 0x800C6BD0: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
L_800C6BD4:
    // 0x800C6BD4: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C6BD8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C6BDC: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800C6BE0: beq         $at, $zero, L_800C6BF8
    if (ctx->r1 == 0) {
        // 0x800C6BE4: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C6BF8;
    }
    // 0x800C6BE4: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6BE8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C6BEC: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6BF0: bne         $at, $zero, L_800C6BD4
    if (ctx->r1 != 0) {
        // 0x800C6BF4: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_800C6BD4;
    }
    // 0x800C6BF4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_800C6BF8:
    // 0x800C6BF8: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C6BFC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6C00: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C6C04: sllv        $t0, $t7, $a3
    ctx->r8 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6C08: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800C6C0C: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800C6C10: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800C6C14: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6C18: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800C6C1C: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800C6C20: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x800C6C24: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800C6C28: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x800C6C2C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C6C30: beq         $t4, $zero, L_800C6C74
    if (ctx->r12 == 0) {
        // 0x800C6C34: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800C6C74;
    }
    // 0x800C6C34: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800C6C38: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x800C6C3C: addiu       $t6, $a3, 0x10
    ctx->r14 = ADD32(ctx->r7, 0X10);
    // 0x800C6C40: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
    // 0x800C6C44: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x800C6C48: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x800C6C4C: subu        $t9, $t2, $s0
    ctx->r25 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6C50: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x800C6C54: srlv        $t7, $ra, $t9
    ctx->r15 = S32(U32(ctx->r31) >> (ctx->r25 & 31));
    // 0x800C6C58: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6C5C: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800C6C60: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800C6C64: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800C6C68: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800C6C6C: nop

    // 0x800C6C70: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_800C6C74:
    // 0x800C6C74: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6C78: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6C7C: bne         $at, $zero, L_800C6B78
    if (ctx->r1 != 0) {
        // 0x800C6C80: lw          $t7, 0x5A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5A8);
            goto L_800C6B78;
    }
    // 0x800C6C80: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6C84:
    // 0x800C6C84: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C6C88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C6C8C: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6C90: sllv        $a1, $t8, $t2
    ctx->r5 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x800C6C94: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x800C6C98: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x800C6C9C: bne         $at, $zero, L_800C6CB0
    if (ctx->r1 != 0) {
        // 0x800C6CA0: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800C6CB0;
    }
    // 0x800C6CA0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C6CA4: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x800C6CA8: b           L_800C6D30
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CAC: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_800C6CB0:
    // 0x800C6CB0: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CB4: lw          $t6, 0x600($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CB8: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x800C6CBC: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800C6CC0: beq         $at, $zero, L_800C6CF0
    if (ctx->r1 == 0) {
        // 0x800C6CC4: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_800C6CF0;
    }
    // 0x800C6CC4: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x800C6CC8: beq         $at, $zero, L_800C6CDC
    if (ctx->r1 == 0) {
        // 0x800C6CCC: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800C6CDC;
    }
    // 0x800C6CCC: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C6CD0: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C6CD4: b           L_800C6CE0
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_800C6CE0;
    // 0x800C6CD8: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_800C6CDC:
    // 0x800C6CDC: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
L_800C6CE0:
    // 0x800C6CE0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6CE4: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6CE8: b           L_800C6D30
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
        goto L_800C6D30;
    // 0x800C6CEC: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
L_800C6CF0:
    // 0x800C6CF0: lw          $t8, 0x608($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X608);
    // 0x800C6CF4: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C6CF8: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800C6CFC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800C6D00: lw          $t6, 0x604($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X604);
    // 0x800C6D04: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
    // 0x800C6D08: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800C6D0C: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6D10: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800C6D14: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800C6D18: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800C6D1C: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x800C6D20: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C6D24: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800C6D28: nop

    // 0x800C6D2C: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_800C6D30:
    // 0x800C6D30: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x800C6D34: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D38: beq         $at, $zero, L_800C6D68
    if (ctx->r1 == 0) {
        // 0x800C6D3C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C6D68;
    }
    // 0x800C6D3C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C6D40: sllv        $v0, $t9, $v1
    ctx->r2 = S32(ctx->r25 << (ctx->r3 & 31));
L_800C6D44:
    // 0x800C6D44: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C6D48: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800C6D4C: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800C6D50: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800C6D54: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800C6D58: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800C6D5C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6D60: bne         $at, $zero, L_800C6D44
    if (ctx->r1 != 0) {
        // 0x800C6D64: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_800C6D44;
    }
    // 0x800C6D64: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800C6D68:
    // 0x800C6D68: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800C6D6C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800C6D70: and         $t6, $ra, $a3
    ctx->r14 = ctx->r31 & ctx->r7;
    // 0x800C6D74: beq         $t6, $zero, L_800C6D8C
    if (ctx->r14 == 0) {
        // 0x800C6D78: srl         $t8, $a3, 1
        ctx->r24 = S32(U32(ctx->r7) >> 1);
            goto L_800C6D8C;
    }
L_800C6D78:
    // 0x800C6D78: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x800C6D7C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D80: and         $t7, $ra, $t8
    ctx->r15 = ctx->r31 & ctx->r24;
    // 0x800C6D84: bne         $t7, $zero, L_800C6D78
    if (ctx->r15 != 0) {
        // 0x800C6D88: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800C6D78;
    }
    // 0x800C6D88: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_800C6D8C:
    // 0x800C6D8C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6D90: and         $t9, $ra, $a1
    ctx->r25 = ctx->r31 & ctx->r5;
    // 0x800C6D94: beq         $t9, $v0, L_800C6DC4
    if (ctx->r25 == ctx->r2) {
        // 0x800C6D98: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800C6DC4;
    }
    // 0x800C6D98: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_800C6D9C:
    // 0x800C6D9C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6DA0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6DA4: sllv        $t8, $t6, $t2
    ctx->r24 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x800C6DA8: lw          $t6, -0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X4);
    // 0x800C6DAC: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800C6DB0: and         $t9, $ra, $t7
    ctx->r25 = ctx->r31 & ctx->r15;
    // 0x800C6DB4: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800C6DB8: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x800C6DBC: bne         $t9, $t6, L_800C6D9C
    if (ctx->r25 != ctx->r14) {
        // 0x800C6DC0: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_800C6D9C;
    }
    // 0x800C6DC0: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_800C6DC4:
    // 0x800C6DC4: bne         $s6, $zero, L_800C6B5C
    if (ctx->r22 != 0) {
        // 0x800C6DC8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6B5C;
    }
    // 0x800C6DC8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C6DCC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800C6DD0: nop

L_800C6DD4:
    // 0x800C6DD4: lw          $t8, 0x5A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6DD8: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6DDC: slt         $at, $t8, $s4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6DE0: beq         $at, $zero, L_800C6B18
    if (ctx->r1 == 0) {
        // 0x800C6DE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C6B18;
    }
    // 0x800C6DE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C6DE8: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_800C6DEC:
    // 0x800C6DEC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6DF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6DF4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6DF8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C6DFC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C6E00: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C6E04: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6E08: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C6E0C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C6E10: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C6E14: jr          $ra
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x800C6E18: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
;}
RECOMP_FUNC void material_load_simple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C384: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007C388: addiu       $a3, $a3, 0x6914
    ctx->r7 = ADD32(ctx->r7, 0X6914);
    // 0x8007C38C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8007C390: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C394: bne         $a1, $t6, L_8007C3AC
    if (ctx->r5 != ctx->r14) {
        // 0x8007C398: addiu       $t0, $t0, 0x6922
        ctx->r8 = ADD32(ctx->r8, 0X6922);
            goto L_8007C3AC;
    }
    // 0x8007C398: addiu       $t0, $t0, 0x6922
    ctx->r8 = ADD32(ctx->r8, 0X6922);
    // 0x8007C39C: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8007C3A0: nop

    // 0x8007C3A4: beq         $t7, $zero, L_8007C574
    if (ctx->r15 == 0) {
        // 0x8007C3A8: nop
    
            goto L_8007C574;
    }
    // 0x8007C3A8: nop

L_8007C3AC:
    // 0x8007C3AC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C3B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007C3B4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007C3B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007C3BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007C3C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007C3C4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007C3C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C3CC: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x8007C3D0: bltz        $t1, L_8007C3E8
    if (SIGNED(ctx->r9) < 0) {
        // 0x8007C3D4: addiu       $t0, $t0, 0x6922
        ctx->r8 = ADD32(ctx->r8, 0X6922);
            goto L_8007C3E8;
    }
    // 0x8007C3D4: addiu       $t0, $t0, 0x6922
    ctx->r8 = ADD32(ctx->r8, 0X6922);
    // 0x8007C3D8: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8007C3DC: nop

    // 0x8007C3E0: beq         $t2, $zero, L_8007C40C
    if (ctx->r10 == 0) {
        // 0x8007C3E4: nop
    
            goto L_8007C40C;
    }
    // 0x8007C3E4: nop

L_8007C3E8:
    // 0x8007C3E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C3EC: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x8007C3F0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007C3F4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007C3F8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8007C3FC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007C400: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007C404: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007C408: nop

L_8007C40C:
    // 0x8007C40C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C410: lw          $t7, 0x6918($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6918);
    // 0x8007C414: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x8007C418: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007C41C: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x8007C420: nor         $t8, $t7, $zero
    ctx->r24 = ~(ctx->r15 | 0);
    // 0x8007C424: and         $a1, $t6, $t8
    ctx->r5 = ctx->r14 & ctx->r24;
    // 0x8007C428: andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // 0x8007C42C: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8007C430: bne         $t9, $v0, L_8007C448
    if (ctx->r25 != ctx->r2) {
        // 0x8007C434: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007C448;
    }
    // 0x8007C434: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007C438: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8007C43C: nop

    // 0x8007C440: beq         $t1, $zero, L_8007C488
    if (ctx->r9 == 0) {
        // 0x8007C444: nop
    
            goto L_8007C488;
    }
    // 0x8007C444: nop

L_8007C448:
    // 0x8007C448: beq         $v0, $zero, L_8007C470
    if (ctx->r2 == 0) {
        // 0x8007C44C: lui         $t6, 0xB600
        ctx->r14 = S32(0XB600 << 16);
            goto L_8007C470;
    }
    // 0x8007C44C: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8007C450: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C454: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8007C458: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C45C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C460: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C464: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007C468: b           L_8007C488
    // 0x8007C46C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C488;
    // 0x8007C46C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C470:
    // 0x8007C470: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C474: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C478: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007C47C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8007C480: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C484: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8007C488:
    // 0x8007C488: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8007C48C: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8007C490: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C494: lw          $t9, -0x12BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X12BC);
    // 0x8007C498: and         $t8, $a1, $at
    ctx->r24 = ctx->r5 & ctx->r1;
    // 0x8007C49C: bne         $t9, $zero, L_8007C52C
    if (ctx->r25 != 0) {
        // 0x8007C4A0: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8007C52C;
    }
    // 0x8007C4A0: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8007C4A4: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8007C4A8: lui         $t3, 0x702
    ctx->r11 = S32(0X702 << 16);
    // 0x8007C4AC: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x8007C4B0: beq         $t2, $zero, L_8007C4F8
    if (ctx->r10 == 0) {
        // 0x8007C4B4: ori         $t3, $t3, 0x10
        ctx->r11 = ctx->r11 | 0X10;
            goto L_8007C4F8;
    }
    // 0x8007C4B4: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8007C4B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4BC: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007C4C0: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8007C4C4: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8007C4C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C4CC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C4D0: addiu       $t9, $t9, -0x1238
    ctx->r25 = ADD32(ctx->r25, -0X1238);
    // 0x8007C4D4: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8007C4D8: lui         $t4, 0x702
    ctx->r12 = S32(0X702 << 16);
    // 0x8007C4DC: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007C4E0: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007C4E4: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8007C4E8: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C4EC: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007C4F0: b           L_8007C560
    // 0x8007C4F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007C560;
    // 0x8007C4F4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C4F8:
    // 0x8007C4F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C4FC: addiu       $t4, $a1, -0x10
    ctx->r12 = ADD32(ctx->r5, -0X10);
    // 0x8007C500: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8007C504: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C508: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007C50C: addiu       $t7, $t7, -0x1218
    ctx->r15 = ADD32(ctx->r15, -0X1218);
    // 0x8007C510: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8007C514: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C518: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C51C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C520: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C524: b           L_8007C560
    // 0x8007C528: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C560;
    // 0x8007C528: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C52C:
    // 0x8007C52C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C530: sll         $t2, $a1, 4
    ctx->r10 = S32(ctx->r5 << 4);
    // 0x8007C534: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C538: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007C53C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C540: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C544: addiu       $t4, $t4, -0x1198
    ctx->r12 = ADD32(ctx->r12, -0X1198);
    // 0x8007C548: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8007C54C: lui         $t1, 0x702
    ctx->r9 = S32(0X702 << 16);
    // 0x8007C550: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x8007C554: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C558: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007C55C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8007C560:
    // 0x8007C560: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C564: sw          $zero, 0x691C($at)
    MEM_W(0X691C, ctx->r1) = 0;
    // 0x8007C568: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C56C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C570: sh          $t6, 0x6920($at)
    MEM_H(0X6920, ctx->r1) = ctx->r14;
L_8007C574:
    // 0x8007C574: jr          $ra
    // 0x8007C578: nop

    return;
    // 0x8007C578: nop

;}
RECOMP_FUNC void trackmenu_render_2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF0C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008FF10: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008FF14: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8008FF18: lw          $t6, 0x6A18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A18);
    // 0x8008FF1C: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8008FF20: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8008FF24: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8008FF28: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8008FF2C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8008FF30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008FF34: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8008FF38: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8008FF3C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8008FF40: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8008FF44: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8008FF48: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8008FF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008FF50: addiu       $s4, $a0, 0xA0
    ctx->r20 = ADD32(ctx->r4, 0XA0);
    // 0x8008FF54: bne         $t8, $zero, L_8008FF60
    if (ctx->r24 != 0) {
        // 0x8008FF58: subu        $s5, $t6, $a1
        ctx->r21 = SUB32(ctx->r14, ctx->r5);
            goto L_8008FF60;
    }
    // 0x8008FF58: subu        $s5, $t6, $a1
    ctx->r21 = SUB32(ctx->r14, ctx->r5);
    // 0x8008FF5C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8008FF60:
    // 0x8008FF60: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8008FF64: jal         0x800C484C
    // 0x8008FF68: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008FF68: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008FF6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FF70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008FF74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008FF78: jal         0x800C492C
    // 0x8008FF7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008FF7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008FF80: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008FF84: lw          $v0, -0x604($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X604);
    // 0x8008FF88: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8008FF8C: blez        $v0, L_8008FFB0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FF90: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008FFB0;
    }
    // 0x8008FF90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008FF94: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8008FF98: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008FF9C: subu        $s1, $t0, $t9
    ctx->r17 = SUB32(ctx->r8, ctx->r25);
    // 0x8008FFA0: bgez        $s1, L_8008FFB0
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008FFA4: nop
    
            goto L_8008FFB0;
    }
    // 0x8008FFA4: nop

    // 0x8008FFA8: b           L_8008FFB0
    // 0x8008FFAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8008FFB0;
    // 0x8008FFAC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8008FFB0:
    // 0x8008FFB0: lw          $t1, 0x6FB0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6FB0);
    // 0x8008FFB4: nop

    // 0x8008FFB8: beq         $s2, $t1, L_80090078
    if (ctx->r18 == ctx->r9) {
        // 0x8008FFBC: nop
    
            goto L_80090078;
    }
    // 0x8008FFBC: nop

    // 0x8008FFC0: jal         0x8006B414
    // 0x8008FFC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_world_id(rdram, ctx);
        goto after_2;
    // 0x8008FFC4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8008FFC8: jal         0x8006C01C
    // 0x8008FFCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_3;
    // 0x8008FFCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8008FFD0: bne         $s2, $v0, L_8008FFE4
    if (ctx->r18 != ctx->r2) {
        // 0x8008FFD4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FFE4;
    }
    // 0x8008FFD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FFD8: jal         0x800C46C4
    // 0x8008FFDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_4;
    // 0x8008FFDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8008FFE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008FFE4:
    // 0x8008FFE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008FFE8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008FFEC: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008FFF0: bgez        $s1, L_80090000
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008FFF4: sra         $t2, $s1, 1
        ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
            goto L_80090000;
    }
    // 0x8008FFF4: sra         $t2, $s1, 1
    ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8008FFF8: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8008FFFC: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_80090000:
    // 0x80090000: jal         0x800C48E4
    // 0x80090004: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80090004: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x80090008: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8009000C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80090010: addiu       $s3, $s3, 0x693C
    ctx->r19 = ADD32(ctx->r19, 0X693C);
    // 0x80090014: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80090018: subu        $s0, $s5, $t3
    ctx->r16 = SUB32(ctx->r21, ctx->r11);
    // 0x8009001C: addiu       $a2, $s0, -0x55
    ctx->r6 = ADD32(ctx->r16, -0X55);
    // 0x80090020: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80090024: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80090028: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8009002C: jal         0x800C49A0
    // 0x80090030: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80090030: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x80090034: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80090038: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009003C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80090040: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80090044: jal         0x800C48E4
    // 0x80090048: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80090048: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // 0x8009004C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80090050: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80090054: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80090058: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8009005C: addiu       $a2, $s0, -0x58
    ctx->r6 = ADD32(ctx->r16, -0X58);
    // 0x80090060: jal         0x800C49A0
    // 0x80090064: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80090064: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_8:
    // 0x80090068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009006C: sw          $s2, 0x6FB0($at)
    MEM_W(0X6FB0, ctx->r1) = ctx->r18;
    // 0x80090070: jal         0x800C46C4
    // 0x80090074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_9;
    // 0x80090074: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_80090078:
    // 0x80090078: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8009007C: addiu       $s3, $s3, 0x693C
    ctx->r19 = ADD32(ctx->r19, 0X693C);
    // 0x80090080: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80090084: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80090088: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009008C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80090090: jal         0x800C48E4
    // 0x80090094: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    set_text_colour(rdram, ctx);
        goto after_10;
    // 0x80090094: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x80090098: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8009009C: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x800900A0: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x800900A4: addu        $a2, $t6, $s5
    ctx->r6 = ADD32(ctx->r14, ctx->r21);
    // 0x800900A8: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    // 0x800900AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800900B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800900B4: jal         0x800C49A0
    // 0x800900B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x800900B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_11:
    // 0x800900BC: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x800900C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800900C4: blez        $s0, L_8009025C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800900C8: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_8009025C;
    }
    // 0x800900C8: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x800900CC: lw          $v0, 0x6A20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A20);
    // 0x800900D0: nop

    // 0x800900D4: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800900D8: subu        $t8, $s5, $v1
    ctx->r24 = SUB32(ctx->r21, ctx->r3);
    // 0x800900DC: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800900E0: beq         $at, $zero, L_80090258
    if (ctx->r1 == 0) {
        // 0x800900E4: addu        $t0, $v1, $s5
        ctx->r8 = ADD32(ctx->r3, ctx->r21);
            goto L_80090258;
    }
    // 0x800900E4: addu        $t0, $v1, $s5
    ctx->r8 = ADD32(ctx->r3, ctx->r21);
    // 0x800900E8: blez        $t0, L_80090258
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800900EC: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_80090258;
    }
    // 0x800900EC: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x800900F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800900F4: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x800900F8: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x800900FC: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80090100: bne         $t9, $zero, L_80090120
    if (ctx->r25 != 0) {
        // 0x80090104: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_80090120;
    }
    // 0x80090104: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x80090108: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009010C: lwc1        $f7, -0x75A0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X75A0);
    // 0x80090110: lwc1        $f6, -0x759C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X759C);
    // 0x80090114: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80090118: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8009011C: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_80090120:
    // 0x80090120: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x80090124: addiu       $v0, $s4, -0x50
    ctx->r2 = ADD32(ctx->r20, -0X50);
    // 0x80090128: beq         $t1, $zero, L_80090190
    if (ctx->r9 == 0) {
        // 0x8009012C: addiu       $t8, $s4, 0x50
        ctx->r24 = ADD32(ctx->r20, 0X50);
            goto L_80090190;
    }
    // 0x8009012C: addiu       $t8, $s4, 0x50
    ctx->r24 = ADD32(ctx->r20, 0X50);
    // 0x80090130: addiu       $t2, $sp, 0x5C
    ctx->r10 = ADD32(ctx->r29, 0X5C);
    // 0x80090134: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80090138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009013C: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80090140: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80090144: jal         0x80066E6C
    // 0x80090148: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    copy_viewport_frame_size_to_coords(rdram, ctx);
        goto after_12;
    // 0x80090148: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_12:
    // 0x8009014C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80090150: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80090154: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x80090158: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8009015C: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x80090160: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x80090164: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x80090168: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8009016C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80090170: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090174: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80090178: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8009017C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090180: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80090184: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80090188: b           L_80090194
    // 0x8009018C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
        goto L_80090194;
    // 0x8009018C: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_80090190:
    // 0x80090190: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_80090194:
    // 0x80090194: slti        $at, $v0, 0x140
    ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x80090198: beq         $at, $zero, L_800901FC
    if (ctx->r1 == 0) {
        // 0x8009019C: sw          $v0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r2;
            goto L_800901FC;
    }
    // 0x8009019C: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800901A0: blez        $s4, L_800901FC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800901A4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800901FC;
    }
    // 0x800901A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800901A8: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x800901AC: mtc1        $s5, $f16
    ctx->f16.u32l = ctx->r21;
    // 0x800901B0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800901B4: andi        $t0, $s0, 0xFF
    ctx->r8 = ctx->r16 & 0XFF;
    // 0x800901B8: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800901BC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800901C0: or          $t9, $t0, $at
    ctx->r25 = ctx->r8 | ctx->r1;
    // 0x800901C4: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800901C8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800901CC: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x800901D0: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800901D4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800901D8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800901DC: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800901E0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800901E4: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x800901E8: jal         0x80079150
    // 0x800901EC: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_13;
    // 0x800901EC: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x800901F0: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800901F4: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800901F8: nop

L_800901FC:
    // 0x800901FC: slti        $at, $s4, 0x140
    ctx->r1 = SIGNED(ctx->r20) < 0X140 ? 1 : 0;
    // 0x80090200: beq         $at, $zero, L_80090250
    if (ctx->r1 == 0) {
        // 0x80090204: nop
    
            goto L_80090250;
    }
    // 0x80090204: nop

    // 0x80090208: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8009020C: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x80090210: blez        $t2, L_80090250
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80090214: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80090250;
    }
    // 0x80090214: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80090218: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x8009021C: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x80090220: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090224: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x80090228: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009022C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090230: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80090234: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80090238: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009023C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80090240: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80090244: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80090248: jal         0x80079150
    // 0x8009024C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    texrect_draw_scaled(rdram, ctx);
        goto after_14;
    // 0x8009024C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_14:
L_80090250:
    // 0x80090250: jal         0x8007B820
    // 0x80090254: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_15;
    // 0x80090254: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
L_80090258:
    // 0x80090258: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_8009025C:
    // 0x8009025C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090260: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80090264: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x80090268: addiu       $v1, $v1, -0x324
    ctx->r3 = ADD32(ctx->r3, -0X324);
    // 0x8009026C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090270: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80090274: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x80090278: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8009027C: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x80090280: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x80090284: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80090288: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8009028C: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x80090290: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80090294: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80090298: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8009029C: swc1        $f16, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f16.u32l;
    // 0x800902A0: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x800902A4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800902A8: bne         $t1, $zero, L_800902CC
    if (ctx->r9 != 0) {
        // 0x800902AC: addiu       $t3, $t3, 0xC44
        ctx->r11 = ADD32(ctx->r11, 0XC44);
            goto L_800902CC;
    }
    // 0x800902AC: addiu       $t3, $t3, 0xC44
    ctx->r11 = ADD32(ctx->r11, 0XC44);
    // 0x800902B0: lwc1        $f18, -0x7598($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7598);
    // 0x800902B4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800902B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800902BC: addiu       $t2, $t2, 0xC54
    ctx->r10 = ADD32(ctx->r10, 0XC54);
    // 0x800902C0: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x800902C4: b           L_800902D0
    // 0x800902C8: swc1        $f18, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f18.u32l;
        goto L_800902D0;
    // 0x800902C8: swc1        $f18, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f18.u32l;
L_800902CC:
    // 0x800902CC: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
L_800902D0:
    // 0x800902D0: jal         0x8009CFA4
    // 0x800902D4: nop

    menu_element_render(rdram, ctx);
        goto after_16;
    // 0x800902D4: nop

    after_16:
    // 0x800902D8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800902DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800902E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800902E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800902E8: swc1        $f4, -0x62C($at)
    MEM_W(-0X62C, ctx->r1) = ctx->f4.u32l;
    // 0x800902EC: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
L_800902F0:
    // 0x800902F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800902F4: sllv        $t5, $t4, $s1
    ctx->r13 = S32(ctx->r12 << (ctx->r17 & 31));
    // 0x800902F8: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x800902FC: beq         $t7, $zero, L_80090398
    if (ctx->r15 == 0) {
        // 0x80090300: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80090398;
    }
    // 0x80090300: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80090304: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80090308: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8009030C: addu        $s0, $t9, $t2
    ctx->r16 = ADD32(ctx->r25, ctx->r10);
    // 0x80090310: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80090314: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x80090318: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009031C: addiu       $t0, $t0, 0xBF8
    ctx->r8 = ADD32(ctx->r8, 0XBF8);
    // 0x80090320: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80090324: addu        $s2, $t8, $t0
    ctx->r18 = ADD32(ctx->r24, ctx->r8);
    // 0x80090328: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8009032C: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x80090330: addu        $a2, $t3, $s4
    ctx->r6 = ADD32(ctx->r11, ctx->r20);
    // 0x80090334: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    // 0x80090338: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8009033C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80090340: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x80090344: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80090348: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009034C: jal         0x80078F08
    // 0x80090350: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_17;
    // 0x80090350: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x80090354: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80090358: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8009035C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80090360: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80090364: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80090368: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009036C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80090370: addu        $a2, $t6, $s4
    ctx->r6 = ADD32(ctx->r14, ctx->r20);
    // 0x80090374: addu        $a3, $t7, $s5
    ctx->r7 = ADD32(ctx->r15, ctx->r21);
    // 0x80090378: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8009037C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80090380: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80090384: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80090388: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8009038C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80090390: jal         0x80078F08
    // 0x80090394: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    texrect_draw(rdram, ctx);
        goto after_18;
    // 0x80090394: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
L_80090398:
    // 0x80090398: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8009039C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800903A0: bne         $s1, $at, L_800902F0
    if (ctx->r17 != ctx->r1) {
        // 0x800903A4: lw          $t6, 0xA0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA0);
            goto L_800902F0;
    }
    // 0x800903A4: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x800903A8: jal         0x8007B820
    // 0x800903AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_19;
    // 0x800903AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x800903B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800903B4: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800903B8: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800903BC: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800903C0: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800903C4: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800903C8: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800903CC: jr          $ra
    // 0x800903D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800903D0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void alResampleParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC5F0: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800CC5F4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CC5F8: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800CC5FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC600: beq         $at, $zero, L_800CC6B0
    if (ctx->r1 == 0) {
        // 0x800CC604: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CC6B0;
    }
    // 0x800CC604: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CC608: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC60C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC610: addu        $at, $at, $t6
    gpr jr_addend_800CC618 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CC614: lw          $t6, -0x6480($at)
    ctx->r14 = ADD32(ctx->r1, -0X6480);
    // 0x800CC618: jr          $t6
    // 0x800CC61C: nop

    switch (jr_addend_800CC618 >> 2) {
        case 0: goto L_800CC620; break;
        case 1: goto L_800CC6B0; break;
        case 2: goto L_800CC6B0; break;
        case 3: goto L_800CC628; break;
        case 4: goto L_800CC6B0; break;
        case 5: goto L_800CC6B0; break;
        case 6: goto L_800CC694; break;
        case 7: goto L_800CC6A4; break;
        case 8: goto L_800CC664; break;
        default: switch_error(__func__, 0x800CC618, 0x800E9B80);
    }
    // 0x800CC61C: nop

L_800CC620:
    // 0x800CC620: b           L_800CC6C8
    // 0x800CC624: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800CC6C8;
    // 0x800CC624: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800CC628:
    // 0x800CC628: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC62C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CC630: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CC634: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800CC638: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800CC63C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800CC640: beq         $a0, $zero, L_800CC6C8
    if (ctx->r4 == 0) {
        // 0x800CC644: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800CC6C8;
    }
    // 0x800CC644: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800CC648: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC64C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CC650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC654: jalr        $t9
    // 0x800CC658: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC658: nop

    after_0:
    // 0x800CC65C: b           L_800CC6CC
    // 0x800CC660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC6CC;
    // 0x800CC660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC664:
    // 0x800CC664: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC668: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CC66C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800CC670: beql        $a0, $zero, L_800CC6CC
    if (ctx->r4 == 0) {
        // 0x800CC674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC6CC;
    }
    goto skip_0;
    // 0x800CC674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CC678: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC67C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CC680: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC684: jalr        $t9
    // 0x800CC688: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC688: nop

    after_1:
    // 0x800CC68C: b           L_800CC6CC
    // 0x800CC690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC6CC;
    // 0x800CC690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC694:
    // 0x800CC694: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CC698: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CC69C: b           L_800CC6C8
    // 0x800CC6A0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800CC6C8;
    // 0x800CC6A0: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800CC6A4:
    // 0x800CC6A4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CC6A8: b           L_800CC6C8
    // 0x800CC6AC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800CC6C8;
    // 0x800CC6AC: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800CC6B0:
    // 0x800CC6B0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC6B4: beql        $a0, $zero, L_800CC6CC
    if (ctx->r4 == 0) {
        // 0x800CC6B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC6CC;
    }
    goto skip_1;
    // 0x800CC6B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CC6BC: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC6C0: jalr        $t9
    // 0x800CC6C4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CC6C4: nop

    after_2:
L_800CC6C8:
    // 0x800CC6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC6CC:
    // 0x800CC6CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CC6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CC6D4: jr          $ra
    // 0x800CC6D8: nop

    return;
    // 0x800CC6D8: nop

;}
RECOMP_FUNC void obj_init_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DEB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DEB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DEBC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DEC0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DEC4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DEC8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DECC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DED0: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DED4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DED8: nop

    // 0x8003DEDC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DEE0: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003DEE4: nop

    // 0x8003DEE8: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8003DEEC: sb          $t2, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r10;
    // 0x8003DEF0: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8003DEF4: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x8003DEF8: jal         0x8006ECD0
    // 0x8003DEFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003DEFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DF00: jal         0x8009C814
    // 0x8003DF04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8003DF04: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DF08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003DF0C: bne         $v0, $zero, L_8003DF30
    if (ctx->r2 != 0) {
        // 0x8003DF10: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003DF30;
    }
    // 0x8003DF10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003DF14: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DF18: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003DF1C: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x8003DF20: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8003DF24: and         $t9, $t5, $t8
    ctx->r25 = ctx->r13 & ctx->r24;
    // 0x8003DF28: beq         $t9, $zero, L_8003DF3C
    if (ctx->r25 == 0) {
        // 0x8003DF2C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DF3C;
    }
    // 0x8003DF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DF30:
    // 0x8003DF30: jal         0x8000FFB8
    // 0x8003DF34: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DF34: nop

    after_2:
    // 0x8003DF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DF3C:
    // 0x8003DF3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DF40: jr          $ra
    // 0x8003DF44: nop

    return;
    // 0x8003DF44: nop

;}
RECOMP_FUNC void rain_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD96C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD970: lw          $t6, 0x31EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31EC);
    // 0x800AD974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD978: beq         $t6, $zero, L_800AD9FC
    if (ctx->r14 == 0) {
        // 0x800AD97C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AD9FC;
    }
    // 0x800AD97C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AD980: jal         0x80066450
    // 0x800AD984: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800AD984: nop

    after_0:
    // 0x800AD988: bne         $v0, $zero, L_800AD9FC
    if (ctx->r2 != 0) {
        // 0x800AD98C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AD9FC;
    }
    // 0x800AD98C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AD990: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD994: lw          $v0, 0x31F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X31F0);
    // 0x800AD998: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800AD99C: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x800AD9A0: sll         $v1, $at, 2
    ctx->r3 = S32(ctx->r1 << 2);
    // 0x800AD9A4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800AD9A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AD9AC: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x800AD9B0: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x800AD9B4: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x800AD9B8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800AD9BC: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800AD9C0: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AD9C4: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AD9C8: addiu       $v1, $t7, 0x3FA
    ctx->r3 = ADD32(ctx->r15, 0X3FA);
    // 0x800AD9CC: addiu       $t0, $t8, 0x3FF
    ctx->r8 = ADD32(ctx->r24, 0X3FF);
    // 0x800AD9D0: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800AD9D4: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x800AD9D8: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AD9DC: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800AD9E0: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800AD9E4: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AD9E8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800AD9EC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AD9F0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800AD9F4: jal         0x800306A4
    // 0x800AD9F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    set_fog(rdram, ctx);
        goto after_1;
    // 0x800AD9F8: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_1:
L_800AD9FC:
    // 0x800AD9FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ADA00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800ADA04: jr          $ra
    // 0x800ADA08: nop

    return;
    // 0x800ADA08: nop

;}
RECOMP_FUNC void menu_title_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C9E4: jr          $ra
    // 0x8009C9E8: sw          $zero, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = 0;
    return;
    // 0x8009C9E8: sw          $zero, -0x5F8($at)
    MEM_W(-0X5F8, ctx->r1) = 0;
;}
RECOMP_FUNC void alCSPSetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7EA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7EA4: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7EAC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7EB0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7EB4: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C7EB8: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C7EBC: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7EC0: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800C7EC4: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7EC8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C7ECC: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7ED0: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7ED4: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7ED8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C7EDC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7EE0: jal         0x800C970C
    // 0x800C7EE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7EE4: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7EEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7EF0: jr          $ra
    // 0x800C7EF4: nop

    return;
    // 0x800C7EF4: nop

;}
RECOMP_FUNC void trackmenu_staff_beaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80093128: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009312C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80093130: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80093134: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80093138: jal         0x8001E2D0
    // 0x8009313C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8009313C: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80093140: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80093144: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80093148: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8009314C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80093150: beq         $t0, $t6, L_80093184
    if (ctx->r8 == ctx->r14) {
        // 0x80093154: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_80093184;
    }
    // 0x80093154: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80093158: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009315C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80093160:
    // 0x80093160: bne         $a3, $a0, L_8009316C
    if (ctx->r7 != ctx->r4) {
        // 0x80093164: nop
    
            goto L_8009316C;
    }
    // 0x80093164: nop

    // 0x80093168: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8009316C:
    // 0x8009316C: lb          $a0, 0x1($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X1);
    // 0x80093170: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80093174: beq         $t0, $a0, L_80093184
    if (ctx->r8 == ctx->r4) {
        // 0x80093178: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80093184;
    }
    // 0x80093178: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009317C: bltz        $a2, L_80093160
    if (SIGNED(ctx->r6) < 0) {
        // 0x80093180: nop
    
            goto L_80093160;
    }
    // 0x80093180: nop

L_80093184:
    // 0x80093184: bltz        $a2, L_800931BC
    if (SIGNED(ctx->r6) < 0) {
        // 0x80093188: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_800931BC;
    }
    // 0x80093188: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8009318C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80093190: lw          $t4, 0x69E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X69E8);
    // 0x80093194: sllv        $t8, $t7, $a2
    ctx->r24 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x80093198: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009319C: lw          $t5, 0x69EC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X69EC);
    // 0x800931A0: sra         $t2, $t8, 31
    ctx->r10 = S32(SIGNED(ctx->r24) >> 31);
    // 0x800931A4: and         $t6, $t2, $t4
    ctx->r14 = ctx->r10 & ctx->r12;
    // 0x800931A8: bne         $t6, $zero, L_800931BC
    if (ctx->r14 != 0) {
        // 0x800931AC: and         $t7, $t8, $t5
        ctx->r15 = ctx->r24 & ctx->r13;
            goto L_800931BC;
    }
    // 0x800931AC: and         $t7, $t8, $t5
    ctx->r15 = ctx->r24 & ctx->r13;
    // 0x800931B0: bne         $t7, $zero, L_800931C0
    if (ctx->r15 != 0) {
        // 0x800931B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800931C0;
    }
    // 0x800931B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800931B8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800931BC:
    // 0x800931BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800931C0:
    // 0x800931C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800931C4: jr          $ra
    // 0x800931C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x800931C8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void racer_spinout_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052BA4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052BA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052BAC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052BB0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80052BB4: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80052BB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052BBC: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052BC0: lwc1        $f9, 0x6C80($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6C80);
    // 0x80052BC4: lwc1        $f8, 0x6C84($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6C84);
    // 0x80052BC8: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80052BCC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80052BD0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80052BD4: lb          $t6, 0x1D8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D8);
    // 0x80052BD8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80052BDC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80052BE0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80052BE4: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
    // 0x80052BE8: bne         $t6, $zero, L_80052C10
    if (ctx->r14 != 0) {
        // 0x80052BEC: swc1        $f16, 0x2C($a1)
        MEM_W(0X2C, ctx->r5) = ctx->f16.u32l;
            goto L_80052C10;
    }
    // 0x80052BEC: swc1        $f16, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f16.u32l;
    // 0x80052BF0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80052BF4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80052BF8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80052BFC: jal         0x80072594
    // 0x80052C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    rumble_set(rdram, ctx);
        goto after_0;
    // 0x80052C00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80052C04: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80052C08: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80052C0C: nop

L_80052C10:
    // 0x80052C10: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052C14: lw          $t7, -0x2524($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2524);
    // 0x80052C18: lh          $v1, 0x1A2($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052C1C: bltz        $t7, L_80052C98
    if (SIGNED(ctx->r15) < 0) {
        // 0x80052C20: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80052C98;
    }
    // 0x80052C20: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80052C24: lw          $t8, -0x2EF8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2EF8);
    // 0x80052C28: nop

    // 0x80052C2C: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80052C30: beq         $at, $zero, L_80052C50
    if (ctx->r1 == 0) {
        // 0x80052C34: nop
    
            goto L_80052C50;
    }
    // 0x80052C34: nop

    // 0x80052C38: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80052C3C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80052C40: ori         $at, $at, 0xFC00
    ctx->r1 = ctx->r1 | 0XFC00;
    // 0x80052C44: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80052C48: b           L_80052C98
    // 0x80052C4C: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
        goto L_80052C98;
    // 0x80052C4C: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
L_80052C50:
    // 0x80052C50: lbu         $v0, 0x1DE($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1DE);
    // 0x80052C54: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80052C58: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80052C5C: beq         $at, $zero, L_80052C74
    if (ctx->r1 == 0) {
        // 0x80052C60: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_80052C74;
    }
    // 0x80052C60: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80052C64: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80052C68: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80052C6C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80052C70: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
L_80052C74:
    // 0x80052C74: lbu         $v0, 0x1DF($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1DF);
    // 0x80052C78: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80052C7C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80052C80: beq         $at, $zero, L_80052C98
    if (ctx->r1 == 0) {
        // 0x80052C84: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80052C98;
    }
    // 0x80052C84: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80052C88: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80052C8C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80052C90: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80052C94: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
L_80052C98:
    // 0x80052C98: lb          $v0, 0x1DB($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052C9C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80052CA0: blez        $v0, L_80052D0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80052CA4: addu        $t2, $t2, $a2
        ctx->r10 = ADD32(ctx->r10, ctx->r6);
            goto L_80052D0C;
    }
    // 0x80052CA4: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x80052CA8: lh          $t3, 0x1A2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052CAC: sll         $t2, $t2, 8
    ctx->r10 = S32(ctx->r10 << 8);
    // 0x80052CB0: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x80052CB4: sh          $t1, 0x1A2($a3)
    MEM_H(0X1A2, ctx->r7) = ctx->r9;
    // 0x80052CB8: lh          $t4, 0x1A2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052CBC: nop

    // 0x80052CC0: blez        $t4, L_80052D78
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80052CC4: nop
    
            goto L_80052D78;
    }
    // 0x80052CC4: nop

    // 0x80052CC8: bgez        $v1, L_80052D78
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80052CCC: nop
    
            goto L_80052D78;
    }
    // 0x80052CCC: nop

    // 0x80052CD0: lb          $t5, 0x1DB($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052CD4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052CD8: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80052CDC: sb          $t8, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = ctx->r24;
    // 0x80052CE0: lw          $t7, -0x254C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X254C);
    // 0x80052CE4: nop

    // 0x80052CE8: slti        $at, $t7, 0x33
    ctx->r1 = SIGNED(ctx->r15) < 0X33 ? 1 : 0;
    // 0x80052CEC: bne         $at, $zero, L_80052D78
    if (ctx->r1 != 0) {
        // 0x80052CF0: nop
    
            goto L_80052D78;
    }
    // 0x80052CF0: nop

    // 0x80052CF4: lb          $t6, 0x1DB($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052CF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052CFC: bne         $t6, $at, L_80052D78
    if (ctx->r14 != ctx->r1) {
        // 0x80052D00: nop
    
            goto L_80052D78;
    }
    // 0x80052D00: nop

    // 0x80052D04: b           L_80052D78
    // 0x80052D08: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
        goto L_80052D78;
    // 0x80052D08: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
L_80052D0C:
    // 0x80052D0C: bgez        $v0, L_80052D78
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80052D10: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_80052D78;
    }
    // 0x80052D10: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80052D14: lh          $t9, 0x1A2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052D18: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x80052D1C: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80052D20: subu        $t3, $t9, $t0
    ctx->r11 = SUB32(ctx->r25, ctx->r8);
    // 0x80052D24: sh          $t3, 0x1A2($a3)
    MEM_H(0X1A2, ctx->r7) = ctx->r11;
    // 0x80052D28: lh          $t2, 0x1A2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052D2C: nop

    // 0x80052D30: bgez        $t2, L_80052D78
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80052D34: nop
    
            goto L_80052D78;
    }
    // 0x80052D34: nop

    // 0x80052D38: blez        $v1, L_80052D78
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80052D3C: nop
    
            goto L_80052D78;
    }
    // 0x80052D3C: nop

    // 0x80052D40: lb          $t1, 0x1DB($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052D44: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80052D48: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80052D4C: sb          $t4, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = ctx->r12;
    // 0x80052D50: lw          $t5, -0x254C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X254C);
    // 0x80052D54: nop

    // 0x80052D58: slti        $at, $t5, -0x32
    ctx->r1 = SIGNED(ctx->r13) < -0X32 ? 1 : 0;
    // 0x80052D5C: beq         $at, $zero, L_80052D78
    if (ctx->r1 == 0) {
        // 0x80052D60: nop
    
            goto L_80052D78;
    }
    // 0x80052D60: nop

    // 0x80052D64: lb          $t8, 0x1DB($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052D68: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052D6C: bne         $t8, $at, L_80052D78
    if (ctx->r24 != ctx->r1) {
        // 0x80052D70: nop
    
            goto L_80052D78;
    }
    // 0x80052D70: nop

    // 0x80052D74: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
L_80052D78:
    // 0x80052D78: lh          $t7, 0x1A2($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052D7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D80: sw          $t7, -0x252C($at)
    MEM_W(-0X252C, ctx->r1) = ctx->r15;
    // 0x80052D84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D88: lwc1        $f4, -0x2514($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2514);
    // 0x80052D8C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80052D90: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80052D94: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80052D98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D9C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80052DA0: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80052DA4: sw          $zero, -0x254C($at)
    MEM_W(-0X254C, ctx->r1) = 0;
    // 0x80052DA8: sb          $zero, 0x1E1($a3)
    MEM_B(0X1E1, ctx->r7) = 0;
    // 0x80052DAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052DB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052DB4: jr          $ra
    // 0x80052DB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80052DB8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void read_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074828: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8007482C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074830: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074834: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x80074838: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007483C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074840: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80074844: jal         0x8006A340
    // 0x80074848: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074848: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007484C: jal         0x800CE770
    // 0x80074850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074850: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074854: bne         $v0, $zero, L_80074864
    if (ctx->r2 != 0) {
        // 0x80074858: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_80074864;
    }
    // 0x80074858: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x8007485C: b           L_80074930
    // 0x80074860: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074930;
    // 0x80074860: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074864:
    // 0x80074864: jal         0x80070EDC
    // 0x80074868: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074868: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x8007486C: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x80074870: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80074874: beq         $t7, $zero, L_800748C8
    if (ctx->r15 == 0) {
        // 0x80074878: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_800748C8;
    }
    // 0x80074878: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007487C: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80074880: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074884:
    // 0x80074884: jal         0x8006A340
    // 0x80074888: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x80074888: nop

    after_3:
    // 0x8007488C: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80074890: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80074894: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80074898: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x8007489C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x800748A0: jal         0x800CE7E0
    // 0x800748A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x800748A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800748A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800748AC: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800748B0: bne         $at, $zero, L_80074884
    if (ctx->r1 != 0) {
        // 0x800748B4: nop
    
            goto L_80074884;
    }
    // 0x800748B4: nop

    // 0x800748B8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800748BC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800748C0: jal         0x800737E0
    // 0x800748C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80073588(rdram, ctx);
        goto after_5;
    // 0x800748C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_800748C8:
    // 0x800748C8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800748CC: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x800748D0: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x800748D4: beq         $t1, $zero, L_80074924
    if (ctx->r9 == 0) {
        // 0x800748D8: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074924;
    }
    // 0x800748D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800748DC:
    // 0x800748DC: jal         0x8006A340
    // 0x800748E0: nop

    si_mesg(rdram, ctx);
        goto after_6;
    // 0x800748E0: nop

    after_6:
    // 0x800748E4: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x800748E8: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800748EC: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x800748F0: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x800748F4: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800748F8: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x800748FC: jal         0x800CE7E0
    // 0x80074900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_7;
    // 0x80074900: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x80074904: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074908: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x8007490C: bne         $at, $zero, L_800748DC
    if (ctx->r1 != 0) {
        // 0x80074910: nop
    
            goto L_800748DC;
    }
    // 0x80074910: nop

    // 0x80074914: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80074918: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8007491C: jal         0x800737E0
    // 0x80074920: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80073588(rdram, ctx);
        goto after_8;
    // 0x80074920: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
L_80074924:
    // 0x80074924: jal         0x80071380
    // 0x80074928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_9;
    // 0x80074928: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8007492C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80074930:
    // 0x80074930: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80074934: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074938: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007493C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074940: jr          $ra
    // 0x80074944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074944: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800304C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030508: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8003050C: lw          $a2, -0x29BC($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X29BC);
    // 0x80030510: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80030514: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x80030518: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8003051C: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80030520: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80030524: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80030528: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003052C: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x80030530: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80030534: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80030538: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x8003053C: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80030540: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030544: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80030548: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003054C: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80030550: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030554: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80030558: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003055C: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80030560: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030564: nop

    // 0x80030568: bc1f        L_80030574
    if (!c1cs) {
        // 0x8003056C: nop
    
            goto L_80030574;
    }
    // 0x8003056C: nop

    // 0x80030570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030574:
    // 0x80030574: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80030578: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8003057C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80030580: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80030584: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80030588: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8003058C: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80030590: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80030594: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80030598: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8003059C: nop

    // 0x800305A0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800305A4: sub.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x800305A8: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800305AC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800305B0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800305B4: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800305B8: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800305BC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x800305C0: nop

    // 0x800305C4: bc1f        L_800305D0
    if (!c1cs) {
        // 0x800305C8: nop
    
            goto L_800305D0;
    }
    // 0x800305C8: nop

    // 0x800305CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800305D0:
    // 0x800305D0: bne         $v0, $v1, L_8003069C
    if (ctx->r2 != ctx->r3) {
        // 0x800305D4: nop
    
            goto L_8003069C;
    }
    // 0x800305D4: nop

    // 0x800305D8: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800305DC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800305E0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800305E4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800305E8: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800305EC: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800305F0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800305F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800305F8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800305FC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030600: nop

    // 0x80030604: bc1f        L_80030610
    if (!c1cs) {
        // 0x80030608: nop
    
            goto L_80030610;
    }
    // 0x80030608: nop

    // 0x8003060C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80030610:
    // 0x80030610: bne         $v1, $a1, L_8003069C
    if (ctx->r3 != ctx->r5) {
        // 0x80030614: nop
    
            goto L_8003069C;
    }
    // 0x80030614: nop

    // 0x80030618: lw          $v0, -0x29C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29C4);
    // 0x8003061C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80030620: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80030624: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80030628: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8003062C: addiu       $v1, $v1, -0x29B0
    ctx->r3 = ADD32(ctx->r3, -0X29B0);
    // 0x80030630: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x80030634: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80030638: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003063C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80030640: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80030644: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80030648: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8003064C: nop

    // 0x80030650: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030654: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80030658: nop

    // 0x8003065C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80030660: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80030664: nop

    // 0x80030668: bc1f        L_8003069C
    if (!c1cs) {
        // 0x8003066C: nop
    
            goto L_8003069C;
    }
    // 0x8003066C: nop

    // 0x80030670: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80030674: nop

    // 0x80030678: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003067C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80030680: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80030684: nop

    // 0x80030688: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8003068C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80030690: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80030694: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80030698: nop

L_8003069C:
    // 0x8003069C: jr          $ra
    // 0x800306A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800306A0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B3A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B3AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B3B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B3B4: lb          $a3, 0x8($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X8);
    // 0x8003B3B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B3BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B3C0: bne         $a3, $at, L_8003B3DC
    if (ctx->r7 != ctx->r1) {
        // 0x8003B3C4: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B3DC;
    }
    // 0x8003B3C4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B3C8: jal         0x8000CC20
    // 0x8003B3CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B3CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B3D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3D4: b           L_8003B3F4
    // 0x8003B3D8: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
        goto L_8003B3F4;
    // 0x8003B3D8: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
L_8003B3DC:
    // 0x8003B3DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B3E0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B3E4: jal         0x8000CBF0
    // 0x8003B3E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B3E8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B3EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3F0: nop

L_8003B3F4:
    // 0x8003B3F4: lb          $t6, 0x8($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X8);
    // 0x8003B3F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B3FC: bne         $t6, $at, L_8003B418
    if (ctx->r14 != ctx->r1) {
        // 0x8003B400: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003B418;
    }
    // 0x8003B400: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B404: addiu       $a0, $a0, 0x6530
    ctx->r4 = ADD32(ctx->r4, 0X6530);
    // 0x8003B408: jal         0x800CA2B4
    // 0x8003B40C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B40C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B410: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B414: nop

L_8003B418:
    // 0x8003B418: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B41C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B420: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
    // 0x8003B424: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B428: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8003B42C: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
    // 0x8003B430: lw          $t2, 0x4C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B434: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003B438: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x8003B43C: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B440: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B444: sb          $zero, 0x12($t3)
    MEM_B(0X12, ctx->r11) = 0;
    // 0x8003B448: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B44C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B450: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003B454: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B458: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B45C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B460: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B464: nop

    // 0x8003B468: bc1f        L_8003B478
    if (!c1cs) {
        // 0x8003B46C: nop
    
            goto L_8003B478;
    }
    // 0x8003B46C: nop

    // 0x8003B470: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B474: nop

L_8003B478:
    // 0x8003B478: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B47C: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x8003B480: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003B484: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8003B488: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003B48C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003B490: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003B494: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003B498: sb          $t7, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r15;
    // 0x8003B49C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003B4A0: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003B4A4: lb          $t8, 0xA($a2)
    ctx->r24 = MEM_B(ctx->r6, 0XA);
    // 0x8003B4A8: nop

    // 0x8003B4AC: beq         $t8, $zero, L_8003B4F0
    if (ctx->r24 == 0) {
        // 0x8003B4B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B4F0;
    }
    // 0x8003B4B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B4B4: jal         0x8006ECD0
    // 0x8003B4B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x8003B4B8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8003B4BC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B4C0: lhu         $t9, 0x14($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14);
    // 0x8003B4C4: lb          $t0, 0xA($a2)
    ctx->r8 = MEM_B(ctx->r6, 0XA);
    // 0x8003B4C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003B4CC: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8003B4D0: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003B4D4: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x8003B4D8: beq         $t4, $zero, L_8003B4E8
    if (ctx->r12 == 0) {
        // 0x8003B4DC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003B4E8;
    }
    // 0x8003B4DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003B4E0: b           L_8003B4EC
    // 0x8003B4E4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
        goto L_8003B4EC;
    // 0x8003B4E4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003B4E8:
    // 0x8003B4E8: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003B4EC:
    // 0x8003B4EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B4F0:
    // 0x8003B4F0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4F4: jr          $ra
    // 0x8003B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003B4F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ghostmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009B0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009B0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009B0F0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009B0F4: jal         0x8009C9EC
    // 0x8009B0F8: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009B0F8: addiu       $a0, $a0, 0x1C88
    ctx->r4 = ADD32(ctx->r4, 0X1C88);
    after_0:
    // 0x8009B0FC: jal         0x800C478C
    // 0x8009B100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8009B100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8009B104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009B108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009B10C: jr          $ra
    // 0x8009B110: nop

    return;
    // 0x8009B110: nop

;}
RECOMP_FUNC void dmacopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077370: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077374: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80077378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007737C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80077380: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077384: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077388: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8007738C: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x80077390: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80077394: jal         0x800C9110
    // 0x80077398: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077398: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x8007739C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800773A0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800773A4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800773A8: jal         0x800773D4
    // 0x800773AC: nop

    dmacopy_v1(rdram, ctx);
        goto after_1;
    // 0x800773AC: nop

    after_1:
    // 0x800773B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800773B4: addiu       $a0, $a0, 0x4818
    ctx->r4 = ADD32(ctx->r4, 0X4818);
    // 0x800773B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800773BC: jal         0x800C9390
    // 0x800773C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800773C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800773C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800773C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800773CC: jr          $ra
    // 0x800773D0: nop

    return;
    // 0x800773D0: nop

;}
RECOMP_FUNC void compute_scene_camera_transform_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031058: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003105C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80031060: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x80031064: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031068: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003106C: lw          $v0, -0x49D0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X49D0);
    // 0x80031070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80031074: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80031078: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003107C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80031080: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80031084: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031088: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003108C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80031090: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031094: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
    // 0x80031098: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8003109C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x800310A0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x800310A4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800310A8: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x800310AC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800310B0: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x800310B4: jal         0x8006FE70
    // 0x800310B8: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x800310B8: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    after_0:
    // 0x800310BC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800310C0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800310C4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800310C8: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800310CC: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x800310D0: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x800310D4: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x800310D8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800310DC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800310E0: jal         0x8006F88C
    // 0x800310E4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x800310E4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x800310E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800310EC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800310F0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800310F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800310F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800310FC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80031100: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80031104: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80031108: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003110C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80031110: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x80031114: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80031118: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8003111C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80031120: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80031124: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80031128: addiu       $v0, $v0, -0x2618
    ctx->r2 = ADD32(ctx->r2, -0X2618);
    // 0x8003112C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80031130: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80031134: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80031138: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8003113C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80031140: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80031144: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80031148: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003114C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80031150: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80031154: nop

    // 0x80031158: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003115C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80031160: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80031164: jr          $ra
    // 0x80031168: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    return;
    // 0x80031168: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void savemenu_input_dest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087A54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087A58: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087A5C: beq         $t6, $zero, L_80087A80
    if (ctx->r14 == 0) {
        // 0x80087A60: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80087A80;
    }
    // 0x80087A60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087A64: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087A68: jal         0x80001D04
    // 0x80087A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087A6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80087A70: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80087A74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A78: b           L_80087B2C
    // 0x80087A7C: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
        goto L_80087B2C;
    // 0x80087A7C: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
L_80087A80:
    // 0x80087A80: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087A84: beq         $t8, $zero, L_80087AA4
    if (ctx->r24 == 0) {
        // 0x80087A88: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087AA4;
    }
    // 0x80087A88: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087A8C: jal         0x80001D04
    // 0x80087A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087A90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087A94: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80087A98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087A9C: b           L_80087B2C
    // 0x80087AA0: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
        goto L_80087B2C;
    // 0x80087AA0: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
L_80087AA4:
    // 0x80087AA4: bgez        $a1, L_80087AE4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087AA8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80087AE4;
    }
    // 0x80087AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087AAC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AB0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80087AB4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087AB8: blez        $t0, L_80087AE4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80087ABC: nop
    
            goto L_80087AE4;
    }
    // 0x80087ABC: nop

    // 0x80087AC0: jal         0x80001D04
    // 0x80087AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80087AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80087AC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087ACC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AD0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80087AD4: nop

    // 0x80087AD8: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80087ADC: b           L_80087B2C
    // 0x80087AE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_80087B2C;
    // 0x80087AE0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80087AE4:
    // 0x80087AE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087AE8: blez        $a1, L_80087B2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80087AEC: addiu       $v0, $v0, 0x71A4
        ctx->r2 = ADD32(ctx->r2, 0X71A4);
            goto L_80087B2C;
    }
    // 0x80087AEC: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087AF0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80087AF4: lw          $t4, 0x6FC0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6FC0);
    // 0x80087AF8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80087AFC: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80087B00: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80087B04: beq         $at, $zero, L_80087B2C
    if (ctx->r1 == 0) {
        // 0x80087B08: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80087B2C;
    }
    // 0x80087B08: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087B0C: jal         0x80001D04
    // 0x80087B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x80087B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80087B14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087B18: addiu       $v0, $v0, 0x71A4
    ctx->r2 = ADD32(ctx->r2, 0X71A4);
    // 0x80087B1C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80087B20: nop

    // 0x80087B24: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80087B28: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_80087B2C:
    // 0x80087B2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087B34: jr          $ra
    // 0x80087B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void set_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C492C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C4930: addiu       $v0, $v0, -0x5258
    ctx->r2 = ADD32(ctx->r2, -0X5258);
    // 0x800C4934: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C4938: nop

    // 0x800C493C: sb          $a0, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r4;
    // 0x800C4940: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C4944: nop

    // 0x800C4948: sb          $a1, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r5;
    // 0x800C494C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C4950: nop

    // 0x800C4954: sb          $a2, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r6;
    // 0x800C4958: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C495C: jr          $ra
    // 0x800C4960: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
    return;
    // 0x800C4960: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
;}
RECOMP_FUNC void spawn_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EA54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000EA58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000EA5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000EA60: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000EA64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EA68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EA6C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8000EA70: jal         0x8006ECD0
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000EA78: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8000EA7C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000EA80: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8000EA84: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8000EA88: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8000EA8C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000EA90: or          $a1, $t6, $t9
    ctx->r5 = ctx->r14 | ctx->r25;
    // 0x8000EA94: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000EA98: jal         0x800B7BD8
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    update_object_stack_trace(rdram, ctx);
        goto after_1;
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8000EAA0: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EAA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000EAA8: andi        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 & 0X2;
    // 0x8000EAAC: beq         $t0, $zero, L_8000EAC0
    if (ctx->r8 == 0) {
        // 0x8000EAB0: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8000EAC0;
    }
    // 0x8000EAB0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000EAB4: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EAB8: b           L_8000EAE0
    // 0x8000EABC: nop

        goto L_8000EAE0;
    // 0x8000EABC: nop

L_8000EAC0:
    // 0x8000EAC0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8000EAC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EAC8: lw          $t1, -0x4BC8($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X4BC8);
    // 0x8000EACC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000EAD0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EAD4: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x8000EAD8: nop

    // 0x8000EADC: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
L_8000EAE0:
    // 0x8000EAE0: lw          $t7, -0x4D18($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4D18);
    // 0x8000EAE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000EAE8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000EAEC: bne         $at, $zero, L_8000EAF8
    if (ctx->r1 != 0) {
        // 0x8000EAF0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000EAF8;
    }
    // 0x8000EAF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EAF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000EAF8:
    // 0x8000EAF8: addiu       $v0, $v0, -0x4D28
    ctx->r2 = ADD32(ctx->r2, -0X4D28);
L_8000EAFC:
    // 0x8000EAFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB00: nop

    // 0x8000EB04: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EB08: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EB0C: slti        $at, $s0, 0x800
    ctx->r1 = SIGNED(ctx->r16) < 0X800 ? 1 : 0;
    // 0x8000EB10: bne         $at, $zero, L_8000EAFC
    if (ctx->r1 != 0) {
        // 0x8000EB14: sw          $zero, 0x0($t6)
        MEM_W(0X0, ctx->r14) = 0;
            goto L_8000EAFC;
    }
    // 0x8000EB14: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8000EB18: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB1C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000EB20: sh          $t9, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r25;
    // 0x8000EB24: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
    // 0x8000EB28: jal         0x8000C718
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_object_header(rdram, ctx);
        goto after_2;
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8000EB30: bne         $v0, $zero, L_8000EB40
    if (ctx->r2 != 0) {
        // 0x8000EB34: sw          $v0, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->r2;
            goto L_8000EB40;
    }
    // 0x8000EB34: sw          $v0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r2;
    // 0x8000EB38: b           L_8000F62C
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EB40:
    // 0x8000EB40: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB44: nop

    // 0x8000EB48: lhu         $t0, 0x30($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X30);
    // 0x8000EB4C: nop

    // 0x8000EB50: andi        $t2, $t0, 0x80
    ctx->r10 = ctx->r8 & 0X80;
    // 0x8000EB54: beq         $t2, $zero, L_8000EB6C
    if (ctx->r10 == 0) {
        // 0x8000EB58: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB58: nop

    // 0x8000EB5C: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8000EB60: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB64: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x8000EB68: sh          $t3, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r11;
L_8000EB6C:
    // 0x8000EB6C: lb          $t4, 0x54($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X54);
    // 0x8000EB70: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8000EB74: bne         $t4, $at, L_8000EBA4
    if (ctx->r12 != ctx->r1) {
        // 0x8000EB78: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB78: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB7C: lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X10);
    // 0x8000EB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000EB84: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8000EB88: beq         $t7, $zero, L_8000EBA4
    if (ctx->r15 == 0) {
        // 0x8000EB8C: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB8C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB90: jal         0x800B7BD8
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_3;
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8000EB98: b           L_8000F62C
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000EBA0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_8000EBA4:
    // 0x8000EBA4: nop

    // 0x8000EBA8: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000EBAC: nop

    // 0x8000EBB0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000EBB4: nop

    // 0x8000EBB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EBBC: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x8000EBC0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000EBC4: lwc1        $f12, 0xC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000EBC8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8000EBCC: nop

    // 0x8000EBD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EBD4: swc1        $f10, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f10.u32l;
    // 0x8000EBD8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8000EBDC: lwc1        $f14, 0x10($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000EBE0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000EBE4: nop

    // 0x8000EBE8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000EBEC: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
    // 0x8000EBF0: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x8000EBF4: jal         0x80029F58
    // 0x8000EBF8: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x8000EBF8: nop

    after_4:
    // 0x8000EBFC: sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // 0x8000EC00: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x8000EC04: nop

    // 0x8000EC08: sh          $t0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r8;
    // 0x8000EC0C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8000EC10: nop

    // 0x8000EC14: sw          $t2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r10;
    // 0x8000EC18: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8000EC1C: nop

    // 0x8000EC20: sh          $t1, 0x4A($s2)
    MEM_H(0X4A, ctx->r18) = ctx->r9;
    // 0x8000EC24: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EC28: jal         0x800245E8
    // 0x8000EC2C: nop

    func_800245B4(rdram, ctx);
        goto after_5;
    // 0x8000EC2C: nop

    after_5:
    // 0x8000EC30: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC34: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000EC38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000EC3C: nop

    // 0x8000EC40: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x8000EC44: lh          $t3, 0x50($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X50);
    // 0x8000EC48: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000EC4C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8000EC50: sb          $t4, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r12;
    // 0x8000EC54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EC58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000EC5C: swc1        $f16, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f16.u32l;
    // 0x8000EC60: lb          $a0, 0x54($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X54);
    // 0x8000EC64: jal         0x80023E64
    // 0x8000EC68: nop

    obj_init_property_flags(rdram, ctx);
        goto after_6;
    // 0x8000EC68: nop

    after_6:
    // 0x8000EC6C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8000EC70: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC74: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EC78: lb          $t5, 0x52($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X52);
    // 0x8000EC7C: addiu       $t6, $s2, 0x80
    ctx->r14 = ADD32(ctx->r18, 0X80);
    // 0x8000EC80: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000EC84: sb          $t7, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r15;
    // 0x8000EC88: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC8C: andi        $t9, $a3, 0x10
    ctx->r25 = ctx->r7 & 0X10;
    // 0x8000EC90: lb          $t8, 0x53($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X53);
    // 0x8000EC94: lb          $s3, 0x55($s0)
    ctx->r19 = MEM_B(ctx->r16, 0X55);
    // 0x8000EC98: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8000EC9C: beq         $t9, $zero, L_8000ECA8
    if (ctx->r25 == 0) {
        // 0x8000ECA0: sw          $t6, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->r14;
            goto L_8000ECA8;
    }
    // 0x8000ECA0: sw          $t6, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r14;
    // 0x8000ECA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000ECA8:
    // 0x8000ECA8: lb          $t0, 0x54($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X54);
    // 0x8000ECAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ECB0: addiu       $t2, $t0, -0x3E
    ctx->r10 = ADD32(ctx->r8, -0X3E);
    // 0x8000ECB4: sltiu       $at, $t2, 0x27
    ctx->r1 = ctx->r10 < 0X27 ? 1 : 0;
    // 0x8000ECB8: beq         $at, $zero, L_8000EDE0
    if (ctx->r1 == 0) {
        // 0x8000ECBC: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8000EDE0;
    }
    // 0x8000ECBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000ECC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000ECC4: addu        $at, $at, $t2
    gpr jr_addend_8000ECD0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8000ECC8: lw          $t2, 0x5744($at)
    ctx->r10 = ADD32(ctx->r1, 0X5744);
    // 0x8000ECCC: nop

    // 0x8000ECD0: jr          $t2
    // 0x8000ECD4: nop

    switch (jr_addend_8000ECD0 >> 2) {
        case 0: goto L_8000ECD8; break;
        case 1: goto L_8000EDE0; break;
        case 2: goto L_8000EDE0; break;
        case 3: goto L_8000EDE0; break;
        case 4: goto L_8000EDE0; break;
        case 5: goto L_8000EDE0; break;
        case 6: goto L_8000EDE0; break;
        case 7: goto L_8000EDE0; break;
        case 8: goto L_8000EDE0; break;
        case 9: goto L_8000EDE0; break;
        case 10: goto L_8000EDE0; break;
        case 11: goto L_8000EDE0; break;
        case 12: goto L_8000EDE0; break;
        case 13: goto L_8000EDE0; break;
        case 14: goto L_8000EDE0; break;
        case 15: goto L_8000ED98; break;
        case 16: goto L_8000EDE0; break;
        case 17: goto L_8000EDE0; break;
        case 18: goto L_8000EDE0; break;
        case 19: goto L_8000EDE0; break;
        case 20: goto L_8000EDE0; break;
        case 21: goto L_8000EDE0; break;
        case 22: goto L_8000EDE0; break;
        case 23: goto L_8000EDE0; break;
        case 24: goto L_8000ECF4; break;
        case 25: goto L_8000EDE0; break;
        case 26: goto L_8000EDE0; break;
        case 27: goto L_8000EDE0; break;
        case 28: goto L_8000EDE0; break;
        case 29: goto L_8000ED10; break;
        case 30: goto L_8000EDE0; break;
        case 31: goto L_8000EDE0; break;
        case 32: goto L_8000EDE0; break;
        case 33: goto L_8000ED40; break;
        case 34: goto L_8000EDE0; break;
        case 35: goto L_8000EDE0; break;
        case 36: goto L_8000EDE0; break;
        case 37: goto L_8000EDE0; break;
        case 38: goto L_8000ED54; break;
        default: switch_error(__func__, 0x8000ECD0, 0x800E5744);
    }
    // 0x8000ECD4: nop

L_8000ECD8:
    // 0x8000ECD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000ECDC: jal         0x80061C34
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_7:
    // 0x8000ECE4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000ECE8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ECEC: b           L_8000EDE4
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_8000EDE4;
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000ECF4:
    // 0x8000ECF4: jal         0x8009C76C
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_8;
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8000ECFC: sb          $v0, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r2;
    // 0x8000ED00: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ED04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000ED08: b           L_8000EDE0
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
        goto L_8000EDE0;
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
L_8000ED10:
    // 0x8000ED10: lbu         $t3, 0x48($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X48);
    // 0x8000ED14: lhu         $t1, 0xE($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED18: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000ED1C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000ED20: srav        $a2, $t1, $t5
    ctx->r6 = S32(SIGNED(ctx->r9) >> (ctx->r13 & 31));
    // 0x8000ED24: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8000ED28: beq         $t7, $zero, L_8000EDE0
    if (ctx->r15 == 0) {
        // 0x8000ED2C: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8000EDE0;
    }
    // 0x8000ED2C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000ED30: addiu       $a2, $t7, -0x1
    ctx->r6 = ADD32(ctx->r15, -0X1);
    // 0x8000ED34: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED38: b           L_8000EDE0
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED40:
    // 0x8000ED40: lbu         $a2, 0x17($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X17);
    // 0x8000ED44: nop

    // 0x8000ED48: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED4C: b           L_8000EDE0
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED54:
    // 0x8000ED54: lhu         $t8, 0xE($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000ED5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000ED60: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_8000ED64:
    // 0x8000ED64: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED68: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED6C: andi        $t9, $t6, 0x3
    ctx->r25 = ctx->r14 & 0X3;
    // 0x8000ED70: bne         $v0, $t9, L_8000ED7C
    if (ctx->r2 != ctx->r25) {
        // 0x8000ED74: sra         $t2, $t0, 2
        ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8000ED7C;
    }
    // 0x8000ED74: sra         $t2, $t0, 2
    ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8000ED78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8000ED7C:
    // 0x8000ED7C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000ED80: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8000ED84: bne         $at, $zero, L_8000ED64
    if (ctx->r1 != 0) {
        // 0x8000ED88: sw          $t2, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r10;
            goto L_8000ED64;
    }
    // 0x8000ED88: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x8000ED8C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
    // 0x8000ED90: b           L_8000EDE0
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
        goto L_8000EDE0;
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
L_8000ED98:
    // 0x8000ED98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000ED9C: jal         0x8009F1B4
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_9;
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_9:
    // 0x8000EDA4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EDA8: beq         $v0, $zero, L_8000EDCC
    if (ctx->r2 == 0) {
        // 0x8000EDAC: nop
    
            goto L_8000EDCC;
    }
    // 0x8000EDAC: nop

    // 0x8000EDB0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDB4: nop

    // 0x8000EDB8: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
    // 0x8000EDBC: nop

    // 0x8000EDC0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8000EDC4: nop

    // 0x8000EDC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8000EDCC:
    // 0x8000EDCC: lw          $t5, 0x40($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000EDD4: sb          $t1, 0x55($t5)
    MEM_B(0X55, ctx->r13) = ctx->r9;
    // 0x8000EDD8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EDDC: nop

L_8000EDE0:
    // 0x8000EDE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000EDE4:
    // 0x8000EDE4: nop

    // 0x8000EDE8: bne         $t7, $zero, L_8000EF18
    if (ctx->r15 != 0) {
        // 0x8000EDEC: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EDEC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EDF0: lh          $v0, 0x4A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4A);
    // 0x8000EDF4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8000EDF8: beq         $v0, $at, L_8000EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8000EDFC: addiu       $at, $zero, 0xCB
        ctx->r1 = ADD32(0, 0XCB);
            goto L_8000EE54;
    }
    // 0x8000EDFC: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8000EE00: bne         $v0, $at, L_8000EF18
    if (ctx->r2 != ctx->r1) {
        // 0x8000EE04: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EE04: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EE08: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000EE0C: jal         0x8009F1B4
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_10;
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_10:
    // 0x8000EE14: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EE18: beq         $v0, $zero, L_8000EE3C
    if (ctx->r2 == 0) {
        // 0x8000EE1C: nop
    
            goto L_8000EE3C;
    }
    // 0x8000EE1C: nop

    // 0x8000EE20: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE24: nop

    // 0x8000EE28: lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X10);
    // 0x8000EE2C: nop

    // 0x8000EE30: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000EE34: nop

    // 0x8000EE38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000EE3C:
    // 0x8000EE3C: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000EE44: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    // 0x8000EE48: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EE4C: b           L_8000EF18
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
        goto L_8000EF18;
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EE54:
    // 0x8000EE54: jal         0x8009F1B4
    // 0x8000EE58: nop

    is_in_adventure_two(rdram, ctx);
        goto after_11;
    // 0x8000EE58: nop

    after_11:
    // 0x8000EE5C: beq         $v0, $zero, L_8000EF00
    if (ctx->r2 == 0) {
        // 0x8000EE60: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_8000EF00;
    }
    // 0x8000EE60: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8000EE64: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000EE6C: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x8000EE70: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000EE74: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE78: nop

    // 0x8000EE7C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000EE80: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE84: nop

    // 0x8000EE88: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000EE8C: nop

    // 0x8000EE90: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x8000EE94: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE98: nop

    // 0x8000EE9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000EEA0: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEA4: nop

    // 0x8000EEA8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8000EEAC: nop

    // 0x8000EEB0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EEB4: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8000EEB8: nop

    // 0x8000EEBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000EEC0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEC4: nop

    // 0x8000EEC8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8000EECC: nop

    // 0x8000EED0: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x8000EED4: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x8000EED8: nop

    // 0x8000EEDC: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8000EEE0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEE4: nop

    // 0x8000EEE8: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8000EEEC: nop

    // 0x8000EEF0: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x8000EEF4: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x8000EEF8: nop

    // 0x8000EEFC: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_8000EF00:
    // 0x8000EF00: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF04: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000EF08: sb          $t5, 0x55($t7)
    MEM_B(0X55, ctx->r15) = ctx->r13;
    // 0x8000EF0C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000EF14: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EF18:
    // 0x8000EF18: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8000EF1C: bne         $t8, $zero, L_8000EFEC
    if (ctx->r24 != 0) {
        // 0x8000EF20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000EFEC;
    }
    // 0x8000EF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000EF24: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EF28: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EF2C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EF2C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000EF30:
    // 0x8000EF30: bne         $a2, $zero, L_8000EF58
    if (ctx->r6 != 0) {
        // 0x8000EF34: addiu       $s1, $a2, 0x1
        ctx->r17 = ADD32(ctx->r6, 0X1);
            goto L_8000EF58;
    }
    // 0x8000EF34: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000EF38: andi        $t6, $a3, 0x4
    ctx->r14 = ctx->r7 & 0X4;
    // 0x8000EF3C: beq         $t6, $zero, L_8000EF5C
    if (ctx->r14 == 0) {
        // 0x8000EF40: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000EF5C;
    }
    // 0x8000EF40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EF44: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF48: nop

    // 0x8000EF4C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EF50: b           L_8000EFD0
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_8000EFD0;
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8000EF58:
    // 0x8000EF58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8000EF5C:
    // 0x8000EF5C: bne         $a2, $at, L_8000EF80
    if (ctx->r6 != ctx->r1) {
        // 0x8000EF60: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_8000EF80;
    }
    // 0x8000EF60: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x8000EF64: beq         $t2, $zero, L_8000EF80
    if (ctx->r10 == 0) {
        // 0x8000EF68: nop
    
            goto L_8000EF80;
    }
    // 0x8000EF68: nop

    // 0x8000EF6C: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF70: nop

    // 0x8000EF74: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000EF78: b           L_8000EFD0
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_8000EFD0;
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8000EF80:
    // 0x8000EF80: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF84: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8000EF88: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x8000EF8C: nop

    // 0x8000EF90: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8000EF94: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8000EF98: jal         0x8005FB3C
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    object_model_init(rdram, ctx);
        goto after_12;
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_12:
    // 0x8000EFA0: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFA4: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000EFA8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EFAC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000EFB0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFB4: nop

    // 0x8000EFB8: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EFBC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000EFC0: nop

    // 0x8000EFC4: bne         $t2, $zero, L_8000EFD4
    if (ctx->r10 != 0) {
        // 0x8000EFC8: lw          $a3, 0x6C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X6C);
            goto L_8000EFD4;
    }
    // 0x8000EFC8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EFCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000EFD0:
    // 0x8000EFD0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
L_8000EFD4:
    // 0x8000EFD4: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFD8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000EFDC: bne         $at, $zero, L_8000EF30
    if (ctx->r1 != 0) {
        // 0x8000EFE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000EF30;
    }
    // 0x8000EFE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EFE4: b           L_8000F0C4
    // 0x8000EFE8: nop

        goto L_8000F0C4;
    // 0x8000EFE8: nop

L_8000EFEC:
    // 0x8000EFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000EFF0: bne         $t3, $at, L_8000F060
    if (ctx->r11 != ctx->r1) {
        // 0x8000EFF4: slt         $at, $a2, $s3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8000F060;
    }
    // 0x8000EFF4: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFF8: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EFFC: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EFFC: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F000:
    // 0x8000F000: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000F004: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F008: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000F00C: nop

    // 0x8000F010: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F014: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8000F018: jal         0x8007B2C4
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_13;
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_13:
    // 0x8000F020: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F024: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F028: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F02C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000F030: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8000F034: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F038: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F03C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000F040: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F044: bne         $t0, $zero, L_8000F050
    if (ctx->r8 != 0) {
        // 0x8000F048: nop
    
            goto L_8000F050;
    }
    // 0x8000F048: nop

    // 0x8000F04C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F050:
    // 0x8000F050: bne         $at, $zero, L_8000F000
    if (ctx->r1 != 0) {
        // 0x8000F054: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F000;
    }
    // 0x8000F054: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F058: b           L_8000F0C4
    // 0x8000F05C: nop

        goto L_8000F0C4;
    // 0x8000F05C: nop

L_8000F060:
    // 0x8000F060: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F064: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000F068: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000F068: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F06C:
    // 0x8000F06C: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000F070: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000F074: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8000F078: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F07C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000F080: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000F084: jal         0x8007C57C
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    tex_load_sprite(rdram, ctx);
        goto after_14;
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_14:
    // 0x8000F08C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000F090: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F094: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F098: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000F09C: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F0A4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F0A8: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000F0AC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F0B0: bne         $t6, $zero, L_8000F0BC
    if (ctx->r14 != 0) {
        // 0x8000F0B4: nop
    
            goto L_8000F0BC;
    }
    // 0x8000F0B4: nop

    // 0x8000F0B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F0BC:
    // 0x8000F0BC: bne         $at, $zero, L_8000F06C
    if (ctx->r1 != 0) {
        // 0x8000F0C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F06C;
    }
    // 0x8000F0C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F0C4:
    // 0x8000F0C4: beq         $v1, $zero, L_8000F0EC
    if (ctx->r3 == 0) {
        // 0x8000F0C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F0EC;
    }
    // 0x8000F0C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0CC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F0D0: jal         0x8000F648
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_15;
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x8000F0D8: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F0DC: jal         0x8000C844
    // 0x8000F0E0: nop

    try_free_object_header(rdram, ctx);
        goto after_16;
    // 0x8000F0E0: nop

    after_16:
    // 0x8000F0E4: b           L_8000F62C
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F0EC:
    // 0x8000F0EC: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000F0F0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0F4: lb          $t2, 0x55($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X55);
    // 0x8000F0F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0FC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000F100: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    // 0x8000F104: jal         0x80023610
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    get_object_property_size(rdram, ctx);
        goto after_17;
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_17:
    // 0x8000F10C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000F110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F114: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F118: sw          $zero, -0x4C30($at)
    MEM_W(-0X4C30, ctx->r1) = 0;
    // 0x8000F11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F120: andi        $t1, $t4, 0x1
    ctx->r9 = ctx->r12 & 0X1;
    // 0x8000F124: sw          $zero, -0x4C2C($at)
    MEM_W(-0X4C2C, ctx->r1) = 0;
    // 0x8000F128: beq         $t1, $zero, L_8000F14C
    if (ctx->r9 == 0) {
        // 0x8000F12C: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F14C;
    }
    // 0x8000F12C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F134: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F138: jal         0x8000F7EC
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shading(rdram, ctx);
        goto after_18;
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_18:
    // 0x8000F140: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F144: nop

    // 0x8000F148: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F14C:
    // 0x8000F14C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000F150: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F154: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x8000F158: beq         $t7, $zero, L_8000F198
    if (ctx->r15 == 0) {
        // 0x8000F15C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F198;
    }
    // 0x8000F15C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F160: jal         0x8000FBCC
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shadow(rdram, ctx);
        goto after_19;
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_19:
    // 0x8000F168: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F16C: bne         $v0, $zero, L_8000F198
    if (ctx->r2 != 0) {
        // 0x8000F170: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F198;
    }
    // 0x8000F170: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F174: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F17C: jal         0x8000F648
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_20;
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000F184: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F188: jal         0x8000C844
    // 0x8000F18C: nop

    try_free_object_header(rdram, ctx);
        goto after_21;
    // 0x8000F18C: nop

    after_21:
    // 0x8000F190: b           L_8000F62C
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F198:
    // 0x8000F198: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8000F19C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1A0: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x8000F1A4: beq         $t6, $zero, L_8000F200
    if (ctx->r14 == 0) {
        // 0x8000F1A8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F200;
    }
    // 0x8000F1A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F1AC: jal         0x8000FC6C
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_water_effect(rdram, ctx);
        goto after_22;
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_22:
    // 0x8000F1B4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F1B8: bne         $v0, $zero, L_8000F200
    if (ctx->r2 != 0) {
        // 0x8000F1BC: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F200;
    }
    // 0x8000F1BC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F1C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F1C4: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F1C8: nop

    // 0x8000F1CC: beq         $v0, $zero, L_8000F1E0
    if (ctx->r2 == 0) {
        // 0x8000F1D0: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F1E0;
    }
    // 0x8000F1D0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F1D4: jal         0x8007B70C
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_23;
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8000F1DC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F1E0:
    // 0x8000F1E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1E4: jal         0x8000F648
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_24;
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_24:
    // 0x8000F1EC: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F1F0: jal         0x8000C844
    // 0x8000F1F4: nop

    try_free_object_header(rdram, ctx);
        goto after_25;
    // 0x8000F1F4: nop

    after_25:
    // 0x8000F1F8: b           L_8000F62C
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F200:
    // 0x8000F200: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8000F204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F208: andi        $t2, $t0, 0x10
    ctx->r10 = ctx->r8 & 0X10;
    // 0x8000F20C: beq         $t2, $zero, L_8000F228
    if (ctx->r10 == 0) {
        // 0x8000F210: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F228;
    }
    // 0x8000F210: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F214: jal         0x8000FD20
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_interaction_data(rdram, ctx);
        goto after_26;
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_26:
    // 0x8000F21C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F220: nop

    // 0x8000F224: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F228:
    // 0x8000F228: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8000F22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F230: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x8000F234: beq         $t3, $zero, L_8000F250
    if (ctx->r11 == 0) {
        // 0x8000F238: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F250;
    }
    // 0x8000F238: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F23C: jal         0x8000FD34
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_collision(rdram, ctx);
        goto after_27;
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_27:
    // 0x8000F244: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F248: nop

    // 0x8000F24C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F250:
    // 0x8000F250: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F254: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F258: lb          $v0, 0x56($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X56);
    // 0x8000F25C: nop

    // 0x8000F260: blez        $v0, L_8000F27C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F264: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F27C;
    }
    // 0x8000F264: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F268: beq         $at, $zero, L_8000F27C
    if (ctx->r1 == 0) {
        // 0x8000F26C: nop
    
            goto L_8000F27C;
    }
    // 0x8000F26C: nop

    // 0x8000F270: sw          $a2, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r6;
    // 0x8000F274: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F278: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
L_8000F27C:
    // 0x8000F27C: lb          $t4, 0x57($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X57);
    // 0x8000F280: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F284: blez        $t4, L_8000F2A0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000F288: nop
    
            goto L_8000F2A0;
    }
    // 0x8000F288: nop

    // 0x8000F28C: jal         0x8000FAC4
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_emitter(rdram, ctx);
        goto after_28;
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_28:
    // 0x8000F294: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F298: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F29C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F2A0:
    // 0x8000F2A0: lb          $t1, 0x5A($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000F2A8: blez        $t1, L_8000F2C8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F2AC: subu        $a1, $a2, $s2
        ctx->r5 = SUB32(ctx->r6, ctx->r18);
            goto L_8000F2C8;
    }
    // 0x8000F2AC: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
    // 0x8000F2B0: sw          $a2, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r6;
    // 0x8000F2B4: lb          $t5, 0x5A($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2B8: nop

    // 0x8000F2BC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000F2C0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8000F2C4: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
L_8000F2C8:
    // 0x8000F2C8: lw          $a0, -0x4C18($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4C18);
    // 0x8000F2CC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000F2D0: jal         0x800710D0
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    mempool_alloc_pool(rdram, ctx);
        goto after_29;
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_29:
    // 0x8000F2D8: bne         $v0, $zero, L_8000F33C
    if (ctx->r2 != 0) {
        // 0x8000F2DC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000F33C;
    }
    // 0x8000F2DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000F2E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F2E4: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F2E8: nop

    // 0x8000F2EC: beq         $v0, $zero, L_8000F2FC
    if (ctx->r2 == 0) {
        // 0x8000F2F0: nop
    
            goto L_8000F2FC;
    }
    // 0x8000F2F0: nop

    // 0x8000F2F4: jal         0x8007B70C
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_30;
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
L_8000F2FC:
    // 0x8000F2FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F300: lw          $v0, -0x4C2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C2C);
    // 0x8000F304: nop

    // 0x8000F308: beq         $v0, $zero, L_8000F31C
    if (ctx->r2 == 0) {
        // 0x8000F30C: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F31C;
    }
    // 0x8000F30C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F310: jal         0x8007B70C
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_31;
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x8000F318: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F31C:
    // 0x8000F31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F320: jal         0x8000F648
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_32;
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x8000F328: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F32C: jal         0x8000C844
    // 0x8000F330: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x8000F330: nop

    after_33:
    // 0x8000F334: b           L_8000F62C
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F33C:
    // 0x8000F33C: andi        $t8, $s1, 0xF
    ctx->r24 = ctx->r17 & 0XF;
    // 0x8000F340: beq         $t8, $zero, L_8000F354
    if (ctx->r24 == 0) {
        // 0x8000F344: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F354;
    }
    // 0x8000F344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F348: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000F34C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x8000F350: addiu       $s1, $t6, 0x10
    ctx->r17 = ADD32(ctx->r14, 0X10);
L_8000F354:
    // 0x8000F354: sra         $t0, $s1, 2
    ctx->r8 = S32(SIGNED(ctx->r17) >> 2);
    // 0x8000F358: blez        $t0, L_8000F390
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F35C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F390;
    }
    // 0x8000F35C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000F360: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F364: addiu       $a1, $a1, -0x4D28
    ctx->r5 = ADD32(ctx->r5, -0X4D28);
    // 0x8000F368: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x8000F36C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
L_8000F370:
    // 0x8000F370: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F374: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000F378: addu        $t9, $t2, $s0
    ctx->r25 = ADD32(ctx->r10, ctx->r16);
    // 0x8000F37C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8000F380: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F384: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000F388: bne         $at, $zero, L_8000F370
    if (ctx->r1 != 0) {
        // 0x8000F38C: sw          $t3, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r11;
            goto L_8000F370;
    }
    // 0x8000F38C: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
L_8000F390:
    // 0x8000F390: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x8000F394: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F398: beq         $v1, $zero, L_8000F3B0
    if (ctx->r3 == 0) {
        // 0x8000F39C: addiu       $a1, $a1, -0x4D28
        ctx->r5 = ADD32(ctx->r5, -0X4D28);
            goto L_8000F3B0;
    }
    // 0x8000F39C: addiu       $a1, $a1, -0x4D28
    ctx->r5 = ADD32(ctx->r5, -0X4D28);
    // 0x8000F3A0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3A4: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3A8: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x8000F3AC: sw          $t5, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r13;
L_8000F3B0:
    // 0x8000F3B0: lw          $v1, 0x50($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X50);
    // 0x8000F3B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F3B8: beq         $v1, $zero, L_8000F3D0
    if (ctx->r3 == 0) {
        // 0x8000F3BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F3D0;
    }
    // 0x8000F3BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F3C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3C4: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3C8: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F3CC: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
L_8000F3D0:
    // 0x8000F3D0: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x8000F3D4: nop

    // 0x8000F3D8: beq         $v1, $zero, L_8000F3F0
    if (ctx->r3 == 0) {
        // 0x8000F3DC: nop
    
            goto L_8000F3F0;
    }
    // 0x8000F3DC: nop

    // 0x8000F3E0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3E4: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3E8: subu        $t9, $t0, $t2
    ctx->r25 = SUB32(ctx->r8, ctx->r10);
    // 0x8000F3EC: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
L_8000F3F0:
    // 0x8000F3F0: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000F3F4: nop

    // 0x8000F3F8: beq         $v1, $zero, L_8000F410
    if (ctx->r3 == 0) {
        // 0x8000F3FC: nop
    
            goto L_8000F410;
    }
    // 0x8000F3FC: nop

    // 0x8000F400: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8000F404: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F408: subu        $t1, $t3, $t4
    ctx->r9 = SUB32(ctx->r11, ctx->r12);
    // 0x8000F40C: sw          $t1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r9;
L_8000F410:
    // 0x8000F410: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8000F414: nop

    // 0x8000F418: beq         $v1, $zero, L_8000F430
    if (ctx->r3 == 0) {
        // 0x8000F41C: nop
    
            goto L_8000F430;
    }
    // 0x8000F41C: nop

    // 0x8000F420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000F424: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F428: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8000F42C: sw          $t8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r24;
L_8000F430:
    // 0x8000F430: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8000F434: nop

    // 0x8000F438: beq         $v1, $zero, L_8000F450
    if (ctx->r3 == 0) {
        // 0x8000F43C: nop
    
            goto L_8000F450;
    }
    // 0x8000F43C: nop

    // 0x8000F440: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8000F444: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F448: subu        $t2, $t6, $t0
    ctx->r10 = SUB32(ctx->r14, ctx->r8);
    // 0x8000F44C: sw          $t2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r10;
L_8000F450:
    // 0x8000F450: lw          $v1, 0x60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X60);
    // 0x8000F454: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F458: beq         $v1, $zero, L_8000F470
    if (ctx->r3 == 0) {
        // 0x8000F45C: addiu       $s0, $s0, -0x4C24
        ctx->r16 = ADD32(ctx->r16, -0X4C24);
            goto L_8000F470;
    }
    // 0x8000F45C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    // 0x8000F460: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F464: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F468: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F46C: sw          $t4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r12;
L_8000F470:
    // 0x8000F470: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F474: nop

    // 0x8000F478: lb          $t1, 0x57($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X57);
    // 0x8000F47C: nop

    // 0x8000F480: blez        $t1, L_8000F4A0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F484: nop
    
            goto L_8000F4A0;
    }
    // 0x8000F484: nop

    // 0x8000F488: lw          $t5, 0x6C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X6C);
    // 0x8000F48C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F490: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x8000F494: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F498: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F49C: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
L_8000F4A0:
    // 0x8000F4A0: lb          $t0, 0x5A($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X5A);
    // 0x8000F4A4: addiu       $t1, $v0, 0x80
    ctx->r9 = ADD32(ctx->r2, 0X80);
    // 0x8000F4A8: blez        $t0, L_8000F4C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F4AC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8000F4C4;
    }
    // 0x8000F4AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000F4B0: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8000F4B4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F4B8: addu        $t9, $v0, $t2
    ctx->r25 = ADD32(ctx->r2, ctx->r10);
    // 0x8000F4BC: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F4C0: sw          $t4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r12;
L_8000F4C4:
    // 0x8000F4C4: sw          $t1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r9;
    // 0x8000F4C8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8000F4CC: nop

    // 0x8000F4D0: andi        $t5, $s1, 0x1
    ctx->r13 = ctx->r17 & 0X1;
    // 0x8000F4D4: beq         $t5, $zero, L_8000F500
    if (ctx->r13 == 0) {
        // 0x8000F4D8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8000F500;
    }
    // 0x8000F4D8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8000F4DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4E0: lw          $t7, -0x4C28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4C28);
    // 0x8000F4E4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000F4E8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F4EC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000F4F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4F4: nop

    // 0x8000F4F8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8000F4FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8000F500:
    // 0x8000F500: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F504: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8000F508: jal         0x800238F0
    // 0x8000F50C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    run_object_init_func(rdram, ctx);
        goto after_34;
    // 0x8000F50C: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    after_34:
    // 0x8000F510: lw          $v0, 0x4C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F514: nop

    // 0x8000F518: beq         $v0, $zero, L_8000F54C
    if (ctx->r2 == 0) {
        // 0x8000F51C: nop
    
            goto L_8000F54C;
    }
    // 0x8000F51C: nop

    // 0x8000F520: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000F524: nop

    // 0x8000F528: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8000F52C: lw          $t3, 0x4C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F530: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000F534: nop

    // 0x8000F538: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8000F53C: lw          $t4, 0x4C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F540: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000F544: nop

    // 0x8000F548: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
L_8000F54C:
    // 0x8000F54C: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000F550: nop

    // 0x8000F554: lb          $v0, 0x56($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X56);
    // 0x8000F558: nop

    // 0x8000F55C: blez        $v0, L_8000F5F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F560: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F5F4;
    }
    // 0x8000F560: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F564: beq         $at, $zero, L_8000F5F4
    if (ctx->r1 == 0) {
        // 0x8000F568: nop
    
            goto L_8000F5F4;
    }
    // 0x8000F568: nop

    // 0x8000F56C: jal         0x8000F99C
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_init_attachpoint(rdram, ctx);
        goto after_35;
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x8000F574: beq         $v0, $zero, L_8000F5F4
    if (ctx->r2 == 0) {
        // 0x8000F578: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000F5F4;
    }
    // 0x8000F578: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F57C: lw          $v0, -0x4C30($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C30);
    // 0x8000F580: nop

    // 0x8000F584: beq         $v0, $zero, L_8000F594
    if (ctx->r2 == 0) {
        // 0x8000F588: nop
    
            goto L_8000F594;
    }
    // 0x8000F588: nop

    // 0x8000F58C: jal         0x8007B70C
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_36;
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
L_8000F594:
    // 0x8000F594: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F598: lw          $v0, -0x4C2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C2C);
    // 0x8000F59C: nop

    // 0x8000F5A0: beq         $v0, $zero, L_8000F5B4
    if (ctx->r2 == 0) {
        // 0x8000F5A4: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F5B4;
    }
    // 0x8000F5A4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F5A8: jal         0x8007B70C
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_37;
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_37:
    // 0x8000F5B0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F5B4:
    // 0x8000F5B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F5B8: jal         0x8000F648
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_38;
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_38:
    // 0x8000F5C0: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F5C4: jal         0x8000C844
    // 0x8000F5C8: nop

    try_free_object_header(rdram, ctx);
        goto after_39;
    // 0x8000F5C8: nop

    after_39:
    // 0x8000F5CC: jal         0x80071380
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_40;
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x8000F5D4: beq         $s1, $zero, L_8000F5EC
    if (ctx->r17 == 0) {
        // 0x8000F5D8: nop
    
            goto L_8000F5EC;
    }
    // 0x8000F5D8: nop

    // 0x8000F5DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000F5E0: nop

    // 0x8000F5E4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8000F5E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8000F5EC:
    // 0x8000F5EC: b           L_8000F62C
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F5F4:
    // 0x8000F5F4: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000F5F8: nop

    // 0x8000F5FC: lb          $t6, 0x5A($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X5A);
    // 0x8000F600: nop

    // 0x8000F604: blez        $t6, L_8000F614
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F608: nop
    
            goto L_8000F614;
    }
    // 0x8000F608: nop

    // 0x8000F60C: jal         0x8000F758
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    light_setup_light_sources(rdram, ctx);
        goto after_41;
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
L_8000F614:
    // 0x8000F614: jal         0x80061C34
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    model_anim_offset(rdram, ctx);
        goto after_42;
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8000F61C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000F620: jal         0x800B7BD8
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_43;
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_43:
    // 0x8000F628: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8000F62C:
    // 0x8000F62C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F630: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F634: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F638: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F63C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F640: jr          $ra
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sprite_cache_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C97C: bltz        $a0, L_8007C998
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C980: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007C998;
    }
    // 0x8007C980: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C984: lw          $t6, 0x68F8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X68F8);
    // 0x8007C988: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C98C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C990: bne         $at, $zero, L_8007C9A0
    if (ctx->r1 != 0) {
        // 0x8007C994: nop
    
            goto L_8007C9A0;
    }
    // 0x8007C994: nop

L_8007C998:
    // 0x8007C998: jr          $ra
    // 0x8007C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C99C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C9A0:
    // 0x8007C9A0: lw          $t7, 0x68EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X68EC);
    // 0x8007C9A4: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007C9A8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C9AC: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007C9B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C9B4: bne         $v1, $at, L_8007C9C4
    if (ctx->r3 != ctx->r1) {
        // 0x8007C9B8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007C9C4;
    }
    // 0x8007C9B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007C9BC: jr          $ra
    // 0x8007C9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C9C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C9C4:
    // 0x8007C9C4: jr          $ra
    // 0x8007C9C8: nop

    return;
    // 0x8007C9C8: nop

;}
RECOMP_FUNC void obj_init_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AD78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD7C: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AD80: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003AD84: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003AD88: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AD8C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AD90: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003AD94: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AD98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003AD9C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003ADA0: bc1f        L_8003ADB0
    if (!c1cs) {
        // 0x8003ADA4: nop
    
            goto L_8003ADB0;
    }
    // 0x8003ADA4: nop

    // 0x8003ADA8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003ADAC: nop

L_8003ADB0:
    // 0x8003ADB0: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003ADB4: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003ADB8: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003ADBC: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003ADC0: nop

    // 0x8003ADC4: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003ADC8: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003ADCC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003ADD0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003ADD4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003ADD8: jal         0x80070A04
    // 0x8003ADDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003ADDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ADE0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003ADE4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003ADE8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003ADEC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003ADF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003ADF4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003ADF8: jal         0x80070A38
    // 0x8003ADFC: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003ADFC: nop

    after_1:
    // 0x8003AE00: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003AE04: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003AE08: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003AE0C: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003AE10: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003AE14: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003AE18: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003AE1C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003AE20: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003AE24: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003AE28: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003AE2C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003AE30: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003AE34: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AE38: nop

    // 0x8003AE3C: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003AE40: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AE44: nop

    // 0x8003AE48: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003AE4C: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE50: nop

    // 0x8003AE54: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003AE58: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE5C: nop

    // 0x8003AE60: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003AE64: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE68: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AE6C: nop

    // 0x8003AE70: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003AE74: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE78: nop

    // 0x8003AE7C: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003AE80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AE88: jr          $ra
    // 0x8003AE8C: nop

    return;
    // 0x8003AE8C: nop

;}
RECOMP_FUNC void gParticlePtrList_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001004C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80010050: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80010054: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80010058: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001005C: addiu       $s7, $s7, -0x4BB8
    ctx->r23 = ADD32(ctx->r23, -0X4BB8);
    // 0x80010060: sw          $zero, -0x4BF8($at)
    MEM_W(-0X4BF8, ctx->r1) = 0;
    // 0x80010064: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80010068: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001006C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010070: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80010074: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80010078: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001007C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80010080: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010084: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010088: blez        $t6, L_8001017C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001008C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001017C;
    }
    // 0x8001008C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010090: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010094: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80010098: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001009C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800100A0: addiu       $s0, $s0, -0x4C24
    ctx->r16 = ADD32(ctx->r16, -0X4C24);
    // 0x800100A4: addiu       $s1, $s1, -0x4C28
    ctx->r17 = ADD32(ctx->r17, -0X4C28);
    // 0x800100A8: addiu       $s4, $s4, -0x4C04
    ctx->r20 = ADD32(ctx->r20, -0X4C04);
    // 0x800100AC: addiu       $s5, $s5, -0x4BBC
    ctx->r21 = ADD32(ctx->r21, -0X4BBC);
    // 0x800100B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800100B4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800100B8:
    // 0x800100B8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800100BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800100C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800100C4: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x800100C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800100CC: blez        $a1, L_80010100
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800100D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80010100;
    }
    // 0x800100D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800100D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800100D8: nop

L_800100DC:
    // 0x800100DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800100E0: nop

    // 0x800100E4: bne         $a2, $t9, L_800100F0
    if (ctx->r6 != ctx->r25) {
        // 0x800100E8: nop
    
            goto L_800100F0;
    }
    // 0x800100E8: nop

    // 0x800100EC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800100F0:
    // 0x800100F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800100F4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800100F8: bne         $at, $zero, L_800100DC
    if (ctx->r1 != 0) {
        // 0x800100FC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800100DC;
    }
    // 0x800100FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010100:
    // 0x80010100: beq         $a0, $s6, L_8001015C
    if (ctx->r4 == ctx->r22) {
        // 0x80010104: addiu       $t1, $a1, -0x1
        ctx->r9 = ADD32(ctx->r5, -0X1);
            goto L_8001015C;
    }
    // 0x80010104: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80010108: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8001010C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80010110: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010114: beq         $at, $zero, L_80010120
    if (ctx->r1 == 0) {
        // 0x80010118: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80010120;
    }
    // 0x80010118: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8001011C: sh          $t0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r8;
L_80010120:
    // 0x80010120: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80010124: beq         $at, $zero, L_8001015C
    if (ctx->r1 == 0) {
        // 0x80010128: sw          $t1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r9;
            goto L_8001015C;
    }
    // 0x80010128: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8001012C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_80010130:
    // 0x80010130: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80010134: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80010138: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8001013C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80010140: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010144: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80010148: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001014C: nop

    // 0x80010150: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80010154: bne         $at, $zero, L_80010130
    if (ctx->r1 != 0) {
        // 0x80010158: nop
    
            goto L_80010130;
    }
    // 0x80010158: nop

L_8001015C:
    // 0x8001015C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80010160: jal         0x800101AC
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    obj_destroy(rdram, ctx);
        goto after_0;
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80010168: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8001016C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010170: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80010174: bne         $at, $zero, L_800100B8
    if (ctx->r1 != 0) {
        // 0x80010178: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800100B8;
    }
    // 0x80010178: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001017C:
    // 0x8001017C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010180: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x80010184: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80010188: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001018C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010190: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80010194: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80010198: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001019C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800101A0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800101A4: jr          $ra
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void video_delta_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ADC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ADC8: sb          $zero, 0x68A8($at)
    MEM_B(0X68A8, ctx->r1) = 0;
    // 0x8007ADCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ADD0: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007ADD4: jr          $ra
    // 0x8007ADD8: sb          $t6, 0x68A9($at)
    MEM_B(0X68A9, ctx->r1) = ctx->r14;
    return;
    // 0x8007ADD8: sb          $t6, 0x68A9($at)
    MEM_B(0X68A9, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mtx_cam_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800696C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800696C8: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800696CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800696D0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800696D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800696D8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800696DC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800696E0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800696E4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800696E8: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x800696EC: jal         0x8006FE70
    // 0x800696F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x800696F0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800696F4: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800696F8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800696FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069700: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x80069704: nop

    // 0x80069708: bc1t        L_80069720
    if (c1cs) {
        // 0x8006970C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80069720;
    }
    // 0x8006970C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069710: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069714: jal         0x80070070
    // 0x80069718: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_translate_y(rdram, ctx);
        goto after_1;
    // 0x80069718: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_1:
    // 0x8006971C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80069720:
    // 0x80069720: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80069724: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80069728: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006972C: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80069730: nop

    // 0x80069734: bc1t        L_80069748
    if (c1cs) {
        // 0x80069738: nop
    
            goto L_80069748;
    }
    // 0x80069738: nop

    // 0x8006973C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069740: jal         0x80070044
    // 0x80069744: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_scale_y(rdram, ctx);
        goto after_2;
    // 0x80069744: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_2:
L_80069748:
    // 0x80069748: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006974C: lw          $t6, 0x129C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X129C);
    // 0x80069750: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069754: addiu       $t8, $t8, 0x12F0
    ctx->r24 = ADD32(ctx->r24, 0X12F0);
    // 0x80069758: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006975C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069760: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80069764: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80069768: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006976C: jal         0x8006F9A8
    // 0x80069770: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x80069770: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_3:
    // 0x80069774: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069778: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x8006977C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80069780: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069784: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80069788: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8006978C: lw          $a0, 0x12F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F4);
    // 0x80069790: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069794: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069798: addiu       $a2, $a2, 0x1620
    ctx->r6 = ADD32(ctx->r6, 0X1620);
    // 0x8006979C: jal         0x8006F9A8
    // 0x800697A0: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x800697A0: addiu       $a1, $a1, 0x14A0
    ctx->r5 = ADD32(ctx->r5, 0X14A0);
    after_4:
    // 0x800697A4: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x800697A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800697AC: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x800697B0: jal         0x8006FAB0
    // 0x800697B4: addiu       $a0, $a0, 0x1620
    ctx->r4 = ADD32(ctx->r4, 0X1620);
    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x800697B4: addiu       $a0, $a0, 0x1620
    ctx->r4 = ADD32(ctx->r4, 0X1620);
    after_5:
    // 0x800697B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800697BC: addiu       $t0, $t0, 0x129C
    ctx->r8 = ADD32(ctx->r8, 0X129C);
    // 0x800697C0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800697C4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800697C8: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800697CC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800697D0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800697D4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800697D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800697DC: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800697E0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800697E4: sw          $t7, 0x1308($at)
    MEM_W(0X1308, ctx->r1) = ctx->r15;
    // 0x800697E8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800697EC: lui         $t3, 0x140
    ctx->r11 = S32(0X140 << 16);
    // 0x800697F0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800697F4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800697F8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800697FC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80069800: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80069804: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80069808: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x8006980C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80069810: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80069814: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069818: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x8006981C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80069820: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80069824: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x80069828: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006982C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80069830: lw          $a0, 0x12F0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X12F0);
    // 0x80069834: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x80069838: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x8006983C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80069840: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80069844: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80069848: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006984C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80069850: jal         0x8006F88C
    // 0x80069854: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x80069854: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_6:
    // 0x80069858: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006985C: lb          $t6, 0x1294($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X1294);
    // 0x80069860: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80069864: lw          $v1, 0x1264($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X1264);
    // 0x80069868: beq         $t6, $zero, L_80069874
    if (ctx->r14 == 0) {
        // 0x8006986C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80069874;
    }
    // 0x8006986C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069870: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80069874:
    // 0x80069874: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80069878: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006987C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069880: addiu       $t8, $t8, 0x1040
    ctx->r24 = ADD32(ctx->r24, 0X1040);
    // 0x80069884: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069888: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8006988C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069890: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069894: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069898: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006989C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800698A0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800698A4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800698A8: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x800698AC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800698B0: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800698B4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800698B8: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x800698BC: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800698C0: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x800698C4: addiu       $a1, $a1, 0x1270
    ctx->r5 = ADD32(ctx->r5, 0X1270);
    // 0x800698C8: negu        $t3, $t9
    ctx->r11 = SUB32(0, ctx->r25);
    // 0x800698CC: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x800698D0: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x800698D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800698D8: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800698DC: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800698E0: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800698E4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800698E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800698EC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800698F0: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x800698F4: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x800698F8: swc1        $f20, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f20.u32l;
    // 0x800698FC: swc1        $f20, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f20.u32l;
    // 0x80069900: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    // 0x80069904: jal         0x800700B4
    // 0x80069908: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_7;
    // 0x80069908: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    after_7:
    // 0x8006990C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069910: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80069914: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80069918: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8006991C: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x80069920: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x80069924: addiu       $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x80069928: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x8006992C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80069930: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80069934: jal         0x8006F88C
    // 0x80069938: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    mtxf_transform_point(rdram, ctx);
        goto after_8;
    // 0x80069938: addiu       $a0, $a0, 0x15E0
    ctx->r4 = ADD32(ctx->r4, 0X15E0);
    after_8:
    // 0x8006993C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80069940: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069944: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80069948: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8006994C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069950: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80069954: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80069958: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006995C: addiu       $a0, $a0, 0x12A0
    ctx->r4 = ADD32(ctx->r4, 0X12A0);
    // 0x80069960: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80069964: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80069968: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006996C: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x80069970: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069974: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80069978: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8006997C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80069980: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069984: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069988: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006998C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069990: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80069994: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069998: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006999C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x800699A0: swc1        $f6, 0x12A8($at)
    MEM_W(0X12A8, ctx->r1) = ctx->f6.u32l;
    // 0x800699A4: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800699A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800699AC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800699B0: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x800699B4: swc1        $f8, 0x12C0($at)
    MEM_W(0X12C0, ctx->r1) = ctx->f8.u32l;
    // 0x800699B8: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800699BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800699C0: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800699C4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800699C8: jr          $ra
    // 0x800699CC: swc1        $f10, 0x12D8($at)
    MEM_W(0X12D8, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x800699CC: swc1        $f10, 0x12D8($at)
    MEM_W(0X12D8, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8000E4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4E8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000E4EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E4F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000E4F8: addiu       $t6, $t6, -0x4BE0
    ctx->r14 = ADD32(ctx->r14, -0X4BE0);
    // 0x8000E4FC: lw          $v0, -0x4BD0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BD0);
    // 0x8000E500: addu        $a1, $v1, $t6
    ctx->r5 = ADD32(ctx->r3, ctx->r14);
    // 0x8000E504: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000E508: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E50C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8000E510: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8000E514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000E518: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000E51C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8000E520: lw          $t9, -0x4BE8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4BE8);
    // 0x8000E524: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000E528: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000E52C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000E530: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8000E534:
    // 0x8000E534: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E538: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8000E53C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8000E540: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8000E544: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x8000E548: bne         $a3, $v0, L_8000E534
    if (ctx->r7 != ctx->r2) {
        // 0x8000E54C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E534;
    }
    // 0x8000E54C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8000E550: jr          $ra
    // 0x8000E554: nop

    return;
    // 0x8000E554: nop

;}
RECOMP_FUNC void func_800BC6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCBE8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BCBEC: addiu       $t2, $t2, -0x5A78
    ctx->r10 = ADD32(ctx->r10, -0X5A78);
    // 0x800BCBF0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCBF4: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x800BCBF8: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x800BCBFC: addiu       $sp, $sp, -0x248
    ctx->r29 = ADD32(ctx->r29, -0X248);
    // 0x800BCC00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BCC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BCC08: bne         $a2, $zero, L_800BCC14
    if (ctx->r6 != 0) {
        // 0x800BCC0C: nop
    
            goto L_800BCC14;
    }
    // 0x800BCC0C: nop

    // 0x800BCC10: break       7
    do_break(2148256784);
L_800BCC14:
    // 0x800BCC14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BCC18: bne         $a2, $at, L_800BCC2C
    if (ctx->r6 != ctx->r1) {
        // 0x800BCC1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BCC2C;
    }
    // 0x800BCC1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BCC20: bne         $t6, $at, L_800BCC2C
    if (ctx->r14 != ctx->r1) {
        // 0x800BCC24: nop
    
            goto L_800BCC2C;
    }
    // 0x800BCC24: nop

    // 0x800BCC28: break       6
    do_break(2148256808);
L_800BCC2C:
    // 0x800BCC2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BCC30: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCC34: mflo        $v0
    ctx->r2 = lo;
    // 0x800BCC38: blez        $a2, L_800BCC90
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BCC3C: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_800BCC90;
    }
    // 0x800BCC3C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
L_800BCC40:
    // 0x800BCC40: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BCC44: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BCC48: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BCC4C: sw          $v0, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r2;
    // 0x800BCC50: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800BCC54: jal         0x80070A04
    // 0x800BCC58: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800BCC58: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    after_0:
    // 0x800BCC5C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BCC60: lw          $t3, 0x244($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X244);
    // 0x800BCC64: addiu       $t2, $t2, -0x5A78
    ctx->r10 = ADD32(ctx->r10, -0X5A78);
    // 0x800BCC68: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCC6C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BCC70: lw          $v0, 0x234($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X234);
    // 0x800BCC74: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCC78: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BCC7C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800BCC80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BCC84: bne         $at, $zero, L_800BCC40
    if (ctx->r1 != 0) {
        // 0x800BCC88: addu        $s0, $s0, $v0
        ctx->r16 = ADD32(ctx->r16, ctx->r2);
            goto L_800BCC40;
    }
    // 0x800BCC88: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800BCC8C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCC90:
    // 0x800BCC90: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BCC94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BCC98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BCC9C: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x800BCCA0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BCCA4: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BCCA8: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800BCCAC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BCCB0: bltz        $a2, L_800BCD08
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCCB4: swc1        $f0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
            goto L_800BCD08;
    }
    // 0x800BCCB4: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x800BCCB8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BCCBC: addiu       $t1, $t1, 0x35DC
    ctx->r9 = ADD32(ctx->r9, 0X35DC);
L_800BCCC0:
    // 0x800BCCC0: bltz        $a2, L_800BCCF0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCCC4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCCF0;
    }
    // 0x800BCCC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCCC8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCCCC:
    // 0x800BCCCC: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x800BCCD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCCD4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BCCD8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800BCCDC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCCE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCCE4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCCE8: beq         $at, $zero, L_800BCCCC
    if (ctx->r1 == 0) {
        // 0x800BCCEC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCCCC;
    }
    // 0x800BCCEC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCCF0:
    // 0x800BCCF0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCCF4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCCF8: beq         $at, $zero, L_800BCCC0
    if (ctx->r1 == 0) {
        // 0x800BCCFC: nop
    
            goto L_800BCCC0;
    }
    // 0x800BCCFC: nop

    // 0x800BCD00: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCD04: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCD08:
    // 0x800BCD08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BCD0C: bltz        $a2, L_800BCD68
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD10: addiu       $t1, $t1, 0x35DC
        ctx->r9 = ADD32(ctx->r9, 0X35DC);
            goto L_800BCD68;
    }
    // 0x800BCD10: addiu       $t1, $t1, 0x35DC
    ctx->r9 = ADD32(ctx->r9, 0X35DC);
L_800BCD14:
    // 0x800BCD14: bltz        $a2, L_800BCD50
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD18: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCD50;
    }
    // 0x800BCD18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCD1C: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800BCD20: addu        $a1, $t4, $t7
    ctx->r5 = ADD32(ctx->r12, ctx->r15);
    // 0x800BCD24: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCD28:
    // 0x800BCD28: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x800BCD2C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCD30: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800BCD34: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800BCD38: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCD3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCD40: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCD44: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCD48: beq         $at, $zero, L_800BCD28
    if (ctx->r1 == 0) {
        // 0x800BCD4C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCD28;
    }
    // 0x800BCD4C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCD50:
    // 0x800BCD50: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCD54: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCD58: beq         $at, $zero, L_800BCD14
    if (ctx->r1 == 0) {
        // 0x800BCD5C: nop
    
            goto L_800BCD14;
    }
    // 0x800BCD5C: nop

    // 0x800BCD60: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCD64: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCD68:
    // 0x800BCD68: bltz        $a2, L_800BCDC4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD6C: nop
    
            goto L_800BCDC4;
    }
    // 0x800BCD6C: nop

L_800BCD70:
    // 0x800BCD70: bltz        $a2, L_800BCDAC
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCD74: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCDAC;
    }
    // 0x800BCD74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCD78: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BCD7C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_800BCD80:
    // 0x800BCD80: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x800BCD84: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BCD88: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BCD8C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x800BCD90: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCD94: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCD98: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCD9C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCDA0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BCDA4: beq         $at, $zero, L_800BCD80
    if (ctx->r1 == 0) {
        // 0x800BCDA8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800BCD80;
    }
    // 0x800BCDA8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800BCDAC:
    // 0x800BCDAC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCDB0: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCDB4: beq         $at, $zero, L_800BCD70
    if (ctx->r1 == 0) {
        // 0x800BCDB8: nop
    
            goto L_800BCD70;
    }
    // 0x800BCDB8: nop

    // 0x800BCDBC: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCDC0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCDC4:
    // 0x800BCDC4: bltz        $a2, L_800BCE30
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCDC8: nop
    
            goto L_800BCE30;
    }
    // 0x800BCDC8: nop

L_800BCDCC:
    // 0x800BCDCC: bltz        $a2, L_800BCE18
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCDD0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCE18;
    }
    // 0x800BCDD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCDD4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BCDD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BCDDC:
    // 0x800BCDDC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800BCDE0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BCDE4: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x800BCDE8: lw          $t6, 0x14($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X14);
    // 0x800BCDEC: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800BCDF0: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800BCDF4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BCDF8: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800BCDFC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCE00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCE04: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCE08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCE10: beq         $at, $zero, L_800BCDDC
    if (ctx->r1 == 0) {
        // 0x800BCE14: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCDDC;
    }
    // 0x800BCE14: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCE18:
    // 0x800BCE18: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCE1C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCE20: beq         $at, $zero, L_800BCDCC
    if (ctx->r1 == 0) {
        // 0x800BCE24: nop
    
            goto L_800BCDCC;
    }
    // 0x800BCE24: nop

    // 0x800BCE28: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BCE2C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BCE30:
    // 0x800BCE30: bltz        $a2, L_800BCE94
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE34: nop
    
            goto L_800BCE94;
    }
    // 0x800BCE34: nop

L_800BCE38:
    // 0x800BCE38: bltz        $a2, L_800BCE80
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE3C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BCE80;
    }
    // 0x800BCE3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BCE40: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCE44: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BCE48:
    // 0x800BCE48: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BCE4C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BCE50: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BCE54: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x800BCE58: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800BCE5C: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BCE60: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BCE64: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800BCE68: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCE6C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCE70: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCE74: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BCE78: beq         $at, $zero, L_800BCE48
    if (ctx->r1 == 0) {
        // 0x800BCE7C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BCE48;
    }
    // 0x800BCE7C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BCE80:
    // 0x800BCE80: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCE84: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCE88: beq         $at, $zero, L_800BCE38
    if (ctx->r1 == 0) {
        // 0x800BCE8C: nop
    
            goto L_800BCE38;
    }
    // 0x800BCE8C: nop

    // 0x800BCE90: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCE94:
    // 0x800BCE94: bltz        $a2, L_800BCF30
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCE98: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCF30;
    }
    // 0x800BCE98: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCE9C:
    // 0x800BCE9C: bne         $at, $zero, L_800BCF1C
    if (ctx->r1 != 0) {
        // 0x800BCEA0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCF1C;
    }
    // 0x800BCEA0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCEA4: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCEA8: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCEAC: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCEB0: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCEB4: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCEB8:
    // 0x800BCEB8: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCEBC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BCEC0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCEC4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCEC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCECC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800BCED0: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BCED4: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x800BCED8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800BCEDC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BCEE0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800BCEE4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCEE8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCEEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCEF0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCEF4: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCEF8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BCEFC: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x800BCF00: addu        $t8, $t5, $a3
    ctx->r24 = ADD32(ctx->r13, ctx->r7);
    // 0x800BCF04: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BCF08: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCF0C: nop

    // 0x800BCF10: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCF14: beq         $at, $zero, L_800BCEB8
    if (ctx->r1 == 0) {
        // 0x800BCF18: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BCEB8;
    }
    // 0x800BCF18: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCF1C:
    // 0x800BCF1C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCF20: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCF24: beq         $at, $zero, L_800BCE9C
    if (ctx->r1 == 0) {
        // 0x800BCF28: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCE9C;
    }
    // 0x800BCF28: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCF2C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCF30:
    // 0x800BCF30: bltz        $a2, L_800BCFE4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCF34: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCFE4;
    }
    // 0x800BCF34: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCF38:
    // 0x800BCF38: bne         $at, $zero, L_800BCFD0
    if (ctx->r1 != 0) {
        // 0x800BCF3C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCFD0;
    }
    // 0x800BCF3C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCF40: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCF44: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCF48: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCF4C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCF50: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCF54:
    // 0x800BCF54: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCF58: lw          $t7, 0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X8);
    // 0x800BCF5C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCF60: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCF64: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCF68: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800BCF6C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BCF70: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BCF74: negu        $t7, $a0
    ctx->r15 = SUB32(0, ctx->r4);
    // 0x800BCF78: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800BCF7C: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800BCF80: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCF84: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800BCF88: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800BCF8C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCF90: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCF94: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCF98: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCF9C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCFA0: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCFA4: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800BCFA8: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800BCFAC: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800BCFB0: negu        $t9, $a3
    ctx->r25 = SUB32(0, ctx->r7);
    // 0x800BCFB4: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800BCFB8: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x800BCFBC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCFC0: nop

    // 0x800BCFC4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCFC8: beq         $at, $zero, L_800BCF54
    if (ctx->r1 == 0) {
        // 0x800BCFCC: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BCF54;
    }
    // 0x800BCFCC: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCFD0:
    // 0x800BCFD0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCFD4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCFD8: beq         $at, $zero, L_800BCF38
    if (ctx->r1 == 0) {
        // 0x800BCFDC: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCF38;
    }
    // 0x800BCFDC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCFE0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCFE4:
    // 0x800BCFE4: bltz        $a2, L_800BD0A8
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCFE8: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD0A8;
    }
    // 0x800BCFE8: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCFEC:
    // 0x800BCFEC: bne         $at, $zero, L_800BD094
    if (ctx->r1 != 0) {
        // 0x800BCFF0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BD094;
    }
    // 0x800BCFF0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCFF4: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCFF8: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x800BCFFC: addu        $a1, $a3, $t8
    ctx->r5 = ADD32(ctx->r7, ctx->r24);
    // 0x800BD000: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BD004: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD008:
    // 0x800BD008: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD00C: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x800BD010: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD014: mflo        $t5
    ctx->r13 = lo;
    // 0x800BD018: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800BD01C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD020: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD024: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD028: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x800BD02C: sll         $t5, $at, 2
    ctx->r13 = S32(ctx->r1 << 2);
    // 0x800BD030: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800BD034: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x800BD038: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800BD03C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD040: lw          $t8, 0x18($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X18);
    // 0x800BD044: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BD048: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD04C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD050: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD054: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD058: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800BD05C: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800BD060: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD064: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD068: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD06C: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BD070: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BD074: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BD078: addu        $t5, $t8, $a3
    ctx->r13 = ADD32(ctx->r24, ctx->r7);
    // 0x800BD07C: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800BD080: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD084: nop

    // 0x800BD088: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BD08C: beq         $at, $zero, L_800BD008
    if (ctx->r1 == 0) {
        // 0x800BD090: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BD008;
    }
    // 0x800BD090: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD094:
    // 0x800BD094: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BD098: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD09C: beq         $at, $zero, L_800BCFEC
    if (ctx->r1 == 0) {
        // 0x800BD0A0: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCFEC;
    }
    // 0x800BD0A0: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD0A4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BD0A8:
    // 0x800BD0A8: bltz        $a2, L_800BD180
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BD0AC: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD180;
    }
    // 0x800BD0AC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BD0B0:
    // 0x800BD0B0: bne         $at, $zero, L_800BD170
    if (ctx->r1 != 0) {
        // 0x800BD0B4: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BD170;
    }
    // 0x800BD0B4: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BD0B8: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BD0BC: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BD0C0: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BD0C4: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BD0C8: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD0CC:
    // 0x800BD0CC: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD0D0: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BD0D4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD0D8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD0DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BD0E0: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x800BD0E4: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD0E8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BD0EC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BD0F0: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BD0F4: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BD0F8: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800BD0FC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BD100: negu        $t5, $a0
    ctx->r13 = SUB32(0, ctx->r4);
    // 0x800BD104: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800BD108: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800BD10C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD110: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BD114: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BD118: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD11C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BD120: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BD124: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD128: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BD12C: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD130: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD134: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800BD138: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD13C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD140: negu        $at, $t7
    ctx->r1 = SUB32(0, ctx->r15);
    // 0x800BD144: sll         $t8, $at, 2
    ctx->r24 = S32(ctx->r1 << 2);
    // 0x800BD148: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x800BD14C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD150: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BD154: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800BD158: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BD15C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BD160: nop

    // 0x800BD164: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BD168: beq         $at, $zero, L_800BD0CC
    if (ctx->r1 == 0) {
        // 0x800BD16C: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BD0CC;
    }
    // 0x800BD16C: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BD170:
    // 0x800BD170: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BD174: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD178: beq         $at, $zero, L_800BD0B0
    if (ctx->r1 == 0) {
        // 0x800BD17C: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BD0B0;
    }
    // 0x800BD17C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BD180:
    // 0x800BD180: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BD184: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BD188: jr          $ra
    // 0x800BD18C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
    return;
    // 0x800BD18C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
;}
RECOMP_FUNC void search_level_properties_forwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE40: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006AE44: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006AE48: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006AE4C: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006AE50: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006AE54: bgez        $a0, L_8006AE64
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AE58: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006AE64;
    }
    // 0x8006AE58: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006AE5C: b           L_8006AE68
    // 0x8006AE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8006AE68;
    // 0x8006AE60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006AE64:
    // 0x8006AE64: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8006AE68:
    // 0x8006AE68: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006AE6C: beq         $a1, $at, L_8006AF9C
    if (ctx->r5 == ctx->r1) {
        // 0x8006AE70: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8006AF9C;
    }
    // 0x8006AE70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AE74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AE78: bne         $a2, $v0, L_8006AED8
    if (ctx->r6 != ctx->r2) {
        // 0x8006AE7C: nop
    
            goto L_8006AED8;
    }
    // 0x8006AE7C: nop

    // 0x8006AE80: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AE84: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AE88: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AE8C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AE90: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AE94: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AE94: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AE98: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006AE9C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AEA0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AEA4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AEA8:
    // 0x8006AEA8: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AEAC: nop

    // 0x8006AEB0: bne         $a1, $t2, L_8006AEC0
    if (ctx->r5 != ctx->r10) {
        // 0x8006AEB4: nop
    
            goto L_8006AEC0;
    }
    // 0x8006AEB4: nop

    // 0x8006AEB8: jr          $ra
    // 0x8006AEBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AEBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AEC0:
    // 0x8006AEC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AEC4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AEC8: bne         $at, $zero, L_8006AEA8
    if (ctx->r1 != 0) {
        // 0x8006AECC: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AEA8;
    }
    // 0x8006AECC: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AED0: b           L_8006B064
    // 0x8006AED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AED4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AED8:
    // 0x8006AED8: bne         $a1, $v0, L_8006AF34
    if (ctx->r5 != ctx->r2) {
        // 0x8006AEDC: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006AF34;
    }
    // 0x8006AEDC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AEE0: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AEE4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006AEE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AEEC: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AEF0: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AEF0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006AEF4: lw          $t3, 0x16FC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X16FC);
    // 0x8006AEF8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006AEFC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006AF00: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
L_8006AF04:
    // 0x8006AF04: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8006AF08: nop

    // 0x8006AF0C: bne         $a2, $t5, L_8006AF1C
    if (ctx->r6 != ctx->r13) {
        // 0x8006AF10: nop
    
            goto L_8006AF1C;
    }
    // 0x8006AF10: nop

    // 0x8006AF14: jr          $ra
    // 0x8006AF18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AF18: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AF1C:
    // 0x8006AF1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AF20: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF24: bne         $at, $zero, L_8006AF04
    if (ctx->r1 != 0) {
        // 0x8006AF28: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AF04;
    }
    // 0x8006AF28: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AF2C: b           L_8006B064
    // 0x8006AF30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AF30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF34:
    // 0x8006AF34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AF38: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AF3C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AF40: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF44: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AF48: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AF48: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006AF4C: lw          $t6, 0x16FC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16FC);
    // 0x8006AF50: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006AF54: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006AF58: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_8006AF5C:
    // 0x8006AF5C: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8006AF60: nop

    // 0x8006AF64: bne         $a1, $t8, L_8006AF84
    if (ctx->r5 != ctx->r24) {
        // 0x8006AF68: nop
    
            goto L_8006AF84;
    }
    // 0x8006AF68: nop

    // 0x8006AF6C: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8006AF70: nop

    // 0x8006AF74: bne         $a2, $t9, L_8006AF84
    if (ctx->r6 != ctx->r25) {
        // 0x8006AF78: nop
    
            goto L_8006AF84;
    }
    // 0x8006AF78: nop

    // 0x8006AF7C: jr          $ra
    // 0x8006AF80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AF80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AF84:
    // 0x8006AF84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AF88: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AF8C: bne         $at, $zero, L_8006AF5C
    if (ctx->r1 != 0) {
        // 0x8006AF90: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AF5C;
    }
    // 0x8006AF90: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AF94: b           L_8006B064
    // 0x8006AF98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AF98: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AF9C:
    // 0x8006AF9C: bne         $a2, $v0, L_8006AFFC
    if (ctx->r6 != ctx->r2) {
        // 0x8006AFA0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006AFFC;
    }
    // 0x8006AFA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AFA4: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006AFA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AFAC: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AFB0: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006AFB4: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006AFB4: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AFB8: lw          $t0, 0x16FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X16FC);
    // 0x8006AFBC: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AFC0: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AFC4: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AFC8:
    // 0x8006AFC8: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AFCC: nop

    // 0x8006AFD0: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006AFD4: beq         $t3, $zero, L_8006AFE4
    if (ctx->r11 == 0) {
        // 0x8006AFD8: nop
    
            goto L_8006AFE4;
    }
    // 0x8006AFD8: nop

    // 0x8006AFDC: jr          $ra
    // 0x8006AFE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AFE0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AFE4:
    // 0x8006AFE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AFE8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AFEC: bne         $at, $zero, L_8006AFC8
    if (ctx->r1 != 0) {
        // 0x8006AFF0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AFC8;
    }
    // 0x8006AFF0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AFF4: b           L_8006B064
    // 0x8006AFF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006B064;
    // 0x8006AFF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AFFC:
    // 0x8006AFFC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006B000: lw          $v0, 0x16F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X16F0);
    // 0x8006B004: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006B008: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B00C: beq         $at, $zero, L_8006B060
    if (ctx->r1 == 0) {
        // 0x8006B010: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_8006B060;
    }
    // 0x8006B010: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006B014: lw          $t4, 0x16FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X16FC);
    // 0x8006B018: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006B01C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006B020: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
L_8006B024:
    // 0x8006B024: lb          $t6, 0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1);
    // 0x8006B028: nop

    // 0x8006B02C: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006B030: beq         $t7, $zero, L_8006B050
    if (ctx->r15 == 0) {
        // 0x8006B034: nop
    
            goto L_8006B050;
    }
    // 0x8006B034: nop

    // 0x8006B038: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8006B03C: nop

    // 0x8006B040: bne         $a2, $t8, L_8006B050
    if (ctx->r6 != ctx->r24) {
        // 0x8006B044: nop
    
            goto L_8006B050;
    }
    // 0x8006B044: nop

    // 0x8006B048: jr          $ra
    // 0x8006B04C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006B04C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006B050:
    // 0x8006B050: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006B054: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006B058: bne         $at, $zero, L_8006B024
    if (ctx->r1 != 0) {
        // 0x8006B05C: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006B024;
    }
    // 0x8006B05C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_8006B060:
    // 0x8006B060: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006B064:
    // 0x8006B064: jr          $ra
    // 0x8006B068: nop

    return;
    // 0x8006B068: nop

;}
RECOMP_FUNC void render_active_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3BD8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B3BDC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3BE0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3BE4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B3BE8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B3BEC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3BF0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3BF4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B3BF8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B3BFC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800B3C00: jal         0x8000E988
    // 0x800B3C04: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x800B3C04: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800B3C08: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C0C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B3C10: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B3C14: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3C18: beq         $at, $zero, L_800B3C88
    if (ctx->r1 == 0) {
        // 0x800B3C1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B3C88;
    }
    // 0x800B3C1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3C20:
    // 0x800B3C20: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C24: nop

    // 0x800B3C28: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B3C2C: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800B3C30: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B3C34: nop

    // 0x800B3C38: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800B3C3C: nop

    // 0x800B3C40: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x800B3C44: beq         $t1, $zero, L_800B3C70
    if (ctx->r9 == 0) {
        // 0x800B3C48: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_800B3C70;
    }
    // 0x800B3C48: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B3C4C: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x800B3C50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B3C54: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800B3C58: beq         $t3, $zero, L_800B3C6C
    if (ctx->r11 == 0) {
        // 0x800B3C5C: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800B3C6C;
    }
    // 0x800B3C5C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B3C60: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800B3C64: jal         0x800B3CA0
    // 0x800B3C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800B3C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
L_800B3C6C:
    // 0x800B3C6C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800B3C70:
    // 0x800B3C70: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B3C74: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B3C78: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B3C7C: bne         $at, $zero, L_800B3C20
    if (ctx->r1 != 0) {
        // 0x800B3C80: sw          $v1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r3;
            goto L_800B3C20;
    }
    // 0x800B3C80: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B3C84: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3C88:
    // 0x800B3C88: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B3C8C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3C90: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3C94: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3C98: jr          $ra
    // 0x800B3C9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B3C9C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
