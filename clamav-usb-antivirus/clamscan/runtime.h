/* 
 * File:   runtime.h
 * Author: pi
 *
 * Created on 21 Aralık 2015 Pazartesi, 00:15
 */

#ifndef RUNTIME_H
#define	RUNTIME_H

#ifdef	__cplusplus
extern "C" {


    void checktemp();
    int _initspec();
    int _specscan();
    int _commandmv(char *filea);
    int _chartoint(char *ch);
    int _getint(char xa);
    char *gtdir(char *gdir);
    char *chadd(char* s1,char* s2);
    void _summary(const struct optstruct *opts);
    int checkusb(char *usb);
    int fposition(int pos);
    int charmach(char *ch);
    char *charget(char *ch);
    char *charget2(char *ch);
    char *checkfile();
    int is_valid_hostid(void);
    char *get_hostid(void *cbdata);
    int charnum(char ch);
    char numchar(int num);
    void _trashed();

    
#ifdef	__cplusplus
}
#endif

#endif	/* RUNTIME_H */

