#pragma once
#include "Arm.h"
#include <vector>
#include <string>
using namespace std;

struct RelativePos {
    int dx;
    int dy;
};

struct BossData {
    int startX;
    int startY;
    vector<int> directions;
    int BosHealth;
    int RightHealth;
    int LeftHealth;
    string type;

    vector<RelativePos> leftArm_hitRel;
    vector<RelativePos> leftArm_nonHitRel;

    vector<RelativePos> rightArm_hitRel;
    vector<RelativePos> rightArm_nonHitRel;

    vector<RelativePos> shellRel;
    vector<RelativePos> bodyRel;
};


extern vector<BossData> BossTemplates;
