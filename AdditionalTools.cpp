
#include "AdditionalTools.h"

Tools::Tools(){
    gift_items.resize(NUM_SKILLS);
    item_width.resize(NUM_SKILLS);
    item_height.resize(NUM_SKILLS);

    gift_items[0] = "images/Utils/1gold.png";
    item_width[0] = 33;   item_height[0] = 41;
    gift_items[1] = "images/Utils/3gold.png";
    item_width[1] = 55;   item_height[1] = 32;

    gift_items[2] = "images/Utils/gift/shield.png";
    gift_items[3] = "images/Utils/gift/preventenemy.png";
    gift_items[4] = "images/Utils/gift/teleport.png";
    gift_items[5] = "images/Utils/gift/x2gold.png";
    gift_items[6] = "images/Utils/gift/plusrocket.png";
    gift_items[7] = "images/Utils/gift/dan4phia.png";
    gift_items[8] = "images/Utils/gift/superbullet.png";
    gift_items[9] = "images/Utils/gift/danloang.png";
    gift_items[10] = "images/Utils/gift/4dan.png";
    gift_items[11] = "images/Utils/gift/new1.png";
    item_width[11] = 50;   item_height[11] = 77;
    gift_items[12] = "images/Utils/gift/ziczac.png";
    gift_items[13] = "images/Utils/gift/new2.png";
    gift_items[14] = "images/Utils/gift/default.png";
    gift_items[15] = "images/Utils/gift/treasure.png";
    item_width[15] = 70;   item_height[15] = 61;
    gift_items[16] = "images/Utils/gift/booster.png";
    gift_items[17] = "images/Utils/gift/hp.png";
    gift_items[18] = "images/Utils/gift/stunned.png";
    item_width[18] = 63;   item_height[18] = 53;
    gift_items[19] = "images/Utils/gift/tia.png";
    item_width[19] = 30;   item_height[19] = 102;
    gift_items[20] = "images/Utils/gift/rocket2.png";
    item_width[20] = 60;   item_height[20] = 59;
    gift_items[21] = "images/Utils/gift/phitieu.png";
    item_width[21] = 60;   item_height[21] = 60;
    gift_items[22] = "images/Utils/gift/superlaser.png";
    item_width[22] = 65;   item_height[22] = 51;


    for(int i = 2; i < gift_items.size(); i++){
        if(i != 11 && i != 15 && i != 18 && i != 19 && i != 20 && i != 21 && i != 22){
            item_width[i] = 60;
            item_height[i] = 60;            
        }

    }

    value = 0;

    startTime = SDL_GetTicks();

    expGold.resize(EXPLODE_GOLD_ANIMATION_FRAMES, NULL);

    int speed = 1;
    
    magnet = false;
}

Tools::~Tools(){
    if(!expGold.empty()){
        for(int i = 0; i < expGold.size(); i++){
            SDL_Texture* aTexture = expGold.at(i);
            if(aTexture != NULL){
                SDL_DestroyTexture(aTexture);
                aTexture = NULL;
            }
        }
        expGold.clear();          
    }
    free();
}

bool Tools::get_gift() {
    int randomNumber = rand() % 100 + 1;

    if (randomNumber <= 20 ) {
        value = 5;
        pos.w = item_width[0];
        pos.h = item_height[0];
        set_skill(Tools::GOLD_1);
        return loadIMG(gift_items[0]);
    }
    else if(randomNumber <= 20) {
        value = 8;
        pos.w = item_width[1];
        pos.h = item_height[1];
        set_skill(Tools::GOLD_2);
        return loadIMG(gift_items[1]);
    } 
    else{
        int random_skill = rand() % (NUM_SKILLS - 2) + 2;
        
        value = 0;
        pos.w = item_width[random_skill];
        pos.h = item_height[random_skill];
        set_skill(random_skill);
        return loadIMG(gift_items[random_skill]);
    }
}


void Tools::handleMove(const int& x_border, const int& y_border){
    if(!magnet){
        int move_x = rand() % 3 - 1; 
        int move_y = rand() % 3 - 1; 

        int td = rand() % 3 + 1; 

        int new_x = pos.x + move_x * td;
        int new_y = pos.y + move_y * td;

        new_x = max(0, min(x_border - pos.w, new_x));
        new_y = max(0, min(y_border - pos.h, new_y));

        if (new_x >= x_border || new_x < 0 || new_y >= y_border || new_y < 0) {
            setPos(-100, -100); 
        } else {
            setPos(new_x, new_y);
        }       
    }
    else{
        float rad_angle = degrees * M_PI / 180.0;
        int move_x = cos(rad_angle) * 50; 
        int move_y = sin(rad_angle) * 50;

        pos.x += move_x / 2;
        pos.y += move_y / 2;

        if (pos.x >= x_border || pos.x < 0 || pos.y >= y_border || pos.y < 0) {
            setPos(500, 500); 
        }
    }

}

float cal_deg(float target_angle, int index) {
    const float MAX_DEVIATION = 11; 
    float deviation = (index * MAX_DEVIATION) - (3) * MAX_DEVIATION / 2;
    return target_angle + deviation;
}

void Tools::set_deg_for_item(const SDL_Rect& posTank, int index){
    SDL_Rect current_pos = getPos();

    float delta_x = posTank.x - current_pos.x;
    float delta_y = posTank.y - current_pos.y;

    float angle = atan2(delta_y, delta_x) * (180.0 / M_PI);

    degrees = cal_deg(angle, index);
}

Uint32 Tools::timer(){
    return SDL_GetTicks() - startTime;
}

void Tools::set_explode_gift(){
    expGold[0] = SDLCommonFunc::loadImage("images/Utils/P103947/exp1.png");
    expGold[1] = SDLCommonFunc::loadImage("images/Utils/P103947/exp2.png");
    expGold[2] = SDLCommonFunc::loadImage("images/Utils/P103947/exp3.png");
    expGold[3] = SDLCommonFunc::loadImage("images/Utils/P103947/exp4.png");
    expGold[4] = SDLCommonFunc::loadImage("images/Utils/P103947/exp5.png");
    expGold[5] = SDLCommonFunc::loadImage("images/Utils/P103947/exp6.png");
    expGold[6] = SDLCommonFunc::loadImage("images/Utils/P103947/exp7.png");
    expGold[7] = SDLCommonFunc::loadImage("images/Utils/P103947/exp8.png");
    expGold[8] = SDLCommonFunc::loadImage("images/Utils/P103947/exp9.png");
}

void Tools::renderCopy2(){
    SDLCommonFunc::render(expGold[frame], pos);
}


void Tools::set_sprite_for_shield(){
    for(int i = 0; i < 3; i++){
        shield[i].x = 95 * i;
        shield[i].y = 0;
        shield[i].w = 95;
        shield[i].h = 95;
    }
}

void Tools::run_shield() {
    SDL_Rect* currentClip = &shield[shield_frame % 3];
    SDLCommonFunc::render_for_sprite(p_object, pos.x, pos.y, currentClip, degrees, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
}

void Tools::set_sprite_for_teleport(){
    for(int i = 0; i < 10; i++){
        teleport[i].x = 100 * i;
        teleport[i].y = 0;
        teleport[i].w = 100;
        teleport[i].h = 100;
    }
}

int Tools::frame_tele = 0;

void Tools::run_teleport(){
    SDL_Rect* currentClip = &teleport[frame_tele / 10];
    SDLCommonFunc::render_for_sprite(p_object, pos.x, pos.y, currentClip, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
       frame_tele++; 
    if( (frame_tele / 10) >= 10 )
    {
        frame_tele = 0;
    }
}

int Tools::frame_booster = 0;

void Tools::set_sprite_for_booster(){
    for(int i = 0; i < 5; i++){
        booster[i].x = 60 * i;
        booster[i].y = 0;
        booster[i].w = 60;
        booster[i].h = 88;
    }
}

void Tools::run_booster(){
    SDL_Rect* currentClip = &booster[frame_booster / 5];
    SDLCommonFunc::render_for_sprite(p_object, pos.x, pos.y, currentClip, degrees, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
       frame_booster++; 
    if( (frame_booster / 5) >= 5 )
    {
        frame_booster = 0;
    }
}

void Tools::set_sprite_for_stun(){
    for(int i = 0; i < 6; i++){
        stun[i].x = 150 * i;
        stun[i].y = 0;
        stun[i].w = 150;
        stun[i].h = 109;
    }
}

int Tools::frame_stun = 0;

void Tools::run_stun(){
    SDL_Rect* currentClip = &stun[frame_stun / 6];
    SDLCommonFunc::render_for_sprite(p_object, pos.x, pos.y, currentClip, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderPresent(gRenderer);
       frame_stun++; 
    if( (frame_stun / 6) >= 6 )
    {
        frame_stun = 0;
    }
}
