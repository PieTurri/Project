//
// Created by piero on 9/28/18.
//

#include "MenuLoop.h"

using namespace std;
using namespace sf;

 MenuLoop::MenuLoop() {}
int MenuLoop::getIndex() {
    return index;
}


void MenuLoop::generateScreen() {

    int counter = 0;
    int counter2 = 0;
    int counter3 = 0;

    window.create(sf::VideoMode(1400, 896), "Leo&Pie Game");

    songs.playMusic(music, index, mapScreen);

    unsigned int h = map.getMapHeight();
    unsigned int w = map.getMapWidth();

    int spritex=128;
    int spritey=128;

    //Projectile projectile1;

    //vector<Projectile>::const_iterator iter;
    //vector<Projectile> projectileArray;





    while (window.isOpen()) {

        while (window.pollEvent(event)) {

            if (getIndex() == 0) {

                menu.setMenuScreen(texture, sprite, font, text, font1);

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Up:
                                menu.MoveUp(text);
                                break;

                            case sf::Keyboard::Down:
                                menu.MoveDown(text);
                                break;

                            case sf::Keyboard::Escape:
                                window.close();
                                break;

                            case sf::Keyboard::Return:
                                switch (menu.GetPressedItem()) {
                                    case 0:
                                        index = 1;
                                        choose.setChooseCharacterScreen(texture, sprite, font, texture1, spriteC,
                                                                        textC);
                                        break;
                                    case 1:
                                        index = 2;
                                        rules.setRulesScreen(texture, sprite, textRules, font);
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }

            } else if (getIndex() == 1) {

                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Left:
                                choose.MoveLeft(texture1, spriteC);
                                break;

                            case sf::Keyboard::Right:
                                choose.MoveRight(texture1, spriteC);
                                break;

                            case sf::Keyboard::Escape:

                                switch (flag) {
                                    case 0:
                                        index = 0;
                                        menu.selectedMenuIndex = 0;
                                        menu.a = true;
                                        menu.setMenuScreen(texture, sprite, font, text, font1);
                                        break;
                                    case 1:
                                        index = 1;
                                        choose.setChooseCharacterScreen(texture, sprite, font, texture1, spriteC,
                                                                        textC);
                                        break;
                                    default:
                                        break;
                                }
                                break;

                            case sf::Keyboard::Return:

                                if(startGame){

                                    flagMap = 2;

                                    switch (event.key.code){

                                        case sf::Keyboard::Return:

                                            spriteItems=new Sprite[145];

                                            map.SetTileMap();

                                            map.generateRoomsItems(spriteItems);

                                            map.setItemsProperty(spriteItems);

                                            map.load("/home/piero/Documents/Programmazione/Project2/Project/Risorse/Tileset1.png",
                                                    sf::Vector2u(32, 32));



                                            view.setCenter(sf::Vector2f(spritex+16, spritey+16));

                                            view.setSize(sf::Vector2f(640,480));

                                            view.setViewport(FloatRect(0, 0, 1, 1));

                                            miniview.setCenter(Vector2f(w * 16, h * 16));

                                            miniview.setSize(sf::Vector2f((w - 2) * 32, (h - 2) * 32));

                                            miniview.setViewport(sf::FloatRect(0.85f, 0, 0.15f, 0.25f));

                                            break;

                                        default:
                                            break;
                                    }
                                }

                                else{

                                    switch (choose.GetPressedItem()) {
                                        case 0 :

                                            drawPlay();

                                            if (startGame) {

                                                factory = new KnightFactory;

                                                hero = factory->createHero();

                                                Efactory = new SkeletonFactory;

                                                enemy = Efactory->createEnemy();

                                                spritePlayer.setPosition(spritex, spritey);

                                                hero->draw(spritePlayer, texturePlayer, typeMove);

                                                enemy->draw(Esprite, Etexture, x_load, y_load);
                                            }

                                            break;

                                        case 1:

                                            drawPlay();

                                            if (startGame) {

                                                factory = new ValkyrieFactory;

                                                hero = factory->createHero();

                                                spritePlayer.setPosition(spritex, spritey);

                                                hero->draw(spritePlayer, texturePlayer, typeMove);
                                            }

                                            break;

                                        default:
                                            break;
                                    }
                                }
                                break;
                            default:
                                break;
                        }
                        break;

                    case sf::Event::Closed:
                        window.close();
                        break;

                    default:
                        break;
                }


            } else if (getIndex() == 2) {
                switch (event.type) {

                    case sf::Event::KeyReleased:

                        switch (event.key.code) {

                            case sf::Keyboard::Escape:
                                index = 0;
                                menu.selectedMenuIndex = 0;
                                menu.a = true;
                                menu.setMenuScreen(texture, sprite, font, text, font1);
                                break;

                            default:
                                break;
                        }
                        break;
                    case sf::Event::Closed:
                        window.close();
                        break;
                    default:
                        break;
                }
            } else if (getIndex() == 3) {


                switch (event.type) {

                    case Event::KeyReleased:
                        switch (event.key.code) {
                            case Keyboard::Up:
                                moveU = false;
                                break;
                            case Keyboard::Down:
                                moveD = false;
                                break;
                            case Keyboard::Left:
                                moveL = false;
                                break;
                            case Keyboard::Right:
                                moveR = false;
                                break;

                            default:
                                break;
                        }
                        break;

                    case Event::KeyPressed:
                        switch (event.key.code) {
                            case Keyboard::Up:
                                moveU = true;
                                break;
                            case Keyboard::Down:
                                moveD = true;
                                break;
                            case Keyboard::Left:
                                moveL = true;
                                break;
                            case Keyboard::Right:
                                moveR = true;
                                break;
                            default:
                                break;
                        }
                        break;
                    default:
                        break;
                    }

                if (moveR && moveU) {
                    hero->movement(spritePlayer, "right", view);
                    hero->movement(spritePlayer, "up", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition())
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 24))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 0))) {
                        hero->movement(spritePlayer, "left", view);
                        hero->movement(spritePlayer, "down", view);
                    }
                    hero->draw(spritePlayer, texturePlayer, 3);
                } else if (moveL && moveU) {
                    hero->movement(spritePlayer, "left", view);
                    hero->movement(spritePlayer, "up", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition())
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(0, 24))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 0))) {
                        hero->movement(spritePlayer, "right", view);
                        hero->movement(spritePlayer, "down", view);
                    }
                    hero->draw(spritePlayer, texturePlayer, 2);
                } else if (moveR && moveD) {
                    hero->movement(spritePlayer, "right", view);
                    hero->movement(spritePlayer, "down", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 24))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 0))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(0, 24))) {
                        hero->movement(spritePlayer, "left", view);
                        hero->movement(spritePlayer, "up", view);
                    }
                    hero->draw(spritePlayer, texturePlayer, 3);
                } else if (moveL && moveD) {
                    hero->movement(spritePlayer, "left", view);
                    hero->movement(spritePlayer, "down", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition())
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(32, 32))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(0, 32))) {
                        hero->movement(spritePlayer, "right", view);
                        hero->movement(spritePlayer, "up", view);
                    }
                    hero->draw(spritePlayer, texturePlayer, 2);
                } else if (moveD) {
                    hero->movement(spritePlayer, "down", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition() + Vector2f(28, 28))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(0, 28)))
                        hero->movement(spritePlayer, "up", view);
                    hero->draw(spritePlayer, texturePlayer, 0);
                } else if (moveU) {
                    hero->movement(spritePlayer, "up", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 0))
                        || !map.getTileWalkability(spritePlayer.getPosition()))
                        hero->movement(spritePlayer, "down", view);
                    hero->draw(spritePlayer, texturePlayer, 1);
                } else if (moveL) {
                    hero->movement(spritePlayer, "left", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition())
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(0, 24)))
                        hero->movement(spritePlayer, "right", view);
                    hero->draw(spritePlayer, texturePlayer, 2);
                } else if (moveR) {
                    hero->movement(spritePlayer, "right", view);
                    if (!map.getTileWalkability(spritePlayer.getPosition() + Vector2f(28, 28))
                        || !map.getTileWalkability(spritePlayer.getPosition() + Vector2f(24, 0)))
                        hero->movement(spritePlayer, "left", view);
                    hero->draw(spritePlayer, texturePlayer, 3);
                }

                switch (event.type) {

                    case Event::Closed:
                        window.close();
                    default:
                        break;
                }

                //fire missle (space bar)
                /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    projectile1.fireT.setPosition(hero->getPosX(),hero->getPosY());
                    projectileArray.push_back(projectile1);
                }*/
            }
        }

        window.clear();

        //draw projectiles

        /*for(iter = projectileArray.begin(); iter != projectileArray.end(); iter ++){

            window.draw(projectileArray[counter].fireT);
            counter++;

        }*/


        window.draw(sprite);
        if (index == 0)
            menu.draw(window, text);

        else if (index == 1) {

            choose.draw(spriteC, texture1);
            for (int i = 0; i < 5; i++)
                window.draw(spriteC[i]);
            choose.drawC(window, textC);

            if (!drawMapLevel) {
                if (permission) {   //disegna la schermata dei livelli
                    window.draw(spritel);

                    level.draw(window, textl);
                    if (shine) {
                        textl[1].setCharacterSize(40);
                        textl[1].setPosition(level.width / 2 - 180, level.height / 2 + 245);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        shine = false;

                    } else if (!shine) {
                        textl[1].setCharacterSize(30);
                        textl[1].setPosition(level.width / 2 - 150, level.height / 2 + 250);
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        shine = true;
                    }
                    cout << flagMap << endl;
                }
            }
        }

        if (flagMap == 1) {
            level.drawCloud(texturem, spritem);

            for (int i = 0; i < 16; i++)
                window.draw(spritem[i]);

            window.draw(spriteCharacterLevel);
            if (shineLevel) {
                spriteCharacterLevel.setPosition(sf::Vector2f(180, 595));
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                shineLevel = false;

            } else if (!shineLevel) {
                spriteCharacterLevel.setPosition(sf::Vector2f(180, 585));
                std::this_thread::sleep_for(std::chrono::milliseconds(25));
                shineLevel = true;
            }
        }

        if(startGame && flagMap == 2){
            switch (event.key.code) {

                case Keyboard::Return:

                    index = 3;

                    break;

                default:

                    break;
            }
        }
        if (index == 2) {
            rules.draw(window, textRules);
        }

        if (index == 3) {

            if (!moveU && !moveD && !moveL && !moveR) {

                map.followCharPos(view,spritePlayer);
            }

            //view

            window.setView(view);
            window.draw(map);
            window.draw(spritePlayer);
            window.draw(Esprite);

            //miniview

            map.generateRoomsItems(spriteItems);

            for(int i=0;i<145;i++)
                window.draw(spriteItems[i]);

            spritePlayer.setScale(3,3);
            window.setView(miniview);
            window.draw(map);
            window.draw(spritePlayer);
            window.draw(Esprite);
            for(int i=84;i<145;i++){
                spriteItems[i].setScale(1,1);
            }
            for(int i=0;i<145;i++){
                window.draw(spriteItems[i]);
            }
            for(int i=84;i<145;i++){
                spriteItems[i].setScale(0.30,0.30);
            }

            spritePlayer.setScale(1,1);

            //movimento random del nemico ->>>>>>RIGUARDA: SI BLOCCA QUANDO MUOVO OMINO E NEMICO ASSIEME

            timeEnemy = clockEnemy.getElapsedTime();

            if (timeEnemy.asMilliseconds() > 500) {
                switch(direction){
                    case 0:
                        if (map.getTileWalkability(Esprite.getPosition()) && noWall) {
                            if (!map.getTileWalkability(Esprite.getPosition() + Vector2f(32, 0))) {

                                enemy->randomDirection(direction);

                            } else {

                                x_load += 32;
                                Esprite.setPosition(x_load, y_load);
                            }
                        }
                        break;

                    case 1:
                        if (map.getTileWalkability(Esprite.getPosition()) && noWall) {
                            if (!map.getTileWalkability(Esprite.getPosition() + Vector2f(-32, 0))) {

                                enemy->randomDirection(direction);


                            } else {

                                x_load -= 32;
                                Esprite.setPosition(x_load, y_load);
                            }
                        }
                        break;

                    case 2:
                        if (map.getTileWalkability(Esprite.getPosition()) && noWall) {
                            if (!map.getTileWalkability(Esprite.getPosition() + Vector2f(0, -32))) {

                                enemy->randomDirection(direction);

                            } else {

                                y_load -= 32;
                                Esprite.setPosition(x_load, y_load);
                            }
                        }
                        break;

                    case 3:
                        if (map.getTileWalkability(Esprite.getPosition()) && noWall) {
                            if (!map.getTileWalkability(Esprite.getPosition() + Vector2f(0, 32))) {

                                enemy->randomDirection(direction);

                            } else {

                                y_load += 32;
                                Esprite.setPosition(x_load, y_load);
                            }
                        }
                        break;
                    default:
                        break;
                }

                clockEnemy.restart();
            }

        }
        window.display();
    }

}

void MenuLoop::drawPlay() {
    permission = true;

    flag = 1;

    if (drawMapLevel) {

        level.setMapLevelScreen(texturel, spritel, texturem, spritem,
                                textureCharacterLevel, spriteCharacterLevel);
        mapScreen = 1;

        switch (event.key.code) {

            case sf::Keyboard::Return:
                flag = 1;
                drawMapLevel = false;
                flagMap = 1;

                break;

            default:
                break;

        }

        songs.playMusic(music, index, mapScreen);

    } else {

        flagMap = 0;
        switch(event.key.code){
            case Keyboard::Return:
                startGame = true;
                break;
            default:
                break;
        }

        level.setScreenLevel(texturel, spritel, textl, font);
        musicLoop = false;
        songs.playMusic(music, index, mapScreen);
    }

}


MenuLoop::~MenuLoop() = default;

