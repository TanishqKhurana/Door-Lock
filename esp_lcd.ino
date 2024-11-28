#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>


const char* ssid = "Anshika's";
const char* password = "anshi1821";


const int servoPin = 14;
Servo doorServo;


const int greenLedPin = 26; 
const int redLedPin = 27;   


String entryStatus = "No action yet"; 


WebServer server(80);


void handleApprove() {
  doorServo.write(90); 
  entryStatus = "Entry Approved";
  digitalWrite(greenLedPin, HIGH);
  digitalWrite(redLedPin, LOW);
  server.send(200, "text/plain", entryStatus);
}

void handleDeny() {
  doorServo.write(0); 
  entryStatus = "Entry Denied";
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, HIGH);
  server.send(200, "text/plain", entryStatus);
}

void handleReset() {
  doorServo.write(0); 
  entryStatus = "System Reset";
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);
  server.send(200, "text/plain", entryStatus);
}


void handleRoot() {
  String html = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<title>Smart Door Lock</title>"
                "<style>"
                "body { font-family: Arial, sans-serif; text-align: center; margin: 0; padding: 0; background-color: #f4f4f4; }"
                "h1 { color: #333; margin-top: 20px; }"
                "p { font-size: 18px; color: #555; }"
                "a { display: inline-block; margin: 10px; padding: 10px 20px; text-decoration: none; font-size: 18px; border-radius: 5px; }"
                ".approve { background-color: #4CAF50; color: white; }"
                ".deny { background-color: #f44336; color: white; }"
                ".reset { background-color: #2196F3; color: white; }"
                ".approve:hover { background-color: #45a049; }"
                ".deny:hover { background-color: #d32f2f; }"
                ".reset:hover { background-color: #1E88E5; }"
                "#status { margin-top: 20px; font-size: 20px; color: #333; }"
                "iframe { margin-top: 20px; border: none; width: 640px; height: 480px; }"
                "</style>"
                "<script>"
                "function sendAction(action) {"
                "  const xhr = new XMLHttpRequest();"
                "  xhr.open('GET', '/' + action, true);"
                "  xhr.onload = function() {"
                "    if (xhr.status === 200) {"
                "      document.getElementById('status').innerText = xhr.responseText;"
                "    }"
                "  };"
                "  xhr.send();"
                "} "
                "</script>"
                "</head>"
                "<body>"
                "<h1>Smart Door Lock</h1>"
                "<p>Person Detected: <strong>Yes</strong></p>"
                "<a href='#' class='approve' onclick=\"sendAction('approve')\">Approve Entry</a>"
                "<a href='#' class='deny' onclick=\"sendAction('deny')\">Deny Entry</a>"
                "<a href='#' class='reset' onclick=\"sendAction('reset')\">Reset</a>"
                "<div id='status'>" + entryStatus + "</div>"
                "<iframe src='http://192.168.193.87:5000'></iframe>"
                "</body>"
                "</html>";
  server.send(200, "text/html", html);
}


void setup() {

  Serial.begin(115200);


  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);


  doorServo.attach(servoPin);
  doorServo.write(0); 


  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  int wifiRetries = 0;
  while (WiFi.status() != WL_CONNECTED && wifiRetries < 20) { 
    delay(500);
    Serial.print(".");
    wifiRetries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWi-Fi connected");
    Serial.println("IP Address: " + WiFi.localIP().toString());


    server.on("/", handleRoot);
    server.on("/approve", handleApprove);
    server.on("/deny", handleDeny);
    server.on("/reset", handleReset);

    server.begin();
    Serial.println("Web server started");
  } else {
    Serial.println("\nFailed to connect to Wi-Fi. Check credentials.");
  }
  Serial.println("Starting handleRoot setup");
  server.on("/", handleRoot);
  Serial.println("Root handler set up");

}

void loop() {

  server.handleClient();
}
