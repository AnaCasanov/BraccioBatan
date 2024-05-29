#include <Servo.h>
#include <Braccio.h>

// Crear objetos de servos para cada articulación
Servo base; //Pin 11, de 0 a 180
Servo shoulder; //Pin 10, de 15 a 165
Servo elbow; //Pin 9, de 0 a 180
Servo wrist_rot; //pin 6, de 0 a 180
Servo wrist_ver; //Pin 5, de 0 a 180
Servo gripper; //Pin 3, de 10 a 73

//Grados de gripper para abrir o cerrar pinza
const int gripper_abrir=10;
const int gripper_cerrar=72;

//Posiciones varias
const int base_coger = 90;
const int shoulder_coger = 85;
const int elbow_coger = 180;
const int wrist_rot_coger = 13;
const int wrist_ver_coger = 90;

const int base_dejar = 90;
const int shoulder_dejar = 80;
const int elbow_dejar = 180; // de 0 a 180, 180 más bajo, 170 más alto
const int wrist_rot_dejar = 90; // 0 a 180
const int wrist_ver_dejar = 90;

//Pines para leer sensor de profundidad
int TRIG = 8;
int ECO = 7;

//Rango distancias bola encontrada
int d_max = 13;
int d_min = 10;

/*FUNCIONES PINZA*/
// Función para abrir la pinza del Braccio
void abrir_pinza() {
 Braccio.ServoMovement(100, base.read(), shoulder.read(), elbow.read(),wrist_rot.read(), wrist_ver.read(), gripper_abrir);
}
// Función para cerrar la pinza del Braccio
void cerrar_pinza() {
  Braccio.ServoMovement(100, base.read(), shoulder.read(), elbow.read(), wrist_rot.read(), wrist_ver.read(), gripper_cerrar);
}

/*FUNCIONES MOVIMIENTO*/
void pos_coger(){
  Braccio.ServoMovement(500, base_coger, shoulder_coger, elbow_coger, wrist_rot_coger, wrist_ver_coger, gripper.read());
}

void pos_dejar(){
  Braccio.ServoMovement(500, base_dejar, shoulder_dejar, elbow_dejar, wrist_rot_dejar, wrist_ver_dejar, gripper.read());
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
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Braccio.begin();
  abrir_pinza();
  pos_dejar();
}
void loop() {
  int d = medirDistancia();
  Serial.println(d);
  if (d<=d_max && d>=d_min){
    pos_coger();
    cerrar_pinza();
    pos_dejar();
    d = medirDistancia();
    while (d<d_min || d>d_max){
      //Se queda en este bucle hasta que alguien pase la mano por debajo
      delay(50);
      d=medirDistancia();
      Serial.println(d);
    }
    //Cuando alguien pasa la mano por debajo, debe soltar la bola
    abrir_pinza();
  }
  delay(50);
}

