#include "../inc/snake.hpp"
#include "../inc/play_state.hpp"
#include "../inc/AISnake.hpp"
#include "../inc/collectables.hpp"
#include <time.h>
#include <stdlib.h>

void AISnake::Update(){

    if(closestFruit.x == NULL){
        hasTarget = false;
    }

    if(stepx == 0 && stepy == 0){
        hasTarget = false;
        stepx = 1000;
        stepy = 1000;
    }

    if(hasTarget == false){
        hasTarget = true;
        closestFruit = fruit_.getClosest(position_);
    }  else if(hasTarget == true){
            if(stepx == 0){
                if(closestFruit.y > position_.y){
                    stepy = (closestFruit.y - position_.y) / 10;
                    moveAI(stepy, Direction::North);
                }else{
                        stepy = (position_.y - closestFruit.y) / 10;
                        moveAI(stepy, Direction::South);
                  }
            }else {
                if(closestFruit.x > position_.x){
                    stepx = (closestFruit.x - position_.x) / 10;
                    moveAI(stepx, Direction::East);
                }else {
                    stepx = (position_.x - closestFruit.x) / 10;
                    moveAI(stepx, Direction::West);
                  }
              }
        }

    if(tailSize >= randomTail){
        closestFruit.x = 775;
        closestFruit.y = 275;
        RandomTail();
    }
}

void AISnake::moveAI(int step, Direction dir){
    if(step >= 1){
        step--;
        changeDirection(dir);
        move();
    }else{
        Update();
        move();
    }
}
void AISnake::RandomTail(){
    randomTail = ((rand() % 7 + 3));
}




