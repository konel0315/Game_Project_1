#pragma once

#include "Enemy.h"
#include "User.h"
#include "Stage_data.h"
#include "Boss.h"
#include "BossData.h"

class Stage {
private:
    vector<Bullet>& bullets;
    User& player;
    int timer = 0;
    

public:
    bool hasBoss = false;
    bool mirrorDirectionToggle = false;
    Boss boss = Boss(0, 0, {}, 0, "");
    Stage(User& player, vector<Bullet>& bullets);

    void loadStage(vector<vector<stage_data>>& data, int Stage_Number); // 적 배치

    // 중심 좌표를 인자로 받도록 수정
    void loadBoss(const BossData& data);

    void draw(); // 그리기
};
