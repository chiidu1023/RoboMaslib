#include "RoboMasval.h"

void RoboMasval::setup(void) {
    Serial.println(F("Hello Teensy 4.1 CAN Test.")); //
    can3.begin(); //
    can3.setBaudRate(1000000); //
}

void RoboMasval::set(int id_) {
    if (millis() - pre_time_ < 3) return; //
    pre_time_ = millis(); //

    // モーター 1-4 用 (ID 0x200)
    msg_send.id = 0x200; //
    msg_send.len = 8; //
    switch (id_) {
        case 1: msg_send.buf[0] = (motor1 >> 8) & 0xFF; msg_send.buf[1] = motor1 & 0xFF; break; //
        case 2: msg_send.buf[2] = (motor2 >> 8) & 0xFF; msg_send.buf[3] = motor2 & 0xFF; break; //
        case 3: msg_send.buf[4] = (motor3 >> 8) & 0xFF; msg_send.buf[5] = motor3 & 0xFF; break; //
        case 4: msg_send.buf[6] = (motor4 >> 8) & 0xFF; msg_send.buf[7] = motor4 & 0xFF; break; //
    }
    can3.write(msg_send); //

    // モーター 5-8 用 (ID 0x1FF)
    msg_send.id = 0x1FF; //
    msg_send.len = 8; //
    switch(id_) {
        case 5: msg_send.buf[0] = (motor5 >> 8) & 0xFF; msg_send.buf[1] = motor5 & 0xFF; break; //
        case 6: msg_send.buf[2] = (motor6 >> 8) & 0xFF; msg_send.buf[3] = motor6 & 0xFF; break; //
        case 7: msg_send.buf[4] = (motor7 >> 8) & 0xFF; msg_send.buf[5] = motor7 & 0xFF; break; //
        case 8: msg_send.buf[6] = (motor8 >> 8) & 0xFF; msg_send.buf[7] = motor8 & 0xFF; break; //
    }
    can3.write(msg_send); //

    received = can3.read(msg_read); //
    if (received) {
        uint8_t index = msg_read.id - 0x201; //
        if (index < 8) {
            for (uint8_t i = 0; i < 3; i++) {
                int16_t buf = (msg_read.buf[2 * i] << 8) | msg_read.buf[2 * i + 1]; //
                status[index][i] = buf; //
            }
            status[index][3] = msg_read.buf[6]; //
        }
    }
}

void RoboMasval::update(int id, int send, int rpm_) {
    int constrained_send = constrain(send, -16384, 16384); //
    switch (id) {
        case 1: motor1 = constrained_send; break; //
        case 2: motor2 = constrained_send; break; //
        case 3: motor3 = constrained_send; break; //
        case 4: motor4 = constrained_send; break; //
        case 5: motor5 = constrained_send; break; //
        case 6: motor6 = constrained_send; break; //
        case 7: motor7 = constrained_send; break; //
        case 8: motor8 = constrained_send; break; //
    }
}

void RoboMasval::info(uint8_t ID_) {
    if (ID_ < 1 || ID_ > 8) return; //
    speed1 = status[ID_ - 1][1]; //
    // 実際には各変数に代入
    switch(ID_) {
        case 1: speed1 = status[0][1]; encoder1 = status[0][3]; break; //
        case 2: speed2 = status[1][1]; encoder2 = status[1][3]; break; //
        case 3: speed3 = status[2][1]; encoder3 = status[2][3]; break; //
        case 4: speed4 = status[3][1]; encoder4 = status[3][3]; break; //
        case 5: speed5 = status[4][1]; encoder5 = status[4][3]; break; //
        case 6: speed6 = status[5][1]; encoder6 = status[5][3]; break; //
        case 7: speed7 = status[6][1]; encoder7 = status[6][3]; break; //
        case 8: speed8 = status[7][1]; encoder8 = status[7][3]; break; //
    }
}

void RoboMasval::set_PID(uint8_t ID_, float kp, float ki, float kd) {
    // PID設定の実装が必要な場合はここに追加
}