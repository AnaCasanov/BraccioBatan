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

}

void loop() {
  // put your main code here, to run repeatedly:

}
