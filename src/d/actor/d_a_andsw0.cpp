//
// Generated by dtk
// Translation Unit: d_a_andsw0.cpp
//

#include "JSystem/JKernel/JKRHeap.h"
#include "f_op/f_op_actor_mng.h"
#include "d/d_com_inf_game.h"
#include "d/d_procname.h"

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
    /* 0x298 */ s8 mAction;
    /* 0x299 */ u8 mNumSwitchesToCheck;
    /* 0x29A */ u8 mBehaviorType;
    /* 0x29B */ u8 mSwitchToSet;
    /* 0x29C */ u8 mFirstSwitchToCheck;
    /* 0x29E */ u16 mTimer;
    /* 0x2A0 */ s16 mEventIdx;
    /* 0x2A2 */ u8 mEventNo;
    /* 0x2A3 */ s8 mEventState;
};

// Bokoblin. TODO: Include d_a_bk.h once implemented.
struct bk_class : public fopAc_ac_c {
    u8 temp[0x121C - 0x290];
    u8 field_0x121C;
};

// Kargaroc. TODO: Include d_a_bb.h once implemented.
struct bb_class : public fopAc_ac_c {};

static s32 daAndsw0_Draw(andsw0_class*) {
    return 1;
}

static void daAndsw0_check(andsw0_class* i_this) {
    /* Nonmatching */
    s32 numToCheck = i_this->mNumSwitchesToCheck;
    u32 switchIdxToCheck;
    if (i_this->mFirstSwitchToCheck) {
        switchIdxToCheck = i_this->mFirstSwitchToCheck;
    } else {
        switchIdxToCheck = i_this->mSwitchToSet + 1;
    }

    switch(i_this->mAction) {
        case ACT_ON_ALL:
            for(int i = 0; i < numToCheck; i++) {
                if(dComIfGs_isSwitch(switchIdxToCheck, fopAcM_GetRoomNo(i_this)) == false) {
                    break;
                }

                if(i == numToCheck - 1) {
                    if(i_this->mBehaviorType != 3) {
                        dComIfGs_onSwitch(i_this->mSwitchToSet, fopAcM_GetRoomNo(i_this));
                    }

                    switch(i_this->mBehaviorType) {
                        case 0:
                            i_this->mAction = ACT_WAIT;
                            break;
                        case 3:
                            i_this->mAction = ACT_TIMER_SET;
                            i_this->mTimer = 0x41;
                            break;
                        default:
                            i_this->mAction = ACT_OFF_ALL;
                            break;
                    }
                }

                switchIdxToCheck += 1;
            }

            break;
        case ACT_OFF_ALL:
            u32 switchIdxToCheck2 = i_this->mFirstSwitchToCheck ? i_this->mFirstSwitchToCheck : i_this->mSwitchToSet + 1;

            for(int i = 0; i < numToCheck; i++) {
                if(dComIfGs_isSwitch(switchIdxToCheck2, fopAcM_GetRoomNo(i_this)) == false) {
                    dComIfGs_offSwitch(i_this->mSwitchToSet, fopAcM_GetRoomNo(i_this));
                    i_this->mAction  = ACT_ON_ALL;
                    break;
                }
                
                switchIdxToCheck2 += 1;
            }

            break;
        case ACT_TIMER:
            i_this->mTimer = (i_this->orig.angle.z & 0xFF) * 0xF;
            if(fopAcM_isSwitch(i_this, i_this->mSwitchToSet)) {
                i_this->mAction = ACT_WAIT;
            }
            else {
                for(int i = 0; i < numToCheck; i++) {
                    if(fopAcM_isSwitch(i_this, switchIdxToCheck)) {
                        i_this->mAction += 1;
                        break;
                    }
                    
                    switchIdxToCheck += 1;
                }
            }

            break;
        case ACT_TIMER2:
            i_this->mTimer -= 1;
            if(i_this->mTimer == 0) {
                for(int i = 0; i < numToCheck; i++) {
                    fopAcM_offSwitch(i_this, switchIdxToCheck);
                    switchIdxToCheck += 1;
                }
                
                i_this->mAction = ACT_TIMER;
            }
            else {
                switchIdxToCheck = i_this->mFirstSwitchToCheck ? i_this->mFirstSwitchToCheck : i_this->mSwitchToSet + 1;

                for(int i = 0; i < numToCheck; i++) {
                    if(fopAcM_isSwitch(i_this, switchIdxToCheck) == false) {
                        break;
                    }

                    if(i == numToCheck - 1) {
                        fopAcM_onSwitch(i_this, i_this->mSwitchToSet);
                        i_this->mAction = ACT_WAIT;
                    }
                    
                    switchIdxToCheck += 1;
                }
            }

            break;
        case ACT_TIMER_SET:
            i_this->mTimer -= 1;
            if(i_this->mTimer == 0) {
                fopAcM_onSwitch(i_this, i_this->mSwitchToSet);
                i_this->mAction = ACT_WAIT;
            }

            break;
        case ACT_WAIT:
        default:
            break;
    }
}

static void* ac[7];
static s32 check_count;

static void* bk_s_sub1(void* i_this, void*) {
    if(fopAcM_IsActor(i_this) && fopAcM_GetName(i_this) == PROC_BK && (fopAcM_GetParam(i_this) & 0xF) == 7)  {
        s32 count = check_count; //regswaps without this
        if(count < 2) {
            ac[check_count] = i_this;
            check_count++;
        }

        return 0;
    }

    return 0;
}

static void* bk_s_sub2(void* i_this, void*) {
    if(fopAcM_IsActor(i_this) && fopAcM_GetName(i_this) == PROC_BK && (fopAcM_GetParam(i_this) & 0xF) == 4)  {
        s32 count = check_count; //regswaps without this
        if(count == 2) {
            ac[check_count] = i_this;
            check_count++;
        }

        return 0;
    }

    return 0;
}

static void* bk_s_sub3(void* i_this, void*) {
    if(fopAcM_IsActor(i_this) && fopAcM_GetName(i_this) == PROC_BK && (fopAcM_GetParam(i_this) & 0xF) == 5)  {
        s32 count = check_count; //regswaps without this
        if(count < 5) {
            ac[check_count] = i_this;
            check_count++;
        }

        return 0;
    }

    return 0;
}

static void* bb_s_sub(void* i_this, void*) {
    if(fopAcM_IsActor(i_this) && fopAcM_GetName(i_this) == PROC_BB)  {
        s32 count = check_count; //regswaps without this
        if(count < 7) {
            ac[check_count] = i_this;
            check_count++;
        }

        return 0;
    }

    return 0;
}

static s32 hajimari_actor_entry(andsw0_class* i_this) {
    for(int i = 0; i < 7; i++) {
        ac[i] = 0;
    }
    check_count = 0;

    i_fpcM_Search(&bk_s_sub1, i_this);
    i_fpcM_Search(&bk_s_sub2, i_this);
    i_fpcM_Search(&bk_s_sub3, i_this);
    check_count = 5;
    i_fpcM_Search(&bb_s_sub, i_this);

    for(int i = 0; i < 7; i++) {
        if(ac[i] == 0) {
            return 0;
        }
    }

    return 1;
}

static void hajimarinomori_check(andsw0_class* i_this) {
    fopAc_ac_c* actor = i_this;
    if (i_this->mBehaviorType == 0) {
        if (hajimari_actor_entry(i_this)) {
            i_this->mBehaviorType = 1;
        }
    }
    else {
        for(int i = 0; i < 7; i++) {}

        if (dComIfGs_isEventBit(4)) {
            bb_class* kargaroc = (bb_class*)ac[5];
            fopAcM_delete(kargaroc);
            kargaroc = (bb_class*)ac[6];
            fopAcM_delete(kargaroc);
            
            bk_class* bokoblin = (bk_class*)ac[3];
            bokoblin->field_0x121C = 1;
            bokoblin = (bk_class*)ac[4];
            bokoblin->field_0x121C = 1;
            
            if (dComIfGs_isEventBit(0x301)) {
                bokoblin = (bk_class*)ac[0];
                bokoblin->field_0x121C = 1;
            }
            if (dComIfGs_isEventBit(0x480)) {
                bokoblin = (bk_class*)ac[1];
                bokoblin->field_0x121C = 1;
            }
            if (dComIfGs_isEventBit(0x301) && dComIfGs_isEventBit(0x480)) {
                bokoblin = (bk_class*)ac[2];
                bokoblin->field_0x121C = 1;
            }
        }
        else {
            bk_class* bokoblin = (bk_class*)ac[0];
            bokoblin->field_0x121C = 1;
            bokoblin = (bk_class*)ac[1];
            bokoblin->field_0x121C = 1;
        }
        
        fopAcM_delete(actor);
    }
}

static void event_start_check(andsw0_class* i_this) {
    fopAc_ac_c* actor = i_this;
    switch (i_this->mEventState) {
    case 0:
        if (i_this->mEventIdx != -1 && fopAcM_isSwitch(actor, i_this->mSwitchToSet)) {
            if (actor->mEvtInfo.checkCommandDemoAccrpt()) {
                i_this->mEventState++;
            } else {
                fopAcM_orderOtherEventId(actor, i_this->mEventIdx, i_this->mEventNo, 0xFFFF, 0, 1);
            }
        }

        break;
    case 1:
        if (dComIfGp_evmng_endCheck(i_this->mEventIdx)) {
            dComIfGp_event_reset();
            i_this->mEventState++;
        }
        break;
    case 2:
        break;
    }
}

static s32 daAndsw0_Execute(andsw0_class* i_this) {
    event_start_check(i_this);
    if (i_this->mNumSwitchesToCheck == 0xFF)
        hajimarinomori_check(i_this);
    else
        daAndsw0_check(i_this);
    return 1;
}

static s32 daAndsw0_IsDelete(andsw0_class*) {
    return 1;
}

static s32 daAndsw0_Delete(andsw0_class*) {
    return 1;
}

static s32 daAndsw0_Create(fopAc_ac_c* ac) {
    fopAcM_SetupActor(ac, andsw0_class);

    andsw0_class * i_this = (andsw0_class *)ac;
    i_this->mNumSwitchesToCheck = (fopAcM_GetParam(ac) >> 0) & 0xFF;
    i_this->mBehaviorType = (fopAcM_GetParam(ac) >> 8) & 0xFF;
    i_this->mSwitchToSet = (fopAcM_GetParam(ac) >> 24) & 0xFF;
    i_this->mFirstSwitchToCheck = (fopAcM_GetParam(ac) >> 16) & 0xFF;
    i_this->mTimer = (i_this->orig.angle.z & 0xFF) * 0xF;
    i_this->mEventNo = i_this->orig.angle.x;
    i_this->mEventIdx = dComIfGp_evmng_getEventIdx(NULL, i_this->mEventNo);
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

static actor_method_class l_daAndsw0_Method = {
    (process_method_func)daAndsw0_Create,
    (process_method_func)daAndsw0_Delete,
    (process_method_func)daAndsw0_Execute,
    (process_method_func)daAndsw0_IsDelete,
    (process_method_func)daAndsw0_Draw,
};

actor_process_profile_definition g_profile_ANDSW0 = {
    fpcLy_CURRENT_e,
    7,
    fpcPi_CURRENT_e,
    PROC_ANDSW0,
    &g_fpcLf_Method.mBase,
    sizeof(andsw0_class),
    0,
    0,
    &g_fopAc_Method.base,
    0x0135,
    &l_daAndsw0_Method,
    fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_0_e,
};
