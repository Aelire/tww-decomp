//
// Generated by dtk
// Translation Unit: JASWaveArcLoader.cpp
//

#include "JSystem/JAudio/JASWaveArcLoader.h"
#include "JSystem/JAudio/JASDvdThread.h"
#include "JSystem/JAudio/JASSystemHeap.h"
#include "JSystem/JKernel/JKRDvdAramRipper.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "MSL_C/string.h"

const u32 DIR_MAX = 64;

JASystem::Kernel::THeap JASystem::WaveArcLoader::sAramHeap(NULL);

/* 80287BD8-80287C24       .text init__Q28JASystem13WaveArcLoaderFv */
bool JASystem::WaveArcLoader::init() {
    u32 local_8;
    void* var1 = Kernel::allocFromSysAramFull(&local_8);
    if (!var1) {
        return false;
    }
    sAramHeap.initRootHeap(var1, local_8, Kernel::THeap::Type0);
    return true;
}

/* 80287C24-80287C30       .text getRootHeap__Q28JASystem13WaveArcLoaderFv */
JASystem::Kernel::THeap* JASystem::WaveArcLoader::getRootHeap() {
    return &sAramHeap;
}

char JASystem::WaveArcLoader::sCurrentDir[DIR_MAX] = "/Banks/";

namespace std {
    using ::strlen;
};

/* 80287C30-80287D24       .text setCurrentDir__Q28JASystem13WaveArcLoaderFPCc */
void JASystem::WaveArcLoader::setCurrentDir(const char* dir) {
    JUT_ASSERT(60, std::strlen(dir) < DIR_MAX);
    strcpy(sCurrentDir, dir);
    int len = strlen(sCurrentDir);
    if (sCurrentDir[len - 1] == '/') {
        return;
    }
    JUT_ASSERT(65, len+1 < DIR_MAX);
    sCurrentDir[len] = '/';
    sCurrentDir[len+1] = 0;
}

/* 80287D24-80287D30       .text getCurrentDir__Q28JASystem13WaveArcLoaderFv */
char* JASystem::WaveArcLoader::getCurrentDir() {
    return sCurrentDir;
}

/* 80287D30-80287DA4       .text __ct__Q28JASystem8TWaveArcFv */
JASystem::TWaveArc::TWaveArc() : mHeap(this) {
    field_0x4c = 0;
    field_0x68 = 0;
    mFileNo = -1;
    mSize = 0;
    field_0x74 = 0;
    OSInitMutex(&mMutex);
}

/* 80287DA4-80287E34       .text loadSetup__Q28JASystem8TWaveArcFUl */
bool JASystem::TWaveArc::loadSetup(u32 param_1) {
    OSLockMutex(&mMutex);
    if (field_0x74 != param_1) {
        OSUnlockMutex(&mMutex);
        return false;
    }
    if (field_0x68 != 1) {
        OSUnlockMutex(&mMutex);
        return false;
    }
    field_0x4c = 1;
    field_0x68 = 2;
    OSUnlockMutex(&mMutex);
    return true;
}

/* 80287E34-80287EB8       .text eraseSetup__Q28JASystem8TWaveArcFv */
bool JASystem::TWaveArc::eraseSetup() {
    OSLockMutex(&mMutex);
    if (field_0x68 == 0) {
        OSUnlockMutex(&mMutex);
        return false;
    }
    if (field_0x68 == 1) {
        field_0x68 = 0;
        OSUnlockMutex(&mMutex);
        return false;
    }
    field_0x4c = 0;
    field_0x68 = 0;
    OSUnlockMutex(&mMutex);
    return true;
}

struct unk_message {
    JASystem::TWaveArc* mpWaveArc;
    int mFileNo;
    void* field_0x8;
    u32 field_0xc;
};

/* 80287EB8-80287F48       .text loadToAramCallback__Q28JASystem8TWaveArcFPv */
s32 JASystem::TWaveArc::loadToAramCallback(void* param_1) {
    unk_message* msg = (unk_message*)param_1;
    if (JKRDvdAramRipper::loadToAram(msg->mFileNo, u32(msg->field_0x8), EXPAND_SWITCH_UNKNOWN0, 0, 0) == 0) {
        return -1;
    }
    TWaveArc* waveArc = msg->mpWaveArc;
    if (!waveArc->loadSetup(msg->field_0xc)) {
        return 0;
    }
    waveArc->onLoadDone();
    return 0;
}

/* 80287F48-80287FE4       .text sendLoadCmd__Q28JASystem8TWaveArcFv */
bool JASystem::TWaveArc::sendLoadCmd() {
    OSLockMutex(&mMutex);
    field_0x4c = 0;
    field_0x68 = 1;
    unk_message msg;
    msg.mpWaveArc = this;
    msg.mFileNo = mFileNo;
    msg.field_0x8 = mHeap.mBase;
    msg.field_0xc = ++field_0x74;
    OSUnlockMutex(&mMutex);
    if (!Dvd::sendCmdMsg(loadToAramCallback, &msg, sizeof(msg))) {
        mHeap.free();
        return false;
    }
    return true;
}

/* 80287FE4-802880A0       .text load__Q28JASystem8TWaveArcFPQ38JASystem6Kernel5THeap */
bool JASystem::TWaveArc::load(Kernel::THeap* heap) {
    if (mFileNo < 0)
        return false;

    OSLockMutex(&mMutex);
    if (field_0x68 != 0) {
        OSUnlockMutex(&mMutex);
        return false;
    }

    if (heap == NULL)
        heap = WaveArcLoader::getRootHeap();

    if (!mHeap.alloc(heap, mSize)) {
        OSUnlockMutex(&mMutex);
        return false;
    }

    bool ret = sendLoadCmd();
    OSUnlockMutex(&mMutex);
    return ret;
}

/* 802880A0-802880C4       .text erase__Q28JASystem8TWaveArcFv */
bool JASystem::TWaveArc::erase() {
    return mHeap.free();
}

/* 802880C4-8028810C       .text onDispose__Q28JASystem8TWaveArcFv */
void JASystem::TWaveArc::onDispose() {
    if (eraseSetup()) {
        onEraseDone();
    }
}

/* 8028810C-8028816C       .text setEntryNum__Q28JASystem8TWaveArcFl */
void JASystem::TWaveArc::setEntryNum(s32 entryNum) {
    DVDFileInfo file;
    if (entryNum >= 0 && DVDFastOpen(entryNum, &file)) {
        mSize = file.length;
        DVDClose(&file);
        mFileNo = entryNum;
    }
}

/* 8028816C-80288214       .text setFileName__Q28JASystem8TWaveArcFPCc */
void JASystem::TWaveArc::setFileName(const char* param_1) {
    char* currentDir = WaveArcLoader::getCurrentDir();
    size_t size = strlen(currentDir);
    size += strlen(param_1);
    char* str = new (JKRGetSystemHeap(), -4) char[size + 1];
    strcpy(str, currentDir);
    strcat(str, param_1);
    str[size] = 0;
    s32 entry = DVDConvertPathToEntrynum(str);
    delete[] str;
    if (entry >= 0) {
        setEntryNum(entry);
    }
}
