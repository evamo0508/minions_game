//Using SDL, SDL_image, standard IO, and strings
#include "init.cpp"
#include "loadmedia.cpp"
#include "smoothmove_jump.cpp"
#include "random_ground_banana_hurt_reward.cpp"
#include "npc_fire.cpp"
#include "start.cpp"
#include "volcano.cpp"
#include "temp_ground.cpp"
#include "HP.h"

int main( int argc, char* args[] )
{
    Dot minion;
    srand(time(0));
  // NPC_FIREBALL fireball2(BLOCK_WIDTH,BLOCK_WIDTH*2);//fireball's start position

    static int run_number=0;
    int first=1,banana_position=rand()%15+1,fireball_start_y=rand()%8+1,change_firegun_position=0,temp_firegun_position,hp_width=200,next_vol_countdown=0;
    bool hurt=false,change_dir=false,next=false,hurt_of_volcanoes=false;
    typedef unsigned long clock_t;
    NPC_FIREBALL fireball(BLOCK_WIDTH,BLOCK_HEIGHT*fireball_start_y);//fireball's start position
    volcano vol1(rand()%14+1,rand()%8+1),vol2(rand()%14+1,rand()%8+1),vol3(rand()%14+1,rand()%8+1);//generate 3 volcanoes
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{

	    //Load media
		if(first){loadMedia();gDotTexture.loadFromFile( "pic/minion.png" );}

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;
            Mix_PlayMusic( gMusic_music1, -1 );
			//First page
			while( !quit && (!next)){
                Start();
                while( SDL_PollEvent( &e ) != 0 ){
                    if( e.type == SDL_QUIT ){quit = true;break;}
					start_handleEvent(e,&next);}
			}
            next=false;

			Next();
			//Next page
			while( !quit && (!next)){
                SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_first_page, NULL, NULL );
				// SDL_RenderPresent( gRenderer );
                for(int i=0;i<7;i++){
                    Blockviewport(i,3,ground);
                    Blockviewport(i,5,ground);
                }
                fireball.handleEvent_next();
                fireball.move_next();
                fireball.render(0,3);
                build_fire_next();
                if(next_vol_countdown<=800){Blockviewport(5,4,ground_fire_BottomL);Blockviewport(5,4,volcanic1);SDL_RenderSetViewport( gRenderer, NULL );next_vol_countdown++; SDL_RenderPresent( gRenderer );}
                if(800<next_vol_countdown&&next_vol_countdown<2000)
                {
                    Blockviewport(4,3,ground_fire_TopL);
                    Blockviewport(5,3,ground_fire_TopM);
                    Blockviewport(6,3,ground_fire_TopR);
                    Blockviewport(4,4,ground_fire_MiddleL);
                    Blockviewport(5,4,ground_fire_MiddleM);
                        //volcano animation when exploding
                        if(next_vol_countdown%3==1)Blockviewport(5,4,volcanic1);
                        else if(next_vol_countdown%3==2)Blockviewport(5,4,volcanic2);
                        else if(next_vol_countdown%3==0)Blockviewport(5,4,volcanic3);
                    Blockviewport(6,4,ground_fire_MiddleR);
                    Blockviewport(4,5,ground_fire_BottomL);
                    Blockviewport(5,5,ground_fire_BottomM);
                    Blockviewport(6,5,ground_fire_BottomR);
                    //SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                    next_vol_countdown++;
                     SDL_RenderPresent( gRenderer );
                    //

				//SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                    //
                }
                if(next_vol_countdown==2000)
                {
                    next_vol_countdown=0;

                SDL_RenderSetViewport( gRenderer, NULL );}//important!!!!Reset viewport!!!!!!


                //SDL_RenderPresent( gRenderer );
                while( SDL_PollEvent( &e ) != 0 ){
                    if( e.type == SDL_QUIT ){quit = true;break;}
                    next_handleEvent(e,&next);}
			}
			SDL_DestroyTexture( gTexture_first_page );
            gTexture_first_page = NULL;
            //change the music
            Mix_PauseMusic();
            Mix_PlayMusic( gMusic_music2, -1 );
			//While application is running
			while( !quit )
			{


			    //dominate execution velocity
                clock_t  t =  clock();
                change_firegun_position++;

				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					minion.handleEvent( e,&change_dir );
				}

if(hp_width>0 && hp_width<Total_HP){

//Ground
for(int i=0;i<16;i++){
  for(int j=0;j<10;j++){
            Blockviewport(i,j,ground);
    }
}

//Shoe
Shoe(&minion,hurt,&hp_width);

//temp ground
temp_ground( &hp_width, & minion, &hurt);


//Medicine
medicine_dir(&minion,hurt,change_dir,&hp_width);

//obs_fire
build_fire(first);
SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!


vol1.volcano_alone(volcanic1);
vol2.volcano_alone(volcanic2);
vol3.volcano_alone(volcanic3);
//random_erupt(vol1,vol2,vol3);
switch(vol1.random_erupt)
{
    case 0:hurt_of_volcanoes=vol1.eruption().volcano_erupt_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position);break;
    case 1:hurt_of_volcanoes=vol2.eruption().volcano_erupt_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position);break;
    case 2:hurt_of_volcanoes=vol3.eruption().volcano_erupt_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position);break;
}

//Fireball
if(change_firegun_position==3000){
    change_firegun_position=0;
    temp_firegun_position=fireball_start_y;
    banana_position=rand()%15+1;
    do{fireball_start_y=rand()%8+1;}while(temp_firegun_position==fireball_start_y);
}

fireball.handleEvent();
fireball.move();
fireball.render(0,fireball_start_y);

//Minion
        if(!hurt)minion.move();
        minion.render();

//Banana
hurt=Banana(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position)||
Banana_fireball(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position)||
vol1.volcano_alone_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position)||
vol2.volcano_alone_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position)||
vol3.volcano_alone_kill(&hp_width,&minion,fireball.get_fireball_position_x(),fireball_start_y*BLOCK_HEIGHT,&banana_position)||
hurt_of_volcanoes;

HP_decrease(&hp_width);
HP(hp_width);
HP_block();

//reset volcano position if hurt
if(hurt){vol1.change();vol2.change();vol3.change();}

//Update screen
        SDL_RenderPresent( gRenderer );

//dominate execution velocity
t=clock()-t;
if(10.0*t<1)SDL_Delay(0.1-t);
first=0;

//delay per four times
if(run_number==3){SDL_Delay(1);run_number=0;}
else{run_number++;}

}
else if(hp_width<=0){
Mix_HaltMusic();
Lose();
}
else if(hp_width>=Total_HP){
Mix_HaltMusic();
Win();
}
        }

	//Free resources and close SDL
	close();
    //Free loaded images
	gDotTexture.free();
	return 0;
}
}

