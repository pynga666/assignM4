#include "stdio.h"
#include "string.h"

int charCount();

int main() {
    char current_word[100];
    char search_word[100];
    int i, j;
    int count=0;
    char array[charCount()];
    int index=0;
    char c;
    FILE *fp;
    fp = fopen("words.txt","r");
    while ((c = fgetc(fp)) !=EOF){
        array[index]=c;
        index++;
    }
    fclose(fp);

    printf("***Find 'winhtut'||'NationalCyberCity' CASE SENSITIVE***\nTYPE : ");
    scanf("%s",&search_word);
    for (i = 0, j = 0; i <= strlen(array); i++) {
        if (array[i] == ' ' || array[i] == '\0' || array[i] == '\n' || array[i] == '.') {
            current_word[j] = '\0';
            if (strcmp(current_word, search_word) == 0) {
                count++;
            }
            j = 0;
        }
        else {
            current_word[j] = array[i];
            j++;
        }
    }
    printf("Found '%s' %d times\n",search_word,count);
}
int charCount(){
    FILE *fp ;
    fp = fopen("words.txt","r");
    char c;
    int count=0 ;
    while ((c = fgetc(fp)) !=EOF){
        count++;
    }
    fclose(fp);
    return count;
}