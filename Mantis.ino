#include <Gamebuino-Meta.h>
#include "Mantis.h"
#include "Terrarium.h"
#include "assets/rgb565.h"

Mantis *mantis;
Terrarium *terrarium;

Image test(IMAGE_DATA);
Image mantis_idle(MANTIS_IDLE);

long ticks_passed= 0;
long days_passed = 0;

void setup() {
  gb.begin();
  
  mantis = new Mantis("Scyther",0,75,0,random(0,4));
  terrarium = new Terrarium(50,mantis);

}

void loop() {
  // put your main code here, to run repeatedly:
  while(!gb.update());
  //inputs
  //logic
    ticks_passed++;
    if(ticks_passed%9600==0){
      ticks_passed=0;
      days_passed++;
    }

    if(ticks_passed%400==0){
      terrarium->hour_pass();
    }
  
  //draw
  gb.display.clear();
  //statusScreen();
  animatedDemo();
}

void animatedDemo(){
    //text here ;3
    gb.display.print("Hello World!");
    gb.display.drawImage(10, 10, mantis_idle);
}

void statusScreen() {
  Image test(IMAGE_DATA);
  gb.display.drawImage(0, 0, test);
  gb.display.setColor(Color(YELLOW));
  gb.display.print("\n ");
  gb.display.print(terrarium->getMantis()->getName());
  gb.display.print("\n ");
  gb.display.print(terrarium->getMantis()->getBehaviourName());
  gb.display.print("\n Age :");
  gb.display.print(terrarium->getMantis()->getAge());
  gb.display.print(" day(s)\n Hunger :");
  gb.display.print(terrarium->getMantis()->getHunger());
  gb.display.print("%");
  gb.display.print("\n Stage :");
  gb.display.print(terrarium->getMantis()->getStageName());
  gb.display.print("\n Happiness :");
  gb.display.print(terrarium->getMantis()->getHappiness());
  gb.display.print(" %\n Weight :");
  gb.display.print(terrarium->getMantis()->getWeight());
  gb.display.print(" Mg\n Humidity  :");
  gb.display.print(terrarium->getHumidity_prct());
  gb.display.print("%");/*
  gb.display.print("\nTime of day:");
   if(ticks_passed<4800){
    gb.display.print("Day \n");
    }else{
    gb.display.print("Night \n");
   }
    gb.display.print(ticks_passed/400);
    gb.display.print(":");
    gb.display.print(int(ticks_passed % 400 /6.666 ));*/
    gb.display.print("\n Press A to leave...");

}
