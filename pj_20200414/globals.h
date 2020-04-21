/*
 * globals.h
 *
 *  Created on: 15 ���. 2020 �.
 *      Author: unyuu
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <iostream>
#include <sstream>
#include <functional>
#include <memory>
#include <stdexcept>

#include <SDL2/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

// ������� ���� �� ���������
constexpr int
	DEFAULT_WINDOW_WIDTH = 800,
	DEFAULT_WINDOW_HEIGHT = 600;

// �������� ���������� � ������ ������������� ��������
// ��� ������������� ���������� SDL
static inline void SDL_DIE(
		const char * reason,
		const char * file = nullptr,
		int line = -1)
{
	std::stringstream ss;
	if (file != nullptr) {
		ss << file;
		if (line > 0)
			ss << ':' << line;
		ss << ": ";
	}
	ss << reason << ": " << SDL_GetError();
	throw std::runtime_error(ss.str());
}

// �������� ���������� � ������ �������
static inline void DIE(
		const char * reason,
		const char * file = nullptr,
		int line = -1)
{
	std::stringstream ss;
	if (file != nullptr) {
		ss << file;
		if (line > 0)
			ss << ':' << line;
		ss << ": ";
	}
	ss << reason;
	throw std::runtime_error(ss.str());
}


#endif /* GLOBALS_H_ */
