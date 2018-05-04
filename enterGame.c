//
//  newGame.c
//  c_learn
//
//  Created by Shen guo on 5/1/18.
//  Copyright © 2018 Shen guo. All rights reserved.
//

#include "enterGame.h"
#include "basicFunctoinforNG.h"


void enterGame(int option) {
    
    if (option == 1)
        initialize(board);
    else if (option == 2)
        loadin(board);
    else {
        printf("Invalid instruction.\n");
        return;
    }
    
    putChess(board);
    
    return;
}
