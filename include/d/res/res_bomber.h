#ifndef RES_BOMBER_H
#define RES_BOMBER_H

#include "global.h"

enum BOMBER_RES_FILE_ID { // IDs and indexes are synced
    /* BDL */
    BOMBER_BDL_VCANK=0x5,
    
    /* BMDC */
    BOMBER_BMD_AISI=0x8,
    
    /* TEX */
    BOMBER_BTI_GAME_BATTERY=0xB,
    BOMBER_BTI_GAME_BATTERY_BASE=0xC,
    BOMBER_BTI_GAME_BOMB_01=0xD,
    BOMBER_BTI_GAME_BOMB_02=0xE,
    BOMBER_BTI_GAME_HUNE_DAMAGE=0xF,
    BOMBER_BTI_GAME_RULE=0x10,
    BOMBER_BTI_GAME_SHIP_NODAMAGE=0x11,
    BOMBER_BTI_RUPY_NUM_DEGREE=0x12,
};

#endif /* RES_BOMBER_H */