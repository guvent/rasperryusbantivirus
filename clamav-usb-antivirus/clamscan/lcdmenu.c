#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <wiringPi.h>
#include <lcd.h>

/*
 * Key : <target>
 *  1  : Green >>
 *  2  : Red >>
 *  3  : Left
 *  4  : Down
 *  5  : Right
 *  6  : Up
 *  7  : Red <<
 *  8  : Green <<
 * 
 */

static int lcdH2;

int mpos = 0;

int linit()
{
#ifdef HAVE_LCD_KEYPAD
    
    wiringPiSetup();
    
    pinMode(21,INPUT);
    pinMode(22,INPUT);
    pinMode(23,INPUT);
    pinMode(24,INPUT);
    pinMode(25,INPUT);
    pinMode(27,INPUT); 
    pinMode(28,INPUT);
    pinMode(29,INPUT);
    
    
    
       lcdH2 = lcdInit(2,16,4,  11,10, 0,1,2,3,0,0,0,0);
    
#endif
       
       
    return 0;
}


int menucreate()
{
#ifdef HAVE_LCD_KEYPAD

    int _x = 0;
    int _y = 0;
    char* _t;
    
    _t = "Okey!!!";
    
    linit();
    
    printf("");
    
       lcdClear(lcdH2);
       lcdPosition(lcdH2,_x,_y);
       
       lcdPrintf(lcdH2,"LCD Init :      Success!");
       
       printf("LCD Init : Success!\n");

#endif
       
    return 0;
}

int menusection()
{

    int rd = 0;

#ifdef HAVE_LCD_KEYPAD
    
    int tk = 0;
    int bk = 0;
    int rn = 1;
    
    while(rn<1000000)
    {
    
        tk = readkey();
        rn++;
        
        if(tk == 1 || tk == 8) { startmenu(); }
        
    }
    
#endif
    
    return rd;
}

int _rn = 1;

int startmenu()
{
#ifdef HAVE_LCD_KEYPAD
    
    int tk = 0;
    
    _rn = 1; 
    
    //lprintf(1,0,0,"Menu");
    
    selectmenu(3);

    sleep(1);

    while(_rn)
    {
        tk = readkey();
        
        switch(tk)
        {
            case 3:
                selectmenu(3);
                break;
            case 5:
                selectmenu(4);
                break;
            case 1:
                entermenu(1);
                break;
            case 2:
                entermenu(2);
                break;
            case 4:
                vprogress(6);
                break;
        }
        //sleep(1);
        
        keywait(tk);
    }
    
#endif
    
    
    return 0;
}

int selectmenu(int subm)
{

#ifdef HAVE_LCD_KEYPAD
    
        switch(subm)
        {
            case 3:
                if(mpos<10) { if(mpos<4) mpos++; }
                if(mpos>10 && mpos<20) { if(mpos<12) mpos++; }
                if(mpos>20 && mpos<30) { if(mpos<22) mpos++; }
                if(mpos>30 && mpos<40) { if(mpos<32) mpos++; }
                if(mpos>40 && mpos<50) { if(mpos<43) mpos++; }

                break;
            case 4:
                if(mpos<10) { if(mpos>1) mpos--; } //else exitmenu(); }
                if(mpos>10 && mpos<20) { if(mpos>11) mpos--; }
                if(mpos>20 && mpos<30) { if(mpos>21) mpos--; }
                if(mpos>30 && mpos<40) { if(mpos>31) mpos--; }
                if(mpos>40 && mpos<50) { if(mpos>41) mpos--; }

                break;
        }
        selectText(mpos);
    
#endif
        
    return 0;
}

int entermenu(int subm)
{
    int rd = 0;
    
#ifdef HAVE_LCD_KEYPAD    
    
    int rn = 1;
        switch(subm)
        {
            case 1:  // Green Key Pressed!
                if(mpos<9) { mpos = (mpos * 10) + 1; }
                if(mpos>10) { execmenu(); }
                break;
            case 2:  // Red Key Pressed!
                if(mpos>10){ mpos = mpos / 10; }
                else exitmenu();
                break;
        }
        
        selectText(mpos);
        
    return rd;

#endif
    
}

int execmenu()
{
#ifdef HAVE_LCD_KEYPAD
    
    system("");
    
    switch(mpos)
    {
        case 11: // Saat Tarih Ayarla
            
            break;
        case 12: // Uyarı Tonları
            
            break;
            
            
        case 21: // Hızlı Biçimlendir
            
            break;
        case 22: // Tam Biçimlendir
            
            break;
            
            
        case 31: // Güncl. Kontrol Et
            system("sudo freshclam");
            break;
        case 32: // Güncelle ve Yükle
            system("sudo freshclam");
            break;
            
            
        case 41: // Uyku Moduna Geç
            
            break;
        case 42: // Yeniden Başlat
	    lprintf(1,0,0,"Yeniden BasliyorLutfen Bekleyin!");
            system("sudo reboot");
            break;
        case 43: // Tamamen Kapat
            lprintf(1,0,0,"Cihaz Kapaniyor Lutfen Bekleyin!");
            system("sudo halt");
            
            break;
        
    }
   
#endif 
    
    return 0;
}

int exitmenu()
{
    _rn = 0;
    mpos = 0;
    return 0;
}

int selectText(int m)
{
#ifdef HAVE_LCD_KEYPAD
    
    char *_tx;
    char *_ty;
    
    switch(m)
    {
        case 1:
            _tx = "Sistem Ayarlari";
            _ty = "<              >";
            break;
        case 2:
            _tx = "USB Bicimlendir ";
            _ty = "<              >";
            break;
        case 3:
            _tx = "VTabani Guncelle";
            _ty = "<              >";
            break;
        case 4:
            _tx = " Kapatma Menusu ";
            _ty = "<              >";
            break;
        
        case 11:
            _tx = "Saat Tarih Ayrla";
            _ty = "<              >";
            break;
        case 12:
            _tx = " Uyari Tonlari  ";
            _ty = "<              >";
            break;
        
        case 21:
            _tx = "Hizli Bicimlendr";
            _ty = "<              >";
            break;
        case 22:
            _tx = "Tam Bicimlendir ";
            _ty = "<              >";
            break;
        
        case 31:
            _tx = "Gunc. Kontrol Et";
            _ty = "<              >";
            break;
        case 32:
            _tx = "Guncelle & Yukle";
            _ty = "<              >";
            break;
        
        case 41:
            _tx = "Uyku Moduna Gec ";
            _ty = "<              >";
            break;
        case 42:
            _tx = " Yeniden Baslat ";
            _ty = "<              >";
            break;
        case 43:
            _tx = " Tamamen Kapat  ";
            _ty = "<              >";
            break;
        
            
        case 1001:
            _tx = "Tam Tarama Devam";
            _ty = "-Yesil'e Basin -";
            break;
        
        
    }
    
    lcdClear(lcdH2);
    lcdPrintf(lcdH2,_tx);
    lcdPosition(lcdH2,0,1);
    lcdPrintf(lcdH2,_ty);

#endif
}


int tprintf(char *_tx,char *_ty)
{
#ifdef HAVE_LCD_KEYPAD
    
    lcdClear(lcdH2);
    lcdPrintf(lcdH2,_tx);
    lcdPosition(lcdH2,0,1);
    lcdPrintf(lcdH2,_ty);
    
#endif
    
}

int lprintf(int cls,int posx,int posy,char *_t)
{
#ifdef HAVE_LCD_KEYPAD
    
    if(cls) lcdClear(lcdH2);
    
    lcdPosition(lcdH2,posx,posy);
    lcdPrintf(lcdH2,_t);

#endif
    
}

int ulprintf(int cls,int posx,int posy,unsigned int _t)
{
#ifdef HAVE_LCD_KEYPAD
    
    if(cls) lcdClear(lcdH2);
    
    lcdPosition(lcdH2,posx,posy);
    lcdPrintf(lcdH2,"%u",_t);

#endif
    
}

int slprintf(int cls,int posx,int posy,const char *_t)
{
#ifdef HAVE_LCD_KEYPAD
    
    if(cls) lcdClear(lcdH2);
    
    lcdPosition(lcdH2,posx,posy);
    lcdPrintf(lcdH2,"%s",_t);

#endif
    
}

int readkey()
{

        int rd = 0;

#ifdef HAVE_LCD_KEYPAD

    int rn = 1;
    
            if(digitalRead(21)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : OK >>\n");
		rd = 1;
                //lcdPrintf(lcdH2,"Pressed :        OK >>"); 
            }
                
            if(digitalRead(22)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : CANCEL >> \n");
                rd = 2;
                //lcdPrintf(lcdH2,"Pressed :        CANCEL >>"); 
            }
                
            if(digitalRead(23)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : Right\n");
                rd = 3;
                //lcdPrintf(lcdH2,"Pressed : Right");
            }
                
            if(digitalRead(24)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : Down\n");
                rd = 4;
                //lcdPrintf(lcdH2,"Pressed : Down"); 
            }
                
            if(digitalRead(25)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : Left\n");
                rd = 5;
                //lcdPrintf(lcdH2,"Pressed : Left"); 
            }
                
            if(digitalRead(27)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : Up\n");
                rd = 6;
                //lcdPrintf(lcdH2,"Pressed : Up"); 
            }
                
            if(digitalRead(28)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : << CANCEL\n");
                rd = 7;
                //lcdPrintf(lcdH2,"Pressed :        << CANCEL"); 
            }
                
            if(digitalRead(29)) {
		//lcdClear(lcdH2);
		//lcdPosition(lcdH2,0,0);
                //printf("Pressed : << OK\n");
                rd = 8;
                //lcdPrintf(lcdH2,"Pressed :        << OK"); 
            }
                
#endif            
    return rd;
}

int scankey(int _wait)
{
    int rd = 0;

#ifdef HAVE_LCD_KEYPAD
    
    int rn = 1;
    
    while(rn)
    {
        rd = readkey();
        if(rd==1 || rd==8) { rd=0; break; }
        if(rd) { break; }
        sleep(_wait);
    }

#endif
    
    
    return rd;
}

int keywait(int tk)
{
#ifdef HAVE_LCD_KEYPAD
    
    while(tk)
    {
        tk = 0;
        tk = readkey();
    }

#endif
    
    return 0;
}

int lpos = 0;
int lcur = 0;
int lavg = 0;

int lprogress()
{
#ifdef HAVE_LCD_KEYPAD
    
    lcdPosition(lcdH2,0,1);
    lcdPrintf(lcdH2,"[");
    
    lcdPosition(lcdH2,15,1);
    lcdPrintf(lcdH2,"]");
    
    if(lavg<=0) {
        lavg--;
    if(lpos<14) { lpos++; } else { 
        if(lcur==0) { lcur=1; } else { lcur=0; }
            lpos = 1; }
    
    lcdPosition(lcdH2,lpos,1);
    if(lcur==0) {
        lcdPrintf(lcdH2,"#"); } 
    else
        {
        lcdPrintf(lcdH2,"-"); }
    }
    else
    {
        lavg = 1000;
    }
    
#endif
    
    return 0;
}

int ltprogress(char *txt)
{
#ifdef HAVE_LCD_KEYPAD
    
    lcdPosition(lcdH2,0,0);
    lcdPrintf(lcdH2,txt);
    
    lcdPosition(lcdH2,0,1);
    lcdPrintf(lcdH2,"[");
    
    lcdPosition(lcdH2,15,1);
    lcdPrintf(lcdH2,"]");
    
    if(lavg<=0) {
        lavg--;
    if(lpos<14) { lpos++; } else { 
        if(lcur==0) { lcur=1; } else { lcur=0; }
            lpos = 1; }
    
    lcdPosition(lcdH2,lpos,1);
    if(lcur==0) {
        lcdPrintf(lcdH2,"#"); } 
    else
        {
        lcdPrintf(lcdH2,"-"); }
    }
    else
    {
        lavg = 1000;
    }
    
#endif
    
    return 0;
}

int vprogress(int lval)
{
#ifdef HAVE_LCD_KEYPAD
    
    lcdPosition(lcdH2,0,1);
    lcdPrintf(lcdH2,"[--------------]");
    
    int xi = 0;
    
    for(xi=1;xi<=lval;xi++)
    {
        lcdPosition(lcdH2,xi,1);
        lcdPrintf(lcdH2,"#");
    }

#endif
    
    return 0;
}

int lprintw(char* tx)
{
    int ln = 0;
    
    ln = strlen(tx);
    
    
    
    return 0;
}

