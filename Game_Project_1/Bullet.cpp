#include <iostream>
#include <vector>
#include "Bullet.h"
#include "Screen.h"
#include "Enemy.h"

using namespace std;

vector<Bullet> InGameBullet;

void moveBullet(vector<Bullet>& InGameBullet, vector<Enemy>& enemies)
{
    for (int i = 0; i < InGameBullet.size(); i++)
    {
        int prevX = InGameBullet[i].pos.x;
        int prevY = InGameBullet[i].pos.y;

        // 기존 위치 지우기
        if (prevY >= 0 && prevY < HEIGHT && prevX >= 0 && prevX < WIDTH)
        {
            if (screen[prevY][prevX] == 3 || screen[prevY][prevX] == 4) {
                screen[prevY][prevX] = 0;  // 총알이 지나간 자리를 0으로 변경
            }
        }

        // 총알 이동
        if (InGameBullet[i].owner==0)
        {
            InGameBullet[i].pos.y -= 1;
        }
        else 
        {
            InGameBullet[i].pos.y += 1;
        }

        int newY = InGameBullet[i].pos.y;
        int newX = InGameBullet[i].pos.x;

        // 새 위치가 화면 안에 있으면 출력
        if (newY >= 0 && newY < HEIGHT && newX >= 0 && newX < WIDTH)
        {
            if (screen[newY][newX] == 0) {
                screen[newY][newX] = InGameBullet[i].owner == 0 ? 3 : 4;
            }
            else if (screen[newY][newX] == 2) {  // 적과 충돌했을 경우
                for (int i = 0;i < enemies.size();i++ ) 
                { // 증감 연산 제거
                    if (enemies[i].x == newX && enemies[i].y == newY)
                    {
                        enemies[i].takeDamage(1);

                        if (enemies[i].isDead()) {
                            enemies.erase(enemies.begin() + i);
                        }
                        break;
                    }
                }

               InGameBullet.erase(InGameBullet.begin() + i);
            }
            else {
                InGameBullet.erase(InGameBullet.begin() + i);
            }
        }
    }

    // 화면 밖으로 나간 총알 삭제
    for (auto it = InGameBullet.begin(); it != InGameBullet.end(); ) {
        if (it->pos.y < 0 || it->pos.y >= HEIGHT) {
            it = InGameBullet.erase(it);  // 삭제 후 반환된 위치를 다시 받음
        }
        else {
            ++it;  // 삭제되지 않았다면 다음 요소로 이동
        }
    }


}
