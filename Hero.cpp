//
// Created by piero on 9/3/18.
//

//#include "Hero.h"
#include "Kalashnikov.h"
#include "Knight.h"
#include "Valkyrie.h"
#include "Hero.h"

Hero::Hero(int Hp, int speed, bool armor) : GameCharacter(Hp, speed) {

    Armor = armor;

    moveU = false;
    moveD = false;
    moveL = false;
    moveR = false;

    lastDirection=false;

    weapon = new Kalashnikov;
    weapon->setRateOfFire(0.1);
}



Hero::~Hero() = default;

bool Hero::isLocked() const {
    return Locked;
}

void Hero::setLocked(bool Locked) {
    Hero::Locked = Locked;
}

bool Hero::isMp() const {
    return Mp;
}

void Hero::setMp(bool Mp) {
    Hero::Mp = Mp;
}

bool Hero::isSpecialPower() const {
    return SpecialPower;
}

void Hero::setSpecialPower(bool SpecialPower) {
    Hero::SpecialPower = SpecialPower;
}

bool Hero::isFinalAttack() const {
    return FinalAttack;
}

void Hero::setFinalAttack(bool FinalAttack) {
    Hero::FinalAttack = FinalAttack;
}

bool Hero::isArmor() const {
    return Armor;
}

void Hero::setArmor(bool Armor) {
    Hero::Armor = Armor;
}

void Hero::setDirUp(bool state) {

    moveU=state;
}

void Hero::setDirDown(bool state) {

    moveD=state;
}

void Hero::setDirLeft(bool state) {

    moveL=state;
}

void Hero::setDirRight(bool state) {

    moveR=state;
}

bool Hero::isStill() {

    if(!moveU&&!moveD&&!moveR&&!moveL)
        return true;
    else
        return false;
}

void Hero::aim(RenderWindow &window, Event event) {

    Vector2i posTarget(event.mouseMove.x,event.mouseMove.y);

    weapon->rotate(window.mapPixelToCoords(posTarget));

}

Hero *Hero::Create(int index) {
    switch(index){
        case 0:
            return new Knight(15,16,false);
        case 1:
            return new Valkyrie(8,5,true);
        default:break;
    }
}

bool Hero::getDirRight() {

    return moveR;
}

bool Hero::getDirLeft() {
    return moveL;
}

bool Hero::getDirDown() {
    return moveD;
}

bool Hero::getDirUp() {
    return moveU;
}

void Hero::moveRight(TileBossMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(speed + getDimension().width / 2, 0));

    if(tile.getHeroWalkability()) {
        sprite.move(speed, 0);
        weapon->move(speed, 0);
        notify();
    }
}

void Hero::moveLeft(TileBossMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(-speed - getDimension().width / 2, 0));

    if(tile.getHeroWalkability()) {

        sprite.move(-speed, 0);
        weapon->move(-speed, 0);
        notify();
    }
}

void Hero::moveUp(TileBossMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(0, -speed - getDimension().height / 2));

    if(tile.getHeroWalkability()) {

        sprite.move(0, -speed);
        weapon->move(0, -speed);
        notify();
    }
}

void Hero::moveDown(TileBossMap *map) {

    Tile tile=map->getTile(getPosition() + Vector2f(0, speed + getDimension().height / 2));

    if(tile.getHeroWalkability()) {

        sprite.move(0, speed);
        weapon->move(0, speed);
        notify();
    }
}

void Hero::draw(RenderWindow &window) {


    if((moveU&&!moveD&&!moveL&&!moveR)){
        weapon->draw(window);
        window.draw(sprite);
        lastDirection=true;
    }
    else if(isStill()){
        if(lastDirection) {
            weapon->draw(window);
            window.draw(sprite);
        } else {
            window.draw(sprite);
            weapon->draw(window);
        }
    }
    else{
        window.draw(sprite);
        weapon->draw(window);
        lastDirection=false;
    }
}



