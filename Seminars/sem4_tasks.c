#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void zad1();
void zad2();
void zad3();
void zad4();
void zad5();
void zad6();
void zad7();
void zad8();
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
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
void zad1(){
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int rowsOK = 1;
    int colsOK = 1;
    // проверка на редове (нарастващи)
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(a[i][j] > a[i][j+1]){
                rowsOK = 0;
                break;
            }
        }
    }
    // проверка на колони (намаляващи)
    for(int j=0;j<m;j++){
        for(int i=0;i<n-1;i++){
            if(a[i][j] < a[i+1][j]){
                colsOK = 0;
                break;
            }
        }
    }
    if(rowsOK && colsOK)
        printf("Matrix satisfies the condition!\n");
    else
        printf("Matrix does NOT satisfy the condition!\n");
}
void zad2(){
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int maxSum = -1000000;
    int bestValue;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            int sum = 0;

            // обхождаме съседите
            for(int di=-1; di<=1; di++){
                for(int dj=-1; dj<=1; dj++){

                    if(di==0 && dj==0) continue;

                    int ni = i + di;
                    int nj = j + dj;
                    // проверка дали е в границите
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        sum += a[ni][nj];
                    }
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                bestValue = a[i][j];
            }
        }
    }
    printf("Number with max neighbor sum: %d\n", bestValue);
    printf("Sum = %d\n", maxSum);
}
void zad3(){
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);

    int a[n][m];

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }

    int min = a[0][0], max = a[0][0];
    int minRow = 0, maxRow = 0;
    // намиране
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] < min){
                min = a[i][j];
                minRow = i;
            }
            if(a[i][j] > max){
                max = a[i][j];
                maxRow = i;
            }
        }
    }
    // размяна на редове
    for(int j=0;j<m;j++){
        int temp = a[minRow][j];
        a[minRow][j] = a[maxRow][j];
        a[maxRow][j] = temp;
    }
    printf("Matrix after swap:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void zad4(){
    int n, m;
    printf("Enter number of people and friendships: ");
    scanf("%d %d", &n, &m);
    int a[n+1][n+1];
    // зануляване
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = 0;
        }
    }
    // въвеждане на приятелства
    printf("Enter friendships (pairs):\n");
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);

        a[x][y] = 1;
        a[y][x] = 1; 
    }
    int person;
    printf("Enter person: ");
    scanf("%d", &person);

    int count = 0;

    printf("Friends: ");
    for(int i=1;i<=n;i++){
        if(a[person][i] == 1){
            printf("%d ", i);
            count++;
        }
    }
    printf("\nTotal friends: %d\n", count);
}
void zad5(){
    int arr[1000];
    int n = 0;
    int cmd;
    while(1){
        printf("\n1-add 2-delete 3-smallest 0-exit: ");
        scanf("%d", &cmd);
        if(cmd == 0) break;
        if(cmd == 1){
            int x;
            scanf("%d", &x);
            arr[n++] = x;
        }
        else if(cmd == 2){
            int x;
            scanf("%d", &x);
            // трием всички x
            int k = 0;
            for(int i=0;i<n;i++){
                if(arr[i] != x){
                    arr[k++] = arr[i];
                }
            }
            n = k;
        }
        else if(cmd == 3){
            int x;
            scanf("%d", &x);
            // сортиране (bubble sort)
            for(int i=0;i<n-1;i++){
                for(int j=0;j<n-1-i;j++){
                    if(arr[j] > arr[j+1]){
                        int temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
            if(x <= n)
                printf("%d-th smallest: %d\n", x, arr[x-1]);
            else
                printf("Not enough elements!\n");
        }
    }
}
void zad6(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *a = (int*)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    int countPrimes = 0;

    // броим простите
    for(int i=0;i<n;i++){
        int x = a[i];
        int isPrime = 1;

        if(x < 2) isPrime = 0;

        for(int j=2; j*j<=x; j++){
            if(x % j == 0){
                isPrime = 0;
                break;
            }
        }

        if(isPrime){
            countPrimes++;
        }
    }

    // създаваме втория масив
    int *primes = (int*)malloc(countPrimes * sizeof(int));
    int *others = (int*)malloc(n * sizeof(int));

    int p = 0, o = 0;

    // разделяме числата
    for(int i=0;i<n;i++){
        int x = a[i];
        int isPrime = 1;

        if(x < 2) isPrime = 0;

        for(int j=2; j*j<=x; j++){
            if(x % j == 0){
                isPrime = 0;
                break;
            }
        }

        if(isPrime){
            primes[p++] = x;
        } else {
            others[o++] = x;
        }
    }

    printf("Non-prime numbers:\n");
    for(int i=0;i<o;i++){
        printf("%d ", others[i]);
    }

    printf("\nPrime numbers:\n");
    for(int i=0;i<p;i++){
        printf("%d ", primes[i]);
    }

    printf("\n");

    free(a);
    free(primes);
    free(others);
}
void zad7(){
    int n, m;
    printf("Enter n and m: ");
    scanf("%d %d", &n, &m);
    int a[n][m];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    int maxSum = -1000000;
    int bestRow = 0, bestCol = 0;
    // обхождаме всички възможни 3x3
    for(int i=0;i<=n-3;i++){
        for(int j=0;j<=m-3;j++){
            int sum = 0;
            for(int x=0;x<3;x++){
                for(int y=0;y<3;y++){
                    sum += a[i+x][j+y];
                }
            }
            if(sum > maxSum){
                maxSum = sum;
                bestRow = i;
                bestCol = j;
            }
        }
    }
    printf("Max 3x3 submatrix:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", a[bestRow+i][bestCol+j]);
        }
        printf("\n");
    }
    printf("Sum = %d\n", maxSum);
}
void zad8(){
    int n = 10;
    int *a = (int*)malloc(n * sizeof(int));
    printf("Enter 10 elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    while(1){
        int x;
        printf("Enter number (0 to stop): ");
        scanf("%d", &x);
        if(x == 0) break;
        int pos;
        printf("Enter position: ");
        scanf("%d", &pos);
        // увеличаваме размера
        n++;
        a = (int*)realloc(a, n * sizeof(int));
        // местим елементите надясно
        for(int i=n-1; i>pos; i--){
            a[i] = a[i-1];
        }
        // вмъкваме новото число
        a[pos] = x;
    }
    printf("Final array:\n");
    for(int i=0;i<n;i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
}