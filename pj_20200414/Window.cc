/*
 * Window.cc
 *
 *  Created on: 15 ���. 2020 �.
 *      Author: unyuu
 */

#include "Window.h"

// ����������� ������� ����
Window::Window(int width, int height)
: _width(width), _height(height)
{
	// �������� ����
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"OpenGL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (_window == nullptr)
		SDL_DIE("SDL_CreateWindow()", __FILE__, __LINE__ - 8);

	// ������� ���������� �������� ��������� OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// �������� ��������� OpenGL
	_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (_context == nullptr)
		SDL_DIE("SDL_GL_CreateContext()", __FILE__, __LINE__ - 3);
}

// �������, ����������� �������� ���� ���������.
void Window::main_loop()
{
	// ��������� ��������� ���������
	gl_setup();

	SDL_Event event; // ����� ����� ��������� ���������� � �������

	// ���������� � ������� ��������
	const Uint8 * keys = SDL_GetKeyboardState(nullptr);

	// �������� ����
	for(;;) {
		// ���� ��������� �������
		while (SDL_PollEvent(&event)) {
			// ��������� ������� ���������� ���������
			if (event.type == SDL_QUIT) return;

			// ��������� ��������� �������
			handle_event(event);
		}

		// ��������� ������
		handle_keys(keys);

		// ���������� ������ ������
		process_logic();

		// ���������
		render();

		// ����� ����������
		SDL_GL_SwapWindow(_window.get());
	}
}
