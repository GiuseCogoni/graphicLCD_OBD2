#include <U8glib.h>
#include <OBD2UART.h>
//#include <LedControl.h>

//LedControl lc=LedControl(7,6,5,1);
U8GLIB_ST7920_128X64 u8g(11, 12, 13, U8G_PIN_NONE);
COBD obd;
int inPin = 4;   // choose the input pin (for a pushbutton)
int val;                        // variable for reading the pin status
int buttonState;                // variable to hold the button state
int buttonPresses = 1;          // how many times the button has been pressed
int buttonPressesMax = 2;

void rotate() {u8g.setRot180();}

void setup() {  
  //  start communication with OBD-II adapter
  obd.begin();
  //  initiate OBD-II connection until success
//  while (!obd.init());
  // Initialize the module 
//  lc.shutdown(0,false);
//  /* Set the brightness to a medium values */
//  lc.setIntensity(0,15);
//  /* and clear the display */
//  lc.clearDisplay(0);
//  lc.setDigit(0,0,8, true);
//  lc.setDigit(0,1,8, true);
//  lc.setDigit(0,2,8, true);
//  lc.setDigit(0,3,8, true);
//  lc.setDigit(0,4,8, true);
//  lc.setDigit(0,5,8, true);
//  lc.setDigit(0,6,8, true);
//  lc.setDigit(0,7,8, true);
  u8g.setColorIndex(1); 
  pinMode(inPin, INPUT);    // declare pushbutton as input
  buttonState = digitalRead(inPin);   // read the initial state
}

void loop() {  
  rotate();
  u8g.firstPage();
  val = digitalRead(inPin);      // read input value and store it in val
  if (val != buttonState) {          // the button state has changed!
    if (val == LOW) {                // check if the button is pressed
      buttonPresses++;               // increment the buttonPresses variable
      if(buttonPresses>buttonPressesMax){
        buttonPresses = 1;
      }
    }
  }
  buttonState = val;                 // save the new state in our variable
  
  int spd = 110;
//  if(obd.readPID(PID_SPEED, spd)){
//    spd = round(spd*0.621371);
//  }  
  int enrv = 0;
//  if(obd.readPID(PID_RPM, enrv)){
//    enrv = round(enrv);
//  } 
  int intt = 0;
//  if(obd.readPID(PID_INTAKE_TEMP, intt)){
//    intt = round(intt);
//  } 
  int wat = 0;
//  if(obd.readPID(PID_COOLANT_TEMP, wat)){
//    wat = round(wat);
//  }  
  int batt = 0;
//  batt = round(obd.getVoltage()); 
  do {
//    u8g.drawFrame(0,0,63,30);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(2, 9, "Speed");
    u8g.setFont(u8g_font_fub14);
    u8g.setPrintPos(8, 28); 
    u8g.print(spd);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(44, 28, "MPH");
    
    
//    u8g.drawFrame(65,0,63,30);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(67, 9, "Eng. rev.");
    u8g.setFont(u8g_font_fub14);
    u8g.setPrintPos(67, 28); 
    u8g.print(enrv);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(114, 28, "RPM");
    
    
    u8g.drawFrame(0,32,41,25);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(2, 41, "Intake");
    u8g.setFont(u8g_font_fub11);
    u8g.setPrintPos(3, 55); 
    u8g.print(intt);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(34, 55, "C");

    u8g.setFont(u8g_font_micro);
    u8g.drawStr(1, 63, "PAGE");
    u8g.setPrintPos(21, 63); 
    u8g.print(buttonPresses);
    u8g.drawStr(25, 63, " OF 2");
    
      
    u8g.drawFrame(43,32,42,25);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(45, 41, "Water");
    u8g.setFont(u8g_font_fub11);
    u8g.setPrintPos(46, 55); 
    u8g.print(wat);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(78, 55, "C");
    
    
    u8g.drawFrame(87,32,41,25);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(89, 41, "Batt.");
    u8g.setFont(u8g_font_fub11);
    u8g.setPrintPos(95, 55); 
    u8g.print(batt);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(116, 55, "V");
  
  } while( u8g.nextPage() );
  delay(1000);   
}

