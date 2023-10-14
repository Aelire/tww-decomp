//
// Generated by dtk
// Translation Unit: d_a_obj_movebox.cpp
//

#include "d/d_a_obj.h"
#include "d/d_bg_s_movebg_actor.h"
#include "d/d_cc_d.h"
#include "d/d_path.h"
#include "d/d_procname.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "d/d_com_inf_game.h"
#include "m_Do/m_Do_mtx.h"
#include "dolphin/types.h"

namespace daObjMovebox {
    struct Act_c;
    
    struct Type_Attr {
        /* 0x00 */ u8 temp00[0x14 - 0x00];
        /* 0x14 */ f32 unk14;
        /* 0x18 */ u8 temp18[0x20 - 0x18];
        /* 0x20 */ f32 unk20;
        /* 0x24 */ f32 unk24;
        /* 0x28 */ u8 temp28[0x58 - 0x28];
        /* 0x58 */ s32 mModelFileIndex;
        /* 0x5C */ u32 mDZBFileIndex;
        /* 0x60 */ u32 mDZBMaxSize;
        /* 0x64 */ f32 unk64;
        /* 0x68 */ u8 temp68[0x70 - 0x68];
        /* 0x70 */ f32 unk70;
        /* 0x74 */ u8 temp74[0x9A - 0x74];
        /* 0x9A */ u8 unk9A;
    };  // Size: 0x9C
    
    struct BgcSrc_c {
        
    };
    
    struct Bgc_c {
    public:
        Bgc_c();
        ~Bgc_c();
        void gnd_pos(const Act_c*, const BgcSrc_c*, int, float);
        void wrt_pos(const cXyz&);
        void wall_pos(const Act_c*, const BgcSrc_c*, int, short, float);
        void proc_vertical(Act_c*);
        void chk_wall_pre(const Act_c*, const BgcSrc_c*, int, short);
        void chk_wall_touch(const Act_c*, const BgcSrc_c*, short);
        void chk_wall_touch2(const Act_c*, const BgcSrc_c*, int, short);
    
    public:
        /* 0x000 */ f32 field0[0x17];
        /* 0x05C */ s32 field1;
        /* 0x060 */ f32 field2;
        /* 0x064 */ cXyz field4[0x17];
        /* 0x178 */ s32 field5;
        /* 0x17C */ f32 field6;
        /* 0x180 */ s32 field7;
    };  // Size: 0x184
    
    class EffSmokeCB { // TODO inherit dPa_smokeEcallBack
    public:
        EffSmokeCB() {}
        virtual ~EffSmokeCB() {}
    
    public:
        /* 0x0 */ u8 field_0x0[0x30];
    };
    
    struct Act_c : public dBgS_MoveBgActor {
    public:
        enum Type {
            TYPE_BREAKABLE_WOODEN_CRATE = 0x0,  // Actor names: Kkiba or DKkiba
            TYPE_BLACK_BOX              = 0x1,  // Actor names: osiBLK0 or DBLK0
            TYPE_BLACK_BOX_WITH_STATUE  = 0x2,  // Actor names: osiBLK1 or DBLK1
            TYPE_BIG_BLACK_BOX          = 0x3,  // Actor names: MpwrB
            TYPE_WOODEN_CRATE           = 0x4,  // Actor names: (N/A)
            TYPE_GOLDEN_CRATE           = 0x5,  // Actor names: Hbox2
            TYPE_METAL_BOX              = 0x6,  // Actor names: Hbox1
            TYPE_METAL_BOX_WITH_SPRING  = 0x7,  // Actor names: Hjump1
            TYPE_WOODEN_CRATE_2         = 0x8,  // Actor names: Hseki2
            TYPE_WOODEN_CRATE_3         = 0x9,  // Actor names: Hseki7
            TYPE_MIRROR                 = 0xA,  // Actor names: Mmrr
            TYPE_BLACK_BOX_2            = 0xB,  // Actor names: MkieBB
            TYPE_MOSSY_BLACK_BOX        = 0xC,  // Actor names: Ecube
        };
        
        enum Mode {
            MODE_WAIT   = 0x0,
            MODE_WALK   = 0x1,
            MODE_AFLOAT = 0x2,
        };
        
        enum Prm_e {
            PRM_TYPE_W = 0x04,
            PRM_TYPE_S = 0x18,
            
            PRM_SWSAVE_W = 0x01,
            PRM_SWSAVE_S = 0x1E,
            
            PRM_SWSAVE1_W = 0x08,
            PRM_SWSAVE1_S = 0x08,
            
            PRM_ITEMNO_W = 0x06,
            PRM_ITEMNO_S = 0x00,
            
            PRM_ITEMSAVE_W = 0x07,
            PRM_ITEMSAVE_S = 0x10,
            
            PRM_BUOY_W = 0x01,
            PRM_BUOY_S = 0x1F,
        };
        
        inline s32 Mthd_Create();
        inline s32 Mthd_Delete();
        
        s32 prm_get_type() const { return daObj::PrmAbstract(this, PRM_TYPE_W, PRM_TYPE_S); }
        s32 prm_get_swSave() const { return daObj::PrmAbstract(this, PRM_SWSAVE_W, PRM_SWSAVE_S); }
        s32 prm_get_swSave1() const;
        s32 prmZ_get_swSave2() const { return mType == TYPE_BLACK_BOX_2 ? 0xFF : (u8)(mPrmZ >> 8); }
        s32 prmZ_get_pathId() const { return mType == TYPE_BLACK_BOX_2 ? 0xFF : (mPrmZ & 0x00FF) >> 0; }
        s32 prmX_get_evId() const { return (mPrmX & 0x00FF) >> 0; }
        s32 prm_get_itemNo() const { return daObj::PrmAbstract(this, PRM_ITEMNO_W, PRM_ITEMNO_S); }
        s32 prm_get_itemSave() const { return daObj::PrmAbstract(this, PRM_ITEMSAVE_W, PRM_ITEMSAVE_S); }
        s32 prm_get_buoy() const { return daObj::PrmAbstract(this, PRM_BUOY_W, PRM_BUOY_S); }
        s32 prm_get_dmy() const; // Unused?
        
        BOOL is_switch1() const { return fopAcM_isSwitch((Act_c*)this, prm_get_swSave1()); };
        BOOL is_switch2() const { return fopAcM_isSwitch((Act_c*)this, prmZ_get_swSave2()); };
        void on_switch1() const { fopAcM_onSwitch((Act_c*)this, prm_get_swSave1()); };
        void on_switch2() const { fopAcM_onSwitch((Act_c*)this, prmZ_get_swSave2()); };
        void off_switch1() const { fopAcM_offSwitch((Act_c*)this, prm_get_swSave1()); };
        void off_switch2() const { fopAcM_offSwitch((Act_c*)this, prmZ_get_swSave2()); };
        
        void prmZ_init();
        void prmX_init();
        const Type_Attr* attr() const;
        void set_mtx();
        void init_mtx();
        void path_init();
        void path_save();
        int CreateHeap();
        void RideCallBack(dBgW*, fopAc_ac_c*, fopAc_ac_c*);
        static fopAc_ac_c* PPCallBack(fopAc_ac_c*, fopAc_ac_c*, short, dBgW::PushPullLabel);
        int Create();
        void afl_sway();
        void check_to_walk();
        void clr_moment_cnt();
        s32 chk_appear() const;
        void eff_set_slip_smoke_pos();
        void eff_smoke_slip_start();
        void eff_smoke_slip_end();
        void eff_smoke_slip_remove();
        void mode_wait_init();
        void mode_wait();
        void mode_walk_init();
        void mode_walk();
        void mode_afl_init();
        void mode_afl();
        void make_item();
        void eff_break();
        void sound_break();
        void sound_slip();
        void sound_limit();
        void sound_land();
        void vib_land();
        void eff_land_smoke();
        int Execute(float(**)[3][4]);
        int Draw();
        int Delete();
    
    public:
        /* 0x2C8 */ request_of_phase_process_class mPhs;
        /* 0x2D0 */ Mtx mMtx;
        /* 0x300 */ J3DModel* mpModel;
        /* 0x304 */ u32 mMode;
        /* 0x308 */ dCcD_Stts mStts;
        /* 0x344 */ dCcD_Cyl mCyl;
        /* 0x474 */ Bgc_c mBgc;
        /* 0x5F8 */ s32 mType;
        /* 0x5FC */ u16 mPrmZ;
        /* 0x5FE */ u16 mPrmX;
        /* 0x600 */ dPath* mPath;
        /* 0x604 */ u8 temp4[0x624 - 0x604];
        /* 0x624 */ f32 mUnknown624;
        /* 0x628 */ u8 temp7[0x634 - 0x628];
        /* 0x634 */ s32 mUnknown634;
        /* 0x638 */ u32 mPPLabel;
        /* 0x63C */ s16 mMomentCnt[4];
        /* 0x644 */ u8 temp6[0x64A - 0x644];
        /* 0x64A */ bool mbUnknown64A;
        /* 0x64B */ bool mbUnknown64B;
        /* 0x64C */ u8 mbShouldAppear;
        /* 0x64D */ bool mbPrmZInitialized;
        /* 0x64E */ bool mbPrmXInitialized;
        /* 0x64F */ bool mbUnknown64F;
        /* 0x650 */ EffSmokeCB mPtclSmokeCb[2];
        /* 0x6B8 */ s32 mBuoyProcId;
        /* 0x6BC */ u8 temp5[0x6C0 - 0x6BC];
        
        static const char* const M_arcname[13];
        static const dCcD_SrcCyl M_cyl_src;
        static const Type_Attr M_attr[13];
    };
    
    STATIC_ASSERT(sizeof(Act_c) == 0x6C0);
    
    const char* const Act_c::M_arcname[13] = {
        "Kkiba_00",
        "Osiblk",
        "Osiblk",
        "MpwrB",
        "Kkiba_00",
        "Hbox2",
        "Hjump",
        "Hjump",
        "Kkiba_00",
        "Kkiba_00",
        "Mmirror",
        "Osiblk",
        "Ecube",
    };
    
    const dCcD_SrcCyl Act_c::M_cyl_src = {
        0,
        0,
        0,
        0,
        AT_TYPE_BOMB, // Tg damage types
        0x09,
        0x79,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        
        // Cylinder
        0.0, // X
        0.0, // Y
        0.0, // Z
        75.0, // Radius
        150.0, // Height
    };
    
    const Type_Attr Act_c::M_attr[13] = {
        // TYPE_BREAKABLE_WOODEN_CRATE
        // Arcname: Kkiba_00
        {
            // TODO
            /* mModelFileIndex */ 4,
            /* mDZBFileIndex   */ 7,
            /* mDZBMaxSize     */ 0x8A0,
        },
        // TYPE_BLACK_BOX
        // Arcname: Osiblk
        {
            // TODO
            /* mModelFileIndex */ 4,
            /* mDZBFileIndex   */ 8,
            /* mDZBMaxSize     */ 0x8A0,
        },
        // TYPE_BLACK_BOX_WITH_STATUE
        // Arcname: Osiblk
        {
            // TODO
            /* mModelFileIndex */ 5,
            /* mDZBFileIndex   */ 9,
            /* mDZBMaxSize     */ 0x1560,
        },
        // TYPE_BIG_BLACK_BOX
        // Arcname: MpwrB
        {
            // TODO
        },
        // TYPE_WOODEN_CRATE
        // Arcname: Kkiba_00
        {
            // TODO
        },
        // TYPE_GOLDEN_CRATE
        // Arcname: Hbox2
        {
            // TODO
        },
        // TYPE_METAL_BOX
        // Arcname: Hjump
        {
            // TODO
        },
        // TYPE_METAL_BOX_WITH_SPRING
        // Arcname: Hjump
        {
            // TODO
        },
        // TYPE_WOODEN_CRATE_2
        // Arcname: Kkiba_00
        {
            // TODO
        },
        // TYPE_WOODEN_CRATE_3
        // Arcname: Kkiba_00
        {
            // TODO
        },
        // TYPE_MIRROR
        // Arcname: Mmirror
        {
            // TODO
        },
        // TYPE_BLACK_BOX_2
        // Arcname: Osiblk
        {
            // TODO
        },
        // TYPE_MOSSY_BLACK_BOX
        // Arcname: Ecube
        {
            // TODO
        },
    };
    
    s32 Act_c::Mthd_Create() {
        fopAcM_SetupActor(this, Act_c);
        
        s32 phase_state;
        mType = prm_get_type();
        phase_state = cPhs_ERROR_e;
        prmX_init();
        prmZ_init();
        
        mbShouldAppear = chk_appear();
        if (mbShouldAppear) {
            phase_state = dComIfG_resLoad(&mPhs, M_arcname[mType]);
            if (phase_state == cPhs_COMPLEATE_e) {
                const Type_Attr* attr = &M_attr[mType];
                u32 maxSize = attr->mDZBMaxSize;
                path_init();
                attr = &M_attr[mType];
                phase_state = MoveBGCreate(M_arcname[mType], attr->mDZBFileIndex, dBgS_MoveBGProc_Trans, maxSize);
                JUT_ASSERT(0x7CE, (phase_state == cPhs_COMPLEATE_e) || (phase_state == cPhs_ERROR_e));
            }
        }
        
        return phase_state;
    }
    
    s32 Act_c::Mthd_Delete() {
        s32 result = MoveBGDelete();
        if (mbShouldAppear) {
            dComIfG_resDelete(&mPhs, M_arcname[mType]);
        }
        return result;
    }
    
    /* 000000EC-000001B0       .text __ct__Q212daObjMovebox5Bgc_cFv */
    Bgc_c::Bgc_c() {
        /* Nonmatching (rodata only) */
        for (int i = 0; i < ARRAY_SIZE(field0); i++) {
            field0[i] = 0.0f;
            field4[i] = cXyz::Zero;
        }
        field1 = -1;
        field5 = -1;
        field6 = FLOAT_MAX;
        field2 = 0.0f;
        field7 = 0;
    }
    
    /* 000001F0-000003A4       .text gnd_pos__Q212daObjMovebox5Bgc_cFPCQ212daObjMovebox5Act_cPCQ212daObjMovebox8BgcSrc_cif */
    void Bgc_c::gnd_pos(const Act_c*, const BgcSrc_c*, int, float) {
        /* Nonmatching */
    }
    
    /* 000003A4-00000474       .text wrt_pos__Q212daObjMovebox5Bgc_cFRC4cXyz */
    void Bgc_c::wrt_pos(const cXyz&) {
        /* Nonmatching */
    }
    
    /* 00000474-00000748       .text wall_pos__Q212daObjMovebox5Bgc_cFPCQ212daObjMovebox5Act_cPCQ212daObjMovebox8BgcSrc_cisf */
    void Bgc_c::wall_pos(const Act_c*, const BgcSrc_c*, int, short, float) {
        /* Nonmatching */
    }
    
    /* 00000748-000008E8       .text proc_vertical__Q212daObjMovebox5Bgc_cFPQ212daObjMovebox5Act_c */
    void Bgc_c::proc_vertical(Act_c*) {
        /* Nonmatching */
    }
    
    /* 000008E8-00000928       .text chk_wall_pre__Q212daObjMovebox5Bgc_cFPCQ212daObjMovebox5Act_cPCQ212daObjMovebox8BgcSrc_cis */
    void Bgc_c::chk_wall_pre(const Act_c*, const BgcSrc_c*, int, short) {
        /* Nonmatching */
    }
    
    /* 00000928-00000CCC       .text chk_wall_touch__Q212daObjMovebox5Bgc_cFPCQ212daObjMovebox5Act_cPCQ212daObjMovebox8BgcSrc_cs */
    void Bgc_c::chk_wall_touch(const Act_c*, const BgcSrc_c*, short) {
        /* Nonmatching */
    }
    
    /* 00001258-000012E0       .text chk_wall_touch2__Q212daObjMovebox5Bgc_cFPCQ212daObjMovebox5Act_cPCQ212daObjMovebox8BgcSrc_cis */
    void Bgc_c::chk_wall_touch2(const Act_c*, const BgcSrc_c*, int, short) {
        /* Nonmatching */
    }
    
    /* 000012E0-00001308       .text prm_get_swSave1__Q212daObjMovebox5Act_cCFv */
    s32 Act_c::prm_get_swSave1() const {
        return daObj::PrmAbstract(this, PRM_SWSAVE1_W, PRM_SWSAVE1_S);
    }
    
    /* 00001308-00001380       .text prmZ_init__Q212daObjMovebox5Act_cFv */
    void Act_c::prmZ_init() {
        if (mbPrmZInitialized) {
            return;
        }
        mbPrmZInitialized = true;
        
        s32 switchEnablesSpawn = prm_get_swSave();
        if (switchEnablesSpawn) {
            // The appearing/disappearing type of box does not take pathId or swSave2 params.
            mPrmZ = 0xFFFF;
        } else {
            mPrmZ = orig.angle.z;
        }
        
        orig.angle.z = 0;
        current.angle.z = 0;
        shape_angle.z = 0;
    }
    
    /* 00001380-000013B0       .text prmX_init__Q212daObjMovebox5Act_cFv */
    void Act_c::prmX_init() {
        if (!mbPrmXInitialized) {
            mPrmX = orig.angle.x;
            mbPrmXInitialized = true;
        }
        
        orig.angle.x = 0;
        current.angle.x = 0;
        shape_angle.x = 0;
    }
    
    /* 000013B0-000013C8       .text attr__Q212daObjMovebox5Act_cCFv */
    const Type_Attr* Act_c::attr() const {
        return &M_attr[mType];
    }
    
    /* 000013C8-00001674       .text set_mtx__Q212daObjMovebox5Act_cFv */
    void Act_c::set_mtx() {
        /* Nonmatching */
        Quaternion temp2;
        cXyz temp3;
        Mtx temp4;
        Vec temp5;
        
        bool isFloating = mMode == MODE_AFLOAT;
        mDoMtx_stack_c::transS(getPosition());
        if (isFloating) {
            mDoMtx_stack_c::transM(0.0f, mUnknown624, 0.0f);
        }
        
        daObj::quat_rotBaseY(&temp2, temp3);
        mDoMtx_stack_c::quatM(&temp2);
        mDoMtx_stack_c::ZXYrotM(shape_angle);
        if (isFloating) {
            mDoMtx_stack_c::transM(0.0f, -mUnknown624, 0.0f);
        }
        
        if (mpModel) {
            mpModel->setBaseTRMtx(mDoMtx_stack_c::get());
        }
        MTXCopy(mDoMtx_stack_c::get(), mMtx);
        
        fopAc_ac_c* buoy;
        if (fopAcM_SearchByID(mBuoyProcId, &buoy)) {
            if (mType == TYPE_METAL_BOX_WITH_SPRING) {
                if (buoy->current.pos.abs2(current.pos) < 0.0001f) {
                    buoy->current.pos = current.pos;
                }
            } else if (mType == TYPE_MIRROR) {
                if (buoy->current.pos.abs2(current.pos) < 0.0001f) {
                    buoy->current.pos = current.pos;
                }
            } else if (mType == TYPE_BLACK_BOX_2) {
                if (buoy->current.pos.abs2(current.pos) < 0.0001f) {
                    buoy->current.pos = current.pos;
                }
            } else {
                mDoMtx_multVecSR(temp4, &temp5, &temp5);
                mDoMtx_copy(temp4, temp4);
            }
        } else {
            mBuoyProcId = -1;
        }
    }
    
    /* 00001674-000016B8       .text init_mtx__Q212daObjMovebox5Act_cFv */
    void Act_c::init_mtx() {
        if (mpModel) {
            mpModel->mBaseScale = mScale;
        }
        set_mtx();
    }
    
    /* 000016B8-00001830       .text path_init__Q212daObjMovebox5Act_cFv */
    void Act_c::path_init() {
        // Load the position the box was last left pushed to based on the path and switch(es).
        s32 pathId = prmZ_get_pathId();
        s32 swSave1 = prm_get_swSave1();
        if (pathId != 0xFF && swSave1 != 0xFF) {
            s32 swSave2 = prmZ_get_swSave2();
            
            bool isMoved1 = is_switch1();
            u32 isMoved2 = false;
            if (0xFF == swSave2) { // Literal must be on the left hand side for a match
                isMoved2 = false;
            } else {
                isMoved2 = is_switch2();
                isMoved2 = !!isMoved2;
            }
            isMoved2 = !!isMoved2;
            
            s32 pntIdx = 0;
            if (isMoved1 != false) {
                pntIdx = 1;
            }
            if (isMoved2) {
                pntIdx += 2;
            }
            
            mPath = dPath_GetRoomPath(pathId, orig.roomNo);
            dPath__Point* pnt = dPath_GetPnt(mPath, pntIdx);
            orig.pos = pnt->mPos;
            current.pos = pnt->mPos;
        }
    }
    
    /* 00001830-00001A10       .text path_save__Q212daObjMovebox5Act_cFv */
    void Act_c::path_save() {
        /* Nonmatching (rodata only) */
        // Determine how far along the path the box has been pushed and save the position to the switch(es).
        // Supports up to 4 possible path points.
        s32 pathId = prmZ_get_pathId();
        s32 swSave1 = prm_get_swSave1();
        if (pathId != 0xFF && swSave1 != 0xFF) {
            s32 swSave2 = prmZ_get_swSave2();
            
            s32 numPnts;
            if (0xFF == swSave2) { // Literal must be on the left hand side for a match
                numPnts = 2;
            } else {
                numPnts = 4;
            }
            if (numPnts > mPath->m_num) {
                numPnts = mPath->m_num;
            }
            
            s32 pntIdx;
            for (pntIdx = 0; pntIdx < numPnts; pntIdx++) {
                cXyz pntPos = dPath_GetPnt(mPath, pntIdx)->mPos;
                if (current.pos.abs2(pntPos) < 9.0f) {
                    break;
                }
            }
            if (pntIdx >= numPnts) {
                return;
            }
            
            // Store the low bit of the 2-bit index in swSave1.
            if (pntIdx & 1) {
                on_switch1();
            } else {
                off_switch1();
            }
            
            if (swSave2 != 0xFF) {
                // Store the high bit of the 2-bit index in swSave2.
                if (pntIdx & 2) {
                    on_switch2();
                } else {
                    off_switch2();
                }
            }
        }
    }
    
    /* 00001A10-00001B00       .text CreateHeap__Q212daObjMovebox5Act_cFv */
    int Act_c::CreateHeap() {
        BOOL success = TRUE;
        const Type_Attr* attr = &M_attr[mType];
        if (attr->mModelFileIndex >= 0) {
            J3DModelData* modelData = (J3DModelData*)dComIfG_getObjectRes(M_arcname[mType], attr->mModelFileIndex);
            JUT_ASSERT(0x6BA, modelData != 0);
            
            mpModel = mDoExt_J3DModel__create(modelData, 0x80000, 0x11000022);
            success = (mpModel != 0);
        } else {
            mpModel = NULL;
        }
        return success;
    }
    
    /* 00001B00-00001C64       .text RideCallBack__Q212daObjMovebox5Act_cFP4dBgWP10fopAc_ac_cP10fopAc_ac_c */
    void Act_c::RideCallBack(dBgW*, fopAc_ac_c*, fopAc_ac_c*) {
        /* Nonmatching */
    }
    
    /* 00001C64-00001DD4       .text PPCallBack__Q212daObjMovebox5Act_cFP10fopAc_ac_cP10fopAc_ac_csQ24dBgW13PushPullLabel */
    fopAc_ac_c* Act_c::PPCallBack(fopAc_ac_c* actor, fopAc_ac_c*, s16 rot, dBgW::PushPullLabel pp_label) {
        /* Nonmatching */
        Act_c* i_this = (Act_c*)actor;
        
        if (pp_label & 0x03) {
            const Type_Attr* attr = &M_attr[i_this->mType];
            bool unk;
            if (!attr->unk9A) {
                unk = true;
            } else {
                unk = pp_label & 0x08;
            }
            if (unk) {
                s32 origAngle = i_this->orig.angle.y;
                s32 angle = rot;
                if (pp_label & 0x2) {
                    angle -= 0x8000;
                }
                angle -= origAngle;
                int pp_field = 3;
                JUT_ASSERT(0x715, pp_label != pp_field);
                
                i_this->mPPLabel = pp_label;
                
                int whichSide;
                if (angle >= -0x2000 && angle < 0x2000) {
                    whichSide = 0;
                } else if (angle >= 0x2000 && angle < 0x6000) {
                    whichSide = 1;
                } else if (angle >= 0x6000 || angle < -0x6000) {
                    whichSide = 2;
                } else {
                    whichSide = 3;
                }
                
                for (int i = 0; i < 4; i++) {
                    if (i == whichSide) {
                        i_this->mMomentCnt[i] += 1;
                    } else {
                        i_this->mMomentCnt[i] = 0;
                    }
                }
                
                i_this->mbUnknown64A = true;
            }
        }
        
        return i_this;
    }
    
    /* 00001DD4-00002214       .text Create__Q212daObjMovebox5Act_cFv */
    int Act_c::Create() {
        /* Nonmatching */
        mCyl.Set(M_cyl_src);
    }
    
    /* 00002214-000024D4       .text afl_sway__Q212daObjMovebox5Act_cFv */
    void Act_c::afl_sway() {
        /* Nonmatching */
    }
    
    /* 000024D4-00002668       .text check_to_walk__Q212daObjMovebox5Act_cFv */
    void Act_c::check_to_walk() {
        /* Nonmatching */
    }
    
    /* 00002668-0000268C       .text clr_moment_cnt__Q212daObjMovebox5Act_cFv */
    void Act_c::clr_moment_cnt() {
        for (int i = 0; i < 4; i++) {
            mMomentCnt[i] = 0;
        }
    }
    
    /* 0000268C-00002768       .text chk_appear__Q212daObjMovebox5Act_cCFv */
    s32 Act_c::chk_appear() const {
        // Boxes that do not have a path to save their position instead use swSave1 to enable or disable spawning.
        s32 pathId = prmZ_get_pathId();
        int sw = prm_get_swSave1();
        if (pathId != 0xFF || sw == 0xFF) {
            return TRUE;
        }
        
        bool switchIsSet = is_switch1();
        bool switchEnablesSpawn = prm_get_swSave();
        BOOL shouldAppear = FALSE;
        if ((!switchIsSet && !switchEnablesSpawn) || (switchIsSet && switchEnablesSpawn)) {
            shouldAppear = TRUE;
        }
        return shouldAppear;
    }
    
    /* 00002768-0000290C       .text eff_set_slip_smoke_pos__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_set_slip_smoke_pos() {
        /* Nonmatching */
    }
    
    /* 0000290C-00002A14       .text eff_smoke_slip_start__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_smoke_slip_start() {
        /* Nonmatching */
    }
    
    /* 00002A14-00002A74       .text eff_smoke_slip_end__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_smoke_slip_end() {
        /* Nonmatching */
    }
    
    /* 00002A74-00002AD4       .text eff_smoke_slip_remove__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_smoke_slip_remove() {
        /* Nonmatching */
    }
    
    /* 00002AD4-00002B48       .text mode_wait_init__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_wait_init() {
        /* Nonmatching (rodata only) */
        speedF = 0.0f;
        const Type_Attr* attr = &M_attr[mType];
        mGravity = attr->unk14;
        mpBgW->m_crr_func = &dBgS_MoveBGProc_Trans;
        clr_moment_cnt();
        mUnknown634 = -1;
        mMode = MODE_WAIT;
    }
    
    /* 00002B48-00002D84       .text mode_wait__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_wait() {
        /* Nonmatching */
    }
    
    /* 00002D84-00002DA4       .text mode_walk_init__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_walk_init() {
        /* Nonmatching (rodata only) */
        speedF = 0.0f;
        mbUnknown64F = false;
        mMode = MODE_WALK;
    }
    
    /* 00002DA4-000031AC       .text mode_walk__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_walk() {
        /* Nonmatching */
    }
    
    /* 000031AC-000031D4       .text mode_afl_init__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_afl_init() {
        /* Nonmatching (rodata only) */
        speedF = 0.0f;
        mpBgW->m_crr_func = &dBgS_MoveBGProc_Typical;
        mMode = MODE_AFLOAT;
    }
    
    /* 000031D4-000033D8       .text mode_afl__Q212daObjMovebox5Act_cFv */
    void Act_c::mode_afl() {
        /* Nonmatching */
    }
    
    /* 000033D8-00003450       .text make_item__Q212daObjMovebox5Act_cFv */
    void Act_c::make_item() {
        /* Nonmatching */
    }
    
    /* 00003450-00003570       .text eff_break__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_break() {
        /* Nonmatching */
    }
    
    /* 00003570-00003808       .text sound_break__Q212daObjMovebox5Act_cFv */
    void Act_c::sound_break() {
        /* Nonmatching */
    }
    
    /* 00003AE0-00003BA4       .text sound_slip__Q212daObjMovebox5Act_cFv */
    void Act_c::sound_slip() {
        /* Nonmatching */
    }
    
    /* 00003BA4-00003C68       .text sound_limit__Q212daObjMovebox5Act_cFv */
    void Act_c::sound_limit() {
        /* Nonmatching */
    }
    
    /* 00003C68-00003D2C       .text sound_land__Q212daObjMovebox5Act_cFv */
    void Act_c::sound_land() {
        /* Nonmatching */
    }
    
    /* 00003D2C-00003D80       .text vib_land__Q212daObjMovebox5Act_cFv */
    void Act_c::vib_land() {
        /* Nonmatching */
    }
    
    /* 00003D80-00003E04       .text eff_land_smoke__Q212daObjMovebox5Act_cFv */
    void Act_c::eff_land_smoke() {
        /* Nonmatching */
    }
    
    /* 00003E04-000040D0       .text Execute__Q212daObjMovebox5Act_cFPPA3_A4_f */
    int Act_c::Execute(float(**)[3][4]) {
        /* Nonmatching */
    }
    
    /* 000040D0-00004254       .text Draw__Q212daObjMovebox5Act_cFv */
    int Act_c::Draw() {
        /* Nonmatching */
    }
    
    /* 00004254-000042A0       .text Delete__Q212daObjMovebox5Act_cFv */
    int Act_c::Delete() {
        /* Nonmatching */
    }
    
    namespace {
        /* 000042A0-000044E0       .text Mthd_Create__Q212daObjMovebox29@unnamed@d_a_obj_movebox_cpp@FPv */
        s32 Mthd_Create(void* i_this) {
            return ((Act_c*)i_this)->Mthd_Create();
        }
        
        /* 000044E0-00004544       .text Mthd_Delete__Q212daObjMovebox29@unnamed@d_a_obj_movebox_cpp@FPv */
        s32 Mthd_Delete(void* i_this) {
            return ((Act_c*)i_this)->Mthd_Delete();
        }
        
        /* 00004544-00004564       .text Mthd_Execute__Q212daObjMovebox29@unnamed@d_a_obj_movebox_cpp@FPv */
        s32 Mthd_Execute(void* i_this) {
            return ((Act_c*)i_this)->MoveBGExecute();
        }
        
        /* 00004564-00004590       .text Mthd_Draw__Q212daObjMovebox29@unnamed@d_a_obj_movebox_cpp@FPv */
        s32 Mthd_Draw(void* i_this) {
            return ((Act_c*)i_this)->Draw();
        }
        
        /* 00004590-000045BC       .text Mthd_IsDelete__Q212daObjMovebox29@unnamed@d_a_obj_movebox_cpp@FPv */
        s32 Mthd_IsDelete(void* i_this) {
            return ((Act_c*)i_this)->IsDelete();
        }
        
        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

actor_process_profile_definition g_profile_Obj_Movebox = {
    fpcLy_CURRENT_e,
    3,
    fpcLy_CURRENT_e,
    PROC_Obj_Movebox,
    &g_fpcLf_Method.mBase,
    sizeof(daObjMovebox::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x0015,
    &daObjMovebox::Mthd_Table,
    0x04 | fopAcStts_SHOWMAP_e | fopAcStts_CULL_e | fopAcStts_FREEZE_e | fopAcStts_UNK40000_e,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
