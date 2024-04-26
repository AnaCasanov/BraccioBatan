#include <Servo.h>
#include <Braccio.h>

// Crear objetos de servos para cada articulación
Servo base; //Pin 11, de 0 a 180
Servo shoulder; //Pin 10, de 15 a 165
Servo elbow; //Pin 9, de 0 a 180
Servo wrist_rot; //pin 6, de 0 a 180
Servo wrist_ver; //Pin 5, de 0 a 180
Servo gripper; //Pin 3, de 10 a 73

//Posición de origen = Posición de búsqueda
const int base_home= 0;
const int shoulder_home= 40;
const int elbow_home= 180;
const int wrist_ver_home= 170;
const int wrist_rot_home= 0;
const int gripper_home = 73;

//Grados que gira en cada iteración
const int base_girar= 5 ;
int girando_reloj = 1;

//Grados de gripper para abrir o cerrar pinza
const int gripper_abrir=10;
const int gripper_cerrar=72;
//Posición de coger la bola
const int shoulder_coger = 80;
const int elbow_coger = 180;
const int wrist_rot_coger = 5;
//Posición de tirar
const int elbow_tirar=100; //Menor numero mas estirado
const int wrist_tirar=40; //Mayor numero mas estirado

//Pines para leer sensor de profundidad
int TRIG = 8;
int ECO = 7;

/*FUNCIONES PINZA*/
// Función para abrir la pinza del Braccio
void abrir_pinza() {
 Braccio.ServoMovement(1, base.read(), shoulder.read(), elbow.read(),wrist_rot.read(), wrist_ver.read(), gripper_abrir);
}

// Función para cerrar la pinza del Braccio
void cerrar_pinza() {
  Braccio.ServoMovement(1, base.read(), shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper_cerrar);
}

/*FUNCIONES MOVIMIENTO*/
// Función para moverse a la posición inicial 
void mover_pos_ini() {
  Braccio.ServoMovement(200, base_home, shoulder_home, elbow_home, wrist_rot_home, wrist_ver_home, gripper_home );
}

//Funcion coger bola
void coger_bola(){
  Braccio.ServoMovement(100, base.read(), shoulder_coger, elbow_coger, wrist_rot_coger, wrist_ver.read(), gripper.read());
}

/*FUNCIONES TIRAR BOLA -> No funcionan*/
void mover_pos_tirar() {
  Braccio.ServoMovement(600, base.read(), shoulder_home, elbow_tirar, wrist_tirar, wrist_ver.read(), gripper.read());

}

void tirar_bola() {
  Braccio.ServoMovement(3, base.read(), shoulder.read(), elbow_tirar+50, wrist_tirar, wrist_ver.read(), gripper.read());
  Braccio.ServoMovement(3, base.read(), shoulder.read(), elbow_tirar+100, 10, wrist_ver.read(), gripper_abrir);
}

/*BARRIDO ROBOT*/
//Función que hace girar el robot
void girar_robot(){
  int base_pos=base.read();
  if (base_pos>175){
    girando_reloj=0;
  }
  else if (base_pos<5) {
    girando_reloj=1;
  }
  if (girando_reloj==1) {
    Braccio.ServoMovement (10, base.read()+base_girar, shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper.read());
  }
  else {
    Braccio.ServoMovement (10, base.read()-base_girar, shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper.read());
  }
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
  Braccio.begin();
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  mover_pos_ini();
  abrir_pinza();
}
void loop() {
  abrir_pinza();
  coger_bola();
  cerrar_pinza();
  girar_robot();


  /*
  girar_robot();
  int distancia = medirDistancia();
  Serial.println(distancia);
  //if (distancia<20){
    abrir_pinza();
    coger_bola();
    cerrar_pinza();
    mover_pos_tirar();
    tirar_bola();
  //}*/

  delay(600);

}

