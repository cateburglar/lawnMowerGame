/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

#ifndef OBSTACLES_H_INCLUDED
#define OBSTACLES_H_INCLUDED
#include "SDL_Plotter.h"

struct obstacle{
    int x, y;
    const int size = 46; // size of obstacle

    /*
    * description: Draws obstacle object to screen
    * return: void
    * precondition: one plotter are passed as parameters
    * postcondition: Draw obstacle to screen
    *
    */
    void draw(SDL_Plotter& g);

    /*
    * description: Erases obstacle object to screen
    * return: void
    * precondition: one plotter are passed as parameters
    * postcondition: erases obstacle object
    *
    */
    void erase(SDL_Plotter& g);

};

#endif // OBSTACLES_H_INCLUDED
