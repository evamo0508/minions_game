#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>


//SDL_Texture* loadTexture( std::string path );
//gTexture_first_page = loadTexture( "pic/ground_fire.png" );
/**
void start(void){
    SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_first_page, NULL, NULL );
				SDL_RenderPresent( gRenderer );

}

void next(void){
SDL_Rect Viewport;
				Viewport.x = 0;
				Viewport.y = 0;
				Viewport.w = SCREEN_WIDTH;
				Viewport.h = SCREEN_HEIGHT;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				if(texture==first_page)SDL_RenderCopy( gRenderer, gTexture_ground, NULL, NULL );

}
**/

void start_handleEvent( SDL_Event& e,bool *next){
    //If a key was pressed
	if(( e.type == SDL_KEYDOWN && e.key.repeat == 0)||e.type == SDL_MOUSEBUTTONDOWN)
    {
        //Adjust the velocity
            *next=true;//SDL_DestroyTexture( gTexture_first_page );gTexture_first_page = NULL;
    }
}

void next_handleEvent( SDL_Event& e,bool *next){
    //If a key was pressed
	if(( e.type == SDL_KEYDOWN && e.key.repeat == 0)||e.type == SDL_MOUSEBUTTONDOWN)
    {
        //Adjust the velocity
            *next=true;//SDL_DestroyTexture( gTexture_first_page );gTexture_first_page = NULL;
    }
}


