#include <Braccio.h>
#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;

  const int base_home= 0;
  const int shoulder_home= 40;
  const int elbow_home= 180;
  const int wrist_rot_home= 0;
  const int wrist_ver_home= 170;
  const int gripper_home= 72;
  
  const int shoulder_coger=80;

  const int gripper_abrir=10;
  const int gripper_cerrar=72;

  const int elbow_tirar=100;
  const int wrist_tirar=40;


void coger_bola() {

  Braccio.ServoMovement(200, base.read(), shoulder_coger, elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper_abrir);

}

void cerrar_pinza() {

  Braccio.ServoMovement(200, base.read(), shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper_cerrar);

}

void mover_pos_tirar() {

  Braccio.ServoMovement(600, base.read(), shoulder_home, elbow_tirar, wrist_tirar, wrist_ver.read(), gripper.read());

}



void tirar_bola() {

  Braccio.ServoMovement(3, base.read(), shoulder.read(), elbow_tirar+50, wrist_tirar, wrist_ver.read(), gripper.read());
  Braccio.ServoMovement(3, base.read(), shoulder.read(), elbow_tirar+100, 10, wrist_ver.read(), gripper_abrir);


}

void setup() {

  Braccio.begin();
  delay(500);
  coger_bola();
  delay(500);
  cerrar_pinza();
  delay(500);
  mover_pos_tirar();
  delay(1000);
  tirar_bola();
}

void loop() {

  
}
