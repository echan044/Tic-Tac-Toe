#include <vector>
#include <iostream>

using namespace std;

const bool CLEAR_SCREEN = true;

/// @brief Utilizes an escape character sequence to clear the screen
void clearScreen() {
    cout << endl;

    if (CLEAR_SCREEN) {
        cout << "\033c";
    }

    cout << endl;

    return;
}


/// @brief Draws the provided tic-tac-toe board to the screen
//  @param board is the tic-tac-toe board that should be drawn
void drawBoard(const vector < char >&gameBoard) {
    clearScreen();
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;

    return;
}



/// @brief Fills vector with characters starting at lower case a.
///
///     If the vector is size 3 then it will have characters a to c.
///     If the vector is size 5 then it will have characters a to e.
///     If the vector is size 26 then it will have characters a to z.
///
/// @param v the vector to initialize
/// @pre-condition the vector size will never be over 26
void initVector(vector <char> &v) {
    // TODO: implement function
    int i = 0;
    int j = v.size();
    char starter = 'a';
    
    for (i = 0; i < j; i++) {
        v.at(i) = (static_cast<char> (starter + i));
    }
    
    return;
}


/// @brief Converts a character representing a cell to associated vector index
/// @param the position to be converted to a vector index
/// @return the integer index in the vector, should be 0 to (vector size - 1)
int convertPosition(char boardPosition) {
    //receive a d, convert that to index 3
    // need a base vector, create one?
    int index = 0;
    int i = 0;
    vector<char> charList(9);
    initVector(charList);
    
    for (i = 0; i < charList.size(); i++) {
        if (charList.at(i) == boardPosition) {
            index = i;
        }
    }
    
    
    return index;
}


/// @brief Predicate function to determine if a spot in board is available.
/// @param board the current tic-tac-toe board 
/// @param position is an index into vector to check if available
/// @return true if position's state is available (not marked) AND is in bounds
bool validPlacement(const vector<char>  &gameBoard, int positionIndex) {
    if (positionIndex > 8) {
        return false;
    }
    if (gameBoard.at(positionIndex) == 'X' || gameBoard.at(positionIndex) == 'O') {
        return false;
    }
    else {
        return true;
    }
}

/// @brief Acquires a play from the user as to where to put her mark
///
///     Utilizes convertPosition and validPlacement functions to convert the
///     user input and then determine if the converted input is a valid play.
///
/// @param board the current tic-tac-toe board 
/// @return an integer index in board vector of a chosen available board spot
int getPlay(const vector<char> &gameBoard) {

    // TODO: implement function
    char boardPosition = ' ';

    cout << "Please choose a position: " << endl;
    cin >> boardPosition;
    convertPosition(boardPosition);
    
    while (!validPlacement(gameBoard, convertPosition(boardPosition))) {
        cout << "Please choose a position: " << endl;
        cin >> boardPosition;
        convertPosition(boardPosition);
    }
    
    if (validPlacement(gameBoard, convertPosition(boardPosition))) {
        return convertPosition((boardPosition));    
    }
    else {
        return -1;
    }
}


/// @brief Predicate function to determine if the game has been won
///
///     Winning conditions in tic-tac-toe require three marks from same 
///     player in a single row, column or diagonal.
///
/// @param board the current tic-tac-toe board 
/// @return true if the game has been won, false otherwise
bool gameWon(const vector<char> &gameBoard) {

    //horizontal wins
    if (gameBoard.at(0) == 'X' && gameBoard.at(1) == 'X' && gameBoard.at(2) == 'X') {
        return true;        
    }
    if (gameBoard.at(3) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(5) == 'X') {
        return true;        
    }
    if (gameBoard.at(6) == 'X' && gameBoard.at(7) == 'X' && gameBoard.at(8) == 'X') {
        return true;        
    }
    
    if (gameBoard.at(0) == 'O' && gameBoard.at(1) == 'O' && gameBoard.at(2) == 'O') {
        return true;        
    }
    if (gameBoard.at(3) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(5) == 'O') {
        return true;        
    }
    if (gameBoard.at(6) == 'O' && gameBoard.at(7) == 'O' && gameBoard.at(8) == 'O') {
        return true;        
    }
    
    //vertical wins
    if (gameBoard.at(0) == 'X' && gameBoard.at(3) == 'X' && gameBoard.at(6) == 'X') {
        return true;        
    }
    if (gameBoard.at(1) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(7) == 'X') {
        return true;        
    }
    if (gameBoard.at(2) == 'X' && gameBoard.at(5) == 'X' && gameBoard.at(8) == 'X') {
        return true;        
    }
    
    if (gameBoard.at(0) == 'O' && gameBoard.at(3) == 'O' && gameBoard.at(6) == 'O') {
        return true;        
    }
    if (gameBoard.at(1) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(7) == 'O') {
        return true;        
    }
    if (gameBoard.at(2) == 'O' && gameBoard.at(5) == 'O' && gameBoard.at(8) == 'O') {
        return true;        
    }
    
    //diagonal wins
    if (gameBoard.at(0) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(8) == 'X') {
        return true;        
    }
    if (gameBoard.at(2) == 'X' && gameBoard.at(4) == 'X' && gameBoard.at(6) == 'X') {
        return true;        
    }
    
    if (gameBoard.at(0) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(8) == 'O') {
        return true;        
    }
    if (gameBoard.at(2) == 'O' && gameBoard.at(4) == 'O' && gameBoard.at(6) == 'O') {
        return true;        
    }
    
    //no win yet
    return false;
}


/// @brief Predicate function to determine if the board is full
/// @param board the current tic-tac-toe board 
/// @return true iff the board is full (no cell is available)
bool boardFull(const vector<char> &gameBoard) {
    int i = 0;
    char starter2 = 'a';

    for (i = 0; i < gameBoard.size(); i++) {
        if (gameBoard.at(i) == static_cast<char>(starter2 + i)) {
            return false;
        }
    }
    
    return true;
}


// Global constants for player representation
const int PLAYER1 = 0;
const int PLAYER2 = 1;

int main() {
    // Variables that you may find useful to utilize
    vector<char> gameBoard(9);
    int curPlay;
    int whosTurn = PLAYER1; // Player 1 always goes first and is 'X'

    /// TODO: Initialize board to empty state
    /// TODO: Display empty board
    initVector(gameBoard);
    drawBoard(gameBoard);
    
    /// TODO: Play until game is over
    while (!gameWon(gameBoard) && !boardFull(gameBoard)) {
        if (whosTurn == PLAYER1) {
            gameBoard.at(getPlay(gameBoard)) = 'X';
        }
        if (whosTurn == PLAYER2) {
            gameBoard.at(getPlay(gameBoard)) = 'O';
        }
        //drawBoard(gameBoard);
        if (whosTurn == PLAYER1) {
            whosTurn = PLAYER2;
        }
        else {
            whosTurn = PLAYER1;
        }
        drawBoard(gameBoard);
    }
        /// TODO: Get a play

        /// TODO: Set the play on the board

        /// TODO: Switch the turn to the other player

        /// TODO: Output the updated board


    /// TODO: Determine winner and output appropriate message
    if (whosTurn = PLAYER1) {
        cout << "PLAYER 1 WINS!" << endl;
    }
    if (whosTurn = PLAYER2) {
        cout << "PLAYER 2 WINS!" << endl;
    }
    

    return 0;
}