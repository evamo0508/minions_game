#include <ctime>
#include <cmath>
#include <cstdlib>
//#include "HP.h"
#define amount_of_obs_fire 60

void Start(void);
void Next(void);
void Lose(void);
void Win(void);
void HP(int width);
void HP_block(void);
void build_fire_next(void);
void Blockviewport(float x,float y,int texture);
void build_fire(bool first);
void Shoe(Dot* minion,bool hurt,int* hp_width);
void medicine_dir(Dot* minion,bool hurt,bool &change_dir,int* hp_width);
bool Banana(int *banana,Dot* minion,int fireball_x,int fireball_y,int* banana_position);
bool Banana_fireball(int *banana,Dot* minion,int fireball_x,int fireball_y,int* banana_position);
int ground_fire[2][amount_of_obs_fire];
extern bool new_press;

void Start(void){
SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_first_page, NULL, NULL );
				SDL_RenderPresent( gRenderer );
}


void Next(void){
gTexture_first_page= loadTexture( "pic/next_page.png" );
SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_first_page, NULL, NULL );
				SDL_RenderPresent( gRenderer );
}

void Lose(void){
SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_lose, NULL, NULL );
				SDL_RenderPresent( gRenderer );
}

void Win(void){
SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_win, NULL, NULL );
				SDL_RenderPresent( gRenderer );
}

void HP_block(void){
SDL_Rect Viewport;
				Viewport.x = 10;
				Viewport.y = 10;
				Viewport.w = Total_HP;
				Viewport.h = 23;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_hp_block, NULL, NULL );
}
/**
void HP(int hp_width){
SDL_Texture* gTexture_hp_banana= loadTexture( "pic/hp_banana.png" );
SDL_Rect Viewport;
				Viewport.x = 10;
				Viewport.y = 10;
				Viewport.w = hp_width;
				Viewport.h = 23;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_hp_banana, NULL, NULL );
				SDL_RenderPresent( gRenderer );
}
**/
void Blockviewport(float x,float y,int texture){
SDL_Rect Viewport;
				Viewport.x = x*BLOCK_WIDTH;
				Viewport.y = y*BLOCK_HEIGHT;
				Viewport.w = BLOCK_WIDTH;
				Viewport.h = BLOCK_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				if(texture==ground)
				SDL_RenderCopy( gRenderer, gTexture_ground, NULL, NULL );
				else if(texture==obs_fire_a)
				SDL_RenderCopy( gRenderer, gTexture_obs_fire_a, NULL, NULL );
				else if(texture==obs_fire_b)
				SDL_RenderCopy( gRenderer, gTexture_obs_fire_b, NULL, NULL );
				else if(texture==obs_fire_c)
				SDL_RenderCopy( gRenderer, gTexture_obs_fire_c, NULL, NULL );
				else if(texture==dis)
				SDL_RenderCopy( gRenderer, gTexture_dis, NULL, NULL );
				else if(texture==npc[0])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[1])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[2])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[3])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[4])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[5])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[6])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[7])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==npc[8])
				SDL_RenderCopy( gRenderer, gTexture_npc_ice_bear0, NULL, NULL );
				else if(texture==minion_run)
				SDL_RenderCopy( gRenderer, gTexture_minion_run, NULL, NULL );
				else if(texture==banana_pic)
				SDL_RenderCopy( gRenderer, gTexture_banana, NULL, NULL );
				else if(texture==firegun)
				SDL_RenderCopy( gRenderer, gTexture_npc_fire_firegun, NULL, NULL );
				else if(texture==shoe)
				SDL_RenderCopy( gRenderer, gTexture_shoe, NULL, NULL );
				else if(texture==volcanic1)
				SDL_RenderCopy( gRenderer, gTexture_volcanic1, NULL, NULL );
				else if(texture==volcanic2)
				SDL_RenderCopy( gRenderer, gTexture_volcanic2, NULL, NULL );
				else if(texture==volcanic3)
				SDL_RenderCopy( gRenderer, gTexture_volcanic3, NULL, NULL );
				else if(texture==ground_fire_BottomL)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_BottomL, NULL, NULL );
				else if(texture==ground_fire_BottomM)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_BottomM, NULL, NULL );
				else if(texture==ground_fire_BottomR)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_BottomR, NULL, NULL );
				else if(texture==ground_fire_MiddleL)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_MiddleL, NULL, NULL );
				else if(texture==ground_fire_MiddleM)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_MiddleM, NULL, NULL );
				else if(texture==ground_fire_MiddleR)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_MiddleR, NULL, NULL );
				else if(texture==ground_fire_TopL)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_TopL, NULL, NULL );
				else if(texture==ground_fire_TopM)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_TopM, NULL, NULL );
				else if(texture==ground_fire_TopR)
				SDL_RenderCopy( gRenderer, gTexture_ground_fire_TopR, NULL, NULL );
				else if(texture==dis2)
				SDL_RenderCopy( gRenderer, gTexture_dis2, NULL, NULL );
				else if(texture==medicine)
				SDL_RenderCopy( gRenderer, gTexture_medicine, NULL, NULL );
				else if(texture==hp_block)
				SDL_RenderCopy( gRenderer, gTexture_hp_block, NULL, NULL );


}

void build_fire(bool first){
    static int type_of_obs_fire,change_of_obs_fire=0;
//Fire animation
    if(first){
        srand(time(0));
        //x
        for(int i=0;i<amount_of_obs_fire;i++)ground_fire[0][i]=rand()%15+1;
        //y
        for(int i=0;i<amount_of_obs_fire;i++)ground_fire[1][i]=rand()%9;//last row shouldn't have any obs
    }

    if(change_of_obs_fire==30){type_of_obs_fire=rand()%3;change_of_obs_fire=0;}//frequency of fire animation

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

change_of_obs_fire++;
}

void build_fire_next(void){
    static int type_of_obs_fire,change_of_obs_fire=0;
//Fire animation
    if(change_of_obs_fire==60){type_of_obs_fire=rand()%3;change_of_obs_fire=0;}//frequency of fire animation

        for(int i=0;i<7;i++){
             switch(type_of_obs_fire){
                case 0:
                Blockviewport(i,4,obs_fire_a);break;
                case 1:
                Blockviewport(i,4,obs_fire_b);break;
                case 2:
                Blockviewport(i,4,obs_fire_c);break;
            }
        }

change_of_obs_fire++;
}

bool Banana(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int* banana_position){
    bool hurt=false;
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    for(int i=0;i<amount_of_obs_fire;i++){
        //remember: ground_fire[0][i]*BLOCK_WIDTH!!!Not just ground_fire[0][i]!!!
//minion get into lava
        if((fabs((ground_fire[0][i])*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
           (fabs((ground_fire[1][i])*BLOCK_HEIGHT-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
              (*hp_width)-=LOSS;SDL_RenderSetViewport( gRenderer, NULL );
                //clear corpse
                    //Ground
                        for(int i=0;i<16;i++){
                            for(int j=0;j<10;j++){
                                Blockviewport(i,j,ground);
                                    }
                                        }
                    Blockviewport(0,1,firegun);
                    //obs_fire
                        build_fire(0);
                            SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!


                //Eat banana
                if((fabs((*banana_position)*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
                (fabs(fireball_y-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
                *banana_position=rand()%15+1;(*hp_width)+=EAT;if(*hp_width>Total_HP)*hp_width=Total_HP;
                }

                //Banana fall into lava
                while((ground_fire[0][i]==(*banana_position))&&(ground_fire[1][i]==fireball_y/BLOCK_HEIGHT)){
                *banana_position=rand()%15+1;SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
                }

                //put banana
                Blockviewport(*banana_position,fireball_y/BLOCK_HEIGHT,banana_pic);

                //Banana_123
                HP(*hp_width);
                HP_block();

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
               hurt=true;break;
    }
//Banana fall into lava
                while((ground_fire[0][i]==(*banana_position))&&(ground_fire[1][i]==fireball_y/BLOCK_HEIGHT)){
                *banana_position=rand()%15+1;SDL_RenderSetViewport( gRenderer, NULL );//Reset viewport every time!!!!!!!!
                }
//Eat banana
                if((fabs((*banana_position)*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
                (fabs(fireball_y-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
                *banana_position=rand()%15+1;(*hp_width)+=EAT;if(*hp_width>Total_HP)*hp_width=Total_HP;
                }

    }





    //put banana
                Blockviewport(*banana_position,fireball_y/BLOCK_HEIGHT,banana_pic);

    //Banana_123
                HP(*hp_width);
                HP_block();

    SDL_RenderPresent( gRenderer );
    return hurt;
}



bool Banana_fireball(int *hp_width,Dot* minion,int fireball_x,int fireball_y,int* banana_position){
    bool hurt=false;
    SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!

        if(((fabs(fireball_x-minion->get_minion_position_x())<=BLOCK_WIDTH-25))&&
           (fabs(fireball_y-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
               (*hp_width)-=LOSS;SDL_RenderSetViewport( gRenderer, NULL );
                //clear corpse
                    //Ground
                        for(int i=0;i<16;i++){
                            for(int j=0;j<10;j++){
                                Blockviewport(i,j,ground);
                                    }
                                        }
                    Blockviewport(0,1,firegun);
                    //obs_fire
                        build_fire(0);
                            SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!


                //Banana
                HP(*hp_width);
                HP_block();
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
//Banana_reward
                //Blockviewport(*banana_position,fireball_y/BLOCK_HEIGHT,banana_pic);

//Banana
                HP(*hp_width);
                HP_block();
    return hurt;
}

void Shoe(Dot* minion,bool hurt,int* hp_width){
  //  SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
    static int shoe_x=rand()%15+1,shoe_y=rand()%10,execution_time=0,change_shoe_position=0;
    static bool get_shoe=false;
    if(get_shoe){
        execution_time++;
        if(execution_time==1000 || hurt){
            minion->change_minion_velocity(1);
            get_shoe=false;
            execution_time=0;
        }
    }

/*********************************
frequency of change_shoe_position
**********************************/
    if(change_shoe_position==1700){shoe_x=rand()%15+1;shoe_y=rand()%10;change_shoe_position=0;}

    for(int i=0;i<amount_of_obs_fire;i++){
       // SDL_RenderSetViewport( gRenderer, NULL );
        //minion pick up shoe
        if((fabs(shoe_x*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
            (fabs(shoe_y*BLOCK_HEIGHT-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
                get_shoe=true;
                (*hp_width)+=EAT;if(*hp_width>Total_HP)*hp_width=Total_HP;
                minion->change_minion_velocity(2);

                shoe_x=rand()%15+1,shoe_y=rand()%10;

                //Shoe fall into lava
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                while((ground_fire[0][i]==shoe_x)&&(ground_fire[1][i]==shoe_y)){shoe_x=rand()%15+1;shoe_y=rand()%10;}

                //put shoe
                Blockviewport(shoe_x,shoe_y,shoe);
                SDL_RenderPresent( gRenderer );
        }
        //Shoe fall into lava
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                while((ground_fire[0][i]==shoe_x)&&(ground_fire[1][i]==shoe_y)){shoe_x=rand()%15+1;shoe_y=rand()%10;}
        Blockviewport(shoe_x,shoe_y,shoe);
    }
    change_shoe_position++;
    return;
}

void medicine_dir(Dot* minion,bool hurt,bool &change_dir,int* hp_width){
    static int medicine_x=rand()%15+1,medicine_y=rand()%10,execution_time=0,change_medicine_position=0;
    static bool get_medicine=false;
    if(get_medicine){
        execution_time++;
        if(execution_time==3000 || hurt){
            change_dir=false;
            get_medicine=false;
            execution_time=0;
        }
    }
/*********************************
frequency of change_medicine_position
**********************************/
    if(change_medicine_position==1400){medicine_x=rand()%15+1;medicine_y=rand()%10;change_medicine_position=0;}

    for(int i=0;i<amount_of_obs_fire;i++){
       // SDL_RenderSetViewport( gRenderer, NULL );
        //minion pick up medicine
        if((fabs(medicine_x*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
            (fabs(medicine_y*BLOCK_HEIGHT-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
                get_medicine=true;
                (*hp_width)+=EAT;if(*hp_width>Total_HP)*hp_width=Total_HP;
                change_dir=true;
                medicine_x=rand()%15+1,medicine_y=rand()%10;

                //medicine fall into lava
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                while((ground_fire[0][i]==medicine_x)&&(ground_fire[1][i]==medicine_y)){medicine_x=rand()%15+1;medicine_y=rand()%10;}

                //put medicine
                Blockviewport(medicine_x,medicine_y,medicine);
                SDL_RenderPresent( gRenderer );
        }
        //medicine fall into lava
                SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                while((ground_fire[0][i]==medicine_x)&&(ground_fire[1][i]==medicine_y)){medicine_x=rand()%15+1;medicine_y=rand()%10;}
        Blockviewport(medicine_x,medicine_y,medicine);
    }
    change_medicine_position++;
    return;
}
