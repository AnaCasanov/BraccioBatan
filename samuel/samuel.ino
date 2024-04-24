
#include <Braccio.h>
#include <Servo.h> 
  const int base_home= 0;
  const int shoulder_home= 40;
  const int elbow_home= 180;
  const int wrist_rot_home= 0;
  const int wrist_ver_home= 170;
  const int gripper_home= 72;

void mover_posIni() {
  Braccio.ServoMovement( base_home, shoulder_home, elbow_home, wrist_rot_home, wrist_ver_home, gripper_home );
}


void setup(){
 Braccio.ServoMovement(); 
}


void loop() {
  // put your main code here, to run repeatedly:

}
