#include<stdio.h>
#include<stdlib.h>


/*This is a function to check whether one of the players has succesfully placed their chance 3 times continuosly 
  in row-wise, column-wise or diagonally. */
int checkwin(int **board, int size, int player){
    for(int i=0; i<size ;++i){
        if((board[0][i]==player && board[1][i]==player && board[2][i]==player) || 
           (board[i][0]==player && board[i][1]==player && board[i][2]==player)){
            return 1; //returns 1 if row and column wise conditions are true. 
        }
    }
    if((board[0][0]==player && board[1][1]==player && board[2][2]==player) || 
       (board[0][2]==player && board[1][1]==player && board[2][0]==player)){
        return 1; //returns 1 if diagonal conditions are true. 
    }
    return 0;
};


/*This function is used to check if the game as resulted in a draw.
  If the cells have not yet been filled then it cannot be a draw. */
int checkdraw(int **board,int size){
    for(int i=0; i<size; ++i){
        for(int j=0; j<size; ++j){
            if(board[i][j]==0)
                return 0; //Because if the cells are 0 that means they havent been filled yet, therefore its not a draw 
        }
    }
    return 1; /*If the return 0 within the for loop is returned then the function will terminate, 
                else return 1 is given to show that the match as resulted in a draw. */
};

//Function to print the winners trophy ascii art. 
void printWinnerTrophy() {
    printf("    _______\n");
    printf("  /        \\\n");
    printf(" /          \\\n");
    printf(" |   /\\ /\\   |\n");
    printf(" |  // ^ \\\\  |\n");
    printf(" | // 0 0 \\\\ |\n");
    printf(" |//  \\_/  \\\\|\n");
    printf(" /           \\\n");
    printf("/_____________\\\n");
    printf("| You have won|\n");
    printf("|The Tic-Trophy|\n");
    printf("|______________|\n");
    printf("\n");
};


int main(){
    int size=3;
    int currentplayer=1;
            
    int** board=(int**)malloc(size * sizeof(int*));    //Memory allocation of columns of the array. 
    for(int i=0; i<size ; ++i){
        board[i]= (int*)malloc(size * sizeof(int));   //Memory allocation of rows of the array. 
    }

    for(int i=0; i<size ; ++i){
        for(int j=0; j<size; ++j){
            board[i][j]=0;                           //Initialising the values of the board to 0. 
        }
    }
    printf("Player 1 : X \nPlayer 2 : O\n");
    //This segment is used to start printing the values in the board as and when the decision of X/0 (1/0) is made. 
    int row, col, inrow, incol;
    while(1){
        int temp;                                    //This segment is to create a temp variable to display the player number. 
        if(currentplayer==1)
            temp=1;
        else if(currentplayer==-1)
            temp=2;

        printf("\nBoard Status:\n");
        for(int i=0; i<size; ++i){
            for(int j=0; j<size; ++j){
                if(board[i][j]==0)
                    printf("- ");
                else if (board[i][j]==1)
                    printf("X ");
                else
                    printf("O ");
            }
            printf("\n");
        }
        printf("------------------------------------------------------------------\n");

        printf("Player %d: Enter the row and column to place your move (1,2,3): \n",temp);
        scanf("%d %d",&inrow,&incol);                                    //Take input of row and column from the user. 
        
        
        row = inrow - 1;                                       //To add user friendlyness to the program. 
        col = incol - 1;

        if(row>=0 && row<size && col>=0 && col<size && board[row][col]==0){
            board[row][col]=currentplayer;                          //Move made by currentplayer is recorded at respective position
        }

        
        if(checkwin(board, size, currentplayer)){
            printf("\nPlayer %d has won the game!!!\n",temp);   //Checks if we have a winner. 
            printWinnerTrophy();
            break;
        }
        if(checkdraw(board, size)){
            printf("\nIt is a draw! *Failure noises* \n");             //Checks if it is a draw. 
            break;
        }

        currentplayer= -currentplayer;                               //When both checkwin and checkdraw fail, the game continues to the next player. 
    }

    for(int i=0; i<size; ++i){
        free(board[i]);
    }
    free(board);
}





