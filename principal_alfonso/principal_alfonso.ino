<<<<<<< Updated upstream
#include <Servo.h>
#include <Braccio.h>


// Crear objetos de servos para cada articulación
Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;


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
void setup() {
  // put your setup code here, to run once:
=======
//Pelayo estuvo aquí. (●'◡'●) fosky y pelayo estuvieron aquí (-0-)
//Onichan estuvo aquí
//El padre de Fueyo estuvo aquí
>>>>>>> Stashed changes

int TRIG = 10;
int ECO = 9;
int DISTANCIA;
int DURACION;
int BOLA;
//╰(*°▽°*)╯

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);
  if(DISTANCIA<=)

}
