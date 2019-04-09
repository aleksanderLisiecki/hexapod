#include "hexapod.h"


hexapod::hexapod()
{
	Maestro = new maestro();
	//Berzier = new berzier2d();
	
	flaga = true;
	t = 0;
	X = 0;
	Y = 0;
	Z = 0;

}

hexapod::~hexapod()
{
	if (Maestro) delete Maestro;
}







void hexapod::idz(float x,float y,float z)
{

}

void hexapod::gait(float x, float y, float z) {	// gait - z angielskiego "chod" (uczymy sie angielskiego :D )
	/*float sin_z;
	float ruch_x = -45; // srodkowanie x
	if (t < 180){
		sin_z = sin(naRadiany(t)) * 50;
		ruch_x += t/2;
		t+=10;
		}
	else 
    	{
        sin_z = 0;
        ruch_x -= (t-180)/2;
        t+=10;
    	}
    if(t > 360)t = 0;*/

	float h = 0;
	float ruch_x = 45;
	if(ruch_x = 0)h = 40;
	if(ruch_x = 90)h = 0;
	if(ruch_x > 0  && flaga)
	{
		t += 5;
		ruch_x = -t;
	}
	else flaga = false;
	if(ruch_x <= 90 && !flaga)
	{
		t += 5;
		ruch_x = t - 45;
	}
	else flaga = true;
	if(t = 135)t = 0;

	vector <float> katy;
	//katy = kinOdwr(ruch_x + x, y, z - sin_z);
	//katy = ruszaj_noga_skosna(true, true, ruch_x + x, y, z - sin_z);
	katy = kinOdwr(ruch_x + x, y, z - h);
    	Maestro->maestroSetSingleTarget(NOGA1_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA1_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA1_C, katy[2]);
}

vector <float> hexapod::ruszaj_noga_skosna(bool prawa, bool przod, float x, float y, float z)
{
    float dx, dy;
	vector <float> katy;
	katy.push_back(0.0f);
	katy.push_back(0.0f);
	katy.push_back(0.0f);
	//katy = kinOdwr(pom_x, pom_y, pom_z);
	if (!prawa && przod)//lewa przod
	{
		dx = cos(PI / 3) * x - sin(PI / 3) * y;
		dy = sin(PI / 3) * x + cos(PI / 3) * y;
	}
	if (!prawa && przod)//prawa przod
	{
		dx = cos(-PI / 3) * x - sin(-PI / 3) * y;
		dy = sin(-PI / 3) * x + cos(-PI / 3) * y;
	}
	if (!prawa && !przod)//lewa tyl
	{
		dx = cos(2 * PI / 3) * x - sin(2 * PI / 3) * y;
		dy = sin(2 * PI / 3) * x + cos(2 * PI / 3) * y;
	}
	if (prawa && !przod)//prawa tyl
	{
		dx = cos(-2 * PI / 3) * x - sin(-2 * PI / 3) * y;
		dy = sin(-2 * PI / 3) * x + cos(-2 * PI / 3) * y;
	}
	katy = kinOdwr(dx, dy, z);
	return katy;
}



void hexapod::ruszaj_noga() {
	vector <float> katy;
	katy.push_back(0.0f);
	katy.push_back(0.0f);
	katy.push_back(0.0f);
	katy = kinOdwr(pom_x, pom_y, pom_z);
//printw("\nkaty[0]: %f", katy[0]);
//printw("\nkaty[1]: %f", katy[1]);
//printw("\nkaty[2]: %f", katy[2]);

	vector<unsigned short> targets;
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	Maestro->maestroSet18Targets(targets);




	refresh();
}




//=============== DZIALAJACY KOD =============================================


//-------------------------------------------------------------------------------
//====================== POZYCJA STARTOWA =======================================
//-------------------------------------------------------------------------------
void hexapod::pozycja_startowa(){

for(int i = 0; i<= 77; i+=2 ){

	vector <float> katy;
	katy = kinOdwr(0.0f, 135.0f, 89.0f + i);
clear();
printw("\n %f",88.0f + i);
refresh();

	vector<unsigned short> targets;
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	Maestro->maestroSet18Targets(targets);
usleep(500);
}
}
//---------------------------------------------------------------------------
//====================== POMPKI =============================================
//---------------------------------------------------------------------------
void hexapod::pompki() {

	float cos_z = cos(naRadiany(t));
	t+=10;
	if (t >= 720) t = 0;

	vector <float> katy;
	katy = kinOdwr(0.0f, 125.0f, 172.0f + cos_z * 60);

	vector<unsigned short> targets;
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	Maestro->maestroSet18Targets(targets);

}

//---------------------------------------------------------------------------
//====================== TUPTANIE ===========================================
//---------------------------------------------------------------------------
void hexapod::tuptanie(){

	vector <float> katy;
for(int nozka=0; nozka<=5; nozka++){

for(int i=0; i < 180; i+=10){
	float sin_z = sin(naRadiany(i));
	katy = kinOdwr(0.0f, 125.0f, 165.0f - sin_z * 60);


	usleep(400);



switch(nozka){
case 1:
 	Maestro->maestroSetSingleTarget(NOGA1_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA1_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA1_C, katy[2]);
break;
case 2:
 	Maestro->maestroSetSingleTarget(NOGA2_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA2_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA2_C, katy[2]);
break;
case 3:
 	Maestro->maestroSetSingleTarget(NOGA3_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA3_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA3_C, katy[2]);
break;
case 4:
 	Maestro->maestroSetSingleTarget(NOGA4_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA4_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA4_C, katy[2]);
break;
case 5:
 	Maestro->maestroSetSingleTarget(NOGA5_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA5_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA5_C, katy[2]);
break;
case 6:
 	Maestro->maestroSetSingleTarget(NOGA6_A, katy[0]);
	Maestro->maestroSetSingleTarget(NOGA6_B, katy[1]);
	Maestro->maestroSetSingleTarget(NOGA6_C, katy[2]);
break;
	}
}
}}

//---------------------------------------------------------------------------
//====================== RUCH SWOBODNY ======================================
//---------------------------------------------------------------------------
void hexapod::ruch_swobodny() {

	
	vector <float> katy;
	katy = kinOdwr(pom_x, 125.0f, pom_z);

	vector<unsigned short> targets;
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	targets.push_back(katy[2]);
	targets.push_back(katy[1]);
	targets.push_back(katy[0]);
	Maestro->maestroSet18Targets(targets);
}


//-------------------------------------------------------------------------------
//====================== KINEMATYKA =============================================
//-------------------------------------------------------------------------------

vector <float> hexapod::kinOdwr(float x, float y, float z)
{
float odleglosc_wspolrzednych = sqrt((x*x)+ (y*y)+(z*z));
if(odleglosc_wspolrzednych <90) printw("\n !!!UWAGA!!! dlogosc ramienia mniejsza niz 90 \n");
else if(2701 < odleglosc_wspolrzednych)printw("\n !!!UWAGA!!! dlogosc ramienia wieksza niz 270 \n");
if (y <= 0 || z <= 0) {
	printw("\nY = %f   Z = %f, kinematyka odwrotna warunki ---> Y>0 && Z>0", y, z);
	vector<float> vct_inv_kin;
	vct_inv_kin.push_back(90.0f);
	vct_inv_kin.push_back(90.0f);
	vct_inv_kin.push_back(90.0f);
	}
if (y > 0 && z > 0) {


	float r = sqrt(pow(x, 2.0) + pow(y, 2.0)) - COXA;
	z -= PODNIESIENIE;
	float t1 = theta1(x, y);
	float t2 = theta2(z, r);
	float t3 = theta3(z, r);


	vector<float> vct_inv_kin;
	vct_inv_kin.push_back(t1);
	vct_inv_kin.push_back(t2);
	vct_inv_kin.push_back(t3);


	return vct_inv_kin;
}
}
float hexapod::theta1(float x, float y) {
	if (y > 0) {
		float t1 = atan(x / y);
		float t2 = atan(-y / x);
		if (x > 0)return naStopnie(t1) + 90.0f;
		else if (x == 0)return 90.0f;
		else if (x < 0)return naStopnie(t2);
	}
	else printw("\nY < 0  ----> poza zakresem");
}
float hexapod::theta2(float z, float r) {

	float d2 = pow((z), 2.0) + pow((r), 2.0);
	float d = sqrt(d2);

	float alfa2 = atan(r / z);

	float alfa1 = acos((pow(FEMUR, 2.0) + d2 - pow(TIBIA, 2.0)) / (2 * FEMUR * d));

	return naStopnie(alfa1 + alfa2);
}
float hexapod::theta3(float z, float r) {

	float d2 = pow((z), 2.0) + pow((r), 2.0);
	return  180.0f - naStopnie(acos((pow(FEMUR, 2.0) + pow(TIBIA, 2.0) - d2) / (2 * FEMUR * TIBIA)));
}
//-------------------------------------------------------------------------------
