#include <LiquidCrystal.h>
#include <Stepper.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);         




int lcd_key     = 0;
int adc_key_in  = 0;
int calc_total;
int display_options;
int Relay1Pin = 13;
int MenuOption = 0;

#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

#define STEPPER_PIN_1 2
#define STEPPER_PIN_2 3
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12
#define FULL_ROTATION 4076



int step_number = 0;




int read_LCD_buttons(){              
    adc_key_in = analogRead(0);     

  

    if (adc_key_in > 1000) return btnNONE; 


    if (adc_key_in < 50)   return btnRIGHT;  
    if (adc_key_in < 150)  return btnUP; 
    if (adc_key_in < 300)  return btnDOWN; 
    if (adc_key_in < 450)  return btnLEFT; 
    if (adc_key_in < 700)  return btnSELECT;  

  

    return btnNONE;      
    
}

void setup(){
   lcd.begin(16, 2);              
   lcd.setCursor(0,0);    
   lcd.print ("Choose breakfast"); 
   lcd.setCursor(0,1) ;
lcd.print ("+   <-       ->"); 
   pinMode(13, OUTPUT); 
    Serial.begin(9600);
    Serial.print(MenuOption);
pinMode(STEPPER_PIN_1, OUTPUT);
pinMode(STEPPER_PIN_2, OUTPUT);
pinMode(STEPPER_PIN_3, OUTPUT);
pinMode(STEPPER_PIN_4, OUTPUT);


}
 
void loop(){

         
   lcd_key = read_LCD_buttons();  
   

   switch (lcd_key){              
    
       case btnRIGHT:{  
          lcd.clear();
            lcd.setCursor(0,1);
            calc_total = calc_total + 1;
            calc_total = constrain(calc_total,1, 5);
            lcd.print (calc_total);
            delay(700);
            break;
       }
       case btnLEFT:{
         lcd.clear();
            lcd.setCursor(0,1); 
            calc_total = calc_total - 1;
            calc_total = constrain(calc_total,1, 5);
            lcd.print(calc_total);
            delay(700); 
            break;
            
       }
       case btnSELECT:{
       MenuOption = 1;
       Serial.print(MenuOption);
        delay(700);
        break;
        }
     }
     
    if (calc_total == 1){
      lcd.setCursor(0,0); 
      lcd.print("Nesquik+Vanillia");   
   lcd.setCursor(0,1) ;
lcd.print ("+   <-   1   ->"); 
      if (MenuOption == 1){
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 1..");
      lcd.setCursor(0,1) ;
      lcd.print ("In process.."); 
      digitalWrite(13, LOW);
      for(int a = 0; a < 600; a++){
      OneStep(false);
      delay(2);
      }
      delay(2000);
      for(int a = 0; a < 600; a++){
      OneStep(true);
      delay(2);
      }
      for(int a = 0; a < 500; a++){
      OneStep(true);
      delay(2);
      }
      delay(2000);
      for(int a = 0; a < 500; a++){
      OneStep(false);
      delay(2);
      }
      delay(20000);
      digitalWrite(13, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 1");
      lcd.setCursor(0,1);  
      lcd.print("Done!");
      delay(2000);
      MenuOption = 0;
      }
    }
    else if (calc_total == 2){
      lcd.setCursor(0,0); 
      lcd.print("Nesquik+Musli");   
   lcd.setCursor(0,1) ;
lcd.print ("+   <-   2   ->"); 
      if (MenuOption == 1){
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 2..");
      lcd.setCursor(0,1) ;
      lcd.print ("In process.."); 
      digitalWrite(13, LOW);
      for(int a = 0; a < 500; a++){
      OneStep(false);
      delay(2);
      }
      delay(4000);
      for(int a = 0; a < 550; a++){
      OneStep(false);
      delay(2);
      }
       delay(5000);
      for(int a = 0; a < 1050; a++){
      OneStep(true);
      delay(2);
      }
      delay(5000);
      digitalWrite(13, HIGH);
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 2");
      lcd.setCursor(0,1);  
      lcd.print("Done!");
      delay(2000);
      MenuOption = 0;
      }
    }
    else if (calc_total == 3){
      lcd.setCursor(0,0); 
      lcd.print("Vanillia+Musli");   
   lcd.setCursor(0,1) ;
lcd.print ("+   <-   3   ->"); 
      if (MenuOption == 1){
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 3..");
      lcd.setCursor(0,1) ;
      lcd.print ("In process.."); 
      digitalWrite(13, LOW);
      for(int a = 0; a < 500; a++){
      OneStep(true);
      delay(2);
      }
      delay(4000);
      for(int a = 0; a < 525; a++){
      OneStep(true);
      delay(2);
      }
       delay(5000);
      for(int a = 0; a < 1025; a++){
      OneStep(false);
      delay(2);
      }
      delay(1000);
      digitalWrite(13, HIGH);
      MenuOption = 0;
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 3");
      lcd.setCursor(0,1);  
      lcd.print("Done!");
      delay(2000);
      }
    }
    else if (calc_total == 4){
      lcd.setCursor(0,0); 
      lcd.print("Everything");   
   lcd.setCursor(0,1) ;
lcd.print ("+   <-   4   ->"); 
      if (MenuOption == 1){
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 4..");
      lcd.setCursor(0,1) ;
      lcd.print ("In process.."); 
      digitalWrite(13, LOW);
      for(int a = 0; a < 500; a++){
      OneStep(true);
      delay(2);
      }
      delay(4000);
      for(int a = 0; a < 525; a++){
      OneStep(true);
      delay(2);
      }
       delay(5000);
      for(int a = 0; a < 525; a++){
      OneStep(true);
      delay(2);
      }
      delay(5000);
      for(int a = 0; a < 500; a++){
      OneStep(true);
      delay(2);
      }
      digitalWrite(13, HIGH);
      MenuOption = 0;
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 4");
      lcd.setCursor(0,1);  
      lcd.print("Done!");
      delay(2000);
      }
    }

    
    else if (calc_total == 5){
      lcd.setCursor(0,0); 
      lcd.print("More milk");   
   lcd.setCursor(0,1) ;
lcd.print ("+   <-   5   ->"); 
      if (MenuOption == 1){
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 5..");
      lcd.setCursor(0,1) ;
      lcd.print ("In process.."); 
      digitalWrite(13, LOW);
      delay(20000);
      digitalWrite(13, HIGH);
      MenuOption = 0;
      lcd.clear();
      lcd.setCursor(0,0);  
      lcd.print("Order 5");
      lcd.setCursor(0,1);  
      lcd.print("Done!");
      delay(2000);

    }
    }
    else{
      digitalWrite(13, HIGH);
    }
 
}

void OneStep(bool dir){
    if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
} 
  }else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
 
  
} 
  }
step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
