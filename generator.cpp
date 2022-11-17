#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomInt(int min, int max);
void setCharacters();
void logoScreen();


vector<char> lowerCase;
vector<char> upperCase;
vector<char> numbers;

int main()
{
    int length = 1;
    setCharacters();
    logoScreen();

    do
    {
        cout<<"\n\n[?] - Please enter length of password: ";
        cin>>length;

        srand(time(0));
        cout<<endl<<endl;

        for(int i = 0; i < length; i++)
        {
            int selection = randomInt(1,3);
            int symbol;
            switch(selection)
            {
                case 1:
                    symbol = randomInt(0,24);
                    cout<<lowerCase.at(symbol);
                    break;
                case 2:
                    symbol = randomInt(0,24);
                    cout<<upperCase.at(symbol);
                    break;
                case 3:
                    symbol = randomInt(0,9);
                    cout<<numbers.at(symbol);
            }
        }
    } while (length != 0);
    
    
}

void setCharacters()
{
    for(int i = 65; i <= 90; i++)
    {
        upperCase.push_back((char)i);
    }
    for(int i = 97; i <= 122; i++)
    {
        lowerCase.push_back((char)i);
    }
    for(int i = 48; i <= 57; i++)
    {
        numbers.push_back((char)i);
    }
}

int randomInt(int min, int max)
{
    int range = max-min+1;
    return rand() % range + min;
}

void logoScreen()
{
    cout<<R"(
                                   __
                               _.-~  )
                    _..--~~~~,'   ,-/     _
                 .-'. . . .'   ,-','    ,' )                                            _
               ,'. . . _   ,--~,-'__..-'  ,'  _ __   __ _ ___ _____      _____  _ __ __| | __ _  ___ _ __  
             ,'. . .  (@)' ---~~~~      ,'   | '_ \ / _` / __/ __\ \ /\ / / _ \| '__/ _` |/ _` |/ _ \ '_ \
            /. . . . '~~             ,-'     | |_) | (_| \__ \__ \\ V  V / (_) | | | (_| | (_| |  __/ | | |
           /. . . . .             ,-'        | .__/ \__,_|___/___/ \_/\_/ \___/|_|  \__,_|\__, |\___|_| |_|
          ; . . . .  - .        ,'           |_|                                          |___/            
         : . . . .       _     /
        . . . . .          `-.:                                 github.com/vertyks
       . . . ./  - .          )
      .  . . |  _____..---.._/ _____
~---~~~~----~~~~             ~~
)"<<endl<<endl;
}