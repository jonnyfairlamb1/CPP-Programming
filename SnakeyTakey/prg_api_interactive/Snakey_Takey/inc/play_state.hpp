#pragma once
#if !defined  PLAY_STATE_HPP
#define       PLAY_STATE_HPP
#include "game_data.hpp"
#include <prg_interactive.hpp>
#include "snake.hpp"
#include "collectables.hpp"
#include "dropoff.hpp"
#include "playerSnake.hpp"
#include "AISnake.hpp"
class PlayState final : public prg::IAppState,
                        public prg::IKeyEvent,
                        public prg::ITimerEvent {
public:
    PlayState(game_data& shared_data) : shared_data_(shared_data), AISnake_(collectables_){};

  bool onCreate() override;
  bool onDestroy() override;
  void onEntry() override;
  void onExit() override;
  void onUpdate() override;
  void onRender(prg::Canvas& canvas) override;
    void onTimer(prg::Timer& timer) override;

  //override the onKey() function from prg::IKeyEvent
  bool onKey(const prg::IKeyEvent::KeyEvent& key_event) override;

    bool dead = false;
private:
    game_data& shared_data_;

    prg::Timer  movementTimer_{0,200,*this};

    AISnake AISnake_;
    PlayerSnake playerSnake_;
    collectables collectables_;
    DropOff dropoff_;
    int gameTimer;
    float timeCalc;

};

#endif // PLAY_STATE_HPP
