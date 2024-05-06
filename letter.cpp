/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

#include "letter.h"

/*
* description: Mutator method for letter row
* return: void
* precondition: one integer is passed as a parameter
* postcondition: Sets the row with the parameter
*
*/
void letter::setRow(int r){
    row = r;
}

/*
* description: Mutator method for letter column
* return: void
* precondition: one integer is passed as a parameter
* postcondition: Sets the column with the parameter
*
*/
void letter::setCol(int c){
    col = c;
}

letter::letter(){
    row = 30;
    col = 30;
}

/*
* description: Reads that data from letter files
* return: void
* precondition: one string is passed as a parameter
* postcondition: Reads data from file
*
*/
void letter::readData(string fName){
    ifstream file;
    file.open(fName);
    assert(file);

    file >> row >> col;
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            file >> map[r][c];
        }
    }
    file.close();
}

/*
* description: Draws letter to screen
* return: void
* precondition: two integers and one plotter are passed as
*               parameters
* postcondition: draws letter to screen in white
*
*/
void letter::drawLetter(SDL_Plotter& g, int x = 0, int y = 0){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == '1'){
                g.plotPixel(x + j, y + i, 255,255,255);
            }
        }
    }

}


/*
* description: Mutator method for data matrix
* return: int
* precondition: two integers are passed as parameters
* postcondition: Returns the location of the matrix
*
*/
int letter::getData(int num1, int num2){
    return map[num1][num2];
}

/*
* description: Accessor method for letter row
* return: int
* precondition: no parameters are passed
* postcondition: returns the row
*
*/
int letter::getRow() const{
    return row;
}

/*
* description: Accessor method for letter column
* return: int
* precondition: no parameters are passed
* postcondition: returns the column
*
*/
int letter::getCol() const{
    return col;
}
