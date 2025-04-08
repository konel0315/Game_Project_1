#include "Arm.h"
#include "Screen.h"

Arm::Arm(vector<vector<Position>> hitFrames, vector<vector<Position>> nonHitFrames, int health)
    : hitAnimFrames(hitFrames), nonHitAnimFrames(nonHitFrames), health(health), currentFrame(0) {
}


void Arm::draw() {
    for (const auto& pos : hitAnimFrames[currentFrame]) {
        screen[pos.y][pos.x] = 1;
    }
    for (const auto& pos : nonHitAnimFrames[currentFrame]) {
        screen[pos.y][pos.x] = 1;
    }
}

void Arm::move() {
    currentFrame = (currentFrame + 1) % hitAnimFrames.size();
    shoot("mirror");
}

void Arm::shoot(string bulletType) {
    const auto& frame = nonHitAnimFrames[currentFrame];
    if (frame.size() > 6) {
        InGameBullet.push_back(Bullet(frame[6].x, frame[6].y + 1, 1, bulletType));
    }
}
