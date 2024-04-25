
void setup() {
    mover_posIni();
  // put your setup code here, to run once:

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