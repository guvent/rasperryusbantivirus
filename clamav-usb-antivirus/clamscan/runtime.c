

char hostid[37];
int _position = 0;
int c;

int checkusb(char *usb);
char *checkfile(void);
char numchar(int);
int charnum(char);
int fposition(int pos);
int charmach(char *ch);
char *charget(char *ch);
char *charget2(char *ch);
void _summary(const struct optstruct *opts);
char *chadd(char* s1,char* s2);
int _chartoint(char* ch);
int _getint(char xa);
char *gtdir(char *gdir);


void checktemp()
{
    int r = 0;
    DIR *d;
    struct dirent *dr;
    
    d = opendir("/tmp");
    
    system("");
                
    while(dr = readdir(d))
    {
        if(dr->d_name == "usbforscan") 
        { r = 1; }
    }
    
    if(r!=1) { 
        printf("?: \"/tmp/usbforscan\" Not Found.! Creating..\n");
        system("sudo mkdir /tmp/usbforscan");
        system("sudo chmod 7777 /tmp/usbforscan");
        printf("?: Created.!\n"); }
    
    
}


int _initspec()
{
    DIR *d;
    struct dirent *dr;
    
    char *cmd;
    c = 0;  //int c;
    char *gf;
    
    d = opendir("/tmp/usbforscan/_warning_viruses");
    
    if(!d)
    {
        system("");
        system("sudo mkdir /tmp/usbforscan/_warning_viruses");
        
    }
    
    cmd = "sudo mkdir /tmp/usbforscan/_warning_viruses/";
    
    gf = gtdir("/tmp/usbforscan/_warning_viruses/");
    
    c = _chartoint(gf);
    
    c = c + 1;
   
    //sprintf(cmd , "%s%d", cmd, c);  Bu Çalışmıyor!!!!!!!!!!!!!!!!!!!!
    
    system("");
    system(cmd);
    
    lprintf(1,0,0,"Init Success");
    
    return 0;
}

int _specscan()
{
    
    _commandmv("autorun.inf");
    _commandmv("autorun.INF");
    _commandmv("AUTORUN.inf");
    _commandmv("AUTORUN.INF");
    
    
    return 0;
    
}

int _commandmv(char *filea)
{
    char *cmd;
    char *cmda = "mv -f /tmp/usbforscan";
    char *cmdb = "  /tmp/usbforscan/_warning_viruses/";
    
    sprintf(cmda,"%s/%s",cmda,filea);
    sprintf(cmdb,"%s%d/",cmdb,c);
    sprintf(cmd,"%s%s",cmda,cmdb);
            
    system("");
    
    system(cmd);
    
    return 0;
}

int _chartoint(char *ch)
{
    int a,b,l;
    char c,d;
    
    l = strlen(ch);
    
    a = 0;
    
    if(l<10)
    {
        c = ch[0];
        a = _getint(c);
    }
    if(l<100)
    {
        c = ch[0];
        d = ch[1];
        a = _getint(c);
        b = _getint(d);
        a = (a + (b * 10));
    }
    
        printf("");
        
    return a;
}

int _getint(char xa)
{
    int b;
    switch(xa)
        {
            case '0':
                b=0;
                break;
            case '1':
                b=1;
                break;
            case '2':
                b=2;
                break;
            case '3':
                b=3;
                break;
            case '4':
                b=4;
                break;
            case '5':
                b=5;
                break;
            case '6':
                b=6;
                break;
            case '7':
                b=7;
                break;
            case '8':
                b=8;
                break;
            case '9':
                b=9;
                break;
            
        }
    return b;
}

char *gtdir(char *gdir)
{
    DIR *d;
    struct dirent *dr;
    
    char *_dir;
    
    
    d = opendir(gdir);
    
    while(dr = readdir(d))
    {
        _dir = dr->d_name;
    }
    
    return _dir;
}


char *chadd(char* s1,char* s2)
{
    char f1[255];
    char f2[255];
    char *rs;
    int d1,d2,ds;
    
    d1 = strlen(s1);
    d2 = strlen(s2);
    ds = d1 + d2;
    
    int i,j,g=0;
    
    for(i=0;i<d1;i++)
    {
        f1[g] = s1[i];
        g++;
        
    }
    
    for(j=0;j<=d2;j++)
    {
        f1[g] = s2[j];
        g++;
        
    }
    
    
    rs = f1;
    
    printf("",rs);
    
    return rs;
    
}

void _summary(const struct optstruct *opts)
{
        
        printf("\n----------- TARAMA ÖZETİ -----------\n");
	printf("Bilinen Virus Türü: %u\n", info.sigs); 
	printf("Taranan Klasor: %u\n", info.dirs); 
	printf("Taranan Dosya: %u\n", info.files); 
	printf("Temizlenen Virusler: %u\n", info.ifiles);
        printf("Uygulama Versiyonu: %s\n", get_version()); 
        
        lprintf(1,0,0,"Bilinen Virus   Sayisi");
        ulprintf(0,8,1,info.sigs);
        sleep(1);
        
        lprintf(1,0,0,"Taranan Klasor");
        ulprintf(0,0,1,info.dirs);
        sleep(1);
        
        lprintf(1,0,0,"Taranan Dosya");
        ulprintf(0,0,1,info.files);
        sleep(1);
        
        lprintf(1,0,0,"Bulunan Virus");
        ulprintf(0,0,1,info.ifiles);
        sleep(1);
        
        
        lprintf(1,0,0,"Uygulama Versyon");
        slprintf(0,0,1,get_version());
        sleep(1);
        
        
        
        info.sigs = 0;
        info.dirs = 0;
        info.files = 0;
        info.ifiles = 0;
        
        if(info.errors)
            printf("Hatalar: %u\n", info.errors); info.errors = 0;

        if(notremoved) {
	    printf("Silinemeyenler: %u\n", notremoved);
	}
	if(notmoved) {
	    printf("Not %s: %u\n", optget(opts, "copy")->enabled ? "moved" : "copied", notmoved);
	}
}


int checkusb(char *usb)
{
    int susb = 0;
    int usbno = 0;
    char *cg;
    
    if(usb!="")
    {
        if(!fposition(2))
        {
            susb = 1;
        }
        else
        {
            printf("USB'yi Çıkartın..!\n");
            lprintf(1,0,0,"USB'yi Alin..!");
        }
        
    }
    else
    {
        lprintf(1,0,0,"USB Yerlestirin!");
        printf("USB Yerleştirin..!\n");
        fposition(0);
    }
    
    //printf("%c ! ",usb[2]);
    return susb;
}

int fposition(int pos)
{
    int rpos = 0;
    
        if(pos == 2) { rpos = _position; }
        else { _position = pos; }
    
      //  rpos = _position;
    
    return rpos;
}

int charmach(char *ch)
{
   // printf(" ch : %s ",ch);
    int nu = 0;
    int nu2 = 0;
    char c1,c2;
    
    if(strlen(ch)>0)
    {
        if(strlen(ch)>1)
        {
            c1 = ch[0]; c2 = ch[1];
            
            nu = charnum(c1);
            nu2 = charnum(c2);
            nu = ( (26 * nu) + nu2 );
        }
        else
        {
            c1 = ch[0];
            nu = charnum(c1);
        }
    }
    
    return nu;
}

char *charget(char *ch)
{
    char gh[7];
    char *bh;
    
    
        gh[0] = ch[2];
        gh[1] = '\0';
    
    
    
    bh = gh;
    
    printf("",bh);
    
    
    return bh;
}

char *charget2(char *ch)
{
    char gh[7];
    char *bh;
    
    
        gh[0] = ch[2];
        gh[1] = ch[3];
        gh[2] = '\0';
    
    bh = gh;
    
    printf("",bh);
    
    
    return bh;
}

char *checkfile()
{
    
    DIR *d;
    char *n,*r;
    struct dirent *dr;
  
    d = opendir("/dev");
    
    r = "";
    
    while(dr = readdir(d))
    {
        
        n = dr->d_name;
        
        if(strncmp("sd",n,2)==0)
        {
            if(strlen(n) > 3)
            {
                r = n;
            }
            if(strlen(n) > 4)
            {
                r = n;
            }
            
        }
        
    }
    
    printf("",r);
    
    closedir(d);
    return r;
    
}


int is_valid_hostid(void)
{
    int count, i;

    if (strlen(hostid) != 36)
        return 0;

    count=0;
    for (i=0; i < 36; i++)
        if (hostid[i] == '-')
            count++;

    if (count != 4)
        return 0;

    if (hostid[8] != '-' || hostid[13] != '-' || hostid[18] != '-' || hostid[23] != '-')
        return 0;

    return 1;
}

char *get_hostid(void *cbdata)
{
    UNUSEDPARAM(cbdata);

    if (!strcmp(hostid, "none"))
        return NULL;

    if (!is_valid_hostid())
        return strdup(STATS_ANON_UUID);

    logg("HostID is valid: %s\n", hostid);

    return strdup(hostid);
}


int charnum(char ch)
{
    int num = 0;
    
    switch (ch)
    {
        case 'a': num = 1; break;
        case 'b': num = 2; break;
        case 'c': num = 3; break;
        case 'd': num = 4; break;
        case 'e': num = 5; break;
        case 'f': num = 6; break;
        case 'g': num = 7; break;
        case 'h': num = 8; break;
        case 'i': num = 9; break;
        case 'j': num = 10; break;
        case 'k': num = 11; break;
        case 'l': num = 12; break;
        case 'm': num = 13; break;
        case 'n': num = 14; break;
        case 'o': num = 15; break;
        case 'p': num = 16; break;
        case 'q': num = 17; break;
        case 'r': num = 18; break;
        case 's': num = 19; break;
        case 't': num = 20; break;
        case 'u': num = 21; break;
        case 'v': num = 22; break;
        case 'w': num = 23; break;
        case 'x': num = 24; break;
        case 'y': num = 25; break;
        case 'z': num = 26; break;
        
    }
    
    return num;
}

char numchar(int num)
{
    char ch;
    
    switch(num)
    {
        case 1: ch = 'a'; break;
        case 2: ch = 'b'; break;
        case 3: ch = 'c'; break;
        case 4: ch = 'd'; break;
        case 5: ch = 'e'; break;
        case 6: ch = 'f'; break;
        case 7: ch = 'g'; break;
        case 8: ch = 'h'; break;
        case 9: ch = 'i'; break;
        case 10: ch = 'j'; break;
        case 11: ch = 'k'; break;
        case 12: ch = 'l'; break;
        case 13: ch = 'm'; break;
        case 14: ch = 'n'; break;
        case 15: ch = 'o'; break;
        case 16: ch = 'p'; break;
        case 17: ch = 'q'; break;
        case 18: ch = 'r'; break;
        case 19: ch = 's'; break;
        case 20: ch = 't'; break;
        case 21: ch = 'u'; break;
        case 22: ch = 'v'; break;
        case 23: ch = 'w'; break;
        case 24: ch = 'x'; break;
        case 25: ch = 'y'; break;
        case 26: ch = 'z'; break;
        
    }
    
    return ch;
}


void _trashed()
{
    /*
    if(strlen(usb)>3)
        {
            cg = charget(usb);
        }
        else if(strlen(usb)>4)
        {
            cg = charget2(usb);
        }
        
        usbno = charmach(cg);
        
            
            if(!fposition(usbno))
            {
                // eject usb
                printf("Eject USB.!");
            }
            else
            {
                // scan usb
                susb = 1;
            }*/
}

