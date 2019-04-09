#ifndef _gui_h
#define _gui_h

#include "common.h"


int GUIInit();
void GUIMain();
void GUIExit();
void czekajMS(int czas_ms); //funkcja czekajMS powoduje delay w ms oraz sprawdza wcisniete klawisze
void readKey();

//int key;

#endif