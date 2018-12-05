#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
//#include"loadmedia.cpp"
//const int SCREEN_WIDTH = 992;
//const int SCREEN_HEIGHT = 620;
const int BLOCK_WIDTH = SCREEN_WIDTH/16;
const int BLOCK_HEIGHT = SCREEN_HEIGHT/10;
const int MINION_WIDTH = BLOCK_WIDTH;
const int MINION_HEIGHT = BLOCK_HEIGHT;

//extern SDL_Renderer* gRenderer = NULL;

class Dot
{
    public:

		//The dimensions of the dot
		static const int DOT_WIDTH = MINION_WIDTH;
		static const int DOT_HEIGHT = MINION_HEIGHT;

		//Initializes the variables
		Dot();

		//Takes key presses and adjusts the dot's velocity
		void handleEvent( SDL_Event& e, bool* change_dir);

		//Moves the dot
		void move();

		//Shows the dot on the screen
		void render(void);

		void change_minion_position(int change_p_mPosx,int change_p_mPosy);
		void change_minion_velocity(int velocity);


		int get_minion_position_x(void){return mPosX;}
		int get_minion_position_y(void){return mPosY;}

    private:
		//The X and Y offsets of the dot
		int mPosX, mPosY;

		//The velocity of the dot
		int mVelX, mVelY;

		/*********************************
        ->change the velocity of minion!!!!
        *********************************/
		//Maximum axis velocity of the dot
		double DOT_VEL = 1;
};

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		#ifdef _SDL_TTF_H
		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
		#endif

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};
LTexture gDotTexture;

Dot::Dot()
{
    //Initialize the offsets
    mPosX = 0;
    mPosY = SCREEN_HEIGHT-MINION_HEIGHT;

    //Initialize the velocity
    mVelX = 0;
    mVelY = 0;
}

void Dot::handleEvent( SDL_Event& e, bool* change_dir){
if(*change_dir){
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_DOWN) ){
                mPosY-=2*BLOCK_HEIGHT;if(mPosY<0)mPosY=0;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_UP) ){
                mPosY+=2*BLOCK_HEIGHT;if(mPosY>SCREEN_HEIGHT-BLOCK_HEIGHT)mPosY=SCREEN_HEIGHT-BLOCK_HEIGHT;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_LEFT) ){
                mPosX+=2*BLOCK_HEIGHT;if(mPosX>SCREEN_WIDTH-BLOCK_WIDTH)mPosX=SCREEN_WIDTH-BLOCK_WIDTH;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_RIGHT) ){
                mPosX-=2*BLOCK_HEIGHT;if(mPosX<0)mPosX=0;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }

        else switch( e.key.keysym.sym )
        {
            case SDLK_DOWN: mVelY -= DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_UP: mVelY += DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_RIGHT: mVelX -= DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_LEFT: mVelX += DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            //case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_DOWN: mVelY =0; gDotTexture.loadFromFile( "pic/minion.png" );  break;
            case SDLK_UP: mVelY =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
            case SDLK_RIGHT: mVelX =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
            case SDLK_LEFT: mVelX =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
        }
    }
}



else if(!(*change_dir)){
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_UP) ){
                mPosY-=2*BLOCK_HEIGHT;if(mPosY<0)mPosY=0;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_DOWN) ){
                mPosY+=2*BLOCK_HEIGHT;if(mPosY>SCREEN_HEIGHT-BLOCK_HEIGHT)mPosY=SCREEN_HEIGHT-BLOCK_HEIGHT;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_RIGHT) ){
                mPosX+=2*BLOCK_HEIGHT;if(mPosX>SCREEN_WIDTH-BLOCK_WIDTH)mPosX=SCREEN_WIDTH-BLOCK_WIDTH;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }
        else if( (e.key.keysym.mod&KMOD_CTRL)&&(e.key.keysym.sym==SDLK_LEFT) ){
                mPosX-=2*BLOCK_HEIGHT;if(mPosX<0)mPosX=0;
                gDotTexture.loadFromFile( "pic/minion_run.png" );
        }

        else switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY -= DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_DOWN: mVelY += DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_LEFT: mVelX -= DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
            case SDLK_RIGHT: mVelX += DOT_VEL; gDotTexture.loadFromFile( "pic/minion_run.png" ); break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            //case SDLK_UP: mVelY += DOT_VEL; break;
            case SDLK_UP: mVelY =0; gDotTexture.loadFromFile( "pic/minion.png" );  break;
            case SDLK_DOWN: mVelY =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
            case SDLK_LEFT: mVelX =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
            case SDLK_RIGHT: mVelX =0; gDotTexture.loadFromFile( "pic/minion.png" ); break;
        }
    }
}
}

void Dot::move()
{
    //Move the dot left or right
    mPosX += mVelX;

    //If the dot went too far to the left or right
    if( ( mPosX < 0 ) || ( mPosX + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        mPosX -= mVelX;
    }

    //Move the dot up or down
    mPosY += mVelY;

    //If the dot went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
}

void Dot::render()
{
    //Show the dot
    SDL_RenderSetViewport( gRenderer, NULL );
    gDotTexture.render( mPosX, mPosY );
}

void Dot::change_minion_position(int change_p_mPosx,int change_p_mPosy){
SDL_RenderSetViewport( gRenderer, NULL );
mPosX=change_p_mPosx;mPosY=change_p_mPosy;
SDL_RenderSetViewport( gRenderer, NULL );
}

void Dot::change_minion_velocity(int velocity){
DOT_VEL=velocity;
}

LTexture::LTexture()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

LTexture::~LTexture()
{
	//Deallocate
	free();
}

bool LTexture::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

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
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			/*********************************
			->change the size of minion!!!!
			*********************************/
			mWidth = MINION_WIDTH;
			mHeight = MINION_HEIGHT;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LTexture::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void LTexture::setColor( Uint8 red, Uint8 green, Uint8 blue )
{
	//Modulate texture rgb
	SDL_SetTextureColorMod( mTexture, red, green, blue );
}

void LTexture::setBlendMode( SDL_BlendMode blending )
{
	//Set blending function
	SDL_SetTextureBlendMode( mTexture, blending );
}

void LTexture::setAlpha( Uint8 alpha )
{
	//Modulate texture alpha
	SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LTexture::getWidth()
{
	return mWidth;
}

int LTexture::getHeight()
{
	return mHeight;
}
