#ifndef SCREEN_H
#define SCREEN_H


#include "Enemy.h"
#include <windows.h>
#include "User.h"
#include "Stage.h"
const int WIDTH = 30;
const int HEIGHT = 30;
enum COLLOR
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    AQUA = 3,
    RED = 4,
    PURPLE = 5,
    YELLOW = 6,
    WHITE = 7,
    GRAY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_AQUA = 11,
    LIGHT_RED = 12,
    LIGHT_PURPLE = 13,
    LIGHT_YELLOW = 14,
    BRIGHT_WHITE = 15
};
// 화면을 int 배열로 정의
extern int screen[HEIGHT][WIDTH];
extern int screenCollor[HEIGHT][WIDTH];
extern vector<Bullet> InGameBullet;
extern vector<Enemy> enemies;  // 적 리스트
extern int clear;

void clearScreen();
void drawUser(int x, int y,int color);
void drawEnemy(int i);
void printScreen();
void moveBullet(vector<Bullet>& InGameBullet, vector<Enemy>& enemies, User& player, Stage& stage);
void gotoxy(int x, int y);
void showStartScreen();
void showGameOverScreen();
void showClearScreen();
#endif // SCREEN_H
