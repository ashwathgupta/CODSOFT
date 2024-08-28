#include<iostream>
using namespace std;

int main()
{
    double n1 , n2;
    int input;

    while(1)
    {
        cout<<"Enter 1st and 2nd number to perform calcualtion"<<endl;
        cin>>n1;
        cin>>n2;
        cout<<"Choose the operation to perform"<<endl;
        cout<<"1.Addition\n2.Subtraction\n3.Multiplication.\n4.Division\nPress any other key to exit\n\n";
        cin>>input;
        cout<<endl;

        switch(input)
        {
            case 1:
                cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
                break;
            case 2:
                cout<<n1<<" - "<<n2<<" = "<<n1-n2<<endl;
                break;
            case 3:
                cout<<n1<<" * "<<n2<<" = "<<n1*n2<<endl;
                break;
            case 4:
                cout<<n1<<" / "<<n2<<" = "<<n1/n2<<endl;
                break;
            default:
                cout<<"Exiting"<<endl;
                return 0;
        }

    }
}

