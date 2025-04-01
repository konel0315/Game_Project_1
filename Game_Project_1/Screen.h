#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include "Bullet.h"

const int WIDTH = 30;
const int HEIGHT = 30;

// 화면을 int 배열로 정의
extern int screen[HEIGHT][WIDTH];
extern std::vector<Bullet> InGameBullet;

void clearScreen();
void drawUser(int x, int y);
void drawEnemy(int x, int y);
void moveBullet(std::vector<Bullet>& InGameBullet, bool isUserBullet);
void printScreen();


#endif // SCREEN_H
