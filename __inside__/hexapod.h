#ifndef _hexapod_h
#define _hexapod_h

using namespace std;

#include "common.h"
#include "pomocnicze.h"
#include "maestro.h"
//#include "berzier.h"

//TODO:




class hexapod
{
public:
	hexapod();
	~hexapod();

int t; // czas
float X, Y, Z; // wspolrzedne robota

maestro *Maestro;

void gait(float x, float y, float z);
vector <float> ruszaj_noga_skosna(bool prawa, bool przod, float x, float y, float z);

vector <float> kinOdwr(float x, float y, float z);
void idz(float x,float y,float z);


void ruch_swobodny();

void pozycja_startowa();


void tuptanie();
void ruszaj_noga();
void pompki();


private:

//	bezier2d *Berzier;

	bool flaga;
	float theta1(float x, float y);
	float theta2(float z, float r);
	float theta3(float z, float r);


};

#endif
