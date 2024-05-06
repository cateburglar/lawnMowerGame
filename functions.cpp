/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */
#include "functions.h"

/*
* description: Draws word to the screen
* return: void
* precondition: one string, two integers and one plotter are passed as
*               parameters
* postcondition: Gets letters from font function
*/
void drawWord(string word, int x, int y, SDL_Plotter& g){
    int current;
    letter upperLetters[100];
    char currChar;
    int initialX = x;

    readFont(upperLetters);

    for(unsigned int i = 0; i < word.size(); i++){
        currChar = word.at(i);

        if(currChar == ' '){
            current = 36;
        }
        else if(currChar == ':'){
            current = 37;
        }
        else if(currChar == '!'){
            current = 38;
        }
        else if(isdigit(currChar)){
            current = currChar - 48 + 26;
        }
        else{
            current = toupper(currChar) - 'A';
        }
        upperLetters[current].drawLetter(g, x, y);
        x += upperLetters[current].getRow() + 10;
        if (x < 0 || x > 800 - 20){
            y += upperLetters[current].getRow() + 10;
            x = initialX;
        }
    }

}

/*
* description: Reads font from txt file
* return: void
* precondition: one array is passed into the parameter
* postcondition: Fills the array with fonts from txt files
*/
void readFont(letter upperLetters[]){
    upperLetters[0].readData("a.txt");
    upperLetters[1].readData("b.txt");
    upperLetters[2].readData("c.txt");
    upperLetters[3].readData("d.txt");
    upperLetters[4].readData("e.txt");
    upperLetters[5].readData("f.txt");
    upperLetters[6].readData("g.txt");
    upperLetters[7].readData("h.txt");
    upperLetters[8].readData("i.txt");
    upperLetters[9].readData("j.txt");
    upperLetters[10].readData("k.txt");
    upperLetters[11].readData("l.txt");
    upperLetters[12].readData("m.txt");
    upperLetters[13].readData("n.txt");
    upperLetters[14].readData("o.txt");
    upperLetters[15].readData("p.txt");
    upperLetters[16].readData("q.txt");
    upperLetters[17].readData("r.txt");
    upperLetters[18].readData("s.txt");
    upperLetters[19].readData("t.txt");
    upperLetters[20].readData("u.txt");
    upperLetters[21].readData("v.txt");
    upperLetters[22].readData("w.txt");
    upperLetters[23].readData("x.txt");
    upperLetters[24].readData("y.txt");
    upperLetters[25].readData("z.txt");
    upperLetters[26].readData("zero.txt");
    upperLetters[27].readData("one.txt");
    upperLetters[28].readData("two.txt");
    upperLetters[29].readData("three.txt");
    upperLetters[30].readData("four.txt");
    upperLetters[31].readData("five.txt");
    upperLetters[32].readData("six.txt");
    upperLetters[33].readData("seven.txt");
    upperLetters[34].readData("eight.txt");
    upperLetters[35].readData("nine.txt");
    upperLetters[36].readData("space.txt");
    upperLetters[37].readData("colon.txt");
    upperLetters[38].readData("exclamation.txt");
}

/*
* description: Displays start screen by description of game
* return: void
* precondition:  one plotter is passed as a parameter
* postcondition: Draws to the start screen
*/
void playScreen(SDL_Plotter& g){
    for (int y = 0; y < 800; y++) {
        for (int x = 0; x < 800; x++) {
            g.plotPixel(y, x, 50, 0, 50);
        }
    }

    drawWord("Welcome to Lawnmower Simulator!", 20, 50, g);
    drawWord("Avoid the rocks and survive as long as you can!", 20, 90, g);
    drawWord("Use the arrow keys to change", 10, 190, g);
    drawWord("directions", 10, 220, g);
    drawWord("for easy mode: press e", 20, 300, g);
    drawWord("for medium mode: press m", 20, 330, g);
    drawWord("for hard mode: press h", 20, 360, g);
    drawWord("press space to play", 20,450,g);
    drawWord("press c to continue last saved", 20, 480, g);
    drawWord("game", 20, 510, g);

    return;
}

/*
* description: Displays end screen
* return: void
* precondition: two integers as the scores and one plotter are passed as
*               parameters
* postcondition: Displays end screen and score with high score
*/
void endScreen(SDL_Plotter& g, int currScore, int& highscore){
    ifstream inFile;
    ofstream outFile;

    drawWord("game over! score: ", 50, 80, g);
    drawWord(to_string(currScore), 470, 80, g);

    inFile.open("highscore.txt");
    if(inFile){
        inFile >> highscore;
        if(currScore > highscore){
            highscore = currScore;
        }
    }
    outFile.open("highscore.txt");
    outFile << highscore;
    inFile.close();
    outFile.close();
    drawWord("Highscore: ", 50, 120, g);
    drawWord(to_string(highscore), 300, 120, g);
}

/*
* description: Checks the direction of the key
* return: Direction
* precondition: one char is passed as the parameters
* postcondition: Assigns the direction of the lawn mower from the user
*/
Direction checkDirection(char key){
    Direction dir;

    switch(key) {
        case UP_ARROW: dir = UP;
                       break;

        case DOWN_ARROW: dir = DOWN;
                       break;

        case LEFT_ARROW: dir = LEFT;
                       break;

        case RIGHT_ARROW: dir = RIGHT;
                       break;
    }

    return dir;
}
