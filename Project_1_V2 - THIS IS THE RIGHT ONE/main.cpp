/* 
 * File:   main.cpp
 * Author: Devin Taniguchi
 * Created on October 22, 2013, 9:32 PM
 * Purpose: Project
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <fstream>
using namespace std;

//No Global Constants

//Function Prototype
void Menu();
int getN();
void def(int);
void instruct();        //Instructions
void game(char[][4],string[],int &,int &);   //Function to hold game
void cCLR(char[][4],int,int);

//Execution Starts here
int main(int argc, char** argv) {
    //Declare variables
    const int PLR=2;
    const int COLOR=4;
    char cCode[PLR][COLOR];
    string list[10];
    int inN,
        nWins,
        nLoses;
    do{
            Menu();
            inN=getN();
            //reads in file
            //Tells Current win lose ratio
            
            switch(inN){
            case 1: instruct();break;
            case 2:{
                //Read file in
                ifstream in;
                in.open("ratio.dat");
                in>>nWins;
                in>>nLoses;
                cout<<"Current Win Lose record is"<<endl;
                cout<<"Wins: "<<nWins<<endl;
                cout<<"Losses: "<<nLoses<<endl;
                cout<<endl;
                //Play Game
                cCLR(cCode,PLR,COLOR);
                game(cCode,list,nWins,nLoses);
                //Output to same file
                ofstream out;
                out.open("ratio.dat");
                out<<nWins<<endl;
                out<<nLoses<<endl;
                //Close files
                in.close();
                out.close();
                break;
            }
            default:   def(inN);}
        }while(inN<3);
        return 0;
    return 0;
}

void cCLR(char c[][4],int r, int k){
    srand(time(0));
    int clrnum;
    for(int i=0;i<k+1;i++){
        //Random number 0 to 5
	clrnum=(rand()%5)+1;
        
        //Changes numbers into colors
	switch(clrnum){
            case 1:{
               //Red
               c[0][i]='R';
               break;
            }
            case 2:{
               //Blue
               c[0][i]='B';
               break;
            }
            case 3:{
                //Yellow
               c[0][i]='Y';
               break;
            }
            case 4:{
               //Purple
               c[0][i]='P';
               break;
            }
            case 5:{
               //Green
               c[0][i]='G';
               break;
            }
        }         
    }
}

void game(char c[][4],string p[],int &w,int &l){
    char win='n';
    int des,
        turns=0;
    
    //Turn limit is 10, stops there
    while(turns!=10){
        turns++;        
        
        //Rules
        cout<<"Colors to pick from: Blue, Green,";
        cout<<" Yellow, Purple, and Red."<<endl;
        cout<<"Please enter the first letter ";
        cout<<"for your guess(capital letters only)."<<endl;
        cout<<endl;
        cout<<"Turn Number: "<<turns<<endl;
        cout<<endl;
        
            //User enter 4 colors
            for(int i=0;i<4;i++){
                    cout<<"Color"<<i<<": "; 
                    cin>>c[1][i];
                    cout<<endl;
            }
        
            //Checks if any are right color and position
            for(int i=0;i<4;i++){
                if(c[1][i]==c[0][i]){
                    cout<<"R"<<" ";
                }
                
                //Checks if any are the right color
                else{
                    if((c[1][i]==c[0][0]|| 
                        c[1][i]==c[0][1]||
                        c[1][i]==c[0][2]||
                        c[1][i]==c[0][3])&&
                        c[1][i]!=c[0][i]){
                        cout<<"W"<<" ";
                    }
                    
                }
            }
            
            cout<<endl;
            cout<<endl;
            
            //Sends array to a string and puts string into an array
            //temp=c[1][0]<<c[1][1]<<c[1][2]<<c[1][3];
            //l[turns-1]=temp;
            string temp(c[1],4);
            p[turns-1]=temp;
            
            //Confirms if all of the colors are right
            if(c[1][0]==c[0][0]&&
               c[1][1]==c[0][1]&&
               c[1][2]==c[0][2]&&
               c[1][3]==c[0][3]){
                cout<<"You win! Number of tries: "<<turns<<endl;
                cout<<endl;
                
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<turns;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }
            
                //Too make sure lose doesn't print
                win='y';
                turns=10;
                
                //changing win lose ratio
                w+=1;
            }
            else{
                cout<<"Incorrect."<<endl;
                cout<<endl;
            }
    }
    //If turns exceed 10 you lose
    if(turns==10&&win=='n'){
            cout<<"You lost."<<endl;
            cout<<endl;
            
            //Outputs different tries
            cout<<"Here are your attempts."<<endl;
            cout<<endl;
            
            //Prints out each letter then ends line
            for(int i=0;i<10;i++){
                cout<<"Attempt #"<<i+1<<endl;
                cout<<p[i]<<endl;
                cout<<endl;
                }  
            
            //Changing Win Lose Ratio
            l+=1;
            }
    
    cout<<endl;
}

void instruct(){
    //Rules
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
