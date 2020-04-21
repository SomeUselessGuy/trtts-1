/*
 * MyWindow.cc
 *
 *  Created on: 15 ���. 2020 �.
 *      Author: unyuu
 */

#include <Vector>

#include "MyWindow.h"

void MyWindow::gl_setup()
{
	glEnable(GL_DEPTH_TEST); // �������� ����� �������
	glEnable(GL_LIGHTING); // ���������

	glEnable(GL_LIGHT0);

	glClearColor(0.2f, 0.2f, .4f, 1.f); // ���� ������� ���� (= ���� ����)

	glMatrixMode(GL_PROJECTION);	// �������� � �������� ��������
	gluPerspective(					// ������������� ��������
			45.,					// ���� ������ �� ��������� � ��������
			double(width()) / double(height()), // ����������� ������ ����
			0.1,					// ���������� �� ������� ��������� ���������
			20.0);					// ���������� �� ������� ��������� ���������

	glMatrixMode(GL_MODELVIEW);		// ������ �������� � �������� ������-����
}

void MyWindow::handle_event(const SDL_Event &event)
{
}

void MyWindow::handle_keys(const Uint8 *keys)
{
	if (keys[SDL_SCANCODE_Q]) {	// ���� ������ ������� Q
		_x_angle += .02;			// ����������� ���� �������� ������ ��� X
		if (_x_angle >= 360.)	// ���������� ���� � ��������� 0..360 ��������
			_x_angle -= 360.;
	}

	if (keys[SDL_SCANCODE_W]) {	// ���� ������ ������� W
		_y_angle += .02;			// ����������� ���� �������� ������ ��� Y
		if (_y_angle >= 360.)	// ���������� ���� � ��������� 0..360 ��������
			_y_angle -= 360.;
	}

	if (keys[SDL_SCANCODE_A]) {	// ���� ������ ������� A
		_x_angle -= .02;			// ��������� ���� �������� ������ ��� X
		if (_x_angle < 0.)		// ���������� ���� � ��������� 0..360 ��������
			_x_angle += 360.;
	}

	if (keys[SDL_SCANCODE_S]) {	// ���� ������ ������� S
		_y_angle -= .02;			// ��������� ���� �������� ������ ��� Y
		if (_y_angle < 0.)		// ���������� ���� � ��������� 0..360 ��������
			_y_angle += 360.;
	}
}

void MyWindow::process_logic()
{
	_z_angle += .01; // ����������� ���� �������� ������ ��� Z

	if (_z_angle >= 360.) // ���������� ���� � ��������� 0..360 ��������
		_z_angle -= 360.;
}

static const std::vector<std::vector<double>> vertices{
	{-1., -1., 1.},
	{-1., 1., 1.},
	{0., 1., 1.},
	{0., 0., 1.},
	{1., 0., 1.},
	{1., -1., 1.},
	{0., 0., 0.},
	{0., 1., 0.},
	{1., 1., 0.},
	{1., 0., 0.},
	{-1., -1., -1.},
	{-1., 1., -1.},
	{1., 1., -1.},
	{1., -1., -1.}
};

static const std::vector<std::vector<unsigned>> faces {
    { 4,  0,  3,  4,  5 },
    { 4,  0,  1,  2,  3 },
    { 4,  2,  1, 11,  7 },
    { 4,  8,  7, 11, 12 },

    { 4,  9,  8, 12, 13 },
    { 4,  9, 13,  5,  4 },
    { 4,  3,  2,  7,  6 },
    { 4,  6,  7,  8,  9 },

    { 4,  4,  3,  6,  9 },
    { 4,  1,  0, 10, 11 },
    { 4, 12, 11, 10, 13 },
    { 4,  0,  5, 13, 10 },
};

static const std::vector<std::vector<double>> normals{
	{0., 0., 1.},
	{0., 0., 1.},
	{0., 1., 0.},
	{0., 1., 0.},

	{1., 0., 0.},
	{1., 0., 0.},
	{1., 0., 0.},
	{0., 0., 1.},

	{0., 1., 0.},
	{-1., 0., 0.},
	{0., 0., -1.},
	{0., -1., 0.},
};



void MyWindow::render()
{
	// ������� ������ ����� � ������ �������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ����������� ������� ������-����
	glLoadIdentity();					// MV = 1
	gluLookAt(
			3., 3., 3.,
			0., 0., 0.,
			0., 0., 1.);				// MV = 1 * Cam = Cam
	glRotated(_x_angle, 1., 0., 0.);	// MV = Cam * RotX
	glRotated(_y_angle, 0., 1., 0.);	// MV = Cam * RotX * RotY
	glRotated(_z_angle, 0., 0., 1.);	// MV = Cam * RotX * RotY * RotZ

	/*
	glBegin(GL_LINES);

	for (auto && v: vertices){
		for (auto && v1: vertices){
			glVertex3dv(&v[0]);
			glVertex3dv(&v1[0]);
		}
	}

	*/

	for(unsigned face_index = 0; face_index < faces.size(); face_index++){
		auto && face = faces[face_index];
		if(face[0] == 3){glBegin(GL_TRIANGLES);}
		else if(face[0] == 4) glBegin(GL_QUADS);
		else glBegin(GL_TRIANGLE_FAN);

		glNormal3dv(&normals[face_index][0]);
		for(unsigned index = 1; index < face[0] + 1; index++){
			unsigned vert = face[index];
			glVertex3dv(&vertices[vert][0]);

		}



		glEnd();
	}


	//glBegin(GL_QUADS);				// �������� �������� ���������������










	/*
	glColor3d(1., 1., 0.);			// Ƹ���� ����
	glVertex3d( 0.8,  0.8,  0.8);	// ������� � X=0.8
	glVertex3d( 0.8,  0.8, -0.8);
	glVertex3d( 0.8, -0.8, -0.8);
	glVertex3d( 0.8, -0.8,  0.8);
	*/

	//glEnd();						// ����� ��������� ����������������
}
