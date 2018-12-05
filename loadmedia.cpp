#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
int npc[9]={0,1,2,3,4,5,6,7,8};
enum name{ground=9,obs_fire_a=10,obs_fire_b=11,obs_fire_c=12,dis=14,minion_run=15,banana_pic=16,firegun=17,shoe=18,volcanic1=19,volcanic2=20,volcanic3=21,
ground_fire_BottomL=22,ground_fire_BottomM=23,ground_fire_BottomR=24,ground_fire_MiddleL=25,ground_fire_MiddleM=26,ground_fire_MiddleR=27,
ground_fire_TopL=28,ground_fire_TopM=29,ground_fire_TopR=30,dis2=31,medicine=32,hp_block=33};

//Loads media
void loadMedia(void);
void close(void);
SDL_Texture* loadTexture( std::string path );

//The music that will be played
Mix_Music *gMusic_music1 = NULL;
Mix_Music *gMusic_music2 = NULL;
//Current displayed texture
SDL_Texture* gTexture_ground = NULL;
SDL_Texture* gTexture_obs_fire_a = NULL;
SDL_Texture* gTexture_obs_fire_b = NULL;
SDL_Texture* gTexture_obs_fire_c = NULL;
SDL_Texture* gTexture_dis = NULL;
SDL_Texture* gTexture_npc_ice_bear0 = NULL;
SDL_Texture* gTexture_npc_ice_bear1 = NULL;
SDL_Texture* gTexture_npc_ice_bear2 = NULL;
SDL_Texture* gTexture_npc_ice_bear3 = NULL;
SDL_Texture* gTexture_npc_ice_bear4 = NULL;
SDL_Texture* gTexture_npc_ice_bear5 = NULL;
SDL_Texture* gTexture_npc_ice_bear6 = NULL;
SDL_Texture* gTexture_npc_ice_bear7 = NULL;
SDL_Texture* gTexture_npc_ice_bear8 = NULL;
SDL_Texture* gTexture_minion_run = NULL;
SDL_Texture* gTexture_banana = NULL;
SDL_Texture* gTexture_npc_fire_firegun=NULL;
SDL_Texture* gTexture_shoe=NULL;
SDL_Texture* gTexture_volcanic1=NULL;
SDL_Texture* gTexture_volcanic2=NULL;
SDL_Texture* gTexture_volcanic3=NULL;
SDL_Texture* gTexture_ground_fire_BottomL=NULL;
SDL_Texture* gTexture_ground_fire_BottomM=NULL;
SDL_Texture* gTexture_ground_fire_BottomR=NULL;
SDL_Texture* gTexture_ground_fire_MiddleL=NULL;
SDL_Texture* gTexture_ground_fire_MiddleM=NULL;
SDL_Texture* gTexture_ground_fire_MiddleR=NULL;
SDL_Texture* gTexture_ground_fire_TopL=NULL;
SDL_Texture* gTexture_ground_fire_TopM=NULL;
SDL_Texture* gTexture_ground_fire_TopR=NULL;
SDL_Texture* gTexture_dis2=NULL;
SDL_Texture* gTexture_medicine=NULL;
SDL_Texture* gTexture_hp_block=NULL;
SDL_Texture* gTexture_win=NULL;
SDL_Texture* gTexture_lose=NULL;
SDL_Texture* gTexture_first_page=NULL;
void loadMedia()
{
    //Load music
	gMusic_music1 = Mix_LoadMUS( "music/music1.wav" );
	if( gMusic_music1 == NULL )
	{
		printf( "Failed to load beat music!" );
	}
	gMusic_music2 = Mix_LoadMUS( "music/music2.wav" );
	if( gMusic_music2 == NULL )
	{
		printf( "Failed to load beat music!" );
	}

	gTexture_ground = loadTexture( "pic/ground_fire.png" );
	if( gTexture_ground == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_obs_fire_a = loadTexture( "pic/obs_fire_a.png" );
	if( gTexture_obs_fire_a == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}


	gTexture_obs_fire_b = loadTexture( "pic/obs_fire_b.png" );
	if( gTexture_obs_fire_b == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}


	gTexture_obs_fire_c = loadTexture( "pic/obs_fire_c.png" );
	if( gTexture_obs_fire_c == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_dis = loadTexture( "pic/dis_fire_before.png" );
	if( gTexture_dis == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear0 = loadTexture( "pic/npc_ice_bear0.png" );
	if( gTexture_npc_ice_bear0 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear1 = loadTexture( "pic/npc_ice_bear1.png" );
	if( gTexture_npc_ice_bear1 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear2 = loadTexture( "pic/npc_ice_bear2.png" );
	if( gTexture_npc_ice_bear2 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear3 = loadTexture( "pic/npc_ice_bear3.png" );
	if( gTexture_npc_ice_bear3 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear4 = loadTexture( "pic/npc_ice_bear4.png" );
	if( gTexture_npc_ice_bear4 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear5 = loadTexture( "pic/npc_ice_bear5.png" );
	if( gTexture_npc_ice_bear5 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear6 = loadTexture( "pic/npc_ice_bear6.png" );
	if( gTexture_npc_ice_bear6 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear7 = loadTexture( "pic/npc_ice_bear7.png" );
	if( gTexture_npc_ice_bear7 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_npc_ice_bear8 = loadTexture( "pic/npc_ice_bear8.png" );
	if( gTexture_npc_ice_bear8 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

    gTexture_minion_run = loadTexture( "pic/minion_run.png" );
	if( gTexture_minion_run == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

	gTexture_banana = loadTexture( "pic/banana.png" );
	if( gTexture_banana == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

    gTexture_npc_fire_firegun = loadTexture( "pic/firegun.png" );
	if( gTexture_npc_fire_firegun == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

    gTexture_shoe = loadTexture( "pic/shoe.png" );
	if( gTexture_shoe == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}

    gTexture_volcanic1 = loadTexture( "pic/volcanic1.png" );
	if( gTexture_volcanic1 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_volcanic2 = loadTexture( "pic/volcanic2.png" );
	if( gTexture_volcanic2 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_volcanic3 = loadTexture( "pic/volcanic3.png" );
	if( gTexture_volcanic3 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_BottomL = loadTexture( "pic/ground_fire_BottomL.png" );
	if( gTexture_ground_fire_BottomL == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_BottomM = loadTexture( "pic/ground_fire_BottomM.png" );
	if( gTexture_ground_fire_BottomM == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_BottomR = loadTexture( "pic/ground_fire_BottomR.png" );
	if( gTexture_ground_fire_BottomR == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_MiddleL = loadTexture( "pic/ground_fire_MiddleL.png" );
	if( gTexture_ground_fire_MiddleL == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_MiddleM = loadTexture( "pic/ground_fire_MiddleM.png" );
	if( gTexture_ground_fire_MiddleM == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_MiddleR = loadTexture( "pic/ground_fire_MiddleR.png" );
	if( gTexture_ground_fire_MiddleR == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_TopL = loadTexture( "pic/ground_fire_TopL.png" );
	if( gTexture_ground_fire_TopL == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
    gTexture_ground_fire_TopM = loadTexture( "pic/ground_fire_TopM.png" );
	if( gTexture_ground_fire_TopM == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_ground_fire_TopR = loadTexture( "pic/ground_fire_TopR.png" );
	if( gTexture_ground_fire_TopR == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_dis2 = loadTexture( "pic/dis_fire_after.png" );
	if( gTexture_dis2 == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_medicine = loadTexture( "pic/medicine.png" );
	if( gTexture_medicine == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_hp_block = loadTexture( "pic/hp_block.png" );
	if( gTexture_medicine == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_win = loadTexture( "pic/win.png" );
	if( gTexture_medicine == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_lose = loadTexture( "pic/lose.png" );
	if( gTexture_lose == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}
	gTexture_first_page = loadTexture( "pic/first_page.png" );
	if( gTexture_first_page == NULL )
	{
		printf( "Failed to load texture image!\n" );
	}


}

SDL_Texture* loadTexture( std::string path )
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return newTexture;
}

void close()
{
    //Free the music
	Mix_FreeMusic( gMusic_music1 );
	gMusic_music1 = NULL;
	Mix_FreeMusic( gMusic_music2 );
	gMusic_music2 = NULL;


	//Free loaded image
	SDL_DestroyTexture( gTexture_ground );
	SDL_DestroyTexture( gTexture_obs_fire_a );
	SDL_DestroyTexture( gTexture_obs_fire_b );
	SDL_DestroyTexture( gTexture_obs_fire_c );
	SDL_DestroyTexture( gTexture_dis );
	SDL_DestroyTexture( gTexture_npc_ice_bear0 );
	SDL_DestroyTexture( gTexture_npc_ice_bear1 );
	SDL_DestroyTexture( gTexture_npc_ice_bear2 );
	SDL_DestroyTexture( gTexture_npc_ice_bear3 );
	SDL_DestroyTexture( gTexture_npc_ice_bear4 );
	SDL_DestroyTexture( gTexture_npc_ice_bear5 );
	SDL_DestroyTexture( gTexture_npc_ice_bear6 );
	SDL_DestroyTexture( gTexture_npc_ice_bear7 );
	SDL_DestroyTexture( gTexture_npc_ice_bear8 );
	SDL_DestroyTexture( gTexture_minion_run );
	SDL_DestroyTexture( gTexture_banana );
	SDL_DestroyTexture( gTexture_npc_fire_firegun );
	SDL_DestroyTexture( gTexture_shoe );
	SDL_DestroyTexture( gTexture_volcanic1 );
	SDL_DestroyTexture( gTexture_volcanic2 );
	SDL_DestroyTexture( gTexture_volcanic3 );
	SDL_DestroyTexture( gTexture_ground_fire_BottomL );
	SDL_DestroyTexture( gTexture_ground_fire_BottomM );
	SDL_DestroyTexture( gTexture_ground_fire_BottomR );
	SDL_DestroyTexture( gTexture_ground_fire_MiddleL );
	SDL_DestroyTexture( gTexture_ground_fire_MiddleM );
	SDL_DestroyTexture( gTexture_ground_fire_MiddleR );
	SDL_DestroyTexture( gTexture_ground_fire_TopL );
	SDL_DestroyTexture( gTexture_ground_fire_TopM );
	SDL_DestroyTexture( gTexture_ground_fire_TopR );
	SDL_DestroyTexture( gTexture_dis2 );
	SDL_DestroyTexture( gTexture_medicine );
	SDL_DestroyTexture( gTexture_hp_block );
	SDL_DestroyTexture( gTexture_win );
	SDL_DestroyTexture( gTexture_lose );
	SDL_DestroyTexture( gTexture_first_page );
	gTexture_ground = NULL;
	gTexture_obs_fire_a = NULL;
	gTexture_obs_fire_b = NULL;
	gTexture_obs_fire_c = NULL;
	gTexture_dis = NULL;
    gTexture_npc_ice_bear0 = NULL;
    gTexture_npc_ice_bear1 = NULL;
    gTexture_npc_ice_bear2 = NULL;
    gTexture_npc_ice_bear3 = NULL;
    gTexture_npc_ice_bear4 = NULL;
    gTexture_npc_ice_bear5 = NULL;
    gTexture_npc_ice_bear6 = NULL;
    gTexture_npc_ice_bear7 = NULL;
    gTexture_npc_ice_bear8 = NULL;
    gTexture_minion_run = NULL;
    gTexture_banana = NULL;
    gTexture_npc_fire_firegun = NULL;
    gTexture_shoe = NULL;
    gTexture_volcanic1 = NULL;
    gTexture_volcanic2 = NULL;
    gTexture_volcanic3 = NULL;
    gTexture_ground_fire_BottomL = NULL;
    gTexture_ground_fire_BottomM = NULL;
    gTexture_ground_fire_BottomR = NULL;
    gTexture_ground_fire_MiddleL = NULL;
    gTexture_ground_fire_MiddleM = NULL;
    gTexture_ground_fire_MiddleR = NULL;
    gTexture_ground_fire_TopL = NULL;
    gTexture_ground_fire_TopM = NULL;
    gTexture_ground_fire_TopR = NULL;
    gTexture_dis2 = NULL;
    gTexture_medicine = NULL;
    gTexture_win = NULL;
    gTexture_hp_block = NULL;
    gTexture_lose = NULL;
    gTexture_first_page = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	Mix_Quit();
	IMG_Quit();
	SDL_Quit();
}
