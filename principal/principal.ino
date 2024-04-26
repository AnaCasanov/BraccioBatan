#include <Servo.h>
#include <Braccio.h>
int TRIG = 10;
int ECO = 9;

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
const int base_girar= 1 ;
  
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
//Función que hace girar el robot
void mueverobot_girar(){
  Braccio.ServoMovement (220, base.read()+base_girar, shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper.read() ); 
}
//Funcion coger bola
void coger_bola(){

}

void mover_pos_tirar(){

}
void tirar_bola(){

}

//Función de detectar distancia
int medirDistancia(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  int duracion = pulseIn(ECO, HIGH);
  int distancia = duracion / 58.2;
  return distancia;  
}


void setup() {
  mover_posIni();
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Braccio.begin();
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

