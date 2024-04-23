#ifndef RES_DEMO23_H
#define RES_DEMO23_H

enum DEMO23_RES_FILE_ID {
    /* STB */
    DEMO23_STB_RESCUE=0x0,
    
    /* BTK */
    DEMO23_BTK_23_LS_CUT04_TURN=0x1,
    DEMO23_BTK_23_LS_CUT05_TETORALOOK_O=0x2,
    DEMO23_BTK_23_LS_CUT10_CRYWAIT_L=0x3,
    DEMO23_BTK_23_LS_CUT10_WARAU_O=0x4,
    DEMO23_BTK_23_LS_CUT13_LOOKTETORA_L=0x5,
    DEMO23_BTK_23_LS_CUT13_LOOKTORINK_O=0x6,
    DEMO23_BTK_23_ZL_CUT06_KIZUKU_O=0x7,
    DEMO23_BTK_23_ZL_CUT06_MEIREI_L=0x8,
    DEMO23_BTK_23_ZL_CUT06_WAIT_L=0x9,
    DEMO23_BTK_23_ZL_CUT08_KIZUKUWAIT_L=0xA,
    DEMO23_BTK_23_ZL_CUT08_OPEN_O=0xB,
    DEMO23_BTK_23_ZL_CUT08_OPENWAIT_L=0xC,
    DEMO23_BTK_23_ZL_CUT12_HANDUP_O=0xD,
    DEMO23_BTK_23_ZL_CUT12_HANDUPWAIT_L=0xE,
    DEMO23_BTK_23_ZL_CUT13_HANDPOINT_O=0xF,
    DEMO23_BTK_23_ZL_CUT13_HANDPOINTWAIT_L=0x10,
    DEMO23_BTK_23_ZL_CUT14_LOOKG_O=0x11,
    DEMO23_BTK_23_ZL_CUT14_LOOKGB_O=0x12,
    DEMO23_BTK_23_ZL_CUT14_LOOKGBWAIT_L=0x13,
    DEMO23_BTK_23_ZL_CUT14_LOOKGWAIT_L=0x14,
    DEMO23_BTK_23_ZL_CUT20_FURIKAERI_O=0x15,
    DEMO23_BTK_23_ZL_CUT20_FURIKAERIWAIT_L=0x16,
    DEMO23_BTK_23_ZL_CUT20_RUN_O=0x17,
    DEMO23_BTK_LS_DEMOLOOK=0x82,
    
    /* BTP */
    DEMO23_BTP_23_LS_CUT04_ORIWAIT_L=0x18,
    DEMO23_BTP_23_LS_CUT04_TURNWAIT_L=0x19,
    DEMO23_BTP_23_LS_CUT05_RUNWAIT_L=0x1A,
    DEMO23_BTP_23_LS_CUT05_TETORLOOKWAIT_L=0x1B,
    DEMO23_BTP_23_LS_CUT10_CRYWAIT_L=0x1C,
    DEMO23_BTP_23_LS_CUT13_LOOKTETORA_L=0x1D,
    DEMO23_BTP_23_LS_CUT13_LOOKWAIT_L=0x1E,
    DEMO23_BTP_23_LS_CUT16_TAKEOUTRUN_L=0x1F,
    DEMO23_BTP_23_ZL_CUT06_MEIREI_L=0x20,
    DEMO23_BTP_23_ZL_CUT06_WAIT_L=0x21,
    DEMO23_BTP_23_ZL_CUT08_KIZUKUWAIT_L=0x22,
    DEMO23_BTP_23_ZL_CUT08_OPENWAIT_L=0x23,
    DEMO23_BTP_23_ZL_CUT12_HANDUPWAIT_L=0x24,
    DEMO23_BTP_23_ZL_CUT13_HANDPOINTWAIT_L=0x25,
    DEMO23_BTP_23_ZL_CUT14_LOOKGBWAIT_L=0x26,
    DEMO23_BTP_23_ZL_CUT14_LOOKGWAIT_L=0x27,
    DEMO23_BTP_23_ZL_CUT20_FURIKAERIWAIT_L=0x28,
    DEMO23_BTP_23_P1A_CUT07_KEY_L=0x29,
    DEMO23_BTP_23_P1A_CUT14_HANDUPWAIT_L=0x2A,
    DEMO23_BTP_23_P1A_CUT16_TAKEOUTRUN_L=0x2B,
    DEMO23_BTP_07_PM_CUT3WAITB=0x4A,
    DEMO23_BTP_07_KM_CUT3WAITA=0x4B,
    DEMO23_BTP_07_KM_CUT3WAITB=0x4C,
    DEMO23_BTP_07_PM_CUT3FURIMUKI=0x4D,
    DEMO23_BTP_07_PM_CUT3WAITA=0x4E,
    DEMO23_BTP_07_KM_CUT3FURIMUKI=0x4F,
    DEMO23_BTP_23_ZL_CUT06_KIZUKU_O=0x56,
    DEMO23_BTP_23_ZL_CUT08_OPEN_O=0x57,
    DEMO23_BTP_23_ZL_CUT12_HANDUP_O=0x58,
    DEMO23_BTP_23_ZL_CUT13_HANDPOINT_O=0x59,
    DEMO23_BTP_23_ZL_CUT14_LOOKG_O=0x5A,
    DEMO23_BTP_23_ZL_CUT14_LOOKGB_O=0x5B,
    DEMO23_BTP_23_ZL_CUT20_FURIKAERI_O=0x5C,
    DEMO23_BTP_23_ZL_CUT20_RUN_O=0x5D,
    DEMO23_BTP_23_P1A_CUT14_HANDUP_O=0x5E,
    DEMO23_BTP_23_P1A_CUT14_RUNNING_O=0x5F,
    DEMO23_BTP_23_P1A_CUT14_TURNRUN_O=0x60,
    DEMO23_BTP_23_P1A_CUT15_TAKEOUT_O=0x61,
    DEMO23_BTP_23_LS_CUT04_TURN_O=0x62,
    DEMO23_BTP_23_LS_CUT05_RUNNING_O=0x63,
    DEMO23_BTP_23_LS_CUT05_TETORLOOK_O=0x64,
    DEMO23_BTP_23_LS_CUT10_WARAU_O=0x65,
    DEMO23_BTP_23_LS_CUT13_LOOKTORINK_O=0x66,
    DEMO23_BTP_23_LS_CUT15_TAKEOUT_O=0x67,
    
    /* BCKS */
    DEMO23_BCK_23_LS_CUT04_ORIWAIT_L=0x2C,
    DEMO23_BCK_23_LS_CUT04_TURNWAIT_L=0x2D,
    DEMO23_BCK_23_LS_CUT05_RUNWAIT_L=0x2E,
    DEMO23_BCK_23_LS_CUT05_TETORLOOKWAIT_L=0x2F,
    DEMO23_BCK_23_LS_CUT10_CRYWAIT_L=0x30,
    DEMO23_BCK_23_LS_CUT13_LOOKTETORA_L=0x31,
    DEMO23_BCK_23_LS_CUT13_LOOKWAIT_L=0x32,
    DEMO23_BCK_23_LS_CUT16_TAKEOUTRUN_L=0x33,
    DEMO23_BCK_23_MD_CUT10_TAKEOUT_L=0x34,
    DEMO23_BCK_23_P1A_CUT06_WALK_L=0x35,
    DEMO23_BCK_23_P1A_CUT07_KEY_L=0x36,
    DEMO23_BCK_23_P1A_CUT10_TAKEOUT_L=0x37,
    DEMO23_BCK_23_P1A_CUT14_HANDUPWAIT_L=0x38,
    DEMO23_BCK_23_P1A_CUT16_TAKEOUTRUN_L=0x39,
    DEMO23_BCK_23_P1B_CUT10_TAKEOUT_L=0x3A,
    DEMO23_BCK_23_PM_CUT10_TAKEOUT_L=0x3B,
    DEMO23_BCK_23_ZL_CUT06_MEIREI_L=0x3C,
    DEMO23_BCK_23_ZL_CUT06_WAIT_L=0x3D,
    DEMO23_BCK_23_ZL_CUT08_KIZUKUWAIT_L=0x3E,
    DEMO23_BCK_23_ZL_CUT08_OPENWAIT_L=0x3F,
    DEMO23_BCK_23_ZL_CUT12_HANDUPWAIT_L=0x40,
    DEMO23_BCK_23_ZL_CUT13_HANDPOINTWAIT_L=0x41,
    DEMO23_BCK_23_ZL_CUT14_LOOKGBWAIT_L=0x42,
    DEMO23_BCK_23_ZL_CUT14_LOOKGWAIT_L=0x43,
    DEMO23_BCK_23_ZL_CUT18_RUN_L=0x44,
    DEMO23_BCK_23_ZL_CUT20_FURIKAERIWAIT_L=0x45,
    DEMO23_BCK_DK_MAJYUTO_DEMO1=0x46,
    DEMO23_BCK_07_KM_CUT3FURIMUKI=0x50,
    DEMO23_BCK_07_KM_CUT3WAITA=0x51,
    DEMO23_BCK_07_KM_CUT3WAITB=0x52,
    DEMO23_BCK_07_PM_CUT3FURIMUKI=0x53,
    DEMO23_BCK_07_PM_CUT3WAITA=0x54,
    DEMO23_BCK_07_PM_CUT3WAITB=0x55,
    DEMO23_BCK_23_LS_CUT04_TURN_O=0x68,
    DEMO23_BCK_23_LS_CUT05_RUNNING_O=0x69,
    DEMO23_BCK_23_LS_CUT05_TETORLOOK_O=0x6A,
    DEMO23_BCK_23_LS_CUT10_WARAU_O=0x6B,
    DEMO23_BCK_23_LS_CUT13_LOOKTORINK_O=0x6C,
    DEMO23_BCK_23_LS_CUT15_TAKEOUT_O=0x6D,
    DEMO23_BCK_23_P1A_CUT14_HANDUP_O=0x6E,
    DEMO23_BCK_23_P1A_CUT14_RUNNING_O=0x6F,
    DEMO23_BCK_23_P1A_CUT14_TURNRUN_O=0x70,
    DEMO23_BCK_23_P1A_CUT15_TAKEOUT_O=0x71,
    DEMO23_BCK_23_ZL_CUT06_KIZUKU_O=0x72,
    DEMO23_BCK_23_ZL_CUT08_OPEN_O=0x73,
    DEMO23_BCK_23_ZL_CUT12_HANDUP_O=0x74,
    DEMO23_BCK_23_ZL_CUT13_HANDPOINT_O=0x75,
    DEMO23_BCK_23_ZL_CUT14_LOOKG_O=0x76,
    DEMO23_BCK_23_ZL_CUT14_LOOKGB_O=0x77,
    DEMO23_BCK_23_ZL_CUT20_FURIKAERI_O=0x78,
    DEMO23_BCK_23_ZL_CUT20_RUN_O=0x79,
    DEMO23_BCK_P1_WAIT=0x7A,
    DEMO23_BCK_P1_WAIT02=0x7B,
    DEMO23_BCK_07B_DK_CUT8_HOBA=0x7D,
    
    /* BDL */
    DEMO23_BDL_DK_COMP=0x49,
    DEMO23_BDL_SDOOR01=0x81,
    
    /* BDLM */
    DEMO23_BDL_DM=0x7E,
    DEMO23_BDL_KM=0x7F,
    DEMO23_BDL_PM=0x80,
};

enum DEMO23_RES_FILE_INDEX {
    /* STB */
    DEMO23_INDEX_STB_RESCUE=0x8,
    
    /* BTK */
    DEMO23_INDEX_BTK_23_LS_CUT04_TURN=0xB,
    DEMO23_INDEX_BTK_23_LS_CUT05_TETORALOOK_O=0xC,
    DEMO23_INDEX_BTK_23_LS_CUT10_CRYWAIT_L=0xD,
    DEMO23_INDEX_BTK_23_LS_CUT10_WARAU_O=0xE,
    DEMO23_INDEX_BTK_23_LS_CUT13_LOOKTETORA_L=0xF,
    DEMO23_INDEX_BTK_23_LS_CUT13_LOOKTORINK_O=0x10,
    DEMO23_INDEX_BTK_23_ZL_CUT06_KIZUKU_O=0x11,
    DEMO23_INDEX_BTK_23_ZL_CUT06_MEIREI_L=0x12,
    DEMO23_INDEX_BTK_23_ZL_CUT06_WAIT_L=0x13,
    DEMO23_INDEX_BTK_23_ZL_CUT08_KIZUKUWAIT_L=0x14,
    DEMO23_INDEX_BTK_23_ZL_CUT08_OPEN_O=0x15,
    DEMO23_INDEX_BTK_23_ZL_CUT08_OPENWAIT_L=0x16,
    DEMO23_INDEX_BTK_23_ZL_CUT12_HANDUP_O=0x17,
    DEMO23_INDEX_BTK_23_ZL_CUT12_HANDUPWAIT_L=0x18,
    DEMO23_INDEX_BTK_23_ZL_CUT13_HANDPOINT_O=0x19,
    DEMO23_INDEX_BTK_23_ZL_CUT13_HANDPOINTWAIT_L=0x1A,
    DEMO23_INDEX_BTK_23_ZL_CUT14_LOOKG_O=0x1B,
    DEMO23_INDEX_BTK_23_ZL_CUT14_LOOKGB_O=0x1C,
    DEMO23_INDEX_BTK_23_ZL_CUT14_LOOKGBWAIT_L=0x1D,
    DEMO23_INDEX_BTK_23_ZL_CUT14_LOOKGWAIT_L=0x1E,
    DEMO23_INDEX_BTK_23_ZL_CUT20_FURIKAERI_O=0x1F,
    DEMO23_INDEX_BTK_23_ZL_CUT20_FURIKAERIWAIT_L=0x20,
    DEMO23_INDEX_BTK_23_ZL_CUT20_RUN_O=0x21,
    DEMO23_INDEX_BTK_LS_DEMOLOOK=0x22,
    
    /* BTP */
    DEMO23_INDEX_BTP_23_LS_CUT04_ORIWAIT_L=0x25,
    DEMO23_INDEX_BTP_23_LS_CUT04_TURNWAIT_L=0x26,
    DEMO23_INDEX_BTP_23_LS_CUT05_RUNWAIT_L=0x27,
    DEMO23_INDEX_BTP_23_LS_CUT05_TETORLOOKWAIT_L=0x28,
    DEMO23_INDEX_BTP_23_LS_CUT10_CRYWAIT_L=0x29,
    DEMO23_INDEX_BTP_23_LS_CUT13_LOOKTETORA_L=0x2A,
    DEMO23_INDEX_BTP_23_LS_CUT13_LOOKWAIT_L=0x2B,
    DEMO23_INDEX_BTP_23_LS_CUT16_TAKEOUTRUN_L=0x2C,
    DEMO23_INDEX_BTP_23_ZL_CUT06_MEIREI_L=0x2D,
    DEMO23_INDEX_BTP_23_ZL_CUT06_WAIT_L=0x2E,
    DEMO23_INDEX_BTP_23_ZL_CUT08_KIZUKUWAIT_L=0x2F,
    DEMO23_INDEX_BTP_23_ZL_CUT08_OPENWAIT_L=0x30,
    DEMO23_INDEX_BTP_23_ZL_CUT12_HANDUPWAIT_L=0x31,
    DEMO23_INDEX_BTP_23_ZL_CUT13_HANDPOINTWAIT_L=0x32,
    DEMO23_INDEX_BTP_23_ZL_CUT14_LOOKGBWAIT_L=0x33,
    DEMO23_INDEX_BTP_23_ZL_CUT14_LOOKGWAIT_L=0x34,
    DEMO23_INDEX_BTP_23_ZL_CUT20_FURIKAERIWAIT_L=0x35,
    DEMO23_INDEX_BTP_23_P1A_CUT07_KEY_L=0x36,
    DEMO23_INDEX_BTP_23_P1A_CUT14_HANDUPWAIT_L=0x37,
    DEMO23_INDEX_BTP_23_P1A_CUT16_TAKEOUTRUN_L=0x38,
    DEMO23_INDEX_BTP_07_PM_CUT3WAITB=0x39,
    DEMO23_INDEX_BTP_07_KM_CUT3WAITA=0x3A,
    DEMO23_INDEX_BTP_07_KM_CUT3WAITB=0x3B,
    DEMO23_INDEX_BTP_07_PM_CUT3FURIMUKI=0x3C,
    DEMO23_INDEX_BTP_07_PM_CUT3WAITA=0x3D,
    DEMO23_INDEX_BTP_07_KM_CUT3FURIMUKI=0x3E,
    DEMO23_INDEX_BTP_23_ZL_CUT06_KIZUKU_O=0x3F,
    DEMO23_INDEX_BTP_23_ZL_CUT08_OPEN_O=0x40,
    DEMO23_INDEX_BTP_23_ZL_CUT12_HANDUP_O=0x41,
    DEMO23_INDEX_BTP_23_ZL_CUT13_HANDPOINT_O=0x42,
    DEMO23_INDEX_BTP_23_ZL_CUT14_LOOKG_O=0x43,
    DEMO23_INDEX_BTP_23_ZL_CUT14_LOOKGB_O=0x44,
    DEMO23_INDEX_BTP_23_ZL_CUT20_FURIKAERI_O=0x45,
    DEMO23_INDEX_BTP_23_ZL_CUT20_RUN_O=0x46,
    DEMO23_INDEX_BTP_23_P1A_CUT14_HANDUP_O=0x47,
    DEMO23_INDEX_BTP_23_P1A_CUT14_RUNNING_O=0x48,
    DEMO23_INDEX_BTP_23_P1A_CUT14_TURNRUN_O=0x49,
    DEMO23_INDEX_BTP_23_P1A_CUT15_TAKEOUT_O=0x4A,
    DEMO23_INDEX_BTP_23_LS_CUT04_TURN_O=0x4B,
    DEMO23_INDEX_BTP_23_LS_CUT05_RUNNING_O=0x4C,
    DEMO23_INDEX_BTP_23_LS_CUT05_TETORLOOK_O=0x4D,
    DEMO23_INDEX_BTP_23_LS_CUT10_WARAU_O=0x4E,
    DEMO23_INDEX_BTP_23_LS_CUT13_LOOKTORINK_O=0x4F,
    DEMO23_INDEX_BTP_23_LS_CUT15_TAKEOUT_O=0x50,
    
    /* BCKS */
    DEMO23_INDEX_BCK_23_LS_CUT04_ORIWAIT_L=0x53,
    DEMO23_INDEX_BCK_23_LS_CUT04_TURNWAIT_L=0x54,
    DEMO23_INDEX_BCK_23_LS_CUT05_RUNWAIT_L=0x55,
    DEMO23_INDEX_BCK_23_LS_CUT05_TETORLOOKWAIT_L=0x56,
    DEMO23_INDEX_BCK_23_LS_CUT10_CRYWAIT_L=0x57,
    DEMO23_INDEX_BCK_23_LS_CUT13_LOOKTETORA_L=0x58,
    DEMO23_INDEX_BCK_23_LS_CUT13_LOOKWAIT_L=0x59,
    DEMO23_INDEX_BCK_23_LS_CUT16_TAKEOUTRUN_L=0x5A,
    DEMO23_INDEX_BCK_23_MD_CUT10_TAKEOUT_L=0x5B,
    DEMO23_INDEX_BCK_23_P1A_CUT06_WALK_L=0x5C,
    DEMO23_INDEX_BCK_23_P1A_CUT07_KEY_L=0x5D,
    DEMO23_INDEX_BCK_23_P1A_CUT10_TAKEOUT_L=0x5E,
    DEMO23_INDEX_BCK_23_P1A_CUT14_HANDUPWAIT_L=0x5F,
    DEMO23_INDEX_BCK_23_P1A_CUT16_TAKEOUTRUN_L=0x60,
    DEMO23_INDEX_BCK_23_P1B_CUT10_TAKEOUT_L=0x61,
    DEMO23_INDEX_BCK_23_PM_CUT10_TAKEOUT_L=0x62,
    DEMO23_INDEX_BCK_23_ZL_CUT06_MEIREI_L=0x63,
    DEMO23_INDEX_BCK_23_ZL_CUT06_WAIT_L=0x64,
    DEMO23_INDEX_BCK_23_ZL_CUT08_KIZUKUWAIT_L=0x65,
    DEMO23_INDEX_BCK_23_ZL_CUT08_OPENWAIT_L=0x66,
    DEMO23_INDEX_BCK_23_ZL_CUT12_HANDUPWAIT_L=0x67,
    DEMO23_INDEX_BCK_23_ZL_CUT13_HANDPOINTWAIT_L=0x68,
    DEMO23_INDEX_BCK_23_ZL_CUT14_LOOKGBWAIT_L=0x69,
    DEMO23_INDEX_BCK_23_ZL_CUT14_LOOKGWAIT_L=0x6A,
    DEMO23_INDEX_BCK_23_ZL_CUT18_RUN_L=0x6B,
    DEMO23_INDEX_BCK_23_ZL_CUT20_FURIKAERIWAIT_L=0x6C,
    DEMO23_INDEX_BCK_DK_MAJYUTO_DEMO1=0x6D,
    DEMO23_INDEX_BCK_07_KM_CUT3FURIMUKI=0x6E,
    DEMO23_INDEX_BCK_07_KM_CUT3WAITA=0x6F,
    DEMO23_INDEX_BCK_07_KM_CUT3WAITB=0x70,
    DEMO23_INDEX_BCK_07_PM_CUT3FURIMUKI=0x71,
    DEMO23_INDEX_BCK_07_PM_CUT3WAITA=0x72,
    DEMO23_INDEX_BCK_07_PM_CUT3WAITB=0x73,
    DEMO23_INDEX_BCK_23_LS_CUT04_TURN_O=0x74,
    DEMO23_INDEX_BCK_23_LS_CUT05_RUNNING_O=0x75,
    DEMO23_INDEX_BCK_23_LS_CUT05_TETORLOOK_O=0x76,
    DEMO23_INDEX_BCK_23_LS_CUT10_WARAU_O=0x77,
    DEMO23_INDEX_BCK_23_LS_CUT13_LOOKTORINK_O=0x78,
    DEMO23_INDEX_BCK_23_LS_CUT15_TAKEOUT_O=0x79,
    DEMO23_INDEX_BCK_23_P1A_CUT14_HANDUP_O=0x7A,
    DEMO23_INDEX_BCK_23_P1A_CUT14_RUNNING_O=0x7B,
    DEMO23_INDEX_BCK_23_P1A_CUT14_TURNRUN_O=0x7C,
    DEMO23_INDEX_BCK_23_P1A_CUT15_TAKEOUT_O=0x7D,
    DEMO23_INDEX_BCK_23_ZL_CUT06_KIZUKU_O=0x7E,
    DEMO23_INDEX_BCK_23_ZL_CUT08_OPEN_O=0x7F,
    DEMO23_INDEX_BCK_23_ZL_CUT12_HANDUP_O=0x80,
    DEMO23_INDEX_BCK_23_ZL_CUT13_HANDPOINT_O=0x81,
    DEMO23_INDEX_BCK_23_ZL_CUT14_LOOKG_O=0x82,
    DEMO23_INDEX_BCK_23_ZL_CUT14_LOOKGB_O=0x83,
    DEMO23_INDEX_BCK_23_ZL_CUT20_FURIKAERI_O=0x84,
    DEMO23_INDEX_BCK_23_ZL_CUT20_RUN_O=0x85,
    DEMO23_INDEX_BCK_P1_WAIT=0x86,
    DEMO23_INDEX_BCK_P1_WAIT02=0x87,
    DEMO23_INDEX_BCK_07B_DK_CUT8_HOBA=0x88,
    
    /* BDL */
    DEMO23_INDEX_BDL_DK_COMP=0x8B,
    DEMO23_INDEX_BDL_SDOOR01=0x8C,
    
    /* BDLM */
    DEMO23_INDEX_BDL_DM=0x8F,
    DEMO23_INDEX_BDL_KM=0x90,
    DEMO23_INDEX_BDL_PM=0x91,
};

#endif /* RES_DEMO23_H */
