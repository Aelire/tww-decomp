#ifndef RES_MD_H
#define RES_MD_H

enum MD_RES_FILE_ID { // IDs and indexes are synced
    /* BCKS */
    MD_BCK_MD_CAUGHT=0x7,
    MD_BCK_MD_CAUGHT01=0x8,
    MD_BCK_MD_CAUGHT02=0x9,
    MD_BCK_MD_FALL=0xA,
    MD_BCK_MD_FALL02=0xB,
    MD_BCK_MD_FIRING=0xC,
    MD_BCK_MD_FLY01=0xD,
    MD_BCK_MD_FLY02=0xE,
    MD_BCK_MD_GLIDING=0xF,
    MD_BCK_MD_HARPPLAY01=0x10,
    MD_BCK_MD_HARPPLAY02=0x11,
    MD_BCK_MD_KAMAE=0x12,
    MD_BCK_MD_KAMAEWAIT=0x13,
    MD_BCK_MD_KYOHI=0x14,
    MD_BCK_MD_KYORO2=0x15,
    MD_BCK_MD_LAND=0x16,
    MD_BCK_MD_LAND02=0x17,
    MD_BCK_MD_LAND03=0x18,
    MD_BCK_MD_MKAMAE=0x19,
    MD_BCK_MD_MWAIT=0x1A,
    MD_BCK_MD_OJIGI=0x1B,
    MD_BCK_MD_ORIWAIT=0x1C,
    MD_BCK_MD_PIYO2=0x1D,
    MD_BCK_MD_RUN=0x1E,
    MD_BCK_MD_SHIPTALK01=0x1F,
    MD_BCK_MD_SHIPWAIT=0x20,
    MD_BCK_MD_SHIPWAIT02=0x21,
    MD_BCK_MD_SQUATDOWN=0x22,
    MD_BCK_MD_SQWAIT01=0x23,
    MD_BCK_MD_SQWAIT02=0x24,
    MD_BCK_MD_TAKEOFF01=0x25,
    MD_BCK_MD_TAKEOFF02=0x26,
    MD_BCK_MD_TALK01=0x27,
    MD_BCK_MD_TALK02=0x28,
    MD_BCK_MD_TALK03=0x29,
    MD_BCK_MD_TALK04=0x2A,
    MD_BCK_MD_TALK05=0x2B,
    MD_BCK_MD_UNAZUKI=0x2C,
    MD_BCK_MD_WAIT01=0x2D,
    MD_BCK_MD_WALK=0x2E,
    MD_BCK_MD_WATASU=0x2F,
    MD_BCK_MDARM_CAUGHT=0x30,
    MD_BCK_MDARM_FALL=0x31,
    MD_BCK_MDARM_FALL02=0x32,
    MD_BCK_MDARM_HARPPLAY01=0x33,
    MD_BCK_MDARM_HARPPLAY02=0x34,
    MD_BCK_MDARM_KAMAE=0x35,
    MD_BCK_MDARM_KAMAEWAIT=0x36,
    MD_BCK_MDARM_KYOHI=0x37,
    MD_BCK_MDARM_KYORO2=0x38,
    MD_BCK_MDARM_LAND=0x39,
    MD_BCK_MDARM_LAND02=0x3A,
    MD_BCK_MDARM_LAND03=0x3B,
    MD_BCK_MDARM_MKAMAE=0x3C,
    MD_BCK_MDARM_MWAIT=0x3D,
    MD_BCK_MDARM_OJIGI=0x3E,
    MD_BCK_MDARM_ORIWAIT=0x3F,
    MD_BCK_MDARM_PIYO2=0x40,
    MD_BCK_MDARM_RUN=0x41,
    MD_BCK_MDARM_SHIPTALK01=0x42,
    MD_BCK_MDARM_SHIPWAIT=0x43,
    MD_BCK_MDARM_SHIPWAIT02=0x44,
    MD_BCK_MDARM_SQUATDOWN=0x45,
    MD_BCK_MDARM_SQWAIT01=0x46,
    MD_BCK_MDARM_SQWAIT02=0x47,
    MD_BCK_MDARM_TAKEOFF01=0x48,
    MD_BCK_MDARM_TALK01=0x49,
    MD_BCK_MDARM_TALK02=0x4A,
    MD_BCK_MDARM_TALK03=0x4B,
    MD_BCK_MDARM_TALK04=0x4C,
    MD_BCK_MDARM_TALK05=0x4D,
    MD_BCK_MDARM_UNAZUKI=0x4E,
    MD_BCK_MDARM_WAIT01=0x4F,
    MD_BCK_MDARM_WALK=0x50,
    MD_BCK_MDARM_WATASU=0x51,
    MD_BCK_MDWING_CAUGHT01=0x52,
    MD_BCK_MDWING_CAUGHT02=0x53,
    MD_BCK_MDWING_FIRING=0x54,
    MD_BCK_MDWING_FLY01=0x55,
    MD_BCK_MDWING_FLY02=0x56,
    MD_BCK_MDWING_GLIDING=0x57,
    MD_BCK_MDWING_TAKEOFF02=0x58,
    MD_BCK_MDWING_WAIT01=0x59,
    
    /* BDLM */
    MD_BDL_MD=0x5C,
    MD_BDL_MD_HARP=0x5D,
    MD_BDL_MDARM=0x5E,
    MD_BDL_MDWING=0x5F,
    MD_BDL_YMDHP00=0x60,
    
    /* BTK */
    MD_BTK_YMDHP00=0x63,
    
    /* BTP */
    MD_BTP_FUAN=0x66,
    MD_BTP_MABA=0x67,
    MD_BTP_MD_CAUGHT=0x68,
    MD_BTP_MD_FALL=0x69,
    MD_BTP_MD_FALL02=0x6A,
    MD_BTP_MD_FLY02=0x6B,
    MD_BTP_MD_HARPPLAY=0x6C,
    MD_BTP_MD_KAMAE=0x6D,
    MD_BTP_MD_KAMAEWAIT=0x6E,
    MD_BTP_MD_KOMARI=0x6F,
    MD_BTP_MD_KYORO2=0x70,
    MD_BTP_MD_LAND=0x71,
    MD_BTP_MD_LAND02=0x72,
    MD_BTP_MD_PIYO2=0x73,
    MD_BTP_MD_UNAZUKI=0x74,
    MD_BTP_MD_WATASU=0x75,
    
    /* DAT */
    MD_BTI_MD_SPOT=0x78,
};

#endif /* RES_MD_H */
