#include <stdio.h>
#include <string.h>
//Let the emojilist store 5 emojis
#define Length_Name 50
#define Emoji_List 5

// for the original emoji_list
char emo_list[Emoji_List][Length_Name] = { "Laugh", "cry", "smile", "look", "angry"};


//remove the inputed emoji from the emoji list 
int removeDuplicate(const char *target) {
    int found_emo = -1;
    int i, j;

    for (i = 0; i < Emoji_List; i++) {
        if (strcmp(emo_list[i], target) == 0) {
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
        strcpy(emo_list[j], emo_list[j + 1]);
    }

    //emo_list[Emoji_List - 1][0] = '\0';

    printf("Remaining emojis: \n");
    for (j = 0; j < Emoji_List - 1; j++) {
        printf("%s\n", emo_list[j]);
    }

    return 0;
}

int main() {
    removeDuplicate("angry");
    return 0;
}
