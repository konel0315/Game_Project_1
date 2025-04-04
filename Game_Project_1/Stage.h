#pragma once

#include "Enemy.h"
#include "User.h"
#include "Stage_data.h"


class Stage {
private:

    vector<Bullet>& bullets;
    User& player;
    int timer = 0;

public:
    Stage(User& player, vector<Bullet>& bullets);

    void loadStage(vector<vector<stage_data>> &data,int Stage_Number); // 적 배치
    void draw();       // 그리기
};


