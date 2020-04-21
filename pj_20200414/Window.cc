/*
 * Window.cc
 *
 *  Created on: 15 апр. 2020 г.
 *      Author: unyuu
 */

#include "Window.h"

// Конструктор объекта окна
Window::Window(int width, int height)
: _width(width), _height(height)
{
	// Создание окна
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

	// Задание параметров будущего контекста OpenGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Создание контекста OpenGL
	_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (_context == nullptr)
		SDL_DIE("SDL_GL_CreateContext()", __FILE__, __LINE__ - 3);
}

// Функция, реализующая основной цикл программы.
void Window::main_loop()
{
	// Начальная настройка контекста
	gl_setup();

	SDL_Event event; // Здесь будет храниться информация о событии

	// Информация о нажатых клавишах
	const Uint8 * keys = SDL_GetKeyboardState(nullptr);

	// Основной цикл
	for(;;) {
		// Цикл обработки событий
		while (SDL_PollEvent(&event)) {
			// Обработка события завершения программы
			if (event.type == SDL_QUIT) return;

			// Обработка остальных событий
			handle_event(event);
		}

		// Обработка клавиш
		handle_keys(keys);

		// Выполнение прочей логики
		process_logic();

		// Рисование
		render();

		// Показ результата
		SDL_GL_SwapWindow(_window.get());
	}
}
