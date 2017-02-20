

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include <itead_serial.h>
#include <unistd.h>


int main () 
{
int fd ;
int count ;
unsigned int nextTime ;
unsigned char *cmd;

    if ((fd = serialOpen ("/dev/ttyAMA0", 9600)) < 0)
    {
        fprintf (stderr, "Unable to open serial device: %s\n", strerror (errno));
        return 1 ;
    }


 
    while(1) {
        
            while (serialDataAvail (fd))
            {
                printf (" -> %3d", serialGetchar(fd));
                
                printf ("\n") ;
            }


            serialPrintf(fd,"page 0");
            serialPutchar(fd,0xff);
            serialPutchar(fd,0xff);
            serialPutchar(fd,0xff);
            

}   

    printf ("\n") ;
 
return 0 ;
}
