#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Stage.h"

int clear = 0;
int main() {
   system("mode con cols=100 lines=30");
   int stage_num = 1;
   User player(WIDTH / 2, HEIGHT - 2, 30);

   Stage* stage = new Stage(player, InGameBullet);
   while (clear == 0)
   {
       stage->loadStage(Every_Stage, stage_num);
       if (stage_num==2)
       {
           stage->loadBoss(BossTemplates[0]);           // 보스만 소환
       }
       while (enemies.size() != 0 || stage->hasBoss) {
           gotoxy(0, 0);
           stage->draw();

           this_thread::sleep_for(chrono::milliseconds(50));
       }
       stage_num++;
       if (stage_num == Every_Stage.size()+1) 
       {
           clear = 1;
       }
   }
   return 0;
}
