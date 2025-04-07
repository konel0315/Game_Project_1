#include <iostream>
#include "Screen.h"
#include "Enemy.h"
#include "User.h"  // 유저 데미지 처리를 위한 헤더
#include "Stage.h"

using namespace std;

vector<Bullet> InGameBullet;
void moveBullet(vector<Bullet>& bullets, vector<Enemy>& enemies, User& player, Stage& stage)
{
    // 1. 이전 위치 지우기
    for (auto& b : bullets)
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            if (screen[y][x] == 3 || screen[y][x] == 4)
                screen[y][x] = 0;
    }

    vector<Bullet> nextBullets;
    for (auto& b : bullets)
    {
        if (b.type == "mirror" && b.dx == 0)
        {
            b.dx = stage.mirrorDirectionToggle ? 1 : -1;

        }
        int x = b.pos.x;
        int y = b.pos.y;

        if (b.type == "basic")
        {
            y += (b.owner == 0) ? -1 : 1;
        }
        else if (b.type == "mirror") {
            x += b.dx;
            y += b.dy + rand() % 3;  // 0, 1, 2 사이의 랜덤값을 y에 더함
        
            // 벽 반사
            if (x <= 0 || x >= WIDTH - 1)
                b.dx *= -1;
           /* if (y <= 0 || y >= HEIGHT - 1)
                b.dy *= -1;*/
        }

        b.pos.x = x;
        b.pos.y = y;

        // 화면 밖이면 삭제
        if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH) continue;

        // === 유저 총알이 적에게 충돌 ===
        if (b.owner == 0) {
            // 적이 없다면 (보스만 존재하는 경우)
            if (enemies.empty()) {
                if (screen[y][x] == 2) {  // 보스도 2로 변경
                    // 왼팔 타격 체크
                    for (int i = 0; i < stage.boss.leftArm.hitParts.size(); i++) {
                        if (stage.boss.leftArm.hitParts[i].x == x && stage.boss.leftArm.hitParts[i].y == y) {
                            stage.boss.leftArm.takeDamage(1);
                            if (stage.boss.leftArm.isDead())
                            {
                                stage.boss.leftArm.EraseArm();
                                stage.boss.Shell_Destroyed_check();
                            }
                            break;
                        }
                    }

                    // 오른팔 타격 체크
                    for (int i = 0; i < stage.boss.rightArm.hitParts.size(); i++) {
                        if (stage.boss.rightArm.hitParts[i].x == x && stage.boss.rightArm.hitParts[i].y == y) {
                            stage.boss.rightArm.takeDamage(1);
                            if(stage.boss.rightArm.isDead())
                            {
                                stage.boss.rightArm.EraseArm();
                                stage.boss.Shell_Destroyed_check();
                            }
                            break;
                        }
                    }

                    // 본체 타격 (팔이 모두 파괴된 경우에만)
                    if (stage.boss.leftArm.hitParts.empty() && stage.boss.rightArm.hitParts.empty()) {
                        stage.boss.shellDestroyed = true;
                        for (int i = 0; i < stage.boss.bodyParts.size(); i++) {
                            if (stage.boss.bodyParts[i].x == x && stage.boss.bodyParts[i].y == y) {
                                stage.boss.takeDamage(1);
                                break;
                            }
                        }
                    }
                    continue;
                }
            }
            // === 유저 총알이 일반 적에게 충돌 ===
            else if (screen[y][x] == 2) {
                for (int i = 0; i < enemies.size(); i++) {
                    if (enemies[i].x == x && enemies[i].y == y) {
                        enemies[i].takeDamage(1);
                        if (enemies[i].isDead()) {
                            enemies.erase(enemies.begin() + i);
                            i--;
                        }
                        break;
                    }
                }
                continue;
            }
        }



        // === 적 총알이 유저에게 충돌 ===
        if (b.owner == 1)
        {
            if ((player.x == x && player.y == y) ||
                (player.x == x - 1 && player.y == y) ||
                (player.x == x + 1 && player.y == y) ||
                (player.x == x && player.y == y - 1))
            {
                player.takeDamage(1);
                continue;
            }
        }

        // === 총알끼리 충돌 ===
        bool collided = false;
        for (auto it = nextBullets.begin(); it != nextBullets.end(); ++it) {
            if (
                (it->pos.x == x && it->pos.y == y && it->owner != b.owner) ||
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y - 1 && b.owner == 0 && it->owner == 1) ||
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y + 1 && b.owner == 1 && it->owner == 0)
                ) {
                nextBullets.erase(it);
                collided = true;
                break;
            }
        }

        if (collided) continue;

        nextBullets.push_back(b);
    }

    bullets = nextBullets;

    // 6. 화면에 총알 다시 그리기
    for (auto& b : bullets)
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            screen[y][x] = (b.owner == 0) ? 3 : 4;
    }
}
