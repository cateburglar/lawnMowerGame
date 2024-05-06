/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "letter.h"
#include <string>
#include <ctime>
#include <iostream>

// Enumeration declaration for direction
enum Direction {UP, DOWN, LEFT, RIGHT};

/*
* description: Draws word to the screen
* return: void
* precondition: one string, two integers and one plotter are passed as
*               parameters
* postcondition: Gets letters from font function
*/
void drawWord(string word, int x, int y, SDL_Plotter& g);

/*
* description: Reads font from txt file
* return: void
* precondition: one array is passed into the parameter
* postcondition: Reads the .txt file
*/
void readFont(letter upperLetters[]);

/*
* description: Displays start screen
* return: void
* precondition:  one plotter are passed as parameters
* postcondition: Draws to the start screen
*/
void playScreen(SDL_Plotter& g);

/*
* description: Displays end screen
* return: void
* precondition: two integers as the scores and one plotter are passed as
*               parameters
* postcondition: Displays end screen and score with high score
*/
void endScreen(SDL_Plotter& g, int currScore, int& highscore);

/*
* description: Checks the direction of the key
* return: Direction
* precondition: one char is passed as the parameters
* postcondition: Assigns the direction of the lawn mower from the user
*/
Direction checkDirection(char key);

#endif // FUNCTIONS_H_INCLUDED
