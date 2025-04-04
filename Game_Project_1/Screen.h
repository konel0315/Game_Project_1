#ifndef SCREEN_H
#define SCREEN_H


#include "Enemy.h"
#include <windows.h>
#include "User.h"
const int WIDTH = 30;
const int HEIGHT = 30;

// 화면을 int 배열로 정의
extern int screen[HEIGHT][WIDTH];
extern vector<Bullet> InGameBullet;
extern vector<Enemy> enemies;  // 적 리스트


void clearScreen();
void drawUser(int x, int y);
void drawEnemy(int i);
void printScreen();
void moveBullet(vector<Bullet>& InGameBullet, vector<Enemy>& enemies, User& player);
void gotoxy(int x, int y);

#endif // SCREEN_H
