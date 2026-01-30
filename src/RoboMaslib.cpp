#include "RoboMaslib.h"

void RoboMaslib::set(int id_) {
    val.set(id_);
}

void RoboMaslib::update(int id, int mode, int send) {
    // val.updateの引数に合わせてrpm_には0を渡しています
    val.update(id, send, 0);
}

void RoboMaslib::info(int _id) {
    val.info(_id);
    
    int16_t current_rpm = 0;
    switch(_id) {
        case 1: rpm1 = val.speed1; current_rpm = rpm1; break;
        case 2: rpm2 = val.speed2; current_rpm = rpm2; break;
        case 3: rpm3 = val.speed3; current_rpm = rpm3; break;
        case 4: rpm4 = val.speed4; current_rpm = rpm4; break;
        case 5: rpm5 = val.speed5; current_rpm = rpm5; break;
        case 6: rpm6 = val.speed6; current_rpm = rpm6; break;
        case 7: rpm7 = val.speed7; current_rpm = rpm7; break;
        case 8: rpm8 = val.speed8; current_rpm = rpm8; break;
        default: return;
    }

    Serial.print("can");
    Serial.print(_id);
    Serial.print(": ");
    Serial.println(current_rpm);
}