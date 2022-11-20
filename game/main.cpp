// Including neccessary libraries
#include <iostream>
#include <windows.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function for text animation
// Note: Sleep() - function for delay from windows.h
void printWithDelay(string text, unsigned int milSeconds = 10)
{
    int len = text.length();

    for (int i = 0; i < len; i++)
    {
        cout << text[i];
        if (text[i] == '.' or text[i] == '!' or text[i] == '?')
            Sleep(milSeconds * 2);
        else
            Sleep(milSeconds);
    }
}

// Function for printing spaces
void spaces(unsigned int num)
{
    for (int i = 0; i < num; i++)
    {
        cout << '\n';
    }
}

// Declaring gloval var for number of players
unsigned int numberOfPlayers;

// Function for greeting player and input of numberOfPlayers
void welcomeFun()
{
    system("CLS");
    string temp = "Hello! This is quiz-game which will test your knowledge in Geography! Let's start.)";
    printWithDelay(temp, 30);

    Sleep(1000);
    system("CLS");

    temp = "Enter numder of players: ";
    printWithDelay(temp, 10);
    cin >> numberOfPlayers;

    spaces(1);
    temp = "Good game!";
    printWithDelay(temp, 10);

    Sleep(1000);
    system("CLS");
}

// Function for getting random number in range
int getRandNum(int range1, int range2)
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); // seeding for the first time only!
        first = false;
    }
    return range1 + (rand() % range2);
}

// Function for sorting players' score
int *bubbleSort(int *array, int size)
{
    bool flag;
    int temp;
    while (true)
    {
        flag = 1;
        for (int i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                flag = 0;
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        if (flag)
            break;
    }
    return array;
}

// // Structure which contains players' scores, quesitons and answears and printing them
struct gameMechanic
{
    int current_player;
    int rounds = 5;
    int *playersScore = new int[numberOfPlayers];

    string capitals[9][2] = {
        {"What is the capital of Romania?", "Bucharest"},
        {"What is the capital of Moldova?", "Chisinau"},
        {"What is the capital of Serbia? ", "Belgrade"},
        {"What is the capital of Albania? ", "Tirana"},
        {"What is the capital of Greece?", "Athens"},
        {"What is the capital of Bosnia and Herzegovina?", "Sarajevo"},
        {"What is the capital of North Macedonia?", "Skopje"},
        {"What is the capital of Kosovo? ", "Pristina"},
        {"What is the capital of Croatia?", "Zagreb"}};

    string languages[9][2] = {
        {"What language do they speak in Romania?", "Romanian language"},
        {"What language do they speak in Moldova?", "Romanian language"},
        {"What language do they speak in Serbia?", "Serbian language"},
        {"What language do they speak in Albania?", "Albanian language"},
        {"What language do they speak in Greece?", "Greek language"},
        {"What language do they speak in Bosnia and Herzegovina?", "Bosnian/Serbian language"},
        {"What language do they speak in North Macedonia?", "Macedonian language"},
        {"What language do they speak in Kosovo", "Albanian/Serbian language"},
        {"What language do they speak in Croatia?", "Croatian language"}};

    // Function for printing question and the answer
    void questanswear()
    {   
        // Var for type of questions
        int choose_type = getRandNum(0, 2);
        // Index of question and answer
        int index = getRandNum(0, 9);
        // Тemp
        int tempIndex;
        int answearRandPosition = getRandNum(0, 4);
        int userInput;

        string question;
        string answear;
        string variantsOfanswears[4];
        string tempValue;

        bool x;

        if (choose_type == 0)
        {
            question = capitals[index][0];
            answear = capitals[index][1];
            for (int i = 0; i < 4; i++)
            {
                if (i == answearRandPosition)
                    variantsOfanswears[i] = answear;
                else
                {
                    // Block for checking repetitions of answers
                    while (true)
                    {
                        x = 1;
                        tempIndex = getRandNum(0, 9);
                        tempValue = capitals[tempIndex][1];
                        for (int k = 0; k <= i; k++)
                        {
                            if (variantsOfanswears[k] == tempValue or tempValue == answear)
                                x = 0;
                        }
                        if (x)
                            break;
                    }
                    variantsOfanswears[i] = tempValue;
                }
            }
        }
        else
        {
            question = languages[index][0];
            answear = languages[index][1];
            for (int i = 0; i < 4; i++)
            {
                if (i == answearRandPosition)
                    variantsOfanswears[i] = answear;
                else
                {
                    // Block for checking repetitions of answers
                    while (true)
                    {
                        x = 1;
                        tempIndex = getRandNum(0, 9);
                        tempValue = languages[tempIndex][1];
                        for (int k = 0; k <= i; k++)
                        {
                            if (variantsOfanswears[k] == tempValue or tempValue == answear)
                                x = 0;
                        }
                        if (x)
                            break;
                    }
                    variantsOfanswears[i] = tempValue;
                }
            }
        }

        printWithDelay(question);
        spaces(2);

        for (int i = 0; i < 4; i++)
        {
            printWithDelay(to_string(i + 1));
            printWithDelay(") ");
            printWithDelay(variantsOfanswears[i]);
            cout << " ";
        }

        spaces(2);

        printWithDelay("Your answear: ");
        cin >> userInput;
        userInput -= 1;

        spaces(1);

        if (variantsOfanswears[userInput] == answear)
        {
            printWithDelay("Correct!");
            playersScore[current_player] += 20;
        }
        else
            printWithDelay("Incorrect.(");
    }

    // Main function which uses questanswear()
    void play()
    {
        string temp;
        for (int i = 0; i < numberOfPlayers; i++)
        {
            current_player = i;
            playersScore[i] = 0;
            printWithDelay("Player " + to_string(i + 1));
            spaces(2);
            for (int q = 1; q <= 5; q++)
            {
                temp = "Question ";
                temp += to_string(q);
                temp += ": ";
                printWithDelay(temp);
                questanswear();
                Sleep(1000);
                system("CLS");
            }
            Sleep(1000);
            system("CLS");
            temp = "Score of Player " + to_string(i + 1);
            temp += ": ";
            temp += to_string(playersScore[i]);
            temp += " out of 100";
            printWithDelay(temp);
            Sleep(1000);
            system("CLS");
        }

        // Block for printing the results
        int copiedPlayersScore[100];
        for(int i = 0; i < numberOfPlayers; i++)
        {
            copiedPlayersScore[i] = playersScore[i];
        }

        bubbleSort(playersScore, numberOfPlayers);
        int tempIndex;
        int count = 1;

        for (int i = numberOfPlayers - 1; i >= 0; i--)
        {
            temp = to_string(count++);
            temp += "# ";
            temp += "Player ";
            for (int k = 0; k < numberOfPlayers; k++)
            {
                if (copiedPlayersScore[k] == playersScore[i])
                    tempIndex = k;
            }
            temp += to_string(tempIndex + 1);
            printWithDelay(temp);
            spaces(1);
        }
        Sleep(5000);
    }
};

int main()
{
    welcomeFun();
    gameMechanic game;
    game.play();
}