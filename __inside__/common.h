//------------------------------- PROJECT SETTINGS --------------------------------------------
#ifndef _common_h
#define _common_h

//------------------------------- DEFINICJE -----------------------------------------------

#define PI 3.141592653f
#define VERSION 01			//wersja programu

#define COXA 39.0f
#define PODNIESIENIE 10.0f
#define FEMUR 90.0f
#define TIBIA 180.0f


#define POZYCJA_STARTOWA_X 0.0
#define POZYCJA_STARTOWA_y 125.0
#define POZYCJA_STARTOWA_z 130.0

#define NOGA1_A 21
#define NOGA1_B 22
#define NOGA1_C 23

#define NOGA2_A 18
#define NOGA2_B 19
#define NOGA2_C 20

#define NOGA3_A 15
#define NOGA3_B 16
#define NOGA3_C 17

#define NOGA4_A 10
#define NOGA4_B 3
#define NOGA4_C 14

#define NOGA5_A 7
#define NOGA5_B 8
#define NOGA5_C 9

#define NOGA6_A 4
#define NOGA6_B 5
#define NOGA6_C 6

//------------------------------- ZMIENNE GLOBALNE -----------------------------------------------

extern bool wyjscie;
extern bool pompki;
extern bool idz;
extern bool ruch_swobodny;
extern bool tuptanie;


extern float pom_x;
extern float pom_y;
extern float pom_z;





//------------------------------- BIBLIOTEKI -----------------------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <cmath>
#include <string>
#include <ncurses.h>
#include <iostream>
#include <curses.h>

//----- biblioteki Maestro -----
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
//----- biblioteki Maestro -----

//------------------------------- BIBLIOTEKI -----------------------------------------------


#endif


/*
TODO:
podawanie czasu z gui do maina




*/
