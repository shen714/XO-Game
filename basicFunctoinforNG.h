//
//  basicFunctoinforNG.h
//  c_learn
//
//  Created by Shen guo on 5/3/18.
//  Copyright © 2018 Shen guo. All rights reserved.
//

#ifndef basicFunctoinforNG_h
#define basicFunctoinforNG_h

#include <stdio.h>

#define GOAL 3
#define SIZE 5

extern char board[][SIZE];
extern int i;
extern const char player[];

int check(char [SIZE][SIZE], int, int);
void initialize(char [SIZE][SIZE]);
void loadin(char [SIZE][SIZE]);
void printBoard(char [SIZE][SIZE]);
void putChess(char [SIZE][SIZE]);
void saveGame(char [SIZE][SIZE]);

#endif /* basicFunctoinforNG_h */
