/*
 * MyWindow.h
 *
 *  Created on: 15 ���. 2020 �.
 *      Author: unyuu
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"

// "����" ����, ������� ���� ������, ��� ������ Window
class MyWindow: public Window
{
protected:
	// ������� _���������_ ��������� ���������
	virtual void gl_setup();

	// ������� ��������� �������
	virtual void handle_event(const SDL_Event & event);

	// ������� ��������� ������� � ������ ������ ������
	virtual void handle_keys(const Uint8 * keys);

	// ������� ���������� ��������� ������, ��
	// ��������� �������� � ����������
	virtual void process_logic();

	// �������, �������������� ���������������
	// ��������� �����������.
	virtual void render();

	// ���� �������� ����� ����������� ������
	double _x_angle { 0. };
	double _y_angle { 0. };
	double _z_angle { 0. };
public:
	MyWindow(): Window() {}				// �����������
	virtual ~MyWindow() = default;		// ����������


};



#endif /* MYWINDOW_H_ */
