
#include <Braccio.h>
#include <Servo.h> 

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

  const int base_home= 0;
  const int shoulder_home= 80;
  const int elbow_home= 180;
  const int wrist_rot_home= 0;
  const int wrist_ver_home= 170;
  const int gripper_home= 72;

void mover_posIni() {
  Braccio.ServoMovement(220, base_home, shoulder_home, elbow_home, wrist_rot_home, wrist_ver_home, gripper_home );
}


void setup(){
  Braccio.begin();
  mover_posIni(); 
}


void loop() {
  // put your main code here, to run repeatedly:

}
