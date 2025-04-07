//��������
#include "Screen.h"
void Enemy::move() 
{
    
    if (moveCount % 2 == 0) 
    {
        // ¦�� ��°: �Ʒ� ��� ���� �̵�
        int dx = 0, dy = 0;

        if (dirIndex < directionArray.size()) 
        {
            int dir = directionArray[dirIndex];
            switch (dir) 
            {
            case 1: dx = 1; break;   // ������
            case -1: dx = -1; break;  // ����
            case +2: dy = -1; break;  // ����
            case -2: dy = +1; break;  // �Ʒ���
            case 0: default: break;  // ���ڸ�
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
    moveCount++;  // ȣ�� Ƚ�� ����

}



void Enemy::draw() {
    int xBottom = x;
    int yBottom = y;
    int xTop, yTop;

    if (moveCount % 2 == 1) {
        // �� ����� �� ������ �ʰ� ���� �� ���� �������� �Ʒ� ��� ��ġ�� �׸�
        xTop = previousX;
        yTop = previousY - 1;
    }
    else {
        // �Ʒ� ��ϰ� x��ǥ ����, ���� �� ĭ
        xTop = x;
        yTop = y - 1;
       
    }

    // ���� ������ �������� �׸���
    screen[yTop][xTop] = 5;
    screen[yBottom][xBottom] = 2;
    
}
void Enemy::shoot(string bulletType)
{
    InGameBullet.push_back(Bullet(x, y +1, 1,bulletType));
}