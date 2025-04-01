#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Screen.h"

using namespace std;

int main() {
    int userX = WIDTH / 2, userY = HEIGHT - 2;
    int enemyX = WIDTH / 2, enemyY = 1;

    clearScreen();
    drawUser(userX, userY);
    drawEnemy(enemyX, enemyY);
    InGameBullet.push_back(Bullet(userX, userY - 1));
    printScreen();

    while (true) {
        clearScreen();
        drawUser(userX, userY);
        drawEnemy(enemyX, enemyY);
        moveBullet(InGameBullet, true);
        printScreen();

        this_thread::sleep_for(chrono::milliseconds(250));
    }

    return 0;
}
