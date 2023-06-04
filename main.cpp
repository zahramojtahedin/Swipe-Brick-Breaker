#include <iostream>
#include<SDL2/SDL.h>
#include<stdbool.h>
#include<SDL2/SDL_ttf.h>
#include<math.h>
#include<string>
static const int width=1200;
static const int height=800;
int jump=10,paddle_width=70,paddle_height=12,ball_width=15,row=1,col=10,spacing=4,brick_height=12,ball_speed=15,font_size=12,level=1;
int score=0,dammage=1,strength,kick,game_hight=0;
std::string text="";
int main(int argc ,char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("brick break",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_OPENGL);
    SDL_Renderer  *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
    int m=1,n=10,completed=1,lives=3;
    float speed_x=-sqrt(5),speed_y=-sqrt(5);
    float brick_width= (float) (width-(n)*spacing)/n;
    float sq_speed;
    int bricks[m][n];
    double rel,norm,bounce;
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                    strength=dammage;
                bricks[i][j]=strength;
            }
        }

    SDL_Rect paddle,ball,brick;
    SDL_Color color;
    TTF_Font *font;


    //paddle(hamoon choobe bazi raket ya harchizi ke esmesh hast!
    paddle.w=paddle_width;
    paddle.h=paddle_height;
    paddle.x = width/2 - paddle_width/2;
    paddle.y = height - 50;
    //ball
    ball.w=ball_width;
    ball.h=ball_width;
    ball.x=width/2 - ball_width/2;
    ball.y=paddle.y-ball_width;

    //intializing font:
    TTF_Init();
    font = TTF_OpenFont("font.ttf",font_size);
    color.r=255;
    color.g=255;
    color.b=255;
    bool running = true,start=false;

    while(running){
        //write:
         text = "lives: "+std::to_string(lives)+" "+"level: "+std::to_string(level)+" score: "+std::to_string(score);
        const char* t =text.c_str();
        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, t, color);
        SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        int text_width= surfaceMessage->w;
        int text_height=surfaceMessage->h;
        SDL_Rect Message_rect;
        Message_rect.x = width/2-text_width;
        Message_rect.y = height-(text_height+15);
        Message_rect.w = text_width;
        Message_rect.h = text_height;


        //input
            SDL_Event e;
            const Uint8 *keystates = SDL_GetKeyboardState(NULL);
            while(SDL_PollEvent(&e)){
                if  (e.type ==SDL_QUIT){
                    running=false;
                }
                if(keystates[SDL_SCANCODE_SPACE]){
                    start=true;
                }
                if(keystates[SDL_SCANCODE_LEFT]){
                    paddle.x -=jump;
                }
                if(keystates[SDL_SCANCODE_RIGHT]){
                    paddle.x +=jump;
                }
            }

    //game logic
        //age coob khord be divar
        if(paddle.x<0){
            paddle.x=0;
        }
        //age choob khord be divar
        if(paddle.x>=width-paddle_width){
            paddle.x=width-paddle_width;
        }
        //age toop khord be divar
        if(ball.x<0){
            speed_x = -speed_x;
        }
        //age toop kord  be divar
        if(ball.x>width-ball_width){
            speed_x=-speed_x;
        }
        //age toop khord be saghf
        if(ball.y<0){
            speed_y=-speed_y;
        }
        //age toop khord zamin
        if(ball.y>height){
            paddle.x = width/2 - paddle_width/2;
            paddle.y = height - 50;
            ball.x=width/2 - ball_width/2;
            ball.y=paddle.y-ball_width;
            speed_x=sqrt(5),speed_y=-sqrt(5);
            lives--;
        }
        //age toop khord be divar
        if(ball.y==0&&ball.x<0){
            speed_x=sqrt(5);
            speed_y=sqrt(5);
        }
        //age toop khord be gooshe
        if(ball.y==0&&ball.x>width-ball.w){
            speed_x=-sqrt(5);
            speed_y=sqrt(5);
        }
        //age toop barkhord kard ba choob
        if(SDL_HasIntersection(&ball,&paddle)){
             rel = (paddle.x+(paddle_width/2))-(ball.x+(ball_width/2));
             norm = rel/(paddle.w);
            bounce = norm*(5*3.14/12);
            speed_y= -ball_speed*cos(bounce);
            speed_x= ball_speed*-sin(bounce);
            sq_speed = sqrt(pow(speed_x,2)+pow(speed_y,2));
            speed_x = speed_x*5/sq_speed;
            speed_y = speed_y*5/sq_speed;
        }

        SDL_Delay(20);
        if(start){
            ball.x +=speed_x;
            ball.y +=speed_y;

        }
        //calculate game height:
        game_hight=0;
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++)
            {
                if(bricks[i][j]>0){
                    game_hight +=brick_height;
                    break;
                }
            }
        }
        if(game_hight>1100){
            running=0;
        }










        //clear screen
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        //draw
        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        SDL_RenderFillRect(renderer,&paddle);
        SDL_RenderFillRect(renderer,&ball);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(bricks[i][j]>0){
                   brick.h=brick_height;
                   brick.w=brick_width;
                   brick.y = (i+1)*spacing+i*brick.h;
                   brick.x = (((j)+1)*spacing)+((j)*brick.w);
                   SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
                   SDL_SetRenderDrawColor(renderer,255,255,255,255-(int)(level-bricks[i][j])/level*255);
                   SDL_RenderFillRect(renderer,&brick);

                   if(SDL_HasIntersection(&ball,&brick)){

                        if(ball.x>brick.x && ball.x<brick.x+brick_width){
                            speed_y = -speed_y;
                        }
                        else{
                            speed_x = -speed_x;
                        }
                        score+=level;
                        kick = bricks[i][j]-dammage>0?bricks[i][j]-dammage:bricks[i][j];
                        bricks[i][j]= bricks[i][j]-dammage>0?bricks[i][j]-dammage:0;
                        if(dammage-kick>0){
                            dammage=dammage-kick;
                        }
                        else{
                            m++;
                            level++;
                            dammage=level;
                            strength=level;
                            int new_bricks[m][n];
                            for(int i=0;i<m;i++){
                                for(int j=0;j<n;j++){
                                    if(i==0){
                                        new_bricks[i][j]=strength;
                                    }
                                    else{
                                        new_bricks[i][j]=bricks[i][j];
                                    }
                                }
                            }
                            for(int i=0;i<m;i++){
                                for(int j=0;j<n;j++){
                                    bricks[i][j]=new_bricks[i][j];
                                }
                            }
                           ball.y = ball.y+6*brick_height;
                        }
                   }
                }
            }
        }

        if(lives<0){
            running=0;
        }


        SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

        SDL_FreeSurface(surfaceMessage);
        SDL_DestroyTexture(Message);

        //show what was drawn
        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
