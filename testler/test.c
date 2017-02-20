
#include <stdio.h>


int main(int argc,char **argv)
{

 _specscan();

}



int _specscan()
{
    
    _commandmv("autorun.inf");
    _commandmv("autorun.INF");
    _commandmv("AUTORUN.inf");
    _commandmv("AUTORUN.INF");
    
    _commanddel("autorun.inf");
    
    return 0;
    
}

int c = 0;

int _commandmv(char *filea)
{
    char cmd[100];
    char cmda[100] = "mv -f /tmp/usbforscan";
    char cmdb[100] = "  /tmp/usbforscan/_warning_viruses/";
    
    sprintf(cmda,"%s/%s",cmda,filea);
    
    sprintf(cmd,"%s%s",cmda,cmdb);            


//    system("");
    
	printf("%s\n",cmd);

//    system(cmd);
    
    return 0;
}

int _commanddel(char *filea)
{
    char cmd[100];
    char cmda[100] = "rm -f /tmp/usbforscan";

    
    sprintf(cmda,"%s/%s",cmda,filea);
    
    sprintf(cmd,"%s",cmda);            


//    system("");
    
	printf("%s\n",cmd);

//    system(cmd);
    
	return 0;
}

int commandattr(char *filea,int attr)
{
    char cmd[100];
    char cmda[100] = "mattrib -s -h -r c:/tmp/usbforscan";

    
    sprintf(cmda,"%s/%s",cmda,filea);
    
    sprintf(cmd,"%s",cmda);            


//    system("");
    
	printf("%s\n",cmd);

//    system(cmd);
    
	return 0;
}

