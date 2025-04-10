#include "Boss.h"
#include "Screen.h"
#include "BossData.h"


void Boss::shoot()
{
    
    Bullet b1 = Bullet(x, y+1, 1, "boss");
    b1.dx = 1;  b1.dy = 1;
    Bullet b2 = Bullet(x, y + 1, 1, "boss");
    b2.dx = -1;  b2.dy = 1;
    Bullet b3 = Bullet(x, y + 1, 1, "boss");
    b3.dx = 1;  b3.dy = -1;
    Bullet b4 = Bullet(x, y + 1, 1, "boss");
    b4.dx = -1;  b4.dy = -1;

    InGameBullet.push_back(b1);
    InGameBullet.push_back(b2);
    InGameBullet.push_back(b3);
    InGameBullet.push_back(b4);
}

void Boss::move()
{
    if (!leftArm.isDead())
    {
        leftArm.move();
    }
    if (!rightArm.isDead())
    {
        rightArm.move();
    }

    if (shellDestroyed && !directionArray.empty())
    {
        if (moveCount % 5 == 0)
        {
            shoot();
        }
        if (dirIndex >= directionArray.size()) 
        {
            dirIndex = 0;
        }
        if (moveCount % 3 == 0)
        {
            int dir = directionArray[dirIndex];
            int dx = 0, dy = 0;

            switch (dir)
            {
            case 1:  dx = 1;  break;
            case -1: dx = -1; break;
            case 2:  dy = -1; break;
            case -2: dy = 1;  break;
            }

            // 중심 좌표 이동
            x += dx;
            y += dy;

            // bodyParts 전체 이동
            for (auto& frame : bodyParts)
                for (auto& pos : frame)
                    pos.x += dx, pos.y += dy;
            dirIndex++;
        }

        currentFrame = (currentFrame + 1) % bodyParts.size();
    }

    moveCount++;
}
void Boss::draw() {
    // 왼팔 (타격 가능 부위)
    if (!leftArm.isDead())
    {
        for (const auto& pos : leftArm.getCurrentHitParts()) {
            int color = (leftArm.hitFlashTimer > 0) ? RED : WHITE;
            screen[pos.y][pos.x] = 2; // ●
            screenCollor[pos.y][pos.x] = color;
        }

        // 왼팔 (타격 불가능 부위)
        for (const auto& pos : leftArm.getCurrentNonHitParts()) {
            screenCollor[pos.y][pos.x] = LIGHT_YELLOW;
            screen[pos.y][pos.x] = 5; // ◎
        }
    }

    // 오른팔 (타격 가능 부위)
    if (!rightArm.isDead())
    {
        for (const auto& pos : rightArm.getCurrentHitParts()) {
            int color = (rightArm.hitFlashTimer > 0) ? RED : WHITE;
            screen[pos.y][pos.x] = 2; // ●
            screenCollor[pos.y][pos.x] = color;
        }

        // 오른팔 (타격 불가능 부위)
        for (const auto& pos : rightArm.getCurrentNonHitParts()) {
            screenCollor[pos.y][pos.x] = LIGHT_YELLOW;
            screen[pos.y][pos.x] = 5; // ◎
        }
    }
    // 본체 (항상 보임)
    if(shellDestroyed)
    {
        for (const auto& pos : bodyParts[currentFrame]) 
        {
            if (pos.x == this->x && pos.y == this->y) {
                screen[pos.y][pos.x] = 5; // ◎ (중앙, 비피격)

            }
            else {
                int color = (hitFlashTimer > 0) ? RED : WHITE;
                screenCollor[pos.y][pos.x] = color;
                screen[pos.y][pos.x] = 2; // ● (피격 가능)
            }
        }
    }
    else {
        for (const auto& pos : bodyParts[0]) {
            if (pos.x == this->x && pos.y == this->y) {
                screen[pos.y][pos.x] = 5; // ◎ (중앙, 비피격)
            }
            else {
                screen[pos.y][pos.x] = 2; // ● (피격 가능)
            }
        }
    }

    // 껍질 (양팔이 살아있을 때만 보임)
    if (!shellDestroyed) {
        for (const auto& pos : shellParts[0]) {
            screenCollor[pos.y][pos.x] = YELLOW;
            screen[pos.y][pos.x] = 5; // ◎
        }
    }
}

void Boss::Shell_Destroyed_check()
{
    if (leftArm.isDead() && rightArm.isDead()) 
    {
        this->shellDestroyed = true;
    }
}
void Boss::reduceHitFlash() {
    if (hitFlashTimer > 0) hitFlashTimer--;
    if (leftArm.hitFlashTimer > 0) leftArm.hitFlashTimer--;
    if (rightArm.hitFlashTimer > 0) rightArm.hitFlashTimer--;

    // 필요하다면 body/shell 별도로 줄이기
}
