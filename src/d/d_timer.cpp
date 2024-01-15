//
// Generated by dtk
// Translation Unit: d_timer.cpp
//

#include "d/d_timer.h"
#include "d/d_com_inf_game.h"
#include "d/d_item.h"
#include "d/d_meter.h"
#include "d/d_procname.h"
#include "JSystem/J2DGraph/J2DScreen.h"
#include "JSystem/J2DGraph/J2DOrthoGraph.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JKernel/JKRSolidHeap.h"

u32 ShipRaceSeTable[] = {
    0x7530, JA_SE_SGAME_TIMER_30,
    0x4E20, JA_SE_SGAME_TIMER_30,
    0x2710, JA_SE_SGAME_TIMER_10,
    0x2328, JA_SE_SGAME_TIMER_10,
    0x1F40, JA_SE_SGAME_TIMER_10,
    0x1B58, JA_SE_SGAME_TIMER_10,
    0x1770, JA_SE_SGAME_TIMER_10,
    0x1388, JA_SE_SGAME_TIMER_10,
    0x0FA0, JA_SE_SGAME_TIMER_10,
    0x0BB8, JA_SE_SGAME_TIMER_10,
    0x07D0, JA_SE_SGAME_TIMER_10,
    0x03E8, JA_SE_SGAME_TIMER_10,
    0xFFFFFFFF, 0x0000,
};

u32 VolcanoSeTable[] = {
    0xEA60, JA_SE_MINIGAME_TIMER_30,
    0x7530, JA_SE_MINIGAME_TIMER_30,
    0x2710, JA_SE_MINIGAME_TIMER_10,
    0x2328, JA_SE_MINIGAME_TIMER_10,
    0x1F40, JA_SE_MINIGAME_TIMER_10,
    0x1B58, JA_SE_MINIGAME_TIMER_10,
    0x1770, JA_SE_MINIGAME_TIMER_10,
    0x1388, JA_SE_MINIGAME_TIMER_10,
    0x0FA0, JA_SE_MINIGAME_TIMER_10,
    0x0BB8, JA_SE_MINIGAME_TIMER_10,
    0x07D0, JA_SE_MINIGAME_TIMER_10,
    0x03E8, JA_SE_MINIGAME_TIMER_10,
    0xFFFFFFFF, 0x0000,
};

/* 8023B860-8023BCD8       .text _create__8dTimer_cFv */
s32 dTimer_c::_create() {
    /* Nonmatching */
    s32 rt = dComIfG_resLoad(&mPhs, "Timer");
    if (rt == cPhs_COMPLEATE_e) {
        fopMsg_prm_timer* prm = (fopMsg_prm_timer*)fopMsgM_GetAppend(this);
        if (prm == NULL)
            return cPhs_ERROR_e;

        dRes_info_c* resInfo = dComIfG_getObjectResInfo("Timer");
        JUT_ASSERT(0x44, resInfo != 0);

        if (prm->mIconType != 0) {
            mpSolidHeap = mDoExt_createSolidHeapFromGameToCurrent(0x4260, 0x20);
        } else {
            mpSolidHeap = mDoExt_createSolidHeapFromGameToCurrent(0x34C0, 0x20);
        }

        if (mpSolidHeap == NULL)
            return cPhs_ERROR_e;

        mpScrnDraw = new dDlst_TimerScrnDraw_c();
        mpScrnDraw->setScreen("ship_race0.blo", resInfo->getArchive());
        if (prm->mIconType != 0) {
            iconTex = JKRAllocFromHeap(mpSolidHeap, 0xC00, 0x20);
            JUT_ASSERT(0x5a, iconTex != 0);
            mpScrnDraw->setIconType(iconTex, prm->mIconType);
        }

        mDoExt_restoreCurrentHeap();
        mDoExt_adjustSolidHeap(mpSolidHeap);

        mpScrnDraw->setRupeePos(prm->mRupeePos.x, prm->mRupeePos.y);
        mpScrnDraw->setTimerPos(prm->mTimerPos.x, prm->mTimerPos.y);
        mpScrnDraw->setShowType(prm->mShowType);
        mType = prm->field_0x1c;
        if (mType == 7) {
        }
    }
}

/* 8023BCD8-8023BF88       .text _execute__8dTimer_cFv */
BOOL dTimer_c::_execute() {
    /* Nonmatching */
}

/* 8023BF88-8023BFE4       .text _draw__8dTimer_cFv */
BOOL dTimer_c::_draw() {
    /* Nonmatching */
}

/* 8023BFE4-8023C0B8       .text _delete__8dTimer_cFv */
BOOL dTimer_c::_delete() {
    /* Nonmatching */
}

/* 8023C0B8-8023C110       .text RestTimeCheck__8dTimer_cFi */
void dTimer_c::RestTimeCheck(int) {
    /* Nonmatching */
}

/* 8023C110-8023C124       .text deleteCheck__8dTimer_cFv */
void dTimer_c::deleteCheck() {
    /* Nonmatching */
}

/* 8023C124-8023C268       .text SetSE__8dTimer_cFv */
void dTimer_c::SetSE() {
    /* Nonmatching */
}

/* 8023C268-8023C2CC       .text start__8dTimer_cFv */
void dTimer_c::start() {
    /* Nonmatching */
}

/* 8023C2CC-8023C2F4       .text start__8dTimer_cFs */
void dTimer_c::start(s16) {
    /* Nonmatching */
}

/* 8023C2F4-8023C3A8       .text stock_start__8dTimer_cFv */
void dTimer_c::stock_start() {
    /* Nonmatching */
}

/* 8023C3A8-8023C3D0       .text stock_start__8dTimer_cFs */
void dTimer_c::stock_start(s16) {
    /* Nonmatching */
}

/* 8023C3D0-8023C454       .text stop__8dTimer_cFUc */
void dTimer_c::stop(u8) {
    /* Nonmatching */
}

/* 8023C454-8023C500       .text restart__8dTimer_cFUc */
void dTimer_c::restart(u8) {
    /* Nonmatching */
}

/* 8023C500-8023C56C       .text end__8dTimer_cFi */
void dTimer_c::end(int) {
    /* Nonmatching */
}

/* 8023C56C-8023C57C       .text deleteRequest__8dTimer_cFv */
void dTimer_c::deleteRequest() {
    /* Nonmatching */
}

/* 8023C57C-8023C5E0       .text getTimeMs__8dTimer_cFv */
void dTimer_c::getTimeMs() {
    /* Nonmatching */
}

/* 8023C5E0-8023C628       .text getLimitTimeMs__8dTimer_cFv */
void dTimer_c::getLimitTimeMs() {
    /* Nonmatching */
}

/* 8023C628-8023C69C       .text getRestTimeMs__8dTimer_cFv */
void dTimer_c::getRestTimeMs() {
    /* Nonmatching */
}

/* 8023C69C-8023CA24       .text setScreen__21dDlst_TimerScrnDraw_cFPCcP10JKRArchive */
void dDlst_TimerScrnDraw_c::setScreen(const char* file, JKRArchive* arc) {
    scrn = new J2DScreen();
    scrn->set(file, arc);
    field_0x22c = NULL;
    fopMsgM_setPaneData(&field_0x008, scrn->search('tim0'));
    fopMsgM_setPaneData(&field_0x040, scrn->search('cn00'));
    fopMsgM_setPaneData(&field_0x078, scrn->search('tt01'));
    fopMsgM_setPaneData(&field_0x0b0, scrn->search('tn01'));
    fopMsgM_setPaneData(&field_0x0e8, scrn->search('tn00'));
    fopMsgM_setPaneData(&field_0x120, scrn->search('tk00'));
    fopMsgM_setPaneData(&field_0x158, scrn->search('\x00rup'));
    fopMsgM_setPaneData(&field_0x190, scrn->search('ruxk'));
    fopMsgM_setPaneData(&field_0x1c8, scrn->search('rupk'));
    field_0x200 = scrn->search('tt02');
    field_0x204 = scrn->search('tt03');
    field_0x208 = scrn->search('tt04');
    field_0x20c = scrn->search('tt05');
    field_0x210 = scrn->search('tt06');

    field_0x214 = scrn->search('\x00ru1');
    field_0x218 = scrn->search('\x00ru2');
    field_0x21c = scrn->search('\x00ru3');

    field_0x220 = scrn->search('ruk1');
    field_0x224 = scrn->search('ruk2');
    field_0x228 = scrn->search('ruk3');

    setShowType(3);
}

/* 8023CA24-8023CA78       .text changeNumberTexture__21dDlst_TimerScrnDraw_cFP7J2DPanei */
void dDlst_TimerScrnDraw_c::changeNumberTexture(J2DPane* pane, int no) {
    if (no < 0 || no >= 10)
        no = 0;

    ((J2DPicture*)pane)->changeTexture(getNumber(no), 0);
}

/* 8023CA78-8023CA8C       .text getNumber__21dDlst_TimerScrnDraw_cFi */
const char* dDlst_TimerScrnDraw_c::getNumber(int no) {
    static const char* number[] = {
        "s_rupy_num_00.bti",
        "s_rupy_num_01.bti",
        "s_rupy_num_02.bti",
        "s_rupy_num_03.bti",
        "s_rupy_num_04.bti",
        "s_rupy_num_05.bti",
        "s_rupy_num_06.bti",
        "s_rupy_num_07.bti",
        "s_rupy_num_08.bti",
        "s_rupy_num_09.bti",
    };

    return number[no];
}

/* 8023CA8C-8023CCD8       .text setTimer__21dDlst_TimerScrnDraw_cFi */
void dDlst_TimerScrnDraw_c::setTimer(int time) {
    /* Nonmatching */
    s32 minsec = time / 1000;
    s32 min = minsec / 60;
    s32 sec = minsec % 60;
    changeNumberTexture(field_0x078.pane, min / 10);
    changeNumberTexture(field_0x200, min % 10);
    changeNumberTexture(field_0x204, sec / 10);
    changeNumberTexture(field_0x208, sec % 10);
    changeNumberTexture(field_0x20c, (time % 1000) / 100);
    changeNumberTexture(field_0x210, ((time % 1000) / 100) / 10);
    if (dComIfGp_event_getMode() == 1) {
        if (field_0x008.mUserArea < 5) {
            field_0x008.mUserArea++;
            s16 alphaStep = 5 - field_0x008.mUserArea;
            f32 alpha = ((f32)alphaStep * (f32)alphaStep) / 25.0f;
            fopMsgM_setNowAlpha(&field_0x008, alpha);
            fopMsgM_setNowAlpha(&field_0x040, alpha);
            fopMsgM_setNowAlpha(&field_0x078, alpha);
            fopMsgM_setNowAlpha(&field_0x0b0, alpha);
            fopMsgM_setNowAlpha(&field_0x0e8, alpha);
            fopMsgM_setNowAlpha(&field_0x120, alpha);
        }
    } else {
        if (field_0x008.mUserArea > 0) {
            field_0x008.mUserArea--;
            int alphaStep = 5 - field_0x008.mUserArea;
            f32 alpha = ((f32)alphaStep * (f32)alphaStep) / 25.0f;
            fopMsgM_setNowAlpha(&field_0x008, alpha);
            fopMsgM_setNowAlpha(&field_0x040, alpha);
            fopMsgM_setNowAlpha(&field_0x078, alpha);
            fopMsgM_setNowAlpha(&field_0x0b0, alpha);
            fopMsgM_setNowAlpha(&field_0x0e8, alpha);
            fopMsgM_setNowAlpha(&field_0x120, alpha);
        }
    }
}

/* 8023CCD8-8023CEF0       .text setRupee__21dDlst_TimerScrnDraw_cFs */
void dDlst_TimerScrnDraw_c::setRupee(s16 num) {
    /* Nonmatching */
    if (num != field_0x230) {
        if (num > field_0x230) {
            field_0x230++;
        } else {
            field_0x230--;
        }

        if (field_0x230 < 0)
            field_0x230 = 0;

        changeNumberTexture(field_0x21c, field_0x230 % 10);
        changeNumberTexture(field_0x218, (field_0x230 % 100) / 10);
        changeNumberTexture(field_0x214, field_0x230 / 100);

        changeNumberTexture(field_0x228, field_0x230 % 10);
        changeNumberTexture(field_0x224, (field_0x230 % 100) / 10);
        changeNumberTexture(field_0x220, field_0x230 / 100);
    }

    
    if (dComIfGp_event_getMode() == 1) {
        if (field_0x158.mUserArea < 5) {
            field_0x158.mUserArea++;
            s16 alphaStep = 5 - field_0x008.mUserArea;
            f32 alpha = 1.0f - ((f32)alphaStep * (f32)alphaStep) / 25.0f;
            fopMsgM_setNowAlpha(&field_0x158, alpha);
            fopMsgM_setNowAlpha(&field_0x190, alpha);
            fopMsgM_setNowAlpha(&field_0x1c8, alpha);
        }
    } else {
        if (field_0x158.mUserArea > 0) {
            field_0x158.mUserArea--;
            s16 alphaStep = 5 - field_0x008.mUserArea;
            f32 alpha = 1.0f - ((f32)alphaStep * (f32)alphaStep) / 25.0f;
            fopMsgM_setNowAlpha(&field_0x158, alpha);
            fopMsgM_setNowAlpha(&field_0x190, alpha);
            fopMsgM_setNowAlpha(&field_0x1c8, alpha);
        }
    }
}

/* 8023CEF0-8023CF48       .text dTm_parentPaneScale__FP18fopMsgM_pane_classP18fopMsgM_pane_classf */
void dTm_parentPaneScale(fopMsgM_pane_class* pane, fopMsgM_pane_class* parent, f32 scale) {
    pane->mPosCenter.x = parent->mPosCenter.x + scale * (pane->mPosCenterOrig.x - parent->mPosCenterOrig.x);
    pane->mPosCenter.y = parent->mPosCenter.y + scale * (pane->mPosCenterOrig.y - parent->mPosCenterOrig.y);
    fopMsgM_paneScaleXY(pane, scale);
}

/* 8023CF48-8023CF98       .text setPaneInitialPos__21dDlst_TimerScrnDraw_cFP18fopMsgM_pane_classff */
void dDlst_TimerScrnDraw_c::setPaneInitialPos(fopMsgM_pane_class* pane, f32 x, f32 y) {
    pane->mPosCenterOrig.x = x + pane->mSizeOrig.x / 2.0f;
    pane->mPosCenterOrig.y = y + pane->mSizeOrig.y / 2.0f;
    fopMsgM_paneTrans(pane, 0.0f, 0.0f);
}

/* 8023CF98-8023D0CC       .text setTimerPos__21dDlst_TimerScrnDraw_cFff */
void dDlst_TimerScrnDraw_c::setTimerPos(f32 x, f32 y) {
    setPaneInitialPos(&field_0x008, x, y);
    setPaneInitialPos(&field_0x040, x + field_0x040.mPosTopLeftOrig.x - field_0x008.mPosTopLeftOrig.x, y + field_0x040.mPosTopLeftOrig.y - field_0x008.mPosTopLeftOrig.y);
    setPaneInitialPos(&field_0x078, x + field_0x078.mPosTopLeftOrig.x - field_0x008.mPosTopLeftOrig.x, y + field_0x078.mPosTopLeftOrig.y - field_0x008.mPosTopLeftOrig.y);
    setPaneInitialPos(&field_0x0b0, x + field_0x0b0.mPosTopLeftOrig.x - field_0x008.mPosTopLeftOrig.x, y + field_0x0b0.mPosTopLeftOrig.y - field_0x008.mPosTopLeftOrig.y);
    setPaneInitialPos(&field_0x0e8, x + field_0x0e8.mPosTopLeftOrig.x - field_0x008.mPosTopLeftOrig.x, y + field_0x0e8.mPosTopLeftOrig.y - field_0x008.mPosTopLeftOrig.y);
    setPaneInitialPos(&field_0x120, x + field_0x120.mPosTopLeftOrig.x - field_0x008.mPosTopLeftOrig.x, y + field_0x120.mPosTopLeftOrig.y - field_0x008.mPosTopLeftOrig.y);
}

/* 8023D0CC-8023D128       .text setRupeePos__21dDlst_TimerScrnDraw_cFff */
void dDlst_TimerScrnDraw_c::setRupeePos(f32 x, f32 y) {
    setPaneInitialPos(&field_0x158, x, y);
    setPaneInitialPos(&field_0x1c8, x, y);
}

/* 8023D128-8023D1F8       .text setShowType__21dDlst_TimerScrnDraw_cFUc */
void dDlst_TimerScrnDraw_c::setShowType(u8 type) {
    if (type & 1) {
        field_0x008.pane->show();
        field_0x040.pane->show();
        field_0x078.pane->show();
        field_0x0b0.pane->show();
        field_0x0e8.pane->show();
        field_0x120.pane->show();
    } else {
        field_0x008.pane->hide();
        field_0x040.pane->hide();
        field_0x078.pane->hide();
        field_0x0b0.pane->hide();
        field_0x0e8.pane->hide();
        field_0x120.pane->hide();
    }

    if (type & 2) {
        field_0x158.pane->show();
        field_0x1c8.pane->show();
        if (field_0x22c != NULL)
            field_0x22c->show();
    } else {
        field_0x158.pane->hide();
        field_0x1c8.pane->hide();
        if (field_0x22c != NULL)
            field_0x22c->hide();
    }
}

/* 8023D1F8-8023D318       .text setIconType__21dDlst_TimerScrnDraw_cFPvUc */
void dDlst_TimerScrnDraw_c::setIconType(void* tex, u8 type) {
    /* Nonmatching */

    u32 itemNo;
    switch (type) {
    case 0:
    case 1:
    case 2:
    case 3:
        itemNo = dComIfGs_getSelectEquip(0);
        break;
    case 4:
        itemNo = LETTER00;
        break;
    default:
        itemNo = (u32)tex;
        break;
    }

    JKRArchive::readTypeResource(tex, 0xC00, 'TIMG', dItem_data::getTexture(itemNo), dComIfGp_getItemIconArchive());
    field_0x22c = new J2DPicture();
    ((J2DPicture*)field_0x158.pane)->setWhite(JUtility::TColor(0));
    ((J2DPicture*)field_0x1c8.pane)->setWhite(JUtility::TColor(0));
    field_0x22c->setAlpha(0);
}

/* 8023D318-8023D644       .text anime__21dDlst_TimerScrnDraw_cFv */
void dDlst_TimerScrnDraw_c::anime() {
    /* Nonmatching */
}

/* 8023D644-8023D848       .text closeAnime__21dDlst_TimerScrnDraw_cFv */
bool dDlst_TimerScrnDraw_c::closeAnime() {
    /* Nonmatching */
    bool ret = false;
    field_0x234++;
    if (field_0x234 <= 7) {
        s32 alphaStep = 7 - field_0x234;
        f32 alpha = ((f32)alphaStep * (f32)alphaStep) / 49.0f;
        f32 x = (((f32)field_0x234 * (f32)field_0x234) / 49.0f) * -50.0f;
        fopMsgM_paneTrans(&field_0x008, x, 0.0f);
        fopMsgM_paneTrans(&field_0x040, x, 0.0f);
        fopMsgM_paneTrans(&field_0x0b0, x, 0.0f);
        fopMsgM_paneTrans(&field_0x0e8, x, 0.0f);
        fopMsgM_paneTrans(&field_0x120, x, 0.0f);
        fopMsgM_setNowAlpha(&field_0x008, alpha);
        fopMsgM_setNowAlpha(&field_0x040, alpha);
        fopMsgM_setNowAlpha(&field_0x078, alpha);
        fopMsgM_setNowAlpha(&field_0x0b0, alpha);
        fopMsgM_setNowAlpha(&field_0x0e8, alpha);
        fopMsgM_setNowAlpha(&field_0x120, alpha);
        fopMsgM_paneTrans(&field_0x158, x + g_menuHIO.field_0x9a, g_menuHIO.field_0x9c);
        fopMsgM_setNowAlpha(&field_0x158, alpha);
        fopMsgM_setNowAlpha(&field_0x190, alpha);
        fopMsgM_setNowAlpha(&field_0x1c8, alpha);
    }

    if (field_0x234 >= 7)
        ret = true;

    return ret;
}

/* 8023D848-8023D8BC       .text hide__21dDlst_TimerScrnDraw_cFv */
bool dDlst_TimerScrnDraw_c::hide() {
    fopMsgM_setNowAlphaZero(&field_0x008);
    fopMsgM_setNowAlphaZero(&field_0x040);
    fopMsgM_setNowAlphaZero(&field_0x078);
    fopMsgM_setNowAlphaZero(&field_0x0b0);
    fopMsgM_setNowAlphaZero(&field_0x0e8);
    fopMsgM_setNowAlphaZero(&field_0x120);
    fopMsgM_setNowAlphaZero(&field_0x158);
    fopMsgM_setNowAlphaZero(&field_0x190);
    fopMsgM_setNowAlphaZero(&field_0x1c8);
    return true;
}

/* 8023D8BC-8023D9A0       .text draw__21dDlst_TimerScrnDraw_cFv */
void dDlst_TimerScrnDraw_c::draw() {
    /* Nonmatching */
    fopMsgM_setAlpha(&field_0x008);
    fopMsgM_setAlpha(&field_0x040);
    fopMsgM_setAlpha(&field_0x078);
    fopMsgM_setAlpha(&field_0x0b0);
    fopMsgM_setAlpha(&field_0x0e8);
    fopMsgM_setAlpha(&field_0x120);
    fopMsgM_setAlpha(&field_0x158);
    fopMsgM_setAlpha(&field_0x190);
    fopMsgM_setAlpha(&field_0x1c8);
    J2DOrthoGraph* graf = dComIfGp_getCurrentGrafPort();
    graf->setPort();
    scrn->draw(0.0f, 0.0f, graf);
    if (field_0x22c != NULL) {
        field_0x22c->draw(field_0x158.mPosTopLeft.x, field_0x158.mPosTopLeft.y, field_0x158.mSize.x, field_0x158.mSize.y, false, false, false);
        field_0x22c->setAlpha(field_0x158.mNowAlpha);
    }
}

/* 8023D9A0-8023D9C0       .text dTimer_Draw__FP8dTimer_c */
BOOL dTimer_Draw(dTimer_c* i_this) {
    return i_this->_draw();
}

/* 8023D9C0-8023D9E0       .text dTimer_Execute__FP8dTimer_c */
BOOL dTimer_Execute(dTimer_c* i_this) {
    return i_this->_execute();
}

/* 8023D9E0-8023D9E8       .text dTimer_IsDelete__FP8dTimer_c */
BOOL dTimer_IsDelete(dTimer_c* i_this) {
    return TRUE;
}

/* 8023D9E8-8023DA08       .text dTimer_Delete__FP8dTimer_c */
BOOL dTimer_Delete(dTimer_c* i_this) {
    return i_this->_delete();
}

/* 8023DA08-8023DA28       .text dTimer_Create__FP9msg_class */
s32 dTimer_Create(msg_class* i_this) {
    return ((dTimer_c*)i_this)->_create();
}

/* 8023DA28-8023DA88       .text dTimer_createTimer__FiUsUcUcffff */
s32 dTimer_createTimer(int param_1, u16 param_2, u8 param_3, u8 param_4, f32 param_5, f32 param_6, f32 param_7, f32 param_8) {
    if (dComIfG_getTimerMode() == -1)
        return fop_Timer_create(PROC_TIMER, param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, NULL);
    return -1;
}

/* 8023DA88-8023DAEC       .text dTimer_createStockTimer__Fv */
s32 dTimer_createStockTimer() {
    if (dComIfG_getTimerMode() != -1)
        return fop_Timer_create(PROC_TIMER, 7, 0, 3, 0, 221.0f, 439.0f, 32.0f, 419.0f, NULL);
    return -1;
}

/* 8023DAEC-8023DB48       .text __dt__21dDlst_TimerScrnDraw_cFv */
dDlst_TimerScrnDraw_c::~dDlst_TimerScrnDraw_c() {
}

msg_method_class l_dTimer_Method = {
    (process_method_func)dTimer_Create,
    (process_method_func)dTimer_Delete,
    (process_method_func)dTimer_Execute,
    (process_method_func)dTimer_IsDelete,
    (process_method_func)dTimer_Draw,
};

msg_process_profile_definition g_profile_TIMER = {
    /* LayerID      */ fpcLy_CURRENT_e,
    /* ListID       */ 12,
    /* ListPrio     */ fpcPi_CURRENT_e,
    /* ProcName     */ PROC_TIMER,
    /* Proc SubMtd  */ &g_fpcLf_Method.mBase,
    /* Size         */ sizeof(dTimer_c),
    /* SizeOther    */ 0,
    /* Parameters   */ 0,
    /* Leaf SubMtd  */ &g_fopMsg_Method,
    /* Priority     */ 0x01D2,
    /* Msg SubMtd   */ &l_dTimer_Method,
};
