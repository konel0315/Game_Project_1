#include <iostream>
#include <thread>
#include <chrono>
#include "Screen.h"
#include "Stage.h"
using namespace std;

int main() {
    system("mode con cols=100 lines=30");

    User player(WIDTH / 2, HEIGHT - 2, 3);

    Stage* stage = new Stage(player, InGameBullet);
    stage->loadStage(Every_Stage,1);
    while (enemies.size()!=0) {
        gotoxy(0, 0);
        stage->update();
        stage->draw();
        
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    return 0;
}
