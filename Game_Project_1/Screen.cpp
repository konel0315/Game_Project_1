#include <iostream>
#include <vector>
#include <algorithm>  // gotoxy를 사용하기 위해 필요
#include "Screen.h"
#include <conio.h>


using namespace std;

int screen[HEIGHT][WIDTH];  // 화면을 int 배열로 정의
int screenCollor[HEIGHT][WIDTH];

vector<Enemy> enemies;

// 커서 이동 함수 (화면 흔들림 방지)
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showStartScreen() {
    system("cls"); // 너가 만든 화면 초기화 함수
    gotoxy(30, 10); std::cout << " GALAGA: 콘솔 에디션 ";
    gotoxy(28, 12); std::cout << "아무 키나 눌러 게임 시작!";
    _getch();
}

void showGameOverScreen() {
    system("cls");
    gotoxy(35, 10); std::cout << " GAME OVER ";
    gotoxy(30, 12); std::cout << "다시 시작하려면 아무 키나 누르세요.";
    _getch();
}

void showClearScreen() {
    system("cls");
    gotoxy(35, 10); std::cout << "  게임 클리어! 축하합니다! ";
    gotoxy(28, 12); std::cout << "아무 키나 누르면 다시 시작합니다.";
    _getch();
}



void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // 화면을 0으로 초기화 (빈칸 '□')
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


void drawChat() { // 디버그용
    //int I = enemies.size(); // 예제: 현재 남아있는 적 수 출력
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

    gotoxy(0, 0);  // 화면을 지우지 않고 (cls 없이) 첫 줄에서 다시 출력
    drawChat();

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), screenCollor[i][j]);

            switch (screen[i][j]) {
            case 0: cout << "□"; break;  // 빈칸
            case 1: cout << "■"; break;  // 사용자
            case 2: cout << "●"; break;  // 적 타격 부위
            case 3: cout << "▲"; break;  // 사용자 총알
            case 4: cout << "▼"; break;  // 적 총알
            case 5: cout << "◎"; break;  // 적 비 타격 부위
            default: cout << " "; break;
            }
        }
        cout << endl;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);  // 색상 초기화
}
