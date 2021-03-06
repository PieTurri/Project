//
// Created by piero on 9/3/18.
//

#ifndef PROJECT_GAMECHARACTER_H
#define PROJECT_GAMECHARACTER_H


#include "Weapon.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameCharacter {

public:

    GameCharacter();

    explicit GameCharacter(int Hp, int speed);

    void draw(RenderWindow &window);

    virtual ~GameCharacter()=0;

    void setSpeed(int s);

    int getSpeed();

    void setHp(int Hp);

    int getHp();

    Vector2f getPosition();

    void setPosition(Vector2f pos);

    void setWeaponUse(bool statement);

    bool getWeaponUse();

    Weapon* getWeapon();

    const Sprite &getSprite() const;

    FloatRect getDimension();

    void setImage(string imageName);

    void scale(float x, float y);

    /*virtual Vector2f moveRight()=0;

    virtual Vector2f moveLeft()=0;

    virtual Vector2f moveUp()=0;

    virtual Vector2f moveDown()=0;*/

    void setWeapon(Weapon *weapon);

protected:

    Texture texture;
    Sprite sprite;

    int Hp;
    int speed;
    bool usingWeapon;

    Weapon* weapon;
};


#endif //PROJECT_GAMECHARACTER_H
