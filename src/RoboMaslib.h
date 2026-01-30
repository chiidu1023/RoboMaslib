#pragma once
#include <RoboMasval.h>
class RoboMaslib{
    public:
    void setup(void);
    void set (int id_);
    void update (int id,int send);
    void info (uint8_t _id,int P);
    int16_t rpm1,rpm2,rpm3,rpm4;
    int16_t rpm5,rpm6,rpm7,rpm8;
    int encoder1,encoder2,encoder3,encoder4;
    int encoder5,encoder6,encoder7,encoder8;
    bool e1,e2,e3,e4,e5,e6,e7,e8;
    bool e1_pre,e2_pre,e3_pre,e4_pre;
    bool e5_pre,e6_pre,e7_pre,e8_pre;
    bool e1_pre_pre,e2_pre_pre,e3_pre_pre,e4_pre_pre;
    bool e5_pre_pre,e6_pre_pre,e7_pre_pre,e8_pre_pre;
    int enc1,enc2,enc3,enc4;
    int enc5,enc6,enc7,enc8;
    private:
    RoboMasval val;
};
void RoboMaslib::setup(void){
    val.setup();
}
void RoboMaslib::set(int id_){
    val.set(id_);
}
void RoboMaslib::update(int id ,int send){
    val.update(id,send,send);
}
void RoboMaslib::info(uint8_t _id,int P){
    val.info(_id);
    switch(_id){
        case 1:
            rpm1=val.speed1;
            encoder1=val.encoder1/P;
            if(P==19){encoder1=val.encoder1/19.2;}
            if(encoder1==8191){e1_pre_pre=1;}else{e1_pre_pre=0;}
            if(e1_pre_pre==1&&e1_pre==1){encoder1=encoder1-8191;}
            if(encoder1==0){e1_pre=1;}else{e1_pre=0;}
            if(e1_pre==1&&e1==1){encoder1=encoder1+8191;}
            if(encoder1==8191){e1=1;}else{e1=0;}
            break;
        case 2:
            rpm2=val.speed2;
            encoder2=val.encoder2/P;
            if(P==19){encoder2=val.encoder2/19.2;}
            if(encoder2==8191){e2_pre_pre=1;}else{e2_pre_pre=0;}
            if(e2_pre_pre==1&&e2_pre==1){encoder2=encoder2-8191;}
            if(encoder2==0){e2_pre=1;}else{e2_pre=0;}
            if(e2_pre==1&&e2==1){encoder2=encoder2+8191;}
            if(encoder2==8191){e2=1;}else{e2=0;}
            break;
        case 3:
            rpm3=val.speed3;
            encoder3=val.encoder3/P;
            if(P==19){encoder3=val.encoder3/19.2;}
            if(encoder3==8191){e3_pre_pre=1;}else{e3_pre_pre=0;}
            if(e3_pre_pre==1&&e3_pre==1){encoder3=encoder3-8191;}
            if(encoder3==0){e3_pre=1;}else{e3_pre=0;}
            if(e3_pre==1&&e3==1){encoder3=encoder1+8191;}
            if(encoder3==8191){e3=1;}else{e3=0;}
            break;
        case 4:
            rpm4=val.speed4;
            encoder4=val.encoder4/P;
            if(P==19){encoder4=val.encoder4/19.2;}
            if(encoder4==8191){e4_pre_pre=1;}else{e4_pre_pre=0;}
            if(e4_pre_pre==1&&e4_pre==1){encoder4=encoder4-8191;}
            if(encoder4==0){e4_pre=1;}else{e4_pre=0;}
            if(e4_pre==1&&e4==1){encoder4=encoder4+8191;}
            if(encoder4==8191){e4=1;}else{e4=0;}
            break;
        case 5:
            rpm5=val.speed5;
            encoder5=val.encoder5/P;
            if(P==19){encoder5=val.encoder5/19.2;}
            if(encoder5==8191){e5_pre_pre=1;}else{e5_pre_pre=0;}
            if(e5_pre_pre==1&&e5_pre==1){encoder5=encoder5-8191;}
            if(encoder5==0){e5_pre=1;}else{e5_pre=0;}
            if(e5_pre==1&&e5==1){encoder5=encoder5+8191;}
            if(encoder5==8191){e5=1;}else{e5=0;}
            break;
        case 6:
            rpm6=val.speed6;
            encoder6=val.encoder6/P;
            if(P==19){encoder6=val.encoder6/19.2;}
            if(encoder6==8191){e6_pre_pre=1;}else{e6_pre_pre=0;}
            if(e6_pre_pre==1&&e6_pre==1){encoder6=encoder6-8191;}
            if(encoder6==0){e6_pre=1;}else{e6_pre=0;}
            if(e6_pre==1&&e6==1){encoder6=encoder6+8191;}
            if(encoder6==8191){e6=1;}else{e6=0;}
            break;
        case 7:
            rpm7=val.speed7;
            encoder7=val.encoder7/P;
            if(P==19){encoder7=val.encoder7/19.2;}
            if(encoder7==8191){e7_pre_pre=1;}else{e7_pre_pre=0;}
            if(e7_pre_pre==1&&e7_pre==1){encoder7=encoder7-8191;}
            if(encoder7==0){e7_pre=1;}else{e7_pre=0;}
            if(e7_pre==1&&e7==1){encoder7=encoder7+8191;}
            if(encoder7==8191){e7=1;}else{e7=0;}
            break;
        case 8:
            rpm8=val.speed8;
            encoder8=val.encoder8/P;
            if(P==19){encoder8=val.encoder8/19.2;}
            if(encoder8==8191){e8_pre_pre=1;}else{e8_pre_pre=0;}
            if(e8_pre_pre==1&&e8_pre==1){encoder8=encoder8-8191;}
            if(encoder8==0){e8_pre=1;}else{e8_pre=0;}
            if(e8_pre==1&&e8==1){encoder8=encoder8+8191;}
            if(encoder8==8191){e8=1;}else{e8=0;}
            break;

    }
}
