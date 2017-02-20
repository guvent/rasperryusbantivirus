/* 
 * File:   main.cpp
 * Author: pi
 *
 * Created on 16 Ekim 2015 Cuma, 15:20
 */

#include <cstdlib>
#include <stdio.h>
#include <wiringPi.h>
#include <lcd.h>
#include <unistd.h>

using namespace std;

static int lcdH;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int rn = 0;
    int _x = 0;
    int _y = 0;
    char* _t;

    _t = argv[1];
    
    wiringPiSetup();
    
    printf("");
    
       lcdH = lcdInit(2,16,4,  11,10, 0,1,2,3,0,0,0,0);
       
    switch(argc)
    {
        case 2:
            
        break;
        case 3:
            _x = atoi(argv[2]);
        break;
        case 4:
            _x = atoi(argv[2]);
            _y = atoi(argv[3]);
        break;
    }
    
    if(_t == "-c")
    {
        lcdClear(lcdH);
    }
    else
    {
        
    
       lcdClear(lcdH);
       lcdPosition(lcdH,_x,_y);
       lcdPrintf(lcdH,"Ok");
       printf("%d - %s\n",argc,_t);
       
    }
    
    return 0;
}

