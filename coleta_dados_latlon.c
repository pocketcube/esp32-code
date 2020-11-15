#define GPS_RX 4
#define GPS_TX 3
#define GPS_Serial_Baud 9600
#include <SoftwareSerial.h>
#include <TinyGPS.h>
TinyGPS gps;
SoftwareSerial gpsSerial(GPS_RX, GPS_TX);
void setup()
{
Serial.begin(GPS_Serial_Baud);
gpsSerial.begin(GPS_Serial_Baud);
}
void loop()
{
bool newData = false;
unsigned long chars;
// Por um segundo, analisamos os dados do GPS e
// relatamos alguns valores-chave
for (unsigned long start = millis(); millis() - start < 1000;)
{
while (gpsSerial.available())
{
char c = gpsSerial.read();
// Serial.write(c); //apague o comentario para mostrar os dados crus
if (gps.encode(c)) / Atribui true caso novos dados sejam recebidos
newData = true;
}
}
if (newData)
{
float flat, flon;
unsigned long age;
gps.f_get_position(&flat, &flon, &age);