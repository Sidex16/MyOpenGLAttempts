#include <windows.h>
#include <GL/glut.h>

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-4, 4, -4, 4, -4, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.6f);    glVertex2f(-4.0f, -4.0f);
    glColor3f(0.0f, 0.8f, 0.2f);    glVertex2f(2.0f, -2.0f);
    glColor3f(0.2f, 0.0f, 1.0f);    glVertex2f(-2.0f, 2.0f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Simple Triangle");
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(5000, 5000);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}