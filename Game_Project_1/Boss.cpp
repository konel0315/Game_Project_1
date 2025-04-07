#include "Boss.h"
#include "Screen.h"

void Boss::draw() {
    // 왼팔 (타격 가능 부위)
    for (int i = 0; i < leftArm.hitParts.size(); ++i) {
        int x = leftArm.hitParts[i].x;
        int y = leftArm.hitParts[i].y;
        screen[y][x] = 2; // ●
    }

    // 왼팔 (타격 불가능 부위)
    for (int i = 0; i < leftArm.nonHitParts.size(); ++i) {
        int x = leftArm.nonHitParts[i].x;
        int y = leftArm.nonHitParts[i].y;
        screen[y][x] = 5; // ◎
    }

    // 오른팔 (타격 가능 부위)
    for (int i = 0; i < rightArm.hitParts.size(); ++i) {
        int x = rightArm.hitParts[i].x;
        int y = rightArm.hitParts[i].y;
        screen[y][x] = 2; // ●
    }

    // 오른팔 (타격 불가능 부위)
    for (int i = 0; i < rightArm.nonHitParts.size(); ++i) {
        int x = rightArm.nonHitParts[i].x;
        int y = rightArm.nonHitParts[i].y;
        screen[y][x] = 5; // ◎
    }

    // 본체 (항상 보임)
    for (int i = 0; i < bodyParts.size(); ++i) {
        int x = bodyParts[i].x;
        int y = bodyParts[i].y;

        if (x == this->x && y == this->y) {
            screen[y][x] = 5; // ◎ (중앙, 비피격)
        }
        else {
            screen[y][x] = 2; // ● (피격 가능)
        }
    }

    // 껍질 (본체에서 떨어진 위치에 있음, 항상 보임)
    if (!shellDestroyed) {
        for (int i = 0; i < shellParts.size(); ++i) {
            int x = shellParts[i].x;
            int y = shellParts[i].y;
            screen[y][x] = 5; // ◎
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