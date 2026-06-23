#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void rain_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE21C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800AE220: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800AE224: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x800AE228: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x800AE22C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x800AE230: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x800AE234: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800AE238: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800AE23C: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800AE240: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800AE244: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800AE248: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800AE24C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800AE250: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800AE254: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x800AE258: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800AE25C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800AE260: beq         $v0, $zero, L_800AE78C
    if (ctx->r2 == 0) {
        // 0x800AE264: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800AE78C;
    }
    // 0x800AE264: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800AE268: lbu         $s1, 0x0($v0)
    ctx->r17 = MEM_BU(ctx->r2, 0X0);
    // 0x800AE26C: lbu         $s2, 0x1($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X1);
    // 0x800AE270: sll         $t6, $s1, 5
    ctx->r14 = S32(ctx->r17 << 5);
    // 0x800AE274: sll         $t7, $s2, 5
    ctx->r15 = S32(ctx->r18 << 5);
    // 0x800AE278: sll         $v1, $t6, 1
    ctx->r3 = S32(ctx->r14 << 1);
    // 0x800AE27C: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800AE280: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800AE284: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800AE288: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x800AE28C: sw          $t9, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r25;
    // 0x800AE290: lh          $t5, 0x8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X8);
    // 0x800AE294: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800AE298: multu       $t5, $a1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE29C: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x800AE2A0: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800AE2A4: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x800AE2A8: mflo        $a0
    ctx->r4 = lo;
    // 0x800AE2AC: jal         0x8000C8B4
    // 0x800AE2B0: nop

    normalise_time(rdram, ctx);
        goto after_0;
    // 0x800AE2B0: nop

    after_0:
    // 0x800AE2B4: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800AE2B8: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x800AE2BC: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800AE2C0: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x800AE2C4: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800AE2C8: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x800AE2CC: lh          $t5, 0xA($s0)
    ctx->r13 = MEM_H(ctx->r16, 0XA);
    // 0x800AE2D0: nop

    // 0x800AE2D4: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE2D8: mflo        $a0
    ctx->r4 = lo;
    // 0x800AE2DC: jal         0x8000C8B4
    // 0x800AE2E0: nop

    normalise_time(rdram, ctx);
        goto after_1;
    // 0x800AE2E0: nop

    after_1:
    // 0x800AE2E4: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x800AE2E8: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x800AE2EC: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE2F0: lw          $t9, 0x88($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X88);
    // 0x800AE2F4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800AE2F8: and         $t5, $t8, $t9
    ctx->r13 = ctx->r24 & ctx->r25;
    // 0x800AE2FC: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x800AE300: sh          $t5, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r13;
    // 0x800AE304: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800AE308: lw          $t5, 0x31FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X31FC);
    // 0x800AE30C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800AE310: sra         $t6, $t5, 2
    ctx->r14 = S32(SIGNED(ctx->r13) >> 2);
    // 0x800AE314: mflo        $s1
    ctx->r17 = lo;
    // 0x800AE318: sra         $t7, $s1, 8
    ctx->r15 = S32(SIGNED(ctx->r17) >> 8);
    // 0x800AE31C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x800AE320: multu       $t8, $s2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE324: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AE328: lw          $t7, 0x31F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31F0);
    // 0x800AE32C: mflo        $s2
    ctx->r18 = lo;
    // 0x800AE330: sra         $t9, $s2, 8
    ctx->r25 = S32(SIGNED(ctx->r18) >> 8);
    // 0x800AE334: or          $s2, $t9, $zero
    ctx->r18 = ctx->r25 | 0;
    // 0x800AE338: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE33C: lbu         $t9, 0x16($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X16);
    // 0x800AE340: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AE344: mflo        $v1
    ctx->r3 = lo;
    // 0x800AE348: sra         $t8, $v1, 14
    ctx->r24 = S32(SIGNED(ctx->r3) >> 14);
    // 0x800AE34C: nop

    // 0x800AE350: multu       $t9, $t8
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE354: mflo        $v1
    ctx->r3 = lo;
    // 0x800AE358: sra         $t5, $v1, 16
    ctx->r13 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AE35C: blez        $t5, L_800AE788
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800AE360: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800AE788;
    }
    // 0x800AE360: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800AE364: lw          $v0, -0x7E24($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7E24);
    // 0x800AE368: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AE36C: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800AE370: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800AE374: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE378: lh          $t5, 0x0($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X0);
    // 0x800AE37C: lh          $t2, 0x2($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X2);
    // 0x800AE380: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x800AE384: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800AE388: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x800AE38C: addu        $s2, $s2, $t2
    ctx->r18 = ADD32(ctx->r18, ctx->r10);
    // 0x800AE390: sw          $t2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r10;
    // 0x800AE394: mflo        $t8
    ctx->r24 = lo;
    // 0x800AE398: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800AE39C: addu        $t6, $t5, $t9
    ctx->r14 = ADD32(ctx->r13, ctx->r25);
    // 0x800AE3A0: and         $t0, $t6, $t7
    ctx->r8 = ctx->r14 & ctx->r15;
    // 0x800AE3A4: addu        $s1, $s1, $t0
    ctx->r17 = ADD32(ctx->r17, ctx->r8);
    // 0x800AE3A8: jal         0x80070A04
    // 0x800AE3AC: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800AE3AC: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800AE3B0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800AE3B4: lw          $t8, -0x7E24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7E24);
    // 0x800AE3B8: nop

    // 0x800AE3BC: lh          $a0, 0x4($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4);
    // 0x800AE3C0: jal         0x80070A38
    // 0x800AE3C4: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    coss_f(rdram, ctx);
        goto after_3;
    // 0x800AE3C4: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800AE3C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3CC: lwc1        $f12, 0x301C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X301C);
    // 0x800AE3D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3D4: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800AE3D8: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800AE3DC: lwc1        $f14, 0x3020($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X3020);
    // 0x800AE3E0: lwc1        $f16, 0x3024($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X3024);
    // 0x800AE3E4: mul.s       $f6, $f14, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x800AE3E8: lwc1        $f18, 0x3028($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X3028);
    // 0x800AE3EC: lwc1        $f20, 0x302C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X302C);
    // 0x800AE3F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE3F4: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE3F8: lwc1        $f22, 0x3030($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X3030);
    // 0x800AE3FC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AE400: lwc1        $f24, 0x3034($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X3034);
    // 0x800AE404: lwc1        $f26, 0x3038($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X3038);
    // 0x800AE408: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AE40C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE414: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE418: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE41C: addiu       $t1, $t1, 0x3220
    ctx->r9 = ADD32(ctx->r9, 0X3220);
    // 0x800AE420: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AE424: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AE428: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x800AE42C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800AE430: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE434: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800AE438: mul.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800AE43C: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x800AE440: addiu       $t3, $t3, 0x303C
    ctx->r11 = ADD32(ctx->r11, 0X303C);
    // 0x800AE444: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800AE448: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE44C: addu        $v0, $t3, $t9
    ctx->r2 = ADD32(ctx->r11, ctx->r25);
    // 0x800AE450: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AE454: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800AE458: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AE45C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE460: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE464: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AE468: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE46C: addiu       $t4, $t4, -0x7E28
    ctx->r12 = ADD32(ctx->r12, -0X7E28);
    // 0x800AE470: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AE474: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AE478: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800AE47C: sh          $t5, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r13;
    // 0x800AE480: lw          $t2, 0x98($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X98);
    // 0x800AE484: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x800AE488: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800AE48C: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x800AE490: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    // 0x800AE494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800AE498: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE49C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AE4A0: nop

    // 0x800AE4A4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AE4A8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE4AC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE4B0: nop

    // 0x800AE4B4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE4B8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AE4BC: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AE4C0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800AE4C4: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AE4C8: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800AE4CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE4D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800AE4D4: nop

    // 0x800AE4D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800AE4DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE4E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE4E4: nop

    // 0x800AE4E8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE4EC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800AE4F0: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800AE4F4: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800AE4F8: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
    // 0x800AE4FC: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800AE500: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE504: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AE508: nop

    // 0x800AE50C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AE510: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE514: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE518: nop

    // 0x800AE51C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE520: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AE524: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800AE528: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800AE52C: sh          $t9, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r25;
    // 0x800AE530: mul.s       $f6, $f22, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800AE534: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE538: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800AE53C: nop

    // 0x800AE540: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800AE544: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE548: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE54C: nop

    // 0x800AE550: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE554: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800AE558: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800AE55C: mul.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800AE560: sh          $t7, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r15;
    // 0x800AE564: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800AE568: mul.s       $f6, $f26, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x800AE56C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AE570: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800AE574: nop

    // 0x800AE578: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800AE57C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE580: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE584: nop

    // 0x800AE588: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE58C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800AE590: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800AE594: mul.s       $f4, $f24, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800AE598: sh          $t5, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r13;
    // 0x800AE59C: lui         $t8, 0x4000
    ctx->r24 = S32(0X4000 << 16);
    // 0x800AE5A0: lui         $t5, 0x4002
    ctx->r13 = S32(0X4002 << 16);
    // 0x800AE5A4: mul.s       $f6, $f26, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x800AE5A8: ori         $t8, $t8, 0x102
    ctx->r24 = ctx->r24 | 0X102;
    // 0x800AE5AC: ori         $t5, $t5, 0x300
    ctx->r13 = ctx->r13 | 0X300;
    // 0x800AE5B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AE5B4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800AE5B8: nop

    // 0x800AE5BC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800AE5C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AE5C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AE5C8: nop

    // 0x800AE5CC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AE5D0: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800AE5D4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800AE5D8: sh          $t6, 0x20($v0)
    MEM_H(0X20, ctx->r2) = ctx->r14;
    // 0x800AE5DC: lw          $t7, -0x7E34($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7E34);
    // 0x800AE5E0: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x800AE5E4: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE5E8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800AE5EC: sh          $t0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r8;
    // 0x800AE5F0: sh          $t2, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r10;
    // 0x800AE5F4: sh          $s1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r17;
    // 0x800AE5F8: sh          $t2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r10;
    // 0x800AE5FC: sh          $s1, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r17;
    // 0x800AE600: sh          $s2, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r18;
    // 0x800AE604: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x800AE608: sh          $s1, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r17;
    // 0x800AE60C: sh          $s2, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r18;
    // 0x800AE610: sh          $t0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r8;
    // 0x800AE614: sh          $s2, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = ctx->r18;
    // 0x800AE618: sh          $t0, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r8;
    // 0x800AE61C: sh          $t2, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r10;
    // 0x800AE620: lbu         $t9, 0x10($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X10);
    // 0x800AE624: lbu         $t7, 0x11($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X11);
    // 0x800AE628: sll         $t6, $t9, 24
    ctx->r14 = S32(ctx->r25 << 24);
    // 0x800AE62C: lbu         $t9, 0x12($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X12);
    // 0x800AE630: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800AE634: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x800AE638: sll         $t7, $t9, 8
    ctx->r15 = S32(ctx->r25 << 8);
    // 0x800AE63C: lbu         $t8, 0x13($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X13);
    // 0x800AE640: or          $t6, $t5, $t7
    ctx->r14 = ctx->r13 | ctx->r15;
    // 0x800AE644: lbu         $t5, 0x14($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X14);
    // 0x800AE648: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800AE64C: lbu         $t8, 0x15($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X15);
    // 0x800AE650: sll         $t7, $t5, 16
    ctx->r15 = S32(ctx->r13 << 16);
    // 0x800AE654: or          $a2, $t6, $v1
    ctx->r6 = ctx->r14 | ctx->r3;
    // 0x800AE658: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x800AE65C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800AE660: sll         $t5, $t8, 8
    ctx->r13 = S32(ctx->r24 << 8);
    // 0x800AE664: or          $a3, $t6, $t5
    ctx->r7 = ctx->r14 | ctx->r13;
    // 0x800AE668: jal         0x8007F9E4
    // 0x800AE66C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x800AE66C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    after_4:
    // 0x800AE670: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x800AE674: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800AE678: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AE67C: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE680: lh          $a0, 0xA($s3)
    ctx->r4 = MEM_H(ctx->r19, 0XA);
    // 0x800AE684: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x800AE688: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x800AE68C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800AE690: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x800AE694: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800AE698: or          $t5, $t6, $at
    ctx->r13 = ctx->r14 | ctx->r1;
    // 0x800AE69C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800AE6A0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800AE6A4: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x800AE6A8: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800AE6AC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800AE6B0: addu        $t9, $t6, $t0
    ctx->r25 = ADD32(ctx->r14, ctx->r8);
    // 0x800AE6B4: addiu       $t1, $t1, 0x3220
    ctx->r9 = ADD32(ctx->r9, 0X3220);
    // 0x800AE6B8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800AE6BC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE6C0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800AE6C4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE6C8: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800AE6CC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AE6D0: addiu       $t3, $t3, 0x303C
    ctx->r11 = ADD32(ctx->r11, 0X303C);
    // 0x800AE6D4: addiu       $t7, $a1, 0x8
    ctx->r15 = ADD32(ctx->r5, 0X8);
    // 0x800AE6D8: sw          $t7, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r15;
    // 0x800AE6DC: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AE6E0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800AE6E4: addiu       $t4, $t4, -0x7E28
    ctx->r12 = ADD32(ctx->r12, -0X7E28);
    // 0x800AE6E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE6EC: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE6F0: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE6F4: andi        $t7, $t5, 0x6
    ctx->r15 = ctx->r13 & 0X6;
    // 0x800AE6F8: ori         $t8, $t7, 0x18
    ctx->r24 = ctx->r15 | 0X18;
    // 0x800AE6FC: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x800AE700: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800AE704: or          $t5, $t9, $at
    ctx->r13 = ctx->r25 | ctx->r1;
    // 0x800AE708: ori         $t7, $t5, 0x50
    ctx->r15 = ctx->r13 | 0X50;
    // 0x800AE70C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800AE710: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800AE714: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800AE718: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800AE71C: mflo        $t6
    ctx->r14 = lo;
    // 0x800AE720: addu        $t9, $t3, $t6
    ctx->r25 = ADD32(ctx->r11, ctx->r14);
    // 0x800AE724: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE728: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x800AE72C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE730: lui         $t6, 0x511
    ctx->r14 = S32(0X511 << 16);
    // 0x800AE734: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE738: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE73C: ori         $t6, $t6, 0x20
    ctx->r14 = ctx->r14 | 0X20;
    // 0x800AE740: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE744: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x800AE748: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800AE74C: addu        $t5, $t9, $t0
    ctx->r13 = ADD32(ctx->r25, ctx->r8);
    // 0x800AE750: sw          $t5, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r13;
    // 0x800AE754: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800AE758: nop

    // 0x800AE75C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x800AE760: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x800AE764: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x800AE768: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x800AE76C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800AE770: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800AE774: addiu       $t5, $t9, 0x4
    ctx->r13 = ADD32(ctx->r25, 0X4);
    // 0x800AE778: andi        $t7, $t5, 0xF
    ctx->r15 = ctx->r13 & 0XF;
    // 0x800AE77C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800AE780: sw          $t8, -0x7E34($at)
    MEM_W(-0X7E34, ctx->r1) = ctx->r24;
    // 0x800AE784: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_800AE788:
    // 0x800AE788: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800AE78C:
    // 0x800AE78C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800AE790: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800AE794: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800AE798: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AE79C: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800AE7A0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800AE7A4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800AE7A8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800AE7AC: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800AE7B0: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x800AE7B4: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x800AE7B8: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800AE7BC: jr          $ra
    // 0x800AE7C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800AE7C0: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800B6F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7490: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B7494: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B7498: jr          $ra
    // 0x800B749C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800B749C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void update_camera_finish_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058BC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80058BC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058BCC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80058BD0: addiu       $s0, $s0, -0x2578
    ctx->r16 = ADD32(ctx->r16, -0X2578);
    // 0x80058BD4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058BD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80058BDC: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x80058BE0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80058BE4: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80058BE8: addiu       $t8, $zero, 0x400
    ctx->r24 = ADD32(0, 0X400);
    // 0x80058BEC: addiu       $t7, $t6, 0x200
    ctx->r15 = ADD32(ctx->r14, 0X200);
    // 0x80058BF0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x80058BF4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80058BF8: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x80058BFC: sh          $t8, 0x2($t9)
    MEM_H(0X2, ctx->r25) = ctx->r24;
    // 0x80058C00: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80058C04: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80058C08: sh          $zero, 0x4($t0)
    MEM_H(0X4, ctx->r8) = 0;
    // 0x80058C0C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80058C10: ori         $t4, $zero, 0x8000
    ctx->r12 = 0 | 0X8000;
    // 0x80058C14: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x80058C18: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058C1C: nop

    // 0x80058C20: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x80058C24: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80058C28: subu        $a0, $t4, $t3
    ctx->r4 = SUB32(ctx->r12, ctx->r11);
    // 0x80058C2C: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x80058C30: jal         0x80070A04
    // 0x80058C34: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80058C34: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_0:
    // 0x80058C38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058C3C: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x80058C40: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80058C44: nop

    // 0x80058C48: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80058C4C: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x80058C50: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80058C54: nop

    // 0x80058C58: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    // 0x80058C5C: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80058C60: jal         0x80070A38
    // 0x80058C64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80058C64: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_1:
    // 0x80058C68: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80058C6C: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80058C70: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058C74: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058C78: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80058C7C: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80058C80: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x80058C84: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80058C88: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80058C8C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80058C90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058C94: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058C98: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058C9C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80058CA0: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80058CA4: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x80058CA8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058CAC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058CB0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80058CB4: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80058CB8: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80058CBC: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058CC0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80058CC4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80058CC8: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x80058CCC: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80058CD0: c.lt.d      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.d < ctx->f6.d;
    // 0x80058CD4: nop

    // 0x80058CD8: bc1f        L_80058D04
    if (!c1cs) {
        // 0x80058CDC: nop
    
            goto L_80058D04;
    }
    // 0x80058CDC: nop

    // 0x80058CE0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058CE4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058CE8: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x80058CEC: add.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f2.d + ctx->f10.d;
    // 0x80058CF0: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80058CF4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80058CF8: swc1        $f10, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f10.u32l;
    // 0x80058CFC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058D00: nop

L_80058D04:
    // 0x80058D04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058D08: nop

    // 0x80058D0C: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80058D10: nop

    // 0x80058D14: bc1f        L_80058D34
    if (!c1cs) {
        // 0x80058D18: nop
    
            goto L_80058D34;
    }
    // 0x80058D18: nop

    // 0x80058D1C: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058D20: nop

    // 0x80058D24: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80058D28: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x80058D2C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058D30: nop

L_80058D34:
    // 0x80058D34: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x80058D38: nop

    // 0x80058D3C: add.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80058D40: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x80058D44: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058D48: nop

    // 0x80058D4C: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80058D50: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80058D54: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x80058D58: jal         0x80029F58
    // 0x80058D5C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_2;
    // 0x80058D5C: nop

    after_2:
    // 0x80058D60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058D64: beq         $v0, $at, L_80058D78
    if (ctx->r2 == ctx->r1) {
        // 0x80058D68: nop
    
            goto L_80058D78;
    }
    // 0x80058D68: nop

    // 0x80058D6C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80058D70: nop

    // 0x80058D74: sh          $v0, 0x34($t1)
    MEM_H(0X34, ctx->r9) = ctx->r2;
L_80058D78:
    // 0x80058D78: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80058D7C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80058D80: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80058D84: nop

    // 0x80058D88: sh          $t4, 0x196($t3)
    MEM_H(0X196, ctx->r11) = ctx->r12;
    // 0x80058D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80058D90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058D94: jr          $ra
    // 0x80058D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80058D98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mempool_free_queue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071680: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80071684: addiu       $a1, $a1, 0x4348
    ctx->r5 = ADD32(ctx->r5, 0X4348);
    // 0x80071688: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007168C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80071690: addiu       $t7, $t7, 0x3B48
    ctx->r15 = ADD32(ctx->r15, 0X3B48);
    // 0x80071694: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x80071698: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x8007169C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800716A0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800716A4: lw          $t8, 0x434C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X434C);
    // 0x800716A8: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800716AC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800716B0: jr          $ra
    // 0x800716B4: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800716B4: sb          $t8, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void enable_pal_viewport_height_adjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800662D8: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800662DC: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800662E0: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x800662E4: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x800662E8: bne         $t8, $zero, L_800662F8
    if (ctx->r24 != 0) {
        // 0x800662EC: sw          $a0, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r4;
            goto L_800662F8;
    }
    // 0x800662EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800662F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800662F4: sb          $t7, 0x1295($at)
    MEM_B(0X1295, ctx->r1) = ctx->r15;
L_800662F8:
    // 0x800662F8: jr          $ra
    // 0x800662FC: nop

    return;
    // 0x800662FC: nop

;}
RECOMP_FUNC void mark_to_read_flap_and_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ED9C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EDA0: addiu       $v0, $v0, -0x2714
    ctx->r2 = ADD32(ctx->r2, -0X2714);
    // 0x8006EDA4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EDA8: nop

    // 0x8006EDAC: ori         $t7, $t6, 0x3
    ctx->r15 = ctx->r14 | 0X3;
    // 0x8006EDB0: jr          $ra
    // 0x8006EDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EDB4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void camDisableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066AD4: beq         $a1, $zero, L_80066B10
    if (ctx->r5 == 0) {
        // 0x80066AD8: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80066B10;
    }
    // 0x80066AD8: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80066ADC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066AE0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066AE4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AE8: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066AEC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066AF0: addiu       $t7, $t7, -0x2A2C
    ctx->r15 = ADD32(ctx->r15, -0X2A2C);
    // 0x80066AF4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066AF8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066AFC: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066B00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80066B04: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80066B08: b           L_80066B3C
    // 0x80066B0C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066B3C;
    // 0x80066B0C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066B10:
    // 0x80066B10: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80066B14: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066B18: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80066B1C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066B20: addiu       $t1, $t1, -0x2A2C
    ctx->r9 = ADD32(ctx->r9, -0X2A2C);
    // 0x80066B24: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80066B28: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80066B2C: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066B30: nop

    // 0x80066B34: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80066B38: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066B3C:
    // 0x80066B3C: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066B40: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80066B44: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x80066B48: jr          $ra
    // 0x80066B4C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066B4C: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_80023568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002359C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800235A0: lb          $t6, -0x4D44($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X4D44);
    // 0x800235A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800235A8: beq         $t6, $zero, L_800235C0
    if (ctx->r14 == 0) {
        // 0x800235AC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800235C0;
    }
    // 0x800235AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800235B0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235B4: lb          $v0, -0x4D5B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5B);
    // 0x800235B8: b           L_800235E4
    // 0x800235BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235E4;
    // 0x800235BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800235C0:
    // 0x800235C0: jal         0x8006BFD8
    // 0x800235C4: nop

    level_type(rdram, ctx);
        goto after_0;
    // 0x800235C4: nop

    after_0:
    // 0x800235C8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800235CC: bne         $v0, $at, L_800235E0
    if (ctx->r2 != ctx->r1) {
        // 0x800235D0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800235E0;
    }
    // 0x800235D0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235D4: lb          $v0, -0x4D5B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D5B);
    // 0x800235D8: b           L_800235E4
    // 0x800235DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
        goto L_800235E4;
    // 0x800235DC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800235E0:
    // 0x800235E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800235E4:
    // 0x800235E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800235E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800235EC: jr          $ra
    // 0x800235F0: nop

    return;
    // 0x800235F0: nop

;}
RECOMP_FUNC void obj_loop_vehicleanim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003813C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038140: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80038144: jal         0x8001F494
    // 0x80038148: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x80038148: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x8003814C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038150: nop

    // 0x80038154: lw          $v1, 0x60($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X60);
    // 0x80038158: nop

    // 0x8003815C: beq         $v1, $zero, L_800381C0
    if (ctx->r3 == 0) {
        // 0x80038160: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800381C0;
    }
    // 0x80038160: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038164: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80038168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8003816C: blez        $v0, L_800381BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038170: addiu       $t6, $zero, 0x4000
        ctx->r14 = ADD32(0, 0X4000);
            goto L_800381BC;
    }
    // 0x80038170: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x80038174: bne         $v0, $at, L_80038188
    if (ctx->r2 != ctx->r1) {
        // 0x80038178: nop
    
            goto L_80038188;
    }
    // 0x80038178: nop

    // 0x8003817C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80038180: b           L_80038194
    // 0x80038184: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
        goto L_80038194;
    // 0x80038184: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038188:
    // 0x80038188: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8003818C: nop

    // 0x80038190: lb          $t7, 0x3A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X3A);
L_80038194:
    // 0x80038194: lw          $t9, 0x40($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X40);
    // 0x80038198: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8003819C: sb          $t8, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = ctx->r24;
    // 0x800381A0: sh          $t6, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r14;
    // 0x800381A4: lb          $t1, 0x3A($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X3A);
    // 0x800381A8: lb          $t0, 0x55($t9)
    ctx->r8 = MEM_B(ctx->r25, 0X55);
    // 0x800381AC: nop

    // 0x800381B0: bne         $t0, $t1, L_800381C0
    if (ctx->r8 != ctx->r9) {
        // 0x800381B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800381C0;
    }
    // 0x800381B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800381B8: sb          $zero, 0x3A($v0)
    MEM_B(0X3A, ctx->r2) = 0;
L_800381BC:
    // 0x800381BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800381C0:
    // 0x800381C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800381C4: jr          $ra
    // 0x800381C8: nop

    return;
    // 0x800381C8: nop

;}
RECOMP_FUNC void func_8005B818(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005B884: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x8005B888: sw          $s3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r19;
    // 0x8005B88C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005B890: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8005B894: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x8005B898: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8005B89C: sw          $s2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r18;
    // 0x8005B8A0: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8005B8A4: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8005B8A8: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x8005B8AC: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8005B8B0: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x8005B8B4: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8005B8B8: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x8005B8BC: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005B8C0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8005B8C4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005B8C8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8005B8CC: sw          $a2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r6;
    // 0x8005B8D0: sw          $a3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r7;
    // 0x8005B8D4: jal         0x8001E2D0
    // 0x8005B8D8: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8005B8D8: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    after_0:
    // 0x8005B8DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005B8E0: jal         0x8006BFF0
    // 0x8005B8E4: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    level_header(rdram, ctx);
        goto after_1;
    // 0x8005B8E4: sw          $v0, -0x251C($at)
    MEM_W(-0X251C, ctx->r1) = ctx->r2;
    after_1:
    // 0x8005B8E8: jal         0x8001BA98
    // 0x8005B8EC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    get_checkpoint_count(rdram, ctx);
        goto after_2;
    // 0x8005B8EC: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    after_2:
    // 0x8005B8F0: beq         $v0, $zero, L_8005C3B8
    if (ctx->r2 == 0) {
        // 0x8005B8F4: sw          $v0, 0x114($sp)
        MEM_W(0X114, ctx->r29) = ctx->r2;
            goto L_8005C3B8;
    }
    // 0x8005B8F4: sw          $v0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r2;
    // 0x8005B8F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005B8FC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8005B900: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005B904: sb          $zero, 0x1C9($s1)
    MEM_B(0X1C9, ctx->r17) = 0;
    // 0x8005B908: sb          $zero, 0x1F5($s1)
    MEM_B(0X1F5, ctx->r17) = 0;
    // 0x8005B90C: sb          $zero, 0x187($s1)
    MEM_B(0X187, ctx->r17) = 0;
    // 0x8005B910: swc1        $f4, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f4.u32l;
    // 0x8005B914: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8005B918: swc1        $f2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f2.u32l;
    // 0x8005B91C: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B920: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005B924: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B928: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8005B92C: nop

    // 0x8005B930: bc1f        L_8005B948
    if (!c1cs) {
        // 0x8005B934: nop
    
            goto L_8005B948;
    }
    // 0x8005B934: nop

    // 0x8005B938: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8005B93C: swc1        $f8, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f8.u32l;
    // 0x8005B940: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B944: nop

L_8005B948:
    // 0x8005B948: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005B94C: nop

    // 0x8005B950: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8005B954: nop

    // 0x8005B958: bc1f        L_8005B96C
    if (!c1cs) {
        // 0x8005B95C: nop
    
            goto L_8005B96C;
    }
    // 0x8005B95C: nop

    // 0x8005B960: swc1        $f10, 0x124($s1)
    MEM_W(0X124, ctx->r17) = ctx->f10.u32l;
    // 0x8005B964: lwc1        $f0, 0x124($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X124);
    // 0x8005B968: nop

L_8005B96C:
    // 0x8005B96C: lwc1        $f5, 0x6F50($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6F50);
    // 0x8005B970: lwc1        $f4, 0x6F54($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F54);
    // 0x8005B974: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B978: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005B97C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B980: lwc1        $f9, 0x6F58($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F58);
    // 0x8005B984: lwc1        $f8, 0x6F5C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F5C);
    // 0x8005B988: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B98C: lwc1        $f19, 0x6F60($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X6F60);
    // 0x8005B990: lwc1        $f18, 0x6F64($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X6F64);
    // 0x8005B994: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005B998: nop

    // 0x8005B99C: div.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f18.d);
    // 0x8005B9A0: jal         0x800CA030
    // 0x8005B9A4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8005B9A4: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    after_3:
    // 0x8005B9A8: lb          $t6, 0x1D3($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005B9AC: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x8005B9B0: beq         $t6, $zero, L_8005B9D0
    if (ctx->r14 == 0) {
        // 0x8005B9B4: addiu       $v1, $sp, 0xF8
        ctx->r3 = ADD32(ctx->r29, 0XF8);
            goto L_8005B9D0;
    }
    // 0x8005B9B4: addiu       $v1, $sp, 0xF8
    ctx->r3 = ADD32(ctx->r29, 0XF8);
    // 0x8005B9B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005B9BC: lwc1        $f9, 0x6F68($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F68);
    // 0x8005B9C0: lwc1        $f8, 0x6F6C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F6C);
    // 0x8005B9C4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005B9C8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005B9CC: cvt.s.d     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f12.fl = CVT_S_D(ctx->f10.d);
L_8005B9D0:
    // 0x8005B9D0: lb          $t7, 0x1D6($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1D6);
    // 0x8005B9D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005B9D8: bne         $t7, $at, L_8005BAD8
    if (ctx->r15 != ctx->r1) {
        // 0x8005B9DC: addiu       $a2, $sp, 0xE4
        ctx->r6 = ADD32(ctx->r29, 0XE4);
            goto L_8005BAD8;
    }
    // 0x8005B9DC: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8005B9E0: lh          $t8, 0x1BE($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005B9E4: lh          $t2, 0x1C2($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X1C2);
    // 0x8005B9E8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8005B9EC: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x8005B9F0: subu        $v0, $t9, $t3
    ctx->r2 = SUB32(ctx->r25, ctx->r11);
    // 0x8005B9F4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005B9F8: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005B9FC: bne         $at, $zero, L_8005BA0C
    if (ctx->r1 != 0) {
        // 0x8005BA00: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005BA0C;
    }
    // 0x8005BA00: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005BA04: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005BA08: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005BA0C:
    // 0x8005BA0C: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x8005BA10: beq         $at, $zero, L_8005BA1C
    if (ctx->r1 == 0) {
        // 0x8005BA14: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005BA1C;
    }
    // 0x8005BA14: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005BA18: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_8005BA1C:
    // 0x8005BA1C: bgez        $v0, L_8005BA28
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005BA20: nop
    
            goto L_8005BA28;
    }
    // 0x8005BA20: nop

    // 0x8005BA24: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8005BA28:
    // 0x8005BA28: addiu       $v0, $v0, -0xC8
    ctx->r2 = ADD32(ctx->r2, -0XC8);
    // 0x8005BA2C: bgez        $v0, L_8005BA38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005BA30: nop
    
            goto L_8005BA38;
    }
    // 0x8005BA30: nop

    // 0x8005BA34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005BA38:
    // 0x8005BA38: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x8005BA3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BA40: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005BA44: lwc1        $f9, 0x6F70($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6F70);
    // 0x8005BA48: lwc1        $f8, 0x6F74($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6F74);
    // 0x8005BA4C: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BA50: nop

    // 0x8005BA54: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8005BA58: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA5C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005BA60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005BA64: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005BA68: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BA6C: sub.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8005BA70: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x8005BA74: cvt.d.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BA78: c.lt.d      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.d < ctx->f4.d;
    // 0x8005BA7C: nop

    // 0x8005BA80: bc1f        L_8005BA90
    if (!c1cs) {
        // 0x8005BA84: nop
    
            goto L_8005BA90;
    }
    // 0x8005BA84: nop

    // 0x8005BA88: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005BA8C: nop

L_8005BA90:
    // 0x8005BA90: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BA94: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x8005BA98: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8005BA9C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8005BAA0: bc1f        L_8005BAB0
    if (!c1cs) {
        // 0x8005BAA4: nop
    
            goto L_8005BAB0;
    }
    // 0x8005BAA4: nop

    // 0x8005BAA8: b           L_8005BB08
    // 0x8005BAAC: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
        goto L_8005BB08;
    // 0x8005BAAC: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
L_8005BAB0:
    // 0x8005BAB0: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8005BAB4: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8005BAB8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BABC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005BAC0: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8005BAC4: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BAC8: add.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d + ctx->f18.d;
    // 0x8005BACC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8005BAD0: b           L_8005BB08
    // 0x8005BAD4: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
        goto L_8005BB08;
    // 0x8005BAD4: swc1        $f8, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f8.u32l;
L_8005BAD8:
    // 0x8005BAD8: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BADC: neg.s       $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = -ctx->f12.fl;
    // 0x8005BAE0: sub.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x8005BAE4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005BAE8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005BAEC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BAF0: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BAF4: mul.d       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x8005BAF8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8005BAFC: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x8005BB00: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x8005BB04: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
L_8005BB08:
    // 0x8005BB08: lb          $a0, 0x192($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X192);
    // 0x8005BB0C: addiu       $a3, $sp, 0xD0
    ctx->r7 = ADD32(ctx->r29, 0XD0);
    // 0x8005BB10: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8005BB14: bgez        $a0, L_8005BB28
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8005BB18: addiu       $t1, $sp, 0xB0
        ctx->r9 = ADD32(ctx->r29, 0XB0);
            goto L_8005BB28;
    }
    // 0x8005BB18: addiu       $t1, $sp, 0xB0
    ctx->r9 = ADD32(ctx->r29, 0XB0);
    // 0x8005BB1C: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x8005BB20: nop

    // 0x8005BB24: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
L_8005BB28:
    // 0x8005BB28: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x8005BB2C: addiu       $t0, $sp, 0x9C
    ctx->r8 = ADD32(ctx->r29, 0X9C);
    // 0x8005BB30: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005BB34: bne         $at, $zero, L_8005BB40
    if (ctx->r1 != 0) {
        // 0x8005BB38: addiu       $s0, $sp, 0xB0
        ctx->r16 = ADD32(ctx->r29, 0XB0);
            goto L_8005BB40;
    }
    // 0x8005BB38: addiu       $s0, $sp, 0xB0
    ctx->r16 = ADD32(ctx->r29, 0XB0);
    // 0x8005BB3C: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
L_8005BB40:
    // 0x8005BB40: lbu         $a1, 0x1C8($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X1C8);
    // 0x8005BB44: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8005BB48: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    // 0x8005BB4C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x8005BB50: sw          $a2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r6;
    // 0x8005BB54: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x8005BB58: jal         0x8001BA50
    // 0x8005BB5C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    find_next_checkpoint_node(rdram, ctx);
        goto after_4;
    // 0x8005BB5C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005BB60: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x8005BB64: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8005BB68: lw          $a0, 0x118($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X118);
    // 0x8005BB6C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x8005BB70: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x8005BB74: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8005BB78: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8005BB7C: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x8005BB80: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005BB84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005BB88: swc1        $f10, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f10.u32l;
    // 0x8005BB8C: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8005BB90: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005BB94: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8005BB98: lb          $t4, 0x1CA($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BB9C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005BBA0: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005BBA4: lb          $t6, 0x2E($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X2E);
    // 0x8005BBA8: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005BBAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8005BBB0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005BBB4: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005BBB8: swc1        $f18, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f18.u32l;
    // 0x8005BBBC: lb          $t7, 0x1CA($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBC0: nop

    // 0x8005BBC4: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8005BBC8: lb          $t2, 0x32($t8)
    ctx->r10 = MEM_B(ctx->r24, 0X32);
    // 0x8005BBCC: nop

    // 0x8005BBD0: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005BBD4: nop

    // 0x8005BBD8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BBDC: swc1        $f10, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->f10.u32l;
    // 0x8005BBE0: lb          $t9, 0x1CA($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BBE4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BBE8: addu        $t3, $v0, $t9
    ctx->r11 = ADD32(ctx->r2, ctx->r25);
    // 0x8005BBEC: lb          $t4, 0x2E($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X2E);
    // 0x8005BBF0: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8005BBF4: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8005BBF8: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BBFC: lwc1        $f4, -0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, -0X4);
    // 0x8005BC00: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005BC04: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x8005BC08: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8005BC0C: swc1        $f6, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f6.u32l;
    // 0x8005BC10: lb          $t5, 0x1CA($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BC14: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BC18: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x8005BC1C: lb          $t7, 0x32($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X32);
    // 0x8005BC20: lwc1        $f6, -0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, -0X4);
    // 0x8005BC24: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8005BC28: nop

    // 0x8005BC2C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BC30: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8005BC34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8005BC38: swc1        $f10, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f10.u32l;
    // 0x8005BC3C: lb          $t8, 0x1CA($s1)
    ctx->r24 = MEM_B(ctx->r17, 0X1CA);
    // 0x8005BC40: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005BC44: addu        $t2, $v0, $t8
    ctx->r10 = ADD32(ctx->r2, ctx->r24);
    // 0x8005BC48: lb          $t9, 0x2E($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X2E);
    // 0x8005BC4C: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8005BC50: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005BC54: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8005BC58: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x8005BC5C: lwc1        $f6, -0x4($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, -0X4);
    // 0x8005BC60: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005BC64: mul.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8005BC68: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x8005BC6C: swc1        $f10, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = ctx->f10.u32l;
    // 0x8005BC70: lw          $t3, 0x114($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X114);
    // 0x8005BC74: nop

    // 0x8005BC78: bne         $a0, $t3, L_8005BC84
    if (ctx->r4 != ctx->r11) {
        // 0x8005BC7C: nop
    
            goto L_8005BC84;
    }
    // 0x8005BC7C: nop

    // 0x8005BC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8005BC84:
    // 0x8005BC84: bne         $t0, $s0, L_8005BB40
    if (ctx->r8 != ctx->r16) {
        // 0x8005BC88: addiu       $t1, $t1, 0x4
        ctx->r9 = ADD32(ctx->r9, 0X4);
            goto L_8005BB40;
    }
    // 0x8005BC88: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8005BC8C: lwc1        $f8, 0x2C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8005BC90: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005BC94: swc1        $f8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f8.u32l;
    // 0x8005BC98: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005BC9C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x8005BCA0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8005BCA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8005BCA8: bc1f        L_8005BCB8
    if (!c1cs) {
        // 0x8005BCAC: nop
    
            goto L_8005BCB8;
    }
    // 0x8005BCAC: nop

    // 0x8005BCB0: neg.s       $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = -ctx->f4.fl;
    // 0x8005BCB4: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
L_8005BCB8:
    // 0x8005BCB8: lwc1        $f8, 0xAC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BCBC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BCC0: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005BCC4: c.eq.d      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.d == ctx->f6.d;
    // 0x8005BCC8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BCCC: bc1f        L_8005BCE0
    if (!c1cs) {
        // 0x8005BCD0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005BCE0;
    }
    // 0x8005BCD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BCD4: lwc1        $f4, 0x6F78($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F78);
    // 0x8005BCD8: nop

    // 0x8005BCDC: swc1        $f4, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f4.u32l;
L_8005BCE0:
    // 0x8005BCE0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8005BCE4: mtc1        $at, $f21
    ctx->f_odd[(21 - 1) * 2] = ctx->r1;
    // 0x8005BCE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8005BCEC:
    // 0x8005BCEC: lwc1        $f18, 0xAC($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BCF0: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BCF4: lwc1        $f4, 0xA8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BCF8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8005BCFC: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x8005BD00: addiu       $a0, $sp, 0xF8
    ctx->r4 = ADD32(ctx->r29, 0XF8);
    // 0x8005BD04: addiu       $a3, $sp, 0x94
    ctx->r7 = ADD32(ctx->r29, 0X94);
    // 0x8005BD08: sub.d       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f20.d - ctx->f18.d;
    // 0x8005BD0C: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BD10: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005BD14: cvt.s.d     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f22.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BD18: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BD1C: c.le.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d <= ctx->f2.d;
    // 0x8005BD20: nop

    // 0x8005BD24: bc1f        L_8005BD38
    if (!c1cs) {
        // 0x8005BD28: nop
    
            goto L_8005BD38;
    }
    // 0x8005BD28: nop

    // 0x8005BD2C: sub.d       $f4, $f2, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f2.d - ctx->f20.d;
    // 0x8005BD30: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8005BD34: cvt.s.d     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f22.fl = CVT_S_D(ctx->f4.d);
L_8005BD38:
    // 0x8005BD38: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD3C: jal         0x80022670
    // 0x8005BD40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    cubic_spline_interpolation(rdram, ctx);
        goto after_5;
    // 0x8005BD40: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8005BD44: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD48: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8005BD4C: addiu       $a0, $sp, 0xE4
    ctx->r4 = ADD32(ctx->r29, 0XE4);
    // 0x8005BD50: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BD54: jal         0x80022670
    // 0x8005BD58: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    cubic_spline_interpolation(rdram, ctx);
        goto after_6;
    // 0x8005BD58: addiu       $a3, $sp, 0x90
    ctx->r7 = ADD32(ctx->r29, 0X90);
    after_6:
    // 0x8005BD5C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x8005BD60: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8005BD64: addiu       $a0, $sp, 0xD0
    ctx->r4 = ADD32(ctx->r29, 0XD0);
    // 0x8005BD68: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8005BD6C: jal         0x80022670
    // 0x8005BD70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_7;
    // 0x8005BD70: addiu       $a3, $sp, 0x8C
    ctx->r7 = ADD32(ctx->r29, 0X8C);
    after_7:
    // 0x8005BD74: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BD78: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BD7C: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BD80: sub.s       $f26, $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f18.fl;
    // 0x8005BD84: sub.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x8005BD88: bne         $s0, $zero, L_8005BE0C
    if (ctx->r16 != 0) {
        // 0x8005BD8C: sub.s       $f28, $f0, $f6
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f6.fl;
            goto L_8005BE0C;
    }
    // 0x8005BD8C: sub.s       $f28, $f0, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8005BD90: mul.s       $f10, $f26, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BD94: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8005BD98: mul.s       $f4, $f24, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8005BD9C: nop

    // 0x8005BDA0: mul.s       $f8, $f28, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BDA4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8005BDA8: jal         0x800CA030
    // 0x8005BDAC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005BDAC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_8:
    // 0x8005BDB0: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BDB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005BDB8: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005BDBC: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8005BDC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BDC4: c.eq.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl == ctx->f12.fl;
    // 0x8005BDC8: nop

    // 0x8005BDCC: bc1t        L_8005BDEC
    if (c1cs) {
        // 0x8005BDD0: nop
    
            goto L_8005BDEC;
    }
    // 0x8005BDD0: nop

    // 0x8005BDD4: div.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8005BDD8: lwc1        $f4, 0xAC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BDDC: nop

    // 0x8005BDE0: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005BDE4: b           L_8005BE0C
    // 0x8005BDE8: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
        goto L_8005BE0C;
    // 0x8005BDE8: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
L_8005BDEC:
    // 0x8005BDEC: lwc1        $f10, 0xAC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XAC);
    // 0x8005BDF0: lwc1        $f5, 0x6F80($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6F80);
    // 0x8005BDF4: lwc1        $f4, 0x6F84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6F84);
    // 0x8005BDF8: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005BDFC: add.d       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f18.d + ctx->f4.d;
    // 0x8005BE00: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x8005BE04: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x8005BE08: swc1        $f6, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->f6.u32l;
L_8005BE0C:
    // 0x8005BE0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8005BE10: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x8005BE14: bne         $at, $zero, L_8005BCEC
    if (ctx->r1 != 0) {
        // 0x8005BE18: nop
    
            goto L_8005BCEC;
    }
    // 0x8005BE18: nop

    // 0x8005BE1C: lwc1        $f10, 0x68($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BE20: lwc1        $f4, 0x6C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BE24: lwc1        $f6, 0x70($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BE28: add.s       $f18, $f10, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f26.fl;
    // 0x8005BE2C: add.s       $f8, $f4, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x8005BE30: swc1        $f18, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f18.u32l;
    // 0x8005BE34: add.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x8005BE38: swc1        $f8, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->f8.u32l;
    // 0x8005BE3C: swc1        $f10, 0x70($s1)
    MEM_W(0X70, ctx->r17) = ctx->f10.u32l;
    // 0x8005BE40: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005BE44: lwc1        $f18, 0x68($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8005BE48: lwc1        $f10, 0x70($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X70);
    // 0x8005BE4C: sub.s       $f26, $f18, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8005BE50: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005BE54: mul.s       $f4, $f26, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8005BE58: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005BE5C: lwc1        $f8, 0x6C($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X6C);
    // 0x8005BE60: sub.s       $f28, $f10, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005BE64: sub.s       $f24, $f8, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x8005BE68: mul.s       $f8, $f28, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x8005BE6C: cvt.d.s     $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f2.d = CVT_D_S(ctx->f22.fl);
    // 0x8005BE70: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x8005BE74: swc1        $f3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f_odd[(3 - 1) * 2];
    // 0x8005BE78: jal         0x800CA030
    // 0x8005BE7C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_9;
    // 0x8005BE7C: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    after_9:
    // 0x8005BE80: lwc1        $f6, 0x12C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005BE84: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005BE88: div.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8005BE8C: lwc1        $f17, 0x6F88($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, 0X6F88);
    // 0x8005BE90: lwc1        $f16, 0x6F8C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6F8C);
    // 0x8005BE94: lwc1        $f3, 0x58($sp)
    ctx->f_odd[(3 - 1) * 2] = MEM_W(ctx->r29, 0X58);
    // 0x8005BE98: lwc1        $f2, 0x5C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8005BE9C: nop

    // 0x8005BEA0: sub.d       $f18, $f20, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f20.d - ctx->f2.d;
    // 0x8005BEA4: cvt.d.s     $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f14.d = CVT_D_S(ctx->f12.fl);
    // 0x8005BEA8: c.lt.d      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.d < ctx->f14.d;
    // 0x8005BEAC: swc1        $f12, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f12.u32l;
    // 0x8005BEB0: bc1f        L_8005BED4
    if (!c1cs) {
        // 0x8005BEB4: cvt.s.d     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
            goto L_8005BED4;
    }
    // 0x8005BEB4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005BEB8: nop

    // 0x8005BEBC: div.d       $f10, $f16, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = DIV_D(ctx->f16.d, ctx->f14.d);
    // 0x8005BEC0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8005BEC4: mul.s       $f26, $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8005BEC8: nop

    // 0x8005BECC: mul.s       $f28, $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = MUL_S(ctx->f28.fl, ctx->f0.fl);
    // 0x8005BED0: nop

L_8005BED4:
    // 0x8005BED4: beq         $s2, $zero, L_8005BF68
    if (ctx->r18 == 0) {
        // 0x8005BED8: swc1        $f4, 0xA8($s1)
        MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
            goto L_8005BF68;
    }
    // 0x8005BED8: swc1        $f4, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f4.u32l;
    // 0x8005BEDC: lb          $t4, 0x192($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X192);
    // 0x8005BEE0: nop

    // 0x8005BEE4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8005BEE8: sb          $t5, 0x192($s1)
    MEM_B(0X192, ctx->r17) = ctx->r13;
    // 0x8005BEEC: lw          $t7, 0x114($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X114);
    // 0x8005BEF0: lb          $t6, 0x192($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X192);
    // 0x8005BEF4: nop

    // 0x8005BEF8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8005BEFC: bne         $at, $zero, L_8005BF30
    if (ctx->r1 != 0) {
        // 0x8005BF00: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8005BF30;
    }
    // 0x8005BF00: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8005BF04: lh          $t8, 0x190($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X190);
    // 0x8005BF08: sb          $zero, 0x192($s1)
    MEM_B(0X192, ctx->r17) = 0;
    // 0x8005BF0C: blez        $t8, L_8005BF30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8005BF10: lw          $t9, 0x78($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X78);
            goto L_8005BF30;
    }
    // 0x8005BF10: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8005BF14: lb          $v0, 0x193($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X193);
    // 0x8005BF18: nop

    // 0x8005BF1C: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x8005BF20: beq         $at, $zero, L_8005BF2C
    if (ctx->r1 == 0) {
        // 0x8005BF24: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8005BF2C;
    }
    // 0x8005BF24: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x8005BF28: sb          $t2, 0x193($s1)
    MEM_B(0X193, ctx->r17) = ctx->r10;
L_8005BF2C:
    // 0x8005BF2C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
L_8005BF30:
    // 0x8005BF30: lw          $t5, 0x114($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X114);
    // 0x8005BF34: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x8005BF38: lh          $v0, 0x190($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X190);
    // 0x8005BF3C: addiu       $t4, $t3, 0x3
    ctx->r12 = ADD32(ctx->r11, 0X3);
    // 0x8005BF40: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005BF44: addiu       $t8, $zero, 0x2710
    ctx->r24 = ADD32(0, 0X2710);
    // 0x8005BF48: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x8005BF4C: mflo        $t6
    ctx->r14 = lo;
    // 0x8005BF50: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005BF54: beq         $at, $zero, L_8005BF60
    if (ctx->r1 == 0) {
        // 0x8005BF58: nop
    
            goto L_8005BF60;
    }
    // 0x8005BF58: nop

    // 0x8005BF5C: sh          $t7, 0x190($s1)
    MEM_H(0X190, ctx->r17) = ctx->r15;
L_8005BF60:
    // 0x8005BF60: b           L_8005BFA8
    // 0x8005BF64: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
        goto L_8005BFA8;
    // 0x8005BF64: sh          $t8, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r24;
L_8005BF68:
    // 0x8005BF68: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8005BF6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005BF70: lwc1        $f8, 0xA8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XA8);
    // 0x8005BF74: nop

    // 0x8005BF78: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8005BF7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8005BF80: nop

    // 0x8005BF84: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8005BF88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BF8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BF90: nop

    // 0x8005BF94: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8005BF98: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8005BF9C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8005BFA0: sh          $t9, 0x1A8($s1)
    MEM_H(0X1A8, ctx->r17) = ctx->r25;
    // 0x8005BFA4: nop

L_8005BFA8:
    // 0x8005BFA8: lb          $v0, 0x1D3($s1)
    ctx->r2 = MEM_B(ctx->r17, 0X1D3);
    // 0x8005BFAC: lw          $t3, 0x128($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X128);
    // 0x8005BFB0: blez        $v0, L_8005BFC0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005BFB4: subu        $t4, $v0, $t3
        ctx->r12 = SUB32(ctx->r2, ctx->r11);
            goto L_8005BFC0;
    }
    // 0x8005BFB4: subu        $t4, $v0, $t3
    ctx->r12 = SUB32(ctx->r2, ctx->r11);
    // 0x8005BFB8: b           L_8005BFC4
    // 0x8005BFBC: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
        goto L_8005BFC4;
    // 0x8005BFBC: sb          $t4, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = ctx->r12;
L_8005BFC0:
    // 0x8005BFC0: sb          $zero, 0x1D3($s1)
    MEM_B(0X1D3, ctx->r17) = 0;
L_8005BFC4:
    // 0x8005BFC4: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8005BFC8: lwc1        $f8, 0xB4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x8005BFCC: nop

    // 0x8005BFD0: sub.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005BFD4: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8005BFD8: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8005BFDC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8005BFE0: nop

    // 0x8005BFE4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8005BFE8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005BFEC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005BFF0: nop

    // 0x8005BFF4: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8005BFF8: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8005BFFC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8005C000: sh          $t6, 0x1BA($s1)
    MEM_H(0X1BA, ctx->r17) = ctx->r14;
    // 0x8005C004: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8005C008: lwc1        $f6, 0xA4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8005C00C: nop

    // 0x8005C010: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8005C014: mul.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x8005C018: add.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x8005C01C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005C020: nop

    // 0x8005C024: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005C028: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005C02C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005C030: nop

    // 0x8005C034: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005C038: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8005C03C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005C040: sh          $t8, 0x1BC($s1)
    MEM_H(0X1BC, ctx->r17) = ctx->r24;
    // 0x8005C044: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005C048: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005C04C: mul.s       $f18, $f8, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8005C050: nop

    // 0x8005C054: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8005C058: jal         0x800CA030
    // 0x8005C05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_10;
    // 0x8005C05C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_10:
    // 0x8005C060: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C064: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005C068: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x8005C06C: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8005C070: bc1t        L_8005C0C8
    if (c1cs) {
        // 0x8005C074: nop
    
            goto L_8005C0C8;
    }
    // 0x8005C074: nop

    // 0x8005C078: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005C07C: div.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8005C080: nop

    // 0x8005C084: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8005C088: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x8005C08C: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005C090: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x8005C094: jal         0x80070990
    // 0x8005C098: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    arctan2_f(rdram, ctx);
        goto after_11;
    // 0x8005C098: swc1        $f10, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f10.u32l;
    after_11:
    // 0x8005C09C: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x8005C0A0: addu        $t2, $v0, $at
    ctx->r10 = ADD32(ctx->r2, ctx->r1);
    // 0x8005C0A4: sh          $t2, 0x1A0($s1)
    MEM_H(0X1A0, ctx->r17) = ctx->r10;
    // 0x8005C0A8: lh          $t9, 0x1A0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C0AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8005C0B0: sh          $t9, 0x0($s3)
    MEM_H(0X0, ctx->r19) = ctx->r25;
    // 0x8005C0B4: lwc1        $f12, 0x90($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8005C0B8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8005C0BC: jal         0x80070990
    // 0x8005C0C0: nop

    arctan2_f(rdram, ctx);
        goto after_12;
    // 0x8005C0C0: nop

    after_12:
    // 0x8005C0C4: sh          $v0, 0x2($s3)
    MEM_H(0X2, ctx->r19) = ctx->r2;
L_8005C0C8:
    // 0x8005C0C8: lh          $t3, 0x1BE($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X1BE);
    // 0x8005C0CC: lh          $t4, 0x1C0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X1C0);
    // 0x8005C0D0: lh          $t5, 0x1A0($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X1A0);
    // 0x8005C0D4: sh          $t3, 0x1C2($s1)
    MEM_H(0X1C2, ctx->r17) = ctx->r11;
    // 0x8005C0D8: sh          $t4, 0x1C4($s1)
    MEM_H(0X1C4, ctx->r17) = ctx->r12;
    // 0x8005C0DC: sh          $t5, 0x1BE($s1)
    MEM_H(0X1BE, ctx->r17) = ctx->r13;
    // 0x8005C0E0: lh          $t6, 0x2($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X2);
    // 0x8005C0E4: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x8005C0E8: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x8005C0EC: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x8005C0F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C0F4: jal         0x80011570
    // 0x8005C0F8: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    move_object(rdram, ctx);
        goto after_13;
    // 0x8005C0F8: sh          $t6, 0x1C0($s1)
    MEM_H(0X1C0, ctx->r17) = ctx->r14;
    after_13:
    // 0x8005C0FC: beq         $v0, $zero, L_8005C258
    if (ctx->r2 == 0) {
        // 0x8005C100: nop
    
            goto L_8005C258;
    }
    // 0x8005C100: nop

    // 0x8005C104: jal         0x8002C804
    // 0x8005C108: nop

    get_current_level_model(rdram, ctx);
        goto after_14;
    // 0x8005C108: nop

    after_14:
    // 0x8005C10C: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C110: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C114: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C118: add.s       $f4, $f18, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f26.fl;
    // 0x8005C11C: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8005C120: add.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x8005C124: swc1        $f4, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f4.u32l;
    // 0x8005C128: add.s       $f18, $f10, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f28.fl;
    // 0x8005C12C: swc1        $f8, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f8.u32l;
    // 0x8005C130: swc1        $f18, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f18.u32l;
    // 0x8005C134: lh          $t7, 0x3E($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3E);
    // 0x8005C138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8005C13C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8005C140: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C144: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005C148: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8005C14C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C150: nop

    // 0x8005C154: bc1f        L_8005C168
    if (!c1cs) {
        // 0x8005C158: nop
    
            goto L_8005C168;
    }
    // 0x8005C158: nop

    // 0x8005C15C: swc1        $f22, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f22.u32l;
    // 0x8005C160: lwc1        $f0, 0xC($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C164: nop

L_8005C168:
    // 0x8005C168: lh          $t8, 0x3C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3C);
    // 0x8005C16C: nop

    // 0x8005C170: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x8005C174: nop

    // 0x8005C178: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C17C: sub.s       $f22, $f10, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005C180: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C184: nop

    // 0x8005C188: bc1f        L_8005C194
    if (!c1cs) {
        // 0x8005C18C: nop
    
            goto L_8005C194;
    }
    // 0x8005C18C: nop

    // 0x8005C190: swc1        $f22, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f22.u32l;
L_8005C194:
    // 0x8005C194: lh          $t2, 0x42($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X42);
    // 0x8005C198: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005C19C: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8005C1A0: lwc1        $f6, 0x6F90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6F90);
    // 0x8005C1A4: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8005C1A8: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1AC: add.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8005C1B0: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C1B4: nop

    // 0x8005C1B8: bc1f        L_8005C1CC
    if (!c1cs) {
        // 0x8005C1BC: nop
    
            goto L_8005C1CC;
    }
    // 0x8005C1BC: nop

    // 0x8005C1C0: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
    // 0x8005C1C4: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C1C8: nop

L_8005C1CC:
    // 0x8005C1CC: lh          $t9, 0x40($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X40);
    // 0x8005C1D0: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x8005C1D4: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005C1D8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C1DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C1E0: sub.s       $f22, $f10, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x8005C1E4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C1E8: nop

    // 0x8005C1EC: bc1f        L_8005C1F8
    if (!c1cs) {
        // 0x8005C1F0: nop
    
            goto L_8005C1F8;
    }
    // 0x8005C1F0: nop

    // 0x8005C1F4: swc1        $f22, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f22.u32l;
L_8005C1F8:
    // 0x8005C1F8: lh          $t3, 0x46($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X46);
    // 0x8005C1FC: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C200: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8005C204: nop

    // 0x8005C208: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005C20C: add.s       $f22, $f6, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8005C210: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8005C214: nop

    // 0x8005C218: bc1f        L_8005C22C
    if (!c1cs) {
        // 0x8005C21C: nop
    
            goto L_8005C22C;
    }
    // 0x8005C21C: nop

    // 0x8005C220: swc1        $f22, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f22.u32l;
    // 0x8005C224: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C228: nop

L_8005C22C:
    // 0x8005C22C: lh          $t4, 0x44($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X44);
    // 0x8005C230: nop

    // 0x8005C234: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x8005C238: nop

    // 0x8005C23C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005C240: sub.s       $f22, $f10, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8005C244: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8005C248: nop

    // 0x8005C24C: bc1f        L_8005C258
    if (!c1cs) {
        // 0x8005C250: nop
    
            goto L_8005C258;
    }
    // 0x8005C250: nop

    // 0x8005C254: swc1        $f22, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f22.u32l;
L_8005C258:
    // 0x8005C258: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8005C25C: lui         $at, 0x4034
    ctx->r1 = S32(0X4034 << 16);
    // 0x8005C260: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005C264: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C268: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8005C26C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8005C270: lwc1        $f8, 0x12C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005C274: bc1f        L_8005C2A8
    if (!c1cs) {
        // 0x8005C278: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8005C2A8;
    }
    // 0x8005C278: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C27C: nop

    // 0x8005C280: div.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8005C284: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8005C288: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8005C28C: nop

    // 0x8005C290: swc1        $f18, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f18.u32l;
    // 0x8005C294: swc1        $f10, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f10.u32l;
    // 0x8005C298: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x8005C29C: nop

    // 0x8005C2A0: div.s       $f6, $f28, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f28.fl, ctx->f4.fl);
    // 0x8005C2A4: swc1        $f6, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f6.u32l;
L_8005C2A8:
    // 0x8005C2A8: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8005C2AC: jal         0x80042D60
    // 0x8005C2B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_80042D20(rdram, ctx);
        goto after_15;
    // 0x8005C2B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x8005C2B4: lw          $a2, 0x128($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X128);
    // 0x8005C2B8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C2BC: jal         0x80055F00
    // 0x8005C2C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    handle_racer_items(rdram, ctx);
        goto after_16;
    // 0x8005C2C0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_16:
    // 0x8005C2C4: sb          $zero, 0x1E5($s1)
    MEM_B(0X1E5, ctx->r17) = 0;
    // 0x8005C2C8: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C2CC: lw          $t5, 0x4C($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005C2D4: swc1        $f8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->f8.u32l;
    // 0x8005C2D8: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C2DC: lw          $t6, 0x4C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2E0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005C2E4: swc1        $f10, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->f10.u32l;
    // 0x8005C2E8: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C2EC: lw          $t7, 0x4C($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X4C);
    // 0x8005C2F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005C2F4: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    // 0x8005C2F8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8005C2FC: sb          $zero, 0x1E6($s1)
    MEM_B(0X1E6, ctx->r17) = 0;
    // 0x8005C300: sh          $zero, 0x1A2($s1)
    MEM_H(0X1A2, ctx->r17) = 0;
    // 0x8005C304: sh          $zero, 0x1A6($s1)
    MEM_H(0X1A6, ctx->r17) = 0;
    // 0x8005C308: sb          $zero, 0x1D2($s1)
    MEM_B(0X1D2, ctx->r17) = 0;
    // 0x8005C30C: swc1        $f4, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->f4.u32l;
    // 0x8005C310: swc1        $f6, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f6.u32l;
    // 0x8005C314: swc1        $f8, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f8.u32l;
    // 0x8005C318: lwc1        $f18, 0xC($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C31C: swc1        $f10, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f10.u32l;
    // 0x8005C320: swc1        $f18, 0xD8($s1)
    MEM_W(0XD8, ctx->r17) = ctx->f18.u32l;
    // 0x8005C324: lwc1        $f4, 0x10($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C328: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8005C32C: swc1        $f4, 0xDC($s1)
    MEM_W(0XDC, ctx->r17) = ctx->f4.u32l;
    // 0x8005C330: lwc1        $f6, 0x14($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C334: nop

    // 0x8005C338: swc1        $f6, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->f6.u32l;
    // 0x8005C33C: lwc1        $f8, 0xC($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C340: nop

    // 0x8005C344: swc1        $f8, 0xE4($s1)
    MEM_W(0XE4, ctx->r17) = ctx->f8.u32l;
    // 0x8005C348: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C34C: nop

    // 0x8005C350: swc1        $f10, 0xE8($s1)
    MEM_W(0XE8, ctx->r17) = ctx->f10.u32l;
    // 0x8005C354: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C358: nop

    // 0x8005C35C: swc1        $f18, 0xEC($s1)
    MEM_W(0XEC, ctx->r17) = ctx->f18.u32l;
    // 0x8005C360: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C364: nop

    // 0x8005C368: swc1        $f4, 0xF0($s1)
    MEM_W(0XF0, ctx->r17) = ctx->f4.u32l;
    // 0x8005C36C: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C370: nop

    // 0x8005C374: swc1        $f6, 0xF4($s1)
    MEM_W(0XF4, ctx->r17) = ctx->f6.u32l;
    // 0x8005C378: lwc1        $f8, 0x14($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C37C: nop

    // 0x8005C380: swc1        $f8, 0xF8($s1)
    MEM_W(0XF8, ctx->r17) = ctx->f8.u32l;
    // 0x8005C384: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8005C388: nop

    // 0x8005C38C: swc1        $f10, 0xFC($s1)
    MEM_W(0XFC, ctx->r17) = ctx->f10.u32l;
    // 0x8005C390: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8005C394: nop

    // 0x8005C398: swc1        $f18, 0x100($s1)
    MEM_W(0X100, ctx->r17) = ctx->f18.u32l;
    // 0x8005C39C: lwc1        $f4, 0x14($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8005C3A0: nop

    // 0x8005C3A4: swc1        $f4, 0x104($s1)
    MEM_W(0X104, ctx->r17) = ctx->f4.u32l;
    // 0x8005C3A8: sw          $zero, 0x74($s3)
    MEM_W(0X74, ctx->r19) = 0;
    // 0x8005C3AC: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x8005C3B0: jal         0x800AFC74
    // 0x8005C3B4: nop

    update_vehicle_particles(rdram, ctx);
        goto after_17;
    // 0x8005C3B4: nop

    after_17:
L_8005C3B8:
    // 0x8005C3B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8005C3BC: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8005C3C0: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8005C3C4: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005C3C8: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005C3CC: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8005C3D0: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8005C3D4: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8005C3D8: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005C3DC: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8005C3E0: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8005C3E4: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8005C3E8: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x8005C3EC: lw          $s2, 0x44($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X44);
    // 0x8005C3F0: lw          $s3, 0x48($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X48);
    // 0x8005C3F4: jr          $ra
    // 0x8005C3F8: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x8005C3F8: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void start_bridge_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E378: bltz        $a0, L_8001E398
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001E37C: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_8001E398;
    }
    // 0x8001E37C: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8001E380: beq         $at, $zero, L_8001E398
    if (ctx->r1 == 0) {
        // 0x8001E384: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8001E398;
    }
    // 0x8001E384: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001E388: lw          $t7, -0x4CB4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4CB4);
    // 0x8001E38C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x8001E390: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8001E394: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
L_8001E398:
    // 0x8001E398: jr          $ra
    // 0x8001E39C: nop

    return;
    // 0x8001E39C: nop

;}
RECOMP_FUNC void cheatlist_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B1D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008B1D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008B1DC: jal         0x8009CA4C
    // 0x8008B1E0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8008B1E0: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_0:
    // 0x8008B1E4: jal         0x800C478C
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8008B1E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8008B1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008B1F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008B1F4: jr          $ra
    // 0x8008B1F8: nop

    return;
    // 0x8008B1F8: nop

;}
RECOMP_FUNC void tri2d_xz_contains_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070730: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x80070734: lh          $t0, 0x0($a2)
    ctx->r8 = MEM_H(ctx->r6, 0X0);
    // 0x80070738: lh          $t1, 0x4($a2)
    ctx->r9 = MEM_H(ctx->r6, 0X4);
    // 0x8007073C: lh          $t3, 0x4($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X4);
    // 0x80070740: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80070744: lh          $t5, 0x4($t6)
    ctx->r13 = MEM_H(ctx->r14, 0X4);
    // 0x80070748: sub         $t6, $a0, $t0
    ctx->r14 = SUB32(ctx->r4, ctx->r8);
    // 0x8007074C: sub         $t7, $t3, $t1
    ctx->r15 = SUB32(ctx->r11, ctx->r9);
    // 0x80070750: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80070754: lh          $t2, 0x0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X0);
    // 0x80070758: sub         $t9, $a1, $t1
    ctx->r25 = SUB32(ctx->r5, ctx->r9);
    // 0x8007075C: addiu       $v0, $zero, 0x0
    ctx->r2 = ADD32(0, 0X0);
    // 0x80070760: sub         $t8, $t2, $t0
    ctx->r24 = SUB32(ctx->r10, ctx->r8);
    // 0x80070764: ori         $a3, $zero, 0x1
    ctx->r7 = 0 | 0X1;
    // 0x80070768: mflo        $t6
    ctx->r14 = lo;
    // 0x8007076C: mflo        $t6
    ctx->r14 = lo;
    // 0x80070770: nop

    // 0x80070774: nop

    // 0x80070778: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007077C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070780: mflo        $t8
    ctx->r24 = lo;
    // 0x80070784: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80070788: bgezl       $t6, L_80070798
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007078C: sub         $t6, $a0, $t2
        ctx->r14 = SUB32(ctx->r4, ctx->r10);
            goto L_80070798;
    }
    goto skip_0;
    // 0x8007078C: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    skip_0:
    // 0x80070790: xor         $a3, $a3, $a3
    ctx->r7 = ctx->r7 ^ ctx->r7;
    // 0x80070794: sub         $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
L_80070798:
    // 0x80070798: sub         $t7, $t5, $t3
    ctx->r15 = SUB32(ctx->r13, ctx->r11);
    // 0x8007079C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707A0: sub         $t8, $t4, $t2
    ctx->r24 = SUB32(ctx->r12, ctx->r10);
    // 0x800707A4: sub         $t9, $a1, $t3
    ctx->r25 = SUB32(ctx->r5, ctx->r11);
    // 0x800707A8: ori         $a2, $zero, 0x1
    ctx->r6 = 0 | 0X1;
    // 0x800707AC: mflo        $t6
    ctx->r14 = lo;
    // 0x800707B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800707B4: nop

    // 0x800707B8: nop

    // 0x800707BC: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800707C4: mflo        $t8
    ctx->r24 = lo;
    // 0x800707C8: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x800707CC: bgez        $t6, L_800707D8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800707D0: nop
    
            goto L_800707D8;
    }
    // 0x800707D0: nop

    // 0x800707D4: xor         $a2, $a2, $a2
    ctx->r6 = ctx->r6 ^ ctx->r6;
L_800707D8:
    // 0x800707D8: bne         $a3, $a2, L_80070830
    if (ctx->r7 != ctx->r6) {
        // 0x800707DC: nop
    
            goto L_80070830;
    }
    // 0x800707DC: nop

    // 0x800707E0: sub         $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800707E4: sub         $t7, $t1, $t5
    ctx->r15 = SUB32(ctx->r9, ctx->r13);
    // 0x800707E8: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800707EC: sub         $t8, $t0, $t4
    ctx->r24 = SUB32(ctx->r8, ctx->r12);
    // 0x800707F0: sub         $t9, $a1, $t5
    ctx->r25 = SUB32(ctx->r5, ctx->r13);
    // 0x800707F4: ori         $a1, $zero, 0x1
    ctx->r5 = 0 | 0X1;
    // 0x800707F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800707FC: mflo        $t6
    ctx->r14 = lo;
    // 0x80070800: nop

    // 0x80070804: nop

    // 0x80070808: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007080C: mflo        $t7
    ctx->r15 = lo;
    // 0x80070810: mflo        $t8
    ctx->r24 = lo;
    // 0x80070814: sub         $t6, $t6, $t7
    ctx->r14 = SUB32(ctx->r14, ctx->r15);
    // 0x80070818: bgez        $t6, L_80070824
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8007081C: nop
    
            goto L_80070824;
    }
    // 0x8007081C: nop

    // 0x80070820: xor         $a1, $a1, $a1
    ctx->r5 = ctx->r5 ^ ctx->r5;
L_80070824:
    // 0x80070824: bne         $a1, $a2, L_80070830
    if (ctx->r5 != ctx->r6) {
        // 0x80070828: nop
    
            goto L_80070830;
    }
    // 0x80070828: nop

    // 0x8007082C: ori         $v0, $zero, 0x1
    ctx->r2 = 0 | 0X1;
L_80070830:
    // 0x80070830: jr          $ra
    // 0x80070834: nop

    return;
    // 0x80070834: nop

;}
RECOMP_FUNC void music_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B34: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80000B38: lw          $t7, -0x3448($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3448);
    // 0x80000B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000B44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000B48: bne         $t7, $zero, L_80000BD0
    if (ctx->r15 != 0) {
        // 0x80000B4C: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000BD0;
    }
    // 0x80000B4C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80000B50: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80000B54: lw          $t8, -0x343C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X343C);
    // 0x80000B58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80000B5C: beq         $t8, $zero, L_80000BD0
    if (ctx->r24 == 0) {
        // 0x80000B60: addiu       $v0, $v0, 0x6284
        ctx->r2 = ADD32(ctx->r2, 0X6284);
            goto L_80000BD0;
    }
    // 0x80000B60: addiu       $v0, $v0, 0x6284
    ctx->r2 = ADD32(ctx->r2, 0X6284);
    // 0x80000B64: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80000B68: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80000B6C: lbu         $t0, -0x3450($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X3450);
    // 0x80000B70: addiu       $t9, $zero, 0x7F
    ctx->r25 = ADD32(0, 0X7F);
    // 0x80000B74: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B78: beq         $t0, $zero, L_80000B94
    if (ctx->r8 == 0) {
        // 0x80000B7C: sb          $t9, -0x3458($at)
        MEM_B(-0X3458, ctx->r1) = ctx->r25;
            goto L_80000B94;
    }
    // 0x80000B7C: sb          $t9, -0x3458($at)
    MEM_B(-0X3458, ctx->r1) = ctx->r25;
    // 0x80000B80: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80000B84: lw          $a1, -0x3460($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3460);
    // 0x80000B88: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80000B8C: jal         0x800022BC
    // 0x80000B90: nop

    music_sequence_start(rdram, ctx);
        goto after_0;
    // 0x80000B90: nop

    after_0:
L_80000B94:
    // 0x80000B94: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000B98: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80000B9C: jal         0x800C7DF0
    // 0x80000BA0: nop

    alCSPGetTempo(rdram, ctx);
        goto after_1;
    // 0x80000BA0: nop

    after_1:
    // 0x80000BA4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BA8: jal         0x800C7E30
    // 0x80000BAC: sw          $v0, 0x6288($at)
    MEM_W(0X6288, ctx->r1) = ctx->r2;
    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x80000BAC: sw          $v0, 0x6288($at)
    MEM_W(0X6288, ctx->r1) = ctx->r2;
    after_2:
    // 0x80000BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000BB4: sw          $v0, -0x3444($at)
    MEM_W(-0X3444, ctx->r1) = ctx->r2;
    // 0x80000BB8: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80000BC0: sb          $t1, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = ctx->r9;
    // 0x80000BC4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000BC8: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80000BCC: sw          $t2, 0x64FC($at)
    MEM_W(0X64FC, ctx->r1) = ctx->r10;
L_80000BD0:
    // 0x80000BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000BD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000BD8: jr          $ra
    // 0x80000BDC: nop

    return;
    // 0x80000BDC: nop

;}
RECOMP_FUNC void is_taj_challenge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023450: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80023454: lb          $v0, -0x4B8A($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4B8A);
    // 0x80023458: jr          $ra
    // 0x8002345C: nop

    return;
    // 0x8002345C: nop

;}
RECOMP_FUNC void music_jingle_pan_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001B5C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001B60: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001B64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001B68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001B6C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80001B70: andi        $s1, $a0, 0xFF
    ctx->r17 = ctx->r4 & 0XFF;
    // 0x80001B74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001B78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001B7C: addiu       $s2, $s2, -0x345C
    ctx->r18 = ADD32(ctx->r18, -0X345C);
    // 0x80001B80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001B84: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
L_80001B88:
    // 0x80001B88: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x80001B8C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x80001B90: jal         0x800C7E40
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    alCSPSetChlPan(rdram, ctx);
        goto after_0;
    // 0x80001B94: andi        $a2, $s1, 0xFF
    ctx->r6 = ctx->r17 & 0XFF;
    after_0:
    // 0x80001B98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001B9C: bne         $s0, $s3, L_80001B88
    if (ctx->r16 != ctx->r19) {
        // 0x80001BA0: nop
    
            goto L_80001B88;
    }
    // 0x80001BA0: nop

    // 0x80001BA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001BA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80001BAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80001BB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80001BB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80001BB8: jr          $ra
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001BBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSeqNewMarker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8670: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x800C8674: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C8678: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C867C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800C8680: addiu       $s3, $sp, 0x48
    ctx->r19 = ADD32(ctx->r29, 0X48);
    // 0x800C8684: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C8688: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C868C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C8690: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C8694: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8698: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C869C: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x800C86A0: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800C86A4: jal         0x800C855C
    // 0x800C86A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    alCSeqNew(rdram, ctx);
        goto after_0;
    // 0x800C86A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x800C86AC: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x800C86B0: addiu       $s4, $sp, 0x140
    ctx->r20 = ADD32(ctx->r29, 0X140);
    // 0x800C86B4: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800C86B8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
L_800C86BC:
    // 0x800C86BC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x800C86C0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C86C4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800C86C8: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800C86CC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C86D0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C86D4: sw          $t7, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r15;
    // 0x800C86D8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800C86DC: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
L_800C86E0:
    // 0x800C86E0: lw          $t0, 0x18($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X18);
    // 0x800C86E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C86E8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800C86EC: sw          $t0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r8;
    // 0x800C86F0: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x800C86F4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800C86F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800C86FC: sw          $t1, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r9;
    // 0x800C8700: lbu         $t2, 0x94($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X94);
    // 0x800C8704: sb          $t2, 0x88($a1)
    MEM_B(0X88, ctx->r5) = ctx->r10;
    // 0x800C8708: lbu         $t3, 0xA4($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA4);
    // 0x800C870C: sb          $t3, 0x98($a1)
    MEM_B(0X98, ctx->r5) = ctx->r11;
    // 0x800C8710: lw          $t4, 0xA8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XA8);
    // 0x800C8714: sw          $t4, 0x9C($v0)
    MEM_W(0X9C, ctx->r2) = ctx->r12;
    // 0x800C8718: lw          $t5, 0xC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0XC);
    // 0x800C871C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800C8720: lw          $t6, 0x4C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4C);
    // 0x800C8724: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x800C8728: lbu         $t7, 0x95($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X95);
    // 0x800C872C: sb          $t7, 0x89($a1)
    MEM_B(0X89, ctx->r5) = ctx->r15;
    // 0x800C8730: lbu         $t8, 0xA5($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA5);
    // 0x800C8734: sb          $t8, 0x99($a1)
    MEM_B(0X99, ctx->r5) = ctx->r24;
    // 0x800C8738: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x800C873C: sw          $t9, 0xA0($v0)
    MEM_W(0XA0, ctx->r2) = ctx->r25;
    // 0x800C8740: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    // 0x800C8744: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800C8748: lw          $t1, 0x50($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X50);
    // 0x800C874C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x800C8750: lbu         $t2, 0x96($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X96);
    // 0x800C8754: sb          $t2, 0x8A($a1)
    MEM_B(0X8A, ctx->r5) = ctx->r10;
    // 0x800C8758: lbu         $t3, 0xA6($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA6);
    // 0x800C875C: sb          $t3, 0x9A($a1)
    MEM_B(0X9A, ctx->r5) = ctx->r11;
    // 0x800C8760: lw          $t4, 0xB0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0XB0);
    // 0x800C8764: sw          $t4, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = ctx->r12;
    // 0x800C8768: lw          $t5, 0x14($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X14);
    // 0x800C876C: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x800C8770: lw          $t6, 0x54($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X54);
    // 0x800C8774: sw          $t6, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r14;
    // 0x800C8778: lbu         $t7, 0x97($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X97);
    // 0x800C877C: sb          $t7, 0x8B($a1)
    MEM_B(0X8B, ctx->r5) = ctx->r15;
    // 0x800C8780: lbu         $t8, 0xA7($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA7);
    // 0x800C8784: sb          $t8, 0x9B($a1)
    MEM_B(0X9B, ctx->r5) = ctx->r24;
    // 0x800C8788: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x800C878C: bne         $a0, $s0, L_800C86E0
    if (ctx->r4 != ctx->r16) {
        // 0x800C8790: sw          $t9, 0xA8($v0)
        MEM_W(0XA8, ctx->r2) = ctx->r25;
            goto L_800C86E0;
    }
    // 0x800C8790: sw          $t9, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = ctx->r25;
    // 0x800C8794: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800C8798: jal         0x800C8264
    // 0x800C879C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    alCSeqNextEvent(rdram, ctx);
        goto after_1;
    // 0x800C879C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x800C87A0: lh          $t0, 0x140($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X140);
    // 0x800C87A4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800C87A8: beq         $t0, $s5, L_800C87B8
    if (ctx->r8 == ctx->r21) {
        // 0x800C87AC: sltu        $at, $t1, $s2
        ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
            goto L_800C87B8;
    }
    // 0x800C87AC: sltu        $at, $t1, $s2
    ctx->r1 = ctx->r9 < ctx->r18 ? 1 : 0;
    // 0x800C87B0: bnel        $at, $zero, L_800C86BC
    if (ctx->r1 != 0) {
        // 0x800C87B4: lw          $t6, 0x4C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X4C);
            goto L_800C86BC;
    }
    goto skip_0;
    // 0x800C87B4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    skip_0:
L_800C87B8:
    // 0x800C87B8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C87BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C87C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C87C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C87C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C87CC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C87D0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C87D4: jr          $ra
    // 0x800C87D8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x800C87D8: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void drm_disable_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8E0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006A8E4: jr          $ra
    // 0x8006A8E8: sh          $zero, -0x278C($at)
    MEM_H(-0X278C, ctx->r1) = 0;
    return;
    // 0x8006A8E8: sh          $zero, -0x278C($at)
    MEM_H(-0X278C, ctx->r1) = 0;
;}
RECOMP_FUNC void menu_unload_bigfont(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80098724: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80098728: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009872C: jal         0x800C478C
    // 0x80098730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80098730: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80098734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009873C: jr          $ra
    // 0x80098740: nop

    return;
    // 0x80098740: nop

;}
RECOMP_FUNC void mode_end_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022E4C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80022E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80022E54: jal         0x8006BFF0
    // 0x80022E58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80022E58: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80022E5C: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x80022E60: sb          $t6, 0x4C($v0)
    MEM_B(0X4C, ctx->r2) = ctx->r14;
    // 0x80022E64: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80022E68: lb          $t7, -0x4B88($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X4B88);
    // 0x80022E6C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022E70: sb          $t7, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r15;
    // 0x80022E74: lw          $t8, -0x4B84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4B84);
    // 0x80022E78: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80022E7C: jal         0x800AB708
    // 0x80022E80: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    minimap_opacity_set(rdram, ctx);
        goto after_1;
    // 0x80022E80: sh          $t8, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r24;
    after_1:
    // 0x80022E84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022E88: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022E8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80022E90: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x80022E94: addiu       $a3, $a3, -0x4B9C
    ctx->r7 = ADD32(ctx->r7, -0X4B9C);
    // 0x80022E98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80022E9C:
    // 0x80022E9C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80022EA0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80022EA4: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80022EA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80022EAC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022EB0: lw          $v1, 0x64($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X64);
    // 0x80022EB4: nop

    // 0x80022EB8: sb          $zero, 0x1D8($v1)
    MEM_B(0X1D8, ctx->r3) = 0;
    // 0x80022EBC: sb          $zero, 0x193($v1)
    MEM_B(0X193, ctx->r3) = 0;
    // 0x80022EC0: sb          $zero, 0x192($v1)
    MEM_B(0X192, ctx->r3) = 0;
    // 0x80022EC4: sh          $zero, 0x190($v1)
    MEM_H(0X190, ctx->r3) = 0;
    // 0x80022EC8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x80022ECC: nop

    // 0x80022ED0: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80022ED4: bne         $at, $zero, L_80022E9C
    if (ctx->r1 != 0) {
        // 0x80022ED8: nop
    
            goto L_80022E9C;
    }
    // 0x80022ED8: nop

    // 0x80022EDC: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80022EE0: nop

    // 0x80022EE4: lw          $a0, 0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X4);
    // 0x80022EE8: jal         0x8000FFB8
    // 0x80022EEC: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x80022EEC: nop

    after_2:
    // 0x80022EF0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80022EF4: addiu       $a3, $a3, -0x4B9C
    ctx->r7 = ADD32(ctx->r7, -0X4B9C);
    // 0x80022EF8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80022EFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80022F00: lw          $t6, -0x4B98($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B98);
    // 0x80022F04: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80022F08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022F0C: addiu       $a2, $a2, -0x4B90
    ctx->r6 = ADD32(ctx->r6, -0X4B90);
    // 0x80022F10: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022F14: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x80022F18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80022F1C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022F20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80022F24: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80022F28: lw          $a1, -0x4C20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4C20);
    // 0x80022F2C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80022F30: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80022F34: beq         $at, $zero, L_80022F84
    if (ctx->r1 == 0) {
        // 0x80022F38: sll         $v0, $a1, 2
        ctx->r2 = S32(ctx->r5 << 2);
            goto L_80022F84;
    }
    // 0x80022F38: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80022F3C: lw          $t8, -0x4C28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4C28);
    // 0x80022F40: sll         $a2, $v1, 2
    ctx->r6 = S32(ctx->r3 << 2);
    // 0x80022F44: addiu       $a1, $zero, 0x3E
    ctx->r5 = ADD32(0, 0X3E);
    // 0x80022F48: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
L_80022F4C:
    // 0x80022F4C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80022F50: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80022F54: lh          $t9, 0x6($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X6);
    // 0x80022F58: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80022F5C: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80022F60: bne         $t0, $zero, L_80022F7C
    if (ctx->r8 != 0) {
        // 0x80022F64: nop
    
            goto L_80022F7C;
    }
    // 0x80022F64: nop

    // 0x80022F68: lh          $t1, 0x48($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X48);
    // 0x80022F6C: nop

    // 0x80022F70: bne         $a1, $t1, L_80022F7C
    if (ctx->r5 != ctx->r9) {
        // 0x80022F74: nop
    
            goto L_80022F7C;
    }
    // 0x80022F74: nop

    // 0x80022F78: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_80022F7C:
    // 0x80022F7C: bne         $at, $zero, L_80022F4C
    if (ctx->r1 != 0) {
        // 0x80022F80: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80022F4C;
    }
    // 0x80022F80: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_80022F84:
    // 0x80022F84: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80022F88: nop

    // 0x80022F8C: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80022F90: nop

    // 0x80022F94: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x80022F98: nop

    // 0x80022F9C: lw          $a0, 0x15C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X15C);
    // 0x80022FA0: nop

    // 0x80022FA4: beq         $a0, $zero, L_80022FC4
    if (ctx->r4 == 0) {
        // 0x80022FA8: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_80022FC4;
    }
    // 0x80022FA8: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80022FAC: jal         0x8000FFB8
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x80022FB0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_3:
    // 0x80022FB4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022FB8: nop

    // 0x80022FBC: sw          $zero, 0x15C($v1)
    MEM_W(0X15C, ctx->r3) = 0;
    // 0x80022FC0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80022FC4:
    // 0x80022FC4: nop

    // 0x80022FC8: bne         $t4, $zero, L_8002307C
    if (ctx->r12 != 0) {
        // 0x80022FCC: nop
    
            goto L_8002307C;
    }
    // 0x80022FCC: nop

    // 0x80022FD0: lh          $t5, 0x1AC($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X1AC);
    // 0x80022FD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80022FD8: bne         $t5, $at, L_80023058
    if (ctx->r13 != ctx->r1) {
        // 0x80022FDC: nop
    
            goto L_80023058;
    }
    // 0x80022FDC: nop

    // 0x80022FE0: jal         0x8006ECD0
    // 0x80022FE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    get_settings(rdram, ctx);
        goto after_4;
    // 0x80022FE4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_4:
    // 0x80022FE8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80022FEC: lhu         $t8, 0x14($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X14);
    // 0x80022FF0: lb          $a3, 0x1D6($v1)
    ctx->r7 = MEM_B(ctx->r3, 0X1D6);
    // 0x80022FF4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80022FF8: addiu       $t6, $a3, 0x3
    ctx->r14 = ADD32(ctx->r7, 0X3);
    // 0x80022FFC: sllv        $a1, $t7, $t6
    ctx->r5 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80023000: and         $t9, $t8, $a1
    ctx->r25 = ctx->r24 & ctx->r5;
    // 0x80023004: beq         $t9, $zero, L_8002301C
    if (ctx->r25 == 0) {
        // 0x80023008: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002301C;
    }
    // 0x80023008: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002300C: jal         0x8009D874
    // 0x80023010: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_5;
    // 0x80023010: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_5:
    // 0x80023014: b           L_80023064
    // 0x80023018: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023064;
    // 0x80023018: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_8002301C:
    // 0x8002301C: addiu       $a0, $a3, 0x6
    ctx->r4 = ADD32(ctx->r7, 0X6);
    // 0x80023020: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80023024: jal         0x8009D874
    // 0x80023028: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_6;
    // 0x80023028: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_6:
    // 0x8002302C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80023030: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80023034: lhu         $t0, 0x14($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0X14);
    // 0x80023038: nop

    // 0x8002303C: or          $t1, $t0, $a1
    ctx->r9 = ctx->r8 | ctx->r5;
    // 0x80023040: jal         0x8009C6E4
    // 0x80023044: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    get_save_file_index(rdram, ctx);
        goto after_7;
    // 0x80023044: sh          $t1, 0x14($a2)
    MEM_H(0X14, ctx->r6) = ctx->r9;
    after_7:
    // 0x80023048: jal         0x8006EE88
    // 0x8002304C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_8;
    // 0x8002304C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x80023050: b           L_80023064
    // 0x80023054: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
        goto L_80023064;
    // 0x80023054: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023058:
    // 0x80023058: jal         0x8009D874
    // 0x8002305C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_9;
    // 0x8002305C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_9:
    // 0x80023060: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
L_80023064:
    // 0x80023064: addiu       $t2, $zero, 0x1F
    ctx->r10 = ADD32(0, 0X1F);
    // 0x80023068: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8002306C: jal         0x800521F8
    // 0x80023070: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    set_taj_status(rdram, ctx);
        goto after_10;
    // 0x80023070: sw          $t2, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->r10;
    after_10:
    // 0x80023074: b           L_800230D0
    // 0x80023078: nop

        goto L_800230D0;
    // 0x80023078: nop

L_8002307C:
    // 0x8002307C: jal         0x80000B28
    // 0x80023080: nop

    music_change_on(rdram, ctx);
        goto after_11;
    // 0x80023080: nop

    after_11:
    // 0x80023084: jal         0x80001844
    // 0x80023088: nop

    music_stop(rdram, ctx);
        goto after_12;
    // 0x80023088: nop

    after_12:
    // 0x8002308C: jal         0x8009D874
    // 0x80023090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_13;
    // 0x80023090: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x80023094: jal         0x80008168
    // 0x80023098: nop

    audspat_jingle_on(rdram, ctx);
        goto after_14;
    // 0x80023098: nop

    after_14:
    // 0x8002309C: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800230A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800230A4: bne         $t4, $at, L_800230B4
    if (ctx->r12 != ctx->r1) {
        // 0x800230A8: nop
    
            goto L_800230B4;
    }
    // 0x800230A8: nop

    // 0x800230AC: jal         0x800C3744
    // 0x800230B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_current_text(rdram, ctx);
        goto after_15;
    // 0x800230B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
L_800230B4:
    // 0x800230B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230B8: sw          $zero, -0x4CD0($at)
    MEM_W(-0X4CD0, ctx->r1) = 0;
    // 0x800230BC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800230C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230C4: sw          $zero, -0x4CC8($at)
    MEM_W(-0X4CC8, ctx->r1) = 0;
    // 0x800230C8: addiu       $t5, $zero, 0x14
    ctx->r13 = ADD32(0, 0X14);
    // 0x800230CC: sw          $t5, 0x78($t7)
    MEM_W(0X78, ctx->r15) = ctx->r13;
L_800230D0:
    // 0x800230D0: jal         0x80000B28
    // 0x800230D4: nop

    music_change_on(rdram, ctx);
        goto after_16;
    // 0x800230D4: nop

    after_16:
    // 0x800230D8: jal         0x800A10B4
    // 0x800230DC: nop

    hud_audio_init(rdram, ctx);
        goto after_17;
    // 0x800230DC: nop

    after_17:
    // 0x800230E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800230E4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800230E8: jal         0x8006BF50
    // 0x800230EC: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800230EC: nop

    after_18:
    // 0x800230F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800230F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800230F8: sb          $zero, -0x4B8A($at)
    MEM_B(-0X4B8A, ctx->r1) = 0;
    // 0x800230FC: jr          $ra
    // 0x80023100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023100: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void bgload_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C791C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7924: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C7928: jal         0x800C9050
    // 0x800C792C: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    osStopThread_recomp(rdram, ctx);
        goto after_0;
    // 0x800C792C: addiu       $a0, $a0, -0x4F50
    ctx->r4 = ADD32(ctx->r4, -0X4F50);
    after_0:
    // 0x800C7930: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7934: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7938: jr          $ra
    // 0x800C793C: nop

    return;
    // 0x800C793C: nop

;}
RECOMP_FUNC void lensflare_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD590: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AD594: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AD598: lui         $s6, 0x800E
    ctx->r22 = S32(0X800E << 16);
    // 0x800AD59C: addiu       $s6, $s6, 0x3018
    ctx->r22 = ADD32(ctx->r22, 0X3018);
    // 0x800AD5A0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AD5A4: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x800AD5A8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AD5AC: addiu       $s5, $s5, 0x3014
    ctx->r21 = ADD32(ctx->r21, 0X3014);
    // 0x800AD5B0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AD5B4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AD5B8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AD5BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AD5C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AD5C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AD5C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AD5CC: blez        $v0, L_800AD67C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD5D0: sw          $zero, 0x0($s5)
        MEM_W(0X0, ctx->r21) = 0;
            goto L_800AD67C;
    }
    // 0x800AD5D0: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800AD5D4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD5D8: lw          $t6, 0x3010($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3010);
    // 0x800AD5DC: nop

    // 0x800AD5E0: beq         $t6, $zero, L_800AD680
    if (ctx->r14 == 0) {
        // 0x800AD5E4: lw          $ra, 0x34($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X34);
            goto L_800AD680;
    }
    // 0x800AD5E4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800AD5E8: blez        $v0, L_800AD67C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800AD5EC: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AD67C;
    }
    // 0x800AD5EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AD5F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800AD5F4: addiu       $s0, $s0, -0x7E00
    ctx->r16 = ADD32(ctx->r16, -0X7E00);
    // 0x800AD5F8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800AD5FC:
    // 0x800AD5FC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AD600: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x800AD604: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AD608: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800AD60C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800AD610: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800AD614: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800AD618: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800AD61C: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800AD620: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AD624: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800AD628: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AD62C: lw          $s2, 0x3C($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X3C);
    // 0x800AD630: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800AD634: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800AD638: jal         0x800CA030
    // 0x800AD63C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800AD63C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800AD640: lh          $t7, 0x8($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X8);
    // 0x800AD644: nop

    // 0x800AD648: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800AD64C: nop

    // 0x800AD650: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AD654: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800AD658: nop

    // 0x800AD65C: bc1f        L_800AD668
    if (!c1cs) {
        // 0x800AD660: nop
    
            goto L_800AD668;
    }
    // 0x800AD660: nop

    // 0x800AD664: sw          $s4, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r20;
L_800AD668:
    // 0x800AD668: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800AD66C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AD670: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AD674: bne         $at, $zero, L_800AD5FC
    if (ctx->r1 != 0) {
        // 0x800AD678: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AD5FC;
    }
    // 0x800AD678: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AD67C:
    // 0x800AD67C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AD680:
    // 0x800AD680: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AD684: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD688: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AD68C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AD690: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AD694: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AD698: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AD69C: jr          $ra
    // 0x800AD6A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800AD6A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800BF9F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFF18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BFF1C: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x800BFF20: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800BFF24: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800BFF28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800BFF2C: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BFF30: beq         $a0, $zero, L_800C015C
    if (ctx->r4 == 0) {
        // 0x800BFF34: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_800C015C;
    }
    // 0x800BFF34: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800BFF38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BFF3C: lw          $t6, -0x5A50($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5A50);
    // 0x800BFF40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BFF44: lwc1        $f0, -0x5988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5988);
    // 0x800BFF48: beq         $t6, $zero, L_800BFF64
    if (ctx->r14 == 0) {
        // 0x800BFF4C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800BFF64;
    }
    // 0x800BFF4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BFF50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BFF54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BFF58: nop

    // 0x800BFF5C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BFF60: nop

L_800BFF64:
    // 0x800BFF64: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BFF68: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BFF6C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BFF70: lhu         $v1, 0x18($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X18);
    // 0x800BFF74: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x800BFF78: addiu       $t3, $t3, -0x5970
    ctx->r11 = ADD32(ctx->r11, -0X5970);
    // 0x800BFF7C: addiu       $t4, $t4, 0x371C
    ctx->r12 = ADD32(ctx->r12, 0X371C);
    // 0x800BFF80: addiu       $t5, $t5, 0x3714
    ctx->r13 = ADD32(ctx->r13, 0X3714);
    // 0x800BFF84: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x800BFF88: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
L_800BFF8C:
    // 0x800BFF8C: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800BFF90: lwc1        $f2, 0x8($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800BFF94: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800BFF98: lwc1        $f12, 0x10($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800BFF9C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BFFA0: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x800BFFA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800BFFA8: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800BFFAC: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800BFFB0: nop

    // 0x800BFFB4: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BFFB8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BFFBC: nop

    // 0x800BFFC0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BFFC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BFFC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BFFCC: nop

    // 0x800BFFD0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BFFD4: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800BFFD8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BFFDC: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BFFE0: bne         $at, $zero, L_800BFFF0
    if (ctx->r1 != 0) {
        // 0x800BFFE4: nop
    
            goto L_800BFFF0;
    }
    // 0x800BFFE4: nop

    // 0x800BFFE8: b           L_800BFFFC
    // 0x800BFFEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800BFFFC;
    // 0x800BFFEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BFFF0:
    // 0x800BFFF0: bgez        $a2, L_800BFFFC
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BFFF4: nop
    
            goto L_800BFFFC;
    }
    // 0x800BFFF4: nop

    // 0x800BFFF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BFFFC:
    // 0x800BFFFC: beq         $a1, $zero, L_800C0054
    if (ctx->r5 == 0) {
        // 0x800C0000: nop
    
            goto L_800C0054;
    }
    // 0x800C0000: nop

    // 0x800C0004: add.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800C0008: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x800C000C: nop

    // 0x800C0010: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800C0014: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800C0018: nop

    // 0x800C001C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800C0020: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800C0024: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800C0028: nop

    // 0x800C002C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800C0030: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800C0034: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800C0038: bgez        $t0, L_800C0048
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C003C: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800C0048;
    }
    // 0x800C003C: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800C0040: b           L_800C0054
    // 0x800C0044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
        goto L_800C0054;
    // 0x800C0044: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800C0048:
    // 0x800C0048: bne         $at, $zero, L_800C0054
    if (ctx->r1 != 0) {
        // 0x800C004C: nop
    
            goto L_800C0054;
    }
    // 0x800C004C: nop

    // 0x800C0050: addiu       $t0, $a3, -0x1
    ctx->r8 = ADD32(ctx->r7, -0X1);
L_800C0054:
    // 0x800C0054: beq         $a1, $zero, L_800C0110
    if (ctx->r5 == 0) {
        // 0x800C0058: slt         $at, $t0, $a2
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800C0110;
    }
    // 0x800C0058: slt         $at, $t0, $a2
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800C005C: bne         $at, $zero, L_800C0110
    if (ctx->r1 != 0) {
        // 0x800C0060: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800C0110;
    }
    // 0x800C0060: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800C0064: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
L_800C0068:
    // 0x800C0068: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800C006C: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x800C0070: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C0074: beq         $v0, $zero, L_800C00B4
    if (ctx->r2 == 0) {
        // 0x800C0078: addu        $a2, $t6, $t7
        ctx->r6 = ADD32(ctx->r14, ctx->r15);
            goto L_800C00B4;
    }
    // 0x800C0078: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x800C007C: lbu         $t8, 0x7($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X7);
    // 0x800C0080: nop

    // 0x800C0084: bne         $s0, $t8, L_800C0104
    if (ctx->r16 != ctx->r24) {
        // 0x800C0088: nop
    
            goto L_800C0104;
    }
    // 0x800C0088: nop

    // 0x800C008C: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x800C0090: nop

    // 0x800C0094: beq         $s0, $t9, L_800C00AC
    if (ctx->r16 == ctx->r25) {
        // 0x800C0098: nop
    
            goto L_800C00AC;
    }
    // 0x800C0098: nop

L_800C009C:
    // 0x800C009C: lbu         $t6, 0x1($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1);
    // 0x800C00A0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C00A4: bne         $s0, $t6, L_800C009C
    if (ctx->r16 != ctx->r14) {
        // 0x800C00A8: nop
    
            goto L_800C009C;
    }
    // 0x800C00A8: nop

L_800C00AC:
    // 0x800C00AC: b           L_800C0104
    // 0x800C00B0: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
        goto L_800C0104;
    // 0x800C00B0: sb          $v1, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r3;
L_800C00B4:
    // 0x800C00B4: addu        $t1, $a2, $a3
    ctx->r9 = ADD32(ctx->r6, ctx->r7);
L_800C00B8:
    // 0x800C00B8: lbu         $t7, 0x0($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X0);
    // 0x800C00BC: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800C00C0: bne         $v1, $t7, L_800C00F4
    if (ctx->r3 != ctx->r15) {
        // 0x800C00C4: nop
    
            goto L_800C00F4;
    }
    // 0x800C00C4: nop

    // 0x800C00C8: beq         $at, $zero, L_800C00E8
    if (ctx->r1 == 0) {
        // 0x800C00CC: nop
    
            goto L_800C00E8;
    }
    // 0x800C00CC: nop

L_800C00D0:
    // 0x800C00D0: lbu         $t8, 0x1($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X1);
    // 0x800C00D4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00D8: slti        $at, $a3, 0x7
    ctx->r1 = SIGNED(ctx->r7) < 0X7 ? 1 : 0;
    // 0x800C00DC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C00E0: bne         $at, $zero, L_800C00D0
    if (ctx->r1 != 0) {
        // 0x800C00E4: sb          $t8, -0x1($t1)
        MEM_B(-0X1, ctx->r9) = ctx->r24;
            goto L_800C00D0;
    }
    // 0x800C00E4: sb          $t8, -0x1($t1)
    MEM_B(-0X1, ctx->r9) = ctx->r24;
L_800C00E8:
    // 0x800C00E8: sb          $s1, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r17;
    // 0x800C00EC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00F0: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C00F4:
    // 0x800C00F4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C00F8: slti        $at, $a3, 0x8
    ctx->r1 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x800C00FC: bne         $at, $zero, L_800C00B8
    if (ctx->r1 != 0) {
        // 0x800C0100: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800C00B8;
    }
    // 0x800C0100: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C0104:
    // 0x800C0104: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C0108: bne         $t2, $a1, L_800C0068
    if (ctx->r10 != ctx->r5) {
        // 0x800C010C: nop
    
            goto L_800C0068;
    }
    // 0x800C010C: nop

L_800C0110:
    // 0x800C0110: bne         $v0, $zero, L_800C014C
    if (ctx->r2 != 0) {
        // 0x800C0114: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800C014C;
    }
    // 0x800C0114: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C0118: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800C011C: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800C0120: lwc1        $f14, 0xC($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800C0124: add.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C0128: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C012C: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C0130: add.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f20.fl;
    // 0x800C0134: swc1        $f16, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f16.u32l;
    // 0x800C0138: add.s       $f18, $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800C013C: swc1        $f14, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f14.u32l;
    // 0x800C0140: add.s       $f12, $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f20.fl;
    // 0x800C0144: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800C0148: swc1        $f12, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f12.u32l;
L_800C014C:
    // 0x800C014C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C0150: bne         $v0, $at, L_800BFF8C
    if (ctx->r2 != ctx->r1) {
        // 0x800C0154: nop
    
            goto L_800BFF8C;
    }
    // 0x800C0154: nop

    // 0x800C0158: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
L_800C015C:
    // 0x800C015C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800C0160: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800C0164: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C0168: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C016C: jr          $ra
    // 0x800C0170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C0170: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void savemenu_input_confirm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80087B40: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x80087B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80087B48: beq         $t6, $zero, L_80087B6C
    if (ctx->r14 == 0) {
        // 0x80087B4C: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80087B6C;
    }
    // 0x80087B4C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80087B50: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80087B54: jal         0x80001D04
    // 0x80087B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80087B58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80087B5C: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80087B60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B64: b           L_80087B94
    // 0x80087B68: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
        goto L_80087B94;
    // 0x80087B68: sw          $t7, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r15;
L_80087B6C:
    // 0x80087B6C: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087B70: beq         $t8, $zero, L_80087B94
    if (ctx->r24 == 0) {
        // 0x80087B74: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087B94;
    }
    // 0x80087B74: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80087B78: jal         0x80001D04
    // 0x80087B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087B7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087B80: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80087B84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B88: sw          $t9, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r25;
    // 0x80087B8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087B90: sw          $zero, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = 0;
L_80087B94:
    // 0x80087B94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80087B98: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80087B9C: jr          $ra
    // 0x80087BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80087BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void set_text_font(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C484C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C4850: lw          $t6, -0x5260($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5260);
    // 0x800C4854: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C4858: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800C485C: beq         $at, $zero, L_800C4870
    if (ctx->r1 == 0) {
        // 0x800C4860: nop
    
            goto L_800C4870;
    }
    // 0x800C4860: nop

    // 0x800C4864: lw          $t7, -0x5258($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5258);
    // 0x800C4868: nop

    // 0x800C486C: sb          $a0, 0x1D($t7)
    MEM_B(0X1D, ctx->r15) = ctx->r4;
L_800C4870:
    // 0x800C4870: jr          $ra
    // 0x800C4874: nop

    return;
    // 0x800C4874: nop

;}
RECOMP_FUNC void obj_loop_airzippers_waterzippers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800359AC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800359B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800359B4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800359B8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800359BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800359C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800359C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800359C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800359CC: jal         0x8000E1CC
    // 0x800359D0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    find_non_car_racers(rdram, ctx);
        goto after_0;
    // 0x800359D0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800359D4: bne         $v0, $zero, L_800359F0
    if (ctx->r2 != 0) {
        // 0x800359D8: nop
    
            goto L_800359F0;
    }
    // 0x800359D8: nop

    // 0x800359DC: lh          $t6, 0x6($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X6);
    // 0x800359E0: nop

    // 0x800359E4: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x800359E8: b           L_80035A00
    // 0x800359EC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
        goto L_80035A00;
    // 0x800359EC: sh          $t7, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r15;
L_800359F0:
    // 0x800359F0: lh          $t8, 0x6($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X6);
    // 0x800359F4: nop

    // 0x800359F8: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800359FC: sh          $t9, 0x6($s3)
    MEM_H(0X6, ctx->r19) = ctx->r25;
L_80035A00:
    // 0x80035A00: lw          $t0, 0x4C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X4C);
    // 0x80035A04: nop

    // 0x80035A08: lbu         $t1, 0x13($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X13);
    // 0x80035A0C: nop

    // 0x80035A10: slti        $at, $t1, 0x64
    ctx->r1 = SIGNED(ctx->r9) < 0X64 ? 1 : 0;
    // 0x80035A14: beq         $at, $zero, L_80035B0C
    if (ctx->r1 == 0) {
        // 0x80035A18: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035B0C;
    }
    // 0x80035A18: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A1C: lh          $t2, 0x6($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X6);
    // 0x80035A20: nop

    // 0x80035A24: andi        $t3, $t2, 0x4000
    ctx->r11 = ctx->r10 & 0X4000;
    // 0x80035A28: bne         $t3, $zero, L_80035B0C
    if (ctx->r11 != 0) {
        // 0x80035A2C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80035B0C;
    }
    // 0x80035A2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80035A30: jal         0x8001BAA8
    // 0x80035A34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_racer_objects(rdram, ctx);
        goto after_1;
    // 0x80035A34: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x80035A38: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80035A3C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80035A40: blez        $t4, L_80035B08
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80035A44: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_80035B08;
    }
    // 0x80035A44: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80035A48: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_80035A4C:
    // 0x80035A4C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80035A50: nop

    // 0x80035A54: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80035A58: nop

    // 0x80035A5C: lbu         $t5, 0x1F5($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1F5);
    // 0x80035A60: nop

    // 0x80035A64: bne         $t5, $zero, L_80035AF8
    if (ctx->r13 != 0) {
        // 0x80035A68: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035A68: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A6C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x80035A70: nop

    // 0x80035A74: slti        $at, $t6, 0xF
    ctx->r1 = SIGNED(ctx->r14) < 0XF ? 1 : 0;
    // 0x80035A78: beq         $at, $zero, L_80035AF8
    if (ctx->r1 == 0) {
        // 0x80035A7C: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035A7C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035A80: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035A84: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x80035A88: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80035A8C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80035A90: lwc1        $f10, 0x10($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X10);
    // 0x80035A94: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80035A98: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80035A9C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80035AA0: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x80035AA4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80035AA8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80035AAC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80035AB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80035AB4: jal         0x800CA030
    // 0x80035AB8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80035AB8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80035ABC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80035AC0: nop

    // 0x80035AC4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80035AC8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035ACC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035AD0: nop

    // 0x80035AD4: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80035AD8: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x80035ADC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80035AE0: slti        $at, $t8, 0x64
    ctx->r1 = SIGNED(ctx->r24) < 0X64 ? 1 : 0;
    // 0x80035AE4: beq         $at, $zero, L_80035AF8
    if (ctx->r1 == 0) {
        // 0x80035AE8: lw          $t9, 0x40($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X40);
            goto L_80035AF8;
    }
    // 0x80035AE8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80035AEC: sb          $s4, 0x1F5($s0)
    MEM_B(0X1F5, ctx->r16) = ctx->r20;
    // 0x80035AF0: sw          $s3, 0x14C($s0)
    MEM_W(0X14C, ctx->r16) = ctx->r19;
    // 0x80035AF4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
L_80035AF8:
    // 0x80035AF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80035AFC: slt         $at, $s1, $t9
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80035B00: bne         $at, $zero, L_80035A4C
    if (ctx->r1 != 0) {
        // 0x80035B04: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80035A4C;
    }
    // 0x80035B04: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80035B08:
    // 0x80035B08: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80035B0C:
    // 0x80035B0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80035B10: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80035B14: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80035B18: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80035B1C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80035B20: jr          $ra
    // 0x80035B24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80035B24: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_80012CE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012CE8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012CEC: addiu       $a2, $a2, -0x4CDC
    ctx->r6 = ADD32(ctx->r6, -0X4CDC);
    // 0x80012CF0: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x80012CF4: nop

    // 0x80012CF8: slti        $at, $t6, 0x9
    ctx->r1 = SIGNED(ctx->r14) < 0X9 ? 1 : 0;
    // 0x80012CFC: beq         $at, $zero, L_80012D54
    if (ctx->r1 == 0) {
        // 0x80012D00: nop
    
            goto L_80012D54;
    }
    // 0x80012D00: nop

    // 0x80012D04: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80012D08: lui         $t8, 0xB800
    ctx->r24 = S32(0XB800 << 16);
    // 0x80012D0C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80012D10: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80012D14: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80012D18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80012D1C: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80012D20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80012D24: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80012D28: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x80012D2C: lw          $a1, -0x4D08($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4D08);
    // 0x80012D30: lui         $t1, 0x601
    ctx->r9 = S32(0X601 << 16);
    // 0x80012D34: sw          $t1, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r9;
    // 0x80012D38: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x80012D3C: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
    // 0x80012D40: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x80012D44: lh          $t3, 0x0($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X0);
    // 0x80012D48: nop

    // 0x80012D4C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80012D50: sh          $t4, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r12;
L_80012D54:
    // 0x80012D54: jr          $ra
    // 0x80012D58: nop

    return;
    // 0x80012D58: nop

;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000ACE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000ACE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000ACE8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000ACEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000ACF0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000ACF4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000ACF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000ACFC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8000AD00:
    // 0x8000AD00: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    // 0x8000AD04: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000AD08: beq         $s1, $zero, L_8000AD00
    if (ctx->r17 == 0) {
        // 0x8000AD0C: nop
    
            goto L_8000AD00;
    }
    // 0x8000AD0C: nop

    // 0x8000AD10: lbu         $t6, 0x34($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD14: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AD18: blez        $t6, L_8000AD4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AD1C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD4C;
    }
    // 0x8000AD1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD20:
    // 0x8000AD20: jal         0x8000ADF4
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AD24: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AD28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD2C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000AD30: jal         0x8000AD98
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x8000AD34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x8000AD38: lbu         $t7, 0x34($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X34);
    // 0x8000AD3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AD40: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000AD44: bne         $at, $zero, L_8000AD20
    if (ctx->r1 != 0) {
        // 0x8000AD48: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000AD20;
    }
    // 0x8000AD48: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8000AD4C:
    // 0x8000AD4C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD50: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD54: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8000AD58: nop

    // 0x8000AD5C: beq         $t9, $zero, L_8000AD84
    if (ctx->r25 == 0) {
        // 0x8000AD60: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000AD84;
    }
    // 0x8000AD60: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AD64: jal         0x8000ADF4
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x8000AD68: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8000AD6C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8000AD70: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000AD74: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    // 0x8000AD78: jal         0x8000AD98
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x8000AD7C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    after_3:
    // 0x8000AD80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000AD84:
    // 0x8000AD84: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AD88: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AD8C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AD90: jr          $ra
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AD94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void render_racer_magnet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013DCC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80013DD0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80013DD4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80013DD8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80013DDC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80013DE0: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80013DE4: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80013DE8: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x80013DEC: lw          $t3, 0x64($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X64);
    // 0x80013DF0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80013DF4: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013DF8: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80013DFC: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80013E00: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80013E04: lbu         $t8, -0x4A05($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X4A05);
    // 0x80013E08: addiu       $s0, $s0, -0x332C
    ctx->r16 = ADD32(ctx->r16, -0X332C);
    // 0x80013E0C: beq         $t8, $zero, L_80014080
    if (ctx->r24 == 0) {
        // 0x80013E10: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80014080;
    }
    // 0x80013E10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80013E14: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80013E18: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80013E1C: beq         $t9, $zero, L_8001407C
    if (ctx->r25 == 0) {
        // 0x80013E20: addiu       $s1, $s1, -0x4BF4
        ctx->r17 = ADD32(ctx->r17, -0X4BF4);
            goto L_8001407C;
    }
    // 0x80013E20: addiu       $s1, $s1, -0x4BF4
    ctx->r17 = ADD32(ctx->r17, -0X4BF4);
    // 0x80013E24: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80013E28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E2C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80013E30: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013E34: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80013E38: sw          $t7, -0x4BF0($at)
    MEM_W(-0X4BF0, ctx->r1) = ctx->r15;
    // 0x80013E3C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80013E40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013E44: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013E48: jal         0x8001E2D0
    // 0x80013E4C: sw          $t9, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r25;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013E4C: sw          $t9, -0x4BEC($at)
    MEM_W(-0X4BEC, ctx->r1) = ctx->r25;
    after_0:
    // 0x80013E50: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013E54: nop

    // 0x80013E58: lb          $a0, 0x1D6($t3)
    ctx->r4 = MEM_B(ctx->r11, 0X1D6);
    // 0x80013E5C: nop

    // 0x80013E60: bltz        $a0, L_80013E70
    if (SIGNED(ctx->r4) < 0) {
        // 0x80013E64: slti        $at, $a0, 0x3
        ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_80013E70;
    }
    // 0x80013E64: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x80013E68: bne         $at, $zero, L_80013E74
    if (ctx->r1 != 0) {
        // 0x80013E6C: nop
    
            goto L_80013E74;
    }
    // 0x80013E6C: nop

L_80013E70:
    // 0x80013E70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80013E74:
    // 0x80013E74: lb          $t0, 0x2($t3)
    ctx->r8 = MEM_B(ctx->r11, 0X2);
    // 0x80013E78: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80013E7C: addu        $t4, $t4, $a0
    ctx->r12 = ADD32(ctx->r12, ctx->r4);
    // 0x80013E80: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013E84: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80013E88: bne         $at, $zero, L_80013E94
    if (ctx->r1 != 0) {
        // 0x80013E8C: addu        $v1, $t5, $v0
        ctx->r3 = ADD32(ctx->r13, ctx->r2);
            goto L_80013E94;
    }
    // 0x80013E8C: addu        $v1, $t5, $v0
    ctx->r3 = ADD32(ctx->r13, ctx->r2);
    // 0x80013E90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013E94:
    // 0x80013E94: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013E98: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013E9C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80013EA0: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x80013EA4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013EA8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013EAC: addiu       $t4, $t4, -0x4A08
    ctx->r12 = ADD32(ctx->r12, -0X4A08);
    // 0x80013EB0: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x80013EB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013EB8: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80013EBC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80013EC0: addu        $t1, $t9, $t4
    ctx->r9 = ADD32(ctx->r25, ctx->r12);
    // 0x80013EC4: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x80013EC8: lbu         $t5, 0x1($t1)
    ctx->r13 = MEM_BU(ctx->r9, 0X1);
    // 0x80013ECC: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80013ED0: sll         $t6, $t5, 26
    ctx->r14 = S32(ctx->r13 << 26);
    // 0x80013ED4: sra         $a0, $t6, 16
    ctx->r4 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80013ED8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x80013EDC: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80013EE0: jal         0x80070A38
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80013EE4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    after_1:
    // 0x80013EE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EEC: lwc1        $f10, 0x5B10($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5B10);
    // 0x80013EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013EF4: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80013EF8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x80013EFC: lwc1        $f18, 0x5B14($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5B14);
    // 0x80013F00: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80013F04: add.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013F08: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80013F0C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80013F10: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80013F14: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80013F18: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80013F1C: swc1        $f6, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f6.u32l;
    // 0x80013F20: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80013F24: lbu         $t9, 0x2($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X2);
    // 0x80013F28: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80013F2C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80013F30: sll         $t4, $t9, 12
    ctx->r12 = S32(ctx->r25 << 12);
    // 0x80013F34: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80013F38: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80013F3C: sh          $t4, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r12;
    // 0x80013F40: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80013F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013F48: sh          $zero, 0x2($t6)
    MEM_H(0X2, ctx->r14) = 0;
    // 0x80013F4C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80013F50: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80013F54: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80013F58: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80013F5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80013F60: lw          $t8, 0x68($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X68);
    // 0x80013F64: nop

    // 0x80013F68: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80013F6C: nop

    // 0x80013F70: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80013F74: nop

    // 0x80013F78: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x80013F7C: lb          $t4, 0x1F($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1F);
    // 0x80013F80: nop

    // 0x80013F84: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013F88: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013F8C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80013F90: nop

    // 0x80013F94: sw          $t7, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->r15;
    // 0x80013F98: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80013F9C: lb          $t4, 0x184($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X184);
    // 0x80013FA0: sll         $t8, $t2, 3
    ctx->r24 = S32(ctx->r10 << 3);
    // 0x80013FA4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013FA8: andi        $t9, $t8, 0x7F
    ctx->r25 = ctx->r24 & 0X7F;
    // 0x80013FAC: addu        $a3, $a3, $t5
    ctx->r7 = ADD32(ctx->r7, ctx->r13);
    // 0x80013FB0: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x80013FB4: lw          $a3, -0x3244($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X3244);
    // 0x80013FB8: jal         0x8007F9E4
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_2;
    // 0x80013FBC: or          $a2, $t2, $at
    ctx->r6 = ctx->r10 | ctx->r1;
    after_2:
    // 0x80013FC0: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80013FC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80013FC8: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80013FCC: lw          $a3, 0x64($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X64);
    // 0x80013FD0: addiu       $a1, $a1, -0x4BF0
    ctx->r5 = ADD32(ctx->r5, -0X4BF0);
    // 0x80013FD4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80013FD8: jal         0x800691E8
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    mtx_shear_push(rdram, ctx);
        goto after_3;
    // 0x80013FDC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80013FE0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80013FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013FE8: sw          $t6, -0x3370($at)
    MEM_W(-0X3370, ctx->r1) = ctx->r14;
    // 0x80013FEC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80013FF0: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x80013FF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80013FF8: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x80013FFC: jal         0x800143A8
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_mesh(rdram, ctx);
        goto after_4;
    // 0x80014000: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80014004: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80014008: sw          $zero, -0x3370($at)
    MEM_W(-0X3370, ctx->r1) = 0;
    // 0x8001400C: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80014010: lui         $t8, 0xBC00
    ctx->r24 = S32(0XBC00 << 16);
    // 0x80014014: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014018: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8001401C: ori         $t8, $t8, 0xA
    ctx->r24 = ctx->r24 | 0XA;
    // 0x80014020: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80014024: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80014028: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8001402C: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80014030: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80014034: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80014038: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001403C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80014040: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80014044: jal         0x8007B820
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80014048: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_5:
    // 0x8001404C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80014050: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80014054: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80014058: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8001405C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x80014060: lw          $t8, -0x4BF0($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4BF0);
    // 0x80014064: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80014068: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8001406C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80014070: lw          $t4, -0x4BEC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4BEC);
    // 0x80014074: nop

    // 0x80014078: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_8001407C:
    // 0x8001407C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80014080:
    // 0x80014080: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80014084: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80014088: jr          $ra
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001408C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void input_clamp_stick_x(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A7DC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A7E0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A7E4: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A7E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A7EC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A7F0: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A7F4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A7F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A7FC: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A804: lb          $a0, 0x1692($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1692);
    // 0x8006A808: jal         0x8006A864
    // 0x8006A80C: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A80C: nop

    after_0:
    // 0x8006A810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A818: jr          $ra
    // 0x8006A81C: nop

    return;
    // 0x8006A81C: nop

;}
RECOMP_FUNC void render_track_selection_viewport_border(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009D2C0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8009D2C4: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009D2C8: lw          $t7, -0x31C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X31C);
    // 0x8009D2CC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8009D2D0: addiu       $t6, $zero, 0x9
    ctx->r14 = ADD32(0, 0X9);
    // 0x8009D2D4: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8009D2D8: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8009D2DC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8009D2E0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8009D2E4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8009D2E8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8009D2EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8009D2F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8009D2F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009D2F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009D2FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009D300: beq         $t7, $at, L_8009D310
    if (ctx->r15 == ctx->r1) {
        // 0x8009D304: sw          $t6, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r14;
            goto L_8009D310;
    }
    // 0x8009D304: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8009D308: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x8009D30C: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
L_8009D310:
    // 0x8009D310: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009D314: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8009D318: blez        $a2, L_8009D47C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8009D31C: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8009D47C;
    }
    // 0x8009D31C: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8009D320: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009D324: addiu       $s1, $s1, 0x693C
    ctx->r17 = ADD32(ctx->r17, 0X693C);
L_8009D328:
    // 0x8009D328: lw          $t9, 0x38($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X38);
    // 0x8009D32C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009D330: addu        $v0, $t9, $s7
    ctx->r2 = ADD32(ctx->r25, ctx->r23);
    // 0x8009D334: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8009D338: nop

    // 0x8009D33C: andi        $t3, $t2, 0x100
    ctx->r11 = ctx->r10 & 0X100;
    // 0x8009D340: bne         $t3, $zero, L_8009D46C
    if (ctx->r11 != 0) {
        // 0x8009D344: nop
    
            goto L_8009D46C;
    }
    // 0x8009D344: nop

    // 0x8009D348: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x8009D34C: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x8009D350: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8009D354: lh          $t4, 0xE($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XE);
    // 0x8009D358: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8009D35C: lw          $t6, 0x4($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X4);
    // 0x8009D360: lw          $t8, 0x8($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X8);
    // 0x8009D364: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009D368: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8009D36C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8009D370: sll         $t9, $a0, 4
    ctx->r25 = S32(ctx->r4 << 4);
    // 0x8009D374: subu        $s0, $t4, $v1
    ctx->r16 = SUB32(ctx->r12, ctx->r3);
    // 0x8009D378: subu        $s2, $t5, $a0
    ctx->r18 = SUB32(ctx->r13, ctx->r4);
    // 0x8009D37C: addu        $fp, $t6, $t7
    ctx->r30 = ADD32(ctx->r14, ctx->r15);
    // 0x8009D380: bne         $a1, $at, L_8009D398
    if (ctx->r5 != ctx->r1) {
        // 0x8009D384: addu        $t0, $t8, $t9
        ctx->r8 = ADD32(ctx->r24, ctx->r25);
            goto L_8009D398;
    }
    // 0x8009D384: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8009D388: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8009D38C: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8009D390: b           L_8009D3B8
    // 0x8009D394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
        goto L_8009D3B8;
    // 0x8009D394: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8009D398:
    // 0x8009D398: lw          $t2, 0x0($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X0);
    // 0x8009D39C: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x8009D3A0: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x8009D3A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009D3A8: sll         $t5, $a3, 14
    ctx->r13 = S32(ctx->r7 << 14);
    // 0x8009D3AC: lw          $s3, 0x0($t4)
    ctx->r19 = MEM_W(ctx->r12, 0X0);
    // 0x8009D3B0: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8009D3B4: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
L_8009D3B8:
    // 0x8009D3B8: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8009D3BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009D3C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x8009D3C4: jal         0x8007B938
    // 0x8009D3C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set(rdram, ctx);
        goto after_0;
    // 0x8009D3C8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x8009D3CC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009D3D0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8009D3D4: addu        $a0, $fp, $t1
    ctx->r4 = ADD32(ctx->r30, ctx->r9);
    // 0x8009D3D8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8009D3DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8009D3E0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8009D3E4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8009D3E8: andi        $t9, $a0, 0x6
    ctx->r25 = ctx->r4 & 0X6;
    // 0x8009D3EC: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x8009D3F0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x8009D3F4: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8009D3F8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8009D3FC: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8009D400: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x8009D404: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x8009D408: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8009D40C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8009D410: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8009D414: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8009D418: or          $t3, $t5, $t2
    ctx->r11 = ctx->r13 | ctx->r10;
    // 0x8009D41C: addiu       $t6, $s2, -0x1
    ctx->r14 = ADD32(ctx->r18, -0X1);
    // 0x8009D420: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8009D424: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x8009D428: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8009D42C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8009D430: or          $t8, $t7, $s4
    ctx->r24 = ctx->r15 | ctx->r20;
    // 0x8009D434: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x8009D438: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8009D43C: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x8009D440: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x8009D444: sll         $t3, $s2, 4
    ctx->r11 = S32(ctx->r18 << 4);
    // 0x8009D448: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8009D44C: or          $t2, $t5, $at
    ctx->r10 = ctx->r13 | ctx->r1;
    // 0x8009D450: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x8009D454: or          $t6, $t2, $t4
    ctx->r14 = ctx->r10 | ctx->r12;
    // 0x8009D458: addu        $t7, $t0, $t1
    ctx->r15 = ADD32(ctx->r8, ctx->r9);
    // 0x8009D45C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009D460: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009D464: lh          $a2, 0x28($s5)
    ctx->r6 = MEM_H(ctx->r21, 0X28);
    // 0x8009D468: nop

L_8009D46C:
    // 0x8009D46C: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x8009D470: slt         $at, $s6, $a2
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8009D474: bne         $at, $zero, L_8009D328
    if (ctx->r1 != 0) {
        // 0x8009D478: addiu       $s7, $s7, 0xC
        ctx->r23 = ADD32(ctx->r23, 0XC);
            goto L_8009D328;
    }
    // 0x8009D478: addiu       $s7, $s7, 0xC
    ctx->r23 = ADD32(ctx->r23, 0XC);
L_8009D47C:
    // 0x8009D47C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8009D480: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009D484: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D488: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009D48C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8009D490: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8009D494: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8009D498: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8009D49C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8009D4A0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8009D4A4: jr          $ra
    // 0x8009D4A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8009D4A8: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void set_current_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3744: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C3748: lb          $t6, 0x3C00($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3C00);
    // 0x800C374C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C3750: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C3754: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C3758: beq         $t6, $zero, L_800C393C
    if (ctx->r14 == 0) {
        // 0x800C375C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C393C;
    }
    // 0x800C375C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C3760: bltz        $a0, L_800C393C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C3764: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C393C;
    }
    // 0x800C3764: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3768: lh          $t7, -0x52B0($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X52B0);
    // 0x800C376C: nop

    // 0x800C3770: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800C3774: beq         $at, $zero, L_800C3940
    if (ctx->r1 == 0) {
        // 0x800C3778: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C3940;
    }
    // 0x800C3778: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C377C: jal         0x8009F064
    // 0x800C3780: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x800C3780: nop

    after_0:
    // 0x800C3784: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C3788: beq         $v0, $at, L_800C37AC
    if (ctx->r2 == ctx->r1) {
        // 0x800C378C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_800C37AC;
    }
    // 0x800C378C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x800C3790: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C3794: beq         $v0, $at, L_800C37B4
    if (ctx->r2 == ctx->r1) {
        // 0x800C3798: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800C37B4;
    }
    // 0x800C3798: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800C379C: beq         $v0, $at, L_800C37BC
    if (ctx->r2 == ctx->r1) {
        // 0x800C37A0: nop
    
            goto L_800C37BC;
    }
    // 0x800C37A0: nop

    // 0x800C37A4: b           L_800C37C4
    // 0x800C37A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
        goto L_800C37C4;
    // 0x800C37A8: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C37AC:
    // 0x800C37AC: b           L_800C37C0
    // 0x800C37B0: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
        goto L_800C37C0;
    // 0x800C37B0: addiu       $s0, $s0, 0x55
    ctx->r16 = ADD32(ctx->r16, 0X55);
L_800C37B4:
    // 0x800C37B4: b           L_800C37C0
    // 0x800C37B8: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
        goto L_800C37C0;
    // 0x800C37B8: addiu       $s0, $s0, 0xAA
    ctx->r16 = ADD32(ctx->r16, 0XAA);
L_800C37BC:
    // 0x800C37BC: addiu       $s0, $s0, 0xFF
    ctx->r16 = ADD32(ctx->r16, 0XFF);
L_800C37C0:
    // 0x800C37C0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
L_800C37C4:
    // 0x800C37C4: and         $a2, $s0, $at
    ctx->r6 = ctx->r16 & ctx->r1;
    // 0x800C37C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C37CC: lw          $a1, -0x52C0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X52C0);
    // 0x800C37D0: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800C37D4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x800C37D8: jal         0x80077190
    // 0x800C37DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x800C37DC: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_1:
    // 0x800C37E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C37E4: lw          $a0, -0x52C0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X52C0);
    // 0x800C37E8: andi        $t9, $s0, 0x1
    ctx->r25 = ctx->r16 & 0X1;
    // 0x800C37EC: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C37F0: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
    // 0x800C37F4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800C37F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C37FC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x800C3800: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800C3804: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800C3808: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x800C380C: and         $t5, $t0, $a1
    ctx->r13 = ctx->r8 & ctx->r5;
    // 0x800C3810: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x800C3814: beq         $t1, $zero, L_800C387C
    if (ctx->r9 == 0) {
        // 0x800C3818: subu        $a3, $t4, $t5
        ctx->r7 = SUB32(ctx->r12, ctx->r13);
            goto L_800C387C;
    }
    // 0x800C3818: subu        $a3, $t4, $t5
    ctx->r7 = SUB32(ctx->r12, ctx->r13);
    // 0x800C381C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3820: addiu       $s0, $s0, -0x526C
    ctx->r16 = ADD32(ctx->r16, -0X526C);
    // 0x800C3824: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C3828: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C382C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C3830: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C3834: lw          $a1, -0x5278($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5278);
    // 0x800C3838: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C383C: jal         0x80077190
    // 0x800C3840: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800C3840: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    after_2:
    // 0x800C3844: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800C3848: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C384C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800C3850: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x800C3854: lw          $t2, -0x5278($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5278);
    // 0x800C3858: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C385C: jal         0x800C32C4
    // 0x800C3860: sw          $t2, -0x5270($at)
    MEM_W(-0X5270, ctx->r1) = ctx->r10;
    find_next_subtitle(rdram, ctx);
        goto after_3;
    // 0x800C3860: sw          $t2, -0x5270($at)
    MEM_W(-0X5270, ctx->r1) = ctx->r10;
    after_3:
    // 0x800C3864: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800C3868: nop

    // 0x800C386C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800C3870: andi        $t5, $t4, 0x1
    ctx->r13 = ctx->r12 & 0X1;
    // 0x800C3874: b           L_800C3948
    // 0x800C3878: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_800C3948;
    // 0x800C3878: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800C387C:
    // 0x800C387C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3880: addiu       $s0, $s0, -0x529C
    ctx->r16 = ADD32(ctx->r16, -0X529C);
    // 0x800C3884: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800C3888: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C388C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C3890: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800C3894: lw          $a1, -0x52A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X52A8);
    // 0x800C3898: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x800C389C: xor         $a2, $t0, $t1
    ctx->r6 = ctx->r8 ^ ctx->r9;
    // 0x800C38A0: jal         0x80077190
    // 0x800C38A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    asset_load(rdram, ctx);
        goto after_4;
    // 0x800C38A4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_4:
    // 0x800C38A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800C38AC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C38B0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800C38B4: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800C38B8: lw          $t9, -0x52A8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X52A8);
    // 0x800C38BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C38C0: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800C38C4: addiu       $a0, $a0, -0x52A0
    ctx->r4 = ADD32(ctx->r4, -0X52A0);
    // 0x800C38C8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800C38CC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800C38D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C38D8: sb          $zero, -0x52B8($at)
    MEM_B(-0X52B8, ctx->r1) = 0;
    // 0x800C38DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38E0: sb          $zero, -0x52BA($at)
    MEM_B(-0X52BA, ctx->r1) = 0;
    // 0x800C38E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38E8: sb          $zero, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = 0;
    // 0x800C38EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C38F0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800C38F4: sb          $t4, -0x52B9($at)
    MEM_B(-0X52B9, ctx->r1) = ctx->r12;
    // 0x800C38F8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800C38FC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C3900: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C3904: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800C3908: addu        $t7, $t6, $a3
    ctx->r15 = ADD32(ctx->r14, ctx->r7);
    // 0x800C390C: addiu       $a1, $a1, -0x52B7
    ctx->r5 = ADD32(ctx->r5, -0X52B7);
    // 0x800C3910: sb          $t5, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r13;
    // 0x800C3914: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800C3918: nop

    // 0x800C391C: bne         $t8, $zero, L_800C3948
    if (ctx->r24 != 0) {
        // 0x800C3920: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800C3948;
    }
    // 0x800C3920: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3924: sh          $zero, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = 0;
    // 0x800C3928: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C392C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3930: sb          $v0, -0x52B6($at)
    MEM_B(-0X52B6, ctx->r1) = ctx->r2;
    // 0x800C3934: b           L_800C3948
    // 0x800C3938: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_800C3948;
    // 0x800C3938: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_800C393C:
    // 0x800C393C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_800C3940:
    // 0x800C3940: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3944: sb          $t9, -0x52BC($at)
    MEM_B(-0X52BC, ctx->r1) = ctx->r25;
L_800C3948:
    // 0x800C3948: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C394C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C3950: jr          $ra
    // 0x800C3954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C3954: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void process_object_interactions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800155B8: addiu       $sp, $sp, -0x490
    ctx->r29 = ADD32(ctx->r29, -0X490);
    // 0x800155BC: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800155C0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800155C4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800155C8: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x800155CC: lw          $s3, -0x4C20($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X4C20);
    // 0x800155D0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x800155D4: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800155D8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800155DC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x800155E0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x800155E4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x800155E8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800155EC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800155F0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800155F4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800155F8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800155FC: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80015600: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015604: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80015608: beq         $at, $zero, L_800156A4
    if (ctx->r1 == 0) {
        // 0x8001560C: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800156A4;
    }
    // 0x8001560C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80015610: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80015614: addiu       $a0, $a0, -0x4C28
    ctx->r4 = ADD32(ctx->r4, -0X4C28);
    // 0x80015618: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x8001561C: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x80015620: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x80015624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80015628: addiu       $a1, $zero, -0x49
    ctx->r5 = ADD32(0, -0X49);
L_8001562C:
    // 0x8001562C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80015630: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015634: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80015638: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8001563C: nop

    // 0x80015640: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x80015644: nop

    // 0x80015648: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001564C: bne         $t9, $zero, L_8001569C
    if (ctx->r25 != 0) {
        // 0x80015650: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015650: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015654: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015658: sll         $t0, $s5, 2
    ctx->r8 = S32(ctx->r21 << 2);
    // 0x8001565C: beq         $s2, $zero, L_80015698
    if (ctx->r18 == 0) {
        // 0x80015660: addu        $t1, $s6, $t0
        ctx->r9 = ADD32(ctx->r22, ctx->r8);
            goto L_80015698;
    }
    // 0x80015660: addu        $t1, $s6, $t0
    ctx->r9 = ADD32(ctx->r22, ctx->r8);
    // 0x80015664: sw          $s1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r17;
    // 0x80015668: lbu         $t2, 0x11($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X11);
    // 0x8001566C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80015670: beq         $fp, $t2, L_8001569C
    if (ctx->r30 == ctx->r10) {
        // 0x80015674: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001569C;
    }
    // 0x80015674: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80015678: lh          $t3, 0x14($s2)
    ctx->r11 = MEM_H(ctx->r18, 0X14);
    // 0x8001567C: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x80015680: and         $t4, $t3, $a1
    ctx->r12 = ctx->r11 & ctx->r5;
    // 0x80015684: sh          $t4, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r12;
    // 0x80015688: sb          $a2, 0x13($s2)
    MEM_B(0X13, ctx->r18) = ctx->r6;
    // 0x8001568C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80015690: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80015694: nop

L_80015698:
    // 0x80015698: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_8001569C:
    // 0x8001569C: bne         $at, $zero, L_8001562C
    if (ctx->r1 != 0) {
        // 0x800156A0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001562C;
    }
    // 0x800156A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_800156A4:
    // 0x800156A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800156A8: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x800156AC: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800156B0: sw          $zero, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = 0;
    // 0x800156B4: blez        $s5, L_80015864
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800156B8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80015864;
    }
    // 0x800156B8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800156BC: lui         $at, 0x4880
    ctx->r1 = S32(0X4880 << 16);
    // 0x800156C0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800156C4: lui         $at, 0x4A80
    ctx->r1 = S32(0X4A80 << 16);
    // 0x800156C8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800156CC: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x800156D0: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800156D4:
    // 0x800156D4: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800156D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800156DC: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800156E0: nop

    // 0x800156E4: lbu         $t5, 0x11($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X11);
    // 0x800156E8: nop

    // 0x800156EC: bne         $fp, $t5, L_80015728
    if (ctx->r30 != ctx->r13) {
        // 0x800156F0: nop
    
            goto L_80015728;
    }
    // 0x800156F0: nop

    // 0x800156F4: lw          $v0, -0x4C10($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C10);
    // 0x800156F8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800156FC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80015700: beq         $at, $zero, L_80015728
    if (ctx->r1 == 0) {
        // 0x80015704: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80015728;
    }
    // 0x80015704: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80015708: lw          $t6, -0x4C14($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C14);
    // 0x8001570C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80015710: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80015714: sw          $s1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r17;
    // 0x80015718: lw          $t9, -0x4C10($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C10);
    // 0x8001571C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80015720: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80015724: sw          $t0, -0x4C10($at)
    MEM_W(-0X4C10, ctx->r1) = ctx->r8;
L_80015728:
    // 0x80015728: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x8001572C: nop

    // 0x80015730: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x80015734: beq         $t1, $zero, L_80015804
    if (ctx->r9 == 0) {
        // 0x80015738: andi        $t6, $v0, 0x100
        ctx->r14 = ctx->r2 & 0X100;
            goto L_80015804;
    }
    // 0x80015738: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
    // 0x8001573C: blez        $s5, L_80015800
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015740: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015800;
    }
    // 0x80015740: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015744:
    // 0x80015744: beq         $s3, $s0, L_800157EC
    if (ctx->r19 == ctx->r16) {
        // 0x80015748: sll         $t2, $s0, 2
        ctx->r10 = S32(ctx->r16 << 2);
            goto L_800157EC;
    }
    // 0x80015748: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x8001574C: addu        $t3, $s6, $t2
    ctx->r11 = ADD32(ctx->r22, ctx->r10);
    // 0x80015750: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
    // 0x80015754: nop

    // 0x80015758: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001575C: nop

    // 0x80015760: lh          $v1, 0x14($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X14);
    // 0x80015764: nop

    // 0x80015768: andi        $t4, $v1, 0x3
    ctx->r12 = ctx->r3 & 0X3;
    // 0x8001576C: beq         $t4, $zero, L_800157EC
    if (ctx->r12 == 0) {
        // 0x80015770: nop
    
            goto L_800157EC;
    }
    // 0x80015770: nop

    // 0x80015774: lbu         $a0, 0x11($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X11);
    // 0x80015778: nop

    // 0x8001577C: bne         $s4, $a0, L_80015794
    if (ctx->r20 != ctx->r4) {
        // 0x80015780: nop
    
            goto L_80015794;
    }
    // 0x80015780: nop

    // 0x80015784: jal         0x8001677C
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_0;
    // 0x80015788: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8001578C: b           L_800157F0
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800157F0;
    // 0x80015790: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80015794:
    // 0x80015794: beq         $fp, $a0, L_800157EC
    if (ctx->r30 == ctx->r4) {
        // 0x80015798: andi        $t5, $v1, 0x20
        ctx->r13 = ctx->r3 & 0X20;
            goto L_800157EC;
    }
    // 0x80015798: andi        $t5, $v1, 0x20
    ctx->r13 = ctx->r3 & 0X20;
    // 0x8001579C: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800157A0: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800157A4: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800157A8: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800157AC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800157B0: beq         $t5, $zero, L_800157C0
    if (ctx->r13 == 0) {
        // 0x800157B4: sub.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
            goto L_800157C0;
    }
    // 0x800157B4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800157B8: b           L_800157C4
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
        goto L_800157C4;
    // 0x800157BC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_800157C0:
    // 0x800157C0: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
L_800157C4:
    // 0x800157C4: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800157C8: nop

    // 0x800157CC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800157D0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800157D4: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800157D8: nop

    // 0x800157DC: bc1f        L_800157EC
    if (!c1cs) {
        // 0x800157E0: nop
    
            goto L_800157EC;
    }
    // 0x800157E0: nop

    // 0x800157E4: jal         0x800159C8
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_800159C8(rdram, ctx);
        goto after_1;
    // 0x800157E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_800157EC:
    // 0x800157EC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800157F0:
    // 0x800157F0: bne         $s0, $s5, L_80015744
    if (ctx->r16 != ctx->r21) {
        // 0x800157F4: nop
    
            goto L_80015744;
    }
    // 0x800157F4: nop

    // 0x800157F8: lh          $v0, 0x14($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X14);
    // 0x800157FC: nop

L_80015800:
    // 0x80015800: andi        $t6, $v0, 0x100
    ctx->r14 = ctx->r2 & 0X100;
L_80015804:
    // 0x80015804: beq         $t6, $zero, L_80015854
    if (ctx->r14 == 0) {
        // 0x80015808: nop
    
            goto L_80015854;
    }
    // 0x80015808: nop

    // 0x8001580C: blez        $s5, L_80015854
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015810: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80015854;
    }
    // 0x80015810: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80015814:
    // 0x80015814: beq         $s3, $s0, L_80015848
    if (ctx->r19 == ctx->r16) {
        // 0x80015818: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80015848;
    }
    // 0x80015818: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8001581C: addu        $t8, $s6, $t7
    ctx->r24 = ADD32(ctx->r22, ctx->r15);
    // 0x80015820: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80015824: nop

    // 0x80015828: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8001582C: nop

    // 0x80015830: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x80015834: nop

    // 0x80015838: bne         $s4, $t9, L_80015848
    if (ctx->r20 != ctx->r25) {
        // 0x8001583C: nop
    
            goto L_80015848;
    }
    // 0x8001583C: nop

    // 0x80015840: jal         0x8001677C
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_80016748(rdram, ctx);
        goto after_2;
    // 0x80015844: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
L_80015848:
    // 0x80015848: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001584C: bne         $s0, $s5, L_80015814
    if (ctx->r16 != ctx->r21) {
        // 0x80015850: nop
    
            goto L_80015814;
    }
    // 0x80015850: nop

L_80015854:
    // 0x80015854: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015858: bne         $s3, $s5, L_800156D4
    if (ctx->r19 != ctx->r21) {
        // 0x8001585C: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_800156D4;
    }
    // 0x8001585C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015860: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80015864:
    // 0x80015864: blez        $s5, L_80015988
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80015868: andi        $v1, $s5, 0x3
        ctx->r3 = ctx->r21 & 0X3;
            goto L_80015988;
    }
    // 0x80015868: andi        $v1, $s5, 0x3
    ctx->r3 = ctx->r21 & 0X3;
    // 0x8001586C: beq         $v1, $zero, L_800158B4
    if (ctx->r3 == 0) {
        // 0x80015870: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800158B4;
    }
    // 0x80015870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80015874: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x80015878: addiu       $t1, $sp, 0x64
    ctx->r9 = ADD32(ctx->r29, 0X64);
    // 0x8001587C: addu        $s7, $t0, $t1
    ctx->r23 = ADD32(ctx->r8, ctx->r9);
L_80015880:
    // 0x80015880: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x80015884: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80015888: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x8001588C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015890: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80015894: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015898: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8001589C: nop

    // 0x800158A0: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x800158A4: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158A8: bne         $v0, $s3, L_80015880
    if (ctx->r2 != ctx->r19) {
        // 0x800158AC: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_80015880;
    }
    // 0x800158AC: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x800158B0: beq         $s3, $s5, L_80015988
    if (ctx->r19 == ctx->r21) {
        // 0x800158B4: addiu       $t3, $sp, 0x64
        ctx->r11 = ADD32(ctx->r29, 0X64);
            goto L_80015988;
    }
L_800158B4:
    // 0x800158B4: addiu       $t3, $sp, 0x64
    ctx->r11 = ADD32(ctx->r29, 0X64);
    // 0x800158B8: sll         $t2, $s3, 2
    ctx->r10 = S32(ctx->r19 << 2);
    // 0x800158BC: sll         $t4, $s5, 2
    ctx->r12 = S32(ctx->r21 << 2);
    // 0x800158C0: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x800158C4: addu        $s7, $t2, $t3
    ctx->r23 = ADD32(ctx->r10, ctx->r11);
L_800158C8:
    // 0x800158C8: lw          $s1, 0x0($s7)
    ctx->r17 = MEM_W(ctx->r23, 0X0);
    // 0x800158CC: addiu       $s7, $s7, 0x10
    ctx->r23 = ADD32(ctx->r23, 0X10);
    // 0x800158D0: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x800158D4: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800158D8: nop

    // 0x800158DC: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x800158E0: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800158E4: nop

    // 0x800158E8: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x800158EC: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800158F0: nop

    // 0x800158F4: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x800158F8: lw          $s1, -0xC($s7)
    ctx->r17 = MEM_W(ctx->r23, -0XC);
    // 0x800158FC: nop

    // 0x80015900: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015904: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015908: nop

    // 0x8001590C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015910: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015914: nop

    // 0x80015918: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001591C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015920: nop

    // 0x80015924: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
    // 0x80015928: lw          $s1, -0x8($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X8);
    // 0x8001592C: nop

    // 0x80015930: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015934: lwc1        $f16, 0xC($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015938: nop

    // 0x8001593C: swc1        $f16, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f16.u32l;
    // 0x80015940: lwc1        $f18, 0x10($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015944: nop

    // 0x80015948: swc1        $f18, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f18.u32l;
    // 0x8001594C: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015950: nop

    // 0x80015954: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x80015958: lw          $s1, -0x4($s7)
    ctx->r17 = MEM_W(ctx->r23, -0X4);
    // 0x8001595C: nop

    // 0x80015960: lw          $s2, 0x4C($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X4C);
    // 0x80015964: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x80015968: nop

    // 0x8001596C: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80015970: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80015974: nop

    // 0x80015978: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x8001597C: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80015980: bne         $s7, $v0, L_800158C8
    if (ctx->r23 != ctx->r2) {
        // 0x80015984: swc1        $f10, 0xC($s2)
        MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
            goto L_800158C8;
    }
    // 0x80015984: swc1        $f10, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f10.u32l;
L_80015988:
    // 0x80015988: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8001598C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015990: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015994: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80015998: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001599C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800159A0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800159A4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800159A8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800159AC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800159B0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800159B4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x800159B8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x800159BC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x800159C0: jr          $ra
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
    return;
    // 0x800159C4: addiu       $sp, $sp, 0x490
    ctx->r29 = ADD32(ctx->r29, 0X490);
;}
RECOMP_FUNC void music_jingle_voicelimit_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000C38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80000C3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80000C40: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80000C44: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80000C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000C4C: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80000C50: jal         0x8000B010
    // 0x80000C54: nop

    set_voice_limit(rdram, ctx);
        goto after_0;
    // 0x80000C54: nop

    after_0:
    // 0x80000C58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000C5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000C60: jr          $ra
    // 0x80000C64: nop

    return;
    // 0x80000C64: nop

;}
RECOMP_FUNC void titlescreen_controller_assign(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B3B8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008B3BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8008B3C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008B3C4: addiu       $a1, $t6, 0x6988
    ctx->r5 = ADD32(ctx->r14, 0X6988);
    // 0x8008B3C8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008B3CC: sw          $a2, -0x5C4($at)
    MEM_W(-0X5C4, ctx->r1) = ctx->r6;
    // 0x8008B3D0: addiu       $v0, $v0, 0x6990
    ctx->r2 = ADD32(ctx->r2, 0X6990);
    // 0x8008B3D4: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x8008B3D8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8008B3DC:
    // 0x8008B3DC: bne         $a1, $v1, L_8008B3EC
    if (ctx->r5 != ctx->r3) {
        // 0x8008B3E0: nop
    
            goto L_8008B3EC;
    }
    // 0x8008B3E0: nop

    // 0x8008B3E4: b           L_8008B3F0
    // 0x8008B3E8: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
        goto L_8008B3F0;
    // 0x8008B3E8: sb          $a2, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r6;
L_8008B3EC:
    // 0x8008B3EC: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8008B3F0:
    // 0x8008B3F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008B3F4: sltu        $at, $a1, $v0
    ctx->r1 = ctx->r5 < ctx->r2 ? 1 : 0;
    // 0x8008B3F8: bne         $at, $zero, L_8008B3DC
    if (ctx->r1 != 0) {
        // 0x8008B3FC: nop
    
            goto L_8008B3DC;
    }
    // 0x8008B3FC: nop

    // 0x8008B400: bne         $a0, $zero, L_8008B418
    if (ctx->r4 != 0) {
        // 0x8008B404: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008B418;
    }
    // 0x8008B404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B408: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8008B40C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B410: b           L_8008B41C
    // 0x8008B414: sb          $t7, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = ctx->r15;
        goto L_8008B41C;
    // 0x8008B414: sb          $t7, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = ctx->r15;
L_8008B418:
    // 0x8008B418: sb          $zero, 0x6974($at)
    MEM_B(0X6974, ctx->r1) = 0;
L_8008B41C:
    // 0x8008B41C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8008B420: bne         $a0, $at, L_8008B434
    if (ctx->r4 != ctx->r1) {
        // 0x8008B424: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8008B434;
    }
    // 0x8008B424: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008B428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B42C: b           L_8008B43C
    // 0x8008B430: sb          $t8, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = ctx->r24;
        goto L_8008B43C;
    // 0x8008B430: sb          $t8, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = ctx->r24;
L_8008B434:
    // 0x8008B434: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B438: sb          $zero, 0x6975($at)
    MEM_B(0X6975, ctx->r1) = 0;
L_8008B43C:
    // 0x8008B43C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8008B440: bne         $a0, $at, L_8008B454
    if (ctx->r4 != ctx->r1) {
        // 0x8008B444: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8008B454;
    }
    // 0x8008B444: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008B448: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B44C: b           L_8008B45C
    // 0x8008B450: sb          $t9, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = ctx->r25;
        goto L_8008B45C;
    // 0x8008B450: sb          $t9, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = ctx->r25;
L_8008B454:
    // 0x8008B454: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B458: sb          $zero, 0x6976($at)
    MEM_B(0X6976, ctx->r1) = 0;
L_8008B45C:
    // 0x8008B45C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008B460: bne         $a0, $at, L_8008B474
    if (ctx->r4 != ctx->r1) {
        // 0x8008B464: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_8008B474;
    }
    // 0x8008B464: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8008B468: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B46C: jr          $ra
    // 0x8008B470: sb          $t0, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = ctx->r8;
    return;
    // 0x8008B470: sb          $t0, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = ctx->r8;
L_8008B474:
    // 0x8008B474: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008B478: sb          $zero, 0x6977($at)
    MEM_B(0X6977, ctx->r1) = 0;
    // 0x8008B47C: jr          $ra
    // 0x8008B480: nop

    return;
    // 0x8008B480: nop

;}
RECOMP_FUNC void input_clamp_stick_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A820: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006A824: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8006A828: lbu         $t6, 0x16D0($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X16D0);
    // 0x8006A82C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006A830: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006A834: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8006A838: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006A83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006A840: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8006A844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006A848: lb          $a0, 0x1693($a0)
    ctx->r4 = MEM_B(ctx->r4, 0X1693);
    // 0x8006A84C: jal         0x8006A864
    // 0x8006A850: nop

    input_clamp_stick_mag(rdram, ctx);
        goto after_0;
    // 0x8006A850: nop

    after_0:
    // 0x8006A854: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006A858: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006A85C: jr          $ra
    // 0x8006A860: nop

    return;
    // 0x8006A860: nop

;}
RECOMP_FUNC void menu_assetgroup_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C9EC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009C9F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009C9F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009C9F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009C9FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009CA00: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8009CA04: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009CA08: beq         $s2, $t6, L_8009CA38
    if (ctx->r18 == ctx->r14) {
        // 0x8009CA0C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8009CA38;
    }
    // 0x8009CA0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009CA10: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x8009CA14: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009CA18: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8009CA1C:
    // 0x8009CA1C: jal         0x8009CA4C
    // 0x8009CA20: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    menu_asset_free(rdram, ctx);
        goto after_0;
    // 0x8009CA20: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    after_0:
    // 0x8009CA24: lh          $s1, 0x0($s0)
    ctx->r17 = MEM_H(ctx->r16, 0X0);
    // 0x8009CA28: nop

    // 0x8009CA2C: bne         $s2, $s1, L_8009CA1C
    if (ctx->r18 != ctx->r17) {
        // 0x8009CA30: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8009CA1C;
    }
    // 0x8009CA30: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8009CA34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8009CA38:
    // 0x8009CA38: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009CA3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009CA40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009CA44: jr          $ra
    // 0x8009CA48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009CA48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_log(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800405B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800405B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800405B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800405BC: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x800405C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800405C4: beq         $a3, $zero, L_800405E0
    if (ctx->r7 == 0) {
        // 0x800405C8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800405E0;
    }
    // 0x800405C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800405CC: jal         0x800BF3D4
    // 0x800405D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    obj_wave_height(rdram, ctx);
        goto after_0;
    // 0x800405D0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800405D4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800405D8: b           L_80040600
    // 0x800405DC: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
        goto L_80040600;
    // 0x800405DC: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
L_800405E0:
    // 0x800405E0: lw          $t6, 0x3C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X3C);
    // 0x800405E4: nop

    // 0x800405E8: lh          $t7, 0x4($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X4);
    // 0x800405EC: nop

    // 0x800405F0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800405F4: nop

    // 0x800405F8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800405FC: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
L_80040600:
    // 0x80040600: lw          $v0, 0x5C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5C);
    // 0x80040604: nop

    // 0x80040608: lw          $t8, 0x100($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X100);
    // 0x8004060C: nop

    // 0x80040610: beq         $t8, $zero, L_80040788
    if (ctx->r24 == 0) {
        // 0x80040614: nop
    
            goto L_80040788;
    }
    // 0x80040614: nop

    // 0x80040618: lw          $t9, 0x7C($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X7C);
    // 0x8004061C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80040620: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80040624: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x80040628: lw          $v1, 0x100($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X100);
    // 0x8004062C: nop

    // 0x80040630: lh          $t1, 0x48($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X48);
    // 0x80040634: nop

    // 0x80040638: bne         $t1, $at, L_80040694
    if (ctx->r9 != ctx->r1) {
        // 0x8004063C: nop
    
            goto L_80040694;
    }
    // 0x8004063C: nop

    // 0x80040640: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80040644: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x80040648: lwc1        $f8, 0x2C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004064C: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80040650: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80040654: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x80040658: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x8004065C: nop

    // 0x80040660: bc1f        L_80040694
    if (!c1cs) {
        // 0x80040664: nop
    
            goto L_80040694;
    }
    // 0x80040664: nop

    // 0x80040668: lb          $t2, 0x1D8($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1D8);
    // 0x8004066C: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80040670: bne         $t2, $zero, L_80040694
    if (ctx->r10 != 0) {
        // 0x80040674: nop
    
            goto L_80040694;
    }
    // 0x80040674: nop

    // 0x80040678: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x8004067C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80040680: jal         0x80072594
    // 0x80040684: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    rumble_set(rdram, ctx);
        goto after_1;
    // 0x80040684: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80040688: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8004068C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80040690: nop

L_80040694:
    // 0x80040694: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80040698: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8004069C: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800406A0: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x800406A4: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800406A8: jal         0x80070A04
    // 0x800406AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800406AC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_2:
    // 0x800406B0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800406B4: nop

    // 0x800406B8: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x800406BC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800406C0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800406C4: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800406C8: jal         0x80070A38
    // 0x800406CC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    coss_f(rdram, ctx);
        goto after_3;
    // 0x800406CC: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_3:
    // 0x800406D0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800406D4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800406D8: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800406DC: lwc1        $f18, 0xC($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800406E0: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800406E4: sub.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800406E8: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800406EC: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800406F0: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800406F4: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800406F8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800406FC: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80040700: lwc1        $f6, 0x24($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80040704: mul.s       $f16, $f12, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80040708: lw          $t7, 0x78($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X78);
    // 0x8004070C: addiu       $t2, $zero, -0x200
    ctx->r10 = ADD32(0, -0X200);
    // 0x80040710: mul.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80040714: add.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80040718: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004071C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80040720: sub.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80040724: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80040728: nop

    // 0x8004072C: div.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80040730: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80040734: nop

    // 0x80040738: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8004073C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80040740: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80040744: nop

    // 0x80040748: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8004074C: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80040750: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80040754: subu        $v0, $t7, $t9
    ctx->r2 = SUB32(ctx->r15, ctx->r25);
    // 0x80040758: slti        $at, $v0, 0x201
    ctx->r1 = SIGNED(ctx->r2) < 0X201 ? 1 : 0;
    // 0x8004075C: bne         $at, $zero, L_8004076C
    if (ctx->r1 != 0) {
        // 0x80040760: sw          $v0, 0x78($a2)
        MEM_W(0X78, ctx->r6) = ctx->r2;
            goto L_8004076C;
    }
    // 0x80040760: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
    // 0x80040764: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x80040768: sw          $v0, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r2;
L_8004076C:
    // 0x8004076C: slti        $at, $v0, -0x200
    ctx->r1 = SIGNED(ctx->r2) < -0X200 ? 1 : 0;
    // 0x80040770: beq         $at, $zero, L_8004077C
    if (ctx->r1 == 0) {
        // 0x80040774: nop
    
            goto L_8004077C;
    }
    // 0x80040774: nop

    // 0x80040778: sw          $t2, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r10;
L_8004077C:
    // 0x8004077C: lw          $v1, 0x7C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X7C);
    // 0x80040780: b           L_800407A4
    // 0x80040784: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
        goto L_800407A4;
    // 0x80040784: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_80040788:
    // 0x80040788: lw          $v1, 0x7C($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X7C);
    // 0x8004078C: nop

    // 0x80040790: blez        $v1, L_800407A0
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80040794: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_800407A0;
    }
    // 0x80040794: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80040798: sw          $t3, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r11;
    // 0x8004079C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_800407A0:
    // 0x800407A0: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
L_800407A4:
    // 0x800407A4: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800407A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800407AC: lw          $v0, 0x78($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X78);
    // 0x800407B0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800407B4: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800407B8: sub.d       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f4.d - ctx->f16.d;
    // 0x800407BC: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x800407C0: blez        $v0, L_800407E8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800407C4: swc1        $f6, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
            goto L_800407E8;
    }
    // 0x800407C4: swc1        $f6, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f6.u32l;
    // 0x800407C8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800407CC: nop

    // 0x800407D0: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x800407D4: sw          $t5, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r13;
    // 0x800407D8: bgez        $t5, L_800407E8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800407DC: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_800407E8;
    }
    // 0x800407DC: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x800407E0: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x800407E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800407E8:
    // 0x800407E8: bgez        $v0, L_80040814
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800407EC: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_80040814;
    }
    // 0x800407EC: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800407F0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800407F4: nop

    // 0x800407F8: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x800407FC: sw          $t8, 0x78($a2)
    MEM_W(0X78, ctx->r6) = ctx->r24;
    // 0x80040800: blez        $t8, L_80040810
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80040804: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_80040810;
    }
    // 0x80040804: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x80040808: sw          $zero, 0x78($a2)
    MEM_W(0X78, ctx->r6) = 0;
    // 0x8004080C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80040810:
    // 0x80040810: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_80040814:
    // 0x80040814: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x80040818: multu       $v0, $t9
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004081C: lw          $t2, 0x5C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X5C);
    // 0x80040820: mflo        $t0
    ctx->r8 = lo;
    // 0x80040824: addu        $t1, $t7, $t0
    ctx->r9 = ADD32(ctx->r15, ctx->r8);
    // 0x80040828: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x8004082C: sw          $zero, 0x100($t2)
    MEM_W(0X100, ctx->r10) = 0;
    // 0x80040830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040834: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80040838: jr          $ra
    // 0x8004083C: nop

    return;
    // 0x8004083C: nop

;}
RECOMP_FUNC void audspat_point_create(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000974C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80009750: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80009754: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009758: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000975C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80009760: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80009764: beq         $a1, $zero, L_8000978C
    if (ctx->r5 == 0) {
        // 0x80009768: sw          $a3, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r7;
            goto L_8000978C;
    }
    // 0x80009768: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8000976C: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009770: nop

    // 0x80009774: ori         $t6, $a0, 0xE000
    ctx->r14 = ctx->r4 | 0XE000;
    // 0x80009778: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8000977C: jal         0x800245E8
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    func_800245B4(rdram, ctx);
        goto after_0;
    // 0x80009780: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_0:
    // 0x80009784: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80009788: nop

L_8000978C:
    // 0x8000978C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80009790: addiu       $a0, $a0, -0x33B0
    ctx->r4 = ADD32(ctx->r4, -0X33B0);
    // 0x80009794: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80009798: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x8000979C: bne         $t9, $at, L_800097C0
    if (ctx->r25 != ctx->r1) {
        // 0x800097A0: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800097C0;
    }
    // 0x800097A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800097A4: beq         $a1, $zero, L_800097B0
    if (ctx->r5 == 0) {
        // 0x800097A8: nop
    
            goto L_800097B0;
    }
    // 0x800097A8: nop

    // 0x800097AC: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800097B0:
    // 0x800097B0: jal         0x800245E8
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x800097B4: addiu       $a0, $zero, -0x55AB
    ctx->r4 = ADD32(0, -0X55AB);
    after_1:
    // 0x800097B8: b           L_80009898
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80009898;
    // 0x800097BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800097C0:
    // 0x800097C0: addiu       $a2, $a2, -0x5E34
    ctx->r6 = ADD32(ctx->r6, -0X5E34);
    // 0x800097C4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800097C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800097CC: lw          $t0, -0x5E30($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5E30);
    // 0x800097D0: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x800097D4: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800097D8: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800097DC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800097E0: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800097E4: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800097E8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800097EC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800097F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800097F4: swc1        $f6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f6.u32l;
    // 0x800097F8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800097FC: nop

    // 0x80009800: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x80009804: lhu         $t4, 0x1A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X1A);
    // 0x80009808: nop

    // 0x8000980C: sh          $t4, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r12;
    // 0x80009810: lbu         $t5, 0x2B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X2B);
    // 0x80009814: nop

    // 0x80009818: sb          $t5, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r13;
    // 0x8000981C: lbu         $t6, 0x2F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X2F);
    // 0x80009820: nop

    // 0x80009824: sb          $t6, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r14;
    // 0x80009828: lbu         $t7, 0x33($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X33);
    // 0x8000982C: nop

    // 0x80009830: sb          $t7, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r15;
    // 0x80009834: lbu         $t8, 0x3F($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X3F);
    // 0x80009838: nop

    // 0x8000983C: sb          $t8, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r24;
    // 0x80009840: lhu         $t9, 0x36($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X36);
    // 0x80009844: nop

    // 0x80009848: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8000984C: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80009850: nop

    // 0x80009854: sb          $t0, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r8;
    // 0x80009858: lbu         $t1, 0x43($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X43);
    // 0x8000985C: sb          $zero, 0x22($v0)
    MEM_B(0X22, ctx->r2) = 0;
    // 0x80009860: sw          $a1, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r5;
    // 0x80009864: sb          $t1, 0x21($v0)
    MEM_B(0X21, ctx->r2) = ctx->r9;
    // 0x80009868: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    // 0x8000986C: lw          $t2, -0x5E3C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5E3C);
    // 0x80009870: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80009874: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80009878: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000987C: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x80009880: nop

    // 0x80009884: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80009888: beq         $a1, $zero, L_80009894
    if (ctx->r5 == 0) {
        // 0x8000988C: sh          $t7, 0x0($a0)
        MEM_H(0X0, ctx->r4) = ctx->r15;
            goto L_80009894;
    }
    // 0x8000988C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x80009890: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_80009894:
    // 0x80009894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80009898:
    // 0x80009898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000989C: jr          $ra
    // 0x800098A0: nop

    return;
    // 0x800098A0: nop

;}
RECOMP_FUNC void func_800149C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800149C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800149C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800149C8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800149CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800149D0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800149D4: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800149D8: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800149DC: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x800149E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800149E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800149E8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800149EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800149F0: lbu         $a3, 0x4($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X4);
    // 0x800149F4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800149F8: jal         0x80014B50
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    func_80014B50(rdram, ctx);
        goto after_0;
    // 0x800149FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80014A00: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80014A04: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80014A08: lbu         $a3, 0x4($t8)
    ctx->r7 = MEM_BU(ctx->r24, 0X4);
    // 0x80014A0C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80014A10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80014A14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80014A18: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80014A1C: jal         0x80014B50
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    func_80014B50(rdram, ctx);
        goto after_1;
    // 0x80014A20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    after_1:
    // 0x80014A24: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80014A28: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80014A2C: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80014A30: beq         $at, $zero, L_80014B28
    if (ctx->r1 == 0) {
        // 0x80014A34: subu        $a0, $t3, $v0
        ctx->r4 = SUB32(ctx->r11, ctx->r2);
            goto L_80014B28;
    }
    // 0x80014A34: subu        $a0, $t3, $v0
    ctx->r4 = SUB32(ctx->r11, ctx->r2);
    // 0x80014A38: andi        $t9, $a0, 0x3
    ctx->r25 = ctx->r4 & 0X3;
    // 0x80014A3C: beq         $t9, $zero, L_80014A80
    if (ctx->r25 == 0) {
        // 0x80014A40: addu        $a2, $t9, $v0
        ctx->r6 = ADD32(ctx->r25, ctx->r2);
            goto L_80014A80;
    }
    // 0x80014A40: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x80014A44: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A48: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A4C: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80014A50: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
L_80014A54:
    // 0x80014A54: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014A58: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80014A5C: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014A60: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80014A64: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80014A68: lb          $t7, 0x38($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X38);
    // 0x80014A6C: nop

    // 0x80014A70: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014A74: bne         $a2, $a1, L_80014A54
    if (ctx->r6 != ctx->r5) {
        // 0x80014A78: sb          $t6, 0x38($a0)
        MEM_B(0X38, ctx->r4) = ctx->r14;
            goto L_80014A54;
    }
    // 0x80014A78: sb          $t6, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r14;
    // 0x80014A7C: beq         $a1, $t3, L_80014B28
    if (ctx->r5 == ctx->r11) {
        // 0x80014A80: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_80014B28;
    }
L_80014A80:
    // 0x80014A80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80014A84: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x80014A88: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x80014A8C: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x80014A90: sll         $t2, $t3, 2
    ctx->r10 = S32(ctx->r11 << 2);
L_80014A94:
    // 0x80014A94: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014A98: nop

    // 0x80014A9C: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014AA0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80014AA4: nop

    // 0x80014AA8: lb          $t4, 0x38($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X38);
    // 0x80014AAC: nop

    // 0x80014AB0: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014AB4: sb          $t5, 0x38($a0)
    MEM_B(0X38, ctx->r4) = ctx->r13;
    // 0x80014AB8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80014ABC: nop

    // 0x80014AC0: addu        $t6, $t7, $v1
    ctx->r14 = ADD32(ctx->r15, ctx->r3);
    // 0x80014AC4: lw          $a1, 0x4($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X4);
    // 0x80014AC8: nop

    // 0x80014ACC: lb          $t8, 0x38($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X38);
    // 0x80014AD0: nop

    // 0x80014AD4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80014AD8: sb          $t9, 0x38($a1)
    MEM_B(0X38, ctx->r5) = ctx->r25;
    // 0x80014ADC: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80014AE0: nop

    // 0x80014AE4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80014AE8: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x80014AEC: nop

    // 0x80014AF0: lb          $t7, 0x38($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X38);
    // 0x80014AF4: nop

    // 0x80014AF8: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80014AFC: sb          $t6, 0x38($a2)
    MEM_B(0X38, ctx->r6) = ctx->r14;
    // 0x80014B00: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80014B04: nop

    // 0x80014B08: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x80014B0C: lw          $a3, 0xC($t9)
    ctx->r7 = MEM_W(ctx->r25, 0XC);
    // 0x80014B10: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80014B14: lb          $t4, 0x38($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X38);
    // 0x80014B18: nop

    // 0x80014B1C: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x80014B20: bne         $v1, $t2, L_80014A94
    if (ctx->r3 != ctx->r10) {
        // 0x80014B24: sb          $t5, 0x38($a3)
        MEM_B(0X38, ctx->r7) = ctx->r13;
            goto L_80014A94;
    }
    // 0x80014B24: sb          $t5, 0x38($a3)
    MEM_B(0X38, ctx->r7) = ctx->r13;
L_80014B28:
    // 0x80014B28: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80014B2C: addiu       $t6, $t3, -0x1
    ctx->r14 = ADD32(ctx->r11, -0X1);
    // 0x80014B30: sw          $v0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r2;
    // 0x80014B34: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80014B38: nop

    // 0x80014B3C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x80014B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014B44: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80014B48: jr          $ra
    // 0x80014B4C: nop

    return;
    // 0x80014B4C: nop

;}
RECOMP_FUNC void void_generate_primitive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800271C4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800271C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800271CC: addiu       $a2, $a2, -0x25C8
    ctx->r6 = ADD32(ctx->r6, -0X25C8);
    // 0x800271D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800271D4: lh          $t7, -0x25C4($t7)
    ctx->r15 = MEM_H(ctx->r15, -0X25C4);
    // 0x800271D8: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x800271DC: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800271E0: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800271E4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800271E8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800271EC: bne         $at, $zero, L_800271FC
    if (ctx->r1 != 0) {
        // 0x800271F0: sw          $a3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r7;
            goto L_800271FC;
    }
    // 0x800271F0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800271F4: b           L_80027598
    // 0x800271F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80027598;
    // 0x800271F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800271FC:
    // 0x800271FC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80027200: addiu       $v1, $v1, -0x25CA
    ctx->r3 = ADD32(ctx->r3, -0X25CA);
    // 0x80027204: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80027208: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x8002720C: bne         $v0, $at, L_800272F8
    if (ctx->r2 != ctx->r1) {
        // 0x80027210: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_800272F8;
    }
    // 0x80027210: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027214: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80027218: addiu       $t5, $t5, -0x49E0
    ctx->r13 = ADD32(ctx->r13, -0X49E0);
    // 0x8002721C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80027220: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80027224: addiu       $s0, $s0, -0x25F8
    ctx->r16 = ADD32(ctx->r16, -0X25F8);
    // 0x80027228: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002722C: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x80027230: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x80027234: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80027238: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8002723C: sll         $t6, $t9, 3
    ctx->r14 = S32(ctx->r25 << 3);
    // 0x80027240: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80027244: andi        $t9, $t8, 0x6
    ctx->r25 = ctx->r24 & 0X6;
    // 0x80027248: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x8002724C: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80027250: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80027254: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x80027258: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x8002725C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80027260: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80027264: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80027268: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002726C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80027270: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80027274: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80027278: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002727C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80027280: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80027284: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80027288: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x8002728C: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80027290: sra         $t6, $t4, 1
    ctx->r14 = S32(SIGNED(ctx->r12) >> 1);
    // 0x80027294: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80027298: addiu       $t8, $t2, 0x8
    ctx->r24 = ADD32(ctx->r10, 0X8);
    // 0x8002729C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800272A0: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800272A4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800272A8: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x800272AC: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x800272B0: sll         $t9, $t4, 4
    ctx->r25 = S32(ctx->r12 << 4);
    // 0x800272B4: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x800272B8: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800272BC: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800272C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800272C4: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800272C8: lw          $t9, -0x25E8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X25E8);
    // 0x800272CC: addiu       $a3, $a3, -0x49D8
    ctx->r7 = ADD32(ctx->r7, -0X49D8);
    // 0x800272D0: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x800272D4: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800272D8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800272DC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800272E0: addiu       $t0, $t0, -0x49D4
    ctx->r8 = ADD32(ctx->r8, -0X49D4);
    // 0x800272E4: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800272E8: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x800272EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800272F0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800272F4: sw          $t6, -0x25E8($at)
    MEM_W(-0X25E8, ctx->r1) = ctx->r14;
L_800272F8:
    // 0x800272F8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800272FC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027300: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80027304: lwc1        $f0, -0x25E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X25E0);
    // 0x80027308: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002730C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80027310: lwc1        $f2, -0x25D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X25D4);
    // 0x80027314: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80027318: addiu       $a3, $a3, -0x49D8
    ctx->r7 = ADD32(ctx->r7, -0X49D8);
    // 0x8002731C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80027320: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80027324: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027328: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002732C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80027330: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027334: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027338: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002733C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80027340: lwc1        $f14, -0x25DC($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X25DC);
    // 0x80027344: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027348: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002734C: mul.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80027350: lwc1        $f16, -0x25D0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X25D0);
    // 0x80027354: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x80027358: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002735C: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80027360: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80027364: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027368: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002736C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027370: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027374: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027378: lbu         $t5, -0x499F($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X499F);
    // 0x8002737C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80027380: lbu         $s0, -0x499E($s0)
    ctx->r16 = MEM_BU(ctx->r16, -0X499E);
    // 0x80027384: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027388: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8002738C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80027390: lbu         $s1, -0x499D($s1)
    ctx->r17 = MEM_BU(ctx->r17, -0X499D);
    // 0x80027394: sh          $t1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r9;
    // 0x80027398: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8002739C: add.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800273A0: addiu       $t0, $t0, -0x49D4
    ctx->r8 = ADD32(ctx->r8, -0X49D4);
    // 0x800273A4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800273A8: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800273AC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800273B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273B8: nop

    // 0x800273BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800273C0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800273C4: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800273C8: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800273CC: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800273D0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800273D4: sb          $t8, -0x1F($v0)
    MEM_B(-0X1F, ctx->r2) = ctx->r24;
    // 0x800273D8: add.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800273DC: sb          $t5, -0x22($v0)
    MEM_B(-0X22, ctx->r2) = ctx->r13;
    // 0x800273E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800273E4: sb          $s0, -0x21($v0)
    MEM_B(-0X21, ctx->r2) = ctx->r16;
    // 0x800273E8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800273EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800273F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800273F4: sh          $t2, -0x24($v0)
    MEM_H(-0X24, ctx->r2) = ctx->r10;
    // 0x800273F8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800273FC: sb          $s1, -0x20($v0)
    MEM_B(-0X20, ctx->r2) = ctx->r17;
    // 0x80027400: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027404: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80027408: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8002740C: sh          $t3, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = ctx->r11;
    // 0x80027410: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80027414: nop

    // 0x80027418: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002741C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027420: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80027424: nop

    // 0x80027428: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002742C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80027430: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80027434: sh          $t7, -0x26($v0)
    MEM_H(-0X26, ctx->r2) = ctx->r15;
    // 0x80027438: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002743C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80027440: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80027444: sb          $t7, -0x15($v0)
    MEM_B(-0X15, ctx->r2) = ctx->r15;
    // 0x80027448: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002744C: sh          $t1, -0x14($v0)
    MEM_H(-0X14, ctx->r2) = ctx->r9;
    // 0x80027450: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80027454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80027458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002745C: sb          $t5, -0x18($v0)
    MEM_B(-0X18, ctx->r2) = ctx->r13;
    // 0x80027460: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80027464: sb          $s0, -0x17($v0)
    MEM_B(-0X17, ctx->r2) = ctx->r16;
    // 0x80027468: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8002746C: sb          $s1, -0x16($v0)
    MEM_B(-0X16, ctx->r2) = ctx->r17;
    // 0x80027470: sh          $t4, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = ctx->r12;
    // 0x80027474: sh          $t9, -0x1C($v0)
    MEM_H(-0X1C, ctx->r2) = ctx->r25;
    // 0x80027478: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002747C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80027480: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80027484: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80027488: sb          $t9, -0xB($v0)
    MEM_B(-0XB, ctx->r2) = ctx->r25;
    // 0x8002748C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80027490: sb          $t5, -0xE($v0)
    MEM_B(-0XE, ctx->r2) = ctx->r13;
    // 0x80027494: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80027498: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002749C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800274A0: sb          $s0, -0xD($v0)
    MEM_B(-0XD, ctx->r2) = ctx->r16;
    // 0x800274A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800274A8: sh          $t2, -0x10($v0)
    MEM_H(-0X10, ctx->r2) = ctx->r10;
    // 0x800274AC: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800274B0: sb          $s1, -0xC($v0)
    MEM_B(-0XC, ctx->r2) = ctx->r17;
    // 0x800274B4: sh          $t3, -0xA($v0)
    MEM_H(-0XA, ctx->r2) = ctx->r11;
    // 0x800274B8: sh          $t6, -0x12($v0)
    MEM_H(-0X12, ctx->r2) = ctx->r14;
    // 0x800274BC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800274C0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800274C4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800274C8: sub.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800274CC: sb          $t5, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r13;
    // 0x800274D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800274D4: sb          $s0, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r16;
    // 0x800274D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800274DC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800274E0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800274E4: sh          $t4, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = ctx->r12;
    // 0x800274E8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800274EC: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
    // 0x800274F0: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800274F4: sb          $s1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r17;
    // 0x800274F8: sh          $t8, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r24;
    // 0x800274FC: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x80027500: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80027504: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x80027508: addiu       $t5, $zero, 0x3E0
    ctx->r13 = ADD32(0, 0X3E0);
    // 0x8002750C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80027510: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80027514: addiu       $t2, $a1, 0x2
    ctx->r10 = ADD32(ctx->r5, 0X2);
    // 0x80027518: addiu       $t3, $a1, 0x1
    ctx->r11 = ADD32(ctx->r5, 0X1);
    // 0x8002751C: addiu       $t9, $a1, 0x3
    ctx->r25 = ADD32(ctx->r5, 0X3);
    // 0x80027520: sb          $t9, 0x11($a0)
    MEM_B(0X11, ctx->r4) = ctx->r25;
    // 0x80027524: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x80027528: sb          $t2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r10;
    // 0x8002752C: sb          $t3, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r11;
    // 0x80027530: sb          $a1, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r5;
    // 0x80027534: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x80027538: sh          $t5, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r13;
    // 0x8002753C: sh          $t5, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r13;
    // 0x80027540: sh          $zero, 0xA($a0)
    MEM_H(0XA, ctx->r4) = 0;
    // 0x80027544: sh          $s0, 0xC($a0)
    MEM_H(0XC, ctx->r4) = ctx->r16;
    // 0x80027548: sh          $zero, 0xE($a0)
    MEM_H(0XE, ctx->r4) = 0;
    // 0x8002754C: sb          $t4, 0x10($a0)
    MEM_B(0X10, ctx->r4) = ctx->r12;
    // 0x80027550: sb          $t3, 0x12($a0)
    MEM_B(0X12, ctx->r4) = ctx->r11;
    // 0x80027554: sb          $t2, 0x13($a0)
    MEM_B(0X13, ctx->r4) = ctx->r10;
    // 0x80027558: sh          $s0, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r16;
    // 0x8002755C: sh          $t5, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r13;
    // 0x80027560: sh          $t5, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r13;
    // 0x80027564: sh          $t5, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r13;
    // 0x80027568: sh          $s0, 0x1C($a0)
    MEM_H(0X1C, ctx->r4) = ctx->r16;
    // 0x8002756C: sh          $zero, 0x1E($a0)
    MEM_H(0X1E, ctx->r4) = 0;
    // 0x80027570: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80027574: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x80027578: lh          $t6, 0x0($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X0);
    // 0x8002757C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80027580: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80027584: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80027588: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
    // 0x8002758C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80027590: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80027594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027598:
    // 0x80027598: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8002759C: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x800275A0: jr          $ra
    // 0x800275A4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800275A4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void sound_pitch_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800020BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800020C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800020C4: beq         $a0, $zero, L_800020D8
    if (ctx->r4 == 0) {
        // 0x800020C8: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800020D8;
    }
    // 0x800020C8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800020CC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800020D0: jal         0x800049F8
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_0;
    // 0x800020D4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_0:
L_800020D8:
    // 0x800020D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800020DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800020E0: jr          $ra
    // 0x800020E4: nop

    return;
    // 0x800020E4: nop

;}
RECOMP_FUNC void strcasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4CF4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4CF8: nop

    // 0x800B4CFC: bne         $v0, $zero, L_800B4D14
    if (ctx->r2 != 0) {
        // 0x800B4D00: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D14;
    }
    // 0x800B4D00: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
    // 0x800B4D04: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D08: nop

    // 0x800B4D0C: beq         $t6, $zero, L_800B4D9C
    if (ctx->r14 == 0) {
        // 0x800B4D10: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D9C;
    }
L_800B4D10:
    // 0x800B4D10: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D14:
    // 0x800B4D14: slti        $at, $a2, 0x61
    ctx->r1 = SIGNED(ctx->r6) < 0X61 ? 1 : 0;
    // 0x800B4D18: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D1C: bne         $at, $zero, L_800B4D34
    if (ctx->r1 != 0) {
        // 0x800B4D20: or          $a3, $a2, $zero
        ctx->r7 = ctx->r6 | 0;
            goto L_800B4D34;
    }
    // 0x800B4D20: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800B4D24: slti        $at, $a2, 0x7B
    ctx->r1 = SIGNED(ctx->r6) < 0X7B ? 1 : 0;
    // 0x800B4D28: beq         $at, $zero, L_800B4D34
    if (ctx->r1 == 0) {
        // 0x800B4D2C: addiu       $a2, $a2, -0x20
        ctx->r6 = ADD32(ctx->r6, -0X20);
            goto L_800B4D34;
    }
    // 0x800B4D2C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x800B4D30: andi        $a3, $a2, 0xFF
    ctx->r7 = ctx->r6 & 0XFF;
L_800B4D34:
    // 0x800B4D34: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B4D38: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B4D3C: bne         $at, $zero, L_800B4D54
    if (ctx->r1 != 0) {
        // 0x800B4D40: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800B4D54;
    }
    // 0x800B4D40: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800B4D44: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B4D48: beq         $at, $zero, L_800B4D54
    if (ctx->r1 == 0) {
        // 0x800B4D4C: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B4D54;
    }
    // 0x800B4D4C: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B4D50: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D54:
    // 0x800B4D54: slt         $at, $a3, $a2
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800B4D58: beq         $at, $zero, L_800B4D6C
    if (ctx->r1 == 0) {
        // 0x800B4D5C: slt         $at, $a2, $a3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_800B4D6C;
    }
    // 0x800B4D5C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B4D60: jr          $ra
    // 0x800B4D64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B4D64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800B4D68: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
L_800B4D6C:
    // 0x800B4D6C: beq         $at, $zero, L_800B4D7C
    if (ctx->r1 == 0) {
        // 0x800B4D70: nop
    
            goto L_800B4D7C;
    }
    // 0x800B4D70: nop

    // 0x800B4D74: jr          $ra
    // 0x800B4D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B4D78: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4D7C:
    // 0x800B4D7C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x800B4D80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4D84: bne         $v0, $zero, L_800B4D10
    if (ctx->r2 != 0) {
        // 0x800B4D88: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800B4D10;
    }
    // 0x800B4D88: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4D8C: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4D90: nop

    // 0x800B4D94: bne         $t9, $zero, L_800B4D14
    if (ctx->r25 != 0) {
        // 0x800B4D98: andi        $a2, $v0, 0xFF
        ctx->r6 = ctx->r2 & 0XFF;
            goto L_800B4D14;
    }
    // 0x800B4D98: andi        $a2, $v0, 0xFF
    ctx->r6 = ctx->r2 & 0XFF;
L_800B4D9C:
    // 0x800B4D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4DA0: jr          $ra
    // 0x800B4DA4: nop

    return;
    // 0x800B4DA4: nop

;}
RECOMP_FUNC void soundoptions_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80085634: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80085638: lw          $a0, 0x6FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6FBC);
    // 0x8008563C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80085640: beq         $a0, $zero, L_80085650
    if (ctx->r4 == 0) {
        // 0x80085644: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80085650;
    }
    // 0x80085644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80085648: jal         0x8000488C
    // 0x8008564C: nop

    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8008564C: nop

    after_0:
L_80085650:
    // 0x80085650: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80085654: lw          $t6, 0x6978($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6978);
    // 0x80085658: nop

    // 0x8008565C: bltz        $t6, L_80085684
    if (SIGNED(ctx->r14) < 0) {
        // 0x80085660: nop
    
            goto L_80085684;
    }
    // 0x80085660: nop

    // 0x80085664: jal         0x80000BE0
    // 0x80085668: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80085668: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_1:
    // 0x8008566C: jal         0x80000B34
    // 0x80085670: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_2;
    // 0x80085670: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_2:
    // 0x80085674: jal         0x80000C98
    // 0x80085678: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_3;
    // 0x80085678: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_3:
    // 0x8008567C: jal         0x80000B18
    // 0x80085680: nop

    music_change_off(rdram, ctx);
        goto after_4;
    // 0x80085680: nop

    after_4:
L_80085684:
    // 0x80085684: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80085688: jal         0x8009C9EC
    // 0x8008568C: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    menu_assetgroup_free(rdram, ctx);
        goto after_5;
    // 0x8008568C: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    after_5:
    // 0x80085690: jal         0x800C478C
    // 0x80085694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_6;
    // 0x80085694: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x80085698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008569C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800856A0: jr          $ra
    // 0x800856A4: nop

    return;
    // 0x800856A4: nop

;}
RECOMP_FUNC void transition_update_fullscreen(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0D54: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0D58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C0D5C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800C0D60: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800C0D64: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C0D68: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C0D6C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C0D70: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C0D74: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C0D78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C0D7C: addiu       $a1, $a1, 0x3740
    ctx->r5 = ADD32(ctx->r5, 0X3740);
    // 0x800C0D80: addiu       $a2, $a2, -0x52F0
    ctx->r6 = ADD32(ctx->r6, -0X52F0);
    // 0x800C0D84: addiu       $a3, $a3, -0x5309
    ctx->r7 = ADD32(ctx->r7, -0X5309);
    // 0x800C0D88: addiu       $t1, $t1, 0x3744
    ctx->r9 = ADD32(ctx->r9, 0X3744);
    // 0x800C0D8C: addiu       $t2, $t2, 0x3738
    ctx->r10 = ADD32(ctx->r10, 0X3738);
    // 0x800C0D90: addiu       $t3, $t3, 0x3748
    ctx->r11 = ADD32(ctx->r11, 0X3748);
    // 0x800C0D94: addiu       $t4, $t4, -0x52EC
    ctx->r12 = ADD32(ctx->r12, -0X52EC);
    // 0x800C0D98: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
L_800C0D9C:
    // 0x800C0D9C: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C0DA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C0DA4: blez        $v1, L_800C0EC4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C0DA8: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C0EC4;
    }
    // 0x800C0DA8: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C0DAC: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C0DB0: beq         $at, $zero, L_800C0DDC
    if (ctx->r1 == 0) {
        // 0x800C0DB4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800C0DDC;
    }
    // 0x800C0DB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0DB8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800C0DBC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0DC0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C0DC4: subu        $t6, $v1, $a0
    ctx->r14 = SUB32(ctx->r3, ctx->r4);
    // 0x800C0DC8: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800C0DCC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800C0DD0: add.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800C0DD4: b           L_800C0DFC
    // 0x800C0DD8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
        goto L_800C0DFC;
    // 0x800C0DD8: swc1        $f16, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f16.u32l;
L_800C0DDC:
    // 0x800C0DDC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C0DE0: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C0DE4: bc1f        L_800C0DF4
    if (!c1cs) {
        // 0x800C0DE8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C0DF4;
    }
    // 0x800C0DE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0DEC: b           L_800C0DF8
    // 0x800C0DF0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
        goto L_800C0DF8;
    // 0x800C0DF0: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
L_800C0DF4:
    // 0x800C0DF4: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
L_800C0DF8:
    // 0x800C0DF8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C0DFC:
    // 0x800C0DFC: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E00: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800C0E04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C0E08: nop

    // 0x800C0E0C: bc1f        L_800C0E24
    if (!c1cs) {
        // 0x800C0E10: nop
    
            goto L_800C0E24;
    }
    // 0x800C0E10: nop

    // 0x800C0E14: swc1        $f2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f2.u32l;
    // 0x800C0E18: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E1C: b           L_800C0E44
    // 0x800C0E20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
        goto L_800C0E44;
    // 0x800C0E20: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0E24:
    // 0x800C0E24: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x800C0E28: nop

    // 0x800C0E2C: bc1f        L_800C0E40
    if (!c1cs) {
        // 0x800C0E30: nop
    
            goto L_800C0E40;
    }
    // 0x800C0E30: nop

    // 0x800C0E34: swc1        $f12, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f12.u32l;
    // 0x800C0E38: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C0E3C: nop

L_800C0E40:
    // 0x800C0E40: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
L_800C0E44:
    // 0x800C0E44: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0E48: nop

    // 0x800C0E4C: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800C0E50: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0E54: nop

    // 0x800C0E58: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0E5C: beq         $t8, $zero, L_800C0EA8
    if (ctx->r24 == 0) {
        // 0x800C0E60: nop
    
            goto L_800C0EA8;
    }
    // 0x800C0E60: nop

    // 0x800C0E64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0E68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C0E6C: sub.s       $f18, $f0, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800C0E70: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C0E74: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800C0E78: nop

    // 0x800C0E7C: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800C0E80: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800C0E84: nop

    // 0x800C0E88: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800C0E8C: bne         $t8, $zero, L_800C0EA0
    if (ctx->r24 != 0) {
        // 0x800C0E90: nop
    
            goto L_800C0EA0;
    }
    // 0x800C0E90: nop

    // 0x800C0E94: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C0E98: b           L_800C0EB8
    // 0x800C0E9C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800C0EB8;
    // 0x800C0E9C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800C0EA0:
    // 0x800C0EA0: b           L_800C0EB8
    // 0x800C0EA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800C0EB8;
    // 0x800C0EA4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
L_800C0EA8:
    // 0x800C0EA8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800C0EAC: nop

    // 0x800C0EB0: bltz        $t8, L_800C0EA0
    if (SIGNED(ctx->r24) < 0) {
        // 0x800C0EB4: nop
    
            goto L_800C0EA0;
    }
    // 0x800C0EB4: nop

L_800C0EB8:
    // 0x800C0EB8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800C0EBC: b           L_800C0F10
    // 0x800C0EC0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
        goto L_800C0F10;
    // 0x800C0EC0: sb          $t8, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r24;
L_800C0EC4:
    // 0x800C0EC4: lhu         $v1, 0x0($t1)
    ctx->r3 = MEM_HU(ctx->r9, 0X0);
    // 0x800C0EC8: nop

    // 0x800C0ECC: beq         $t0, $v1, L_800C0F10
    if (ctx->r8 == ctx->r3) {
        // 0x800C0ED0: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800C0F10;
    }
    // 0x800C0ED0: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C0ED4: beq         $at, $zero, L_800C0EE4
    if (ctx->r1 == 0) {
        // 0x800C0ED8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C0EE4;
    }
    // 0x800C0ED8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C0EDC: b           L_800C0F10
    // 0x800C0EE0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
        goto L_800C0F10;
    // 0x800C0EE0: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
L_800C0EE4:
    // 0x800C0EE4: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800C0EE8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C0EEC: beq         $t5, $zero, L_800C0F10
    if (ctx->r13 == 0) {
        // 0x800C0EF0: sh          $zero, 0x0($t1)
        MEM_H(0X0, ctx->r9) = 0;
            goto L_800C0F10;
    }
    // 0x800C0EF0: sh          $zero, 0x0($t1)
    MEM_H(0X0, ctx->r9) = 0;
    // 0x800C0EF4: lwc1        $f6, 0x0($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800C0EF8: lhu         $t6, 0x0($t3)
    ctx->r14 = MEM_HU(ctx->r11, 0X0);
    // 0x800C0EFC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800C0F00: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800C0F04: swc1        $f8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f8.u32l;
    // 0x800C0F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C0F0C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
L_800C0F10:
    // 0x800C0F10: bne         $v0, $zero, L_800C0F20
    if (ctx->r2 != 0) {
        // 0x800C0F14: nop
    
            goto L_800C0F20;
    }
    // 0x800C0F14: nop

    // 0x800C0F18: bgtz        $a0, L_800C0D9C
    if (SIGNED(ctx->r4) > 0) {
        // 0x800C0F1C: nop
    
            goto L_800C0D9C;
    }
    // 0x800C0F1C: nop

L_800C0F20:
    // 0x800C0F20: jr          $ra
    // 0x800C0F24: nop

    return;
    // 0x800C0F24: nop

;}
RECOMP_FUNC void sndp_get_state(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000461C: beq         $a0, $zero, L_80004630
    if (ctx->r4 == 0) {
        // 0x80004620: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004630;
    }
    // 0x80004620: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80004624: lbu         $v0, 0x3F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3F);
    // 0x80004628: jr          $ra
    // 0x8000462C: nop

    return;
    // 0x8000462C: nop

L_80004630:
    // 0x80004630: jr          $ra
    // 0x80004634: nop

    return;
    // 0x80004634: nop

;}
RECOMP_FUNC void lerp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800228BC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800228C0: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x800228C4: lwc1        $f12, 0x4($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800228C8: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800228CC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800228D0: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800228D4: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800228D8: add.s       $f2, $f8, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800228DC: jr          $ra
    // 0x800228E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800228E0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void music_is_playing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800015C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800015CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800015D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800015D4: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x800015D8: jal         0x800C7FB0
    // 0x800015DC: nop

    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x800015DC: nop

    after_0:
    // 0x800015E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800015E4: xori        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 ^ 0X1;
    // 0x800015E8: sltiu       $t6, $t6, 0x1
    ctx->r14 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800015EC: andi        $v0, $t6, 0xFF
    ctx->r2 = ctx->r14 & 0XFF;
    // 0x800015F0: jr          $ra
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800015F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void find_taj_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018CA0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80018CA4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80018CA8: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x80018CAC: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x80018CB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80018CB4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018CB8: beq         $at, $zero, L_80018D08
    if (ctx->r1 == 0) {
        // 0x80018CBC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80018D08;
    }
    // 0x80018CBC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80018CC0: lw          $t6, -0x4C28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4C28);
    // 0x80018CC4: addiu       $a2, $zero, 0x3E
    ctx->r6 = ADD32(0, 0X3E);
    // 0x80018CC8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
L_80018CCC:
    // 0x80018CCC: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x80018CD0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80018CD4: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x80018CD8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018CDC: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80018CE0: bne         $t9, $zero, L_80018D00
    if (ctx->r25 != 0) {
        // 0x80018CE4: nop
    
            goto L_80018D00;
    }
    // 0x80018CE4: nop

    // 0x80018CE8: lh          $t0, 0x48($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X48);
    // 0x80018CEC: nop

    // 0x80018CF0: bne         $a2, $t0, L_80018D00
    if (ctx->r6 != ctx->r8) {
        // 0x80018CF4: nop
    
            goto L_80018D00;
    }
    // 0x80018CF4: nop

    // 0x80018CF8: jr          $ra
    // 0x80018CFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80018CFC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80018D00:
    // 0x80018D00: bne         $at, $zero, L_80018CCC
    if (ctx->r1 != 0) {
        // 0x80018D04: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80018CCC;
    }
    // 0x80018D04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80018D08:
    // 0x80018D08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80018D0C: jr          $ra
    // 0x80018D10: nop

    return;
    // 0x80018D10: nop

;}
RECOMP_FUNC void music_jingle_play_safe(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001784: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000178C: jal         0x80001C08
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    music_jingle_playing(rdram, ctx);
        goto after_0;
    // 0x80001790: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80001794: bne         $v0, $zero, L_800017C4
    if (ctx->r2 != 0) {
        // 0x80001798: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_800017C4;
    }
    // 0x80001798: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000179C: lbu         $t6, 0x1B($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X1B);
    // 0x800017A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800017A4: addiu       $v0, $v0, 0x6285
    ctx->r2 = ADD32(ctx->r2, 0X6285);
    // 0x800017A8: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800017AC: lw          $a1, -0x345C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X345C);
    // 0x800017B0: jal         0x800022BC
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    music_sequence_start(rdram, ctx);
        goto after_1;
    // 0x800017B4: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    after_1:
    // 0x800017B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800017BC: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800017C0: sb          $t7, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = ctx->r15;
L_800017C4:
    // 0x800017C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800017C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800017CC: jr          $ra
    // 0x800017D0: nop

    return;
    // 0x800017D0: nop

;}
