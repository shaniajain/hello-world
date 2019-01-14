// Shania Jain, Aneri Parikh, Lahari Vuppaladhadiam
// 1/22/17
// C++ Final Project
// Snakes and Ladders - two-player game that guides players through a board with snakes (bring you down)  and ladders (carry you up) that have been pre-set. The person who reaches position 100 first wins


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


// checks if player’s position is at a snake
int Snakes(int &position, int roll_dice)
{
    int start_snake[10] = {16, 46, 49, 62, 64, 74, 89, 92, 95, 99}; // defines the starting point of each snake
    int end_snake[10] = {6, 25, 11, 19, 60, 53, 68, 88, 75, 80}; // defines the corresponding end point that is lower
    
    for (int i = 0; i < 10; i++)
    {
        if (position == start_snake[i])
        {
            position = end_snake[i]; // shifts player’s position to bottom tail of snake
            cout << "Oops! You ran into a snake! ";
        }
        
    }
    return 0;
    
}



//checks if player’s position is at a ladder
int ladders(int &position, int roll_dice)
{
    const int ARR_SIZE = 11;
    int start_ladder[] = {2, 7, 8, 15, 21, 28, 36, 51, 71, 78, 87}; // defines the starting point of each ladder
    int end_ladder[] = {38, 14, 31, 26, 42, 84, 44, 67, 91, 98, 94}; // defines end point of ladder
    
    for (int i = 0; i <= ARR_SIZE; i++)
    {
        if (position == start_ladder[i])
        {
            position = end_ladder[i]; // shifts player’s position to the end of the ladder
            cout << "Yay! You found a ladder! ";
        }
    }
    cout << "You are now at position " << position << endl << endl;
    return 0;
}




int main ()
{
    //set initial position to 0
    int position1 = 0;
    int position2 = 0;
    
    //loop continues until either players’ position exceeds 100
    while (position1 < 100 && position2 < 100)
    {
        cout << "It is player1's turn. Press '1' to play. ";
        int input1;
        cin >> input1;
        
        if (input1 == 1)
        {
            //generates a random number between 1 and 6
            int dice = 1 + rand() % 6;
            cout << "You rolled a " << dice << " ";
            //adds number on dice to current position to get player 1’s new position
            position1 = position1 + dice;
            //call to Snake function
            Snakes(position1, dice);
            //call to ladder function
            ladders(position1, dice);
        }
        
        cout << "It is player2's turn. Press '1' to play. ";
        int input2;
        cin >> input2;
        
        if (input2 == 1)
        {
            //generates a random number between 1 and 6
            int dice = rand() % 6 + 1;
            cout << "You rolled a " << dice << " ";
            
            //adds number on dice to current position to get player 2’s new position
            position2 = position2 + dice;
            
            // call to snake function
            Snakes(position2, dice);
            // call to ladder function
            ladders(position2, dice);
        }
    }
    
    
    //prints the winner of the game if one of the players passes 100
    if (position1 > 100 && position1 > position2)
    {
        cout << "Congrats Player1. You won!" << endl;
    }
    else if (position2 > 100 && position2 > position1)
    {
        cout << "Congrats Player2. You won!" << endl;
    }
    return 0;
}
