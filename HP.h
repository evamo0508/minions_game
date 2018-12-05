
void HP(int hp_width){
static SDL_Texture* gTexture_hp_banana= loadTexture( "pic/hp_banana.png" );
SDL_Rect Viewport;
				Viewport.x = 10;
				Viewport.y = 10;
				Viewport.w = hp_width;
				Viewport.h = 23;
				SDL_RenderSetViewport( gRenderer, &Viewport );
				SDL_RenderCopy( gRenderer, gTexture_hp_banana, NULL, NULL );
			//	SDL_RenderPresent( gRenderer );
}

void HP_decrease(int *hp_width){
static int loss=60;
if(loss==60){
    loss=0;
    *hp_width-=1;
}
loss++;
}
