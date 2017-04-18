#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

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


void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);

//////////////////////////////// SKY BOX
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW); // Line ini yang menyebabkan pelangi tidak muncul, komentari saja supaya pelangi muncul
	glLoadIdentity();
	
	glMatrixMode(GL_COLOR);
	glLoadIdentity();
	
	glBegin(GL_QUADS);
		//Sky Blue Color
		glColor3f(0.5,0.5,6.0);
		glVertex2f(-1.0,-1.0);
		glVertex2f(1.0,-1.0);
		//White Color
		glColor3f(1.0,1.0,1.0);
		glVertex2f(1.0,1.0);
		glVertex2f(-1.0, 1.0);
	glEnd();
	

////////////////////////////////END OF SKY BOX
////////////////////////////////DRAWING MOUNTAIN

	glBegin(GL_POLYGON);            // These vertices form a closed polygon
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow
		glVertex2f(0.4f, 0.2f);
		glVertex2f(0.6f, 0.2f);
		glVertex2f(0.7f, 0.4f);
		glVertex2f(0.6f, 0.6f);
		glVertex2f(0.4f, 0.6f);
		glVertex2f(0.3f, 0.4f);
	glEnd();

////////////////////////////////END OF DRAWING MOUNTAIN


//////////////////////////////// Pelangi merah - kuning

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(100,500);


		/* 
		abc[0] titik asal kiri
		abc[1] titik control kiri atas
		abc[2] titik control kanan atas
		abc[3] titik asal kanan
		*/
		Point abc[4];

		abc[0].setxy(100.0,500.0);
		abc[1].setxy(200.0,600.0);
		abc[2].setxy(400.0,600.0);
		abc[3].setxy(500.0,500.0);


		executeCurve(abc,'r','g');

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(500,500);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(450,400);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(150,400);

	glEnd();


//////////////////////////////// Pelangi kuning - hijau

	glBegin(GL_POLYGON);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(150,400);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(450,400);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(400,300);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(200,300);

	glEnd();


//////////////////////////////// Pelangi hijau - biru

	glBegin(GL_POLYGON);

		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(200,300);

		// glColor3f(0.0f, 0.0f, 1.0f);
		// glVertex2f(250,200);

		Point blue[4];
		blue[0].setxy(250.0,200.0);
		blue[1].setxy(290.0,240.0);
		blue[2].setxy(310.0,240.0);
		blue[3].setxy(350.0,200.0);

		executeCurve(blue,'b','g');
		// glColor3f(0.0f, 0.0f, 1.0f);
		// glVertex2f(350,200);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2f(400,300);
	glEnd();


	// glBegin(GL_POLYGON);
		// blue[0].setxy(250.0,200.0);
		// blue[1].setxy(290.0,240.0);
		// blue[2].setxy(310.0,240.0);
		// blue[3].setxy(350.0,200.0);

		// executeCurve(blue,'w','g');
		// glColor3f(1.0f, 1.0f, 1.0f);
		// glVertex2f(350,200);
	// glEnd();

 
    
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Pemandangan Euy");
	glutDisplayFunc(display);
	gluOrtho2D(0,640,0,640);
	glClearColor(0.2f,0.2f,0.2f,0);
	glutMainLoop();
	return 0;
}
