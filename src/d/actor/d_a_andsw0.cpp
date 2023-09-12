//
// Generated by dtk
// Translation Unit: d_a_andsw0.cpp
//

#include "JSystem/JKernel/JKRHeap.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_com_inf_game.h"

enum {
    ACT_ON_ALL = 0,
    ACT_OFF_ALL,
    ACT_WAIT = 10,
    ACT_TIMER = 20,
    ACT_TIMER2,
    ACT_TIMER_SET = 30,
};

struct andsw0_class : public fopAc_ac_c {
public:
    /* 0x290 */ u32 _pad[2];
    /* 0x298 */ u8 mAction;
    /* 0x299 */ u8 mNumSwitchesToCheck;
    /* 0x29A */ u8 mBehaviorType;
    /* 0x29B */ u8 mSwitchToSet;
    /* 0x29C */ u8 mFirstSwitchToCheck;
    /* 0x29E */ u16 mTimer;
    /* 0x2A0 */ u16 mEventMapToolNo;
    /* 0x292 */ u8 mEventIdx;
    /* 0x293 */ u8 mEventState;
};

/* 00000078-00000080       .text daAndsw0_Draw__FP12andsw0_class */
s32 daAndsw0_Draw(andsw0_class*) {
    return 1;
}

/* 00000080-000003C4       .text daAndsw0_check__FP12andsw0_class */
void daAndsw0_check(andsw0_class*) {
    /* Nonmatching */
}

/* 000003C4-0000044C       .text bk_s_sub1__FPvPv */
void bk_s_sub1(void*, void*) {
    /* Nonmatching */
}

/* 0000044C-000004D4       .text bk_s_sub2__FPvPv */
void bk_s_sub2(void*, void*) {
    /* Nonmatching */
}

/* 000004D4-0000055C       .text bk_s_sub3__FPvPv */
void bk_s_sub3(void*, void*) {
    /* Nonmatching */
}

/* 0000055C-000005D4       .text bb_s_sub__FPvPv */
void bb_s_sub(void*, void*) {
    /* Nonmatching */
}

/* 000005D4-000006AC       .text hajimari_actor_entry__FP12andsw0_class */
s32 hajimari_actor_entry(andsw0_class*) {
    /* Nonmatching */
}

/* 000006AC-0000081C       .text hajimarinomori_check__FP12andsw0_class */
void hajimarinomori_check(andsw0_class* i_this) {
    if (i_this->mBehaviorType == 0) {
        if (hajimari_actor_entry(i_this))
            i_this->mBehaviorType = 1;
    } else {
        if (dComIfGs_isEventBit(4)) {
            //
        }
    }
}

/* 0000081C-00000914       .text event_start_check__FP12andsw0_class */
static void event_start_check(andsw0_class* i_this) {
    switch (i_this->mEventState) {
    case 0:
    default:
        if (i_this->mEventIdx != -1 && i_fopAcM_isSwitch(i_this, i_this->mSwitchToSet)) {
            if (i_this->mEvtInfo.i_checkCommandDemoAccrpt()) {
                i_this->mEventState++;
            } else {
                fopAcM_orderOtherEventId(i_this, i_this->mEventIdx, i_this->mEventMapToolNo, 0xFFFF, 0, 1);
            }
        }
    case 1:
        if (dComIfGp_evmng_endCheck(i_this->mEventIdx)) {
            dComIfGp_event_onEventFlag(8);
            i_this->mEventState++;
        }
        break;
    }
}

/* 00000914-00000964       .text daAndsw0_Execute__FP12andsw0_class */
s32 daAndsw0_Execute(andsw0_class* i_this) {
    event_start_check(i_this);
    if (i_this->mNumSwitchesToCheck == 0xFF)
        hajimarinomori_check(i_this);
    else
        daAndsw0_check(i_this);
    return 1;
}

/* 00000964-0000096C       .text daAndsw0_IsDelete__FP12andsw0_class */
s32 daAndsw0_IsDelete(andsw0_class*) {
    return 1;
}

/* 0000096C-00000974       .text daAndsw0_Delete__FP12andsw0_class */
s32 daAndsw0_Delete(andsw0_class*) {
    return 1;
}

/* 00000974-00000A64       .text daAndsw0_Create__FP10fopAc_ac_c */
s32 daAndsw0_Create(fopAc_ac_c* ac) {
    fopAcM_SetupActor(ac, andsw0_class);

    andsw0_class * i_this = (andsw0_class *)ac;
    i_this->mNumSwitchesToCheck = (fopAcM_GetParam(ac) >> 0) & 0xFF;
    i_this->mBehaviorType = (fopAcM_GetParam(ac) >> 8) & 0xFF;
    i_this->mSwitchToSet = (fopAcM_GetParam(ac) >> 24) & 0xFF;
    i_this->mFirstSwitchToCheck = (fopAcM_GetParam(ac) >> 16) & 0xFF;
    i_this->mTimer = (i_this->orig.angle.z & 0xFF) * 16;
    i_this->mEventMapToolNo = i_this->orig.angle.x;
    i_this->mEventIdx = dComIfGp_evmng_getEventIdx(NULL, i_this->mEventMapToolNo);
    if (i_this->mBehaviorType == 2)
        i_this->mAction = ACT_TIMER;
    if (i_this->mFirstSwitchToCheck == 0xFF)
        i_this->mFirstSwitchToCheck = 0;
    if (i_this->mNumSwitchesToCheck == 0xFF) {
        i_this->mSwitchToSet = 0;
        i_this->mBehaviorType = 0;
    }

    return cPhs_COMPLEATE_e;
}

