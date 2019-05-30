#include "../inc/dropoff.hpp"
#include <string>

void DropOff::render(prg::Canvas& canvas) const{

//Left Goal
   for(int i = 0; i <= 50; i++){
            canvas.drawLine(i,400, i, 200, prg::Colour::BLACK);
    }
  std::string PlayerScoreText = ("Player's score " + std::to_string(playerScore));

    prg::uint text_dims[2];
  prg::Font::MEDIUM.computePrintDimensions(text_dims, PlayerScoreText);
  prg::Font::MEDIUM.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 - 200,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 275,
    prg::Colour::BLACK,
    PlayerScoreText);


//Right Goal
    for(int i = 750; i <= 800; i++){
            canvas.drawLine(i,400, i, 200, prg::Colour::BLACK);
    }

  std::string AIScoreText = ("AI's score " + std::to_string(AIScore));


  prg::Font::MEDIUM.computePrintDimensions(text_dims, AIScoreText);
  prg::Font::MEDIUM.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 + 200,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 275,
    prg::Colour::BLACK,
    AIScoreText);





}


void DropOff::PlayerScores(Snake& snake_){

//LeftGoal
if(snake_.position_.x > 0 && snake_.position_.x < 50 && snake_.position_.y > 200 && snake_.position_.y < 400 && !scored){
    if(snake_.tailSize > snake_.minTailSize){
        scored = true;
        diff = snake_.tailSize -= snake_.minTailSize;
        playerScore += diff;
        snake_.RemoveTail(diff);
        }
    }else{
        scored = false;
    }
}

void DropOff::AIScores(Snake& snake_){
//RIght Goal
if(snake_.position_.x > 750 && snake_.position_.x < 800 && snake_.position_.y > 200 && snake_.position_.y < 400 && !scored){
        if(snake_.tailSize > snake_.minTailSize){
        scored = true;
        diff = snake_.tailSize -= snake_.minTailSize;
        AIScore += diff;
        snake_.RemoveTail(diff);
        }
    }else{
        scored = false;
    }
}




