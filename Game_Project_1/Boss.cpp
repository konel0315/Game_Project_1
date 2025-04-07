#include "Boss.h"
#include "Screen.h"

void Boss::draw() {
    // ���� (Ÿ�� ���� ����)
    for (int i = 0; i < leftArm.hitParts.size(); ++i) {
        int x = leftArm.hitParts[i].x;
        int y = leftArm.hitParts[i].y;
        screen[y][x] = 2; // ��
    }

    // ���� (Ÿ�� �Ұ��� ����)
    for (int i = 0; i < leftArm.nonHitParts.size(); ++i) {
        int x = leftArm.nonHitParts[i].x;
        int y = leftArm.nonHitParts[i].y;
        screen[y][x] = 5; // ��
    }

    // ������ (Ÿ�� ���� ����)
    for (int i = 0; i < rightArm.hitParts.size(); ++i) {
        int x = rightArm.hitParts[i].x;
        int y = rightArm.hitParts[i].y;
        screen[y][x] = 2; // ��
    }

    // ������ (Ÿ�� �Ұ��� ����)
    for (int i = 0; i < rightArm.nonHitParts.size(); ++i) {
        int x = rightArm.nonHitParts[i].x;
        int y = rightArm.nonHitParts[i].y;
        screen[y][x] = 5; // ��
    }

    // ��ü (�׻� ����)
    for (int i = 0; i < bodyParts.size(); ++i) {
        int x = bodyParts[i].x;
        int y = bodyParts[i].y;

        if (x == this->x && y == this->y) {
            screen[y][x] = 5; // �� (�߾�, ���ǰ�)
        }
        else {
            screen[y][x] = 2; // �� (�ǰ� ����)
        }
    }

    // ���� (��ü���� ������ ��ġ�� ����, �׻� ����)
    if (!shellDestroyed) {
        for (int i = 0; i < shellParts.size(); ++i) {
            int x = shellParts[i].x;
            int y = shellParts[i].y;
            screen[y][x] = 5; // ��
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