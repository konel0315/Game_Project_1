#pragma once
#include "Enemy.h"
#include <iostream>
#include "Arm.h"

class Boss : public Enemy
{
public:
    Arm leftArm;
    Arm rightArm;
    vector<Arm::Position> shellParts;
    vector<Arm::Position> bodyParts;
    bool shellDestroyed = false;
    Boss(int startX, int startY, vector<int> directions, int health, string type)
        : Enemy(startX, startY, directions, health, type),
        leftArm({}, {},0), rightArm({}, {},0) {
    }
    void Shell_Destroyed_check();
    // Boss 전용 움직임
     void move() override{}

    // Boss 전용 그리기
     void draw( ) override;
};
