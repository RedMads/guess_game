/*
Hi guys, im RedMad this my frist offcial C++ Program !

C++ is HARD and ADVANCED for me but i will go through it :P


The IDEA of this game:

    The Program will choose a random number based on the configuration file
    the High number the more Harder!, is simple Classic Guessing Game!
    
    If you close to the number the program will let you know by 2 Msges (Low, High)


    WARNING:
        Don't Delete the < settings.conf > file is the main settings file!
        Don't Rename it or chnge the file path!


    Licenses:

        Use it how ever you like!


    I hope this program help people to Learn C++ or Programming!


*/



#include <iostream>
#include <string>
#include <stdint.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <limits>

using namespace std;



class Game{

    public:

        int load_settings(){

            string data;


            fstream fin("settings.conf",ios::in);

            while (fin >> data)

                max = stoi(data.substr(6, data.length() - 2));


            return max;
            

        }


        // Global variable !
        int max = load_settings();



        // This Function run all the main functions (Save time) !
        void run_all(){

            Game().load_settings(), Game().clean_banner(), Game().game();

        }



        // Generate random number and return it!
        int random_int(int max){

            srand(time(0));

            int number = 1 + rand() % max;

            return number;
        }


        void clean_banner(){
            
            system("clear");
            cout << "\a\a\a*** WELCOME TO THE GUESSING GAME ***\a\a\a\n" << endl;
            cout << "         By RedMad :$ v1.0\n\n\n" << endl;

        }

            
        // The main game function!
        void game(){


            // Some needed variabels :$
            int random_number = random_int(max), counter = 0;;
            long long number_input;
            string main_input;
                      

            // Main while loop
            while (true) {


                cout << "[?] Enter Number: "; 

                cin >> number_input;             

                counter++;



                if(number_input == random_number){
                    
                    Game().clean_banner();
                    cout << "[$] YOU WIN THE GAME !! ";

                    cout << "\n\n[$] NUMBER: " << random_number;

                    cout << "\n\n[$] TRYS: " << counter;

                    cout << "\n\n[?] Play Again? (y/n): ";

                    cin >> main_input;


                    // Inested while loop !
                    while (true) {


                        if (main_input == "y") {

                            Game().run_all();
                            random_number = random_int(100);
                            break;

                        }

                        else if(main_input == "n") {

                            cout << "\n\n[$] Bye Bye :$" ;

                            exit(1);
                        }

                        else {


                            cout << "[?] Play Again? (y/n): ";

                            cin >> main_input;

                        }   

                    }
                }


                else if (number_input > max){
                    cin.clear();
                    cin.ignore();

                    Game().clean_banner();
                    cout << "[!] The value you enter is Higher than " << max << "\n\n";

                }

                else if (number_input > random_number){
                    cin.clear();
                    cin.ignore();

                    Game().clean_banner();
                    cout << "[$] Try Low!" << "\n\n";
                    

                }


                else if (number_input < random_number && number_input != 0){
                    
                    cin.clear();
                    cin.ignore();

                    Game().clean_banner();
                    cout << "[$] Try High!" << "\n\n";

                }


                else {

                    cin.clear();
                    cin.ignore();

                    Game().clean_banner();
                    cout << "[!] The value you entered is not a number !" << "\n\n";


                }
                

            }

        }





};


int main(){


    // Call the RUN game function !
    Game().run_all();


    return 0;
}



