const int BLED=9; //Контакт 9 для вывода BLUE RGB
const int GLED=10; //Контакт 10 для вывода GREEN RGB
const int RLED=11; //Контакт 11 для вывода Красного RGB
const int TEMP=0; // A0 для датчика температуры
const int LOWER_BOUND=53; // Нижний порог
const int UPPER_BOUND=62; // Верхний порог
int val = 0; //переменная для чтения аналогового значения

void setup() {
 pinMode (BLED, OUTPUT);
 pinMode (GLED, OUTPUT);
 pinMode (RLED, OUTPUT);
 Serial.begin(9600);
}

void loop() {
val = analogRead(TEMP);
Serial.println(val);
delay (2000);
if (val<=LOWER_BOUND)
  {
    digitalWrite(RLED,LOW);
    digitalWrite(GLED,LOW);
    digitalWrite(BLED,HIGH);
  }
  
  else if (val>UPPER_BOUND)
  {
    digitalWrite(RLED,HIGH);
    digitalWrite(GLED,LOW);
    digitalWrite(BLED,LOW);
  }
 else
 {
    digitalWrite(RLED,LOW);
    digitalWrite(GLED,HIGH);
    digitalWrite(BLED,LOW);
 }
}
