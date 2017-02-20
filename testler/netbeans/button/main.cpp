/* 
 * File:   main.cpp
 * Author: pi
 *
 * Created on 08 Kasım 2015 Pazar, 23:54
 */

#include <cstdlib>
#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <lcd.h>


using namespace std;

static int lcdH;

/*
 * 
 */
int main(int argc, char** argv) {

    int rn = 1;
    int rd = 0;
    
    wiringPiSetup();
    
	lcdH = lcdInit (2, 16, 4,  11,10 , 0,1,2,3,0,0,0,0) ;

    pinMode(21,INPUT);
    pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);
    pinMode(25,INPUT);
    
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : OK >>\n");
		lcdPrintf(lcdH,"Bir Tusa Basin.!");
    
    while(rn)
    {
        

            if(digitalRead(21)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : OK >>\n");
		lcdPrintf(lcdH,"Pressed :        OK >>"); }
                
            if(digitalRead(22)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : CANCEL >> \n");
                lcdPrintf(lcdH,"Pressed :        CANCEL >>"); }
                
            if(digitalRead(23)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : Right\n");
                lcdPrintf(lcdH,"Pressed : Right"); }
                
            if(digitalRead(24)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : Down\n");
                lcdPrintf(lcdH,"Pressed : Down"); }
                
            if(digitalRead(25)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : Left\n");
                lcdPrintf(lcdH,"Pressed : Left"); }
                
            if(digitalRead(27)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : Up\n");
                lcdPrintf(lcdH,"Pressed : Up"); }
                
            if(digitalRead(28)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : << CANCEL\n");
                lcdPrintf(lcdH,"Pressed :        << CANCEL"); }
                
            if(digitalRead(29)) {
		lcdClear(lcdH);
		lcdPosition(lcdH,0,0);
                printf("Pressed : << OK\n");
                lcdPrintf(lcdH,"Pressed :        << OK"); }
                
            
        
        
        
        
    }
    
    
    return 0;
}

