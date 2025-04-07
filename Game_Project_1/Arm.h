#pragma once
#include <vector>
using namespace std;

class Arm {
public:
    struct Position {
        int x;
        int y;
    };
    int health;
    vector<Position> hitParts;      // �ǰ� ������ �κ�
    vector<Position> nonHitParts;   // �ǰ� �Ұ����� ��� ��

    Arm(vector<Position> hit, vector<Position> nonHit,int health);

    void takeDamage(int damage) {
        health -= damage;
    }
    void draw();
    bool isDead() const {
        return health <= 0;
    }
    void EraseArm();
};
