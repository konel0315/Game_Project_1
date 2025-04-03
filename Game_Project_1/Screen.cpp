#include <iostream>
#include <vector>
#include <algorithm>
#include "Screen.h"

using namespace std;

int screen[HEIGHT][WIDTH];  // 화면을 int 배열로 정의

vector<Enemy> enemies;

void clearScreen() 
{
    for (int i = 0; i < HEIGHT; i++) 
    {
        for (int j = 0; j < WIDTH; j++) 
        {
            screen[i][j] = 0;  // 화면을 0으로 초기화 (빈칸 '□')
        }
    }
}

void drawUser(int x, int y) 
{
    screen[y][x] = 1;  // 사용자 위치 '■'
    screen[y + 1][x - 1] = 1;
    screen[y + 1][x] = 1;
    screen[y + 1][x + 1] = 1;
}

void drawEnemy(int i) 
{
    
    screen[enemies[i].y][enemies[i].x - 1] = 2;  // 적 위치 '●'
    screen[enemies[i].y][enemies[i].x] = 2;
    screen[enemies[i].y][enemies[i].x + 1] = 2;
}
void drawChat() //디버그용
{
    /*int I = enemies.begin()->health;*/
    /*int I=InGameBullet.begin()->owner;*/
   /* int I = InGameBullet.size();*/
    /*cout << I<<endl;*/
}

void printScreen() {
    system("cls");  // 콘솔을 초기화
    drawChat();
    for (int i = 0; i < HEIGHT; i++) 
    {
        for (int j = 0; j < WIDTH; j++) 
        {
            // 숫자 값에 따라 출력할 문자 결정
            switch (screen[i][j]) 
            {
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
