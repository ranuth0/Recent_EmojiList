#include <stdio.h>
#include <string.h>

#define Length_Name 50
#define Emoji_List 10

// Global variables for the array of strings with fixed maximum size (Column F)
char recent_emojis[Emoji_List][Length_Name];
int current_count = 0;

// Function Prototypes (Column H)
int finditem(char *emoji);
void removeDuplicate(int index);
void shiftRight(int start_index);
void insertFront(char *emoji);
void displayHistory();
void saveHistory();
int loadHistory();

int main() {
    // 1. Try to load history from file at startup
    loadHistory();

    printf("=== DEMO: Initial History ===\n");
    displayHistory();

    printf("\n=== DEMO: Inserting items up to maximum size ===\n");
    insertFront("😀");
    insertFront("🔥");
    insertFront("🚀");
    insertFront("🎉");
    insertFront("👍");
    insertFront("❤️");
    insertFront("😎");
    insertFront("✨");
    insertFront("🌟");
    insertFront("💡"); // 10th item
    displayHistory();

    printf("\n=== DEMO: Duplicate Handling (Moving '🔥' to front) ===\n");
    insertFront("🔥"); // '🔥' already exists; should move to index 0 without duplicating
    displayHistory();

    printf("\n=== DEMO: Maximum-Size Behavior (Inserting 11th unique item '👑') ===\n");
    insertFront("👑"); // '👑' goes to front, oldest unique item should fall off
    displayHistory();

    printf("\n=== DEMO: Input Validation Testing ===\n");
    insertFront(""); // Empty input validation test
    insertFront("ThisEmojiNameIsWayTooLongAndShouldBeRejectedByTheValidationLogic"); // Length test

    // 2. Save history before exiting
    saveHistory();
    return 0;
}

// 1. Find item index
int finditem(char *emoji) {
    for (int i = 0; i < current_count; i++) {
        if (strcmp(recent_emojis[i], emoji) == 0) {
            return i; 
        }
    }
    return -1;
}

// 2. Remove duplicate item by shifting subsequent items left
void removeDuplicate(int index) {
    for (int i = index; i < current_count - 1; i++) {
        strcpy(recent_emojis[i], recent_emojis[i + 1]);
    }
    current_count--;
}

// 3. Shift elements to the right to make room at the front
void shiftRight(int start_index) {
    // Determine the boundary based on capacity (Column I)
    int end = (current_count < Emoji_List) ? current_count : Emoji_List - 1;
    
    for (int i = end; i > start_index; i--) {
        strcpy(recent_emojis[i], recent_emojis[i - 1]);
    }
    
    if (current_count < Emoji_List) {
        current_count++;
    }
}

// 4. Insert recent item with strict Input Validation (Column I)
void insertFront(char *emoji) {
    // VALIDATION 1: Check for empty input
    if (emoji == NULL || strlen(emoji) == 0) {
        printf("[Validation Error] Cannot insert empty input!\n");
        return;
    }

    // VALIDATION 2: Check maximum string length
    if (strlen(emoji) >= Length_Name) {
        printf("[Validation Error] Input too long! Maximum length allowed is %d.\n", Length_Name - 1);
        return;
    }

    // Check if it already exists
    int existing_index = finditem(emoji);
    if (existing_index != -1) {
        removeDuplicate(existing_index);
    }
    
    // Shift elements right to free up index 0
    shiftRight(0);
    
    // Insert at front
    strcpy(recent_emojis[0], emoji);
}

// 5. Display History
void displayHistory() {
    if (current_count == 0) {
        printf("No recent items.\n");
        return;
    }

    for (int i = 0; i < current_count; i++) {
        printf("%s ", recent_emojis[i]);
    }
    printf("\n");
}

// 6. File Handling Requirement: Save to file (Column G)
void saveHistory() {
    FILE *file = fopen("emoji_history.txt", "w");
    if (file == NULL) {
        printf("Error: Could not save history to file.\n");
        return;
    }
    for (int i = 0; i < current_count; i++) {
        fprintf(file, "%s\n", recent_emojis[i]);
    }
    fclose(file);
    printf("[System] History successfully saved to file.\n");
}

// 7. File Handling Requirement: Load from file (Column G)
int loadHistory() {
    FILE *file = fopen("emoji_history.txt", "r");
    if (file == NULL) {
        return 0; // File doesn't exist yet, which is fine for first run
    }
    
    current_count = 0;
    char temp[Length_Name];
    
    // Load up to capacity limit
    while (current_count < Emoji_List && fscanf(file, "%49s", temp) == 1) {
        strcpy(recent_emojis[current_count], temp);
        current_count++;
    }
    
    fclose(file);
    return 1;
}