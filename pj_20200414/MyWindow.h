/*
 * MyWindow.h
 *
 *  Created on: 15 апр. 2020 г.
 *      Author: unyuu
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// "Наше" окно, умеющее чуть больше, чем просто Window
class MyWindow: public Window
{
protected:
	// Функция _начальной_ настройки контекста
	virtual void gl_setup();

	// Функция обработки события
	virtual void handle_event(const SDL_Event & event);

	// Функция обработки нажатых в данный момент клавиш
	virtual void handle_keys(const Uint8 * keys);

	// Функция выполнения некоторой логики, не
	// связанной напрямую с отрисовкой
	virtual void process_logic();

	// Функция, осуществляющая непосредственно
	// отрисовку изображения.
	virtual void render();

	// Угол поворота нашей вращающейся модели
	double _x_angle { 0. };
	double _y_angle { 0. };
	double _z_angle { 0. };
public:
	MyWindow(): Window() {}				// Конструктор
	virtual ~MyWindow() = default;		// Деструктор


};



#endif /* MYWINDOW_H_ */
