//
// Generated by dtk
// Translation Unit: d_a_obj_dragonhead.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "d/d_cc_d.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

class daObjDragonhead_c : public fopAc_ac_c {
public:
    inline s32 _create();
    inline bool _execute();
    inline bool _draw();
    inline bool _delete();
    BOOL CreateHeap();
    void CreateInit();
    void set_mtx();

public:
    /* 0x290 */ request_of_phase_process_class mPhs;
    /* 0x298 */ J3DModel * mpModel;
    /* 0x29C */ dCcD_Stts mStts;
    /* 0x2D8 */ dCcD_Sph mSph;
    /* 0x404 */ u8 mAlpha;
    /* 0x405 */ bool mSwitchOn;
    /* 0x408 */ dBgW * mpBgW;
    /* 0x40C */ u8 field_0x40c;
    /* 0x410 */ cXyz mSphCenter;
    /* 0x41C */ Mtx mtx;
};

dCcD_SrcSph sph_check_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ AT_TYPE_FIRE_ARROW,
        /* SrcObjTg SPrm     */ 0x09,
        /* SrcObjCo SPrm     */ 0,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGSphS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 1000.0f,
    },
};

/* 00000078-00000098       .text CheckCreateHeap__FP10fopAc_ac_c */
BOOL CheckCreateHeap(fopAc_ac_c* i_this) {
    return ((daObjDragonhead_c*)i_this)->CreateHeap();
}

namespace daObjDragonhead_prm {
    inline u8 getSwitchNo(daObjDragonhead_c* ac) { return (fopAcM_GetParam(ac) >> 8) & 0xFF; }
};

/* 00000098-00000228       .text CreateHeap__17daObjDragonhead_cFv */
BOOL daObjDragonhead_c::CreateHeap() {
    J3DModelData* model_data = (J3DModelData*)(dComIfG_getObjectRes("Qdghd", 0x04));
    JUT_ASSERT(0xA0, model_data != 0);
    mpModel = mDoExt_J3DModel__create(model_data, 0x00, 0x11020203);
    if (!mpModel)
        return FALSE;

    s32 ret = 1;

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    mDoMtx_stack_c::scaleM(mScale);
    mDoMtx_copy(mDoMtx_stack_c::get(), mtx);

    mpBgW = new dBgW();
    if (!mpBgW || mpBgW->Set((cBgD_t*)dComIfG_getObjectRes("Qdghd", 0x07), cBgW::MOVE_BG_e, &mtx))
        ret = 0;

    if (ret != 1)
        return false;

    return mpModel != NULL;
}

/* 00000228-0000034C       .text CreateInit__17daObjDragonhead_cFv */
void daObjDragonhead_c::CreateInit() {
    fopAcM_SetMtx(this, mpModel->getBaseTRMtx());
    fopAcM_setCullSizeFar(this, 1.0f);
    set_mtx();

    field_0x40c = 0;
    /* Nonmatching -- swapped switchNo and g_dComIfG_gameInfo load */
    if (dComIfGs_isSwitch(daObjDragonhead_prm::getSwitchNo(this), fopAcM_GetHomeRoomNo(this))) {
        mSwitchOn = true;
        mAlpha = 0;
    } else {
        mSwitchOn = false;
        mAlpha = 0xFF;
        if (field_0x40c == 0 && !dComIfG_Bgsp()->Regist(mpBgW, this))
            field_0x40c = 1;
    }

    mStts.Init(0xFF, 0xFF, this);
    mSph.Set(sph_check_src);
    mSphCenter.set(79338.0f, 950.0f, 220000.0f);
    mSph.SetC(mSphCenter);
    mSph.SetStts(&mStts);
}

/* 0000034C-000003CC       .text set_mtx__17daObjDragonhead_cFv */
void daObjDragonhead_c::set_mtx() {
    mpModel->setBaseScale(mScale);
    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(current.angle.y);
    mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

s32 daObjDragonhead_c::_create() {
    fopAcM_SetupActor(this, daObjDragonhead_c);

    s32 ret = dComIfG_resLoad(&mPhs, "Qdghd");

    if (ret == cPhs_COMPLEATE_e) {
        if (fopAcM_entrySolidHeap(this, (heapCallbackFunc)CheckCreateHeap, 0x10500) == 0) {
            ret = cPhs_ERROR_e;
        } else {
            CreateInit();
        }
    }

    return ret;
}

bool daObjDragonhead_c::_delete() {
    if (heap != NULL && field_0x40c == 1)
        dComIfG_Bgsp()->Release(mpBgW);

    mDoAud_seDeleteObject(&mSphCenter);
    dComIfG_resDelete(&mPhs, "Qdghd");
    return true;
}

bool daObjDragonhead_c::_execute() {
    dComIfG_Ccsp()->Set(&mSph);
    if (!mSwitchOn) {
        mDoAud_seStart(JA_SE_OBJ_ICEBERG_BREATH, &mSphCenter, 0, dComIfGp_getReverb(fopAcM_GetRoomNo(this)));
        if (mSph.ChkTgHit()) {
            cCcD_Obj* at = mSph.GetTgHitObj();
            if (at != NULL && at->ChkAtType(AT_TYPE_FIRE_ARROW)) {
                dComIfGs_onSwitch(daObjDragonhead_prm::getSwitchNo(this), fopAcM_GetHomeRoomNo(this));
                mSwitchOn = true;
            }
        }
    }

    /* Nonmatching -- swapped switchNo and g_dComIfG_gameInfo load */
    if (dComIfGs_isSwitch(daObjDragonhead_prm::getSwitchNo(this), fopAcM_GetHomeRoomNo(this))) {
        if (field_0x40c == 1) {
            if (!dComIfG_Bgsp()->Release(mpBgW))
                field_0x40c = 0;

            mDoAud_seStart(JA_SE_OBJ_ICEVERG_MELT, &mEyePos, 0, dComIfGp_getReverb(fopAcM_GetRoomNo(this)));
        }

        if (mAlpha != 0) {
            if (mAlpha >= 2)
                mAlpha -= 2;
            else
                mAlpha = 0;
        }
    } else {
        mSwitchOn = false;
        if (field_0x40c == 0 && !dComIfG_Bgsp()->Regist(mpBgW, this))
            field_0x40c = 1;

        if (mAlpha < 0xFF) {
            if (mAlpha <= 0xFD)
                mAlpha += 2;
            else
                mAlpha = 0xFF;
        }
    }

    set_mtx();
    return true;
}

bool daObjDragonhead_c::_draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, &current.pos, &mTevStr);
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    dComIfGd_setListBG();
    J3DModelData* modelData = mpModel->getModelData();
    u16 materialNum = modelData->getMaterialNum();
    for (u16 i = 0; i < materialNum; i++) {
        J3DMaterial* mat = modelData->getMaterialNodePointer(i);
        mat->getTevKColor(3)->mColor.a = mAlpha;
    }
    mDoExt_modelUpdateDL(mpModel);
    dComIfGd_setList();
    return true;
}

/* 000003CC-000004FC       .text daObjDragonhead_Create__FPv */
s32 daObjDragonhead_Create(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_create();
}

/* 000006B4-00000730       .text daObjDragonhead_Delete__FPv */
BOOL daObjDragonhead_Delete(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_delete();
}

/* 00000730-00000824       .text daObjDragonhead_Draw__FPv */
BOOL daObjDragonhead_Draw(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_draw();
}

/* 00000824-00000A48       .text daObjDragonhead_Execute__FPv */
BOOL daObjDragonhead_Execute(void* i_this) {
    return ((daObjDragonhead_c*)i_this)->_execute();
}

/* 00000A48-00000A50       .text daObjDragonhead_IsDelete__FPv */
BOOL daObjDragonhead_IsDelete(void* i_this) {
    return TRUE;
}

static actor_method_class daObj_DragonheadMethodTable = {
    (process_method_func)daObjDragonhead_Create,
    (process_method_func)daObjDragonhead_Delete,
    (process_method_func)daObjDragonhead_Execute,
    (process_method_func)daObjDragonhead_IsDelete,
    (process_method_func)daObjDragonhead_Draw,
};

actor_process_profile_definition g_profile_Obj_Dragonhead = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 3,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_Obj_Dragonhead,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daObjDragonhead_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x0025,
    /* Actor SubMtd */ &daObj_DragonheadMethodTable,
    /* Status       */ fopAcStts_UNK40000_e | fopAcStts_UNK4000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_CUSTOM_e,
};
