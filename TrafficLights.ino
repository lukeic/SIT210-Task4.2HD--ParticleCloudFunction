const int RED_LED = D4;
const int YELLOW_LED = D2;
const int GREEN_LED = D3;

int toggleLight(String lightName) {
  int light;

  if (lightName == "red") {
    light = RED_LED;
  } else if (lightName == "yellow") {
    light = YELLOW_LED;
  } else if (lightName == "green") {
    light = GREEN_LED;
  } else {
    return -1;
  }

  int currentValue = digitalRead(light);
  if (currentValue == HIGH) {
    digitalWrite(light, LOW);
  } else {
    digitalWrite(light, HIGH);
  }

  return 0;
}

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  Particle.function("toggleLight", toggleLight);
}

void loop() {
}
