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

    int health;
    string bulletType;

    // 각 프레임별 위치들
    vector<vector<Position>> hitAnimFrames;
    vector<vector<Position>> nonHitAnimFrames;

    int currentFrame;

    Arm(vector<vector<Position>> hitFrames, vector<vector<Position>> nonHitFrames, int health);

    void takeDamage(int damage) {
        health -= damage;
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
        currentFrame = (currentFrame + 1) % hitAnimFrames.size(); // 프레임 루프
    }
};
