#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <time.h>
using namespace std;

void game_menu();
void select_mode();
void play(string, int, int);

int main()
{
    srand(time(0));
    game_menu();
    return 0;
}

void game_menu ()
{
    system("COLOR F1");
    cout<<"************************************** Number Guessing Game Menu **************************************"
        <<endl<<endl
        <<"1. Play Game"<<endl<<"2. High Scores"<<endl<<"3. Exit"<<endl
        <<"Select your Option: ";
    int choice;
    cin>>choice;
    switch (choice)
    {
    case 1:
        select_mode();
    case 2:
        system("CLS");
        cout<<"No High-scores!"<<endl;
        game_menu();
    case 3:
        exit(0);
    default:
        system("CLS");
        cout<<"Invalid choice! Try again."<<endl;
        game_menu();
    }
}

void select_mode()
{
    system("CLS");
    system("COLOR 10");
    cout<<"Choose Your Game Mode"<<endl
        <<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl<<"4. Custom"<<endl<<"5. Back"<<endl
        <<"Enter your selection number: ";
    int selection;
    cin>>selection;
    switch (selection)
    {
    case 1:
        play("Easy", 1, 20);
    case 2:
        play("Medium", 1, 50);
    case 3:
        play("Hard", 1, 100);
    case 4:
        system("CLS");
        int num1, num2;
        cout<<"Enter starting range: ";
        cin>>num1;
        cout<<"Enter ending range: ";
        cin>>num2;
        if (num1 < num2)
            play("Custom", num1, num2);
        else
            select_mode();
    case 5:
        game_menu();
    default:
        game_menu();
    }
}

void play (string game_mode, int lower_limit, int upper_limit)
{
    system("CLS");
    system("COLOR 49");
    unsigned int number_of_turns = 0;
    int random_number = rand()%(upper_limit-lower_limit+1)+lower_limit;
    int input_number;
    cout<<game_mode<<endl;
    cout<<"The number is between "<<lower_limit<<" and "<<upper_limit<<endl;
    do
    {
        number_of_turns++;
        cout<<"Turn #"<<number_of_turns<<": Enter your guess (or enter -1 to quit game): ";
        cin>>input_number;
        if (input_number == -1)
            break;
        else if (input_number < random_number)
            cout<<"Your guess is lower than the actual number!"<<endl;
        else if (input_number > random_number)
            cout<<"Your guess is higher than the actual number!"<<endl;
    }
    while (input_number != random_number);
    if (input_number == random_number)
    {
        cout<<"Congratulations! You won by guessing the correct number."<<endl
            <<"The number was "<<random_number<<endl
            <<"Total turns taken: "<<number_of_turns<<endl
            <<"Do you want to play another game? (y/n): ";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case 'y':
            system("CLS");
            play(game_mode, lower_limit, upper_limit);
        case 'n':
            system("CLS");
            game_menu();
        default:
            system("CLS");
            cout<<"Invalid choice! Returning to main menu..."<<endl;
            game_menu();
        }
    }
    else
    {
        system("CLS");
        cout<<"The number was "<<random_number<<endl;
        game_menu();
    }
}
