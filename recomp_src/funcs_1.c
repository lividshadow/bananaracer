#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void get_collision_normal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AD14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD18: lwc1        $f4, -0x499C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X499C);
    // 0x8002AD1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD20: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8002AD24: lwc1        $f6, -0x4998($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4998);
    // 0x8002AD28: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002AD2C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x8002AD30: lwc1        $f8, -0x4994($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X4994);
    // 0x8002AD34: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002AD38: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    // 0x8002AD3C: lw          $v0, -0x4990($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4990);
    // 0x8002AD40: jr          $ra
    // 0x8002AD44: nop

    return;
    // 0x8002AD44: nop

;}
RECOMP_FUNC void alCSeqTicksToSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C88E0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800C88E4: mtc1        $a2, $f8
    ctx->f8.u32l = ctx->r6;
    // 0x800C88E8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C88EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C88F0: bgez        $a2, L_800C8904
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C88F4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C8904;
    }
    // 0x800C88F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C88F8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C88FC: nop

    // 0x800C8900: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C8904:
    // 0x800C8904: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C8908: mul.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C890C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C8910: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x800C8914: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800C8918: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800C891C: bgez        $t7, L_800C8930
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800C8920: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C8930;
    }
    // 0x800C8920: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C8924: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C8928: nop

    // 0x800C892C: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800C8930:
    // 0x800C8930: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C8934: ldc1        $f18, -0x65C8($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X65C8);
    // 0x800C8938: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800C893C: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x800C8940: div.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f8.d);
    // 0x800C8944: jr          $ra
    // 0x800C8948: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    return;
    // 0x800C8948: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
;}
RECOMP_FUNC void set_dialogue_box_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5BAC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5BB0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5BB4: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5BB8: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5BBC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5BC0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5BC4: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5BC8: nop

    // 0x800C5BCC: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x800C5BD0: jr          $ra
    // 0x800C5BD4: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5BD4: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void mtxf_mul(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F9A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8006F9AC: sdc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    SD(ctx->f2.u64, 0X0, ctx->r29);
    // 0x8006F9B0: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F9B4:
    // 0x8006F9B4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F9B8: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006F9BC: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F9C0: lwc1        $f12, 0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8006F9C4: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006F9C8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F9CC: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x8006F9D0: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F9D4: lwc1        $f8, 0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F9D8: lwc1        $f16, 0x30($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X30);
    // 0x8006F9DC: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006F9E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F9E4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x8006F9E8: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006F9EC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F9F0: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006F9F4: lwc1        $f12, 0x14($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8006F9F8: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006F9FC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006FA00: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA04: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA08: lwc1        $f14, 0x24($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X24);
    // 0x8006FA0C: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA10: lwc1        $f16, 0x34($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X34);
    // 0x8006FA14: swc1        $f18, -0x10($a2)
    MEM_W(-0X10, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA18: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA1C: nop

    // 0x8006FA20: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA24: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA28: lwc1        $f12, 0x18($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8006FA2C: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA30: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006FA34: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA38: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA3C: lwc1        $f14, 0x28($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X28);
    // 0x8006FA40: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA44: lwc1        $f16, 0x38($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X38);
    // 0x8006FA48: swc1        $f18, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA4C: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA50: nop

    // 0x8006FA54: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA58: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA5C: lwc1        $f12, 0x1C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x8006FA60: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA64: lwc1        $f10, 0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006FA68: mul.s       $f10, $f2, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006FA6C: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA70: lwc1        $f14, 0x2C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8006FA74: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006FA78: lwc1        $f16, 0x3C($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X3C);
    // 0x8006FA7C: swc1        $f18, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA80: mul.s       $f14, $f6, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8006FA84: nop

    // 0x8006FA88: mul.s       $f16, $f8, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8006FA8C: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8006FA90: add.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006FA94: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8006FA98: swc1        $f18, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->f18.u32l;
    // 0x8006FA9C: bnel        $t0, $zero, L_8006F9B4
    if (ctx->r8 != 0) {
        // 0x8006FAA0: nop
    
            goto L_8006F9B4;
    }
    goto skip_0;
    // 0x8006FAA0: nop

    skip_0:
    // 0x8006FAA4: ldc1        $f2, 0x0($sp)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r29, 0X0);
    // 0x8006FAA8: jr          $ra
    // 0x8006FAAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8006FAAC: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void music_jingle_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001B0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001B14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001B18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001B1C: jal         0x8000317C
    // 0x80001B20: sb          $a0, -0x3454($at)
    MEM_B(-0X3454, ctx->r1) = ctx->r4;
    sndp_get_global_volume(rdram, ctx);
        goto after_0;
    // 0x80001B20: sb          $a0, -0x3454($at)
    MEM_B(-0X3454, ctx->r1) = ctx->r4;
    after_0:
    // 0x80001B24: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80001B28: lbu         $t7, -0x3454($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X3454);
    // 0x80001B2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001B30: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001B34: lw          $a0, -0x345C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X345C);
    // 0x80001B38: mflo        $a1
    ctx->r5 = lo;
    // 0x80001B3C: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80001B40: jal         0x800C7DB0
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    alCSPSetVol(rdram, ctx);
        goto after_1;
    // 0x80001B44: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80001B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001B4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001B50: jr          $ra
    // 0x80001B54: nop

    return;
    // 0x80001B54: nop

;}
RECOMP_FUNC void leveltable_vehicle_default(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B2EC: blez        $a0, L_8006B32C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006B2F0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8006B32C;
    }
    // 0x8006B2F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006B2F4: lw          $t6, 0x16F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16F0);
    // 0x8006B2F8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006B2FC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006B300: beq         $at, $zero, L_8006B32C
    if (ctx->r1 == 0) {
        // 0x8006B304: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006B32C;
    }
    // 0x8006B304: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006B308: lw          $t7, 0x16FC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X16FC);
    // 0x8006B30C: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8006B310: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8006B314: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8006B318: lb          $v0, 0x2($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X2);
    // 0x8006B31C: nop

    // 0x8006B320: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x8006B324: jr          $ra
    // 0x8006B328: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x8006B328: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8006B32C:
    // 0x8006B32C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006B330: jr          $ra
    // 0x8006B334: nop

    return;
    // 0x8006B334: nop

;}
RECOMP_FUNC void obj_init_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D42C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8003D430: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8003D434: jr          $ra
    // 0x8003D438: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
    return;
    // 0x8003D438: sh          $t6, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void timetrial_ghost_read(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059E90: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059E94: lb          $a1, -0x24E4($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X24E4);
    // 0x80059E98: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80059E9C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80059EA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80059EA4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80059EA8: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80059EAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80059EB0: jal         0x8001B3E0
    // 0x80059EB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    timetrial_staff_ghost_check(rdram, ctx);
        goto after_0;
    // 0x80059EB4: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80059EB8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059EBC: beq         $v0, $zero, L_80059EC8
    if (ctx->r2 == 0) {
        // 0x80059EC0: lui         $at, 0x41F0
        ctx->r1 = S32(0X41F0 << 16);
            goto L_80059EC8;
    }
    // 0x80059EC0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80059EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_80059EC8:
    // 0x80059EC8: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80059ECC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x80059ED0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80059ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80059ED8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80059EDC: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x80059EE0: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059EE4: bne         $t8, $zero, L_80059F20
    if (ctx->r24 != 0) {
        // 0x80059EE8: div.s       $f2, $f0, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
            goto L_80059F20;
    }
    // 0x80059EE8: div.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80059EEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059EF0: bne         $a1, $at, L_80059F20
    if (ctx->r5 != ctx->r1) {
        // 0x80059EF4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80059F20;
    }
    // 0x80059EF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80059EF8: lwc1        $f11, 0x6EC0($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6EC0);
    // 0x80059EFC: lwc1        $f10, 0x6EC4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6EC4);
    // 0x80059F00: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80059F04: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059F08: lui         $at, 0x403E
    ctx->r1 = S32(0X403E << 16);
    // 0x80059F0C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80059F10: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80059F14: nop

    // 0x80059F18: div.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = DIV_D(ctx->f16.d, ctx->f18.d);
    // 0x80059F1C: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80059F20:
    // 0x80059F20: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059F24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059F28: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059F2C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059F30: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059F34: addu        $t5, $t5, $t6
    ctx->r13 = ADD32(ctx->r13, ctx->r14);
    // 0x80059F38: cvt.w.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80059F3C: lh          $t5, -0x24E0($t5)
    ctx->r13 = MEM_H(ctx->r13, -0X24E0);
    // 0x80059F40: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x80059F44: addiu       $t7, $t5, -0x2
    ctx->r15 = ADD32(ctx->r13, -0X2);
    // 0x80059F48: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059F4C: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80059F50: bne         $at, $zero, L_80059F7C
    if (ctx->r1 != 0) {
        // 0x80059F54: sw          $v1, 0x60($sp)
        MEM_W(0X60, ctx->r29) = ctx->r3;
            goto L_80059F7C;
    }
    // 0x80059F54: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x80059F58: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x80059F5C: nop

    // 0x80059F60: lbu         $v1, 0x1F7($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1F7);
    // 0x80059F64: nop

    // 0x80059F68: blez        $v1, L_80059F74
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80059F6C: addiu       $t8, $v1, -0x1
        ctx->r24 = ADD32(ctx->r3, -0X1);
            goto L_80059F74;
    }
    // 0x80059F6C: addiu       $t8, $v1, -0x1
    ctx->r24 = ADD32(ctx->r3, -0X1);
    // 0x80059F70: sb          $t8, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = ctx->r24;
L_80059F74:
    // 0x80059F74: b           L_8005A40C
    // 0x80059F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A40C;
    // 0x80059F78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80059F7C:
    // 0x80059F7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80059F80: beq         $a1, $at, L_80059FC8
    if (ctx->r5 == ctx->r1) {
        // 0x80059F84: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059FC8;
    }
    // 0x80059F84: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059F88: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80059F8C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x80059F90: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    // 0x80059F94: jal         0x8006BFC8
    // 0x80059F98: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    level_id(rdram, ctx);
        goto after_1;
    // 0x80059F98: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x80059F9C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80059FA0: lh          $t9, -0x24D4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X24D4);
    // 0x80059FA4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80059FA8: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x80059FAC: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80059FB0: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80059FB4: beq         $v0, $t9, L_80059FC8
    if (ctx->r2 == ctx->r25) {
        // 0x80059FB8: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_80059FC8;
    }
    // 0x80059FB8: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80059FBC: b           L_8005A40C
    // 0x80059FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005A40C;
    // 0x80059FC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80059FC4: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_80059FC8:
    // 0x80059FC8: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80059FCC: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80059FD0: addu        $ra, $ra, $t6
    ctx->r31 = ADD32(ctx->r31, ctx->r14);
    // 0x80059FD4: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80059FD8: lw          $ra, -0x24F0($ra)
    ctx->r31 = MEM_W(ctx->r31, -0X24F0);
    // 0x80059FDC: subu        $t7, $t7, $t1
    ctx->r15 = SUB32(ctx->r15, ctx->r9);
    // 0x80059FE0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80059FE4: addiu       $a3, $sp, 0x84
    ctx->r7 = ADD32(ctx->r29, 0X84);
    // 0x80059FE8: addiu       $t0, $sp, 0x74
    ctx->r8 = ADD32(ctx->r29, 0X74);
    // 0x80059FEC: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80059FF0: addiu       $t4, $sp, 0x74
    ctx->r12 = ADD32(ctx->r29, 0X74);
    // 0x80059FF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80059FF8: addu        $t2, $ra, $t7
    ctx->r10 = ADD32(ctx->r31, ctx->r15);
L_80059FFC:
    // 0x80059FFC: bne         $t1, $t3, L_8005A068
    if (ctx->r9 != ctx->r11) {
        // 0x8005A000: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8005A068;
    }
    // 0x8005A000: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8005A004: lh          $v1, 0xC($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XC);
    // 0x8005A008: lh          $t9, 0x18($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X18);
    // 0x8005A00C: addu        $t8, $v1, $v1
    ctx->r24 = ADD32(ctx->r3, ctx->r3);
    // 0x8005A010: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A014: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005A018: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8005A01C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A020: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A024: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8005A028: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x8005A02C: addu        $t7, $a0, $a0
    ctx->r15 = ADD32(ctx->r4, ctx->r4);
    // 0x8005A030: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A034: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8005A038: nop

    // 0x8005A03C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A040: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A044: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8005A048: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x8005A04C: addu        $t6, $a1, $a1
    ctx->r14 = ADD32(ctx->r5, ctx->r5);
    // 0x8005A050: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8005A054: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005A058: nop

    // 0x8005A05C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A060: b           L_8005A120
    // 0x8005A064: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A120;
    // 0x8005A064: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A068:
    // 0x8005A068: slt         $at, $t1, $t5
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8005A06C: bne         $at, $zero, L_8005A0D8
    if (ctx->r1 != 0) {
        // 0x8005A070: nop
    
            goto L_8005A0D8;
    }
    // 0x8005A070: nop

    // 0x8005A074: lh          $v1, 0x0($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X0);
    // 0x8005A078: lh          $t6, -0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, -0XC);
    // 0x8005A07C: addu        $t9, $v1, $v1
    ctx->r25 = ADD32(ctx->r3, ctx->r3);
    // 0x8005A080: subu        $t7, $t9, $t6
    ctx->r15 = SUB32(ctx->r25, ctx->r14);
    // 0x8005A084: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8005A088: nop

    // 0x8005A08C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A090: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A094: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8005A098: lh          $t9, -0xA($v0)
    ctx->r25 = MEM_H(ctx->r2, -0XA);
    // 0x8005A09C: addu        $t8, $a0, $a0
    ctx->r24 = ADD32(ctx->r4, ctx->r4);
    // 0x8005A0A0: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x8005A0A4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8005A0A8: nop

    // 0x8005A0AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A0B0: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A0B4: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8005A0B8: lh          $t8, -0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, -0X8);
    // 0x8005A0BC: addu        $t7, $a1, $a1
    ctx->r15 = ADD32(ctx->r5, ctx->r5);
    // 0x8005A0C0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A0C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8005A0C8: nop

    // 0x8005A0CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A0D0: b           L_8005A120
    // 0x8005A0D4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
        goto L_8005A120;
    // 0x8005A0D4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A0D8:
    // 0x8005A0D8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8005A0DC: nop

    // 0x8005A0E0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8005A0E4: nop

    // 0x8005A0E8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A0EC: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x8005A0F0: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8005A0F4: nop

    // 0x8005A0F8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8005A0FC: nop

    // 0x8005A100: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A104: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x8005A108: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8005A10C: nop

    // 0x8005A110: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8005A114: nop

    // 0x8005A118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A11C: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
L_8005A120:
    // 0x8005A120: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005A124: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8005A128: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8005A12C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005A130: bne         $a2, $t4, L_80059FFC
    if (ctx->r6 != ctx->r12) {
        // 0x8005A134: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_80059FFC;
    }
    // 0x8005A134: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8005A138: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x8005A13C: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8005A140: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8005A144: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8005A148: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A14C: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8005A150: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8005A154: sub.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x8005A158: addu        $v0, $ra, $t6
    ctx->r2 = ADD32(ctx->r31, ctx->r14);
    // 0x8005A15C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A160: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8005A164: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A168: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005A16C: jal         0x80022574
    // 0x8005A170: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    catmull_rom_interpolation(rdram, ctx);
        goto after_2;
    // 0x8005A170: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8005A174: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A178: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8005A17C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A180: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x8005A184: jal         0x80022574
    // 0x8005A188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_3;
    // 0x8005A188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8005A18C: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A190: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8005A194: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8005A198: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8005A19C: jal         0x80022574
    // 0x8005A1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    catmull_rom_interpolation(rdram, ctx);
        goto after_4;
    // 0x8005A1A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8005A1A4: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
    // 0x8005A1A8: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A1AC: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A1B0: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8005A1B4: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x8005A1B8: addiu       $a2, $v0, 0xC
    ctx->r6 = ADD32(ctx->r2, 0XC);
    // 0x8005A1BC: lh          $t7, 0xA($a2)
    ctx->r15 = MEM_H(ctx->r6, 0XA);
    // 0x8005A1C0: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x8005A1C4: ori         $a3, $zero, 0x8001
    ctx->r7 = 0 | 0X8001;
    // 0x8005A1C8: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8005A1CC: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A1D0: bne         $at, $zero, L_8005A1E0
    if (ctx->r1 != 0) {
        // 0x8005A1D4: lui         $t0, 0xFFFF
        ctx->r8 = S32(0XFFFF << 16);
            goto L_8005A1E0;
    }
    // 0x8005A1D4: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A1D8: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A1DC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
L_8005A1E0:
    // 0x8005A1E0: lui         $t0, 0xFFFF
    ctx->r8 = S32(0XFFFF << 16);
    // 0x8005A1E4: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A1E8: beq         $at, $zero, L_8005A1F8
    if (ctx->r1 == 0) {
        // 0x8005A1EC: ori         $t0, $t0, 0x1
        ctx->r8 = ctx->r8 | 0X1;
            goto L_8005A1F8;
    }
    // 0x8005A1EC: ori         $t0, $t0, 0x1
    ctx->r8 = ctx->r8 | 0X1;
    // 0x8005A1F0: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A1F4: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A1F8:
    // 0x8005A1F8: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x8005A1FC: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x8005A200: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8005A204: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8005A208: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005A20C: nop

    // 0x8005A210: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005A214: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A218: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A21C: nop

    // 0x8005A220: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8005A224: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8005A228: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005A22C: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8005A230: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
    // 0x8005A234: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x8005A238: lh          $t9, 0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X8);
    // 0x8005A23C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x8005A240: subu        $v1, $t9, $t7
    ctx->r3 = SUB32(ctx->r25, ctx->r15);
    // 0x8005A244: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A248: bne         $at, $zero, L_8005A258
    if (ctx->r1 != 0) {
        // 0x8005A24C: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A258;
    }
    // 0x8005A24C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A250: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A254: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A258:
    // 0x8005A258: beq         $at, $zero, L_8005A264
    if (ctx->r1 == 0) {
        // 0x8005A25C: nop
    
            goto L_8005A264;
    }
    // 0x8005A25C: nop

    // 0x8005A260: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A264:
    // 0x8005A264: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x8005A268: nop

    // 0x8005A26C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8005A270: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8005A274: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8005A278: nop

    // 0x8005A27C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8005A280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A288: nop

    // 0x8005A28C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8005A290: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8005A294: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8005A298: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x8005A29C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8005A2A0: lh          $a0, 0x6($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X6);
    // 0x8005A2A4: lh          $t6, 0x6($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X6);
    // 0x8005A2A8: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8005A2AC: subu        $v1, $t6, $t9
    ctx->r3 = SUB32(ctx->r14, ctx->r25);
    // 0x8005A2B0: slt         $at, $v1, $a3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8005A2B4: bne         $at, $zero, L_8005A2C4
    if (ctx->r1 != 0) {
        // 0x8005A2B8: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_8005A2C4;
    }
    // 0x8005A2B8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A2BC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x8005A2C0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_8005A2C4:
    // 0x8005A2C4: beq         $at, $zero, L_8005A2D0
    if (ctx->r1 == 0) {
        // 0x8005A2C8: nop
    
            goto L_8005A2D0;
    }
    // 0x8005A2C8: nop

    // 0x8005A2CC: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
L_8005A2D0:
    // 0x8005A2D0: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x8005A2D4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005A2D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005A2DC: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8005A2E0: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8005A2E4: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005A2E8: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
    // 0x8005A2EC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A2F0: nop

    // 0x8005A2F4: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8005A2F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005A2FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005A300: nop

    // 0x8005A304: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8005A308: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8005A30C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A310: addu        $t7, $a0, $t9
    ctx->r15 = ADD32(ctx->r4, ctx->r25);
    // 0x8005A314: sh          $t7, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r15;
    // 0x8005A318: swc1        $f2, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f2.u32l;
    // 0x8005A31C: jal         0x80029F58
    // 0x8005A320: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x8005A320: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_5:
    // 0x8005A324: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8005A328: lwc1        $f2, 0x94($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8005A32C: sh          $v0, 0x2E($s0)
    MEM_H(0X2E, ctx->r16) = ctx->r2;
    // 0x8005A330: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x8005A334: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A338: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x8005A33C: bne         $t5, $t6, L_8005A40C
    if (ctx->r13 != ctx->r14) {
        // 0x8005A340: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8005A40C;
    }
    // 0x8005A340: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005A344: lwc1        $f13, 0x6EC8($at)
    ctx->f_odd[(13 - 1) * 2] = MEM_W(ctx->r1, 0X6EC8);
    // 0x8005A348: lwc1        $f12, 0x6ECC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, 0X6ECC);
    // 0x8005A34C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x8005A350: c.le.d      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.d <= ctx->f0.d;
    // 0x8005A354: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8005A358: bc1f        L_8005A368
    if (!c1cs) {
        // 0x8005A35C: lui         $at, 0x4058
        ctx->r1 = S32(0X4058 << 16);
            goto L_8005A368;
    }
    // 0x8005A35C: lui         $at, 0x4058
    ctx->r1 = S32(0X4058 << 16);
    // 0x8005A360: b           L_8005A408
    // 0x8005A364: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
        goto L_8005A408;
    // 0x8005A364: sb          $zero, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = 0;
L_8005A368:
    // 0x8005A368: sub.d       $f16, $f12, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f12.d - ctx->f0.d;
    // 0x8005A36C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005A370: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005A374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005A378: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x8005A37C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8005A380: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8005A384: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A388: nop

    // 0x8005A38C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8005A390: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A394: nop

    // 0x8005A398: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005A39C: beq         $t7, $zero, L_8005A3EC
    if (ctx->r15 == 0) {
        // 0x8005A3A0: nop
    
            goto L_8005A3EC;
    }
    // 0x8005A3A0: nop

    // 0x8005A3A4: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A3A8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A3AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005A3B0: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x8005A3B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8005A3B8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8005A3BC: nop

    // 0x8005A3C0: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8005A3C4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8005A3C8: nop

    // 0x8005A3CC: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x8005A3D0: bne         $t7, $zero, L_8005A3E4
    if (ctx->r15 != 0) {
        // 0x8005A3D4: nop
    
            goto L_8005A3E4;
    }
    // 0x8005A3D4: nop

    // 0x8005A3D8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A3DC: b           L_8005A3FC
    // 0x8005A3E0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_8005A3FC;
    // 0x8005A3E0: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_8005A3E4:
    // 0x8005A3E4: b           L_8005A3FC
    // 0x8005A3E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_8005A3FC;
    // 0x8005A3E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
L_8005A3EC:
    // 0x8005A3EC: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8005A3F0: nop

    // 0x8005A3F4: bltz        $t7, L_8005A3E4
    if (SIGNED(ctx->r15) < 0) {
        // 0x8005A3F8: nop
    
            goto L_8005A3E4;
    }
    // 0x8005A3F8: nop

L_8005A3FC:
    // 0x8005A3FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8005A400: sb          $t7, 0x1F7($v0)
    MEM_B(0X1F7, ctx->r2) = ctx->r15;
    // 0x8005A404: nop

L_8005A408:
    // 0x8005A408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8005A40C:
    // 0x8005A40C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A410: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005A414: jr          $ra
    // 0x8005A418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8005A418: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void gfxtask_wait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077EA4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80077EA8: lw          $t6, -0x15A4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15A4);
    // 0x80077EAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80077EB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80077EB4: bne         $t6, $zero, L_80077EC4
    if (ctx->r14 != 0) {
        // 0x80077EB8: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_80077EC4;
    }
    // 0x80077EB8: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80077EBC: b           L_80077EEC
    // 0x80077EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80077EEC;
    // 0x80077EC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80077EC4:
    // 0x80077EC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077EC8: addiu       $a0, $a0, 0x6478
    ctx->r4 = ADD32(ctx->r4, 0X6478);
    // 0x80077ECC: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80077ED0: jal         0x800C9110
    // 0x80077ED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80077ED4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80077ED8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80077EDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80077EE0: sw          $zero, -0x15A4($at)
    MEM_W(-0X15A4, ctx->r1) = 0;
    // 0x80077EE4: lw          $v0, 0x4($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X4);
    // 0x80077EE8: nop

L_80077EEC:
    // 0x80077EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077EF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80077EF4: jr          $ra
    // 0x80077EF8: nop

    return;
    // 0x80077EF8: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4F28: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800D4F2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D4F30: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800D4F34: jal         0x800D4EA0
    // 0x800D4F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800D4F38: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800D4F3C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D4F40: jal         0x800D4DA0
    // 0x800D4F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800D4F44: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800D4F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4F4C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800D4F50: jr          $ra
    // 0x800D4F54: nop

    return;
    // 0x800D4F54: nop

;}
RECOMP_FUNC void charselect_music_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C620: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C624: addiu       $a1, $a1, 0x6960
    ctx->r5 = ADD32(ctx->r5, 0X6960);
    // 0x8008C628: lb          $v0, 0x1($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1);
    // 0x8008C62C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008C630: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008C634: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008C638: blez        $v0, L_8008C718
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008C63C: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008C718;
    }
    // 0x8008C63C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008C640: subu        $t7, $v0, $a0
    ctx->r15 = SUB32(ctx->r2, ctx->r4);
    // 0x8008C644: sb          $t7, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r15;
    // 0x8008C648: lb          $t8, 0x1($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1);
    // 0x8008C64C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C650: bgtz        $t8, L_8008C718
    if (SIGNED(ctx->r24) > 0) {
        // 0x8008C654: addiu       $s0, $s0, 0x6958
        ctx->r16 = ADD32(ctx->r16, 0X6958);
            goto L_8008C718;
    }
    // 0x8008C654: addiu       $s0, $s0, 0x6958
    ctx->r16 = ADD32(ctx->r16, 0X6958);
    // 0x8008C658: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C65C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C660: bltz        $v0, L_8008C69C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C664: sll         $t9, $v0, 1
        ctx->r25 = S32(ctx->r2 << 1);
            goto L_8008C69C;
    }
    // 0x8008C664: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x8008C668: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x8008C66C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C670: jal         0x80001114
    // 0x8008C674: nop

    music_channel_off(rdram, ctx);
        goto after_0;
    // 0x8008C674: nop

    after_0:
    // 0x8008C678: lb          $t0, 0x0($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X0);
    // 0x8008C67C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C680: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8008C684: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C688: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C68C: jal         0x80001114
    // 0x8008C690: nop

    music_channel_off(rdram, ctx);
        goto after_1;
    // 0x8008C690: nop

    after_1:
    // 0x8008C694: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8008C698: addiu       $a1, $a1, 0x6960
    ctx->r5 = ADD32(ctx->r5, 0X6960);
L_8008C69C:
    // 0x8008C69C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C6A0: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C6A4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C6A8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C6AC: bltz        $v0, L_8008C6C0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C6B0: sb          $v0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r2;
            goto L_8008C6C0;
    }
    // 0x8008C6B0: sb          $v0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r2;
    // 0x8008C6B4: lh          $t2, 0x2($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X2);
    // 0x8008C6B8: nop

    // 0x8008C6BC: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
L_8008C6C0:
    // 0x8008C6C0: lb          $t3, 0x0($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X0);
    // 0x8008C6C4: nop

    // 0x8008C6C8: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x8008C6CC: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C6D0: nop

    // 0x8008C6D4: bltz        $v0, L_8008C718
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C6D8: sll         $t5, $v0, 1
        ctx->r13 = S32(ctx->r2 << 1);
            goto L_8008C718;
    }
    // 0x8008C6D8: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x8008C6DC: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8008C6E0: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C6E4: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
    // 0x8008C6E8: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C6EC: jal         0x80001170
    // 0x8008C6F0: nop

    music_channel_on(rdram, ctx);
        goto after_2;
    // 0x8008C6F0: nop

    after_2:
    // 0x8008C6F4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C6F8: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C6FC: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x8008C700: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C704: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8008C708: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C70C: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C710: jal         0x80001170
    // 0x8008C714: nop

    music_channel_on(rdram, ctx);
        goto after_3;
    // 0x8008C714: nop

    after_3:
L_8008C718:
    // 0x8008C718: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C71C: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C720: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8008C724: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008C728: bltz        $v0, L_8008C7A8
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C72C: addiu       $s0, $s0, 0x6958
        ctx->r16 = ADD32(ctx->r16, 0X6958);
            goto L_8008C7A8;
    }
    // 0x8008C72C: addiu       $s0, $s0, 0x6958
    ctx->r16 = ADD32(ctx->r16, 0X6958);
    // 0x8008C730: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x8008C734: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    // 0x8008C738: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x8008C73C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8008C740: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8008C744: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C748: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x8008C74C: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x8008C750: bne         $at, $zero, L_8008C768
    if (ctx->r1 != 0) {
        // 0x8008C754: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C768;
    }
    // 0x8008C754: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C758: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x8008C75C: sh          $t2, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r10;
    // 0x8008C760: lh          $a2, 0x2($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X2);
    // 0x8008C764: nop

L_8008C768:
    // 0x8008C768: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C76C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C770: jal         0x80001268
    // 0x8008C774: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_4;
    // 0x8008C774: andi        $a1, $a2, 0xFF
    ctx->r5 = ctx->r6 & 0XFF;
    after_4:
    // 0x8008C778: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C77C: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
    // 0x8008C780: lb          $t4, 0x0($v1)
    ctx->r12 = MEM_B(ctx->r3, 0X0);
    // 0x8008C784: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C788: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8008C78C: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x8008C790: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C794: lbu         $a1, 0x3($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X3);
    // 0x8008C798: jal         0x80001268
    // 0x8008C79C: nop

    music_channel_fade_set(rdram, ctx);
        goto after_5;
    // 0x8008C79C: nop

    after_5:
    // 0x8008C7A0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8008C7A4: addiu       $v1, $v1, 0x6954
    ctx->r3 = ADD32(ctx->r3, 0X6954);
L_8008C7A8:
    // 0x8008C7A8: lb          $v0, 0x0($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X0);
    // 0x8008C7AC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8008C7B0: bltz        $v0, L_8008C85C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8008C7B4: sll         $t9, $t7, 2
        ctx->r25 = S32(ctx->r15 << 2);
            goto L_8008C85C;
    }
    // 0x8008C7B4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8008C7B8: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8008C7BC: lb          $t0, 0x0($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X0);
    // 0x8008C7C0: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x8008C7C4: beq         $t0, $v0, L_8008C848
    if (ctx->r8 == ctx->r2) {
        // 0x8008C7C8: sh          $t8, 0x2($s0)
        MEM_H(0X2, ctx->r16) = ctx->r24;
            goto L_8008C848;
    }
    // 0x8008C7C8: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x8008C7CC: lh          $v1, 0x2($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X2);
    // 0x8008C7D0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8008C7D4: bgez        $v1, L_8008C818
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8008C7D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8008C818;
    }
    // 0x8008C7D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7DC: sll         $t1, $v0, 1
    ctx->r9 = S32(ctx->r2 << 1);
    // 0x8008C7E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7E4: addu        $a0, $a0, $t1
    ctx->r4 = ADD32(ctx->r4, ctx->r9);
    // 0x8008C7E8: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C7EC: jal         0x80001114
    // 0x8008C7F0: nop

    music_channel_off(rdram, ctx);
        goto after_6;
    // 0x8008C7F0: nop

    after_6:
    // 0x8008C7F4: lb          $t2, 0x0($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X0);
    // 0x8008C7F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C7FC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8008C800: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8008C804: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C808: jal         0x80001114
    // 0x8008C80C: nop

    music_channel_off(rdram, ctx);
        goto after_7;
    // 0x8008C80C: nop

    after_7:
    // 0x8008C810: b           L_8008C84C
    // 0x8008C814: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
        goto L_8008C84C;
    // 0x8008C814: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C818:
    // 0x8008C818: addu        $a0, $a0, $t4
    ctx->r4 = ADD32(ctx->r4, ctx->r12);
    // 0x8008C81C: lbu         $a0, 0x334($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X334);
    // 0x8008C820: jal         0x80001268
    // 0x8008C824: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    music_channel_fade_set(rdram, ctx);
        goto after_8;
    // 0x8008C824: andi        $a1, $v1, 0xFF
    ctx->r5 = ctx->r3 & 0XFF;
    after_8:
    // 0x8008C828: lb          $t5, 0x0($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X0);
    // 0x8008C82C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008C830: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8008C834: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x8008C838: lbu         $a0, 0x335($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X335);
    // 0x8008C83C: lbu         $a1, 0x3($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X3);
    // 0x8008C840: jal         0x80001268
    // 0x8008C844: nop

    music_channel_fade_set(rdram, ctx);
        goto after_9;
    // 0x8008C844: nop

    after_9:
L_8008C848:
    // 0x8008C848: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
L_8008C84C:
    // 0x8008C84C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8008C850: bgez        $t6, L_8008C860
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008C854: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008C860;
    }
    // 0x8008C854: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008C858: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8008C85C:
    // 0x8008C85C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008C860:
    // 0x8008C860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008C864: jr          $ra
    // 0x8008C868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8008C868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void aitable_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006C3D0: lw          $v0, 0x1740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1740);
    // 0x8006C3D4: jr          $ra
    // 0x8006C3D8: nop

    return;
    // 0x8006C3D8: nop

;}
RECOMP_FUNC void level_global_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A8F0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006A8F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A8F8: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A8FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8006A900: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8006A904: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8006A908: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8006A90C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A910: jal         0x80070EDC
    // 0x8006A914: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006A914: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x8006A918: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8006A91C: jal         0x80076EE4
    // 0x8006A920: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8006A920: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_1:
    // 0x8006A924: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8006A928: addiu       $s3, $s3, 0x16E0
    ctx->r19 = ADD32(ctx->r19, 0X16E0);
    // 0x8006A92C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006A930: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006A934: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006A938: addiu       $v1, $v1, 0x1700
    ctx->r3 = ADD32(ctx->r3, 0X1700);
    // 0x8006A93C: addiu       $v0, $v0, 0x1740
    ctx->r2 = ADD32(ctx->r2, 0X1740);
L_8006A940:
    // 0x8006A940: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8006A944: sw          $zero, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = 0;
    // 0x8006A948: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x8006A94C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x8006A950: bne         $v1, $v0, L_8006A940
    if (ctx->r3 != ctx->r2) {
        // 0x8006A954: sw          $zero, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = 0;
            goto L_8006A940;
    }
    // 0x8006A954: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8006A958: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8006A95C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A960: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006A964: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x8006A968: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x8006A96C: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x8006A970: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8006A974: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A978: beq         $t3, $t8, L_8006A9A0
    if (ctx->r11 == ctx->r24) {
        // 0x8006A97C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8006A9A0;
    }
    // 0x8006A97C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006A980: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A984:
    // 0x8006A984: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x8006A988: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x8006A98C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8006A990: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8006A994: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8006A998: bne         $t3, $t6, L_8006A984
    if (ctx->r11 != ctx->r14) {
        // 0x8006A99C: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8006A984;
    }
    // 0x8006A99C: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8006A9A0:
    // 0x8006A9A0: addiu       $t7, $a2, -0x1
    ctx->r15 = ADD32(ctx->r6, -0X1);
    // 0x8006A9A4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006A9A8: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8006A9AC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006A9B0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8006A9B4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006A9B8: jal         0x80070EDC
    // 0x8006A9BC: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8006A9BC: sll         $a0, $t8, 1
    ctx->r4 = S32(ctx->r24 << 1);
    after_2:
    // 0x8006A9C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006A9C4: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006A9C8: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8006A9CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8006A9D0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006A9D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006A9D8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006A9DC: addiu       $s0, $s0, 0x16E8
    ctx->r16 = ADD32(ctx->r16, 0X16E8);
    // 0x8006A9E0: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006A9E4: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006A9E8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006A9EC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8006A9F0: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8006A9F4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006A9F8: blez        $t4, L_8006AB28
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8006A9FC: sw          $t9, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r25;
            goto L_8006AB28;
    }
    // 0x8006A9FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8006AA00: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8006AA04: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006AA08:
    // 0x8006AA08: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006AA0C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006AA10: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8006AA14: lw          $a2, 0x0($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X0);
    // 0x8006AA18: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8006AA1C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8006AA20: jal         0x80077190
    // 0x8006AA24: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8006AA24: addiu       $a3, $zero, 0xC4
    ctx->r7 = ADD32(0, 0XC4);
    after_3:
    // 0x8006AA28: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006AA2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006AA30: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006AA34: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006AA38: lb          $a0, 0x0($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X0);
    // 0x8006AA3C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8006AA40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AA44: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006AA48: slt         $at, $t7, $a0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006AA4C: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006AA50: beq         $at, $zero, L_8006AA5C
    if (ctx->r1 == 0) {
        // 0x8006AA54: addiu       $t0, $t0, 0x16FC
        ctx->r8 = ADD32(ctx->r8, 0X16FC);
            goto L_8006AA5C;
    }
    // 0x8006AA54: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006AA58: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
L_8006AA5C:
    // 0x8006AA5C: lb          $a0, 0x4C($a1)
    ctx->r4 = MEM_B(ctx->r5, 0X4C);
    // 0x8006AA60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AA64: bltz        $a0, L_8006AA90
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006AA68: slti        $at, $a0, 0x10
        ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
            goto L_8006AA90;
    }
    // 0x8006AA68: slti        $at, $a0, 0x10
    ctx->r1 = SIGNED(ctx->r4) < 0X10 ? 1 : 0;
    // 0x8006AA6C: beq         $at, $zero, L_8006AA90
    if (ctx->r1 == 0) {
        // 0x8006AA70: sll         $t8, $a0, 2
        ctx->r24 = S32(ctx->r4 << 2);
            goto L_8006AA90;
    }
    // 0x8006AA70: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8006AA74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006AA78: addiu       $t9, $t9, 0x1700
    ctx->r25 = ADD32(ctx->r25, 0X1700);
    // 0x8006AA7C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8006AA80: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8006AA84: nop

    // 0x8006AA88: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8006AA8C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8006AA90:
    // 0x8006AA90: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006AA94: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8006AA98: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x8006AA9C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x8006AAA0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAA4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAA8: lb          $t4, 0x4C($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4C);
    // 0x8006AAAC: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x8006AAB0: sb          $t4, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r12;
    // 0x8006AAB4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAB8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006AABC: lb          $t9, 0x4E($t6)
    ctx->r25 = MEM_B(ctx->r14, 0X4E);
    // 0x8006AAC0: addu        $t7, $t4, $v1
    ctx->r15 = ADD32(ctx->r12, ctx->r3);
    // 0x8006AAC4: sll         $t5, $t9, 4
    ctx->r13 = S32(ctx->r25 << 4);
    // 0x8006AAC8: sb          $t5, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r13;
    // 0x8006AACC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAD0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AAD4: addu        $v0, $t6, $v1
    ctx->r2 = ADD32(ctx->r14, ctx->r3);
    // 0x8006AAD8: lb          $t4, 0x4D($t9)
    ctx->r12 = MEM_B(ctx->r25, 0X4D);
    // 0x8006AADC: lb          $t8, 0x2($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X2);
    // 0x8006AAE0: andi        $t5, $t4, 0xF
    ctx->r13 = ctx->r12 & 0XF;
    // 0x8006AAE4: or          $t7, $t8, $t5
    ctx->r15 = ctx->r24 | ctx->r13;
    // 0x8006AAE8: sb          $t7, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r15;
    // 0x8006AAEC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8006AAF0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006AAF4: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8006AAF8: sb          $t6, 0x3($t4)
    MEM_B(0X3, ctx->r12) = ctx->r14;
    // 0x8006AAFC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006AB00: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x8006AB04: lh          $t5, 0xB0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0XB0);
    // 0x8006AB08: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x8006AB0C: sh          $t5, 0x4($t9)
    MEM_H(0X4, ctx->r25) = ctx->r13;
    // 0x8006AB10: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8006AB14: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AB18: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AB1C: bne         $at, $zero, L_8006AA08
    if (ctx->r1 != 0) {
        // 0x8006AB20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8006AA08;
    }
    // 0x8006AB20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8006AB24: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006AB28:
    // 0x8006AB28: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB2C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AB30: addiu       $a0, $t4, 0x1
    ctx->r4 = ADD32(ctx->r12, 0X1);
    // 0x8006AB34: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x8006AB38: jal         0x80070EDC
    // 0x8006AB3C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x8006AB3C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_4:
    // 0x8006AB40: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006AB44: addiu       $t1, $t1, 0x16F4
    ctx->r9 = ADD32(ctx->r9, 0X16F4);
    // 0x8006AB48: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006AB50: addiu       $a0, $a0, 0x16F8
    ctx->r4 = ADD32(ctx->r4, 0X16F8);
    // 0x8006AB54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AB58: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8006AB5C: addiu       $t2, $t2, 0x16F0
    ctx->r10 = ADD32(ctx->r10, 0X16F0);
    // 0x8006AB60: addiu       $t0, $t0, 0x16FC
    ctx->r8 = ADD32(ctx->r8, 0X16FC);
    // 0x8006AB64: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8006AB68: blez        $t7, L_8006AB98
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006AB6C: addiu       $t3, $zero, -0x1
        ctx->r11 = ADD32(0, -0X1);
            goto L_8006AB98;
    }
    // 0x8006AB6C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_8006AB70:
    // 0x8006AB70: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8006AB74: nop

    // 0x8006AB78: addu        $t9, $t5, $s1
    ctx->r25 = ADD32(ctx->r13, ctx->r17);
    // 0x8006AB7C: sb          $t3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r11;
    // 0x8006AB80: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8006AB84: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AB88: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8006AB8C: bne         $at, $zero, L_8006AB70
    if (ctx->r1 != 0) {
        // 0x8006AB90: nop
    
            goto L_8006AB70;
    }
    // 0x8006AB90: nop

    // 0x8006AB94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006AB98:
    // 0x8006AB98: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x8006AB9C: nop

    // 0x8006ABA0: blez        $a2, L_8006ABF8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8006ABA4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006ABF8;
    }
    // 0x8006ABA4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006ABA8: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
L_8006ABAC:
    // 0x8006ABAC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x8006ABB0: nop

    // 0x8006ABB4: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x8006ABB8: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8006ABBC: nop

    // 0x8006ABC0: bne         $a1, $t8, L_8006ABE4
    if (ctx->r5 != ctx->r24) {
        // 0x8006ABC4: nop
    
            goto L_8006ABE4;
    }
    // 0x8006ABC4: nop

    // 0x8006ABC8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8006ABCC: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8006ABD0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006ABD4: addu        $t9, $t7, $t5
    ctx->r25 = ADD32(ctx->r15, ctx->r13);
    // 0x8006ABD8: sb          $s1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r17;
    // 0x8006ABDC: lw          $a2, 0x16F0($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X16F0);
    // 0x8006ABE0: nop

L_8006ABE4:
    // 0x8006ABE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006ABE8: slt         $at, $s1, $a2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8006ABEC: bne         $at, $zero, L_8006ABAC
    if (ctx->r1 != 0) {
        // 0x8006ABF0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006ABAC;
    }
    // 0x8006ABF0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006ABF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8006ABF8:
    // 0x8006ABF8: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006ABFC: jal         0x80071380
    // 0x8006AC00: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x8006AC00: nop

    after_5:
    // 0x8006AC04: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8006AC08: jal         0x80071380
    // 0x8006AC0C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x8006AC0C: nop

    after_6:
    // 0x8006AC10: jal         0x80076EE4
    // 0x8006AC14: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    asset_table_load(rdram, ctx);
        goto after_7;
    // 0x8006AC14: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x8006AC18: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006AC1C: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8006AC20: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8006AC24: beq         $t3, $a2, L_8006AC3C
    if (ctx->r11 == ctx->r6) {
        // 0x8006AC28: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8006AC3C;
    }
    // 0x8006AC28: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8006AC2C:
    // 0x8006AC2C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8006AC30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006AC34: bne         $t3, $t6, L_8006AC2C
    if (ctx->r11 != ctx->r14) {
        // 0x8006AC38: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006AC2C;
    }
    // 0x8006AC38: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006AC3C:
    // 0x8006AC3C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8006AC40: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
    // 0x8006AC44: addu        $t4, $v1, $a0
    ctx->r12 = ADD32(ctx->r3, ctx->r4);
    // 0x8006AC48: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8006AC4C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AC50: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    // 0x8006AC54: sw          $a3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r7;
    // 0x8006AC58: jal         0x80070EDC
    // 0x8006AC5C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x8006AC5C: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_8:
    // 0x8006AC60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006AC64: addiu       $v1, $v1, 0x16EC
    ctx->r3 = ADD32(ctx->r3, 0X16EC);
    // 0x8006AC68: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8006AC6C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006AC70: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006AC74: jal         0x80070EDC
    // 0x8006AC78: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_9;
    // 0x8006AC78: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_9:
    // 0x8006AC7C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8006AC80: addiu       $s0, $s0, -0x2780
    ctx->r16 = ADD32(ctx->r16, -0X2780);
    // 0x8006AC84: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8006AC88: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8006AC8C: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x8006AC90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8006AC94: jal         0x80077190
    // 0x8006AC98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_10;
    // 0x8006AC98: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8006AC9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006ACA0: addiu       $v1, $v1, 0x16EC
    ctx->r3 = ADD32(ctx->r3, 0X16EC);
    // 0x8006ACA4: blez        $s1, L_8006AD7C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8006ACA8: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8006AD7C;
    }
    // 0x8006ACA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8006ACAC: andi        $a1, $s1, 0x3
    ctx->r5 = ctx->r17 & 0X3;
    // 0x8006ACB0: beq         $a1, $zero, L_8006ACEC
    if (ctx->r5 == 0) {
        // 0x8006ACB4: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8006ACEC;
    }
    // 0x8006ACB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8006ACB8: sll         $v0, $zero, 2
    ctx->r2 = S32(0 << 2);
L_8006ACBC:
    // 0x8006ACBC: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x8006ACC0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006ACC4: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006ACC8: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8006ACCC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8006ACD0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8006ACD4: addu        $t4, $t9, $t6
    ctx->r12 = ADD32(ctx->r25, ctx->r14);
    // 0x8006ACD8: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006ACDC: sw          $t4, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r12;
    // 0x8006ACE0: bne         $a0, $a3, L_8006ACBC
    if (ctx->r4 != ctx->r7) {
        // 0x8006ACE4: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8006ACBC;
    }
    // 0x8006ACE4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8006ACE8: beq         $a3, $s1, L_8006AD7C
    if (ctx->r7 == ctx->r17) {
        // 0x8006ACEC: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_8006AD7C;
    }
L_8006ACEC:
    // 0x8006ACEC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x8006ACF0: sll         $a0, $s1, 2
    ctx->r4 = S32(ctx->r17 << 2);
L_8006ACF4:
    // 0x8006ACF4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x8006ACF8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8006ACFC: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AD00: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8006AD04: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD08: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x8006AD0C: addu        $t5, $t7, $v0
    ctx->r13 = ADD32(ctx->r15, ctx->r2);
    // 0x8006AD10: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
    // 0x8006AD14: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD18: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD1C: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AD20: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8006AD24: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD28: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8006AD2C: addu        $t4, $t8, $t7
    ctx->r12 = ADD32(ctx->r24, ctx->r15);
    // 0x8006AD30: sw          $t4, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r12;
    // 0x8006AD34: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD38: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD3C: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AD40: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8006AD44: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD48: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8006AD4C: addu        $t4, $t7, $t5
    ctx->r12 = ADD32(ctx->r15, ctx->r13);
    // 0x8006AD50: sw          $t4, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r12;
    // 0x8006AD54: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8006AD5C: addu        $t7, $t8, $v0
    ctx->r15 = ADD32(ctx->r24, ctx->r2);
    // 0x8006AD60: lw          $t5, 0xC($t7)
    ctx->r13 = MEM_W(ctx->r15, 0XC);
    // 0x8006AD64: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006AD68: addu        $t8, $t6, $v0
    ctx->r24 = ADD32(ctx->r14, ctx->r2);
    // 0x8006AD6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8006AD70: addu        $t4, $t5, $t9
    ctx->r12 = ADD32(ctx->r13, ctx->r25);
    // 0x8006AD74: bne         $v0, $a0, L_8006ACF4
    if (ctx->r2 != ctx->r4) {
        // 0x8006AD78: sw          $t4, 0xC($t8)
        MEM_W(0XC, ctx->r24) = ctx->r12;
            goto L_8006ACF4;
    }
    // 0x8006AD78: sw          $t4, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r12;
L_8006AD7C:
    // 0x8006AD7C: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8006AD80: jal         0x80071380
    // 0x8006AD84: nop

    mempool_free(rdram, ctx);
        goto after_11;
    // 0x8006AD84: nop

    after_11:
    // 0x8006AD88: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006AD8C: lw          $a0, -0x276C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X276C);
    // 0x8006AD90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006AD94: blez        $a0, L_8006ADBC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006AD98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006ADBC;
    }
    // 0x8006AD98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006AD9C: lui         $a1, 0x8007
    ctx->r5 = S32(0X8007 << 16);
    // 0x8006ADA0: addiu       $a1, $a1, -0x7C68
    ctx->r5 = ADD32(ctx->r5, -0X7C68);
L_8006ADA4:
    // 0x8006ADA4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x8006ADA8: lbu         $t5, 0x0($t7)
    ctx->r13 = MEM_BU(ctx->r15, 0X0);
    // 0x8006ADAC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006ADB0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8006ADB4: bne         $at, $zero, L_8006ADA4
    if (ctx->r1 != 0) {
        // 0x8006ADB8: addu        $v1, $v1, $t5
        ctx->r3 = ADD32(ctx->r3, ctx->r13);
            goto L_8006ADA4;
    }
    // 0x8006ADB8: addu        $v1, $v1, $t5
    ctx->r3 = ADD32(ctx->r3, ctx->r13);
L_8006ADBC:
    // 0x8006ADBC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006ADC0: lw          $t9, -0x2770($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2770);
    // 0x8006ADC4: nop

    // 0x8006ADC8: beq         $v1, $t9, L_8006ADDC
    if (ctx->r3 == ctx->r25) {
        // 0x8006ADCC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8006ADDC;
    }
    // 0x8006ADCC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006ADD0: jal         0x8006A8E0
    // 0x8006ADD4: nop

    drm_disable_input(rdram, ctx);
        goto after_12;
    // 0x8006ADD4: nop

    after_12:
    // 0x8006ADD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8006ADDC:
    // 0x8006ADDC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8006ADE0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8006ADE4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8006ADE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8006ADEC: jr          $ra
    // 0x8006ADF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006ADF0: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ghostmenu_generate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099B78: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80099B7C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80099B80: addiu       $t1, $t1, 0x6A74
    ctx->r9 = ADD32(ctx->r9, 0X6A74);
    // 0x80099B84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80099B88: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80099B8C: jal         0x8001E2D0
    // 0x80099B90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80099B90: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80099B94: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80099B98: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099B9C: lui         $ra, 0x8012
    ctx->r31 = S32(0X8012 << 16);
    // 0x80099BA0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80099BA4: addiu       $t1, $t1, 0x6A74
    ctx->r9 = ADD32(ctx->r9, 0X6A74);
    // 0x80099BA8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80099BAC: addiu       $t3, $t3, 0x6AE0
    ctx->r11 = ADD32(ctx->r11, 0X6AE0);
    // 0x80099BB0: addiu       $ra, $ra, 0x6A8C
    ctx->r31 = ADD32(ctx->r31, 0X6A8C);
    // 0x80099BB4: addiu       $a3, $a3, 0x6A7C
    ctx->r7 = ADD32(ctx->r7, 0X6A7C);
    // 0x80099BB8: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80099BBC: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x80099BC0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80099BC4:
    // 0x80099BC4: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x80099BC8: nop

    // 0x80099BCC: beq         $a1, $a0, L_80099C58
    if (ctx->r5 == ctx->r4) {
        // 0x80099BD0: nop
    
            goto L_80099C58;
    }
    // 0x80099BD0: nop

    // 0x80099BD4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80099BD8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099BDC: beq         $a1, $t6, L_80099C1C
    if (ctx->r5 == ctx->r14) {
        // 0x80099BE0: addu        $t7, $v0, $t0
        ctx->r15 = ADD32(ctx->r2, ctx->r8);
            goto L_80099C1C;
    }
    // 0x80099BE0: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
    // 0x80099BE4: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80099BE8: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80099BEC: beq         $t7, $a0, L_80099C1C
    if (ctx->r15 == ctx->r4) {
        // 0x80099BF0: addu        $t7, $v0, $t0
        ctx->r15 = ADD32(ctx->r2, ctx->r8);
            goto L_80099C1C;
    }
    // 0x80099BF0: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
L_80099BF4:
    // 0x80099BF4: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x80099BF8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80099BFC: beq         $a1, $t8, L_80099C18
    if (ctx->r5 == ctx->r24) {
        // 0x80099C00: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80099C18;
    }
    // 0x80099C00: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80099C04: addu        $t9, $a2, $t0
    ctx->r25 = ADD32(ctx->r6, ctx->r8);
    // 0x80099C08: lbu         $t6, 0x0($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X0);
    // 0x80099C0C: nop

    // 0x80099C10: bne         $t6, $a0, L_80099BF4
    if (ctx->r14 != ctx->r4) {
        // 0x80099C14: nop
    
            goto L_80099BF4;
    }
    // 0x80099C14: nop

L_80099C18:
    // 0x80099C18: addu        $t7, $v0, $t0
    ctx->r15 = ADD32(ctx->r2, ctx->r8);
L_80099C1C:
    // 0x80099C1C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80099C20: addu        $t6, $ra, $t2
    ctx->r14 = ADD32(ctx->r31, ctx->r10);
    // 0x80099C24: beq         $a1, $t8, L_80099C58
    if (ctx->r5 == ctx->r24) {
        // 0x80099C28: nop
    
            goto L_80099C58;
    }
    // 0x80099C28: nop

    // 0x80099C2C: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80099C30: sll         $t8, $t0, 3
    ctx->r24 = S32(ctx->r8 << 3);
    // 0x80099C34: addu        $t9, $t3, $t4
    ctx->r25 = ADD32(ctx->r11, ctx->r12);
    // 0x80099C38: sb          $t2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r10;
    // 0x80099C3C: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80099C40: sll         $t6, $t4, 1
    ctx->r14 = S32(ctx->r12 << 1);
    // 0x80099C44: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80099C48: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80099C4C: sh          $t9, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r25;
    // 0x80099C50: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x80099C54: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
L_80099C58:
    // 0x80099C58: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x80099C5C: slti        $at, $t2, 0x6
    ctx->r1 = SIGNED(ctx->r10) < 0X6 ? 1 : 0;
    // 0x80099C60: bne         $at, $zero, L_80099BC4
    if (ctx->r1 != 0) {
        // 0x80099C64: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80099BC4;
    }
    // 0x80099C64: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80099C68: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80099C6C: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x80099C70: addiu       $t2, $t4, -0x1
    ctx->r10 = ADD32(ctx->r12, -0X1);
    // 0x80099C74: blez        $t2, L_80099D6C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80099C78: nop
    
            goto L_80099D6C;
    }
    // 0x80099C78: nop

    // 0x80099C7C: lhu         $a0, 0x44($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X44);
    // 0x80099C80: nop

L_80099C84:
    // 0x80099C84: blez        $t2, L_80099D58
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80099C88: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80099D58;
    }
    // 0x80099C88: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80099C8C: andi        $v0, $t2, 0x1
    ctx->r2 = ctx->r10 & 0X1;
    // 0x80099C90: beq         $v0, $zero, L_80099CCC
    if (ctx->r2 == 0) {
        // 0x80099C94: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80099CCC;
    }
    // 0x80099C94: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80099C98: beq         $at, $zero, L_80099CC8
    if (ctx->r1 == 0) {
        // 0x80099C9C: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80099CC8;
    }
    // 0x80099C9C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80099CA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099CA4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099CA8: lbu         $t6, 0x6AE1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6AE1);
    // 0x80099CAC: lbu         $a2, 0x6AE0($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X6AE0);
    // 0x80099CB0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80099CB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099CB8: andi        $a0, $a3, 0xFFFF
    ctx->r4 = ctx->r7 & 0XFFFF;
    // 0x80099CBC: andi        $a3, $a1, 0xFFFF
    ctx->r7 = ctx->r5 & 0XFFFF;
    // 0x80099CC0: sb          $t6, 0x6AE0($at)
    MEM_B(0X6AE0, ctx->r1) = ctx->r14;
    // 0x80099CC4: sb          $a2, 0x6AE1($at)
    MEM_B(0X6AE1, ctx->r1) = ctx->r6;
L_80099CC8:
    // 0x80099CC8: beq         $t0, $t2, L_80099D58
    if (ctx->r8 == ctx->r10) {
        // 0x80099CCC: sll         $t9, $t0, 1
        ctx->r25 = S32(ctx->r8 << 1);
            goto L_80099D58;
    }
L_80099CCC:
    // 0x80099CCC: sll         $t9, $t0, 1
    ctx->r25 = S32(ctx->r8 << 1);
    // 0x80099CD0: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80099CD4: addu        $v1, $t9, $t7
    ctx->r3 = ADD32(ctx->r25, ctx->r15);
    // 0x80099CD8: sh          $a0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r4;
    // 0x80099CDC: sh          $a3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r7;
L_80099CE0:
    // 0x80099CE0: lhu         $a0, 0x2($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X2);
    // 0x80099CE4: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x80099CE8: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x80099CEC: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80099CF0: beq         $at, $zero, L_80099D18
    if (ctx->r1 == 0) {
        // 0x80099CF4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80099D18;
    }
    // 0x80099CF4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80099CF8: lbu         $a2, 0x0($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X0);
    // 0x80099CFC: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80099D00: sh          $a0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r4;
    // 0x80099D04: andi        $a0, $t1, 0xFFFF
    ctx->r4 = ctx->r9 & 0XFFFF;
    // 0x80099D08: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80099D0C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80099D10: sb          $a2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r6;
    // 0x80099D14: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
L_80099D18:
    // 0x80099D18: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x80099D1C: addu        $v0, $t3, $t0
    ctx->r2 = ADD32(ctx->r11, ctx->r8);
    // 0x80099D20: slt         $at, $t1, $a3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80099D24: beq         $at, $zero, L_80099D44
    if (ctx->r1 == 0) {
        // 0x80099D28: nop
    
            goto L_80099D44;
    }
    // 0x80099D28: nop

    // 0x80099D2C: lbu         $a2, 0x1($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X1);
    // 0x80099D30: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80099D34: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x80099D38: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x80099D3C: sb          $a2, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r6;
    // 0x80099D40: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_80099D44:
    // 0x80099D44: lhu         $a0, 0x44($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X44);
    // 0x80099D48: lhu         $a3, 0x46($sp)
    ctx->r7 = MEM_HU(ctx->r29, 0X46);
    // 0x80099D4C: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x80099D50: bne         $t0, $t2, L_80099CE0
    if (ctx->r8 != ctx->r10) {
        // 0x80099D54: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80099CE0;
    }
    // 0x80099D54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80099D58:
    // 0x80099D58: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80099D5C: bgtz        $t2, L_80099C84
    if (SIGNED(ctx->r10) > 0) {
        // 0x80099D60: nop
    
            goto L_80099C84;
    }
    // 0x80099D60: nop

    // 0x80099D64: sh          $a3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r7;
    // 0x80099D68: sh          $a0, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r4;
L_80099D6C:
    // 0x80099D6C: blez        $t4, L_80099E0C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80099D70: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80099E0C;
    }
    // 0x80099D70: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099D74: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80099D78: addiu       $v1, $t9, 0x6AC0
    ctx->r3 = ADD32(ctx->r25, 0X6AC0);
    // 0x80099D7C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099D80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80099D84: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80099D88: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x80099D8C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80099D90: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80099D94: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80099D98: addiu       $t0, $t0, 0x6A7C
    ctx->r8 = ADD32(ctx->r8, 0X6A7C);
    // 0x80099D9C: addiu       $t1, $t1, 0x6A84
    ctx->r9 = ADD32(ctx->r9, 0X6A84);
    // 0x80099DA0: addiu       $t2, $t2, 0x6A98
    ctx->r10 = ADD32(ctx->r10, 0X6A98);
    // 0x80099DA4: addu        $t3, $t7, $v1
    ctx->r11 = ADD32(ctx->r15, ctx->r3);
    // 0x80099DA8: addiu       $a3, $a3, 0x6AB8
    ctx->r7 = ADD32(ctx->r7, 0X6AB8);
    // 0x80099DAC: addiu       $a2, $a2, 0x6AB0
    ctx->r6 = ADD32(ctx->r6, 0X6AB0);
    // 0x80099DB0: addiu       $a1, $a1, 0x6AE0
    ctx->r5 = ADD32(ctx->r5, 0X6AE0);
    // 0x80099DB4: addiu       $a0, $a0, 0x6AA8
    ctx->r4 = ADD32(ctx->r4, 0X6AA8);
L_80099DB8:
    // 0x80099DB8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x80099DBC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80099DC0: addu        $t8, $t0, $v0
    ctx->r24 = ADD32(ctx->r8, ctx->r2);
    // 0x80099DC4: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x80099DC8: addu        $t7, $t1, $v0
    ctx->r15 = ADD32(ctx->r9, ctx->r2);
    // 0x80099DCC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x80099DD0: addu        $t8, $ra, $v0
    ctx->r24 = ADD32(ctx->r31, ctx->r2);
    // 0x80099DD4: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80099DD8: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80099DDC: sb          $t9, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r25;
    // 0x80099DE0: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x80099DE4: addu        $t9, $t2, $t7
    ctx->r25 = ADD32(ctx->r10, ctx->r15);
    // 0x80099DE8: lhu         $t8, 0x0($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X0);
    // 0x80099DEC: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x80099DF0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099DF4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099DF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80099DFC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80099E00: sb          $t6, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r14;
    // 0x80099E04: bne         $at, $zero, L_80099DB8
    if (ctx->r1 != 0) {
        // 0x80099E08: sh          $t8, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r24;
            goto L_80099DB8;
    }
    // 0x80099E08: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
L_80099E0C:
    // 0x80099E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80099E10: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80099E14: jr          $ra
    // 0x80099E18: nop

    return;
    // 0x80099E18: nop

;}
RECOMP_FUNC void racer_sound_hovercraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D08: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80005D0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005D10: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80005D14: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80005D18: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80005D1C: jal         0x8001139C
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80005D20: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80005D24: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80005D28: bne         $v0, $zero, L_80005D54
    if (ctx->r2 != 0) {
        // 0x80005D2C: nop
    
            goto L_80005D54;
    }
    // 0x80005D2C: nop

    // 0x80005D30: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80005D34: lwc1        $f2, 0x24($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80005D38: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80005D3C: nop

    // 0x80005D40: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80005D44: jal         0x800CA030
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80005D48: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_1:
    // 0x80005D4C: b           L_80005D5C
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
        goto L_80005D5C;
    // 0x80005D50: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
L_80005D54:
    // 0x80005D54: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005D58: nop

L_80005D5C:
    // 0x80005D5C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005D60: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005D64: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005D68: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80005D6C: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80005D70: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80005D74: beq         $t7, $zero, L_80005DDC
    if (ctx->r15 == 0) {
        // 0x80005D78: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005DDC;
    }
    // 0x80005D78: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005D7C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80005D80: lwc1        $f8, 0xB0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x80005D84: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80005D88: nop

    // 0x80005D8C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005D90: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005D94: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80005D98: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80005D9C: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80005DA0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DA4: nop

    // 0x80005DA8: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80005DAC: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DB0: nop

    // 0x80005DB4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80005DB8: nop

    // 0x80005DBC: bc1f        L_80005E10
    if (!c1cs) {
        // 0x80005DC0: nop
    
            goto L_80005E10;
    }
    // 0x80005DC0: nop

    // 0x80005DC4: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80005DC8: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005DCC: nop

    // 0x80005DD0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DD4: b           L_80005E14
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_80005E14;
    // 0x80005DD8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005DDC:
    // 0x80005DDC: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80005DE0: lwc1        $f4, 0xB4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x80005DE4: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80005DE8: nop

    // 0x80005DEC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80005DF0: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005DF4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80005DF8: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80005DFC: swc1        $f4, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f4.u32l;
    // 0x80005E00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005E04: nop

    // 0x80005E08: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80005E0C: nop

L_80005E10:
    // 0x80005E10: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80005E14:
    // 0x80005E14: nop

    // 0x80005E18: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80005E1C: nop

    // 0x80005E20: bc1f        L_80005E2C
    if (!c1cs) {
        // 0x80005E24: nop
    
            goto L_80005E2C;
    }
    // 0x80005E24: nop

    // 0x80005E28: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_80005E2C:
    // 0x80005E2C: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x80005E30: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80005E34: lh          $t2, 0x196($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X196);
    // 0x80005E38: lh          $t4, 0x1A0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X1A0);
    // 0x80005E3C: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x80005E40: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x80005E44: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x80005E48: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
    // 0x80005E4C: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80005E50: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80005E54: bne         $at, $zero, L_80005E64
    if (ctx->r1 != 0) {
        // 0x80005E58: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80005E64;
    }
    // 0x80005E58: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80005E5C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80005E60: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E64:
    // 0x80005E64: slti        $at, $v0, -0x8000
    ctx->r1 = SIGNED(ctx->r2) < -0X8000 ? 1 : 0;
    // 0x80005E68: beq         $at, $zero, L_80005E74
    if (ctx->r1 == 0) {
        // 0x80005E6C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80005E74;
    }
    // 0x80005E6C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80005E70: addu        $v0, $v0, $at
    ctx->r2 = ADD32(ctx->r2, ctx->r1);
L_80005E74:
    // 0x80005E74: sll         $a0, $v0, 16
    ctx->r4 = S32(ctx->r2 << 16);
    // 0x80005E78: sra         $t6, $a0, 16
    ctx->r14 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80005E7C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80005E80: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005E84: jal         0x80070A04
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80005E88: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x80005E8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80005E90: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005E94: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x80005E98: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005E9C: bc1f        L_80005EA8
    if (!c1cs) {
        // 0x80005EA0: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80005EA8;
    }
    // 0x80005EA0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80005EA4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
L_80005EA8:
    // 0x80005EA8: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005EAC: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005EB0: jal         0x80066750
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_3;
    // 0x80005EB4: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x80005EB8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EBC: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EC0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EC4: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EC8: nop
    
            goto L_80005F24;
    }
    // 0x80005EC8: nop

    // 0x80005ECC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x80005ED0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005ED4: jal         0x8001139C
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    get_race_countdown(rdram, ctx);
        goto after_4;
    // 0x80005ED8: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x80005EDC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005EE0: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80005EE4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005EE8: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005EEC: bne         $v0, $zero, L_80005F24
    if (ctx->r2 != 0) {
        // 0x80005EF0: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_80005F24;
    }
    // 0x80005EF0: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005EF4: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80005EF8: lui         $at, 0x402E
    ctx->r1 = S32(0X402E << 16);
    // 0x80005EFC: lwc1        $f10, 0xBC($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0XBC);
    // 0x80005F00: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80005F04: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80005F08: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F0C: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80005F10: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80005F14: nop

    // 0x80005F18: div.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = DIV_D(ctx->f6.d, ctx->f10.d);
    // 0x80005F1C: b           L_80005F2C
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80005F2C;
    // 0x80005F20: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80005F24:
    // 0x80005F24: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80005F28: nop

L_80005F2C:
    // 0x80005F2C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x80005F30: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x80005F34: jal         0x800A06D0
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_5;
    // 0x80005F38: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80005F3C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80005F40: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80005F44: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80005F48: lwc1        $f18, 0x20($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80005F4C: bne         $v0, $zero, L_80005F64
    if (ctx->r2 != 0) {
        // 0x80005F50: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_80005F64;
    }
    // 0x80005F50: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80005F54: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80005F58: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80005F5C: nop

    // 0x80005F60: swc1        $f4, 0xA4($t8)
    MEM_W(0XA4, ctx->r24) = ctx->f4.u32l;
L_80005F64:
    // 0x80005F64: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80005F68: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80005F6C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80005F70: cvt.d.s     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f0.d = CVT_D_S(ctx->f16.fl);
    // 0x80005F74: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80005F78: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x80005F7C: bc1f        L_80005F90
    if (!c1cs) {
        // 0x80005F80: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80005F90;
    }
    // 0x80005F80: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80005F84: sub.d       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f0.d - ctx->f2.d;
    // 0x80005F88: b           L_80005F98
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
        goto L_80005F98;
    // 0x80005F8C: cvt.s.d     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f16.fl = CVT_S_D(ctx->f6.d);
L_80005F90:
    // 0x80005F90: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80005F94: nop

L_80005F98:
    // 0x80005F98: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80005F9C: cvt.d.s     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f8.d = CVT_D_S(ctx->f16.fl);
    // 0x80005FA0: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x80005FA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FA8: bc1t        L_8000607C
    if (c1cs) {
        // 0x80005FAC: nop
    
            goto L_8000607C;
    }
    // 0x80005FAC: nop

    // 0x80005FB0: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x80005FB4: nop

    // 0x80005FB8: lb          $v0, 0x185($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X185);
    // 0x80005FBC: nop

    // 0x80005FC0: beq         $v0, $zero, L_8000607C
    if (ctx->r2 == 0) {
        // 0x80005FC4: nop
    
            goto L_8000607C;
    }
    // 0x80005FC4: nop

    // 0x80005FC8: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80005FCC: beq         $at, $zero, L_80005FDC
    if (ctx->r1 == 0) {
        // 0x80005FD0: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80005FDC;
    }
    // 0x80005FD0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x80005FD4: b           L_80005FDC
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80005FDC;
    // 0x80005FD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80005FDC:
    // 0x80005FDC: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80005FE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80005FE4: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x80005FE8: lwc1        $f5, 0x51E0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51E0);
    // 0x80005FEC: lwc1        $f4, 0x51E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51E4);
    // 0x80005FF0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80005FF4: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80005FF8: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80005FFC: sll         $t9, $a1, 6
    ctx->r25 = S32(ctx->r5 << 6);
    // 0x80006000: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006004: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006008: nop

    // 0x8000600C: bc1f        L_80006048
    if (!c1cs) {
        // 0x80006010: nop
    
            goto L_80006048;
    }
    // 0x80006010: nop

    // 0x80006014: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80006018: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000601C: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006020: nop

    // 0x80006024: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006028: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x8000602C: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006030: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x80006034: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006038: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x8000603C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006040: b           L_800060B4
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006044: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006048:
    // 0x80006048: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x8000604C: nop

    // 0x80006050: bc1f        L_80006074
    if (!c1cs) {
        // 0x80006054: nop
    
            goto L_80006074;
    }
    // 0x80006054: nop

    // 0x80006058: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x8000605C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006060: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006064: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006068: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x8000606C: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006070: nop

L_80006074:
    // 0x80006074: b           L_800060B4
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800060B4;
    // 0x80006078: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_8000607C:
    // 0x8000607C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006080: lwc1        $f9, 0x51E8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X51E8);
    // 0x80006084: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006088: lwc1        $f8, 0x51EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X51EC);
    // 0x8000608C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006090: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006094: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80006098: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x8000609C: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x800060A0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800060A4: lw          $a0, -0x5E44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5E44);
    // 0x800060A8: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800060AC: nop

    // 0x800060B0: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800060B4:
    // 0x800060B4: lwc1        $f8, 0xCC($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x800060B8: lwc1        $f10, 0xA4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800060BC: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800060C0: lh          $t2, 0x0($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X0);
    // 0x800060C4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800060C8: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800060CC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800060D0: beq         $t2, $at, L_8000612C
    if (ctx->r10 == ctx->r1) {
        // 0x800060D4: add.s       $f14, $f14, $f8
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
            goto L_8000612C;
    }
    // 0x800060D4: add.s       $f14, $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f8.fl;
    // 0x800060D8: lb          $t4, 0x1E2($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X1E2);
    // 0x800060DC: nop

    // 0x800060E0: bne         $t4, $zero, L_8000612C
    if (ctx->r12 != 0) {
        // 0x800060E4: nop
    
            goto L_8000612C;
    }
    // 0x800060E4: nop

    // 0x800060E8: lb          $t3, 0x1E5($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X1E5);
    // 0x800060EC: nop

    // 0x800060F0: slti        $at, $t3, 0x4
    ctx->r1 = SIGNED(ctx->r11) < 0X4 ? 1 : 0;
    // 0x800060F4: beq         $at, $zero, L_8000612C
    if (ctx->r1 == 0) {
        // 0x800060F8: nop
    
            goto L_8000612C;
    }
    // 0x800060F8: nop

    // 0x800060FC: jal         0x8001139C
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    get_race_countdown(rdram, ctx);
        goto after_6;
    // 0x80006100: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_6:
    // 0x80006104: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80006108: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000610C: bne         $v0, $zero, L_8000612C
    if (ctx->r2 != 0) {
        // 0x80006110: addiu       $t1, $t1, -0x5E48
        ctx->r9 = ADD32(ctx->r9, -0X5E48);
            goto L_8000612C;
    }
    // 0x80006110: addiu       $t1, $t1, -0x5E48
    ctx->r9 = ADD32(ctx->r9, -0X5E48);
    // 0x80006114: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006118: lwc1        $f5, 0x51F0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X51F0);
    // 0x8000611C: lwc1        $f4, 0x51F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X51F4);
    // 0x80006120: cvt.d.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.d = CVT_D_S(ctx->f14.fl);
    // 0x80006124: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80006128: cvt.s.d     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f14.fl = CVT_S_D(ctx->f10.d);
L_8000612C:
    // 0x8000612C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006130: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80006134: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80006138: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8000613C: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80006140: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006144: div.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80006148: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000614C: swc1        $f4, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f4.u32l;
    // 0x80006150: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006154: lwc1        $f10, 0x51FC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X51FC);
    // 0x80006158: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000615C: lwc1        $f11, 0x51F8($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X51F8);
    // 0x80006160: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80006164: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80006168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000616C: bc1f        L_80006190
    if (!c1cs) {
        // 0x80006170: nop
    
            goto L_80006190;
    }
    // 0x80006170: nop

    // 0x80006174: lwc1        $f6, 0x5200($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5200);
    // 0x80006178: nop

    // 0x8000617C: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80006180: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006184: nop

    // 0x80006188: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x8000618C: nop

L_80006190:
    // 0x80006190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80006194: lwc1        $f4, 0x5204($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5204);
    // 0x80006198: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000619C: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800061A0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800061A4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800061A8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061AC: nop

    // 0x800061B0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800061B4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061B8: nop

    // 0x800061BC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061C0: beq         $a1, $zero, L_8000620C
    if (ctx->r5 == 0) {
        // 0x800061C4: nop
    
            goto L_8000620C;
    }
    // 0x800061C4: nop

    // 0x800061C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800061CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800061D0: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800061D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800061D8: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800061DC: nop

    // 0x800061E0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800061E4: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800061E8: nop

    // 0x800061EC: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800061F0: bne         $a1, $zero, L_80006204
    if (ctx->r5 != 0) {
        // 0x800061F4: nop
    
            goto L_80006204;
    }
    // 0x800061F4: nop

    // 0x800061F8: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800061FC: b           L_8000621C
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_8000621C;
    // 0x80006200: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_80006204:
    // 0x80006204: b           L_8000621C
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_8000621C;
    // 0x80006208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_8000620C:
    // 0x8000620C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006210: nop

    // 0x80006214: bltz        $a1, L_80006204
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006218: nop
    
            goto L_80006204;
    }
    // 0x80006218: nop

L_8000621C:
    // 0x8000621C: lhu         $t7, 0x18($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X18);
    // 0x80006220: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x80006224: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80006228: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000622C: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006230: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006260;
    }
    // 0x80006230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80006234:
    // 0x80006234: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006238: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x8000623C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80006240: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x80006244: lhu         $t4, 0x18($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X18);
    // 0x80006248: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x8000624C: slt         $at, $a0, $t4
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80006250: bne         $at, $zero, L_80006260
    if (ctx->r1 != 0) {
        // 0x80006254: slti        $at, $t8, 0x4
        ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
            goto L_80006260;
    }
    // 0x80006254: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80006258: bne         $at, $zero, L_80006234
    if (ctx->r1 != 0) {
        // 0x8000625C: nop
    
            goto L_80006234;
    }
    // 0x8000625C: nop

L_80006260:
    // 0x80006260: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80006264: bne         $v0, $at, L_8000627C
    if (ctx->r2 != ctx->r1) {
        // 0x80006268: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8000627C;
    }
    // 0x80006268: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8000626C: addu        $t3, $v1, $v0
    ctx->r11 = ADD32(ctx->r3, ctx->r2);
    // 0x80006270: lbu         $t0, 0x2C($t3)
    ctx->r8 = MEM_BU(ctx->r11, 0X2C);
    // 0x80006274: b           L_8000638C
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
        goto L_8000638C;
    // 0x80006278: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000627C:
    // 0x8000627C: beq         $a1, $zero, L_80006290
    if (ctx->r5 == 0) {
        // 0x80006280: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_80006290;
    }
    // 0x80006280: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006284: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80006288: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x8000628C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_80006290:
    // 0x80006290: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80006294: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80006298: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x8000629C: lhu         $a2, 0x18($t7)
    ctx->r6 = MEM_HU(ctx->r15, 0X18);
    // 0x800062A0: addu        $t2, $v1, $t9
    ctx->r10 = ADD32(ctx->r3, ctx->r25);
    // 0x800062A4: lhu         $t4, 0x1A($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X1A);
    // 0x800062A8: subu        $t8, $a0, $a2
    ctx->r24 = SUB32(ctx->r4, ctx->r6);
    // 0x800062AC: subu        $t3, $t4, $a2
    ctx->r11 = SUB32(ctx->r12, ctx->r6);
    // 0x800062B0: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800062B4: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062B8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800062BC: addu        $t6, $v1, $a1
    ctx->r14 = ADD32(ctx->r3, ctx->r5);
    // 0x800062C0: addu        $t5, $v1, $v0
    ctx->r13 = ADD32(ctx->r3, ctx->r2);
    // 0x800062C4: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062C8: lbu         $a3, 0x2C($t5)
    ctx->r7 = MEM_BU(ctx->r13, 0X2C);
    // 0x800062CC: lbu         $t7, 0x2D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2D);
    // 0x800062D0: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800062D4: subu        $t8, $t7, $a3
    ctx->r24 = SUB32(ctx->r15, ctx->r7);
    // 0x800062D8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800062DC: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800062E0: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800062E4: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800062E8: bgez        $a3, L_800062FC
    if (SIGNED(ctx->r7) >= 0) {
        // 0x800062EC: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800062FC;
    }
    // 0x800062EC: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800062F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800062F4: nop

    // 0x800062F8: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800062FC:
    // 0x800062FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006300: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006304: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80006308: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000630C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006310: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80006314: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006318: nop

    // 0x8000631C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006320: beq         $t0, $zero, L_8000636C
    if (ctx->r8 == 0) {
        // 0x80006324: nop
    
            goto L_8000636C;
    }
    // 0x80006324: nop

    // 0x80006328: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000632C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006330: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80006334: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006338: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8000633C: nop

    // 0x80006340: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80006344: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006348: nop

    // 0x8000634C: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006350: bne         $t0, $zero, L_80006364
    if (ctx->r8 != 0) {
        // 0x80006354: nop
    
            goto L_80006364;
    }
    // 0x80006354: nop

    // 0x80006358: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x8000635C: b           L_8000637C
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_8000637C;
    // 0x80006360: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_80006364:
    // 0x80006364: b           L_8000637C
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_8000637C;
    // 0x80006368: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8000636C:
    // 0x8000636C: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006370: nop

    // 0x80006374: bltz        $t0, L_80006364
    if (SIGNED(ctx->r8) < 0) {
        // 0x80006378: nop
    
            goto L_80006364;
    }
    // 0x80006378: nop

L_8000637C:
    // 0x8000637C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80006380: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80006384: or          $t0, $t2, $zero
    ctx->r8 = ctx->r10 | 0;
    // 0x80006388: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
L_8000638C:
    // 0x8000638C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006390: bgez        $t0, L_800063A8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80006394: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800063A8;
    }
    // 0x80006394: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006398: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000639C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800063A0: nop

    // 0x800063A4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800063A8:
    // 0x800063A8: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800063AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800063B0: div.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800063B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800063B8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800063BC: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800063C0: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
    // 0x800063C4: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800063C8: nop

    // 0x800063CC: swc1        $f6, 0x60($t4)
    MEM_W(0X60, ctx->r12) = ctx->f6.u32l;
    // 0x800063D0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800063D4: nop

    // 0x800063D8: swc1        $f10, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f10.u32l;
    // 0x800063DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800063E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800063E4: jr          $ra
    // 0x800063E8: nop

    return;
    // 0x800063E8: nop

;}
RECOMP_FUNC void racer_sound_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F8C: jr          $ra
    // 0x80007F90: sb          $zero, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = 0;
    return;
    // 0x80007F90: sb          $zero, -0x33C0($at)
    MEM_B(-0X33C0, ctx->r1) = 0;
;}
RECOMP_FUNC void render_dialogue_boxes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C5C60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C5C64: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800C5C68: addiu       $s0, $s0, 0x3C78
    ctx->r16 = ADD32(ctx->r16, 0X3C78);
    // 0x800C5C6C: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x800C5C70: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C5C74: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C5C78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C5C7C: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C5C80: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x800C5C84: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x800C5C88: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C5C8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C5C90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C5C94: beq         $t6, $zero, L_800C5CD0
    if (ctx->r14 == 0) {
        // 0x800C5C98: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_800C5CD0;
    }
    // 0x800C5C98: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C5C9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C5CA0: addiu       $v0, $v0, -0x524C
    ctx->r2 = ADD32(ctx->r2, -0X524C);
    // 0x800C5CA4: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800C5CA8: nop

    // 0x800C5CAC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800C5CB0: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800C5CB4: lb          $t9, 0x0($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X0);
    // 0x800C5CB8: nop

    // 0x800C5CBC: bne         $t9, $zero, L_800C5CD0
    if (ctx->r25 != 0) {
        // 0x800C5CC0: nop
    
            goto L_800C5CD0;
    }
    // 0x800C5CC0: nop

    // 0x800C5CC4: jal         0x8009EEEC
    // 0x800C5CC8: nop

    dialogue_close_stub(rdram, ctx);
        goto after_0;
    // 0x800C5CC8: nop

    after_0:
    // 0x800C5CCC: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800C5CD0:
    // 0x800C5CD0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C5CD4: addiu       $s3, $s3, -0x5258
    ctx->r19 = ADD32(ctx->r19, -0X5258);
    // 0x800C5CD8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C5CDC: addiu       $s1, $zero, 0x28
    ctx->r17 = ADD32(0, 0X28);
    // 0x800C5CE0: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
L_800C5CE4:
    // 0x800C5CE4: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C5CE8: nop

    // 0x800C5CEC: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C5CF0: lhu         $v0, 0x1E($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X1E);
    // 0x800C5CF4: nop

    // 0x800C5CF8: andi        $t2, $v0, 0x8000
    ctx->r10 = ctx->r2 & 0X8000;
    // 0x800C5CFC: beq         $t2, $zero, L_800C5D38
    if (ctx->r10 == 0) {
        // 0x800C5D00: andi        $t3, $v0, 0x4000
        ctx->r11 = ctx->r2 & 0X4000;
            goto L_800C5D38;
    }
    // 0x800C5D00: andi        $t3, $v0, 0x4000
    ctx->r11 = ctx->r2 & 0X4000;
    // 0x800C5D04: beq         $t3, $zero, L_800C5D28
    if (ctx->r11 == 0) {
        // 0x800C5D08: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C5D28;
    }
    // 0x800C5D08: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5D0C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5D10: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800C5D14: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800C5D18: jal         0x800C60B8
    // 0x800C5D1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_1;
    // 0x800C5D1C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800C5D20: b           L_800C5D3C
    // 0x800C5D24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C5D3C;
    // 0x800C5D24: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5D28:
    // 0x800C5D28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C5D2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C5D30: jal         0x800C60B8
    // 0x800C5D34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    render_dialogue_box(rdram, ctx);
        goto after_2;
    // 0x800C5D34: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
L_800C5D38:
    // 0x800C5D38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5D3C:
    // 0x800C5D3C: bne         $s0, $s4, L_800C5CE4
    if (ctx->r16 != ctx->r20) {
        // 0x800C5D40: addiu       $s1, $s1, 0x28
        ctx->r17 = ADD32(ctx->r17, 0X28);
            goto L_800C5CE4;
    }
    // 0x800C5D40: addiu       $s1, $s1, 0x28
    ctx->r17 = ADD32(ctx->r17, 0X28);
    // 0x800C5D44: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C5D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5D4C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5D50: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C5D54: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C5D58: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C5D5C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5D60: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C5D64: jr          $ra
    // 0x800C5D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C5D68: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void vec3s_reflect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FBF8: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006FBFC: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8006FC00: lh          $t1, 0x2($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X2);
    // 0x8006FC04: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8006FC08: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC0C: lh          $t2, 0x4($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X4);
    // 0x8006FC10: lh          $t5, 0x4($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X4);
    // 0x8006FC14: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FC18: nop

    // 0x8006FC1C: nop

    // 0x8006FC20: mult        $t1, $t4
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC24: mflo        $t7
    ctx->r15 = lo;
    // 0x8006FC28: add         $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8006FC2C: nop

    // 0x8006FC30: mult        $t2, $t5
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC34: mflo        $t8
    ctx->r24 = lo;
    // 0x8006FC38: add         $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8006FC3C: sra         $t6, $t6, 12
    ctx->r14 = S32(SIGNED(ctx->r14) >> 12);
    // 0x8006FC40: mult        $t6, $t3
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC44: mflo        $t3
    ctx->r11 = lo;
    // 0x8006FC48: sra         $t3, $t3, 13
    ctx->r11 = S32(SIGNED(ctx->r11) >> 13);
    // 0x8006FC4C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x8006FC50: mult        $t6, $t4
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC54: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x8006FC58: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FC5C: sra         $t4, $t4, 13
    ctx->r12 = S32(SIGNED(ctx->r12) >> 13);
    // 0x8006FC60: sub         $t4, $t4, $t1
    ctx->r12 = SUB32(ctx->r12, ctx->r9);
    // 0x8006FC64: mult        $t6, $t5
    result = S64(S32(ctx->r14)) * S64(S32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC68: sh          $t4, 0x8($a0)
    MEM_H(0X8, ctx->r4) = ctx->r12;
    // 0x8006FC6C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FC70: sra         $t5, $t5, 13
    ctx->r13 = S32(SIGNED(ctx->r13) >> 13);
    // 0x8006FC74: sub         $t5, $t5, $t0
    ctx->r13 = SUB32(ctx->r13, ctx->r8);
    // 0x8006FC78: jr          $ra
    // 0x8006FC7C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
    return;
    // 0x8006FC7C: sh          $t5, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void set_rectangle_texture_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF650: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x800AF654: nop

    // 0x800AF658: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800AF65C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800AF660: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800AF664: lbu         $a3, 0x1($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X1);
    // 0x800AF668: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800AF66C: sll         $t8, $a1, 5
    ctx->r24 = S32(ctx->r5 << 5);
    // 0x800AF670: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800AF674: sll         $t1, $a3, 5
    ctx->r9 = S32(ctx->r7 << 5);
    // 0x800AF678: sh          $t1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r9;
    // 0x800AF67C: sh          $t8, 0x8($v1)
    MEM_H(0X8, ctx->r3) = ctx->r24;
    // 0x800AF680: sh          $t8, 0x16($v1)
    MEM_H(0X16, ctx->r3) = ctx->r24;
    // 0x800AF684: sh          $t8, 0x18($v1)
    MEM_H(0X18, ctx->r3) = ctx->r24;
    // 0x800AF688: sh          $t1, 0x1A($v1)
    MEM_H(0X1A, ctx->r3) = ctx->r9;
    // 0x800AF68C: jr          $ra
    // 0x800AF690: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
    return;
    // 0x800AF690: sh          $t8, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void interrupts_disable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F750: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006F754: lb          $t0, -0x2660($t0)
    ctx->r8 = MEM_B(ctx->r8, -0X2660);
    // 0x8006F758: beq         $t0, $zero, L_8006F774
    if (ctx->r8 == 0) {
        // 0x8006F75C: mfc0        $t0, Status
        ctx->r8 = cop0_status_read(ctx);
            goto L_8006F774;
    }
    // 0x8006F75C: mfc0        $t0, Status
    ctx->r8 = cop0_status_read(ctx);
    // 0x8006F760: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x8006F764: and         $t1, $t0, $at
    ctx->r9 = ctx->r8 & ctx->r1;
    // 0x8006F768: mtc0        $t1, Status
    cop0_status_write(ctx, ctx->r9);    // 0x8006F76C: andi        $v0, $t0, 0x1
    ctx->r2 = ctx->r8 & 0X1;
    // 0x8006F770: nop

L_8006F774:
    // 0x8006F774: jr          $ra
    // 0x8006F778: nop

    return;
    // 0x8006F778: nop

;}
RECOMP_FUNC void func_8000B750(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B750: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000B754: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B758: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000B75C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000B760: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B764: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8000B768: bne         $a1, $at, L_8000B788
    if (ctx->r5 != ctx->r1) {
        // 0x8000B76C: sw          $a3, 0x8C($sp)
        MEM_W(0X8C, ctx->r29) = ctx->r7;
            goto L_8000B788;
    }
    // 0x8000B76C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8000B770: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B774: addiu       $v1, $v1, -0x3330
    ctx->r3 = ADD32(ctx->r3, -0X3330);
    // 0x8000B778: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000B77C: nop

    // 0x8000B780: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8000B784: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_8000B788:
    // 0x8000B788: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000B78C: addiu       $v1, $v1, -0x3330
    ctx->r3 = ADD32(ctx->r3, -0X3330);
    // 0x8000B790: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8000B794: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000B798: bgez        $t7, L_8000B7A4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000B79C: nop
    
            goto L_8000B7A4;
    }
    // 0x8000B79C: nop

    // 0x8000B7A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8000B7A4:
    // 0x8000B7A4: bltz        $s0, L_8000BAD0
    if (SIGNED(ctx->r16) < 0) {
        // 0x8000B7A8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BAD0;
    }
    // 0x8000B7A8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B7AC: beq         $at, $zero, L_8000BACC
    if (ctx->r1 == 0) {
        // 0x8000B7B0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_8000BACC;
    }
    // 0x8000B7B0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000B7B4: jal         0x8001E2D0
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000B7B8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    after_0:
    // 0x8000B7BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000B7C0: addiu       $t6, $t6, -0x4A60
    ctx->r14 = ADD32(ctx->r14, -0X4A60);
    // 0x8000B7C4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8000B7C8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B7CC: addu        $t2, $t5, $t6
    ctx->r10 = ADD32(ctx->r13, ctx->r14);
    // 0x8000B7D0: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000B7D4: sll         $t9, $s0, 7
    ctx->r25 = S32(ctx->r16 << 7);
    // 0x8000B7D8: lw          $a2, 0x88($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X88);
    // 0x8000B7DC: addu        $v1, $t9, $v0
    ctx->r3 = ADD32(ctx->r25, ctx->r2);
    // 0x8000B7E0: sll         $t8, $a1, 7
    ctx->r24 = S32(ctx->r5 << 7);
    // 0x8000B7E4: addu        $t4, $t8, $v0
    ctx->r12 = ADD32(ctx->r24, ctx->r2);
    // 0x8000B7E8: beq         $a3, $zero, L_8000BACC
    if (ctx->r7 == 0) {
        // 0x8000B7EC: or          $t3, $v1, $zero
        ctx->r11 = ctx->r3 | 0;
            goto L_8000BACC;
    }
    // 0x8000B7EC: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
    // 0x8000B7F0: beq         $a2, $zero, L_8000B818
    if (ctx->r6 == 0) {
        // 0x8000B7F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000B818;
    }
    // 0x8000B7F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B7F8: beq         $a2, $at, L_8000B820
    if (ctx->r6 == ctx->r1) {
        // 0x8000B7FC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000B820;
    }
    // 0x8000B7FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B800: beq         $a2, $at, L_8000B828
    if (ctx->r6 == ctx->r1) {
        // 0x8000B804: addiu       $at, $zero, 0xD
        ctx->r1 = ADD32(0, 0XD);
            goto L_8000B828;
    }
    // 0x8000B804: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8000B808: beq         $a2, $at, L_8000B830
    if (ctx->r6 == ctx->r1) {
        // 0x8000B80C: addiu       $v0, $v1, 0x48
        ctx->r2 = ADD32(ctx->r3, 0X48);
            goto L_8000B830;
    }
    // 0x8000B80C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
    // 0x8000B810: b           L_8000B830
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B830;
    // 0x8000B814: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B818:
    // 0x8000B818: b           L_8000B830
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8000B830;
    // 0x8000B81C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000B820:
    // 0x8000B820: b           L_8000B830
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
        goto L_8000B830;
    // 0x8000B824: addiu       $v0, $v1, 0x24
    ctx->r2 = ADD32(ctx->r3, 0X24);
L_8000B828:
    // 0x8000B828: b           L_8000B830
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
        goto L_8000B830;
    // 0x8000B82C: addiu       $v0, $v1, 0x48
    ctx->r2 = ADD32(ctx->r3, 0X48);
L_8000B830:
    // 0x8000B830: beq         $v0, $zero, L_8000BAB8
    if (ctx->r2 == 0) {
        // 0x8000B834: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000BAB8;
    }
    // 0x8000B834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B838: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B83C: sb          $a2, -0x4A38($at)
    MEM_B(-0X4A38, ctx->r1) = ctx->r6;
    // 0x8000B840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000B844: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000B848: sb          $a1, -0x4A28($at)
    MEM_B(-0X4A28, ctx->r1) = ctx->r5;
    // 0x8000B84C: lbu         $t7, 0x70($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X70);
    // 0x8000B850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000B854: bne         $t7, $at, L_8000BA18
    if (ctx->r15 != ctx->r1) {
        // 0x8000B858: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_8000BA18;
    }
    // 0x8000B858: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8000B85C: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B860: sw          $t4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r12;
    // 0x8000B864: sll         $t9, $t8, 28
    ctx->r25 = S32(ctx->r24 << 28);
    // 0x8000B868: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B86C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x8000B870: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B874: jal         0x80070A38
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x8000B878: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    after_1:
    // 0x8000B87C: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B880: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B884: lwc1        $f6, 0x18($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000B888: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000B88C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8000B890: lwc1        $f12, 0x74($t3)
    ctx->f12.u32l = MEM_W(ctx->r11, 0X74);
    // 0x8000B894: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8000B898: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000B89C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000B8A0: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x8000B8A4: mul.s       $f2, $f10, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8000B8A8: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B8AC: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8000B8B0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000B8B4: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8000B8B8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B8BC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B8C0: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x8000B8C4: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8000B8C8: addiu       $t1, $t1, -0x4A7C
    ctx->r9 = ADD32(ctx->r9, -0X4A7C);
    // 0x8000B8CC: mul.s       $f14, $f4, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8000B8D0: bne         $v1, $at, L_8000B8F4
    if (ctx->r3 != ctx->r1) {
        // 0x8000B8D4: addiu       $t0, $t0, -0x4A84
        ctx->r8 = ADD32(ctx->r8, -0X4A84);
            goto L_8000B8F4;
    }
    // 0x8000B8D4: addiu       $t0, $t0, -0x4A84
    ctx->r8 = ADD32(ctx->r8, -0X4A84);
    // 0x8000B8D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B8DC: lwc1        $f0, 0x56C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C0);
    // 0x8000B8E0: nop

    // 0x8000B8E4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B8E8: nop

    // 0x8000B8EC: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B8F0: nop

L_8000B8F4:
    // 0x8000B8F4: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000B8F8: bne         $at, $zero, L_8000B91C
    if (ctx->r1 != 0) {
        // 0x8000B8FC: addiu       $t6, $zero, -0x8000
        ctx->r14 = ADD32(0, -0X8000);
            goto L_8000B91C;
    }
    // 0x8000B8FC: addiu       $t6, $zero, -0x8000
    ctx->r14 = ADD32(0, -0X8000);
    // 0x8000B900: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000B904: lwc1        $f0, 0x56C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X56C4);
    // 0x8000B908: nop

    // 0x8000B90C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8000B910: nop

    // 0x8000B914: mul.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8000B918: nop

L_8000B91C:
    // 0x8000B91C: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000B920: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000B924: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8000B928: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000B92C: lw          $v1, -0x4A78($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4A78);
    // 0x8000B930: swc1        $f10, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f10.u32l;
    // 0x8000B934: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000B938: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B93C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8000B940: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000B944: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000B948: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8000B94C: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8000B950: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000B954: lw          $t8, -0x3344($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3344);
    // 0x8000B958: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
    // 0x8000B95C: sh          $t6, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r14;
    // 0x8000B960: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8000B964: sh          $zero, 0x52($sp)
    MEM_H(0X52, ctx->r29) = 0;
    // 0x8000B968: sh          $zero, 0x54($sp)
    MEM_H(0X54, ctx->r29) = 0;
    // 0x8000B96C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000B970: swc1        $f14, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f14.u32l;
    // 0x8000B974: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
    // 0x8000B978: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8000B97C: addu        $a0, $t8, $t5
    ctx->r4 = ADD32(ctx->r24, ctx->r13);
    // 0x8000B980: lbu         $t8, 0x72($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X72);
    // 0x8000B984: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x8000B988: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000B98C: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B990: sll         $t5, $t8, 12
    ctx->r13 = S32(ctx->r24 << 12);
    // 0x8000B994: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8000B998: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8000B99C: lw          $t7, 0x7C($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X7C);
    // 0x8000B9A0: lw          $t6, -0x333C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X333C);
    // 0x8000B9A4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8000B9A8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000B9AC: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000B9B0: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8000B9B4: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8000B9B8: jal         0x8000B38C
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    func_8000B38C(rdram, ctx);
        goto after_2;
    // 0x8000B9BC: addu        $a1, $t6, $t9
    ctx->r5 = ADD32(ctx->r14, ctx->r25);
    after_2:
    // 0x8000B9C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8000B9C4: addiu       $t0, $t0, -0x4A84
    ctx->r8 = ADD32(ctx->r8, -0X4A84);
    // 0x8000B9C8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9CC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000B9D0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000B9D4: addiu       $t1, $t1, -0x4A7C
    ctx->r9 = ADD32(ctx->r9, -0X4A7C);
    // 0x8000B9D8: sll         $t6, $s0, 28
    ctx->r14 = S32(ctx->r16 << 28);
    // 0x8000B9DC: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8000B9E0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000B9E4: or          $t5, $t6, $t8
    ctx->r13 = ctx->r14 | ctx->r24;
    // 0x8000B9E8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000B9EC: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x8000B9F0: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x8000B9F4: sw          $t9, 0x7C($t6)
    MEM_W(0X7C, ctx->r14) = ctx->r25;
    // 0x8000B9F8: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8000B9FC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8000BA00: addiu       $t5, $t8, 0x9
    ctx->r13 = ADD32(ctx->r24, 0X9);
    // 0x8000BA04: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x8000BA08: lw          $a3, 0x0($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA0C: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    // 0x8000BA10: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8000BA14: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_8000BA18:
    // 0x8000BA18: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8000BA1C: sw          $a0, 0x78($a3)
    MEM_W(0X78, ctx->r7) = ctx->r4;
    // 0x8000BA20: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA24: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8000BA28: swc1        $f0, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f0.u32l;
    // 0x8000BA2C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA30: nop

    // 0x8000BA34: swc1        $f0, 0x10($t8)
    MEM_W(0X10, ctx->r24) = ctx->f0.u32l;
    // 0x8000BA38: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000BA3C: nop

    // 0x8000BA40: swc1        $f0, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->f0.u32l;
    // 0x8000BA44: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000BA48: nop

    // 0x8000BA4C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x8000BA50: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8000BA54: nop

    // 0x8000BA58: swc1        $f4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f4.u32l;
    // 0x8000BA5C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000BA60: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x8000BA64: jal         0x80070560
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_3;
    // 0x8000BA68: swc1        $f8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8000BA6C: jal         0x80011560
    // 0x8000BA70: nop

    ignore_bounds_check(rdram, ctx);
        goto after_4;
    // 0x8000BA70: nop

    after_4:
    // 0x8000BA74: lw          $v0, 0x80($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X80);
    // 0x8000BA78: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8000BA7C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000BA80: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8000BA84: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BA88: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8000BA8C: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000BA90: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000BA94: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x8000BA98: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8000BA9C: add.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000BAA0: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x8000BAA4: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000BAA8: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8000BAAC: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8000BAB0: jal         0x80011570
    // 0x8000BAB4: nop

    move_object(rdram, ctx);
        goto after_5;
    // 0x8000BAB4: nop

    after_5:
L_8000BAB8:
    // 0x8000BAB8: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x8000BABC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAC0: beq         $t7, $zero, L_8000BACC
    if (ctx->r15 == 0) {
        // 0x8000BAC4: addu        $at, $at, $s0
        ctx->r1 = ADD32(ctx->r1, ctx->r16);
            goto L_8000BACC;
    }
    // 0x8000BAC4: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x8000BAC8: sb          $zero, -0x4A18($at)
    MEM_B(-0X4A18, ctx->r1) = 0;
L_8000BACC:
    // 0x8000BACC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BAD0:
    // 0x8000BAD0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000BAD4: jr          $ra
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8000BAD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void level_music_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006BF54: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BF58: lw          $t6, 0x16E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X16E8);
    // 0x8006BF5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006BF60: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8006BF64: lbu         $t7, 0x52($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X52);
    // 0x8006BF68: nop

    // 0x8006BF6C: beq         $t7, $zero, L_8006BFBC
    if (ctx->r15 == 0) {
        // 0x8006BF70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8006BFBC;
    }
    // 0x8006BF70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006BF74: jal         0x800012E8
    // 0x8006BF78: nop

    music_channel_reset_all(rdram, ctx);
        goto after_0;
    // 0x8006BF78: nop

    after_0:
    // 0x8006BF7C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8006BF80: lw          $t8, 0x16E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X16E8);
    // 0x8006BF84: nop

    // 0x8006BF88: lbu         $a0, 0x52($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X52);
    // 0x8006BF8C: jal         0x80000B34
    // 0x8006BF90: nop

    music_play(rdram, ctx);
        goto after_1;
    // 0x8006BF90: nop

    after_1:
    // 0x8006BF94: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006BF98: jal         0x800014BC
    // 0x8006BF9C: nop

    music_tempo_set_relative(rdram, ctx);
        goto after_2;
    // 0x8006BF9C: nop

    after_2:
    // 0x8006BFA0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006BFA4: lw          $t9, 0x16E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X16E8);
    // 0x8006BFA8: nop

    // 0x8006BFAC: lhu         $a0, 0x54($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X54);
    // 0x8006BFB0: jal         0x80001074
    // 0x8006BFB4: nop

    music_dynamic_set(rdram, ctx);
        goto after_3;
    // 0x8006BFB4: nop

    after_3:
    // 0x8006BFB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8006BFBC:
    // 0x8006BFBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006BFC0: jr          $ra
    // 0x8006BFC4: nop

    return;
    // 0x8006BFC4: nop

;}
RECOMP_FUNC void render_dialogue_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C56C8: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800C56CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C56D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C56D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C56D8: sw          $a1, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r5;
    // 0x800C56DC: sw          $a2, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r6;
    // 0x800C56E0: bne         $a3, $zero, L_800C56F0
    if (ctx->r7 != 0) {
        // 0x800C56E4: sw          $a3, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r7;
            goto L_800C56F0;
    }
    // 0x800C56E4: sw          $a3, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r7;
    // 0x800C56E8: b           L_800C5978
    // 0x800C56EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800C5978;
    // 0x800C56EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C56F0:
    // 0x800C56F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C56F4: lw          $a0, -0x5254($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5254);
    // 0x800C56F8: sll         $t7, $zero, 5
    ctx->r15 = S32(0 << 5);
    // 0x800C56FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800C5700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C5704: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C5708: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
L_800C570C:
    // 0x800C570C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800C5710: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x800C5714: bne         $a1, $t8, L_800C5720
    if (ctx->r5 != ctx->r24) {
        // 0x800C5718: nop
    
            goto L_800C5720;
    }
    // 0x800C5718: nop

    // 0x800C571C: addu        $a3, $t9, $a0
    ctx->r7 = ADD32(ctx->r25, ctx->r4);
L_800C5720:
    // 0x800C5720: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C5724: slti        $at, $v1, 0x40
    ctx->r1 = SIGNED(ctx->r3) < 0X40 ? 1 : 0;
    // 0x800C5728: beq         $at, $zero, L_800C5738
    if (ctx->r1 == 0) {
        // 0x800C572C: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_800C5738;
    }
    // 0x800C572C: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800C5730: beq         $a3, $zero, L_800C570C
    if (ctx->r7 == 0) {
        // 0x800C5734: nop
    
            goto L_800C570C;
    }
    // 0x800C5734: nop

L_800C5738:
    // 0x800C5738: beq         $a3, $zero, L_800C5974
    if (ctx->r7 == 0) {
        // 0x800C573C: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_800C5974;
    }
    // 0x800C573C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800C5740: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800C5744: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C5748: lw          $t3, -0x5258($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5258);
    // 0x800C574C: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C5750: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x800C5754: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800C5758: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x800C575C: bne         $t4, $v0, L_800C5774
    if (ctx->r12 != ctx->r2) {
        // 0x800C5760: addu        $t0, $t2, $t3
        ctx->r8 = ADD32(ctx->r10, ctx->r11);
            goto L_800C5774;
    }
    // 0x800C5760: addu        $t0, $t2, $t3
    ctx->r8 = ADD32(ctx->r10, ctx->r11);
    // 0x800C5764: lh          $t5, 0xC($t0)
    ctx->r13 = MEM_H(ctx->r8, 0XC);
    // 0x800C5768: nop

    // 0x800C576C: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800C5770: sw          $t6, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r14;
L_800C5774:
    // 0x800C5774: lw          $t7, 0x150($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X150);
    // 0x800C5778: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C577C: bne         $t7, $v0, L_800C5794
    if (ctx->r15 != ctx->r2) {
        // 0x800C5780: nop
    
            goto L_800C5794;
    }
    // 0x800C5780: nop

    // 0x800C5784: lh          $t8, 0xE($t0)
    ctx->r24 = MEM_H(ctx->r8, 0XE);
    // 0x800C5788: nop

    // 0x800C578C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800C5790: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800C5794:
    // 0x800C5794: lbu         $v0, 0x1D($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5798: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C579C: beq         $a1, $v0, L_800C585C
    if (ctx->r5 == ctx->r2) {
        // 0x800C57A0: sll         $t2, $v0, 10
        ctx->r10 = S32(ctx->r2 << 10);
            goto L_800C585C;
    }
    // 0x800C57A0: sll         $t2, $v0, 10
    ctx->r10 = S32(ctx->r2 << 10);
    // 0x800C57A4: lw          $t3, -0x525C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X525C);
    // 0x800C57A8: andi        $t4, $v1, 0x5
    ctx->r12 = ctx->r3 & 0X5;
    // 0x800C57AC: beq         $t4, $zero, L_800C581C
    if (ctx->r12 == 0) {
        // 0x800C57B0: addu        $t1, $t2, $t3
        ctx->r9 = ADD32(ctx->r10, ctx->r11);
            goto L_800C581C;
    }
    // 0x800C57B0: addu        $t1, $t2, $t3
    ctx->r9 = ADD32(ctx->r10, ctx->r11);
    // 0x800C57B4: lw          $a2, 0x158($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X158);
    // 0x800C57B8: lw          $a0, 0x154($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X154);
    // 0x800C57BC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800C57C0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800C57C4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x800C57C8: jal         0x800C64C0
    // 0x800C57CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    parse_string_with_number(rdram, ctx);
        goto after_0;
    // 0x800C57CC: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C57D0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C57D4: lw          $a1, 0x14C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X14C);
    // 0x800C57D8: lbu         $a2, 0x1D($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C57DC: jal         0x800C5300
    // 0x800C57E0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    get_text_width(rdram, ctx);
        goto after_1;
    // 0x800C57E0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_1:
    // 0x800C57E4: lw          $v1, 0x15C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X15C);
    // 0x800C57E8: lw          $a0, 0x14C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X14C);
    // 0x800C57EC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800C57F0: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x800C57F4: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C57F8: andi        $t5, $v1, 0x1
    ctx->r13 = ctx->r3 & 0X1;
    // 0x800C57FC: beq         $t5, $zero, L_800C5814
    if (ctx->r13 == 0) {
        // 0x800C5800: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800C5814;
    }
    // 0x800C5800: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800C5804: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x800C5808: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C580C: b           L_800C581C
    // 0x800C5810: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
        goto L_800C581C;
    // 0x800C5810: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C5814:
    // 0x800C5814: subu        $a0, $a0, $t6
    ctx->r4 = SUB32(ctx->r4, ctx->r14);
    // 0x800C5818: sw          $a0, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r4;
L_800C581C:
    // 0x800C581C: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800C5820: beq         $t7, $zero, L_800C5840
    if (ctx->r15 == 0) {
        // 0x800C5824: andi        $t4, $v1, 0x8
        ctx->r12 = ctx->r3 & 0X8;
            goto L_800C5840;
    }
    // 0x800C5824: andi        $t4, $v1, 0x8
    ctx->r12 = ctx->r3 & 0X8;
    // 0x800C5828: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800C582C: lhu         $t9, 0x22($t1)
    ctx->r25 = MEM_HU(ctx->r9, 0X22);
    // 0x800C5830: nop

    // 0x800C5834: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800C5838: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800C583C: sw          $t3, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r11;
L_800C5840:
    // 0x800C5840: beq         $t4, $zero, L_800C585C
    if (ctx->r12 == 0) {
        // 0x800C5844: nop
    
            goto L_800C585C;
    }
    // 0x800C5844: nop

    // 0x800C5848: lhu         $t6, 0x22($t1)
    ctx->r14 = MEM_HU(ctx->r9, 0X22);
    // 0x800C584C: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800C5850: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x800C5854: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x800C5858: sw          $t8, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r24;
L_800C585C:
    // 0x800C585C: lw          $a0, 0x24($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X24);
    // 0x800C5860: lw          $s0, 0x158($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X158);
    // 0x800C5864: bne         $a0, $zero, L_800C5878
    if (ctx->r4 != 0) {
        // 0x800C5868: addiu       $v1, $t0, 0x24
        ctx->r3 = ADD32(ctx->r8, 0X24);
            goto L_800C5878;
    }
    // 0x800C5868: addiu       $v1, $t0, 0x24
    ctx->r3 = ADD32(ctx->r8, 0X24);
    // 0x800C586C: sw          $a3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r7;
    // 0x800C5870: b           L_800C58C4
    // 0x800C5874: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
        goto L_800C58C4;
    // 0x800C5874: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_800C5878:
    // 0x800C5878: beq         $a0, $zero, L_800C58BC
    if (ctx->r4 == 0) {
        // 0x800C587C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800C58BC;
    }
    // 0x800C587C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800C5880: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x800C5884: nop

    // 0x800C5888: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800C588C: beq         $at, $zero, L_800C58BC
    if (ctx->r1 == 0) {
        // 0x800C5890: nop
    
            goto L_800C58BC;
    }
    // 0x800C5890: nop

L_800C5894:
    // 0x800C5894: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x800C5898: lw          $v0, 0x1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1C);
    // 0x800C589C: nop

    // 0x800C58A0: beq         $v0, $zero, L_800C58BC
    if (ctx->r2 == 0) {
        // 0x800C58A4: nop
    
            goto L_800C58BC;
    }
    // 0x800C58A4: nop

    // 0x800C58A8: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800C58AC: nop

    // 0x800C58B0: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800C58B4: bne         $at, $zero, L_800C5894
    if (ctx->r1 != 0) {
        // 0x800C58B8: nop
    
            goto L_800C5894;
    }
    // 0x800C58B8: nop

L_800C58BC:
    // 0x800C58BC: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800C58C0: sw          $v0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r2;
L_800C58C4:
    // 0x800C58C4: sb          $s0, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r16;
    // 0x800C58C8: lw          $t3, 0x154($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X154);
    // 0x800C58CC: nop

    // 0x800C58D0: sw          $t3, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r11;
    // 0x800C58D4: lw          $t4, 0x14C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X14C);
    // 0x800C58D8: nop

    // 0x800C58DC: sh          $t4, 0x8($a3)
    MEM_H(0X8, ctx->r7) = ctx->r12;
    // 0x800C58E0: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800C58E4: sh          $zero, 0xC($a3)
    MEM_H(0XC, ctx->r7) = 0;
    // 0x800C58E8: sh          $zero, 0xE($a3)
    MEM_H(0XE, ctx->r7) = 0;
    // 0x800C58EC: sh          $t6, 0xA($a3)
    MEM_H(0XA, ctx->r7) = ctx->r14;
    // 0x800C58F0: lbu         $t5, 0x14($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X14);
    // 0x800C58F4: nop

    // 0x800C58F8: sb          $t5, 0x10($a3)
    MEM_B(0X10, ctx->r7) = ctx->r13;
    // 0x800C58FC: lbu         $t7, 0x15($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X15);
    // 0x800C5900: nop

    // 0x800C5904: sb          $t7, 0x11($a3)
    MEM_B(0X11, ctx->r7) = ctx->r15;
    // 0x800C5908: lbu         $t8, 0x16($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X16);
    // 0x800C590C: nop

    // 0x800C5910: sb          $t8, 0x12($a3)
    MEM_B(0X12, ctx->r7) = ctx->r24;
    // 0x800C5914: lbu         $t9, 0x17($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X17);
    // 0x800C5918: nop

    // 0x800C591C: sb          $t9, 0x13($a3)
    MEM_B(0X13, ctx->r7) = ctx->r25;
    // 0x800C5920: lbu         $t2, 0x18($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X18);
    // 0x800C5924: nop

    // 0x800C5928: sb          $t2, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r10;
    // 0x800C592C: lbu         $t3, 0x19($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X19);
    // 0x800C5930: nop

    // 0x800C5934: sb          $t3, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r11;
    // 0x800C5938: lbu         $t4, 0x1A($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X1A);
    // 0x800C593C: nop

    // 0x800C5940: sb          $t4, 0x16($a3)
    MEM_B(0X16, ctx->r7) = ctx->r12;
    // 0x800C5944: lbu         $t6, 0x1B($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X1B);
    // 0x800C5948: nop

    // 0x800C594C: sb          $t6, 0x17($a3)
    MEM_B(0X17, ctx->r7) = ctx->r14;
    // 0x800C5950: lbu         $t5, 0x1C($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X1C);
    // 0x800C5954: nop

    // 0x800C5958: sb          $t5, 0x18($a3)
    MEM_B(0X18, ctx->r7) = ctx->r13;
    // 0x800C595C: lbu         $t7, 0x1D($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1D);
    // 0x800C5960: nop

    // 0x800C5964: sb          $t7, 0x19($a3)
    MEM_B(0X19, ctx->r7) = ctx->r15;
    // 0x800C5968: lhu         $t8, 0x1E($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X1E);
    // 0x800C596C: nop

    // 0x800C5970: sh          $t8, 0x1A($a3)
    MEM_H(0X1A, ctx->r7) = ctx->r24;
L_800C5974:
    // 0x800C5974: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800C5978:
    // 0x800C5978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C597C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C5980: jr          $ra
    // 0x800C5984: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800C5984: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void func_8006C300(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C540: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006C544: addiu       $a0, $a0, -0x2760
    ctx->r4 = ADD32(ctx->r4, -0X2760);
    // 0x8006C548: lb          $v1, 0x0($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X0);
    // 0x8006C54C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006C550: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8006C554: bne         $at, $zero, L_8006C564
    if (ctx->r1 != 0) {
        // 0x8006C558: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8006C564;
    }
    // 0x8006C558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006C55C: jr          $ra
    // 0x8006C560: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    return;
    // 0x8006C560: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8006C564:
    // 0x8006C564: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8006C568: jr          $ra
    // 0x8006C56C: nop

    return;
    // 0x8006C56C: nop

;}
RECOMP_FUNC void alEnvmixerParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CAFDC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CAFE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CAFE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CAFE8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CAFEC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800CAFF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CAFF4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800CAFF8: nop

    // 0x800CAFFC: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x800CB000: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800CB004: nop

    // 0x800CB008: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x800CB00C: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800CB010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CB014: beq         $s0, $at, L_800CB14C
    if (ctx->r16 == ctx->r1) {
        // 0x800CB018: nop
    
            goto L_800CB14C;
    }
    // 0x800CB018: nop

    // 0x800CB01C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800CB020: beq         $s0, $at, L_800CB048
    if (ctx->r16 == ctx->r1) {
        // 0x800CB024: nop
    
            goto L_800CB048;
    }
    // 0x800CB024: nop

    // 0x800CB028: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CB02C: beq         $s0, $at, L_800CB09C
    if (ctx->r16 == ctx->r1) {
        // 0x800CB030: nop
    
            goto L_800CB09C;
    }
    // 0x800CB030: nop

    // 0x800CB034: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800CB038: beq         $s0, $at, L_800CB100
    if (ctx->r16 == ctx->r1) {
        // 0x800CB03C: nop
    
            goto L_800CB100;
    }
    // 0x800CB03C: nop

    // 0x800CB040: b           L_800CB164
    // 0x800CB044: nop

        goto L_800CB164;
    // 0x800CB044: nop

L_800CB048:
    // 0x800CB048: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CB04C: nop

    // 0x800CB050: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x800CB054: nop

    // 0x800CB058: beq         $t9, $zero, L_800CB074
    if (ctx->r25 == 0) {
        // 0x800CB05C: nop
    
            goto L_800CB074;
    }
    // 0x800CB05C: nop

    // 0x800CB060: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CB064: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CB068: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x800CB06C: b           L_800CB084
    // 0x800CB070: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
        goto L_800CB084;
    // 0x800CB070: sw          $t0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r8;
L_800CB074:
    // 0x800CB074: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CB078: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x800CB07C: nop

    // 0x800CB080: sw          $t3, 0x3C($t4)
    MEM_W(0X3C, ctx->r12) = ctx->r11;
L_800CB084:
    // 0x800CB084: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x800CB088: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800CB08C: nop

    // 0x800CB090: sw          $t5, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r13;
    // 0x800CB094: b           L_800CB19C
    // 0x800CB098: nop

        goto L_800CB19C;
    // 0x800CB098: nop

L_800CB09C:
    // 0x800CB09C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0A0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CB0A4: sw          $t7, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->r15;
    // 0x800CB0A8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0AC: nop

    // 0x800CB0B0: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
    // 0x800CB0B4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800CB0B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CB0BC: sh          $t1, 0x1A($t0)
    MEM_H(0X1A, ctx->r8) = ctx->r9;
    // 0x800CB0C0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB0C4: nop

    // 0x800CB0C8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800CB0CC: nop

    // 0x800CB0D0: beq         $t3, $zero, L_800CB0F8
    if (ctx->r11 == 0) {
        // 0x800CB0D4: nop
    
            goto L_800CB0F8;
    }
    // 0x800CB0D4: nop

    // 0x800CB0D8: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB0DC: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB0E0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800CB0E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CB0E8: lw          $t9, 0x8($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X8);
    // 0x800CB0EC: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    // 0x800CB0F0: jalr        $t9
    // 0x800CB0F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CB0F4: nop

    after_0:
L_800CB0F8:
    // 0x800CB0F8: b           L_800CB19C
    // 0x800CB0FC: nop

        goto L_800CB19C;
    // 0x800CB0FC: nop

L_800CB100:
    // 0x800CB100: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800CB104: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CB108: sw          $t6, 0x48($t7)
    MEM_W(0X48, ctx->r15) = ctx->r14;
    // 0x800CB10C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB110: nop

    // 0x800CB114: lw          $t1, 0x0($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X0);
    // 0x800CB118: nop

    // 0x800CB11C: beq         $t1, $zero, L_800CB144
    if (ctx->r9 == 0) {
        // 0x800CB120: nop
    
            goto L_800CB144;
    }
    // 0x800CB120: nop

    // 0x800CB124: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB128: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB12C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800CB130: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CB134: lw          $t9, 0x8($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X8);
    // 0x800CB138: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    // 0x800CB13C: jalr        $t9
    // 0x800CB140: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CB140: nop

    after_1:
L_800CB144:
    // 0x800CB144: b           L_800CB19C
    // 0x800CB148: nop

        goto L_800CB19C;
    // 0x800CB148: nop

L_800CB14C:
    // 0x800CB14C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800CB150: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB154: nop

    // 0x800CB158: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800CB15C: b           L_800CB19C
    // 0x800CB160: nop

        goto L_800CB19C;
    // 0x800CB160: nop

L_800CB164:
    // 0x800CB164: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB168: nop

    // 0x800CB16C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800CB170: nop

    // 0x800CB174: beq         $t6, $zero, L_800CB19C
    if (ctx->r14 == 0) {
        // 0x800CB178: nop
    
            goto L_800CB19C;
    }
    // 0x800CB178: nop

    // 0x800CB17C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800CB180: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CB184: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800CB188: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800CB18C: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x800CB190: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800CB194: jalr        $t9
    // 0x800CB198: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CB198: nop

    after_2:
L_800CB19C:
    // 0x800CB19C: b           L_800CB1AC
    // 0x800CB1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800CB1AC;
    // 0x800CB1A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CB1A4: b           L_800CB1AC
    // 0x800CB1A8: nop

        goto L_800CB1AC;
    // 0x800CB1A8: nop

L_800CB1AC:
    // 0x800CB1AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB1B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CB1B4: jr          $ra
    // 0x800CB1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800CB1B8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void menu_boot_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80088A84: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80088A88: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80088A8C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80088A90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80088A94: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80088A98: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80088A9C: bne         $t6, $zero, L_80088AA8
    if (ctx->r14 != 0) {
        // 0x80088AA0: addiu       $v1, $zero, 0x78
        ctx->r3 = ADD32(0, 0X78);
            goto L_80088AA8;
    }
    // 0x80088AA0: addiu       $v1, $zero, 0x78
    ctx->r3 = ADD32(0, 0X78);
    // 0x80088AA4: addiu       $v1, $zero, 0x84
    ctx->r3 = ADD32(0, 0X84);
L_80088AA8:
    // 0x80088AA8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088AAC: lw          $v0, 0x71E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71E0);
    // 0x80088AB0: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80088AB4: beq         $v0, $zero, L_80088ADC
    if (ctx->r2 == 0) {
        // 0x80088AB8: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088ADC;
    }
    // 0x80088AB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088ABC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80088AC0: beq         $v0, $at, L_80088B28
    if (ctx->r2 == ctx->r1) {
        // 0x80088AC4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80088B28;
    }
    // 0x80088AC4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80088AC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80088ACC: beq         $v0, $at, L_80088B90
    if (ctx->r2 == ctx->r1) {
        // 0x80088AD0: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_80088B90;
    }
    // 0x80088AD0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80088AD4: b           L_80088BE4
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
        goto L_80088BE4;
    // 0x80088AD8: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088ADC:
    // 0x80088ADC: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088AE0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088AE4: nop

    // 0x80088AE8: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80088AEC: beq         $at, $zero, L_80088B0C
    if (ctx->r1 == 0) {
        // 0x80088AF0: addu        $t7, $v0, $a1
        ctx->r15 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B0C;
    }
    // 0x80088AF0: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x80088AF4: slti        $at, $t7, 0x21
    ctx->r1 = SIGNED(ctx->r15) < 0X21 ? 1 : 0;
    // 0x80088AF8: bne         $at, $zero, L_80088BE0
    if (ctx->r1 != 0) {
        // 0x80088AFC: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80088BE0;
    }
    // 0x80088AFC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80088B00: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80088B04: b           L_80088BE0
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80088BE0;
    // 0x80088B08: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80088B0C:
    // 0x80088B0C: jal         0x80088C60
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_init_cpak(rdram, ctx);
        goto after_0;
    // 0x80088B10: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_0:
    // 0x80088B14: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B18: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80088B1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B20: b           L_80088BE0
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
        goto L_80088BE0;
    // 0x80088B24: sw          $t0, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r8;
L_80088B28:
    // 0x80088B28: addiu       $v1, $v1, 0x71D8
    ctx->r3 = ADD32(ctx->r3, 0X71D8);
    // 0x80088B2C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80088B30: nop

    // 0x80088B34: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x80088B38: beq         $at, $zero, L_80088B5C
    if (ctx->r1 == 0) {
        // 0x80088B3C: addu        $t1, $v0, $a1
        ctx->r9 = ADD32(ctx->r2, ctx->r5);
            goto L_80088B5C;
    }
    // 0x80088B3C: addu        $t1, $v0, $a1
    ctx->r9 = ADD32(ctx->r2, ctx->r5);
    // 0x80088B40: slti        $at, $t1, 0x8D
    ctx->r1 = SIGNED(ctx->r9) < 0X8D ? 1 : 0;
    // 0x80088B44: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80088B48: bne         $at, $zero, L_80088B7C
    if (ctx->r1 != 0) {
        // 0x80088B4C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80088B7C;
    }
    // 0x80088B4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80088B50: addiu       $v0, $zero, 0x8C
    ctx->r2 = ADD32(0, 0X8C);
    // 0x80088B54: b           L_80088B7C
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_80088B7C;
    // 0x80088B58: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80088B5C:
    // 0x80088B5C: jal         0x80088C3C
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    bootscreen_free(rdram, ctx);
        goto after_1;
    // 0x80088B60: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x80088B64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80088B68: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80088B6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80088B70: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088B74: lw          $v0, 0x71D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X71D8);
    // 0x80088B78: sw          $t3, 0x71E0($at)
    MEM_W(0X71E0, ctx->r1) = ctx->r11;
L_80088B7C:
    // 0x80088B7C: slti        $at, $v0, 0x81
    ctx->r1 = SIGNED(ctx->r2) < 0X81 ? 1 : 0;
    // 0x80088B80: bne         $at, $zero, L_80088BE4
    if (ctx->r1 != 0) {
        // 0x80088B84: slti        $at, $a3, 0x12C
        ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
            goto L_80088BE4;
    }
    // 0x80088B84: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
    // 0x80088B88: b           L_80088BE0
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
        goto L_80088BE0;
    // 0x80088B8C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088B90:
    // 0x80088B90: lw          $t4, -0x604($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X604);
    // 0x80088B94: nop

    // 0x80088B98: beq         $t4, $zero, L_80088BCC
    if (ctx->r12 == 0) {
        // 0x80088B9C: addiu       $a3, $zero, 0x12C
        ctx->r7 = ADD32(0, 0X12C);
            goto L_80088BCC;
    }
    // 0x80088B9C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    // 0x80088BA0: jal         0x800C06AC
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    check_fadeout_transition(rdram, ctx);
        goto after_2;
    // 0x80088BA4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_2:
    // 0x80088BA8: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BAC: bne         $v0, $zero, L_80088BC8
    if (ctx->r2 != 0) {
        // 0x80088BB0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80088BC8;
    }
    // 0x80088BB0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80088BB4: addiu       $a0, $a0, -0x314
    ctx->r4 = ADD32(ctx->r4, -0X314);
    // 0x80088BB8: jal         0x800C06F8
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80088BBC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_3:
    // 0x80088BC0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80088BC4: nop

L_80088BC8:
    // 0x80088BC8: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
L_80088BCC:
    // 0x80088BCC: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80088BD0: jal         0x80089540
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    menu_controller_pak_loop(rdram, ctx);
        goto after_4;
    // 0x80088BD4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80088BD8: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80088BDC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
L_80088BE0:
    // 0x80088BE0: slti        $at, $a3, 0x12C
    ctx->r1 = SIGNED(ctx->r7) < 0X12C ? 1 : 0;
L_80088BE4:
    // 0x80088BE4: beq         $at, $zero, L_80088C2C
    if (ctx->r1 == 0) {
        // 0x80088BE8: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80088C2C;
    }
    // 0x80088BE8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088BEC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80088BF0: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x80088BF4: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80088BF8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80088BFC: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80088C00: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80088C04: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x80088C08: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80088C0C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80088C10: addiu       $a1, $a1, -0x2A4
    ctx->r5 = ADD32(ctx->r5, -0X2A4);
    // 0x80088C14: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    // 0x80088C18: jal         0x80078F08
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    texrect_draw(rdram, ctx);
        goto after_5;
    // 0x80088C1C: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    after_5:
    // 0x80088C20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80088C24: jal         0x8007B820
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x80088C28: addiu       $a0, $a0, 0x693C
    ctx->r4 = ADD32(ctx->r4, 0X693C);
    after_6:
L_80088C2C:
    // 0x80088C2C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80088C30: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80088C34: jr          $ra
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80088C38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8000E79C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E79C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000E7A0: lw          $a2, -0x4BC0($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4BC0);
    // 0x8000E7A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000E7A8: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8000E7AC: addiu       $t8, $t8, -0x4BE0
    ctx->r24 = ADD32(ctx->r24, -0X4BE0);
    // 0x8000E7B0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000E7B4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8000E7B8: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8000E7BC: addu        $t5, $t5, $t0
    ctx->r13 = ADD32(ctx->r13, ctx->r8);
    // 0x8000E7C0: addu        $t1, $t0, $t8
    ctx->r9 = ADD32(ctx->r8, ctx->r24);
    // 0x8000E7C4: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8000E7C8: lw          $t5, -0x4BD0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4BD0);
    // 0x8000E7CC: andi        $t6, $v0, 0x3F
    ctx->r14 = ctx->r2 & 0X3F;
    // 0x8000E7D0: andi        $t7, $v1, 0x3F
    ctx->r15 = ctx->r3 & 0X3F;
    // 0x8000E7D4: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000E7D8: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x8000E7DC: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000E7E0: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x8000E7E4: beq         $at, $zero, L_8000E820
    if (ctx->r1 == 0) {
        // 0x8000E7E8: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8000E820;
    }
    // 0x8000E7E8: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8000E7EC: addu        $t0, $a0, $t6
    ctx->r8 = ADD32(ctx->r4, ctx->r14);
    // 0x8000E7F0: sltu        $at, $t0, $a3
    ctx->r1 = ctx->r8 < ctx->r7 ? 1 : 0;
    // 0x8000E7F4: addu        $a2, $a0, $t7
    ctx->r6 = ADD32(ctx->r4, ctx->r15);
    // 0x8000E7F8: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E7FC: or          $t2, $a3, $zero
        ctx->r10 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E7FC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_8000E800:
    // 0x8000E800: lbu         $t6, 0x0($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E804: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E808: sltu        $at, $t0, $t2
    ctx->r1 = ctx->r8 < ctx->r10 ? 1 : 0;
    // 0x8000E80C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E810: bne         $at, $zero, L_8000E800
    if (ctx->r1 != 0) {
        // 0x8000E814: sb          $t6, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r14;
            goto L_8000E800;
    }
    // 0x8000E814: sb          $t6, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r14;
    // 0x8000E818: b           L_8000E85C
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_8000E85C;
    // 0x8000E81C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E820:
    // 0x8000E820: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E824: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E828: addu        $t7, $a3, $v1
        ctx->r15 = ADD32(ctx->r7, ctx->r3);
            goto L_8000E858;
    }
    // 0x8000E828: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x8000E82C: subu        $a2, $t7, $v0
    ctx->r6 = SUB32(ctx->r15, ctx->r2);
    // 0x8000E830: addu        $t2, $a0, $v1
    ctx->r10 = ADD32(ctx->r4, ctx->r3);
    // 0x8000E834: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E838: beq         $at, $zero, L_8000E858
    if (ctx->r1 == 0) {
        // 0x8000E83C: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_8000E858;
    }
    // 0x8000E83C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
L_8000E840:
    // 0x8000E840: lbu         $t8, -0x1($t0)
    ctx->r24 = MEM_BU(ctx->r8, -0X1);
    // 0x8000E844: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8000E848: sltu        $at, $t2, $a2
    ctx->r1 = ctx->r10 < ctx->r6 ? 1 : 0;
    // 0x8000E84C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8000E850: bne         $at, $zero, L_8000E840
    if (ctx->r1 != 0) {
        // 0x8000E854: sb          $t8, 0x0($a2)
        MEM_B(0X0, ctx->r6) = ctx->r24;
            goto L_8000E840;
    }
    // 0x8000E854: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
L_8000E858:
    // 0x8000E858: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8000E85C:
    // 0x8000E85C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000E860: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
L_8000E864:
    // 0x8000E864: lbu         $t9, 0x0($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X0);
    // 0x8000E868: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000E86C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000E870: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8000E874: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000E878: bne         $at, $zero, L_8000E864
    if (ctx->r1 != 0) {
        // 0x8000E87C: sb          $t9, -0x1($a3)
        MEM_B(-0X1, ctx->r7) = ctx->r25;
            goto L_8000E864;
    }
    // 0x8000E87C: sb          $t9, -0x1($a3)
    MEM_B(-0X1, ctx->r7) = ctx->r25;
    // 0x8000E880: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x8000E884: nop

    // 0x8000E888: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x8000E88C: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x8000E890: jr          $ra
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    return;
    // 0x8000E894: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
;}
RECOMP_FUNC void texrect_draw_scaled(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079150: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80079154: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80079158: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007915C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079160: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80079164: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80079168: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8007916C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80079170: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80079174: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80079178: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8007917C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80079180: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80079184: sw          $a2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r6;
    // 0x80079188: jal         0x8007A970
    // 0x8007918C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x8007918C: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    after_0:
    // 0x80079190: lw          $t1, 0xC8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XC8);
    // 0x80079194: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80079198: andi        $t6, $t1, 0xFF
    ctx->r14 = ctx->r9 & 0XFF;
    // 0x8007919C: bne         $t6, $at, L_800791C4
    if (ctx->r14 != ctx->r1) {
        // 0x800791A0: lw          $t0, 0xCC($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XCC);
            goto L_800791C4;
    }
    // 0x800791A0: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800791A4: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x800791A8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800791AC: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800791B0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800791B4: addiu       $t6, $t6, -0x13D8
    ctx->r14 = ADD32(ctx->r14, -0X13D8);
    // 0x800791B8: b           L_800791D8
    // 0x800791BC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
        goto L_800791D8;
    // 0x800791BC: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
    // 0x800791C0: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
L_800791C4:
    // 0x800791C4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800791C8: andi        $t8, $t0, 0xFF
    ctx->r24 = ctx->r8 & 0XFF;
    // 0x800791CC: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800791D0: addiu       $t6, $t6, -0x1398
    ctx->r14 = ADD32(ctx->r14, -0X1398);
    // 0x800791D4: addu        $a3, $t9, $t6
    ctx->r7 = ADD32(ctx->r25, ctx->r14);
L_800791D8:
    // 0x800791D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800791DC: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800791E0: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x800791E4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800791E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800791EC: addiu       $t9, $t9, -0x1410
    ctx->r25 = ADD32(ctx->r25, -0X1410);
    // 0x800791F0: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800791F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800791F8: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800791FC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80079200: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079204: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80079208: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x8007920C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80079210: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079214: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x80079218: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007921C: addu        $t8, $a3, $at
    ctx->r24 = ADD32(ctx->r7, ctx->r1);
    // 0x80079220: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80079224: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80079228: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x8007922C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80079230: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x80079234: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079238: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007923C: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x80079240: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80079244: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x80079248: lw          $ra, 0x0($s2)
    ctx->r31 = MEM_W(ctx->r18, 0X0);
    // 0x8007924C: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x80079250: beq         $ra, $zero, L_80079730
    if (ctx->r31 == 0) {
        // 0x80079254: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_80079730;
    }
    // 0x80079254: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80079258: lwc1        $f4, 0xB8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8007925C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079260: lwc1        $f16, 0xBC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x80079264: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80079268: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8007926C: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80079270: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80079274: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80079278: lw          $s2, 0x80($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X80);
    // 0x8007927C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80079280: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079284: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079288: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8007928C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079290: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80079294: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80079298: mfc1        $s7, $f10
    ctx->r23 = (int32_t)ctx->f10.u32l;
    // 0x8007929C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800792A0: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800792A4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800792A8: andi        $s5, $t0, 0x1000
    ctx->r21 = ctx->r8 & 0X1000;
    // 0x800792AC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800792B0: andi        $s6, $t0, 0x2000
    ctx->r22 = ctx->r8 & 0X2000;
    // 0x800792B4: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800792B8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800792BC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800792C0: nop

    // 0x800792C4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800792C8: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800792CC: mfc1        $fp, $f6
    ctx->r30 = (int32_t)ctx->f6.u32l;
    // 0x800792D0: nop

L_800792D4:
    // 0x800792D4: bne         $s5, $zero, L_80079320
    if (ctx->r21 != 0) {
        // 0x800792D8: nop
    
            goto L_80079320;
    }
    // 0x800792D8: nop

    // 0x800792DC: lh          $t7, 0x4($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X4);
    // 0x800792E0: nop

    // 0x800792E4: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800792E8: nop

    // 0x800792EC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800792F0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800792F4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800792F8: nop

    // 0x800792FC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80079300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079308: nop

    // 0x8007930C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80079310: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x80079314: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80079318: b           L_800793A4
    // 0x8007931C: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
        goto L_800793A4;
    // 0x8007931C: addu        $t3, $t9, $s7
    ctx->r11 = ADD32(ctx->r25, ctx->r23);
L_80079320:
    // 0x80079320: lh          $t6, 0x4($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X4);
    // 0x80079324: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x80079328: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8007932C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80079330: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079334: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80079338: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007933C: nop

    // 0x80079340: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80079344: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079348: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007934C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079350: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079354: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80079358: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007935C: subu        $s2, $s7, $t8
    ctx->r18 = SUB32(ctx->r23, ctx->r24);
    // 0x80079360: bgez        $t9, L_80079374
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80079364: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80079374;
    }
    // 0x80079364: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80079368: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8007936C: nop

    // 0x80079370: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80079374:
    // 0x80079374: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80079378: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8007937C: nop

    // 0x80079380: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80079384: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079388: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007938C: nop

    // 0x80079390: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80079394: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x80079398: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8007939C: subu        $t3, $s2, $t7
    ctx->r11 = SUB32(ctx->r18, ctx->r15);
    // 0x800793A0: nop

L_800793A4:
    // 0x800793A4: bne         $s6, $zero, L_800793F0
    if (ctx->r22 != 0) {
        // 0x800793A8: nop
    
            goto L_800793F0;
    }
    // 0x800793A8: nop

    // 0x800793AC: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x800793B0: nop

    // 0x800793B4: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800793B8: nop

    // 0x800793BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800793C0: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800793C4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800793C8: nop

    // 0x800793CC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800793D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800793D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800793D8: nop

    // 0x800793DC: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800793E0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800793E4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800793E8: b           L_80079474
    // 0x800793EC: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
        goto L_80079474;
    // 0x800793EC: addu        $t2, $t6, $fp
    ctx->r10 = ADD32(ctx->r14, ctx->r30);
L_800793F0:
    // 0x800793F0: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x800793F4: lbu         $t6, 0x1($ra)
    ctx->r14 = MEM_BU(ctx->r31, 0X1);
    // 0x800793F8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800793FC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80079400: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80079404: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80079408: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8007940C: nop

    // 0x80079410: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80079414: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079418: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007941C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079420: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80079424: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80079428: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8007942C: subu        $s3, $fp, $t9
    ctx->r19 = SUB32(ctx->r30, ctx->r25);
    // 0x80079430: bgez        $t6, L_80079444
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80079434: cvt.s.w     $f18, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80079444;
    }
    // 0x80079434: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80079438: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8007943C: nop

    // 0x80079440: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
L_80079444:
    // 0x80079444: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80079448: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8007944C: nop

    // 0x80079450: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80079454: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80079458: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8007945C: nop

    // 0x80079460: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80079464: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80079468: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8007946C: subu        $t2, $s3, $t8
    ctx->r10 = SUB32(ctx->r19, ctx->r24);
    // 0x80079470: nop

L_80079474:
    // 0x80079474: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80079478: sra         $t6, $v0, 16
    ctx->r14 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007947C: slt         $at, $t3, $t9
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80079480: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079484: andi        $t7, $t6, 0xFFFF
        ctx->r15 = ctx->r14 & 0XFFFF;
            goto L_80079718;
    }
    // 0x80079484: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80079488: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007948C: slt         $at, $t2, $t8
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80079490: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079494: nop
    
            goto L_80079718;
    }
    // 0x80079494: nop

    // 0x80079498: bne         $s5, $zero, L_800794F0
    if (ctx->r21 != 0) {
        // 0x8007949C: nop
    
            goto L_800794F0;
    }
    // 0x8007949C: nop

    // 0x800794A0: lbu         $t9, 0x0($ra)
    ctx->r25 = MEM_BU(ctx->r31, 0X0);
    // 0x800794A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800794A8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800794AC: bgez        $t9, L_800794C0
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800794B0: cvt.s.w     $f4, $f16
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800794C0;
    }
    // 0x800794B0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800794B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800794B8: nop

    // 0x800794BC: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800794C0:
    // 0x800794C0: mul.s       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800794C4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800794C8: nop

    // 0x800794CC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800794D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800794D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800794D8: nop

    // 0x800794DC: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800794E0: mfc1        $t7, $f8
    ctx->r15 = (int32_t)ctx->f8.u32l;
    // 0x800794E4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800794E8: addu        $s2, $t7, $t3
    ctx->r18 = ADD32(ctx->r15, ctx->r11);
    // 0x800794EC: nop

L_800794F0:
    // 0x800794F0: bne         $s6, $zero, L_80079548
    if (ctx->r22 != 0) {
        // 0x800794F4: nop
    
            goto L_80079548;
    }
    // 0x800794F4: nop

    // 0x800794F8: lbu         $t8, 0x1($ra)
    ctx->r24 = MEM_BU(ctx->r31, 0X1);
    // 0x800794FC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80079500: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80079504: bgez        $t8, L_80079518
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80079508: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80079518;
    }
    // 0x80079508: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8007950C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80079510: nop

    // 0x80079514: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_80079518:
    // 0x80079518: mul.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8007951C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80079520: nop

    // 0x80079524: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80079528: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8007952C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80079530: nop

    // 0x80079534: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80079538: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8007953C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80079540: addu        $s3, $t6, $t2
    ctx->r19 = ADD32(ctx->r14, ctx->r10);
    // 0x80079544: nop

L_80079548:
    // 0x80079548: blez        $s2, L_80079718
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8007954C: nop
    
            goto L_80079718;
    }
    // 0x8007954C: nop

    // 0x80079550: blez        $s3, L_80079718
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80079554: slt         $at, $t3, $s2
        ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80079718;
    }
    // 0x80079554: slt         $at, $t3, $s2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80079558: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x8007955C: slt         $at, $t2, $s3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_80079718;
    }
    // 0x8007955C: slt         $at, $t2, $s3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80079560: beq         $at, $zero, L_80079718
    if (ctx->r1 == 0) {
        // 0x80079564: nop
    
            goto L_80079718;
    }
    // 0x80079564: nop

    // 0x80079568: lbu         $v1, 0x0($ra)
    ctx->r3 = MEM_BU(ctx->r31, 0X0);
    // 0x8007956C: subu        $t8, $s2, $t3
    ctx->r24 = SUB32(ctx->r18, ctx->r11);
    // 0x80079570: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80079574: sll         $t7, $v1, 12
    ctx->r15 = S32(ctx->r3 << 12);
    // 0x80079578: div         $zero, $t7, $t8
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r24))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r24)));
    // 0x8007957C: andi        $t9, $s2, 0xFFF
    ctx->r25 = ctx->r18 & 0XFFF;
    // 0x80079580: bne         $t8, $zero, L_8007958C
    if (ctx->r24 != 0) {
        // 0x80079584: nop
    
            goto L_8007958C;
    }
    // 0x80079584: nop

    // 0x80079588: break       7
    do_break(2147980680);
L_8007958C:
    // 0x8007958C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079590: bne         $t8, $at, L_800795A4
    if (ctx->r24 != ctx->r1) {
        // 0x80079594: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800795A4;
    }
    // 0x80079594: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079598: bne         $t7, $at, L_800795A4
    if (ctx->r15 != ctx->r1) {
        // 0x8007959C: nop
    
            goto L_800795A4;
    }
    // 0x8007959C: nop

    // 0x800795A0: break       6
    do_break(2147980704);
L_800795A4:
    // 0x800795A4: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x800795A8: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800795AC: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800795B0: andi        $t8, $s3, 0xFFF
    ctx->r24 = ctx->r19 & 0XFFF;
    // 0x800795B4: or          $s4, $t7, $t8
    ctx->r20 = ctx->r15 | ctx->r24;
    // 0x800795B8: lbu         $a0, 0x1($ra)
    ctx->r4 = MEM_BU(ctx->r31, 0X1);
    // 0x800795BC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800795C0: subu        $t6, $s3, $t2
    ctx->r14 = SUB32(ctx->r19, ctx->r10);
    // 0x800795C4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800795C8: negu        $t7, $t3
    ctx->r15 = SUB32(0, ctx->r11);
    // 0x800795CC: mflo        $t4
    ctx->r12 = lo;
    // 0x800795D0: beq         $s5, $zero, L_800795E4
    if (ctx->r21 == 0) {
        // 0x800795D4: nop
    
            goto L_800795E4;
    }
    // 0x800795D4: nop

    // 0x800795D8: sll         $t5, $v1, 5
    ctx->r13 = S32(ctx->r3 << 5);
    // 0x800795DC: b           L_800795E4
    // 0x800795E0: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
        goto L_800795E4;
    // 0x800795E0: negu        $t4, $t4
    ctx->r12 = SUB32(0, ctx->r12);
L_800795E4:
    // 0x800795E4: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800795E8: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x800795EC: div         $zero, $t9, $t6
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r14)));
    // 0x800795F0: bne         $t6, $zero, L_800795FC
    if (ctx->r14 != 0) {
        // 0x800795F4: nop
    
            goto L_800795FC;
    }
    // 0x800795F4: nop

    // 0x800795F8: break       7
    do_break(2147980792);
L_800795FC:
    // 0x800795FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079600: bne         $t6, $at, L_80079614
    if (ctx->r14 != ctx->r1) {
        // 0x80079604: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079614;
    }
    // 0x80079604: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079608: bne         $t9, $at, L_80079614
    if (ctx->r25 != ctx->r1) {
        // 0x8007960C: nop
    
            goto L_80079614;
    }
    // 0x8007960C: nop

    // 0x80079610: break       6
    do_break(2147980816);
L_80079614:
    // 0x80079614: negu        $t6, $t2
    ctx->r14 = SUB32(0, ctx->r10);
    // 0x80079618: mflo        $a3
    ctx->r7 = lo;
    // 0x8007961C: beq         $s6, $zero, L_80079630
    if (ctx->r22 == 0) {
        // 0x80079620: nop
    
            goto L_80079630;
    }
    // 0x80079620: nop

    // 0x80079624: sll         $t0, $v1, 5
    ctx->r8 = S32(ctx->r3 << 5);
    // 0x80079628: b           L_80079630
    // 0x8007962C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
        goto L_80079630;
    // 0x8007962C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
L_80079630:
    // 0x80079630: bgez        $t3, L_8007964C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80079634: nop
    
            goto L_8007964C;
    }
    // 0x80079634: nop

    // 0x80079638: multu       $t7, $t4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007963C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80079640: mflo        $t8
    ctx->r24 = lo;
    // 0x80079644: sra         $t9, $t8, 7
    ctx->r25 = S32(SIGNED(ctx->r24) >> 7);
    // 0x80079648: addu        $t5, $t5, $t9
    ctx->r13 = ADD32(ctx->r13, ctx->r25);
L_8007964C:
    // 0x8007964C: bgez        $t2, L_80079668
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80079650: nop
    
            goto L_80079668;
    }
    // 0x80079650: nop

    // 0x80079654: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80079658: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8007965C: mflo        $t7
    ctx->r15 = lo;
    // 0x80079660: sra         $t8, $t7, 7
    ctx->r24 = S32(SIGNED(ctx->r15) >> 7);
    // 0x80079664: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
L_80079668:
    // 0x80079668: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007966C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80079670: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80079674: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80079678: lh          $a1, 0xA($ra)
    ctx->r5 = MEM_H(ctx->r31, 0XA);
    // 0x8007967C: nop

    // 0x80079680: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80079684: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80079688: sll         $t9, $a1, 3
    ctx->r25 = S32(ctx->r5 << 3);
    // 0x8007968C: andi        $t6, $t9, 0xFFFF
    ctx->r14 = ctx->r25 & 0XFFFF;
    // 0x80079690: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80079694: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80079698: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007969C: lw          $t9, 0xC($ra)
    ctx->r25 = MEM_W(ctx->r31, 0XC);
    // 0x800796A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800796A4: addu        $t8, $t9, $at
    ctx->r24 = ADD32(ctx->r25, ctx->r1);
    // 0x800796A8: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800796AC: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x800796B0: andi        $t7, $t3, 0xFFF
    ctx->r15 = ctx->r11 & 0XFFF;
    // 0x800796B4: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800796B8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800796BC: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800796C0: andi        $t8, $t2, 0xFFF
    ctx->r24 = ctx->r10 & 0XFFF;
    // 0x800796C4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800796C8: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800796CC: sw          $s4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r20;
    // 0x800796D0: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800796D4: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x800796D8: addiu       $t7, $t1, 0x8
    ctx->r15 = ADD32(ctx->r9, 0X8);
    // 0x800796DC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800796E0: andi        $t7, $t0, 0xFFFF
    ctx->r15 = ctx->r8 & 0XFFFF;
    // 0x800796E4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800796E8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x800796EC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800796F0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x800796F4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800796F8: lui         $t6, 0xB200
    ctx->r14 = S32(0XB200 << 16);
    // 0x800796FC: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80079700: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079704: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x80079708: sll         $t9, $t4, 16
    ctx->r25 = S32(ctx->r12 << 16);
    // 0x8007970C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80079710: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80079714: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
L_80079718:
    // 0x80079718: lw          $ra, 0x8($s1)
    ctx->r31 = MEM_W(ctx->r17, 0X8);
    // 0x8007971C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80079720: bne         $ra, $zero, L_800792D4
    if (ctx->r31 != 0) {
        // 0x80079724: nop
    
            goto L_800792D4;
    }
    // 0x80079724: nop

    // 0x80079728: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8007972C: sw          $s2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r18;
L_80079730:
    // 0x80079730: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80079734: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80079738: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8007973C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80079740: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80079744: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80079748: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007974C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80079750: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80079754: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80079758: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8007975C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80079760: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80079764: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80079768: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8007976C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80079770: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80079774: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80079778: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8007977C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80079780: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079784: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80079788: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8007978C: jr          $ra
    // 0x80079790: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x80079790: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void block_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A2DC: bltz        $a0, L_8002A300
    if (SIGNED(ctx->r4) < 0) {
        // 0x8002A2E0: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8002A300;
    }
    // 0x8002A2E0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8002A2E4: lw          $v1, -0x3178($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3178);
    // 0x8002A2E8: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x8002A2EC: lh          $t6, 0x1A($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X1A);
    // 0x8002A2F0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8002A2F4: slt         $at, $t6, $a0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A2F8: beq         $at, $zero, L_8002A308
    if (ctx->r1 == 0) {
        // 0x8002A2FC: nop
    
            goto L_8002A308;
    }
    // 0x8002A2FC: nop

L_8002A300:
    // 0x8002A300: jr          $ra
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A304: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A308:
    // 0x8002A308: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x8002A30C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002A310: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002A314: jr          $ra
    // 0x8002A318: nop

    return;
    // 0x8002A318: nop

;}
RECOMP_FUNC void obj_butterfly_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016C9C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80016CA0: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80016CA4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016CA8: addiu       $s6, $s6, -0x4C24
    ctx->r22 = ADD32(ctx->r22, -0X4C24);
    // 0x80016CAC: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x80016CB0: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80016CB4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80016CB8: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016CBC: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016CC0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80016CC4: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016CC8: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80016CCC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016CD0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80016CD4: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016CD8: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016CDC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016CE0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80016CE4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80016CE8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80016CEC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80016CF0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80016CF4: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016CF8: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016CFC: blez        $t6, L_80016DD0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80016D00: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016DD0;
    }
    // 0x80016D00: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016D04: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80016D08: lw          $s3, 0x68($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X68);
    // 0x80016D0C: addiu       $s4, $s4, -0x4C28
    ctx->r20 = ADD32(ctx->r20, -0X4C28);
    // 0x80016D10: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016D14: addiu       $s5, $zero, 0x55
    ctx->r21 = ADD32(0, 0X55);
L_80016D18:
    // 0x80016D18: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80016D1C: nop

    // 0x80016D20: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x80016D24: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x80016D28: nop

    // 0x80016D2C: lh          $t9, 0x6($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X6);
    // 0x80016D30: nop

    // 0x80016D34: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x80016D38: bne         $t0, $zero, L_80016DBC
    if (ctx->r8 != 0) {
        // 0x80016D3C: nop
    
            goto L_80016DBC;
    }
    // 0x80016D3C: nop

    // 0x80016D40: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
    // 0x80016D44: nop

    // 0x80016D48: bne         $s5, $t1, L_80016DBC
    if (ctx->r21 != ctx->r9) {
        // 0x80016D4C: nop
    
            goto L_80016DBC;
    }
    // 0x80016D4C: nop

    // 0x80016D50: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80016D54: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80016D58: sub.s       $f2, $f4, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016D5C: bne         $s3, $zero, L_80016D90
    if (ctx->r19 != 0) {
        // 0x80016D60: sub.s       $f14, $f6, $f22
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
            goto L_80016D90;
    }
    // 0x80016D60: sub.s       $f14, $f6, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016D64: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80016D68: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D6C: sub.s       $f0, $f8, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80016D70: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016D74: nop

    // 0x80016D78: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D7C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80016D80: jal         0x800CA030
    // 0x80016D84: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016D84: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_0:
    // 0x80016D88: b           L_80016DA8
    // 0x80016D8C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016DA8;
    // 0x80016D8C: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016D90:
    // 0x80016D90: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016D94: nop

    // 0x80016D98: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016D9C: jal         0x800CA030
    // 0x80016DA0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016DA0: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x80016DA4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016DA8:
    // 0x80016DA8: nop

    // 0x80016DAC: bc1f        L_80016DBC
    if (!c1cs) {
        // 0x80016DB0: nop
    
            goto L_80016DBC;
    }
    // 0x80016DB0: nop

    // 0x80016DB4: b           L_80016DD4
    // 0x80016DB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_80016DD4;
    // 0x80016DB8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80016DBC:
    // 0x80016DBC: lw          $t2, 0x0($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X0);
    // 0x80016DC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016DC4: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80016DC8: bne         $at, $zero, L_80016D18
    if (ctx->r1 != 0) {
        // 0x80016DCC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016D18;
    }
    // 0x80016DCC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016DD0:
    // 0x80016DD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80016DD4:
    // 0x80016DD4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80016DD8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80016DDC: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80016DE0: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80016DE4: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80016DE8: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80016DEC: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80016DF0: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80016DF4: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80016DF8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80016DFC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80016E00: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80016E04: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80016E08: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80016E0C: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80016E10: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x80016E14: jr          $ra
    // 0x80016E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80016E18: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void clear_game_progress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBD4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006EBD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EBDC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8006EBE0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006EBE4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8006EBE8: jal         0x8006B464
    // 0x8006EBEC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8006EBEC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8006EBF0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006EBF4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006EBF8: sb          $t6, 0x4B($a2)
    MEM_B(0X4B, ctx->r6) = ctx->r14;
    // 0x8006EBFC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8006EC00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006EC04: blez        $t7, L_8006EC34
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8006EC08: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8006EC34;
    }
    // 0x8006EC08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8006EC0C:
    // 0x8006EC0C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8006EC10: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006EC14: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8006EC18: sh          $zero, 0x0($t9)
    MEM_H(0X0, ctx->r25) = 0;
    // 0x8006EC1C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006EC20: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8006EC24: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8006EC28: bne         $at, $zero, L_8006EC0C
    if (ctx->r1 != 0) {
        // 0x8006EC2C: nop
    
            goto L_8006EC0C;
    }
    // 0x8006EC2C: nop

    // 0x8006EC30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006EC34:
    // 0x8006EC34: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EC38: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8006EC3C: blez        $t1, L_8006EC68
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8006EC40: nop
    
            goto L_8006EC68;
    }
    // 0x8006EC40: nop

L_8006EC44:
    // 0x8006EC44: lw          $t2, 0x4($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X4);
    // 0x8006EC48: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006EC4C: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8006EC50: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x8006EC54: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8006EC58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8006EC5C: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8006EC60: bne         $at, $zero, L_8006EC44
    if (ctx->r1 != 0) {
        // 0x8006EC64: nop
    
            goto L_8006EC44;
    }
    // 0x8006EC64: nop

L_8006EC68:
    // 0x8006EC68: sh          $zero, 0x8($a2)
    MEM_H(0X8, ctx->r6) = 0;
    // 0x8006EC6C: sh          $zero, 0xA($a2)
    MEM_H(0XA, ctx->r6) = 0;
    // 0x8006EC70: sh          $zero, 0xC($a2)
    MEM_H(0XC, ctx->r6) = 0;
    // 0x8006EC74: sh          $zero, 0xE($a2)
    MEM_H(0XE, ctx->r6) = 0;
    // 0x8006EC78: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    // 0x8006EC7C: sh          $zero, 0x14($a2)
    MEM_H(0X14, ctx->r6) = 0;
    // 0x8006EC80: sb          $zero, 0x16($a2)
    MEM_B(0X16, ctx->r6) = 0;
    // 0x8006EC84: sb          $zero, 0x17($a2)
    MEM_B(0X17, ctx->r6) = 0;
    // 0x8006EC88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EC8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8006EC90: jr          $ra
    // 0x8006EC94: nop

    return;
    // 0x8006EC94: nop

;}
RECOMP_FUNC void alEnvmixerPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA630: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800CA634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA638: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800CA63C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800CA640: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800CA644: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x800CA648: lw          $t6, 0x70($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X70);
    // 0x800CA64C: nop

    // 0x800CA650: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x800CA654: lw          $t7, 0x60($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X60);
    // 0x800CA658: nop

    // 0x800CA65C: sw          $t7, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r15;
    // 0x800CA660: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA664: nop

    // 0x800CA668: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800CA66C: sh          $zero, 0x46($sp)
    MEM_H(0X46, ctx->r29) = 0;
    // 0x800CA670: sh          $zero, 0x56($sp)
    MEM_H(0X56, ctx->r29) = 0;
    // 0x800CA674: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA678: nop

    // 0x800CA67C: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CA680: nop

    // 0x800CA684: beq         $t0, $zero, L_800CAF2C
    if (ctx->r8 == 0) {
        // 0x800CA688: nop
    
            goto L_800CAF2C;
    }
    // 0x800CA688: nop

L_800CA68C:
    // 0x800CA68C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA690: nop

    // 0x800CA694: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x800CA698: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA69C: nop

    // 0x800CA6A0: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA6A4: nop

    // 0x800CA6A8: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x800CA6AC: nop

    // 0x800CA6B0: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x800CA6B4: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800CA6B8: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x800CA6BC: nop

    // 0x800CA6C0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800CA6C4: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800CA6C8: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CA6CC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800CA6D0: nop

    // 0x800CA6D4: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800CA6D8: beq         $at, $zero, L_800CA6E8
    if (ctx->r1 == 0) {
        // 0x800CA6DC: nop
    
            goto L_800CA6E8;
    }
    // 0x800CA6DC: nop

    // 0x800CA6E0: b           L_800CAF2C
    // 0x800CA6E4: nop

        goto L_800CAF2C;
    // 0x800CA6E4: nop

L_800CA6E8:
    // 0x800CA6E8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CA6EC: nop

    // 0x800CA6F0: bltz        $t0, L_800CA700
    if (SIGNED(ctx->r8) < 0) {
        // 0x800CA6F4: nop
    
            goto L_800CA700;
    }
    // 0x800CA6F4: nop

    // 0x800CA6F8: b           L_800CA718
    // 0x800CA6FC: nop

        goto L_800CA718;
    // 0x800CA6FC: nop

L_800CA700:
    // 0x800CA700: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA704: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA708: addiu       $a1, $a1, -0x6510
    ctx->r5 = ADD32(ctx->r5, -0X6510);
    // 0x800CA70C: addiu       $a0, $a0, -0x6520
    ctx->r4 = ADD32(ctx->r4, -0X6520);
    // 0x800CA710: jal         0x800B74A0
    // 0x800CA714: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    __assert_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA714: addiu       $a2, $zero, 0x68
    ctx->r6 = ADD32(0, 0X68);
    after_0:
L_800CA718:
    // 0x800CA718: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800CA71C: nop

    // 0x800CA720: slti        $at, $t1, 0xA1
    ctx->r1 = SIGNED(ctx->r9) < 0XA1 ? 1 : 0;
    // 0x800CA724: beq         $at, $zero, L_800CA734
    if (ctx->r1 == 0) {
        // 0x800CA728: nop
    
            goto L_800CA734;
    }
    // 0x800CA728: nop

    // 0x800CA72C: b           L_800CA74C
    // 0x800CA730: nop

        goto L_800CA74C;
    // 0x800CA730: nop

L_800CA734:
    // 0x800CA734: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x800CA738: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800CA73C: addiu       $a1, $a1, -0x64E8
    ctx->r5 = ADD32(ctx->r5, -0X64E8);
    // 0x800CA740: addiu       $a0, $a0, -0x6508
    ctx->r4 = ADD32(ctx->r4, -0X6508);
    // 0x800CA744: jal         0x800B74A0
    // 0x800CA748: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    __assert_recomp(rdram, ctx);
        goto after_1;
    // 0x800CA748: addiu       $a2, $zero, 0x69
    ctx->r6 = ADD32(0, 0X69);
    after_1:
L_800CA74C:
    // 0x800CA74C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA750: nop

    // 0x800CA754: lw          $t3, 0x3C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X3C);
    // 0x800CA758: nop

    // 0x800CA75C: lhu         $t4, 0x8($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X8);
    // 0x800CA760: nop

    // 0x800CA764: sltiu       $at, $t4, 0x11
    ctx->r1 = ctx->r12 < 0X11 ? 1 : 0;
    // 0x800CA768: beq         $at, $zero, L_800CAE24
    if (ctx->r1 == 0) {
        // 0x800CA76C: nop
    
            goto L_800CAE24;
    }
    // 0x800CA76C: nop

    // 0x800CA770: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CA774: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CA778: addu        $at, $at, $t4
    gpr jr_addend_800CA784 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CA77C: lw          $t4, -0x64D0($at)
    ctx->r12 = ADD32(ctx->r1, -0X64D0);
    // 0x800CA780: nop

    // 0x800CA784: jr          $t4
    // 0x800CA788: nop

    switch (jr_addend_800CA784 >> 2) {
        case 0: goto L_800CADD0; break;
        case 1: goto L_800CAE24; break;
        case 2: goto L_800CAE24; break;
        case 3: goto L_800CAE24; break;
        case 4: goto L_800CAE24; break;
        case 5: goto L_800CAE24; break;
        case 6: goto L_800CAE24; break;
        case 7: goto L_800CAE24; break;
        case 8: goto L_800CAE24; break;
        case 9: goto L_800CAE24; break;
        case 10: goto L_800CAE24; break;
        case 11: goto L_800CA9C0; break;
        case 12: goto L_800CA9C0; break;
        case 13: goto L_800CA78C; break;
        case 14: goto L_800CAD08; break;
        case 15: goto L_800CAD88; break;
        case 16: goto L_800CA9C0; break;
        default: switch_error(__func__, 0x800CA784, 0x800E9B30);
    }
    // 0x800CA788: nop

L_800CA78C:
    // 0x800CA78C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA790: nop

    // 0x800CA794: lw          $t6, 0x3C($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X3C);
    // 0x800CA798: nop

    // 0x800CA79C: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x800CA7A0: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7A4: nop

    // 0x800CA7A8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x800CA7AC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800CA7B0: nop

    // 0x800CA7B4: lh          $t9, 0xA($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XA);
    // 0x800CA7B8: nop

    // 0x800CA7BC: beq         $t9, $zero, L_800CA7DC
    if (ctx->r25 == 0) {
        // 0x800CA7C0: nop
    
            goto L_800CA7DC;
    }
    // 0x800CA7C0: nop

    // 0x800CA7C4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7C8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CA7CC: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CA7D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA7D4: jalr        $t9
    // 0x800CA7D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CA7D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_2:
L_800CA7DC:
    // 0x800CA7DC: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7E0: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA7E4: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800CA7E8: lw          $a2, 0x18($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X18);
    // 0x800CA7EC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CA7F0: jalr        $t9
    // 0x800CA7F4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x800CA7F4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
    // 0x800CA7F8: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CA7FC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CA800: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CA804: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CA808: jalr        $t9
    // 0x800CA80C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x800CA80C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_4:
    // 0x800CA810: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA814: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA818: sw          $t4, 0x38($t5)
    MEM_W(0X38, ctx->r13) = ctx->r12;
    // 0x800CA81C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA820: nop

    // 0x800CA824: sw          $zero, 0x30($t6)
    MEM_W(0X30, ctx->r14) = 0;
    // 0x800CA828: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800CA82C: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA830: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x800CA834: nop

    // 0x800CA838: sw          $t8, 0x34($t0)
    MEM_W(0X34, ctx->r8) = ctx->r24;
    // 0x800CA83C: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA840: nop

    // 0x800CA844: lh          $t1, 0x10($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X10);
    // 0x800CA848: nop

    // 0x800CA84C: addu        $t3, $t1, $t1
    ctx->r11 = ADD32(ctx->r9, ctx->r9);
    // 0x800CA850: bgez        $t3, L_800CA860
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CA854: sra         $t9, $t3, 1
        ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
            goto L_800CA860;
    }
    // 0x800CA854: sra         $t9, $t3, 1
    ctx->r25 = S32(SIGNED(ctx->r11) >> 1);
    // 0x800CA858: addiu       $at, $t3, 0x1
    ctx->r1 = ADD32(ctx->r11, 0X1);
    // 0x800CA85C: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800CA860:
    // 0x800CA860: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800CA864: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800CA868: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA86C: nop

    // 0x800CA870: sh          $t4, 0x1A($t5)
    MEM_H(0X1A, ctx->r13) = ctx->r12;
    // 0x800CA874: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800CA878: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CA87C: lbu         $t7, 0x12($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X12);
    // 0x800CA880: nop

    // 0x800CA884: sh          $t7, 0x18($t8)
    MEM_H(0X18, ctx->r24) = ctx->r15;
    // 0x800CA888: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800CA88C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800CA890: lbu         $t2, 0x13($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X13);
    // 0x800CA894: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA898: sll         $t1, $t2, 1
    ctx->r9 = S32(ctx->r10 << 1);
    // 0x800CA89C: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x800CA8A0: lh          $t3, 0x3D30($t3)
    ctx->r11 = MEM_H(ctx->r11, 0X3D30);
    // 0x800CA8A4: nop

    // 0x800CA8A8: sh          $t3, 0x20($t9)
    MEM_H(0X20, ctx->r25) = ctx->r11;
    // 0x800CA8AC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA8B0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA8B4: lbu         $t5, 0x13($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X13);
    // 0x800CA8B8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8BC: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800CA8C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800CA8C4: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA8C8: lh          $t8, 0x3E2E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3E2E);
    // 0x800CA8CC: nop

    // 0x800CA8D0: sh          $t8, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r24;
    // 0x800CA8D4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800CA8D8: nop

    // 0x800CA8DC: lw          $t1, 0x14($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X14);
    // 0x800CA8E0: nop

    // 0x800CA8E4: beq         $t1, $zero, L_800CA908
    if (ctx->r9 == 0) {
        // 0x800CA8E8: nop
    
            goto L_800CA908;
    }
    // 0x800CA8E8: nop

    // 0x800CA8EC: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8F0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800CA8F4: sh          $t3, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r11;
    // 0x800CA8F8: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CA8FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CA900: b           L_800CA96C
    // 0x800CA904: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
        goto L_800CA96C;
    // 0x800CA904: sh          $t4, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r12;
L_800CA908:
    // 0x800CA908: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CA90C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CA910: lh          $t7, 0x18($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X18);
    // 0x800CA914: lh          $t2, 0x1A($t6)
    ctx->r10 = MEM_H(ctx->r14, 0X1A);
    // 0x800CA918: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CA91C: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CA920: lh          $t0, 0x3D30($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3D30);
    // 0x800CA924: nop

    // 0x800CA928: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA92C: mflo        $t1
    ctx->r9 = lo;
    // 0x800CA930: sra         $t3, $t1, 15
    ctx->r11 = S32(SIGNED(ctx->r9) >> 15);
    // 0x800CA934: sh          $t3, 0x1C($t6)
    MEM_H(0X1C, ctx->r14) = ctx->r11;
    // 0x800CA938: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CA93C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800CA940: lh          $t4, 0x18($t9)
    ctx->r12 = MEM_H(ctx->r25, 0X18);
    // 0x800CA944: lh          $t0, 0x1A($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X1A);
    // 0x800CA948: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800CA94C: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x800CA950: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800CA954: lh          $t8, 0x3E2E($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X3E2E);
    // 0x800CA958: nop

    // 0x800CA95C: multu       $t8, $t0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CA960: mflo        $t2
    ctx->r10 = lo;
    // 0x800CA964: sra         $t1, $t2, 15
    ctx->r9 = S32(SIGNED(ctx->r10) >> 15);
    // 0x800CA968: sh          $t1, 0x1E($t9)
    MEM_H(0X1E, ctx->r25) = ctx->r9;
L_800CA96C:
    // 0x800CA96C: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800CA970: nop

    // 0x800CA974: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800CA978: nop

    // 0x800CA97C: beq         $t6, $zero, L_800CA9B8
    if (ctx->r14 == 0) {
        // 0x800CA980: nop
    
            goto L_800CA9B8;
    }
    // 0x800CA980: nop

    // 0x800CA984: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800CA988: nop

    // 0x800CA98C: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800CA990: nop

    // 0x800CA994: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800CA998: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800CA99C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA9A0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800CA9A4: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800CA9A8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x800CA9AC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800CA9B0: jalr        $t9
    // 0x800CA9B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x800CA9B4: nop

    after_5:
L_800CA9B8:
    // 0x800CA9B8: b           L_800CAE8C
    // 0x800CA9BC: nop

        goto L_800CAE8C;
    // 0x800CA9BC: nop

L_800CA9C0:
    // 0x800CA9C0: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA9C4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800CA9C8: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9CC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CA9D0: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CA9D4: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CA9D8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CA9DC: jal         0x800CB1BC
    // 0x800CA9E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    static_3_800CB1BC(rdram, ctx);
        goto after_6;
    // 0x800CA9E0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_6:
    // 0x800CA9E4: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CA9E8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CA9EC: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800CA9F0: lw          $t1, 0x30($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X30);
    // 0x800CA9F4: nop

    // 0x800CA9F8: addu        $t6, $t1, $t3
    ctx->r14 = ADD32(ctx->r9, ctx->r11);
    // 0x800CA9FC: sw          $t6, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r14;
    // 0x800CAA00: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA04: nop

    // 0x800CAA08: lw          $t5, 0x30($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X30);
    // 0x800CAA0C: lw          $t7, 0x34($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X34);
    // 0x800CAA10: nop

    // 0x800CAA14: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800CAA18: bne         $at, $zero, L_800CAAC0
    if (ctx->r1 != 0) {
        // 0x800CAA1C: nop
    
            goto L_800CAAC0;
    }
    // 0x800CAA1C: nop

    // 0x800CAA20: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA24: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CAA28: lh          $t8, 0x18($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X18);
    // 0x800CAA2C: lh          $t3, 0x1A($t9)
    ctx->r11 = MEM_H(ctx->r25, 0X1A);
    // 0x800CAA30: sll         $t0, $t8, 1
    ctx->r8 = S32(ctx->r24 << 1);
    // 0x800CAA34: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800CAA38: lh          $t1, 0x3D30($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3D30);
    // 0x800CAA3C: nop

    // 0x800CAA40: multu       $t1, $t3
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAA44: mflo        $t6
    ctx->r14 = lo;
    // 0x800CAA48: sra         $t2, $t6, 15
    ctx->r10 = S32(SIGNED(ctx->r14) >> 15);
    // 0x800CAA4C: sh          $t2, 0x28($t9)
    MEM_H(0X28, ctx->r25) = ctx->r10;
    // 0x800CAA50: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA54: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800CAA58: lh          $t5, 0x18($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X18);
    // 0x800CAA5C: lh          $t1, 0x1A($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X1A);
    // 0x800CAA60: negu        $t7, $t5
    ctx->r15 = SUB32(0, ctx->r13);
    // 0x800CAA64: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800CAA68: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x800CAA6C: lh          $t0, 0x3E2E($t0)
    ctx->r8 = MEM_H(ctx->r8, 0X3E2E);
    // 0x800CAA70: nop

    // 0x800CAA74: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CAA78: mflo        $t3
    ctx->r11 = lo;
    // 0x800CAA7C: sra         $t6, $t3, 15
    ctx->r14 = S32(SIGNED(ctx->r11) >> 15);
    // 0x800CAA80: sh          $t6, 0x2E($t4)
    MEM_H(0X2E, ctx->r12) = ctx->r14;
    // 0x800CAA84: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA88: nop

    // 0x800CAA8C: lw          $t9, 0x34($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X34);
    // 0x800CAA90: nop

    // 0x800CAA94: sw          $t9, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->r25;
    // 0x800CAA98: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAA9C: nop

    // 0x800CAAA0: lh          $t7, 0x28($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X28);
    // 0x800CAAA4: nop

    // 0x800CAAA8: sh          $t7, 0x1C($t5)
    MEM_H(0X1C, ctx->r13) = ctx->r15;
    // 0x800CAAAC: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAB0: nop

    // 0x800CAAB4: lh          $t0, 0x2E($t8)
    ctx->r8 = MEM_H(ctx->r24, 0X2E);
    // 0x800CAAB8: b           L_800CAB60
    // 0x800CAABC: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
        goto L_800CAB60;
    // 0x800CAABC: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
L_800CAAC0:
    // 0x800CAAC0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAC4: nop

    // 0x800CAAC8: lh          $t3, 0x1C($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X1C);
    // 0x800CAACC: lw          $a1, 0x30($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X30);
    // 0x800CAAD0: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800CAAD4: lh          $a2, 0x26($t1)
    ctx->r6 = MEM_H(ctx->r9, 0X26);
    // 0x800CAAD8: lhu         $a3, 0x24($t1)
    ctx->r7 = MEM_HU(ctx->r9, 0X24);
    // 0x800CAADC: jal         0x800CB9F8
    // 0x800CAAE0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    static_3_800CB9F8(rdram, ctx);
        goto after_7;
    // 0x800CAAE0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_7:
    // 0x800CAAE4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CAAE8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAAEC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800CAAF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CAAF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CAAF8: nop

    // 0x800CAAFC: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CAB00: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800CAB04: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CAB08: sh          $t4, 0x1C($t9)
    MEM_H(0X1C, ctx->r25) = ctx->r12;
    // 0x800CAB0C: nop

    // 0x800CAB10: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB14: nop

    // 0x800CAB18: lh          $t7, 0x1E($t2)
    ctx->r15 = MEM_H(ctx->r10, 0X1E);
    // 0x800CAB1C: lw          $a1, 0x30($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X30);
    // 0x800CAB20: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CAB24: lh          $a2, 0x2C($t2)
    ctx->r6 = MEM_H(ctx->r10, 0X2C);
    // 0x800CAB28: lhu         $a3, 0x2A($t2)
    ctx->r7 = MEM_HU(ctx->r10, 0X2A);
    // 0x800CAB2C: jal         0x800CB9F8
    // 0x800CAB30: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    static_3_800CB9F8(rdram, ctx);
        goto after_8;
    // 0x800CAB30: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_8:
    // 0x800CAB34: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CAB38: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB3C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800CAB40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800CAB44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800CAB48: nop

    // 0x800CAB4C: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800CAB50: mfc1        $t0, $f16
    ctx->r8 = (int32_t)ctx->f16.u32l;
    // 0x800CAB54: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CAB58: sh          $t0, 0x1E($t8)
    MEM_H(0X1E, ctx->r24) = ctx->r8;
    // 0x800CAB5C: nop

L_800CAB60:
    // 0x800CAB60: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB64: nop

    // 0x800CAB68: lh          $t1, 0x1C($t3)
    ctx->r9 = MEM_H(ctx->r11, 0X1C);
    // 0x800CAB6C: nop

    // 0x800CAB70: bne         $t1, $zero, L_800CAB84
    if (ctx->r9 != 0) {
        // 0x800CAB74: nop
    
            goto L_800CAB84;
    }
    // 0x800CAB74: nop

    // 0x800CAB78: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB7C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CAB80: sh          $t6, 0x1C($t4)
    MEM_H(0X1C, ctx->r12) = ctx->r14;
L_800CAB84:
    // 0x800CAB84: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAB88: nop

    // 0x800CAB8C: lh          $t7, 0x1E($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X1E);
    // 0x800CAB90: nop

    // 0x800CAB94: bne         $t7, $zero, L_800CABA8
    if (ctx->r15 != 0) {
        // 0x800CAB98: nop
    
            goto L_800CABA8;
    }
    // 0x800CAB98: nop

    // 0x800CAB9C: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CABA0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CABA4: sh          $t2, 0x1E($t5)
    MEM_H(0X1E, ctx->r13) = ctx->r10;
L_800CABA8:
    // 0x800CABA8: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CABAC: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x800CABB0: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CABB4: nop

    // 0x800CABB8: lh          $t3, 0x8($t8)
    ctx->r11 = MEM_H(ctx->r24, 0X8);
    // 0x800CABBC: nop

    // 0x800CABC0: bne         $t3, $at, L_800CABE4
    if (ctx->r11 != ctx->r1) {
        // 0x800CABC4: nop
    
            goto L_800CABE4;
    }
    // 0x800CABC4: nop

    // 0x800CABC8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CABCC: nop

    // 0x800CABD0: lw          $t6, 0x3C($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X3C);
    // 0x800CABD4: nop

    // 0x800CABD8: lw          $t4, 0xC($t6)
    ctx->r12 = MEM_W(ctx->r14, 0XC);
    // 0x800CABDC: nop

    // 0x800CABE0: sh          $t4, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r12;
L_800CABE4:
    // 0x800CABE4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CABE8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800CABEC: lw          $t7, 0x3C($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X3C);
    // 0x800CABF0: nop

    // 0x800CABF4: lh          $t2, 0x8($t7)
    ctx->r10 = MEM_H(ctx->r15, 0X8);
    // 0x800CABF8: nop

    // 0x800CABFC: bne         $t2, $at, L_800CAC78
    if (ctx->r10 != ctx->r1) {
        // 0x800CAC00: nop
    
            goto L_800CAC78;
    }
    // 0x800CAC00: nop

    // 0x800CAC04: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC08: nop

    // 0x800CAC0C: sw          $zero, 0x30($t5)
    MEM_W(0X30, ctx->r13) = 0;
    // 0x800CAC10: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC14: nop

    // 0x800CAC18: lw          $t8, 0x3C($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X3C);
    // 0x800CAC1C: nop

    // 0x800CAC20: lw          $t3, 0xC($t8)
    ctx->r11 = MEM_W(ctx->r24, 0XC);
    // 0x800CAC24: nop

    // 0x800CAC28: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x800CAC2C: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800CAC30: nop

    // 0x800CAC34: addu        $t4, $t6, $t6
    ctx->r12 = ADD32(ctx->r14, ctx->r14);
    // 0x800CAC38: bgez        $t4, L_800CAC48
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800CAC3C: sra         $t1, $t4, 1
        ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800CAC48;
    }
    // 0x800CAC3C: sra         $t1, $t4, 1
    ctx->r9 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800CAC40: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800CAC44: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_800CAC48:
    // 0x800CAC48: sw          $t1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r9;
    // 0x800CAC4C: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800CAC50: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC54: nop

    // 0x800CAC58: sh          $t9, 0x1A($t7)
    MEM_H(0X1A, ctx->r15) = ctx->r25;
    // 0x800CAC5C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC60: nop

    // 0x800CAC64: lw          $t5, 0x3C($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X3C);
    // 0x800CAC68: nop

    // 0x800CAC6C: lw          $t0, 0x10($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X10);
    // 0x800CAC70: nop

    // 0x800CAC74: sw          $t0, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->r8;
L_800CAC78:
    // 0x800CAC78: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC7C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800CAC80: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CAC84: nop

    // 0x800CAC88: lh          $t6, 0x8($t3)
    ctx->r14 = MEM_H(ctx->r11, 0X8);
    // 0x800CAC8C: nop

    // 0x800CAC90: bne         $t6, $at, L_800CACF4
    if (ctx->r14 != ctx->r1) {
        // 0x800CAC94: nop
    
            goto L_800CACF4;
    }
    // 0x800CAC94: nop

    // 0x800CAC98: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAC9C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800CACA0: lw          $t1, 0x3C($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X3C);
    // 0x800CACA4: nop

    // 0x800CACA8: lw          $t9, 0xC($t1)
    ctx->r25 = MEM_W(ctx->r9, 0XC);
    // 0x800CACAC: nop

    // 0x800CACB0: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x800CACB4: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x800CACB8: lh          $t5, 0x3D30($t5)
    ctx->r13 = MEM_H(ctx->r13, 0X3D30);
    // 0x800CACBC: nop

    // 0x800CACC0: sh          $t5, 0x20($t4)
    MEM_H(0X20, ctx->r12) = ctx->r13;
    // 0x800CACC4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CACC8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800CACCC: lw          $t2, 0x3C($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X3C);
    // 0x800CACD0: nop

    // 0x800CACD4: lw          $t8, 0xC($t2)
    ctx->r24 = MEM_W(ctx->r10, 0XC);
    // 0x800CACD8: nop

    // 0x800CACDC: negu        $t3, $t8
    ctx->r11 = SUB32(0, ctx->r24);
    // 0x800CACE0: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x800CACE4: addu        $t1, $t1, $t6
    ctx->r9 = ADD32(ctx->r9, ctx->r14);
    // 0x800CACE8: lh          $t1, 0x3E2E($t1)
    ctx->r9 = MEM_H(ctx->r9, 0X3E2E);
    // 0x800CACEC: nop

    // 0x800CACF0: sh          $t1, 0x22($t0)
    MEM_H(0X22, ctx->r8) = ctx->r9;
L_800CACF4:
    // 0x800CACF4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CACF8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CACFC: sw          $t9, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r25;
    // 0x800CAD00: b           L_800CAE8C
    // 0x800CAD04: nop

        goto L_800CAE8C;
    // 0x800CAD04: nop

L_800CAD08:
    // 0x800CAD08: lw          $t5, 0x58($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD0C: nop

    // 0x800CAD10: lw          $t4, 0x3C($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X3C);
    // 0x800CAD14: nop

    // 0x800CAD18: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x800CAD1C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800CAD20: nop

    // 0x800CAD24: lh          $t8, 0xA($t2)
    ctx->r24 = MEM_H(ctx->r10, 0XA);
    // 0x800CAD28: nop

    // 0x800CAD2C: beq         $t8, $zero, L_800CAD4C
    if (ctx->r24 == 0) {
        // 0x800CAD30: nop
    
            goto L_800CAD4C;
    }
    // 0x800CAD30: nop

    // 0x800CAD34: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD38: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800CAD3C: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CAD40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAD44: jalr        $t9
    // 0x800CAD48: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x800CAD48: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_9:
L_800CAD4C:
    // 0x800CAD4C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD50: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800CAD54: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800CAD58: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CAD5C: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800CAD60: jalr        $t9
    // 0x800CAD64: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_10;
    // 0x800CAD64: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_10:
    // 0x800CAD68: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD6C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CAD70: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800CAD74: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CAD78: jalr        $t9
    // 0x800CAD7C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_11;
    // 0x800CAD7C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_11:
    // 0x800CAD80: b           L_800CAE8C
    // 0x800CAD84: nop

        goto L_800CAE8C;
    // 0x800CAD84: nop

L_800CAD88:
    // 0x800CAD88: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAD8C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAD90: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAD94: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CAD98: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAD9C: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CADA0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CADA4: jal         0x800CB1BC
    // 0x800CADA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_3_800CB1BC(rdram, ctx);
        goto after_12;
    // 0x800CADA8: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_12:
    // 0x800CADAC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CADB0: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CADB4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CADB8: lw          $t9, 0x8($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X8);
    // 0x800CADBC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CADC0: jalr        $t9
    // 0x800CADC4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_13;
    // 0x800CADC4: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_13:
    // 0x800CADC8: b           L_800CAE8C
    // 0x800CADCC: nop

        goto L_800CAE8C;
    // 0x800CADCC: nop

L_800CADD0:
    // 0x800CADD0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800CADD4: lw          $t2, 0x3D10($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3D10);
    // 0x800CADD8: nop

    // 0x800CADDC: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x800CADE0: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CADE4: nop

    // 0x800CADE8: lw          $t3, 0x3C($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X3C);
    // 0x800CADEC: nop

    // 0x800CADF0: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800CADF4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800CADF8: nop

    // 0x800CADFC: lw          $t6, 0xC($t1)
    ctx->r14 = MEM_W(ctx->r9, 0XC);
    // 0x800CAE00: nop

    // 0x800CAE04: sw          $zero, 0xD8($t6)
    MEM_W(0XD8, ctx->r14) = 0;
    // 0x800CAE08: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CAE0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x800CAE10: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800CAE14: jal         0x8006595C
    // 0x800CAE18: nop

    _freePVoice(rdram, ctx);
        goto after_14;
    // 0x800CAE18: nop

    after_14:
    // 0x800CAE1C: b           L_800CAE8C
    // 0x800CAE20: nop

        goto L_800CAE8C;
    // 0x800CAE20: nop

L_800CAE24:
    // 0x800CAE24: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAE28: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAE2C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE30: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE34: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAE38: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CAE3C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800CAE40: jal         0x800CB1BC
    // 0x800CAE44: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    static_3_800CB1BC(rdram, ctx);
        goto after_15;
    // 0x800CAE44: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_15:
    // 0x800CAE48: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CAE4C: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE50: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE54: lw          $t9, 0x30($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X30);
    // 0x800CAE58: nop

    // 0x800CAE5C: addu        $t8, $t9, $t2
    ctx->r24 = ADD32(ctx->r25, ctx->r10);
    // 0x800CAE60: sw          $t8, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r24;
    // 0x800CAE64: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAE68: nop

    // 0x800CAE6C: lw          $t1, 0x3C($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X3C);
    // 0x800CAE70: lw          $t9, 0x8($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X8);
    // 0x800CAE74: lh          $a1, 0x8($t1)
    ctx->r5 = MEM_H(ctx->r9, 0X8);
    // 0x800CAE78: lw          $a2, 0xC($t1)
    ctx->r6 = MEM_W(ctx->r9, 0XC);
    // 0x800CAE7C: jalr        $t9
    // 0x800CAE80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_16;
    // 0x800CAE80: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_16:
    // 0x800CAE84: b           L_800CAE8C
    // 0x800CAE88: nop

        goto L_800CAE8C;
    // 0x800CAE88: nop

L_800CAE8C:
    // 0x800CAE8C: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800CAE90: lh          $t6, 0x46($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X46);
    // 0x800CAE94: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800CAE98: addu        $t5, $t6, $t7
    ctx->r13 = ADD32(ctx->r14, ctx->r15);
    // 0x800CAE9C: sh          $t5, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r13;
    // 0x800CAEA0: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x800CAEA4: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800CAEA8: nop

    // 0x800CAEAC: subu        $t4, $t2, $t8
    ctx->r12 = SUB32(ctx->r10, ctx->r24);
    // 0x800CAEB0: sw          $t4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r12;
    // 0x800CAEB4: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAEB8: nop

    // 0x800CAEBC: lw          $t3, 0x3C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X3C);
    // 0x800CAEC0: nop

    // 0x800CAEC4: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    // 0x800CAEC8: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAECC: nop

    // 0x800CAED0: lw          $t0, 0x3C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X3C);
    // 0x800CAED4: nop

    // 0x800CAED8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800CAEDC: nop

    // 0x800CAEE0: sw          $t6, 0x3C($t9)
    MEM_W(0X3C, ctx->r25) = ctx->r14;
    // 0x800CAEE4: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x800CAEE8: nop

    // 0x800CAEEC: lw          $t5, 0x3C($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X3C);
    // 0x800CAEF0: nop

    // 0x800CAEF4: bne         $t5, $zero, L_800CAF08
    if (ctx->r13 != 0) {
        // 0x800CAEF8: nop
    
            goto L_800CAF08;
    }
    // 0x800CAEF8: nop

    // 0x800CAEFC: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF00: nop

    // 0x800CAF04: sw          $zero, 0x40($t2)
    MEM_W(0X40, ctx->r10) = 0;
L_800CAF08:
    // 0x800CAF08: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800CAF0C: jal         0x800658DC
    // 0x800CAF10: nop

    __freeParam(rdram, ctx);
        goto after_17;
    // 0x800CAF10: nop

    after_17:
    // 0x800CAF14: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF18: nop

    // 0x800CAF1C: lw          $t4, 0x3C($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X3C);
    // 0x800CAF20: nop

    // 0x800CAF24: bne         $t4, $zero, L_800CA68C
    if (ctx->r12 != 0) {
        // 0x800CAF28: nop
    
            goto L_800CA68C;
    }
    // 0x800CAF28: nop

L_800CAF2C:
    // 0x800CAF2C: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF30: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CAF34: lw          $t3, 0x48($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X48);
    // 0x800CAF38: nop

    // 0x800CAF3C: bne         $t3, $at, L_800CAF84
    if (ctx->r11 != ctx->r1) {
        // 0x800CAF40: nop
    
            goto L_800CAF84;
    }
    // 0x800CAF40: nop

    // 0x800CAF44: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800CAF48: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAF4C: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF50: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800CAF54: addiu       $a1, $sp, 0x56
    ctx->r5 = ADD32(ctx->r29, 0X56);
    // 0x800CAF58: addiu       $a2, $sp, 0x46
    ctx->r6 = ADD32(ctx->r29, 0X46);
    // 0x800CAF5C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800CAF60: jal         0x800CB1BC
    // 0x800CAF64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    static_3_800CB1BC(rdram, ctx);
        goto after_18;
    // 0x800CAF64: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_18:
    // 0x800CAF68: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800CAF6C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF70: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800CAF74: lw          $t7, 0x30($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X30);
    // 0x800CAF78: nop

    // 0x800CAF7C: addu        $t2, $t7, $t5
    ctx->r10 = ADD32(ctx->r15, ctx->r13);
    // 0x800CAF80: sw          $t2, 0x30($t9)
    MEM_W(0X30, ctx->r25) = ctx->r10;
L_800CAF84:
    // 0x800CAF84: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800CAF88: nop

    // 0x800CAF8C: lw          $t4, 0x30($t8)
    ctx->r12 = MEM_W(ctx->r24, 0X30);
    // 0x800CAF90: lw          $t1, 0x34($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X34);
    // 0x800CAF94: nop

    // 0x800CAF98: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CAF9C: beq         $at, $zero, L_800CAFB8
    if (ctx->r1 == 0) {
        // 0x800CAFA0: nop
    
            goto L_800CAFB8;
    }
    // 0x800CAFA0: nop

    // 0x800CAFA4: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x800CAFA8: nop

    // 0x800CAFAC: lw          $t0, 0x34($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X34);
    // 0x800CAFB0: nop

    // 0x800CAFB4: sw          $t0, 0x30($t3)
    MEM_W(0X30, ctx->r11) = ctx->r8;
L_800CAFB8:
    // 0x800CAFB8: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800CAFBC: b           L_800CAFCC
    // 0x800CAFC0: nop

        goto L_800CAFCC;
    // 0x800CAFC0: nop

    // 0x800CAFC4: b           L_800CAFCC
    // 0x800CAFC8: nop

        goto L_800CAFCC;
    // 0x800CAFC8: nop

L_800CAFCC:
    // 0x800CAFCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CAFD0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CAFD4: jr          $ra
    // 0x800CAFD8: nop

    return;
    // 0x800CAFD8: nop

;}
RECOMP_FUNC void move_particle_with_acceleration(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B38B8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B38BC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B38C0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B38C4: addiu       $s2, $s2, -0x7DC0
    ctx->r18 = ADD32(ctx->r18, -0X7DC0);
    // 0x800B38C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B38CC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B38D0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B38D4: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B38D8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B38DC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B38E0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B38E4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B38E8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800B38EC: beq         $t6, $zero, L_800B39EC
    if (ctx->r14 == 0) {
        // 0x800B38F0: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_800B39EC;
    }
    // 0x800B38F0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800B38F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B38F8: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
L_800B38FC:
    // 0x800B38FC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B3900: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3904: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B3908: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B390C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3910: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B3914: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3918: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B391C: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800B3920: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3924: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x800B3928: lh          $t8, 0x62($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X62);
    // 0x800B392C: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x800B3930: lh          $t1, 0x64($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X64);
    // 0x800B3934: lh          $t3, 0x4($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X4);
    // 0x800B3938: lh          $t4, 0x66($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X66);
    // 0x800B393C: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x800B3940: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x800B3944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3948: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B394C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800B3950: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3954: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3958: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x800B395C: swc1        $f18, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f18.u32l;
    // 0x800B3960: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x800B3964: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x800B3968: sh          $t5, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r13;
    // 0x800B396C: swc1        $f20, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f20.u32l;
    // 0x800B3970: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800B3974: swc1        $f20, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f20.u32l;
    // 0x800B3978: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800B397C: swc1        $f6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f6.u32l;
    // 0x800B3980: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3984: jal         0x80070560
    // 0x800B3988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B3988: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800B398C: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B3990: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B3994: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B3998: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B399C: lwc1        $f10, 0x68($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X68);
    // 0x800B39A0: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B39A4: lwc1        $f4, 0x3C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800B39A8: nop

    // 0x800B39AC: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B39B0: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B39B4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x800B39B8: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B39BC: nop

    // 0x800B39C0: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B39C4: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B39C8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800B39CC: nop

    // 0x800B39D0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800B39D4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800B39D8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B39DC: nop

    // 0x800B39E0: slt         $v0, $s1, $t6
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B39E4: bne         $v0, $zero, L_800B38FC
    if (ctx->r2 != 0) {
        // 0x800B39E8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800B38FC;
    }
    // 0x800B39E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800B39EC:
    // 0x800B39EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B39F0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800B39F4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800B39F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B39FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3A00: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3A04: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3A08: jr          $ra
    // 0x800B3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B3A0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void alSynNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065370: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80065374: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80065378: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8006537C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80065380: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80065384: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80065388: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8006538C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80065390: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80065394: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80065398: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006539C: lw          $s7, 0x14($a1)
    ctx->r23 = MEM_W(ctx->r5, 0X14);
    // 0x800653A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800653A4: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800653A8: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x800653AC: sw          $zero, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = 0;
    // 0x800653B0: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x800653B4: lw          $t7, 0x18($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X18);
    // 0x800653B8: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x800653BC: sw          $t8, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r24;
    // 0x800653C0: sw          $t7, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r15;
    // 0x800653C4: lw          $t9, 0x10($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X10);
    // 0x800653C8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800653CC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x800653D0: addiu       $t0, $zero, 0x1C
    ctx->r8 = ADD32(0, 0X1C);
    // 0x800653D4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x800653D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800653DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800653E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800653E4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800653E8: jal         0x800C7D50
    // 0x800653EC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x800653EC: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_0:
    // 0x800653F0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800653F4: jal         0x80065324
    // 0x800653F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    alSaveNew(rdram, ctx);
        goto after_1;
    // 0x800653F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800653FC: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80065400: addiu       $t2, $zero, 0x4C
    ctx->r10 = ADD32(0, 0X4C);
    // 0x80065404: sw          $t1, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r9;
    // 0x80065408: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8006540C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065410: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065414: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x80065418: jal         0x800C7D50
    // 0x8006541C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    alHeapDBAlloc(rdram, ctx);
        goto after_2;
    // 0x8006541C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_2:
    // 0x80065420: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80065424: sw          $v0, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r2;
    // 0x80065428: sw          $t3, 0x40($s6)
    MEM_W(0X40, ctx->r22) = ctx->r11;
    // 0x8006542C: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80065430: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80065434: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80065438: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006543C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065440: jal         0x800C7D50
    // 0x80065444: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_3;
    // 0x80065444: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_3:
    // 0x80065448: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x8006544C: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x80065450: jal         0x80065264
    // 0x80065454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alAuxBusNew(rdram, ctx);
        goto after_4;
    // 0x80065454: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x80065458: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x8006545C: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80065460: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80065464: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006546C: jal         0x800C7D50
    // 0x80065470: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_5;
    // 0x80065470: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_5:
    // 0x80065474: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80065478: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x8006547C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80065480: jal         0x80065264
    // 0x80065484: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    alAuxBusNew(rdram, ctx);
        goto after_6;
    // 0x80065484: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_6:
    // 0x80065488: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x8006548C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065490: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065494: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065498: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    // 0x8006549C: jal         0x800C7D50
    // 0x800654A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_7;
    // 0x800654A0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x800654A4: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800654A8: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x800654AC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800654B0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800654B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800654B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800654BC: jal         0x800C7D50
    // 0x800654C0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x800654C0: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_8:
    // 0x800654C4: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x800654C8: lw          $a2, 0x4($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X4);
    // 0x800654CC: jal         0x800652C4
    // 0x800654D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alMainBusNew(rdram, ctx);
        goto after_9;
    // 0x800654D0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x800654D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800654D8: or          $s1, $fp, $zero
    ctx->r17 = ctx->r30 | 0;
    // 0x800654DC: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
L_800654E0:
    // 0x800654E0: lbu         $t8, 0x1C($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1C);
    // 0x800654E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800654E8: beq         $t8, $zero, L_8006550C
    if (ctx->r24 == 0) {
        // 0x800654EC: sll         $a1, $s0, 16
        ctx->r5 = S32(ctx->r16 << 16);
            goto L_8006550C;
    }
    // 0x800654EC: sll         $a1, $s0, 16
    ctx->r5 = S32(ctx->r16 << 16);
    // 0x800654F0: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800654F4: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800654F8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    // 0x800654FC: jal         0x80065AA0
    // 0x80065500: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    alSynAllocFX(rdram, ctx);
        goto after_10;
    // 0x80065500: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    after_10:
    // 0x80065504: b           L_80065530
    // 0x80065508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80065530;
    // 0x80065508: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8006550C:
    // 0x8006550C: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80065510: lw          $t0, 0x34($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X34);
    // 0x80065514: lw          $a0, 0x30($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X30);
    // 0x80065518: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8006551C: mflo        $t1
    ctx->r9 = lo;
    // 0x80065520: addu        $a2, $t0, $t1
    ctx->r6 = ADD32(ctx->r8, ctx->r9);
    // 0x80065524: jal         0x800CC8F0
    // 0x80065528: nop

    alMainBusParam(rdram, ctx);
        goto after_11;
    // 0x80065528: nop

    after_11:
    // 0x8006552C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80065530:
    // 0x80065530: slti        $at, $s0, 0x2
    ctx->r1 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x80065534: bne         $at, $zero, L_800654E0
    if (ctx->r1 != 0) {
        // 0x80065538: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800654E0;
    }
    // 0x80065538: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006553C: sw          $zero, 0x4($s6)
    MEM_W(0X4, ctx->r22) = 0;
    // 0x80065540: sw          $zero, 0x8($s6)
    MEM_W(0X8, ctx->r22) = 0;
    // 0x80065544: sw          $zero, 0x14($s6)
    MEM_W(0X14, ctx->r22) = 0;
    // 0x80065548: sw          $zero, 0x18($s6)
    MEM_W(0X18, ctx->r22) = 0;
    // 0x8006554C: sw          $zero, 0xC($s6)
    MEM_W(0XC, ctx->r22) = 0;
    // 0x80065550: sw          $zero, 0x10($s6)
    MEM_W(0X10, ctx->r22) = 0;
    // 0x80065554: lw          $a3, 0x4($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X4);
    // 0x80065558: addiu       $t2, $zero, 0xE0
    ctx->r10 = ADD32(0, 0XE0);
    // 0x8006555C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80065560: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80065564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065568: jal         0x800C7D50
    // 0x8006556C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x8006556C: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_12:
    // 0x80065570: lw          $t3, 0x4($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X4);
    // 0x80065574: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80065578: blez        $t3, L_8006563C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8006557C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8006563C;
    }
    // 0x8006557C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80065580: addiu       $a1, $s6, 0x4
    ctx->r5 = ADD32(ctx->r22, 0X4);
    // 0x80065584: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x80065588: addiu       $s2, $v0, 0x8C
    ctx->r18 = ADD32(ctx->r2, 0X8C);
    // 0x8006558C: addiu       $s3, $v0, 0x58
    ctx->r19 = ADD32(ctx->r2, 0X58);
    // 0x80065590: addiu       $s4, $v0, 0x10
    ctx->r20 = ADD32(ctx->r2, 0X10);
L_80065594:
    // 0x80065594: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x80065598: or          $s5, $s1, $zero
    ctx->r21 = ctx->r17 | 0;
    // 0x8006559C: jal         0x800C8CF0
    // 0x800655A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alLink(rdram, ctx);
        goto after_13;
    // 0x800655A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x800655A4: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
    // 0x800655A8: lw          $a1, 0x24($s6)
    ctx->r5 = MEM_W(ctx->r22, 0X24);
    // 0x800655AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800655B0: jal         0x80065138
    // 0x800655B4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alLoadNew(rdram, ctx);
        goto after_14;
    // 0x800655B4: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_14:
    // 0x800655B8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800655BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655C0: jal         0x800CBAA0
    // 0x800655C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alLoadParam(rdram, ctx);
        goto after_15;
    // 0x800655C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_15:
    // 0x800655C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800655CC: jal         0x800651DC
    // 0x800655D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alResampleNew(rdram, ctx);
        goto after_16;
    // 0x800655D0: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_16:
    // 0x800655D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800655D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655DC: jal         0x800CC5F0
    // 0x800655E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    alResampleParam(rdram, ctx);
        goto after_17;
    // 0x800655E0: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_17:
    // 0x800655E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800655E8: jal         0x80065094
    // 0x800655EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    alEnvmixerNew(rdram, ctx);
        goto after_18;
    // 0x800655EC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_18:
    // 0x800655F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800655F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800655F8: jal         0x800CAFDC
    // 0x800655FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    alEnvmixerParam(rdram, ctx);
        goto after_19;
    // 0x800655FC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_19:
    // 0x80065600: lw          $a0, 0x34($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X34);
    // 0x80065604: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80065608: jal         0x80065C14
    // 0x8006560C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    alAuxBusParam(rdram, ctx);
        goto after_20;
    // 0x8006560C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_20:
    // 0x80065610: addiu       $t4, $s5, 0x8C
    ctx->r12 = ADD32(ctx->r21, 0X8C);
    // 0x80065614: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x80065618: lw          $t5, 0x4($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X4);
    // 0x8006561C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065620: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80065624: addiu       $s1, $s1, 0xE0
    ctx->r17 = ADD32(ctx->r17, 0XE0);
    // 0x80065628: addiu       $s2, $s2, 0xE0
    ctx->r18 = ADD32(ctx->r18, 0XE0);
    // 0x8006562C: addiu       $s3, $s3, 0xE0
    ctx->r19 = ADD32(ctx->r19, 0XE0);
    // 0x80065630: bne         $at, $zero, L_80065594
    if (ctx->r1 != 0) {
        // 0x80065634: addiu       $s4, $s4, 0xE0
        ctx->r20 = ADD32(ctx->r20, 0XE0);
            goto L_80065594;
    }
    // 0x80065634: addiu       $s4, $s4, 0xE0
    ctx->r20 = ADD32(ctx->r20, 0XE0);
    // 0x80065638: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8006563C:
    // 0x8006563C: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80065640: lw          $a2, 0x30($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X30);
    // 0x80065644: jal         0x800CCA40
    // 0x80065648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    alSaveParam(rdram, ctx);
        goto after_21;
    // 0x80065648: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x8006564C: lw          $a3, 0x8($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X8);
    // 0x80065650: addiu       $t6, $zero, 0x1C
    ctx->r14 = ADD32(0, 0X1C);
    // 0x80065654: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065658: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006565C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065660: jal         0x800C7D50
    // 0x80065664: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    alHeapDBAlloc(rdram, ctx);
        goto after_22;
    // 0x80065664: or          $a2, $s7, $zero
    ctx->r6 = ctx->r23 | 0;
    after_22:
    // 0x80065668: sw          $zero, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = 0;
    // 0x8006566C: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x80065670: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80065674: blez        $t7, L_800656A0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80065678: nop
    
            goto L_800656A0;
    }
    // 0x80065678: nop

L_8006567C:
    // 0x8006567C: lw          $t8, 0x2C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X2C);
    // 0x80065680: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80065684: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80065688: sw          $v1, 0x2C($s6)
    MEM_W(0X2C, ctx->r22) = ctx->r3;
    // 0x8006568C: lw          $t9, 0x8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X8);
    // 0x80065690: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x80065694: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065698: bne         $at, $zero, L_8006567C
    if (ctx->r1 != 0) {
        // 0x8006569C: nop
    
            goto L_8006567C;
    }
    // 0x8006569C: nop

L_800656A0:
    // 0x800656A0: sw          $s7, 0x28($s6)
    MEM_W(0X28, ctx->r22) = ctx->r23;
    // 0x800656A4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800656A8: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800656AC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800656B0: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800656B4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800656B8: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800656BC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800656C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800656C4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800656C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800656CC: jr          $ra
    // 0x800656D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800656D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void hud_render_player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A06E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A06E4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A06E8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A06EC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800A06F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800A06F4: jal         0x80066460
    // 0x800A06F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_viewport(rdram, ctx);
        goto after_0;
    // 0x800A06F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A06FC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A0700: lbu         $t6, 0x774A($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X774A);
    // 0x800A0704: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0708: beq         $t6, $zero, L_800A0728
    if (ctx->r14 == 0) {
        // 0x800A070C: sw          $v0, 0x72C8($at)
        MEM_W(0X72C8, ctx->r1) = ctx->r2;
            goto L_800A0728;
    }
    // 0x800A070C: sw          $v0, 0x72C8($at)
    MEM_W(0X72C8, ctx->r1) = ctx->r2;
    // 0x800A0710: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0714: lw          $t7, 0x72C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C8);
    // 0x800A0718: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A071C: jal         0x8001BB4C
    // 0x800A0720: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    get_racer_object_by_port(rdram, ctx);
        goto after_1;
    // 0x800A0720: subu        $a0, $t8, $t7
    ctx->r4 = SUB32(ctx->r24, ctx->r15);
    after_1:
    // 0x800A0724: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A0728:
    // 0x800A0728: jal         0x8006BFF0
    // 0x800A072C: nop

    level_header(rdram, ctx);
        goto after_2;
    // 0x800A072C: nop

    after_2:
    // 0x800A0730: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0734: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0738: bne         $t9, $zero, L_800A0760
    if (ctx->r25 != 0) {
        // 0x800A073C: sw          $v0, 0x7320($at)
        MEM_W(0X7320, ctx->r1) = ctx->r2;
            goto L_800A0760;
    }
    // 0x800A073C: sw          $v0, 0x7320($at)
    MEM_W(0X7320, ctx->r1) = ctx->r2;
    // 0x800A0740: jal         0x8001E474
    // 0x800A0744: nop

    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A0744: nop

    after_3:
    // 0x800A0748: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A074C: bne         $v0, $at, L_800A0764
    if (ctx->r2 != ctx->r1) {
        // 0x800A0750: lw          $t0, 0x3C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0764;
    }
    // 0x800A0750: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0754: jal         0x8001BB4C
    // 0x800A0758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object_by_port(rdram, ctx);
        goto after_4;
    // 0x800A0758: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A075C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
L_800A0760:
    // 0x800A0760: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
L_800A0764:
    // 0x800A0764: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0768: beq         $t0, $zero, L_800A10A8
    if (ctx->r8 == 0) {
        // 0x800A076C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A10A8;
    }
    // 0x800A076C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A0770: lw          $t1, 0x7320($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7320);
    // 0x800A0774: nop

    // 0x800A0778: lbu         $t2, 0xBC($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0XBC);
    // 0x800A077C: nop

    // 0x800A0780: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A0784: bne         $t3, $zero, L_800A10A8
    if (ctx->r11 != 0) {
        // 0x800A0788: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A10A8;
    }
    // 0x800A0788: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A078C: jal         0x8006DC4C
    // 0x800A0790: nop

    get_game_mode(rdram, ctx);
        goto after_5;
    // 0x800A0790: nop

    after_5:
    // 0x800A0794: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800A0798: beq         $v0, $v1, L_800A10A4
    if (ctx->r2 == ctx->r3) {
        // 0x800A079C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800A10A4;
    }
    // 0x800A079C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07A0: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x800A07A4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800A07A8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A07AC: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800A07B0: sw          $t5, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r13;
    // 0x800A07B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800A07B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07BC: sw          $t8, 0x72C0($at)
    MEM_W(0X72C0, ctx->r1) = ctx->r24;
    // 0x800A07C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A07C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07C8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A07CC: lb          $t0, 0x7291($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7291);
    // 0x800A07D0: sw          $t9, 0x72C4($at)
    MEM_W(0X72C4, ctx->r1) = ctx->r25;
    // 0x800A07D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A07D8: beq         $t0, $zero, L_800A081C
    if (ctx->r8 == 0) {
        // 0x800A07DC: sw          $zero, 0x7740($at)
        MEM_W(0X7740, ctx->r1) = 0;
            goto L_800A081C;
    }
    // 0x800A07DC: sw          $zero, 0x7740($at)
    MEM_W(0X7740, ctx->r1) = 0;
    // 0x800A07E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A07E4: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A07E8: lb          $t1, 0x0($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X0);
    // 0x800A07EC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800A07F0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A07F4: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800A07F8: sb          $t3, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r11;
    // 0x800A07FC: lb          $t4, 0x0($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X0);
    // 0x800A0800: lbu         $v0, 0x774B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X774B);
    // 0x800A0804: nop

    // 0x800A0808: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800A080C: beq         $at, $zero, L_800A084C
    if (ctx->r1 == 0) {
        // 0x800A0810: nop
    
            goto L_800A084C;
    }
    // 0x800A0810: nop

    // 0x800A0814: b           L_800A084C
    // 0x800A0818: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_800A084C;
    // 0x800A0818: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_800A081C:
    // 0x800A081C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A0820: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A0824: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A0828: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800A082C: nop

    // 0x800A0830: subu        $t8, $t5, $t6
    ctx->r24 = SUB32(ctx->r13, ctx->r14);
    // 0x800A0834: sb          $t8, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r24;
    // 0x800A0838: lb          $t7, 0x0($a2)
    ctx->r15 = MEM_B(ctx->r6, 0X0);
    // 0x800A083C: nop

    // 0x800A0840: bgez        $t7, L_800A084C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800A0844: nop
    
            goto L_800A084C;
    }
    // 0x800A0844: nop

    // 0x800A0848: sb          $zero, 0x0($a2)
    MEM_B(0X0, ctx->r6) = 0;
L_800A084C:
    // 0x800A084C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A0850: lb          $t9, 0x7292($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X7292);
    // 0x800A0854: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0858: bne         $t9, $zero, L_800A10A4
    if (ctx->r25 != 0) {
        // 0x800A085C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A10A4;
    }
    // 0x800A085C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0860: lbu         $t1, 0x774A($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X774A);
    // 0x800A0864: lw          $v0, 0x64($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X64);
    // 0x800A0868: beq         $t1, $zero, L_800A0884
    if (ctx->r9 == 0) {
        // 0x800A086C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A0884;
    }
    // 0x800A086C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A0870: lh          $t2, 0x0($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X0);
    // 0x800A0874: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0878: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800A087C: b           L_800A0890
    // 0x800A0880: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
        goto L_800A0890;
    // 0x800A0880: sw          $t3, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r11;
L_800A0884:
    // 0x800A0884: lh          $t4, 0x0($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X0);
    // 0x800A0888: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A088C: sw          $t4, 0x72D0($at)
    MEM_W(0X72D0, ctx->r1) = ctx->r12;
L_800A0890:
    // 0x800A0890: lw          $t5, 0x72C8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X72C8);
    // 0x800A0894: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A0898: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800A089C: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A08A0: lw          $t8, 0x72A0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72A0);
    // 0x800A08A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A08A8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800A08AC: jal         0x8001E474
    // 0x800A08B0: sw          $t8, 0x729C($at)
    MEM_W(0X729C, ctx->r1) = ctx->r24;
    cutscene_id(rdram, ctx);
        goto after_6;
    // 0x800A08B0: sw          $t8, 0x729C($at)
    MEM_W(0X729C, ctx->r1) = ctx->r24;
    after_6:
    // 0x800A08B4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A08B8: beq         $v0, $at, L_800A0AE8
    if (ctx->r2 == ctx->r1) {
        // 0x800A08BC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A0AE8;
    }
    // 0x800A08BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A08C0: lw          $t7, 0x72CC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72CC);
    // 0x800A08C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A08C8: bne         $t7, $zero, L_800A0988
    if (ctx->r15 != 0) {
        // 0x800A08CC: nop
    
            goto L_800A0988;
    }
    // 0x800A08CC: nop

    // 0x800A08D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A08D4: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A08D8: jal         0x8006A794
    // 0x800A08DC: nop

    input_pressed(rdram, ctx);
        goto after_7;
    // 0x800A08DC: nop

    after_7:
    // 0x800A08E0: andi        $t9, $v0, 0x4
    ctx->r25 = ctx->r2 & 0X4;
    // 0x800A08E4: beq         $t9, $zero, L_800A0A4C
    if (ctx->r25 == 0) {
        // 0x800A08E8: nop
    
            goto L_800A0A4C;
    }
    // 0x800A08E8: nop

    // 0x800A08EC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A08F0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A08F4: lb          $t1, 0x1D8($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A08F8: nop

    // 0x800A08FC: bne         $t1, $zero, L_800A0A4C
    if (ctx->r9 != 0) {
        // 0x800A0900: nop
    
            goto L_800A0A4C;
    }
    // 0x800A0900: nop

    // 0x800A0904: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A0908: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A090C: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A0910: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0914: beq         $v0, $zero, L_800A0924
    if (ctx->r2 == 0) {
        // 0x800A0918: nop
    
            goto L_800A0924;
    }
    // 0x800A0918: nop

    // 0x800A091C: bne         $v0, $at, L_800A0A4C
    if (ctx->r2 != ctx->r1) {
        // 0x800A0920: nop
    
            goto L_800A0A4C;
    }
    // 0x800A0920: nop

L_800A0924:
    // 0x800A0924: lbu         $t3, 0x72F4($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F4);
    // 0x800A0928: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A092C: beq         $t3, $zero, L_800A0A4C
    if (ctx->r11 == 0) {
        // 0x800A0930: addiu       $v0, $v0, 0x2D10
        ctx->r2 = ADD32(ctx->r2, 0X2D10);
            goto L_800A0A4C;
    }
    // 0x800A0930: addiu       $v0, $v0, 0x2D10
    ctx->r2 = ADD32(ctx->r2, 0X2D10);
    // 0x800A0934: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0938: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A093C: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A0940: andi        $a0, $t6, 0xFF
    ctx->r4 = ctx->r14 & 0XFF;
    // 0x800A0944: addiu       $a0, $a0, 0x14F
    ctx->r4 = ADD32(ctx->r4, 0X14F);
    // 0x800A0948: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x800A094C: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800A0950: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x800A0954: jal         0x80001D04
    // 0x800A0958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A0958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800A095C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A0960: addiu       $v0, $v0, 0x2D10
    ctx->r2 = ADD32(ctx->r2, 0X2D10);
    // 0x800A0964: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0968: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x800A096C: beq         $t7, $zero, L_800A0980
    if (ctx->r15 == 0) {
        // 0x800A0970: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800A0980;
    }
    // 0x800A0970: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0974: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A0978: b           L_800A0A4C
    // 0x800A097C: sb          $t9, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r25;
        goto L_800A0A4C;
    // 0x800A097C: sb          $t9, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r25;
L_800A0980:
    // 0x800A0980: b           L_800A0A4C
    // 0x800A0984: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
        goto L_800A0A4C;
    // 0x800A0984: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
L_800A0988:
    // 0x800A0988: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A098C: jal         0x8006A794
    // 0x800A0990: nop

    input_pressed(rdram, ctx);
        goto after_9;
    // 0x800A0990: nop

    after_9:
    // 0x800A0994: andi        $t0, $v0, 0x4
    ctx->r8 = ctx->r2 & 0X4;
    // 0x800A0998: beq         $t0, $zero, L_800A0A4C
    if (ctx->r8 == 0) {
        // 0x800A099C: nop
    
            goto L_800A0A4C;
    }
    // 0x800A099C: nop

    // 0x800A09A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x800A09A4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A09A8: lb          $t2, 0x1D8($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A09AC: nop

    // 0x800A09B0: bne         $t2, $zero, L_800A0A4C
    if (ctx->r10 != 0) {
        // 0x800A09B4: nop
    
            goto L_800A0A4C;
    }
    // 0x800A09B4: nop

    // 0x800A09B8: lw          $t3, 0x7320($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X7320);
    // 0x800A09BC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A09C0: lb          $t5, 0x4C($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X4C);
    // 0x800A09C4: nop

    // 0x800A09C8: andi        $t4, $t5, 0x40
    ctx->r12 = ctx->r13 & 0X40;
    // 0x800A09CC: bne         $t4, $zero, L_800A0A4C
    if (ctx->r12 != 0) {
        // 0x800A09D0: nop
    
            goto L_800A0A4C;
    }
    // 0x800A09D0: nop

    // 0x800A09D4: lbu         $t6, 0x72F4($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X72F4);
    // 0x800A09D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A09DC: beq         $t6, $zero, L_800A0A4C
    if (ctx->r14 == 0) {
        // 0x800A09E0: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800A0A4C;
    }
    // 0x800A09E0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A09E4: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A09E8: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x800A09EC: addiu       $t9, $t9, 0x2D14
    ctx->r25 = ADD32(ctx->r25, 0X2D14);
    // 0x800A09F0: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800A09F4: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800A09F8: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x800A09FC: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800A0A00: nop

    // 0x800A0A04: slti        $at, $a0, 0x3
    ctx->r1 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800A0A08: beq         $at, $zero, L_800A0A18
    if (ctx->r1 == 0) {
        // 0x800A0A0C: addiu       $t2, $a0, 0x1
        ctx->r10 = ADD32(ctx->r4, 0X1);
            goto L_800A0A18;
    }
    // 0x800A0A0C: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x800A0A10: b           L_800A0A1C
    // 0x800A0A14: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_800A0A1C;
    // 0x800A0A14: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_800A0A18:
    // 0x800A0A18: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_800A0A1C:
    // 0x800A0A1C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A20: addiu       $t7, $zero, 0x150
    ctx->r15 = ADD32(0, 0X150);
    // 0x800A0A24: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x800A0A28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A0A2C: addu        $t4, $v1, $t5
    ctx->r12 = ADD32(ctx->r3, ctx->r13);
    // 0x800A0A30: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x800A0A34: nop

    // 0x800A0A38: sltiu       $t8, $t6, 0x1
    ctx->r24 = ctx->r14 < 0X1 ? 1 : 0;
    // 0x800A0A3C: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x800A0A40: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x800A0A44: jal         0x80001D04
    // 0x800A0A48: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A0A48: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
L_800A0A4C:
    // 0x800A0A4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0A50: lw          $a0, 0x72D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X72D0);
    // 0x800A0A54: jal         0x8006A794
    // 0x800A0A58: nop

    input_pressed(rdram, ctx);
        goto after_11;
    // 0x800A0A58: nop

    after_11:
    // 0x800A0A5C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A0A60: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800A0A64: beq         $t1, $zero, L_800A0AE8
    if (ctx->r9 == 0) {
        // 0x800A0A68: addiu       $a2, $a2, 0x7290
        ctx->r6 = ADD32(ctx->r6, 0X7290);
            goto L_800A0AE8;
    }
    // 0x800A0A68: addiu       $a2, $a2, 0x7290
    ctx->r6 = ADD32(ctx->r6, 0X7290);
    // 0x800A0A6C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A0A70: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A0A74: lb          $t2, 0x1D8($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A0A78: nop

    // 0x800A0A7C: bne         $t2, $zero, L_800A0AE8
    if (ctx->r10 != 0) {
        // 0x800A0A80: nop
    
            goto L_800A0AE8;
    }
    // 0x800A0A80: nop

    // 0x800A0A84: lbu         $t3, 0x72F4($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X72F4);
    // 0x800A0A88: nop

    // 0x800A0A8C: beq         $t3, $zero, L_800A0AE8
    if (ctx->r11 == 0) {
        // 0x800A0A90: nop
    
            goto L_800A0AE8;
    }
    // 0x800A0A90: nop

    // 0x800A0A94: lb          $t5, 0x0($a2)
    ctx->r13 = MEM_B(ctx->r6, 0X0);
    // 0x800A0A98: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A0A9C: bne         $t5, $zero, L_800A0AE8
    if (ctx->r13 != 0) {
        // 0x800A0AA0: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800A0AE8;
    }
    // 0x800A0AA0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A0AA4: lw          $t4, 0x72CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X72CC);
    // 0x800A0AA8: addiu       $t6, $t6, 0x2D24
    ctx->r14 = ADD32(ctx->r14, 0X2D24);
    // 0x800A0AAC: addu        $v0, $t4, $t6
    ctx->r2 = ADD32(ctx->r12, ctx->r14);
    // 0x800A0AB0: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A0AB4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0AB8: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800A0ABC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800A0AC0: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x800A0AC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A0AC8: bne         $t1, $zero, L_800A0AE0
    if (ctx->r9 != 0) {
        // 0x800A0ACC: addiu       $a0, $zero, 0x5E
        ctx->r4 = ADD32(0, 0X5E);
            goto L_800A0AE0;
    }
    // 0x800A0ACC: addiu       $a0, $zero, 0x5E
    ctx->r4 = ADD32(0, 0X5E);
    // 0x800A0AD0: jal         0x80001D04
    // 0x800A0AD4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    sound_play(rdram, ctx);
        goto after_12;
    // 0x800A0AD4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_12:
    // 0x800A0AD8: b           L_800A0AE8
    // 0x800A0ADC: nop

        goto L_800A0AE8;
    // 0x800A0ADC: nop

L_800A0AE0:
    // 0x800A0AE0: jal         0x80001D04
    // 0x800A0AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A0AE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_800A0AE8:
    // 0x800A0AE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0AEC: lb          $t0, 0x7294($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7294);
    // 0x800A0AF0: nop

    // 0x800A0AF4: bne         $t0, $zero, L_800A0B88
    if (ctx->r8 != 0) {
        // 0x800A0AF8: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A0B88;
    }
    // 0x800A0AF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A0AFC: lw          $t2, 0x7320($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7320);
    // 0x800A0B00: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800A0B04: lb          $v0, 0x4C($t2)
    ctx->r2 = MEM_B(ctx->r10, 0X4C);
    // 0x800A0B08: nop

    // 0x800A0B0C: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x800A0B10: bne         $t3, $zero, L_800A0B2C
    if (ctx->r11 != 0) {
        // 0x800A0B14: nop
    
            goto L_800A0B2C;
    }
    // 0x800A0B14: nop

    // 0x800A0B18: beq         $v0, $zero, L_800A0B2C
    if (ctx->r2 == 0) {
        // 0x800A0B1C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A0B2C;
    }
    // 0x800A0B1C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A0B20: beq         $v0, $at, L_800A0B2C
    if (ctx->r2 == ctx->r1) {
        // 0x800A0B24: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A0B2C;
    }
    // 0x800A0B24: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0B28: bne         $v0, $at, L_800A0B60
    if (ctx->r2 != ctx->r1) {
        // 0x800A0B2C: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_800A0B60;
    }
L_800A0B2C:
    // 0x800A0B2C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A0B30: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A0B34: sb          $v1, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r3;
    // 0x800A0B38: jal         0x80001844
    // 0x800A0B3C: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    music_stop(rdram, ctx);
        goto after_14;
    // 0x800A0B3C: sb          $v1, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r3;
    after_14:
    // 0x800A0B40: jal         0x800012E8
    // 0x800A0B44: nop

    music_channel_reset_all(rdram, ctx);
        goto after_15;
    // 0x800A0B44: nop

    after_15:
    // 0x800A0B48: jal         0x80000B34
    // 0x800A0B4C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    music_play(rdram, ctx);
        goto after_16;
    // 0x800A0B4C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_16:
    // 0x800A0B50: jal         0x8000318C
    // 0x800A0B54: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_17;
    // 0x800A0B54: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_17:
    // 0x800A0B58: b           L_800A0B70
    // 0x800A0B5C: nop

        goto L_800A0B70;
    // 0x800A0B5C: nop

L_800A0B60:
    // 0x800A0B60: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A0B64: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A0B68: jal         0x8006BF50
    // 0x800A0B6C: nop

    level_music_start(rdram, ctx);
        goto after_18;
    // 0x800A0B6C: nop

    after_18:
L_800A0B70:
    // 0x800A0B70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0B74: addiu       $v0, $v0, 0x7294
    ctx->r2 = ADD32(ctx->r2, 0X7294);
    // 0x800A0B78: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x800A0B7C: nop

    // 0x800A0B80: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800A0B84: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A0B88:
    // 0x800A0B88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0B8C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A0B90: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0B94: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800A0B98: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A0B9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A0BA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800A0BA4: jal         0x8007852C
    // 0x800A0BA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    rsp_init(rdram, ctx);
        goto after_19;
    // 0x800A0BA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    after_19:
    // 0x800A0BAC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0BB0: jal         0x800784A4
    // 0x800A0BB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    rdp_init(rdram, ctx);
        goto after_20;
    // 0x800A0BB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_20:
    // 0x800A0BB8: jal         0x8007B278
    // 0x800A0BBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    tex_enable_modes(rdram, ctx);
        goto after_21;
    // 0x800A0BBC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_21:
    // 0x800A0BC0: jal         0x8007B25C
    // 0x800A0BC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    tex_disable_modes(rdram, ctx);
        goto after_22;
    // 0x800A0BC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x800A0BC8: jal         0x8007C36C
    // 0x800A0BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_23;
    // 0x800A0BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_23:
    // 0x800A0BD0: jal         0x80066750
    // 0x800A0BD4: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_24;
    // 0x800A0BD4: nop

    after_24:
    // 0x800A0BD8: bne         $v0, $zero, L_800A0D74
    if (ctx->r2 != 0) {
        // 0x800A0BDC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A0D74;
    }
    // 0x800A0BDC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A0BE0: lbu         $t7, 0x72F4($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X72F4);
    // 0x800A0BE4: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800A0BE8: bne         $t7, $zero, L_800A0D74
    if (ctx->r15 != 0) {
        // 0x800A0BEC: nop
    
            goto L_800A0D74;
    }
    // 0x800A0BEC: nop

    // 0x800A0BF0: lh          $t1, 0x0($t9)
    ctx->r9 = MEM_H(ctx->r25, 0X0);
    // 0x800A0BF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0BF8: bne         $t1, $zero, L_800A0D74
    if (ctx->r9 != 0) {
        // 0x800A0BFC: nop
    
            goto L_800A0D74;
    }
    // 0x800A0BFC: nop

    // 0x800A0C00: lbu         $t0, 0x72F5($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X72F5);
    // 0x800A0C04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0C08: beq         $t0, $zero, L_800A0CF0
    if (ctx->r8 == 0) {
        // 0x800A0C0C: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800A0CF0;
    }
    // 0x800A0C0C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800A0C10: addiu       $v0, $v0, 0x72EC
    ctx->r2 = ADD32(ctx->r2, 0X72EC);
    // 0x800A0C14: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800A0C18: jal         0x80070A04
    // 0x800A0C1C: nop

    sins_f(rdram, ctx);
        goto after_25;
    // 0x800A0C1C: nop

    after_25:
    // 0x800A0C20: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0C24: addiu       $a0, $a0, 0x72F0
    ctx->r4 = ADD32(ctx->r4, 0X72F0);
    // 0x800A0C28: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A0C2C: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800A0C30: mul.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800A0C34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A0C38: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0C3C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A0C40: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800A0C44: addiu       $v0, $v0, 0x72EC
    ctx->r2 = ADD32(ctx->r2, 0X72EC);
    // 0x800A0C48: sll         $t6, $t4, 11
    ctx->r14 = S32(ctx->r12 << 11);
    // 0x800A0C4C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A0C50: nop

    // 0x800A0C54: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A0C58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A0C5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A0C60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0C64: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A0C68: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800A0C6C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A0C70: sw          $t3, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = ctx->r11;
    // 0x800A0C74: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800A0C78: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800A0C7C: addu        $t8, $t5, $t6
    ctx->r24 = ADD32(ctx->r13, ctx->r14);
    // 0x800A0C80: andi        $v1, $t8, 0xFFFF
    ctx->r3 = ctx->r24 & 0XFFFF;
    // 0x800A0C84: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800A0C88: bne         $at, $zero, L_800A0D74
    if (ctx->r1 != 0) {
        // 0x800A0C8C: sh          $t8, 0x0($v0)
        MEM_H(0X0, ctx->r2) = ctx->r24;
            goto L_800A0D74;
    }
    // 0x800A0C8C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800A0C90: addiu       $at, $zero, -0x8000
    ctx->r1 = ADD32(0, -0X8000);
    // 0x800A0C94: addu        $t7, $v1, $at
    ctx->r15 = ADD32(ctx->r3, ctx->r1);
    // 0x800A0C98: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A0C9C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A0CA0: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800A0CA4: div.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800A0CA8: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A0CAC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A0CB0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0CB4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800A0CB8: addiu       $v1, $v1, 0x72E4
    ctx->r3 = ADD32(ctx->r3, 0X72E4);
    // 0x800A0CBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0CC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A0CC4: swc1        $f18, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f18.u32l;
    // 0x800A0CC8: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800A0CCC: nop

    // 0x800A0CD0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A0CD4: c.le.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d <= ctx->f4.d;
    // 0x800A0CD8: nop

    // 0x800A0CDC: bc1f        L_800A0D74
    if (!c1cs) {
        // 0x800A0CE0: nop
    
            goto L_800A0D74;
    }
    // 0x800A0CE0: nop

    // 0x800A0CE4: sb          $t9, 0x72F4($at)
    MEM_B(0X72F4, ctx->r1) = ctx->r25;
    // 0x800A0CE8: b           L_800A0D74
    // 0x800A0CEC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_800A0D74;
    // 0x800A0CEC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800A0CF0:
    // 0x800A0CF0: lb          $t1, 0x7294($t1)
    ctx->r9 = MEM_B(ctx->r9, 0X7294);
    // 0x800A0CF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0CF8: bne         $t1, $at, L_800A0D1C
    if (ctx->r9 != ctx->r1) {
        // 0x800A0CFC: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A0D1C;
    }
    // 0x800A0CFC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A0D00: jal         0x80001D04
    // 0x800A0D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_26;
    // 0x800A0D04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x800A0D08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A0D0C: lb          $t0, 0x7294($t0)
    ctx->r8 = MEM_B(ctx->r8, 0X7294);
    // 0x800A0D10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D14: addiu       $t2, $t0, 0x1
    ctx->r10 = ADD32(ctx->r8, 0X1);
    // 0x800A0D18: sb          $t2, 0x7294($at)
    MEM_B(0X7294, ctx->r1) = ctx->r10;
L_800A0D1C:
    // 0x800A0D1C: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800A0D20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A0D24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800A0D28: addiu       $v1, $v1, 0x72E4
    ctx->r3 = ADD32(ctx->r3, 0X72E4);
    // 0x800A0D2C: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800A0D30: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800A0D34: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x800A0D38: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x800A0D3C: subu        $v0, $t3, $t5
    ctx->r2 = SUB32(ctx->r11, ctx->r13);
    // 0x800A0D40: bgez        $v0, L_800A0D50
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800A0D44: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800A0D50;
    }
    // 0x800A0D44: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800A0D48: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800A0D4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800A0D50:
    // 0x800A0D50: bne         $v0, $zero, L_800A0D74
    if (ctx->r2 != 0) {
        // 0x800A0D54: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800A0D74;
    }
    // 0x800A0D54: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800A0D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D5C: sb          $t8, 0x72F5($at)
    MEM_B(0X72F5, ctx->r1) = ctx->r24;
    // 0x800A0D60: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x800A0D64: jal         0x80001D04
    // 0x800A0D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_27;
    // 0x800A0D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_27:
    // 0x800A0D6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A0D70: sw          $zero, 0x72E8($at)
    MEM_W(0X72E8, ctx->r1) = 0;
L_800A0D74:
    // 0x800A0D74: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0D78: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A0D7C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A0D80: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A0D84: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A0D88: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800A0D8C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A0D90: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800A0D94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A0D98: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0D9C: jal         0x800A7FBC
    // 0x800A0DA0: nop

    hud_magnet_reticle(rdram, ctx);
        goto after_28;
    // 0x800A0DA0: nop

    after_28:
    // 0x800A0DA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0DA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A0DAC: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A0DB0: jal         0x8006816C
    // 0x800A0DB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    mtx_ortho(rdram, ctx);
        goto after_29;
    // 0x800A0DB4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    after_29:
    // 0x800A0DB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A0DBC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A0DC0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A0DC4: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800A0DC8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x800A0DCC: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x800A0DD0: addiu       $t4, $zero, -0x100
    ctx->r12 = ADD32(0, -0X100);
    // 0x800A0DD4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A0DD8: jal         0x8001139C
    // 0x800A0DDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    get_race_countdown(rdram, ctx);
        goto after_30;
    // 0x800A0DDC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_30:
    // 0x800A0DE0: sra         $a0, $v0, 1
    ctx->r4 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800A0DE4: jal         0x8000E4D8
    // 0x800A0DE8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_in_time_trial(rdram, ctx);
        goto after_31;
    // 0x800A0DE8: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_31:
    // 0x800A0DEC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0DF0: beq         $v0, $zero, L_800A0E10
    if (ctx->r2 == 0) {
        // 0x800A0DF4: nop
    
            goto L_800A0E10;
    }
    // 0x800A0DF4: nop

    // 0x800A0DF8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0DFC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0E00: jal         0x800A2CBC
    // 0x800A0E04: nop

    hud_main_time_trial(rdram, ctx);
        goto after_32;
    // 0x800A0E04: nop

    after_32:
    // 0x800A0E08: b           L_800A0F48
    // 0x800A0E0C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0E0C: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0E10:
    // 0x800A0E10: jal         0x8001E474
    // 0x800A0E14: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_33;
    // 0x800A0E14: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_33:
    // 0x800A0E18: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A0E20: bne         $v0, $at, L_800A0E4C
    if (ctx->r2 != ctx->r1) {
        // 0x800A0E24: nop
    
            goto L_800A0E4C;
    }
    // 0x800A0E24: nop

    // 0x800A0E28: jal         0x80068748
    // 0x800A0E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_34;
    // 0x800A0E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_34:
    // 0x800A0E30: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0E34: jal         0x800A76E8
    // 0x800A0E38: nop

    hud_balloons(rdram, ctx);
        goto after_35;
    // 0x800A0E38: nop

    after_35:
    // 0x800A0E3C: jal         0x80068748
    // 0x800A0E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_36;
    // 0x800A0E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_36:
    // 0x800A0E44: b           L_800A0F48
    // 0x800A0E48: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0E48: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0E4C:
    // 0x800A0E4C: jal         0x8006BFD8
    // 0x800A0E50: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    level_type(rdram, ctx);
        goto after_37;
    // 0x800A0E50: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_37:
    // 0x800A0E54: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E58: beq         $v0, $zero, L_800A0E90
    if (ctx->r2 == 0) {
        // 0x800A0E5C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A0E90;
    }
    // 0x800A0E5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A0E60: beq         $v0, $at, L_800A0E90
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E64: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800A0E90;
    }
    // 0x800A0E64: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0E68: beq         $v0, $at, L_800A0ED4
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E6C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A0ED4;
    }
    // 0x800A0E6C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A0E70: beq         $v0, $at, L_800A0F04
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E74: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A0F04;
    }
    // 0x800A0E74: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A0E78: beq         $v0, $at, L_800A0EEC
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E7C: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_800A0EEC;
    }
    // 0x800A0E7C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A0E80: beq         $v0, $at, L_800A0F20
    if (ctx->r2 == ctx->r1) {
        // 0x800A0E84: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0F20;
    }
    // 0x800A0E84: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0E88: b           L_800A0F38
    // 0x800A0E8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
        goto L_800A0F38;
    // 0x800A0E8C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A0E90:
    // 0x800A0E90: jal         0x80023450
    // 0x800A0E94: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    is_taj_challenge(rdram, ctx);
        goto after_38;
    // 0x800A0E94: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    after_38:
    // 0x800A0E98: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800A0E9C: beq         $v0, $zero, L_800A0EC0
    if (ctx->r2 == 0) {
        // 0x800A0EA0: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800A0EC0;
    }
    // 0x800A0EA0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EA4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EA8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EAC: jal         0x800A2B7C
    // 0x800A0EB0: nop

    hud_main_taj(rdram, ctx);
        goto after_39;
    // 0x800A0EB0: nop

    after_39:
    // 0x800A0EB4: b           L_800A0F48
    // 0x800A0EB8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0EB8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0EBC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A0EC0:
    // 0x800A0EC0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EC4: jal         0x800A1300
    // 0x800A0EC8: nop

    hud_main_race(rdram, ctx);
        goto after_40;
    // 0x800A0EC8: nop

    after_40:
    // 0x800A0ECC: b           L_800A0F48
    // 0x800A0ED0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0ED0: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0ED4:
    // 0x800A0ED4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0ED8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EDC: jal         0x800A2ACC
    // 0x800A0EE0: nop

    hud_main_boss(rdram, ctx);
        goto after_41;
    // 0x800A0EE0: nop

    after_41:
    // 0x800A0EE4: b           L_800A0F48
    // 0x800A0EE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0EE8: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0EEC:
    // 0x800A0EEC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0EF0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0EF4: jal         0x800A1788
    // 0x800A0EF8: nop

    hud_main_treasure(rdram, ctx);
        goto after_42;
    // 0x800A0EF8: nop

    after_42:
    // 0x800A0EFC: b           L_800A0F48
    // 0x800A0F00: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F00: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0F04:
    // 0x800A0F04: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800A0F08: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F0C: jal         0x800A2144
    // 0x800A0F10: nop

    hud_main_battle(rdram, ctx);
        goto after_43;
    // 0x800A0F10: nop

    after_43:
    // 0x800A0F14: b           L_800A0F48
    // 0x800A0F18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F18: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F1C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800A0F20:
    // 0x800A0F20: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F24: jal         0x800A1968
    // 0x800A0F28: nop

    hud_main_eggs(rdram, ctx);
        goto after_44;
    // 0x800A0F28: nop

    after_44:
    // 0x800A0F2C: b           L_800A0F48
    // 0x800A0F30: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
        goto L_800A0F48;
    // 0x800A0F30: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F34: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
L_800A0F38:
    // 0x800A0F38: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F3C: jal         0x800A2C08
    // 0x800A0F40: nop

    hud_main_hub(rdram, ctx);
        goto after_45;
    // 0x800A0F40: nop

    after_45:
    // 0x800A0F44: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
L_800A0F48:
    // 0x800A0F48: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0F4C: lb          $t5, 0x1D8($t3)
    ctx->r13 = MEM_B(ctx->r11, 0X1D8);
    // 0x800A0F50: nop

    // 0x800A0F54: bne         $t5, $at, L_800A1008
    if (ctx->r13 != ctx->r1) {
        // 0x800A0F58: nop
    
            goto L_800A1008;
    }
    // 0x800A0F58: nop

    // 0x800A0F5C: jal         0x80068748
    // 0x800A0F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_46;
    // 0x800A0F60: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_46:
    // 0x800A0F64: jal         0x8000E4D8
    // 0x800A0F68: nop

    is_in_time_trial(rdram, ctx);
        goto after_47;
    // 0x800A0F68: nop

    after_47:
    // 0x800A0F6C: beq         $v0, $zero, L_800A0F8C
    if (ctx->r2 == 0) {
        // 0x800A0F70: nop
    
            goto L_800A0F8C;
    }
    // 0x800A0F70: nop

    // 0x800A0F74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F78: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0F7C: jal         0x800A738C
    // 0x800A0F80: nop

    hud_time_trial_finish(rdram, ctx);
        goto after_48;
    // 0x800A0F80: nop

    after_48:
    // 0x800A0F84: b           L_800A1000
    // 0x800A0F88: nop

        goto L_800A1000;
    // 0x800A0F88: nop

L_800A0F8C:
    // 0x800A0F8C: jal         0x80066450
    // 0x800A0F90: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_49;
    // 0x800A0F90: nop

    after_49:
    // 0x800A0F94: bne         $v0, $zero, L_800A0FF4
    if (ctx->r2 != 0) {
        // 0x800A0F98: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0F98: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0F9C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A0FA4: lh          $t8, 0x1AC($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X1AC);
    // 0x800A0FA8: nop

    // 0x800A0FAC: bne         $t8, $at, L_800A0FF4
    if (ctx->r24 != ctx->r1) {
        // 0x800A0FB0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0FB0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FB4: jal         0x8009F1C4
    // 0x800A0FB8: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_50;
    // 0x800A0FB8: nop

    after_50:
    // 0x800A0FBC: beq         $v0, $zero, L_800A0FDC
    if (ctx->r2 == 0) {
        // 0x800A0FC0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FDC;
    }
    // 0x800A0FC0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FC4: jal         0x8006BFD8
    // 0x800A0FC8: nop

    level_type(rdram, ctx);
        goto after_51;
    // 0x800A0FC8: nop

    after_51:
    // 0x800A0FCC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A0FD0: bne         $v0, $at, L_800A0FF4
    if (ctx->r2 != ctx->r1) {
        // 0x800A0FD4: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800A0FF4;
    }
    // 0x800A0FD4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800A0FD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0FDC:
    // 0x800A0FDC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0FE0: jal         0x800A4EC4
    // 0x800A0FE4: nop

    hud_race_finish_1player(rdram, ctx);
        goto after_52;
    // 0x800A0FE4: nop

    after_52:
    // 0x800A0FE8: b           L_800A1000
    // 0x800A0FEC: nop

        goto L_800A1000;
    // 0x800A0FEC: nop

    // 0x800A0FF0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_800A0FF4:
    // 0x800A0FF4: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800A0FF8: jal         0x800A679C
    // 0x800A0FFC: nop

    hud_race_finish_multiplayer(rdram, ctx);
        goto after_53;
    // 0x800A0FFC: nop

    after_53:
L_800A1000:
    // 0x800A1000: jal         0x80068748
    // 0x800A1004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_54;
    // 0x800A1004: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_54:
L_800A1008:
    // 0x800A1008: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A100C: sb          $zero, 0x7291($at)
    MEM_B(0X7291, ctx->r1) = 0;
    // 0x800A1010: jal         0x8007C36C
    // 0x800A1014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_55;
    // 0x800A1014: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_55:
    // 0x800A1018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A101C: lw          $v0, 0x7740($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7740);
    // 0x800A1020: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1024: beq         $v0, $zero, L_800A106C
    if (ctx->r2 == 0) {
        // 0x800A1028: addiu       $a1, $a1, 0x7340
        ctx->r5 = ADD32(ctx->r5, 0X7340);
            goto L_800A106C;
    }
    // 0x800A1028: addiu       $a1, $a1, 0x7340
    ctx->r5 = ADD32(ctx->r5, 0X7340);
    // 0x800A102C: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800A1030: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800A1034: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x800A1038: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A103C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x800A1040: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x800A1044: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A1048: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800A104C: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A1050: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800A1054: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800A1058: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800A105C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1060: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1064: jal         0x80078F08
    // 0x800A1068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_56;
    // 0x800A1068: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_56:
L_800A106C:
    // 0x800A106C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A1070: lw          $t3, 0x72BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X72BC);
    // 0x800A1074: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x800A1078: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A107C: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x800A1080: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800A1084: lw          $t6, 0x72C0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X72C0);
    // 0x800A1088: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A108C: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800A1090: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x800A1094: lw          $t7, 0x72C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X72C4);
    // 0x800A1098: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800A109C: jal         0x8007B278
    // 0x800A10A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    tex_enable_modes(rdram, ctx);
        goto after_57;
    // 0x800A10A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    after_57:
L_800A10A4:
    // 0x800A10A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A10A8:
    // 0x800A10A8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A10AC: jr          $ra
    // 0x800A10B0: nop

    return;
    // 0x800A10B0: nop

;}
RECOMP_FUNC void get_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5300: bne         $a0, $zero, L_800C5310
    if (ctx->r4 != 0) {
        // 0x800C5304: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800C5310;
    }
    // 0x800C5304: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C5308: jr          $ra
    // 0x800C530C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C530C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C5310:
    // 0x800C5310: bgez        $a2, L_800C532C
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800C5314: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_800C532C;
    }
    // 0x800C5314: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800C5318: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C531C: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5320: nop

    // 0x800C5324: lbu         $a2, 0x1D($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0X1D);
    // 0x800C5328: nop

L_800C532C:
    // 0x800C532C: lw          $t8, -0x525C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X525C);
    // 0x800C5330: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5334: sll         $t7, $a2, 10
    ctx->r15 = S32(ctx->r6 << 10);
    // 0x800C5338: beq         $t9, $zero, L_800C5430
    if (ctx->r25 == 0) {
        // 0x800C533C: addu        $v0, $t7, $t8
        ctx->r2 = ADD32(ctx->r15, ctx->r24);
            goto L_800C5430;
    }
    // 0x800C533C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C5340: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C5344: lw          $t2, -0x5250($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5250);
    // 0x800C5348: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800C534C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C5350: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C5354: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x800C5358: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C535C:
    // 0x800C535C: slti        $at, $a2, 0x21
    ctx->r1 = SIGNED(ctx->r6) < 0X21 ? 1 : 0;
    // 0x800C5360: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C5364: bne         $at, $zero, L_800C5378
    if (ctx->r1 != 0) {
        // 0x800C5368: or          $t1, $a2, $zero
        ctx->r9 = ctx->r6 | 0;
            goto L_800C5378;
    }
    // 0x800C5368: or          $t1, $a2, $zero
    ctx->r9 = ctx->r6 | 0;
    // 0x800C536C: slti        $at, $a2, 0x80
    ctx->r1 = SIGNED(ctx->r6) < 0X80 ? 1 : 0;
    // 0x800C5370: bne         $at, $zero, L_800C53D0
    if (ctx->r1 != 0) {
        // 0x800C5374: addiu       $a2, $t1, -0x20
        ctx->r6 = ADD32(ctx->r9, -0X20);
            goto L_800C53D0;
    }
    // 0x800C5374: addiu       $a2, $t1, -0x20
    ctx->r6 = ADD32(ctx->r9, -0X20);
L_800C5378:
    // 0x800C5378: bne         $t3, $t1, L_800C53C4
    if (ctx->r11 != ctx->r9) {
        // 0x800C537C: nop
    
            goto L_800C53C4;
    }
    // 0x800C537C: nop

    // 0x800C5380: lhu         $a2, 0x26($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X26);
    // 0x800C5384: nop

    // 0x800C5388: div         $zero, $v1, $a2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r6)));
    // 0x800C538C: addu        $t5, $v1, $a2
    ctx->r13 = ADD32(ctx->r3, ctx->r6);
    // 0x800C5390: bne         $a2, $zero, L_800C539C
    if (ctx->r6 != 0) {
        // 0x800C5394: nop
    
            goto L_800C539C;
    }
    // 0x800C5394: nop

    // 0x800C5398: break       7
    do_break(2148291480);
L_800C539C:
    // 0x800C539C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C53A0: bne         $a2, $at, L_800C53B4
    if (ctx->r6 != ctx->r1) {
        // 0x800C53A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C53B4;
    }
    // 0x800C53A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C53A8: bne         $v1, $at, L_800C53B4
    if (ctx->r3 != ctx->r1) {
        // 0x800C53AC: nop
    
            goto L_800C53B4;
    }
    // 0x800C53AC: nop

    // 0x800C53B0: break       6
    do_break(2148291504);
L_800C53B4:
    // 0x800C53B4: mfhi        $t6
    ctx->r14 = hi;
    // 0x800C53B8: subu        $v1, $t5, $t6
    ctx->r3 = SUB32(ctx->r13, ctx->r14);
    // 0x800C53BC: b           L_800C540C
    // 0x800C53C0: nop

        goto L_800C540C;
    // 0x800C53C0: nop

L_800C53C4:
    // 0x800C53C4: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x800C53C8: b           L_800C540C
    // 0x800C53CC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
        goto L_800C540C;
    // 0x800C53CC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
L_800C53D0:
    // 0x800C53D0: andi        $t8, $a2, 0xFF
    ctx->r24 = ctx->r6 & 0XFF;
    // 0x800C53D4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800C53D8: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800C53DC: lbu         $t5, 0x100($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X100);
    // 0x800C53E0: nop

    // 0x800C53E4: beq         $t4, $t5, L_800C540C
    if (ctx->r12 == ctx->r13) {
        // 0x800C53E8: nop
    
            goto L_800C540C;
    }
    // 0x800C53E8: nop

    // 0x800C53EC: lhu         $a2, 0x20($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X20);
    // 0x800C53F0: nop

    // 0x800C53F4: bne         $a2, $zero, L_800C5408
    if (ctx->r6 != 0) {
        // 0x800C53F8: nop
    
            goto L_800C5408;
    }
    // 0x800C53F8: nop

    // 0x800C53FC: lbu         $t6, 0x101($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X101);
    // 0x800C5400: b           L_800C540C
    // 0x800C5404: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
        goto L_800C540C;
    // 0x800C5404: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800C5408:
    // 0x800C5408: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
L_800C540C:
    // 0x800C540C: beq         $t2, $zero, L_800C5420
    if (ctx->r10 == 0) {
        // 0x800C5410: nop
    
            goto L_800C5420;
    }
    // 0x800C5410: nop

    // 0x800C5414: beq         $v1, $a0, L_800C5420
    if (ctx->r3 == ctx->r4) {
        // 0x800C5418: nop
    
            goto L_800C5420;
    }
    // 0x800C5418: nop

    // 0x800C541C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800C5420:
    // 0x800C5420: lbu         $t0, 0x1($a3)
    ctx->r8 = MEM_BU(ctx->r7, 0X1);
    // 0x800C5424: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C5428: bne         $t0, $zero, L_800C535C
    if (ctx->r8 != 0) {
        // 0x800C542C: andi        $a2, $t0, 0xFF
        ctx->r6 = ctx->r8 & 0XFF;
            goto L_800C535C;
    }
    // 0x800C542C: andi        $a2, $t0, 0xFF
    ctx->r6 = ctx->r8 & 0XFF;
L_800C5430:
    // 0x800C5430: subu        $v0, $v1, $a1
    ctx->r2 = SUB32(ctx->r3, ctx->r5);
    // 0x800C5434: jr          $ra
    // 0x800C5438: nop

    return;
    // 0x800C5438: nop

;}
RECOMP_FUNC void obj_loop_ainode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D06C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D070: jr          $ra
    // 0x8003D074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D074: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void obj_disable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AFC44: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AFC48: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AFC4C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AFC50: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800AFC54: nop

    // 0x800AFC58: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800AFC5C: sh          $t9, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r25;
    // 0x800AFC60: lh          $t0, 0x1A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X1A);
    // 0x800AFC64: nop

    // 0x800AFC68: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800AFC6C: jr          $ra
    // 0x800AFC70: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
    return;
    // 0x800AFC70: sh          $t1, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void func_8002EEEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EF2C: addiu       $sp, $sp, -0x128
    ctx->r29 = ADD32(ctx->r29, -0X128);
    // 0x8002EF30: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002EF34: lw          $v0, -0x29BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X29BC);
    // 0x8002EF38: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8002EF3C: sw          $s7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r23;
    // 0x8002EF40: sw          $s6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r22;
    // 0x8002EF44: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8002EF48: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8002EF4C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8002EF50: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8002EF54: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8002EF58: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8002EF5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF60: lwc1        $f0, -0x29A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29A4);
    // 0x8002EF64: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002EF6C: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EF70: lwc1        $f2, -0x29A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29A0);
    // 0x8002EF74: swc1        $f6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f6.u32l;
    // 0x8002EF78: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EF7C: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002EF80: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8002EF84: addiu       $s7, $s7, -0x29C8
    ctx->r23 = ADD32(ctx->r23, -0X29C8);
    // 0x8002EF88: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
    // 0x8002EF8C: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EF90: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8002EF94: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002EF98: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002EF9C: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
    // 0x8002EFA0: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFA4: addiu       $t8, $t8, -0x31C8
    ctx->r24 = ADD32(ctx->r24, -0X31C8);
    // 0x8002EFA8: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8002EFAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002EFB0: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x8002EFB4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EFB8: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8002EFBC: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8002EFC0: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x8002EFC4: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x8002EFC8: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFCC: lw          $a3, 0x98($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X98);
    // 0x8002EFD0: sub.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x8002EFD4: addiu       $a1, $a1, -0x36C8
    ctx->r5 = ADD32(ctx->r5, -0X36C8);
    // 0x8002EFD8: swc1        $f18, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f18.u32l;
    // 0x8002EFDC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002EFE0: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8002EFE4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8002EFE8: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8002EFEC: swc1        $f6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f6.u32l;
    // 0x8002EFF0: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EFF4: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8002EFF8: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x8002EFFC: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8002F000: swc1        $f10, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f10.u32l;
    // 0x8002F004: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8002F008: jal         0x800BE1A0
    // 0x8002F00C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    func_800BDC80(rdram, ctx);
        goto after_0;
    // 0x8002F00C: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x8002F010: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8002F014: blez        $v0, L_8002F2B4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F018: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8002F2B4;
    }
    // 0x8002F018: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8002F01C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8002F020: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8002F024: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8002F028: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002F02C: addiu       $s1, $s1, -0x29C4
    ctx->r17 = ADD32(ctx->r17, -0X29C4);
    // 0x8002F030: addiu       $s3, $s3, -0x4960
    ctx->r19 = ADD32(ctx->r19, -0X4960);
    // 0x8002F034: addiu       $s5, $s5, -0x3850
    ctx->r21 = ADD32(ctx->r21, -0X3850);
    // 0x8002F038: addiu       $s0, $s0, -0x36C8
    ctx->r16 = ADD32(ctx->r16, -0X36C8);
    // 0x8002F03C: addiu       $s2, $sp, 0xD8
    ctx->r18 = ADD32(ctx->r29, 0XD8);
    // 0x8002F040: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_8002F044:
    // 0x8002F044: lh          $a1, 0x2($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X2);
    // 0x8002F048: lh          $v1, 0x8($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X8);
    // 0x8002F04C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8002F050: lh          $a2, -0x29B2($a2)
    ctx->r6 = MEM_H(ctx->r6, -0X29B2);
    // 0x8002F054: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002F058: beq         $at, $zero, L_8002F068
    if (ctx->r1 == 0) {
        // 0x8002F05C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8002F068;
    }
    // 0x8002F05C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002F060: b           L_8002F078
    // 0x8002F064: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
        goto L_8002F078;
    // 0x8002F064: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_8002F068:
    // 0x8002F068: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002F06C: beq         $at, $zero, L_8002F078
    if (ctx->r1 == 0) {
        // 0x8002F070: nop
    
            goto L_8002F078;
    }
    // 0x8002F070: nop

    // 0x8002F074: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F078:
    // 0x8002F078: lh          $v0, 0xE($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XE);
    // 0x8002F07C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002F080: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F084: beq         $at, $zero, L_8002F098
    if (ctx->r1 == 0) {
        // 0x8002F088: slt         $at, $a1, $v0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002F098;
    }
    // 0x8002F088: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002F08C: b           L_8002F0A4
    // 0x8002F090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8002F0A4;
    // 0x8002F090: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002F094: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
L_8002F098:
    // 0x8002F098: beq         $at, $zero, L_8002F0A8
    if (ctx->r1 == 0) {
        // 0x8002F09C: slt         $at, $a2, $a0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002F0A8;
    }
    // 0x8002F09C: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002F0A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8002F0A4:
    // 0x8002F0A4: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
L_8002F0A8:
    // 0x8002F0A8: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F0AC: nop
    
            goto L_8002F2A4;
    }
    // 0x8002F0AC: nop

    // 0x8002F0B0: lh          $t9, -0x29B4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X29B4);
    // 0x8002F0B4: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8002F0B8: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8002F0BC: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F0C0: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_8002F2A4;
    }
    // 0x8002F0C0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8002F0C4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8002F0C8: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x8002F0CC: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x8002F0D0: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8002F0D4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002F0D8: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x8002F0DC: lh          $t9, 0xA($s0)
    ctx->r25 = MEM_H(ctx->r16, 0XA);
    // 0x8002F0E0: mtc1        $t8, $f14
    ctx->f14.u32l = ctx->r24;
    // 0x8002F0E4: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8002F0E8: mtc1        $t9, $f12
    ctx->f12.u32l = ctx->r25;
    // 0x8002F0EC: lh          $t6, 0xC($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XC);
    // 0x8002F0F0: cvt.s.w     $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.fl = CVT_S_W(ctx->f14.u32l);
    // 0x8002F0F4: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8002F0F8: lh          $t7, 0x10($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X10);
    // 0x8002F0FC: cvt.s.w     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    ctx->f12.fl = CVT_S_W(ctx->f12.u32l);
    // 0x8002F100: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8002F104: swc1        $f18, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f18.u32l;
    // 0x8002F108: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002F10C: swc1        $f16, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f16.u32l;
    // 0x8002F110: swc1        $f14, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f14.u32l;
    // 0x8002F114: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8002F118: swc1        $f12, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f12.u32l;
    // 0x8002F11C: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x8002F120: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
L_8002F124:
    // 0x8002F124: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002F128: bne         $v0, $s2, L_8002F124
    if (ctx->r2 != ctx->r18) {
        // 0x8002F12C: sh          $t0, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r8;
            goto L_8002F124;
    }
    // 0x8002F12C: sh          $t0, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r8;
    // 0x8002F130: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F134: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x8002F138: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8002F13C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002F140: addiu       $t8, $t8, -0x31C8
    ctx->r24 = ADD32(ctx->r24, -0X31C8);
    // 0x8002F144: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F148: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8002F14C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8002F150: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8002F154: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8002F158: jal         0x8002FFAC
    // 0x8002F15C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_8002FF6C(rdram, ctx);
        goto after_1;
    // 0x8002F15C: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_1:
    // 0x8002F160: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8002F164: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8002F168: addiu       $t5, $t5, -0x4968
    ctx->r13 = ADD32(ctx->r13, -0X4968);
    // 0x8002F16C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8002F170: bne         $at, $zero, L_8002F2A4
    if (ctx->r1 != 0) {
        // 0x8002F174: or          $ra, $v0, $zero
        ctx->r31 = ctx->r2 | 0;
            goto L_8002F2A4;
    }
    // 0x8002F174: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x8002F178: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002F17C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002F180: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8002F184: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x8002F188: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8002F18C: addiu       $t7, $t7, -0x3848
    ctx->r15 = ADD32(ctx->r15, -0X3848);
    // 0x8002F190: addu        $t3, $t6, $t7
    ctx->r11 = ADD32(ctx->r14, ctx->r15);
    // 0x8002F194: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x8002F198: blez        $v0, L_8002F298
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002F19C: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8002F298;
    }
    // 0x8002F19C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8002F1A0: addiu       $a3, $sp, 0xA8
    ctx->r7 = ADD32(ctx->r29, 0XA8);
L_8002F1A4:
    // 0x8002F1A4: lh          $v1, 0xE($a3)
    ctx->r3 = MEM_H(ctx->r7, 0XE);
    // 0x8002F1A8: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8002F1AC: bgez        $v1, L_8002F278
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002F1B0: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8002F278;
    }
    // 0x8002F1B0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8002F1B4: sll         $t8, $t4, 2
    ctx->r24 = S32(ctx->r12 << 2);
    // 0x8002F1B8: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x8002F1BC: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x8002F1C0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8002F1C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002F1C8: addiu       $t6, $t6, -0x3848
    ctx->r14 = ADD32(ctx->r14, -0X3848);
    // 0x8002F1CC: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x8002F1D0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8002F1D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002F1D8: blez        $a2, L_8002F23C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002F1DC: addu        $t2, $t9, $t6
        ctx->r10 = ADD32(ctx->r25, ctx->r14);
            goto L_8002F23C;
    }
    // 0x8002F1DC: addu        $t2, $t9, $t6
    ctx->r10 = ADD32(ctx->r25, ctx->r14);
    // 0x8002F1E0: sll         $t7, $zero, 4
    ctx->r15 = S32(0 << 4);
    // 0x8002F1E4: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F1E8: addu        $a0, $s3, $t7
    ctx->r4 = ADD32(ctx->r19, ctx->r15);
L_8002F1EC:
    // 0x8002F1EC: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002F1F0: nop

    // 0x8002F1F4: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8002F1F8: nop

    // 0x8002F1FC: bc1f        L_8002F224
    if (!c1cs) {
        // 0x8002F200: nop
    
            goto L_8002F224;
    }
    // 0x8002F200: nop

    // 0x8002F204: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8002F208: lwc1        $f10, 0x8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F20C: nop

    // 0x8002F210: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x8002F214: nop

    // 0x8002F218: bc1f        L_8002F224
    if (!c1cs) {
        // 0x8002F21C: nop
    
            goto L_8002F224;
    }
    // 0x8002F21C: nop

    // 0x8002F220: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_8002F224:
    // 0x8002F224: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002F228: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8002F22C: beq         $at, $zero, L_8002F23C
    if (ctx->r1 == 0) {
        // 0x8002F230: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_8002F23C;
    }
    // 0x8002F230: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002F234: beq         $a1, $t0, L_8002F1EC
    if (ctx->r5 == ctx->r8) {
        // 0x8002F238: nop
    
            goto L_8002F1EC;
    }
    // 0x8002F238: nop

L_8002F23C:
    // 0x8002F23C: bne         $a1, $t0, L_8002F270
    if (ctx->r5 != ctx->r8) {
        // 0x8002F240: sll         $t8, $a2, 4
        ctx->r24 = S32(ctx->r6 << 4);
            goto L_8002F270;
    }
    // 0x8002F240: sll         $t8, $a2, 4
    ctx->r24 = S32(ctx->r6 << 4);
    // 0x8002F244: lwc1        $f16, 0x0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002F248: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002F24C: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002F250: addu        $v1, $s3, $t8
    ctx->r3 = ADD32(ctx->r19, ctx->r24);
    // 0x8002F254: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8002F258: sw          $t6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r14;
    // 0x8002F25C: sb          $a2, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r6;
    // 0x8002F260: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
    // 0x8002F264: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x8002F268: b           L_8002F28C
    // 0x8002F26C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
        goto L_8002F28C;
    // 0x8002F26C: swc1        $f18, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f18.u32l;
L_8002F270:
    // 0x8002F270: b           L_8002F28C
    // 0x8002F274: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
        goto L_8002F28C;
    // 0x8002F274: sb          $a1, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r5;
L_8002F278:
    // 0x8002F278: sb          $v1, 0x2($t7)
    MEM_B(0X2, ctx->r15) = ctx->r3;
    // 0x8002F27C: lbu         $t8, 0x1($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X1);
    // 0x8002F280: sllv        $t6, $t9, $t1
    ctx->r14 = S32(ctx->r25 << (ctx->r9 & 31));
    // 0x8002F284: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8002F288: sb          $t7, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r15;
L_8002F28C:
    // 0x8002F28C: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8002F290: bne         $t1, $ra, L_8002F1A4
    if (ctx->r9 != ctx->r31) {
        // 0x8002F294: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002F1A4;
    }
    // 0x8002F294: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
L_8002F298:
    // 0x8002F298: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8002F29C: sw          $t9, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r25;
    // 0x8002F2A0: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_8002F2A4:
    // 0x8002F2A4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8002F2A8: slt         $at, $s4, $s6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r22) ? 1 : 0;
    // 0x8002F2AC: bne         $at, $zero, L_8002F044
    if (ctx->r1 != 0) {
        // 0x8002F2B0: addiu       $s0, $s0, 0x14
        ctx->r16 = ADD32(ctx->r16, 0X14);
            goto L_8002F044;
    }
    // 0x8002F2B0: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
L_8002F2B4:
    // 0x8002F2B4: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x8002F2B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8002F2BC: addu        $t6, $t8, $s6
    ctx->r14 = ADD32(ctx->r24, ctx->r22);
    // 0x8002F2C0: sw          $t6, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r14;
    // 0x8002F2C4: lw          $s7, 0x40($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X40);
    // 0x8002F2C8: lw          $s6, 0x3C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X3C);
    // 0x8002F2CC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8002F2D0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8002F2D4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F2D8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8002F2DC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8002F2E0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8002F2E4: jr          $ra
    // 0x8002F2E8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
    return;
    // 0x8002F2E8: addiu       $sp, $sp, 0x128
    ctx->r29 = ADD32(ctx->r29, 0X128);
;}
RECOMP_FUNC void func_800535C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053604: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80053608: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8005360C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80053610: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80053614: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x80053618: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005361C: addiu       $a1, $a1, -0x2570
    ctx->r5 = ADD32(ctx->r5, -0X2570);
    // 0x80053620: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x80053624: sh          $t7, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r15;
    // 0x80053628: lh          $t8, 0x2($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2);
    // 0x8005362C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053630: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80053634: sh          $t9, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r25;
    // 0x80053638: lh          $t0, 0x1A4($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X1A4);
    // 0x8005363C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80053640: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80053644: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80053648: sh          $t1, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r9;
    // 0x8005364C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80053650: swc1        $f0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f0.u32l;
    // 0x80053654: swc1        $f0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f0.u32l;
    // 0x80053658: swc1        $f0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f0.u32l;
    // 0x8005365C: jal         0x800700B4
    // 0x80053660: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80053660: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    after_0:
    // 0x80053664: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80053668: addiu       $t2, $s0, 0xA0
    ctx->r10 = ADD32(ctx->r16, 0XA0);
    // 0x8005366C: addiu       $t3, $s0, 0xA4
    ctx->r11 = ADD32(ctx->r16, 0XA4);
    // 0x80053670: addiu       $t4, $s0, 0x9C
    ctx->r12 = ADD32(ctx->r16, 0X9C);
    // 0x80053674: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80053678: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8005367C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x80053680: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80053684: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80053688: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8005368C: jal         0x8006F88C
    // 0x80053690: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x80053690: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    after_1:
    // 0x80053694: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80053698: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8005369C: jr          $ra
    // 0x800536A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800536A0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void music_channel_fade_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000126C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001270: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x80001274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001278: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000127C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001280: beq         $at, $zero, L_80001298
    if (ctx->r1 == 0) {
        // 0x80001284: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001298;
    }
    // 0x80001284: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001288: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000128C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001290: jal         0x80063DE0
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetFadeIn(rdram, ctx);
        goto after_0;
    // 0x80001294: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001298:
    // 0x80001298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000129C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012A0: jr          $ra
    // 0x800012A4: nop

    return;
    // 0x800012A4: nop

;}
RECOMP_FUNC void rumble_kill(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072954: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80072958: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007295C: jr          $ra
    // 0x80072960: sw          $t6, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r14;
    return;
    // 0x80072960: sw          $t6, -0x1604($at)
    MEM_W(-0X1604, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void cubic_spline_interpolation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022670: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80022674: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80022678: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8002267C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80022680: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80022684: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80022688: addu        $v0, $a0, $t6
    ctx->r2 = ADD32(ctx->r4, ctx->r14);
    // 0x8002268C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80022690: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022694: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80022698: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8002269C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800226A0: cvt.d.s     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f12.d = CVT_D_S(ctx->f6.fl);
    // 0x800226A4: mul.d       $f14, $f8, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f14.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x800226A8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800226AC: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x800226B0: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x800226B4: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800226B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800226BC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800226C0: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800226C4: mul.d       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800226C8: lui         $at, 0xBFF8
    ctx->r1 = S32(0XBFF8 << 16);
    // 0x800226CC: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800226D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226D4: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800226D8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800226DC: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x800226E0: add.d       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f14.d + ctx->f8.d;
    // 0x800226E4: lui         $at, 0xC004
    ctx->r1 = S32(0XC004 << 16);
    // 0x800226E8: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x800226EC: mul.d       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f18.d);
    // 0x800226F0: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x800226F4: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x800226F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800226FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80022700: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80022704: lui         $at, 0xBFE0
    ctx->r1 = S32(0XBFE0 << 16);
    // 0x80022708: mul.d       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8002270C: add.d       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f0.d + ctx->f0.d;
    // 0x80022710: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x80022714: add.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f12.d + ctx->f8.d;
    // 0x80022718: add.d       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f10.d + ctx->f4.d;
    // 0x8002271C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80022720: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80022724: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80022728: mul.d       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x8002272C: mov.s       $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = ctx->f6.fl;
    // 0x80022730: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
    // 0x80022734: add.d       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f4.d + ctx->f8.d;
    // 0x80022738: mul.d       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x8002273C: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80022740: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80022744: add.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = ctx->f8.d + ctx->f14.d;
    // 0x80022748: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8002274C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80022750: mov.s       $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = ctx->f4.fl;
    // 0x80022754: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80022758: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002275C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80022760: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x80022764: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022768: nop

    // 0x8002276C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80022770: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80022774: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022778: nop

    // 0x8002277C: mul.s       $f10, $f12, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80022780: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022784: swc1        $f4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f4.u32l;
    // 0x80022788: add.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8002278C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x80022790: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80022794: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80022798: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8002279C: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800227A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800227A4: add.s       $f2, $f10, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f2.fl;
    // 0x800227A8: jr          $ra
    // 0x800227AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800227AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ainode_get(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D248: bltz        $a0, L_8001D270
    if (SIGNED(ctx->r4) < 0) {
        // 0x8001D24C: slti        $at, $a0, 0x80
        ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
            goto L_8001D270;
    }
    // 0x8001D24C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x8001D250: beq         $at, $zero, L_8001D270
    if (ctx->r1 == 0) {
        // 0x8001D254: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8001D270;
    }
    // 0x8001D254: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001D258: lw          $t6, -0x4B7C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B7C);
    // 0x8001D25C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8001D260: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001D264: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001D268: jr          $ra
    // 0x8001D26C: nop

    return;
    // 0x8001D26C: nop

L_8001D270:
    // 0x8001D270: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001D274: jr          $ra
    // 0x8001D278: nop

    return;
    // 0x8001D278: nop

;}
RECOMP_FUNC void obj_bridge_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E3A0: lui         $at, 0xC6FA
    ctx->r1 = S32(0XC6FA << 16);
    // 0x8001E3A4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001E3A8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8001E3AC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8001E3B0: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8001E3B4: swc1        $f0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f0.u32l;
    // 0x8001E3B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E3BC: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x8001E3C0: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001E3C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E3C8: blez        $v1, L_8001E468
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E3CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E468;
    }
    // 0x8001E3CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E3D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001E3D4: addiu       $t1, $t1, -0x4C28
    ctx->r9 = ADD32(ctx->r9, -0X4C28);
    // 0x8001E3D8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001E3DC: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
L_8001E3E0:
    // 0x8001E3E0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x8001E3E4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E3E8: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x8001E3EC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001E3F0: nop

    // 0x8001E3F4: beq         $a0, $zero, L_8001E460
    if (ctx->r4 == 0) {
        // 0x8001E3F8: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E3F8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E3FC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001E400: nop

    // 0x8001E404: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001E408: bne         $t9, $zero, L_8001E460
    if (ctx->r25 != 0) {
        // 0x8001E40C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E40C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E410: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001E414: nop

    // 0x8001E418: bne         $t2, $t3, L_8001E460
    if (ctx->r10 != ctx->r11) {
        // 0x8001E41C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E41C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E420: lw          $t4, 0x78($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X78);
    // 0x8001E424: nop

    // 0x8001E428: bne         $s0, $t4, L_8001E460
    if (ctx->r16 != ctx->r12) {
        // 0x8001E42C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E460;
    }
    // 0x8001E42C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E430: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E434: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E438: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x8001E43C: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E440: nop

    // 0x8001E444: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001E448: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E44C: nop

    // 0x8001E450: swc1        $f8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f8.u32l;
    // 0x8001E454: lw          $v1, -0x4C24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4C24);
    // 0x8001E458: nop

    // 0x8001E45C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E460:
    // 0x8001E460: bne         $at, $zero, L_8001E3E0
    if (ctx->r1 != 0) {
        // 0x8001E464: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8001E3E0;
    }
    // 0x8001E464: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8001E468:
    // 0x8001E468: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8001E46C: jr          $ra
    // 0x8001E470: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8001E470: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void optionscreen_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800845F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800845F4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800845F8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800845FC: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80084600: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80084604: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80084608: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8008460C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80084610: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80084614: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80084618: jal         0x800C484C
    // 0x8008461C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008461C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80084620: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084624: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084628: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008462C: jal         0x800C492C
    // 0x80084630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x80084630: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80084634: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x80084638: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008463C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80084640: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80084644: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80084648: jal         0x800C48E4
    // 0x8008464C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008464C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x80084650: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80084654: addiu       $s0, $s0, -0x5E0
    ctx->r16 = ADD32(ctx->r16, -0X5E0);
    // 0x80084658: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008465C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80084660: addiu       $s6, $s6, 0x693C
    ctx->r22 = ADD32(ctx->r22, 0X693C);
    // 0x80084664: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80084668: lw          $a3, 0x90($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X90);
    // 0x8008466C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80084670: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80084674: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80084678: jal         0x800C49A0
    // 0x8008467C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008467C: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x80084680: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80084684: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80084688: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008468C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80084690: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80084694: jal         0x800C48E4
    // 0x80084698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x80084698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008469C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800846A0: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800846A4: lw          $a3, 0x90($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X90);
    // 0x800846A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800846AC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800846B0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x800846B4: jal         0x800C49A0
    // 0x800846B8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x800846B8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x800846BC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800846C0: addiu       $s2, $zero, 0x4C
    ctx->r18 = ADD32(0, 0X4C);
    // 0x800846C4: jal         0x800C484C
    // 0x800846C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_6;
    // 0x800846C8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800846CC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800846D0: lw          $t2, -0x70($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X70);
    // 0x800846D4: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x800846D8: beq         $t2, $zero, L_8008476C
    if (ctx->r10 == 0) {
        // 0x800846DC: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8008476C;
    }
    // 0x800846DC: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800846E0: addiu       $t4, $t4, -0x70
    ctx->r12 = ADD32(ctx->r12, -0X70);
    // 0x800846E4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800846E8: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800846EC: addiu       $s3, $s3, -0x620
    ctx->r19 = ADD32(ctx->r19, -0X620);
    // 0x800846F0: addiu       $s4, $s4, 0x695C
    ctx->r20 = ADD32(ctx->r20, 0X695C);
    // 0x800846F4: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x800846F8: addiu       $s5, $zero, 0x1FF
    ctx->r21 = ADD32(0, 0X1FF);
L_800846FC:
    // 0x800846FC: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x80084700: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80084704: bne         $s1, $t5, L_80084728
    if (ctx->r17 != ctx->r13) {
        // 0x80084708: addiu       $a1, $zero, 0xFF
        ctx->r5 = ADD32(0, 0XFF);
            goto L_80084728;
    }
    // 0x80084708: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008470C: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80084710: nop

    // 0x80084714: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80084718: bne         $at, $zero, L_8008472C
    if (ctx->r1 != 0) {
        // 0x8008471C: sll         $a3, $v0, 3
        ctx->r7 = S32(ctx->r2 << 3);
            goto L_8008472C;
    }
    // 0x8008471C: sll         $a3, $v0, 3
    ctx->r7 = S32(ctx->r2 << 3);
    // 0x80084720: b           L_8008472C
    // 0x80084724: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
        goto L_8008472C;
    // 0x80084724: subu        $a3, $s5, $a3
    ctx->r7 = SUB32(ctx->r21, ctx->r7);
L_80084728:
    // 0x80084728: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8008472C:
    // 0x8008472C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80084730: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80084734: jal         0x800C48E4
    // 0x80084738: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80084738: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    after_7:
    // 0x8008473C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80084740: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80084744: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80084748: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8008474C: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x80084750: jal         0x800C49A0
    // 0x80084754: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80084754: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_8:
    // 0x80084758: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x8008475C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80084760: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80084764: bne         $t8, $zero, L_800846FC
    if (ctx->r24 != 0) {
        // 0x80084768: addiu       $s2, $s2, 0x1C
        ctx->r18 = ADD32(ctx->r18, 0X1C);
            goto L_800846FC;
    }
    // 0x80084768: addiu       $s2, $s2, 0x1C
    ctx->r18 = ADD32(ctx->r18, 0X1C);
L_8008476C:
    // 0x8008476C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80084770: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80084774: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80084778: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8008477C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80084780: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80084784: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80084788: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8008478C: jr          $ra
    // 0x80084790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80084790: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void divider_clear_coverage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800776B8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800776BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800776C0: jal         0x8007A970
    // 0x800776C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800776C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800776C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800776CC: srl         $a1, $v0, 16
    ctx->r5 = S32(U32(ctx->r2) >> 16);
    // 0x800776D0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800776D4: srl         $t6, $a1, 7
    ctx->r14 = S32(U32(ctx->r5) >> 7);
    // 0x800776D8: sll         $t2, $t6, 2
    ctx->r10 = S32(ctx->r14 << 2);
    // 0x800776DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800776E0: lui         $t7, 0xBA00
    ctx->r15 = S32(0XBA00 << 16);
    // 0x800776E4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800776E8: ori         $t7, $t7, 0x1402
    ctx->r15 = ctx->r15 | 0X1402;
    // 0x800776EC: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x800776F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800776F4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800776F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800776FC: srl         $t8, $a2, 8
    ctx->r24 = S32(U32(ctx->r6) >> 8);
    // 0x80077700: sll         $ra, $t8, 2
    ctx->r31 = S32(ctx->r24 << 2);
    // 0x80077704: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077708: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8007770C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80077710: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077714: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80077718: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8007771C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077720: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80077724: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077728: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x8007772C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80077730: lui         $t8, 0xB900
    ctx->r24 = S32(0XB900 << 16);
    // 0x80077734: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80077738: ori         $t8, $t8, 0x31D
    ctx->r24 = ctx->r24 | 0X31D;
    // 0x8007773C: ori         $t9, $t9, 0x4240
    ctx->r25 = ctx->r25 | 0X4240;
    // 0x80077740: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077744: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80077748: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8007774C: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80077750: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80077754: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80077758: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007775C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077760: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80077764: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80077768: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8007776C: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x80077770: jal         0x80066450
    // 0x80077774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80077774: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80077778: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007777C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80077780: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80077784: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80077788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007778C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80077790: beq         $v0, $at, L_800777B8
    if (ctx->r2 == ctx->r1) {
        // 0x80077794: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_800777B8;
    }
    // 0x80077794: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x80077798: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007779C: beq         $v0, $at, L_80077800
    if (ctx->r2 == ctx->r1) {
        // 0x800777A0: lui         $t0, 0xF600
        ctx->r8 = S32(0XF600 << 16);
            goto L_80077800;
    }
    // 0x800777A0: lui         $t0, 0xF600
    ctx->r8 = S32(0XF600 << 16);
    // 0x800777A4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800777A8: beq         $v0, $at, L_80077800
    if (ctx->r2 == ctx->r1) {
        // 0x800777AC: nop
    
            goto L_80077800;
    }
    // 0x800777AC: nop

    // 0x800777B0: b           L_8007788C
    // 0x800777B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8007788C;
    // 0x800777B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800777B8:
    // 0x800777B8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800777BC: srl         $t9, $t4, 1
    ctx->r25 = S32(U32(ctx->r12) >> 1);
    // 0x800777C0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800777C4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800777C8: srl         $t6, $t2, 1
    ctx->r14 = S32(U32(ctx->r10) >> 1);
    // 0x800777CC: andi        $t7, $t5, 0x3FF
    ctx->r15 = ctx->r13 & 0X3FF;
    // 0x800777D0: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x800777D4: subu        $v0, $t9, $t6
    ctx->r2 = SUB32(ctx->r25, ctx->r14);
    // 0x800777D8: addu        $t6, $v0, $t2
    ctx->r14 = ADD32(ctx->r2, ctx->r10);
    // 0x800777DC: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800777E0: or          $t9, $t8, $t0
    ctx->r25 = ctx->r24 | ctx->r8;
    // 0x800777E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800777E8: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800777EC: andi        $t7, $v0, 0x3FF
    ctx->r15 = ctx->r2 & 0X3FF;
    // 0x800777F0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800777F4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800777F8: b           L_80077888
    // 0x800777FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_80077888;
    // 0x800777FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80077800:
    // 0x80077800: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077804: srl         $t6, $t4, 1
    ctx->r14 = S32(U32(ctx->r12) >> 1);
    // 0x80077808: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8007780C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80077810: srl         $t7, $t2, 1
    ctx->r15 = S32(U32(ctx->r10) >> 1);
    // 0x80077814: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x80077818: sll         $t8, $t9, 14
    ctx->r24 = S32(ctx->r25 << 14);
    // 0x8007781C: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80077820: addu        $t7, $v0, $t2
    ctx->r15 = ADD32(ctx->r2, ctx->r10);
    // 0x80077824: andi        $t9, $t7, 0x3FF
    ctx->r25 = ctx->r15 & 0X3FF;
    // 0x80077828: or          $t6, $t8, $t0
    ctx->r14 = ctx->r24 | ctx->r8;
    // 0x8007782C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80077830: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80077834: andi        $t9, $v0, 0x3FF
    ctx->r25 = ctx->r2 & 0X3FF;
    // 0x80077838: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007783C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80077840: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80077844: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80077848: srl         $t7, $t5, 1
    ctx->r15 = S32(U32(ctx->r13) >> 1);
    // 0x8007784C: srl         $t9, $ra, 1
    ctx->r25 = S32(U32(ctx->r31) >> 1);
    // 0x80077850: subu        $a2, $t7, $t9
    ctx->r6 = SUB32(ctx->r15, ctx->r25);
    // 0x80077854: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80077858: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007785C: addu        $t6, $a2, $ra
    ctx->r14 = ADD32(ctx->r6, ctx->r31);
    // 0x80077860: andi        $t8, $t6, 0x3FF
    ctx->r24 = ctx->r14 & 0X3FF;
    // 0x80077864: sll         $t7, $t8, 14
    ctx->r15 = S32(ctx->r24 << 14);
    // 0x80077868: andi        $t6, $t4, 0x3FF
    ctx->r14 = ctx->r12 & 0X3FF;
    // 0x8007786C: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80077870: or          $t9, $t7, $t0
    ctx->r25 = ctx->r15 | ctx->r8;
    // 0x80077874: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80077878: andi        $t6, $a2, 0x3FF
    ctx->r14 = ctx->r6 & 0X3FF;
    // 0x8007787C: sll         $t9, $t6, 14
    ctx->r25 = S32(ctx->r14 << 14);
    // 0x80077880: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80077884: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80077888:
    // 0x80077888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007788C:
    // 0x8007788C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80077890: jr          $ra
    // 0x80077894: nop

    return;
    // 0x80077894: nop

;}
RECOMP_FUNC void should_taj_teleport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800521C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800521CC: addiu       $v1, $v1, -0x24FE
    ctx->r3 = ADD32(ctx->r3, -0X24FE);
    // 0x800521D0: lb          $t6, 0x0($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X0);
    // 0x800521D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800521D8: bne         $t6, $at, L_800521EC
    if (ctx->r14 != ctx->r1) {
        // 0x800521DC: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_800521EC;
    }
    // 0x800521DC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800521E0: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800521E4: jr          $ra
    // 0x800521E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800521E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800521EC:
    // 0x800521EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800521F0: jr          $ra
    // 0x800521F4: nop

    return;
    // 0x800521F4: nop

;}
RECOMP_FUNC void obj_loop_animcar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003880C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038814: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038818: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x8003881C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80038820: beq         $v0, $zero, L_8003883C
    if (ctx->r2 == 0) {
        // 0x80038824: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8003883C;
    }
    // 0x80038824: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038828: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8003882C: jal         0x8001BAFC
    // 0x80038830: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x80038830: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_0:
    // 0x80038834: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80038838: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8003883C:
    // 0x8003883C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038840: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80038844: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80038848: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8003884C: jal         0x8001F494
    // 0x80038850: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    func_8001F460(rdram, ctx);
        goto after_1;
    // 0x80038850: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_1:
    // 0x80038854: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80038858: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003885C: lh          $t6, 0x6($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X6);
    // 0x80038860: sw          $v0, 0x7C($a3)
    MEM_W(0X7C, ctx->r7) = ctx->r2;
    // 0x80038864: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80038868: bne         $v0, $zero, L_80038884
    if (ctx->r2 != 0) {
        // 0x8003886C: sh          $t7, 0x6($a3)
        MEM_H(0X6, ctx->r7) = ctx->r15;
            goto L_80038884;
    }
    // 0x8003886C: sh          $t7, 0x6($a3)
    MEM_H(0X6, ctx->r7) = ctx->r15;
    // 0x80038870: beq         $v1, $zero, L_80038888
    if (ctx->r3 == 0) {
        // 0x80038874: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80038888;
    }
    // 0x80038874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038878: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003887C: nop

    // 0x80038880: sw          $a3, 0x148($v0)
    MEM_W(0X148, ctx->r2) = ctx->r7;
L_80038884:
    // 0x80038884: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80038888:
    // 0x80038888: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003888C: jr          $ra
    // 0x80038890: nop

    return;
    // 0x80038890: nop

;}
RECOMP_FUNC void hud_course_arrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A13F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A13F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A13FC: lbu         $t6, 0x2D10($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X2D10);
    // 0x800A1400: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A1404: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1408: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800A140C: beq         $t6, $zero, L_800A1778
    if (ctx->r14 == 0) {
        // 0x800A1410: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800A1778;
    }
    // 0x800A1410: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A1414: lb          $v0, 0x1F9($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X1F9);
    // 0x800A1418: nop

    // 0x800A141C: blez        $v0, L_800A1634
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A1420: lw          $t9, 0x20($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X20);
            goto L_800A1634;
    }
    // 0x800A1420: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800A1424: lbu         $v1, 0x1F8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1F8);
    // 0x800A1428: subu        $t9, $v0, $a1
    ctx->r25 = SUB32(ctx->r2, ctx->r5);
    // 0x800A142C: beq         $v1, $zero, L_800A161C
    if (ctx->r3 == 0) {
        // 0x800A1430: sb          $t9, 0x1F9($a0)
        MEM_B(0X1F9, ctx->r4) = ctx->r25;
            goto L_800A161C;
    }
    // 0x800A1430: sb          $t9, 0x1F9($a0)
    MEM_B(0X1F9, ctx->r4) = ctx->r25;
    // 0x800A1434: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1438: lw          $s0, 0x729C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X729C);
    // 0x800A143C: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800A1440: sltiu       $at, $t1, 0x8
    ctx->r1 = ctx->r9 < 0X8 ? 1 : 0;
    // 0x800A1444: beq         $at, $zero, L_800A14FC
    if (ctx->r1 == 0) {
        // 0x800A1448: addiu       $s0, $s0, 0x420
        ctx->r16 = ADD32(ctx->r16, 0X420);
            goto L_800A14FC;
    }
    // 0x800A1448: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A144C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A1450: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1454: addu        $at, $at, $t1
    gpr jr_addend_800A1460 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x800A1458: lw          $t1, -0x7388($at)
    ctx->r9 = ADD32(ctx->r1, -0X7388);
    // 0x800A145C: nop

    // 0x800A1460: jr          $t1
    // 0x800A1464: nop

    switch (jr_addend_800A1460 >> 2) {
        case 0: goto L_800A1468; break;
        case 1: goto L_800A1478; break;
        case 2: goto L_800A1488; break;
        case 3: goto L_800A1498; break;
        case 4: goto L_800A14AC; break;
        case 5: goto L_800A14C0; break;
        case 6: goto L_800A14D4; break;
        case 7: goto L_800A14EC; break;
        default: switch_error(__func__, 0x800A1460, 0x800E8C78);
    }
    // 0x800A1464: nop

L_800A1468:
    // 0x800A1468: addiu       $t2, $zero, 0x21
    ctx->r10 = ADD32(0, 0X21);
    // 0x800A146C: sh          $t2, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r10;
    // 0x800A1470: b           L_800A1508
    // 0x800A1474: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1474: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1478:
    // 0x800A1478: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800A147C: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x800A1480: b           L_800A1508
    // 0x800A1484: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1484: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1488:
    // 0x800A1488: addiu       $t4, $zero, 0x1F
    ctx->r12 = ADD32(0, 0X1F);
    // 0x800A148C: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x800A1490: b           L_800A1508
    // 0x800A1494: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A1494: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1498:
    // 0x800A1498: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A149C: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x800A14A0: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x800A14A4: b           L_800A1508
    // 0x800A14A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14A8: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14AC:
    // 0x800A14AC: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14B0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x800A14B4: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x800A14B8: b           L_800A1508
    // 0x800A14BC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14BC: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14C0:
    // 0x800A14C0: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14C4: addiu       $t8, $zero, 0x1F
    ctx->r24 = ADD32(0, 0X1F);
    // 0x800A14C8: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
    // 0x800A14CC: b           L_800A1508
    // 0x800A14D0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14D0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_800A14D4:
    // 0x800A14D4: addiu       $v0, $zero, -0x8000
    ctx->r2 = ADD32(0, -0X8000);
    // 0x800A14D8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800A14DC: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x800A14E0: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x800A14E4: b           L_800A1508
    // 0x800A14E8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
        goto L_800A1508;
    // 0x800A14E8: sh          $v0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r2;
L_800A14EC:
    // 0x800A14EC: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x800A14F0: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x800A14F4: b           L_800A1508
    // 0x800A14F8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
        goto L_800A1508;
    // 0x800A14F8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A14FC:
    // 0x800A14FC: addiu       $t1, $zero, 0x1D
    ctx->r9 = ADD32(0, 0X1D);
    // 0x800A1500: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x800A1504: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_800A1508:
    // 0x800A1508: jal         0x8009C850
    // 0x800A150C: nop

    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x800A150C: nop

    after_0:
    // 0x800A1510: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x800A1514: beq         $t2, $zero, L_800A1548
    if (ctx->r10 == 0) {
        // 0x800A1518: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_800A1548;
    }
    // 0x800A1518: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A151C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A1520: nop

    // 0x800A1524: lbu         $t3, 0x1F8($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A1528: nop

    // 0x800A152C: slti        $at, $t3, 0x1E
    ctx->r1 = SIGNED(ctx->r11) < 0X1E ? 1 : 0;
    // 0x800A1530: beq         $at, $zero, L_800A1548
    if (ctx->r1 == 0) {
        // 0x800A1534: nop
    
            goto L_800A1548;
    }
    // 0x800A1534: nop

    // 0x800A1538: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x800A153C: ori         $t5, $zero, 0x8000
    ctx->r13 = 0 | 0X8000;
    // 0x800A1540: subu        $t6, $t5, $t4
    ctx->r14 = SUB32(ctx->r13, ctx->r12);
    // 0x800A1544: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_800A1548:
    // 0x800A1548: lw          $t8, 0x72CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72CC);
    // 0x800A154C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800A1550: bne         $t8, $zero, L_800A161C
    if (ctx->r24 != 0) {
        // 0x800A1554: nop
    
            goto L_800A161C;
    }
    // 0x800A1554: nop

    // 0x800A1558: lb          $t9, 0x1D8($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X1D8);
    // 0x800A155C: nop

    // 0x800A1560: bne         $t9, $zero, L_800A161C
    if (ctx->r25 != 0) {
        // 0x800A1564: nop
    
            goto L_800A161C;
    }
    // 0x800A1564: nop

    // 0x800A1568: lbu         $t7, 0x1F8($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1F8);
    // 0x800A156C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A1570: beq         $t7, $zero, L_800A161C
    if (ctx->r15 == 0) {
        // 0x800A1574: nop
    
            goto L_800A161C;
    }
    // 0x800A1574: nop

    // 0x800A1578: lbu         $t1, 0x2D38($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X2D38);
    // 0x800A157C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A1580: bne         $t1, $zero, L_800A161C
    if (ctx->r9 != 0) {
        // 0x800A1584: addiu       $a0, $a0, 0x72BC
        ctx->r4 = ADD32(ctx->r4, 0X72BC);
            goto L_800A161C;
    }
    // 0x800A1584: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A1588: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A158C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A1590: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A1594: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A1598: addiu       $t5, $zero, -0x60
    ctx->r13 = ADD32(0, -0X60);
    // 0x800A159C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15A0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A15A4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A15A8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A15AC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800A15B0: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A15B4: jal         0x800AAB5C
    // 0x800A15B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A15B8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    after_1:
    // 0x800A15BC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A15C0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A15C4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A15CC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A15D0: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A15D4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A15D8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A15DC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A15E0: jal         0x800AAB5C
    // 0x800A15E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A15E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x800A15E8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A15EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A15F0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800A15F4: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A15F8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x800A15FC: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A1600: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A1604: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A1608: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A160C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800A1610: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800A1614: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A1618: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800A161C:
    // 0x800A161C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A1620: lbu         $v0, 0x2D38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D38);
    // 0x800A1624: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1628: b           L_800A1648
    // 0x800A162C: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
        goto L_800A1648;
    // 0x800A162C: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
    // 0x800A1630: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
L_800A1634:
    // 0x800A1634: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A1638: sb          $zero, 0x1F9($t9)
    MEM_B(0X1F9, ctx->r25) = 0;
    // 0x800A163C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A1640: lbu         $v0, 0x2D38($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2D38);
    // 0x800A1644: addiu       $a1, $a1, 0x72BC
    ctx->r5 = ADD32(ctx->r5, 0X72BC);
L_800A1648:
    // 0x800A1648: beq         $v0, $zero, L_800A1778
    if (ctx->r2 == 0) {
        // 0x800A164C: andi        $t7, $v0, 0x20
        ctx->r15 = ctx->r2 & 0X20;
            goto L_800A1778;
    }
    // 0x800A164C: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x800A1650: beq         $t7, $zero, L_800A1750
    if (ctx->r15 == 0) {
        // 0x800A1654: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A1750;
    }
    // 0x800A1654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A1658: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A165C: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A1660: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800A1664: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800A1668: addiu       $t3, $zero, -0x60
    ctx->r11 = ADD32(0, -0X60);
    // 0x800A166C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A1670: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A1674: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A1678: lw          $s0, 0x729C($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X729C);
    // 0x800A167C: addiu       $t5, $zero, 0x1D
    ctx->r13 = ADD32(0, 0X1D);
    // 0x800A1680: addiu       $s0, $s0, 0x420
    ctx->r16 = ADD32(ctx->r16, 0X420);
    // 0x800A1684: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
    // 0x800A1688: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x800A168C: jal         0x8009C850
    // 0x800A1690: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    get_filtered_cheats(rdram, ctx);
        goto after_3;
    // 0x800A1690: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    after_3:
    // 0x800A1694: andi        $t4, $v0, 0x4
    ctx->r12 = ctx->r2 & 0X4;
    // 0x800A1698: beq         $t4, $zero, L_800A16CC
    if (ctx->r12 == 0) {
        // 0x800A169C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A16CC;
    }
    // 0x800A169C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A16A0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800A16A4: nop

    // 0x800A16A8: lbu         $t8, 0x1F8($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X1F8);
    // 0x800A16AC: nop

    // 0x800A16B0: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x800A16B4: beq         $at, $zero, L_800A16CC
    if (ctx->r1 == 0) {
        // 0x800A16B8: nop
    
            goto L_800A16CC;
    }
    // 0x800A16B8: nop

    // 0x800A16BC: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x800A16C0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800A16C4: subu        $t1, $t7, $t9
    ctx->r9 = SUB32(ctx->r15, ctx->r25);
    // 0x800A16C8: sh          $t1, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r9;
L_800A16CC:
    // 0x800A16CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A16D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A16D4: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A16D8: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A16DC: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A16E0: jal         0x800AAB5C
    // 0x800A16E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A16E4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_4:
    // 0x800A16E8: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A16EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A16F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A16F4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A16F8: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800A16FC: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A1700: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A1704: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A1708: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A170C: jal         0x800AAB5C
    // 0x800A1710: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A1710: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800A1714: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A1718: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A171C: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800A1720: swc1        $f6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f6.u32l;
    // 0x800A1724: lw          $v0, 0x72BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X72BC);
    // 0x800A1728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A172C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A1730: sw          $t2, 0x72BC($at)
    MEM_W(0X72BC, ctx->r1) = ctx->r10;
    // 0x800A1734: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A1738: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A173C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800A1740: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A1744: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800A1748: lbu         $a0, 0x2D38($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2D38);
    // 0x800A174C: nop

L_800A1750:
    // 0x800A1750: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x800A1754: nop

    // 0x800A1758: slt         $at, $t4, $a0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A175C: beq         $at, $zero, L_800A1770
    if (ctx->r1 == 0) {
        // 0x800A1760: subu        $t6, $a0, $t4
        ctx->r14 = SUB32(ctx->r4, ctx->r12);
            goto L_800A1770;
    }
    // 0x800A1760: subu        $t6, $a0, $t4
    ctx->r14 = SUB32(ctx->r4, ctx->r12);
    // 0x800A1764: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1768: b           L_800A1778
    // 0x800A176C: sb          $t6, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r14;
        goto L_800A1778;
    // 0x800A176C: sb          $t6, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = ctx->r14;
L_800A1770:
    // 0x800A1770: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1774: sb          $zero, 0x2D38($at)
    MEM_B(0X2D38, ctx->r1) = 0;
L_800A1778:
    // 0x800A1778: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A177C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A1780: jr          $ra
    // 0x800A1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800A1784: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
