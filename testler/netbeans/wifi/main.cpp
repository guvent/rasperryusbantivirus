/* 
 * File:   main.cpp
 * Author: pi
 *
 * Created on 15 Aralık 2018 Cumartesi, 18:29
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <bits/c++config.h>
#include "unistd.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *f,*fw;
    char * fr = NULL;
    size_t fs = 0;
    ssize_t frs;
    int sz = 0;
    
    char *ssid;
    char *key;
    char *keym;
    char *oth;
    
    system("");
    
    system("rm -f /tmp/clamscan.wifi");
    system("iwlist wlan0 scan | grep ESSID |sed 's@                    ESSID:\"@ @' | sed 's@\"@ @' >> /tmp/clamscan.wifi");
    
    f = fopen("/tmp/clamscan.wifi","r");
    
    while((frs=getline(&fr,&fs,f)) != -1) {
        printf("%s",fr);
        
    }
    
    fclose(f);
    
    ssid="Cag Elektronik Bilgisayar";
    key="bilmiyorumKI";
    keym = "WPA-PSK";
    
    fw = fopen("/etc/wpa_supplicant/wpa_supplicant.conf","w");
    
    
    
    oth = "ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev\nupdate_config=1\nnetwork={\n ssid=\"";
    
    fwrite(oth,strlen(oth),1,fw);
    
    fwrite(ssid,strlen(ssid),1,fw);
    
    fwrite("\"\n psk=\"",strlen("\"\n psk=\""),1,fw);
    
    fwrite(key,strlen(key),1,fw);
    
    fwrite("\"\n key_mgmt=",strlen("\"\n key_mgmt="),1,fw);
    
    fwrite(keym,strlen(keym),1,fw);
    
    fwrite("\n} ",strlen("\n} "),1,fw);
    
    fclose(fw);
    
   // sleep(10);
    
    return 0;
}

