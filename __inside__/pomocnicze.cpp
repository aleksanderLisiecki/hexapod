#include "pomocnicze.h"

int SetAngle(double angle)
{
	if (angle > 180 || angle < 0)
		return 6000;
	else
	{
		angle = angle / 180.0;
		angle = angle * 1800.0 + 600.0;
		angle = angle * 4;
		return (int)angle;
	}
}
double naStopnie(double a)
{
	a = a * 180.0 / PI;
	return a;
}
double naRadiany(double a)
{
    a = a * PI / 180;
}

/*
void czekajMS(int czas_ms)
{
	int check_delay = 2; //ile razy ma sprawdzic nacisniecie klawisza 
	int frequency = czas_ms / check_delay;
	for (float i = 0; i < float(czas_ms / 2); i++)
	{
		usleep(check_delay * 1000);
		readKey();
	}

}
void readKey()
{
	int last_key;
	//--- odczytywanie ostatniego wcisnietego klawisza ---
	while ((last_key = getch()) != ERR) key = last_key;

	switch (last_key) {
	case 27: wyjscie = true;  break;  //--- ESC ---
	}
}*/
