/*
 * Window.h
 *
 *  Created on: 15 ���. 2020 �.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "globals.h"

// ����� ���� � ���������� OpenGL
class Window
{
protected:
	int _width;								// ������ ����
	int _height;							// ������ ����

	std::shared_ptr<SDL_Window> _window;	// ��������� �� SDL-����
	std::shared_ptr<void> _context;			// ��������� �� OpenGL-��������

	// ������� _���������_ ��������� ���������
	virtual void gl_setup() {}

	// ������� ��������� �������
	virtual void handle_event(const SDL_Event & event) {}

	// ������� ��������� ������� � ������ ������ ������
	virtual void handle_keys(const Uint8 * keys) {}

	// ������� ���������� ��������� ������, ��
	// ��������� �������� � ����������
	virtual void process_logic() {}

	// �������, �������������� ���������������
	// ��������� �����������.
	virtual void render() {}

public:
	Window(							// �����������
			int width = DEFAULT_WINDOW_WIDTH,
			int height = DEFAULT_WINDOW_HEIGHT);
	virtual ~Window() = default;	// ����������

	// �������, ����������� �������� ���� ���������.
	virtual void main_loop();

	// ������� ��� �������� ����
	int width() const { return _width; }
	int height() const { return _height; }
};




#endif /* WINDOW_H_ */
