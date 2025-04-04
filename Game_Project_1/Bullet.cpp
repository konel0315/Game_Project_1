#include <iostream>
#include "Screen.h"
#include "Enemy.h"
#include "User.h"  // ���� ������ ó���� ���� ���

using namespace std;

vector<Bullet> InGameBullet;

void moveBullet(vector<Bullet>& bullets, vector<Enemy>& enemies, User& player) 
{

    // 1. ���� ��ġ �����
    for (auto& b : bullets) 
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            if (screen[y][x] == 3 || screen[y][x] == 4)
                screen[y][x] = 0;
    }

    // 2. �浹 üũ �� ��ġ �̵�
    vector<Bullet> nextBullets;
    for (auto& b : bullets) 
    {
        // �Ѿ� �̵�
        b.pos.y += (b.owner == 0) ? -1 : 1;

        int x = b.pos.x, y = b.pos.y;

        // ȭ�� ������ ������ ����
        if (y < 0 || y >= HEIGHT) continue;

        // 3. ���� �Ѿ��� ���� �浹
        if (b.owner == 0&&screen[y][x] == 2) // ���� �Ѿ��̸�
        {
            for (int i = 0; i < enemies.size(); i++)
            {
                if (enemies[i].x == x && enemies[i].y == y)  // screen üũ ��� ���� ��ġ ��
                {
                    enemies[i].takeDamage(1);
                    if (enemies[i].isDead()) {
                        enemies.erase(enemies.begin() + i);
                        i--; // �ε��� ���� (erase �Ŀ��� for���� ���� �����ϵ���)
                    }
                    break; // �� ���� �浹�ϸ� �� Ȯ���� �ʿ� ����
                }
            }
            continue; // �浹������ ���� X
        }

        // 4. �� �Ѿ��� ������ �浹
        if (b.owner == 1)
        {
            if ((player.x == x && player.y == y) || // �÷��̾ �Ѿ˰� ��Ȯ�� ���� ��ġ
                (player.x == x - 1 && player.y == y) || // ����
                (player.x == x + 1 && player.y == y) || // ������
                (player.x == x && player.y == y - 1)) // ����
            {
                player.takeDamage(1); // �÷��̾� ����
                continue;
            }
        }


        // 5. �Ѿ˳��� �浹
        // �Ѿ˳��� �浹 (���� �浹 ����)
        bool collided = false;
        for (auto it = nextBullets.begin(); it != nextBullets.end(); ++it) {
            if (
                (it->pos.x == x && it->pos.y == y && it->owner != b.owner) ||  // ���� ��ġ
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y - 1 && b.owner == 0 && it->owner == 1) || // ������ ������ �� �Ѿ˰� ����
                (it->pos.x == b.pos.x && it->pos.y == b.pos.y + 1 && b.owner == 1 && it->owner == 0)    // �Ʒ����� �ö�� �Ʊ� �Ѿ˰� ����
                ) {
                nextBullets.erase(it);
                collided = true;
                break;
            }
        }

        if (collided) continue;

        // ���� �Ѿ˸� ����
        nextBullets.push_back(b);
    }

    bullets = nextBullets;

    // 6. ���� �Ѿ� �ٽ� �׸���
    for (auto& b : bullets) 
    {
        int x = b.pos.x, y = b.pos.y;
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            screen[y][x] = (b.owner == 0) ? 3 : 4;
    }
}
