#include <iostream>
#include <windows.h>
#include <cstdlib> //For generating a random number
#include <time.h> //For using current time as the seed value
using namespace std;

class GuessingGame
{
    protected: //Declaring variables of the game as protected for security and inheritance
        string game_mode;
        int random_number, input_number, min, max;
        unsigned int turns;
    public:
        GuessingGame() //Default constructor
        {
            game_mode = "None";
            random_number = input_number = turns = 0;
            min = max = 1;
        }
        void display_menu() //Function to display main page of the game
        {
            system("CLS");
            system("COLOR 1F");
            cout<<"************************"<<endl
                <<"* Number Guessing Game *"<<endl
                <<"************************"<<endl
                <<"---------"<<endl
                <<"MAIN MENU"<<endl
                <<"---------"<<endl
                <<"1. Play Game"<<endl<<"2. Exit"<<endl<<endl
                <<"Select your Option: ";
            int choice;
            cin>>choice;
            if (choice == 1)
            {
                select_mode();
            }
            else if (choice == 2)
            {
                cout<<"Thanks for playing this game :)"<<endl;
                exit(0);
            }
            else
            {
                cout<<"Invalid Option! ";
                system("PAUSE");
                display_menu();
            }

        }
        void select_mode() //Page for selecting game mode
        {
            system("CLS");
            cout<<"----------------"<<endl
                <<"Select Game Mode"<<endl
                <<"----------------"<<endl
                <<"1. Easy"<<endl<<"2. Medium"<<endl<<"3. Hard"<<endl<<"4. Custom"<<endl<<"5. Back"<<endl<<endl
                <<"Enter your selection number: ";
            int selection;
            cin>>selection;
            switch (selection) //Switch-case statement for selecting mode and defining min/max value accordingly
            {
            case 1:
                game_mode = "Easy";
                max = 20;
                play();
            case 2:
                game_mode = "Medium";
                max = 50;
                play();
            case 3:
                game_mode = "Hard";
                max = 100;
                play();
            case 4:
                system("CLS");
                cout<<"Enter starting range: ";
                cin>>min;
                cout<<"Enter ending range: ";
                cin>>max;
                if (min < max)
                {
                    game_mode = "Custom";
                    play();
                }
                else
                {
                    cout<<"Invalid range! ";
                    min = 1; max = 20;
                    system("PAUSE");
                    select_mode();
                }
            case 5:
                display_menu();
            default:
                cout<<"Invalid Selection! ";
                system("PAUSE");
                select_mode();
            }
        }
        void play () //Function to start playing the game
        {
            system("CLS");
            system("COLOR 0A");
            random_number = rand()%(max-min+1)+min; //Formula for generating a random number in given range
            turns = 0;
            cout<<"GAME MODE: "<<game_mode<<endl<<endl
                <<"Guess a number between "<<min<<" and "<<max<<endl;
            do  //Do-while loop to get input from user and check whether it is higher or lower
            {
                turns++;
                cout<<"Turn #"<<turns<<endl<<"Enter your guess (or enter -1 to quit game): ";
                cin>>input_number;
                if (input_number == -1)
                    break;
                else if (input_number < random_number)
                    cout<<"Your guess is too LOW!"<<endl;
                else if (input_number > random_number)
                    cout<<"Your guess is too HIGH!"<<endl;
            }
            while (input_number != random_number); //Loop will continue until the guess is not correct
            if (input_number == random_number)
            {
                cout<<endl<<"Congratulations! You won the game."<<endl
                    <<"The number was "<<random_number<<endl
                    <<"Total turns taken: "<<turns<<endl<<endl
                    <<"Do you want to play another game? (y/n): ";
                char opt;
                cin>>opt;
                switch (opt) //Switch-case statement for playing another game
                {
                case 'y':
                    play();
                case 'n':
                    cout<<"Returning to the main menu. ";
                    system("PAUSE");
                    display_menu();
                default:
                    cout<<"Invalid choice! Returning to main menu. ";
                    system("PAUSE");
                    display_menu();
                }
            }
            else
            {
                cout<<"The number was "<<random_number<<endl<<"Returning to the Main Menu. ";
                system("PAUSE");
                display_menu();
            }
        }
};


int main()
{
    srand(time(0)); //Initiating seed value as the current time
    GuessingGame game; //Declaring object of class GuessingGame
    game.display_menu(); //For displaying main page of the game
    return 0;
}