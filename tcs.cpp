// C++ code
//
#include <Servo.h>

int dist = 0;
Servo servo_8;

//Make sure to subscribe Technomekanics:)
String ssid     = "Simulator Wifi";  // SSID to connect to
String password = ""; // Our virtual wifi has no password 
String host     = "api.thingspeak.com"; // Open Weather Map API
const int httpPort   = 80;
String url_1     = "/update?api_key=6JJY0KP4Q0KT1CL9&field1=";
String url_2     = "/update?api_key=6JJY0KP4Q0KT1CL9&field2=";
String url_3     = "/update?api_key=6JJY0KP4Q0KT1CL9&field3=";


int setupESP8266(void) {
  // Start our ESP8266 Serial Communication
  Serial.begin(115200);   // Serial connection over USB to computer
  Serial.println("AT");   // Serial connection on Tx / Rx port to ESP8266
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 1;
    
  // Connect to 123D Circuits Simulator Wifi
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 2;
  
  // Open TCP connection to the host:
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 3;
  
  return 0;
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}


void function(void)
{
  dist = 0.01723 * readUltrasonicDistance(7, 7);
  if (dist <= 100) {
    servo_8.write(90);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_8.write(0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (digitalRead(2) == 1) {
    digitalWrite(12, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(12, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
  if (analogRead(A0) > 200) {
    digitalWrite(9, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(9, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}

void anydata(void) {
  
  int temp = map(analogRead(A0),20,358,-40,125);
  
  // Construct our HTTP call
  String httpPacket_temp = "GET " + url_1 + String(temp) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length_temp = httpPacket_temp.length();
  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length_temp);
  delay(10);
  // Send our http request
  Serial.print(httpPacket_temp);
  delay(10); // Wait a little for the ESP to respond
  

  String httpPacket_dist = "GET " + url_2 + String(dist) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length_dist = httpPacket_dist.length();
  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length_dist);
  delay(10);
  // Send our http request
  Serial.print(httpPacket_dist);
  delay(10); // Wait a little for the ESP to respond
  
  
  String httpPacket_pir = "GET " + url_3 + String(digitalRead(2)) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length_pir = httpPacket_pir.length();
  // Send our message length
  Serial.print("AT+CIPSEND=");
  Serial.println(length_pir);
  delay(10);
  // Send our http request
  Serial.print(httpPacket_pir);
  delay(10); // Wait a little for the ESP to respond
  if (!Serial.find("SEND OK\r\n")) return;
}


void setup()
{
  setupESP8266();
  servo_8.attach(8, 500, 2500);
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  function();
  anydata();
}
