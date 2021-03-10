#include<bits./stdc++.h>
using namespace std;

void printInputMatrix();
void printBoard();
int addMark();
int check();

char board[3][3] = {' ',' ',' ',
                    ' ',' ',' ',
                    ' ',' ',' ',};

int turn = 1; //1-player 1  | 0-player 2
int mark = 'o'; // o player 1 | x player 2
int input;

int main(){
    int won = 0;
    int validInput =0;

    for(int i = 0; i<9;i++){
        system("cls");
        printBoard();
        if(turn) cout<<"Player 1 turn (symbol: o)"<<endl;
        else cout<<"player 2 turn (symbol:x)"<<endl;
        printInputMatrix();
        cout<<"Enter input from Input Matrix: ";
        cin>>input;
        while (input<0 || input>9)
        {
            cout<<"Invalid Input. Please Re-Enter input: ";
            cin>>input;
        }
        if(turn) mark = 'o';
        else mark = 'x';

        validInput = addMark();
        if(!validInput){
            i--;
            continue;
        }
        won = check();
        if(won){
            system("cls");
            printBoard();
            if(turn) cout<<endl<<"*** player 1 - won You won ***";
            else cout<<endl<<"*** player 2 - won You won ***";
            break;
        }
        if(i == 8){
            system("cls");
            printBoard();
            cout<<endl<<"*** Match Draw ***";
        }

        turn = !turn;
        
    }
    return 0;
}

void printInputMatrix(){
    cout<<endl<<endl<<"Input Matrix"<<endl;
    cout<<" 1 | 2 | 3 "<<endl;
    cout<<" -----------"<<endl;
    cout<<" 4 | 5 | 6 "<<endl;
    cout<<" -----------"<<endl;
    cout<<" 7 | 8 | 9 "<<endl;
}
void printBoard(){
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
    cout<<" -----------"<<endl;
    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
    cout<<" -----------"<<endl;
    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
}

int addMark(){
    for(int i = 0, k = 1;i<3;i++){
        for(int j = 0;j<3;j++,k++){
            if( k ==input){
                if(board[i][j] == ' '){
                    board[i][j] = mark;
                    return 1;
                }
                else{
                    cout<<"Invalid Input";
                   // getch();
                    return 0;
                }
            }
        }
    }
}

int check(){
    //checking rows
    if(board[0][0] == mark && board[0][1] == mark && board[0][2] ==mark )
     return 1;
    if(board[1][0] == mark && board[1][1] == mark && board[1][2] ==mark )
     return 1;
    if(board[2][0] == mark && board[2][1] == mark && board[2][2] ==mark )
     return 1;
     //checking column
    if(board[0][0] == mark && board[1][0] == mark && board[2][0] ==mark )
     return 1;
    if(board[0][1] == mark && board[1][1] == mark && board[2][1] ==mark )
     return 1;
    if(board[0][2] == mark && board[1][2] == mark && board[2][2] ==mark )
     return 1;
     //checking diagonal
    if(board[0][0] == mark && board[1][1] == mark && board[2][2] ==mark )
     return 1;
    if(board[0][2] == mark && board[1][1] == mark && board[2][0] ==mark )
     return 1;


     return 0;   
    
}

