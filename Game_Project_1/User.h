#pragma once
#include "Bullet.h"

class User
{
public:
    int x, y;      // 위치 정보 (pos 구조체 제거)
    int health;    // 체력 정보

    // 생성자
    User(int x, int y, int health)
        : x(x), y(y), health(health) {
    }
    void move(int dx, int dy);
    void shoot();
    void takeDamage(int damage);
    void handleInput();
};