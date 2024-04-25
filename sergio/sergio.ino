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


void coger_bola() {

  Braccio.ServoMovement(200, base.read(), 80, elbow.read(), wrist_rot.read(), wrist_ver.read(), 10);

}

void cerrar_pinza() {

  Braccio.ServoMovement(200, base.read(), shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), 72);

}

void mover_pos_tirar() {

  Braccio.ServoMovement(200, base.read(), shoulder.read(), 80, wrist_rot.read(), 100, gripper.read());

}


void tirar_bola() {

  Braccio.ServoMovement(30, base.read(), shoulder.read(), 220, wrist_rot.read(), 40, 10);

}

void setup() {

  Braccio.begin();
  coger_bola();
  delay(1000);
  cerrar_pinza();
  delay(1000);
  mover_pos_tirar();
  delay(2000);
  tirar_bola();
}

void loop() {

  
}
