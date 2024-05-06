/*
* Author: Austin Carlin, Catherine Arlinghau, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

#include "obstacles.h"

/*
* description: Erases obstacle object to screen
* return: void
* precondition: one plotter are passed as parameters
* postcondition: erases obstacle object
*
*/

void obstacle::erase(SDL_Plotter& g){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            g.plotPixel(x + j, y + i, 0, 255, 0);
        }
    }
}

/*
* description: Draws obstacle object to screen
* return: void
* precondition: one plotter are passed as parameters
* postcondition: Draw obstacle to screen
*
*/void obstacle::draw(SDL_Plotter& g){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            g.plotPixel(x+j, y+i, 50, 75, 50);
        }
    }
}
