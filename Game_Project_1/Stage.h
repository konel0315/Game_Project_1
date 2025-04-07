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

    void loadStage(vector<vector<stage_data>>& data, int Stage_Number); // �� ��ġ

    // �߽� ��ǥ�� ���ڷ� �޵��� ����
    void loadBoss(const BossData& data);

    void draw(); // �׸���
};
