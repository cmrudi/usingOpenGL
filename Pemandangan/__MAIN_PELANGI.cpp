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

void drawRainbow() {

  //////////////////////////////// Pelangi merah - kuning

  glBegin(GL_POLYGON);
    
    /* 
    abc[0] titik asal kiri
    abc[1] titik control kiri atas
    abc[2] titik control kanan atas
    abc[3] titik asal kanan
    */
    Point abc[4];

    abc[0].setxy(-1.000,-0.3500);
    abc[1].setxy(-0.9000,-0.3000);
    abc[2].setxy(-0.3000,-0.4000);
    abc[3].setxy(-0.1000,-0.6000);


    executeCurve(abc,'r','g');

    // glColor3f(1.0f, 0.0f, 0.0f);
    // glVertex2f(0.500,0.500);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1,-0.700);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-1.0,-0.50);

  glEnd();

  //////////////////////////////// Pelangi kuning - hijau

  glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-1.0,-0.50);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.1,-0.700);
    
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(-0.100,-0.800);
    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(-1.0,-0.60);

  glEnd();


//////////////////////////////// Pelangi hijau - biru

  glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(-1.0,-0.60);

    glColor3f(0.0f, 0.7f, 0.0f);
    glVertex2f(-0.100,-0.800);
    
    // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f(250,200);

    // Point blue[4];
    // blue[0].setxy(-1.0,-0.70);
    // blue[1].setxy(-0.9,-0.6);
    // blue[2].setxy(-0.5,-0.6);
    // blue[3].setxy(-0.3500,-1.0);
    // executeCurve(blue,'b','g');

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.3500,-0.90);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-1.00,-0.800);
    

    // glColor3f(0.0f, 0.0f, 1.0f);
    // glVertex2f(350,200);
    // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex2f(400,300);
  glEnd();


  glBegin(GL_POLYGON);
    Point blue[4];
    blue[0].setxy(-1.00,-0.800);
    blue[1].setxy(-0.9,-0.7);
    blue[2].setxy(-0.4,-0.87);
    blue[3].setxy(-0.3500,-0.90);

    executeCurve(blue,'o','g');
    verColor('o');
    glVertex2f(-0.3500,-0.90);
  glEnd();

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

////////////////////////////////DRAWING RAINBOW
  drawRainbow();
////////////////////////////////END OF RAINBOW

////////////////////////////////DRAWING MOUNTAIN
	// glBegin(GL_POLYGON);
	// 	glColor3f(0.1,0.9,0.1);
	// 	glVertex2f(-1,-0.25);
	// 	glVertex2f(-0.9,-0.2);
	// 	glVertex2f(-0.8,-0.2);
	// 	glVertex2f(-0.7,-0.2);
	// 	glVertex2f(-0.6,-0.25);
	// 	glVertex2f(-0.5,-0.35);
	// 	glVertex2f(-0.4,-0.45);
	// 	glVertex2f(-0.3,-0.45);
	// 	glVertex2f(-0.2,-0.50);
	// 	glVertex2f(-0.1,-0.55);
	// 	glVertex2f(0,-1);
	// 	glVertex2f(-1,-1);
	// glEnd();
	
	glBegin(GL_POLYGON);
		glColor3f(0.1,0.9,0.1);
		glVertex2f(0.5,-0.75);
		glVertex2f(0.6,-0.65);
		glVertex2f(0.7,-0.55);
		glVertex2f(0.8,-0.45);
		glVertex2f(0.9,-0.35);
		glVertex2f(1,-0.30);
		glVertex2f(1,-1);
	glEnd();



	glBegin(GL_POLYGON);            // These vertices form a closed polygon
		glColor3f(0.0f, 1.0f, 0.0f); // Green
		glVertex2f(-1, -1);
		glVertex2f(-0.9,-0.9);
		glVertex2f(-0.8,-0.85);
		glVertex2f(-0.7,-0.80);
		glVertex2f(-0.6,-0.75);
		glVertex2f(-0.5,-0.70);
		glVertex2f(-0.4,-0.70);
		glVertex2f(-0.3,-0.70);
		glVertex2f(-0.2,-0.55);
		glVertex2f(-0.1,-0.50);
		glVertex2f(0, -0.50);
		glVertex2f(0.1, -0.50);
		glVertex2f(0.2, -0.50);
		glVertex2f(0.3, -0.60);
		glVertex2f(0.4, -0.75);
		glVertex2f(0.5, -0.75);
		glVertex2f(0.6, -0.75);
		glVertex2f(0.7, -0.80);
		glVertex2f(0.8, -0.80);
		glVertex2f(0.9, -0.80);
		glVertex2f(1, -1);
	glEnd();

////////////////////////////////END OF DRAWING MOUNTAIN

	float x = 0.5;
	float y = 0.5;

	glColor3f(1.0,0.5,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(-0.17+x, 0.17+y);
		glVertex2f(0.17+x, 0.17+y);
		glVertex2f(0.17+x, -0.17+y);
		glVertex2f(-0.17+x, -0.17+y);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(0+x, 0.25+y);
		glVertex2f(-0.25+x, 0+y);
		glVertex2f(0+x, -0.25+y);
		glVertex2f(0.25+x, 0+y);
	glEnd();


////////////////////////////////DRAWING SUN
	int slices = 50;
    float radius = 0.18;
    float incr = (float) (2 * PI / slices);
    float posX = 0.5;
    float posY = 0.5;

	glBegin(GL_TRIANGLE_FAN);

		  glColor3f(1,0.7,0);//inner color
		  glVertex2f(0.0f+posX, 0.0f+posY);

		  glColor3f(1,1,0);//outer color

		  for(int i = 0; i < slices; i++)
		  {
				float angle = incr * i;

				float x = (float) cos(angle) * radius;
				float y = (float) sin(angle) * radius;

				glVertex2f(x + posX, y + posY);
		  }

		  glVertex2f(radius+ posX, 0.0f + posY);

	glEnd();

/////////////////////////////////END OF DRAWING SUN


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
