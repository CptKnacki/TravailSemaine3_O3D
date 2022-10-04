
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


//correction//
/*

#include <iostream>
#include <string>
using namespace std;

const int mapSize = 6;
const char exitValue = 's', player = 'p', enter = 'e', walls = '#', path = ' ';
char currentInput = 'a';

string map[mapSize] =
{
    "#######S#######",
    "##   ## ##  ###",
    "## ####    ####",
    "##     ### ####",
    "######     ####",
    "##P    ########",
}

bool Init();
void Display();
void GameLoop();
void ReadInput();
void GetInputValue();
bool GetNextMove(int _x, int _y);

bool Init()
{
    bool find = false;
    for(int i = 0; i < mapSize; i++)
    {
        int length = map[y].lentgh();
        for(int y = 0 ; y < length; y++)
        {
            if(map[i][y] == 'e')
            {
                currentY = y;
                currentX = x;
                find = true;
            }
        }
    }
}

void Display()
{
   for(int i = 0; i < mapSize; i++)
    {
       int length = map[y].length();
       for(int y = 0; y < length; y++)
        {
            if (currentX == x && currentY == y)
                cout << player;
            else cout << map[y][x];
        }
        cout << endl;
    }
}

void GameLoop()
{
    while(map[currentY][currentX] == != exitValue)
    {
        system("CLS");
        Display();
    }

}

void ReadInput()
{
    bool isValidInput = false;
    cout << "Choose direction" << endl;
    while(!isValidInput)
    {
        cin currentInput;
        currentInput = to_lower(currentInput);
        IsValidInput = (currentInput == 'z' ||currentInput == 'q' ||currentInput == 's' ||currentInput == 'd');
    }
}

bool GetNextMove(int _x, int _y)
{
    bool _yOutOfRange = _y < 0 || _y > mapSize;
    bool _xOutOfRange = _x < 0 || _x > map[_y].length;

    if(_yOutOfRange ||_xOutOfRange) return false;
    return map[_y][_x] != wall;

}

void GetInputValue()
{
    if(currentInput == 'z' && GetNextMove(currentY - 1, currentX))
        currentY--;
    else if (currentInput == 's' && GetNextMove(currentY + 1, currentX))
        currentY++;
    else if (currentInput == 'q' && GetNextMove(currentY, currentX - 1))
        currentX--;
    else if (currentInput == 'd' && GetNextMove(currentY, currentX + 1))
        currentX++;

}
int main()
{
    SetConsoleOutpuCp(CP_UTF8);
    if(!Init())
    {
        return -2;
    }
    GameLoop();
    system("CLS");
    cout << "felicitations !" << endl;

    return 0;
}

char** t = new char* [10];
for (int i = 0 ; i < 10 ; i++)
{
    t[i] = new char(0);
}

delete[] t;


class A
{
   private:
   string name = "";
   public:
   A() = default;

   A(string _name)
   {
    name = _name;
   }

   string Name()
   {
    return name;
   }
};

class B : public A
{
   public:
   
   B()
   {
    name = "Bibi";
   }
};

int main()
{
    A a("Toto");
    B b;
    // b.name;
    cout << a.Name();
}

class Entity
{
    private:
        string name = "";
    public:
        string Name()
        {
            return name;
        }
        Entity()
        {}
        ~Entity()
        {}
};


class Player : public Entity
{
    private:
        string nickName;
        int age;
        Entity* ent = new Entity();
    public:
        Player(const Player& _player)
        {
            nickName = _player.nickName;
            age = _player.age;
            ent = _player.ent;
        }
        ~Player()
        {
            delete ent;
        }
};

*/