#include "gui.h"

int key=0;
//GUI
int GUIInit(){

	initscr();
	clear();
	mvprintw(0, 0, "HEX v1.%d", VERSION);
	mvprintw(2, 0, "ESC aby wyjsc...");


	int migaj_kursorem = 1; // migaj kursorem przez x sekund
	bool kursor = 0;



	nodelay(stdscr, 1);	// ustawia no-delay mode - getch nie czeka na wcisniecie klawisza :)
				// konsola nie wyswietla wpisywanych znakow (nie odpowiada)


	// ----- petla migania kursorem, miga przez x sekund i przechdozi do glownej petli -----
	while (migaj_kursorem) {
		if(getch() == 27) return 1;//obsluga esc
		if (kursor) {	mvprintw(2, 17, " "); }
		else{	mvprintw(2, 17, "|"); migaj_kursorem--; }
		kursor = !kursor;
		usleep(500 * 1000); //czekaj 500ms
	}

	refresh();

	noecho();
	raw();
	return 0;
}
void GUIMain(){

	//clear();
	mvprintw(1, 0, "[Esc] > Wyjscie");
	mvprintw(2, 0, "Kod wcisnietego klawisza: %d", key);

printw("\n\npompki: %d", pompki);
printw("\nchod: %d", idz);
printw("\nruch swobodny: %d", ruch_swobodny);
printw("\ntuptanie: %d", tuptanie);


	printw("\n\npom_x: %f", pom_x);
	printw("\npom_y: %f", pom_y);
	printw("\npom_z: %f", pom_z);

	/*mvprintw(4, 0, "pol: %d", pol);
	mvprintw(5, 0, "rayleigh: %d", rayleigh);
	mvprintw(6, 0, "tlumienie: %d", tlumienie);
	mvprintw(7, 0, "przod: %d", idzprzod);
	mvprintw(8, 0, "tyl: %d", idztyl);
	mvprintw(9, 0, "lewo: %d", slewo);
	mvprintw(10, 0, "prawo: %d", sprawo);
	mvprintw(11, 0, "predkosc: %d", szybkosc);
	mvprintw(12, 0, "vi: %f", vi);
	mvprintw(13, 0, "xi: %f", xi);
	*/

key = 0;
	refresh();

	czekajMS(20); //== 50 fps
}
void GUIExit(){
	endwin();
}

void czekajMS(int czas_ms) {
	int check_delay = 2; //ile razy ma sprawdzic nacisniecie klawisza
	int frequency = czas_ms / check_delay;
	for (float i = 0; i < float(czas_ms / 2); i++)
	{
		usleep(frequency * 1000);
		readKey();
	}



}

void readKey() {

	int buf_key;
	//--- odczytywanie ostatniego wcisnietego klawisza ---
	while ((buf_key = getch()) != ERR){ key = buf_key;
	//
	}
	switch (key) {
	case 27: wyjscie = true;  clear(); break;  //--- ESC ---

	case 113: pom_x+=2; break;	// q
	case 97: pom_x-=2; break;	// a
	case 119: pom_y+=2; break;	// w
	case 115: pom_y-=2; break;	// s
	case 101: pom_z+=2; break;	// e
	case 100: pom_z-=2; break;	// d


	case 112: pompki = !pompki; 	usleep(100 * 1000); break;	// d

	case 111: ruch_swobodny = !ruch_swobodny; 	usleep(100 * 1000); break;	// o

	case 105: idz = !idz; 		usleep(100 * 1000); break; // i
	case 117: tuptanie = !tuptanie; 		usleep(100 * 1000); break; // u
	}

}
