int a = 10;
int val = 0;
float ct = A0;  //ADC
float c = 0;
int n = 0;
float Potstep = 0.0078;  // fixed due to the DAC resolution
int scan_rate = 100;     // mV/s
long intervalos = (1000000L / (scan_rate * 128L));

void setup() {
  TCCR1B = TCCR1B & B11111000 | B00000001;  //Set dividers to change PWM frequency
  Serial.begin(9600);

  pinMode(a, OUTPUT);
  pinMode(ct, INPUT);
}

void loop() {
  while (n <= 1) {
    //Start the forward scan
    for (val = 0; val <= 255; val++) {
      analogWrite(a, val);
      Serial.print(val);
      delay(intervalos);
      //c = ((0.00195*(analogRead(ct))-1)*1000); // Current reading outputs in uA!!!
      c = analogRead(ct);
      Serial.print(" ");
      Serial.print(c);
      Serial.print(" ");
      Serial.print(n);
      Serial.print(" ");
      Serial.print(scan_rate);
      Serial.print(" ");
      Serial.println(intervalos);
    }
    //Start the reverse scan
    for (val = 255; val >= 0; val--) {
      analogWrite(a, val);
      Serial.print(val);
      delay(intervalos);
      //c = ((0.00195*(analogRead(ct))-1)*1000); // Current reading outputs in uA!!!

      c = analogRead(ct);
      Serial.print(" ");
      Serial.print(c);
      Serial.print(" ");
      Serial.print(n);
      Serial.print(" ");
      Serial.print(scan_rate);
      Serial.print(" ");
      Serial.println(intervalos);
    }
    n = n + 1;
  }
}