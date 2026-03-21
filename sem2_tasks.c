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
void zad10();
void zad11();
void zad12();
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
            case 10:
                zad10();
                break;
            case 11:
                zad11();
                break;
            case 12:
                zad12();
                break; 
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
void zad1(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    if(a > b){
        printf("The bigger number is: %d\n", a);
    }
    else{
        printf("The bigger number is: %d\n", b);
    }
}
void zad2(){
    int hour;
    int minute;

    printf("Enter hour: ");
    scanf("%d", &hour);

    printf("Enter minutes: ");
    scanf("%d", &minute);

    minute = minute + 15;

    if(minute >= 60){
        minute = minute - 60;
        hour = hour + 1;
    }
    if(hour == 24){
        hour = 0;
    }
    printf("Time after 15 minutes: %d:%02d\n", hour, minute);
}
void zad3(){
    int num1, num2, num3;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 == num2 && num1 == num3){
        printf("These numbers are equal!");
    }
    else{
        printf("These numbers are not equal!");
    }
}
void zad4(){
    int points;
    double bonus = 0;
    printf("Enter points: ");
    scanf("%d", &points);
    if(points <= 100){
        bonus = 5;
    }
    else if(points <= 1000){
        bonus = points * 0.20;
    }
    else{
        bonus = points * 0.10;
    }
    // extra bonus
    if(points % 2 == 0){
        bonus = bonus + 1;
    }
    if(points % 10 == 5){
        bonus = bonus + 2;
    }
    printf("Bonus points: %.2f\n", bonus);
    printf("Total points: %.2f\n", points + bonus);
}
void zad5(){
    int minutes, seconds, player1, player2, player3;
    printf("Enter three time's players: ");
    scanf("%d %d %d", &player1, &player2, &player3);
    minutes = (player1 + player2 + player3) / 60;
    seconds = (player1 + player2 + player3) % 60;
    printf("Minutes: %d Seconds: %d\n", minutes, seconds);
}
void zad6(){
    double x1, y1, x2, y2;
    double x, y;

    printf("Enter x1: ");
    scanf("%lf", &x1);

    printf("Enter y1: ");
    scanf("%lf", &y1);

    printf("Enter x2: ");
    scanf("%lf", &x2);

    printf("Enter y2: ");
    scanf("%lf", &y2);

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter y: ");
    scanf("%lf", &y);

    if(x >= x1 && x <= x2 && y >= y1 && y <= y2){
        printf("Inside\n");
    }
    else{
        printf("Outside\n");
    }
}
void zad7(){
    int n;
    char period;
    double taxi, bus, train;
    double price;

    printf("Enter kilometers: ");
    scanf("%d", &n);

    printf("Enter period (D for day, N for night): ");
    scanf(" %c", &period);
    // taxi price
    if(period == 'D'){
        taxi = 0.70 + n * 0.79;
    }
    else{
        taxi = 0.70 + n * 0.90;
    }
    price = taxi;
    // bus price
    if(n >= 20){
        bus = n * 0.09;
        if(bus < price){
            price = bus;
        }
    }
    // train price
    if(n >= 100){
        train = n * 0.06;
        if(train < price){
            price = train;
        }
    }
    printf("The cheapest price is: %.2f\n", price);
}
void zad8(){
    int V;
    int P1;
    int P2;
    double N;
    double water;

    printf("Enter pool volume: ");
    scanf("%d", &V);

    printf("Enter pipe 1 flow: ");
    scanf("%d", &P1);

    printf("Enter pipe 2 flow: ");
    scanf("%d", &P2);

    printf("Enter hours: ");
    scanf("%lf", &N);

    water = (P1 + P2) * N;

    if(water <= V){

        double percent = (water / V) * 100;
        double p1percent = (P1 * N / water) * 100;
        double p2percent = (P2 * N / water) * 100;

        printf("The pool is %.2f%% full\n", percent);
        printf("Pipe1: %.2f%%\n", p1percent);
        printf("Pipe2: %.2f%%\n", p2percent);
    }
    else{
        double overflow = water - V;
        printf("For %.2f hours the pool overflows with %.2f liters\n", N, overflow);
    }

}
void zad9() {
    float X; // vineyard area in square meters
    float Y; // kg of grapes per 1 sq.m
    float Z; // desired wine in liters
    int workers; // number of workers

    printf("Enter vineyard area (sq.m): ");
    scanf("%f", &X);

    printf("Enter kg of grapes per 1 sq.m: ");
    scanf("%f", &Y);

    printf("Enter desired wine (liters): ");
    scanf("%f", &Z);

    printf("Enter number of workers: ");
    scanf("%d", &workers);
    // Calculate grapes for wine
    float total_grape = X * Y;          // total grapes
    float grape_for_wine = total_grape * 0.4; // 40% for wine
    float wine_produced = grape_for_wine / 2.5; // 2.5 kg grapes per 1 liter
    // Check if wine is enough
    if (wine_produced >= Z) {
        printf("Wine is enough. You can produce %.2f liters.\n", wine_produced);
        float leftover = wine_produced - Z; // leftover
        if (workers > 0) {
            printf("Leftover %.2f liters is divided among %d workers. Each gets %.2f liters.\n",
                   leftover, workers, leftover / workers);
        }
    } else {
        printf("Wine is not enough. You can produce only %.2f liters.\n", wine_produced);
        printf("You are short by %.2f liters.\n", Z - wine_produced);
    }
}
void zad10() {
    int n; 
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int num; 
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &num);

        if (num < 200) {
            count1++;
        } else if (num <= 399) {
            count2++;
        } else if (num <= 599) {
            count3++;
        } else if (num <= 799) {
            count4++;
        } else { 
            count5++;
        }
    }
    float p1 = (count1 * 100.0) / n;
    float p2 = (count2 * 100.0) / n;
    float p3 = (count3 * 100.0) / n;
    float p4 = (count4 * 100.0) / n;
    float p5 = (count5 * 100.0) / n;
    printf("Percentage of numbers < 200: %.2f\n", p1);
    printf("Percentage of numbers 200-399: %.2f\n", p2);
    printf("Percentage of numbers 400-599: %.2f\n", p3);
    printf("Percentage of numbers 600-799: %.2f\n", p4);
    printf("Percentage of numbers >= 800: %.2f\n", p5);
}
void zad11() {
    int n;
    printf("Enter an integer n (n >= 3): ");
    scanf("%d", &n);

    int half = n / 2;              // ширина на лявата и дясната кула
    int middle_top = n - 2;        // празно пространство между кулите горе
    int middle_bottom = 2 * n - 2 * half - 2; // долу

    printf("/");
    for (int i = 0; i < half; i++) printf("^");
    printf("\\");
    for (int i = 0; i < middle_top; i++) printf("_");
    printf("/");
    for (int i = 0; i < half; i++) printf("^");
    printf("\\\n");

    for (int i = 0; i < n - 2; i++) {
        printf("|");
        for (int j = 0; j < 2 * n - 2; j++) printf(" ");
        printf("|\n");
    }
    printf("\\");
    for (int i = 0; i < half; i++) printf("_");
    printf("/");
    for (int i = 0; i < middle_bottom; i++) printf(" ");
    printf("\\");
    for (int i = 0; i < half; i++) printf("_");
    printf("/\n");
}
void zad12() {
    int n;
    printf("Enter an integer n (n >= 3): ");
    scanf("%d", &n);

    int width = 2 * n - 1;
    int height = 2 * (n - 2) + 1;
    int left_right = n - 1;
    int middle_row = height / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < left_right; j++) {
            if (i % 2 == 0)
                printf("*");
            else
                printf("-");
        }
        printf("\\");
        printf("/");
        for (int j = 0; j < left_right; j++) {
            if (i % 2 == 0)
                printf("*");
            else
                printf("-");
        }
        printf("\n");
        if (i == middle_row) {
            for (int j = 0; j < left_right; j++) printf("*");
            printf("@");
            for (int j = 0; j < left_right; j++) printf("*");
            printf("\n");
        }
    }
}