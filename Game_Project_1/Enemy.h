#pragma once
#include "Bullet.h"

class Enemy
{
public:
    int x, y;      // 위치 정보 (pos 구조체 제거)
    int health;    // 체력 정보
    int previousX, previousY;  // 이전 프레임의 위치 저장
    vector<int> directionArray;
    int dirIndex = 0;
    int moveCount = 0;
    int hitFlashTimer = 0;
    bool isHit = false;
    string Bulletype;
    Enemy(int startX, int startY, vector<int> directions, int health,string type)
        : x(startX), y(startY), directionArray(directions), previousX(startX), health(health), previousY(startY),Bulletype(type){}
    virtual ~Enemy() {}
    virtual void move();

    virtual void draw();
    // 생성자

    // 총알 발사 함수
    void shoot(string bulletType);
    // 체력 감소 함수
    void takeDamage(int damage) {
        health -= damage;
        hitFlashTimer = 2;
    }

    // 적이 죽었는지 확인하는 함수
    bool isDead() const {
        return health <= 0;
    }
};
