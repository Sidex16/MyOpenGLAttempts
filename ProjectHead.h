#include <GL/glut.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

string inputText = ""; // Змінна для зберігання введеного тексту
vector<string> PlayersName; // Масив імен гравців
int NumberOfPlayers;
bool GameBeginIsEnd = false;
bool NumberOfPlayersIsEnd = false;
int newline = 20; // Відступ між рядками


void PrintText(string info)
{
    if (info != "")
    {
        string text = info; // Текст, який потрібно відобразити

        for (char c : text) // Пройти по кожному символу тексту і відобразити його
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }
}

void NextLine()
{
    newline += 20; // Зміщення на новий рядок
    glRasterPos2i(10, glutGet(GLUT_WINDOW_HEIGHT) - newline);

}

void FillPlayersName()
{

}