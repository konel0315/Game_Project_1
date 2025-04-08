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

    vector<vector<RelativePos>> leftArm_hitRel;
    vector<vector<RelativePos>> leftArm_nonHitRel;

    vector<vector<RelativePos>> rightArm_hitRel;
    vector<vector<RelativePos>>rightArm_nonHitRel;

    vector<vector<RelativePos>> shellRel;
    vector<vector<RelativePos>> bodyRel;
};


extern vector<BossData> BossTemplates;
