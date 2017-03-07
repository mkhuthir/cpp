#include <GL/gl.h>
#include <GL/glut.h>

double x, y, z;           // current teapot position (initialized in main)

void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    /* draw scene */
    glPushMatrix();
    glTranslatef(x,y,z);
    glutWireTeapot(.5);
    glPopMatrix();

    /* flush drawing routines to the window */
    glFlush();

    /* display the offscreen buffer */
    glutSwapBuffers();
}

void animate () {

    /* update state variables */
    x += .001;
    y += .001;
    z -= .001;

    /* refresh screen */
    glutPostRedisplay();
}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);

}


int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    /* create and set up a window */
    glutCreateWindow("flying teapot");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);

    /* depth-buffering */
    glEnable(GL_DEPTH_TEST);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,.5,3.0);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1.0,1.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

    /* initialize state variables (teapot position) */
    x = 0;
    y = 0;
    z = 0;

    /* tell GLUT to wait for events */
    glutMainLoop();
}
