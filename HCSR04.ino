/* Programa para módulo ultrasonido.
Usa la velocidad del sonido en el aire a temperatura
ambiente "340m/s (0.034 cm/us)" para calcular la distancia
presente entre el sensor y un objeto presenta en dirección del sensor.*/

#define trigPin 13           //Pin digital 13 para el Trigger del sensor
#define echoPin 12           //Pin digital 12 para el Echo del sensor

void setup() {
Serial.begin(9600);          //inicializar comunicación serial a 9600 baudios
pinMode (trigPin, OUTPUT);   //pin como salida
pinMode (echoPin, INPUT);    //pin como entrada
digitalWrite(trigPin, LOW);  //Inicializamos el pin con 0
}

void loop() {
 int duracion, distancia;
 int pin=0;
 digitalWrite(trigPin, HIGH);              // pulso de disparo
 delayMicroseconds(1000);                  // duración de pulso 1000 microsegundos
 digitalWrite(trigPin, LOW);               // terminar pulso de disparo
 duracion = pulseIn(echoPin, HIGH);        // obtenemos el ancho del pulso, "pulseIn(pin, value)" es decir el tiempo que dura en llegar el eco del ultrasonido
 distancia = (duracion/2)*0.034;             // ecuación para medir la distancia en CM
 if (distancia == 81)
//   { for ( pin=1 ; pin > 0; pin++)
//         //pin = pin + 1;
//         //Serial.print(pin);
//     { if (pin >5) 
//      {Serial.print("Led on \n");
//      delay(1000);
//      }
//     }
//    } 
 Serial.print(distancia);                  // se envían los datos por com serial
 Serial.print(" cm \n");                   // se escribe la unidad de medida y el caracter de nueva línea
 delay(1000);                              // imprimir datos cada 1000 ms
 }
