#pragma once
#include "Enemy.h"
#include <iostream>
#include "Arm.h"

class Boss : public Enemy
{
public:
    Arm leftArm;
    Arm rightArm;
    int currentFrame=0;
    vector<vector<Arm::Position>> shellParts;
    vector<vector<Arm::Position>> bodyParts;
    bool shellDestroyed = false;
    Boss(int startX, int startY, vector<int> directions, int health, string type)
        : Enemy(startX, startY, directions, health, type),
        leftArm({}, {},0), rightArm({}, {},0) {
    }
    void Shell_Destroyed_check();
    // Boss 전용 움직임
    void move() override;
    
    // Boss 전용 그리기
     void draw( ) override;
     const vector<Arm::Position>& getCurrentHitParts() const 
     {
         return bodyParts[currentFrame];
     }
     void nextFrame() {
         currentFrame = (currentFrame + 1) % bodyParts.size(); // 프레임 루프
     }
     // Boss.cpp 생성자 혹은 초기화 함수 등에서
     void shoot();
     bool isDead() const {
         return health <= 0;
     }
     void reduceHitFlash();
     
};
