#include "User.h"
#include "Bullet.h"
#include <vector>
#include <conio.h>  // _kbhit(), _getch() 사용을 위한 헤더
#include "Screen.h"

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
    InGameBullet.push_back(Bullet(x, y - 1, 0));  // 유저가 총알 발사 (위쪽으로)
}

void User::takeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        health = 0;
        // 유저가 사망하면 게임 오버 처리 가능
    }
}

void User::handleInput() {
    if (_kbhit()) {  // 키 입력이 있는지 확인
        char key = _getch();  // 키 입력 받기

        switch (key) {
        case 'w': move(0, -1); break;  // 위로 이동
        case 's': move(0, 1); break;   // 아래로 이동
        case 'a': move(-1, 0); break;  // 왼쪽 이동
        case 'd': move(1, 0); break;   // 오른쪽 이동
        case ' ': shoot(); break;      // 스페이스바 입력 시 총알 발사
        }
    }
}
