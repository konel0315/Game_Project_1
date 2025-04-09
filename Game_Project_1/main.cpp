#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Stage.h"

// �Լ� ����


int main() {
    system("mode con cols=100 lines=30");

    while (true) {
        showStartScreen(); // ���� ȭ�� �����ֱ�

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

                if (player.health <= 0) { // ���� ��� üũ
                    showGameOverScreen(); // ���� ���� ȭ��
                    goto restart; // ó������ �ٽ� ����
                }
            }

            stage_num++;
            if (stage_num == Every_Stage.size() + 1) {
                clear = 1;
            }
        }

        showClearScreen(); // Ŭ���� ȭ��
    restart:
        delete stage; // �޸� ����
    }

    return 0;
}
