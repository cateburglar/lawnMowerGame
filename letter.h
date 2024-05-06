/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

#ifndef LETTER_H_INCLUDED
#define LETTER_H_INCLUDED

#include <cassert>
#include <fstream>
#include <string>
#include <sstream>
#include "SDL_Plotter.h"

using namespace std;

const int MAX_LETTER = 30;

class letter{
    private:
        char map[MAX_LETTER][MAX_LETTER];
        int row, col;
        /*
        * description: Mutator method for letter row
        * return: void
        * precondition: one integer is passed as a parameter
        * postcondition: Sets the row with the parameter
        *
        */
        void setRow(int);
        /*
        * description: Mutator method for letter column
        * return: void
        * precondition: one integer is passed as a parameter
        * postcondition: Sets the column with the parameter
        *
        */
        void setCol(int);
    public:
        letter();
        /*
        * description: Draws letter to screen
        * return: void
        * precondition: two integers and one plotter are passed as
        *               parameters
        * postcondition: draws letter to screen in white
        *
        */
        void drawLetter (SDL_Plotter&, int, int);
        /*
        * description: Reads that data from letter files
        * return: void
        * precondition: one string is passed as a parameter
        * postcondition: Reads data from file
        *
        */
        void readData(string);
        /*
        * description: Mutator method for data matrix
        * return: int
        * precondition: two integers are passed as parameters
        * postcondition: Returns the location of the matrix
        *
        */
        int getData(int, int);
        /*
        * description: Accessor method for letter row
        * return: int
        * precondition: no parameters are passed
        * postcondition: returns the row
        *
        */
        int getRow() const;
        /*
        * description: Accessor method for letter column
        * return: int
        * precondition: no parameters are passed
        * postcondition: returns the column
        *
        */
        int getCol() const;
};


#endif // LETTER_H_INCLUDED
