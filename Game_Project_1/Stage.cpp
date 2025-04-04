
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
            data[index][i].enemy_health
        ));
    }
}

void Stage::update() {

    if (timer % 2 == 0)
        player.handleInput();

    if (timer % 3 == 0 && !enemies.empty())
        for (auto& e : enemies) e.move();

    
    timer++;
}

void Stage::draw() {
    clearScreen();
    moveBullet(bullets, enemies, player);
    for (auto& e : enemies) e.draw();
    drawUser(player.x, player.y);
    printScreen();
}
