#ifndef RES_BMDFOOT_H
#define RES_BMDFOOT_H

enum BMDFOOT_RES_FILE_ID { // IDs and indexes are synced
    /* BCK */
    BMDFOOT_BCK_ASI_ATTACK1=0x5,
    BMDFOOT_BCK_ASI_ATTACK2=0x6,
    BMDFOOT_BCK_ASI_ATTACK_LOOP=0x7,
    BMDFOOT_BCK_ASI_DATTACK1=0x8,
    BMDFOOT_BCK_ASI_DATTACK2=0x9,
    BMDFOOT_BCK_ASI_DATTACK3=0xA,
    BMDFOOT_BCK_ASI_DEAD=0xB,
    BMDFOOT_BCK_ASI_DEAD_LOOP=0xC,
    BMDFOOT_BCK_ASI_NOBIKIRU=0xD,
    BMDFOOT_BCK_ASI_NUKU=0xE,
    BMDFOOT_BCK_ASI_START1=0xF,
    BMDFOOT_BCK_ASI_START2=0x10,
    BMDFOOT_BCK_ASI_UMARU=0x11,
    BMDFOOT_BCK_ASI_UMARU_WAIT=0x12,
    BMDFOOT_BCK_ASI_WAIT=0x13,
    
    /* BMDM */
    BMDFOOT_BMD_ASI=0x16,
    
    /* BTK */
    BMDFOOT_BTK_ASI=0x19,
};

#endif /* RES_BMDFOOT_H */
