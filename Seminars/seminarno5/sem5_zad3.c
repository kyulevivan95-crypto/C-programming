#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // 1. Създаваме текстов файл с примерни думи
    FILE *f = fopen("input.txt", "w");
    fprintf(f, "apple car price elephant head tire cool soft eleven output night tent story movies pleasure memory time search shortcut river compare evening");
    fclose(f);

    // 2. Отваряме за четене
    f = fopen("input.txt", "r");

    char word[51];
    char prev[51];

    char **result = NULL;
    int size = 0;

    // четем първата дума
    if(fscanf(f, "%s", word) == 1){
        result = (char**)malloc(sizeof(char*));
        result[0] = (char*)malloc(strlen(word) + 1);
        strcpy(result[0], word);
        size = 1;

        strcpy(prev, word);
    }

    // четем останалите
    while(fscanf(f, "%s", word) == 1){
        int len_prev = strlen(prev);
        
        if(word[0] == prev[len_prev - 1]){
            result = (char**)realloc(result, (size + 1) * sizeof(char*));
            result[size] = (char*)malloc(strlen(word) + 1);
            strcpy(result[size], word);
            size++;

            strcpy(prev, word);
        }
    }

    fclose(f);

    // 3. Запис в бинарен файл
    FILE *bin = fopen("output.bin", "wb");

    fwrite(&size, sizeof(int), 1, bin);

    for(int i = 0; i < size; i++){
        int len = strlen(result[i]);
        fwrite(&len, sizeof(int), 1, bin);
        fwrite(result[i], sizeof(char), len, bin);
    }

    fclose(bin);

    // 4. Четене от бинарен файл
    bin = fopen("output.bin", "rb");

    int n;
    fread(&n, sizeof(int), 1, bin);

    printf("From binary file:\n");

    for(int i = 0; i < n; i++){
        int len;
        fread(&len, sizeof(int), 1, bin);

        char *temp = (char*)malloc(len + 1);
        fread(temp, sizeof(char), len, bin);
        temp[len] = '\0';

        printf("%s ", temp);

        free(temp);
    }

    fclose(bin);

    // 5. Освобождаване на памет
    for(int i = 0; i < size; i++){
        free(result[i]);
    }
    free(result);

    return 0;
}