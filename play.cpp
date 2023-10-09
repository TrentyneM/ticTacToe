#include <iostream>		// Standard C++ Input/Output Stream
#include "play.hpp"		// Header File with Function Definitions

// Game Board (Strings are just character arrays..)
std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};

int player = 1;		// Which player's turn is it?					
int position = 0;	// Player Input


// Game Title Screen and Board Display
void introduction() {

  std::cout << "Press [Enter] to begin: ";
  
  // When using std::cin, you can use a function
  // called ignore() to discard any characters entered.
  std::cin.ignore();

  std::cout << "\n";

  std::cout << "===========\n";
  std::cout << "Tic-Tac-Toe\n";
  std::cout << "===========\n\n";
  
  std::cout << "Player 1) X\n";
  std::cout << "Player 2) O\n\n";

  std::cout << "Here's the 3 x 3 grid:\n\n";

  std::cout << "     |     |      \n";
  std::cout << "  1  |  2  |  3   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  4  |  5  |  6   \n";
  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";
  std::cout << "  7  |  8  |  9   \n";
  std::cout << "     |     |      \n\n";

}


// Determine if any pairs of 3 of pieces have been made on the board,
// if so, return the winner
bool is_winner() {

  // Decide the winner
  bool winner = false;
  
  // If the board slot at index 0 is equal to the next board slot on the right and the next,
  // and the first slot is not empty, player wins.
  if ((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ") {
	 
	// Victory Royale
    winner = true;
	
  } else if ((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
	  
    winner = true;
	
  } else if ((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
	  
    winner = true;
	
  } 
  
  
  // If the board slot at index 0 is equal to the next board slot down, and slot 0
  // matches the last board slot, and not empty, is winner.
  else if ((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
	  
    winner = true;
	
  } else if ((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
	  
    winner = true;
	
  } else if ((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
	  
    winner = true;
	
  } 
  
  
  // If the board slot at index 0 is equal to the next board slot diagonal down,  and slot 0 is
  // equal to 8, and not blank, winner
  else if ((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
	  
    winner = true;
  }
  
  else if ((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
	  
    winner = true;
	
  }

  return winner;

}


// Is the board filled up?
bool filled_up() {

  // Set filled to true
  bool filled = true;

  // I greater than amount of board spaces, increment i
  for (int i = 0; i < 9; i++) {

	// If any of the characters are blank, filled is false
    if (board[i] == " ") {

      filled = false;

    }

  }

  // Return weather or not the board is filled
  return filled;

}


// Function to draw out the game board using the string's index numbers
void draw() {

  std::cout << "     |     |      \n";

  std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

  std::cout << "_____|_____|_____ \n";
  std::cout << "     |     |      \n";

  std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  std::cout << "     |     |      \n";

  std::cout << "\n";
    
}

void set_position() {

  std::cout << "Player " << player << "'s Turn (Enter 1-9): ";

  while (!(std::cin >> position)) {

    std::cout << "Player " << player << ", please enter a valid number between 1 and 9: ";
    std::cin.clear();
    std::cin.ignore();

  }
  
  std::cout << "\n";

  // Subtract one from our position to account for the 0 in the game board index
  // If the board slot at the subtracted position is not blank, there's something in that slot
  while (board[position-1] != " ") {

    std::cout << "Oops, there's already something in that position!\n\n";

    std::cout << "Player " << player << "'s Turn (Enter 1-9): ";
    std::cin >> position;

    std::cout << "\n";
  }

}

// Update the board on player move, based on who's turn it is
// (if the remainder of player divided by 2 is still one, it's player 1's piece)
// (otherwise, it's player 2's piece)
void update_board() {

  if (player % 2 == 1) {

    board[position-1] = "X";

  } else {

    board[position-1] = "O";

  }

}

// Change the current player's turn
void change_player() {

  if (player == 1) {

    player++;

  } else {
  
    player--;
  
  }

}

// Keep taking turns until there's a winner or the board is filled up
void take_turn() {

  // While not winning and board isn't filled up
  while ( !is_winner() && !filled_up() ) {
  
	// Ask the player their move
    set_position();

	// Update the game board
    update_board();

	// Change the current player's turn.
    change_player();

	// Draw the game board
    draw();
  
  }

}

// End the game
void end_game() {

  if (is_winner()) {
    std::cout << "There's a winner!\n";
  }
  else if (filled_up()) {
    std::cout << "There's a tie!\n";
  }

}

