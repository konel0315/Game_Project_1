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
    vector<Position> hitParts;      // 피격 가능한 부분
    vector<Position> nonHitParts;   // 피격 불가능한 장식 등

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
