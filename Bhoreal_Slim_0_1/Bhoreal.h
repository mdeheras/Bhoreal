#include <Arduino.h>
#include <Wire.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/power.h>

#define  SERIAL_ENABLE     false    // Enable Serial comunication
#define  MIDI_DEBUG        false    // Enable MIDI debuging
//#define  SERIAL_DATA       false
#define  DEMO_ACCEL        true     // Enable accelerometer
#define  BAT_MONITOR       false    // Battery monitor enabled
#define  wifiConfig        true

#define buffer_length        32     // Buffer for eeprom data

//#define  MODEL  MINISLIM //Modelo
#define  MODEL  SLIMPRO //Modelo
//#define  MODEL  SLIM //Modelo

class Bhoreal {
  public:  
  
    // Constructor: number of LEDs, pin number, LED type
    void show(void);
    void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
    
    void begin();
    void config();
    boolean compareData(char* text, char* text1);
    void writeData(uint32_t eeaddress, char* text);
    char* readData(uint16_t eeaddress);
    void checkButtons();
    void refresh();
    void midiRefresh();
    void startup();
    float readBattery();
    void checkADC();
    void checkBattery();
    uint32_t hue2rgb(uint16_t hueValue);
    boolean awake();
    void slaveSend(byte val);
    byte slaveRead(byte reg);
    void sleep();
    void sleepNow();
    void printChar(byte value, byte pos);
    void printChar(char* text);
    
    //WIFI
    boolean apMode();
    boolean Connect();
    boolean reConnect();
    void protocolDefine(byte protocol);
    void WIFIsleep();
    void WIFISend(byte value, boolean state);
    boolean reset();
    int checkWiFly();
    char* getMAC();
    char* getIP();
    int getWiFlyVersion();
    boolean update();
    void BaudSetup();
    boolean open(const char *addr, int port);
    boolean close();
    void WIFIRead();
    void checkServer();
    
    void timer1Initialize();
    void timer1SetPeriod(long microseconds);
    void timer1Stop();
    void serialRequests();
    
    void AttachInterrupt6(int mode);
    void selectMode();
  private:
  
    //Variables
    char buffer[buffer_length];
    uint32_t endTime;                     // Latch timing reference
    const volatile uint8_t *port;         // Output PORT register
    uint8_t pinMask;                // Output PORT bitmask    
    
    void checkMatrix(byte sel);
    void demoAccel();
    void white();
    void programMode();
    void on_press(byte r, byte c, byte sel);
    void on_release(byte r, byte c, byte sel);

    
    void detachInterrupt6();
    //Accelerometer
    void writeTo(int device, byte address, byte val);
    void readFrom(int device, byte address, int num, byte buff[]);
    
    //utils
    char* itoa(int32_t number);
};
