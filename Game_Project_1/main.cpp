#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <windows.h>
#include "Screen.h"
#include "Bullet.h"
using namespace std;

int main() {
    int userX = WIDTH / 2, userY = HEIGHT - 2;
    int enemyX = WIDTH / 2, enemyY = 3;

    clearScreen();
    drawUser(userX, userY);
    InGameBullet.push_back(Bullet(userX, userY - 1,0));
    InGameBullet.push_back(Bullet(userX, userY - 3, 0));
    InGameBullet.push_back(Bullet(userX, userY - 5, 0));
    enemies.push_back(Enemy(enemyX, enemyY,3));//Àû»ý¼º
    printScreen();

    while (true) {
        clearScreen();
        drawUser(userX, userY);
        if (enemies.size() > 0) 
        {
            drawEnemy(0);
        }
        moveBullet(InGameBullet, enemies);
        printScreen();

        this_thread::sleep_for(chrono::milliseconds(250));
    }

    return 0;
}
