#include <ctime>
#include <cstdlib>
void temp_ground(int *banana, Dot* minion,bool* hurt)
{
    static int tempground_x[4]={rand()%15+1,rand()%15+1,rand()%15+1,rand()%15+1},tempground_y[4]={rand()%10,rand()%10,rand()%10,rand()%10},stand_time[4]={0,0,0,0},dis_time[4]={0,0,0,0};
    static bool stand_on[4]={false,false,false,false},dis_start[4]={false,false,false,false};
    for(int a=0;a<4;a++)
    {
        //minion stand on the temp ground
        if(stand_on[a]){
            stand_time[a]++;
        }
        else{stand_time[a]=0;}
        // the ground dis
        if(dis_start[a]){
            dis_time[a]++;
            if(dis_time[a]==300 ){
                dis_start[a]=false;
                dis_time[a]=0;

                //minion die or not
                if(stand_on[a]){
                    (*banana)--;SDL_RenderSetViewport( gRenderer, NULL );
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
                    for(int i=0;i<3;i++){
                        SDL_RenderSetViewport( gRenderer, NULL );//important!!!!Reset viewport!!!!!!
                        if(*banana>=(i+1))
                        Blockviewport(i,0,banana_pic);
                    }

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
                   *hurt=true;
                }
                else{*hurt=false;}
                //new temp groumd
                tempground_x[a]=rand()%15+1,tempground_y[a]=rand()%10;
                SDL_RenderPresent( gRenderer );
            }
        }

    /*********************************/


        for(int i=0;i<amount_of_obs_fire;i++){
           // SDL_RenderSetViewport( gRenderer, NULL );
            //minion stand on temp ground
            if((fabs(tempground_x[a]*BLOCK_WIDTH-minion->get_minion_position_x())<=BLOCK_WIDTH-25)&&
                (fabs(tempground_y[a]*BLOCK_HEIGHT-minion->get_minion_position_y())<=BLOCK_HEIGHT-17)){
                stand_on[a]=true;
                dis_start[a]=true;
                SDL_RenderSetViewport( gRenderer, NULL );
                while((ground_fire[0][i]==tempground_x[a])&&(ground_fire[1][i]==tempground_y[a])){tempground_x[a]=rand()%15+1;tempground_y[a]=rand()%10;}
            }
            else{
                stand_on[a]=false;
                SDL_RenderSetViewport( gRenderer, NULL );
                while((ground_fire[0][i]==tempground_x[a])&&(ground_fire[1][i]==tempground_y[a])){tempground_x[a]=rand()%15+1;tempground_y[a]=rand()%10;}
            }
        }
        //dis or dis2 pic
        if(dis_start[a]){
            if(dis_time[a]<200)Blockviewport(tempground_x[a],tempground_y[a],dis2);
            if(dis_time[a]>=200&&dis_time[a]<225)Blockviewport(tempground_x[a],tempground_y[a],obs_fire_a);
            if(dis_time[a]>=225&&dis_time[a]<250)Blockviewport(tempground_x[a],tempground_y[a],dis2);
            if(dis_time[a]>=250&&dis_time[a]<275)Blockviewport(tempground_x[a],tempground_y[a],obs_fire_a);
            if(dis_time[a]>=275&&dis_time[a]<300)Blockviewport(tempground_x[a],tempground_y[a],dis2);
        }
        else{
            Blockviewport(tempground_x[a],tempground_y[a],dis);
        }


    }
    return ;
}
