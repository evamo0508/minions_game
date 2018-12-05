#include <ctime>
#include <cmath>
//#include "HP.h"
void volcano1(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position,bool &vol1alone,bool &vol1erupt,
              int &vol1_x,int &vol1_y,int &vol2_x,int &vol2_y,int &vol3_x,int &vol3_y,int &random_erupt)
{
    static int erupt_countdown=0;
    //volcano falls into lava
    for(int i=0;i<amount_of_obs_fire;i++)
    {
        while((ground_fire[0][i]==vol1_x)&&(ground_fire[1][i]==vol1_y))
        {
            vol1_x=rand()%14+1;vol1_y=rand()%8+1;
            SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
        }
    }
    //print volcano alone
    Blockviewport(vol1_x,vol1_y,ground_fire_BottomL);
    Blockviewport(vol1_x,vol1_y,volcanic1);
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    //control eruption
    if(random_erupt==1)
    {
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            //put nine blocks
            Blockviewport(vol1_x-1,vol1_y-1,ground_fire_TopL);
            Blockviewport(vol1_x,vol1_y-1,ground_fire_TopM);
            Blockviewport(vol1_x+1,vol1_y-1,ground_fire_TopR);
            Blockviewport(vol1_x-1,vol1_y,ground_fire_MiddleL);
            Blockviewport(vol1_x,vol1_y,ground_fire_MiddleM);
                //volcano animation when exploding
                if(erupt_countdown%3==1)Blockviewport(vol1_x,vol1_y,volcanic1);
                else if(erupt_countdown%3==2)Blockviewport(vol1_x,vol1_y,volcanic2);
                else if(erupt_countdown%3==0)Blockviewport(vol1_x,vol1_y,volcanic3);
            Blockviewport(vol1_x+1,vol1_y,ground_fire_MiddleR);
            Blockviewport(vol1_x-1,vol1_y+1,ground_fire_BottomL);
            Blockviewport(vol1_x,vol1_y+1,ground_fire_BottomM);
            Blockviewport(vol1_x+1,vol1_y+1,ground_fire_BottomR);
            SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
        }
    }
    vol1alone=false;
    if(erupt_countdown<800)
    {
        if((minion->get_minion_position_x()>=(vol1_x*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=(vol1_x*BLOCK_WIDTH-25))&&
            (minion->get_minion_position_y()>=(vol1_y*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=(vol1_y*BLOCK_HEIGHT-17)))
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
                vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                vol1alone=true;
                erupt_countdown=0;
        }
    }
    if(random_erupt==1)
    {
        vol1erupt=false;
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            if((minion->get_minion_position_x()>=((vol1_x-1)*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=((vol1_x+2)*BLOCK_WIDTH-25))&&
                (minion->get_minion_position_y()>=((vol1_y-1)*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=((vol1_y+2)*BLOCK_HEIGHT-17)))
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
                    vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                  vol1erupt=true;
                  erupt_countdown=0;
            }

        }
    }
    if(erupt_countdown==2000){erupt_countdown=0;random_erupt=rand()%3;}
    erupt_countdown++;
    SDL_RenderSetViewport( gRenderer, NULL ); //important!!!!Reset viewport!!!!!!
}

void volcano2(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position,bool &vol2alone,bool &vol2erupt,
              int &vol1_x,int &vol1_y,int &vol2_x,int &vol2_y,int &vol3_x,int &vol3_y,int &random_erupt)
{
    static int erupt_countdown=0;
    //volcano falls into lava
    for(int i=0;i<amount_of_obs_fire;i++)
    {
        while((ground_fire[0][i]==vol2_x)&&(ground_fire[1][i]==vol2_y))
        {
            vol2_x=rand()%14+1;vol2_y=rand()%8+1;
            SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
        }
    }
    //print volcano alone
    Blockviewport(vol2_x,vol2_y,ground_fire_BottomL);
    Blockviewport(vol2_x,vol2_y,volcanic2);
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    //control eruption
    if(random_erupt==2)
    {
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            //put nine blocks
            Blockviewport(vol2_x-1,vol2_y-1,ground_fire_TopL);
            Blockviewport(vol2_x,vol2_y-1,ground_fire_TopM);
            Blockviewport(vol2_x+1,vol2_y-1,ground_fire_TopR);
            Blockviewport(vol2_x-1,vol2_y,ground_fire_MiddleL);
            Blockviewport(vol2_x,vol2_y,ground_fire_MiddleM);
                //volcano animation when exploding
                if(erupt_countdown%3==1)Blockviewport(vol2_x,vol2_y,volcanic1);
                else if(erupt_countdown%3==2)Blockviewport(vol2_x,vol2_y,volcanic2);
                else if(erupt_countdown%3==0)Blockviewport(vol2_x,vol2_y,volcanic3);
            Blockviewport(vol2_x+1,vol2_y,ground_fire_MiddleR);
            Blockviewport(vol2_x-1,vol2_y+1,ground_fire_BottomL);
            Blockviewport(vol2_x,vol2_y+1,ground_fire_BottomM);
            Blockviewport(vol2_x+1,vol2_y+1,ground_fire_BottomR);
            SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
        }
    }
    vol2alone=false;
    if(erupt_countdown<800)
    {
        if((minion->get_minion_position_x()>=(vol2_x*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=(vol2_x*BLOCK_WIDTH-25))&&
            (minion->get_minion_position_y()>=(vol2_y*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=(vol2_y*BLOCK_HEIGHT-17)))
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
                vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                vol2alone=true;
                erupt_countdown=0;
        }
    }
    if(random_erupt==2)
    {
        vol2erupt=false;
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            if((minion->get_minion_position_x()>=((vol2_x-1)*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=((vol2_x+2)*BLOCK_WIDTH-25))&&
                (minion->get_minion_position_y()>=((vol2_y-1)*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=((vol2_y+2)*BLOCK_HEIGHT-17)))
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
                    vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                  vol2erupt=true;
                  erupt_countdown=0;
            }

        }
    }
    if(erupt_countdown==2000){erupt_countdown=0;random_erupt=rand()%3;}
    erupt_countdown++;
    SDL_RenderSetViewport( gRenderer, NULL ); //important!!!!Reset viewport!!!!!!
}

void volcano3(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int *banana_position,bool &vol3alone,bool &vol3erupt,
               int &vol1_x,int &vol1_y,int &vol2_x,int &vol2_y,int &vol3_x,int &vol3_y,int &random_erupt)
{
    static int erupt_countdown=0;
    //volcano falls into lava
    for(int i=0;i<amount_of_obs_fire;i++)
    {
        while((ground_fire[0][i]==vol3_x)&&(ground_fire[1][i]==vol3_y))
        {
            vol3_x=rand()%14+1;vol3_y=rand()%8+1;
            SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
        }
    }
    //print volcano alone
    Blockviewport(vol3_x,vol3_y,ground_fire_BottomL);
    Blockviewport(vol3_x,vol3_y,volcanic3);
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    //control eruption
    if(random_erupt==3)
    {
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            //put nine blocks
            Blockviewport(vol3_x-1,vol3_y-1,ground_fire_TopL);
            Blockviewport(vol3_x,vol3_y-1,ground_fire_TopM);
            Blockviewport(vol3_x+1,vol3_y-1,ground_fire_TopR);
            Blockviewport(vol3_x-1,vol3_y,ground_fire_MiddleL);
            Blockviewport(vol3_x,vol3_y,ground_fire_MiddleM);
                //volcano animation when exploding
                if(erupt_countdown%3==1)Blockviewport(vol3_x,vol3_y,volcanic1);
                else if(erupt_countdown%3==2)Blockviewport(vol3_x,vol3_y,volcanic2);
                else if(erupt_countdown%3==0)Blockviewport(vol3_x,vol3_y,volcanic3);
            Blockviewport(vol3_x+1,vol3_y,ground_fire_MiddleR);
            Blockviewport(vol3_x-1,vol3_y+1,ground_fire_BottomL);
            Blockviewport(vol3_x,vol3_y+1,ground_fire_BottomM);
            Blockviewport(vol3_x+1,vol3_y+1,ground_fire_BottomR);
            SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
        }
    }
    vol3alone=false;
    if(erupt_countdown<800)
    {
        if((minion->get_minion_position_x()>=(vol3_x*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=(vol3_x*BLOCK_WIDTH-25))&&
            (minion->get_minion_position_y()>=(vol3_y*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=(vol3_y*BLOCK_HEIGHT-17)))
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
                vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                vol3alone=true;
                erupt_countdown=0;
        }
    }
    if(random_erupt==3)
    {
        vol3erupt=false;
        if(800<erupt_countdown&&erupt_countdown<2000)
        {
            if((minion->get_minion_position_x()>=((vol3_x-1)*BLOCK_WIDTH-25))&&(minion->get_minion_position_x()<=((vol3_x+2)*BLOCK_WIDTH-25))&&
                (minion->get_minion_position_y()>=((vol3_y-1)*BLOCK_HEIGHT-17))&&(minion->get_minion_position_y()<=((vol3_y+2)*BLOCK_HEIGHT-17)))
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
                    vol1_x=rand()%14+1;vol1_y=rand()%8+1;vol2_x=rand()%14+1;vol2_y=rand()%8+1;vol3_x=rand()%14+1;vol3_y=rand()%8+1;

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
                  vol3erupt=true;
                  erupt_countdown=0;
            }

        }
    }
    if(erupt_countdown==2000){erupt_countdown=0;random_erupt=rand()%3;}
    erupt_countdown++;
    SDL_RenderSetViewport( gRenderer, NULL ); //important!!!!Reset viewport!!!!!!
}
bool hurt_of_volcanoes(bool &vol1alone,bool &vol1erupt,bool &vol2alone,bool &vol2erupt,bool &vol3alone,bool &vol3erupt){return (vol1alone||vol1erupt||vol2alone||vol2erupt||vol3alone||vol3erupt);}


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


