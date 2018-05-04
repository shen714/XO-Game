//
//  XOgame.c
//  c_learn
//
//  Created by Shen guo on 5/1/18.
//  Copyright © 2018 Shen guo. All rights reserved.
//


#include <stdio.h>
#include "enterGame.h"

int main () {
    int option;
    int continueGame = 1;
    printf("==========Welcome to XO Game==========\n");
    while (continueGame) {
        printf("Choose :\n1.New Game\n2.Load in Saved Game\n");
        scanf("%d", &option);
        enterGame(option);
        
        printf("0.Exist or 1. Continue\n");
        scanf("%d", &continueGame);
    }
    return 0;
}
