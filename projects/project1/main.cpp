#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void run_game(string words[], int word_count, string letters); // Function that runs the game
bool is_game_over(int word_count, int found_word_count); // Checks to see if the game is over
void get_file(); // Gets the file and the data within it
void display_grid(string grid[15][15]); // Displays the grid with all the letters
void display_words(string words[], int word_count, string guessed_words[]); // Displays the words that have yet to be found
string get_coords(string words[], string grid[15][15]); // Get the coordinates of the desired position
string build_word(int guess[], string grid[15][15]); // Checks to see if the coordinates given produce a word

/*
 * Main function
 */
int main () {
    cout << "Welcome to UMBC word search" << endl;
    get_file();
    return 0;
}

/* This is where the bulk of the program is run, after getting the file
 * the game will begin where the player will look through the word search
 * and when they have found a word, input coordinates:
 * The program will tell the user whether they have found a new word,
 * and existing word, or not found a word */
void run_game(string words[], int word_count, string letters) {
    int found_words = 0; // Used to determine when the game will end
    string guessed_words[20]; // Used to store the guessed words
    int found_word_location = 100; // Used to store newly found words into the guessed words array

    // Create the grid
    string grid[15][15];
    int letter_num = 0;
    for (int x = 0; x < 15; x++) {
        for (int y = 0; y < 15; y++) {
            grid[x][y] = letters[letter_num];
            letter_num += 1;
        }
    }
    // Run through the game
    do {
        display_grid(grid); // Start turns by displaying the game board
        display_words(words, word_count, guessed_words); // Start turns by displaying the words list
        string guessed_word = get_coords(words, grid); // Then get the coordinates from the user and make the word guessed

        // Checks to see if the guessed word has been found, already been found, or is a newly found word
        int found_word = 0; // CODE: 0 = NOT FOUND // 1 = FOUND // 2 = ALREADY FOUND
        // Goes through the list of words and checks to see if the guessed word matches
        for (int i = 0; i < word_count; i++) {
            if (guessed_word == words[i]) {
                if (guessed_word == guessed_words[i]) {
                    found_word = 2; // Shows that the word was already found
                } else {
                    found_word = 1; // Shows the word is a newly found word
                    found_word_location = i; // Stores the location of the word
                }
            }
        }
        guessed_words[found_word_location] = words[found_word_location]; // Adds the guessed word to the array

        // Tell the user the status of their guess
        if (found_word == 1) { // Found a new word
            cout << "You found the word " << guessed_word << endl;
            found_words += 1;
        } else if (found_word == 2) { // Found an existing word
            cout << "You already found the word " << guessed_word << endl;
        } else { // Did not find a word
            cout << "You didn't find a word in the list" << endl;
        }
    } while (!is_game_over(word_count, found_words)); // Continuously gets input until the user has found all the words
    cout << "Thank you for playing UMBC Word Search!" << endl; // Game is now over
}

void get_file() {
    string fileName; // Name of the file to be loaded
    string info; // Used for obtaining information from the gameFile

    string letters; // Stores the letters from the game
    string words[10]; // Stores the words to be found
    int num_words = 0; // Number of words

    cout << "What is the name of the file you would like to load?" << endl;
    cin >> fileName;

    ifstream gameFile (fileName); // Open the given file
    if (gameFile.is_open()) { // Make sure the file is loaded
        while (gameFile >> info) {
            if (info.length() < 2 and info != " ") {
                letters += info;
            } else if (info.length() > 1 and info != " ") {
                words[num_words] = info;
                num_words += 1;
            }
        }
    } else {
        cout << "Unable to open file, try again" << endl;
        get_file(); // Re-run to get another file name from the user if the file cannot be opened
    }

    gameFile.close();

    cout << letters.length() << " letters imported." << endl; // Shows the number of letters imported
    cout << num_words << " words imported." << endl; // Shows the number of words imported

    run_game(words, num_words, letters); // Now run the game with the data obtained
}

/*
 * This function displays the grid to the user with numbered rows and columns
 */
void display_grid(string grid[15][15]) {
    cout << "    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14" << endl;
    for (int i = 0; i < 15; i++) {
        if (i < 10) { // This is for aesthetic and formatting (if the number is single digits, an extra space is given
            cout << " " << i << " ";
        } else { // Otherwise, just a single space will be shown
            cout << i << " ";
        }
        for (int j = 0; j < 15; j++) {
            cout << " " << grid[i][j] << " ";
        } cout << endl;
    }
}

/*
 * This function displays all the words, and whether a word has already been found or not
 * Found words have *** FOUND *** added to it to let the user know
 */
void display_words(string words[], int word_count, string guessed_words[]) {
    cout << "************************** WORDS LIST **************************" << endl;
    for (int i = 0; i < word_count; i++) {
        if (guessed_words[i] == words[i]) {
            cout << words[i] << " *** FOUND *** " << endl; // Display *** Found *** if the word was found
        } else {
            cout << words[i] << endl; // Otherwise, show the word as yet to be guessed/found
        }
    }
}

// Determines whether the game is over by comparing the number of words found to the total number of words
bool is_game_over(int word_count, int found_word_count) {
    if (found_word_count < word_count) {
        return false; // The game continues
    } else {
        return true; // The game is now over
    }
}

/*
 * This function gets the coordinates from the user, then passes to build_word to build the word, then
 * returns the word to run_game where it will be checked against the existing words list
 */
string get_coords(string words[], string grid[15][15]) {
    // Get the starting coordinates of the guess
    int start_x;
    int start_y;
    cout << "What is the starting X Y (separated by a space)?" << endl;
    cin >> start_x >> start_y;
    // Get the ending coordinates of the guess
    int end_x;
    int end_y;
    cout << "What is the ending X Y (separated by a space)?" << endl;
    cin >> end_x >> end_y;

    // Makes sure the points are not off the grid
    if (start_x > 15 or start_y > 15 or end_x > 15 or end_y > 15) {
        cout << "That point is not in the grid" << endl;
        get_coords(words, grid);
    }

    // Store the positions into an int array
    int guess[] = {start_x, start_y, end_x, end_y};
    string guessed_word = build_word(guess, grid);

    // Return the built word to be checked
    return guessed_word;
}

/*
 * This function builds the word based on the coords given by the user
 */
string build_word(int guess[], string grid[15][15]) {
    string guessed_word; // Used to build the guessed word
    int x1 = guess[0]; // first x pos given
    int y1 = guess[1]; // first y pos given
    int x2 = guess[2]; // second x pos given
    int y2 = guess[3]; // second y pos given

    guessed_word += grid[x1][y1]; // Start by adding the letter from the initial position given

    if (x1 > x2) { // If x1 is larger than x2...
        while (x1 > x2) {
            if (y1 > y2) { // If y1 is also larger than y2...
                x1 -= 1; // Modify x1,y1 by 1 to get the location of the next letter to be added
                y1 -= 1;
                guessed_word += grid[x1][y1]; // Add the new letter
            } else if (y1 < y2) { // If y1 is smaller than y2...
                x1 -= 1;
                y1 += 1;
                guessed_word += grid[x1][y1];
            } else { // If y1 and y2 are the same (same column/vertical)
                x1 -= 1;
                guessed_word += grid[x1][y1];
            }
        }
    }
    else if (x1 < x2) { // If x1 is smaller than x2...
        while (x1 < x2) {
            if (y1 > y2) {
                x1 += 1;
                y1 -= 1;
                guessed_word += grid[x1][y1];
            } else if (y1 < y2) {
                x1 += 1;
                y1 += 1;
                guessed_word += grid[x1][y1];
            } else {
                x1 += 1;
                guessed_word += grid[x1][y1];
            }
        }
    }
    else if (x1 == x2) { // If x1 = x2 (same row/horizontal)...
        while (y1 > y2) {
            y1 -= 1;
            guessed_word += grid[x1][y1];
        }
        while (y1 < y2) {
            y1 += 1;
            guessed_word += grid[x1][y1];
        }
    }
    // Now return the guessed word to be checked
    return guessed_word;
}
