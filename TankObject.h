#ifndef TANKOBJECT_H_INCLUDED
#define TANKOBJECT_H_INCLUDED

#include "Common.h"
#include "BaseObject.h"
#include "BulletObject.h"

#define WIDTH_TANK_OBJECT 60
#define HEIGHT_TANK_OBJECT 52

#define SPEED_BULLET_MAIN_TANK 8.0
#define SPEED_ROCKET_MAIN_TANK 8.0

// const int ROCKET_ANIMATION_FRAMES = 4;

class TankObject : public BaseObject
{
public:
    TankObject();
    ~TankObject();

    void handleInputAction(SDL_Event e, Mix_Chunk* bulletSound[NUMBER_OF_BULLET_SOUND]);
    void handleMove();

    double getDegrees() const {return degrees; }
    void setDegrees(double d) { degrees = d; }

    SDL_RendererFlip getFlipType() const { return flipType; }
    void setFlipType (SDL_RendererFlip type) { flipType = type; }

    void setBulletList(vector<BulletObject*> bulletList) { bulletOfTankList = bulletList; }
    vector<BulletObject*> getBulletList() const { return bulletOfTankList; }

    void setRocketList(vector<BulletObject*> rocketlist) { rocketOfTankList = rocketlist; }
    vector<BulletObject*> getRocketList() const { return rocketOfTankList; }

    void runBullet();
    void removeBullet(const int& idx);

    void runRocket();
    void removeRocket(const int& idx);

    void setRocket(unsigned int& c) { currentRocket = c; }
    unsigned int getRocket() { return currentRocket; }
    void setRocketTexture();
private:
    int x_val;
    int y_val;
    double degrees;
    SDL_RendererFlip flipType;

    vector<BulletObject*> bulletOfTankList;
    vector<BulletObject*> rocketOfTankList;
    unsigned int currentRocket;
    //vector<SDL_Texture*> rocketTexture;
};

#endif // TANKOBJECT_H_INCLUDED
//up