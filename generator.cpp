#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>


using namespace std;

int randomInt(int min, int max);
void setCharacters();
void logoScreen();
void animation(int character,int type);

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

        for(int i = 0; i <= length; i++)
        {
            int selection = randomInt(1,3);
            int symbol;
            switch(selection)
            {
                case 1:
                    symbol = randomInt(0,24);
                    //cout<<lowerCase.at(symbol);
                    animation((int)lowerCase.at(symbol),1);
                    break;
                case 2:
                    symbol = randomInt(0,24);
                    //cout<<upperCase.at(symbol);
                    animation((int)upperCase.at(symbol),2);
                    break;
                case 3:
                    symbol = randomInt(0,9);
                    //cout<<numbers.at(symbol);
                    animation((int)numbers.at(symbol),3);
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

void animation(int character, int type)
{
    int currentChar;
    int randomselection;
    int startChar;
    switch(type)
    {
        case 1:
            startChar = (character % 97)/2+97;
            while(startChar != character)
            {

                cout<<(char)startChar;
                startChar++;
                if(startChar == character)
                {
                    return;
                }
                Sleep(1.0);
                cout<<"\b";
            }
            break;
        case 2:
            startChar = (character % 65)/2+65;
            while(startChar != character)
            {

                cout<<(char)startChar;
                startChar++;
                if(startChar == character)
                {
                    return;
                }
                Sleep(1.0);
                cout<<"\b";
            }
            break;
        case 3:
            startChar = (character % 48)/2+48;
            while(startChar != character)
            {
                cout<<(char)startChar;
                startChar++;
                if(startChar == character)
                {
                    return;
                }
                Sleep(1.0);
                cout<<"\b";
            }
            break;
    }


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