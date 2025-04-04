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

    Enemy(int startX, int startY, vector<int> directions, int health)
        : x(startX), y(startY), directionArray(directions), previousX(startX), health(health), previousY(startY){}

    void move();

    void draw();
    // ������

    // �Ѿ� �߻� �Լ�
    void shoot(/*Bullet bulletType*/);
    // ü�� ���� �Լ�
    void takeDamage(int damage) {
        health -= damage;
    }

    // ���� �׾����� Ȯ���ϴ� �Լ�
    bool isDead() const {
        return health <= 0;
    }
};
