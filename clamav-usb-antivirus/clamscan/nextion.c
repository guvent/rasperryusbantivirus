#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <itead_serial.h>
#include <unistd.h>

int fd;


int nextion_init() 
{

int count ;


    if ((fd = serialOpen ("/dev/ttyAMA0", 9600)) < 0)
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno));
        return 1;
    }



return 0;
}



char* nextion_read()
{
    char *val;
    int i=0;
    
    while(1) {

        while (serialDataAvail(fd))
        {
            val[i] = serialGetchar(fd);
            i++;
        }
        
        
    }   

    return val;
    
}

int nextion_sent(char* cmd)
{
    
        serialPrintf(fd,cmd);
        serialPutchar(fd,0xff);
        serialPutchar(fd,0xff);
        serialPutchar(fd,0xff);
        
        while (serialDataAvail(fd))
        {
            return serialGetchar(fd); 
        }
        
        return 0;
        
}


int nextion_live()
{
    
    
    
    
}



int nexdraw_messagebox(char* mtitle,char* mdescr,int mmode)
{
    
    
    
}

int nexdraw_listitems()
{
    
    
}

int nexdraw_keyboard()
{
    
    
    
}

int nexdraw_waiting()
{


}

int nexdraw_summary()
{
    
    
}
