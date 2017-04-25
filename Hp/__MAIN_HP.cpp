#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#define PI 3.14159265

using namespace std;

int counter = 0;
int clicks = 4;

class Point {
	public:
		float x, y;
		void setxy(float x2, float y2)
		{
			x = x2; y = y2;
		}
		//operator overloading for '=' sign
		const Point & operator=(const Point &rPoint)
		{
			x = rPoint.x;
			y = rPoint.y;
			return *this;
		}

};

int factorial(int n)
{
    if (n<=1)
        return(1);
    else
        n=n*factorial(n-1);
    return n;
}

float binomial_coff(float n,float k)
{
    float ans;
    ans = factorial(n) / (factorial(k)*factorial(n-k));
    return ans;
}

Point drawBezierGeneralized(Point PT[], double t) {
    Point P;
    P.x = 0; P.y = 0;   
    for (int i = 0; i<clicks; i++)
    {
        P.x = P.x + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].x;
        P.y = P.y + binomial_coff((float)(clicks - 1), (float)i) * pow(t, (double)i) * pow((1 - t), (clicks - 1 - i)) * PT[i].y;
    }
    //cout<<P.x<<endl<<P.y;
    //cout<<endl<<endl;
    return P;
}

//color: r for red, b for blue, w for white
void verColor(char a) {
	  if (a=='r') {
  		glColor3f(1.0f, 0.0f, 0.0f);  
	  }
	  else if (a=='b') {
  		glColor3f(0.0f, 0.0f, 1.0f);
	  }
	  else if (a=='w') {
  		glColor3f(1.0f, 1.0f, 1.0f);
	  }
    else if(a=='o') {
      glColor3f(0.5f, 0.5f, 6.0f); 
    }
}


// mode: g for gradient, l for line
void drawLine(Point p1, Point p2, char c, char mode) {
	if (mode=='g') {
		//verColor(c);
		glVertex2f(p1.x, p1.y);
		//verColor(c);
		glVertex2f(p2.x, p2.y);
	}
	else if (mode=='l') {
		glBegin(GL_LINES);
			glVertex2f(p1.x, p1.y);
			glVertex2f(p2.x, p2.y);
		glEnd();
		//glFlush();
	}
  
}

void executeCurve(Point P[], char color, char mode) {

  verColor(color);
  
  Point p1 = P[0];
  /* Draw each segment of the curve.Make t increment in smaller amounts for a more detailed curve.*/
  for(double t = 0.0;t <= 1.0; t += 0.02)
  {
      
      Point p2 = drawBezierGeneralized(P,t);
      // cout<<p1.x<<"  ,  "<<p1.y<<endl;
      // cout<<p2.x<<"  ,  "<<p2.y<<endl;
      // cout<<endl;
      drawLine(p1, p2, color,mode);
      
      p1 = p2;
  }
}

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

void
drawBox(void)
{
  int i;

  for (i = 0; i < 6; i++) {
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}



void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawBox();
  glutSwapBuffers();
}

void
init(void)
{
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

  /* Adjust cube position to be asthetic angle. */
  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hape Kece Euy");
	glutDisplayFunc(display);
	gluOrtho2D(0,640,0,640);
	glClearColor(0.2f,0.2f,0.2f,0);
	glutMainLoop();
	return 0;
}
