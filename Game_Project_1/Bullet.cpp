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

        // ���� ��ġ �����
        if (prevY >= 0 && prevY < HEIGHT && prevX >= 0 && prevX < WIDTH)
        {
            if (screen[prevY][prevX] == 3 || screen[prevY][prevX] == 4) {
                screen[prevY][prevX] = 0;  // �Ѿ��� ������ �ڸ��� 0���� ����
            }
        }

        // �Ѿ� �̵�
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

        // �� ��ġ�� ȭ�� �ȿ� ������ ���
        if (newY >= 0 && newY < HEIGHT && newX >= 0 && newX < WIDTH)
        {
            if (screen[newY][newX] == 0) {
                screen[newY][newX] = InGameBullet[i].owner == 0 ? 3 : 4;
            }
            else if (screen[newY][newX] == 2) {  // ���� �浹���� ���
                for (int i = 0;i < enemies.size();i++ ) 
                { // ���� ���� ����
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

    // ȭ�� ������ ���� �Ѿ� ����
    for (auto it = InGameBullet.begin(); it != InGameBullet.end(); ) {
        if (it->pos.y < 0 || it->pos.y >= HEIGHT) {
            it = InGameBullet.erase(it);  // ���� �� ��ȯ�� ��ġ�� �ٽ� ����
        }
        else {
            ++it;  // �������� �ʾҴٸ� ���� ��ҷ� �̵�
        }
    }


}
