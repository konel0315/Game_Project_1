//적움직임
#include "Screen.h"
void Enemy::move() 
{
    
    if (moveCount % 2 == 0) 
    {
        // 짝수 번째: 아래 블록 실제 이동
        int dx = 0, dy = 0;

        if (dirIndex < directionArray.size()) 
        {
            int dir = directionArray[dirIndex];
            switch (dir) 
            {
            case 1: dx = 1; break;   // 오른쪽
            case -1: dx = -1; break;  // 왼쪽
            case +2: dy = -1; break;  // 위로
            case -2: dy = +1; break;  // 아래로
            case 0: default: break;  // 제자리
            }
        }
        if (moveCount % 2 == 0) {
            previousX = x;
            previousY = y;
        }
        x += dx;
        y += dy;

        dirIndex++;
        if (dirIndex == directionArray.size()) 
        {
            dirIndex = 0;
        }
    }


    if (x < 0) x = 0;
    if (x >= WIDTH ) x = WIDTH - 1;
    if (y < 0) y = 0;
    if (y >= HEIGHT ) y = HEIGHT - 1;



    if (moveCount % 4 == 0) 
    {
       shoot(Bulletype);
    }
    moveCount++;  // 호출 횟수 증가

}



void Enemy::draw() {
    int xBottom = x;
    int yBottom = y;
    int xTop, yTop;

    if (moveCount % 2 == 1) {
        // 위 블록이 한 프레임 늦게 따라감 → 이전 프레임의 아래 블록 위치로 그림
        xTop = previousX;
        yTop = previousY - 1;
    }
    else {
        // 아래 블록과 x좌표 같고, 위로 한 칸
        xTop = x;
        yTop = y - 1;
       
    }

    // 현재 프레임 기준으로 그리기
    screen[yTop][xTop] = 5;
    screen[yBottom][xBottom] = 2;
    
}
void Enemy::shoot(string bulletType)
{
    InGameBullet.push_back(Bullet(x, y +1, 1,bulletType));
}