#include "../inc/snake.hpp"
#include "../inc/play_state.hpp"

void Snake::move()
{
    tail_.push_front(position_);

    if(position_.x <  prg::application.getScreenWidth() && position_.x > 0 && position_.y < prg::application.getScreenHeight() && position_.y > 0){


            switch(direction_){

            case Direction::North:
                position_.y += 10;
                break;
            case Direction::East:
                position_.x += 10;
                break;
            case Direction::South:
                position_.y -= 10;
                break;
            case Direction::West:
                position_.x -= 10;
                break;
            }


            if(growthRate == 0)
            {
                tail_.pop_back();
            }else
            {
                growthRate--;
                tailSize ++;
            }
        }else{
            prg::application.setState("win_state");
        }
    }


void Snake::changeDirection(Direction new_direction)
{
    direction_ = new_direction;
}

void Snake::render(prg::Canvas& canvas) const
{
  canvas.drawCircle(
    position_.x,
    position_.y,
    5,
    prg::Colour::RED
  );
  for(auto pos : tail_){
  canvas.drawCircle(
    pos.x,
    pos.y,
    4,
    prg::Colour::RED);
    }
}

void Snake::RemoveTail(int dif){
    for(int i = 0; i < dif; i++){
        tail_.pop_back();
    }
    tailSize = minTailSize;
}
void Snake::Collision(){
    for (auto pos:tail_){
        if(position_.x == pos.x && position_.y == pos.y){
            prg::application.setState("gameover_state");
        }
    }
}

