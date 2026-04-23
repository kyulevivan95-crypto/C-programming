#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void zad1();
void zad2();
void zad3();
void zad4();
int isAnagram(char *a, char *b);

int main(){
    int choice;
    while(1){
        printf("Enter a task: ");
        scanf("%d", &choice);
        if(choice==0){
            printf("The program ended!\n");
            break;
        }

        switch(choice){
            case 1:
                zad1();
                break;
            case 2:
                zad2();
                break;
            case 3:
                zad3();
                break;
            case 4:
                zad4();
                break;
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}

void zad1(){
    int guests;
    scanf("%d", &guests);

    char item[20];

    int chairs = 0, tables = 0, cups_sets = 0, dishes_sets = 0;
    double total = 0;

    while(1){
        scanf("%s", item);

        if(strcmp(item, "PARTY!") == 0)
            break;

        if(strcmp(item, "Chair") == 0){
            chairs++;
            total += 13.99;
        }
        else if(strcmp(item, "Table") == 0){
            tables++;
            total += 42.00;
        }
        else if(strcmp(item, "Cups") == 0){
            cups_sets++;
            total += 5.98;
        }
        else if(strcmp(item, "Dishes") == 0){
            dishes_sets++;
            total += 21.02;
        }
    }

    printf("%.2lf\n", total);

    // нужни маси (1 маса за 8 човека)
    int needed_tables = (guests + 7) / 8;
    if(needed_tables > tables)
        printf("%d Table\n", needed_tables - tables);

    // нужни столове
    if(guests > chairs)
        printf("%d Chairs\n", guests - chairs);

    // чаши (комплект от 6)
    int needed_cups_sets = (guests + 5) / 6;
    if(needed_cups_sets > cups_sets)
        printf("%d Cups\n", needed_cups_sets - cups_sets);

    // чинии (комплект от 6)
    int needed_dishes_sets = (guests + 5) / 6;
    if(needed_dishes_sets > dishes_sets)
        printf("%d Dishes\n", needed_dishes_sets - dishes_sets);
}

typedef struct {
    char name[50];
    double price;
    int id;
} Product;

typedef struct {
    char address[100];
    int product_id;
} Order;

void zad2(){
    Product products[100];
    Order waiting[100];

    int productCount = 0;
    int waitingCount = 0;

    char command[20];

    while(1){
        scanf("%s", command);

        if(strcmp(command, "end") == 0)
            break;

        if(strcmp(command, "Product") == 0){
            Product p;
            scanf("%s", p.name);
            scanf("%lf", &p.price);
            scanf("%d", &p.id);

            products[productCount++] = p;

            // проверка за чакащи поръчки
            for(int i = 0; i < waitingCount; i++){
                if(waiting[i].product_id == p.id){
                    printf("Client %s ordered %s\n", waiting[i].address, p.name);

                    // махаме поръчката
                    for(int j = i; j < waitingCount - 1; j++){
                        waiting[j] = waiting[j+1];
                    }
                    waitingCount--;
                    i--;
                }
            }
        }
        else if(strcmp(command, "Order") == 0){
            Order o;
            scanf("%s", o.address);
            scanf("%d", &o.product_id);

            int found = 0;

            for(int i = 0; i < productCount; i++){
                if(products[i].id == o.product_id){
                    printf("Client %s ordered %s\n", o.address, products[i].name);
                    found = 1;
                    break;
                }
            }

            if(!found){
                waiting[waitingCount++] = o;
            }
        }
    }
}

void zad3(){
    char word[50];
    scanf("%s", word);

    int len = strlen(word);

    char guessed[50];
    for(int i = 0; i < len; i++){
        guessed[i] = '_';
    }
    guessed[len] = '\0';

    int attempts = 0;

    while(1){
        printf("%s\n", guessed);

        char ch;
        scanf(" %c", &ch);
        attempts++;

        int found = 0;

        for(int i = 0; i < len; i++){
            if(word[i] == ch && guessed[i] == '_'){
                guessed[i] = ch;
                found = 1;
            }
        }

        // проверка дали е позната думата
        if(strcmp(word, guessed) == 0){
            break;
        }
    }

    printf("%s\n", guessed);
    printf("Attempts: %d\n", attempts);

    if(attempts <= len + 2){
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

int isAnagram(char *a, char *b){
    int count[256] = {0};

    for(int i = 0; a[i]; i++){
        count[(unsigned char)a[i]]++;
    }

    for(int i = 0; b[i]; i++){
        count[(unsigned char)b[i]]--;
    }

    for(int i = 0; i < 256; i++){
        if(count[i] != 0)
            return 0;
    }

    return 1;
}

void zad4(){
    char s1[100], s2[100];

    scanf("%s", s1);
    scanf("%s", s2);

    if(isAnagram(s1, s2)){
        printf("Anagram\n");
    } else {
        printf("Not anagram\n");
    }
}