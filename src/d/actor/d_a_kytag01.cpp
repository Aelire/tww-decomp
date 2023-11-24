//
// Generated by dtk
// Translation Unit: d_a_kytag01.cpp
//

#include "d/actor/d_a_kytag01.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"

/* 00000078-0000007C       .text wether_tag_move__FP13kytag01_class */
void wether_tag_move(kytag01_class* i_this) {
}

/* 0000007C-00000084       .text daKytag01_Draw__FP13kytag01_class */
BOOL daKytag01_Draw(kytag01_class* i_this) {
    return TRUE;
}

/* 00000084-000000A8       .text daKytag01_Execute__FP13kytag01_class */
BOOL daKytag01_Execute(kytag01_class* i_this) {
    wether_tag_move(i_this);
    return TRUE;
}

/* 000000A8-000000B0       .text daKytag01_IsDelete__FP13kytag01_class */
BOOL daKytag01_IsDelete(kytag01_class* i_this) {
    return TRUE;
}

/* 000000B0-00000100       .text daKytag01_Delete__FP13kytag01_class */
BOOL daKytag01_Delete(kytag01_class* i_this) {
    dScnKy_env_light_c& env_light = dKy_getEnvlight();
    for (u32 i = 0; i < 10; i++) {
        if (env_light.mpWaveInfl[i] == &i_this->mWaveInfo)
            env_light.mpWaveInfl[i] = NULL;
    }
    dKy_getEnvlight().mWaveChan.mWaveCount = 0;
    return TRUE;
}

/* 00000100-00000224       .text wave_make__Fv */
void wave_make() { 
    dScnKy_env_light_c& env_light = dKy_getEnvlight();
    if (env_light.mWaveChan.mWaveCount == 0) {
        env_light.mWaveChan.mWaveSpawnDist = 20000.0f;
        env_light.mWaveChan.mWaveSpawnRadius = 22000.0f;
        env_light.mWaveChan.mWaveReset = 0;
        env_light.mWaveChan.mWaveScale = 300.0f;
        env_light.mWaveChan.mWaveScaleRand = 0.001f;
        env_light.mWaveChan.mWaveCounterSpeedScale = 1.2f;
        env_light.mWaveChan.field_0x2f = 0;
        env_light.mWaveChan.mWaveScaleBottom = 6.0f;
        env_light.mWaveChan.mWaveCount = 300;
        env_light.mWaveChan.mWaveSpeed = 30.0f;
        env_light.mWaveChan.mWaveFlatInter = 0.0f;
        if (strcmp(dComIfGp_getStartStageName(), "MajyuE") == 0) {
            env_light.mWaveChan.mWaveSpawnDist = 25000.0f;
            env_light.mWaveChan.mWaveSpawnRadius = 27000.0f;
            env_light.mWaveChan.mWaveScaleBottom = 8.0f;
        }
        if (strcmp(dComIfGp_getStartStageName(), "M_NewD2") == 0) {
            env_light.mWaveChan.mWaveSpawnDist = 35000.0f;
            env_light.mWaveChan.mWaveSpawnRadius = 37000.0f;
            env_light.mWaveChan.mWaveScaleBottom = 8.0f;
            env_light.mWaveChan.mWaveCounterSpeedScale = 1.5f;
            env_light.mWaveChan.mWaveScale = 500.0f;
            env_light.mWaveChan.mWaveSpeed = 55.0f;
        }
    }
}

/* 00000224-00000318       .text daKytag01_Create__FP10fopAc_ac_c */
s32 daKytag01_Create(fopAc_ac_c* i_ac) {
    dScnKy_env_light_c& env_light = dKy_getEnvlight();
    kytag01_class* i_this = (kytag01_class*)i_ac;
    fopAcM_SetupActor(i_this, kytag01_class);

    i_this->mWaveInfo.mPos = i_this->current.pos;
    i_this->mWaveInfo.mInnerRadius = i_this->mScale.x * 5000.0f;
    i_this->mWaveInfo.mOuterRadius = i_this->mScale.z * 5000.0f;

    f32 defaultOuter = i_this->mWaveInfo.mInnerRadius + 500.0f;
    if (defaultOuter >= i_this->mWaveInfo.mOuterRadius)
        i_this->mWaveInfo.mOuterRadius = defaultOuter;

    for (u32 i = 0; i < 10; i++) {
        if (env_light.mpWaveInfl[i] == NULL) {
            env_light.mpWaveInfl[i] = &i_this->mWaveInfo;
            break;
        }
    }

    wave_make();
    return cPhs_COMPLEATE_e;
}

static actor_method_class l_daKytag01_Method = {
    (process_method_func)daKytag01_Create,
    (process_method_func)daKytag01_Delete,
    (process_method_func)daKytag01_Execute,
    (process_method_func)daKytag01_IsDelete,
    (process_method_func)daKytag01_Draw,
};

actor_process_profile_definition g_profile_KYTAG01 = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_KYTAG01,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(kytag01_class),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00A1,
    /* Actor SubMtd */ &l_daKytag01_Method,
    /* Status       */ fopAcStts_UNK40000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
