#ifndef ENEMY_H
#define ENEMY_H
class Player;

#include "VisibleObject.h"
#include "Projectile.h"
#include "Player.h"
#include <list>
#include <cmath>

class Enemy : public VisibleObject
{
public:
    Enemy();
    Enemy(int, float, float);
    ~Enemy();

    void fireProjectile(sf::Texture[]);
    void updateProjectiles();
    void cleanProjectiles();
    void drawProjectiles(sf::RenderWindow &);
    bool checkProjCollision(Player &);

    int getScore();
    int getType();
    int getHitPoints();
    int getInitHealth();
    void takeDamage(int);
    void updatePosition();
    void setDestination(float, float);
    void setVelocity(float, float);
    void trackPlayer(Player &);
    void drawEnemy(sf::RenderWindow &);
    void rotate(Player &);
    bool fire();
    bool destroyCheck();
    sf::Clock timeSinceHit;
    std::list<Projectile> projList;
private:

    bool isDestroyed;
    int enemyType;
    int score;
    int fireClock;
    int hitPoints;
    int startingHealth;
    float pixelsPerFrame;
    float center[2];
    float rotation;
    float velocity[2];
    float destination[2];
};

#endif // ENEMY_H
