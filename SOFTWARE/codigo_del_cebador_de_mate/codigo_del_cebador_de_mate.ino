// Hecho por santino fernandez y ramiro ayala 6-5
//Codigo del cebador de mat  y explicacion de cada parte 

#define BLYNK_TEMPLATE_ID "TMPL2VupCpP-n" // identifica tu proyecto
#define BLYNK_TEMPLATE_NAME "CEBADOR DE MATE" // el nombre de tu proyecto
#define BLYNK_AUTH_TOKEN "jizlQK03tLrJrDWALezB_Saujrhl8S9G" // clave que conecta el esp32 con la cuenta d blynk

#include <WiFi.h> // permite conectar el esp32 al wifi junto con el wificlient
#include <WiFiClient.h> 
#include <BlynkSimpleEsp32.h> // sirve para que el blynk se pueda comunicar con el esp

char ssid[] = "Estudiantes"; // el nombre de la red a la que esta conectado el esp
char pass[] = "Escuelas_2025"; // la contraseña de la red

#define VALVULA_PIN 17 // el pin del rele q uso
BLYNK_WRITE(V0) // el boton de blynk c llama v0
{ int boton = param.asInt(); // la variable del boton v0 y el param.asint para que convierta los datos recibidos en numeros enteros, osea 1= encendido y 0= apagado
digitalWrite(VALVULA_PIN, boton); }

void setup()
{ pinMode(VALVULA_PIN, OUTPUT);
digitalWrite(VALVULA_PIN, LOW); // esto es para que el pin este apagado desde un principio, osea este en 0

Serial.begin(115200); // los bits por segundo

Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass); // conecta el blynk a la red wifi
} 

void loop()
{ Blynk.run(); } // sirve para que la conexion se mantenga y ve si hay cambios en la app