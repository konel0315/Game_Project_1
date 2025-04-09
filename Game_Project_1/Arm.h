#pragma once
#include <vector>
#include "Bullet.h"
using namespace std;

class Arm {
public:
    struct Position {
        int x;
        int y;
    };
    int hitFlashTimer = 0;
    bool isHit = false;
    int health;
    string bulletType;

    // �� �����Ӻ� ��ġ��
    vector<vector<Position>> hitAnimFrames;
    vector<vector<Position>> nonHitAnimFrames;

    int currentFrame;

    Arm(vector<vector<Position>> hitFrames, vector<vector<Position>> nonHitFrames, int health);

    void takeDamage(int damage) {
        health -= damage;
        hitFlashTimer = 2;
    }
    void draw();
    void move();
    void shoot(string bulletType);

    bool isDead() const {
        return health <= 0;
    }
    const vector<Position>& getCurrentHitParts() const {
        return hitAnimFrames[currentFrame];
    }

    const vector<Position>& getCurrentNonHitParts() const {
        return nonHitAnimFrames[currentFrame];
    }

    void nextFrame() {
        currentFrame = (currentFrame + 1) % hitAnimFrames.size(); // ������ ����
    }
};
