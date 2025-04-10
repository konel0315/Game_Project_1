#include <iostream>
#include <vector>
#include <algorithm>  // gotoxy�� ����ϱ� ���� �ʿ�
#include "Screen.h"
#include <conio.h>


using namespace std;

int screen[HEIGHT][WIDTH];  // ȭ���� int �迭�� ����
int screenCollor[HEIGHT][WIDTH];

vector<Enemy> enemies;

// Ŀ�� �̵� �Լ� (ȭ�� ��鸲 ����)
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showStartScreen() {
    system("cls"); // �ʰ� ���� ȭ�� �ʱ�ȭ �Լ�
    gotoxy(30, 10); std::cout << " GALAGA: �ܼ� ����� ";
    gotoxy(28, 12); std::cout << "�ƹ� Ű�� ���� ���� ����!";
    _getch();
}

void showGameOverScreen() {
    system("cls");
    gotoxy(35, 10); std::cout << " GAME OVER ";
    gotoxy(30, 12); std::cout << "�ٽ� �����Ϸ��� �ƹ� Ű�� ��������.";
    _getch();
}

void showClearScreen() {
    system("cls");
    gotoxy(35, 10); std::cout << "  ���� Ŭ����! �����մϴ�! ";
    gotoxy(28, 12); std::cout << "�ƹ� Ű�� ������ �ٽ� �����մϴ�.";
    _getch();
}



void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // ȭ���� 0���� �ʱ�ȭ (��ĭ '��')
            screenCollor[i][j] = WHITE;
        }
    }
}

void drawUser(int x, int y, int hitFlashTimer) {
    int color = (hitFlashTimer > 0) ? RED : LIGHT_GREEN;

    screen[y][x] = 1;
    screenCollor[y][x] = color;

    screen[y - 1][x] = 1;
    screenCollor[y - 1][x] = color;

    screen[y][x - 1] = 1;
    screenCollor[y][x - 1] = color;

    screen[y][x + 1] = 1;
    screenCollor[y][x + 1] = color;
}


void drawChat() { // ����׿�
    //int I = enemies.size(); // ����: ���� �����ִ� �� �� ���
    //cout << "User life: " <<Player<< endl;
}

void printScreen() {

    static bool initialized = false;
    if (!initialized) {
        CONSOLE_CURSOR_INFO cursorInfo;
        cursorInfo.bVisible = FALSE;
        cursorInfo.dwSize = 1;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        initialized = true;
    }

    gotoxy(0, 0);  // ȭ���� ������ �ʰ� (cls ����) ù �ٿ��� �ٽ� ���
    drawChat();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), screenCollor[i][j]);

            switch (screen[i][j]) {
            case 0: cout << "��"; break;  // ��ĭ
            case 1: cout << "��"; break;  // �����
            case 2: cout << "��"; break;  // �� Ÿ�� ����
            case 3: cout << "��"; break;  // ����� �Ѿ�
            case 4: cout << "��"; break;  // �� �Ѿ�
            case 5: cout << "��"; break;  // �� �� Ÿ�� ����
            default: cout << " "; break;
            }
        }
        cout << endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);  // ���� �ʱ�ȭ
}
