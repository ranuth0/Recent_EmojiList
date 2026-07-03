#include <stdio.h>
#include <string.h>

#define Length_Name 50
#define Emoji_List 10

char history_array[Emoji_List][Length_Name];
int current_count = 0; 

int finditem();
int removeDuplicate();
void shiftRight();
void insertFront();
void displayHistory();
void saveHistory();
int loadHistory();

int main() {
    
    return 0;
}


// Shifts string elements in history_array to the right to make room at index 0
void shiftRight() {
    // TODO: Implement loop shifting strings from index i to i+1 using strcpy()
}

// Inserts a new emoji name string at the very front (index 0) of the array
void insertFront() {
    // TODO: Call shiftRight(), then strcpy() the new emoji into index 0
}


// Prints out the current list of emoji strings stored in history_array
void displayHistory() {
    if (current_count == 0) {
        printf("No recent emoji.\n");
        return;
    }

    printf("Recent History (most recent first):\n");
    for (int i = 0; i < current_count; i++) {
        printf("%d. %s\n", i + 1, history_array[i]);
    }
}


// Writes the history_array strings into a permanent .txt file
void saveHistory() {
    // TODO: fopen("history.txt", "w"), loop and fprintf() strings, fclose()
}


// Reads saved emoji strings from the .txt file back into history_array
//Sakd
int loadHistory() {
    // TODO: fopen("history.txt", "r"), fscanf() strings into array, return count
    return 0; 
}

// Searches for a specific emoji string in the array
int finditem() {
    // TODO: Loop through array, use strcmp() to find match, return index or -1
    return -1; 
}


// Scans the array and cleans up any matching/repeated emoji strings
int removeDuplicate() {
    // TODO: Identify duplicates and compress the array
    return 0; 
}
