#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void savemenu_blank_save_destination(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80086608: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008660C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80086610: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80086614: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80086618: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8008661C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80086620: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80086624: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80086628: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008662C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80086630: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80086634: addiu       $s3, $s3, 0x6AD0
    ctx->r19 = ADD32(ctx->r19, 0X6AD0);
    // 0x80086638: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8008663C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086640: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80086644:
    // 0x80086644: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80086648: nop

    // 0x8008664C: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x80086650: nop

    // 0x80086654: beq         $t7, $zero, L_800866D4
    if (ctx->r15 == 0) {
        // 0x80086658: nop
    
            goto L_800866D4;
    }
    // 0x80086658: nop

    // 0x8008665C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80086660: nop

    // 0x80086664: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086668: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x8008666C: sb          $s4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r20;
    // 0x80086670: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80086674: nop

    // 0x80086678: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008667C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80086680: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x80086684: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086688: nop

    // 0x8008668C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086690: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80086694: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    // 0x80086698: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008669C: nop

    // 0x800866A0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800866A4: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800866A8: jal         0x80073EA4
    // 0x800866AC: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x800866AC: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    after_0:
    // 0x800866B0: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800866B4: nop

    // 0x800866B8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800866BC: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x800866C0: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x800866C4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800866C8: nop

    // 0x800866CC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800866D0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800866D4:
    // 0x800866D4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800866D8: bne         $s2, $s5, L_80086644
    if (ctx->r18 != ctx->r21) {
        // 0x800866DC: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80086644;
    }
    // 0x800866DC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800866E0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800866E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800866E8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800866EC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800866F0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800866F4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800866F8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800866FC: jr          $ra
    // 0x80086700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80086700: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void alSynStopVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9E10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9E18: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C9E1C: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9E20: beql        $t6, $zero, L_800C9E7C
    if (ctx->r14 == 0) {
        // 0x800C9E24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9E7C;
    }
    goto skip_0;
    // 0x800C9E24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C9E28: jal         0x800658A8
    // 0x800C9E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9E30: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9E34: beq         $v0, $zero, L_800C9E78
    if (ctx->r2 == 0) {
        // 0x800C9E38: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C9E78;
    }
    // 0x800C9E38: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9E3C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9E40: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9E44: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800C9E48: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9E4C: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9E50: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9E54: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C9E58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9E5C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9E60: lw          $t3, 0x8($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X8);
    // 0x800C9E64: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C9E68: lw          $a0, 0xC($t3)
    ctx->r4 = MEM_W(ctx->r11, 0XC);
    // 0x800C9E6C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9E70: jalr        $t9
    // 0x800C9E74: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9E74: nop

    after_1:
L_800C9E78:
    // 0x800C9E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9E7C:
    // 0x800C9E7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9E80: jr          $ra
    // 0x800C9E84: nop

    return;
    // 0x800C9E84: nop

;}
RECOMP_FUNC void audio_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000450: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80000454: sw          $a0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r4;
    // 0x80000458: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000045C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80000460: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80000464: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x80000468: lui         $a2, 0x2
    ctx->r6 = S32(0X2 << 16);
    // 0x8000046C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80000470: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80000474: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80000478: ori         $a2, $a2, 0x9D88
    ctx->r6 = ctx->r6 | 0X9D88;
    // 0x8000047C: addiu       $a1, $a1, -0x3B20
    ctx->r5 = ADD32(ctx->r5, -0X3B20);
    // 0x80000480: jal         0x800C7AC0
    // 0x80000484: addiu       $a0, $a0, 0x6268
    ctx->r4 = ADD32(ctx->r4, 0X6268);
    alHeapInit(rdram, ctx);
        goto after_0;
    // 0x80000484: addiu       $a0, $a0, 0x6268
    ctx->r4 = ADD32(ctx->r4, 0X6268);
    after_0:
    // 0x80000488: jal         0x80076EE4
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x8000048C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80000490: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80000494: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80000498: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x8000049C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800004A0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800004A4: jal         0x80070EDC
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800004A8: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    after_2:
    // 0x800004AC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004B0: addiu       $s0, $s0, 0x6294
    ctx->r16 = ADD32(ctx->r16, 0X6294);
    // 0x800004B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800004B8: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x800004BC: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x800004C0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800004C4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800004C8: jal         0x80077190
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800004CC: subu        $a3, $t8, $a2
    ctx->r7 = SUB32(ctx->r24, ctx->r6);
    after_3:
    // 0x800004D0: lw          $a1, 0x8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8);
    // 0x800004D4: jal         0x80077240
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_4;
    // 0x800004D8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_4:
    // 0x800004DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800004E0: jal         0x800C7C04
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_5;
    // 0x800004E4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_5:
    // 0x800004E8: lw          $t9, 0x1C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X1C);
    // 0x800004EC: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x800004F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800004F4: addiu       $s0, $s0, 0x62A8
    ctx->r16 = ADD32(ctx->r16, 0X62A8);
    // 0x800004F8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800004FC: subu        $a0, $t9, $t1
    ctx->r4 = SUB32(ctx->r25, ctx->r9);
    // 0x80000500: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    // 0x80000504: jal         0x80070EDC
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x80000508: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_6:
    // 0x8000050C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000510: addiu       $v1, $v1, 0x6298
    ctx->r3 = ADD32(ctx->r3, 0X6298);
    // 0x80000514: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000518: lw          $a2, 0x18($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X18);
    // 0x8000051C: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000520: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000524: jal         0x80077190
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_7;
    // 0x80000528: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_7:
    // 0x8000052C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80000530: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80000534: divu        $zero, $t3, $at
    lo = S32(U32(ctx->r11) / U32(ctx->r1)); hi = S32(U32(ctx->r11) % U32(ctx->r1));
    // 0x80000538: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000053C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000540: addiu       $v1, $v1, 0x62AC
    ctx->r3 = ADD32(ctx->r3, 0X62AC);
    // 0x80000544: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000548: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x8000054C: mflo        $t4
    ctx->r12 = lo;
    // 0x80000550: sw          $t4, 0x62A0($at)
    MEM_W(0X62A0, ctx->r1) = ctx->r12;
    // 0x80000554: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x80000558: lw          $t5, 0x18($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X18);
    // 0x8000055C: nop

    // 0x80000560: subu        $a0, $t5, $t6
    ctx->r4 = SUB32(ctx->r13, ctx->r14);
    // 0x80000564: jal         0x80070EDC
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x80000568: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_8:
    // 0x8000056C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80000570: addiu       $v1, $v1, 0x629C
    ctx->r3 = ADD32(ctx->r3, 0X629C);
    // 0x80000574: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80000578: addiu       $s0, $s0, 0x62AC
    ctx->r16 = ADD32(ctx->r16, 0X62AC);
    // 0x8000057C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80000580: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x80000584: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80000588: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000058C: jal         0x80077190
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_9;
    // 0x80000590: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_9:
    // 0x80000594: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80000598: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000059C: divu        $zero, $t8, $at
    lo = S32(U32(ctx->r24) / U32(ctx->r1)); hi = S32(U32(ctx->r24) % U32(ctx->r1));
    // 0x800005A0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800005A4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800005A8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800005AC: mflo        $t9
    ctx->r25 = lo;
    // 0x800005B0: sw          $t9, 0x62A4($at)
    MEM_W(0X62A4, ctx->r1) = ctx->r25;
    // 0x800005B4: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x800005B8: jal         0x80070EDC
    // 0x800005BC: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x800005BC: nop

    after_10:
    // 0x800005C0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800005C4: addiu       $s0, $s0, 0x6290
    ctx->r16 = ADD32(ctx->r16, 0X6290);
    // 0x800005C8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800005CC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800005D0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800005D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800005D8: jal         0x80077190
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_11;
    // 0x800005DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
    // 0x800005E0: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x800005E4: jal         0x80077240
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_12;
    // 0x800005E8: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_12:
    // 0x800005EC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800005F0: jal         0x800C7C04
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alBnkfNew(rdram, ctx);
        goto after_13;
    // 0x800005F4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x800005F8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800005FC: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80000600: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80000604: addiu       $a2, $a2, 0x6268
    ctx->r6 = ADD32(ctx->r6, 0X6268);
    // 0x80000608: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000060C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80000610: jal         0x800C7D50
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_14;
    // 0x80000614: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x80000618: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8000061C: addiu       $s0, $s0, 0x6278
    ctx->r16 = ADD32(ctx->r16, 0X6278);
    // 0x80000620: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80000624: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000628: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x8000062C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80000630: jal         0x80077190
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    asset_load(rdram, ctx);
        goto after_15;
    // 0x80000634: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_15:
    // 0x80000638: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000063C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000640: lh          $a3, 0x2($t2)
    ctx->r7 = MEM_H(ctx->r10, 0X2);
    // 0x80000644: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000648: sll         $t3, $a3, 3
    ctx->r11 = S32(ctx->r7 << 3);
    // 0x8000064C: addiu       $a0, $t3, 0x4
    ctx->r4 = ADD32(ctx->r11, 0X4);
    // 0x80000650: jal         0x80070EDC
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_16;
    // 0x80000654: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_16:
    // 0x80000658: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000065C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80000660: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x80000664: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80000668: jal         0x80077190
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    asset_load(rdram, ctx);
        goto after_17;
    // 0x8000066C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_17:
    // 0x80000670: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x80000674: jal         0x80077240
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    asset_rom_offset(rdram, ctx);
        goto after_18;
    // 0x80000678: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    after_18:
    // 0x8000067C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80000680: jal         0x800C7D08
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    alSeqFileNew(rdram, ctx);
        goto after_19;
    // 0x80000684: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_19:
    // 0x80000688: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000068C: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80000690: lh          $a0, 0x2($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2);
    // 0x80000694: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x80000698: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8000069C: jal         0x80070EDC
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_20;
    // 0x800006A0: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_20:
    // 0x800006A4: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800006A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800006AC: addiu       $t0, $t0, 0x628C
    ctx->r8 = ADD32(ctx->r8, 0X628C);
    // 0x800006B0: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x800006B4: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800006B8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800006BC: blez        $t6, L_80000744
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800006C0: addiu       $t5, $zero, 0x28
        ctx->r13 = ADD32(0, 0X28);
            goto L_80000744;
    }
    // 0x800006C0: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x800006C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800006C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800006CC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800006D0:
    // 0x800006D0: addu        $t7, $a0, $a3
    ctx->r15 = ADD32(ctx->r4, ctx->r7);
    // 0x800006D4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800006D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800006DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800006E0: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800006E4: nop

    // 0x800006E8: addu        $v1, $t9, $a1
    ctx->r3 = ADD32(ctx->r25, ctx->r5);
    // 0x800006EC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800006F0: nop

    // 0x800006F4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x800006F8: beq         $t1, $zero, L_80000718
    if (ctx->r9 == 0) {
        // 0x800006FC: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80000718;
    }
    // 0x800006FC: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80000700: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80000704: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x80000708: nop

    // 0x8000070C: addu        $v1, $t3, $a1
    ctx->r3 = ADD32(ctx->r11, ctx->r5);
    // 0x80000710: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80000714: nop

L_80000718:
    // 0x80000718: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8000071C: beq         $at, $zero, L_80000728
    if (ctx->r1 == 0) {
        // 0x80000720: nop
    
            goto L_80000728;
    }
    // 0x80000720: nop

    // 0x80000724: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80000728:
    // 0x80000728: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000072C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80000730: lh          $t4, 0x2($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X2);
    // 0x80000734: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000738: slt         $at, $a2, $t4
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000073C: bne         $at, $zero, L_800006D0
    if (ctx->r1 != 0) {
        // 0x80000740: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_800006D0;
    }
    // 0x80000740: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
L_80000744:
    // 0x80000744: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80000748: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x8000074C: addiu       $t7, $zero, 0x60
    ctx->r15 = ADD32(0, 0X60);
    // 0x80000750: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80000754: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80000758: addiu       $t1, $t1, 0x6268
    ctx->r9 = ADD32(ctx->r9, 0X6268);
    // 0x8000075C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80000760: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
    // 0x80000764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80000768: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8000076C: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x80000770: sb          $t8, 0x8C($sp)
    MEM_B(0X8C, ctx->r29) = ctx->r24;
    // 0x80000774: sb          $t9, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = ctx->r25;
    // 0x80000778: sw          $zero, 0x88($sp)
    MEM_W(0X88, ctx->r29) = 0;
    // 0x8000077C: sw          $t1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r9;
    // 0x80000780: addiu       $a0, $sp, 0x70
    ctx->r4 = ADD32(ctx->r29, 0X70);
    // 0x80000784: jal         0x80002660
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    amCreateAudioMgr(rdram, ctx);
        goto after_21;
    // 0x80000788: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    after_21:
    // 0x8000078C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80000790: jal         0x80002224
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    sound_seqplayer_init(rdram, ctx);
        goto after_22;
    // 0x80000794: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    after_22:
    // 0x80000798: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000079C: addiu       $v1, $v1, -0x3460
    ctx->r3 = ADD32(ctx->r3, -0X3460);
    // 0x800007A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800007A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800007A8: jal         0x8000B010
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    set_voice_limit(rdram, ctx);
        goto after_23;
    // 0x800007AC: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_23:
    // 0x800007B0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800007B4: jal         0x80002224
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    sound_seqplayer_init(rdram, ctx);
        goto after_24;
    // 0x800007B8: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    after_24:
    // 0x800007BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800007C0: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007C4: sw          $v0, -0x345C($at)
    MEM_W(-0X345C, ctx->r1) = ctx->r2;
    // 0x800007C8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007CC: jal         0x80070EDC
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_25;
    // 0x800007D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_25:
    // 0x800007D4: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007D8: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800007DC: sw          $v0, 0x627C($at)
    MEM_W(0X627C, ctx->r1) = ctx->r2;
    // 0x800007E0: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800007E4: jal         0x80070EDC
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_26;
    // 0x800007E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800007EC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x800007F0: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x800007F4: addiu       $t2, $zero, 0x96
    ctx->r10 = ADD32(0, 0X96);
    // 0x800007F8: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x800007FC: addiu       $t4, $zero, 0x10
    ctx->r12 = ADD32(0, 0X10);
    // 0x80000800: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80000804: addiu       $t6, $t6, 0x6268
    ctx->r14 = ADD32(ctx->r14, 0X6268);
    // 0x80000808: sw          $v0, 0x6280($at)
    MEM_W(0X6280, ctx->r1) = ctx->r2;
    // 0x8000080C: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x80000810: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80000814: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80000818: sh          $t5, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r13;
    // 0x8000081C: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x80000820: jal         0x800031C0
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    sndp_init_player(rdram, ctx);
        goto after_27;
    // 0x80000824: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_27:
    // 0x80000828: jal         0x80002A50
    // 0x8000082C: nop

    audioStartThread(rdram, ctx);
        goto after_28;
    // 0x8000082C: nop

    after_28:
    // 0x80000830: jal         0x80000968
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_29;
    // 0x80000834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_29:
    // 0x80000838: jal         0x80071380
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_30;
    // 0x8000083C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_30:
    // 0x80000840: jal         0x8000318C
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sndp_set_active_sound_limit(rdram, ctx);
        goto after_31;
    // 0x80000844: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_31:
    // 0x80000848: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000084C: sw          $zero, -0x3448($at)
    MEM_W(-0X3448, ctx->r1) = 0;
    // 0x80000850: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000854: sb          $zero, 0x62C0($at)
    MEM_B(0X62C0, ctx->r1) = 0;
    // 0x80000858: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000085C: sb          $zero, 0x62C1($at)
    MEM_B(0X62C1, ctx->r1) = 0;
    // 0x80000860: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000864: sw          $zero, -0x3438($at)
    MEM_W(-0X3438, ctx->r1) = 0;
    // 0x80000868: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000086C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80000870: sb          $zero, 0x64F8($at)
    MEM_B(0X64F8, ctx->r1) = 0;
    // 0x80000874: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80000878: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000087C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80000880: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80000884: sb          $zero, 0x64F9($at)
    MEM_B(0X64F9, ctx->r1) = 0;
    // 0x80000888: jr          $ra
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000088C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void emitter_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF740: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AF744: lw          $t6, 0x3284($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3284);
    // 0x800AF748: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AF74C: slt         $at, $a1, $t6
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800AF750: beq         $at, $zero, L_800AF7EC
    if (ctx->r1 == 0) {
        // 0x800AF754: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AF7EC;
    }
    // 0x800AF754: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AF758: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AF75C: lw          $t7, 0x328C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X328C);
    // 0x800AF760: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800AF764: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800AF768: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800AF76C: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800AF770: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800AF774: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF778: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF77C: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800AF780: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800AF784: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800AF788: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800AF78C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800AF790: nop

    // 0x800AF794: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800AF798: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AF79C: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800AF7A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF7A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF7A8: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AF7AC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800AF7B0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800AF7B4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800AF7B8: nop

    // 0x800AF7BC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800AF7C0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800AF7C4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800AF7C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800AF7CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800AF7D0: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AF7D4: nop

    // 0x800AF7D8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800AF7DC: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800AF7E0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800AF7E4: jal         0x800AF7FC
    // 0x800AF7E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    emitter_init_with_pos(rdram, ctx);
        goto after_0;
    // 0x800AF7E8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
L_800AF7EC:
    // 0x800AF7EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AF7F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AF7F4: jr          $ra
    // 0x800AF7F8: nop

    return;
    // 0x800AF7F8: nop

;}
RECOMP_FUNC void set_anti_aliasing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028FE4: jr          $ra
    // 0x80028FE8: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
    return;
    // 0x80028FE8: sw          $a0, -0x4984($at)
    MEM_W(-0X4984, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_unknown25(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AAC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038AB0: jr          $ra
    // 0x80038AB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038AB4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void cam_shake_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066314: jr          $ra
    // 0x80066318: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
    return;
    // 0x80066318: sw          $zero, 0x1298($at)
    MEM_W(0X1298, ctx->r1) = 0;
;}
RECOMP_FUNC void obj_init_lavaspurt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800375B8: lbu         $t6, 0x9($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X9);
    // 0x800375BC: nop

    // 0x800375C0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800375C4: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
    // 0x800375C8: lbu         $t8, 0x8($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X8);
    // 0x800375CC: jr          $ra
    // 0x800375D0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
    return;
    // 0x800375D0: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void racer_calc_distance_to_opponent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B868: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B86C: lw          $v0, -0x4BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4BB0);
    // 0x8001B870: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8001B874: bgtz        $v0, L_8001B888
    if (SIGNED(ctx->r2) > 0) {
        // 0x8001B878: nop
    
            goto L_8001B888;
    }
    // 0x8001B878: nop

    // 0x8001B87C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001B880: jr          $ra
    // 0x8001B884: nop

    return;
    // 0x8001B884: nop

L_8001B888:
    // 0x8001B888: lh          $a0, 0x190($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X190);
    // 0x8001B88C: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B890: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B894: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001B898: beq         $at, $zero, L_8001B8B8
    if (ctx->r1 == 0) {
        // 0x8001B89C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8001B8B8;
    }
    // 0x8001B89C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001B8A0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x8001B8A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8001B8A8: lh          $a3, 0x190($a2)
    ctx->r7 = MEM_H(ctx->r6, 0X190);
    // 0x8001B8AC: lh          $a0, 0x190($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X190);
    // 0x8001B8B0: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    // 0x8001B8B4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001B8B8:
    // 0x8001B8B8: lb          $t1, 0x192($a2)
    ctx->r9 = MEM_B(ctx->r6, 0X192);
    // 0x8001B8BC: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B8C0: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8001B8C4: beq         $at, $zero, L_8001B908
    if (ctx->r1 == 0) {
        // 0x8001B8C8: or          $t0, $t1, $zero
        ctx->r8 = ctx->r9 | 0;
            goto L_8001B908;
    }
    // 0x8001B8C8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001B8CC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B8D0: lw          $a3, -0x4BB4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB4);
    // 0x8001B8D4: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
L_8001B8D8:
    // 0x8001B8D8: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B8DC: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8001B8E0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8001B8E4: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001B8E8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001B8EC: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x8001B8F0: lwc1        $f4, 0x20($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X20);
    // 0x8001B8F4: bne         $t0, $v0, L_8001B900
    if (ctx->r8 != ctx->r2) {
        // 0x8001B8F8: add.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8001B900;
    }
    // 0x8001B8F8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8001B8FC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8001B900:
    // 0x8001B900: bne         $at, $zero, L_8001B8D8
    if (ctx->r1 != 0) {
        // 0x8001B904: nop
    
            goto L_8001B8D8;
    }
    // 0x8001B904: nop

L_8001B908:
    // 0x8001B908: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001B90C: addiu       $t0, $t1, -0x1
    ctx->r8 = ADD32(ctx->r9, -0X1);
    // 0x8001B910: lw          $a3, -0x4BB4($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X4BB4);
    // 0x8001B914: bgez        $t0, L_8001B920
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B918: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_8001B920;
    }
    // 0x8001B918: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x8001B91C: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B920:
    // 0x8001B920: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B924: lwc1        $f8, 0xA8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XA8);
    // 0x8001B928: lb          $t0, 0x192($a1)
    ctx->r8 = MEM_B(ctx->r5, 0X192);
    // 0x8001B92C: nop

    // 0x8001B930: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8001B934: mflo        $t8
    ctx->r24 = lo;
    // 0x8001B938: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x8001B93C: lwc1        $f6, 0x20($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X20);
    // 0x8001B940: nop

    // 0x8001B944: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001B948: bgez        $t0, L_8001B954
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8001B94C: add.s       $f2, $f2, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
            goto L_8001B954;
    }
    // 0x8001B94C: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8001B950: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
L_8001B954:
    // 0x8001B954: multu       $t0, $t3
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B958: lwc1        $f18, 0xA8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XA8);
    // 0x8001B95C: mflo        $t4
    ctx->r12 = lo;
    // 0x8001B960: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x8001B964: lwc1        $f16, 0x20($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X20);
    // 0x8001B968: nop

    // 0x8001B96C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001B970: beq         $v1, $zero, L_8001B97C
    if (ctx->r3 == 0) {
        // 0x8001B974: sub.s       $f2, $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_8001B97C;
    }
    // 0x8001B974: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8001B978: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_8001B97C:
    // 0x8001B97C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8001B980: jr          $ra
    // 0x8001B984: nop

    return;
    // 0x8001B984: nop

;}
RECOMP_FUNC void run_object_loop_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023F7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80023F80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80023F84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80023F88: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80023F8C: lh          $a1, 0x4A($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X4A);
    // 0x80023F90: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x80023F94: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80023F98: jal         0x800B7BD8
    // 0x80023F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_0;
    // 0x80023F9C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80023FA0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80023FA4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80023FA8: lh          $t6, 0x48($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X48);
    // 0x80023FAC: nop

    // 0x80023FB0: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x80023FB4: sltiu       $at, $t7, 0x76
    ctx->r1 = ctx->r15 < 0X76 ? 1 : 0;
    // 0x80023FB8: beq         $at, $zero, L_800245A4
    if (ctx->r1 == 0) {
        // 0x80023FBC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800245A4;
    }
    // 0x80023FBC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80023FC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80023FC4: addu        $at, $at, $t7
    gpr jr_addend_80023FD0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80023FC8: lw          $t7, 0x619C($at)
    ctx->r15 = ADD32(ctx->r1, 0X619C);
    // 0x80023FCC: nop

    // 0x80023FD0: jr          $t7
    // 0x80023FD4: nop

    switch (jr_addend_80023FD0 >> 2) {
        case 0: goto L_80023FD8; break;
        case 1: goto L_80023FEC; break;
        case 2: goto L_80024000; break;
        case 3: goto L_8002413C; break;
        case 4: goto L_80024014; break;
        case 5: goto L_80024050; break;
        case 6: goto L_800245A4; break;
        case 7: goto L_800245A4; break;
        case 8: goto L_80024064; break;
        case 9: goto L_80024078; break;
        case 10: goto L_8002408C; break;
        case 11: goto L_800240A0; break;
        case 12: goto L_800240DC; break;
        case 13: goto L_800240F0; break;
        case 14: goto L_80024100; break;
        case 15: goto L_80024114; break;
        case 16: goto L_8002413C; break;
        case 17: goto L_800245A4; break;
        case 18: goto L_800245A4; break;
        case 19: goto L_800245A4; break;
        case 20: goto L_8002403C; break;
        case 21: goto L_80024128; break;
        case 22: goto L_800245A4; break;
        case 23: goto L_80024028; break;
        case 24: goto L_80024150; break;
        case 25: goto L_800245A4; break;
        case 26: goto L_80024164; break;
        case 27: goto L_80024178; break;
        case 28: goto L_800240B4; break;
        case 29: goto L_8002418C; break;
        case 30: goto L_800241A0; break;
        case 31: goto L_800245A4; break;
        case 32: goto L_800245A4; break;
        case 33: goto L_800245A4; break;
        case 34: goto L_800241B4; break;
        case 35: goto L_800241DC; break;
        case 36: goto L_800241F0; break;
        case 37: goto L_80024204; break;
        case 38: goto L_80024218; break;
        case 39: goto L_800240C8; break;
        case 40: goto L_800245A4; break;
        case 41: goto L_800245A4; break;
        case 42: goto L_800245A4; break;
        case 43: goto L_8002422C; break;
        case 44: goto L_80024240; break;
        case 45: goto L_80024254; break;
        case 46: goto L_800245A4; break;
        case 47: goto L_800245A4; break;
        case 48: goto L_80024268; break;
        case 49: goto L_80024290; break;
        case 50: goto L_800242A4; break;
        case 51: goto L_800242B8; break;
        case 52: goto L_800242CC; break;
        case 53: goto L_800242E0; break;
        case 54: goto L_800242F4; break;
        case 55: goto L_80024308; break;
        case 56: goto L_8002431C; break;
        case 57: goto L_800245A4; break;
        case 58: goto L_80024330; break;
        case 59: goto L_80024340; break;
        case 60: goto L_80024354; break;
        case 61: goto L_800245A4; break;
        case 62: goto L_80024368; break;
        case 63: goto L_8002437C; break;
        case 64: goto L_80024390; break;
        case 65: goto L_800241C8; break;
        case 66: goto L_800243A4; break;
        case 67: goto L_800243B8; break;
        case 68: goto L_800243CC; break;
        case 69: goto L_800245A4; break;
        case 70: goto L_800243CC; break;
        case 71: goto L_800243F4; break;
        case 72: goto L_80024408; break;
        case 73: goto L_8002441C; break;
        case 74: goto L_80024430; break;
        case 75: goto L_80024444; break;
        case 76: goto L_80024458; break;
        case 77: goto L_8002446C; break;
        case 78: goto L_80024480; break;
        case 79: goto L_80024268; break;
        case 80: goto L_80024494; break;
        case 81: goto L_800245A4; break;
        case 82: goto L_800244A8; break;
        case 83: goto L_80024268; break;
        case 84: goto L_80024268; break;
        case 85: goto L_800245A4; break;
        case 86: goto L_800244BC; break;
        case 87: goto L_800245A4; break;
        case 88: goto L_800244D0; break;
        case 89: goto L_800245A4; break;
        case 90: goto L_800245A4; break;
        case 91: goto L_80024308; break;
        case 92: goto L_800244E4; break;
        case 93: goto L_800245A4; break;
        case 94: goto L_800243E0; break;
        case 95: goto L_800243E0; break;
        case 96: goto L_800244F8; break;
        case 97: goto L_800245A4; break;
        case 98: goto L_80024520; break;
        case 99: goto L_800243E0; break;
        case 100: goto L_800243E0; break;
        case 101: goto L_800243CC; break;
        case 102: goto L_800243CC; break;
        case 103: goto L_8002450C; break;
        case 104: goto L_800245A4; break;
        case 105: goto L_800245A4; break;
        case 106: goto L_80024534; break;
        case 107: goto L_80024548; break;
        case 108: goto L_800244BC; break;
        case 109: goto L_8002455C; break;
        case 110: goto L_800245A4; break;
        case 111: goto L_80024570; break;
        case 112: goto L_800245A4; break;
        case 113: goto L_80024584; break;
        case 114: goto L_80024534; break;
        case 115: goto L_80024598; break;
        case 116: goto L_800245A4; break;
        case 117: goto L_8002427C; break;
        default: switch_error(__func__, 0x80023FD0, 0x800E619C);
    }
    // 0x80023FD4: nop

L_80023FD8:
    // 0x80023FD8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FDC: jal         0x80033E10
    // 0x80023FE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_scenery(rdram, ctx);
        goto after_1;
    // 0x80023FE0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80023FE4: b           L_800245A8
    // 0x80023FE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80023FE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023FEC:
    // 0x80023FEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80023FF0: jal         0x80037114
    // 0x80023FF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fish(rdram, ctx);
        goto after_2;
    // 0x80023FF4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_2:
    // 0x80023FF8: b           L_800245A8
    // 0x80023FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80023FFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024000:
    // 0x80024000: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024004: jal         0x80037824
    // 0x80024008: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animator(rdram, ctx);
        goto after_3;
    // 0x80024008: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_3:
    // 0x8002400C: b           L_800245A8
    // 0x80024010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024010: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024014:
    // 0x80024014: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024018: jal         0x800389F8
    // 0x8002401C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_smoke(rdram, ctx);
        goto after_4;
    // 0x8002401C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_4:
    // 0x80024020: b           L_800245A8
    // 0x80024024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024024: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024028:
    // 0x80024028: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002402C: jal         0x80038AB8
    // 0x80024030: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown25(rdram, ctx);
        goto after_5;
    // 0x80024030: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_5:
    // 0x80024034: b           L_800245A8
    // 0x80024038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024038: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002403C:
    // 0x8002403C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024040: jal         0x80038C34
    // 0x80024044: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bombexplosion(rdram, ctx);
        goto after_6;
    // 0x80024044: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_6:
    // 0x80024048: b           L_800245A8
    // 0x8002404C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002404C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024050:
    // 0x80024050: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024054: jal         0x80038F98
    // 0x80024058: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_exit(rdram, ctx);
        goto after_7;
    // 0x80024058: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_7:
    // 0x8002405C: b           L_800245A8
    // 0x80024060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024060: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024064:
    // 0x80024064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024068: jal         0x800391C4
    // 0x8002406C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_cameracontrol(rdram, ctx);
        goto after_8;
    // 0x8002406C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x80024070: b           L_800245A8
    // 0x80024074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024074: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024078:
    // 0x80024078: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002407C: jal         0x800391FC
    // 0x80024080: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_setuppoint(rdram, ctx);
        goto after_9;
    // 0x80024080: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_9:
    // 0x80024084: b           L_800245A8
    // 0x80024088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024088: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002408C:
    // 0x8002408C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024090: jal         0x8003923C
    // 0x80024094: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dino_whale(rdram, ctx);
        goto after_10;
    // 0x80024094: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_10:
    // 0x80024098: b           L_800245A8
    // 0x8002409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002409C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240A0:
    // 0x800240A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240A4: jal         0x8003AD68
    // 0x800240A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_checkpoint(rdram, ctx);
        goto after_11;
    // 0x800240A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_11:
    // 0x800240AC: b           L_800245A8
    // 0x800240B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240B4:
    // 0x800240B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240B8: jal         0x8003AE90
    // 0x800240BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_modechange(rdram, ctx);
        goto after_12;
    // 0x800240BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_12:
    // 0x800240C0: b           L_800245A8
    // 0x800240C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240C8:
    // 0x800240C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240CC: jal         0x8003B1B4
    // 0x800240D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bonus(rdram, ctx);
        goto after_13;
    // 0x800240D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_13:
    // 0x800240D4: b           L_800245A8
    // 0x800240D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240DC:
    // 0x800240DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800240E0: jal         0x8003B9C8
    // 0x800240E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_door(rdram, ctx);
        goto after_14;
    // 0x800240E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_14:
    // 0x800240E8: b           L_800245A8
    // 0x800240EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800240F0:
    // 0x800240F0: jal         0x80030AB4
    // 0x800240F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_fogchanger(rdram, ctx);
        goto after_15;
    // 0x800240F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_15:
    // 0x800240F8: b           L_800245A8
    // 0x800240FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800240FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024100:
    // 0x80024100: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024104: jal         0x8003D06C
    // 0x80024108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ainode(rdram, ctx);
        goto after_16;
    // 0x80024108: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_16:
    // 0x8002410C: b           L_800245A8
    // 0x80024110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024110: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024114:
    // 0x80024114: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024118: jal         0x8003E180
    // 0x8002411C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weaponballoon(rdram, ctx);
        goto after_17;
    // 0x8002411C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_17:
    // 0x80024120: b           L_800245A8
    // 0x80024124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024124: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024128:
    // 0x80024128: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002412C: jal         0x8003E5FC
    // 0x80024130: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wballoonpop(rdram, ctx);
        goto after_18;
    // 0x80024130: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_18:
    // 0x80024134: b           L_800245A8
    // 0x80024138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024138: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002413C:
    // 0x8002413C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024140: jal         0x8003E670
    // 0x80024144: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weapon(rdram, ctx);
        goto after_19;
    // 0x80024144: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_19:
    // 0x80024148: b           L_800245A8
    // 0x8002414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002414C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024150:
    // 0x80024150: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024154: jal         0x8003CFD8
    // 0x80024158: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_skycontrol(rdram, ctx);
        goto after_20;
    // 0x80024158: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_20:
    // 0x8002415C: b           L_800245A8
    // 0x80024160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024160: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024164:
    // 0x80024164: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024168: jal         0x80034B8C
    // 0x8002416C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_torch_mist(rdram, ctx);
        goto after_21;
    // 0x8002416C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_21:
    // 0x80024170: b           L_800245A8
    // 0x80024174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024178:
    // 0x80024178: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002417C: jal         0x80040188
    // 0x80024180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_texscroll(rdram, ctx);
        goto after_22;
    // 0x80024180: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_22:
    // 0x80024184: b           L_800245A8
    // 0x80024188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024188: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002418C:
    // 0x8002418C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024190: jal         0x80036220
    // 0x80024194: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_stopwatchman(rdram, ctx);
        goto after_23;
    // 0x80024194: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_23:
    // 0x80024198: b           L_800245A8
    // 0x8002419C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002419C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241A0:
    // 0x800241A0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241A4: jal         0x8003D5E0
    // 0x800241A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_banana(rdram, ctx);
        goto after_24;
    // 0x800241A8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_24:
    // 0x800241AC: b           L_800245A8
    // 0x800241B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241B4:
    // 0x800241B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241B8: jal         0x80040488
    // 0x800241BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_buoy_pirateship(rdram, ctx);
        goto after_25;
    // 0x800241BC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_25:
    // 0x800241C0: b           L_800245A8
    // 0x800241C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241C8:
    // 0x800241C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241CC: jal         0x800405B0
    // 0x800241D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_log(rdram, ctx);
        goto after_26;
    // 0x800241D0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_26:
    // 0x800241D4: b           L_800245A8
    // 0x800241D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241DC:
    // 0x800241DC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241E0: jal         0x80040860
    // 0x800241E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_weather(rdram, ctx);
        goto after_27;
    // 0x800241E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_27:
    // 0x800241E8: b           L_800245A8
    // 0x800241EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800241EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800241F0:
    // 0x800241F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800241F4: jal         0x8003CAA8
    // 0x800241F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bridge_whaleramp(rdram, ctx);
        goto after_28;
    // 0x800241F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_28:
    // 0x800241FC: b           L_800245A8
    // 0x80024200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024200: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024204:
    // 0x80024204: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024208: jal         0x8003CEE0
    // 0x8002420C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rampswitch(rdram, ctx);
        goto after_29;
    // 0x8002420C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_29:
    // 0x80024210: b           L_800245A8
    // 0x80024214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024218:
    // 0x80024218: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002421C: jal         0x8003CF4C
    // 0x80024220: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_seamonster(rdram, ctx);
        goto after_30;
    // 0x80024220: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_30:
    // 0x80024224: b           L_800245A8
    // 0x80024228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024228: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002422C:
    // 0x8002422C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024230: jal         0x800352A0
    // 0x80024234: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_collectegg(rdram, ctx);
        goto after_31;
    // 0x80024234: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_31:
    // 0x80024238: b           L_800245A8
    // 0x8002423C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002423C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024240:
    // 0x80024240: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024244: jal         0x8003568C
    // 0x80024248: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_eggcreator(rdram, ctx);
        goto after_32;
    // 0x80024248: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_32:
    // 0x8002424C: b           L_800245A8
    // 0x80024250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024250: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024254:
    // 0x80024254: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024258: jal         0x80035FAC
    // 0x8002425C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_characterflag(rdram, ctx);
        goto after_33;
    // 0x8002425C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_33:
    // 0x80024260: b           L_800245A8
    // 0x80024264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024268:
    // 0x80024268: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002426C: jal         0x80037D28
    // 0x80024270: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animobject(rdram, ctx);
        goto after_34;
    // 0x80024270: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_34:
    // 0x80024274: b           L_800245A8
    // 0x80024278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024278: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002427C:
    // 0x8002427C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024280: jal         0x80042D10
    // 0x80024284: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizghosts(rdram, ctx);
        goto after_35;
    // 0x80024284: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_35:
    // 0x80024288: b           L_800245A8
    // 0x8002428C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002428C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024290:
    // 0x80024290: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024294: jal         0x80038750
    // 0x80024298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcamera(rdram, ctx);
        goto after_36;
    // 0x80024298: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_36:
    // 0x8002429C: b           L_800245A8
    // 0x800242A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242A4:
    // 0x800242A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242A8: jal         0x80038914
    // 0x800242AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_infopoint(rdram, ctx);
        goto after_37;
    // 0x800242AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_37:
    // 0x800242B0: b           L_800245A8
    // 0x800242B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242B8:
    // 0x800242B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242BC: jal         0x8003880C
    // 0x800242C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_animcar(rdram, ctx);
        goto after_38;
    // 0x800242C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_38:
    // 0x800242C4: b           L_800245A8
    // 0x800242C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242CC:
    // 0x800242CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242D0: jal         0x8003837C
    // 0x800242D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_char_select(rdram, ctx);
        goto after_39;
    // 0x800242D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_39:
    // 0x800242D8: b           L_800245A8
    // 0x800242DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242E0:
    // 0x800242E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242E4: jal         0x8003C7E4
    // 0x800242E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trigger(rdram, ctx);
        goto after_40;
    // 0x800242E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_40:
    // 0x800242EC: b           L_800245A8
    // 0x800242F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800242F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800242F4:
    // 0x800242F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800242F8: jal         0x80038138
    // 0x800242FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_vehicleanim(rdram, ctx);
        goto after_41;
    // 0x800242FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_41:
    // 0x80024300: b           L_800245A8
    // 0x80024304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024304: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024308:
    // 0x80024308: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002430C: jal         0x800359AC
    // 0x80024310: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_airzippers_waterzippers(rdram, ctx);
        goto after_42;
    // 0x80024310: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_42:
    // 0x80024314: b           L_800245A8
    // 0x80024318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024318: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002431C:
    // 0x8002431C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024320: jal         0x80035E74
    // 0x80024324: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_timetrialghost(rdram, ctx);
        goto after_43;
    // 0x80024324: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_43:
    // 0x80024328: b           L_800245A8
    // 0x8002432C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002432C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024330:
    // 0x80024330: jal         0x800C04FC
    // 0x80024334: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    obj_loop_wavepower(rdram, ctx);
        goto after_44;
    // 0x80024334: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_44:
    // 0x80024338: b           L_800245A8
    // 0x8002433C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002433C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024340:
    // 0x80024340: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024344: jal         0x80040C94
    // 0x80024348: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_butterfly(rdram, ctx);
        goto after_45;
    // 0x80024348: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_45:
    // 0x8002434C: b           L_800245A8
    // 0x80024350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024354:
    // 0x80024354: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024358: jal         0x80039370
    // 0x8002435C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_parkwarden(rdram, ctx);
        goto after_46;
    // 0x8002435C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_46:
    // 0x80024360: b           L_800245A8
    // 0x80024364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024368:
    // 0x80024368: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002436C: jal         0x8003DF48
    // 0x80024370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_worldkey(rdram, ctx);
        goto after_47;
    // 0x80024370: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_47:
    // 0x80024374: b           L_800245A8
    // 0x80024378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024378: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002437C:
    // 0x8002437C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024380: jal         0x8003D43C
    // 0x80024384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bananacreator(rdram, ctx);
        goto after_48;
    // 0x80024384: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_48:
    // 0x80024388: b           L_800245A8
    // 0x8002438C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002438C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024390:
    // 0x80024390: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024394: jal         0x8003D098
    // 0x80024398: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_treasuresucker(rdram, ctx);
        goto after_49;
    // 0x80024398: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_49:
    // 0x8002439C: b           L_800245A8
    // 0x800243A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243A4:
    // 0x800243A4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243A8: jal         0x800375D4
    // 0x800243AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lavaspurt(rdram, ctx);
        goto after_50;
    // 0x800243AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_50:
    // 0x800243B0: b           L_800245A8
    // 0x800243B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243B8:
    // 0x800243B8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243BC: jal         0x8003767C
    // 0x800243C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_posarrow(rdram, ctx);
        goto after_51;
    // 0x800243C0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_51:
    // 0x800243C4: b           L_800245A8
    // 0x800243C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243CC:
    // 0x800243CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243D0: jal         0x80038200
    // 0x800243D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_hittester(rdram, ctx);
        goto after_52;
    // 0x800243D4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_52:
    // 0x800243D8: b           L_800245A8
    // 0x800243DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243E0:
    // 0x800243E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243E4: jal         0x800382BC
    // 0x800243E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_snowball(rdram, ctx);
        goto after_53;
    // 0x800243E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_53:
    // 0x800243EC: b           L_800245A8
    // 0x800243F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800243F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800243F4:
    // 0x800243F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800243F8: jal         0x80034BB4
    // 0x800243FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_effectbox(rdram, ctx);
        goto after_54;
    // 0x800243FC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_54:
    // 0x80024400: b           L_800245A8
    // 0x80024404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024404: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024408:
    // 0x80024408: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002440C: jal         0x80034EDC
    // 0x80024410: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_trophycab(rdram, ctx);
        goto after_55;
    // 0x80024410: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_55:
    // 0x80024414: b           L_800245A8
    // 0x80024418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024418: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002441C:
    // 0x8002441C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024420: jal         0x800420D0
    // 0x80024424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_bubbler(rdram, ctx);
        goto after_56;
    // 0x80024424: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_56:
    // 0x80024428: b           L_800245A8
    // 0x8002442C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002442C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024430:
    // 0x80024430: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024434: jal         0x8003D2F8
    // 0x80024438: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_flycoin(rdram, ctx);
        goto after_57;
    // 0x80024438: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_57:
    // 0x8002443C: b           L_800245A8
    // 0x80024440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024440: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024444:
    // 0x80024444: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024448: jal         0x8003B4FC
    // 0x8002444C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_goldenballoon(rdram, ctx);
        goto after_58;
    // 0x8002444C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_58:
    // 0x80024450: b           L_800245A8
    // 0x80024454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024454: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024458:
    // 0x80024458: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002445C: jal         0x800348A0
    // 0x80024460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_laserbolt(rdram, ctx);
        goto after_59;
    // 0x80024460: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_59:
    // 0x80024464: b           L_800245A8
    // 0x80024468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024468: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002446C:
    // 0x8002446C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024470: jal         0x800345E0
    // 0x80024474: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_lasergun(rdram, ctx);
        goto after_60;
    // 0x80024474: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_60:
    // 0x80024478: b           L_800245A8
    // 0x8002447C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002447C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024480:
    // 0x80024480: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024484: jal         0x8003ACE0
    // 0x80024488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_gbparkwarden(rdram, ctx);
        goto after_61;
    // 0x80024488: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_61:
    // 0x8002448C: b           L_800245A8
    // 0x80024490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024490: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024494:
    // 0x80024494: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024498: jal         0x80035C90
    // 0x8002449C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_groundzipper(rdram, ctx);
        goto after_62;
    // 0x8002449C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_62:
    // 0x800244A0: b           L_800245A8
    // 0x800244A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244A8:
    // 0x800244A8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244AC: jal         0x80037DB8
    // 0x800244B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wizpigship(rdram, ctx);
        goto after_63;
    // 0x800244B0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_63:
    // 0x800244B4: b           L_800245A8
    // 0x800244B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244B8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244BC:
    // 0x800244BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244C0: jal         0x8003DD54
    // 0x800244C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_silvercoin(rdram, ctx);
        goto after_64;
    // 0x800244C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_64:
    // 0x800244C8: b           L_800245A8
    // 0x800244CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244D0:
    // 0x800244D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244D4: jal         0x80038B14
    // 0x800244D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_wardensmoke(rdram, ctx);
        goto after_65;
    // 0x800244D8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_65:
    // 0x800244DC: b           L_800245A8
    // 0x800244E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244E4:
    // 0x800244E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244E8: jal         0x800421A0
    // 0x800244EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_unknown94(rdram, ctx);
        goto after_66;
    // 0x800244EC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_66:
    // 0x800244F0: b           L_800245A8
    // 0x800244F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x800244F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800244F8:
    // 0x800244F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800244FC: jal         0x80038E04
    // 0x80024500: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_teleport(rdram, ctx);
        goto after_67;
    // 0x80024500: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_67:
    // 0x80024504: b           L_800245A8
    // 0x80024508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024508: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002450C:
    // 0x8002450C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024510: jal         0x800421B8
    // 0x80024514: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rangetrigger(rdram, ctx);
        goto after_68;
    // 0x80024514: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_68:
    // 0x80024518: b           L_800245A8
    // 0x8002451C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002451C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024520:
    // 0x80024520: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024524: jal         0x80035814
    // 0x80024528: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_rocketsignpost(rdram, ctx);
        goto after_69;
    // 0x80024528: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_69:
    // 0x8002452C: b           L_800245A8
    // 0x80024530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024534:
    // 0x80024534: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024538: jal         0x80033FA0
    // 0x8002453C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_fireball_octoweapon(rdram, ctx);
        goto after_70;
    // 0x8002453C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_70:
    // 0x80024540: b           L_800245A8
    // 0x80024544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024544: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024548:
    // 0x80024548: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002454C: jal         0x80042330
    // 0x80024550: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_frog(rdram, ctx);
        goto after_71;
    // 0x80024550: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_71:
    // 0x80024554: b           L_800245A8
    // 0x80024558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002455C:
    // 0x8002455C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024560: jal         0x8003C324
    // 0x80024564: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_ttdoor(rdram, ctx);
        goto after_72;
    // 0x80024564: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_72:
    // 0x80024568: b           L_800245A8
    // 0x8002456C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x8002456C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024570:
    // 0x80024570: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024574: jal         0x80037D48
    // 0x80024578: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_dooropener(rdram, ctx);
        goto after_73;
    // 0x80024578: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_73:
    // 0x8002457C: b           L_800245A8
    // 0x80024580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024584:
    // 0x80024584: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80024588: jal         0x800429D8
    // 0x8002458C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_pigrocketeer(rdram, ctx);
        goto after_74;
    // 0x8002458C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_74:
    // 0x80024590: b           L_800245A8
    // 0x80024594: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800245A8;
    // 0x80024594: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024598:
    // 0x80024598: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8002459C: jal         0x80042AD0
    // 0x800245A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    obj_loop_levelname(rdram, ctx);
        goto after_75;
    // 0x800245A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_75:
L_800245A4:
    // 0x800245A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800245A8:
    // 0x800245A8: jal         0x800B7BD8
    // 0x800245AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_76;
    // 0x800245AC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_76:
    // 0x800245B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800245B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800245B8: jr          $ra
    // 0x800245BC: nop

    return;
    // 0x800245BC: nop

;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCE80: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800CCE84: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800CCE88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CCE8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800CCE90: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800CCE94: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800CCE98: jal         0x800D4EA0
    // 0x800CCE9C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x800CCE9C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800CCEA0: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800CCEA4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CCEA8: ldc1        $f6, -0x6440($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6440);
    // 0x800CCEAC: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x800CCEB0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCEB4: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800CCEB8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CCEBC: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x800CCEC0: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x800CCEC4: jal         0x800D5010
    // 0x800CCEC8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CCEC8: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800CCECC: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CCED0: jal         0x800D5180
    // 0x800CCED4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x800CCED4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x800CCED8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800CCEDC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800CCEE0: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800CCEE4: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CCEE8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800CCEEC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800CCEF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CCEF4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x800CCEF8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800CCEFC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCF00: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x800CCF04: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800CCF08: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CCF10: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800CCF14: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x800CCF18: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x800CCF1C: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800CCF20: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CCF24: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800CCF28: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x800CCF2C: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CCF30: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CCF34: nop

    // 0x800CCF38: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x800CCF3C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800CCF40: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CCF44: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF48: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800CCF4C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CCF50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCF54: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CCF58: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCF5C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CCF60: beq         $v1, $a0, L_800CCFA4
    if (ctx->r3 == ctx->r4) {
        // 0x800CCF64: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_800CCFA4;
    }
    // 0x800CCF64: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_800CCF68:
    // 0x800CCF68: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCF6C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CCF70: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CCF74: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCF78: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CCF7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCF80: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCF84: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CCF88: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800CCF8C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCF90: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800CCF94: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCF98: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCF9C: bne         $v1, $a0, L_800CCF68
    if (ctx->r3 != ctx->r4) {
        // 0x800CCFA0: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_800CCF68;
    }
    // 0x800CCFA0: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_800CCFA4:
    // 0x800CCFA4: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CCFA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800CCFAC: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x800CCFB0: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800CCFB4: nop

    // 0x800CCFB8: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800CCFBC: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x800CCFC0: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x800CCFC4: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x800CCFC8: beq         $a1, $zero, L_800CD0A0
    if (ctx->r5 == 0) {
        // 0x800CCFCC: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_800CD0A0;
    }
    // 0x800CCFCC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800CCFD0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CCFD4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CCFD8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x800CCFDC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x800CCFE0: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x800CCFE4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800CCFE8: bc1fl       L_800CCFFC
    if (!c1cs) {
        // 0x800CCFEC: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_800CCFFC;
    }
    goto skip_0;
    // 0x800CCFEC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x800CCFF0: b           L_800CD0A0
    // 0x800CCFF4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_800CD0A0;
    // 0x800CCFF4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800CCFF8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_800CCFFC:
    // 0x800CCFFC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CD000: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CD004: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800CD008: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x800CD00C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CD010: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800CD014: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CD018: nop

    // 0x800CD01C: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800CD020: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CD024: nop

    // 0x800CD028: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CD02C: beql        $t8, $zero, L_800CD080
    if (ctx->r24 == 0) {
        // 0x800CD030: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_800CD080;
    }
    goto skip_1;
    // 0x800CD030: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x800CD034: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CD038: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CD03C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CD040: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800CD044: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CD048: nop

    // 0x800CD04C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800CD050: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CD054: nop

    // 0x800CD058: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x800CD05C: bne         $t8, $zero, L_800CD074
    if (ctx->r24 != 0) {
        // 0x800CD060: nop
    
            goto L_800CD074;
    }
    // 0x800CD060: nop

    // 0x800CD064: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800CD068: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CD06C: b           L_800CD08C
    // 0x800CD070: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_800CD08C;
    // 0x800CD070: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_800CD074:
    // 0x800CD074: b           L_800CD08C
    // 0x800CD078: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_800CD08C;
    // 0x800CD078: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800CD07C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_800CD080:
    // 0x800CD080: nop

    // 0x800CD084: bltz        $t8, L_800CD074
    if (SIGNED(ctx->r24) < 0) {
        // 0x800CD088: nop
    
            goto L_800CD074;
    }
    // 0x800CD088: nop

L_800CD08C:
    // 0x800CD08C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800CD090: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CD094: bgtz        $t9, L_800CD0A0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800CD098: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_800CD0A0;
    }
    // 0x800CD098: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800CD09C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_800CD0A0:
    // 0x800CD0A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD0A4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800CD0A8: jr          $ra
    // 0x800CD0AC: nop

    return;
    // 0x800CD0AC: nop

;}
RECOMP_FUNC void music_sequence_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000232C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80002330: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80002334: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80002338: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000233C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002340: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002344: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80002348: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000234C: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80002350: jal         0x800C7FB0
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    alCSPGetState(rdram, ctx);
        goto after_0;
    // 0x80002354: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    after_0:
    // 0x80002358: bne         $v0, $zero, L_80002558
    if (ctx->r2 != 0) {
        // 0x8000235C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000235C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002360: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x80002364: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80002368: beq         $t6, $zero, L_80002558
    if (ctx->r14 == 0) {
        // 0x8000236C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80002558;
    }
    // 0x8000236C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80002370: jal         0x80077240
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    asset_rom_offset(rdram, ctx);
        goto after_1;
    // 0x80002374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80002378: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x8000237C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80002380: lw          $t7, 0x6278($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6278);
    // 0x80002384: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80002388: lw          $t1, 0x628C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X628C);
    // 0x8000238C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80002390: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80002394: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80002398: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8000239C: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800023A0: lw          $a3, 0x0($t3)
    ctx->r7 = MEM_W(ctx->r11, 0X0);
    // 0x800023A4: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800023A8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800023AC: jal         0x80077190
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x800023B0: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    after_2:
    // 0x800023B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800023B8: jal         0x800C855C
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    alCSeqNew(rdram, ctx);
        goto after_3;
    // 0x800023BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800023C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800023C4: jal         0x800C8AC0
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alCSPSetSeq(rdram, ctx);
        goto after_4;
    // 0x800023C8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x800023CC: jal         0x800C8B00
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alCSPPlay(rdram, ctx);
        goto after_5;
    // 0x800023D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800023D4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800023D8: lw          $t4, -0x3460($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X3460);
    // 0x800023DC: nop

    // 0x800023E0: bne         $s0, $t4, L_800024E8
    if (ctx->r16 != ctx->r12) {
        // 0x800023E4: nop
    
            goto L_800024E8;
    }
    // 0x800023E4: nop

    // 0x800023E8: lbu         $t6, 0x0($s3)
    ctx->r14 = MEM_BU(ctx->r19, 0X0);
    // 0x800023EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800023F0: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800023F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800023F8: addiu       $s0, $s0, 0x629C
    ctx->r16 = ADD32(ctx->r16, 0X629C);
    // 0x800023FC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80002400: mflo        $t7
    ctx->r15 = lo;
    // 0x80002404: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002408: lbu         $a0, 0x0($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X0);
    // 0x8000240C: jal         0x80001990
    // 0x80002410: nop

    music_volume_set(rdram, ctx);
        goto after_6;
    // 0x80002410: nop

    after_6:
    // 0x80002414: lbu         $t9, 0x0($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X0);
    // 0x80002418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8000241C: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002420: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80002424: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002428: mflo        $t0
    ctx->r8 = lo;
    // 0x8000242C: addu        $t1, $v0, $t0
    ctx->r9 = ADD32(ctx->r2, ctx->r8);
    // 0x80002430: lbu         $a0, 0x1($t1)
    ctx->r4 = MEM_BU(ctx->r9, 0X1);
    // 0x80002434: nop

    // 0x80002438: beq         $a0, $zero, L_80002458
    if (ctx->r4 == 0) {
        // 0x8000243C: nop
    
            goto L_80002458;
    }
    // 0x8000243C: nop

    // 0x80002440: jal         0x80001534
    // 0x80002444: nop

    music_tempo_set(rdram, ctx);
        goto after_7;
    // 0x80002444: nop

    after_7:
    // 0x80002448: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8000244C: lw          $v0, 0x629C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X629C);
    // 0x80002450: b           L_80002460
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
        goto L_80002460;
    // 0x80002454: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002458:
    // 0x80002458: sh          $t2, 0x62B0($at)
    MEM_H(0X62B0, ctx->r1) = ctx->r10;
    // 0x8000245C: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
L_80002460:
    // 0x80002460: nop

    // 0x80002464: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002468: mflo        $t4
    ctx->r12 = lo;
    // 0x8000246C: addu        $t6, $v0, $t4
    ctx->r14 = ADD32(ctx->r2, ctx->r12);
    // 0x80002470: lbu         $a0, 0x2($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X2);
    // 0x80002474: jal         0x80002608
    // 0x80002478: nop

    sound_reverb_set(rdram, ctx);
        goto after_8;
    // 0x80002478: nop

    after_8:
    // 0x8000247C: lbu         $t5, 0x0($s3)
    ctx->r13 = MEM_BU(ctx->r19, 0X0);
    // 0x80002480: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002484: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002488: addiu       $s1, $s1, 0x64FC
    ctx->r17 = ADD32(ctx->r17, 0X64FC);
    // 0x8000248C: sb          $t5, 0x6284($at)
    MEM_B(0X6284, ctx->r1) = ctx->r13;
    // 0x80002490: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x80002494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80002498: beq         $t7, $at, L_80002550
    if (ctx->r15 == ctx->r1) {
        // 0x8000249C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80002550;
    }
    // 0x8000249C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800024A0: addiu       $s2, $zero, 0x10
    ctx->r18 = ADD32(0, 0X10);
L_800024A4:
    // 0x800024A4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800024A8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800024AC: sllv        $t9, $t8, $s0
    ctx->r25 = S32(ctx->r24 << (ctx->r16 & 31));
    // 0x800024B0: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x800024B4: beq         $t1, $zero, L_800024CC
    if (ctx->r9 == 0) {
        // 0x800024B8: nop
    
            goto L_800024CC;
    }
    // 0x800024B8: nop

    // 0x800024BC: jal         0x80001170
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_on(rdram, ctx);
        goto after_9;
    // 0x800024C0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_9:
    // 0x800024C4: b           L_800024D8
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800024D8;
    // 0x800024C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024CC:
    // 0x800024CC: jal         0x80001114
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    music_channel_off(rdram, ctx);
        goto after_10;
    // 0x800024D0: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_10:
    // 0x800024D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800024D8:
    // 0x800024D8: bne         $s0, $s2, L_800024A4
    if (ctx->r16 != ctx->r18) {
        // 0x800024DC: nop
    
            goto L_800024A4;
    }
    // 0x800024DC: nop

    // 0x800024E0: b           L_80002554
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
        goto L_80002554;
    // 0x800024E4: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_800024E8:
    // 0x800024E8: lbu         $t3, 0x0($s3)
    ctx->r11 = MEM_BU(ctx->r19, 0X0);
    // 0x800024EC: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x800024F0: multu       $t3, $s1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800024F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800024F8: addiu       $s0, $s0, 0x629C
    ctx->r16 = ADD32(ctx->r16, 0X629C);
    // 0x800024FC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80002500: mflo        $t4
    ctx->r12 = lo;
    // 0x80002504: addu        $t6, $t2, $t4
    ctx->r14 = ADD32(ctx->r10, ctx->r12);
    // 0x80002508: lbu         $a0, 0x0($t6)
    ctx->r4 = MEM_BU(ctx->r14, 0X0);
    // 0x8000250C: jal         0x80001B0C
    // 0x80002510: nop

    music_jingle_volume_set(rdram, ctx);
        goto after_11;
    // 0x80002510: nop

    after_11:
    // 0x80002514: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002518: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000251C: multu       $v1, $s1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80002520: mflo        $t7
    ctx->r15 = lo;
    // 0x80002524: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80002528: lbu         $a0, 0x1($t8)
    ctx->r4 = MEM_BU(ctx->r24, 0X1);
    // 0x8000252C: nop

    // 0x80002530: beq         $a0, $zero, L_80002548
    if (ctx->r4 == 0) {
        // 0x80002534: nop
    
            goto L_80002548;
    }
    // 0x80002534: nop

    // 0x80002538: jal         0x800017D4
    // 0x8000253C: nop

    sound_jingle_tempo_set(rdram, ctx);
        goto after_12;
    // 0x8000253C: nop

    after_12:
    // 0x80002540: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80002544: nop

L_80002548:
    // 0x80002548: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x8000254C: sb          $v1, 0x6285($at)
    MEM_B(0X6285, ctx->r1) = ctx->r3;
L_80002550:
    // 0x80002550: sb          $zero, 0x0($s3)
    MEM_B(0X0, ctx->r19) = 0;
L_80002554:
    // 0x80002554: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80002558:
    // 0x80002558: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000255C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80002560: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80002564: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80002568: jr          $ra
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000256C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void hud_race_finish_1player(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4EC4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A4EC8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4ECC: lw          $v0, 0x729C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X729C);
    // 0x800A4ED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800A4ED4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A4ED8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800A4EDC: sb          $zero, 0x27($sp)
    MEM_B(0X27, ctx->r29) = 0;
    // 0x800A4EE0: addiu       $a3, $v0, 0x700
    ctx->r7 = ADD32(ctx->r2, 0X700);
    // 0x800A4EE4: lb          $v1, 0x1A($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1A);
    // 0x800A4EE8: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A4EEC: beq         $v1, $zero, L_800A4F1C
    if (ctx->r3 == 0) {
        // 0x800A4EF0: addiu       $s0, $v0, 0x740
        ctx->r16 = ADD32(ctx->r2, 0X740);
            goto L_800A4F1C;
    }
    // 0x800A4EF0: addiu       $s0, $v0, 0x740
    ctx->r16 = ADD32(ctx->r2, 0X740);
    // 0x800A4EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A4EF8: beq         $v1, $at, L_800A4F78
    if (ctx->r3 == ctx->r1) {
        // 0x800A4EFC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800A4F78;
    }
    // 0x800A4EFC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A4F00: beq         $v1, $v0, L_800A5080
    if (ctx->r3 == ctx->r2) {
        // 0x800A4F04: sll         $t3, $a1, 2
        ctx->r11 = S32(ctx->r5 << 2);
            goto L_800A5080;
    }
    // 0x800A4F04: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A4F08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A4F0C: beq         $v1, $v0, L_800A50E0
    if (ctx->r3 == ctx->r2) {
        // 0x800A4F10: nop
    
            goto L_800A50E0;
    }
    // 0x800A4F10: nop

    // 0x800A4F14: b           L_800A50E8
    // 0x800A4F18: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
        goto L_800A50E8;
    // 0x800A4F18: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A4F1C:
    // 0x800A4F1C: jal         0x80000BE0
    // 0x800A4F20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    music_voicelimit_set(rdram, ctx);
        goto after_0;
    // 0x800A4F20: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800A4F24: jal         0x80000B34
    // 0x800A4F28: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    music_play(rdram, ctx);
        goto after_1;
    // 0x800A4F28: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    after_1:
    // 0x800A4F2C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A4F30: jal         0x80001D04
    // 0x800A4F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800A4F34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800A4F38: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4F3C: addiu       $a1, $a1, 0x7300
    ctx->r5 = ADD32(ctx->r5, 0X7300);
    // 0x800A4F40: jal         0x80001D04
    // 0x800A4F44: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A4F44: addiu       $a0, $zero, 0x102
    ctx->r4 = ADD32(0, 0X102);
    after_3:
    // 0x800A4F48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A4F4C: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A4F50: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800A4F54: addiu       $t6, $zero, 0x7F
    ctx->r14 = ADD32(0, 0X7F);
    // 0x800A4F58: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x800A4F5C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x800A4F60: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x800A4F64: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A4F68: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800A4F6C: sb          $t8, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r24;
    // 0x800A4F70: b           L_800A50E4
    // 0x800A4F74: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
        goto L_800A50E4;
    // 0x800A4F74: sb          $t9, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r25;
L_800A4F78:
    // 0x800A4F78: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x800A4F7C: subu        $t0, $t0, $a1
    ctx->r8 = SUB32(ctx->r8, ctx->r5);
    // 0x800A4F80: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800A4F84: addu        $t0, $t0, $a1
    ctx->r8 = ADD32(ctx->r8, ctx->r5);
    // 0x800A4F88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A4F8C: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4F90: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4F94: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x800A4F98: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A4F9C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A4FA0: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A4FA4: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A4FA8: nop

    // 0x800A4FAC: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800A4FB0: nop

    // 0x800A4FB4: bc1f        L_800A4FC0
    if (!c1cs) {
        // 0x800A4FB8: nop
    
            goto L_800A4FC0;
    }
    // 0x800A4FB8: nop

    // 0x800A4FBC: swc1        $f2, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f2.u32l;
L_800A4FC0:
    // 0x800A4FC0: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FC4: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x800A4FC8: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800A4FCC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A4FD0: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
    // 0x800A4FD4: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FD8: nop

    // 0x800A4FDC: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x800A4FE0: nop

    // 0x800A4FE4: bc1f        L_800A4FF8
    if (!c1cs) {
        // 0x800A4FE8: nop
    
            goto L_800A4FF8;
    }
    // 0x800A4FE8: nop

    // 0x800A4FEC: swc1        $f12, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f12.u32l;
    // 0x800A4FF0: lwc1        $f2, 0xC($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A4FF4: nop

L_800A4FF8:
    // 0x800A4FF8: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x800A4FFC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800A5000: bc1f        L_800A50E4
    if (!c1cs) {
        // 0x800A5004: sb          $t1, 0x27($sp)
        MEM_B(0X27, ctx->r29) = ctx->r9;
            goto L_800A50E4;
    }
    // 0x800A5004: sb          $t1, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r9;
    // 0x800A5008: lb          $t2, 0x1B($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1B);
    // 0x800A500C: addiu       $t5, $zero, -0x78
    ctx->r13 = ADD32(0, -0X78);
    // 0x800A5010: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x800A5014: sb          $t3, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r11;
    // 0x800A5018: lb          $t4, 0x1B($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X1B);
    // 0x800A501C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5020: slti        $at, $t4, 0x78
    ctx->r1 = SIGNED(ctx->r12) < 0X78 ? 1 : 0;
    // 0x800A5024: bne         $at, $zero, L_800A503C
    if (ctx->r1 != 0) {
        // 0x800A5028: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_800A503C;
    }
    // 0x800A5028: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A502C: lb          $t6, 0x1C($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1C);
    // 0x800A5030: sb          $t5, 0x1B($a3)
    MEM_B(0X1B, ctx->r7) = ctx->r13;
    // 0x800A5034: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A5038: sb          $t7, 0x1C($a3)
    MEM_B(0X1C, ctx->r7) = ctx->r15;
L_800A503C:
    // 0x800A503C: lb          $t8, 0x1C($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1C);
    // 0x800A5040: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800A5044: bne         $v0, $t8, L_800A50E8
    if (ctx->r2 != ctx->r24) {
        // 0x800A5048: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A50E8;
    }
    // 0x800A5048: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A504C: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
    // 0x800A5050: jal         0x80001D04
    // 0x800A5054: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x800A5054: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800A5058: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x800A505C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800A5060: addiu       $v0, $v0, 0x2CF0
    ctx->r2 = ADD32(ctx->r2, 0X2CF0);
    // 0x800A5064: lb          $t1, 0xC($v0)
    ctx->r9 = MEM_B(ctx->r2, 0XC);
    // 0x800A5068: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x800A506C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A5070: bne         $t0, $t1, L_800A50E4
    if (ctx->r8 != ctx->r9) {
        // 0x800A5074: addiu       $t2, $zero, -0x1
        ctx->r10 = ADD32(0, -0X1);
            goto L_800A50E4;
    }
    // 0x800A5074: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800A5078: b           L_800A50E4
    // 0x800A507C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
        goto L_800A50E4;
    // 0x800A507C: sb          $t2, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r10;
L_800A5080:
    // 0x800A5080: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800A5084: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A5088: addu        $t3, $t3, $a1
    ctx->r11 = ADD32(ctx->r11, ctx->r5);
    // 0x800A508C: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A5090: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A5094: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5098: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A509C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A50A0: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A50A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A50A8: swc1        $f8, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f8.u32l;
    // 0x800A50AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800A50B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800A50B4: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A50B8: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x800A50BC: sb          $t4, 0x27($sp)
    MEM_B(0X27, ctx->r29) = ctx->r12;
    // 0x800A50C0: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800A50C4: nop

    // 0x800A50C8: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800A50CC: nop

    // 0x800A50D0: bc1f        L_800A50E8
    if (!c1cs) {
        // 0x800A50D4: lb          $t5, 0x27($sp)
        ctx->r13 = MEM_B(ctx->r29, 0X27);
            goto L_800A50E8;
    }
    // 0x800A50D4: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
    // 0x800A50D8: b           L_800A50E4
    // 0x800A50DC: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
        goto L_800A50E4;
    // 0x800A50DC: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A50E0:
    // 0x800A50E0: sb          $v0, 0x1A($a3)
    MEM_B(0X1A, ctx->r7) = ctx->r2;
L_800A50E4:
    // 0x800A50E4: lb          $t5, 0x27($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X27);
L_800A50E8:
    // 0x800A50E8: nop

    // 0x800A50EC: beq         $t5, $zero, L_800A516C
    if (ctx->r13 == 0) {
        // 0x800A50F0: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A516C;
    }
    // 0x800A50F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A50F4: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A50F8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A50FC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800A5100: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800A5104: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A5108: addiu       $t8, $zero, -0x2E
    ctx->r24 = ADD32(0, -0X2E);
    // 0x800A510C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5110: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5114: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A5118: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A511C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800A5120: jal         0x800AAB5C
    // 0x800A5124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A5124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    after_5:
    // 0x800A5128: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A512C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5130: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5134: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5138: addiu       $a2, $a2, 0x72C4
    ctx->r6 = ADD32(ctx->r6, 0X72C4);
    // 0x800A513C: addiu       $a1, $a1, 0x72C0
    ctx->r5 = ADD32(ctx->r5, 0X72C0);
    // 0x800A5140: jal         0x800AAB5C
    // 0x800A5144: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A5144: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_6:
    // 0x800A5148: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A514C: addiu       $a0, $a0, 0x72BC
    ctx->r4 = ADD32(ctx->r4, 0X72BC);
    // 0x800A5150: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A5154: lui         $t0, 0xFA00
    ctx->r8 = S32(0XFA00 << 16);
    // 0x800A5158: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A515C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A5160: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800A5164: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800A5168: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800A516C:
    // 0x800A516C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5170: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A5174: jr          $ra
    // 0x800A5178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800A5178: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void set_active_camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066828: bltz        $a0, L_80066840
    if (SIGNED(ctx->r4) < 0) {
        // 0x8006682C: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066840;
    }
    // 0x8006682C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066830: beq         $at, $zero, L_80066840
    if (ctx->r1 == 0) {
        // 0x80066834: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80066840;
    }
    // 0x80066834: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066838: jr          $ra
    // 0x8006683C: sw          $a0, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r4;
    return;
    // 0x8006683C: sw          $a0, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = ctx->r4;
L_80066840:
    // 0x80066840: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066844: sw          $zero, 0x1264($at)
    MEM_W(0X1264, ctx->r1) = 0;
    // 0x80066848: jr          $ra
    // 0x8006684C: nop

    return;
    // 0x8006684C: nop

;}
RECOMP_FUNC void get_controller_pak_file_list(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800760B8: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800760BC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800760C0: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800760C4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800760C8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800760CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800760D0: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800760D4: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800760D8: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800760DC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800760E0: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800760E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800760E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800760EC: jal         0x80075B34
    // 0x800760F0: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800760F0: sw          $a3, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800760F4: beq         $v0, $zero, L_80076110
    if (ctx->r2 == 0) {
        // 0x800760F8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80076110;
    }
    // 0x800760F8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800760FC: jal         0x80075D44
    // 0x80076100: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80076100: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_1:
    // 0x80076104: sll         $t6, $s7, 30
    ctx->r14 = S32(ctx->r23 << 30);
    // 0x80076108: b           L_80076390
    // 0x8007610C: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
        goto L_80076390;
    // 0x8007610C: or          $v0, $t6, $s0
    ctx->r2 = ctx->r14 | ctx->r16;
L_80076110:
    // 0x80076110: sll         $t7, $s7, 2
    ctx->r15 = S32(ctx->r23 << 2);
    // 0x80076114: subu        $t7, $t7, $s7
    ctx->r15 = SUB32(ctx->r15, ctx->r23);
    // 0x80076118: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8007611C: addu        $t7, $t7, $s7
    ctx->r15 = ADD32(ctx->r15, ctx->r23);
    // 0x80076120: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076124: addiu       $t8, $t8, 0x4598
    ctx->r24 = ADD32(ctx->r24, 0X4598);
    // 0x80076128: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8007612C: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076130: sw          $a0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r4;
    // 0x80076134: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x80076138: jal         0x800D08F0
    // 0x8007613C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_2;
    // 0x8007613C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    after_2:
    // 0x80076140: beq         $v0, $zero, L_80076160
    if (ctx->r2 == 0) {
        // 0x80076144: nop
    
            goto L_80076160;
    }
    // 0x80076144: nop

    // 0x80076148: jal         0x80075D44
    // 0x8007614C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_3;
    // 0x8007614C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_3:
    // 0x80076150: sll         $v0, $s7, 30
    ctx->r2 = S32(ctx->r23 << 30);
    // 0x80076154: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076158: b           L_80076390
    // 0x8007615C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80076390;
    // 0x8007615C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076160:
    // 0x80076160: jal         0x8009F064
    // 0x80076164: nop

    get_language(rdram, ctx);
        goto after_4;
    // 0x80076164: nop

    after_4:
    // 0x80076168: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007616C: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x80076170: bne         $v0, $at, L_80076184
    if (ctx->r2 != ctx->r1) {
        // 0x80076174: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_80076184;
    }
    // 0x80076174: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80076178: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x8007617C: b           L_800761A4
    // 0x80076180: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
        goto L_800761A4;
    // 0x80076180: ori         $s6, $s6, 0x594A
    ctx->r22 = ctx->r22 | 0X594A;
L_80076184:
    // 0x80076184: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80076188: lw          $t0, 0x300($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X300);
    // 0x8007618C: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x80076190: bne         $t0, $zero, L_800761A4
    if (ctx->r8 != 0) {
        // 0x80076194: ori         $s6, $s6, 0x5945
        ctx->r22 = ctx->r22 | 0X5945;
            goto L_800761A4;
    }
    // 0x80076194: ori         $s6, $s6, 0x5945
    ctx->r22 = ctx->r22 | 0X5945;
    // 0x80076198: lui         $s6, 0x4E44
    ctx->r22 = S32(0X4E44 << 16);
    // 0x8007619C: b           L_800761A4
    // 0x800761A0: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
        goto L_800761A4;
    // 0x800761A0: ori         $s6, $s6, 0x5950
    ctx->r22 = ctx->r22 | 0X5950;
L_800761A4:
    // 0x800761A4: slt         $at, $s4, $t1
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800761A8: beq         $at, $zero, L_800761B4
    if (ctx->r1 == 0) {
        // 0x800761AC: addiu       $s0, $s0, -0x1650
        ctx->r16 = ADD32(ctx->r16, -0X1650);
            goto L_800761B4;
    }
    // 0x800761AC: addiu       $s0, $s0, -0x1650
    ctx->r16 = ADD32(ctx->r16, -0X1650);
    // 0x800761B0: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
L_800761B4:
    // 0x800761B4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800761B8: nop

    // 0x800761BC: beq         $a0, $zero, L_800761D0
    if (ctx->r4 == 0) {
        // 0x800761C0: lw          $a2, 0x68($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X68);
            goto L_800761D0;
    }
    // 0x800761C0: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x800761C4: jal         0x80071380
    // 0x800761C8: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800761C8: nop

    after_5:
    // 0x800761CC: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
L_800761D0:
    // 0x800761D0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x800761D4: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x800761D8: subu        $t2, $t2, $a2
    ctx->r10 = SUB32(ctx->r10, ctx->r6);
    // 0x800761DC: sll         $a0, $t2, 3
    ctx->r4 = S32(ctx->r10 << 3);
    // 0x800761E0: jal         0x80070EDC
    // 0x800761E4: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800761E4: sw          $a0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r4;
    after_6:
    // 0x800761E8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800761EC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800761F0: jal         0x800D0A40
    // 0x800761F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    _bzero(rdram, ctx);
        goto after_7;
    // 0x800761F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800761F8: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800761FC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80076200: blez        $t3, L_80076254
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80076204: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80076254;
    }
    // 0x80076204: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80076208: lw          $s0, 0xA0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA0);
    // 0x8007620C: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x80076210: lw          $s2, 0xA4($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA4);
    // 0x80076214: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x80076218: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_8007621C:
    // 0x8007621C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80076220: addiu       $v1, $v1, 0x12
    ctx->r3 = ADD32(ctx->r3, 0X12);
    // 0x80076224: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80076228: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8007622C: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x80076230: lw          $t4, 0x68($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X68);
    // 0x80076234: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80076238: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8007623C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80076240: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80076244: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80076248: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007624C: bne         $at, $zero, L_8007621C
    if (ctx->r1 != 0) {
        // 0x80076250: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8007621C;
    }
    // 0x80076250: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_80076254:
    // 0x80076254: lw          $a3, 0xA0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XA0);
    // 0x80076258: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007625C: beq         $at, $zero, L_800762B0
    if (ctx->r1 == 0) {
        // 0x80076260: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800762B0;
    }
    // 0x80076260: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80076264: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80076268: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x8007626C: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80076270: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x80076274: addu        $a1, $t7, $a3
    ctx->r5 = ADD32(ctx->r15, ctx->r7);
    // 0x80076278: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x8007627C: addu        $s0, $a3, $v1
    ctx->r16 = ADD32(ctx->r7, ctx->r3);
    // 0x80076280: addu        $s1, $t5, $v1
    ctx->r17 = ADD32(ctx->r13, ctx->r3);
    // 0x80076284: addu        $s2, $t6, $s3
    ctx->r18 = ADD32(ctx->r14, ctx->r19);
L_80076288:
    // 0x80076288: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x8007628C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80076290: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80076294: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x80076298: sltu        $at, $s0, $a1
    ctx->r1 = ctx->r16 < ctx->r5 ? 1 : 0;
    // 0x8007629C: sb          $a0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r4;
    // 0x800762A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800762A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800762A8: bne         $at, $zero, L_80076288
    if (ctx->r1 != 0) {
        // 0x800762AC: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80076288;
    }
    // 0x800762AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800762B0:
    // 0x800762B0: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800762B4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800762B8: blez        $t8, L_80076384
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800762BC: nop
    
            goto L_80076384;
    }
    // 0x800762BC: nop

    // 0x800762C0: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_800762C4:
    // 0x800762C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800762C8: jal         0x800D0AE0
    // 0x800762CC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    osPfsFileState_recomp(rdram, ctx);
        goto after_8;
    // 0x800762CC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_8:
    // 0x800762D0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800762D4: bne         $v0, $at, L_800762E8
    if (ctx->r2 != ctx->r1) {
        // 0x800762D8: sll         $t9, $s3, 2
        ctx->r25 = S32(ctx->r19 << 2);
            goto L_800762E8;
    }
    // 0x800762D8: sll         $t9, $s3, 2
    ctx->r25 = S32(ctx->r19 << 2);
    // 0x800762DC: addu        $t0, $s5, $t9
    ctx->r8 = ADD32(ctx->r21, ctx->r25);
    // 0x800762E0: b           L_80076370
    // 0x800762E4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80076370;
    // 0x800762E4: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_800762E8:
    // 0x800762E8: beq         $v0, $zero, L_80076300
    if (ctx->r2 == 0) {
        // 0x800762EC: addiu       $a0, $sp, 0x7E
        ctx->r4 = ADD32(ctx->r29, 0X7E);
            goto L_80076300;
    }
    // 0x800762EC: addiu       $a0, $sp, 0x7E
    ctx->r4 = ADD32(ctx->r29, 0X7E);
    // 0x800762F0: jal         0x80075D44
    // 0x800762F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_9;
    // 0x800762F4: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_9:
    // 0x800762F8: b           L_80076390
    // 0x800762FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80076390;
    // 0x800762FC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80076300:
    // 0x80076300: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80076304: lw          $t2, 0x9C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X9C);
    // 0x80076308: lw          $t3, 0xA0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA0);
    // 0x8007630C: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x80076310: addu        $t1, $s5, $v1
    ctx->r9 = ADD32(ctx->r21, ctx->r3);
    // 0x80076314: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80076318: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007631C: addu        $s1, $t2, $v1
    ctx->r17 = ADD32(ctx->r10, ctx->r3);
    // 0x80076320: addu        $s0, $t3, $v1
    ctx->r16 = ADD32(ctx->r11, ctx->r3);
    // 0x80076324: jal         0x80076BE4
    // 0x80076328: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    font_codes_to_string(rdram, ctx);
        goto after_10;
    // 0x80076328: addu        $s2, $t4, $s3
    ctx->r18 = ADD32(ctx->r12, ctx->r19);
    after_10:
    // 0x8007632C: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x80076330: addiu       $a0, $sp, 0x7A
    ctx->r4 = ADD32(ctx->r29, 0X7A);
    // 0x80076334: jal         0x80076BE4
    // 0x80076338: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    font_codes_to_string(rdram, ctx);
        goto after_11;
    // 0x80076338: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_11:
    // 0x8007633C: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x80076340: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80076344: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80076348: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    // 0x8007634C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80076350: lhu         $t8, 0x78($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X78);
    // 0x80076354: bne         $t7, $s6, L_80076370
    if (ctx->r15 != ctx->r22) {
        // 0x80076358: addiu       $at, $zero, 0x3459
        ctx->r1 = ADD32(0, 0X3459);
            goto L_80076370;
    }
    // 0x80076358: addiu       $at, $zero, 0x3459
    ctx->r1 = ADD32(0, 0X3459);
    // 0x8007635C: bne         $t8, $at, L_80076370
    if (ctx->r24 != ctx->r1) {
        // 0x80076360: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_80076370;
    }
    // 0x80076360: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80076364: jal         0x80076D4C
    // 0x80076368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    get_file_type(rdram, ctx);
        goto after_12;
    // 0x80076368: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_12:
    // 0x8007636C: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
L_80076370:
    // 0x80076370: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x80076374: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80076378: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8007637C: bne         $at, $zero, L_800762C4
    if (ctx->r1 != 0) {
        // 0x80076380: lw          $a0, 0x54($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X54);
            goto L_800762C4;
    }
    // 0x80076380: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
L_80076384:
    // 0x80076384: jal         0x80075D44
    // 0x80076388: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_13;
    // 0x80076388: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_13:
    // 0x8007638C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076390:
    // 0x80076390: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80076394: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80076398: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007639C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800763A0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800763A4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800763A8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800763AC: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800763B0: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800763B4: jr          $ra
    // 0x800763B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800763B8: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void alEvtqFlushType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C95F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800C95F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C95F8: sll         $s3, $a1, 16
    ctx->r19 = S32(ctx->r5 << 16);
    // 0x800C95FC: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9600: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C9604: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800C9608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C960C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
    // 0x800C9610: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9614: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9618: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800C961C: jal         0x800C9F90
    // 0x800C9620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800C9620: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800C9624: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800C9628: lw          $s0, 0x8($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X8);
    // 0x800C962C: beq         $s0, $zero, L_800C9678
    if (ctx->r16 == 0) {
        // 0x800C9630: nop
    
            goto L_800C9678;
    }
    // 0x800C9630: nop

L_800C9634:
    // 0x800C9634: lh          $t7, 0xC($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XC);
    // 0x800C9638: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800C963C: bne         $s3, $t7, L_800C9670
    if (ctx->r19 != ctx->r15) {
        // 0x800C9640: nop
    
            goto L_800C9670;
    }
    // 0x800C9640: nop

    // 0x800C9644: beq         $s1, $zero, L_800C965C
    if (ctx->r17 == 0) {
        // 0x800C9648: nop
    
            goto L_800C965C;
    }
    // 0x800C9648: nop

    // 0x800C964C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800C9650: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800C9654: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C9658: sw          $t0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r8;
L_800C965C:
    // 0x800C965C: jal         0x800C8CC0
    // 0x800C9660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x800C9660: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800C9664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C9668: jal         0x800C8CF0
    // 0x800C966C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_2;
    // 0x800C966C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_2:
L_800C9670:
    // 0x800C9670: bne         $s1, $zero, L_800C9634
    if (ctx->r17 != 0) {
        // 0x800C9674: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800C9634;
    }
    // 0x800C9674: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_800C9678:
    // 0x800C9678: jal         0x800C9F90
    // 0x800C967C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x800C967C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x800C9680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C9684: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C9688: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C968C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9690: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C9694: jr          $ra
    // 0x800C9698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800C9698: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gfx_init_basic_xlu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F9E4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007F9E8: sltiu       $at, $a1, 0x2
    ctx->r1 = ctx->r5 < 0X2 ? 1 : 0;
    // 0x8007F9EC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8007F9F0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8007F9F4: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8007F9F8: addiu       $v0, $v0, -0x6D8
    ctx->r2 = ADD32(ctx->r2, -0X6D8);
    // 0x8007F9FC: bne         $at, $zero, L_8007FA10
    if (ctx->r1 != 0) {
        // 0x8007FA00: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8007FA10;
    }
    // 0x8007FA00: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8007FA04: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FA08: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8007FA0C: addiu       $v0, $v0, -0x6A8
    ctx->r2 = ADD32(ctx->r2, -0X6A8);
L_8007FA10:
    // 0x8007FA10: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA14: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x8007FA18: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x8007FA1C: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8007FA20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007FA24: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8007FA28: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x8007FA2C: addiu       $t2, $t2, -0x670
    ctx->r10 = ADD32(ctx->r10, -0X670);
    // 0x8007FA30: addu        $t1, $t9, $at
    ctx->r9 = ADD32(ctx->r25, ctx->r1);
    // 0x8007FA34: lui         $t8, 0x702
    ctx->r24 = S32(0X702 << 16);
    // 0x8007FA38: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007FA3C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x8007FA40: ori         $t8, $t8, 0x10
    ctx->r24 = ctx->r24 | 0X10;
    // 0x8007FA44: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8007FA48: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x8007FA4C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007FA50: addiu       $a3, $a2, 0x8
    ctx->r7 = ADD32(ctx->r6, 0X8);
    // 0x8007FA54: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x8007FA58: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x8007FA5C: lw          $t5, 0x8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8);
    // 0x8007FA60: addiu       $t0, $a3, 0x8
    ctx->r8 = ADD32(ctx->r7, 0X8);
    // 0x8007FA64: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8007FA68: sw          $t5, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r13;
    // 0x8007FA6C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007FA70: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8007FA74: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x8007FA78: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007FA7C: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x8007FA80: jr          $ra
    // 0x8007FA84: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    return;
    // 0x8007FA84: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
;}
RECOMP_FUNC void music_channel_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001228: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x8000122C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80001230: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001234: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001238: bne         $at, $zero, L_80001248
    if (ctx->r1 != 0) {
        // 0x8000123C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80001248;
    }
    // 0x8000123C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80001240: b           L_80001258
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80001258;
    // 0x80001244: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80001248:
    // 0x80001248: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000124C: lw          $a0, -0x3460($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3460);
    // 0x80001250: jal         0x800C7F00
    // 0x80001254: nop

    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001254: nop

    after_0:
L_80001258:
    // 0x80001258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000125C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001260: jr          $ra
    // 0x80001264: nop

    return;
    // 0x80001264: nop

;}
RECOMP_FUNC void func_8002458C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245C0: jr          $ra
    // 0x800245C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x800245C4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void apply_plane_tilt_anim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004C0E0: lb          $t6, 0x1D7($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X1D7);
    // 0x8004C0E4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8004C0E8: beq         $t6, $at, L_8004C178
    if (ctx->r14 == ctx->r1) {
        // 0x8004C0EC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8004C178;
    }
    // 0x8004C0EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8004C0F0: andi        $t7, $zero, 0xFF
    ctx->r15 = 0 & 0XFF;
    // 0x8004C0F4: bne         $t7, $zero, L_8004C178
    if (ctx->r15 != 0) {
        // 0x8004C0F8: sb          $zero, 0x1F2($a2)
        MEM_B(0X1F2, ctx->r6) = 0;
            goto L_8004C178;
    }
    // 0x8004C0F8: sb          $zero, 0x1F2($a2)
    MEM_B(0X1F2, ctx->r6) = 0;
    // 0x8004C0FC: lb          $v0, 0x1E1($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1E1);
    // 0x8004C100: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x8004C104: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8004C108: subu        $v0, $t9, $t8
    ctx->r2 = SUB32(ctx->r25, ctx->r24);
    // 0x8004C10C: bgez        $v0, L_8004C118
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8004C110: sll         $a2, $a3, 2
        ctx->r6 = S32(ctx->r7 << 2);
            goto L_8004C118;
    }
    // 0x8004C110: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x8004C114: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8004C118:
    // 0x8004C118: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8004C11C: bne         $at, $zero, L_8004C128
    if (ctx->r1 != 0) {
        // 0x8004C120: nop
    
            goto L_8004C128;
    }
    // 0x8004C120: nop

    // 0x8004C124: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8004C128:
    // 0x8004C128: lh          $a0, 0x18($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X18);
    // 0x8004C12C: nop

    // 0x8004C130: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x8004C134: blez        $v1, L_8004C150
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004C138: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8004C150;
    }
    // 0x8004C138: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8004C13C: subu        $v0, $a2, $a3
    ctx->r2 = SUB32(ctx->r6, ctx->r7);
    // 0x8004C140: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004C144: beq         $at, $zero, L_8004C150
    if (ctx->r1 == 0) {
        // 0x8004C148: nop
    
            goto L_8004C150;
    }
    // 0x8004C148: nop

    // 0x8004C14C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C150:
    // 0x8004C150: bgez        $v1, L_8004C170
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004C154: negu        $at, $a3
        ctx->r1 = SUB32(0, ctx->r7);
            goto L_8004C170;
    }
    // 0x8004C154: negu        $at, $a3
    ctx->r1 = SUB32(0, ctx->r7);
    // 0x8004C158: sll         $a2, $at, 2
    ctx->r6 = S32(ctx->r1 << 2);
    // 0x8004C15C: subu        $v0, $a2, $at
    ctx->r2 = SUB32(ctx->r6, ctx->r1);
    // 0x8004C160: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8004C164: beq         $at, $zero, L_8004C174
    if (ctx->r1 == 0) {
        // 0x8004C168: addu        $t0, $a0, $v0
        ctx->r8 = ADD32(ctx->r4, ctx->r2);
            goto L_8004C174;
    }
    // 0x8004C168: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
    // 0x8004C16C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8004C170:
    // 0x8004C170: addu        $t0, $a0, $v0
    ctx->r8 = ADD32(ctx->r4, ctx->r2);
L_8004C174:
    // 0x8004C174: sh          $t0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r8;
L_8004C178:
    // 0x8004C178: jr          $ra
    // 0x8004C17C: nop

    return;
    // 0x8004C17C: nop

;}
RECOMP_FUNC void obj_init_lensflare(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004096C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80040970: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040974: jal         0x800ACE08
    // 0x80040978: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    lensflare_init(rdram, ctx);
        goto after_0;
    // 0x80040978: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8004097C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040984: jr          $ra
    // 0x80040988: nop

    return;
    // 0x80040988: nop

;}
RECOMP_FUNC void rumble_exists(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072534: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80072538: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x8007253C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80072540: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80072544: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80072548: bltz        $t7, L_8007255C
    if (SIGNED(ctx->r15) < 0) {
        // 0x8007254C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8007255C;
    }
    // 0x8007254C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80072550: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80072554: bne         $at, $zero, L_80072564
    if (ctx->r1 != 0) {
        // 0x80072558: nop
    
            goto L_80072564;
    }
    // 0x80072558: nop

L_8007255C:
    // 0x8007255C: b           L_80072584
    // 0x80072560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80072584;
    // 0x80072560: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80072564:
    // 0x80072564: jal         0x80072490
    // 0x80072568: nop

    input_get_id(rdram, ctx);
        goto after_0;
    // 0x80072568: nop

    after_0:
    // 0x8007256C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80072570: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80072574: lbu         $t8, 0x4765($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4765);
    // 0x80072578: sllv        $t0, $t9, $v0
    ctx->r8 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x8007257C: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x80072580: and         $v0, $t8, $t1
    ctx->r2 = ctx->r24 & ctx->r9;
L_80072584:
    // 0x80072584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80072588: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007258C: jr          $ra
    // 0x80072590: nop

    return;
    // 0x80072590: nop

;}
RECOMP_FUNC void menu_audio_options_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084B8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B90: sh          $zero, 0x7206($at)
    MEM_H(0X7206, ctx->r1) = 0;
    // 0x80084B94: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084B98: sw          $zero, 0x695C($at)
    MEM_W(0X695C, ctx->r1) = 0;
    // 0x80084B9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084BA0: sw          $zero, -0x604($at)
    MEM_W(-0X604, ctx->r1) = 0;
    // 0x80084BA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084BA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084BAC: sw          $zero, 0x6FBC($at)
    MEM_W(0X6FBC, ctx->r1) = 0;
    // 0x80084BB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084BB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084BB8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80084BBC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BC0: sw          $t6, 0x6978($at)
    MEM_W(0X6978, ctx->r1) = ctx->r14;
    // 0x80084BC4: jal         0x8009CBB8
    // 0x80084BC8: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x80084BC8: addiu       $a0, $a0, -0x54
    ctx->r4 = ADD32(ctx->r4, -0X54);
    after_0:
    // 0x80084BCC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BD0: jal         0x8009CDE8
    // 0x80084BD4: addiu       $a0, $a0, -0x48
    ctx->r4 = ADD32(ctx->r4, -0X48);
    menu_imagegroup_load(rdram, ctx);
        goto after_1;
    // 0x80084BD4: addiu       $a0, $a0, -0x48
    ctx->r4 = ADD32(ctx->r4, -0X48);
    after_1:
    // 0x80084BD8: jal         0x8008E968
    // 0x80084BDC: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x80084BDC: nop

    after_2:
    // 0x80084BE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084BE4: jal         0x800C06F8
    // 0x80084BE8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x80084BE8: addiu       $a0, $a0, -0x304
    ctx->r4 = ADD32(ctx->r4, -0X304);
    after_3:
    // 0x80084BEC: jal         0x8008043C
    // 0x80084BF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_8007FFEC(rdram, ctx);
        goto after_4;
    // 0x80084BF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80084BF4: jal         0x80001AFC
    // 0x80084BF8: nop

    music_volume_config(rdram, ctx);
        goto after_5;
    // 0x80084BF8: nop

    after_5:
    // 0x80084BFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084C00: jal         0x8000317C
    // 0x80084C04: sw          $v0, 0x44($at)
    MEM_W(0X44, ctx->r1) = ctx->r2;
    sndp_get_global_volume(rdram, ctx);
        goto after_6;
    // 0x80084C04: sw          $v0, 0x44($at)
    MEM_W(0X44, ctx->r1) = ctx->r2;
    after_6:
    // 0x80084C08: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80084C0C: lw          $t7, 0x318($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X318);
    // 0x80084C10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80084C14: andi        $t8, $t7, 0x40
    ctx->r24 = ctx->r15 & 0X40;
    // 0x80084C18: beq         $t8, $zero, L_80084C54
    if (ctx->r24 == 0) {
        // 0x80084C1C: sw          $v0, 0x40($at)
        MEM_W(0X40, ctx->r1) = ctx->r2;
            goto L_80084C54;
    }
    // 0x80084C1C: sw          $v0, 0x40($at)
    MEM_W(0X40, ctx->r1) = ctx->r2;
    // 0x80084C20: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80084C24: lw          $t9, 0x6FA0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6FA0);
    // 0x80084C28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084C2C: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x80084C30: addiu       $t0, $zero, 0xD4
    ctx->r8 = ADD32(0, 0XD4);
    // 0x80084C34: sh          $t0, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r8;
    // 0x80084C38: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80084C3C: jal         0x80000BE0
    // 0x80084C40: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    music_voicelimit_set(rdram, ctx);
        goto after_7;
    // 0x80084C40: sw          $t9, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r25;
    after_7:
    // 0x80084C44: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80084C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084C4C: b           L_80084C74
    // 0x80084C50: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
        goto L_80084C74;
    // 0x80084C50: sw          $t1, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r9;
L_80084C54:
    // 0x80084C54: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80084C58: addiu       $v0, $v0, -0x44
    ctx->r2 = ADD32(ctx->r2, -0X44);
    // 0x80084C5C: addiu       $t2, $zero, 0xC0
    ctx->r10 = ADD32(0, 0XC0);
    // 0x80084C60: sw          $zero, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = 0;
    // 0x80084C64: sh          $t2, 0x32($v0)
    MEM_H(0X32, ctx->r2) = ctx->r10;
    // 0x80084C68: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80084C6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80084C70: sw          $t3, 0x6980($at)
    MEM_W(0X6980, ctx->r1) = ctx->r11;
L_80084C74:
    // 0x80084C74: jal         0x800C46D0
    // 0x80084C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_8;
    // 0x80084C78: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_8:
    // 0x80084C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084C80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084C84: jr          $ra
    // 0x80084C88: nop

    return;
    // 0x80084C88: nop

;}
RECOMP_FUNC void racerfx_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BADC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000BAE0: addiu       $v0, $v0, -0x4A78
    ctx->r2 = ADD32(ctx->r2, -0X4A78);
    // 0x8000BAE4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8000BAE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000BAEC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000BAF0: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x8000BAF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8000BAF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BAFC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8000BB00: sw          $zero, -0x4A84($at)
    MEM_W(-0X4A84, ctx->r1) = 0;
    // 0x8000BB04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000BB08: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000BB0C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000BB10: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8000BB14: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8000BB18: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8000BB1C: sw          $zero, -0x4A7C($at)
    MEM_W(-0X4A7C, ctx->r1) = 0;
    // 0x8000BB20: jal         0x8001E2D0
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x8000BB24: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_0:
    // 0x8000BB28: addiu       $t9, $zero, 0x9
    ctx->r25 = ADD32(0, 0X9);
    // 0x8000BB2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BB30: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000BB34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000BB38: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8000BB3C: sw          $t9, -0x3330($at)
    MEM_W(-0X3330, ctx->r1) = ctx->r25;
    // 0x8000BB40: addiu       $a0, $a0, -0x4A60
    ctx->r4 = ADD32(ctx->r4, -0X4A60);
    // 0x8000BB44: addiu       $v1, $v1, -0x4A18
    ctx->r3 = ADD32(ctx->r3, -0X4A18);
    // 0x8000BB48: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB4C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BB50:
    // 0x8000BB50: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BB54: sll         $t5, $t0, 2
    ctx->r13 = S32(ctx->r8 << 2);
    // 0x8000BB58: beq         $t4, $zero, L_8000BB74
    if (ctx->r12 == 0) {
        // 0x8000BB5C: addu        $t7, $a0, $t5
        ctx->r15 = ADD32(ctx->r4, ctx->r13);
            goto L_8000BB74;
    }
    // 0x8000BB5C: addu        $t7, $a0, $t5
    ctx->r15 = ADD32(ctx->r4, ctx->r13);
    // 0x8000BB60: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000BB64: nop

    // 0x8000BB68: beq         $v0, $zero, L_8000BB74
    if (ctx->r2 == 0) {
        // 0x8000BB6C: nop
    
            goto L_8000BB74;
    }
    // 0x8000BB6C: nop

    // 0x8000BB70: sw          $zero, 0x78($v0)
    MEM_W(0X78, ctx->r2) = 0;
L_8000BB74:
    // 0x8000BB74: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BB78: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x8000BB7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8000BB80: bne         $at, $zero, L_8000BB50
    if (ctx->r1 != 0) {
        // 0x8000BB84: sb          $t2, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r10;
            goto L_8000BB50;
    }
    // 0x8000BB84: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8000BB88: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000BB8C: lw          $t6, -0x4B90($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4B90);
    // 0x8000BB90: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000BB94: blez        $t6, L_8000BF0C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000BB98: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000BF0C;
    }
    // 0x8000BB98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000BB9C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BBA0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BBA4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x8000BBA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BBAC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000BBB0: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BBB4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BBB8: addiu       $s3, $s3, -0x4B9C
    ctx->r19 = ADD32(ctx->r19, -0X4B9C);
    // 0x8000BBBC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BBC0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
L_8000BBC4:
    // 0x8000BBC4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8000BBC8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8000BBCC: mov.s       $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = ctx->f16.fl;
    // 0x8000BBD0: bne         $t8, $zero, L_8000BBE8
    if (ctx->r24 != 0) {
        // 0x8000BBD4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BBE8;
    }
    // 0x8000BBD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BBD8: lwc1        $f6, 0x56C8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56C8);
    // 0x8000BBDC: nop

    // 0x8000BBE0: mul.s       $f2, $f16, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x8000BBE4: nop

L_8000BBE8:
    // 0x8000BBE8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000BBF0: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BBF4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8000BBF8: addiu       $t8, $t8, -0x4A70
    ctx->r24 = ADD32(ctx->r24, -0X4A70);
    // 0x8000BBFC: lw          $s0, 0x64($t5)
    ctx->r16 = MEM_W(ctx->r13, 0X64);
    // 0x8000BC00: nop

    // 0x8000BC04: lb          $a0, 0x2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X2);
    // 0x8000BC08: lh          $t6, 0x18E($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X18E);
    // 0x8000BC0C: sll         $t7, $a0, 7
    ctx->r15 = S32(ctx->r4 << 7);
    // 0x8000BC10: beq         $t6, $zero, L_8000BC2C
    if (ctx->r14 == 0) {
        // 0x8000BC14: addu        $v0, $t7, $t3
        ctx->r2 = ADD32(ctx->r15, ctx->r11);
            goto L_8000BC2C;
    }
    // 0x8000BC14: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x8000BC18: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8000BC1C: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x8000BC20: nop

    // 0x8000BC24: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BC28: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
L_8000BC2C:
    // 0x8000BC2C: lbu         $t5, 0x72($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X72);
    // 0x8000BC30: nop

    // 0x8000BC34: addu        $t7, $t5, $s1
    ctx->r15 = ADD32(ctx->r13, ctx->r17);
    // 0x8000BC38: sb          $t7, 0x72($v0)
    MEM_B(0X72, ctx->r2) = ctx->r15;
    // 0x8000BC3C: lb          $t6, 0x1D3($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D3);
    // 0x8000BC40: nop

    // 0x8000BC44: beq         $t6, $zero, L_8000BD4C
    if (ctx->r14 == 0) {
        // 0x8000BC48: nop
    
            goto L_8000BD4C;
    }
    // 0x8000BC48: nop

    // 0x8000BC4C: lbu         $t9, 0x70($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BC50: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x8000BC54: bne         $t9, $zero, L_8000BC9C
    if (ctx->r25 != 0) {
        // 0x8000BC58: sb          $t8, 0x73($v0)
        MEM_B(0X73, ctx->r2) = ctx->r24;
            goto L_8000BC9C;
    }
    // 0x8000BC58: sb          $t8, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r24;
    // 0x8000BC5C: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BC60: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC64: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC68: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000BC6C: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x8000BC70: lwc1        $f6, 0x56CC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56CC);
    // 0x8000BC74: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BC78: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BC7C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8000BC80: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BC84: bc1f        L_8000BC9C
    if (!c1cs) {
        // 0x8000BC88: nop
    
            goto L_8000BC9C;
    }
    // 0x8000BC88: nop

    // 0x8000BC8C: lwc1        $f8, 0x56D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56D0);
    // 0x8000BC90: sb          $t2, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r10;
    // 0x8000BC94: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8000BC98: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BC9C:
    // 0x8000BC9C: lbu         $t4, 0x70($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000BCA4: bne         $t4, $at, L_8000BCE8
    if (ctx->r12 != ctx->r1) {
        // 0x8000BCA8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCA8: nop

    // 0x8000BCAC: mul.s       $f6, $f2, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8000BCB0: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCB4: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BCB8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000BCBC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000BCC0: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BCC4: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCC8: nop

    // 0x8000BCCC: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BCD0: nop

    // 0x8000BCD4: bc1f        L_8000BCE8
    if (!c1cs) {
        // 0x8000BCD8: nop
    
            goto L_8000BCE8;
    }
    // 0x8000BCD8: nop

    // 0x8000BCDC: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000BCE0: sb          $t5, 0x70($v0)
    MEM_B(0X70, ctx->r2) = ctx->r13;
    // 0x8000BCE4: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
L_8000BCE8:
    // 0x8000BCE8: lbu         $t7, 0x70($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BCEC: nop

    // 0x8000BCF0: bne         $t1, $t7, L_8000BD40
    if (ctx->r9 != ctx->r15) {
        // 0x8000BCF4: nop
    
            goto L_8000BD40;
    }
    // 0x8000BCF4: nop

    // 0x8000BCF8: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BCFC: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x8000BD00: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x8000BD04: nop

    // 0x8000BD08: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD0C: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD0C: nop

    // 0x8000BD10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000BD14: nop

    // 0x8000BD18: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8000BD1C: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8000BD20: swc1        $f8, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f8.u32l;
    // 0x8000BD24: lwc1        $f10, 0x74($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD28: nop

    // 0x8000BD2C: c.lt.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl < ctx->f10.fl;
    // 0x8000BD30: nop

    // 0x8000BD34: bc1f        L_8000BD40
    if (!c1cs) {
        // 0x8000BD38: nop
    
            goto L_8000BD40;
    }
    // 0x8000BD38: nop

    // 0x8000BD3C: swc1        $f14, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f14.u32l;
L_8000BD40:
    // 0x8000BD40: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD44: b           L_8000BE00
    // 0x8000BD48: nop

        goto L_8000BE00;
    // 0x8000BD48: nop

L_8000BD4C:
    // 0x8000BD4C: lb          $a0, 0x73($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X73);
    // 0x8000BD50: nop

    // 0x8000BD54: blez        $a0, L_8000BD68
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000BD58: subu        $t6, $a0, $s1
        ctx->r14 = SUB32(ctx->r4, ctx->r17);
            goto L_8000BD68;
    }
    // 0x8000BD58: subu        $t6, $a0, $s1
    ctx->r14 = SUB32(ctx->r4, ctx->r17);
    // 0x8000BD5C: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD60: b           L_8000BE00
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
        goto L_8000BE00;
    // 0x8000BD64: sb          $t6, 0x73($v0)
    MEM_B(0X73, ctx->r2) = ctx->r14;
L_8000BD68:
    // 0x8000BD68: lbu         $t8, 0x70($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BD6C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BD70: bne         $t1, $t8, L_8000BDB4
    if (ctx->r9 != ctx->r24) {
        // 0x8000BD74: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BD74: nop

    // 0x8000BD78: lwc1        $f6, 0x56D4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X56D4);
    // 0x8000BD7C: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD80: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8000BD84: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8000BD88: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8000BD8C: swc1        $f10, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f10.u32l;
    // 0x8000BD90: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BD94: nop

    // 0x8000BD98: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8000BD9C: nop

    // 0x8000BDA0: bc1f        L_8000BDB4
    if (!c1cs) {
        // 0x8000BDA4: nop
    
            goto L_8000BDB4;
    }
    // 0x8000BDA4: nop

    // 0x8000BDA8: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000BDAC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
    // 0x8000BDB0: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
L_8000BDB4:
    // 0x8000BDB4: lbu         $v1, 0x70($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X70);
    // 0x8000BDB8: nop

    // 0x8000BDBC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x8000BDC0: beq         $at, $zero, L_8000BE00
    if (ctx->r1 == 0) {
        // 0x8000BDC4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000BE00;
    }
    // 0x8000BDC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000BDC8: lwc1        $f8, 0x56D8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X56D8);
    // 0x8000BDCC: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDD0: mul.s       $f10, $f2, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x8000BDD4: andi        $v1, $zero, 0xFF
    ctx->r3 = 0 & 0XFF;
    // 0x8000BDD8: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000BDDC: swc1        $f6, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f6.u32l;
    // 0x8000BDE0: lwc1        $f8, 0x74($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BDE4: nop

    // 0x8000BDE8: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x8000BDEC: nop

    // 0x8000BDF0: bc1f        L_8000BDFC
    if (!c1cs) {
        // 0x8000BDF4: nop
    
            goto L_8000BDFC;
    }
    // 0x8000BDF4: nop

    // 0x8000BDF8: swc1        $f12, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f12.u32l;
L_8000BDFC:
    // 0x8000BDFC: sb          $zero, 0x70($v0)
    MEM_B(0X70, ctx->r2) = 0;
L_8000BE00:
    // 0x8000BE00: bgtz        $v1, L_8000BE20
    if (SIGNED(ctx->r3) > 0) {
        // 0x8000BE04: nop
    
            goto L_8000BE20;
    }
    // 0x8000BE04: nop

    // 0x8000BE08: lwc1        $f4, 0x74($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X74);
    // 0x8000BE0C: nop

    // 0x8000BE10: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x8000BE14: nop

    // 0x8000BE18: bc1f        L_8000BE74
    if (!c1cs) {
        // 0x8000BE1C: nop
    
            goto L_8000BE74;
    }
    // 0x8000BE1C: nop

L_8000BE20:
    // 0x8000BE20: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000BE24: lb          $a1, 0x2($s0)
    ctx->r5 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE28: addu        $t4, $t9, $s2
    ctx->r12 = ADD32(ctx->r25, ctx->r18);
    // 0x8000BE2C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000BE30: lb          $a2, 0x1D7($s0)
    ctx->r6 = MEM_B(ctx->r16, 0X1D7);
    // 0x8000BE34: lb          $a3, 0x203($s0)
    ctx->r7 = MEM_B(ctx->r16, 0X203);
    // 0x8000BE38: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    // 0x8000BE3C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
    // 0x8000BE40: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x8000BE44: jal         0x8000B750
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8000B750(rdram, ctx);
        goto after_1;
    // 0x8000BE48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8000BE4C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000BE50: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8000BE54: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8000BE58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000BE5C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x8000BE60: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x8000BE64: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8000BE68: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8000BE6C: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000BE70: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8000BE74:
    // 0x8000BE74: lb          $v1, 0x2($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X2);
    // 0x8000BE78: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000BE7C: addiu       $t7, $t7, -0x4A08
    ctx->r15 = ADD32(ctx->r15, -0X4A08);
    // 0x8000BE80: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8000BE84: addu        $v0, $t5, $t7
    ctx->r2 = ADD32(ctx->r13, ctx->r15);
    // 0x8000BE88: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x8000BE8C: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x8000BE90: addu        $t8, $t6, $s1
    ctx->r24 = ADD32(ctx->r14, ctx->r17);
    // 0x8000BE94: addu        $t4, $t9, $s1
    ctx->r12 = ADD32(ctx->r25, ctx->r17);
    // 0x8000BE98: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x8000BE9C: sb          $t4, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r12;
    // 0x8000BEA0: lb          $t5, 0x175($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X175);
    // 0x8000BEA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000BEA8: beq         $t5, $zero, L_8000BED8
    if (ctx->r13 == 0) {
        // 0x8000BEAC: nop
    
            goto L_8000BED8;
    }
    // 0x8000BEAC: nop

    // 0x8000BEB0: lbu         $t7, 0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEB4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000BEB8: addu        $v1, $t7, $t6
    ctx->r3 = ADD32(ctx->r15, ctx->r14);
    // 0x8000BEBC: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8000BEC0: beq         $at, $zero, L_8000BED0
    if (ctx->r1 == 0) {
        // 0x8000BEC4: addiu       $t8, $zero, 0x20
        ctx->r24 = ADD32(0, 0X20);
            goto L_8000BED0;
    }
    // 0x8000BEC4: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x8000BEC8: b           L_8000BEF8
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BECC: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BED0:
    // 0x8000BED0: b           L_8000BEF8
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
        goto L_8000BEF8;
    // 0x8000BED4: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
L_8000BED8:
    // 0x8000BED8: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x8000BEDC: nop

    // 0x8000BEE0: subu        $v1, $t9, $s1
    ctx->r3 = SUB32(ctx->r25, ctx->r17);
    // 0x8000BEE4: blez        $v1, L_8000BEF4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000BEE8: nop
    
            goto L_8000BEF4;
    }
    // 0x8000BEE8: nop

    // 0x8000BEEC: b           L_8000BEF8
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
        goto L_8000BEF8;
    // 0x8000BEF0: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_8000BEF4:
    // 0x8000BEF4: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
L_8000BEF8:
    // 0x8000BEF8: lw          $t4, -0x4B90($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4B90);
    // 0x8000BEFC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8000BF00: slt         $at, $t0, $t4
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000BF04: bne         $at, $zero, L_8000BBC4
    if (ctx->r1 != 0) {
        // 0x8000BF08: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8000BBC4;
    }
    // 0x8000BF08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8000BF0C:
    // 0x8000BF0C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000BF10: lw          $a0, -0x332C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X332C);
    // 0x8000BF14: nop

    // 0x8000BF18: beq         $a0, $zero, L_8000BF2C
    if (ctx->r4 == 0) {
        // 0x8000BF1C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8000BF2C;
    }
    // 0x8000BF1C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BF20: jal         0x80011134
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_tex_animate(rdram, ctx);
        goto after_2;
    // 0x8000BF24: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8000BF28: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8000BF2C:
    // 0x8000BF2C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8000BF30: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8000BF34: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8000BF38: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8000BF3C: jr          $ra
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000BF40: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void get_level_default_vehicle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DD6C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DD70: lw          $v0, 0x3A98($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3A98);
    // 0x8006DD74: jr          $ra
    // 0x8006DD78: nop

    return;
    // 0x8006DD78: nop

;}
RECOMP_FUNC void mtxf_from_scale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070878: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8007087C: addiu       $t1, $t0, 0x40
    ctx->r9 = ADD32(ctx->r8, 0X40);
L_80070880:
    // 0x80070880: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x80070884: bne         $t1, $t0, L_80070880
    if (ctx->r9 != ctx->r8) {
        // 0x80070888: sw          $zero, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = 0;
            goto L_80070880;
    }
    // 0x80070888: sw          $zero, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = 0;
    // 0x8007088C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070890: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070894: nop

    // 0x80070898: swc1        $f18, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f18.u32l;
    // 0x8007089C: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800708A0: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x800708A4: jr          $ra
    // 0x800708A8: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
    return;
    // 0x800708A8: sw          $a3, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r7;
;}
RECOMP_FUNC void level_properties_pop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C46C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8006C470: addiu       $t0, $t0, -0x2768
    ctx->r8 = ADD32(ctx->r8, -0X2768);
    // 0x8006C474: lh          $t6, 0x0($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X0);
    // 0x8006C478: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006C47C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8006C480: sh          $t7, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r15;
    // 0x8006C484: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x8006C488: addiu       $t1, $t1, 0x1748
    ctx->r9 = ADD32(ctx->r9, 0X1748);
    // 0x8006C48C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8006C490: addu        $t2, $t1, $t9
    ctx->r10 = ADD32(ctx->r9, ctx->r25);
    // 0x8006C494: lh          $t3, 0x0($t2)
    ctx->r11 = MEM_H(ctx->r10, 0X0);
    // 0x8006C498: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006C49C: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8006C4A0: lh          $t4, 0x0($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4A4: nop

    // 0x8006C4A8: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x8006C4AC: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
    // 0x8006C4B0: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4B4: nop

    // 0x8006C4B8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x8006C4BC: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8006C4C0: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x8006C4C4: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8006C4C8: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8006C4CC: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4D0: nop

    // 0x8006C4D4: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x8006C4D8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x8006C4DC: lh          $t4, 0x0($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X0);
    // 0x8006C4E0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8006C4E4: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8006C4E8: lh          $t5, 0x0($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4EC: nop

    // 0x8006C4F0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8006C4F4: sh          $t6, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r14;
    // 0x8006C4F8: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8006C4FC: nop

    // 0x8006C500: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8006C504: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8006C508: lh          $t2, 0x0($t9)
    ctx->r10 = MEM_H(ctx->r25, 0X0);
    // 0x8006C50C: beq         $v1, $at, L_8006C518
    if (ctx->r3 == ctx->r1) {
        // 0x8006C510: sw          $t2, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r10;
            goto L_8006C518;
    }
    // 0x8006C510: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8006C514: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
L_8006C518:
    // 0x8006C518: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006C51C: jr          $ra
    // 0x8006C520: sh          $t3, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = ctx->r11;
    return;
    // 0x8006C520: sh          $t3, -0x2764($at)
    MEM_H(-0X2764, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void obj_init_lasergun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034570: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80034574: addiu       $t6, $zero, 0x22
    ctx->r14 = ADD32(0, 0X22);
    // 0x80034578: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003457C: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x80034580: nop

    // 0x80034584: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x80034588: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003458C: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x80034590: nop

    // 0x80034594: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
    // 0x80034598: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8003459C: nop

    // 0x800345A0: sb          $t0, 0xF($v0)
    MEM_B(0XF, ctx->r2) = ctx->r8;
    // 0x800345A4: lbu         $t1, 0xC($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XC);
    // 0x800345A8: lb          $t3, 0xF($v0)
    ctx->r11 = MEM_B(ctx->r2, 0XF);
    // 0x800345AC: sb          $t1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r9;
    // 0x800345B0: lbu         $t2, 0xD($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XD);
    // 0x800345B4: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x800345B8: sb          $t2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r10;
    // 0x800345BC: lbu         $t5, 0x8($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X8);
    // 0x800345C0: nop

    // 0x800345C4: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800345C8: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800345CC: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x800345D0: nop

    // 0x800345D4: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800345D8: jr          $ra
    // 0x800345DC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
    return;
    // 0x800345DC: sh          $t9, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void get_object_list_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E4E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E4EC: lw          $v0, -0x4C20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4C20);
    // 0x8001E4F0: jr          $ra
    // 0x8001E4F4: nop

    return;
    // 0x8001E4F4: nop

;}
RECOMP_FUNC void _frexpf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB664: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800CB668: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800CB66C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800CB670: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB674: nop

    // 0x800CB678: c.eq.d      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.d == ctx->f4.d;
    // 0x800CB67C: nop

    // 0x800CB680: bc1f        L_800CB690
    if (!c1cs) {
        // 0x800CB684: nop
    
            goto L_800CB690;
    }
    // 0x800CB684: nop

    // 0x800CB688: b           L_800CB7E0
    // 0x800CB68C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
        goto L_800CB7E0;
    // 0x800CB68C: mov.d       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.d = ctx->f12.d;
L_800CB690:
    // 0x800CB690: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x800CB694: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB698: nop

    // 0x800CB69C: c.lt.d      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.d < ctx->f12.d;
    // 0x800CB6A0: nop

    // 0x800CB6A4: bc1f        L_800CB6B8
    if (!c1cs) {
        // 0x800CB6A8: nop
    
            goto L_800CB6B8;
    }
    // 0x800CB6A8: nop

    // 0x800CB6AC: swc1        $f13, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(13 - 1) * 2];
    // 0x800CB6B0: b           L_800CB6C4
    // 0x800CB6B4: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
        goto L_800CB6C4;
    // 0x800CB6B4: swc1        $f12, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f12.u32l;
L_800CB6B8:
    // 0x800CB6B8: neg.d       $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = -ctx->f12.d;
    // 0x800CB6BC: swc1        $f8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f8.u32l;
    // 0x800CB6C0: swc1        $f9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(9 - 1) * 2];
L_800CB6C4:
    // 0x800CB6C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB6C8: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB6CC: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB6D0: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB6D4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB6D8: nop

    // 0x800CB6DC: c.le.d      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.d <= ctx->f10.d;
    // 0x800CB6E0: nop

    // 0x800CB6E4: bc1f        L_800CB734
    if (!c1cs) {
        // 0x800CB6E8: nop
    
            goto L_800CB734;
    }
    // 0x800CB6E8: nop

L_800CB6EC:
    // 0x800CB6EC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800CB6F0: nop

    // 0x800CB6F4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CB6F8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800CB6FC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB700: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800CB704: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB708: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB70C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CB710: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800CB714: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800CB718: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800CB71C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB720: nop

    // 0x800CB724: c.le.d      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.d <= ctx->f6.d;
    // 0x800CB728: swc1        $f6, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f6.u32l;
    // 0x800CB72C: bc1t        L_800CB6EC
    if (c1cs) {
        // 0x800CB730: swc1        $f7, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
            goto L_800CB6EC;
    }
    // 0x800CB730: swc1        $f7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(7 - 1) * 2];
L_800CB734:
    // 0x800CB734: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB738: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800CB73C: lwc1        $f11, 0x8($sp)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB740: lwc1        $f10, 0xC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB744: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800CB748: nop

    // 0x800CB74C: c.lt.d      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.d < ctx->f16.d;
    // 0x800CB750: nop

    // 0x800CB754: bc1f        L_800CB794
    if (!c1cs) {
        // 0x800CB758: nop
    
            goto L_800CB794;
    }
    // 0x800CB758: nop

L_800CB75C:
    // 0x800CB75C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800CB760: nop

    // 0x800CB764: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CB768: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CB76C: lwc1        $f19, 0x8($sp)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB770: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB774: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800CB778: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800CB77C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CB780: add.d       $f4, $f18, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f18.d + ctx->f18.d;
    // 0x800CB784: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CB788: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800CB78C: bc1t        L_800CB75C
    if (c1cs) {
        // 0x800CB790: swc1        $f5, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
            goto L_800CB75C;
    }
    // 0x800CB790: swc1        $f5, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(5 - 1) * 2];
L_800CB794:
    // 0x800CB794: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x800CB798: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800CB79C: nop

    // 0x800CB7A0: c.lt.d      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.d < ctx->f12.d;
    // 0x800CB7A4: nop

    // 0x800CB7A8: bc1f        L_800CB7C0
    if (!c1cs) {
        // 0x800CB7AC: nop
    
            goto L_800CB7C0;
    }
    // 0x800CB7AC: nop

    // 0x800CB7B0: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB7B4: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB7B8: b           L_800CB7D0
    // 0x800CB7BC: nop

        goto L_800CB7D0;
    // 0x800CB7BC: nop

L_800CB7C0:
    // 0x800CB7C0: lwc1        $f15, 0x8($sp)
    ctx->f_odd[(15 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x800CB7C4: lwc1        $f14, 0xC($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800CB7C8: nop

    // 0x800CB7CC: neg.d       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.d); 
    ctx->f14.d = -ctx->f14.d;
L_800CB7D0:
    // 0x800CB7D0: b           L_800CB7E0
    // 0x800CB7D4: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
        goto L_800CB7E0;
    // 0x800CB7D4: mov.d       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.d = ctx->f14.d;
    // 0x800CB7D8: b           L_800CB7E0
    // 0x800CB7DC: nop

        goto L_800CB7E0;
    // 0x800CB7DC: nop

L_800CB7E0:
    // 0x800CB7E0: jr          $ra
    // 0x800CB7E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800CB7E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void light_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800323D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800323DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800323E0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800323E4: addiu       $s3, $s3, -0x3134
    ctx->r19 = ADD32(ctx->r19, -0X3134);
    // 0x800323E8: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800323EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800323F0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800323F4: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800323F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800323FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80032400: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80032404: blez        $t6, L_80032444
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80032408: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80032444;
    }
    // 0x80032408: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003240C: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x80032410: addiu       $s4, $s4, -0x3140
    ctx->r20 = ADD32(ctx->r20, -0X3140);
    // 0x80032414: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80032418:
    // 0x80032418: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8003241C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80032420: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80032424: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80032428: jal         0x80032464
    // 0x8003242C: nop

    light_update(rdram, ctx);
        goto after_0;
    // 0x8003242C: nop

    after_0:
    // 0x80032430: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80032434: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80032438: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003243C: bne         $at, $zero, L_80032418
    if (ctx->r1 != 0) {
        // 0x80032440: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80032418;
    }
    // 0x80032440: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80032444:
    // 0x80032444: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80032448: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003244C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80032450: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80032454: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80032458: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8003245C: jr          $ra
    // 0x80032460: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80032460: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void clear_dialogue_box_open_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5C30: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5C34: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5C38: lw          $t6, -0x5258($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5258);
    // 0x800C5C3C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5C40: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5C44: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5C48: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5C4C: nop

    // 0x800C5C50: andi        $t9, $t8, 0xBFFF
    ctx->r25 = ctx->r24 & 0XBFFF;
    // 0x800C5C54: jr          $ra
    // 0x800C5C58: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5C58: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void ghostmenu_erase(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099E1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80099E20: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80099E24: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80099E28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80099E2C: bltz        $a0, L_80099F84
    if (SIGNED(ctx->r4) < 0) {
        // 0x80099E30: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_80099F84;
    }
    // 0x80099E30: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80099E34: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099E38: addiu       $v1, $v1, 0x6A74
    ctx->r3 = ADD32(ctx->r3, 0X6A74);
    // 0x80099E3C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80099E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80099E44: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80099E48: beq         $at, $zero, L_80099F84
    if (ctx->r1 == 0) {
        // 0x80099E4C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80099F84;
    }
    // 0x80099E4C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80099E50: jal         0x80001D04
    // 0x80099E54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x80099E54: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80099E58: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099E5C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80099E60: addu        $s0, $s0, $a2
    ctx->r16 = ADD32(ctx->r16, ctx->r6);
    // 0x80099E64: lbu         $s0, 0x6AE0($s0)
    ctx->r16 = MEM_BU(ctx->r16, 0X6AE0);
    // 0x80099E68: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80099E6C: lw          $a0, 0x6A70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A70);
    // 0x80099E70: jal         0x80075630
    // 0x80099E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800753D8(rdram, ctx);
        goto after_1;
    // 0x80099E74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80099E78: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80099E7C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80099E80: addiu       $v1, $v1, 0x6A74
    ctx->r3 = ADD32(ctx->r3, 0X6A74);
    // 0x80099E84: bne         $v0, $zero, L_80099F84
    if (ctx->r2 != 0) {
        // 0x80099E88: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_80099F84;
    }
    // 0x80099E88: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x80099E8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80099E90: addu        $at, $at, $s0
    ctx->r1 = ADD32(ctx->r1, ctx->r16);
    // 0x80099E94: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80099E98: sb          $t7, 0x6A7C($at)
    MEM_B(0X6A7C, ctx->r1) = ctx->r15;
    // 0x80099E9C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80099EA0: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x80099EA4: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x80099EA8: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80099EAC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80099EB0: beq         $at, $zero, L_80099F4C
    if (ctx->r1 == 0) {
        // 0x80099EB4: or          $t1, $t9, $zero
        ctx->r9 = ctx->r25 | 0;
            goto L_80099F4C;
    }
    // 0x80099EB4: or          $t1, $t9, $zero
    ctx->r9 = ctx->r25 | 0;
    // 0x80099EB8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80099EBC: addiu       $t3, $t3, 0x6AE0
    ctx->r11 = ADD32(ctx->r11, 0X6AE0);
    // 0x80099EC0: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x80099EC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80099EC8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80099ECC: addiu       $t5, $t5, 0x6AB0
    ctx->r13 = ADD32(ctx->r13, 0X6AB0);
    // 0x80099ED0: addiu       $t4, $t4, 0x6AA8
    ctx->r12 = ADD32(ctx->r12, 0X6AA8);
    // 0x80099ED4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80099ED8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099EDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80099EE0: addiu       $t8, $t8, 0x6AC0
    ctx->r24 = ADD32(ctx->r24, 0X6AC0);
    // 0x80099EE4: addiu       $t6, $t6, 0x6AB8
    ctx->r14 = ADD32(ctx->r14, 0X6AB8);
    // 0x80099EE8: addiu       $t3, $t3, 0x6AC0
    ctx->r11 = ADD32(ctx->r11, 0X6AC0);
    // 0x80099EEC: addu        $a0, $a2, $t4
    ctx->r4 = ADD32(ctx->r6, ctx->r12);
    // 0x80099EF0: addu        $a1, $a2, $t5
    ctx->r5 = ADD32(ctx->r6, ctx->r13);
    // 0x80099EF4: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x80099EF8: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80099EFC: addu        $a3, $t9, $t3
    ctx->r7 = ADD32(ctx->r25, ctx->r11);
    // 0x80099F00: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80099F04: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_80099F08:
    // 0x80099F08: lbu         $t4, 0x1($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X1);
    // 0x80099F0C: lbu         $t5, 0x1($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X1);
    // 0x80099F10: lbu         $t6, 0x1($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X1);
    // 0x80099F14: lbu         $t7, 0x1($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X1);
    // 0x80099F18: lhu         $t8, 0x2($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2);
    // 0x80099F1C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80099F20: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x80099F24: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80099F28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80099F2C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80099F30: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80099F34: sb          $t4, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r12;
    // 0x80099F38: sb          $t5, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = ctx->r13;
    // 0x80099F3C: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x80099F40: sb          $t7, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r15;
    // 0x80099F44: bne         $at, $zero, L_80099F08
    if (ctx->r1 != 0) {
        // 0x80099F48: sh          $t8, -0x2($v1)
        MEM_H(-0X2, ctx->r3) = ctx->r24;
            goto L_80099F08;
    }
    // 0x80099F48: sh          $t8, -0x2($v1)
    MEM_H(-0X2, ctx->r3) = ctx->r24;
L_80099F4C:
    // 0x80099F4C: blez        $t1, L_80099F84
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80099F50: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_80099F84;
    }
    // 0x80099F50: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80099F54: addiu       $v0, $t9, 0x6AE0
    ctx->r2 = ADD32(ctx->r25, 0X6AE0);
    // 0x80099F58: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
L_80099F5C:
    // 0x80099F5C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80099F60: nop

    // 0x80099F64: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80099F68: beq         $at, $zero, L_80099F74
    if (ctx->r1 == 0) {
        // 0x80099F6C: addiu       $t3, $v1, -0x1
        ctx->r11 = ADD32(ctx->r3, -0X1);
            goto L_80099F74;
    }
    // 0x80099F6C: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x80099F70: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
L_80099F74:
    // 0x80099F74: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80099F78: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80099F7C: bne         $at, $zero, L_80099F5C
    if (ctx->r1 != 0) {
        // 0x80099F80: nop
    
            goto L_80099F5C;
    }
    // 0x80099F80: nop

L_80099F84:
    // 0x80099F84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80099F88: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80099F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80099F90: jr          $ra
    // 0x80099F94: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x80099F94: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void get_level_segment_index_from_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F58: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80029F5C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80029F60: lw          $v0, -0x3178($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3178);
    // 0x80029F64: swc1        $f20, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f20.u32l;
    // 0x80029F68: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80029F6C: bne         $v0, $zero, L_80029F7C
    if (ctx->r2 != 0) {
        // 0x80029F70: swc1        $f21, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
            goto L_80029F7C;
    }
    // 0x80029F70: swc1        $f21, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80029F74: b           L_8002A08C
    // 0x80029F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8002A08C;
    // 0x80029F78: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80029F7C:
    // 0x80029F7C: lh          $a3, 0x1A($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X1A);
    // 0x80029F80: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80029F84: ori         $a0, $a0, 0x4240
    ctx->r4 = ctx->r4 | 0X4240;
    // 0x80029F88: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80029F8C: blez        $a3, L_8002A088
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80029F90: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8002A088;
    }
    // 0x80029F90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80029F94: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80029F98: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80029F9C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80029FA0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FA4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FA8: nop

    // 0x80029FAC: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80029FB0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80029FB4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80029FB8: nop

L_80029FBC:
    // 0x80029FBC: lh          $t7, 0x6($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6);
    // 0x80029FC0: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80029FC4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80029FC8: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x80029FCC: nop
    
            goto L_8002A078;
    }
    // 0x80029FCC: nop

    // 0x80029FD0: lh          $t8, 0x0($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X0);
    // 0x80029FD4: nop

    // 0x80029FD8: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029FDC: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x80029FE0: nop
    
            goto L_8002A078;
    }
    // 0x80029FE0: nop

    // 0x80029FE4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80029FE8: lh          $t2, 0xA($t0)
    ctx->r10 = MEM_H(ctx->r8, 0XA);
    // 0x80029FEC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80029FF0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80029FF4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80029FF8: nop

    // 0x80029FFC: cvt.w.s     $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    ctx->f6.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8002A000: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002A004: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002A008: slt         $at, $v0, $t2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002A00C: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A010: nop
    
            goto L_8002A078;
    }
    // 0x8002A010: nop

    // 0x8002A014: lh          $t3, 0x4($t0)
    ctx->r11 = MEM_H(ctx->r8, 0X4);
    // 0x8002A018: nop

    // 0x8002A01C: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002A020: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A024: nop
    
            goto L_8002A078;
    }
    // 0x8002A024: nop

    // 0x8002A028: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002A02C: lh          $t4, 0x8($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X8);
    // 0x8002A030: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002A034: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002A038: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002A03C: lh          $t5, 0x2($t0)
    ctx->r13 = MEM_H(ctx->r8, 0X2);
    // 0x8002A040: cvt.w.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    ctx->f8.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8002A044: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8002A048: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x8002A04C: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x8002A050: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002A054: subu        $v0, $t8, $t6
    ctx->r2 = SUB32(ctx->r24, ctx->r14);
    // 0x8002A058: bgez        $v0, L_8002A068
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8002A05C: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8002A068;
    }
    // 0x8002A05C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002A060: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8002A064: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
L_8002A068:
    // 0x8002A068: beq         $at, $zero, L_8002A078
    if (ctx->r1 == 0) {
        // 0x8002A06C: nop
    
            goto L_8002A078;
    }
    // 0x8002A06C: nop

    // 0x8002A070: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8002A074: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_8002A078:
    // 0x8002A078: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002A07C: slt         $at, $a2, $a3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8002A080: bne         $at, $zero, L_80029FBC
    if (ctx->r1 != 0) {
        // 0x8002A084: addiu       $t1, $t1, 0xC
        ctx->r9 = ADD32(ctx->r9, 0XC);
            goto L_80029FBC;
    }
    // 0x8002A084: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
L_8002A088:
    // 0x8002A088: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8002A08C:
    // 0x8002A08C: lwc1        $f21, 0x8($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X8);
    // 0x8002A090: lwc1        $f20, 0xC($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8002A094: jr          $ra
    // 0x8002A098: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002A098: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void hud_battle_portraits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A2388: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800A238C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A2390: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800A2394: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800A2398: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800A239C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800A23A0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800A23A4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800A23A8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800A23AC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800A23B0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800A23B4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800A23B8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A23BC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800A23C0: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x800A23C4: jal         0x8001BAA8
    // 0x800A23C8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A23C8: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_0:
    // 0x800A23CC: beq         $s0, $zero, L_800A23E0
    if (ctx->r16 == 0) {
        // 0x800A23D0: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_800A23E0;
    }
    // 0x800A23D0: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x800A23D4: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800A23D8: b           L_800A23F4
    // 0x800A23DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800A23F4;
    // 0x800A23DC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A23E0:
    // 0x800A23E0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800A23E4: nop

    // 0x800A23E8: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x800A23EC: nop

    // 0x800A23F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800A23F4:
    // 0x800A23F4: jal         0x80068748
    // 0x800A23F8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A23F8: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    after_1:
    // 0x800A23FC: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800A2400: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A2404: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A2408: bne         $t7, $at, L_800A27F4
    if (ctx->r15 != ctx->r1) {
        // 0x800A240C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A27F4;
    }
    // 0x800A240C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A2410: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2414: addiu       $s0, $s0, 0x729C
    ctx->r16 = ADD32(ctx->r16, 0X729C);
    // 0x800A2418: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A241C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A2420: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2424: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2428: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A242C: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2430: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A2434: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x800A2438: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A243C: mfc1        $s4, $f6
    ctx->r20 = (int32_t)ctx->f6.u32l;
    // 0x800A2440: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800A2444: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A2448: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A244C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A2450: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2454: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2458: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A245C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A2460: lwc1        $f21, -0x7350($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, -0X7350);
    // 0x800A2464: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A2468: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800A246C: lwc1        $f20, -0x734C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X734C);
    // 0x800A2470: addiu       $s5, $s5, 0x72F7
    ctx->r21 = ADD32(ctx->r21, 0X72F7);
    // 0x800A2474: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800A2478: addiu       $fp, $zero, 0x2
    ctx->r30 = ADD32(0, 0X2);
    // 0x800A247C: addiu       $s7, $zero, 0x10
    ctx->r23 = ADD32(0, 0X10);
    // 0x800A2480: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800A2484: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
L_800A2488:
    // 0x800A2488: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800A248C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2490: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A2494: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A2498: addu        $t3, $s1, $t0
    ctx->r11 = ADD32(ctx->r17, ctx->r8);
    // 0x800A249C: sub.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f12.fl;
    // 0x800A24A0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A24A4: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A24A8: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A24AC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A24B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A24B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A24B8: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800A24BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A24C0: lw          $a0, 0x64($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X64);
    // 0x800A24C4: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A24C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A24CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A24D0: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800A24D4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800A24D8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800A24DC: nop

    // 0x800A24E0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800A24E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A24E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A24EC: nop

    // 0x800A24F0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A24F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800A24F8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800A24FC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2500: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x800A2504: add.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A2508: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A250C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2510: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A2514: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2518: nop

    // 0x800A251C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2520: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A2524: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2528: nop

    // 0x800A252C: lwc1        $f4, 0x68C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A2530: nop

    // 0x800A2534: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A2538: swc1        $f6, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f6.u32l;
    // 0x800A253C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2540: nop

    // 0x800A2544: lwc1        $f8, 0x690($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2548: nop

    // 0x800A254C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A2550: swc1        $f10, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f10.u32l;
    // 0x800A2554: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2558: nop

    // 0x800A255C: lwc1        $f16, 0x6AC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2560: nop

    // 0x800A2564: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2568: swc1        $f18, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f18.u32l;
    // 0x800A256C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2570: nop

    // 0x800A2574: lwc1        $f4, 0x6B0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2578: nop

    // 0x800A257C: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A2580: swc1        $f6, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f6.u32l;
    // 0x800A2584: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2588: nop

    // 0x800A258C: lwc1        $f8, 0x6CC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A2590: nop

    // 0x800A2594: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2598: swc1        $f10, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f10.u32l;
    // 0x800A259C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25A0: nop

    // 0x800A25A4: lwc1        $f16, 0x6D0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A25A8: nop

    // 0x800A25AC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A25B0: swc1        $f18, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f18.u32l;
    // 0x800A25B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25B8: nop

    // 0x800A25BC: lwc1        $f4, 0x6EC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A25C0: nop

    // 0x800A25C4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A25C8: swc1        $f6, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f6.u32l;
    // 0x800A25CC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A25D0: nop

    // 0x800A25D4: lwc1        $f8, 0x6F0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A25D8: nop

    // 0x800A25DC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A25E0: swc1        $f10, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f10.u32l;
    // 0x800A25E4: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A25E8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800A25EC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A25F0: bne         $at, $zero, L_800A260C
    if (ctx->r1 != 0) {
        // 0x800A25F4: nop
    
            goto L_800A260C;
    }
    // 0x800A25F4: nop

    // 0x800A25F8: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A25FC: lh          $t6, 0x0($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X0);
    // 0x800A2600: nop

    // 0x800A2604: bne         $t5, $t6, L_800A2628
    if (ctx->r13 != ctx->r14) {
        // 0x800A2608: nop
    
            goto L_800A2628;
    }
    // 0x800A2608: nop

L_800A260C:
    // 0x800A260C: sw          $a3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r7;
    // 0x800A2610: jal         0x800A2834
    // 0x800A2614: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    hud_lives_render(rdram, ctx);
        goto after_2;
    // 0x800A2614: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    after_2:
    // 0x800A2618: lw          $a3, 0x7C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X7C);
    // 0x800A261C: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x800A2620: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800A2624: nop

L_800A2628:
    // 0x800A2628: bne         $s6, $v1, L_800A2638
    if (ctx->r22 != ctx->r3) {
        // 0x800A262C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800A2638;
    }
    // 0x800A262C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800A2630: b           L_800A2690
    // 0x800A2634: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
        goto L_800A2690;
    // 0x800A2634: addiu       $s4, $s4, 0x44
    ctx->r20 = ADD32(ctx->r20, 0X44);
L_800A2638:
    // 0x800A2638: bne         $fp, $v1, L_800A2690
    if (ctx->r30 != ctx->r3) {
        // 0x800A263C: lui         $t7, 0x8000
        ctx->r15 = S32(0X8000 << 16);
            goto L_800A2690;
    }
    // 0x800A263C: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800A2640: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800A2644: nop

    // 0x800A2648: bne         $t7, $zero, L_800A268C
    if (ctx->r15 != 0) {
        // 0x800A264C: nop
    
            goto L_800A268C;
    }
    // 0x800A264C: nop

    // 0x800A2650: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800A2654: nop

    // 0x800A2658: cvt.d.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.d = CVT_D_W(ctx->f16.u32l);
    // 0x800A265C: add.d       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f20.d); 
    ctx->f4.d = ctx->f18.d + ctx->f20.d;
    // 0x800A2660: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A2664: nop

    // 0x800A2668: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A266C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A2670: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A2674: nop

    // 0x800A2678: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A267C: mfc1        $s1, $f6
    ctx->r17 = (int32_t)ctx->f6.u32l;
    // 0x800A2680: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A2684: b           L_800A2690
    // 0x800A2688: nop

        goto L_800A2690;
    // 0x800A2688: nop

L_800A268C:
    // 0x800A268C: addiu       $s1, $s1, 0x37
    ctx->r17 = ADD32(ctx->r17, 0X37);
L_800A2690:
    // 0x800A2690: bne         $s2, $s7, L_800A2488
    if (ctx->r18 != ctx->r23) {
        // 0x800A2694: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800A2488;
    }
    // 0x800A2694: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800A2698: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x800A269C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A26A0: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800A26A4: lwc1        $f12, 0x64C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A26A8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A26AC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A26B0: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A26B4: sub.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A26B8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A26BC: nop

    // 0x800A26C0: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A26C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A26C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A26CC: nop

    // 0x800A26D0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A26D4: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A26D8: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800A26DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A26E0: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800A26E4: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800A26E8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A26EC: nop

    // 0x800A26F0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A26F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A26F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A26FC: nop

    // 0x800A2700: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A2704: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A2708: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800A270C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A2710: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x800A2714: add.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A2718: swc1        $f4, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f4.u32l;
    // 0x800A271C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2720: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A2724: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A2728: nop

    // 0x800A272C: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A2730: swc1        $f10, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f10.u32l;
    // 0x800A2734: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2738: nop

    // 0x800A273C: lwc1        $f16, 0x68C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X68C);
    // 0x800A2740: nop

    // 0x800A2744: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A2748: swc1        $f18, 0x68C($v0)
    MEM_W(0X68C, ctx->r2) = ctx->f18.u32l;
    // 0x800A274C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2750: nop

    // 0x800A2754: lwc1        $f4, 0x690($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X690);
    // 0x800A2758: nop

    // 0x800A275C: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A2760: swc1        $f6, 0x690($v0)
    MEM_W(0X690, ctx->r2) = ctx->f6.u32l;
    // 0x800A2764: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2768: nop

    // 0x800A276C: lwc1        $f8, 0x6AC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6AC);
    // 0x800A2770: nop

    // 0x800A2774: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A2778: swc1        $f10, 0x6AC($v0)
    MEM_W(0X6AC, ctx->r2) = ctx->f10.u32l;
    // 0x800A277C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2780: nop

    // 0x800A2784: lwc1        $f16, 0x6B0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6B0);
    // 0x800A2788: nop

    // 0x800A278C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A2790: swc1        $f18, 0x6B0($v0)
    MEM_W(0X6B0, ctx->r2) = ctx->f18.u32l;
    // 0x800A2794: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A2798: nop

    // 0x800A279C: lwc1        $f4, 0x6CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6CC);
    // 0x800A27A0: nop

    // 0x800A27A4: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A27A8: swc1        $f6, 0x6CC($v0)
    MEM_W(0X6CC, ctx->r2) = ctx->f6.u32l;
    // 0x800A27AC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27B0: nop

    // 0x800A27B4: lwc1        $f8, 0x6D0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X6D0);
    // 0x800A27B8: nop

    // 0x800A27BC: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x800A27C0: swc1        $f10, 0x6D0($v0)
    MEM_W(0X6D0, ctx->r2) = ctx->f10.u32l;
    // 0x800A27C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27C8: nop

    // 0x800A27CC: lwc1        $f16, 0x6EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X6EC);
    // 0x800A27D0: nop

    // 0x800A27D4: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A27D8: swc1        $f18, 0x6EC($v0)
    MEM_W(0X6EC, ctx->r2) = ctx->f18.u32l;
    // 0x800A27DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800A27E0: nop

    // 0x800A27E4: lwc1        $f4, 0x6F0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X6F0);
    // 0x800A27E8: nop

    // 0x800A27EC: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A27F0: swc1        $f6, 0x6F0($v0)
    MEM_W(0X6F0, ctx->r2) = ctx->f6.u32l;
L_800A27F4:
    // 0x800A27F4: jal         0x80068748
    // 0x800A27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A27F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x800A27FC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800A2800: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800A2804: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A2808: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A280C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800A2810: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800A2814: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800A2818: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800A281C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800A2820: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800A2824: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800A2828: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800A282C: jr          $ra
    // 0x800A2830: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800A2830: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void get_next_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4B24: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B4B28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B4B2C: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x800B4B30: addiu       $a1, $a1, 0x3284
    ctx->r5 = ADD32(ctx->r5, 0X3284);
    // 0x800B4B34: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x800B4B38: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4B3C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4B40: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4B44: bne         $at, $zero, L_800B4B64
    if (ctx->r1 != 0) {
        // 0x800B4B48: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4B64;
    }
    // 0x800B4B48: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4B4C:
    // 0x800B4B4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800B4B50: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B4B54: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B4B58: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B4B5C: beq         $at, $zero, L_800B4B4C
    if (ctx->r1 == 0) {
        // 0x800B4B60: subu        $t8, $v1, $v0
        ctx->r24 = SUB32(ctx->r3, ctx->r2);
            goto L_800B4B4C;
    }
    // 0x800B4B60: subu        $t8, $v1, $v0
    ctx->r24 = SUB32(ctx->r3, ctx->r2);
L_800B4B64:
    // 0x800B4B64: lw          $t9, 0x328C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X328C);
    // 0x800B4B68: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4B6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4B70: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800B4B74: jr          $ra
    // 0x800B4B78: nop

    return;
    // 0x800B4B78: nop

;}
RECOMP_FUNC void read_save_file(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007445C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80074460: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074464: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80074468: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007446C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80074470: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80074474: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80074478: jal         0x8006A340
    // 0x8007447C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x8007447C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    after_0:
    // 0x80074480: jal         0x800CE770
    // 0x80074484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074484: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074488: bne         $v0, $zero, L_80074498
    if (ctx->r2 != 0) {
        // 0x8007448C: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_80074498;
    }
    // 0x8007448C: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x80074490: b           L_80074558
    // 0x80074494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074558;
    // 0x80074494: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80074498:
    // 0x80074498: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8007449C: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x800744A0: beq         $v0, $zero, L_800744C4
    if (ctx->r2 == 0) {
        // 0x800744A4: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800744C4;
    }
    // 0x800744A4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800744A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800744AC: beq         $v0, $at, L_800744CC
    if (ctx->r2 == ctx->r1) {
        // 0x800744B0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800744CC;
    }
    // 0x800744B0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800744B4: beq         $v0, $at, L_800744D4
    if (ctx->r2 == ctx->r1) {
        // 0x800744B8: addiu       $v1, $zero, 0xA
        ctx->r3 = ADD32(0, 0XA);
            goto L_800744D4;
    }
    // 0x800744B8: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800744BC: b           L_800744D4
    // 0x800744C0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
        goto L_800744D4;
    // 0x800744C0: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
L_800744C4:
    // 0x800744C4: b           L_800744D4
    // 0x800744C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800744D4;
    // 0x800744C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800744CC:
    // 0x800744CC: b           L_800744D4
    // 0x800744D0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_800744D4;
    // 0x800744D0: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_800744D4:
    // 0x800744D4: jal         0x80070EDC
    // 0x800744D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800744D8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x800744DC: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800744E0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800744E4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800744E8:
    // 0x800744E8: jal         0x8006A340
    // 0x800744EC: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x800744EC: nop

    after_3:
    // 0x800744F0: sll         $t6, $s0, 3
    ctx->r14 = S32(ctx->r16 << 3);
    // 0x800744F4: addu        $a2, $t6, $s2
    ctx->r6 = ADD32(ctx->r14, ctx->r18);
    // 0x800744F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800744FC: jal         0x800CE7E0
    // 0x80074500: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x80074500: andi        $a1, $s1, 0xFF
    ctx->r5 = ctx->r17 & 0XFF;
    after_4:
    // 0x80074504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074508: bne         $s0, $s3, L_800744E8
    if (ctx->r16 != ctx->r19) {
        // 0x8007450C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800744E8;
    }
    // 0x8007450C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80074510: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80074514: jal         0x800732C4
    // 0x80074518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    populate_settings_from_save_data(rdram, ctx);
        goto after_5;
    // 0x80074518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_5:
    // 0x8007451C: jal         0x80071380
    // 0x80074520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80074520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80074524: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80074528: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8007452C: lbu         $v1, 0x4B($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4B);
    // 0x80074530: nop

    // 0x80074534: beq         $v1, $zero, L_80074558
    if (ctx->r3 == 0) {
        // 0x80074538: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074558;
    }
    // 0x80074538: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007453C: jal         0x80074574
    // 0x80074540: nop

    erase_save_file(rdram, ctx);
        goto after_7;
    // 0x80074540: nop

    after_7:
    // 0x80074544: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80074548: nop

    // 0x8007454C: lbu         $v1, 0x4B($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X4B);
    // 0x80074550: nop

    // 0x80074554: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074558:
    // 0x80074558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007455C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80074560: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80074564: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80074568: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007456C: jr          $ra
    // 0x80074570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074570: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void __cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D5010: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x800D5014: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x800D5018: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D501C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5020: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x800D5024: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800D5028: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x800D502C: beql        $at, $zero, L_800D5154
    if (ctx->r1 == 0) {
        // 0x800D5030: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_800D5154;
    }
    goto skip_0;
    // 0x800D5030: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x800D5034: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5038: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800D503C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800D5040: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800D5044: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800D5048: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D504C: bc1fl       L_800D5060
    if (!c1cs) {
        // 0x800D5050: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_800D5060;
    }
    goto skip_1;
    // 0x800D5050: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x800D5054: b           L_800D5060
    // 0x800D5058: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_800D5060;
    // 0x800D5058: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800D505C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_800D5060:
    // 0x800D5060: ldc1        $f8, -0x6298($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X6298);
    // 0x800D5064: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x800D5068: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D506C: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x800D5070: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x800D5074: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D5078: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x800D507C: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x800D5080: nop

    // 0x800D5084: bc1fl       L_800D50A4
    if (!c1cs) {
        // 0x800D5088: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_800D50A4;
    }
    goto skip_2;
    // 0x800D5088: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x800D508C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x800D5090: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x800D5094: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800D5098: b           L_800D50B4
    // 0x800D509C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_800D50B4;
    // 0x800D509C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D50A0: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_800D50A4:
    // 0x800D50A4: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x800D50A8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800D50AC: nop

    // 0x800D50B0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_800D50B4:
    // 0x800D50B4: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D50B8: ldc1        $f10, -0x6290($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X6290);
    // 0x800D50BC: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x800D50C0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D50C4: ldc1        $f6, -0x6288($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X6288);
    // 0x800D50C8: lui         $v1, 0x800F
    ctx->r3 = S32(0X800F << 16);
    // 0x800D50CC: addiu       $v1, $v1, -0x62C0
    ctx->r3 = ADD32(ctx->r3, -0X62C0);
    // 0x800D50D0: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x800D50D4: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x800D50D8: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x800D50DC: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x800D50E0: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x800D50E4: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x800D50E8: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x800D50EC: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x800D50F0: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x800D50F4: nop

    // 0x800D50F8: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x800D50FC: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x800D5100: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800D5104: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x800D5108: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x800D510C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800D5110: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x800D5114: bne         $t0, $zero, L_800D5134
    if (ctx->r8 != 0) {
        // 0x800D5118: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_800D5134;
    }
    // 0x800D5118: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x800D511C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D5120: nop

    // 0x800D5124: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800D5128: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x800D512C: jr          $ra
    // 0x800D5130: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x800D5130: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_800D5134:
    // 0x800D5134: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x800D5138: nop

    // 0x800D513C: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x800D5140: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x800D5144: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x800D5148: jr          $ra
    // 0x800D514C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x800D514C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D5150: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_800D5154:
    // 0x800D5154: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5158: bc1t        L_800D516C
    if (c1cs) {
        // 0x800D515C: nop
    
            goto L_800D516C;
    }
    // 0x800D515C: nop

    // 0x800D5160: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800D5164: jr          $ra
    // 0x800D5168: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
    return;
    // 0x800D5168: lwc1        $f0, -0x61C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X61C0);
L_800D516C:
    // 0x800D516C: lwc1        $f0, -0x6280($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6280);
    // 0x800D5170: jr          $ra
    // 0x800D5174: nop

    return;
    // 0x800D5174: nop

;}
RECOMP_FUNC void mempool_free_queue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800713D8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800713DC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800713E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800713E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800713E8: jal         0x8006F750
    // 0x800713EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    interrupts_disable(rdram, ctx);
        goto after_0;
    // 0x800713EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800713F0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800713F4: addiu       $s1, $s1, 0x4348
    ctx->r17 = ADD32(ctx->r17, 0X4348);
    // 0x800713F8: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800713FC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80071400: blez        $v1, L_80071494
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071404: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80071494;
    }
    // 0x80071404: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80071408: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8007140C: addiu       $s2, $s2, 0x3B48
    ctx->r18 = ADD32(ctx->r18, 0X3B48);
    // 0x80071410: addiu       $s0, $s0, 0x3B48
    ctx->r16 = ADD32(ctx->r16, 0X3B48);
L_80071414:
    // 0x80071414: lbu         $t6, 0x4($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X4);
    // 0x80071418: nop

    // 0x8007141C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80071420: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80071424: bne         $t8, $zero, L_80071474
    if (ctx->r24 != 0) {
        // 0x80071428: sb          $t7, 0x4($s0)
        MEM_B(0X4, ctx->r16) = ctx->r15;
            goto L_80071474;
    }
    // 0x80071428: sb          $t7, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r15;
    // 0x8007142C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80071430: jal         0x800714B8
    // 0x80071434: nop

    mempool_free_addr(rdram, ctx);
        goto after_1;
    // 0x80071434: nop

    after_1:
    // 0x80071438: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8007143C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80071440: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80071444: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x80071448: lw          $t0, -0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, -0X8);
    // 0x8007144C: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x80071450: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80071454: lbu         $t1, -0x4($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X4);
    // 0x80071458: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x8007145C: addiu       $t4, $t4, 0x3B48
    ctx->r12 = ADD32(ctx->r12, 0X3B48);
    // 0x80071460: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80071464: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80071468: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x8007146C: b           L_80071488
    // 0x80071470: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
        goto L_80071488;
    // 0x80071470: sb          $t1, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r9;
L_80071474:
    // 0x80071474: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071478: addiu       $t6, $t6, 0x3B48
    ctx->r14 = ADD32(ctx->r14, 0X3B48);
    // 0x8007147C: sll         $t5, $v1, 3
    ctx->r13 = S32(ctx->r3 << 3);
    // 0x80071480: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x80071484: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_80071488:
    // 0x80071488: sltu        $at, $s0, $a0
    ctx->r1 = ctx->r16 < ctx->r4 ? 1 : 0;
    // 0x8007148C: bne         $at, $zero, L_80071414
    if (ctx->r1 != 0) {
        // 0x80071490: nop
    
            goto L_80071414;
    }
    // 0x80071490: nop

L_80071494:
    // 0x80071494: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80071498: jal         0x8006F77C
    // 0x8007149C: nop

    interrupts_enable(rdram, ctx);
        goto after_2;
    // 0x8007149C: nop

    after_2:
    // 0x800714A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800714A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800714A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800714AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800714B0: jr          $ra
    // 0x800714B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800714B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void obj_init_bridge_whaleramp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CA2C: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CA30: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x8003CA34: sb          $t6, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r14;
    // 0x8003CA38: lbu         $t8, 0x9($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X9);
    // 0x8003CA3C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8003CA40: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003CA44: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x8003CA48: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x8003CA4C: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA50: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x8003CA54: sh          $t0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r8;
    // 0x8003CA58: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA5C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8003CA60: sb          $t2, 0x11($t3)
    MEM_B(0X11, ctx->r11) = ctx->r10;
    // 0x8003CA64: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA68: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x8003CA6C: sb          $t4, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r12;
    // 0x8003CA70: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CA74: nop

    // 0x8003CA78: sb          $zero, 0x12($t6)
    MEM_B(0X12, ctx->r14) = 0;
    // 0x8003CA7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8003CA80: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x8003CA84: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x8003CA88: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x8003CA8C: nop

    // 0x8003CA90: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8003CA94: bne         $at, $zero, L_8003CAA0
    if (ctx->r1 != 0) {
        // 0x8003CA98: nop
    
            goto L_8003CAA0;
    }
    // 0x8003CA98: nop

    // 0x8003CA9C: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_8003CAA0:
    // 0x8003CAA0: jr          $ra
    // 0x8003CAA4: nop

    return;
    // 0x8003CAA4: nop

;}
RECOMP_FUNC void osCreateScheduler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800797A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800797A4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800797A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800797AC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800797B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800797B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800797B8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800797BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800797C0: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800797C4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800797C8: sw          $zero, 0x274($a0)
    MEM_W(0X274, ctx->r4) = 0;
    // 0x800797CC: sw          $zero, 0x278($a0)
    MEM_W(0X278, ctx->r4) = 0;
    // 0x800797D0: sw          $zero, 0x260($a0)
    MEM_W(0X260, ctx->r4) = 0;
    // 0x800797D4: sw          $zero, 0x264($a0)
    MEM_W(0X264, ctx->r4) = 0;
    // 0x800797D8: sw          $zero, 0x268($a0)
    MEM_W(0X268, ctx->r4) = 0;
    // 0x800797DC: sw          $zero, 0x26C($a0)
    MEM_W(0X26C, ctx->r4) = 0;
    // 0x800797E0: sw          $zero, 0x270($a0)
    MEM_W(0X270, ctx->r4) = 0;
    // 0x800797E4: sw          $zero, 0x280($a0)
    MEM_W(0X280, ctx->r4) = 0;
    // 0x800797E8: sw          $zero, 0x27C($a0)
    MEM_W(0X27C, ctx->r4) = 0;
    // 0x800797EC: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800797F0: sh          $t7, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r15;
    // 0x800797F4: andi        $s1, $a3, 0xFF
    ctx->r17 = ctx->r7 & 0XFF;
    // 0x800797F8: jal         0x800D1EF0
    // 0x800797FC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    osCreateViManager_recomp(rdram, ctx);
        goto after_0;
    // 0x800797FC: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    after_0:
    // 0x80079800: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x80079804: addu        $t8, $t8, $s1
    ctx->r24 = ADD32(ctx->r24, ctx->r17);
    // 0x80079808: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007980C: addiu       $t9, $t9, 0x3E90
    ctx->r25 = ADD32(ctx->r25, 0X3E90);
    // 0x80079810: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80079814: jal         0x800D2200
    // 0x80079818: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    osViSetMode_recomp(rdram, ctx);
        goto after_1;
    // 0x80079818: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    after_1:
    // 0x8007981C: jal         0x800D2270
    // 0x80079820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osViBlack_recomp(rdram, ctx);
        goto after_2;
    // 0x80079820: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80079824: addiu       $s1, $s0, 0x40
    ctx->r17 = ADD32(ctx->r16, 0X40);
    // 0x80079828: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8007982C: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x80079830: jal         0x800C8D80
    // 0x80079834: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_3;
    // 0x80079834: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_3:
    // 0x80079838: addiu       $a0, $s0, 0x78
    ctx->r4 = ADD32(ctx->r16, 0X78);
    // 0x8007983C: addiu       $a1, $s0, 0x90
    ctx->r5 = ADD32(ctx->r16, 0X90);
    // 0x80079840: jal         0x800C8D80
    // 0x80079844: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80079844: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_4:
    // 0x80079848: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8007984C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079850: jal         0x800CD110
    // 0x80079854: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_5;
    // 0x80079854: addiu       $a2, $zero, 0x29B
    ctx->r6 = ADD32(0, 0X29B);
    after_5:
    // 0x80079858: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007985C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079860: jal         0x800CD110
    // 0x80079864: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_6;
    // 0x80079864: addiu       $a2, $zero, 0x29C
    ctx->r6 = ADD32(0, 0X29C);
    after_6:
    // 0x80079868: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    // 0x8007986C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80079870: jal         0x800CD110
    // 0x80079874: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x80079874: addiu       $a2, $zero, 0x29D
    ctx->r6 = ADD32(0, 0X29D);
    after_7:
    // 0x80079878: lbu         $a2, 0x3B($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X3B);
    // 0x8007987C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80079880: jal         0x800D22E0
    // 0x80079884: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    osViSetEvent_recomp(rdram, ctx);
        goto after_8;
    // 0x80079884: addiu       $a1, $zero, 0x29A
    ctx->r5 = ADD32(0, 0X29A);
    after_8:
    // 0x80079888: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8007988C: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80079890: addiu       $s1, $s0, 0xB0
    ctx->r17 = ADD32(ctx->r16, 0XB0);
    // 0x80079894: lui         $a2, 0x8008
    ctx->r6 = S32(0X8008 << 16);
    // 0x80079898: addiu       $a2, $a2, -0x6604
    ctx->r6 = ADD32(ctx->r6, -0X6604);
    // 0x8007989C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800798A0: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800798A4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800798A8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800798AC: jal         0x800C8DB0
    // 0x800798B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    osCreateThread_recomp(rdram, ctx);
        goto after_9;
    // 0x800798B0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_9:
    // 0x800798B4: jal         0x800C8F00
    // 0x800798B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    osStartThread_recomp(rdram, ctx);
        goto after_10;
    // 0x800798B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800798BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800798C0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800798C4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800798C8: jr          $ra
    // 0x800798CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800798CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE724: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800CE728: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x800CE72C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x800CE730: beql        $t6, $v1, L_800CE75C
    if (ctx->r14 == ctx->r3) {
        // 0x800CE734: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800CE75C;
    }
    goto skip_0;
    // 0x800CE734: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_800CE738:
    // 0x800CE738: bnel        $v1, $zero, L_800CE74C
    if (ctx->r3 != 0) {
        // 0x800CE73C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_800CE74C;
    }
    goto skip_1;
    // 0x800CE73C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x800CE740: jr          $ra
    // 0x800CE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CE744: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CE748: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_800CE74C:
    // 0x800CE74C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800CE750: bne         $v0, $v1, L_800CE738
    if (ctx->r2 != ctx->r3) {
        // 0x800CE754: nop
    
            goto L_800CE738;
    }
    // 0x800CE754: nop

    // 0x800CE758: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800CE75C:
    // 0x800CE75C: jr          $ra
    // 0x800CE760: nop

    return;
    // 0x800CE760: nop

;}
RECOMP_FUNC void func_80026C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80026C54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80026C58: addiu       $t0, $t0, -0x25E2
    ctx->r8 = ADD32(ctx->r8, -0X25E2);
    // 0x80026C5C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80026C60: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80026C64: lh          $t8, -0x25C6($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X25C6);
    // 0x80026C68: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026C6C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x80026C70: sll         $s0, $a1, 16
    ctx->r16 = S32(ctx->r5 << 16);
    // 0x80026C74: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x80026C78: sra         $t6, $a3, 16
    ctx->r14 = S32(SIGNED(ctx->r7) >> 16);
    // 0x80026C7C: sra         $t7, $s0, 16
    ctx->r15 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80026C80: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80026C84: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x80026C88: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x80026C8C: sw          $a0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r4;
    // 0x80026C90: sw          $a1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r5;
    // 0x80026C94: beq         $at, $zero, L_80026E88
    if (ctx->r1 == 0) {
        // 0x80026C98: sw          $a2, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r6;
            goto L_80026E88;
    }
    // 0x80026C98: sw          $a2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r6;
    // 0x80026C9C: blez        $v0, L_80026CFC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80026CA0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80026CFC;
    }
    // 0x80026CA0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80026CA4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026CA8: addiu       $t1, $t1, -0x2608
    ctx->r9 = ADD32(ctx->r9, -0X2608);
    // 0x80026CAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026CB0: nop

    // 0x80026CB4: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x80026CB8: nop

    // 0x80026CBC: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80026CC0: beq         $at, $zero, L_80026CFC
    if (ctx->r1 == 0) {
        // 0x80026CC4: nop
    
            goto L_80026CFC;
    }
    // 0x80026CC4: nop

L_80026CC8:
    // 0x80026CC8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026CCC: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026CD0: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026CD4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026CD8: beq         $at, $zero, L_80026CFC
    if (ctx->r1 == 0) {
        // 0x80026CDC: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026CFC;
    }
    // 0x80026CDC: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026CE0: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026CE4: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80026CE8: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x80026CEC: nop

    // 0x80026CF0: slt         $at, $t6, $a3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80026CF4: bne         $at, $zero, L_80026CC8
    if (ctx->r1 != 0) {
        // 0x80026CF8: nop
    
            goto L_80026CC8;
    }
    // 0x80026CF8: nop

L_80026CFC:
    // 0x80026CFC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80026D00: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026D04: beq         $at, $zero, L_80026D80
    if (ctx->r1 == 0) {
        // 0x80026D08: addiu       $t1, $t1, -0x2608
        ctx->r9 = ADD32(ctx->r9, -0X2608);
            goto L_80026D80;
    }
    // 0x80026D08: addiu       $t1, $t1, -0x2608
    ctx->r9 = ADD32(ctx->r9, -0X2608);
    // 0x80026D0C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80026D10: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80026D14: addu        $a1, $a0, $t7
    ctx->r5 = ADD32(ctx->r4, ctx->r15);
    // 0x80026D18: lh          $t8, 0x0($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X0);
    // 0x80026D1C: nop

    // 0x80026D20: bne         $a3, $t8, L_80026D80
    if (ctx->r7 != ctx->r24) {
        // 0x80026D24: nop
    
            goto L_80026D80;
    }
    // 0x80026D24: nop

    // 0x80026D28: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x80026D2C: nop

    // 0x80026D30: slt         $at, $t9, $s0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026D34: beq         $at, $zero, L_80026D84
    if (ctx->r1 == 0) {
        // 0x80026D38: sll         $a1, $v0, 16
        ctx->r5 = S32(ctx->r2 << 16);
            goto L_80026D84;
    }
    // 0x80026D38: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026D3C:
    // 0x80026D3C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80026D40: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80026D44: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80026D48: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80026D4C: beq         $at, $zero, L_80026D80
    if (ctx->r1 == 0) {
        // 0x80026D50: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80026D80;
    }
    // 0x80026D50: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80026D54: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80026D58: addu        $a1, $a0, $t4
    ctx->r5 = ADD32(ctx->r4, ctx->r12);
    // 0x80026D5C: lh          $t5, 0x0($a1)
    ctx->r13 = MEM_H(ctx->r5, 0X0);
    // 0x80026D60: nop

    // 0x80026D64: bne         $a3, $t5, L_80026D80
    if (ctx->r7 != ctx->r13) {
        // 0x80026D68: nop
    
            goto L_80026D80;
    }
    // 0x80026D68: nop

    // 0x80026D6C: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x80026D70: nop

    // 0x80026D74: slt         $at, $t6, $s0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80026D78: bne         $at, $zero, L_80026D3C
    if (ctx->r1 != 0) {
        // 0x80026D7C: nop
    
            goto L_80026D3C;
    }
    // 0x80026D7C: nop

L_80026D80:
    // 0x80026D80: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
L_80026D84:
    // 0x80026D84: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80026D88: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80026D8C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80026D90: beq         $at, $zero, L_80026DF8
    if (ctx->r1 == 0) {
        // 0x80026D94: sll         $a0, $v1, 3
        ctx->r4 = S32(ctx->r3 << 3);
            goto L_80026DF8;
    }
    // 0x80026D94: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
L_80026D98:
    // 0x80026D98: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x80026D9C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80026DA0: addu        $a2, $t8, $v0
    ctx->r6 = ADD32(ctx->r24, ctx->r2);
    // 0x80026DA4: lh          $t9, -0x8($a2)
    ctx->r25 = MEM_H(ctx->r6, -0X8);
    // 0x80026DA8: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80026DAC: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x80026DB0: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026DB4: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x80026DB8: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x80026DBC: lh          $t3, -0x6($a2)
    ctx->r11 = MEM_H(ctx->r6, -0X6);
    // 0x80026DC0: sra         $a1, $t8, 16
    ctx->r5 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80026DC4: sh          $t3, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r11;
    // 0x80026DC8: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026DCC: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80026DD0: addu        $a2, $t4, $v0
    ctx->r6 = ADD32(ctx->r12, ctx->r2);
    // 0x80026DD4: lb          $t5, -0x1($a2)
    ctx->r13 = MEM_B(ctx->r6, -0X1);
    // 0x80026DD8: nop

    // 0x80026DDC: sb          $t5, 0x7($a2)
    MEM_B(0X7, ctx->r6) = ctx->r13;
    // 0x80026DE0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026DE4: nop

    // 0x80026DE8: addu        $a2, $t6, $v0
    ctx->r6 = ADD32(ctx->r14, ctx->r2);
    // 0x80026DEC: lb          $t7, -0x2($a2)
    ctx->r15 = MEM_B(ctx->r6, -0X2);
    // 0x80026DF0: bne         $at, $zero, L_80026D98
    if (ctx->r1 != 0) {
        // 0x80026DF4: sb          $t7, 0x6($a2)
        MEM_B(0X6, ctx->r6) = ctx->r15;
            goto L_80026D98;
    }
    // 0x80026DF4: sb          $t7, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r15;
L_80026DF8:
    // 0x80026DF8: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80026DFC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80026E00: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x80026E04: sh          $a3, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r7;
    // 0x80026E08: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026E0C: addiu       $v1, $v1, -0x25E4
    ctx->r3 = ADD32(ctx->r3, -0X25E4);
    // 0x80026E10: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026E14: sh          $s0, 0x2($t5)
    MEM_H(0X2, ctx->r13) = ctx->r16;
    // 0x80026E18: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80026E1C: nop

    // 0x80026E20: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80026E24: sh          $zero, 0x4($t7)
    MEM_H(0X4, ctx->r15) = 0;
    // 0x80026E28: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80026E2C: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x80026E30: addu        $t2, $t9, $a0
    ctx->r10 = ADD32(ctx->r25, ctx->r4);
    // 0x80026E34: sb          $t8, 0x7($t2)
    MEM_B(0X7, ctx->r10) = ctx->r24;
    // 0x80026E38: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x80026E3C: lw          $t3, 0x10($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10);
    // 0x80026E40: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x80026E44: sb          $t3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r11;
    // 0x80026E48: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80026E4C: lw          $t7, -0x2604($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2604);
    // 0x80026E50: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x80026E54: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80026E58: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80026E5C: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80026E60: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x80026E64: nop

    // 0x80026E68: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80026E6C: beq         $t2, $zero, L_80026E84
    if (ctx->r10 == 0) {
        // 0x80026E70: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80026E84;
    }
    // 0x80026E70: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80026E74: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x80026E78: nop

    // 0x80026E7C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80026E80: sh          $t3, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r11;
L_80026E84:
    // 0x80026E84: sh          $t5, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r13;
L_80026E88:
    // 0x80026E88: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x80026E8C: jr          $ra
    // 0x80026E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x80026E90: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void set_stereo_pan_mode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80065E14: jr          $ra
    // 0x80065E18: sh          $a0, -0x2A40($at)
    MEM_H(-0X2A40, ctx->r1) = ctx->r4;
    return;
    // 0x80065E18: sh          $a0, -0x2A40($at)
    MEM_H(-0X2A40, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void get_particle_behaviour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4AD8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B4ADC: lw          $v1, 0x3284($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3284);
    // 0x800B4AE0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800B4AE4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800B4AE8: beq         $at, $zero, L_800B4B08
    if (ctx->r1 == 0) {
        // 0x800B4AEC: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800B4B08;
    }
    // 0x800B4AEC: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800B4AF0: lw          $t6, 0x328C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X328C);
    // 0x800B4AF4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800B4AF8: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800B4AFC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800B4B00: jr          $ra
    // 0x800B4B04: nop

    return;
    // 0x800B4B04: nop

L_800B4B08:
    // 0x800B4B08: lw          $t9, 0x328C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X328C);
    // 0x800B4B0C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800B4B10: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800B4B14: lw          $v0, -0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X4);
    // 0x800B4B18: nop

    // 0x800B4B1C: jr          $ra
    // 0x800B4B20: nop

    return;
    // 0x800B4B20: nop

;}
RECOMP_FUNC void func_8000E138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E138: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E13C: lb          $v0, -0x4D60($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X4D60);
    // 0x8000E140: jr          $ra
    // 0x8000E144: nop

    return;
    // 0x8000E144: nop

;}
RECOMP_FUNC void strncasecmp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4DA8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4DAC: nop

    // 0x800B4DB0: bne         $v0, $zero, L_800B4DC8
    if (ctx->r2 != 0) {
        // 0x800B4DB4: nop
    
            goto L_800B4DC8;
    }
    // 0x800B4DB4: nop

    // 0x800B4DB8: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4DBC: nop

    // 0x800B4DC0: beq         $t6, $zero, L_800B4E60
    if (ctx->r14 == 0) {
        // 0x800B4DC4: nop
    
            goto L_800B4E60;
    }
    // 0x800B4DC4: nop

L_800B4DC8:
    // 0x800B4DC8: beq         $a2, $zero, L_800B4E60
    if (ctx->r6 == 0) {
        // 0x800B4DCC: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4E60;
    }
    // 0x800B4DCC: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4DD0:
    // 0x800B4DD0: slti        $at, $a3, 0x61
    ctx->r1 = SIGNED(ctx->r7) < 0X61 ? 1 : 0;
    // 0x800B4DD4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4DD8: bne         $at, $zero, L_800B4DF0
    if (ctx->r1 != 0) {
        // 0x800B4DDC: or          $t0, $a3, $zero
        ctx->r8 = ctx->r7 | 0;
            goto L_800B4DF0;
    }
    // 0x800B4DDC: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x800B4DE0: slti        $at, $a3, 0x7B
    ctx->r1 = SIGNED(ctx->r7) < 0X7B ? 1 : 0;
    // 0x800B4DE4: beq         $at, $zero, L_800B4DF0
    if (ctx->r1 == 0) {
        // 0x800B4DE8: addiu       $a3, $a3, -0x20
        ctx->r7 = ADD32(ctx->r7, -0X20);
            goto L_800B4DF0;
    }
    // 0x800B4DE8: addiu       $a3, $a3, -0x20
    ctx->r7 = ADD32(ctx->r7, -0X20);
    // 0x800B4DEC: andi        $t0, $a3, 0xFF
    ctx->r8 = ctx->r7 & 0XFF;
L_800B4DF0:
    // 0x800B4DF0: andi        $v0, $v1, 0xFF
    ctx->r2 = ctx->r3 & 0XFF;
    // 0x800B4DF4: slti        $at, $v0, 0x61
    ctx->r1 = SIGNED(ctx->r2) < 0X61 ? 1 : 0;
    // 0x800B4DF8: bne         $at, $zero, L_800B4E10
    if (ctx->r1 != 0) {
        // 0x800B4DFC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B4E10;
    }
    // 0x800B4DFC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B4E00: slti        $at, $v0, 0x7B
    ctx->r1 = SIGNED(ctx->r2) < 0X7B ? 1 : 0;
    // 0x800B4E04: beq         $at, $zero, L_800B4E10
    if (ctx->r1 == 0) {
        // 0x800B4E08: addiu       $v0, $v0, -0x20
        ctx->r2 = ADD32(ctx->r2, -0X20);
            goto L_800B4E10;
    }
    // 0x800B4E08: addiu       $v0, $v0, -0x20
    ctx->r2 = ADD32(ctx->r2, -0X20);
    // 0x800B4E0C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4E10:
    // 0x800B4E10: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800B4E14: beq         $at, $zero, L_800B4E24
    if (ctx->r1 == 0) {
        // 0x800B4E18: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800B4E24;
    }
    // 0x800B4E18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800B4E1C: jr          $ra
    // 0x800B4E20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x800B4E20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800B4E24:
    // 0x800B4E24: slt         $at, $a3, $t0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800B4E28: beq         $at, $zero, L_800B4E38
    if (ctx->r1 == 0) {
        // 0x800B4E2C: nop
    
            goto L_800B4E38;
    }
    // 0x800B4E2C: nop

    // 0x800B4E30: jr          $ra
    // 0x800B4E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800B4E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800B4E38:
    // 0x800B4E38: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800B4E3C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B4E40: bne         $v0, $zero, L_800B4E58
    if (ctx->r2 != 0) {
        // 0x800B4E44: addiu       $a2, $a2, -0x1
        ctx->r6 = ADD32(ctx->r6, -0X1);
            goto L_800B4E58;
    }
    // 0x800B4E44: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800B4E48: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800B4E4C: nop

    // 0x800B4E50: beq         $t9, $zero, L_800B4E60
    if (ctx->r25 == 0) {
        // 0x800B4E54: nop
    
            goto L_800B4E60;
    }
    // 0x800B4E54: nop

L_800B4E58:
    // 0x800B4E58: bne         $a2, $zero, L_800B4DD0
    if (ctx->r6 != 0) {
        // 0x800B4E5C: andi        $a3, $v0, 0xFF
        ctx->r7 = ctx->r2 & 0XFF;
            goto L_800B4DD0;
    }
    // 0x800B4E5C: andi        $a3, $v0, 0xFF
    ctx->r7 = ctx->r2 & 0XFF;
L_800B4E60:
    // 0x800B4E60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B4E64: jr          $ra
    // 0x800B4E68: nop

    return;
    // 0x800B4E68: nop

;}
RECOMP_FUNC void thread1_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065FD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065FE0: jal         0x800B74B0
    // 0x80065FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    thread0_create(rdram, ctx);
        goto after_0;
    // 0x80065FE4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80065FE8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065FEC: addiu       $t6, $t6, -0x328
    ctx->r14 = ADD32(ctx->r14, -0X328);
    // 0x80065FF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065FF4: lui         $a2, 0x8007
    ctx->r6 = S32(0X8007 << 16);
    // 0x80065FF8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80065FFC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80066000: addiu       $a2, $a2, -0x3A90
    ctx->r6 = ADD32(ctx->r6, -0X3A90);
    // 0x80066004: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    // 0x80066008: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8006600C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80066010: jal         0x800C8DB0
    // 0x80066014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80066014: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80066018: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006601C: addiu       $v0, $v0, -0x2328
    ctx->r2 = ADD32(ctx->r2, -0X2328);
    // 0x80066020: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80066024: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80066028: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8006602C: addiu       $t1, $zero, 0x0
    ctx->r9 = ADD32(0, 0X0);
    // 0x80066030: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80066034: sw          $t9, 0x2004($v0)
    MEM_W(0X2004, ctx->r2) = ctx->r25;
    // 0x80066038: sw          $t8, 0x2000($v0)
    MEM_W(0X2000, ctx->r2) = ctx->r24;
    // 0x8006603C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80066040: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80066044: jal         0x800C8F00
    // 0x80066048: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80066048: addiu       $a0, $a0, -0x170
    ctx->r4 = ADD32(ctx->r4, -0X170);
    after_2:
    // 0x8006604C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80066050: jal         0x800CCDA0
    // 0x80066054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    osSetThreadPri_recomp(rdram, ctx);
        goto after_3;
    // 0x80066054: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
L_80066058:
    // 0x80066058: b           L_80066058
    pause_self(rdram);
    // 0x8006605C: nop

    // 0x80066060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066064: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80066068: jr          $ra
    // 0x8006606C: nop

    return;
    // 0x8006606C: nop

;}
RECOMP_FUNC void debug_text_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B6744: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800B6748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B674C: addiu       $t6, $t6, -0x7D68
    ctx->r14 = ADD32(ctx->r14, -0X7D68);
    // 0x800B6750: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B6754: jal         0x800B7440
    // 0x800B6758: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    debug_text_origin(rdram, ctx);
        goto after_0;
    // 0x800B6758: sw          $t6, -0x7468($at)
    MEM_W(-0X7468, ctx->r1) = ctx->r14;
    after_0:
    // 0x800B675C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B6764: jr          $ra
    // 0x800B6768: nop

    return;
    // 0x800B6768: nop

;}
RECOMP_FUNC void obj_init_torch_mist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B30: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80034B34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034B38: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80034B3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034B40: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034B44: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80034B48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80034B4C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80034B50: nop

    // 0x80034B54: bc1f        L_80034B64
    if (!c1cs) {
        // 0x80034B58: nop
    
            goto L_80034B64;
    }
    // 0x80034B58: nop

    // 0x80034B5C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80034B60: nop

L_80034B64:
    // 0x80034B64: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80034B68: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80034B6C: nop

    // 0x80034B70: lwc1        $f8, 0xC($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0XC);
    // 0x80034B74: nop

    // 0x80034B78: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80034B7C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80034B80: lbu         $t9, 0x8($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X8);
    // 0x80034B84: jr          $ra
    // 0x80034B88: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
    return;
    // 0x80034B88: sw          $t9, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r25;
;}
