#include "../inc/play_state.hpp"

#include <string>


bool PlayState::onCreate()
{
  return true;
}

bool PlayState::onDestroy()
{
  return true;
}

void PlayState::onEntry()
{

    playerSnake_.tail_.clear();
    collectables_.fruit_.clear();
    playerSnake_.growthRate = 3;
    playerSnake_.tailSize = 0;
    playerSnake_.position_ = {50,50};
    AISnake_.position_ = {750,50};
    playerSnake_.changeDirection(Direction::North);

  prg::application.addKeyListener(*this);
  movementTimer_.start();
  collectables_.ListFruit();

  gameTimer = 90;
}

void PlayState::onExit()
{
  prg::application.removeKeyListener(*this);
    movementTimer_.stop();
    shared_data_.PlayerScore = dropoff_.playerScore;
    shared_data_.AIScore = dropoff_.AIScore;
}

void PlayState::onUpdate()
{
    if (gameTimer == -1){
            prg::application.setState("win_state");

    }
playerSnake_.Collision();
collectables_.FruitCollision(playerSnake_);
collectables_.FruitCollision(AISnake_);

}

void PlayState::onRender(prg::Canvas& canvas)
{
  std::string text = ("Time : " + std::to_string(gameTimer));

  prg::uint text_dims[2];
  prg::Font::MEDIUM.computePrintDimensions(text_dims, text);
  prg::Font::MEDIUM.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 ,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 275,
    prg::Colour::BLACK,
    text);


//Draws the objects on screen
    dropoff_.render(canvas);
    playerSnake_.render(canvas);
    AISnake_.render(canvas);
    collectables_.render(canvas);
}

bool PlayState::onKey(const prg::IKeyEvent::KeyEvent& key_event)
{
  if(key_event.key_state == KeyEvent::KB_DOWN) {
    switch(key_event.key) {
    case 'w':
      playerSnake_.changeDirection(Direction::North);
      break;
    case 'd':
      playerSnake_.changeDirection(Direction::East);
      break;
    case 's':
      playerSnake_.changeDirection(Direction::South);
      break;
    case 'a':
      playerSnake_.changeDirection(Direction::West);
      break;
    case KeyEvent::KB_ESC_KEY:
        prg::application.exit();
      break;
    case 'p':
        dropoff_.AIScore++;
    break;
    }
  }

  return true;
}
  void PlayState::onTimer(prg::Timer& timer)
  {
    dropoff_.PlayerScores(playerSnake_);
    dropoff_.AIScores(AISnake_);
      playerSnake_.move();
      AISnake_.Update();
      timeCalc += 0.2;
      if(timeCalc == 1.0f){
        timeCalc = 0;
        gameTimer -= 1;
      }
  }
