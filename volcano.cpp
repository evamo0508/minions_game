#include <ctime>
#include <cmath>
//#include "HP.h"

class volcano
{
public:
    //initialize
    volcano(int x,int y);
    //before eruption
    void volcano_alone(int texture);
    //erupt
    volcano& eruption();
    //when minion touches volcano_alone
    bool volcano_alone_kill(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position);
    //when minion touches volcano_erupt
    bool volcano_erupt_kill(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position);
    //change volcano position when hurt
    void change(){vol_x=rand()%14+1;vol_y=rand()%8+1;erupt_countdown=0;}

    static int random_erupt;

private:
    int vol_x,vol_y;
    int erupt_countdown=0;

};
int volcano::random_erupt=rand()%3;
volcano::volcano(int x,int y)
{
    vol_x=x;vol_y=y;
    //volcano falls into lava
    for(int i=0;i<amount_of_obs_fire;i++)
    {
        while((ground_fire[0][i]==vol_x)&&(ground_fire[1][i]==vol_y))
        {
            vol_x=rand()%14+1;vol_y=rand()%8+1;
            SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
        }
    }
}

void volcano::volcano_alone(int texture)
{
    Blockviewport(vol_x,vol_y,ground_fire_BottomL);
    Blockviewport(vol_x,vol_y,texture);
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
}

volcano& volcano::eruption()
{
   if(800<erupt_countdown&&erupt_countdown<2000)
    {
        //put nine blocks
        Blockviewport(vol_x-1,vol_y-1,ground_fire_TopL);
        Blockviewport(vol_x,vol_y-1,ground_fire_TopM);
        Blockviewport(vol_x+1,vol_y-1,ground_fire_TopR);
        Blockviewport(vol_x-1,vol_y,ground_fire_MiddleL);
        Blockviewport(vol_x,vol_y,ground_fire_MiddleM);
            //volcano animation when exploding
            if(erupt_countdown%3==1)Blockviewport(vol_x,vol_y,volcanic1);
            else if(erupt_countdown%3==2)Blockviewport(vol_x,vol_y,volcanic2);
            else if(erupt_countdown%3==0)Blockviewport(vol_x,vol_y,volcanic3);
        Blockviewport(vol_x+1,vol_y,ground_fire_MiddleR);
        Blockviewport(vol_x-1,vol_y+1,ground_fire_BottomL);
        Blockviewport(vol_x,vol_y+1,ground_fire_BottomM);
        Blockviewport(vol_x+1,vol_y+1,ground_fire_BottomR);
        SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    }
    erupt_countdown++;
    return *this;
}

bool volcano::volcano_alone_kill(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position)
{
    bool hurt=false;
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    if(erupt_countdown<800)
    {
        if((minion->get_minion_position_x()>=(vol_x*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=(vol_x*BLOCK_WIDTH-25))&&
            (minion->get_minion_position_y()>=(vol_y*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=(vol_y*BLOCK_HEIGHT-17)))
        {
            *hp_width-=LOSS;
            SDL_RenderSetViewport( gRenderer, NULL );
            //clear corpse
                //Ground
                for(int i=0;i<16;i++){
                    for(int j=0;j<10;j++){
                        Blockviewport(i,j,ground);}}
                Blockviewport(0,1,firegun);
                //obs_fire
                build_fire(0);

                //reset volcano
                volcano vol1(rand()%14+1,rand()%8+1),vol2(rand()%14+1,rand()%8+1),vol3(rand()%14+1,rand()%8+1);

                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!

                //Banana
                HP(*hp_width);
                //Banana_reward
                Blockviewport(*banana_position,fireball_y/BLOCK_HEIGHT,banana_pic);

                //twinkle
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                minion->change_minion_position(0,SCREEN_HEIGHT-BLOCK_HEIGHT);
                for(int i=0;i<10;i++){
                    if(i%2==1)gDotTexture.loadFromFile( "pic/minion_run.png" );
                    else gDotTexture.loadFromFile( "pic/ground_fire.png" );
                    minion->render();
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay( 100 );
               }
               hurt=true;
        }
    }
    return hurt;
}

bool volcano::volcano_erupt_kill(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position)
{
    bool hurt=false;
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    if(800<erupt_countdown&&erupt_countdown<2000)
    {
        if((minion->get_minion_position_x()>=((vol_x-1)*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=((vol_x+2)*BLOCK_WIDTH-25))&&
            (minion->get_minion_position_y()>=((vol_y-1)*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=((vol_y+2)*BLOCK_HEIGHT-17)))
        {
            *hp_width-=LOSS;
            SDL_RenderSetViewport( gRenderer, NULL );
            //clear corpse
                //Ground
                for(int i=0;i<16;i++){
                    for(int j=0;j<10;j++){
                        Blockviewport(i,j,ground);}}
                Blockviewport(0,1,firegun);
                //obs_fire
                build_fire(0);

                //reset volcano
                volcano vol1(rand()%14+1,rand()%8+1),vol2(rand()%14+1,rand()%8+1),vol3(rand()%14+1,rand()%8+1);

                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!

                //Banana
                HP(*hp_width);

                //Banana_reward
                Blockviewport(*banana_position,fireball_y/BLOCK_HEIGHT,banana_pic);

                //twinkle
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                minion->change_minion_position(0,SCREEN_HEIGHT-BLOCK_HEIGHT);
                for(int i=0;i<10;i++){
                    if(i%2==1)gDotTexture.loadFromFile( "pic/minion_run.png" );
                    else gDotTexture.loadFromFile( "pic/ground_fire.png" );
                    minion->render();
                    SDL_RenderPresent( gRenderer );
                    SDL_Delay( 100 );
               }
              hurt=true;
        }

    }

    if(erupt_countdown==2000){erupt_countdown=0;random_erupt=rand()%3;}
    return hurt;
}

/*bool random_erupt(volcano &vol1,volcano &vol2,volcano &vol3)
{
    bool hurt=false;
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    static int temp=rand()%3,erupt_countdown=0;
    erupt_countdown++;
    if(1000<erupt_countdown&&erupt_countdown<3000)
    {
        switch(temp)
        {
            case 0:vol1.eruption();break;
            case 1:vol2.eruption();break;
            case 2:vol3.eruption();break;
        }
    }
    if(erupt_countdown==3000){erupt_countdown=0;temp=rand()%3;}
    return hurt;
}*/

