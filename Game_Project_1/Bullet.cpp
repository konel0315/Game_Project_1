#include <iostream>
#include "Screen.h"
#include "Enemy.h"
#include "User.h"  // 유저 데미지 처리를 위한 헤더

using namespace std;

vector<Bullet> InGameBullet;

void moveBullet(vector<Bullet>& bullets, vector<Enemy>& enemies, User& player) 
{
 
    // 1. 이전 위치 지우기
    for (auto& b : bullets) 
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            if (screen[y][x] == 3 || screen[y][x] == 4)
                screen[y][x] = 0;
    }

    // 2. 충돌 체크 및 위치 이동
    vector<Bullet> nextBullets;
    for (auto& b : bullets) 
    {
        // 총알 이동
        b.pos.y += (b.owner == 0) ? -1 : 1;

        int x = b.pos.x, y = b.pos.y;

        // 화면 밖으로 나가면 삭제
        if (y < 0 || y >= HEIGHT) continue;

        // 3. 유저 총알이 적과 충돌
        if (b.owner == 0 && screen[y][x] == 2) 
        {
            for (int i = 0; i < enemies.size(); i++) 
            {
                if ((enemies[i].x == x && enemies[i].y == y) || (enemies[i].x == x && enemies[i].y - 1 == y)) 
                {
                    enemies[i].takeDamage(1);
                    if (enemies[i].isDead())
                        enemies.erase(enemies.begin() + i);
                    break;
                }
            }
            continue; // 충돌했으니 저장 X
        }

        // 4. 적 총알이 유저와 충돌
        if (b.owner == 1)
        {
            if ((player.x == x && player.y == y - 1) || (player.x == x - 1 && player.y == y) || (player.x == x + 1 && player.y == y)) {

                player.takeDamage(1); // 네가 만들었으면 이거 쓰고
                continue;
            }
        }

        // 5. 총알끼리 충돌
        // 총알끼리 충돌 (교차 충돌 포함)
        bool collided = false;
        for (auto it = nextBullets.begin(); it != nextBullets.end(); ++it) {
            if (
                (it->pos.x == x && it->pos.y == y && it->owner != b.owner) ||  // 같은 위치
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y - 1 && b.owner == 0 && it->owner == 1) || // 위에서 내려온 적 총알과 교차
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y + 1 && b.owner == 1 && it->owner == 0)    // 아래에서 올라온 아군 총알과 교차
                ) {
                nextBullets.erase(it);
                collided = true;
                break;
            }
        }

        if (collided) continue;

        // 남은 총알만 유지
        nextBullets.push_back(b);
    }

    bullets = nextBullets;

    // 6. 남은 총알 다시 그리기
    for (auto& b : bullets) 
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            screen[y][x] = (b.owner == 0) ? 3 : 4;
    }
}
