#include "../inc/collectables.hpp"
#include <time.h>
#include <stdlib.h>


void collectables::Collectables()
{
    //ctor
}

void collectables::render(prg::Canvas& canvas) const
{
    for(auto pos : fruit_){
      canvas.drawCircle(
        pos.x,
        pos.y,
        4,
        prg::Colour::BLACK
      );
    }
}

void collectables::FruitCollision(Snake& snake_){
    for(auto iter = fruit_.begin(); iter != fruit_.end(); ++iter){
        if(snake_.position_.x == iter->x && snake_.position_.y == iter->y){
            iter = fruit_.erase(iter);
            snake_.growthRate++;
            AddFruit();
        }
    }
}

void collectables::ListFruit(){

    for(int i = 0; i < 5;i++){

        XCord = ((rand() % 60)*10)+ 100;
        YCord = ((rand() % 40)*10)+ 100;

        fruitPosition_= {XCord,YCord};
        fruit_.push_front(fruitPosition_);
    }
}

void collectables::AddFruit(){

         XCord = ((rand() % 60)*10)+ 100;
         YCord = ((rand() % 40)*10)+ 100;

        fruitPosition_= {XCord,YCord};
        fruit_.push_front(fruitPosition_);

}



Position collectables::getClosest(const Position& Snake)
{
    Position closest = {1000,1000};
        for (auto pos : fruit_){
            if(Snake.x == pos.x){
                continue;
            }else if(Snake.x > pos.x){
                    int diffx = Snake.x - pos.x;
                    int diffy = Snake.y - pos.y;

                    if(diffx == closest.x){
                        if(diffy >= closest.y){
                            continue;
                        }else if(diffy < closest.y){
                                closest = pos;
                            }
                    }else if(diffx < closest.x){
                            closest = pos;
                        }
                }else if(Snake.x < pos.x){
                    int diffx = pos.x - Snake.x;
                    int diffy = pos.y - Snake.y;

                    if(diffx == closest.x){
                        if(diffy >= closest.y){
                            continue;
                        }else if(diffy < closest.y){
                                closest = pos;
                            }
                    }else if(diffx < closest.x){
                            closest = pos;
                        }
                }
            }
    return closest;
}
