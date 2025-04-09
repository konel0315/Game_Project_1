#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Stage.h"

// 함수 선언


int main() {
    system("mode con cols=100 lines=30");

    while (true) {
        showStartScreen(); // 시작 화면 보여주기

        int stage_num = 1;
        int clear = 0;
        User player(WIDTH / 2, HEIGHT - 2, 30);
        Stage* stage = new Stage(player, InGameBullet);

        while (clear == 0) {
            stage->loadStage(Every_Stage, stage_num);
            if (stage_num == 2) {
                stage->loadBoss(BossTemplates[0]);
            }

            while (enemies.size() != 0 || stage->hasBoss) {
                gotoxy(0, 0);
                stage->draw();
                std::this_thread::sleep_for(std::chrono::milliseconds(50));

                if (player.health <= 0) { // 유저 사망 체크
                    showGameOverScreen(); // 게임 오버 화면
                    goto restart; // 처음부터 다시 시작
                }
            }

            stage_num++;
            if (stage_num == Every_Stage.size() + 1) {
                clear = 1;
            }
        }

        showClearScreen(); // 클리어 화면
    restart:
        delete stage; // 메모리 정리
    }

    return 0;
}
