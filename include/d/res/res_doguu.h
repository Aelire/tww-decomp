#ifndef RES_DOGUU_H
#define RES_DOGUU_H

enum DOGUU_RES_FILE_ID { // IDs and indexes are synced
    /* BCK */
    DOGUU_BCK_VGSBA=0x6,
    DOGUU_BCK_VGSHD=0x7,
    DOGUU_BCK_VGSHF=0x8,
    DOGUU_BCK_VGSHN=0x9,
    DOGUU_BCK_VGSPA=0xA,
    
    /* BDLM */
    DOGUU_BDL_VGSBA=0xD,
    DOGUU_BDL_VGSHD=0xE,
    DOGUU_BDL_VGSHF=0xF,
    DOGUU_BDL_VGSHN=0x10,
    DOGUU_BDL_VGSMA=0x11,
    DOGUU_BDL_VGSPD=0x12,
    DOGUU_BDL_VGSPF=0x13,
    DOGUU_BDL_VGSPN=0x14,
    
    /* BMT */
    DOGUU_BMT_VGSBD=0x17,
    DOGUU_BMT_VGSBF=0x18,
    DOGUU_BMT_VGSBN=0x19,
    DOGUU_BMT_VGSMD=0x1A,
    DOGUU_BMT_VGSMF=0x1B,
    DOGUU_BMT_VGSMN=0x1C,
    
    /* BRK */
    DOGUU_BRK_VGSMD=0x1F,
    DOGUU_BRK_VGSMF=0x20,
    DOGUU_BRK_VGSMN=0x21,
    DOGUU_BTK_VGSPA=0x22,
};

#endif /* RES_DOGUU_H */
