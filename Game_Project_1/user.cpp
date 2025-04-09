#include "User.h"
#include <conio.h>  // _kbhit(), _getch() ����� ���� ���
#include "Screen.h"
#include <iostream>


extern vector<Bullet> InGameBullet;  // ���� �Ѿ� ����

void User::move(int dx, int dy) {
    x += dx;
    y += dy;

    // ȭ�� ������ ������ �ʵ��� ����
    if (x < 1) x = 1;
    if (x >= WIDTH-1) x = WIDTH-2 ;

    // ������ ���� ���Ϸ� �̵� �Ұ����ϵ��� ����
    if (y < HEIGHT / 2) y = HEIGHT / 2;
    if (y >= HEIGHT) y = HEIGHT - 1;
}


void User::shoot() {
    //cout << "�Ѿ� �߰� ��, ���� �Ѿ� ����: " << InGameBullet.size() << endl;
    InGameBullet.push_back(Bullet(x, y - 2, 0));
    //cout << "�Ѿ� �߰� ��, ���� �Ѿ� ����: " << InGameBullet.size() << endl;
    //cin.get();  // ���缭 Ȯ��
}

void User::takeDamage(int damage) {
    health -= damage;
    hitFlashTimer = 2;
    if (health <= 0) {
        health = 0;
        // ������ ����ϸ� ���� ���� ó�� ����
    }
}

void User::handleInput() {
    if (_kbhit()) {
        char key = _getch();

        switch (key) {
        case 'w': move(0, -1); break;
        case 's': move(0, 1); break;
        case 'a': move(-1, 0); break;
        case 'd': move(1, 0); break;

        case ' ':
            if (shootCooldown == 0) {
                shoot();
                shootCooldown = maxCooldown;
            }
            break;
        }
    }

    // ��Ÿ�� ����
    if (shootCooldown > 0) {
        shootCooldown--;
    }
}

