#pragma once
#include "Bullet.h"

class Enemy
{
public:
    int x, y;      // ��ġ ���� (pos ����ü ����)
    int health;    // ü�� ����

    // ������
    Enemy(int x, int y, int health)
        : x(x), y(y), health(health) {
    }

    // �Ѿ� �߻� �Լ�
    void shoot(Bullet bulletType);

    // ü�� ���� �Լ�
    void takeDamage(int damage) {
        health -= damage;
    }

    // ���� �׾����� Ȯ���ϴ� �Լ�
    bool isDead() const {
        return health <= 0;
    }
};
