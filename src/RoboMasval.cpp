#include "RoboMasval.h"

void RoboMasval::setup(void) {
    Serial.println(F("Hello Teensy 4.1 CAN Test."));
    can3.begin();
    can3.setBaudRate(1000000);
}

void RoboMasval::set(int id_) {
    // 送信頻度の制限（3ms以下ならスキップ）
    if (millis() - pre_time_ < 3) return;
    pre_time_ = millis();

    // ID 0x200 への送信設定 (Motor 1-4)
    msg_send.id = 0x200;
    msg_send.len = 8;
    switch (id_) {
        case 1:
            msg_send.buf[0] = (motor1 >> 8) & 0xFF;
            msg_send.buf[1] = motor1 & 0xFF;
            break;
        case 2:
            msg_send.buf[2] = (motor2 >> 8) & 0xFF;
            msg_send.buf[3] = motor2 & 0xFF;
            break;
        case 3:
            msg_send.buf[4] = (motor3 >> 8) & 0xFF;
            msg_send.buf[5] = motor3 & 0xFF;
            break;
        case 4:
            msg_send.buf[6] = (motor4 >> 8) & 0xFF;
            msg_send.buf[7] = motor4 & 0xFF;
            break;
    }
    can3.write(msg_send);

    // ID 0x1FF への送信設定 (Motor 5-8)
    msg_send.id = 0x1FF;
    msg_send.len = 8;
    switch(id_) {
        case 5:
            msg_send.buf[0] = (motor5 >> 8) & 0xFF;
            msg_send.buf[1] = motor5 & 0xFF;
            break;
        case 6:
            msg_send.buf[2] = (motor6 >> 8) & 0xFF;
            msg_send.buf[3] = motor6 & 0xFF;
            break;
        case 7:
            msg_send.buf[4] = (motor7 >> 8) & 0xFF;
            msg_send.buf[5] = motor7 & 0xFF;
            break;
        case 8:
            msg_send.buf[6] = (motor8 >> 8) & 0xFF;
            msg_send.buf[7] = motor8 & 0xFF;
            break;
    }
    can3.write(msg_send);

    // 受信処理
    received = can3.read(msg_read);
    if (received) {
        uint8_t index = msg_read.id - 0x201;
        if (index < 8) {
            for (uint8_t i = 0; i < 3; i++) {
                int16_t buf = (msg_read.buf[2 * i] << 8) | msg_read.buf[2 * i + 1];
                status[index][i] = buf;
            }
            status[index][3] = msg_read.buf[6]; // 温度/エンコーダ情報
        }
    }
}

void RoboMasval::update(int id, int send, int rpm_) {
    // 入力値を-16384〜16384に制限して各モータ変数に格納
    int constrained_send = constrain(send, -16384, 16384);
    
    switch (id) {
        case 1: motor1 = constrained_send; break;
        case 2: motor2 = constrained_send; break;
        case 3: motor3 = constrained_send; break;
        case 4: motor4 = constrained_send; break;
        case 5: motor5 = constrained_send; break;
        case 6: motor6 = constrained_send; break;
        case 7: motor7 = constrained_send; break;
        case 8: motor8 = constrained_send; break;
    }
}

void RoboMasval::info(uint8_t ID_) {
    if (ID_ < 1 || ID_ > 8) return;
    
    int16_t current_speed = status[ID_ - 1][1];
    int current_encoder = status[ID_ - 1][3];

    switch(ID_) {
        case 1: speed1 = current_speed; encoder1 = current_encoder; break;
        case 2: speed2 = current_speed; encoder2 = current_encoder; break;
        case 3: speed3 = current_speed; encoder3 = current_encoder; break;
        case 4: speed4 = current_speed; encoder4 = current_encoder; break;
        case 5: speed5 = current_speed; encoder5 = current_encoder; break;
        case 6: speed6 = current_speed; encoder6 = current_encoder; break;
        case 7: speed7 = current_speed; encoder7 = current_encoder; break;
        case 8: speed8 = current_speed; encoder8 = current_encoder; break;
    }
}