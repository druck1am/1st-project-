//
//  main.cpp
//  BOS_18
//
//  Created by Alex Druckenmiller on 11/22/19.
//  Copyright © 2019 Alex Druckenmiller. All rights reserved.
//


#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>




using namespace std;

int display_board(char board[][3], int BOARD_ROWS);
int handle_turn(int player_number, int players, char board[][3], int BOARD_ROWS);
int handle_AI_turn(int player_number, char board [][3], int BOARD_ROWS);
bool check_row_win(int player_number, char board[][3], int BOARD_ROWS);
bool check_col_win(int player_number, char board[][3], int BOARD_ROWS);
bool check_diag_win(int player_number, char board[][3], int BOARD_ROWS);
bool check_win(int player_number, char board[][3], int BOARD_ROWS);
bool check_tie(char board[][3], int BOARD_ROWS);
bool checkaiwin(int player_input, int player_number, char board[][3], int BOARD_ROWS);
bool checkplayerwin(int player_input, int player_number, char board[][3], int BOARD_ROWS);

int BOARD_ROWS = 3;

int main() {
    
    int counter = 0;
    char board [3][3] = {'1','2','3','4','5','6','7','8','9'};
    int player_number = 1;
    char name1[10];
    char name2[10];
    int players;
    
    cout << "Please select 1 or 2 players: ";
    cin >> players;
    
    

    while(players > 2 or players < 1){
        cout << "invalid choice" << endl;
        cout << "Please select 1 or 2 players" << endl;
        cin >> players;
    };
    
    if (players == 1){
        cout << "player 1 please enter your name: ";
        cin >> name1;
        
        cout << endl;
        
    }
    else if (players == 2){
        cout << "player 1 please enter your name: ";
        cin >> name1;
        cout << "\nplayer 2 please enter your name: ";
        cin >> name2;
        cout << endl;
    }


    
    display_board(board, BOARD_ROWS);
    
    while (check_win(player_number, board, BOARD_ROWS) != true){
        player_number = handle_turn(player_number, players, board, BOARD_ROWS);
        counter++;
        if(counter == 9 and check_win(player_number, board, BOARD_ROWS) != true){
            cout << "TIE!";
            return 0;
        };
    }
    
    player_number++;
    if(player_number % 2 == 0){
        player_number = 2;
    }
    else{
        player_number = 1;
    };
    
    if (player_number == 1){
        cout << name1 << " has won!";
    }
    else if (player_number == 2){
        if(players == 1){
            cout << "AI has won";
            return 0;
        };
        cout << name2 << " has won!";
    };
    return 0;
}

int handle_turn(int player_number, int players, char board[][3], int BOARD_ROWS){
    
    int player_input;
    char aichoice;
    
    if (players == 1 and player_number % 2 == 0){
        
        aichoice = handle_AI_turn(player_number, board, BOARD_ROWS);
        player_input = aichoice;
        
        if (player_input == 1){
            if(board[0][0]== '1'){
                board [0][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 2){
            if(board[0][1]== '2'){
                board [0][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 3){
            if(board[0][2]== '3'){
                board [0][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 4){
            if(board[1][0]== '4'){
                board [1][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 5){
            if(board[1][1]== '5'){
                board [1][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 6){
            if(board[1][2]== '6'){
                board [1][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 7){
            if(board[2][0]== '7'){
                board [2][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 8){
            if(board[2][1]== '8'){
                board [2][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
        if (player_input == 9){
            if(board[2][2]== '9'){
                board [2][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
        };
    }
    else if(player_number % 2 == 0){
        player_number = 2;
    }
    else{
        player_number = 1;
    };

    cout << "PLAYER " << player_number << ": please pick a position: ";
    cin >> player_input;

    if(player_number % 2 == 0){
        if (player_input == 1){
            if(board[0][0]== '1'){
                board [0][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[0][0] != '1'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 1){
                    break;
                };
            };
        };
        if (player_input == 2){
            if(board[0][1]== '2'){
                board [0][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[0][1] != '2'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 2){
                    break;
                };
            };
        };
        if (player_input == 3){
            if(board[0][2]== '3'){
                board [0][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[0][2] != '3'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 3){
                    break;
                };
            };
        };
        if (player_input == 4){
            if(board[1][0]== '4'){
                board [1][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[1][0] != '4'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 4){
                    break;
                };
            };
        };
        if (player_input == 5){
            if(board[1][1]== '5'){
                board [1][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[1][1] != '5'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 5){
                    break;
                };
            };
        };
        if (player_input == 6){
            if(board[1][2]== '6'){
                board [1][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[1][2] != '6'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 6){
                    break;
                };
            };
        };
        if (player_input == 7){
            if(board[2][0]== '7'){
                board [2][0]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[2][0] != '7'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 7){
                    break;
                };
            };
        };
        if (player_input == 8){
            if(board[2][1]== '8'){
                board [2][1]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[2][1] != '8'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 8){
                    break;
                };
            };
        };
        if (player_input == 9){
            if(board[2][2]== '9'){
                board [2][2]= 'O';
                cout << endl;
                display_board(board, BOARD_ROWS);
                player_number++;
                return player_number;
            }
            while(board[2][2] != '9'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 9){
                    break;
                };
            };
        };
    }
    else{
        if (player_input == 1){
            if(board[0][0]== '1'){
                board [0][0]= 'X';
                player_number++;
                return player_number;
            }
            while(board[0][0] != '1'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 1){
                    break;
                };
            };
        };
        if (player_input == 2){
            if(board[0][1]== '2'){
                board [0][1]= 'X';
                player_number++;
                return player_number;
            }
            while(board[0][1] != '2'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 2){
                    break;
                };
            };
        };
        if (player_input == 3){
            if(board[0][2]== '3'){
                board [0][2]= 'X';
                player_number++;
                return player_number;
            }
            while(board[0][2] != '3'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 3){
                    break;
                };
            };
        };
        if (player_input == 4){
            if(board[1][0]== '4'){
                board [1][0]= 'X';
                player_number++;
                return player_number;
            }
            while(board[1][0] != '4'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 4){
                    break;
                };
            };
        };
        if (player_input == 5){
            if(board[1][1]== '5'){
                board [1][1]= 'X';
                player_number++;
                return player_number;
            }
            while(board[1][1] != '5'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 5){
                    break;
                };
            };
        };
        if (player_input == 6){
            if(board[1][2]== '6'){
                board [1][2]= 'X';
                player_number++;
                return player_number;
            }
            while(board[1][2] != '6'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 6){
                    break;
                };
            };
        };
        if (player_input == 7){
            if(board[2][0]== '7'){
                board [2][0]= 'X';
                player_number++;
                return player_number;
            }
            while(board[2][0] != '7'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 7){
                    break;
                };
            };
        };
        if (player_input == 8){
            if(board[2][1]== '8'){
                board [2][1]= 'X';
                player_number++;
                return player_number;
            }
            while(board[2][1] != '8'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 8){
                    break;
                };
            };
        };
        if (player_input == 9){
            if(board[2][2]== '9'){
                board [2][2]= 'X';
                player_number++;
                return player_number;
            }
            while(board[2][2] != '9'){
                cout << "INVALID MOVE" << endl;
                cout << "Please select another location: ";
                cin >> player_input;
                if (player_input != 9){
                    break;
                };
            };
        };
    };
    
    cout << "invalid move";
    return 0;
    }

int display_board(char board[][3], int BOARD_ROWS){
        
        for (int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << "|" << board [i][j] << "|";
            }
            cout << endl;
        }
    return 0;
}


bool check_row_win(int player_number, char board[][3], int BOARD_ROWS){
    
    for (int i = 0; i < 3; i++){
        if ((board [i][0] & board [i][1]) == (board [i][2])){
            return true;
        }
    }
    
    return false;
}

bool check_col_win(int player_number, char board[][3], int BOARD_ROWS){
    
    for (int i = 0; i < 3; i++){
        if ((board [0][i] & board [1][i]) == (board [2][i])){
            return true;
        }
    }
    return false;
}

bool check_diag_win(int player_number, char board[][3], int BOARD_ROWS){
    
    if ((board [0][0] & board [1][1]) == (board [2][2])){
        return true;
    }
    else if ((board [0][2] & board [1][1]) == (board [2][0])){
        return true;
     };
            
    return false;
}

bool check_win(int player_number, char board[][3], int BOARD_ROWS){
    if (check_row_win(player_number, board, BOARD_ROWS) == true){
        return true;
    };
    if (check_col_win(player_number, board, BOARD_ROWS) == true){
        return true;
    };
    if (check_diag_win(player_number, board, BOARD_ROWS) == true){
        return true;
    };
    return false;
}

int handle_AI_turn(int player_number, char board [][3], int BOARD_ROWS){
    
    int aichoiceO;
    
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' and board[i][j] != 'O'){
                aichoiceO = board[i][j] - '0';
                if(checkaiwin(aichoiceO, player_number, board, BOARD_ROWS)){
                    return aichoiceO;
                };
                if(checkplayerwin(aichoiceO, player_number, board, BOARD_ROWS)){
                    return aichoiceO;
                };
            };
        };
    };
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] != 'X' and board[i][j] != 'O'){
                aichoiceO = board[i][j] - '0';
                return aichoiceO;
            };
        };
    };
    
    return 0;
};

bool checkaiwin(int player_input, int player_number, char board[][3], int BOARD_ROWS){
    
    if (player_input == 1){
        if(board[0][0]== '1'){
            board [0][0]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][0] = '1';
                return true;
            }
            else{
                board[0][0] = '1';
            };
        };
    };
    
    if (player_input == 2){
        if(board[0][1]== '2'){
            board [0][1]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][1] = '2';
                return true;
            }
            else{
                board[0][1] = '2';
            };
        };
    };
    
    if (player_input == 3){
        if(board[0][2]== '3'){
            board [0][2]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][2] = '3';
                return true;
            }
            else{
                board[0][2] = '3';
            };
        };
    };
    
    if (player_input == 4){
        if(board[1][0]== '4'){
            board [1][0]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][0] = '4';
                return true;
            }
            else{
                board[1][0] = '4';
            };
        };
    };
    
    if (player_input == 5){
        if(board[1][1]== '5'){
            board [1][1]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][1] = '5';
                return true;
            }
            else{
                board[1][1] = '5';
            };
        };
    };
    
    if (player_input == 6){
        if(board[1][2]== '6'){
            board [1][2]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][2] = '6';
                return true;
            }
            else{
                board[1][2] = '6';
            };
        };
    };
    
    if (player_input == 7){
        if(board[2][0]== '7'){
            board [2][0]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][0] = '7';
                return true;
            }
            else{
                board[2][0] = '7';
            };
        };
    };
    
    if (player_input == 8){
        if(board[2][1]== '8'){
            board [2][1]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][1] = '8';
                return true;
            }
            else{
                board[2][1] = '8';
            };
        };
    };
    
    if (player_input == 9){
        if(board[2][2]== '9'){
            board [2][2]= 'O';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][2] = '9';
                return true;
            }
            else{
                board[2][2] = '9';
            };
        };
    };
    
    return 0;
};

bool checkplayerwin(int player_input, int player_number, char board[][3], int BOARD_ROWS){
    
    if (player_input == 1){
        if(board[0][0]== '1'){
            board [0][0]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][0] = '1';
                return true;
            }
            else{
                board[0][0] = '1';
            };
        };
    };
    
    if (player_input == 2){
        if(board[0][1]== '2'){
            board [0][1]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][1] = '2';
                return true;
            }
            else{
                board[0][1] = '2';
            };
        };
    };
    
    if (player_input == 3){
        if(board[0][2]== '3'){
            board [0][2]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[0][2] = '3';
                return true;
            }
            else{
                board[0][2] = '3';
            };
        };
    };
    
    if (player_input == 4){
        if(board[1][0]== '4'){
            board [1][0]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][0] = '4';
                return true;
            }
            else{
                board[1][0] = '4';
            };
        };
    };
    
    if (player_input == 5){
        if(board[1][1]== '5'){
            board [1][1]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][1] = '5';
                return true;
            }
            else{
                board[1][1] = '5';
            };
        };
    };
    
    if (player_input == 6){
        if(board[1][2]== '6'){
            board [1][2]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[1][2] = '6';
                return true;
            }
            else{
                board[1][2] = '6';
            };
        };
    };
    
    if (player_input == 7){
        if(board[2][0]== '7'){
            board [2][0]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][0] = '7';
                return true;
            }
            else{
                board[2][0] = '7';
            };
        };
    };
    
    if (player_input == 8){
        if(board[2][1]== '8'){
            board [2][1]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][1] = '8';
                return true;
            }
            else{
                board[2][1] = '8';
            };
        };
    };
    
    if (player_input == 9){
        if(board[2][2]== '9'){
            board [2][2]= 'X';
            if(check_win(player_number, board, BOARD_ROWS)){
                board[2][2] = '9';
                return true;
            }
            else{
                board[2][2] = '9';
            };
        };
    };
    
    return 0;
};

