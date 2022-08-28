#include <ftkoopa.h>

#include <melee/it/itkind.h>

extern void func_800BC7E0(HSD_GObj*, HSD_GObj*);
extern void func_800BC8D4(HSD_GObj*, HSD_GObj*);
extern void func_800DE7C0(HSD_GObj*, s32, s32);
extern void func_800DE2A8(HSD_GObj*, HSD_GObj*);

extern f32 lbl_804D9AD8;
extern f32 lbl_804D9ADC;

void ftKoopa_OnDeath(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    ftKoopaAttributes* koopaAttr = fp->x2D4_specialAttributes;
    ftKoopaVars* ftVars;
    f32 unk = 0.0;
    f32 unk1 = 0.0;

    func_80074A4C(fighterObj, 0, 0);

    ftVars = (ftKoopaVars*) &fp->sa.koopa.x222C;

    fp->dmg.x18B0 = koopaAttr->x0;
    ftVars->x0 = koopaAttr->x10;
    ftVars->x4 = koopaAttr->x18;
}

void func_80132A64(HSD_GObj* fighterObj)
{
    func_80134D78(fighterObj);
    return;
}

void ftKoopa_OnLoadForGKoopa(Fighter* fp)
{
    PUSH_ATTRS(fp, ftKoopaAttributes);
}

void ftKoopa_OnLoad(HSD_GObj* fighterObj)
{
    ftData* ftDataInfo;
    void** items;
    Fighter* fp;

    fp = (Fighter*) fighterObj->user_data;
    ftDataInfo = fp->x10C_ftData;
    items = ftDataInfo->x48_items;

    PUSH_ATTRS(fp, ftKoopaAttributes);

    func_8026B3F8(items[0], It_Kind_Koopa_Flame);

    fp->x2226_flag.bits.b1 = 1;
}

void func_80132B38(void)
{
    return;
}

void ftKoopa_OnItemPickup(HSD_GObj* fighterObj, BOOL bool)
{
    Fighter_OnItemPickup(fighterObj, bool, 1, 1);
}

void ftKoopa_OnItemInvisible(HSD_GObj* fighterObj)
{
    Fighter_OnItemInvisible(fighterObj, 1);
}

void ftKoopa_OnItemVisible(HSD_GObj* fighterObj)
{
    Fighter_OnItemVisible(fighterObj, 1);
}

void ftKoopa_OnItemDrop(HSD_GObj* fighterObj, BOOL bool1)
{
    Fighter_OnItemDrop(fighterObj, bool1, 1, 1);
}

void ftKoopa_LoadSpecialAttrs(HSD_GObj* fighterObj)
{
    COPY_ATTRS(fighterObj, ftKoopaAttributes);
}

void ftKoopa_OnKnockbackEnter(HSD_GObj* fighterObj)
{
    Fighter_OnKnockbackEnter(fighterObj, 1);
}

void ftKoopa_OnKnockbackExit(HSD_GObj* fighterObj)
{
    Fighter_OnKnockbackExit(fighterObj, 1);
}

f32 func_80132DC0(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x4C;
}

f32 func_80132DD0(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x48;
}

f32 func_80132DE0(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x44;
}

f32 func_80132DF0(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x40;
}

f32 func_80132E00(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x3C;
}

f32 func_80132E10(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x34;
}

f32 func_80132E20(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;
    return ((ftKoopaAttributes*) fp->x2D4_specialAttributes)->x38;
}

void func_80132E30(HSD_GObj* fighterObj)
{
    Fighter* fp;
    HSD_GObj* temp;
    BOOL flag_set;

    fp = fighterObj->user_data;
    if (fp->x2210_ThrowFlags.b4 != 0) {
        fp->x2210_ThrowFlags.b4 = 0;
        flag_set = TRUE;
    } else {
        flag_set = FALSE;
    }
    if (flag_set != FALSE) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
        fp->x234C_stateVar4 = 1;
    }
    if ((u32) fp->x2200_ftcmd_var0 != 0) {
        if (fp->x1A58_interactedFighter != 0) {
            temp = fp->x1A58_interactedFighter;
            func_8007E2F4(fp, 0);
            func_800DE2A8(fighterObj, temp);
            func_800DE7C0(temp, 0, 0);
            fp->x2200_ftcmd_var0 = 0;
        }
    }
}

void ftKoopa_SpecialS_StartAction(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;

    f64 unk = 0.0;

    fp->x2210_ThrowFlags.flags = 0;
    fp->x2200_ftcmd_var0 = 0;
    fp->x2344_stateVar2 = 0;
    fp->x234C_stateVar4 = 0;

    Fighter_ActionStateChange_800693AC(fighterObj, 0x15B, 0, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);

    func_8006EBA4(fighterObj);

    fp = fighterObj->user_data;

    func_8007E2D0(fp, 8, func_8013302C, NULL, func_800BC7E0);

    fp->x2340_stateVar1 = 0;
    fp->x2348_stateVar3 = 0;

    return;
}

void ftKoopa_SpecialAirS_StartAction(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;

    f64 unk = 0.0;

    fp->x2210_ThrowFlags.flags = 0;
    fp->x2200_ftcmd_var0 = 0;
    fp->x2344_stateVar2 = 0;
    fp->x234C_stateVar4 = 0;

    Fighter_ActionStateChange_800693AC(fighterObj, 0x161, 0, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);

    func_8006EBA4(fighterObj);

    fp = fighterObj->user_data;

    func_8007E2D0(fp, 8, func_801330E4, NULL, func_800BC8D4);

    fp->x2340_stateVar1 = 0;
    fp->x2348_stateVar3 = 0;

    return;
}

void func_8013302C(HSD_GObj* fighterObj)
{
    Fighter* fp = fighterObj->user_data;

    if ((s32) fp->x2344_stateVar2 != 0) {
        Fighter_ActionStateChange_800693AC(fighterObj, 349, 0x80, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
    } else {
        Fighter_ActionStateChange_800693AC(fighterObj, 348, 0x0, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
    }
    fp->x2222_flag.bits.b2 = 1;
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
    fp->x2340_stateVar1 = 0;
    fp->x2200_ftcmd_var0 = 0;
    return;
}

void func_801330E4(HSD_GObj* fighterObj)
{
    Fighter* fp;

    fp = fighterObj->user_data;
    if ((s32) fp->x2344_stateVar2 != 0) {
        Fighter_ActionStateChange_800693AC(fighterObj, 0x163, 0x80, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
    } else {
        Fighter_ActionStateChange_800693AC(fighterObj, 0x162, 0, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
    }
    fp->x2222_flag.bits.b2 = 1;
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
    fp->x2340_stateVar1 = 0;
    fp->x2200_ftcmd_var0 = 0;
}

void func_8013319C(HSD_GObj* fighterObj)
{
    Fighter* fp;

    double unk = 0.0;

    fp = fighterObj->user_data;
    func_8007D5D4(fp);
    Fighter_ActionStateChange_800693AC(fighterObj, 0x161, 0x0C4C5088, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
    fp = fighterObj->user_data;
    func_8007E2D0(fp, 8, func_801330E4, NULL, func_800BC8D4);
    fp->x2340_stateVar1 = 0;
    fp->x2348_stateVar3 = 0;
}

void func_8013322C(HSD_GObj* fighterObj)
{
    Fighter* ft1;
    Fighter* ft2;

    double unk = 0.0;

    ft2 = fighterObj->user_data;
    func_8007D7FC(ft2);
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15B, 0x0C4C5088, 0, ft2->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
    ft1 = fighterObj->user_data;
    func_8007E2D0(ft1, 8, func_8013302C, NULL, func_800BC7E0);
    ft1->x2340_stateVar1 = 0;
    ft1->x2348_stateVar3 = 0;
    ft2->x2340_stateVar1 = 0;
    ft2->x2200_ftcmd_var0 = 0;
}

void func_801332C4(HSD_GObj* fighterObj)
{
    HSD_GObj* temp_r31;
    Fighter* fp;

    fp = fighterObj->user_data;
    temp_r31 = fp->x1A58_interactedFighter;
    func_8007D5D4(fp);
    if (temp_r31 != 0) {
        func_800DC920(fighterObj, temp_r31);
        func_800CC730(temp_r31);
    }
    func_800CC730(fighterObj);
}

void func_80133324(HSD_GObj* fighterObj)
{
    Fighter* fp;

    fp = fighterObj->user_data;
    func_8007D7FC(fp);
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15C, 0x0C4C5088, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
}

void func_80133398(HSD_GObj* fighterObj)
{
    HSD_GObj* unk_fighterObj;
    Fighter* fp;

    fp = fighterObj->user_data;
    unk_fighterObj = fp->x1A58_interactedFighter;
    func_8007D5D4(fp);
    if (unk_fighterObj != 0) {
        func_800DC920(fighterObj, unk_fighterObj);
        func_800CC730(unk_fighterObj);
    }
    func_800CC730(fighterObj);
}

void func_801333F8(HSD_GObj* fighterObj)
{
    Fighter* fp;

    fp = fighterObj->user_data;
    func_8007D7FC(fp);
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15E, 0x044C1080, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
    func_8006F0FC(fighterObj, lbl_804D9AD8);
    fp->x2340_stateVar1 = 0;
    fp->x2200_ftcmd_var0 = 0;
}

void func_80133484(HSD_GObj* fighterObj)
{
    HSD_GObj* unk_fighterObj;
    Fighter* fp;

    fp = fighterObj->user_data;
    unk_fighterObj = fp->x1A58_interactedFighter;
    func_8007D5D4(fp);
    if (unk_fighterObj != 0) {
        func_800DC920(fighterObj, unk_fighterObj);
        func_800CC730(unk_fighterObj);
    }
    func_800CC730(fighterObj);
}

void func_801334E4(HSD_GObj* fighterObj)
{
    Fighter* fp;

    u32 x = 0;

    fp = fighterObj->user_data;

    func_8007D7FC(fp);

    if ((s32) fp->x234C_stateVar4 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
    }
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15F, 0x0C4C5088, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);

    if ((s32) fp->x234C_stateVar4 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
    }
    if (fp->x1A58_interactedFighter != 0) {
        func_800BCE64(fp->x1A58_interactedFighter, 0x119);
    }
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
}

void func_8013359C(HSD_GObj* fighterObj)
{
    Fighter* fp;

    fp = fighterObj->user_data;
    func_8007D7FC(fp);
    if ((s32) fp->x234C_stateVar4 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
    }
    Fighter_ActionStateChange_800693AC(fighterObj, 0x160, 0x0C4C5088, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
    if ((s32) fp->x234C_stateVar4 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
    }
    if (fp->x1A58_interactedFighter != 0U) {
        func_800BCE64(fp->x1A58_interactedFighter, 0x11A);
    }
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
}

void func_80133654(HSD_GObj* fighterObj)
{
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_8008A2BC(fighterObj);
    }
}

void func_80133690(HSD_GObj* fighterObj)
{
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_800CC730(fighterObj);
    }
}

void func_801336CC(HSD_GObj* fighterObj)
{
    Fighter* ft_temp;
    Fighter* fp;

    ftKoopaAttributes* koopaAttr;

    double unk = 0.0;
    double unk1 = 0.0;

    fp = ft_temp = fighterObj->user_data;
    koopaAttr = (ftKoopaAttributes*) fp->x2D4_specialAttributes;
    if (((u32) fp->x2200_ftcmd_var0 != 0) && ((s32) fp->x2344_stateVar2 != 0)) {
        func_8007ABD0(&fp->x914[0], koopaAttr->x2C, fighterObj);
        fp->x2200_ftcmd_var0 = 0;
    }
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        if ((s32) fp->x2340_stateVar1 != 0) {
            fp->x2344_stateVar2 = 1;
            ft_temp = fighterObj->user_data;
            if ((s32) ft_temp->x2344_stateVar2 != 0) {
                Fighter_ActionStateChange_800693AC(fighterObj, 0x15D, 0x80, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
            } else {
                Fighter_ActionStateChange_800693AC(fighterObj, 0x15C, 0, 0, lbl_804D9AD8, lbl_804D9ADC, lbl_804D9AD8);
            }
            ft_temp->x2222_flag.bits.b2 = 1;
            func_8007E2F4(ft_temp, 0x1FF);
            func_8007E2FC(fighterObj);
            ft_temp->x2340_stateVar1 = 0;
            ft_temp->x2200_ftcmd_var0 = 0;
            func_800BC9C8(fp->x1A58_interactedFighter);
            return;
        }
        fp = fighterObj->user_data;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x15E, 0x80080, 0, fp->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
        func_8006F0FC(fighterObj, lbl_804D9AD8);
        fp->x2340_stateVar1 = 0;
        fp->x2200_ftcmd_var0 = 0;
        func_8007E2F4(fp, 0x1FF);
    }
}

inline void unk_koopa_inline1(HSD_GObj* fighterObj)
{
    Fighter* fp;
    f32 temp_f1;
    f32 temp_f1_2;
    fp = fighterObj->user_data;
    if ((fp->x2344_stateVar2_s32) != 0) {
        temp_f1 = lbl_804D9AD8;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x163, 0x80, (void*) 0, temp_f1, lbl_804D9ADC, temp_f1);
    } else {
        temp_f1_2 = lbl_804D9AD8;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x162, 0, (void*) 0, temp_f1_2, lbl_804D9ADC, temp_f1_2);
    }
    fp->x2222_flag.bits.b2 = 1;
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
    fp->x2340_stateVar1 = 0;
    fp->x2200_ftcmd_var0 = 0;
}

void lbl_8013383C(HSD_GObj* fighterObj)
{
    f32 temp_f1;
    f32 temp_f1_2;
    f32 filler[2];
    Fighter* fp_temp2;
    Fighter* fp;
    ftKoopaAttributes* koopaAttr;
    fp = fighterObj->user_data;
    koopaAttr = (ftKoopaAttributes*) fp->x2D4_specialAttributes;
    if (((fp->x2200_ftcmd_var0) != 0U) && ((fp->x2344_stateVar2_s32) != 0)) {
        func_8007ABD0(fp->x914, koopaAttr->x2C, fighterObj);
        fp->x2200_ftcmd_var0 = 0U;
    }
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        if (0 != (fp->x2340_stateVar1)) {
            fp->x2344_stateVar2_s32 = 1;
            unk_koopa_inline1(fighterObj);
            func_800BCAF4(fp->x1A58_interactedFighter);
            return;
        }
        fp_temp2 = fighterObj->user_data;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x164, 0x80080, 0, fp_temp2->x894_currentAnimFrame, lbl_804D9ADC, lbl_804D9AD8);
        func_8006F0FC(fighterObj, lbl_804D9AD8);
        fp_temp2->x2340_stateVar1 = 0;
        fp_temp2->x2200_ftcmd_var0 = 0;
        func_8007E2F4(fp_temp2, 0x1FF);
    }
}

void func_801339AC()
{
    return;
}

void func_801339B0()
{
    return;
}

void func_801339B4(HSD_GObj* fighterObj, f32 unused1, f32 unused2, f32 unused3)
{
    HSD_GObj* temp_fighterObj;
    HSD_GObj* interactedFighter;
    s32 var_r0;
    s32 var_r3;
    Fighter* fp = fighterObj->user_data;

    fp->x2200_ftcmd_var0 = fp->x2200_ftcmd_var0;

    if (fp->x2210_ThrowFlags.b4) {
        fp->x2210_ThrowFlags.b4 = 0;
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
        fp->x234C_stateVar4 = 1;
    }
    if (fp->x2200_ftcmd_var0 != 0) {
        interactedFighter = fp->x1A58_interactedFighter;
        temp_fighterObj = interactedFighter;
        if (interactedFighter != 0) {
            func_8007E2F4(fp, 0);
            func_800DE2A8(fighterObj, interactedFighter);
            func_800DE7C0(temp_fighterObj, 0, 0);
            fp->x2200_ftcmd_var0 = 0;
        }
    }
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_8008A2BC(fighterObj);
    }
}

void func_80133A90(HSD_GObj* fighterObj, f32 unused0, f32 unused1)
{
    func_80132E30(fighterObj);
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_8008A2BC(fighterObj);
    }
}

void lbl_80133AD4(HSD_GObj* fighterObj, f32 unused1, f32 unused2, f32 unused3)
{
    HSD_GObj* temp_fighterObj;
    HSD_GObj* interactedFighter;
    s32 var_r0;
    s32 var_r3;
    Fighter* fp = fighterObj->user_data;

    fp->x2200_ftcmd_var0 = fp->x2200_ftcmd_var0;

    if (fp->x2210_ThrowFlags.b4) {
        fp->x2210_ThrowFlags.b4 = 0;
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 != 0) {
        fp->x2C_facing_direction = -fp->x2C_facing_direction;
        fp->x234C_stateVar4 = 1;
    }
    if (fp->x2200_ftcmd_var0 != 0) {
        interactedFighter = fp->x1A58_interactedFighter;
        temp_fighterObj = interactedFighter;
        if (interactedFighter != 0) {
            func_8007E2F4(fp, 0);
            func_800DE2A8(fighterObj, interactedFighter);
            func_800DE7C0(temp_fighterObj, 0, 0);
            fp->x2200_ftcmd_var0 = 0;
        }
    }
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_800CC730(fighterObj);
    }
}

void lbl_80133BB0(HSD_GObj* fighterObj, f32 unused0, f32 unused1)
{
    func_80132E30(fighterObj);
    if (ftAnim_IsFramesRemaining(fighterObj) == 0) {
        func_800CC730(fighterObj);
    }
}

extern unk_t func_800BCDE0();
extern f64 lbl_804D9AD0;

#pragma push
asm unk_t lbl_80133BF4()
{ // clang-format off
    nofralloc
/* 80133BF4 001307D4  7C 08 02 A6 */	mflr r0
/* 80133BF8 001307D8  38 80 00 00 */	li r4, 0
/* 80133BFC 001307DC  90 01 00 04 */	stw r0, 4(r1)
/* 80133C00 001307E0  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80133C04 001307E4  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80133C08 001307E8  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 80133C0C 001307EC  80 06 06 68 */	lwz r0, 0x668(r6)
/* 80133C10 001307F0  80 A6 02 D4 */	lwz r5, 0x2d4(r6)
/* 80133C14 001307F4  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 80133C18 001307F8  41 82 00 0C */	beq lbl_80133C24
/* 80133C1C 001307FC  38 00 00 01 */	li r0, 1
/* 80133C20 00130800  90 06 23 40 */	stw r0, 0x2340(r6)
lbl_80133C24:
/* 80133C24 00130804  C0 45 00 30 */	lfs f2, 0x30(r5)
/* 80133C28 00130808  C0 66 06 28 */	lfs f3, 0x628(r6)
/* 80133C2C 0013080C  FC 20 10 50 */	fneg f1, f2
/* 80133C30 00130810  FC 03 08 40 */	fcmpo cr0, f3, f1
/* 80133C34 00130814  40 81 00 14 */	ble lbl_80133C48
/* 80133C38 00130818  C0 06 06 20 */	lfs f0, 0x620(r6)
/* 80133C3C 0013081C  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80133C40 00130820  40 80 00 08 */	bge lbl_80133C48
/* 80133C44 00130824  38 80 FF FF */	li r4, -1
lbl_80133C48:
/* 80133C48 00130828  FC 03 10 40 */	fcmpo cr0, f3, f2
/* 80133C4C 0013082C  40 80 00 14 */	bge lbl_80133C60
/* 80133C50 00130830  C0 06 06 20 */	lfs f0, 0x620(r6)
/* 80133C54 00130834  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 80133C58 00130838  40 81 00 08 */	ble lbl_80133C60
/* 80133C5C 0013083C  38 80 00 01 */	li r4, 1
lbl_80133C60:
/* 80133C60 00130840  6C 80 80 00 */	xoris r0, r4, 0x8000
/* 80133C64 00130844  C8 22 A0 F0 */	lfd f1, lbl_804D9AD0(r2)
/* 80133C68 00130848  90 01 00 34 */	stw r0, 0x34(r1)
/* 80133C6C 0013084C  3C 00 43 30 */	lis r0, 0x4330
/* 80133C70 00130850  C0 46 00 2C */	lfs f2, 0x2c(r6)
/* 80133C74 00130854  2C 04 00 00 */	cmpwi r4, 0
/* 80133C78 00130858  90 01 00 30 */	stw r0, 0x30(r1)
/* 80133C7C 0013085C  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 80133C80 00130860  EC 00 08 28 */	fsubs f0, f0, f1
/* 80133C84 00130864  EC 02 00 32 */	fmuls f0, f2, f0
/* 80133C88 00130868  FC 00 00 1E */	fctiwz f0, f0
/* 80133C8C 0013086C  D8 01 00 28 */	stfd f0, 0x28(r1)
/* 80133C90 00130870  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80133C94 00130874  90 06 23 48 */	stw r0, 0x2348(r6)
/* 80133C98 00130878  41 82 00 74 */	beq lbl_80133D0C
/* 80133C9C 0013087C  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80133CA0 00130880  38 00 00 00 */	li r0, 0
/* 80133CA4 00130884  90 1F 22 10 */	stw r0, 0x2210(r31)
/* 80133CA8 00130888  90 1F 22 00 */	stw r0, 0x2200(r31)
/* 80133CAC 0013088C  80 1F 23 48 */	lwz r0, 0x2348(r31)
/* 80133CB0 00130890  2C 00 00 01 */	cmpwi r0, 1
/* 80133CB4 00130894  40 82 00 30 */	bne lbl_80133CE4
/* 80133CB8 00130898  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133CBC 0013089C  38 80 01 5F */	li r4, 0x15f
/* 80133CC0 001308A0  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133CC4 001308A4  3C A0 00 08 */	lis r5, 8
/* 80133CC8 001308A8  FC 60 08 90 */	fmr f3, f1
/* 80133CCC 001308AC  38 C0 00 00 */	li r6, 0
/* 80133CD0 001308B0  4B F3 56 DD */	bl Fighter_ActionStateChange_800693AC
/* 80133CD4 001308B4  80 7F 1A 58 */	lwz r3, 0x1a58(r31)
/* 80133CD8 001308B8  38 80 01 19 */	li r4, 0x119
/* 80133CDC 001308BC  4B F8 91 05 */	bl func_800BCDE0
/* 80133CE0 001308C0  48 00 00 2C */	b lbl_80133D0C
lbl_80133CE4:
/* 80133CE4 001308C4  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133CE8 001308C8  38 80 01 60 */	li r4, 0x160
/* 80133CEC 001308CC  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133CF0 001308D0  3C A0 00 08 */	lis r5, 8
/* 80133CF4 001308D4  FC 60 08 90 */	fmr f3, f1
/* 80133CF8 001308D8  38 C0 00 00 */	li r6, 0
/* 80133CFC 001308DC  4B F3 56 B1 */	bl Fighter_ActionStateChange_800693AC
/* 80133D00 001308E0  80 7F 1A 58 */	lwz r3, 0x1a58(r31)
/* 80133D04 001308E4  38 80 01 1A */	li r4, 0x11a
/* 80133D08 001308E8  4B F8 90 D9 */	bl func_800BCDE0
lbl_80133D0C:
/* 80133D0C 001308EC  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80133D10 001308F0  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80133D14 001308F4  38 21 00 40 */	addi r1, r1, 0x40
/* 80133D18 001308F8  7C 08 03 A6 */	mtlr r0
/* 80133D1C 001308FC  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80133D20()
{ // clang-format off
    nofralloc
/* 80133D20 00130900  7C 08 02 A6 */	mflr r0
/* 80133D24 00130904  38 80 00 00 */	li r4, 0
/* 80133D28 00130908  90 01 00 04 */	stw r0, 4(r1)
/* 80133D2C 0013090C  94 21 FF C0 */	stwu r1, -0x40(r1)
/* 80133D30 00130910  93 E1 00 3C */	stw r31, 0x3c(r1)
/* 80133D34 00130914  80 C3 00 2C */	lwz r6, 0x2c(r3)
/* 80133D38 00130918  80 06 06 68 */	lwz r0, 0x668(r6)
/* 80133D3C 0013091C  80 A6 02 D4 */	lwz r5, 0x2d4(r6)
/* 80133D40 00130920  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 80133D44 00130924  41 82 00 0C */	beq lbl_80133D50
/* 80133D48 00130928  38 00 00 01 */	li r0, 1
/* 80133D4C 0013092C  90 06 23 40 */	stw r0, 0x2340(r6)
lbl_80133D50:
/* 80133D50 00130930  C0 45 00 30 */	lfs f2, 0x30(r5)
/* 80133D54 00130934  C0 66 06 28 */	lfs f3, 0x628(r6)
/* 80133D58 00130938  FC 20 10 50 */	fneg f1, f2
/* 80133D5C 0013093C  FC 03 08 40 */	fcmpo cr0, f3, f1
/* 80133D60 00130940  40 81 00 14 */	ble lbl_80133D74
/* 80133D64 00130944  C0 06 06 20 */	lfs f0, 0x620(r6)
/* 80133D68 00130948  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80133D6C 0013094C  40 80 00 08 */	bge lbl_80133D74
/* 80133D70 00130950  38 80 FF FF */	li r4, -1
lbl_80133D74:
/* 80133D74 00130954  FC 03 10 40 */	fcmpo cr0, f3, f2
/* 80133D78 00130958  40 80 00 14 */	bge lbl_80133D8C
/* 80133D7C 0013095C  C0 06 06 20 */	lfs f0, 0x620(r6)
/* 80133D80 00130960  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 80133D84 00130964  40 81 00 08 */	ble lbl_80133D8C
/* 80133D88 00130968  38 80 00 01 */	li r4, 1
lbl_80133D8C:
/* 80133D8C 0013096C  6C 80 80 00 */	xoris r0, r4, 0x8000
/* 80133D90 00130970  C8 22 A0 F0 */	lfd f1, lbl_804D9AD0(r2)
/* 80133D94 00130974  90 01 00 34 */	stw r0, 0x34(r1)
/* 80133D98 00130978  3C 00 43 30 */	lis r0, 0x4330
/* 80133D9C 0013097C  C0 46 00 2C */	lfs f2, 0x2c(r6)
/* 80133DA0 00130980  2C 04 00 00 */	cmpwi r4, 0
/* 80133DA4 00130984  90 01 00 30 */	stw r0, 0x30(r1)
/* 80133DA8 00130988  C8 01 00 30 */	lfd f0, 0x30(r1)
/* 80133DAC 0013098C  EC 00 08 28 */	fsubs f0, f0, f1
/* 80133DB0 00130990  EC 02 00 32 */	fmuls f0, f2, f0
/* 80133DB4 00130994  FC 00 00 1E */	fctiwz f0, f0
/* 80133DB8 00130998  D8 01 00 28 */	stfd f0, 0x28(r1)
/* 80133DBC 0013099C  80 01 00 2C */	lwz r0, 0x2c(r1)
/* 80133DC0 001309A0  90 06 23 48 */	stw r0, 0x2348(r6)
/* 80133DC4 001309A4  41 82 00 74 */	beq lbl_80133E38
/* 80133DC8 001309A8  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 80133DCC 001309AC  38 00 00 00 */	li r0, 0
/* 80133DD0 001309B0  90 1F 22 10 */	stw r0, 0x2210(r31)
/* 80133DD4 001309B4  90 1F 22 00 */	stw r0, 0x2200(r31)
/* 80133DD8 001309B8  80 1F 23 48 */	lwz r0, 0x2348(r31)
/* 80133DDC 001309BC  2C 00 00 01 */	cmpwi r0, 1
/* 80133DE0 001309C0  40 82 00 30 */	bne lbl_80133E10
/* 80133DE4 001309C4  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133DE8 001309C8  38 80 01 65 */	li r4, 0x165
/* 80133DEC 001309CC  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133DF0 001309D0  3C A0 00 08 */	lis r5, 8
/* 80133DF4 001309D4  FC 60 08 90 */	fmr f3, f1
/* 80133DF8 001309D8  38 C0 00 00 */	li r6, 0
/* 80133DFC 001309DC  4B F3 55 B1 */	bl Fighter_ActionStateChange_800693AC
/* 80133E00 001309E0  80 7F 1A 58 */	lwz r3, 0x1a58(r31)
/* 80133E04 001309E4  38 80 01 1E */	li r4, 0x11e
/* 80133E08 001309E8  4B F8 8F D9 */	bl func_800BCDE0
/* 80133E0C 001309EC  48 00 00 2C */	b lbl_80133E38
lbl_80133E10:
/* 80133E10 001309F0  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133E14 001309F4  38 80 01 66 */	li r4, 0x166
/* 80133E18 001309F8  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133E1C 001309FC  3C A0 00 08 */	lis r5, 8
/* 80133E20 00130A00  FC 60 08 90 */	fmr f3, f1
/* 80133E24 00130A04  38 C0 00 00 */	li r6, 0
/* 80133E28 00130A08  4B F3 55 85 */	bl Fighter_ActionStateChange_800693AC
/* 80133E2C 00130A0C  80 7F 1A 58 */	lwz r3, 0x1a58(r31)
/* 80133E30 00130A10  38 80 01 1F */	li r4, 0x11f
/* 80133E34 00130A14  4B F8 8F AD */	bl func_800BCDE0
lbl_80133E38:
/* 80133E38 00130A18  80 01 00 44 */	lwz r0, 0x44(r1)
/* 80133E3C 00130A1C  83 E1 00 3C */	lwz r31, 0x3c(r1)
/* 80133E40 00130A20  38 21 00 40 */	addi r1, r1, 0x40
/* 80133E44 00130A24  7C 08 03 A6 */	mtlr r0
/* 80133E48 00130A28  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80133E4C()
{ // clang-format off
    nofralloc
/* 80133E4C 00130A2C  7C 08 02 A6 */	mflr r0
/* 80133E50 00130A30  90 01 00 04 */	stw r0, 4(r1)
/* 80133E54 00130A34  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80133E58 00130A38  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 80133E5C 00130A3C  7C 7F 1B 78 */	mr r31, r3
/* 80133E60 00130A40  93 C1 00 48 */	stw r30, 0x48(r1)
/* 80133E64 00130A44  93 A1 00 44 */	stw r29, 0x44(r1)
/* 80133E68 00130A48  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 80133E6C 00130A4C  38 60 00 00 */	li r3, 0
/* 80133E70 00130A50  80 1E 06 68 */	lwz r0, 0x668(r30)
/* 80133E74 00130A54  80 9E 02 D4 */	lwz r4, 0x2d4(r30)
/* 80133E78 00130A58  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 80133E7C 00130A5C  41 82 00 0C */	beq lbl_80133E88
/* 80133E80 00130A60  38 00 00 01 */	li r0, 1
/* 80133E84 00130A64  90 1E 23 40 */	stw r0, 0x2340(r30)
lbl_80133E88:
/* 80133E88 00130A68  C0 44 00 30 */	lfs f2, 0x30(r4)
/* 80133E8C 00130A6C  C0 7E 06 28 */	lfs f3, 0x628(r30)
/* 80133E90 00130A70  FC 20 10 50 */	fneg f1, f2
/* 80133E94 00130A74  FC 03 08 40 */	fcmpo cr0, f3, f1
/* 80133E98 00130A78  40 81 00 14 */	ble lbl_80133EAC
/* 80133E9C 00130A7C  C0 1E 06 20 */	lfs f0, 0x620(r30)
/* 80133EA0 00130A80  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80133EA4 00130A84  40 80 00 08 */	bge lbl_80133EAC
/* 80133EA8 00130A88  38 60 FF FF */	li r3, -1
lbl_80133EAC:
/* 80133EAC 00130A8C  FC 03 10 40 */	fcmpo cr0, f3, f2
/* 80133EB0 00130A90  40 80 00 14 */	bge lbl_80133EC4
/* 80133EB4 00130A94  C0 1E 06 20 */	lfs f0, 0x620(r30)
/* 80133EB8 00130A98  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 80133EBC 00130A9C  40 81 00 08 */	ble lbl_80133EC4
/* 80133EC0 00130AA0  38 60 00 01 */	li r3, 1
lbl_80133EC4:
/* 80133EC4 00130AA4  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 80133EC8 00130AA8  C8 22 A0 F0 */	lfd f1, lbl_804D9AD0(r2)
/* 80133ECC 00130AAC  90 01 00 3C */	stw r0, 0x3c(r1)
/* 80133ED0 00130AB0  3C 00 43 30 */	lis r0, 0x4330
/* 80133ED4 00130AB4  C0 5E 00 2C */	lfs f2, 0x2c(r30)
/* 80133ED8 00130AB8  2C 03 00 00 */	cmpwi r3, 0
/* 80133EDC 00130ABC  90 01 00 38 */	stw r0, 0x38(r1)
/* 80133EE0 00130AC0  C8 01 00 38 */	lfd f0, 0x38(r1)
/* 80133EE4 00130AC4  EC 00 08 28 */	fsubs f0, f0, f1
/* 80133EE8 00130AC8  EC 02 00 32 */	fmuls f0, f2, f0
/* 80133EEC 00130ACC  FC 00 00 1E */	fctiwz f0, f0
/* 80133EF0 00130AD0  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 80133EF4 00130AD4  80 01 00 34 */	lwz r0, 0x34(r1)
/* 80133EF8 00130AD8  90 1E 23 48 */	stw r0, 0x2348(r30)
/* 80133EFC 00130ADC  41 82 00 80 */	beq lbl_80133F7C
/* 80133F00 00130AE0  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 80133F04 00130AE4  38 00 00 00 */	li r0, 0
/* 80133F08 00130AE8  90 1E 22 10 */	stw r0, 0x2210(r30)
/* 80133F0C 00130AEC  90 1E 22 00 */	stw r0, 0x2200(r30)
/* 80133F10 00130AF0  80 1E 23 48 */	lwz r0, 0x2348(r30)
/* 80133F14 00130AF4  2C 00 00 01 */	cmpwi r0, 1
/* 80133F18 00130AF8  40 82 00 34 */	bne lbl_80133F4C
/* 80133F1C 00130AFC  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133F20 00130B00  7F E3 FB 78 */	mr r3, r31
/* 80133F24 00130B04  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133F28 00130B08  38 80 01 5F */	li r4, 0x15f
/* 80133F2C 00130B0C  FC 60 08 90 */	fmr f3, f1
/* 80133F30 00130B10  3C A0 00 08 */	lis r5, 8
/* 80133F34 00130B14  38 C0 00 00 */	li r6, 0
/* 80133F38 00130B18  4B F3 54 75 */	bl Fighter_ActionStateChange_800693AC
/* 80133F3C 00130B1C  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 80133F40 00130B20  38 80 01 19 */	li r4, 0x119
/* 80133F44 00130B24  4B F8 8E 9D */	bl func_800BCDE0
/* 80133F48 00130B28  48 00 00 D4 */	b lbl_8013401C
lbl_80133F4C:
/* 80133F4C 00130B2C  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133F50 00130B30  7F E3 FB 78 */	mr r3, r31
/* 80133F54 00130B34  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133F58 00130B38  38 80 01 60 */	li r4, 0x160
/* 80133F5C 00130B3C  FC 60 08 90 */	fmr f3, f1
/* 80133F60 00130B40  3C A0 00 08 */	lis r5, 8
/* 80133F64 00130B44  38 C0 00 00 */	li r6, 0
/* 80133F68 00130B48  4B F3 54 45 */	bl Fighter_ActionStateChange_800693AC
/* 80133F6C 00130B4C  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 80133F70 00130B50  38 80 01 1A */	li r4, 0x11a
/* 80133F74 00130B54  4B F8 8E 6D */	bl func_800BCDE0
/* 80133F78 00130B58  48 00 00 A4 */	b lbl_8013401C
lbl_80133F7C:
/* 80133F7C 00130B5C  80 1E 23 40 */	lwz r0, 0x2340(r30)
/* 80133F80 00130B60  2C 00 00 00 */	cmpwi r0, 0
/* 80133F84 00130B64  41 82 00 98 */	beq lbl_8013401C
/* 80133F88 00130B68  38 00 00 01 */	li r0, 1
/* 80133F8C 00130B6C  90 1E 23 44 */	stw r0, 0x2344(r30)
/* 80133F90 00130B70  83 BF 00 2C */	lwz r29, 0x2c(r31)
/* 80133F94 00130B74  80 1D 23 44 */	lwz r0, 0x2344(r29)
/* 80133F98 00130B78  2C 00 00 00 */	cmpwi r0, 0
/* 80133F9C 00130B7C  41 82 00 28 */	beq lbl_80133FC4
/* 80133FA0 00130B80  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133FA4 00130B84  7F E3 FB 78 */	mr r3, r31
/* 80133FA8 00130B88  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133FAC 00130B8C  38 80 01 5D */	li r4, 0x15d
/* 80133FB0 00130B90  FC 60 08 90 */	fmr f3, f1
/* 80133FB4 00130B94  38 A0 00 80 */	li r5, 0x80
/* 80133FB8 00130B98  38 C0 00 00 */	li r6, 0
/* 80133FBC 00130B9C  4B F3 53 F1 */	bl Fighter_ActionStateChange_800693AC
/* 80133FC0 00130BA0  48 00 00 24 */	b lbl_80133FE4
lbl_80133FC4:
/* 80133FC4 00130BA4  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80133FC8 00130BA8  7F E3 FB 78 */	mr r3, r31
/* 80133FCC 00130BAC  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80133FD0 00130BB0  38 80 01 5C */	li r4, 0x15c
/* 80133FD4 00130BB4  FC 60 08 90 */	fmr f3, f1
/* 80133FD8 00130BB8  38 A0 00 00 */	li r5, 0
/* 80133FDC 00130BBC  38 C0 00 00 */	li r6, 0
/* 80133FE0 00130BC0  4B F3 53 CD */	bl Fighter_ActionStateChange_800693AC
lbl_80133FE4:
/* 80133FE4 00130BC4  88 1D 22 22 */	lbz r0, 0x2222(r29)
/* 80133FE8 00130BC8  38 60 00 01 */	li r3, 1
/* 80133FEC 00130BCC  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 80133FF0 00130BD0  98 1D 22 22 */	stb r0, 0x2222(r29)
/* 80133FF4 00130BD4  38 7D 00 00 */	addi r3, r29, 0
/* 80133FF8 00130BD8  38 80 01 FF */	li r4, 0x1ff
/* 80133FFC 00130BDC  4B F4 A2 F9 */	bl func_8007E2F4
/* 80134000 00130BE0  7F E3 FB 78 */	mr r3, r31
/* 80134004 00130BE4  4B F4 A2 F9 */	bl func_8007E2FC
/* 80134008 00130BE8  38 00 00 00 */	li r0, 0
/* 8013400C 00130BEC  90 1D 23 40 */	stw r0, 0x2340(r29)
/* 80134010 00130BF0  90 1D 22 00 */	stw r0, 0x2200(r29)
/* 80134014 00130BF4  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 80134018 00130BF8  4B F8 89 B1 */	bl func_800BC9C8
lbl_8013401C:
/* 8013401C 00130BFC  80 01 00 54 */	lwz r0, 0x54(r1)
/* 80134020 00130C00  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 80134024 00130C04  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 80134028 00130C08  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 8013402C 00130C0C  38 21 00 50 */	addi r1, r1, 0x50
/* 80134030 00130C10  7C 08 03 A6 */	mtlr r0
/* 80134034 00130C14  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134038()
{ // clang-format off
    nofralloc
/* 80134038 00130C18  7C 08 02 A6 */	mflr r0
/* 8013403C 00130C1C  90 01 00 04 */	stw r0, 4(r1)
/* 80134040 00130C20  94 21 FF B0 */	stwu r1, -0x50(r1)
/* 80134044 00130C24  93 E1 00 4C */	stw r31, 0x4c(r1)
/* 80134048 00130C28  7C 7F 1B 78 */	mr r31, r3
/* 8013404C 00130C2C  93 C1 00 48 */	stw r30, 0x48(r1)
/* 80134050 00130C30  93 A1 00 44 */	stw r29, 0x44(r1)
/* 80134054 00130C34  83 C3 00 2C */	lwz r30, 0x2c(r3)
/* 80134058 00130C38  38 60 00 00 */	li r3, 0
/* 8013405C 00130C3C  80 1E 06 68 */	lwz r0, 0x668(r30)
/* 80134060 00130C40  80 9E 02 D4 */	lwz r4, 0x2d4(r30)
/* 80134064 00130C44  54 00 05 AD */	rlwinm. r0, r0, 0, 0x16, 0x16
/* 80134068 00130C48  41 82 00 0C */	beq lbl_80134074
/* 8013406C 00130C4C  38 00 00 01 */	li r0, 1
/* 80134070 00130C50  90 1E 23 40 */	stw r0, 0x2340(r30)
lbl_80134074:
/* 80134074 00130C54  C0 44 00 30 */	lfs f2, 0x30(r4)
/* 80134078 00130C58  C0 7E 06 28 */	lfs f3, 0x628(r30)
/* 8013407C 00130C5C  FC 20 10 50 */	fneg f1, f2
/* 80134080 00130C60  FC 03 08 40 */	fcmpo cr0, f3, f1
/* 80134084 00130C64  40 81 00 14 */	ble lbl_80134098
/* 80134088 00130C68  C0 1E 06 20 */	lfs f0, 0x620(r30)
/* 8013408C 00130C6C  FC 00 08 40 */	fcmpo cr0, f0, f1
/* 80134090 00130C70  40 80 00 08 */	bge lbl_80134098
/* 80134094 00130C74  38 60 FF FF */	li r3, -1
lbl_80134098:
/* 80134098 00130C78  FC 03 10 40 */	fcmpo cr0, f3, f2
/* 8013409C 00130C7C  40 80 00 14 */	bge lbl_801340B0
/* 801340A0 00130C80  C0 1E 06 20 */	lfs f0, 0x620(r30)
/* 801340A4 00130C84  FC 00 10 40 */	fcmpo cr0, f0, f2
/* 801340A8 00130C88  40 81 00 08 */	ble lbl_801340B0
/* 801340AC 00130C8C  38 60 00 01 */	li r3, 1
lbl_801340B0:
/* 801340B0 00130C90  6C 60 80 00 */	xoris r0, r3, 0x8000
/* 801340B4 00130C94  C8 22 A0 F0 */	lfd f1, lbl_804D9AD0(r2)
/* 801340B8 00130C98  90 01 00 3C */	stw r0, 0x3c(r1)
/* 801340BC 00130C9C  3C 00 43 30 */	lis r0, 0x4330
/* 801340C0 00130CA0  C0 5E 00 2C */	lfs f2, 0x2c(r30)
/* 801340C4 00130CA4  2C 03 00 00 */	cmpwi r3, 0
/* 801340C8 00130CA8  90 01 00 38 */	stw r0, 0x38(r1)
/* 801340CC 00130CAC  C8 01 00 38 */	lfd f0, 0x38(r1)
/* 801340D0 00130CB0  EC 00 08 28 */	fsubs f0, f0, f1
/* 801340D4 00130CB4  EC 02 00 32 */	fmuls f0, f2, f0
/* 801340D8 00130CB8  FC 00 00 1E */	fctiwz f0, f0
/* 801340DC 00130CBC  D8 01 00 30 */	stfd f0, 0x30(r1)
/* 801340E0 00130CC0  80 01 00 34 */	lwz r0, 0x34(r1)
/* 801340E4 00130CC4  90 1E 23 48 */	stw r0, 0x2348(r30)
/* 801340E8 00130CC8  41 82 00 80 */	beq lbl_80134168
/* 801340EC 00130CCC  83 DF 00 2C */	lwz r30, 0x2c(r31)
/* 801340F0 00130CD0  38 00 00 00 */	li r0, 0
/* 801340F4 00130CD4  90 1E 22 10 */	stw r0, 0x2210(r30)
/* 801340F8 00130CD8  90 1E 22 00 */	stw r0, 0x2200(r30)
/* 801340FC 00130CDC  80 1E 23 48 */	lwz r0, 0x2348(r30)
/* 80134100 00130CE0  2C 00 00 01 */	cmpwi r0, 1
/* 80134104 00130CE4  40 82 00 34 */	bne lbl_80134138
/* 80134108 00130CE8  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 8013410C 00130CEC  7F E3 FB 78 */	mr r3, r31
/* 80134110 00130CF0  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80134114 00130CF4  38 80 01 65 */	li r4, 0x165
/* 80134118 00130CF8  FC 60 08 90 */	fmr f3, f1
/* 8013411C 00130CFC  3C A0 00 08 */	lis r5, 8
/* 80134120 00130D00  38 C0 00 00 */	li r6, 0
/* 80134124 00130D04  4B F3 52 89 */	bl Fighter_ActionStateChange_800693AC
/* 80134128 00130D08  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 8013412C 00130D0C  38 80 01 1E */	li r4, 0x11e
/* 80134130 00130D10  4B F8 8C B1 */	bl func_800BCDE0
/* 80134134 00130D14  48 00 00 D4 */	b lbl_80134208
lbl_80134138:
/* 80134138 00130D18  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 8013413C 00130D1C  7F E3 FB 78 */	mr r3, r31
/* 80134140 00130D20  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80134144 00130D24  38 80 01 66 */	li r4, 0x166
/* 80134148 00130D28  FC 60 08 90 */	fmr f3, f1
/* 8013414C 00130D2C  3C A0 00 08 */	lis r5, 8
/* 80134150 00130D30  38 C0 00 00 */	li r6, 0
/* 80134154 00130D34  4B F3 52 59 */	bl Fighter_ActionStateChange_800693AC
/* 80134158 00130D38  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 8013415C 00130D3C  38 80 01 1F */	li r4, 0x11f
/* 80134160 00130D40  4B F8 8C 81 */	bl func_800BCDE0
/* 80134164 00130D44  48 00 00 A4 */	b lbl_80134208
lbl_80134168:
/* 80134168 00130D48  80 1E 23 40 */	lwz r0, 0x2340(r30)
/* 8013416C 00130D4C  2C 00 00 00 */	cmpwi r0, 0
/* 80134170 00130D50  41 82 00 98 */	beq lbl_80134208
/* 80134174 00130D54  38 00 00 01 */	li r0, 1
/* 80134178 00130D58  90 1E 23 44 */	stw r0, 0x2344(r30)
/* 8013417C 00130D5C  83 BF 00 2C */	lwz r29, 0x2c(r31)
/* 80134180 00130D60  80 1D 23 44 */	lwz r0, 0x2344(r29)
/* 80134184 00130D64  2C 00 00 00 */	cmpwi r0, 0
/* 80134188 00130D68  41 82 00 28 */	beq lbl_801341B0
/* 8013418C 00130D6C  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 80134190 00130D70  7F E3 FB 78 */	mr r3, r31
/* 80134194 00130D74  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 80134198 00130D78  38 80 01 63 */	li r4, 0x163
/* 8013419C 00130D7C  FC 60 08 90 */	fmr f3, f1
/* 801341A0 00130D80  38 A0 00 80 */	li r5, 0x80
/* 801341A4 00130D84  38 C0 00 00 */	li r6, 0
/* 801341A8 00130D88  4B F3 52 05 */	bl Fighter_ActionStateChange_800693AC
/* 801341AC 00130D8C  48 00 00 24 */	b lbl_801341D0
lbl_801341B0:
/* 801341B0 00130D90  C0 22 A0 F8 */	lfs f1, lbl_804D9AD8(r2)
/* 801341B4 00130D94  7F E3 FB 78 */	mr r3, r31
/* 801341B8 00130D98  C0 42 A0 FC */	lfs f2, lbl_804D9ADC(r2)
/* 801341BC 00130D9C  38 80 01 62 */	li r4, 0x162
/* 801341C0 00130DA0  FC 60 08 90 */	fmr f3, f1
/* 801341C4 00130DA4  38 A0 00 00 */	li r5, 0
/* 801341C8 00130DA8  38 C0 00 00 */	li r6, 0
/* 801341CC 00130DAC  4B F3 51 E1 */	bl Fighter_ActionStateChange_800693AC
lbl_801341D0:
/* 801341D0 00130DB0  88 1D 22 22 */	lbz r0, 0x2222(r29)
/* 801341D4 00130DB4  38 60 00 01 */	li r3, 1
/* 801341D8 00130DB8  50 60 2E B4 */	rlwimi r0, r3, 5, 0x1a, 0x1a
/* 801341DC 00130DBC  98 1D 22 22 */	stb r0, 0x2222(r29)
/* 801341E0 00130DC0  38 7D 00 00 */	addi r3, r29, 0
/* 801341E4 00130DC4  38 80 01 FF */	li r4, 0x1ff
/* 801341E8 00130DC8  4B F4 A1 0D */	bl func_8007E2F4
/* 801341EC 00130DCC  7F E3 FB 78 */	mr r3, r31
/* 801341F0 00130DD0  4B F4 A1 0D */	bl func_8007E2FC
/* 801341F4 00130DD4  38 00 00 00 */	li r0, 0
/* 801341F8 00130DD8  90 1D 23 40 */	stw r0, 0x2340(r29)
/* 801341FC 00130DDC  90 1D 22 00 */	stw r0, 0x2200(r29)
/* 80134200 00130DE0  80 7E 1A 58 */	lwz r3, 0x1a58(r30)
/* 80134204 00130DE4  4B F8 88 F1 */	bl func_800BCAF4
lbl_80134208:
/* 80134208 00130DE8  80 01 00 54 */	lwz r0, 0x54(r1)
/* 8013420C 00130DEC  83 E1 00 4C */	lwz r31, 0x4c(r1)
/* 80134210 00130DF0  83 C1 00 48 */	lwz r30, 0x48(r1)
/* 80134214 00130DF4  83 A1 00 44 */	lwz r29, 0x44(r1)
/* 80134218 00130DF8  38 21 00 50 */	addi r1, r1, 0x50
/* 8013421C 00130DFC  7C 08 03 A6 */	mtlr r0
/* 80134220 00130E00  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

extern unk_t func_800850B4();

#pragma push
asm unk_t lbl_80134224()
{ // clang-format off
    nofralloc
/* 80134224 00130E04  7C 08 02 A6 */	mflr r0
/* 80134228 00130E08  90 01 00 04 */	stw r0, 4(r1)
/* 8013422C 00130E0C  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134230 00130E10  4B F5 0E 85 */	bl func_800850B4
/* 80134234 00130E14  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80134238 00130E18  38 21 00 08 */	addi r1, r1, 8
/* 8013423C 00130E1C  7C 08 03 A6 */	mtlr r0
/* 80134240 00130E20  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134244()
{ // clang-format off
    nofralloc
/* 80134244 00130E24  7C 08 02 A6 */	mflr r0
/* 80134248 00130E28  90 01 00 04 */	stw r0, 4(r1)
/* 8013424C 00130E2C  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 80134250 00130E30  DB E1 00 18 */	stfd f31, 0x18(r1)
/* 80134254 00130E34  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80134258 00130E38  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8013425C 00130E3C  C3 FF 00 84 */	lfs f31, 0x84(r31)
/* 80134260 00130E40  4B F5 0E D5 */	bl func_80085134
/* 80134264 00130E44  D3 FF 00 84 */	stfs f31, 0x84(r31)
/* 80134268 00130E48  7F E3 FB 78 */	mr r3, r31
/* 8013426C 00130E4C  4B F4 92 4D */	bl func_8007D4B8
/* 80134270 00130E50  80 01 00 24 */	lwz r0, 0x24(r1)
/* 80134274 00130E54  CB E1 00 18 */	lfd f31, 0x18(r1)
/* 80134278 00130E58  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 8013427C 00130E5C  38 21 00 20 */	addi r1, r1, 0x20
/* 80134280 00130E60  7C 08 03 A6 */	mtlr r0
/* 80134284 00130E64  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134288()
{ // clang-format off
    nofralloc
/* 80134288 00130E68  7C 08 02 A6 */	mflr r0
/* 8013428C 00130E6C  90 01 00 04 */	stw r0, 4(r1)
/* 80134290 00130E70  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134294 00130E74  4B F5 0C A9 */	bl func_80084F3C
/* 80134298 00130E78  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013429C 00130E7C  38 21 00 08 */	addi r1, r1, 8
/* 801342A0 00130E80  7C 08 03 A6 */	mtlr r0
/* 801342A4 00130E84  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801342A8()
{ // clang-format off
    nofralloc
/* 801342A8 00130E88  7C 08 02 A6 */	mflr r0
/* 801342AC 00130E8C  90 01 00 04 */	stw r0, 4(r1)
/* 801342B0 00130E90  94 21 FF F8 */	stwu r1, -8(r1)
/* 801342B4 00130E94  4B F5 0C 39 */	bl func_80084EEC
/* 801342B8 00130E98  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801342BC 00130E9C  38 21 00 08 */	addi r1, r1, 8
/* 801342C0 00130EA0  7C 08 03 A6 */	mtlr r0
/* 801342C4 00130EA4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801342C8()
{ // clang-format off
    nofralloc
/* 801342C8 00130EA8  7C 08 02 A6 */	mflr r0
/* 801342CC 00130EAC  90 01 00 04 */	stw r0, 4(r1)
/* 801342D0 00130EB0  94 21 FF F8 */	stwu r1, -8(r1)
/* 801342D4 00130EB4  4B F5 0C 69 */	bl func_80084F3C
/* 801342D8 00130EB8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801342DC 00130EBC  38 21 00 08 */	addi r1, r1, 8
/* 801342E0 00130EC0  7C 08 03 A6 */	mtlr r0
/* 801342E4 00130EC4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801342E8()
{ // clang-format off
    nofralloc
/* 801342E8 00130EC8  7C 08 02 A6 */	mflr r0
/* 801342EC 00130ECC  90 01 00 04 */	stw r0, 4(r1)
/* 801342F0 00130ED0  94 21 FF F8 */	stwu r1, -8(r1)
/* 801342F4 00130ED4  4B F5 0B F9 */	bl func_80084EEC
/* 801342F8 00130ED8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801342FC 00130EDC  38 21 00 08 */	addi r1, r1, 8
/* 80134300 00130EE0  7C 08 03 A6 */	mtlr r0
/* 80134304 00130EE4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134308()
{ // clang-format off
    nofralloc
/* 80134308 00130EE8  7C 08 02 A6 */	mflr r0
/* 8013430C 00130EEC  90 01 00 04 */	stw r0, 4(r1)
/* 80134310 00130EF0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134314 00130EF4  4B F5 0D A1 */	bl func_800850B4
/* 80134318 00130EF8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013431C 00130EFC  38 21 00 08 */	addi r1, r1, 8
/* 80134320 00130F00  7C 08 03 A6 */	mtlr r0
/* 80134324 00130F04  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134328()
{ // clang-format off
    nofralloc
/* 80134328 00130F08  7C 08 02 A6 */	mflr r0
/* 8013432C 00130F0C  90 01 00 04 */	stw r0, 4(r1)
/* 80134330 00130F10  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134334 00130F14  4B F5 0D 81 */	bl func_800850B4
/* 80134338 00130F18  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013433C 00130F1C  38 21 00 08 */	addi r1, r1, 8
/* 80134340 00130F20  7C 08 03 A6 */	mtlr r0
/* 80134344 00130F24  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134348()
{ // clang-format off
    nofralloc
/* 80134348 00130F28  7C 08 02 A6 */	mflr r0
/* 8013434C 00130F2C  90 01 00 04 */	stw r0, 4(r1)
/* 80134350 00130F30  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134354 00130F34  4B F5 0B 99 */	bl func_80084EEC
/* 80134358 00130F38  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013435C 00130F3C  38 21 00 08 */	addi r1, r1, 8
/* 80134360 00130F40  7C 08 03 A6 */	mtlr r0
/* 80134364 00130F44  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134368()
{ // clang-format off
    nofralloc
/* 80134368 00130F48  7C 08 02 A6 */	mflr r0
/* 8013436C 00130F4C  90 01 00 04 */	stw r0, 4(r1)
/* 80134370 00130F50  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134374 00130F54  4B F5 0B 79 */	bl func_80084EEC
/* 80134378 00130F58  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013437C 00130F5C  38 21 00 08 */	addi r1, r1, 8
/* 80134380 00130F60  7C 08 03 A6 */	mtlr r0
/* 80134384 00130F64  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

extern unk_t func_8008403C();

#pragma push
asm unk_t lbl_80134388()
{ // clang-format off
    nofralloc
/* 80134388 00130F68  7C 08 02 A6 */	mflr r0
/* 8013438C 00130F6C  3C 80 80 13 */	lis r4, func_8013319C@ha
/* 80134390 00130F70  90 01 00 04 */	stw r0, 4(r1)
/* 80134394 00130F74  38 84 31 9C */	addi r4, r4, func_8013319C@l
/* 80134398 00130F78  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013439C 00130F7C  4B F4 FC A1 */	bl func_8008403C
/* 801343A0 00130F80  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801343A4 00130F84  38 21 00 08 */	addi r1, r1, 8
/* 801343A8 00130F88  7C 08 03 A6 */	mtlr r0
/* 801343AC 00130F8C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

extern unk_t func_80082C74();

#pragma push
asm unk_t lbl_801343B0()
{ // clang-format off
    nofralloc
/* 801343B0 00130F90  7C 08 02 A6 */	mflr r0
/* 801343B4 00130F94  3C 80 80 13 */	lis r4, func_8013322C@ha
/* 801343B8 00130F98  90 01 00 04 */	stw r0, 4(r1)
/* 801343BC 00130F9C  38 84 32 2C */	addi r4, r4, func_8013322C@l
/* 801343C0 00130FA0  94 21 FF F8 */	stwu r1, -8(r1)
/* 801343C4 00130FA4  4B F4 E8 B1 */	bl func_80082C74
/* 801343C8 00130FA8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801343CC 00130FAC  38 21 00 08 */	addi r1, r1, 8
/* 801343D0 00130FB0  7C 08 03 A6 */	mtlr r0
/* 801343D4 00130FB4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

extern unk_t func_800841B8();

#pragma push
asm unk_t lbl_801343D8()
{ // clang-format off
    nofralloc
/* 801343D8 00130FB8  7C 08 02 A6 */	mflr r0
/* 801343DC 00130FBC  3C 80 80 13 */	lis r4, func_801332C4@ha
/* 801343E0 00130FC0  90 01 00 04 */	stw r0, 4(r1)
/* 801343E4 00130FC4  38 84 32 C4 */	addi r4, r4, func_801332C4@l
/* 801343E8 00130FC8  94 21 FF F8 */	stwu r1, -8(r1)
/* 801343EC 00130FCC  4B F4 FD CD */	bl func_800841B8
/* 801343F0 00130FD0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801343F4 00130FD4  38 21 00 08 */	addi r1, r1, 8
/* 801343F8 00130FD8  7C 08 03 A6 */	mtlr r0
/* 801343FC 00130FDC  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134400()
{ // clang-format off
    nofralloc
/* 80134400 00130FE0  7C 08 02 A6 */	mflr r0
/* 80134404 00130FE4  3C 80 80 13 */	lis r4, func_80133324@ha
/* 80134408 00130FE8  90 01 00 04 */	stw r0, 4(r1)
/* 8013440C 00130FEC  38 84 33 24 */	addi r4, r4, func_80133324@l
/* 80134410 00130FF0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134414 00130FF4  4B F4 E8 61 */	bl func_80082C74
/* 80134418 00130FF8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013441C 00130FFC  38 21 00 08 */	addi r1, r1, 8
/* 80134420 00131000  7C 08 03 A6 */	mtlr r0
/* 80134424 00131004  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134428()
{ // clang-format off
    nofralloc
/* 80134428 00131008  7C 08 02 A6 */	mflr r0
/* 8013442C 0013100C  3C 80 80 13 */	lis r4, func_80133398@ha
/* 80134430 00131010  90 01 00 04 */	stw r0, 4(r1)
/* 80134434 00131014  38 84 33 98 */	addi r4, r4, func_80133398@l
/* 80134438 00131018  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013443C 0013101C  4B F4 FD 7D */	bl func_800841B8
/* 80134440 00131020  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80134444 00131024  38 21 00 08 */	addi r1, r1, 8
/* 80134448 00131028  7C 08 03 A6 */	mtlr r0
/* 8013444C 0013102C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134450()
{ // clang-format off
    nofralloc
/* 80134450 00131030  7C 08 02 A6 */	mflr r0
/* 80134454 00131034  3C 80 80 13 */	lis r4, func_801333F8@ha
/* 80134458 00131038  90 01 00 04 */	stw r0, 4(r1)
/* 8013445C 0013103C  38 84 33 F8 */	addi r4, r4, func_801333F8@l
/* 80134460 00131040  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134464 00131044  4B F4 E8 11 */	bl func_80082C74
/* 80134468 00131048  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013446C 0013104C  38 21 00 08 */	addi r1, r1, 8
/* 80134470 00131050  7C 08 03 A6 */	mtlr r0
/* 80134474 00131054  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134478()
{ // clang-format off
    nofralloc
/* 80134478 00131058  7C 08 02 A6 */	mflr r0
/* 8013447C 0013105C  3C 80 80 13 */	lis r4, func_80133484@ha
/* 80134480 00131060  90 01 00 04 */	stw r0, 4(r1)
/* 80134484 00131064  38 84 34 84 */	addi r4, r4, func_80133484@l
/* 80134488 00131068  94 21 FF F8 */	stwu r1, -8(r1)
/* 8013448C 0013106C  4B F4 FD 2D */	bl func_800841B8
/* 80134490 00131070  80 01 00 0C */	lwz r0, 0xc(r1)
/* 80134494 00131074  38 21 00 08 */	addi r1, r1, 8
/* 80134498 00131078  7C 08 03 A6 */	mtlr r0
/* 8013449C 0013107C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801344A0()
{ // clang-format off
    nofralloc
/* 801344A0 00131080  7C 08 02 A6 */	mflr r0
/* 801344A4 00131084  3C 80 80 13 */	lis r4, func_80133484@ha
/* 801344A8 00131088  90 01 00 04 */	stw r0, 4(r1)
/* 801344AC 0013108C  38 84 34 84 */	addi r4, r4, func_80133484@l
/* 801344B0 00131090  94 21 FF F8 */	stwu r1, -8(r1)
/* 801344B4 00131094  4B F4 FD 05 */	bl func_800841B8
/* 801344B8 00131098  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801344BC 0013109C  38 21 00 08 */	addi r1, r1, 8
/* 801344C0 001310A0  7C 08 03 A6 */	mtlr r0
/* 801344C4 001310A4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801344C8()
{ // clang-format off
    nofralloc
/* 801344C8 001310A8  7C 08 02 A6 */	mflr r0
/* 801344CC 001310AC  3C 80 80 13 */	lis r4, func_801334E4@ha
/* 801344D0 001310B0  90 01 00 04 */	stw r0, 4(r1)
/* 801344D4 001310B4  38 84 34 E4 */	addi r4, r4, func_801334E4@l
/* 801344D8 001310B8  94 21 FF F8 */	stwu r1, -8(r1)
/* 801344DC 001310BC  4B F4 E7 99 */	bl func_80082C74
/* 801344E0 001310C0  80 01 00 0C */	lwz r0, 0xc(r1)
/* 801344E4 001310C4  38 21 00 08 */	addi r1, r1, 8
/* 801344E8 001310C8  7C 08 03 A6 */	mtlr r0
/* 801344EC 001310CC  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_801344F0()
{ // clang-format off
    nofralloc
/* 801344F0 001310D0  7C 08 02 A6 */	mflr r0
/* 801344F4 001310D4  3C 80 80 13 */	lis r4, func_8013359C@ha
/* 801344F8 001310D8  90 01 00 04 */	stw r0, 4(r1)
/* 801344FC 001310DC  38 84 35 9C */	addi r4, r4, func_8013359C@l
/* 80134500 001310E0  94 21 FF F8 */	stwu r1, -8(r1)
/* 80134504 001310E4  4B F4 E7 71 */	bl func_80082C74
/* 80134508 001310E8  80 01 00 0C */	lwz r0, 0xc(r1)
/* 8013450C 001310EC  38 21 00 08 */	addi r1, r1, 8
/* 80134510 001310F0  7C 08 03 A6 */	mtlr r0
/* 80134514 001310F4  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134518()
{ // clang-format off
    nofralloc
/* 80134518 001310F8  7C 08 02 A6 */	mflr r0
/* 8013451C 001310FC  90 01 00 04 */	stw r0, 4(r1)
/* 80134520 00131100  94 21 FF E8 */	stwu r1, -0x18(r1)
/* 80134524 00131104  93 E1 00 14 */	stw r31, 0x14(r1)
/* 80134528 00131108  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 8013452C 0013110C  88 1F 22 19 */	lbz r0, 0x2219(r31)
/* 80134530 00131110  54 00 CF FF */	rlwinm. r0, r0, 0x19, 0x1f, 0x1f
/* 80134534 00131114  40 82 00 28 */	bne lbl_8013455C
/* 80134538 00131118  38 83 00 00 */	addi r4, r3, 0
/* 8013453C 0013111C  4C C6 31 82 */	crclr 6
/* 80134540 00131120  38 BF 00 B0 */	addi r5, r31, 0xb0
/* 80134544 00131124  38 60 04 D8 */	li r3, 0x4d8
/* 80134548 00131128  4B F2 B8 95 */	bl ef_Spawn
/* 8013454C 0013112C  88 1F 22 19 */	lbz r0, 0x2219(r31)
/* 80134550 00131130  38 60 00 01 */	li r3, 1
/* 80134554 00131134  50 60 3E 30 */	rlwimi r0, r3, 7, 0x18, 0x18
/* 80134558 00131138  98 1F 22 19 */	stb r0, 0x2219(r31)
lbl_8013455C:
/* 8013455C 0013113C  3C 60 80 06 */	lis r3, efLib_PauseAll@ha
/* 80134560 00131140  38 03 BA 40 */	addi r0, r3, efLib_PauseAll@l
/* 80134564 00131144  3C 60 80 06 */	lis r3, efLib_ResumeAll@ha
/* 80134568 00131148  90 1F 21 D4 */	stw r0, 0x21d4(r31)
/* 8013456C 0013114C  38 03 BA C4 */	addi r0, r3, efLib_ResumeAll@l
/* 80134570 00131150  90 1F 21 D8 */	stw r0, 0x21d8(r31)
/* 80134574 00131154  38 00 00 00 */	li r0, 0
/* 80134578 00131158  90 1F 21 BC */	stw r0, 0x21bc(r31)
/* 8013457C 0013115C  80 01 00 1C */	lwz r0, 0x1c(r1)
/* 80134580 00131160  83 E1 00 14 */	lwz r31, 0x14(r1)
/* 80134584 00131164  38 21 00 18 */	addi r1, r1, 0x18
/* 80134588 00131168  7C 08 03 A6 */	mtlr r0
/* 8013458C 0013116C  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop

#pragma push
asm unk_t lbl_80134590()
{ // clang-format off
    nofralloc
/* 80134590 00131170  7C 08 02 A6 */	mflr r0
/* 80134594 00131174  90 01 00 04 */	stw r0, 4(r1)
/* 80134598 00131178  94 21 FF E0 */	stwu r1, -0x20(r1)
/* 8013459C 0013117C  93 E1 00 1C */	stw r31, 0x1c(r1)
/* 801345A0 00131180  83 E3 00 2C */	lwz r31, 0x2c(r3)
/* 801345A4 00131184  88 1F 22 19 */	lbz r0, 0x2219(r31)
/* 801345A8 00131188  54 00 CF FF */	rlwinm. r0, r0, 0x19, 0x1f, 0x1f
/* 801345AC 0013118C  40 82 00 2C */	bne lbl_801345D8
/* 801345B0 00131190  80 BF 05 E8 */	lwz r5, 0x5e8(r31)
/* 801345B4 00131194  38 83 00 00 */	addi r4, r3, 0
/* 801345B8 00131198  4C C6 31 82 */	crclr 6
/* 801345BC 0013119C  38 60 04 DF */	li r3, 0x4df
/* 801345C0 001311A0  80 A5 00 00 */	lwz r5, 0(r5)
/* 801345C4 001311A4  4B F2 B8 19 */	bl ef_Spawn
/* 801345C8 001311A8  88 1F 22 19 */	lbz r0, 0x2219(r31)
/* 801345CC 001311AC  38 60 00 01 */	li r3, 1
/* 801345D0 001311B0  50 60 3E 30 */	rlwimi r0, r3, 7, 0x18, 0x18
/* 801345D4 001311B4  98 1F 22 19 */	stb r0, 0x2219(r31)
lbl_801345D8:
/* 801345D8 001311B8  3C 60 80 06 */	lis r3, efLib_PauseAll@ha
/* 801345DC 001311BC  38 03 BA 40 */	addi r0, r3, efLib_PauseAll@l
/* 801345E0 001311C0  3C 60 80 06 */	lis r3, efLib_ResumeAll@ha
/* 801345E4 001311C4  90 1F 21 D4 */	stw r0, 0x21d4(r31)
/* 801345E8 001311C8  38 03 BA C4 */	addi r0, r3, efLib_ResumeAll@l
/* 801345EC 001311CC  90 1F 21 D8 */	stw r0, 0x21d8(r31)
/* 801345F0 001311D0  38 00 00 00 */	li r0, 0
/* 801345F4 001311D4  90 1F 21 BC */	stw r0, 0x21bc(r31)
/* 801345F8 001311D8  80 01 00 24 */	lwz r0, 0x24(r1)
/* 801345FC 001311DC  83 E1 00 1C */	lwz r31, 0x1c(r1)
/* 80134600 001311E0  38 21 00 20 */	addi r1, r1, 0x20
/* 80134604 001311E4  7C 08 03 A6 */	mtlr r0
/* 80134608 001311E8  4E 80 00 20 */	blr 
} // clang-format on
#pragma pop
