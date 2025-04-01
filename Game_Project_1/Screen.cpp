#include <iostream>
#include <vector>
#include <algorithm>
#include "Screen.h"

using namespace std;

int screen[HEIGHT][WIDTH];  // ȭ���� int �迭�� ����
vector<Bullet> InGameBullet;

void clearScreen() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = 0;  // ȭ���� 0���� �ʱ�ȭ (��ĭ '��')
        }
    }
}

void drawUser(int x, int y) {
    screen[y][x] = 1;  // ����� ��ġ '��'
    screen[y + 1][x - 1] = 1;
    screen[y + 1][x] = 1;
    screen[y + 1][x + 1] = 1;
}

void drawEnemy(int x, int y) {
    screen[y][x - 1] = 2;  // �� ��ġ '��'
    screen[y][x] = 2;
    screen[y][x + 1] = 2;
}

void moveBullet(vector<Bullet>& InGameBullet, bool isUserBullet) {
    for (int i = 0; i < InGameBullet.size(); i++) {
        int prevX = InGameBullet[i].pos.x;
        int prevY = InGameBullet[i].pos.y;

        // ���� ��ġ �����
        if (prevY >= 0 && prevY < HEIGHT && prevX >= 0 && prevX < WIDTH) {
            screen[prevY][prevX] = 0;  // �Ѿ��� ������ �ڸ��� 0���� ����
        }

        // �Ѿ� �̵�
        if (isUserBullet) {
            InGameBullet[i].pos.y--;
        }
        else {
            InGameBullet[i].pos.y++;
        }

        int newY = InGameBullet[i].pos.y;
        int newX = InGameBullet[i].pos.x;

        // �� ��ġ�� ȭ�� �ȿ� ������ ���
        if (newY >= 0 && newY < HEIGHT && newX >= 0 && newX < WIDTH) {
            screen[newY][newX] = isUserBullet ? 3 : 4;  // User Bullet�� 3, Enemy Bullet�� 4�� ����
        }
    }

    // ȭ�� ������ ���� �Ѿ� ����
    InGameBullet.erase(remove_if(InGameBullet.begin(), InGameBullet.end(), [](Bullet& b) {
        return b.pos.y < 0 || b.pos.y >= HEIGHT;
        }), InGameBullet.end());
}

void printScreen() {
    system("cls");  // �ܼ��� �ʱ�ȭ

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // ���� ���� ���� ����� ���� ����
            switch (screen[i][j]) {
            case 0: cout << "��"; break;  // ��ĭ
            case 1: cout << "��"; break;  // �����
            case 2: cout << "��"; break;  // ��
            case 3: cout << "��"; break;  // ����� �Ѿ�
            case 4: cout << "��"; break;  // �� �Ѿ�
            default: cout << " "; break;
            }
        }
        cout << endl;
    }
}
