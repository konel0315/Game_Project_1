#include <iostream>
#include <vector>
#include <algorithm>  // gotoxy�� ����ϱ� ���� �ʿ�
#include "Screen.h"


using namespace std;

int screen[HEIGHT][WIDTH];  // ȭ���� int �迭�� ����

vector<Enemy> enemies;

// Ŀ�� �̵� �Լ� (ȭ�� ��鸲 ����)
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // ȭ���� 0���� �ʱ�ȭ (��ĭ '��')
        }
    }
}

void drawUser(int x, int y) {
    screen[y][x] = 1;  // ����� ��ġ '��'
    screen[y - 1][x ] = 1;
    screen[y ][x-1] = 1;
    screen[y ][x + 1] = 1;
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
            // ���� ���� ���� ����� ���� ����
            switch (screen[i][j]) {
            case 0: cout << "��"; break;  // ��ĭ
            case 1: cout << "��"; break;  // �����
            case 2: cout << "��"; break;  // �� Ÿ�� ����
            case 3: cout << "��"; break;  // ����� �Ѿ�
            case 4: cout << "��"; break;  // �� �Ѿ�
            case 5: cout << "��"; break; //�� �� Ÿ�� ����
            default: cout << " "; break;
            }
        }
        cout << endl;
    }
}
