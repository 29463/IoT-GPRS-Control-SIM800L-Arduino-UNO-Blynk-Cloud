#define BLYNK_TEMPLATE_ID   "TMPL6uDMl0W4z"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN    "FeJq5W_C2IHoL4MpepKmX87k0qZ9xXo5"

#define BLYNK_HEARTBEAT 120   // try 120 or 180 for GSM stability [web:87]

#define BLYNK_PRINT Serial
#define TINY_GSM_MODEM_SIM800

#include <SoftwareSerial.h>
#include <TinyGsmClient.h>
#include <BlynkSimpleTinyGSM.h>

// ---- Your Zong APN ----
char apn[]  = "zongwap";
char user[] = "";
char pass[] = "";

// ---- SIM800L serial (SET TO 9600) ----
SoftwareSerial SerialAT(2, 3); // RX=2, TX=3

TinyGsm modem(SerialAT);
BlynkTimer timer;

const int LED_PIN = 8;

BLYNK_WRITE(V0)
{
  int value = param.asInt();              
  digitalWrite(LED_PIN, value ? HIGH : LOW);
  Blynk.virtualWrite(V1, value);          
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0);
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Console for debugging (Keep at 115200)
  Serial.begin(115200);
  delay(100);

  // ---- THIS IS THE FIX: 9600 BAUD ----
  SerialAT.begin(9600); 
  delay(3000);

  Serial.println("Initializing modem...");
  
  // Restart modem to ensure fresh connection
  modem.restart(); 

  String modemInfo = modem.getModemInfo();
  Serial.print("Modem Info: ");
  Serial.println(modemInfo);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, modem, apn, user, pass);
}

void loop()
{
  Blynk.run();
  timer.run();
}