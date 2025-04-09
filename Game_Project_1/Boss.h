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
    // Boss ���� ������
    void move() override;
    
    // Boss ���� �׸���
     void draw( ) override;
     const vector<Arm::Position>& getCurrentHitParts() const 
     {
         return bodyParts[currentFrame];
     }
     void nextFrame() {
         currentFrame = (currentFrame + 1) % bodyParts.size(); // ������ ����
     }
     // Boss.cpp ������ Ȥ�� �ʱ�ȭ �Լ� ���
     void shoot();
     bool isDead() const {
         return health <= 0;
     }
     void reduceHitFlash();
     
};
