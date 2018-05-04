//
//  basicFunctoinforNG.c
//  c_learn
//
//  Created by Shen guo on 5/3/18.
//  Copyright © 2018 Shen guo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "basicFunctoinforNG.h"

const char player[] = {'X', 'O'};
char board[SIZE][SIZE];
int i;


// print the board out.
void printBoard(char board[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        for (int k = 0; k < SIZE; k++) {
            printf("%2c", board[j][k]);
        }
        printf("\n");
    }
    return;
}

// initialize the board with 'E' in every location.
void initialize(char board[SIZE][SIZE]) {
    i = 0;
    int j, k;
    for (j = 0; j < SIZE; j++) {
        for (k = 0; k < SIZE; k++) {
            board[j][k] = 'E';
        }
    }
    printf("The board :\n");
    printBoard(board);
    return;
}


// instruct the player pick up location.
void putChess(char board[SIZE][SIZE]) {
    printf("\nYou can press -1 to save and exist the game.\n\n");
    int row = 0, col = 0;
            
    for (; i < SIZE * SIZE; i++) {
        //enter row
        printf("%c's term:\nPlease enter row :", player[i % 2]);
        scanf("%d", &row);
        if (row == -1)
            return;
        while (row >= SIZE) {
            printf("Out of range! Please pick up another location.\n");
            printf("Please enter row :");
            scanf("%d", &row);
        }
        
        //enter col
        printf("Please enter col :");
        scanf("%d", &col);
        if (col == -1)
            return;
        while (col >= SIZE) {
            printf("Out of range! Please pick up another location.\n");
            printf("Please enter col :");
            scanf("%d", &col);
        }
        
        //check if the location is empty
        if (board[row][col] != 'E') {
            printf("Wrong step. Please pick up another location.\n");
            i--;
            continue;
        }
        
        //put sign on the location
        board[row][col] = player[i % 2];
        
        printf("The board :\n");
        printBoard(board);
        saveGame(board);
        
        //check if anyone wins
        if (check(board, row, col)) {
            printf("%c wins!\n", player[i % 2]);
            return;
        }
    }
    
    //when the board is full and no one wins
    printf("It's a draw.\n");
    return;
}

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int check (char board [SIZE][SIZE], int row, int col) {
    int count = 0, start, end;
    char sign = player[i % 2];
    
    //check row
    start = MIN (row, GOAL - 1);
    end = MIN(SIZE - row - 1, GOAL - 1);
    
    for (int j = row - start; j <= row + end; j++) {
        if (board[j][col] == sign)
            count++;
        else
            count = 0;
        if(count == GOAL) {
            return 1;
        }
    }
    
    //check col
    start = MIN (col, GOAL - 1);
    end = MIN(SIZE - col - 1, GOAL - 1);
    count = 0;
    
    for (int k = col - start; k <= col + end; k++) {
        if (board[row][k] == sign)
            count++;
        else
            count = 0;
        if(count == GOAL) {
            return 1;
        }
    }
    
    
    //check downward diagonal
    start = MIN(MIN(row, col), GOAL - 1);
    end = MIN(MIN(SIZE - row - 1, SIZE - col - 1), GOAL - 1);
    count = 0;
    
    for (int j = row - start, k = col - start; j <= row + end && k <= col + end; j++, k++) {
        if (board[j][k] == sign)
            count++;
        else
            count = 0;
        if(count == GOAL) {
            return 1;
        }
    }
    
    //check upward diagonal
    start = MIN(MIN(SIZE - row - 1, col), GOAL - 1);
    end =  MIN(MIN(row, SIZE - col - 1), GOAL - 1);
    count = 0;
    
    for (int j = row + start, k = col - start; j >= row - end && k <= col + end; j--, k++) {
        if (board[j][k] == sign)
            count++;
        else
            count = 0;
        if(count == GOAL) {
            return 1;
        }
    }
    return 0;
}

//save the game
void saveGame (char board[SIZE][SIZE]) {
    FILE *fp;
    fp = fopen("/Users/shenguo/Desktop/c/c_learn/c_learn/C-Language/XOGame/savedGame.txt", "w");
    
    fprintf(fp, "%s %d", board, i + 1);
    
    fclose(fp);
    return;
}

//load in saved game
void loadin (char board[SIZE][SIZE]) {
    FILE *fp;
    
    fp = fopen("/Users/shenguo/Desktop/c/c_learn/c_learn/C-Language/XOGame/savedGame.txt", "r");
    if (fp == NULL) {
        printf("Unable to load in game.\n");
        return;
    }
    
    for(int j = 0; j < SIZE; j++) {
        for (int k = 0; k < SIZE; k++) {
            char s[] = "0";
            fscanf(fp, "%c", &s[0]);
            board[j][k] = s[0];
        }
    }
    
    printf("The board :\n");
    printBoard(board);
    fscanf(fp, "%d", &i);
    
    fclose(fp);
    
    return;
}
