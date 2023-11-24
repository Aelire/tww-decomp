#ifndef D_A_NPC_ZK1_H
#define D_A_NPC_ZK1_H

#include "f_op/f_op_actor.h"
#include "JSystem/J3DGraphAnimator/J3DNode.h"

class daNpc_Zk1_c : public fopAc_ac_c {
public:
    void _nodeCB_Head(J3DNode*, J3DModel*);
    void _nodeCB_BackBone(J3DNode*, J3DModel*);
    void init_ZK1_0();
    void createInit();
    void play_animation();
    void setMtx(bool);
    void bckResID(int);
    void btpResID(int);
    void setBtp(signed char, bool);
    void init_texPttrnAnm(signed char, bool);
    void play_btp_anm();
    void setAnm_anm(daNpc_Zk1_c::anm_prm_c*);
    void setAnm();
    void chngAnmTag();
    void ctrlAnmTag();
    void chngAnmAtr(unsigned char);
    void ctrlAnmAtr();
    void setAnm_ATR();
    void anmAtr(unsigned short);
    void next_msgStatus(unsigned long*);
    void getMsg_ZK1_0();
    void getMsg();
    void eventOrder();
    void checkOrder();
    void chk_talk();
    void chk_parts_notMov();
    void searchByID(unsigned int, int*);
    void lookBack();
    void chkAttention();
    void setAttention(bool);
    void decideType(int);
    void privateCut(int);
    void endEvent();
    void isEventEntry();
    void event_proc(int);
    void set_action(int (daNpc_Zk1_c::*)(void*), void*);
    void setStt(signed char);
    void wait_1();
    void talk_1();
    void wait_action1(void*);
    void demo();
    void shadowDraw();
    BOOL _draw();
    BOOL _execute();
    BOOL _delete();
    s32 _create();
    void bodyCreateHeap();
    void CreateHeap();

public:
    /* 0x6C4 */ u8 m6C4[0x72C - 0x6C4];
    /* 0x72C */ cXyz m72C;
    /* 0x738 */ u8 m738[0x750 - 0x738];
    /* 0x750 */ cXyz m750;
    /* 0x75C */ u8 m75C[0x7B4 - 0x75C];
};

#endif /* D_A_NPC_ZK1_H */