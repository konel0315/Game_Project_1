
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
        player.handleInput();  // ���� �Է� ó��
    if (timer % 3 == 0 && !enemies.empty())
        for (auto& e : enemies) e.move();
    
     // �Ѿ� �̵� �� �浹 ó��
    for (auto& e : enemies) e.draw(); 
    if (hasBoss) {
        if (timer % 3 == 0)
        {
            boss.move();  // Ȥ�� ���߿� �������� ���� ���
        }
        boss.draw();
    }
    moveBullet(bullets, enemies, player, *this);    // �� �׸���
    drawUser(player.x, player.y);        // ���� �׸���
    timer++;
    mirrorDirectionToggle = !mirrorDirectionToggle;
    printScreen();
}
