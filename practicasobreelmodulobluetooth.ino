//Oscar Barrios - 2022241

#include <SoftwareSerial.h>//Libreria para Bluetooth
#include <Servo.h>//Libreria para el servo
#include "LedControl.h"//Libreria LedControl

LedControl lc=LedControl(11,13,10,1);//Se coloca los pines que se van a usar y la cantidad de matrices qeu se usan
SoftwareSerial BT(8, 9);//Pines del HC-06

char val;//Variables
int ledrojo = 7;//Variables
int ledrojo2 = 3;//Variables
int ledrojo3 = 6;//Variables
int ledrojo4 = 5;//Variables
const int servoPin1 = 4;//Variables

byte uno[8]= {//array que contiene todos los elementos de las
  B00010000,//filas necesarias por mostrar el digito uno
  B00110000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00010000,
  B00111000
};

Servo servo;//Se establece el nombre del servo

void setup() {
  Serial.begin(9600);//Monitor serial
  BT.begin(9600);//Se inicializa el modulo bluetooth
  pinMode(ledrojo, OUTPUT);//Se configura los pines como salida
  pinMode(ledrojo2, OUTPUT);
  servo.attach(servoPin1);
  lc.shutdown(0,false);//enciende la matriz
  lc.setIntensity(0,4);//establece brillo
  lc.clearDisplay(0);//blanquea matriz
}



void loop() {

movimiento();//Una variable que va a servir para el servo

  if(BT.available() > 0){
    val = BT.read();
    Serial.println(val);//Se imprime variable val
  }

  if(val == 'A'){
    digitalWrite(ledrojo, HIGH);//Si se manda la señal "A" se enciende el led
  }

  if(val == 'B'){
    digitalWrite(ledrojo, LOW);//Si se manda la señal "B" se apaga el led
  }

  if(val == 'C'){
    digitalWrite(ledrojo2, HIGH);//Si se manda la señal "C" se enciende el led
  }

  if(val == 'D'){
    digitalWrite(ledrojo2, LOW);//Si se manda la señal "D" se apaga el led
  }

    if(val == 'E'){
    digitalWrite(ledrojo3, HIGH);//Si se manda la señal "E" se enciende el led
  }

  if(val == 'F'){
    digitalWrite(ledrojo3, LOW);//Si se manda la señal "F" se apaga el led
  }

    if(val == 'G'){
    digitalWrite(ledrojo4, HIGH);//Si se manda la señal "G" se enciende el led
  }

  if(val == 'H'){
    digitalWrite(ledrojo4, LOW);
  }
  
  if(val == 'H'){
    digitalWrite(ledrojo4, LOW);
  }
  
  if(val == 'I'){
    mostrar_1();//Se muestra el numero
  }
}

void movimiento(){//Se crea esto para mover el servo
  while(BT.available() > 0){
    val = BT.read();
    Serial.println(val);
    servo.write(val);
    delay(10);
  }
}

void mostrar_1(){     // funcion mostrar_1
  for (int i = 0; i < 8; i++)     // bucle itera 8 veces por el array
  {
  lc.setRow(0,i,uno[i]);    // establece fila con valor de array uno en misma posicion
  }
}