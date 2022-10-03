
#pragma region Dependencies and prototypes

#include <iostream>
#include <string>
using namespace std;

// Methods prototypes //
void MovePlayerPosition();
void AskPlayerInput();
void ShowLabyrinth();
void WinCondition();
// void CreateString();
void TheGame();

#pragma endregion

#pragma region Settings

// 7 chaines de 15 caractères //
const int labyrinthSize = 7; 
string map[labyrinthSize] =
{
    "#######S#######",
    "##   ## ##  ###",
    "## ####    ####",
    "##     ### ####",
    "######     ####",
    "##P    ########",
    "###############"
};

// Player position //
int actualYposition = 5;
int actualXposition = 2;

// Exit Position //
int exitYposition = 0;
int exitXposition = 7;

// Win and input //
char playerInput = '_';
bool win = false;

#pragma endregion

#pragma region Methods

// Method to display the labyrinth //
void ShowLabyrinth()
{
    for (int i = 0; i < labyrinthSize; i++)
    {
        cout << map[i] << endl;
    }
}

// Method to change the coordonates of the player //
void MovePlayerPosition()
{
    string theNewString = "";

    if (playerInput == 'Z' || playerInput == 'z')
    {
        if(map[actualYposition - 1][actualXposition] != '#')
            actualYposition = (actualYposition - 1 <= 0) ? 0 : actualYposition - 1;

        if (map[actualYposition + 1][actualXposition] != '#')
            map[actualYposition + 1][actualXposition] = ' ';

        theNewString = map[actualYposition];
        theNewString[actualXposition] = 'P';
    }
    else if (playerInput == 'Q' || playerInput == 'q')
    {
        if (map[actualYposition][actualXposition - 1] != '#')
            actualXposition = (actualXposition - 1 <= 0) ? 0 : actualXposition -1 ;

        theNewString = map[actualYposition];

        if (theNewString[actualXposition + 1] != '#')
            theNewString[actualXposition + 1] = ' ';

        theNewString[actualXposition] = 'P';

    }
    else if (playerInput == 'S' || playerInput == 's')
    {
        if (map[actualYposition + 1][actualXposition] != '#')
            actualYposition = (actualYposition + 1 >= 5) ? 5 : actualYposition + 1;

        if (map[actualYposition - 1][actualXposition] != '#')
            map[actualYposition - 1][actualXposition] = ' ';

        theNewString = map[actualYposition];
        theNewString[actualXposition] = 'P';
    }
    else if(playerInput == 'D' || playerInput == 'd')
    {
        if (map[actualYposition][actualXposition+ 1] != '#')
            actualXposition = (actualXposition + 1 >= 14) ? 14 : actualXposition + 1;

        theNewString = map[actualYposition];

        if (theNewString[actualXposition - 1] != '#')
            theNewString[actualXposition - 1] = ' ';
        theNewString[actualXposition] = 'P';
    }
    else
    {
        return;
    }

    map[actualYposition] = theNewString;

}

/*
// Methods to change the labyrinth array //
void CreateString()
{
    string theNewString = "";

    if (playerInput == 'Q' || playerInput == 'q')
    {
        theNewString = map[actualYposition];

        if(theNewString[actualXposition + 1] != '#')
            theNewString[actualXposition + 1] = ' ';

        theNewString[actualXposition] = 'P';
    }
    else if (playerInput == 'D' || playerInput == 'd')
    {
        theNewString = map[actualYposition];

        if (theNewString[actualXposition - 1] != '#')
            theNewString[actualXposition - 1] = ' ';
        theNewString[actualXposition] = 'P';
    }
    else if (playerInput == 'Z' || playerInput == 'z')
    {
        if (map[actualYposition + 1][actualXposition] != '#')
            map[actualYposition + 1][actualXposition] = ' ';

        theNewString = map[actualYposition];
        theNewString[actualXposition] = 'P';
    }
    else if (playerInput == 'S' || playerInput == 's')
    {
        if(map[actualYposition - 1][actualXposition] != '#')
           map[actualYposition - 1][actualXposition] = ' ';

        theNewString = map[actualYposition];
        theNewString[actualXposition] = 'P';
    }
    else
    {
        return;
    }

    map[actualYposition] = theNewString;
}
*/

// Method to obtain the player input //
void AskPlayerInput()
{
    cout << endl << "Where do you want to go ? ( " << actualXposition+1 << " ; " << actualYposition+1 << ")" << endl;
    cin >> playerInput;
}

// Method that see if the player as won //
void WinCondition()
{
    win = (actualYposition == exitYposition && actualXposition == exitXposition) ? true : false;
}

// Method of the game that use all of the others above //
void TheGame()
{
    while (!win)
    {
        system("CLS");
        ShowLabyrinth();
        AskPlayerInput();
        MovePlayerPosition();
        WinCondition();
    }

    cout << endl << "You win !!" << endl;
}

#pragma endregion

int main()
{
    TheGame();
}

//!!!** A NOTER **!!!\\
//! 
//! Dans un test, l'appel d'une variable suivi de ++ ou -- ne correspond pas simplement à l'appel simple 
//! de la variable incrémenté ou décrémenté... Cet appel est lié à une affectation et modifie donc la valeur,
//! ce qui cause de gros soucis dans les test !!
//!


