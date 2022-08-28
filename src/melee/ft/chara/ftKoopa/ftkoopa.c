#include <ftkoopa.h>

#include <melee/it/itkind.h>

extern void func_800BC7E0(HSD_GObj*, HSD_GObj*);
extern void func_800BC8D4(HSD_GObj*, HSD_GObj*);
extern void func_800DE7C0(HSD_GObj*, s32, s32);
extern void func_800DE2A8(HSD_GObj*, HSD_GObj*);


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

    Fighter_ActionStateChange_800693AC(fighterObj, 0x15B, 0, 0, 0.0F, 1.0F, 0.0F);

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

    Fighter_ActionStateChange_800693AC(fighterObj, 0x161, 0, 0, 0.0F, 1.0F, 0.0F);

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
        Fighter_ActionStateChange_800693AC(fighterObj, 349, 0x80, 0, 0.0F, 1.0F, 0.0F);
    } else {
        Fighter_ActionStateChange_800693AC(fighterObj, 348, 0x0, 0, 0.0F, 1.0F, 0.0F);
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
        Fighter_ActionStateChange_800693AC(fighterObj, 0x163, 0x80, 0, 0.0F, 1.0F, 0.0F);
    } else {
        Fighter_ActionStateChange_800693AC(fighterObj, 0x162, 0, 0, 0.0F, 1.0F, 0.0F);
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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x161, 0x0C4C5088, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);
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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15B, 0x0C4C5088, 0, ft2->x894_currentAnimFrame, 1.0F, 0.0F);
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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15C, 0x0C4C5088, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);
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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15E, 0x044C1080, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);
    func_8007E2F4(fp, 0x1FF);
    func_8007E2FC(fighterObj);
    func_8006F0FC(fighterObj, 0.0F);
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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x15F, 0x0C4C5088, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);

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
    Fighter_ActionStateChange_800693AC(fighterObj, 0x160, 0x0C4C5088, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);
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
                Fighter_ActionStateChange_800693AC(fighterObj, 0x15D, 0x80, 0, 0.0F, 1.0F, 0.0F);
            } else {
                Fighter_ActionStateChange_800693AC(fighterObj, 0x15C, 0, 0, 0.0F, 1.0F, 0.0F);
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
        Fighter_ActionStateChange_800693AC(fighterObj, 0x15E, 0x80080, 0, fp->x894_currentAnimFrame, 1.0F, 0.0F);
        func_8006F0FC(fighterObj, 0.0F);
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
        temp_f1 = 0.0F;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x163, 0x80, (void*) 0, temp_f1, 1.0F, temp_f1);
    } else {
        temp_f1_2 = 0.0F;
        Fighter_ActionStateChange_800693AC(fighterObj, 0x162, 0, (void*) 0, temp_f1_2, 1.0F, temp_f1_2);
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
        Fighter_ActionStateChange_800693AC(fighterObj, 0x164, 0x80080, 0, fp_temp2->x894_currentAnimFrame, 1.0F, 0.0F);
        func_8006F0FC(fighterObj, 0.0F);
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

//https://decomp.me/scratch/g5XlQ int to float constant incorrect
inline void ftKoopa_SpecialS_ChangeAction(HSD_GObj* arg0, s32 kpStateR, s32 victimStateR, s32 kpStateL, s32 victimStateL)
{
    Fighter* fp = fp = getFighter(arg0);
    fp->x2210_ThrowFlags.flags = 0;
    fp->x2200_ftcmd_var0 = 0;
    if ((fp->x2348_stateVar3_s32) == 1) {
        Fighter_ActionStateChange_800693AC(arg0, kpStateR, 0x80000, 0, 0.0f, 1.0f, 0.0f);
        func_800BCDE0(fp->x1A58_interactedFighter, victimStateR);
        return;
    }
    Fighter_ActionStateChange_800693AC(arg0, kpStateL, 0x80000, 0, 0.0f, 1.0f, 0.0f);
    func_800BCDE0(fp->x1A58_interactedFighter, victimStateL);
}

void lbl_80133BF4(HSD_GObj* arg0)
{
    f32 unused[2];
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    s32 facingDir;
    ftKoopaAttributes* koopaAttr;
    Fighter* fp = fp = getFighter(arg0);
    koopaAttr = koopaAttr = getFtSpecialAttrsD(fp);
    facingDir = 0;
    if (fp->input.x668 & HSD_BUTTON_B) {
        fp->x2340_stateVar1 = 1;
    }
    temp_f2 = koopaAttr->x30;
    temp_f3 = fp->input.x628_lstick_x2;
    temp_f1 = -temp_f2;
    if ((temp_f3 > temp_f1) && (fp->input.x620_lstick_x < (-temp_f2))) {
        facingDir = -1;
    }
    if ((temp_f3 < temp_f2) && (fp->input.x620_lstick_x > temp_f2)) {
        facingDir = 1;
    }
    fp->x2348_stateVar3_s32 = fp->x2C_facing_direction * facingDir;

    if (facingDir != 0) {
        ftKoopa_SpecialS_ChangeAction(arg0, 0x15f, 0x119, 0x160, 0x11a);
    }
}