#include <iostream>
#include <windows.h>
#include <string> 
#include <stdlib.h>

using namespace std;

void printWithDelay(string text, unsigned int milSeconds)
{
    int len = text.length();

    for(int i = 0; i < len; i++)
    {
        cout << text[i];
        if (text[i] == ' ') Sleep(milSeconds*2);
        else Sleep(milSeconds);
    }
}

void spaces(unsigned int num)
{
    for(int i = 0; i < num; i++)
    {
        cout << '\n';
    }
}

int main()
{

    string greetings = "Hello! This is quiz-game which will test your knowledge in Geography! Let's start.)";
    printWithDelay(greetings, 30);

    Sleep(1000);
    system ("CLS");

    unsigned int numberOfPlayers;

    printWithDelay("Enter numder of players: ", 10);
    cin >> numberOfPlayers;

    spaces(2);
    printWithDelay("Good game!", 10);

    Sleep(100);
    system ("CLS");

    string temp;

    for(int i = 0; i < numberOfPlayers; i++)
    {
       printWithDelay("Player 1", 10);
       spaces(2);
        for(int j = 1; j <= 10; j++)
        {
            temp = "Question ";
            temp += to_string(j);
            temp += ":";
            printWithDelay(temp, 10);
            spaces(2);
        }
        spaces(3);
    }
    Sleep(10000);
}