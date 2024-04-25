#include <Servo.h>
#include <Braccio.h>


// Crear objetos de servos para cada articulación
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

  
// Función para abrir la pinza del Braccio
void openGripper() {
 Braccio.ServoMovement(500, base.read(), shoulder.read(), elbow.read(), 
                       wrist_rot.read(), wrist_ver.read(), 10);
}

// Función para cerrar la pinza del Braccio
void closeGripper() {
 Braccio.ServoMovement(500, base.read(), shoulder.read(), elbow.read(), 
                       wrist_rot.read(), wrist_ver.read(), 73);
}

// Función para moverse a la posición inicial 
void mover_posIni() {
  Braccio.ServoMovement(200, base_home, shoulder_home, elbow_home, wrist_rot_home, wrist_ver_home, gripper_home );
}
//Función mueverobot
void mueverobot_girar(){

}
//Funcion coger bola
void coger_bola(){

}

void mover_pos_tirar(){

}
void tirar_bola(){

}
int medirDistancia(){

}


void setup() {
    mover_posIni();
  
}
void loop() {
  mueverobot_girar();
  int distancia = medirDistancia();
  Serial.println(distancia);
  if (distancia<20){
    openGripper();
    coger_bola();
    closeGripper();
    mover_pos_tirar();
    tirar_bola();
  }

}

