//
// Generated by dtk
// Translation Unit: d_a_item.cpp
//

#include "d/d_item.h"
#include "d/d_item_data.h"
#include "d/actor/d_a_itembase_static.h"
#include "d/actor/d_a_item.h"
#include "d/actor/d_a_player_link.h"
#include "d/d_com_inf_game.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_mtx.h"
#include "f_op/f_op_camera_mng.h"
#include "dolphin/types.h"

class dCcD_GObjInf;

// Needed for the .data section to match.
static f32 dummy1[3] = {1.0f, 1.0f, 1.0f};
static f32 dummy2[3] = {1.0f, 1.0f, 1.0f};

s32 daItem_c::m_timer_max = 10000;

/* 800F4BC8-800F4BD4       .text getData__12daItemBase_cFv */
daItemBase_c_m_data* daItemBase_c::getData() {
    return &daItemBase_c::m_data;
}

/* 800F4BD4-800F4C4C       .text setArrowTrans__Fs4cXyz */
cXyz setArrowTrans(s16 yRot, cXyz offset) {
    cXyz arrowTrans = offset;
    mDoMtx_stack_c::YrotS(yRot);
    mDoMtx_stack_c::multVec(&arrowTrans, &arrowTrans);
    return arrowTrans;
}

/* 800F4C4C-800F4CD8       .text getYOffset__8daItem_cFv */
float daItem_c::getYOffset() {
    switch (m_itemNo) {
    case HEART:
        return 0.0f;
    case SKULL_NECKLACE:
        return 0.0f;
    case BOKOBABA_SEED:
        return 0.0f;
    case GOLDEN_FEATHER:
        return 0.0f;
    case BOKO_BELT:
        return 0.0f;
    case RED_JELLY:
    case GREEN_JELLY:
    case BLUE_JELLY:
        return 0.0f;
    case SHIELD:
        return 23.0f;
    case SWORD:
        return 20.0f;
    case DROPPED_SWORD:
        return 10.0f;
    case GREEN_RUPEE:
    case BLUE_RUPEE:
    case YELLOW_RUPEE:
    case RED_RUPEE:
    case PURPLE_RUPEE:
    case ORANGE_RUPEE:
    case SILVER_RUPEE:
        return 0.0f;
    case KAKERA_HEART:
    case UTUWA_HEART:
        return 0.0f;
    case SMALL_KEY:
    case BOSS_KEY:
        return 0.0f;
    default:
        return 0.0f;
    }
}

/* 800F4CD8-800F4E6C       .text set_mtx__8daItem_cFv */
void daItem_c::set_mtx() {
    cXyz pos = current.pos;
    csXyz rot = current.angle;
    if (m_itemNo == UTUWA_HEART) {
        rot.y = shape_angle.y;
    }
    set_mtx_base(mpModel, pos, rot);
    
    if (isArrow(m_itemNo)) {
        cXyz offset(5.0f, 0.0f, 10.0f);
        cXyz arrowTrans = setArrowTrans(current.angle.y, offset);
        
        pos += arrowTrans;
        set_mtx_base(mpModelArrow[0], pos, rot);
        
        pos += arrowTrans;
        set_mtx_base(mpModelArrow[1], pos, rot);
    }
}

/* 800F4E6C-800F4FDC       .text set_mtx_base__8daItem_cFP8J3DModel4cXyz5csXyz */
void daItem_c::set_mtx_base(J3DModel* pModel, cXyz pos, csXyz rot) {
    if (!pModel) {
        return;
    }
    
    pModel->setBaseScale(mScale);
    
    mDoMtx_stack_c::transS(pos.x, pos.y + getYOffset(), pos.z);
    
    if (isRupee(m_itemNo)) {
        u8 height = dItem_data::getH(m_itemNo);
        mDoMtx_stack_c::transM(0.0f, height/2.0f, 0.0f);
    }
    
    mDoMtx_stack_c::ZXYrotM(rot.x, rot.y, rot.z + mExtraZRot);
    
    if (isRupee(m_itemNo)) {
        u8 height = dItem_data::getH(m_itemNo);
        mDoMtx_stack_c::transM(0.0f, -height/2.0f, 0.0f);
    }
    
    pModel->setBaseTRMtx(mDoMtx_stack_c::get());
}

/* 800F4FDC-800F5044       .text itemGetCallBack__FP10fopAc_ac_cP12dCcD_GObjInfP10fopAc_ac_cP12dCcD_GObjInf */
void itemGetCallBack(fopAc_ac_c* item_actor, dCcD_GObjInf*, fopAc_ac_c* collided_actor, dCcD_GObjInf*) {
    daItem_c* item = (daItem_c*)item_actor;
    daPy_lk_c* link = daPy_getPlayerLinkActorClass();
    if (item && item->checkPlayerGet() && collided_actor && collided_actor == link) {
        item->itemGetExecute();
    }
}

/* 800F5044-800F53EC       .text CreateInit__8daItem_cFv */
void daItem_c::CreateInit() {
    mAcchCir.SetWall(30.0f, 30.0f);
    cXyz* speedPtr;
    mAcch.Set(&current.pos, &next.pos, this, 1, &mAcchCir, speedPtr = &speed, NULL, NULL);
    mAcch.m_flags &= ~0x400;
    mAcch.m_flags &= ~0x8;
    mCullMtx = mpModel->mBaseTransformMtx;
    mStts.Init(0, 0xFF, this);
    mCyl.Set(m_cyl_src);
    mCyl.SetStts(&mStts);
    mCyl.SetCoHitCallback(&itemGetCallBack);
    
    // Regswaps if the inlines are used.
    // f32 height = dItem_data::getH(m_itemNo);
    // f32 radius = dItem_data::getR(m_itemNo);
    f32 height = dItem_data::item_info[m_itemNo].mCollisionH;
    f32 radius = dItem_data::item_info[m_itemNo].mCollisionR;
    if (mScale.x > 1.0f) {
        height *= mScale.x;
        radius *= mScale.x;
    }
    mCyl.SetR(radius);
    mCyl.SetH(height);
    
    mItemTimer = getData()->mDuration;
    field_0x65a = getData()->field_0x18;
    field_0x650 = speedPtr->y;
    mCurState = 0;
    
    mType = daItem_prm::getType(this);
    if (daItem_prm::getType(this) == 3 || daItem_prm::getType(this) == 1) {
        mStatusFlags |= 2;
    }
    mAction = daItem_prm::getAction(this);
    
    show();
    
    if (dItem_data::checkSpecialEffect(m_itemNo) && (m_itemNo != SMALL_KEY || (m_itemNo == SMALL_KEY && (mStatusFlags & 2)))) {
        u16 particleID = dItem_data::getSpecialEffect(m_itemNo);
        dComIfGp_particle_set(particleID, &current.pos, NULL, NULL, 0xFF, &mPtclFollowCb);
    }
    
    switch (m_itemNo) {
    case BOMB_5:
    case BOMB_10:
    case BOMB_20:
    case BOMB_30:
        mScaleTarget.x = 0.6f;
        mScaleTarget.y = 0.6f;
        mScaleTarget.z = 0.6f;
        break;
    default:
        mScaleTarget.x = 1.0f;
        mScaleTarget.y = 1.0f;
        mScaleTarget.z = 1.0f;
        break;
    }
    
    mSwitchId = daItem_prm::getSwitchNo2(this);
    if (mSwitchId != 0xFF && !fopAcM_isSwitch(this, mSwitchId)) {
        hide();
        mStatusFlags |= 2;
    }
    mActivationSwitch = daItem_prm::getSwitchNo(this);
    
    current.angle.z = 0;
    orig.angle.z = 0;
    initAction();
    
    switch (m_itemNo) {
    case SWORD:
    case SHIELD:
        mStatus |= 0x4000;
        break;
    case DROPPED_SWORD:
        current.angle.x = 0x4000;
        break;
    }
    
    set_mtx();
    animPlay(1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    
    if (fopAcM_SearchByName(PROC_BST)) { // Gohdan
        mpParticleEmitter = dComIfGp_particle_set(0x81E1, &current.pos);
    }
}

/* 800F53EC-800F5668       .text _daItem_create__8daItem_cFv */
s32 daItem_c::_daItem_create() {
    fopAcM_SetupActor(this, daItem_c);
    
    m_itemNo = daItem_prm::getItemNo(this);
    
    if (!dItem_data::getFieldArc(m_itemNo)) {
        setLoadError();
        return cPhs_ERROR_e;
    }
    
    mPickupFlag = daItem_prm::getItemBitNo(this);
    if (m_itemNo != BLUE_JELLY) { // Blue Chu Jelly uses mPickupFlag as if it was a switch.
        mPickupFlag &= 0x7F;
        if (dComIfGs_isItem(mPickupFlag, orig.roomNo) && mPickupFlag != 0x7F) {
            // Already picked up, don't create the item again.
            setLoadError();
            return cPhs_ERROR_e;
        }
    }
    
    s32 phase_state = dComIfG_resLoad(&mPhs, dItem_data::getFieldArc(m_itemNo));
    if (phase_state == cPhs_COMPLEATE_e) {
        // Note: The demo version calls getHeapSize instead of getFieldHeapSize here.
        u32 heap_size = dItem_data::getFieldHeapSize(m_itemNo);
        if (!fopAcM_entrySolidHeap(this, &CheckFieldItemCreateHeap, heap_size)) {
            return cPhs_ERROR_e;
        }
        CreateInit();
    }
    
    return phase_state;
}

/* 800F5668-800F5834       .text _daItem_execute__8daItem_cFv */
BOOL daItem_c::_daItem_execute() {
    if (mSwitchId != 0xFF && !fopAcM_isSwitch(this, mSwitchId)) {
        return TRUE;
    }
    if (mSwitchId != 0xFF && fopAcM_isSwitch(this, mSwitchId)) {
        show();
    }
    
    timeCount();
    
    mEyePos = current.pos;
    mEyePos.y += dItem_data::getH(m_itemNo)/2.0f;
    mAttentionInfo.mPosition = current.pos;
    
    switch (mCurState) {
    case 3:
        execBringNezumi();
        break;
    case 0:
    case 1:
        if (checkActionNow()) {
            mCurState = 1;
        } else {
            mCurState = 0;
        }
    case 2:
        execWaitMain();
        break;
    case 5:
        execInitNormalDirection();
    case 6:
        execMainNormalDirection();
        break;
    case 7:
        execInitGetDemoDirection();
        break;
    case 8:
        execWaitGetDemoDirection();
        break;
    case 9:
        execMainGetDemoDirection();
        break;
    case 0xA:
    case 0xB:
        execWaitMainFromBoss();
        break;
    }
    
    animPlay(1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    set_mtx();
    
    return TRUE;
}

/* 800F5834-800F59CC       .text mode_proc_call__8daItem_cFv */
void daItem_c::mode_proc_call() {
    static daItem_c_ModeFunc mode_proc[] = {
        &mode_wait,
        &mode_wait,
        &mode_water,
    };
    
    if (mType == 1) {
        itemDefaultRotateY();
    } else {
        (this->*mode_proc[mMode])();
    }
    
    if (mStatusFlags & 0x08) {
        fopAc_ac_c* boomerang = (fopAc_ac_c*)fopAcM_SearchByName(PROC_BOOMERANG);
        if (boomerang) {
            current.pos = boomerang->current.pos;
        } else {
            mStatusFlags &= ~0x08;
        }
    }
    
    if (mStatusFlags & 0x40) {
        fopAc_ac_c* grappling_hook = (fopAc_ac_c*)fopAcM_SearchByName(PROC_HIMO2);
        if (grappling_hook) {
            current.pos = grappling_hook->current.pos;
        } else {
            mStatusFlags &= ~0x40;
        }
    }
    
    if (mType == 1 && (fopAcM_checkHookCarryNow(this) || mStatusFlags & 0x08)) {
        mType = 3;
    }
}

/* 800F59CC-800F5AFC       .text execInitNormalDirection__8daItem_cFv */
void daItem_c::execInitNormalDirection() {
    daPy_py_c* player = daPy_getPlayerActorClass();
    cXyz headPos = player->getHeadTopPos();
    headPos.y += 15.0f;
    current.pos = headPos;
    current.angle.z = 0;
    current.angle.x = 0;
    mScale.set(mScaleTarget.x, mScaleTarget.y, mScaleTarget.z);
    mExtraZRot = 0;
    
    field_0x65c = getData()->field_0x40;
    f32 speedY = getData()->mPickedUpInitialSpeedY;
    speed.set(0.0f, speedY, 0.0f);
    mGravity = getData()->mPickedUpGravity;
    
    show();
    
    mCyl.SetTgType(0);
    mCyl.OffCoSPrmBit(1);
    
    mPtclSmokeCb.end();
    if (mpParticleEmitter) {
        mpParticleEmitter->becomeInvalidEmitter();
        mpParticleEmitter = NULL;
    }
    
    mCurState = 6;
}

/* 800F5AFC-800F5BC8       .text execMainNormalDirection__8daItem_cFv */
void daItem_c::execMainNormalDirection() {
    daPy_py_c* player = daPy_getPlayerActorClass();
    cXyz headPos = player->getHeadTopPos();
    headPos.y += 15.0f;
    current.pos.x = headPos.x;
    current.pos.z = headPos.z;
    fopAcM_posMoveF(this, NULL);
    if (current.pos.y < headPos.y) {
        current.pos.y = headPos.y;
    }
    
    current.angle = dComIfGp_getCamera(0)->mAngle;
    
    field_0x65c--;
    if (field_0x65c < 0) {
        fopAcM_delete(this);
    }
}

/* 800F5BC8-800F5C68       .text execInitGetDemoDirection__8daItem_cFv */
void daItem_c::execInitGetDemoDirection() {
    fopAc_ac_c* player = daPy_getPlayerActorClass();
    daPy_lk_c* link = daPy_getPlayerLinkActorClass();
    
    hide();
    mPtclFollowCb.end();
    
    if (player == link) {
        fopAcM_orderItemEvent(this);
        mEvtInfo.onCondition(dEvtCnd_CANGETITEM_e);
        mDemoItemBsPcId = fopAcM_createItemForTrBoxDemo(&current.pos, m_itemNo, -1, current.roomNo, NULL, NULL);
        mCurState = 8;
    }
}

/* 800F5C68-800F5CDC       .text execWaitGetDemoDirection__8daItem_cFv */
void daItem_c::execWaitGetDemoDirection() {
    hide();
    
    if (mEvtInfo.checkCommandItem()) {
        mCurState = 9;
        if (mDemoItemBsPcId != -1) {
            dComIfGp_event_setItemPartnerId(mDemoItemBsPcId);
        }
    } else {
        fopAcM_orderItemEvent(this);
        mEvtInfo.onCondition(dEvtCnd_CANGETITEM_e);
    }
}

/* 800F5CDC-800F5D44       .text execMainGetDemoDirection__8daItem_cFv */
void daItem_c::execMainGetDemoDirection() {
    hide();
    
    if (dComIfGp_evmng_endCheck("DEFAULT_GETITEM")) {
        dComIfGp_event_reset();
        fopAcM_delete(this);
    }
}

/* 800F5D44-800F5D88       .text execBringNezumi__8daItem_cFv */
void daItem_c::execBringNezumi() {
    if (mType != 1) {
        fopAcM_posMoveF(this, mStts.GetCCMoveP());
    }
    mode_proc_call();
}

/* 800F5D88-800F5F40       .text execWaitMain__8daItem_cFv */
void daItem_c::execWaitMain() {
    checkGetItem();
    if (mType != 1) {
        fopAcM_posMoveF(this, mStts.GetCCMoveP());
    }
    mode_proc_call();
    
    if (!(mStatusFlags & 0x02)) {
        f32 temp1 = mScaleTarget.x / getData()->mScaleAnimSpeed;
        f32 temp2 = mScaleTarget.y / getData()->mScaleAnimSpeed;
        f32 temp3 = mScaleTarget.z / getData()->mScaleAnimSpeed;
        cLib_chaseF(&mScale.x, mScaleTarget.x, temp1);
        cLib_chaseF(&mScale.y, mScaleTarget.y, temp2);
        cLib_chaseF(&mScale.z, mScaleTarget.z, temp3);
    }
    
    if (checkItemDisappear() && mItemTimer == 0) {
        if (field_0x65a == 0) {
            fopAcM_delete(this);
        }
        s32 temp1 = getData()->field_0x14;
        s32 temp2 = field_0x634 / temp1;
        if (!(field_0x634 - temp2 * temp1)) {
            changeDraw();
        }
    }
    
    if (!dItem_data::chkFlag(m_itemNo, 2)) {
        if (mActivationSwitch == 0xFF || (mActivationSwitch != 0xFF && fopAcM_isSwitch(this, mActivationSwitch))) {
            mCyl.SetC(current.pos);
            dComIfG_Ccsp()->Set(&mCyl);
        }
    }
}

/* 800F5F40-800F5FC0       .text execWaitMainFromBoss__8daItem_cFv */
void daItem_c::execWaitMainFromBoss() {
    checkGetItem();
    if (mType != 1) {
        fopAcM_posMoveF(this, mStts.GetCCMoveP());
    }
    mode_proc_call();
    
    if (mCurState != 0xB) {
        scaleAnimFromBossItem();
    }
    
    mCyl.SetC(current.pos);
    dComIfG_Ccsp()->Set(&mCyl);
}

/* 800F5FC0-800F60C0       .text scaleAnimFromBossItem__8daItem_cFv */
void daItem_c::scaleAnimFromBossItem() {
    if (field_0x638 < 30) {
        mScale.x = cM_ssin(field_0x634*0x2000 - 0x4000)*2.0f / field_0x634+1.0f;
        if (mScale.x < 0.0f) {
            mScale.x = 0.0f;
        }
        mScale.y = mScale.x;
        mScale.z = mScale.x;
    } else {
        if (field_0x638 == 30) {
            fopAcM_seStart(this, JA_SE_CM_BOSS_HEART_APPEAR, 0);
        }
        mScale.setAll(1.0f);
    }
}

/* 800F60C0-800F6110       .text _daItem_draw__8daItem_cFv */
BOOL daItem_c::_daItem_draw() {
    if (chkDraw()) {
        return DrawBase();
    }
    return TRUE;
}

/* 800F6110-800F61C8       .text setTevStr__8daItem_cFv */
void daItem_c::setTevStr() {
    g_env_light.settingTevStruct(TEV_TYPE_ACTOR, getPositionP(), &mTevStr);
    
    mTevStr.mColorC0.r = 0x96;
    mTevStr.mColorC0.g = 0x96;
    mTevStr.mColorC0.b = 0x96;
    mTevStr.mColorK0.r = 0xFF;
    mTevStr.mColorK0.g = 0xFF;
    mTevStr.mColorK0.b = 0xFF;
    g_env_light.setLightTevColorType(mpModel, &mTevStr);
    
    for (int i = 0; i < 2; i++) {
        if (!mpModelArrow[i]) {
            continue;
        }
        g_env_light.setLightTevColorType(mpModelArrow[i], &mTevStr);
    }
}

/* 800F61C8-800F6268       .text _daItem_delete__8daItem_cFv */
BOOL daItem_c::_daItem_delete() {
    mPtclRippleCb.end();
    mPtclFollowCb.end();
    mPtclSmokeCb.end();
    if (mpParticleEmitter) {
        mpParticleEmitter->becomeInvalidEmitter();
        mpParticleEmitter = NULL;
    }
    
    DeleteBase(dItem_data::getFieldArc(m_itemNo));
    
    return TRUE;
}

/* 800F6268-800F6434       .text Reflect__FR4cXyzP4cXyzff */
bool Reflect(cXyz& surfVec, cXyz* moveVec, f32 param_2, f32 xzMult) {
    // Reflects a vector off the normal of a surface.
    cXyz reflectVec;
    cXyz moveNorm;
    cXyz surfNorm;
    f32 mag = moveVec->abs();
    moveNorm = moveVec->normalize();
    surfNorm = surfVec.normalize();
    moveNorm = moveNorm * -1.0f;
    f32 dot = 2.0f*surfNorm.getDotProduct(moveNorm);
    bool hitFront = true;
    if (dot < 0.0f) {
        hitFront = false;
    }
    reflectVec = (surfNorm * dot) - moveNorm;
    reflectVec *= mag;
    moveVec->x = reflectVec.x * xzMult;
    moveVec->y = reflectVec.y;
    moveVec->z = reflectVec.z * xzMult;
    return hitFront;
}

/* 800F6434-800F6D24       .text itemGetExecute__8daItem_cFv */
void daItem_c::itemGetExecute() {
    if (mCurState == 5) {
        return;
    }
    mCurState = 5;
    
    switch (m_itemNo) {
    case HEART:
        mDoAud_seStart(JA_SE_HEART_PIECE, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case GREEN_RUPEE:
        mDoAud_seStart(JA_SE_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case BLUE_RUPEE:
        mDoAud_seStart(JA_SE_BLUE_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case YELLOW_RUPEE:
        mDoAud_seStart(JA_SE_BLUE_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case RED_RUPEE:
        mDoAud_seStart(JA_SE_RED_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case PURPLE_RUPEE:
        mDoAud_seStart(JA_SE_RED_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case ORANGE_RUPEE:
        mDoAud_seStart(JA_SE_RED_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case SILVER_RUPEE:
        mDoAud_seStart(JA_SE_RED_LUPY_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case UTUWA_HEART:
        mDoAud_seStart(JA_SE_HEART_PIECE, NULL, 0, 0);
        mCurState = 7;
        break;
    case KAKERA_HEART:
        mDoAud_seStart(JA_SE_HEART_PIECE, NULL, 0, 0);
        mCurState = 7;
        break;
    case S_MAGIC:
        mDoAud_seStart(JA_SE_MAGIC_POT_GET_S, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case L_MAGIC:
        mDoAud_seStart(JA_SE_MAGIC_POT_GET_L, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case BOMB_5:
    case BOMB_10:
    case BOMB_20:
    case BOMB_30:
        mDoAud_seStart(JA_SE_CONSUMP_ITEM_GET, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case SMALL_KEY:
        mCurState = 7;
        break;
    case TRIPLE_HEART:
        mDoAud_seStart(JA_SE_HEART_PIECE, NULL, 0, 0);
        execItemGet(m_itemNo);
        break;
    case PENDANT:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(7)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(7);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case DEKU_LEAF:
        mCurState = 7;
        break;
    case SWORD:
        daItem_c* item = (daItem_c*)fopAcM_SearchByName(PROC_ITEM);
        if (item && item->m_itemNo == SHIELD) {
            item->itemGetExecute();
        }
        mCurState = 7;
        break;
    case SHIELD:
        item = (daItem_c*)fopAcM_SearchByName(PROC_ITEM);
        if (item && item->m_itemNo == SWORD) {
            item->itemGetExecute();
        }
        mCurState = 7;
        break;
    case DROPPED_SWORD:
        mCurState = 7;
        break;
    case SKULL_NECKLACE:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(0)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(0);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case BOKOBABA_SEED:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(1)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(1);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case GOLDEN_FEATHER:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(2)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(2);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case BOKO_BELT:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(3)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(3);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case RED_JELLY:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(4)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(4);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case GREEN_JELLY:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(5)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(5);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case BLUE_JELLY:
        mDoAud_seStart(JA_SE_SPOILS_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBeast(6)) {
            mCurState = 7;
            dComIfGs_onGetItemBeast(6);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case ANIMAL_ESA:
        mDoAud_seStart(JA_SE_ESA_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBait(0)) {
            mCurState = 7;
            dComIfGs_onGetItemBait(0);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    case BIRD_ESA_5:
        mDoAud_seStart(JA_SE_ESA_GET, NULL, 0, 0);
        if (!dComIfGs_isGetItemBait(1)) {
            mCurState = 7;
            dComIfGs_onGetItemBait(1);
        } else {
            execItemGet(m_itemNo);
        }
        break;
    }
    
    u8 roomNo = getRoomNo();
    s32 flag = mPickupFlag;
    if (m_itemNo == BLUE_JELLY) {
        // Blue Chu Jelly uses mPickupFlag as if it was a switch.
        // Specifically a switch in stageNo 0xE, which is not used for anything else.
        dComIfGs_onSaveSwitch(0xE, flag);
    } else {
        dComIfGs_onItem(flag, (s8)roomNo);
    }
    
    mStatusFlags &= ~0x4;
    
    mCyl.SetTgType(0);
    mCyl.OffCoSPrmBit(1);
    mCyl.ClrTgHit();
    mCyl.ClrCoHit();
}

/* 800F6D24-800F6D78       .text itemDefaultRotateY__8daItem_cFv */
void daItem_c::itemDefaultRotateY() {
    // Rotates at a fixed speed.
    s16 rotationSpeed = 0xFFFF / getData()->mNumFramesPerFullSpin;
    fopAcM_addAngleY(this, current.angle.y + rotationSpeed, rotationSpeed);
}

/* 800F6D78-800F6E54       .text checkItemDisappear__8daItem_cFv */
BOOL daItem_c::checkItemDisappear() {
    BOOL disappearing = true;
    if (mCurState == 3) {
        disappearing = false;
        show();
    }
    if (mStatusFlags & 0x02) {
        disappearing = false;
    }
    if (mStatusFlags & 0x10) {
        disappearing = false;
    }
    if (dItem_data::chkFlag(m_itemNo, 0x01)) {
        disappearing = false;
    }
    if (g_dComIfG_gameInfo.play.mEvtCtrl.mMode != 0) {
        disappearing = false;
    }
    if (mCurState == 4) {
        disappearing = false;
    }
    if ((mStatusFlags & 0x08) || (mStatusFlags & 0x40) || (mStatus & fopAcStts_HOOK_CARRY_e)) {
        disappearing = false;
        show();
    }
    return disappearing;
}

/* 800F6E54-800F6E74       .text setItemTimer__8daItem_cFi */
void daItem_c::setItemTimer(int timer) {
    if (timer == -1) {
        mStatusFlags |= 0x10;
        return;
    }
    mItemTimer = timer;
}

/* 800F6E74-800F6EC8       .text checkPlayerGet__8daItem_cFv */
BOOL daItem_c::checkPlayerGet() {
    if (field_0x638 < getData()->field_0x42) {
        return FALSE;
    }
    if (mCurState == 3) {
        return FALSE;
    }
    return TRUE;
}

/* 800F6EC8-800F7028       .text itemActionForRupee__8daItem_cFv */
void daItem_c::itemActionForRupee() {
    /* Nonmatching */
}

/* 800F7028-800F713C       .text itemActionForHeart__8daItem_cFv */
void daItem_c::itemActionForHeart() {
    /* Nonmatching */
}

/* 800F713C-800F72A4       .text itemActionForKey__8daItem_cFv */
void daItem_c::itemActionForKey() {
    /* Nonmatching */
}

/* 800F72A4-800F73A4       .text itemActionForEmono__8daItem_cFv */
void daItem_c::itemActionForEmono() {
    /* Nonmatching */
}

/* 800F73A4-800F7898       .text itemActionForSword__8daItem_cFv */
void daItem_c::itemActionForSword() {
    /* Nonmatching */
}

/* 800F7898-800F7AF0       .text itemActionForArrow__8daItem_cFv */
void daItem_c::itemActionForArrow() {
    /* Nonmatching */
}

/* 800F7AF0-800F7BF8       .text checkWall__8daItem_cFv */
void daItem_c::checkWall() {
    // If the item hit a wall, bounce off.
    if (!mAcch.ChkWallHit()) {
        return;
    }
    
    cM3dGPla* wallPlane = dComIfG_Bgsp()->GetTriPla(mAcchCir.GetBgIndex(), mAcchCir.GetPolyIndex());
    cXyz wallNorm = wallPlane->mNormal;
    
    cXyz vel;
    vel.x = speedF * cM_ssin(current.angle.y);
    vel.y = speed.y;
    vel.z = speedF * cM_scos(current.angle.y);
    
    if (!cM3d_IsZero(vel.x) || !cM3d_IsZero(vel.z)) {
        Reflect(wallNorm, &vel, 1.0f, 1.0f);
        if (!cM3d_IsZero(vel.x)) {
            current.angle.y = cM_atan2s(vel.x, vel.z);
        }
    }
}

/* 800F7BF8-800F7DDC       .text set_bound_se__8daItem_cFv */
void daItem_c::set_bound_se() {
    if (field_0x638 < 10) {
        return;
    }
    
    f32 temp2 = fabs(field_0x650);
    temp2 = 2.0f * temp2;
    u32 temp = temp2;
    if (temp > 100) {
        temp = 100;
    }
    
    switch (m_itemNo) {
    case GREEN_RUPEE:
    case BLUE_RUPEE:
    case YELLOW_RUPEE:
    case RED_RUPEE:
    case PURPLE_RUPEE:
    case ORANGE_RUPEE:
        fopAcM_seStart(this, JA_SE_OBJ_LUPY_BOUND, temp);
        break;
    case S_MAGIC:
    case L_MAGIC:
        fopAcM_seStart(this, JA_SE_OBJ_M_POT_BOUND, temp);
        break;
    case ARROW_10:
    case ARROW_20:
    case ARROW_30:
    case MAGIC_ARROW:
    case LIGHT_ARROW:
        fopAcM_seStart(this, JA_SE_CM_BST_ARROW_BOUND, temp);
        break;
    case KAKERA_HEART:
    case UTUWA_HEART:
        fopAcM_seStart(this, JA_SE_CM_BST_HEART_BOUND, temp);
        break;
    case BOMB_5:
    case BOMB_10:
    case BOMB_20:
    case BOMB_30:
        fopAcM_seStart(this, JA_SE_CM_BST_BOMB_BOUND, temp);
        break;
    }
}

/* 800F7DDC-800F7E6C       .text checkGetItem__8daItem_cFv */
BOOL daItem_c::checkGetItem() {
    if (!checkPlayerGet()) {
        return FALSE;
    }
    
    if (mCyl.ChkTgHit()) {
        cCcD_Obj* hitObj = mCyl.GetTgHitObj();
        if (hitObj) {
            u32 atType = hitObj->GetAtType();
            if (atType & AT_TYPE_SWORD) {
                itemGetExecute();
                return TRUE;
            } else if (atType & AT_TYPE_BOOMERANG) {
                mStatusFlags |= 0x08;
            }
        }
    }
    
    return FALSE;
}

/* 800F7E6C-800F7F0C       .text timeCount__8daItem_cFv */
BOOL daItem_c::timeCount() {
    field_0x634++;
    if (field_0x638 < m_timer_max) {
        field_0x638++;
    }
    
    if (checkPlayerGet() && !dComIfGp_event_runCheck()) {
        if (mItemTimer > 0) {
            mItemTimer--;
        } else if (field_0x65a > 0) {
            field_0x65a--;
        }
    }
    
    return TRUE;
}

/* 800F7F0C-800F7F50       .text mode_wait_init__8daItem_cFv */
void daItem_c::mode_wait_init() {
    mMode = 0;
    mGravity = getData()->mFieldItemGravity;
    mPtclRippleCb.end();
}

/* 800F7F50-800F80CC       .text mode_water_init__8daItem_cFv */
void daItem_c::mode_water_init() {
    /* Nonmatching */
}

/* 800F80CC-800F844C       .text mode_wait__8daItem_cFv */
void daItem_c::mode_wait() {
    /* Nonmatching */
}

/* 800F844C-800F8528       .text mode_water__8daItem_cFv */
void daItem_c::mode_water() {
    /* Nonmatching */
}

/* 800F8528-800F8950       .text initAction__8daItem_cFv */
void daItem_c::initAction() {
    /* Nonmatching */
}

/* 800F8950-800F8970       .text daItem_Draw__FP8daItem_c */
BOOL daItem_Draw(daItem_c* i_this) {
    return i_this->_daItem_draw();
}

/* 800F8970-800F8990       .text daItem_Execute__FP8daItem_c */
BOOL daItem_Execute(daItem_c* i_this) {
    return i_this->_daItem_execute();
}

/* 800F8990-800F89B0       .text daItem_IsDelete__FP8daItem_c */
BOOL daItem_IsDelete(daItem_c* i_this) {
    return i_this->_daItem_isdelete();
}

/* 800F89B0-800F89D0       .text daItem_Delete__FP8daItem_c */
BOOL daItem_Delete(daItem_c* i_this) {
    return i_this->_daItem_delete();
}

/* 800F89D0-800F89F0       .text daItem_Create__FP10fopAc_ac_c */
s32 daItem_Create(fopAc_ac_c* i_this) {
    return ((daItem_c*)i_this)->_daItem_create();
}

/* 800F89F0-800F89F8       .text _daItem_isdelete__8daItem_cFv */
BOOL daItem_c::_daItem_isdelete() {
    return TRUE;
}

dCcD_SrcCyl daItem_c::m_cyl_src = {
    // dCcD_SrcGObjInf
    {
        /* Flags             */ 0,
        /* SrcObjAt Type     */ 0,
        /* SrcObjAt Atp      */ 0,
        /* SrcObjAt SPrm     */ 0,
        /* SrcObjTg Type     */ 0xFFFFFFFF,
        /* SrcObjTg SPrm     */ 0x09,
        /* SrcObjCo SPrm     */ 0x59,
        /* SrcGObjAt Se      */ 0,
        /* SrcGObjAt HitMark */ 0,
        /* SrcGObjAt Spl     */ 0,
        /* SrcGObjAt Mtrl    */ 0,
        /* SrcGObjAt GFlag   */ 0,
        /* SrcGObjTg Se      */ 0,
        /* SrcGObjTg HitMark */ 0,
        /* SrcGObjTg Spl     */ 0,
        /* SrcGObjTg Mtrl    */ 0,
        /* SrcGObjTg GFlag   */ 0x04,
        /* SrcGObjCo GFlag   */ 0,
    },
    // cM3dGCylS
    {
        /* Center */ 0.0f, 0.0f, 0.0f,
        /* Radius */ 10.0f,
        /* Height */ 50.0f,
    },
};

static actor_method_class l_daItem_Method = {
    (process_method_func)daItem_Create,
    (process_method_func)daItem_Delete,
    (process_method_func)daItem_Execute,
    (process_method_func)daItem_IsDelete,
    (process_method_func)daItem_Draw,
};

actor_process_profile_definition g_profile_ITEM = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 7,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_ITEM,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(daItem_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopAc_Method.base,
    /* Priority     */ 0x00F5,
    /* Actor SubMtd */ &l_daItem_Method,
    /* Status       */ fopAcStts_CULL_e | fopAcStts_UNK40000_e | fopAcStts_UNK80000_e,
    /* Group        */ fopAc_ACTOR_e,
    /* CullType     */ fopAc_CULLBOX_0_e,
};
