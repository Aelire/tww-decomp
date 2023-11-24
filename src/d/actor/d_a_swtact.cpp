//
// Generated by dtk
// Translation Unit: d_a_swtact.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"
#include "d/actor/d_a_player.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"

class daSwTact_c : public fopAc_ac_c {
public:
    bool _delete();
    BOOL CreateHeap();
    void CreateInit();
    void set_mtx();
    s32 getAnswer();
    s32 _create();
    bool _execute();
    bool _draw();

    inline f32 getR() { return mRadius * mScale.x; }

    static const char * m_arcname;
    static const f32 mDefaultR;
    static const f32 mDefaultRwM;
    static const u32 m_heapsize;

public:
    /* 0x290 */ request_of_phase_process_class mPhs;
    /* 0x298 */ J3DModel * model;
    /* 0x29C */ f32 mRadius;
    /* 0x2A0 */ u32 mSwitchNo;
    /* 0x2A4 */ u8 mAnswer;
    /* 0x2A5 */ bool mTrigger;
    /* 0x2A6 */ u8 mPlayerStatus;
    /* 0x2A7 */ u8 pad;
};

namespace daSwTact_prm {
    inline u32 getSwitchNo(daSwTact_c * i_this)  { return (fopAcM_GetParam(i_this) >> 0) & 0xFF; }
    inline u32 getAnswer(daSwTact_c * i_this)  { return (fopAcM_GetParam(i_this) >> 8) & 0xFF; }
    inline u32 getModel(daSwTact_c * i_this) { return (fopAcM_GetParam(i_this) >> 16) & 0x0F; }
}

const char * daSwTact_c::m_arcname = "Itact";
const f32 daSwTact_c::mDefaultR = 50.0f;
const f32 daSwTact_c::mDefaultRwM = 100.0f;
const u32 daSwTact_c::m_heapsize = 0x3000;

/* 00000078-000000AC       .text _delete__10daSwTact_cFv */
bool daSwTact_c::_delete() {
    dComIfG_resDelete(&mPhs, m_arcname);
    return true;
}

/* 000000AC-000000CC       .text CheckCreateHeap__FP10fopAc_ac_c */
s32 CheckCreateHeap(fopAc_ac_c* i_ac) {
    return ((daSwTact_c *)i_ac)->CreateHeap();
}

/* 000000CC-00000194       .text CreateHeap__10daSwTact_cFv */
BOOL daSwTact_c::CreateHeap() {
    J3DModelData * modelData = (J3DModelData *)dComIfG_getObjectRes(m_arcname, 3);
    JUT_ASSERT(0xe1, modelData != 0);
    model = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
    if (model == NULL)
        return FALSE;
    return TRUE;
}

/* 00000194-0000024C       .text CreateInit__10daSwTact_cFv */
void daSwTact_c::CreateInit() {
    static const f32 cull_size[] = {
        -120.0f, -10.0f, -120.0f,
        120.0f, 10.0f, 120.0f,
    };

    mSwitchNo = daSwTact_prm::getSwitchNo(this);
    mAnswer = daSwTact_prm::getAnswer(this);
    if (daSwTact_prm::getModel(this) == 1) {
        fopAcM_SetMtx(this, model->getBaseTRMtx());
        f32 scaleZ = mScale.z;
        f32 scaleX = mScale.x;
        fopAcM_setCullSizeBox(this, cull_size[0] * scaleX, cull_size[1], cull_size[2] * scaleZ, cull_size[3] * scaleX, cull_size[4], cull_size[5] * scaleZ);
        mRadius = 100.0f;
    } else {
        mRadius = 50.0f;
    }
}

/* 0000024C-000002CC       .text set_mtx__10daSwTact_cFv */
void daSwTact_c::set_mtx() {
    if (daSwTact_prm::getModel(this) == 1) {
        model->setBaseScale(mScale);
        mDoMtx_stack_c::transS(current.pos);
        model->setBaseTRMtx(mDoMtx_stack_c::get());
    }
}

/* 000002CC-0000038C       .text _create__10daSwTact_cFv */
s32 daSwTact_c::_create() {
    fopAcM_SetupActor(this, daSwTact_c);

    s32 result = cPhs_COMPLEATE_e;
    if (daSwTact_prm::getModel(this) == 1) {
        result = dComIfG_resLoad(&this->mPhs, m_arcname);

        if (result == cPhs_COMPLEATE_e) {
            if (!fopAcM_entrySolidHeap(this, (heapCallbackFunc)CheckCreateHeap, 0x3000)) {
                return cPhs_ERROR_e;
            }
        }
    }

    if (result == cPhs_COMPLEATE_e) {
        CreateInit();
    }

    return result;
}

/* 0000038C-00000410       .text getAnswer__10daSwTact_cFv */
s32 daSwTact_c::getAnswer() {
    switch (mAnswer) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 5;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 4;
    case 0xFF:
    default:
        return -1;
    }
}

/* 00000410-000006AC       .text _execute__10daSwTact_cFv */
bool daSwTact_c::_execute() {
    daPy_py_c * player = daPy_getPlayerActorClass();
    u32 stts1 = dComIfGp_checkPlayerStatus1(0, 0x01);

    if (player == NULL || dComIfGp_checkPlayerStatus0(0, 0x10000))
        return true;

    if ((player->current.pos - current.pos).absXZ() <= getR()) {
        if (mPlayerStatus != stts1 && stts1 != 0) {
            player->setTactZev(fopAcM_GetID(this), getAnswer(), NULL);
        }

        s32 tactMusic = player->getTactMusic();
        switch (mAnswer) {
        case 0:
            if (tactMusic == 0)
                mTrigger = true;
            break;
        case 1:
            if (tactMusic == 1)
                mTrigger = true;
            break;
        case 2:
            if (tactMusic == 5)
                mTrigger = true;
            break;
        case 3:
            if (tactMusic == 2)
                mTrigger = true;
            break;
        case 4:
            if (tactMusic == 3)
                mTrigger = true;
            break;
        case 5:
            if (tactMusic == 4)
                mTrigger = true;
            break;
        case 0xFF:
            if ((u32)tactMusic <= 4 || tactMusic == 5)
                mTrigger = true;
            break;
        }
    }

    if (mTrigger != 0 && !dComIfGp_event_runCheck()) {
        dComIfGs_onSwitch(mSwitchNo, fopAcM_GetHomeRoomNo(this));
        mTrigger = 0;
    }

    mPlayerStatus = stts1;
    set_mtx();

    return true;
}

/* 000006AC-00000720       .text _draw__10daSwTact_cFv */
bool daSwTact_c::_draw() {
    if (daSwTact_prm::getModel(this) == 0)
        return TRUE;

    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(model, &mTevStr);
    mDoExt_modelUpdateDL(model);
    return TRUE;
}

/* 00000720-00000740       .text daSwTact_Create__FPv */
s32 daSwTact_Create(void* i_ac) {
    return ((daSwTact_c *)i_ac)->_create();
}

/* 00000740-00000764       .text daSwTact_Delete__FPv */
BOOL daSwTact_Delete(void* i_ac) {
    return ((daSwTact_c*)i_ac)->_delete();
}

/* 00000764-00000788       .text daSwTact_Draw__FPv */
BOOL daSwTact_Draw(void* i_ac) {
    return ((daSwTact_c*)i_ac)->_draw();
}

/* 00000788-000007AC       .text daSwTact_Execute__FPv */
BOOL daSwTact_Execute(void* i_ac) {
    return ((daSwTact_c*)i_ac)->_execute();
}

/* 000007AC-000007B4       .text daSwTact_IsDelete__FPv */
BOOL daSwTact_IsDelete(void* i_ac) {
    return TRUE;
}

actor_method_class daSwTactMethodTable = {
    (process_method_func)daSwTact_Create,
    (process_method_func)daSwTact_Delete,
    (process_method_func)daSwTact_Execute,
    (process_method_func)daSwTact_IsDelete,
    (process_method_func)daSwTact_Draw,
};

actor_process_profile_definition g_profile_SW_TACT = {
    fpcLy_CURRENT_e,
    7,
    fpcPi_CURRENT_e,
    PROC_SW_TACT,
    &g_fpcLf_Method.mBase,
    sizeof(daSwTact_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x013B,
    &daSwTactMethodTable,
    fopAcStts_CULL_e | fopAcStts_UNK4000_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
