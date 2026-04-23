#include <stdio.h>
#include <stdlib.h>

int main(){
    char filename[100];
    int key;

    // 1. Създаваме файл (първоначално празен)
    FILE *f = fopen("filen.txt", "w");
    fclose(f);

    // 2. Добавяме примерен текст
    f = fopen("filen.txt", "w");
    fprintf(f, "Hello World\nThis is a test file\nProgramming in C is fun");
    fclose(f);

    // 3. Четем име на файл
    printf("Enter file name: ");
    scanf("%s", filename);

    // 4. Четем ключ
    printf("Enter key (2-10): ");
    scanf("%d", &key);

    if(key < 2 || key > 10){
        printf("Invalid key!\n");
        return 0;
    }

    FILE *in = fopen(filename, "r");
    if(in == NULL){
        printf("Cannot open file!\n");
        return 0;
    }

    FILE *out = fopen("encoded.txt", "w");

    char ch;

    // 5. Кодиране символ по символ
    while((ch = fgetc(in)) != EOF){

        // ако е малка буква
        if(ch >= 'a' && ch <= 'z'){
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        // ако е главна буква
        else if(ch >= 'A' && ch <= 'Z'){
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        // другите символи не ги пипаме

        fputc(ch, out);
    }

    fclose(in);
    fclose(out);

    printf("File encoded successfully!\n");

    // 6. Показваме резултата
    out = fopen("encoded.txt", "r");

    printf("Encoded content:\n");

    while((ch = fgetc(out)) != EOF){
        putchar(ch);
    }

    fclose(out);

    return 0;
}