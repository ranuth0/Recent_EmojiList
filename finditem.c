#include <stdio.h>
#include <string.h>

#define Length_Name 50
#define Emoji_List 10

char history[Emoji_List][Length_Name] = {
    "😂",
    "❤️",
    "🔥"
};

int count = 3;

int finditem(char item[])
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(history[i], item) == 0)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int index = finditem("🔥");

    if (index != -1)
        printf("Found at index %d\n", index);
    else
        printf("Not found\n");

    return 0;
}