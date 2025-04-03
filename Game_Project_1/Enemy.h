#pragma once
#include "Bullet.h"

class Enemy
{
public:
    int x, y;      // 위치 정보 (pos 구조체 제거)
    int health;    // 체력 정보

    // 생성자
    Enemy(int x, int y, int health)
        : x(x), y(y), health(health) {
    }

    // 적 이동 함수
    void move(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // 총알 발사 함수
    void shoot(Bullet bulletType);

    // 체력 감소 함수
    void takeDamage(int damage) {
        health -= damage;
    }

    // 적이 죽었는지 확인하는 함수
    bool isDead() const {
        return health <= 0;
    }
};
