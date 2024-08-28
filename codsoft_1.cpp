/* TASK 1: NUMBER GUESSING GAME
Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number

Coded by: Ashwath Gupta
Version 1 , Date: 19 August 2024 


*/

#include <iostream>
#include <random>
using namespace std;
void game(void)
{
    random_device rd;  // Obtain a random number from hardware
    mt19937 gen(rd()); // Seed the generator
    int r1,r2;
    cout<<"Enter the range of numbers to guess "<<endl;
    cin>>r1;
    cin>>r2;

    uniform_int_distribution<> distr(r1, r2); // Define the range

    int n=distr(gen); // Generate numbers
    int input,count=0;

    
    
    while(input!=n)
    {
        cout<<"Enter a number between "<<r1 <<" and "<<r2<<endl;
        cin>>input;
        count++;
        if(input==n)
        {   
            if(count==1)
            {
                cout<<"Congratulations you have guessed the correct number in "<<count<<" try "<<endl;
            }
            else if(count>1)
            {
                cout<<"Congratulations you have guessed the correct number in "<<count<<" tries "<<endl;
            }
        }
        else if(input>n)
        {
            cout<<"Your guess "<<input<<" higher"<<endl;

        }
        else if(input<n)
        {
            cout<<"Your guess "<<input<<" lower"<<endl;
        
        }
    }

}
int main() {

   while(1)
   {
        cout<<"WELCOME TO THE  NUMBER GUESSING GAME"<<endl;
        cout<<"1.Start Game"<<endl;
        cout<<"2.Exit Game"<<endl;

        int start;
        cin>>start; 
        switch(start)
        {
            case 1: 
                game();
                break;
        
            case 2: 
                cout<<"Exiting game"<<endl;
                return 0;
                break;
            default:
                cout<<"Invalid input";
                return 0;
        } 

   } 
   


    return 0;
}
