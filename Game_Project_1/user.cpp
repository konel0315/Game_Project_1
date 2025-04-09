#include "User.h"
#include <conio.h>  // _kbhit(), _getch() 사용을 위한 헤더
#include "Screen.h"
#include <iostream>


extern vector<Bullet> InGameBullet;  // 전역 총알 벡터

void User::move(int dx, int dy) {
    x += dx;
    y += dy;

    // 화면 밖으로 나가지 않도록 제한
    if (x < 1) x = 1;
    if (x >= WIDTH-1) x = WIDTH-2 ;

    // 높이의 절반 이하로 이동 불가능하도록 제한
    if (y < HEIGHT / 2) y = HEIGHT / 2;
    if (y >= HEIGHT) y = HEIGHT - 1;
}


void User::shoot() {
    //cout << "총알 추가 전, 현재 총알 개수: " << InGameBullet.size() << endl;
    InGameBullet.push_back(Bullet(x, y - 2, 0));
    //cout << "총알 추가 후, 현재 총알 개수: " << InGameBullet.size() << endl;
    //cin.get();  // 멈춰서 확인
}

void User::takeDamage(int damage) {
    health -= damage;
    hitFlashTimer = 2;
    if (health <= 0) {
        health = 0;
        // 유저가 사망하면 게임 오버 처리 가능
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

    // 쿨타임 감소
    if (shootCooldown > 0) {
        shootCooldown--;
    }
}

