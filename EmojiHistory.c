/*******************************************************************************
 * PROGRAM:   Recent Emoji List
 * COURSE: PRO101: Computer Fundamentals
 * AUTHOR:    Aun Ratharanuth, Muny Reach, Sok Samnang, Rith Yousthoninsakd, Heang Sreynin, Kheng Leanghuot
 * LICENSE:    This project is developed as part of the Computer Fundamentals course at CamTech University.
 *             Copyright (c) 2026. All rights reserved. (Proprietary)
 * DESCRIPTION:
 * This program implements a recent history tracker for emojis. It 
 * allows users to input emojis, automatically clears duplicates by moving 
 * them to the front of the list, and limits the history pool to a maximum of 
 * 5 items. The history state is persistent, saving to and loading from an 
 * external text file ("history.txt").
 *
 * INPUTS:  
 * - Emoji strings via standard input (stdin).
 * - Historic data from "history.txt".
 *
 * OUTPUTS: 
 * - An updated terminal display of the 5 most recent unique emojis.
 * - Data written back to "history.txt" upon clean exit.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#define Length_Name 50
#define Emoji_List 10

char history_array[Emoji_List][Length_Name];
int current_count = 5; 

int finditem(char item[]);
int removeDuplicate(const char *target);
void shiftRight();
void insertFront(char item[]);
void displayHistory();
void saveHistory();
int loadHistory();
bool isemoji(const char *str);

int main() {
    char input_emoji[Length_Name];
    current_count = loadHistory();

    while(1){
        displayHistory();
        
        printf("Enter an Emoji or 'exit' to quit: ");
        fgets(input_emoji, Length_Name, stdin);

        input_emoji[strcspn(input_emoji, "\n")] = 0;

        if(!strcmp(input_emoji, "exit")) {
            printf("Exiting program\n");
            break;
        }
        
        if(!isemoji(input_emoji)) {
            printf("Invalid input or include space.\n");
            sleep(1);
            continue;
        }

        if(finditem(input_emoji)!= -1) {
            removeDuplicate(input_emoji);
        }
        
        insertFront(input_emoji);
        sleep(1);
    }
    saveHistory();
    return 0;
}


void shiftRight() {
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

void insertFront(char item[]) {
    // TODO: Call shiftRight(), then strcpy() the new emoji into index 0
    shiftRight();             
    strcpy(history_array[0], item); 
    if (current_count < Emoji_List) {
        current_count++;          
    }
}


void displayHistory() {
    if (current_count == 0) {
        printf("No recent emoji.\n");
        return;
    }

    for (int i = 0; i < current_count; i++) {
        printf("%s ", history_array[i]);
    }
    printf("\n");
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
    while (fscanf(fp, "%s", history_array[current_count]) == 1)
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

    for (i = 0; i < current_count; i++) {
        if (strcmp(history_array[i], target) == 0) {
            found_emo = i;
            break;
        }
    }

    if (found_emo == -1) {
    //     printf("Emoji not found.\n");
         return -1;
    }

    for (j = found_emo; j < current_count - 1; j++) {
        //emo_list[i][Length_Name] = emo_list[i+1][Length_Name];
        strcpy(history_array[j], history_array[j + 1]);
    }

    current_count--;
    // printf("Remaining emojis: \n");
    // for (j = 0; j < current_count - 1; j++) {
    //     printf("%s\n", history_array[j]);
    // }

    return 0;
}

bool isemoji(const char *str) {
    int len = strlen(str);

    if (len < 3) {
        return false;
    }

    int i = 0;
    int emojicount = 0;
    while(i < len) {
        unsigned char c = (unsigned char)str[i];
            if(c<=127) {
                return false;
            }

            if(c >=224 && c <= 247) {
                int bytes;
                    if(c >= 240) {
                        bytes = 4;
                    } else {
                        bytes = 3;
                    }
                    
                    if(i+bytes > len) {
                        return false;
                    }

                    for(int j = 1; j < bytes; j++) {
                        unsigned char next_c = (unsigned char)str[i+j];
                            if(next_c < 128 || next_c >191) {
                                return false;
                            }
                    }

                    i+= bytes;
                    emojicount++;
                    if (i < len) {
                        return false;
                    }

            } else {
                return false;
            }

        if(emojicount == 1) {
            return true;
        } else {
            return false;
        }
    }
}