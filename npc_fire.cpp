#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//extern int ground_fire[2][amount_of_obs_fire];

class NPC_FIREBALL
{
    public:

		//The dimensions of the dot
		static const int FIREBALL_WIDTH = MINION_WIDTH;
		static const int FIREBALL_HEIGHT = MINION_HEIGHT;
        /*********************************
        ->change the velocity of fireball!!!!
        *********************************/
		//Maximum axis velocity of the dot
		double FIREBALL_VEL=2;

		//Initializes the variables
		NPC_FIREBALL(int start_X,int start_Y);

		//Automatically adjusts the fireball's velocity
		void handleEvent();
		void handleEvent_next();

		//Moves the fireball
		void move();
		void move_next();

		//Shows the fireball on the screen
		void render(int x,int y);

		int get_fireball_position_x(void){return mPosX;}
		int get_fireball_position_y(void){return mPosY;}


    private:
		//The X and Y offsets of the fireball
		int mPosX, mPosY;

		//The velocity of the fireball
		int mVelX, mVelY;

		LTexture gFireballTexture;
};



NPC_FIREBALL::NPC_FIREBALL(int start_X,int start_Y)
{
    //Initialize the offsets
    mPosX = start_X;
    mPosY = start_Y;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;

    //FIREBALL_VEL=2;
}

void NPC_FIREBALL::handleEvent()
{
   static int change_of_npc_fire=0;

	if(change_of_npc_fire==900)
    {
        change_of_npc_fire=0;
        mVelX += FIREBALL_VEL;
        gFireballTexture.loadFromFile( "pic/npc_fire_fireball.png" );
    }

    change_of_npc_fire++;
    if(mPosX==SCREEN_WIDTH-BLOCK_WIDTH){
    mPosX=BLOCK_WIDTH;
    mVelX = FIREBALL_VEL;
    change_of_npc_fire=0;//important!!!!!BUT I DON'T KNOW WHY~~JUST TRY HAHA
    }
}

void NPC_FIREBALL::handleEvent_next()
{
   static int change_of_npc_fire=900;

	if(change_of_npc_fire==900)
    {
        change_of_npc_fire=0;
        mVelX += FIREBALL_VEL;
        gFireballTexture.loadFromFile( "pic/npc_fire_fireball.png" );
    }

    change_of_npc_fire++;
    if(mPosX==BLOCK_WIDTH*6){
    mPosX=BLOCK_WIDTH;
    mVelX = FIREBALL_VEL;
    change_of_npc_fire=0;//important!!!!!BUT I DON'T KNOW WHY~~JUST TRY HAHA
    }
}

void NPC_FIREBALL::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + FIREBALL_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

}

void NPC_FIREBALL::move_next()
{
    static int change_of_npc_fire=2;

	if(change_of_npc_fire==4)
    {
        change_of_npc_fire=0;
        mPosX += mVelX;
    }

    change_of_npc_fire++;
    //Move the dot left or right

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + FIREBALL_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

}


void NPC_FIREBALL::render(int x,int y)
{
    //Show the dot
    mPosY=y;
    Blockviewport(x,y,firegun);
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    gFireballTexture.render( mPosX, y*BLOCK_HEIGHT );
}


/**
for(int i=0;i<amount_of_obs_fire;i++){
             switch(type_of_obs_fire){
                case 0:
                Blockviewport(ground_fire[0][i],ground_fire[1][i],obs_fire_a);break;
                case 1:
                Blockviewport(ground_fire[0][i],ground_fire[1][i],obs_fire_b);break;
                case 2:
                Blockviewport(ground_fire[0][i],ground_fire[1][i],obs_fire_c);break;
            }
        }

**/
