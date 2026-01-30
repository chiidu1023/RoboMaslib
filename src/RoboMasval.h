#pragma once
#include <FlexCAN_T4.h>
#include <PIDController.h>
class RoboMasval{
    public:
    FlexCAN_T4<CAN3, RX_SIZE_256, TX_SIZE_16> can3;
    CAN_message_t msg_read;
    CAN_message_t msg_send;
    bool received;
    uint32_t pre_time_ = 0;
    uint32_t pre_time__ = 0;
    int ID = 0x200;
    void setup (void);
    void set(int id_);
    void update(int id,int send, int rpm_);
    void info(uint8_t _id);
    void set_PID(uint8_t ID_ , float kp=0.65, float ki=0, float kd=0);
    PIDController pid1, pid2, pid3, pid4, pid5, pid6, pid7, pid8;
    int status[8][4];
    int motor1 = 0, motor2 = 0, motor3 = 0, motor4 = 0;
    int motor5 = 0, motor6 = 0, motor7 = 0, motor8 = 0;
    int16_t speed1,speed2,speed3,speed4;
    int16_t speed5,speed6,speed7,speed8;
    int encoder1,encoder2,encoder3,encoder4;
    int encoder5,encoder6,encoder7,encoder8;
};
void RoboMasval::setup(void){
    Serial.println(F("Hello Teensy 4.1 CAN Test."));
    can3.begin();
    can3.setBaudRate(1000000);
}
void RoboMasval::set(int id_) {
        if (millis() - pre_time_ < 3) return;
        pre_time_ = millis();
        msg_send.id = 0x200;
        msg_send.len = 8;
        switch (id_){
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
        msg_send.id = 0x1FF;
        msg_send.len = 8;
        switch(id_){
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
        received = can3.read(msg_read);
        if (received) {
            uint8_t index = msg_read.id - 0x201;
            if (index < 8) {
                for (uint8_t i = 0; i < 3; i++) {
                    int16_t buf = (msg_read.buf[2 * i] << 8) | msg_read.buf[2 * i + 1];
                    status[index][i] = buf;
                }
                status[index][3] = msg_read.buf[6]; // 温度
            }
        }
    }
    void RoboMasval::update(int id,int send,int rpm_){
        
            switch (id){
                case 1:
                    send=constrain(send, -16384, 16384);
                    motor1=send;
                    break;
                case 2:
                    send=constrain(send, -16384, 16384);
                    motor2=send;
                    break;
                case 3:
                    send=constrain(send, -16384, 16384);
                    motor3=send;
                    break;
                case 4:
                    send=constrain(send, -16384, 16384);
                    motor4=send;
                    break;
                case 5:
                    send=constrain(send, -16384, 16384);
                    motor5=send;
                    break;
                case 6:
                    send=constrain(send, -16384, 16384);
                    motor6=send;
                    break;
                case 7:
                    send=constrain(send, -16384, 16384);
                    motor7=send;
                    break;
                case 8:
                    send=constrain(send, -16384, 16384);
                    motor8=send;
                    break;
            }
    }
     void RoboMasval::info(uint8_t ID_) {
        switch(ID_){
            case 1:
             speed1=status[ID_ - 1][1];
             encoder1=status[ID_ - 1][3];
             break;
            case 2:
             speed2=status[ID_ - 1][1];
             encoder2=status[ID_ - 1][3];
             break;
            case 3:
             speed3=status[ID_ - 1][1];
             encoder3=status[ID_ - 1][3];
             break;
            case 4:
             speed4=status[ID_ - 1][1];
             encoder4=status[ID_ - 1][3];
             break;
            case 5:
             speed5=status[ID_ - 1][1];
             encoder5=status[ID_ - 1][3];
             break;
            case 6:
             speed6=status[ID_ - 1][1];
             encoder6=status[ID_ - 1][3];
             break;
            case 7:
             speed7=status[ID_ - 1][1];
             encoder7=status[ID_ - 1][3];
             break;
            case 8:
             speed8=status[ID_ - 1][1];
             encoder8=status[ID_ - 1][3];
             break;
        }
    }