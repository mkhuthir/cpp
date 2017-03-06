#include <GL/glut.h>

void draw(void) {

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    //Draw here
    
    glFlush();

}


int main(int argc, char **argv) {

    glutInit(&argc, argv);

    // Setting up the Display -RGB color model + Alpha Channel = GLUT_RGBA
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

    //Configure Window Postion
    glutInitWindowPosition(50, 50);

    //Configure Window Size
    glutInitWindowSize(800,800);

    //Create Window
    glutCreateWindow("Hello OpenGL");

    //Call to the drawing function
    glutDisplayFunc(draw);

    // Loop require by OpenGL
    glutMainLoop();
    
    return 0;
}
