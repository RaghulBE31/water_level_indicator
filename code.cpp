#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Create an instance of the server
ESP8266WebServer server(80);

// Define pins
const int trigPin = D2;
const int echoPin = D1;

// Tank dimensions
const int tankHeight = 200; // Total height of the tank in cm
const int tankWidth = 100;   // Width of the tank for visual representation

void setup() {
  Serial.begin(115200);
  
  // Initialize the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  // Define the web server route
  server.on("/", handleRoot);
  server.on("/tank", handleTank);
  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>Water Tank Level</h1>";
  html += "<div style='width: " + String(tankWidth) + "px; height: " + String(tankHeight) + "px; border: 1px solid #000; position: relative;'>";
  html += "<div id='water' style='position: absolute; bottom: 0; background-color: #00f; width: 100%;'></div>";
  html += "</div>";
  html += "<p id='level'>Water Level: 0 cm</p>";
  html += "<script>";
  html += "setInterval(() => {";
  html += "fetch('/tank').then(response => response.text()).then(data => {";
  html += "const level = parseInt(data);";
  html += "document.getElementById('water').style.height = (level / " + String(tankHeight) + " * 100) + '%';";
  html += "document.getElementById('level').innerText = 'Water Level: ' + level + ' cm';";
  html += "});";
  html += "}, 1000);"; // Update every second
  html += "</script></body></html>";
  server.send(200, "text/html", html);
}

void handleTank() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Calculate distance in cm

  // Return distance to the client
  server.send(200, "text/plain", String(distance));
}
