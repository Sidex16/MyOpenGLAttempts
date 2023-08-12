#include "ProjectHead.h"


void renderScene()
{

    newline = 0; // Відступ між рядками
    glClearColor(0.0, 0.0, 0.0, 1.0); // Колір фону
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0); // Колір тексту
    NextLine();

    if (!NumberOfPlayersIsEnd)
    {
        PrintText("Enter Number Of Players: ");
        NextLine();
        PrintText(inputText);
    }

    if (!GameBeginIsEnd and NumberOfPlayersIsEnd)
    {
        PrintText("Enter user's name: ");
        NextLine();
        PrintText(inputText);
        NextLine();
    }
    // Виведення імен гравців
    for (size_t i = 0; i < PlayersName.size(); i++)
    {
        PrintText(PlayersName[i]);
        NextLine();
    }

    glFlush();

}

void keyboard(unsigned char key, int x, int y)
{

    if (!NumberOfPlayersIsEnd)
    {
        if (key == 13) // Код клавіші Enter
        {
            NumberOfPlayers = stoi(inputText);
            NumberOfPlayersIsEnd = true;
            inputText = "Players: ";
        }
        else if (key == 8) // Код клавіші Backspace
        {
            if (!inputText.empty())
                inputText.pop_back(); // Видалення останнього символу
        }
        else
        {
            inputText += key; // Додавання символу до введеного тексту
        }
    }

    if (NumberOfPlayersIsEnd and !GameBeginIsEnd)
    {

        if (PlayersName.size() == NumberOfPlayers + 1)
        {
            GameBeginIsEnd = true;
        }

        if (key == 13) // Код клавіші Enter
        {
            PlayersName.push_back(inputText);
            inputText = ""; // Очищення введеного тексту
        }
        else if (key == 8) // Код клавіші Backspace
        {
            if (!inputText.empty())
                inputText.pop_back(); // Видалення останнього символу
        }
        else if (key == ']')
        {

        }
        else
        {
            inputText += key; // Додавання символу до введеного тексту
        }
    }

    glutPostRedisplay(); // Оновлення вікна
}

int main(int argc, char** argv)
{
    SetConsoleOutputCP(65001);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("King");

    glutDisplayFunc(renderScene); // Реєстрація функції відображення
    glutKeyboardFunc(keyboard); // Реєстрація функції обробки клавіатури

    glutMainLoop(); // Головний цикл GLUT
    return 0;
}