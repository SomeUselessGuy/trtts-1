/*
 * main.cc
 *
 *  Created on: 14 ���. 2020 �.
 *      Author: unyuu
 */

#include "globals.h"

#include "MyWindow.h"

#include <SDL2/SDL_main.h>

int main(int, char **)
{
	try {
		SDL_Init(SDL_INIT_EVERYTHING);

		MyWindow win;

		win.main_loop();
	} catch (const std::exception & e) {
		std::cerr <<
				"��� ���������� ��������� �������� ��������� ��������:" <<
				std::endl << e.what() << std::endl;
		return 1;
	} catch (...) {
		std::cerr <<
				"��� ���������� ��������� �������� "
				"����������� ��������� ��������." << std::endl;
		return 2;
	}

	return 0;
}
