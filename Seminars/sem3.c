#include <stdio.h>
#include <math.h>
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
void zad8();
void zad9();
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
            case 5:
                zad5();
                break;
            case 6:
                zad6();
                break;
            case 7:
                zad7();
                break;
            case 8:
                zad8();
                break;
            case 9:
                zad9();
                break;
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
// 1.	Всяка редица от равни числа в едномерен сортиран масив, се нарича площадка. 
// Да се напише програма, която намира началото и дължината на най-дългата площадка в даден сортиран 
// във възходящ ред едномерен масив.
void zad1(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int maxLen = 1, currentLen = 1;
    int startIndex = 0, bestStart = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            currentLen++;
        } else {
            currentLen = 1;
            startIndex = i;
        }

        if(currentLen > maxLen){
            maxLen = currentLen;
            bestStart = startIndex;
        }
    }

    printf("Longest platform starts at index %d and has length %d\n", bestStart, maxLen);
}
// 2.	Да се напише програма, която проверява дали между елементите на редицата a0, a1, ..., an 
// са изпълнени релациите: a0 < a1 > a2 < a3…
// (въвеждат се N и елементите на редицата)

void zad2(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int valid = 1;

    for(int i = 0; i < n - 1; i++){
        if(i % 2 == 0){ // четен индекс → <
            if(arr[i] >= arr[i+1]){
                valid = 0;
                break;
            }
        } else { // нечетен индекс → >
            if(arr[i] <= arr[i+1]){
                valid = 0;
                break;
            }
        }
    }
    if(valid){
        printf("The sequence is valid!\n");
    } else {
        printf("The sequence is NOT valid!\n");
    }
}
// 3.	Напишете програма, която получава масив от N елемента 
// и обръща реда на елементите. Изкарайте ново полученият масив.
void zad3(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // обръщане
    for(int i = 0; i < n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    printf("Reversed array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 4.	Напишете програма, която получава редица с цели N числа. След това получава цяло число К. 
// Отместете всички елементи на редицата с K позиции, като използвате правилото за превъртане 
// (когато елемент от последна позиция трябва да се измести то той трябва да отиде на първа позиция в редицата).
void zad4(){
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);

    // ако k е по-голямо от n
    k = k % n;

    // правим k на брой завъртания
    for(int step = 0; step < k; step++){
        int last = arr[n - 1]; // запазваме последния елемент
        // местим всички надясно
        for(int i = n - 1; i > 0; i--){
            arr[i] = arr[i - 1];
        }
        arr[0] = last; // слагаме последния отпред
    }

    printf("Result:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 5.	Дадена е редица с N цели числа. Да се намери K тия по големина елемент в редицата. 
void zad5(){
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("K-th largest element is: %d\n", arr[n - k]);
}
// 6. За дадена редица от числа да се намери и отпечата най-дългата (монотонно) нарастваща (или намаляваща) под редица.
void zad6(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int maxLen = 1, currLen = 1;
    int start = 0, bestStart = 0;
    // ---------- НАРАСТВАЩА ----------
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            currLen++;
        } else {
            currLen = 1;
            start = i;
        }

        if(currLen > maxLen){
            maxLen = currLen;
            bestStart = start;
        }
    }

    printf("Longest increasing subsequence:\n");
    for(int i = bestStart; i < bestStart + maxLen; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    // ---------- НАМАЛЯВАЩА ----------
    maxLen = 1;
    currLen = 1;
    start = 0;
    bestStart = 0;

    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i - 1]){
            currLen++;
        } else {
            currLen = 1;
            start = i;
        }

        if(currLen > maxLen){
            maxLen = currLen;
            bestStart = start;
        }
    }

    printf("Longest decreasing subsequence:\n");
    for(int i = bestStart; i < bestStart + maxLen; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 7. Да се напише програма, която намира последователност от числа в масив, 
// които имат сума равна на число, въведено от  потребителя(ако има такава). 
void zad7(){
    int n, target;
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter target sum: ");
    scanf("%d", &target);

    int found = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;

        for(int j = i; j < n; j++){
            sum += arr[j];

            if(sum == target){
                printf("Sequence found:\n");

                for(int k = i; k <= j; k++){
                    printf("%d ", arr[k]);
                }
                printf("\n");

                found = 1;
                return; 
            }
            if(sum > target){
                break;
            }
        }
    }
    if(!found){
        printf("No such sequence found.\n");
    }
}
// 8. Потребителя въвежда 10 числа в масив от 20 елемента. 
// След това въвежда числа, като с всяко въведено число указва индекса, 
// където да бъде вмъкнато това число (числото избутва останалите). 
// Въвеждането спира при вход 0 (нула) или при запълване на масива.
void zad8(){
    int arr[20];
    int n = 10; 

    printf("Enter 10 elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    while(n < 20){
        int num, pos;

        printf("Enter number (0 to stop): ");
        scanf("%d", &num);

        if(num == 0){
            break; 
        }
        printf("Enter position: ");
        scanf("%d", &pos);

        if(pos < 0 || pos > n){
            printf("Invalid position!\n");
            continue;
        }
        for(int i = n; i > pos; i--){
            arr[i] = arr[i - 1];
        }
        arr[pos] = num; 
        n++; 
    }
    printf("Final array:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// 9. Напишете програма, която намира  максималната редица 
// от последователни еднакви елементи в масив и ги отпечатва.
void zad9(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int currentLen = 1;     
    int maxLen = 1;        
    int start = 0;          
    int bestStart = 0;      

    for(int i = 0; i < n - 1; i++){
        if(arr[i] == arr[i + 1]){
            currentLen++;
        } else {
            currentLen = 1;
            start = i + 1;
        }
        if(currentLen > maxLen){
            maxLen = currentLen;
            bestStart = start;
        }
    }
    printf("Longest sequence:\n");
    for(int i = bestStart; i < bestStart + maxLen; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}