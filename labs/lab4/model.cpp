#include "model.h"
#include <cstdlib>
#include <ctime>

using namespace std;

// Constructor initializes the object
Model::Model(int w, int h) {
    width = w;
    height = h;
    state = INIT;
    // Two dimensional array
    grid = new char*[height];
    visible = new char*[height];
    // For every row, create the array for that row
    for (int i = 0; i < height; i++) {
        grid[i] = new char[width];
        visible[i] = new char[width];
    }
    char letter = 'A';
    // Guarantee pairs of characters in the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grid[i][j] = letter;
            // Everything's invisible at first
            visible[i][j] = '_';
            // Every other iteration...
            if (j % 2 == 1) {
                letter++;
                if (letter > 'Z') {
                    letter = 'A';
                }
            }
        }
    }
    // Seed random number generator with time
    srand(time(0));
    // Randomize
    int otheri, otherj;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Pick a random spot in the grid
            otheri = rand() % height;
            otherj = rand() % width;
            // Swap grid[i][j] with grid[otheri][otherj]
            letter = grid[i][j];
            grid[i][j] = grid[otheri][otherj];
            grid[otheri][otherj] = letter;
        }
    }
}
// Destructor deletes dynamically allocated memory
Model::~Model() {
    for (int i = 0; i < height; i++) {
        delete grid[i];
        delete visible[i];
    }
    delete grid;
    delete visible;
}
// TODO: Is the row/column valid?
// That is, is the row within the height, and is the column within the width?
// Return whether it is or isn't.
bool Model::valid(int row, int column) {
    return true;
}
bool Model::matched(int row, int column) {
    return true;
}
// TODO: Flip a cell
void Model::flip(int row, int column) {
    // If the row and column are not valid, break out and don't do anything
    if (!valid(row, column)) { return; }
    visible[row][column] =  grid[row][column];
	
    switch(state) {
    case INIT:
        // clear out lastRow and lastColumn
        lastRow.clear();
        lastColumn.clear();
        state = FIRST;
        break;
    case FIRST:
        // Check to see if the grid at last row and column match what's in the grid the current column
        // set the state accordingly
		if (grid[lastRow.back()][lastColumn.back()] == grid[row][column]) {
			state = INIT;
		} else {
			state = NO_MATCH;
		}
        break;
    case NO_MATCH:
		visible[lastRow.back()][lastColumn.back()] = '_';
		lastRow.pop_back();
		lastColumn.pop_back();
		visible[lastRow.back()] [lastColumn.back()] = '_';
        // clear out the visible state in the last two rows/columns
        // go to the first state
        break;
    }
    lastRow.push_back(row);
    lastColumn.push_back(column);
}
// TODO: If everything is visible, then it's game over
bool Model::gameOver() {
    // Hint: assume the game is over, unless it isn't
    // Hint: Loop through the grid and see if any element is not visible
    return false;
}
int Model::getWidth() {
    return width;
}
int Model::getHeight() {
    return height;
}
char Model::get(int row, int col) {
	return visible[row][col];
}