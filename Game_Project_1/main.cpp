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

    // �ܼ� Ŀ�� ����� (������ ����)
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    clearScreen();
    drawUser(player.x, player.y);
    enemies.push_back(Enemy(enemyX, enemyY, 3)); // �� ����

    printScreen();
    int timer = 0;

    while (true) {
        gotoxy(0, 0);  // Ŀ���� ù �ٷ� �̵��Ͽ� ȭ�� �и� ����

        if (timer % 2 == 0) {
            player.handleInput();
        }

        clearScreen();  // ���� ȭ�� ���� (�ʿ��� ��츸 ����)
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
