#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Bullet.h"
#include "User.h"

using namespace std;

int main() {
    User player(WIDTH / 2, HEIGHT - 2, 3);
    int enemyX = WIDTH / 2, enemyY = 3;

    // 콘솔 커서 숨기기 (깜빡임 방지)
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    clearScreen();
    drawUser(player.x, player.y);
    enemies.push_back(Enemy(enemyX, enemyY, 3)); // 적 생성

    printScreen();
    int timer = 0;

    while (true) {
        gotoxy(0, 0);  // 커서를 첫 줄로 이동하여 화면 밀림 방지

        if (timer % 2 == 0) {
            player.handleInput();
        }

        clearScreen();  // 기존 화면 삭제 (필요할 경우만 실행)
        drawUser(player.x, player.y);

        if (!enemies.empty()) {
            drawEnemy(0);
        }

        moveBullet(InGameBullet, enemies);
        printScreen();

        this_thread::sleep_for(chrono::milliseconds(50));
        timer++;
    }

    return 0;
}
