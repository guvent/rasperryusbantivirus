

#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>



int main(int argc, char**argv) {

     int d;
    
       d = lcdInit(2, 16, 4,  7,8 , 25,24,23,18,0,0,0,0);
       /*
       lcdHome(d);
       lcdClear(d);
       
       lcdPrintf(d,"Okey!");
 */
    return 0;
}


/*
     
    
 */