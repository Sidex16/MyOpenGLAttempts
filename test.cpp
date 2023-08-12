#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <string>

int windowWidth = 800;
int windowHeight = 600;
int numPlayers = 0;
std::vector<std::string> playerNames;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, windowHeight, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0f, 1.0f, 1.0f);

    // Відображення тексту
    glRasterPos2f(10, 20);
    std::string info = "Введіть кіkjvlkaa1лькість гравців: " + std::to_string(numPlayers);
    for (const char& c : info) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }

    // Відображення імен гравців
    glRasterPos2f(10, 40);
    int lineHeight = 15; // Висота рядка
    for (const std::string& name : playerNames) {
        for (const char& c : name) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
        glBitmap(0, 0, 0, 0, 0, -lineHeight, nullptr); // Зсув до наступного рядка
    }

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) { // Код клавіші "Esc"
        exit(0);
    }
}

void specialKeyboard(int key, int x, int y) {
    if (key == 13) { // Код спеціальної клавіші "Enter"
        std::cout << std::endl;

        for (int i = 0; i < numPlayers; ++i) {
            std::string playerName;
            std::cout << "Введіть ім'я граvsnklvevkjd2вця " << i + 1 << ": ";
            std::cin >> playerName;
            playerNames.push_back(playerName);
        }

        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("OpenGL Program");

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeyboard);

    glutMainLoop();

    return 0;
}
