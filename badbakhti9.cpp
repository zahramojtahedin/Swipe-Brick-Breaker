#include <iostream>
#include <SDL2/SDL.h> // window and renderer and basic configure
#include <SDL2/SDL_image.h> // loading BitMap images on window
#include <SDL2/SDL2_gfx.h> // extra useful function
#include <string>
#include <math.h>
#include <time.h>
#include <fstream>
// by MohammadAmin Alamalhoda ma.alamalhoda@gmail.com

void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
void print_one_digit(int X,int Y,int R,SDL_Renderer *renderer);

using namespace std;


int main( int argc, char * argv[] )
{string namekarbar;
cout<<"enter your name:";
cin>>namekarbar;
int difficulty;
cout<<"difficukty from 2 to ... :";
cin>>difficulty;
    int W = 700;
    int L = 1200;
string color;
cout<<"choose the color of ball(blue,red,green,black,pink,orange,golden,gray):";
cin>>color;
double xam=0,yam=-0.5;
double jahat;
cout<<"choose the first Vx(0.05,0.1,0.2,0.25,0.5,1,...):";
cin>>jahat;
xam=jahat;
int r,g,b;
if(color=="blue"){r=0;g=0;b=255;}
if(color=="red"){r=255;g=0;b=0;}
if(color=="green"){r=0;g=255;b=0;}
if(color=="black"){r=0;g=0;b=0;}
if(color=="pink"){r=255;g=20;b=147;}
if(color=="orange"){r=255;g=69;b=0;}
if(color=="golden"){r=184;g=134;b=11;}
if(color=="gray"){r=211;g=211;b=211;}



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

    SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
    window_color(m_renderer,15,123,255);


    int level=1,strength[7][1000];
    //tolid ajor
    srand(time(0));
    for(int i=1;i<=7;i++){
        for(int j=1;j<=level;j++){
               strength[i-1][j-1] =rand()%20;
        if(strength[i-1][j-1]>5)
          rect(m_renderer,168*i-140,50*j-40,140,40,123,38,9,1);
    }
    }
     rect(m_renderer,530,650,140,30,59,255,15,1);


     double step=0;
     double height=0;


     ellipse(m_renderer,600,636,14,14,r,g,b,1);

   SDL_RenderPresent(m_renderer);


SDL_Texture *img;
int w_img,h_img;
img=IMG_LoadTexture(m_renderer,"scores.png");
SDL_QueryTexture(img,NULL,NULL,&w_img,&h_img);
SDL_Rect img_rect;
img_rect.x=1060;
img_rect.y=600;
img_rect.h=50;
img_rect.w=50;
SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
SDL_RenderPresent(m_renderer);

SDL_Texture *img2;
int w_img2,h_img2;
img2=IMG_LoadTexture(m_renderer,"ghermez.png");
SDL_QueryTexture(img2,NULL,NULL,&w_img2,&h_img2);
SDL_Rect img2_rect;
img2_rect.x=1060;
img2_rect.y=550;
img2_rect.h=50;
img2_rect.w=50;
SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);

SDL_Texture *img3;
int w_img3,h_img3;
img3=IMG_LoadTexture(m_renderer,"zard.png");
SDL_QueryTexture(img3,NULL,NULL,&w_img3,&h_img3);
SDL_Rect img3_rect;
img3_rect.x=1060;
img3_rect.y=550;
img3_rect.h=50;
img3_rect.w=50;
SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);

SDL_Texture *img4;
int w_img4,h_img4;
img4=IMG_LoadTexture(m_renderer,"sabz.png");
SDL_QueryTexture(img4,NULL,NULL,&w_img4,&h_img4);
SDL_Rect img4_rect;
img4_rect.x=1060;
img4_rect.y=550;
img4_rect.h=50;
img4_rect.w=50;
SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);
SDL_RenderPresent(m_renderer);

SDL_Texture *img25;
int w_img25,h_img25;
img25=IMG_LoadTexture(m_renderer,"level15.png");
SDL_QueryTexture(img25,NULL,NULL,&w_img25,&h_img25);
SDL_Rect img25_rect;
img25_rect.x=1060;
img25_rect.y=500;
img25_rect.h=50;
img25_rect.w=50;
SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);

SDL_Texture *img24;
int w_img24,h_img24;
img24=IMG_LoadTexture(m_renderer,"level14.png");
SDL_QueryTexture(img24,NULL,NULL,&w_img24,&h_img24);
SDL_Rect img24_rect;
img24_rect.x=1060;
img24_rect.y=500;
img24_rect.h=50;
img24_rect.w=50;
SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);

SDL_Texture *img23;
int w_img23,h_img23;
img23=IMG_LoadTexture(m_renderer,"level13.png");
SDL_QueryTexture(img23,NULL,NULL,&w_img23,&h_img23);
SDL_Rect img23_rect;
img23_rect.x=1060;
img23_rect.y=500;
img23_rect.h=50;
img23_rect.w=50;
SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);

SDL_Texture *img22;
int w_img22,h_img22;
img22=IMG_LoadTexture(m_renderer,"level12.png");
SDL_QueryTexture(img22,NULL,NULL,&w_img22,&h_img22);
SDL_Rect img22_rect;
img22_rect.x=1060;
img22_rect.y=500;
img22_rect.h=50;
img22_rect.w=50;
SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);

SDL_Texture *img21;
int w_img21,h_img21;
img21=IMG_LoadTexture(m_renderer,"level11.png");
SDL_QueryTexture(img21,NULL,NULL,&w_img21,&h_img21);
SDL_Rect img21_rect;
img21_rect.x=1060;
img21_rect.y=500;
img21_rect.h=50;
img21_rect.w=50;
SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);

SDL_Texture *img20;
int w_img20,h_img20;
img20=IMG_LoadTexture(m_renderer,"level10.png");
SDL_QueryTexture(img20,NULL,NULL,&w_img20,&h_img20);
SDL_Rect img20_rect;
img20_rect.x=1060;
img20_rect.y=500;
img20_rect.h=50;
img20_rect.w=50;
SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);

SDL_Texture *img19;
int w_img19,h_img19;
img19=IMG_LoadTexture(m_renderer,"level9.png");
SDL_QueryTexture(img2,NULL,NULL,&w_img19,&h_img19);
SDL_Rect img19_rect;
img19_rect.x=1060;
img19_rect.y=500;
img19_rect.h=50;
img19_rect.w=50;
SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);

SDL_Texture *img18;
int w_img18,h_img18;
img18=IMG_LoadTexture(m_renderer,"level8.png");
SDL_QueryTexture(img18,NULL,NULL,&w_img18,&h_img18);
SDL_Rect img18_rect;
img18_rect.x=1060;
img18_rect.y=500;
img18_rect.h=50;
img18_rect.w=50;
SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);

SDL_Texture *img17;
int w_img17,h_img17;
img17=IMG_LoadTexture(m_renderer,"level7.png");
SDL_QueryTexture(img17,NULL,NULL,&w_img17,&h_img17);
SDL_Rect img17_rect;
img17_rect.x=1060;
img17_rect.y=500;
img17_rect.h=50;
img17_rect.w=50;
SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);

SDL_Texture *img16;
int w_img16,h_img16;
img16=IMG_LoadTexture(m_renderer,"level6.png");
SDL_QueryTexture(img16,NULL,NULL,&w_img16,&h_img16);
SDL_Rect img16_rect;
img16_rect.x=1060;
img16_rect.y=500;
img16_rect.h=50;
img16_rect.w=50;
SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);

SDL_Texture *img15;
int w_img15,h_img15;
img15=IMG_LoadTexture(m_renderer,"level5.png");
SDL_QueryTexture(img15,NULL,NULL,&w_img15,&h_img15);
SDL_Rect img15_rect;
img15_rect.x=1060;
img15_rect.y=500;
img15_rect.h=50;
img15_rect.w=50;
SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);

SDL_Texture *img14;
int w_img14,h_img14;
img14=IMG_LoadTexture(m_renderer,"level4.png");
SDL_QueryTexture(img14,NULL,NULL,&w_img14,&h_img14);
SDL_Rect img14_rect;
img14_rect.x=1060;
img14_rect.y=500;
img14_rect.h=50;
img14_rect.w=50;
SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);

SDL_Texture *img13;
int w_img13,h_img13;
img13=IMG_LoadTexture(m_renderer,"level3.png");
SDL_QueryTexture(img13,NULL,NULL,&w_img13,&h_img13);
SDL_Rect img13_rect;
img13_rect.x=1060;
img13_rect.y=500;
img13_rect.h=50;
img13_rect.w=50;
SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);

SDL_Texture *img12;
int w_img12,h_img12;
img12=IMG_LoadTexture(m_renderer,"level2.png");
SDL_QueryTexture(img12,NULL,NULL,&w_img12,&h_img12);
SDL_Rect img12_rect;
img12_rect.x=1060;
img12_rect.y=500;
img12_rect.h=50;
img12_rect.w=50;
SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);

SDL_Texture *img11;
int w_img11,h_img11;
img11=IMG_LoadTexture(m_renderer,"level1.png");
SDL_QueryTexture(img11,NULL,NULL,&w_img11,&h_img11);
SDL_Rect img11_rect;
img11_rect.x=1060;
img11_rect.y=500;
img11_rect.h=50;
img11_rect.w=50;
SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);

SDL_RenderPresent(m_renderer);


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

            ellipse(m_renderer,600+step,636,14,14,r,g,b,1);
            rect(m_renderer,530+step,650,140,30,59,255,15,1);
             SDL_RenderPresent(m_renderer);
              if(mimm[SDL_SCANCODE_SPACE]){quit=true;}
        }

        }

}
int xbox=step;
//barkhord avval
for(height=0;height+636>=50*level+14;height-=0.5){step+=xam;
     ellipse(m_renderer,600+step-xam,636+height+0.5,14,14,15,123,255,1);
     ellipse(m_renderer,600+step,636+height,14,14,r,g,b,1);
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
SDL_Delay(1);
 }
int damage=1,scores=0,lives=3;


while(lives!=0){
for(int i=1;i<=7;i++){
    for(int j=level;j>0;j--){if(strength[i-1][j-1]>5){

        if(168*i-70-600-step<=70 && 168*i-70-600-step>=-70 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
           damage-=1;scores+=level;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
           damage-=1;scores+=level;
        }
        if(168*i-70-600-step>-84 && 168*i-70-600-step<-70 && 50*j-20-636-height<20+14 && 50*j-20-636-height>=0){
           yam=-yam;xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
           damage-=1;scores+=level;
        }
        if(168*i-70-600-step<=70 && 168*i-70-600-step>=-70 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
           yam=-yam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
           damage-=1;scores+=level;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
           yam=-yam;xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
           damage-=1;scores+=level;
        }
        if(168*i-70-600-step>-84 && 168*i-70-600-step<-70 && 50*j-20-636-height>-20-14 && 50*j-20-636-height<=0){
          yam=-yam;xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
          damage-=1;scores+=level;
        }
        if(168*i-70-600-step>70 && 168*i-70-600-step<=84 && 50*j-20-636-height<20 && 50*j-20-636-height>=-20){
            xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
            damage-=1;scores+=level;
        }
        if(168*i-70-600-step<-70 && 168*i-70-600-step>=-84 && 50*j-20-636-height<20 && 50*j-20-636-height>=-20){
            xam=-xam;strength[i-1][j-1]-=20; if(strength[i-1][j-1]<5){rect(m_renderer,168*i-140,50*j-40,140,40,15,123,255,1);}
            damage-=1;scores+=level;
        }
    }}}
        if(530+xbox+32<=600+step && 530+xbox+108>=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
        }
        if(530+xbox+32>600+step && 530+xbox+12<=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=-0.1;
        }
        if(530+xbox+108<600+step && 530+xbox+128>=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=0.1;
        }
        if(530+xbox+12>600+step && 530+xbox+6<=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=-0.2;
        }
         if(530+xbox+6>600+step && 530+xbox<=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=-0.25;
        }
        if(530+xbox+134>=600+step && 530+xbox+128<600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=0.2;
        }
        if(530+xbox+140>=600+step && 530+xbox+134<600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=0.25;
        }
         if(530+xbox>600+step && 530+xbox-13<=600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=-0.5;
        }
         if(530+xbox+153>=600+step && 530+xbox+140<600+step && 636+height>635 && 636+height<650){
            yam=-0.5;
            xam=0.5;
        }
        if(step+600>=1185 || step+600<=15){
            xam=-xam;
        }

        if(636+height==14){
            yam=-yam;
        }


 step+=xam;height+=yam;

SDL_RenderCopy(m_renderer,img,NULL,&img_rect);


rect(m_renderer,1100,600,100,50,15,123,255,1);
if(scores<10){
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1100,600,scores,m_renderer);}

if(scores<100 && scores>=10){
       if(scores-level<10){
       }
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1100,600,scores/10,m_renderer);
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1130,600,scores%10,m_renderer);}

if(scores<1000 && scores>=100){
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1100,600,scores/100,m_renderer);
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1160,600,scores%10,m_renderer);
        SDL_SetRenderDrawColor(m_renderer,0,0,0,255);
        print_one_digit(1130,600,((int)(scores/10))%10,m_renderer);}








         SDL_RenderPresent(m_renderer);
          SDL_Event *event3=new SDL_Event();
          const Uint8 *taa=SDL_GetKeyboardState(NULL);
          if(SDL_PollEvent(event3)){
        if(event3->type==SDL_KEYDOWN){
        rect(m_renderer,530+xbox,650,140,30,15,123,255,1);
        if(taa[SDL_SCANCODE_D]){
        xbox+=5;}
        if(taa[SDL_SCANCODE_A]){
        xbox-=5;}
        rect(m_renderer,530+xbox,650,140,30,59,255,15,1);
         if(taa[SDL_SCANCODE_H]){
            for(int i=1;i<=7;i++){
                rect(m_renderer,168*i-140,50*1-40,140,40,15,123,255,1);
                strength[i-1][0]-=100;
                scores+=100;
            }
         }
         if(taa[SDL_SCANCODE_L]){
         lives=0;
         }
         if(taa[SDL_SCANCODE_P]){
                bool stoping=true;
         while(stoping){
             SDL_RenderPresent(m_renderer);
          SDL_Event *event15=new SDL_Event();
          const Uint8 *pause=SDL_GetKeyboardState(NULL);
          if(SDL_PollEvent(event15)){
        if(event15->type==SDL_KEYDOWN){
         if(pause[SDL_SCANCODE_P]){
                stoping=false;
         }}}}}



}}

       if(damage==0){level+=1;damage=level;
        for(int i=1;i<=7;i++){
            for(int j=level;j>1;j--){
                strength[i-1][j-1]=strength[i-1][j-2];
               if(strength[i-1][j-1]>5){
                rect(m_renderer,168*i-140,50*(j-1)-40,140,40,15,123,255,1);
                 rect(m_renderer,168*i-140,50*j-40,140,40,123,38,9,1);
            }}
        }
        srand(time(0));
        for(int i=1;i<=7;i++){
            strength[i-1][0]=rand()%20;

            if(strength[i-1][0]>5){
                rect(m_renderer,168*i-140,50*1-40,140,40,123,38,9,1);
            }
        }
        for(int i=1;i<difficulty;i++){
       srand(time(0));
       strength[rand()%7][0]+=20;
       }
       }
       if(height+636>=715){lives-=1;if(lives==3){SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);}
                                    if(lives==2){SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);}
                                    if(lives==1){SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);}
                                     if(level==1){SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);}
                                    if(level==2){SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);}
                                    if(level==3){SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);}
                                     if(level==4){SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);}
                                    if(level==5){SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);}
                                    if(level==6){SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);}
                                     if(level==7){SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);}
                                    if(level==8){SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);}
                                    if(level==9){SDL_RenderCopy(m_renderer,img19,NULL,&img19_rect);}
                                     if(level==10){SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);}
                                    if(level==11){SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);}
                                    if(level==12){SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);}
                                     if(level==13){SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);}
                                    if(level==14){SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);}
                                    if(level==15){SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);}
                                    SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
                                    if(lives==0)break;
        rect(m_renderer,530+xbox,650,140,30,15,123,255,1);
        xbox=0;xam=0;
        step=0;height=0;
         rect(m_renderer,530,650,140,30,59,255,15,1);
         ellipse(m_renderer,600,636,14,14,r,g,b,1);
         SDL_RenderPresent(m_renderer);
        SDL_Event *event10=new SDL_Event();
   const Uint8 *quff=SDL_GetKeyboardState(NULL);
   bool bye=false;
   while(!bye){
    SDL_PollEvent(event10);
    while( SDL_PollEvent(event10)){

        if(event10->type==SDL_KEYDOWN){
             ellipse(m_renderer,600+step,636,14,14,15,123,255,1);
             rect(m_renderer,530+step,650,140,30,15,123,255,1);
            if(quff[SDL_SCANCODE_D]){
                step+=5;
            }
            if(quff[SDL_SCANCODE_A]){
                step-=5;
            }

            ellipse(m_renderer,600+step,636,14,14,r,g,b,1);
            rect(m_renderer,530+step,650,140,30,59,255,15,1);

            if(quff[SDL_SCANCODE_SPACE]){bye=true;}
        }
                                    if(lives==3){SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);}
                                    if(lives==2){SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);}
                                    if(lives==1){SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);}
                                     if(level==1){SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);}
                                    if(level==2){SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);}
                                    if(level==3){SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);}
                                     if(level==4){SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);}
                                    if(level==5){SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);}
                                    if(level==6){SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);}
                                     if(level==7){SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);}
                                    if(level==8){SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);}
                                    if(level==9){SDL_RenderCopy(m_renderer,img19,NULL,&img19_rect);}
                                     if(level==10){SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);}
                                    if(level==11){SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);}
                                    if(level==12){SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);}
                                     if(level==13){SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);}
                                    if(level==14){SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);}
                                    if(level==15){SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);}
                                    SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
                                    SDL_RenderPresent(m_renderer);
        }

}
xbox=step;
//barkhord avval
for(height=0;height+636>=50*level+14;height-=0.5){
     ellipse(m_renderer,600+step,636+height+0.5,14,14,15,123,255,1);
     ellipse(m_renderer,600+step,636+height,14,14,r,g,b,1);
     yam=-0.5;
                                    if(lives==3){SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);}
                                    if(lives==2){SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);}
                                    if(lives==1){SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);}
                                     if(level==1){SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);}
                                    if(level==2){SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);}
                                    if(level==3){SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);}
                                     if(level==4){SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);}
                                    if(level==5){SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);}
                                    if(level==6){SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);}
                                     if(level==7){SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);}
                                    if(level==8){SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);}
                                    if(level==9){SDL_RenderCopy(m_renderer,img19,NULL,&img19_rect);}
                                     if(level==10){SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);}
                                    if(level==11){SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);}
                                    if(level==12){SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);}
                                     if(level==13){SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);}
                                    if(level==14){SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);}
                                    if(level==15){SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);}
                                    SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
 SDL_RenderPresent(m_renderer);
  SDL_Event *event11=new SDL_Event();
   const Uint8 *alef=SDL_GetKeyboardState(NULL);
  if( SDL_PollEvent(event11)){

        if(event11->type==SDL_KEYDOWN){
             rect(m_renderer,530+xbox,650,140,30,15,123,255,1);
            if(alef[SDL_SCANCODE_D]){
                xbox+=5;
            }
            if(alef[SDL_SCANCODE_A]){
                xbox-=5;
            }
            rect(m_renderer,530+xbox,650,140,30,59,255,15,1);

        }
}
                                    if(lives==3){SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);}
                                    if(lives==2){SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);}
                                    if(lives==1){SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);}
                                     if(level==1){SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);}
                                    if(level==2){SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);}
                                    if(level==3){SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);}
                                     if(level==4){SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);}
                                    if(level==5){SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);}
                                    if(level==6){SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);}
                                     if(level==7){SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);}
                                    if(level==8){SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);}
                                    if(level==9){SDL_RenderCopy(m_renderer,img19,NULL,&img19_rect);}
                                     if(level==10){SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);}
                                    if(level==11){SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);}
                                    if(level==12){SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);}
                                     if(level==13){SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);}
                                    if(level==14){SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);}
                                    if(level==15){SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);}
                                    SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
                                    SDL_RenderPresent(m_renderer);
SDL_Delay(1);
 }
 }ellipse(m_renderer,600+step-xam,636+height-yam,14,14,15,123,255,1);
 ellipse(m_renderer,600+step,636+height,14,14,r,g,b,1);

                                    if(lives==3){SDL_RenderCopy(m_renderer,img4,NULL,&img4_rect);}
                                    if(lives==2){SDL_RenderCopy(m_renderer,img3,NULL,&img3_rect);}
                                    if(lives==1){SDL_RenderCopy(m_renderer,img2,NULL,&img2_rect);}
                                    if(level==1){SDL_RenderCopy(m_renderer,img11,NULL,&img11_rect);}
                                    if(level==2){SDL_RenderCopy(m_renderer,img12,NULL,&img12_rect);}
                                    if(level==3){SDL_RenderCopy(m_renderer,img13,NULL,&img13_rect);}
                                     if(level==4){SDL_RenderCopy(m_renderer,img14,NULL,&img14_rect);}
                                    if(level==5){SDL_RenderCopy(m_renderer,img15,NULL,&img15_rect);}
                                    if(level==6){SDL_RenderCopy(m_renderer,img16,NULL,&img16_rect);}
                                     if(level==7){SDL_RenderCopy(m_renderer,img17,NULL,&img17_rect);}
                                    if(level==8){SDL_RenderCopy(m_renderer,img18,NULL,&img18_rect);}
                                    if(level==9){SDL_RenderCopy(m_renderer,img19,NULL,&img19_rect);}
                                     if(level==10){SDL_RenderCopy(m_renderer,img20,NULL,&img20_rect);}
                                    if(level==11){SDL_RenderCopy(m_renderer,img21,NULL,&img21_rect);}
                                    if(level==12){SDL_RenderCopy(m_renderer,img22,NULL,&img22_rect);}
                                     if(level==13){SDL_RenderCopy(m_renderer,img23,NULL,&img23_rect);}
                                    if(level==14){SDL_RenderCopy(m_renderer,img24,NULL,&img24_rect);}
                                    if(level==15){SDL_RenderCopy(m_renderer,img25,NULL,&img25_rect);}
                                    SDL_RenderCopy(m_renderer,img,NULL,&img_rect);
SDL_Delay(1);
for(int i=1;i<=7;i++){
            for(int j=level;j>1;j--){
                if(strength[i-1][j-1]>5 && 50*j>=600){lives=0;}}}
}


if(lives==0){SDL_Texture *img5;
int w_img5,h_img5;
img5=IMG_LoadTexture(m_renderer,"gameover.png");
SDL_QueryTexture(img5,NULL,NULL,&w_img5,&h_img5);
SDL_Rect img5_rect;
img5_rect.x=0;
img5_rect.y=0;
img5_rect.h=600;
img5_rect.w=1200;
SDL_RenderCopy(m_renderer,img5,NULL,&img5_rect);
SDL_RenderPresent(m_renderer);}


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


void print_one_digit(int X,int Y,int R,SDL_Renderer *renderer){

    if (R==0) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
    }
    if (R==1) {
        SDL_RenderDrawLine(renderer, X+17, Y+40, X+17, Y+10);
    }
    if (R==2) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+5, Y+40);
    }
    if (R==3) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
    }
    if (R==4) {
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+20, X+30, Y+20);
    }
    if (R==5) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+25);
        SDL_RenderDrawLine(renderer, X+30, Y+25, X+30, Y+40);
    }
    if (R==6) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+25, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
    }
    if (R==7) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+5, Y+40);
    }
    if (R==8) {
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
        SDL_RenderDrawLine(renderer, X+5, Y+25, X+30, Y+25);
        SDL_RenderDrawLine(renderer, X+5, Y+40, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+40);
    }
    if (R==9) {
        SDL_RenderDrawLine(renderer, X+30, Y+10, X+30, Y+40);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+5, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+20, X+30, Y+20);
        SDL_RenderDrawLine(renderer, X+5, Y+10, X+30, Y+10);
    }

}












