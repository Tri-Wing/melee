#include "melee/gr/stage.h"

extern struct _StageInfo stage_info;

extern f32 lbl_804DBCD0; // 0.017453f

f32 func_80224A54()
{
    return stage_info.cam_info.cam_bounds_left + stage_info.cam_info.cam_x_offset;
}

f32 func_80224A68()
{
    return stage_info.cam_info.cam_bounds_right + stage_info.cam_info.cam_x_offset;
}

f32 func_80224A80()
{
    return stage_info.cam_info.cam_bounds_top + stage_info.cam_info.cam_y_offset;
}

f32 func_80224A98()
{
    return stage_info.cam_info.cam_bounds_bottom + stage_info.cam_info.cam_y_offset;
}

f32 func_80224AB0()
{
    return lbl_804DBCD0 * stage_info.cam_info.cam_pan_degrees;
}

f32 func_80224AC8()
{
    return stage_info.cam_info.cam_max_depth;
}

f32 func_80224AD8()
{
    return stage_info.cam_info.cam_zoom_rate;
}