#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Stage.h"


int main() {
   system("mode con cols=100 lines=30");

   User player(WIDTH / 2, HEIGHT - 2, 3);

   Stage* stage = new Stage(player, InGameBullet);
   stage->loadStage(Every_Stage, 2);            // 아무 적도 없음
   stage->loadBoss(BossTemplates[0]);           // 보스만 소환

   while (enemies.size()!=0|| stage->hasBoss) {
       gotoxy(0, 0);
       stage->draw();
       
       this_thread::sleep_for(chrono::milliseconds(50));
   }

   return 0;
}
