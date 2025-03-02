#include <fticeclimber.h>

/// TODO remove float externs when file is finished and float data is removed from asm
extern f32 lbl_804D9898;


void ftNana_OnLoad(HSD_GObj* fighterObj) {
    s32 unused[4];
    Fighter* fp = fighterObj->user_data;
    fp->x2222_flag.bits.b4 = 1;
    ftIceClimber_OnLoadForNana(fp);

    {
        ftIceClimberAttributes* attr = fp->x2D4_specialAttributes;
        fp->x40 = attr->xC4;
    }

}

void ftNana_OnDeath(HSD_GObj* fighterObj) {
    s32 unused;
    Fighter* fp = fighterObj->user_data;
    ftIceClimberAttributes* attr = fp->x2D4_specialAttributes;
    fp->dmg.x18B0 = attr->xC8;
    func_80074A4C(fighterObj, 0U, 0);
    func_80074A4C(fighterObj, 1U, 0);
    fp->sa.nana.x2234 = 0;
    fp->sa.nana.x222C = 0;
    fp->sa.nana.x2230.bits.b0 = 0;
    fp->sa.nana.x2238 = 0;
    fp->sa.nana.x224C = 0;
    fp->sa.nana.x2250 = lbl_804D9898;
}

void ftNana_80122FAC(HSD_GObj* fighterObj) {
    func_801238E4(fighterObj);
}

void ftNana_LoadSpecialAttrs(HSD_GObj* fighterObj) {
    COPY_ATTRS(fighterObj, ftIceClimberAttributes);
}
