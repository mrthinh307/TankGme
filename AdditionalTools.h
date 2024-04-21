#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "BaseObject.h"

const int TIME_TO_EXPLODE_GOLD = 10000;
const int EXPLODE_GOLD_ANIMATION_FRAMES = 9;

const int EXP_GOLD_WIDTH = 60;
const int EXP_GOLD_HEIGHT = 90;

const int NUM_SKILLS = 23;

const int SHIELD_WIDTH = 95;
const int SHIELD_HEIGHT = 95;

static unsigned int currentGold = 0;
static unsigned int currentHeart = 3;
static unsigned int currentKilled = 0;

class Tools : public BaseObject
{
public:
    enum skill_list {
        GOLD_1 = 0,
        GOLD_2 = 1,
        SHIELD = 2,
        MAGNET = 3, 
        TELEPORT = 4, 
        X2GOLD = 5,
        ADD_ROCKET = 6,
        FOUR_DIRECTIONS_BULLET = 7,
        SUPER_BULLET = 8,
        BULLET_SPREAD = 9,
        STRAIGHT_BEAM = 10,
        NEW_BULLET_1 = 11,
        TRAP_BULLET = 12,
        ROUNDABOUT = 13,
        DEFAULT = 14,
        TREASURE  = 15,
        BOOSTER = 16,
        HEART = 17,
        STUN = 18,
        TIA_BULLET = 19,
        ROCKET_2 = 20,
        PHI_TIEU = 21,
        SUPER_LASER = 22
    };

    Tools();
    ~Tools();

    unsigned int getGoldValue() { return value; }
    void setGoldValue(unsigned int v) { value = v; }

    double getDegrees() const {return degrees; }
    void setDegrees(double d) { degrees = d; }
    void set_deg_for_item(const SDL_Rect& posTank, int index);

    int get_skill() const { return skill; }
    void set_skill(int type) { skill = type; }

    void handleMove(const int& x_border, const int& y_border);

    Uint32 timer();

    void setFrame(const int& fr) { frame = fr; }
    void set_explode_gift();
    void renderCopy2();

    bool get_gift();

    void set_speed(const int& sp) { speed = sp; }
    int get_speed() { return speed; }

    /* SET SKILLS */

    //1. SHIELD
    void set_sprite_for_shield();
    void run_shield();
    int get_shield_frame() { return shield_frame; }
    void set_shield_frame(int x) { shield_frame = x; }

    //2. Teleport
    void set_sprite_for_teleport();
    void run_teleport();

    //3. MAGNET
    void set_magnet(bool x) { magnet = x; }
    bool get_magnet() { return magnet; }

    //4. BOOSTER
    void set_sprite_for_booster();
    void run_booster();

    //5. STUN
    void set_sprite_for_stun();
    void run_stun();

private:
    unsigned value;
    double degrees;
    Uint32 startTime;
    int speed;

    int frame;
    vector<SDL_Texture*> expGold;

    vector<string> gift_items;
    vector<int> item_width;
    vector<int> item_height;

    int skill;

    SDL_Rect shield[3];
    int shield_frame;

    SDL_Rect teleport[10];
    static int frame_tele;

    bool magnet;

    static int frame_booster;
    SDL_Rect booster[5];

    static int frame_stun;
    SDL_Rect stun[6];
};

#endif


