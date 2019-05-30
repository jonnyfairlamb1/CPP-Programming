#include "../inc/win_state.hpp"

#include <string>


bool WinState::onCreate()
{

}

bool WinState::onDestroy()
{
}

void WinState::onEntry()
{
  prg::application.addKeyListener(*this);

  CalcWinner();

}

void WinState::onExit()
{
  prg::application.removeKeyListener(*this);
}

void WinState::onUpdate()
{
}

void WinState::onRender(prg::Canvas& canvas)
{
std::string text = ("GAME OVER TIME RAN OUT");

  prg::uint text_dims[2];
  prg::Font::MASSIVE.computePrintDimensions(text_dims, text);
  prg::Font::MASSIVE.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 ,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2,
    prg::Colour::RED,
    text);

    std::string PlayerScoreText = ("Player Score : " + std::to_string(shared_data_.PlayerScore));

  prg::Font::MEDIUM.computePrintDimensions(text_dims, PlayerScoreText);
  prg::Font::MEDIUM.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 - 300,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 + 275,
    prg::Colour::BLACK,
    PlayerScoreText);


    std::string AIScoreText = ("AI Score : " + std::to_string(shared_data_.AIScore));

    prg::Font::MEDIUM.computePrintDimensions(text_dims, AIScoreText);
    prg::Font::MEDIUM.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 + 275,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 + 275,
    prg::Colour::BLACK,
    AIScoreText);

    if(PlayerWins == true){
           std::string AIScoreText = ("Player Wins!");

    prg::Font::MASSIVE.computePrintDimensions(text_dims, AIScoreText);
    prg::Font::MASSIVE.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 ,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 250,
    prg::Colour::BLACK,
    AIScoreText);
    }

    if(AIWins == true){
        std::string AIScoreText = ("AI Wins!");

    prg::Font::MASSIVE.computePrintDimensions(text_dims, AIScoreText);
    prg::Font::MASSIVE.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2 ,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 250,
    prg::Colour::BLACK,
    AIScoreText);
    }

    if(Draw == true){
        std::string AIScoreText = ("Its a draw!");

    prg::Font::MASSIVE.computePrintDimensions(text_dims, AIScoreText);
    prg::Font::MASSIVE.print(
    canvas,
    prg::application.getScreenWidth() / 2 - text_dims[0] / 2,
    prg::application.getScreenHeight() / 2 - text_dims[1] / 2 - 250,
    prg::Colour::BLACK,
    AIScoreText);
    }
}

bool WinState::onKey(const prg::IKeyEvent::KeyEvent& key_event)
{
if(key_event.key_state == KeyEvent::KB_DOWN) {
            switch(key_event.key) {
            case 'r':
            prg::application.setState("play_state");
            break;

            case KeyEvent::KB_ESC_KEY:
            prg::application.exit();
            break;
        }
    }
}

void WinState::CalcWinner(){
      if(shared_data_.PlayerScore > shared_data_.AIScore){
        PlayerWins = true;
        AIWins = false;
        Draw = false;
        }
      if(shared_data_.AIScore > shared_data_.PlayerScore){
        AIWins = true;
        PlayerWins = false;
        Draw = false;
        }
      if(shared_data_.AIScore == shared_data_.PlayerScore){
        Draw = true;
        AIWins = false;
        PlayerWins = false;
        }
}

