
#include "Stage.h"
#include "Screen.h"
#include <thread>


Stage::Stage(User& p, vector<Bullet>& b) : player(p), bullets(b) {}

void Stage::loadStage(vector<vector<stage_data>> &data,int Stage_Number)
{
    int index = Stage_Number - 1;
    enemies.clear();
    for (int i = 0;i < data[index].size();i++)
    {
        enemies.push_back(Enemy(
            data[index ][i].enemy_x,
            data[index ][i].enemy_y,
            data[index][i].pattern,
            data[index][i].enemy_health,
            data[index][i].bulletype
        ));
    }
}

vector<vector<Arm::Position>> convertToAbsolute(int baseX, int baseY, const vector<vector<RelativePos>>& rels) {
    vector<vector<Arm::Position>> result;
    for (const auto& frame : rels) {
        vector<Arm::Position> convertedFrame;
        for (const auto& rel : frame) {
            convertedFrame.push_back({ baseX + rel.dx, baseY + rel.dy });
        }
        result.push_back(convertedFrame);
    }
    return result;
}



void Stage::loadBoss(const BossData& data) {
    int cx = data.startX;
    int cy = data.startY;

    boss = Boss(cx, cy, data.directions, data.BosHealth, data.type);

    boss.leftArm = Arm(
        convertToAbsolute(cx, cy, data.leftArm_hitRel),
        convertToAbsolute(cx, cy, data.leftArm_nonHitRel),
        data.LeftHealth
    );

    boss.rightArm = Arm(
        convertToAbsolute(cx, cy, data.rightArm_hitRel),
        convertToAbsolute(cx, cy, data.rightArm_nonHitRel),
        data.RightHealth
    );

    boss.shellParts = convertToAbsolute(cx, cy, data.shellRel);
    boss.bodyParts = convertToAbsolute(cx, cy, data.bodyRel);

    hasBoss = true;
}





void Stage::draw() {
    clearScreen();
        player.handleInput();  // 유저 입력 처리
    if (timer % 3 == 0 && !enemies.empty())
        for (auto& e : enemies) e.move();
    
     // 총알 이동 및 충돌 처리
    for (auto& e : enemies) e.draw(); 
    if (hasBoss) {
        if (timer % 3 == 0)
        {
            boss.move();  // 혹시 나중에 움직임이 들어가면 대비
        }
        boss.draw();
    }
    moveBullet(bullets, enemies, player, *this);    // 적 그리기
    drawUser(player.x, player.y);        // 유저 그리기
    timer++;
    mirrorDirectionToggle = !mirrorDirectionToggle;
    printScreen();
}
