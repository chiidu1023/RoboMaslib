#include "RoboMaslib.h"

// セットアップ
void RoboMaslib::setup(void) {
    val.setup(); //
}

// 指令の送信
void RoboMaslib::set(int id_) {
    val.set(id_); //
}

// 指令値の更新
void RoboMaslib::update(int id, int send) {
    val.update(id, send, send); //
}

// データの取得と累積エンコーダの計算
void RoboMaslib::info(uint8_t _id, int P) {
    val.info(_id); //
    
    // P=19の場合の補正係数
    float ratio = (P == 19) ? 19.2 : (float)P; //

    switch(_id) {
        case 1:
            rpm1 = val.speed1; //
            encoder1 = val.encoder1 / ratio; //
            if(encoder1 == 8191) e1_pre_pre = 1; else e1_pre_pre = 0; //
            if(e1_pre_pre == 1 && e1_pre == 1) encoder1 -= 8191; //
            if(encoder1 == 0) e1_pre = 1; else e1_pre = 0; //
            if(e1_pre == 1 && e1 == 1) encoder1 += 8191; //
            if(encoder1 == 8191) e1 = 1; else e1 = 0; //
            break;
        case 2:
            rpm2 = val.speed2; //
            encoder2 = val.encoder2 / ratio; //
            if(encoder2 == 8191) e2_pre_pre = 1; else e2_pre_pre = 0; //
            if(e2_pre_pre == 1 && e2_pre == 1) encoder2 -= 8191; //
            if(encoder2 == 0) e2_pre = 1; else e2_pre = 0; //
            if(e2_pre == 1 && e2 == 1) encoder2 += 8191; //
            if(encoder2 == 8191) e2 = 1; else e2 = 0; //
            break;
        case 3:
            rpm3 = val.speed3; //
            encoder3 = val.encoder3 / ratio; //
            if(encoder3 == 8191) e3_pre_pre = 1; else e3_pre_pre = 0; //
            if(e3_pre_pre == 1 && e3_pre == 1) encoder3 -= 8191; //
            if(encoder3 == 0) e3_pre = 1; else e3_pre = 0; //
            if(e3_pre == 1 && e3 == 1) encoder3 += 8191; //
            if(encoder3 == 8191) e3 = 1; else e3 = 0; //
            break;
        case 4:
            rpm4 = val.speed4; //
            encoder4 = val.encoder4 / ratio; //
            if(encoder4 == 8191) e4_pre_pre = 1; else e4_pre_pre = 0; //
            if(e4_pre_pre == 1 && e4_pre == 1) encoder4 -= 8191; //
            if(encoder4 == 0) e4_pre = 1; else e4_pre = 0; //
            if(e4_pre == 1 && e4 == 1) encoder4 += 8191; //
            if(encoder4 == 8191) e4 = 1; else e4 = 0; //
            break;
        case 5:
            rpm5 = val.speed5; //
            encoder5 = val.encoder5 / ratio; //
            if(encoder5 == 8191) e5_pre_pre = 1; else e5_pre_pre = 0; //
            if(e5_pre_pre == 1 && e5_pre == 1) encoder5 -= 8191; //
            if(encoder5 == 0) e5_pre = 1; else e5_pre = 0; //
            if(e5_pre == 1 && e5 == 1) encoder5 += 8191; //
            if(encoder5 == 8191) e5 = 1; else e5 = 0; //
            break;
        case 6:
            rpm6 = val.speed6; //
            encoder6 = val.encoder6 / ratio; //
            if(encoder6 == 8191) e6_pre_pre = 1; else e6_pre_pre = 0; //
            if(e6_pre_pre == 1 && e6_pre == 1) encoder6 -= 8191; //
            if(encoder6 == 0) e6_pre = 1; else e6_pre = 0; //
            if(e6_pre == 1 && e6 == 1) encoder6 += 8191; //
            if(encoder6 == 8191) e6 = 1; else e6 = 0; //
            break;
        case 7:
            rpm7 = val.speed7; //
            encoder7 = val.encoder7 / ratio; //
            if(encoder7 == 8191) e7_pre_pre = 1; else e7_pre_pre = 0; //
            if(e7_pre_pre == 1 && e7_pre == 1) encoder7 -= 8191; //
            if(encoder7 == 0) e7_pre = 1; else e7_pre = 0; //
            if(e7_pre == 1 && e7 == 1) encoder7 += 8191; //
            if(encoder7 == 8191) e7 = 1; else e7 = 0; //
            break;
        case 8:
            rpm8 = val.speed8; //
            encoder8 = val.encoder8 / ratio; //
            if(encoder8 == 8191) e8_pre_pre = 1; else e8_pre_pre = 0; //
            if(e8_pre_pre == 1 && e8_pre == 1) encoder8 -= 8191; //
            if(encoder8 == 0) e8_pre = 1; else e8_pre = 0; //
            if(e8_pre == 1 && e8 == 1) encoder8 += 8191; //
            if(encoder8 == 8191) e8 = 1; else e8 = 0; //
            break;
    }
}