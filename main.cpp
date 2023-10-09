// C++ Tic Tac Toe Game

#include <iostream>		// Standard C++ Input/Output
#include "play.hpp"		// Header file with our function definitions

int main() {

  // Show the title screen
  introduction();
  
  // Take turns until a winner or board fills
  take_turn();

  // End the game
  end_game();
    
}