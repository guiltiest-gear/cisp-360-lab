// Program    : part-a.cpp
// Author     : Jade Fox
// Due Date   : July 2, 2023
// Description: Write a tic tac toe program to allow two players to play a game

#include <iostream>
#include <string>

using std::cout, std::cin, std::string;

// Define the dimensions of the array in a constant
const int rows_and_columns = 3;

// Show the board
void display_the_board(const char array[][rows_and_columns]) {
    cout << '\n';
    for (int i = 0; i < rows_and_columns; i++) {
        for (int j = 0; j < rows_and_columns; j++) {
            cout << array[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

// Make sure the players actually put in a number that actually works
int validate(int number, int lowest, int highest) {
    while (!(cin >> number) || (number < lowest || number > highest)) {
        cout << "Error. Please input a number actually within the correct range.";
        cin.clear();
    }
    return number;
}

// Player choices are made here
void player(char array[][rows_and_columns], char letter) {
    cout << "Where will you place " << letter << "?\n";
    // Row and column are set to 0 so g++ shuts up about uninitialized variables
    // The program will literally work the extact same way without these being set to a value
    // The 0's will get overwritten anyway
    // I genuinely have no clue why it keeps bugging me about this
    int row = 0, column = 0;
    bool occupied = false;

    do {
        // Validate input to make sure those are legal moves
        cout << "Which row? ";
        row = validate(row, 1, 3);

        cout << "Which column? ";
        column = validate(column, 1, 3);

        // If the spot is empty, put the X or O there
        if (array[(row - 1)][(column - 1)] == '*') {
            array[(row - 1)][(column - 1)] = letter;
            occupied = true;
        } else {
            cout << "Spot taken, try again please.\n";
            occupied = false;
        }
    } while (occupied == false); // Make sure players are putting their X's and O's in empty spots
}

// Check for horizontal win
bool horizontal_win(const char array[][rows_and_columns], const char letter, string &game_winner) {
    int across = 0;
    bool winner = false;

    for (int row = 0; row < rows_and_columns; row++) {
        for (int column = 0; column < rows_and_columns; column++) {
            if (array[row][column] == letter) {
                across++;
            }
        }

        if (across == 3) {
            if (letter == 'X') {
                game_winner = "Player 1";
            } else {
                game_winner = "Player 2";
            }
            winner = true;
            break;
        } else {
            winner = false;
            across = 0;
        }
    }
    return winner;
}

// What about the vertical?
bool vertical_win(const char array[][rows_and_columns], const char letter, string &game_winner) {
    int down = 0;
    bool winner = false;

    for (int column = 0; column < rows_and_columns; column++) {
        for (int row = 0; row < rows_and_columns; row++) {
            if (array[row][column] == letter) {
                down++;
            }
        }

        if (down == 3) {
            if (letter == 'X') {
                game_winner = "Player 1";
            } else {
                game_winner = "Player 2";
            }
            winner = true;
            break;
        } else {
            winner = false;
            down = 0;
        }
    }
    return winner;
}

// Can't forget about the diagonals of course
bool diagonal_win_left_to_right(const char array[][rows_and_columns], const char letter, string &game_winner) {
    int diagonal = 0;
    bool winner = false;

    for (int i = 0; i < rows_and_columns; i++) {
        if (array[i][i] == letter) {
            diagonal++;
        }
    }

    if (diagonal == 3) {
        if (letter == 'X') {
            game_winner = "Player 1";
        } else {
            game_winner = "Player 2";
        }
        winner = true;
    } else {
        winner = false;
    }

    return winner;
}

bool diagonal_win_right_to_left(const char array[][rows_and_columns], const char letter, string &game_winner) {
    int diagonal = 0;
    bool winner;

    for (int row = 0, column = (rows_and_columns - 1); row < rows_and_columns; row++, column--) {
        if (array[row][column] == letter) {
            diagonal++;
        }
    }

    if (diagonal == 3) {
        if (letter == 'X') {
            game_winner = "Player 1";
        } else {
            game_winner = "Player 2";
        }
        winner = true;
    } else {
        winner = false;
    }

    return winner;
}

// Did someone win yet?
int winner_ultimate_check(const char array[][rows_and_columns], const char letter, string &game_winner) {
    bool winner = false;

    if (horizontal_win(array, letter, game_winner)) {
        winner = true;
    } else if (vertical_win(array, letter, game_winner)) {
        winner = true;
    } else if (diagonal_win_left_to_right(array, letter, game_winner)) {
        winner = true;
    } else if (diagonal_win_right_to_left(array, letter, game_winner)) {
        winner = true;
    } else {
        game_winner = "tie!";
        winner = false;
    }

    return winner;
}

int main() {
    char board[rows_and_columns][rows_and_columns] = {
        {'*', '*', '*'},
        {'*', '*', '*'},
        {'*', '*', '*'}
    };
    string winner = "";

    display_the_board(board);

    player(board, 'X');
    display_the_board(board);

    for (int i = 0; i < 4; i++) {
        player(board, 'O');
        display_the_board(board);

        if (winner_ultimate_check(board, 'O', winner)) {
            break;
        }

        player(board, 'X');
        display_the_board(board);

        if (winner_ultimate_check(board, 'X', winner)) {
            break;
        }
    }

    cout << "Game winner: " << winner << '\n';
    return 0;
}
