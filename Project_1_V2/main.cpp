/* 
 * File:   main.cpp
 * Author: Devin Taniguchi
 * Created on October 22, 2013, 9:32 PM
 * Purpose: Project
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//No Global Constants

//Function Prototype
void Menu();
int getN();
void def(int);
void instruct();        //Instructions
void game(char[]);            //Function to hold game
void cCLR(char[],int,int);
//Execution Starts here
int main(int argc, char** argv) {
    //Declare variables
    const int PLR=2;
    const int COLOR=4;
    char cCode[PLR][COLOR];
    int inN;
    do{
            Menu();
            inN=getN();
            switch(inN){
            case 1: instruct();break;
            case 2:{
                cCLR(cCode,PLR,COLOR)
                game();break;
            }
            default:   def(inN);}
        }while(inN<3);
        return 0;
    return 0;
}
void cCLR(char c[],int r, int k){
    srand(time(0));
    int clrnum;
    for(int i=0;i<k+1;i++){
	clrnum=(rand()%5)+1;//Random number 0 to 5

	switch(clrnum){//Changes numbers into colors
            case 1:{
               c[0][i]='R';//Red
               break;
            }
            case 2:{
               c[0][i]='B';//Blue
               break;
            }
            case 3:{
               c[0][i]='Y';//Yellow
               break;
            }
            case 4:{
               c[0][i]='P';//Purple
               break;
            }
            case 5:{
               c[0][i]='G';//Green
               break;
            }
        }         
    }
}
void game(char c[]){
    char win='n';
    int turns=0;
    while(turns!=10){//Turn limit is 10, stops there
        turns++;
        cout<<"Colors to pick from: Blue, Green, Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter for your guess(capital letters only)."<<endl;
        cout<<"Turn Number: "<<turns<<endl;

            for(int i=0;i<4;i++){//User enter 4 colors
                    cout<<"Color"<<i<<": "; 
                    cin>>c[1][i];
                    cout<<endl;
            }

            for(int i=0;i<4;i++){//Checks if any are right color and position
                if(c[1][i]==c[0][i]){
                    cout<<"R"<<" ";
                }
                else{
                    if((c[1][i]==c[0][0]|| //Checks if any are the right color
                        c[1][i]==c[0][1]||
                        c[1][i]==c[0][2]||
                        c[1][i]==c[0][3])&&
                        c[1][i]!=c[0][i]){
                        cout<<"W"<<" ";
                    }
                    
                }
            }
            
            cout <<endl<<endl;
            if(c[1][0]==c[0][0]&&//Confirms if all of the colors are right
               c[1][1]==c[0][1]&&
               c[1][2]==c[0][2]&&
               c[1][3]==c[0][3]){
                cout<<"You win! Number of tries: "<<turns<<endl;
                win='y';//Too make sure lose doesn't print
                turns=10;
            }
            else{
                cout<<"Incorrect."<<endl<<endl;
            }
    }
    if(turns==10&&win=='n'){
            cout << "You lost." << endl;
    }
    cout<<endl;
}
void instruct(){//Rules
    cout<<"The main objective is to solve the computer's code."<<endl;
    cout<<endl;
    cout<<"With a 4 color combination for a code and 5 colors"<<endl;
    cout<<" to choose from you have the guess the combo in 10 "<<endl;
    cout<<"or you lose."<<endl;
    cout<<endl;
    cout<<"Additionally each time you guess you will be told "<<endl;
    cout<<"Whether you have a right color in the right "<<endl;
    cout<<"position or a right color in the wrong position "<<endl;
    cout<<"by the Rs and Ws at the end of your code."<<endl;
    cout<<"(Rs for right spot and color and Ws for only right color)"<<endl;
    cout<<endl;
}
void Menu(){
            cout<<"MASTERMIND"<<endl;
            cout<<"Type 1 for the Instructions"<<endl;
            cout<<"Type 2 to Play"<<endl;
            cout<<"Type anything else to exit"<<endl;
    }
    int getN(){
            int inN;
            cin>>inN;
            return inN;
    }
void def(int inN){
            cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }
