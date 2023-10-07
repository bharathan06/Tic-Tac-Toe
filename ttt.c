#include<stdio.h>
#include<stdlib.h>


/*This is a function to check whether one of the players has succesfully placed their chance 3 times continiously 
  in row-wise, column-wise or diagonally. */
int checkwin(int **board, int size, int player){
    for(int i=0; i<size ;++i){
        if((board[0][i]==player && board[1][i]==player && board[2][i]==player) || 
           (board[i][0]==player && board[i][1]==player && board [i][2==player])){
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

    //This segment is used to start printing the values in the board as and when the decision of X/0 (1/0) is made. 
    int row, col;
    while(1){
        printf("Current status of the game.\n");
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

        printf("Player %d: Enter the row and column to place your move: \n",currentplayer);
        scanf("%d %d",&row,&col);                                    //Take input of row and column from the user. 

        if(row>=0 && row<size && col>=0 && col<size && board[row][col]==0){
            board[row][col]=currentplayer;                          //Move made by currentplayer is recorded at respective position
        }

        
        if(checkwin(board, size, currentplayer)){
            printf("Player %d has won the game!!!\n",currentplayer);   //Checks if we have a winner. 
            break;
        }
        if(checkdraw(board, size)){
            printf("It is a draw! *Failure noises* \n");             //Checks if it is a draw. 
            break;
        }

        currentplayer= -currentplayer;                               //When both checkwin and checkdraw fail, the game continues to the next player. 
    }

    for(int i=0; i<size; ++i){
        free(board[i]);
    }
    free(board);
}





