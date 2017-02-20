/* 
 * File:   main.c
 * Author: pi
 *
 * Created on 15 Aralık 2018 Cumartesi, 22:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <inttypes.h>
#include <sys/ioctl.h>
#include <linux/msdos_fs.h>
#include <dirent.h>
#include <string.h>


char **gtdir(char *gdir);
int setattr(char *dd,__u32 att);
int getattr(char dd);
int pullfile(char* fd,long pos);
int pushfile(char* fd,long pos,int put);
char* readfile(char* dd);
int getsize(char* dd);
char** finddirectry();
char* getascii(char* ch);
char* charadd(char* _cd,char* _cs);
char* charadds(char _cd[],char _cs[],int _id,int _is);
int charlen(char ch[]);



/*
 * 
 */

int Fpcs = 0;

/* Folder Names as Ascii Code Here */

int list = { 0 , 0 };

/* Folder Names as Ascii Code Here */



int main(int argc, char** argv) {

    finddirectry();
    
    printf("Pieces : %i\n",Fpcs);
    
    
    return (EXIT_SUCCESS);
}


char** finddirectry()
{
    char **dr;
    dr = gtdir("/media/pi/0E12F0EF12F0DCA1");
    
	char *dir;

        int att1=0;
        int att2=0;
        
    long *dri[1024];
    
    int i;
    for(i=0;i<=Fpcs;i++)
    {
       // printf("%s \n",dr[i-1]);
        
	dir = "/media/pi/0E12F0EF12F0DCA1/";

	dir = charadd(dir,dr[i-1]);

	//dir = charadd(dir,"/");

        att1 = getattr(dir);
        
	setattr(dir,0);
	//setattr(dir,ATTR_HIDDEN);
	
	att2 = getattr(dir);

        printf("Dir: %s | %d - %d\n",dir,att1,att2);
        //dri[i-1] = getascii(dr[i-1]);
        
        //printf("%s\n",dri[i-1]);
    }

}


char* getascii(char ch[2048])
{
    char c[4096];
    char cc[4096];
    
    
    
    int i;
    for(i=0;i<1024;i++)
    {
        cc[i-1] = '\0';
    }
    
    
    for(i=0;i<strlen(ch);i++)
    {
        sprintf(cc,"%s%i",cc,ch[i-1]);

        
    }
    return cc;
}




char* charadd(char* _cd,char* _cs)
{
    char rt[1024];
    int sz,szd,ix,iy;
    
    
    
    sz = strlen(_cs);
    szd = strlen(_cd);
    
    //printf("%d - %d",sz,szd);
    
    int i;
    for(i=0;i<=szd;i++)
    {
        rt[i-1] = _cd[i-1];
    }
    
    for(i=0;i<=sz;i++)
    {
        ix = (i) + (szd);
        rt[ix] = _cs[i];
    }
    rt[((sz)+szd)] = '\0';
    
    
    return rt;
}

char* charadds(char _cd[],char _cs[],int _id,int _is)
{
    char rt[1024];
    int sz,szd,ix,iy;
    
    
    
    sz = _is;
    szd = _id;
    
    //printf("%d - %d",sz,szd);
    
    int i;
    for(i=0;i<=szd;i++)
    {
        rt[i-1] = _cd[i-1];
    }
    
    for(i=0;i<=sz;i++)
    {
        ix = (i) + (szd);
        rt[ix] = _cs[i];
    }
    rt[((sz)+szd)] = '\0';
    
    
    return rt;
}


int charlen(char ch[])
{
    int rt=0;
    int i=0;
    
    while(1)
    {
        if(ch[i]='\0')
        {   break;   }
        i++;
    }
    rt = i;
}

/*
 * setattr(File or Directory Path,If Set Attributes)
 * 
 * Attributes:
 * ATTR_{RO,HIDDEN,SYS,VOLUME,DIR,ARCH,NONE}
 * 
 * Example:
 * attr("/tmp/dir",ATTR_HIDDEN);
 * 
 */
int setattr(char *dd,__u32 att)
{
    
    int fd = open(dd, 0);
    __u32 attrs;

    int err;
    
    attrs = att;
    
    err = ioctl(fd, FAT_IOCTL_SET_ATTRIBUTES, &attrs);
    if(err==-1)
    { 
        
        printf("ERROR!!!\n");
    }
    
    return 0;

}


/*
 * getattr(File or Directory Path)
 * 
 * Return of type int
 */
int getattr(char dd)
{
    int fd = open(dd, 0);
    __u32 attrs = 0;

    int err;
    
    //attrs = ATTR_NONE;  /* ATTR_{RO,HIDDEN,SYS,VOLUME,DIR,ARCH} */
    err = ioctl(fd, FAT_IOCTL_GET_ATTRIBUTES, &attrs);
    if(err==-1){ printf("Error!!\n"); }
    return attrs;
    
}

/*
 * Get Directory List to Array
 * 
 * Example:
 *   char **dr;
 *   dr = gtdir("/media/pi/0E12F0EF12F0DCA1");
 *   
 *   int i;
 * 
 *   for(i=0;i<=Fpcs;i++)
 *   {
 *      printf("%s\n",dr[i-1]);
 *   }
 * 
 *   printf("Pieces : %i\n",Fpcs);
 * 
 */
char** gtdir(char *gdir)
{
    DIR *d;
    struct dirent *dr;
    
    char* _dir[1024];
    char* buff;
    
    int i=0;
    
    d = opendir(gdir);
    
    while(dr = readdir(d))
    {
        
        buff = dr->d_name;
        
        _dir[i] = dr->d_name;
        
        
        //printf(buff);
        
        i++;
    }
    
    Fpcs = i;
    
    return _dir;
}

int pullfile(char* fd,long pos)
{
    int fgt;
    
    FILE* f;
    f=fopen(fd,"r");
    
    fseek(f,pos,SEEK_SET);
    
    fgt = fgetc(f);
    
    fclose(f);
    return fgt;
}

int pushfile(char* fd,long pos,int put)
{
    int fgt;
    
    FILE* f;
    f=fopen(fd,"r");
    
    fseek(f,pos,SEEK_SET);
    
    fputc(put,f);
    fgt = fgetc(f);
    
    fclose(f);
    return fgt;
}


/*
 * Reading File to char array
 * 
 * Example:
 *   char* rd;
 *   char* fl;
 *   int sz
 * 
 *   fl = "/media/pi/0E12F0EF12F0DCA1/r.lnk";
 * 
 *   sz = getsize(fl);
 *   rd =readfile(fl);
 * 
 *   int i;
 *   for(i=0;i<sz;i++) 
 *   {
 *     printf("%c",rd[i]); 
 *   }
 * 
 */
char* readfile(char* dd)
{
    int sz;
    
    sz = getsize(dd);
    printf("Lenght :%d\n",sz);
    
    char *rd = malloc(sz);
    int *buff = malloc(sz);
    
    
    FILE* f;
    f= fopen(dd,"rb");
    
    read(f->_fileno,rd,sz);
    
    int i;
    
    for(i=0;i<sz;i++) {
    //rd[i] = buff[i];
    
       // printf("%c",rd[i]);
    
    }
    fclose(f);
    return rd;
    
}

int getsize(char* dd)
{
    FILE* f;
    f=fopen(dd,"rb");
    int sz;
    fseek(f,0,SEEK_END);
    sz=ftell(f);
    rewind(f);
    fclose(f);
    return sz;
}



