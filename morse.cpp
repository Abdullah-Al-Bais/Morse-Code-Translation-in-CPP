#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char alpha[36]= {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6','7','8','9','0'};
char morse[36][6]= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"};


int main()
{
    cout<<"!--WELCOME TO MORSE TRANSLATION--!"<<endl;
    cout<<"--We are using 'Full stop' as 'Dot'--"<<endl;
    cout<<"--We are using 'Minus' as 'dash'---"<<endl;
    cout<<"--Letters have 1 or 2 space between them--"<<endl;
    cout<<"--Words have 3 or more space between them--"<<endl;
    cout<<"======================="<<endl;
    cout<<"======================="<<endl;

    cout<<"   1. English to Morse "<<endl;
    cout<<"   2. Morse to English "<<endl;
    cout<<"Choose your option: ";

    int n;
    int flag=0;
    cin >>n;
    cin.ignore();
    string input;
    string sub_input;
    int pos=0;
    int i,j;

    if (n==1)
    {
        cout<<"====English to Morse===="<<endl;
        cout<<"............................................."<<endl;
        cout<<"Enter your English message:"<<endl;

        getline(cin, input);
        transform(input.begin(), input.end(), input.begin(),::toupper);

        cout<<"Morse Code:   ";
        for (i=0; i< input.length(); i++)
        {
            for(j =0; j<36; j++)
            {
                if(input[i]==alpha[j])
                {
                    cout<<morse[j]<<" ";
                }
                else if(input[i]==' ' || input[i]=='  ')
                {
                    cout<<"  ";
                    break;
                }

            }
        }
    }

    else if(n==2)
    {
        cout<<"====Morse To English===="<<endl;
        cout<<"............................................."<<endl;
        cout<<"Enter your Morse Code:"<<endl;
        getline(cin, input);

        cout<<"The Message:   ";
        for (i=0; i<input.length(); i++)
        {
            if(input[i]!=' ')
            {
                flag=0;
            }
            if (input[i]==' ' && flag<2)
            {
                flag++;
                sub_input=input.substr(pos,(i-pos));
                pos=i+1;//****
                for (j=0; j<36; j++)
                {
                    if (morse[j]==sub_input)
                    {
                        cout<<alpha[j];
                        break;
                    }
                }
                if (input[pos]==' ')//*****
                {
                    flag++;
                    i=pos;
                    pos=pos+1;
                }

                else
                {
                    flag=0;
                    continue;
                }

            }
            else if (input[i]==' '||flag>=2)
            {
                flag++;
                if(flag==3)
                {
                    cout<<"  ";
                }
                pos=i+1;

            }
            else if (i==(input.length()-1))
            {
                sub_input=input.substr(pos,(i+1-pos));

                for (j=0; j<36; j++)
                {
                    if (morse[j]==sub_input)
                    {
                        cout<<alpha[j];
                    }
                }

            }

        }
    }
    else
    {
        cout << "Invalid option!" << endl;
    }
}



