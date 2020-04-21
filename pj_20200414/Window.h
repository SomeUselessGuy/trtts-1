/*
 * Window.h
 *
 *  Created on: 15 апр. 2020 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "globals.h"

// Класс окна с поддержкой OpenGL
class Window
{
protected:
	int _width;								// Ширина окна
	int _height;							// Высота окна

	std::shared_ptr<SDL_Window> _window;	// Указатель на SDL-окно
	std::shared_ptr<void> _context;			// Указатель на OpenGL-контекст

	// Функция _начальной_ настройки контекста
	virtual void gl_setup() {}

	// Функция обработки события
	virtual void handle_event(const SDL_Event & event) {}

	// Функция обработки нажатых в данный момент клавиш
	virtual void handle_keys(const Uint8 * keys) {}

	// Функция выполнения некоторой логики, не
	// связанной напрямую с отрисовкой
	virtual void process_logic() {}

	// Функция, осуществляющая непосредственно
	// отрисовку изображения.
	virtual void render() {}

public:
	Window(							// Конструктор
			int width = DEFAULT_WINDOW_WIDTH,
			int height = DEFAULT_WINDOW_HEIGHT);
	virtual ~Window() = default;	// Деструктор

	// Функция, реализующая основной цикл программы.
	virtual void main_loop();

	// Геттеры для размеров окна
	int width() const { return _width; }
	int height() const { return _height; }
};




#endif /* WINDOW_H_ */
