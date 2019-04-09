#include "main.h"



using namespace std;

bool wyjscie = false; //redefinicja zmiennej zadeklarowanej w common.h
bool pompki = false;
bool idz = false;
bool ruch_swobodny = false;
bool tuptanie = false;

float pom_x = 0.0f;
float pom_y = 140.0f;
float pom_z = 100.0f;



int main() {
	if (GUIInit()) { GUIExit(); return 0; } // warunek konczenia podczas ekranu poczatkowego

	Hexapod = new hexapod();
Hexapod -> pozycja_startowa();


Hexapod -> tuptanie();


	while (!wyjscie){
//----------------------------------------------------------------------------------
//============================== PETLA GLOWNA ======================================
//----------------------------------------------------------------------------------

//=================== POMPKI =================
//--------------------------------------------
if(pompki)Hexapod -> pompki();
//--------------------------------------------
//================ RUCH SWOBODNY =============
//--------------------------------------------
if(ruch_swobodny)Hexapod -> ruch_swobodny();
//--------------------------------------------
//=================== GAIT ===================
//--------------------------------------------
if(idz)Hexapod -> gait(pom_x, pom_y, pom_z);
//--------------------------------------------
//=================== TUPTANIE ===================
//--------------------------------------------
if(tuptanie){Hexapod -> tuptanie(); tuptanie = false;}


		GUIMain();


//Hexapod->Maestro->maestroSetSingleTarget(23, pom_x);








//----------------------------------------------------------------------------------
//============================== PETLA GLOWNA ======================================
//----------------------------------------------------------------------------------
	}
	GUIExit();
	return 0;
}
