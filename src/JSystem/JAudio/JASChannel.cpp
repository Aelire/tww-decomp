//
// Generated by dtk
// Translation Unit: JASChannel.cpp
//

#include "JSystem/JAudio/JASChannel.h"
#include "JSystem/JAudio/JASChAllocQueue.h"
#include "JSystem/JAudio/JASChannelMgr.h"
#include "JSystem/JAudio/JASDSPChannel.h"
#include "JSystem/JAudio/JASDSPInterface.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "dolphin/types.h"

/* 8028B3E8-8028B5A4       .text init__Q28JASystem8TChannelFv */
void JASystem::TChannel::init() {
    field_0x28 = 0;
    field_0x2c = 0;
    field_0x30 = 0;
    field_0x34 = 0;
    field_0x10 = NULL;
    field_0xc = 0;
    field_0x14 = 0;
    field_0x18 = 0;
    field_0x1c = 0;
    field_0xd4 = 0;
    if (!field_0x4) {
        field_0xb0[0] = 0x150;
        field_0xb0[1] = 0x210;
        field_0xb0[2] = 0x352;
        field_0xb0[3] = 0x412;
        field_0xb0[4] = 0;
        field_0xb0[5] = 0;
        field_0x48 = 0x10101;
        field_0x4c = 600;
        field_0x60[0] = 0x1a;
        field_0x60[1] = 1;
        field_0x60[2] = 1;
    } else {
        for (int i = 0; i < 6; i++) {
            field_0xb0[i] = field_0x4->field_0x4e[i];
        }
        field_0x48 = field_0x4->field_0x68;
        field_0x4c = field_0x4->field_0x6c;
        for (int i = 0; i < 3; i++) {
            field_0x60[i] = field_0x4->mCalcTypes[i];
        }
    }
    for (u32 i = 0; i < 4; i++) {
        JUT_ASSERT(155, osc[i]);
        osc[i]->field_0x0 = NULL;
        osc[i]->init();
    }
    mPauseFlag = 0;
    field_0xc8++;
    if (s32(field_0xc8) == 0) {
        field_0xc8 = 1;
    }
    field_0xe8 = 0;
}

/* 8028B5A4-8028B620       .text setOscillator__Q28JASystem8TChannelFUlPQ28JASystem11TOscillator */
void JASystem::TChannel::setOscillator(u32 oscnum, TOscillator* param_2) {
    JUT_ASSERT(173, oscnum < (4));
    osc[oscnum] = param_2;
}

/* 8028B620-8028B6A8       .text setOscInit__Q28JASystem8TChannelFUlPCQ38JASystem11TOscillator4Osc_ */
void JASystem::TChannel::setOscInit(u32 oscnum, const TOscillator::Osc_* param_2) {
    JUT_ASSERT(183, oscnum < (4));
    osc[oscnum]->field_0x0 = param_2;
    osc[oscnum]->initStart();
}

/* 8028B6A8-8028B73C       .text forceStopOsc__Q28JASystem8TChannelFUl */
bool JASystem::TChannel::forceStopOsc(u32 numosc) {
    /* Nonmatching */
    JUT_ASSERT(195, numosc < (4));
    return osc[numosc]->field_0x0 != NULL ? osc[numosc]->forceStop() : false;
}

/* 8028B73C-8028B7D0       .text releaseOsc__Q28JASystem8TChannelFUl */
bool JASystem::TChannel::releaseOsc(u32 numosc) {
    /* Nonmatching */
    JUT_ASSERT(209, numosc < (4));
    return osc[numosc]->field_0x0 ? osc[numosc]->release() : false;
}

/* 8028B7D0-8028B850       .text directReleaseOsc__Q28JASystem8TChannelFUlUs */
void JASystem::TChannel::directReleaseOsc(u32 oscnum, u16 param_2) {
    JUT_ASSERT(224, oscnum < (4));
    osc[oscnum]->field_0x18 = param_2;
}

/* 8028B850-8028B8E4       .text bankOscToOfs__Q28JASystem8TChannelFUl */
f32 JASystem::TChannel::bankOscToOfs(u32 oscnum) {
    /* Nonmatching */
    JUT_ASSERT(234, oscnum < (4));
    return osc[oscnum]->field_0x0 ? osc[oscnum]->getOffset() : 1.0f;
}

/* 8028B8E4-8028BA98       .text effectOsc__Q28JASystem8TChannelFUlf */
void JASystem::TChannel::effectOsc(u32 oscnum, f32 param_2) {
    /* Nonmatching */
}

/* 8028BA98-8028BB14       .text getOscState__Q28JASystem8TChannelCFUl */
int JASystem::TChannel::getOscState(u32 oscnum) const {
    /* Nonmatching */
    JUT_ASSERT(274, oscnum < (4));
    return osc[oscnum]->field_0x4;
}

/* 8028BB14-8028BB98       .text isOsc__Q28JASystem8TChannelFUl */
BOOL JASystem::TChannel::isOsc(u32 oscnum) {
    /* Nonmatching */
    JUT_ASSERT(284, oscnum < (4));
    return osc[oscnum]->field_0x0 != 0;
}

/* 8028BB98-8028BC78       .text copyOsc__Q28JASystem8TChannelFUlPQ38JASystem11TOscillator4Osc_ */
void JASystem::TChannel::copyOsc(u32 oscnum, TOscillator::Osc_* param_2) {
    /* Nonmatching */
    JUT_ASSERT(295, oscnum < (4));
    if (isOsc(oscnum)) {
        *param_2 = *osc[oscnum]->field_0x0;
    } else {
        OSReport("osc[%d] is NULL\n", oscnum);
    }
}

/* 8028BC78-8028BD10       .text overwriteOsc__Q28JASystem8TChannelFUlPQ38JASystem11TOscillator4Osc_ */
void JASystem::TChannel::overwriteOsc(u32 oscnum, TOscillator::Osc_* param_2) {
    JUT_ASSERT(308, oscnum < (4));
    setOscInit(oscnum, param_2);
    effectOsc(oscnum, bankOscToOfs(oscnum));
}

/* 8028BD10-8028BDA4       .text setKeySweepTarget__Q28JASystem8TChannelFUcUl */
void JASystem::TChannel::setKeySweepTarget(u8, u32) {
    /* Nonmatching */
}

/* 8028BDA4-8028BDAC       .text setPauseFlag__Q28JASystem8TChannelFUc */
void JASystem::TChannel::setPauseFlag(u8 param_1) {
    mPauseFlag = param_1;
}

/* 8028BDAC-8028BDBC       .text setPauseFlagReq__Q28JASystem8TChannelFUc */
void JASystem::TChannel::setPauseFlagReq(u8 param_1) {
    mPauseFlag = param_1;
    field_0x3 = 1;
}

/* 8028BDBC-8028BE64       .text setPanPower__Q28JASystem8TChannelFffff */
void JASystem::TChannel::setPanPower(f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    /* Nonmatching */
    f32 px = param_1 + param_2 + param_3;
    if (px == 0.0f) {
        OSReport("----- JASChannel::setPanPower : px == 0.0\n");
        px = 1.0f;
    }
    field_0x64.field_0x0 = param_1 / px;
    field_0x64.field_0x4 = param_2 / px;
    field_0x64.field_0x8 = param_3 / px;
}

/* 8028BE64-8028BEB8       .text checkLogicalChannel__Q28JASystem8TChannelFv */
BOOL JASystem::TChannel::checkLogicalChannel() {
    /* Nonmatching */
    if (!field_0x10 && field_0xc == 0) {
        OSReport("----- checkLC : 波形がアサインされていません\n");
        return false;
    }
    return true;
}

/* 8028BEB8-8028BF40       .text play__Q28JASystem8TChannelFUl */
BOOL JASystem::TChannel::play(u32 param_1) {
    /* Nonmatching */
    if (param_1 == 0) {
        param_1 = -1;
    }
    field_0x30 = param_1;
    field_0x34 = field_0x30;
    field_0x28 = &updatecallLogicalChannel;
    field_0x20 = NULL;
    if (!checkLogicalChannel()) {
        return false;
    }
    TDSPQueue::enQueue(this);
    field_0x4->addListTail(this, 3);
    return true;
}

/* 8028BF40-8028BFAC       .text stop__Q28JASystem8TChannelFUs */
void JASystem::TChannel::stop(u16 param_1) {
    if (!field_0x20) {
        updatecallLogicalChannel(this, 6);
    } else if (param_1 == 0) {
        updatecallLogicalChannel(this, 0);
    } else {
        directReleaseOsc(0, param_1);
        updatecallLogicalChannel(this, 0);
    }
}

/* 8028BFAC-8028C108       .text updateJcToDSP__Q28JASystem8TChannelFv */
void JASystem::TChannel::updateJcToDSP() {
    /* Nonmatching */
    DSPInterface::DSPBuffer* dspBuffer = field_0x20->field_0xc;
    if (field_0xd4) {
        for (u8 i = 0; i < 6; i++) {
            dspBuffer->setMixerVolumeOnly(i, field_0xbc[i]);
        }
        dspBuffer->setPitch(field_0xa0);
        dspBuffer->setPauseFlag(mPauseFlag);
        dspBuffer->flushChannel();
    } else {
        for (u8 i = 0; i < 6; i++) {
            dspBuffer->setMixerVolume(i, field_0xbc[i], field_0x4->field_0x5a[i]);
        }
        dspBuffer->setPitch(field_0xa0);
        if (field_0x4->field_0x61 & 0x20) {
            dspBuffer->setIIRFilterParam(field_0x4->field_0x3c);
        }
        if (field_0x4->field_0x61 & 0x1f) {
            dspBuffer->setFIR8FilterParam(field_0x4->field_0x2c);
        }
        dspBuffer->setFilterMode(field_0x4->field_0x61);
        dspBuffer->setDistFilter(field_0x4->field_0x4c);
        dspBuffer->setPauseFlag(mPauseFlag);
        field_0x20->field_0xc->flushChannel();
    }
}

/* 8028C108-8028C140       .text forceStopLogicalChannel__Q28JASystem8TChannelFv */
bool JASystem::TChannel::forceStopLogicalChannel() {
    if (!field_0x20) {
        return false;
    }
    field_0x20->forceStop();
    return true;
}

/* 8028C140-8028C1C0       .text stopLogicalChannel__Q28JASystem8TChannelFv */
bool JASystem::TChannel::stopLogicalChannel() {
    /* Nonmatching */
    if (!field_0x20) {
        OSReport("----- stopLC : DSP Ch is not assigned\n");
        return false;
    }
    field_0x20->mCallback = NULL;
    field_0x20->field_0x6 = 0;
    field_0x20->stop();
    TDSPChannel::free(field_0x20, u32(this));
    field_0x20 = NULL;
    return true;
}

/* 8028C1C0-8028C3A8       .text playLogicalChannel__Q28JASystem8TChannelFv */
int JASystem::TChannel::playLogicalChannel() {
    /* Nonmatching */
}

/* 8028C3A8-8028C62C       .text updateEffectorParam__Q28JASystem8TChannelFv */
void JASystem::TChannel::updateEffectorParam() {
    /* Nonmatching */
}

/* 8028C62C-8028C6C4       .text killBrokenLogicalChannels__Q28JASystem8TChannelFPQ28JASystem11TDSPChannel */
void JASystem::TChannel::killBrokenLogicalChannels(TDSPChannel*) {
    /* Nonmatching */
}

/* 8028C6C4-8028CABC       .text updatecallDSPChannel__Q28JASystem8TChannelFPQ28JASystem11TDSPChannelUl */
void JASystem::TChannel::updatecallDSPChannel(TDSPChannel*, u32) {
    /* Nonmatching */
}

/* 8028CABC-8028CB88       .text calcEffect__Q28JASystem8TChannelFPCQ38JASystem6Driver10PanMatrix_PCQ38JASystem6Driver10PanMatrix_Uc */
f32 JASystem::TChannel::calcEffect(const Driver::PanMatrix_*, const JASystem::Driver::PanMatrix_*, u8) {
    /* Nonmatching */
}

/* 8028CB88-8028CC90       .text calcPan__Q28JASystem8TChannelFPCQ38JASystem6Driver10PanMatrix_PCQ38JASystem6Driver10PanMatrix_Uc */
f32 JASystem::TChannel::calcPan(const Driver::PanMatrix_*, const Driver::PanMatrix_*, u8) {
    /* Nonmatching */
}

/* 8028CC90-8028CD90       .text updateJcToDSPInit__Q28JASystem8TChannelFv */
void JASystem::TChannel::updateJcToDSPInit() {
    /* Nonmatching */
    JASystem::DSPInterface::DSPBuffer * pBuffer = field_0x20->field_0xc;
    if (pBuffer->field_0xb0[0] == 0xFFFF) {
        pBuffer->initAutoMixer();
        pBuffer->setMixerInitDelayMax(field_0x4->field_0x60);
    }
}

/* 8028CD90-8028CEA8       .text updateAutoMixer__Q28JASystem8TChannelFffff */
void JASystem::TChannel::updateAutoMixer(f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    f32 level = param_1 <= 0.0f ? 0.0f : param_1 >= 1.0f ? 1.0f : param_1;
    field_0x20->field_0xc->setAutoMixer(level * Driver::getAutoLevel(), param_2 * 127.5f, param_4 * 127.5f, param_3 * 127.5f, field_0xb0[1]);
}

/* 8028CEA8-8028D128       .text updateMixer__Q28JASystem8TChannelFffff */
void JASystem::TChannel::updateMixer(f32, f32, f32, f32) {
    /* Nonmatching */
}

/* 8028D128-8028D218       .text extraUpdate__Q28JASystem8TChannelFPQ28JASystem8TChannelUl */
void JASystem::TChannel::extraUpdate(TChannel*, u32) {
    /* Nonmatching */
}

/* 8028D218-8028D3C0       .text updatecallLogicalChannel__Q28JASystem8TChannelFPQ28JASystem8TChannelUl */
void JASystem::TChannel::updatecallLogicalChannel(TChannel*, u32) {
    /* Nonmatching */
}
