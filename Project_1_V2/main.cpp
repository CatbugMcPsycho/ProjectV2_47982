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
void game();            //Function to hold game
//Execution Starts here
int main(int argc, char** argv) {
    //Declare variables
    int inN;
    do{
            Menu();
            inN=getN();
            switch(inN){
            case 1: instruct();break;
            case 2: game();break;
            default:   def(inN);}
        }while(inN<3);
        return 0;
    return 0;
}
void game(){
    char colors[4],
         win='n',
         userclr[4];
    srand(time(0));
    int clrnum,
        turns=0;
    for(int i=0;i<4;i++){
	clrnum=(rand()%5)+1;//Random number 0 to 5

	switch(clrnum){//Changes numbers into colors
            case 1:{
               colors[i]='R';//Red
               break;
            }
            case 2:{
               colors[i]='B';//Blue
               break;
            }
            case 3:{
               colors[i]='Y';//Yellow
               break;
            }
            case 4:{
               colors[i]='P';//Purple
               break;
            }
            case 5:{
               colors[i]='G';//Green
               break;
            }
        }         
    }
    while(turns!=10){//Turn limit is 10, stops there
        turns++;
        cout<<"Colors to pick from: Blue, Green, Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter for your guess(capital letters only)."<<endl;
        cout<<"Turn Number: "<<turns<<endl;

            for(int i=0;i<4;i++){//User enter 4 colors
                    cout<<"Color"<<i<<": "; 
                    cin>>userclr[i];
                    cout<<endl;
            }

            for(int i=0;i<4;i++){//Checks if any are right color and position
                if(userclr[i]==colors[i]){
                    cout<<"R"<<" ";
                }
            }
            if(userclr[0]==colors[1]|| //Checks if any are the right color
               userclr[0]==colors[2]||
               userclr[0]==colors[3]){
                cout<<"W"<<" ";
            }
            if(userclr[1]==colors[0]||//Checks if any are the right color
               userclr[1]==colors[2]||
               userclr[1]==colors[3]){
                cout<<"W"<<" ";
            }
            if(userclr[2]==colors[0]||//Checks if any are the right color
               userclr[2]==colors[1]||
               userclr[2]==colors[3]){
                cout<<"W"<<" ";
            }
            if(userclr[3]==colors[0]||//Checks if any are the right color
               userclr[3]==colors[1]||
               userclr[3]==colors[2]){
                cout<<"W"<<" ";
            }
            cout <<endl<<endl;
            if(userclr[0]==colors[0]&&//Confirms if all of the colors are right
               userclr[1]==colors[1]&&
               userclr[2]==colors[2]&&
               userclr[3]==colors[3]){
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
