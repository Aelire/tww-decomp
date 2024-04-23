#ifndef RES_DEMO02_H
#define RES_DEMO02_H

enum DEMO02_RES_FILE_ID {
    /* BTP */
    DEMO02_BTP_HANG=0x22,
    DEMO02_BTP_FUAN=0x2B,
    DEMO02_BTP_FUAN02=0x2C,
    DEMO02_BTP_KIZUKU=0x2D,
    DEMO02_BTP_LS_DEMOLOOK=0x2E,
    DEMO02_BTP_LS_DEMOWAIT=0x2F,
    DEMO02_BTP_LS_GET=0x30,
    DEMO02_BTP_MABA=0x31,
    DEMO02_BTP_NGWARAI=0x32,
    DEMO02_BTP_NOZOKU=0x33,
    DEMO02_BTP_OKORI=0x34,
    DEMO02_BTP_WARAI=0x35,
    DEMO02_BTP_47_LS_BWAIT_L=0x39,
    DEMO02_BTP_47_LS_KYORO_L=0x3A,
    DEMO02_BTP_47_LS_KYOROB_L=0x3B,
    DEMO02_BTP_47_LS_LOOKWAIT_L=0x3C,
    DEMO02_BTP_47_LS_RUN_L=0x3D,
    
    /* BCKS */
    DEMO02_BCK_01_B_ZL=0x24,
    DEMO02_BCK_01B_A_DK=0x25,
    DEMO02_BCK_01B_A_ZL=0x26,
    DEMO02_BCK_01B_DK_WZ=0x27,
    DEMO02_BCK_01B_ZL_WZ=0x28,
    DEMO02_BCK_FIRE=0x29,
    DEMO02_BCK_47_LS_BWAIT_L=0x43,
    DEMO02_BCK_47_LS_KYOROB_L=0x44,
    DEMO02_BCK_47_LS_KYORO_L=0x45,
    DEMO02_BCK_47_LS_LOOKWAIT_L=0x46,
    DEMO02_BCK_47_LS_RUN_L=0x47,
    DEMO02_BCK_KA_WAIT1=0x48,
    DEMO02_BCK_KA_WAIT2=0x49,
    DEMO02_BCK_KA_WAIT3=0x4A,
    
    /* STB */
    DEMO02_STB_KAIZOKU_ZELDA_FLY=0x2A,
    DEMO02_STB_AWAKE=0x36,
    
    /* BDL */
    DEMO02_BDL_KA=0x38,
    
    /* BTK */
    DEMO02_BTK_47_LS_RUN_L=0x4B,
    DEMO02_BTK_47_LS_KYORO_L=0x4C,
    DEMO02_BTK_47_LS_KYOROB_L=0x4D,
    DEMO02_BTK_47_LS_LOOKWAIT_L=0x4E,
    DEMO02_BTK_47_LS_BWAIT_L=0x4F,
};

enum DEMO02_RES_FILE_INDEX {
    /* BTP */
    DEMO02_INDEX_BTP_HANG=0x7,
    DEMO02_INDEX_BTP_FUAN=0x8,
    DEMO02_INDEX_BTP_FUAN02=0x9,
    DEMO02_INDEX_BTP_KIZUKU=0xA,
    DEMO02_INDEX_BTP_LS_DEMOLOOK=0xB,
    DEMO02_INDEX_BTP_LS_DEMOWAIT=0xC,
    DEMO02_INDEX_BTP_LS_GET=0xD,
    DEMO02_INDEX_BTP_MABA=0xE,
    DEMO02_INDEX_BTP_NGWARAI=0xF,
    DEMO02_INDEX_BTP_NOZOKU=0x10,
    DEMO02_INDEX_BTP_OKORI=0x11,
    DEMO02_INDEX_BTP_WARAI=0x12,
    DEMO02_INDEX_BTP_47_LS_BWAIT_L=0x13,
    DEMO02_INDEX_BTP_47_LS_KYORO_L=0x14,
    DEMO02_INDEX_BTP_47_LS_KYOROB_L=0x15,
    DEMO02_INDEX_BTP_47_LS_LOOKWAIT_L=0x16,
    DEMO02_INDEX_BTP_47_LS_RUN_L=0x17,
    
    /* BCKS */
    DEMO02_INDEX_BCK_01_B_ZL=0x1A,
    DEMO02_INDEX_BCK_01B_A_DK=0x1B,
    DEMO02_INDEX_BCK_01B_A_ZL=0x1C,
    DEMO02_INDEX_BCK_01B_DK_WZ=0x1D,
    DEMO02_INDEX_BCK_01B_ZL_WZ=0x1E,
    DEMO02_INDEX_BCK_FIRE=0x1F,
    DEMO02_INDEX_BCK_47_LS_BWAIT_L=0x20,
    DEMO02_INDEX_BCK_47_LS_KYOROB_L=0x21,
    DEMO02_INDEX_BCK_47_LS_KYORO_L=0x22,
    DEMO02_INDEX_BCK_47_LS_LOOKWAIT_L=0x23,
    DEMO02_INDEX_BCK_47_LS_RUN_L=0x24,
    DEMO02_INDEX_BCK_KA_WAIT1=0x25,
    DEMO02_INDEX_BCK_KA_WAIT2=0x26,
    DEMO02_INDEX_BCK_KA_WAIT3=0x27,
    
    /* STB */
    DEMO02_INDEX_STB_KAIZOKU_ZELDA_FLY=0x2A,
    DEMO02_INDEX_STB_AWAKE=0x2B,
    
    /* BDL */
    DEMO02_INDEX_BDL_KA=0x2E,
    
    /* BTK */
    DEMO02_INDEX_BTK_47_LS_RUN_L=0x31,
    DEMO02_INDEX_BTK_47_LS_KYORO_L=0x32,
    DEMO02_INDEX_BTK_47_LS_KYOROB_L=0x33,
    DEMO02_INDEX_BTK_47_LS_LOOKWAIT_L=0x34,
    DEMO02_INDEX_BTK_47_LS_BWAIT_L=0x35,
};

#endif /* RES_DEMO02_H */
