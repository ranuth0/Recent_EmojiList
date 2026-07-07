#include <stdio.h>
#include <string.h>

#define Length_Name 50
#define Emoji_List 10

char history_array[Emoji_List][Length_Name];
int current_count = 10; 

int finditem(char item[]);
int removeDuplicate(const char *target);
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
    int startindex;

    if(current_count < Emoji_List) {
        startindex = current_count - 1;
    } else {
        startindex = current_count - 2;
    }

    for(int i = startindex; i >= 0; i--) {
        strcpy(history_array[i+1], history_array[i]);
    }
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

void saveHistory() {
    FILE *fp = fopen("history.txt", "w");

    for(int i = 0; i < current_count; i++) {
        fprintf(fp, "%s\n", history_array[i]);
    }

    fclose(fp);
}

// Reads saved emoji strings from the .txt file back into history_array
int loadHistory() {
    // TODO: fopen("history.txt", "r"), fscanf() strings into array, return count
    FILE *fp;
    fp = fopen("history.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    int current_count = 0; 
    while (fscanf(fp, "%s", history_array[current_count])  != NULL)
    {
        current_count++;
    }
    fclose(fp);
    return current_count; 
}

int finditem(char item[])
{
    for (int i = 0; i < current_count; i++)
    {
        if (strcmp(history_array[i], item) == 0)
        {
            return i;
        }
    }
    return -1;
}


int removeDuplicate(const char *target) {
    int found_emo = -1;
    int i, j;

    for (i = 0; i < Emoji_List; i++) {
        if (strcmp(history_array[i], target) == 0) {
            found_emo = i;
            break;
        }
    }

    if (found_emo == -1) {
        printf("Emoji not found.\n");
        return -1;
    }

    for (j = found_emo; j < Emoji_List - 1; j++) {
        //emo_list[i][Length_Name] = emo_list[i+1][Length_Name];
        strcpy(history_array[j], history_array[j + 1]);
    }

    printf("Remaining emojis: \n");
    for (j = 0; j < Emoji_List - 1; j++) {
        printf("%s\n", history_array[j]);
    }

    return 0;
}
