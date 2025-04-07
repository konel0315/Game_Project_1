#include "Arm.h"
#include "Screen.h"

Arm::Arm(vector<Position> hit, vector<Position> nonHit,int health)
    : hitParts(hit), nonHitParts(nonHit),health(health){
}
void Arm::EraseArm()
{
    hitParts.clear();
    nonHitParts.clear();
}

void Arm::draw()
{
    for (int i = 0; i < hitParts.size(); ++i) {
        screen[hitParts[i].y][hitParts[i].x] = 1;
    }
    for (int i = 0; i < nonHitParts.size(); ++i) {
        screen[nonHitParts[i].y][nonHitParts[i].x] = 1;
    }
}
void Arm :: move()
{
    shoot("mirror");
}
void Arm::shoot(string bulletType)
{
    InGameBullet.push_back(Bullet(nonHitParts[6].x, nonHitParts[6].y + 1, 1, bulletType));

}