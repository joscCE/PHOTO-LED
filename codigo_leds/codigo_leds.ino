// Pines de conexión
const int pinFotoresistencia = A0;
const int led1 = 7;
const int led2 = 6;
const int led3 = 5;

// Variables para almacenar el valor leído de la fotoresistencia
int valorLuz = 0;

// Valores a los que encienden las leds
int EN_1 = 883;
int EN_2 = 954;
int EN_3 = 974;

void setup() {
  // Configuramos los pines de los LEDs como salida
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Iniciamos la comunicación serial (opcional, para depuración)
  Serial.begin(9600);
}

void loop() {
  // Leemos el valor de la fotoresistencia
  valorLuz = analogRead(pinFotoresistencia);
  
  // Enviamos el valor al monitor serial (opcional)
  Serial.println(valorLuz);
  
  // Lógica para encender los LEDs según el nivel de luz
  if (valorLuz > EN_1 && valorLuz < EN_2) {
    // Baja luz: encender el LED 1
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (valorLuz >= EN_2 && valorLuz < EN_3) {
    // Luz media: encender los LEDs 1 y 2
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if(valorLuz >= EN_3) {
    // Alta luz: encender todos los LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);

  }
  
  // Pequeño retardo para estabilidad
  delay(100);
}
