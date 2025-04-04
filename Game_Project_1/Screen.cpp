#include <iostream>
#include <vector>
#include <algorithm>  // gotoxy를 사용하기 위해 필요
#include "Screen.h"


using namespace std;

int screen[HEIGHT][WIDTH];  // 화면을 int 배열로 정의

vector<Enemy> enemies;

// 커서 이동 함수 (화면 흔들림 방지)
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // 화면을 0으로 초기화 (빈칸 '□')
        }
    }
}

void drawUser(int x, int y) {
    screen[y][x] = 1;  // 사용자 위치 '■'
    screen[y - 1][x ] = 1;
    screen[y ][x-1] = 1;
    screen[y ][x + 1] = 1;
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
            // 숫자 값에 따라 출력할 문자 결정
            switch (screen[i][j]) {
            case 0: cout << "□"; break;  // 빈칸
            case 1: cout << "■"; break;  // 사용자
            case 2: cout << "●"; break;  // 적 타격 부위
            case 3: cout << "▲"; break;  // 사용자 총알
            case 4: cout << "▼"; break;  // 적 총알
            case 5: cout << "◎"; break; //적 비 타격 부위
            default: cout << " "; break;
            }
        }
        cout << endl;
    }
}
