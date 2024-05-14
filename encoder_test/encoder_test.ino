// for fake ch340 https://github.com/SHWotever/FakeCH340DriverFixer/releases/tag/1.0

#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENCA 2 // YELLOW (Signal leitung (Impuls des Motors 11)) (Bewegung)
#define ENCB 3 // GREEN (Signal leitung (Auflösung 11 * Reduktion verhältnis = Auflösung)) (??? )

volatile int posi = 0; // specify posi as volatile

void setup() {
  Serial.begin(9600);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
}

void loop() {

  /**/
  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
  int pos = 0; 
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }
  Serial.println(pos);
  

  //int a = digitalRead(ENCA);
  //Serial.println(a);

  //int b = digitalRead(ENCB);
  //Serial.println(b);
}

void readEncoder() {

  int b = digitalRead(ENCB);
  if (b > 0) {
    posi++;
  } else {
    posi--;
  }
}