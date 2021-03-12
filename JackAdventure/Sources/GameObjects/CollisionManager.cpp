#include "CollisionManager.h"

void CollisionManager::addObj(HitBox* hitBox)
{
    m_listObj.push_back(hitBox);
}

bool CollisionManager::checkCollision(HitBox* a, HitBox* b)
{
    return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

void CollisionManager::Update()
{
    for (auto a : m_listObj) {
        if (a->isAlive() == false) continue;
        for (auto b : m_listObj) {
            if (b->isAlive() == false) continue;

            if (a->getTag() == b->getTag()) continue;
            if (!checkCollision(a, b)) continue;

            if (a->getTag() == PLAYER && b->getTag() == CREEP) {
                a->setAlive(false);
                b->setAlive(false);
            }

            if (a->getTag() == PLAYER && b->getTag() == BOSS) {
                a->setAlive(false);
            }
            
            if (a->getTag() == PLAYER && b->getTag() == BOSS_Bullet) {
                a->setAlive(false);
                b->setAlive(false);
            }

            if (a->getTag() == CREEP && b->getTag() == BOSS_Bullet) {
                a->setAlive(false);
                b->setAlive(false);
            }
            if (a->getTag() == CREEP && b->getTag() == BOSS) {
                a->setAlive(false);
                b->setAlive(false);
            }
        }
    }
}
