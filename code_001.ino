
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init(); 
  Serial.begin(9600);  // buart rate
  //lcd.begin(); 
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Bluetooth Based");
  lcd.setCursor(1,1);
  lcd.print("Home Automation");
  //Serial.println("System Ready...");
  pinMode(7,OUTPUT); // RELAY MODULE -1
    pinMode(6,OUTPUT); //RELAY MODULE -2
      pinMode(5,OUTPUT); //RELAY MODULE -3
  
}

void loop()
{
  if(Serial.available()>0)
   {     
   char data= Serial.read();
   Serial.println(data);
   lcd.setCursor(1,0);
   lcd.print("Home Automation");
         
     if(data=='a')
     {
   
        digitalWrite(7,HIGH); // RELAY-1 ON
        Serial.println("Bulb - OFF     ");
        lcd.setCursor(1,1);
        lcd.print("  Bulb - OFF  ");
  }   
   if(data=='b')
     {
       digitalWrite(7,LOW);  // RELAY-1 OFF
       Serial.println("Bulb - ON");
       lcd.setCursor(1,1);
       lcd.print("  Bulb - ON  ");
  } 

    if(data=='c')
     {
    digitalWrite(6,HIGH); // RELAY - 2 ON
    Serial.println("Switch - OFF");
    lcd.setCursor(1,1);
    lcd.print(" Switch - OFF  ");
  }   
   if(data=='d')
     {
    digitalWrite(6,LOW); // RELAY -2 OFF
    Serial.println("Switch - ON");
    lcd.setCursor(1,1);
    lcd.print("  Switch - ON  ");
  }
    if(data=='e')
     {
    digitalWrite(5,HIGH); // RELAY -3 ON
    Serial.println("Fan - OFF");
    lcd.setCursor(1,1);
    lcd.print("  Fan - OFF  ");
  }
  if(data=='f')
     {
    digitalWrite(5,LOW); // RELAY -3 OFF
    Serial.println("Fan - ON");
    lcd.setCursor(1,1);
    lcd.print("  Fan - ON  ");
     }
  }
}
