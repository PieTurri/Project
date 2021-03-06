//
// Created by piero on 10/6/18.
//

#include "TileMap.h"

using namespace std;

TileMap::TileMap() {}

TileMap::~TileMap() {
}

void TileMap::updateRoomsItems() {

    if(!items.empty()) {
        for (int i = 0; i < items.size(); i++) {
            if(items[i].getAnimation())
                items[i].animate();
        }
    }
}

void TileMap::setItemsProperty() {

    itemTextFile.open("elementiMappa");

    int i=0;
    int j=0;
    int k=0;

    Item item("mercante/frame-", 5);

    items.push_back(item);
    items[j].setPosition(Vector2f(960,128));
    tiles[960/32][128/32].setHeroWalkability(false);
    tiles[960/32][128/32].setEnemyWalkability(false);
    items[j].setAnimation(true);
    j++;

    while(itemTextFile>>i) {

        Item item1("torcia/frame-", 32);

        if(i!=0){

            items.push_back(item1);
            items[j].setPosition(getTileCoordinates(k));
            items[j].setAnimation(true);
            switch(i){
                case 1:
                    items[j].rotate(-30);
                    items[j].setOrigin(-8,0);
                    break;
                case 2:
                    items[j].rotate(+30);
                    items[j].setOrigin(8,0);
                    break;
                case 3:
                    items[j].rotate(180);
                    items[j].setOrigin(0,16);
                    break;
                default:
                    break;
            }
            j++;
        }
        k++;
    }

    itemTextFile.close();

    srand((unsigned int) time(NULL));

    int obstaclePosX;
    int obstaclePosY;

    for (int x = 0; x < 10; x++) {

        Obstacle obstacle("barile/frame-",7);
        obstacle.setOrigin(48,51);

        obstacles.push_back(obstacle);

        do {

            obstaclePosX = rand() % width;
            obstaclePosY = rand() % height;
        } while (!isFightingGround(tiles[obstaclePosY][obstaclePosX]));

        Vector2f v(obstaclePosX*32+16,obstaclePosY*32+16);

        obstacles[x].setPosition(v);
        tiles[obstaclePosY][obstaclePosX].setHeroWalkability(false);
        tiles[obstaclePosY][obstaclePosX].setEnemyWalkability(false);
    }

}

vector<Obstacle> & TileMap::getObstacle() {

    return obstacles;
}

void TileMap::setObstacle(vector<Obstacle> &obstacle) {

    obstacles=obstacle;
}

bool TileMap::isFightingGround(Tile &tile) {

    return tile.getValue()==fightFloor;
}

void TileMap::openBossDoor() {

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){
            if(tiles[i][j].getValue()==heroStartingPosition) {
                tiles[i][j].setValue(121);
                heroStartingPosition=121;
            }
        }
    }

    load("Tileset1.png",Vector2u(32,32));
}

bool TileMap::isBossDoor(Tile &tile) {

    return tile.getValue()==heroStartingPosition;
}

void TileMap::draw(RenderWindow &window) {

    TileBossMap::draw(window);

    updateRoomsItems();

    for(int i=0;i<items.size();i++)
        items[i].draw(window);

    /*vector<Obstacle>::iterator it=obstacles.begin();

    for(int i=0;i<obstacles.size();i++)
        obstacles[i].draw(window);

    for(int i=0;i<obstacles.size();i++){
        if(!obstacles[i].getDestroyed()) {

            it++;
        }
        else {

            getTile(obstacles[i].getPosition()).reset();
            obstacles.erase(it);
            i--;
        }
    }*/
}

void TileMap::setTileMap() {

    TileBossMap::setTileMap();

    for(int i=0;i<width;i++){
        for(int j=0;j<height;j++){

            if (tiles[i][j].getValue()==other) {
                tiles[i][j].setHeroWalkability(false);
                tiles[i][j].setEnemyWalkability(false);
            }
            if (tiles[i][j].getValue() == corridorFloor)
                tiles[i][j].setEnemyWalkability(false);
        }
    }
}

void TileMap::setCorridorFloor(int value) {

    corridorFloor=value;
}

void TileMap::setFightFloor(int value) {

    fightFloor=value;
}

void TileMap::setVacuum(int value) {

    other=value;
}
