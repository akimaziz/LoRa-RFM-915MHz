#include <RH_RF95.h>
#include <DHT.h>
#include <Adafruit_PCD8544.h>
#include <Adafruit_GFX.h>

// Define YouTube symbol bitmap data
#define YOUTUBE_WIDTH  84
#define YOUTUBE_HEIGHT 48
#define intelkecik_lebar 44
#define intelkecik_tinggi 28
#define inteli9_lebar 44
#define inteli9_tinggi 28
#define palestin_WIDTH  84
#define palestin_HEIGHT 48

static const unsigned char PROGMEM youtube_bitmap[] = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x1f, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x80, 0x00, 0x01, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 
  0xf0, 0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x03, 
  0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x03, 
  0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x1e, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x03, 0x80, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xc0, 0x00, 
  0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x03, 0xc0, 0x00, 0x0f, 0x00, 0x00, 0x03, 0x80, 
  0x00, 0x00, 0xe0, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0xe0, 0x01, 0xe0, 
  0x01, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0xe0, 0x01, 0xe0, 0x02, 0x00, 0x00, 0x00, 0x03, 
  0xc0, 0x02, 0x00, 0xe0, 0x01, 0xe0, 0x06, 0x0f, 0x07, 0xff, 0x03, 0xf0, 0x7f, 0xc0, 0xe0, 0x01, 
  0xe0, 0x0c, 0x07, 0x07, 0xff, 0x83, 0xf8, 0xff, 0xe0, 0xe0, 0x01, 0xc0, 0x18, 0x07, 0x07, 0x07, 
  0xc3, 0x81, 0xe1, 0xf0, 0xe0, 0x03, 0xc0, 0x18, 0x07, 0x07, 0x03, 0xc3, 0x81, 0xc0, 0xf0, 0xe0, 
  0x03, 0xc0, 0x30, 0x07, 0x07, 0x03, 0xc3, 0x83, 0xc0, 0x70, 0xe0, 0x07, 0x80, 0x30, 0x07, 0x07, 
  0x03, 0xc3, 0x83, 0xc0, 0xf8, 0xe0, 0x07, 0x80, 0x70, 0x07, 0x07, 0x03, 0xc3, 0x83, 0xff, 0xf8, 
  0xe0, 0x0f, 0x00, 0x60, 0x07, 0x07, 0x03, 0xc3, 0x83, 0xff, 0xf0, 0xe0, 0x1f, 0x00, 0x60, 0x0f, 
  0x07, 0x03, 0xc3, 0x83, 0xc0, 0x00, 0xe0, 0x7e, 0x00, 0xe0, 0x07, 0x07, 0x03, 0xc3, 0x81, 0xc0, 
  0x00, 0xe0, 0xfc, 0x00, 0xe0, 0x0f, 0x07, 0x03, 0xc3, 0xc1, 0xe0, 0x40, 0xe1, 0xf0, 0x00, 0xe0, 
  0x07, 0x07, 0x03, 0xc3, 0xf8, 0xff, 0xf0, 0xe1, 0xe0, 0x00, 0xe0, 0x07, 0x07, 0x03, 0xc1, 0xf8, 
  0x7f, 0xe0, 0x61, 0x80, 0x00, 0x70, 0x01, 0x07, 0x03, 0xc0, 0x70, 0x1f, 0x80, 0x00, 0x00, 0x00, 
  0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 
  0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00, 0x07, 0xe0, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x03, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 
  0xf0, 0x00, 0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x7f, 
  0xfc, 0x00, 0x00, 0x3f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x7f, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xf0, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
static const unsigned char PROGMEM intelkecik_bitmap[] = {
 0x7f, 0xff, 0xff, 0xc3, 0xff, 0xe0, 0x7f, 0xff, 0xf0, 0x38, 0x1f, 0xe0, 0x7f, 0xff, 0x1f, 0xff, 
 0xe7, 0xe0, 0x7f, 0xfc, 0xff, 0xff, 0xf9, 0xe0, 0x7f, 0xf7, 0xff, 0xff, 0xfc, 0xe0, 0x7f, 0xff, 
  0xff, 0xff, 0xfe, 0x60, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x60, 0x7e, 0x7f, 0xff, 0xff, 0x9f, 0x20, 
  0x7e, 0x7f, 0xf7, 0xff, 0x9f, 0xa0, 0x77, 0xff, 0xf7, 0xff, 0xbf, 0xa0, 0x7f, 0x70, 0xf1, 0xe7, 
  0x9f, 0xa0, 0x6e, 0x60, 0x31, 0x83, 0x9f, 0x20, 0x5e, 0x67, 0x37, 0xb9, 0xbf, 0x20, 0x5e, 0x67, 
  0x33, 0x39, 0xbf, 0x60, 0x5e, 0x67, 0x37, 0x01, 0x9e, 0x60, 0x1e, 0x67, 0x37, 0x3f, 0xbc, 0xe0, 
  0x3e, 0x67, 0x33, 0xbf, 0x99, 0xe0, 0x1f, 0x67, 0x31, 0x81, 0x93, 0xe0, 0x1f, 0xff, 0xff, 0xef, 
  0xff, 0xe0, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x4f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x4f, 0xff, 
  0xff, 0xff, 0xdf, 0xe0, 0x63, 0xff, 0xff, 0xfe, 0x1f, 0xe0, 0x71, 0xff, 0xff, 0xf0, 0x1f, 0xe0, 
  0x78, 0x3f, 0xff, 0x00, 0x7f, 0xe0, 0x7e, 0x00, 0x00, 0x03, 0xff, 0xe0, 0x7f, 0xc0, 0x00, 0x3f, 
  0xff, 0xe0, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xe0
};
static const unsigned char PROGMEM inteli9_bitmap[] = {
 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 
 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xc0, 0x3f, 0xf0, 0x00, 0x00, 0xfe, 
  0x00, 0x07, 0xf0, 0x00, 0x00, 0xf8, 0x3f, 0xc1, 0xf0, 0x00, 0x00, 0xe1, 0xff, 0xf8, 0xf0, 0x00, 
  0x00, 0xc7, 0xff, 0xfe, 0x30, 0x00, 0x00, 0x8f, 0xff, 0xff, 0x10, 0x00, 0x00, 0x9f, 0xc0, 0x3f, 
  0x90, 0x00, 0x00, 0xff, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0xfe, 0x3f, 0xc7, 0xf0, 0x00, 0x00, 0xfc, 
  0xff, 0xf3, 0xf0, 0x00, 0x00, 0xfd, 0xff, 0xfb, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 
  0x00, 0xff, 0xe0, 0x3f, 0xf0, 0x00, 0x00, 0xff, 0x86, 0x1f, 0xf0, 0x00, 0x00, 0xff, 0x9f, 0x9f, 
  0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xfd, 0xff, 0xf0, 0x00, 0x00, 0xff, 
  0xf0, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xf0, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xf9, 0xff, 0xf0, 0x00, 
  0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 
  0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x00
};
static const unsigned char PROGMEM palestin_bitmap[] = {
 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 
 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x00, 0x81, 0xe0, 0x10, 0x0f, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfe, 0x3e, 0x0f, 
  0xc7, 0xe3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfe, 0x7f, 0x9f, 0xef, 0xf3, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0xfe, 0x7f, 0x9f, 0xcf, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe0, 0x73, 
  0x9c, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe0, 0x73, 0x9c, 0x0f, 0x03, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x3c, 0xfe, 0x7f, 0x9f, 0xcf, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfe, 
  0x7f, 0x9f, 0xcf, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xfe, 0x7f, 0x1e, 0x0f, 0x03, 0xc0, 
  0x00, 0x00, 0x00, 0x00, 0x3c, 0xe0, 0x7f, 0x1c, 0x0f, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 
  0xe0, 0x77, 0x9f, 0xef, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe0, 0x73, 0x9f, 0xef, 0xf3, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe0, 0x73, 0x9f, 0xc7, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x3c, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 
  0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xe6, 0x47, 0x37, 0xa9, 0x73, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x3c, 0xf6, 0x46, 0x63, 0x2f, 0xc3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xf7, 0x47, 0x73, 
  0x2f, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xef, 0x46, 0x1b, 0x2f, 0xc3, 0xc0, 0x00, 0x00, 
  0x00, 0x00, 0x3c, 0x8f, 0x77, 0xfb, 0x2b, 0xf3, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 
  0x30, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 
  0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 
  0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 
  0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 
  0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
  0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 
  0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 
  0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 
  0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 
  0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00
};


#define RFM95_CS 10
#define RFM95_RST 7  
#define RFM95_INT 2

#define RF95_FREQ 915.0

Adafruit_PCD8544 lcd = Adafruit_PCD8544(24, 26, 28, 30, 32);
RH_RF95 rf95(RFM95_CS, RFM95_INT);

#define DHTPIN 47
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
  lcd.begin();
  lcd.setContrast(57);
  pinMode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, HIGH);

  while (!Serial);
  Serial.begin(9600);
  delay(100);

  Serial.println("LoRa TX Test!");
  lcd.clearDisplay();
  
  // Display YouTube symbol
  lcd.drawBitmap(0, 0, youtube_bitmap, YOUTUBE_WIDTH, YOUTUBE_HEIGHT, BLACK);
  lcd.display();
  delay(3000);
  lcd.clearDisplay();
  lcd.drawBitmap(0, 0, palestin_bitmap, palestin_WIDTH, palestin_HEIGHT, BLACK);
  lcd.display();
  delay(3000);
  lcd.clearDisplay();

  digitalWrite(RFM95_RST, LOW);
  delay(10);
  digitalWrite(RFM95_RST, HIGH);
  delay(10);

  while (!rf95.init()) {
    Serial.println("LoRa radio init failed");
    while (1);
  }
  Serial.println("LoRa radio init OK!");
  lcd.setCursor(0,10);
  lcd.print("  TEMPERATURE");
  lcd.setCursor(0,20);
  lcd.print("     AND");
  lcd.setCursor(0,30);
  lcd.print("   HUMIDITY");
  lcd.setCursor(0,40);
  lcd.print("   INDICATOR");
  lcd.display();
  lcd.clearDisplay();
  delay(2000);
  //lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("Initialization");
  delay(2000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("Initialization");
  lcd.setCursor(0,10);
  lcd.print("LoRa Connected");
  delay(2000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("Initialization");
  lcd.setCursor(0,10);
  lcd.print("LoRa Connected");
  lcd.setCursor(0,30);
  lcd.print("prepared by:");
  delay(2000);
  lcd.display();
  lcd.clearDisplay();
  lcd.setCursor(0,0);
  lcd.print("Initialization");
  lcd.setCursor(0,10);
  lcd.print("LoRa Connected");
  lcd.setCursor(0,30);
  lcd.print("prepared by:");
  lcd.setCursor(0,40);
  lcd.print("Hakimi Azizan");
  delay(1000);
  lcd.display();
  lcd.clearDisplay();
  delay(1000);
  
  if (!rf95.setFrequency(RF95_FREQ)) {
    Serial.println("setFrequency failed");
    while (1);
  }
  Serial.print("Set Freq to: "); Serial.println(RF95_FREQ);

  rf95.setTxPower(23, false);

  dht.begin();
}

int16_t packetnum = 0;

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: "); Serial.print(t); Serial.println(" *C");
  Serial.print("Humidity: "); Serial.print(h); Serial.println(" %");

  
  lcd.drawBitmap(0, 20, intelkecik_bitmap, intelkecik_lebar, intelkecik_tinggi, BLACK);
  lcd.drawBitmap(47, 20, inteli9_bitmap, inteli9_lebar, inteli9_tinggi, BLACK);
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" *C");
  lcd.display();
  lcd.setCursor(0,10);
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print(" %");
  lcd.display();
  lcd.clearDisplay();
  String data = "Temperature: " + String(t) + ", Humidity: " +String(h); 
  
  
  Serial.println("Sending to rf95_server: " + data); 
  rf95.send((uint8_t*)data.c_str(), data.length() + 1);
  

  Serial.println("Waiting for packet to complete...");
  rf95.waitPacketSent();

  delay(900);
}