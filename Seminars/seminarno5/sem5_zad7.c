#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "workers.bin"
#define MAX 30

typedef struct {
    int id;
    double rate;     // почасово заплащане
    double hours;    // отработени часове
    double salary;   // седмична заплата
} Worker;

// функция за изчисляване на заплата
double calculateSalary(double rate, double hours){
    double total;

    if(hours <= 40){
        total = rate * hours;
    } else {
        double overtime = hours - 40;
        total = rate * 40 + overtime * rate * 1.5;
    }

    // данък 3.65%
    total = total - total * 0.0365;

    return total;
}

// добавяне на нов сътрудник
void addWorker(){
    FILE *f = fopen(FILE_NAME, "ab");

    Worker w;

    printf("Enter ID: ");
    scanf("%d", &w.id);

    printf("Enter hourly rate: ");
    scanf("%lf", &w.rate);

    printf("Enter hours worked: ");
    scanf("%lf", &w.hours);

    w.salary = calculateSalary(w.rate, w.hours);

    fwrite(&w, sizeof(Worker), 1, f);

    fclose(f);

    printf("Worker added!\n");
}

// извеждане на всички заплати
void printWorkers(){
    FILE *f = fopen(FILE_NAME, "rb");

    if(f == NULL){
        printf("File not found!\n");
        return;
    }

    Worker w;

    printf("Workers:\n");

    while(fread(&w, sizeof(Worker), 1, f)){
        printf("ID: %d | Salary: %.2lf\n", w.id, w.salary);
    }

    fclose(f);
}

// броене на записите
int countWorkers(){
    FILE *f = fopen(FILE_NAME, "rb");

    if(f == NULL) return 0;

    fseek(f, 0, SEEK_END);
    int count = ftell(f) / sizeof(Worker);

    fclose(f);
    return count;
}

// създаване на файл с примерни данни
void createInitialData(){
    FILE *f = fopen(FILE_NAME, "wb");

    Worker w1 = {1, 10.0, 40, 0};
    Worker w2 = {2, 12.0, 45, 0};
    Worker w3 = {3, 8.5, 38, 0};

    w1.salary = calculateSalary(w1.rate, w1.hours);
    w2.salary = calculateSalary(w2.rate, w2.hours);
    w3.salary = calculateSalary(w3.rate, w3.hours);

    fwrite(&w1, sizeof(Worker), 1, f);
    fwrite(&w2, sizeof(Worker), 1, f);
    fwrite(&w3, sizeof(Worker), 1, f);

    fclose(f);
}

int main(){
    int choice;

    // създаваме файл с примерни данни (само веднъж)
    createInitialData();

    while(1){
        printf("\n1. Add worker\n");
        printf("2. Show salaries\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if(choice == 0){
            printf("Program ended!\n");
            break;
        }

        switch(choice){
            case 1:
                if(countWorkers() >= MAX){
                    printf("Max workers reached!\n");
                } else {
                    addWorker();
                }
                break;

            case 2:
                printWorkers();
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}