// Programmer: Mihalis Tsoukalos
// Date: Wednesday 04 June 2014
//
// A simple OpenGL program that draws a triangle.

#include "GL/freeglut.h"
#include "GL/gl.h"
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

int dotSize;
int xWidth;
int yHeight;
int *xArray;
int *yArray;


void readFile() {
	ifstream dotFile;
	dotFile.open("dragon.txt");
	char output[10];
	string x = "";
	string y = "";
	int _x;
	int _y;
	if (dotFile.is_open()) {
		dotFile >> dotSize;
		dotFile >> xWidth;
		dotFile >> yHeight;
		
		xArray = new int[dotSize+1];
		yArray = new int[dotSize+1];
		
		int idx = 0;
		while (!dotFile.eof()) {
			dotFile >> output;
			int i = 0;
			while (output[i] != ',') {
				x += output[i];
				i++;
			}
			i++;
			while (output[i] != ',') {
				y+= output[i];
				i++;
			}
			_x = atoi( x.c_str() );
			_y = atoi( y.c_str() );
			xArray[idx] = _x;
			yArray[idx] = _y;
			idx++;
			x = "";
			y = "";
		}
	}
	dotFile.close();
}

void drawTriangle()
{	
	
    /*glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_POLYGON);
                glVertex3f(-0.7, 0.7, 0);
                glVertex3f(0.7, 0.7, 0);
                glVertex3f(0.7, 0.8, 0);
                glVertex3f(0, -1, 0);
        glEnd();

    glFlush();*/
}

void drawDragon()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_POLYGON);
			for (int i = 0; i < dotSize; i++) {
				glVertex3f((float)xArray[i]/(float)xWidth, (float)yArray[i]/(float)yHeight, 0);
				//cout << (float)xArray[i]/(float)xWidth <<"-" << (float)yArray[i]/(float)yHeight << endl;
			}
        glEnd();

    glFlush();
}

void drawCube()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
		
		glBegin(GL_QUADS);
			  glColor3f (0.0, 0.0, 0.0);

			  glVertex3f (0.1, 0.1, 0.0);
			  glVertex3f (0.9, 0.1, 0.0);
			  glVertex3f (0.9, 0.9, 0.0);
			  glVertex3f (0.1, 0.9, 0.0);
		
        glEnd();

    glFlush();
}

int main(int argc, char **argv) {
	
	readFile();
	
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Naga naga-an");
    glutDisplayFunc(drawDragon);
    //glutDisplayFunc(drawCube);
    glutMainLoop();
    return 0;
}
