/*
 * OGL02Animation.cpp: 3D Shapes with animation
 */
//#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

 
/* Global variables */
char title[] = "3D Shapes with animation";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid [NEW]
GLfloat angleCube = 0.0f;     // Rotational angle for cube [NEW]
int refreshMills = 15;        // refresh interval in milliseconds [NEW]


float xRel = 3.55f;
float yRel = 0.4f;
float zRel = 7.1f;




float scale = 4.0;
float xHalfDim = 0.8875f;
float yHalfDim = 0.1f;
float zHalfDim = 1.775f;

 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void setColor(char a) {
     if (a=='r') {
      glColor3f(1.0f, 0.0f, 0.0f);  
     }
     else if (a=='b') {
      glColor3f(0.0f, 0.0f, 1.0f);
     }
     else if (a=='w') {
      glColor3f(1.0f, 1.0f, 1.0f);
     }
     else if (a=='h') {
      glColor3f(0.0f, 0.0f, 0.0f);
     }
    else if(a=='o') {
      glColor3f(0.5f, 0.5f, 6.0f); 
    }
    else if (a=='c') {
      glColor3f(0.4,0.2,0);
     }
     else if (a=='y') {
      glColor3f(1.0,1.0,0);
     }
}

void drawCamera(float posX, float posY, float radius, char inCol, char outCol) {

   int slices = 50;
   float incr = (float) (2 * PI / slices);
    
   glBegin(GL_TRIANGLE_FAN);

        setColor(inCol);//inner color
        glVertex3f(0.0f+posX,-yHalfDim-0.01f, 0.0f+posY);

        setColor(outCol);//outer color

        for(int i = 0; i < slices; i++)
        {
            float angle = incr * i;

            float x = (float) cos(angle) * radius;
            float y = (float) sin(angle) * radius;

            glVertex3f(x + posX,-yHalfDim-0.01f, y + posY);
        }

        glVertex3f(radius+ posX,-yHalfDim-0.01f, 0.0f + posY);

   glEnd();
}

void drawFrontCamera(float posX, float posY, float radius, char inCol, char outCol) {

   int slices = 50;
   float incr = (float) (2 * PI / slices);
    
   glBegin(GL_TRIANGLE_FAN);

        setColor(inCol);//inner color
        glVertex3f(0.0f+posX,yHalfDim+0.01f, 0.0f+posY);

        setColor(outCol);//outer color

        for(int i = 0; i < slices; i++)
        {
            float angle = incr * i;

            float x = (float) cos(angle) * radius;
            float y = (float) sin(angle) * radius;

            glVertex3f(x + posX,yHalfDim+0.01f, y + posY);
        }

        glVertex3f(radius+ posX,yHalfDim+0.01f, 0.0f + posY);

   glEnd();
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
   
   

   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
   glRotatef(angleCube, 1.0f, 1.0f, 1.0f);  // Rotate about (1,1,1)-axis [NEW]
 
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(239.0/255.0, 224.0/255.0, 184.0/255.0); // Soft Gold || FRONT FACE
      glVertex3f( xHalfDim, yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim, yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim, yHalfDim,  zHalfDim);
      glVertex3f( xHalfDim, yHalfDim,  zHalfDim);
      
	  // Tambalan warna beda yang atas    //Black || SCREEN on FRONT FACE
      glColor3f(0,0,0);
      glVertex3f( xHalfDim-0.07, yHalfDim+0.01, -zHalfDim+0.5);
      glVertex3f(-xHalfDim+0.07, yHalfDim+0.01, -zHalfDim+0.5);
      glVertex3f(-xHalfDim+0.07, yHalfDim+0.01,  zHalfDim-0.4);
      glVertex3f( xHalfDim-0.07, yHalfDim+0.01,  zHalfDim-0.4);
      
      
      
      
 	
      // Bottom face (y = -1.0f)
      glColor3f(196.0/255.0, 180.0/255.0, 139.0/255.0);
      glVertex3f( xHalfDim, -yHalfDim,  zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim,  zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim, -zHalfDim);
      glVertex3f( xHalfDim, -yHalfDim, -zHalfDim);

      // Tambalan warna beda yang atas
      glColor3f(239.0/255.0, 224.0/255.0, 184.0/255.0);
      glVertex3f( xHalfDim, -yHalfDim-0.015,  zHalfDim-0.5);
      glVertex3f(-xHalfDim, -yHalfDim-0.015,  zHalfDim-0.5);
      glVertex3f(-xHalfDim, -yHalfDim-0.015, -zHalfDim+0.5);
      glVertex3f( xHalfDim, -yHalfDim-0.015, -zHalfDim+0.5);
 
      // Front face  (z = 1.0f)
      glColor3f(0.9f, 0.5f, 0.5f);     // Orange
      glVertex3f( xHalfDim,  yHalfDim, zHalfDim);
      glVertex3f(-xHalfDim,  yHalfDim, zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim, zHalfDim);
      glVertex3f( xHalfDim, -yHalfDim, zHalfDim);
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Yellow
      glVertex3f( xHalfDim, -yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim,  yHalfDim, -zHalfDim);
      glVertex3f( xHalfDim,  yHalfDim, -zHalfDim);
 
      // Left face (x = -1.0f)
      glColor3f(0.5f, 0.5f, 0.9f);     // Blue
      glVertex3f(-xHalfDim,  yHalfDim,  zHalfDim);
      glVertex3f(-xHalfDim,  yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim, -zHalfDim);
      glVertex3f(-xHalfDim, -yHalfDim,  zHalfDim);
 
      // Right face (x = 1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Half Blue
      glVertex3f(xHalfDim,  yHalfDim, -zHalfDim);
      glVertex3f(xHalfDim,  yHalfDim,  zHalfDim);
      glVertex3f(xHalfDim, -yHalfDim,  zHalfDim);
      glVertex3f(xHalfDim, -yHalfDim, -zHalfDim);
   glEnd();  // End of drawing color-cube
   
   // Button Menu Box
   glBegin(GL_LINE_STRIP);
   	  float xBoxStart = 0.45;
   	  glColor3f(0,0,0);
   	  glVertex3f( xHalfDim-xBoxStart, yHalfDim, -zHalfDim+0.2);
   	  glVertex3f( xHalfDim-xBoxStart-0.15, yHalfDim, -zHalfDim+0.2);
   	  glVertex3f( xHalfDim-xBoxStart-0.15, yHalfDim, -zHalfDim+0.35);
   	  glVertex3f( xHalfDim-xBoxStart, yHalfDim, -zHalfDim+0.35);
   	  glVertex3f( xHalfDim-xBoxStart, yHalfDim, -zHalfDim+0.2);  
   glEnd();
   
   //Button Menu Pentagon
   glBegin(GL_LINE_STRIP);
   	  float xPentagonStart = 0.85;
   	  glColor3f(0,0,0);
   	  glVertex3f( xHalfDim-xPentagonStart, yHalfDim, -zHalfDim+0.2);
   	  glVertex3f( xHalfDim-xPentagonStart-0.15, yHalfDim, -zHalfDim+0.2);
   	  glVertex3f( xHalfDim-xPentagonStart-0.15, yHalfDim, -zHalfDim+0.28);
   	  glVertex3f( xHalfDim-xPentagonStart-0.075, yHalfDim, -zHalfDim+0.35);
   	  glVertex3f( xHalfDim-xPentagonStart, yHalfDim, -zHalfDim+0.28);
   	  glVertex3f( xHalfDim-xPentagonStart, yHalfDim, -zHalfDim+0.2);
   glEnd();
   
   //Button Menu Triangle
   glBegin(GL_LINE_STRIP);
   	  float xTriangleStart = 1.25;
   	  glColor3f(0,0,0);
   	  glVertex3f( xHalfDim-xTriangleStart, yHalfDim, -zHalfDim+0.2);
   	  glVertex3f( xHalfDim-xTriangleStart-0.15, yHalfDim, -zHalfDim+0.275);
   	  glVertex3f( xHalfDim-xTriangleStart, yHalfDim, -zHalfDim+0.35);
   	  glVertex3f( xHalfDim-xTriangleStart, yHalfDim, -zHalfDim+0.2);  
   glEnd();
   
   //Front Camera
   drawFrontCamera(0.3,1.6,0.05,'c','h');
   
   //Proximity Sensor
   drawFrontCamera(-0.35,1.6,0.05,'c','h');
   drawFrontCamera(-0.38,1.6,0.05,'c','h');
   drawFrontCamera(-0.41,1.6,0.05,'c','h');
   
   //Front Speaker
   drawFrontCamera(0.1,1.6,0.05,'g','w');
   drawFrontCamera(0.07,1.6,0.05,'g','w');
   drawFrontCamera(0.04,1.6,0.05,'g','w');
   drawFrontCamera(0.01,1.6,0.05,'g','w');
   drawFrontCamera(-0.02,1.6,0.05,'g','w');
   drawFrontCamera(-0.05,1.6,0.05,'g','w');
   drawFrontCamera(-0.08,1.6,0.05,'g','w');
   drawFrontCamera(-0.11,1.6,0.05,'g','w');
   drawFrontCamera(-0.14,1.6,0.05,'g','w');
   drawFrontCamera(-0.17,1.6,0.05,'g','w');
   drawFrontCamera(-0.21,1.6,0.05,'g','w');
   
   //Rear Camera
   drawCamera(-0.6,1.5,0.15,'c','h');
   //Flash for Rear Camera
   drawCamera(-0.3,1.5,0.05,'y','w');
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
 
   // Update the rotational angle after each refresh [NEW]
   anglePyramid += 0.2f;
   angleCube -= 0.15f;
}
 
/* Called back when timer expired [NEW] */
void timer(int value) {
   glutPostRedisplay();      // Post re-paint request to activate display()
   glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutTimerFunc(0, timer, 0);     // First timer call immediately [NEW]
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
