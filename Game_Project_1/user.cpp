#include "User.h"
#include "Bullet.h"
#include <vector>
#include <conio.h>  // _kbhit(), _getch() ����� ���� ���
#include "Screen.h"

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
    InGameBullet.push_back(Bullet(x, y - 1, 0));  // ������ �Ѿ� �߻� (��������)
}

void User::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
        // ������ ����ϸ� ���� ���� ó�� ����
    }
}

void User::handleInput() {
    if (_kbhit()) {  // Ű �Է��� �ִ��� Ȯ��
        char key = _getch();  // Ű �Է� �ޱ�

        switch (key) {
        case 'w': move(0, -1); break;  // ���� �̵�
        case 's': move(0, 1); break;   // �Ʒ��� �̵�
        case 'a': move(-1, 0); break;  // ���� �̵�
        case 'd': move(1, 0); break;   // ������ �̵�
        case ' ': shoot(); break;      // �����̽��� �Է� �� �Ѿ� �߻�
        }
    }
}
