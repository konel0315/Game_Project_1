#pragma once
#include "Bullet.h"

class Enemy
{
public:
    int x, y;      // ��ġ ���� (pos ����ü ����)
    int health;    // ü�� ����
    int previousX, previousY;  // ���� �������� ��ġ ����
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
    // ������

    // �Ѿ� �߻� �Լ�
    void shoot(string bulletType);
    // ü�� ���� �Լ�
    void takeDamage(int damage) {
        health -= damage;
        hitFlashTimer = 2;
    }

    // ���� �׾����� Ȯ���ϴ� �Լ�
    bool isDead() const {
        return health <= 0;
    }
};
