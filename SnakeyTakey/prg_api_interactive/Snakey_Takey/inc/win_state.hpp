#pragma once
#if !defined  WIN_STATE_HPP
#define       WIN_STATE_HPP
#include "game_data.hpp"
#include <prg_interactive.hpp>

class WinState final : public prg::IAppState,
                        public prg::IKeyEvent{
public:
    WinState(game_data& shared_data) : shared_data_(shared_data) {};

  bool onCreate() override;
  bool onDestroy() override;
  void onEntry() override;
  void onExit() override;
  void onUpdate() override;
  void onRender(prg::Canvas& canvas) override;

  void CalcWinner();

  //override the onKey() function from prg::IKeyEvent
  bool onKey(const prg::IKeyEvent::KeyEvent& key_event) override;

private:
    game_data& shared_data_;

    bool PlayerWins = false;
    bool AIWins = false;
    bool Draw = false;

};

#endif // PLAY_STATE_HPP
