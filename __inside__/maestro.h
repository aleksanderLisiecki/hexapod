#ifndef _maestro_h
#define _maestro_h

using namespace std;

#include "common.h"

class maestro
{
public:
    maestro(); // wywoluje UARTInit() odpalajacy komunikacje z maestro
    ~maestro();
    int maestroGetError(); // pobiera blad
    int maestroGetPosition(unsigned char channel);//pobiera pozycje kanalu
    void maestroSetSingleTarget(unsigned char channel, unsigned short target);//podaje katy dla 1 serwa
    void maestroSet18Targets(vector<unsigned short> targets);//podaje katy dla 18 serw
    void UARTInit();//inicjalizacja portu komunikacyjnego z maestro
    int SetAngle(double angle);


private:
    int fd;
};
#endif
