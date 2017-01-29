#include <U8glib.h>
//#include <OBD2UART.h>

U8GLIB_ST7920_128X64 u8g(13, 12, 11, U8G_PIN_NONE);
//COBD obd;

void setup() {  
  //  start communication with OBD-II adapter
//  obd.begin();
//  //  initiate OBD-II connection until success
//  while (!obd.init());
  u8g.setColorIndex(1); 
}

void loop() {  
  u8g.firstPage();
//  int spd = 0;
//  if(obd.readPID(PID_SPEED, spd)){
//    spd = round(spd*0.621371);
//  }  
//  int enrv = 0;
//  if(obd.readPID(PID_RPM, enrv)){
//    enrv = round(enrv);
//  } 
//  int intt = 0;
//  if(obd.readPID(PID_INTAKE_TEMP, intt)){
//    intt = round(intt);
//  } 
//  int wat = 0;
//  if(obd.readPID(PID_COOLANT_TEMP, wat)){
//    wat = round(wat);
//  }  
//  int batt = 0;
//  batt = round(obd.getVoltage()); 
  do {
    u8g.drawFrame(0,0,63,31);
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr(2, 9, "Speed");
    u8g.setFont(u8g_font_fub14);
    u8g.setPrintPos(8, 29); 
//    u8g.print(spd);
    u8g.print(100);
    u8g.setFont(u8g_font_micro);
    u8g.drawStr(44, 29, "MPH");
    
//    
//    u8g.drawFrame(65,0,63,31);
//    u8g.setFont(u8g_font_6x10);
//    u8g.drawStr(67, 9, "Eng. rev.");
//    u8g.setFont(u8g_font_fub14);
//    u8g.setPrintPos(67, 29); 
//    u8g.print(enrv);
//    u8g.setFont(u8g_font_micro);
//    u8g.drawStr(114, 29, "RPM");
//    
//    
//    u8g.drawFrame(0,33,41,31);
//    u8g.setFont(u8g_font_6x10);
//    u8g.drawStr(2, 42, "Intake");
//    u8g.setFont(u8g_font_fub11);
//    u8g.setPrintPos(3, 62); 
//    u8g.print(intt);
//    u8g.setFont(u8g_font_micro);
//    u8g.drawStr(34, 62, "C");
//    
//      
//    u8g.drawFrame(43,33,42,31);
//    u8g.setFont(u8g_font_6x10);
//    u8g.drawStr(45, 42, "Water");
//    u8g.setFont(u8g_font_fub11);
//    u8g.setPrintPos(46, 62); 
//    u8g.print(wat);
//    u8g.setFont(u8g_font_micro);
//    u8g.drawStr(78, 62, "C");
//    
//    
//    u8g.drawFrame(87,33,41,31);
//    u8g.setFont(u8g_font_6x10);
//    u8g.drawStr(89, 42, "Batt.");
//    u8g.setFont(u8g_font_fub11);
//    u8g.setPrintPos(95, 62); 
//    u8g.print(batt);
//    u8g.setFont(u8g_font_micro);
//    u8g.drawStr(116, 62, "V");
  
  } while( u8g.nextPage() );
  delay(1000);   
}

