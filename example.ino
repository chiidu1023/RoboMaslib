#include <RoboMaslib.h>

RoboMaslib robo;

void setup() {

  robo.setup();//robomasのセットアップ

}


void loop() {

  robo.set(5);//ID

  robo.update(5,-2000);//ID,電流値

  robo.info(5,19);//ID,減速比 rpm,encの値を取得　 robo.rpm1(rpmN) robo.enc1(enc1)で値を計算の値として利用可

  Serial.print(robo.rpm5);

  Serial,ptint(robo.enc5);

}

