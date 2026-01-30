#pragma once
#include <RoboMasval.h>

class RoboMaslib{
    public:
    void set (int id_);
    void update (int id,int mode,int send);
    void info (int _id);
    int16_t rpm1,rpm2,rpm3,rpm4;
    int16_t rpm5,rpm6,rpm7,rpm8;
    private:
    RoboMasval val;
};

void RoboMaslib::set(int id_){
    val.set(id_);
}

void RoboMaslib::update(int id ,int mode,int send){
    val.update(id,mode,send,0);
}

void RoboMaslib::info(int _id){
    val.info(_id);
    switch(_id){
        case 1:
            rpm1=val.speed1;
            Serial.print("can1: ");
            Serial.println(val.speed1);
            break;
        case 2:
            rpm2=val.speed2;
            Serial.print("can2: ");
            Serial.println(val.speed2);
            break;
        case 3:
            rpm3=val.speed3;
            Serial.print("can3: ");
            Serial.println(val.speed3);
            break;
        case 4:
            rpm4=val.speed4;
            Serial.print("can4: ");
            Serial.println(val.speed4);
            break;
        case 5:
            rpm5=val.speed5;
            Serial.print("can5: ");
            Serial.println(val.speed5);
            break;
        case 6:
            rpm6=val.speed6;
            Serial.print("can6: ");
            Serial.println(val.speed6);
            break;
        case 7:
            rpm7=val.speed7;
            Serial.print("can7: ");
            Serial.println(val.speed7);
            break;
        case 8:
            rpm8=val.speed8;
            Serial.print("can8: ");
            Serial.println(val.speed8);
            break;

    }
}
