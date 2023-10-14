//
// Generated by dtk
// Translation Unit: d_a_obj_toripost.cpp
//

#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "f_op/f_op_actor_mng.h"
#include "d/actor/d_a_player.h"
#include "d/d_com_inf_game.h"
#include "d/d_lib.h"
#include "d/d_npc.h"
#include "d/d_letter.h"
#include "d/d_item_data.h"
#include "d/d_s_play.h"
#include "d/d_a_obj.h"
#include "d/d_procname.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"

extern dScnPly_reg_HIO_c g_regHIO;

struct daObjTpost_c__letter_data {
    /* 0x00 */ bool field_0x00;
    /* 0x04 */ u32 mMsgId;
    /* 0x08 */ u8 mItemId;
    /* 0x0A */ u16 mEventReg;
};

class daObjTpost_c : public fopNpc_npc_c {
public:
    enum Proc_e {
        PROC_INIT = 0,
        PROC_EXEC = 1
    };

    bool _createHeap();
    bool cutProc();
    void cutPresentStart(int staffIdx);
    void cutPresentProc(int staffIdx);
    void cutSetAnmStart(int staffIdx);
    void cutSetAnmProc(int staffIdx);
    void cutDispLetterStart(int staffIdx);
    void cutDispLetterProc(int staffIdx);
    void deliverLetter();
    s16 getReceiveLetterNum();
    s32 getReadableLetterNum();
    u8 checkSendPrice();
    int getMsgXY();
    int getMsgNormal();
    u32 getMsg();
    u16 next_msgStatus(u32* msgId);
    bool checkTalk();
    void eventOrder();
    void checkOrder();
    void setAttention();
    void setAnm(s8 param_1, bool param_2);
    void setMtx();
    void modeWaitInit();
    void modeWait();
    void modeTalkInit();
    void modeTalk();
    void modeTalkXYInit();
    void modeTalkXY();
    void modeReceiveInit();
    void modeReceive();
    void modeReceiveDemoInit();
    void modeReceiveDemo();
    void modeProc(Proc_e proc, int newMode);
    bool _execute();
    void debugDraw();
    bool _draw();
    void createInit();
    void getArg();
    int _create();
    bool _delete();

    inline s32 getSendPrice() { return m_send_price[mPayType]; }

    static const char m_arc_name[];
    static const daObjTpost_c__letter_data m_letter[];
    static const dCcD_SrcCyl m_cyl_src;

private:
    static const s32 m_send_price[];

    /* 0x6C4 */ u32 mCurMode;
    /* 0x6C8 */ s8 field_0x6C8;
    /* 0x6C9 */ s8 field_0x6C9;
    /* 0x6CA */ s8 field_0x6CA;
    /* 0x6CC */ request_of_phase_process_class mPhs;
    /* 0x6D4 */ mDoExt_McaMorf* mMorf;
    /* 0x6D8 */ dBgS_ObjAcch mAcch;
    /* 0x89C */ dBgS_AcchCir mAcchCir;
    /* 0x8DC */ int field_0x8DC;
    /* 0x8E0 */ int field_0x8E0;
    /* 0x8E4 */ int field_0x8E4;
    /* 0x8E8 */ u8 mPayType;
    /* 0x8E9 */ u8 field_0x8E9;
    /* 0x8EA */ u8 field_0x8EA;
    /* 0x8EB */ u8 field_0x8EB;
    /* 0x8EC */ s32 mNumReadable;
    /* 0x8F0 */ u32 field_0x8F0;
    /* 0x8F4 */ u8 field_0x8F4;
    /* 0x8F5 */ u8 field_0x8F5;
    /* 0x8F6 */ u8 field_0x8F6;
    /* 0x8F7 */ s8 field_0x8F7;
};

const char daObjTpost_c::m_arc_name[] = "Toripost";
const daObjTpost_c__letter_data daObjTpost_c::m_letter[] = {
    {false, 0x1AAF, 0x07, 0xAC03},
    {false, 0x0CF9, 0x07, 0xB503},
    {false, 0x0CFA, 0xC3, 0x7D03},
    {false, 0x0CFC, 0x04, 0x7B03},
    {false, 0x0805, 0x04, 0x9D03},
    {false, 0x0CFD, 0x01, 0x7A03},
    {true,  0x0DB6, 0xCB, 0xB203},
    {false, 0x1148, 0x04, 0x8B03},
    {false, 0x1AAF, 0x07, 0xAC03},
    {true,  0x0F76, 0x9D, 0xB003},
    {false, 0x19A6, 0x3F, 0xAE03},
    {true,  0x0CFB, 0x04, 0x7C03},
    {true,  0x0F77, 0x9E, 0xAF03}
};
const dCcD_SrcCyl daObjTpost_c::m_cyl_src = {
    0,
    0,
    0,
    0,
    0xFFFFFFBF, // Tg damage types
    0xF,
    0x79,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    7,
    0,
    
    // Cylinder
    0.0, // X
    0.0, // Y
    0.0, // Z
    0.0, // Radius
    0.0, // Height
};
const s32 daObjTpost_c::m_send_price[] = {
    0x05,
    0x0A,
    0x14
};

class daObjTpost_HIO_c {
public:
    daObjTpost_HIO_c();
    virtual ~daObjTpost_HIO_c() {}

    /* 0x04 */ s8 field_0x04;
    /* 0x05 */ bool debug_draw;
    /* 0x06 */ s8 field_0x06;
    /* 0x07 */ u8 field_0x07;
    /* 0x08 */ f32 attn_pos_offset;
    /* 0x0C */ f32 eye_pos_offset;
    /* 0x10 */ f32 talk_distance;
    /* 0x14 */ s16 field_0x14;
    /* 0x16 */ s16 field_0x16;
};

static daObjTpost_HIO_c l_HIO;

// need to figure out what's putting this data in front of a bunch of rels with the compiler-generated symbol names
static Vec dummy = {1.0f, 1.0f, 1.0f};
static Vec dummy2 = {1.0f, 1.0f, 1.0f};
static u8 dummy3[] = {
    2,
    0,
    2,
    1,
    0,
    0,
    0,
    0,
    0x40,
    8,
    0,
    0,
    0,
    0,
    0,
    0,
    0x3F,
    0xE0,
    0,
    0,
    0,
    0,
    0
};

static int createHeap_CB(fopAc_ac_c* i_this) {
    static_cast<daObjTpost_c*>(i_this)->_createHeap();
}

bool daObjTpost_c::_createHeap() {
    J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(m_arc_name, 9);
    JUT_ASSERT(132, modelData != 0);

    mMorf = new mDoExt_McaMorf(modelData, 0, 0, 0, -1, 1.0f, 0, -1, 1, 0, 0x80000, 0x11000022);

    if(mMorf == 0 || mMorf->getModel() == 0) {
        return 0;
    }
    else {
        mMorf->getModel()->setUserArea((u32)this);

        return 1;
    }
}

daObjTpost_HIO_c::daObjTpost_HIO_c() {
    field_0x04 = -1;
    debug_draw = false;
    field_0x06 = 0;
    field_0x07 = 0;
    attn_pos_offset = 140.0f;
    eye_pos_offset = 100.0f;
    talk_distance = 300.0f;
    field_0x14 = 30;
    field_0x16 = 30;
}

bool daObjTpost_c::cutProc() {
    static const char* action_table[3] = {
        "PRESENT",
        "SET_ANM",
        "DISP_LETTER"
    };

    int staffIdx = dComIfGp_evmng_getMyStaffId("Tpost", 0, 0);
    if(staffIdx != -1) {
        int actIdx = dComIfGp_evmng_getMyActIdx(staffIdx, action_table, 3, 1, 0);
        if(actIdx == -1) {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        else {
            if(dComIfGp_evmng_getIsAddvance(staffIdx)) {
                switch(actIdx) {
                    case 0:
                        cutPresentStart(staffIdx);
                        break;
                    case 1:
                        cutSetAnmStart(staffIdx);
                        break;
                    case 2:
                        cutDispLetterStart(staffIdx);
                        break;
                }
            }
            
            switch(actIdx) {
                case 0:
                    cutPresentProc(staffIdx);
                    break;
                case 1:
                    cutSetAnmProc(staffIdx);
                    break;
                case 2:
                    cutDispLetterProc(staffIdx);
                    break;
            }
        }
    }
}

void daObjTpost_c::cutPresentStart(int staffIdx) {
    return;
}

void daObjTpost_c::cutPresentProc(int staffIdx) {
    u32 item = fopAcM_createItemForPresentDemo(&current.pos, m_letter[mNumReadable].mItemId, 0, -1, -1, 0, 0);
    if(item != 0xFFFFFFFF) {
        dComIfGp_event_setItemPartnerId(item);
        dComIfGp_evmng_cutEnd(staffIdx);
    }
    else {
        dComIfGp_evmng_cutEnd(staffIdx);
    }
}

void daObjTpost_c::cutSetAnmStart(int staffIdx) {
    const char* name = dComIfGp_evmng_getMyStringP(staffIdx, "Name");
    if(name != 0 && dEvmng_strcmp(name, "HAKIDASU") == 0) {
        setAnm(3, false);
    }
    else {
        setAnm(1, false);
    }
}

void daObjTpost_c::cutSetAnmProc(int staffIdx) {
    // Using the mDoExt_McaMorf::isStop inline causes regswap.
    // if(mMorf->isStop()) { //
    mDoExt_McaMorf* morf = mMorf;
    bool stopped = true;
    if (!morf->mFrameCtrl.checkState(1) && morf->mFrameCtrl.getRate() != 0.0f) { stopped = false; }
    if (stopped) {
        dComIfGp_evmng_cutEnd(staffIdx);
    }
}

void daObjTpost_c::cutDispLetterStart(int staffIdx) {
    mCurrMsgID = m_letter[mNumReadable].mMsgId;
}

void daObjTpost_c::cutDispLetterProc(int staffIdx) {
    u16 mode = talk(0);
    if(mode == 5) {
        daPy_getPlayerActorClass()->onLetterReadEyeMove();
    }
    if(mode == dNpcMsgStts_BOX_CLOSED_e) {
        dComIfGp_evmng_cutEnd(staffIdx);
    }
}

void daObjTpost_c::deliverLetter() {
    switch(field_0x8F6) {
        case 0x9A:
            dComIfGs_onEventBit(0x1220);
            break;
        case 0x99:
            dLetter_send(0xAC03);
            break;
    }
}

s16 daObjTpost_c::getReceiveLetterNum() {
    s16 num = 0;
    for(int i = 1; i < 0xD; i++) {
        if(dLetter_isStock(m_letter[i].mEventReg)) {
            num = num + 1;
        }
    }

    return num;
}

s32 daObjTpost_c::getReadableLetterNum() {
    s32 num = 0;
    s32 startIdx = mNumReadable ? mNumReadable : 1;
    s32 readable = mNumReadable;

    if(readable < 0xD) {
        for(int i = startIdx; i < 0xD; i++) {
            if(dLetter_isStock(m_letter[i].mEventReg) == 0) {
                continue;
            }
            
            num = i;
            break;
        }
    }

    return num;
}

u8 daObjTpost_c::checkSendPrice() {
    static const u8 pay_type[49] = {
        02, 
        01,
        01,
        00,
        00,
        00,
        00,
        02,
        01,
        01,
        00,
        00,
        00,
        00,
        02,
        01,
        01,
        00,
        00,
        00,
        00,
        02,
        01,
        01,
        00,
        00,
        00,
        00,
        02,
        01,
        01,
        01,
        01,
        01,
        01,
        02,
        01,
        01,
        01,
        01,
        01,
        01,
        02,
        02,
        02,
        02,
        02,
        02,
        02
    };

    if(strcmp(dComIfGp_getStartStageName(), "sea") != 0) {
        return 0;
    }
    else {
        return pay_type[fopAcM_GetRoomNo(this)];
    }
}

int daObjTpost_c::getMsgXY() {
    s32 msgId;
    GXColor col = {0x00, 0x00, 0x00, 0x80};
    cXyz pos(g_regHIO.mChild[12].mFloatRegs[0], g_regHIO.mChild[12].mFloatRegs[1], g_regHIO.mChild[12].mFloatRegs[2]);
    cXyz scale(2.0f, 2.0f, 2.0f);

    switch(field_0x8F6) {
        case 0x99:
        case 0x9A:
            msgId = 0xCE8;
            col.r = g_regHIO.mChild[12].mShortRegs[0] + 0x80;
            col.g = g_regHIO.mChild[12].mShortRegs[1] + 0x80;
            col.b = g_regHIO.mChild[12].mShortRegs[2] + 0x80;
            mDoMtx_stack_c::copy(mMorf->getModel()->mpNodeMtx[2]);
            mDoMtx_stack_c::multVec(&pos, &pos);
            dComIfGp_particle_set(0x57, &pos, &shape_angle, &scale, 0xFF, 0, -1, &col);
            
            break;
        case 0x98:
        case 0x9B:
            setAnm(3, false);
            field_0x8EA = 1;
            msgId = 0xCEA;

            break;
        default:
            setAnm(3, false);
            field_0x8EA = 1;
            msgId = 0xCE9;

            break;
    }

    return msgId;
}

int daObjTpost_c::getMsgNormal() {
    s32 msgId;
    if(field_0x8EB) {
        dComIfGp_setMessageCountNumber(field_0x8F0);
        msgId = 0xCF7;
        field_0x8EB = 0;
    }
    else {
        if(dKy_daynight_check() == false) {
            msgId = 0xCE5;
        }
        else {
            msgId = 0xCE6;
        }
    }

    return msgId;
}

u32 daObjTpost_c::getMsg() {
    if(dComIfGp_event_chkTalkXY()) {
        return getMsgXY();
    }
    else {
        return getMsgNormal();
    }
}

u16 daObjTpost_c::next_msgStatus(u32* msgId) {
    static const u32 pay_msg_num[3] = {
        0x0CEC,
        0x0CED,
        0x0CEE
    };

    u16 status = dNpcMsgStts_MSG_CONTINUES_e;
    switch(*msgId) {
        case 0xCE5:
        case 0xCE6:
            if(mNumReadable) {
                dComIfGp_setMessageCountNumber(getReceiveLetterNum());
                *msgId = 0xCEB;
            }
            else {
                *msgId = 0xCE7;
            }

            break;
        case 0xCEB:
            dComIfGp_setMessageCountNumber(field_0x8F0);
            *msgId = 0xCF7;
            break;
        case 0xCF7:
            if(l_HIO.field_0x07 != 0 || m_letter[mNumReadable].field_0x00 != 0) {
                *msgId = 0xCF3;
            }
            else {
                field_0x8E9 = 1;
                status = dNpcMsgStts_MSG_ENDS_e;
            }

            break;
        case 0xCE8:
            *msgId = pay_msg_num[mPayType];

            break;
        case 0xCEC:
        case 0xCED:
        case 0xCEE:
            *msgId = 0xCEF;

            break;
        case 0xCEF:
            if(mpCurrMsg->mSelectedChoiceIdx == 0) {
                if(dComIfGs_getRupee() >= getSendPrice()) {
                    dComIfGp_setItemRupeeCount(-getSendPrice());
                    dComIfGs_setReserveItemEmpty();
                    deliverLetter();
                    *msgId = 0xCF2;
                }
                else {
                    setAnm(3, false);
                    field_0x8EA = 1;
                    *msgId = 0xCF1;
                }
            }
            else {
                setAnm(3, false);
                field_0x8EA = 1;
                *msgId = 0xCF0;
            }

            break;
        case 0xCF3:
            if(m_letter[mNumReadable].mEventReg == 0xB203) {
                *msgId = 0xCF8;
            }
            else {
                *msgId = 0xCF4;
            }

            break;
        case 0xCF4:
        case 0xCF8:
            if(mpCurrMsg->mSelectedChoiceIdx == 0) {
                s32 price = 0x0A;
                if(m_letter[mNumReadable].mEventReg == 0xB203) {
                    price = 0xC9;
                }
                if(dComIfGs_getRupee() >= price) {
                    dComIfGp_setItemRupeeCount(-price);
                    field_0x8E9 = 1;
                    status = dNpcMsgStts_MSG_ENDS_e;
                }
                else {
                    *msgId = 0xCF6;
                }
            }
            else {
                *msgId = 0xCF5;
            }

            break;
        case 0xCF5:
        case 0xCF6:
            mNumReadable += 1;
            field_0x8F0 += 1;
            mNumReadable = getReadableLetterNum();
            if(mNumReadable) {
                dComIfGp_setMessageCountNumber(field_0x8F0);
                *msgId = 0xCF7;
            }
            else {
                status = dNpcMsgStts_MSG_ENDS_e;
            }

            break;
        default:
            status = dNpcMsgStts_MSG_ENDS_e;
            break;
    }

    if(mCurrMsgID == m_letter[mNumReadable].mMsgId && status == dNpcMsgStts_MSG_ENDS_e) {
        status = dNpcMsgStts_MSG_DISPLAYED_e;
    }

    return status;
}

bool daObjTpost_c::checkTalk() {
    return fopAcM_searchPlayerDistanceXZ(this) < l_HIO.talk_distance;
}

void daObjTpost_c::eventOrder() {
    static char* a_demo_name_tbl[] = {
        "DEFAULT_POST"
    };

    if(field_0x8F7 == 1 || field_0x8F7 == 2) {
        mEvtInfo.onCondition(1);
        mEvtInfo.onCondition(0x20);

        if(field_0x8F7 == 1) {
            fopAcM_orderSpeakEvent(this);
        }
    }
    else if(field_0x8F7 >= 3) {
        fopAcM_orderOtherEvent2(this, a_demo_name_tbl[field_0x8F7 - 3], 1, 0x14F);
    }
}

void daObjTpost_c::checkOrder() {
    if(mEvtInfo.checkCommandDemoAccrpt()) {
        field_0x8F7 = 0;
        return;
    }

    if(mEvtInfo.checkCommandTalk()) {
        if(field_0x8F7 == 1 || field_0x8F7 == 2) {
            field_0x8F7 = 0;
            if(dComIfGp_event_chkTalkXY()) {
                field_0x8F5 = 1;
            }
            else {
                field_0x8F4 = 1;
            }
        }
    }

    return;
}

void daObjTpost_c::setAttention() {
    mAttentionInfo.mPosition = current.pos;
    mAttentionInfo.mPosition.y += l_HIO.attn_pos_offset;
    mEyePos = current.pos;
    mEyePos.y += l_HIO.eye_pos_offset;
}

void daObjTpost_c::setAnm(s8 param_1, bool param_2) {
    static const int a_anm_bcks_tbl[] = {
        0x04,
        0x05,
        0x06,
    };
    static const dLib_anm_prm_c a_anm_prm_tbl[] = {
        {
            -1,
            -1,
            0,
            8.0f,
            1.0f,
            2
        },
        {
            0,
            -1,
            0,
            8.0f,
            0.0f,
            0
        },
        {
            0,
            -1,
            0,
            8.0f,
            1.0f,
            0
        },
        {
            1,
            -1,
            0,
            8.0f,
            1.0f,
            0
        },
        {
            2,
            -1,
            0,
            8.0f,
            1.0f,
            2
        },
    };

    if(param_1 != 5) {
        field_0x6C9 = param_1;
    }

    if(field_0x6C8 == 0 && mMorf->getFrame() == 1.0f) {
        mDoAud_seStart(0x6973, 0, 0, 0);
    }

    if(field_0x6C8 == 1) {
        cXyz scale;
        scale.setAll(1.0f);
        if(mMorf->getFrame() == 1.0f) {
            dComIfGp_particle_set(0x8190, &current.pos, &current.angle, &scale);
            mDoAud_seStart(0x6974, 0, 0, 0);
        }
    }

    dLib_bcks_setAnm(m_arc_name, mMorf, &field_0x6C8, &field_0x6C9, &field_0x6CA, a_anm_bcks_tbl, a_anm_prm_tbl, param_2);
}

void daObjTpost_c::setMtx() {
    J3DModel* pModel = mMorf->getModel();
    pModel->setBaseScale(mScale);

    mDoMtx_stack_c::transS(current.pos);
    mDoMtx_stack_c::YrotM(shape_angle.y);
    MTXCopy(mDoMtx_stack_c::get(), pModel->getBaseTRMtx());
}

void daObjTpost_c::modeWaitInit() {
    field_0x8F0 = 1;
    if(mNumReadable) {
        setAnm(4, false);
    }
    else {
        setAnm(1, false);
    }
}

void daObjTpost_c::modeWait() {
    if(mNumReadable) {
        setAnm(4, false);
    }
    else {
        setAnm(1, false);
    }

    if(field_0x8F4) {
        modeProc(PROC_INIT, 1);
    }
    else {
        if(field_0x8F5) {
            modeProc(PROC_INIT, 2);
        }
        else {
            if(checkTalk()) {
                field_0x8F7 = 2;
            }
        }
    }
}

void daObjTpost_c::modeTalkInit() {
    setAnm(1, false);
}

void daObjTpost_c::modeTalk() {
    if(talk(1) == dNpcMsgStts_BOX_CLOSED_e) {
        if(field_0x8E9) {
            modeProc(PROC_INIT, 3);
            field_0x8E9 = 0;
        }
        else {
            modeProc(PROC_INIT, 0);
        }

        dComIfGp_event_onEventFlag(8);
        field_0x8F4 = 0;
    }
}

void daObjTpost_c::modeTalkXYInit() {
    setAnm(1, false);
    field_0x8F6 = dComIfGp_event_getPreItemNo();
    field_0x8DC = l_HIO.field_0x14;
    field_0x8E0 = l_HIO.field_0x16;
}

void daObjTpost_c::modeTalkXY() {
    daPy_py_c* player = daPy_getPlayerActorClass();
    if(field_0x6C9 == 3) {
        if(field_0x8EA != 0) {
            field_0x8E4 = 10;
            field_0x8EA = 0;
        }

        if(field_0x8E4 != -1 && cLib_calcTimer(&field_0x8E4) == 0) {
            player->mDemo.setOriginalDemoType();
            player->mDemo.setParam0(0);
            player->mDemo.setDemoMode(0x18);

            field_0x8E4 = -1;
        }

        switch(mCurrMsgID) {
            case 0xCE9:
            case 0xCEA:
            case 0xCF0:
            case 0xCF1:
                if(player->getBaseAnimeFrameRate() == 0.0f) {
                    player->mDemo.setOriginalDemoType();
                    player->mDemo.setParam0(0);
                    player->mDemo.setDemoMode(1);
                }

                break;
        }
    }

    if(field_0x6C9 == 1 && dComIfGp_evmng_ChkPresentEnd() && cLib_calcTimer(&field_0x8E0) == 0) {
        dComIfGp_evmng_CancelPresent();
        setAnm(2, false);
    }

    if(field_0x6C9 == 2 || field_0x6C9 == 3) {
        // Using the mDoExt_McaMorf::isStop inline causes regswap.
        // if(mMorf->isStop()) {
        mDoExt_McaMorf* morf = mMorf;
        bool stopped = true;
        if (!morf->mFrameCtrl.checkState(1) && morf->mFrameCtrl.getRate() != 0.0f) { stopped = false; }
        if (stopped) {
            if(cLib_calcTimer(&field_0x8DC) == 0 && talk(1) == dNpcMsgStts_BOX_CLOSED_e) {
                modeProc(PROC_INIT, 0);
                dComIfGp_event_onEventFlag(8);
                field_0x8F5 = 0;
            }
        }
    }
}

void daObjTpost_c::modeReceiveInit() {
    dComIfGp_event_onEventFlag(8);
    field_0x8F7 = 3;
    setAnm(1, false);
}

void daObjTpost_c::modeReceive() {
    modeProc(PROC_INIT, 4);
}

void daObjTpost_c::modeReceiveDemoInit() {
    return;
}

void daObjTpost_c::modeReceiveDemo() {
    if(dComIfGp_getEventManager().endCheckOld("DEFAULT_POST")) {
        dLetter_read(m_letter[mNumReadable].mEventReg);
        mNumReadable = getReadableLetterNum();
        dComIfGp_event_onEventFlag(8);

        if(mNumReadable != 0) {
            modeProc(PROC_INIT, 1);
            field_0x8F7 = 1;
            field_0x8EB = 1;
            field_0x8F0 += 1;
        }
        else {
            modeProc(PROC_INIT, 0);
            field_0x8F0 = 1;
        }
    }
}

void daObjTpost_c::modeProc(daObjTpost_c::Proc_e proc, int newMode) {
    typedef void(daObjTpost_c::*mode_func_t)(void);
    struct mode_entry_t {
        mode_func_t init;
        mode_func_t run;
        const char* name;
    };

    static mode_entry_t mode_tbl[] = {
        {
            &daObjTpost_c::modeWaitInit,
            &daObjTpost_c::modeWait,
            "WAIT",
        },
        {
            &daObjTpost_c::modeTalkInit,
            &daObjTpost_c::modeTalk,
            "TALK",
        },
        {
            &daObjTpost_c::modeTalkXYInit,
            &daObjTpost_c::modeTalkXY,
            "TALK_XY",
        },
        {
            &daObjTpost_c::modeReceiveInit,
            &daObjTpost_c::modeReceive,
            "RECEIVE",
        },
        {
            &daObjTpost_c::modeReceiveDemoInit,
            &daObjTpost_c::modeReceiveDemo,
            "RECEIVE_DEMO",
        }
    };

    if(proc == PROC_INIT) {
        mCurMode = newMode;
        (this->*mode_tbl[mCurMode].init)();
    }
    else if(proc == PROC_EXEC) {
        (this->*mode_tbl[mCurMode].run)();
    }
}

bool daObjTpost_c::_execute() {
    if(dComIfGs_isSymbol(1)) {
        mNumReadable = getReadableLetterNum();
    }
    else {
        mNumReadable = 0;
    }

    checkOrder();
    setAttention();
    setCollision(40.0f, 140.0f);
    modeProc(PROC_EXEC, 5);
    dBgS* bgs = dComIfG_Bgsp();

    if(g_dComIfG_gameInfo.play.mEvtCtrl.mMode != 0 && mEventCut.cutProc() == false) {
        cutProc();
    }
    eventOrder();

    fopAcM_posMoveF(this, 0);
    mAcch.CrrPos(*bgs);
    mStts.Move();
    if(mCyl.ChkTgHit()) {
        daObj::HitSeStart(&mEyePos, current.roomNo, &mCyl, 0x0B);
    }
    daObj::HitEff_kikuzu(this, &mCyl);
    fopAcM_rollPlayerCrash(this, 40.0f, 7);

    mMorf->play(0, 0, 0);
    mMorf->calc();
    setMtx();
    setAnm(5, false);

    return 0;
}

void daObjTpost_c::debugDraw() {
    GXColor col = {0xFF, 0x00, 0x00, 0x80};
}

bool daObjTpost_c::_draw() {
    if(l_HIO.debug_draw) {
        debugDraw();
    }

    J3DModel* pModel = mMorf->getModel();
    g_env_light.settingTevStruct(TEV_TYPE_BG0, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(pModel, &mTevStr);
    mMorf->entryDL();
    dComIfGd_setSimpleShadow2(getPositionP(), mAcch.GetGroundH(), 40.0f, mAcch.m_gnd, shape_angle.y, 1.0f, 0);

    return 1;
}

void daObjTpost_c::createInit() {
    if(dComIfGs_isSymbol(2)) {
        dLetter_autoStock(0xB503);
    }

    if(dComIfGs_checkGetItem(BOMB_BAG)) {
        dLetter_autoStock(0x7D03);
    }

    if(dLetter_isDelivery(0xAC03) && dComIfGs_isStageBossEnemy(6)) {
        dLetter_autoStock(0x7C03);
    }

    if(dComIfGs_isEventBit(0x1E80)) {
        dLetter_autoStock(0x7B03);
    }

    if(dComIfGs_getWalletSize() == 1 || dComIfGs_getWalletSize() == 2) {
        dLetter_autoStock(0x7A03);
    }

    field_0x8F0 = 1;
    mCurrMsgBsPcId = -1;
    mpCurrMsg = 0;

    mAttentionInfo.mDistances[1] = 5;
    mAttentionInfo.mDistances[3] = 6;
    mAttentionInfo.mFlags = 0x2000000A;

    setAnm(1, false);
    setMtx();
    mMorf->calc();

    mCullMtx = mMorf->getModel()->getBaseTRMtx();
    fopAcM_setCullSizeBox(this, -50.0f, 0.0f, -50.0f, 70.0f, 200.0f, 70.0f);
    mCullSizeFar = 10.0f;

    mStts.Init(0xFF, 0xFF, this);
    mCyl.Set(m_cyl_src);
    mCyl.SetStts(&mStts);

    mPayType = checkSendPrice();
    modeProc(PROC_INIT, 0);

    mAcchCir.SetWall(30.0f, 30.0f);
    mAcch.Set(&current.pos, &next.pos, this, 1, &mAcchCir, &speed, 0, 0);
    mAcch.SetRoofNone();
    mGravity = -4.5f;

    mEventCut.setActorInfo2("Tpost", this);
}

void daObjTpost_c::getArg() {
    return;
}

int daObjTpost_c::_create() {
    fopAcM_SetupActor(this, daObjTpost_c);

    getArg();
    int step = dComIfG_resLoad(&mPhs, m_arc_name);
    if(step == cPhs_COMPLEATE_e) {
        if(fopAcM_entrySolidHeap(this, &createHeap_CB, 0x7E0) == 0) {
            return cPhs_ERROR_e;
        }

        createInit();
    }

    return step;
}

bool daObjTpost_c::_delete() {
    dComIfG_resDelete(&mPhs, m_arc_name);
    return true;
}

static int daObjTpostCreate(void* i_this) {
    return static_cast<daObjTpost_c*>(i_this)->_create();
}

static BOOL daObjTpostDelete(void* i_this) {
    return static_cast<daObjTpost_c*>(i_this)->_delete();
}

static BOOL daObjTpostExecute(void* i_this) {
    return static_cast<daObjTpost_c*>(i_this)->_execute();
}

static BOOL daObjTpostDraw(void* i_this) {
    return static_cast<daObjTpost_c*>(i_this)->_draw();
}

static bool daObjTpostIsDelete(void*) {
    return true;
}


static actor_method_class daObjTpostMethodTable = {
    (process_method_func)daObjTpostCreate,
    (process_method_func)daObjTpostDelete,
    (process_method_func)daObjTpostExecute,
    (process_method_func)daObjTpostIsDelete,
    (process_method_func)daObjTpostDraw,
};

actor_process_profile_definition g_profile_OBJ_TORIPOST = {
    fpcLy_CURRENT_e,
    3,
    fpcPi_CURRENT_e,
    PROC_OBJ_TORIPOST,
    &g_fpcLf_Method.mBase,
    sizeof(daObjTpost_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x01B3,
    &daObjTpostMethodTable,
    0x18 | fopAcStts_SHOWMAP_e | fopAcStts_CULL_e | fopAcStts_UNK40000_e | fopAcStts_UNK200000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_4_e,
};
