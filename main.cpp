/*
* Author: Austin Carlin, Catherine Arlinghaus, Erin Koehler, Kiana Walters
* Assignment Title:  Group Project
* Assignment Description:
* Due Date: 12/7/2022
* Date Created: 11/29/2022
* Date Last Modified: 12/7/2022
 */

/*
 * Data Abstraction:
 *         Variables are declared to be used in drawing the game
 * Input:
 *         The program displays the beginning screen and reads the keyboard
            hits by the user in order to determine what to do next. E, M, H
            set the difficulty levels, and C and space start the game.
 * Process:
 *         Once the user starts the game, the screen is initialized to all
            green and instructions are kept on the screen while the user plays.
            The arrows control the lawn-mower's direction.
            If the user hits p, the game pauses. If the user hits s, the game
            ends the user's current score is saved. If the user hits a
            "rock" or goes off the screen, the game ends. The current highscore
            is displayed after the user dies.
 * Output:
 *         The all-time highscore is displayed to the screen when the user dies.
            Words are output to the screen to direct the user what to hit and
            how to play.
 * Assumptions:
 *
 */
#include <iostream>
#include "functions.h"
#include <string>
#include <ctime>
#include "obstacles.h"
#include "SDL_Plotter.h"
using namespace std;

const int SIZE = 36; // constant integer for size of lawn mower
const int NUM_COL = 800; // constant integer for screen size
const int NUM_ROW = 800; // constant integer for screen size


int main(int argc, char **argv){
    SDL_Plotter plotter;
    char key; // char to key from user
    int length = 2;
    SDL_Plotter g(NUM_ROW,NUM_COL); // plotter declared with size
    int R=20, G=20, B=255; // default color
    int xLoc[length], yLoc[length]; // array story the x and y location
    int prevX, prevY;
    Direction dir = RIGHT; // sets the initial direction of lawnmower to right
    int startTime = 0, stopTime = 0; // declares the start and stop time
    bool startGame = false; // sets the game to false
    bool pause = false; // sets pause to false
    bool continueLastGame = false; // sets continue to false
    int prevScore, currScore;
    vector<obstacle> obstacles; // vector list to store obstacles
    int counter = 0; // counter to reset obstacle loop
    int difficulty = 15; // default difficulty
    ifstream inFile; // input file stream to get saved data and high score
    ofstream outFile; // output file stream
    int highscore = 0; // counter for high score

    // initializing music file
    g.initSound("SnakeMusic1.wav");

    // places the lawn mower in the center of the screen
    xLoc[0] = NUM_COL/2;
    xLoc[1] = NUM_COL/2 - SIZE;
    yLoc[0] = NUM_ROW/2;
    yLoc[1] = NUM_ROW/2;

    // starts the screen and reads users key while not quit
    while(!g.getQuit() && !startGame){
        playScreen(g); // screen opens
        if(g.kbhit()) {
            key = g.getKey(); // gets key char
            switch(key) {
                case SDLK_SPACE:
                    startGame = true; // starts game with space key
                    break;
                case SDLK_e: // easy difficulty
                    difficulty = 15; // obstacles appear slower
                    break;
                case SDLK_m: // medium difficulty
                    difficulty = 8;
                    break;
                case SDLK_h: // hard difficulty
                    difficulty = 3; // obstacles appear faster
                    break;
                case SDLK_c: // continue key from saved file
                    // opens file to get current score
                    inFile.open("currGame.txt");
                    continueLastGame = true;
                    startGame = true;
                    if(inFile) {
                        inFile >> prevScore; // reads last score
                    }
                    inFile.close(); // closes file
                    break;
            }
        } // end if statement
        g.update(); // updates screen
    } // end while loop

    if(startGame) {
        startTime = clock(); // starts time
        g.playSound("SnakeMusic1.wav"); // play music file while game starts

        // Initializes screen to be green
        for (int y = 0; y < NUM_ROW; y++) {
            for (int x = 0; x < NUM_COL; x++) {
                g.plotPixel(y, x, 0, 128, 0);
            }
        }

        // tells the user how to save, pause, and resume
        drawWord("press p to pause and s to save", 20, 20, g);
        drawWord("press space to resume", 20, 50  , g);

        while (!g.getQuit() && startGame) {
            // Gets user input while moving lawn mower
            if (g.kbhit()) {
                key = g.getKey();
                dir = checkDirection(key); // direction of the lawn mower
                switch(key){
                    case SDLK_p: // pauses game
                        pause = true;
                        break;
                    case SDLK_s: // saves the game
                        startGame = false; // stops game
                        stopTime = clock(); // stops time
                        currScore = stopTime - startTime; // assigns score
                        outFile.open("currGame.txt"); // opens file with saved
                                                    //score
                        if(outFile) {
                            outFile << currScore; // writes score to file
                        }
                        outFile.close();
                        break;
                    case SDLK_SPACE: // resumes game
                        pause = false;
                        dir = RIGHT;
                        break;
                }
            }

            //Process**********************************************
            prevX = xLoc[0];
            prevY = yLoc[0];

            if(!pause){

                switch (dir) {
                    case RIGHT: xLoc[0] += SIZE; // moves right
                                break;
                    case LEFT  : xLoc[0] -= SIZE; // moves left
                                 break;

                    case UP    : yLoc[0] -= SIZE; // moves up
                                 break;

                    case DOWN  : yLoc[0] += SIZE; // moves down
                                 break;
                }

                // Mows lawn
                for(int i = 0; i < length; i++) {
                    for (int y = 0; y < SIZE; y++) {
                        for (int x = 0; x < SIZE; x++) {
                            g.plotPixel(prevX + x, y + prevY, 139,69,19);//brown
                            g.plotPixel(y, x, 0, 128, 0);
                        }
                    }
                }

                // Copy cell locations
                for (int i = length - 1; i > 0; i--) {
                    xLoc[i] = xLoc[i - 1];
                    yLoc[i] = yLoc[i - 1];
                }

                counter++;
                // Creates new and random obstacles and pushes to vector
                if(counter > difficulty) {
                    obstacle curr;
                    curr.x = SIZE * (rand() % 20);
                    curr.y = SIZE * (rand() % 20);
                    obstacles.push_back(curr);
                    counter = 0; // restarts counter
                }

              // Draws the lawn mower
               for(int i = 0; i < length; i++) {
                    for (int y = 0; y < SIZE; y++) {
                        for (int x = 0; x < SIZE; x++) {
                            g.plotPixel(xLoc[i] + x, yLoc[i] + y, R,G,B);
                        }

                    }
               }

               // Draws Obstacles
                for(unsigned int i = 0; i < obstacles.size(); i++){
                    obstacles[i].draw(g);
                }
                // Checks if the lawn mower runs into the obstacle
                // or goes off the screen
                for(int i = 0; i < length; i++){
                    for(unsigned int j = 0; j < obstacles.size(); j++){
                        if(abs(xLoc[i] - obstacles[j].x) <= 36 &&
                           abs(yLoc[i]- obstacles[j].y) <= 36){
                            startGame = false; // ends game
                        }
                        if((xLoc[i] > NUM_COL || yLoc[i] > NUM_ROW) ||
                            (xLoc[i] < 0 || yLoc[i] < 0)){
                            startGame = false; // ends game
                        }
                    }
                }
            }
            stopTime = clock(); // reads stop time
            currScore = stopTime - startTime; // assigns score with the times
            if (continueLastGame) {
                currScore += prevScore;
            }

            currScore /= 100;

            g.update(); // updates screen
            g.Sleep(90); // rendering speed

        } // end while loop for main game
    } // end if statement for main game

    while(!startGame && !g.getQuit()){
        // end screen function
        endScreen(g, currScore, highscore);
        g.update();
    }


    return 0;
} // end main
/**


plotter.setColor(0, 255, 0);

// Clear the screen with the green background color
plotter.clear();

// Loop until the user closes the window
while(plotter.getQuit() == false) {
    // Update the screen with the green background
    plotter.update();
}

return 0;
}*/
