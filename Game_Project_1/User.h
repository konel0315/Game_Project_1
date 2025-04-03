#pragma once
#include "Bullet.h"

class User
{
public:
    int x, y;      // ��ġ ���� (pos ����ü ����)
    int health;    // ü�� ����

    // ������
    User(int x, int y, int health)
        : x(x), y(y), health(health) {
    }
    void move(int dx, int dy);
    void shoot();
    void takeDamage(int damage);
    void handleInput();
};