#include "inc/play_state.hpp"
#include "inc/win_state.hpp"
#include "inc/game_data.hpp"
#include <prg_interactive.hpp>
#include <stdexcept>
#include <iostream>

void play();

int main()
{

  try {
    game_data shared_data {0,0};
    WinState win_state(shared_data);
    PlayState play_state(shared_data);

    prg::application.addState("play_state", play_state);
    prg::application.addState("win_state", win_state);


    prg::application.run("Jonny Fairlamb", "Q5058597", 800, 600);
  }
  catch(std::exception& e) {
    std::cerr << "Exception Caught: " << e.what() << std::endl;
  }
}
