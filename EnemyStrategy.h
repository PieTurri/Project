//
// Created by piero on 2/21/19.
//

#ifndef PROJECT_ENEMYSTRATEGY_H
#define PROJECT_ENEMYSTRATEGY_H

#include <iostream>
#include "TileMap.h"
#include <SFML/Graphics.hpp>

using namespace std;

class EnemyStrategy {

public:

    EnemyStrategy();

    explicit EnemyStrategy(Sprite &sprite);

    virtual EnemyStrategy * changeStrategy() = 0;

    virtual ~EnemyStrategy();

    virtual void setDirection(TileMap &map, Sprite &Esprite) = 0;

    void updateMovement(TileMap &map,Sprite &sprite);

    bool isFiringStrategy();

protected:

    Vector2f pos_load;

    bool firingStrategy;

    int direction;

    bool didEnemyMove;

    Time timeEnemy;
    Clock clockEnemy;
};

#endif //PROJECT_ENEMYSTRATEGY_H
