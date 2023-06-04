#include <iostream>
#include <SDL2/SDL.h> // window and renderer and basic configure
#include <SDL2/SDL_image.h> // loading BitMap images on window
#include <SDL2/SDL2_gfx.h> // extra useful function
#include <string>
#include <math.h>

// by MohammadAmin Alamalhoda ma.alamalhoda@gmail.com

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);

using namespace std;


int main( int argc, char * argv[] )
{
    int W = 700;
    int L = 1200;

    // be ina kari nadashte bashid
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen res olution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);


    window_color(m_renderer,15,123,255);


    int level=4,strength[7][level];
    //tolid ajor
    for(int i=1;i<=7;i++){
        for(int j=1;j<=level;j++){
               strength[i-1][j-1] =rand()%20;
        if(strength[i-1][j-1]>5)
          rect(m_renderer,168*i-140,50*j-40,140,40,123,38,9,1);
    }
    }
     rect(m_renderer,530,650,140,30,59,255,15,1);


     int step=0;
     double height=0;


     ellipse(m_renderer,600,636,14,14,255,15,187,1);

   SDL_RenderPresent(m_renderer);




//harekat va zarbe ebtedaei
      SDL_Event *event=new SDL_Event();
   const Uint8 *mimm=SDL_GetKeyboardState(NULL);
   bool quit=false;
   while(!quit){
    SDL_PollEvent(event);
    while( SDL_PollEvent(event)){

        if(event->type==SDL_KEYDOWN){
             ellipse(m_renderer,600+step,636,14,14,15,123,255,1);
             rect(m_renderer,530+step,650,140,30,15,123,255,1);
            if(mimm[SDL_SCANCODE_D]){
                step+=5;
            }
            if(mimm[SDL_SCANCODE_A]){
                step-=5;
            }

            ellipse(m_renderer,600+step,636,14,14,255,15,187,1);
            rect(m_renderer,530+step,650,140,30,59,255,15,1);
             SDL_RenderPresent(m_renderer);
            if(mimm[SDL_SCANCODE_SPACE]){quit=true;}
        }

        }

}
int xbox=step;
//barkhord avval
for(height=0;height+636>=50*level+14;height-=0.5){
     ellipse(m_renderer,600+step,636+height+0.5,14,14,15,123,255,1);
     ellipse(m_renderer,600+step,636+height,14,14,255,15,187,1);
 SDL_RenderPresent(m_renderer);
  SDL_Event *event2=new SDL_Event();
   const Uint8 *sadd=SDL_GetKeyboardState(NULL);
  if( SDL_PollEvent(event2)){

        if(event2->type==SDL_KEYDOWN){
             rect(m_renderer,530+xbox,650,140,30,15,123,255,1);
            if(sadd[SDL_SCANCODE_D]){
                xbox+=5;
            }
            if(sadd[SDL_SCANCODE_A]){
                xbox-=5;
            }
            rect(m_renderer,530+xbox,650,140,30,59,255,15,1);
             SDL_RenderPresent(m_renderer);
        }
}
 }


double xam=0,yam=-0.5;
while(1==1){
for(int i=1;i<=7;i++){
    for(int j=level;j>0;j--){if(strength[i-1][j-1]>5){

        if(168*i-70-600-step<=70 && 168*i-70-600-step>=-70 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;xam=-xam;
        }
        if(168*i-70-600-step>-84 && 168*i-70-600-step<-70 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;xam=-xam;
        }
        if(168*i-70-600-step<=70 && 168*i-70-600-step>=-70 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
           yam=-yam;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
           yam=-yam;xam=-xam;
        }
        if(168*i-70-600-step>-84 && 168*i-70-600-step<-70 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
          yam=-yam;xam=-xam;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height<20 && 50*j-20-636-height>=-20){
            xam=-xam;
        }
        if(168*i-70-600-step<-70 && 168*i-70-600-step>=-84 && 50*j-20-636-height<20 && 50*j-20-636-height>=-20){
            xam=-xam;
        }
    }}}
 step+=xam;height+=yam;
 ellipse(m_renderer,600+step-xam,636+height-yam,14,14,15,123,255,1);
 ellipse(m_renderer,600+step,636+height,14,14,255,15,187,1);
         SDL_RenderPresent(m_renderer);
          SDL_Event *event3=new SDL_Event();
          const Uint8 *taa=SDL_GetKeyboardState(NULL);
          if( SDL_PollEvent(event3)){
        if(event3->type==SDL_KEYDOWN){
        rect(m_renderer,530+xbox,650,140,30,15,123,255,1);
        if(taa[SDL_SCANCODE_D]){
        xbox+=5;}
        if(taa[SDL_SCANCODE_A]){
        xbox-=5;}
        rect(m_renderer,530+xbox,650,140,30,59,255,15,1);
}}







}








SDL_Delay(4000);


 }












  void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;


    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
    SDL_RenderPresent(Renderer);

}







void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );

    // Show the window
    SDL_RenderPresent( Renderer );

}


 void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{
    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0)
        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);

}









