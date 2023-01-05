#define ECHO 9
#define TRIG 8
#define relay 3
long duration;
int distance;


bool is_cat_sound = false;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
  digitalWrite(relay, HIGH);
}

void loop() {

  int val_distance = map(analogRead(A0), 0, 1024, 100, 10);       //0-100 cm
  int val_timedelay = map(analogRead(A1), 0, 1024, 10000, 100);  // 0-5 sec

  Serial.print("val_distance = ");
  Serial.println(val_distance);
  Serial.print("val_timedelay = ");
  Serial.println(val_timedelay);

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < val_distance && !is_cat_sound) {
    digitalWrite(relay, LOW);
    is_cat_sound = true;
    delay(1000);
    digitalWrite(relay, HIGH);
    delay(val_timedelay);
    is_cat_sound = false;
  }
 

}
