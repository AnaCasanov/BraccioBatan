//Pelayo estuvo aquí. (●'◡'●) fosky y pelayo estuvieron aquí (-0-)
const int base_home= 0 ;
const int shoulder_home= 40 ;
const int elbow_home= 180 ;
const int wrist_rot_home= 0 ;
const int wrist_ver_home= 170 ;
const int gripper_home= 72 ;
const int gripper_open= 10;
const int gripper_close= 73;

void setup() {


}

void loop() {
  leerposicion();
  delay(1000);

}
void mueverobot_1º(){
  Braccio.ServoMovement (220, base.read(), shoulder_home, elbow_home, wrist_rot_home, wrist_ver_home, gripper_home ); 
}