#include <iostream>
#include <vector>
#include <algorithm>
#include "Screen.h"

using namespace std;

int screen[HEIGHT][WIDTH];  // 화면을 int 배열로 정의
vector<Bullet> InGameBullet;

void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // 화면을 0으로 초기화 (빈칸 '□')
        }
    }
}

void drawUser(int x, int y) {
    screen[y][x] = 1;  // 사용자 위치 '■'
    screen[y + 1][x - 1] = 1;
    screen[y + 1][x] = 1;
    screen[y + 1][x + 1] = 1;
}

void drawEnemy(int x, int y) {
    screen[y][x - 1] = 2;  // 적 위치 '●'
    screen[y][x] = 2;
    screen[y][x + 1] = 2;
}

void moveBullet(vector<Bullet>& InGameBullet, bool isUserBullet) {
    for (int i = 0; i < InGameBullet.size(); i++) {
        int prevX = InGameBullet[i].pos.x;
        int prevY = InGameBullet[i].pos.y;

        // 기존 위치 지우기
        if (prevY >= 0 && prevY < HEIGHT && prevX >= 0 && prevX < WIDTH) {
            screen[prevY][prevX] = 0;  // 총알이 지나간 자리를 0으로 변경
        }

        // 총알 이동
        if (isUserBullet) {
            InGameBullet[i].pos.y--;
        }
        else {
            InGameBullet[i].pos.y++;
        }

        int newY = InGameBullet[i].pos.y;
        int newX = InGameBullet[i].pos.x;

        // 새 위치가 화면 안에 있으면 출력
        if (newY >= 0 && newY < HEIGHT && newX >= 0 && newX < WIDTH) {
            screen[newY][newX] = isUserBullet ? 3 : 4;  // User Bullet은 3, Enemy Bullet은 4로 설정
        }
    }

    // 화면 밖으로 나간 총알 삭제
    InGameBullet.erase(remove_if(InGameBullet.begin(), InGameBullet.end(), [](Bullet& b) {
        return b.pos.y < 0 || b.pos.y >= HEIGHT;
        }), InGameBullet.end());
}

void printScreen() {
    system("cls");  // 콘솔을 초기화

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // 숫자 값에 따라 출력할 문자 결정
            switch (screen[i][j]) {
            case 0: cout << "□"; break;  // 빈칸
            case 1: cout << "■"; break;  // 사용자
            case 2: cout << "●"; break;  // 적
            case 3: cout << "▲"; break;  // 사용자 총알
            case 4: cout << "▼"; break;  // 적 총알
            default: cout << " "; break;
            }
        }
        cout << endl;
    }
}
