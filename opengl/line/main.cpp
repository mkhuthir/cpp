
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define NENDS 2           // number of end "points" to draw

GLdouble width, height;   // window width and height
int wd;                   // GLUT window handle
int ends[NENDS][2];       // array of 2D points

void init(void)           // initialize paramaters
{
  width  = 800.0;         // GL window width
  height = 800.0;         // GL window height

  ends[0][0] = (int)(0.25*width);  //  (0,0) is the lower left corner  
  ends[0][1] = (int)(0.75*height);
  ends[1][0] = (int)(0.75*width);
  ends[1][1] = (int)(0.25*height);

  return;
}

// Callback functions for GLUT

// Draw the window - this is where all the GL actions are
void displayCB(void)
{
  int i;

  glClear(GL_COLOR_BUFFER_BIT);       // clear the screen to white
  
  glBegin(GL_LINES);                  // draw lines
    for (i = 0; i < NENDS; ++i) {
      glVertex2iv((GLint *) ends[i]);
    }
  glEnd();
  
  glFlush();

  return;
}

// Called when window is resized,also when window is first created, before the first call to display().
void reshapeCB(int w, int h)
{
  // save new screen dimensions
  width = (GLdouble) w;
  height = (GLdouble) h;

  // tell OpenGL to use the whole window for drawing
  glViewport(0, 0, (GLsizei) width, (GLsizei) height);

  // do an orthographic parallel projection with the coordinate system set to first quadrant, limited by screen/window size
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, width, 0.0, height, -1.f, 1.f);
  
  return;
}

void kbdCB(unsigned char key, int x, int y)
{
  switch((char)key) {
    case 'q':
    case 27:    //  ESC  
      glutDestroyWindow(wd);
      exit(0);
    default:
      break;
  }

  return;
}

int main(int argc, char *argv[])
{
  init();

  //  initialize GLUT, let it extract command-line GLUT options that you may provide  
  glutInit(&argc, argv);

  //  specify the display to be single buffered and color as RGBA values  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

  //  set the initial window size  
  glutInitWindowSize((int) width, (int) height);

  //  create the window and store the handle to it  
  wd = glutCreateWindow("Experiment with line drawing");

  //  --- register callbacks with GLUT ---  

  //  register function to handle window resizes  
  glutReshapeFunc(reshapeCB);

  //  register keyboard event processing function  
  glutKeyboardFunc(kbdCB);

  //  register function that draws in the window  
  glutDisplayFunc(displayCB);

  //  init GL  
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glColor3f(0.0, 0.0, 0.0);
  glLineWidth(3.0);

  // start the GLUT main loop  
  glutMainLoop();

  exit(0);
}