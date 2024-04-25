int TRIG = 10;
int ECO = 9;


int medirDistancia(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  int duracion = pulseIn(ECO, HIGH);
  int distancia = duracion / 58.2;
  return distancia;  
}
void setup_alfonso() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECO, INPUT);
}

void setup(){}
void loop() {


}
