#include <stdio.h>
#include <string.h>
//Let the emojilist store 10 emojis
#define Length_Name 50
#define Emoji_List 10

// for the original emoji_list
int emo_list[Emoji_List] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int finditem();

//remove the inputed emoji from the emoji list 
int removeDuplicate(int temp) {
    
    //the entered emo
    int found_emo = -1;
    int removed_size = Emoji_List-1;
    int i,j;
    for (i= 0; i< Emoji_List; i++ ) {

        //find the duplicated index
        if (emo_list[i] == temp) {
            found_emo = i;
        }
    }

    //for shifting element 
    for (j= found_emo; j< removed_size; j++ ) {
        emo_list[j] = emo_list[j+1];
    }

    //print remain element
    for (j= 0; j< removed_size; j++ ) {
        printf("%d ", emo_list[j]);
    }
    return 0;
}

void shiftRight();
void insertFront();
void displayHistory();
void saveHistory();
int loadHistory();

int main() {
    int a = 3;
    /* printf("Enter a number: ");
    scanf(" %d", &a); */
    removeDuplicate(a);
    return 0;
}
