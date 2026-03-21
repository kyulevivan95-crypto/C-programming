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
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
void zad1(){      //ZAD1
    printf("One Two Three Four Five Six Seven Eight Nine Ten\n");   
}
void zad2(){     //ZAD2
    int rows = 10;

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}
void zad3(){    //ZAD3
    char ch;
    int i;
    printf("Enter a symbol: ");
    scanf("%c", &ch);
    for(i = 0; i < 10; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        printf("%c", ch);
        printf("        ");
        printf("%c\n", ch);
    }
    for(i = 0; i < 10; i++)
    {
        printf("%c", ch);
    }
}
void zad4(){  //ZAD4
    char symbol;
    int rows = 5;
    printf("Enter a symbol: ");
    scanf(" %c", &symbol);
    for(int i = 1; i <= rows; i++) {
        for(int s = 1; s <= rows - i; s++) {
            printf("   ");
        }
        if(i == 1) {
            printf("%c", symbol);
        }
        else if(i == rows) {
            for(int j = 1; j <= 2 * rows - 1; j++) {
                printf("%c ", symbol);
            }
        }
        else {
            printf("%c", symbol);
            for(int space = 1; space <= 2 * i - 3; space++) {
                printf("   ");
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
    printf("\n");
    for(int i = rows; i >= 1; i--) {
        for(int s = 1; s <= rows - i; s++) {
            printf("   ");
        }
        if(i == 1) {
            printf("%c", symbol);
        }
        else if(i == rows) {
            for(int j = 1; j <= 2 * rows - 1; j++) {
                printf("%c ", symbol);
            }
        }
        else {
            printf("%c", symbol);
            for(int space = 1; space <= 2 * i - 3; space++) {
                printf("   ");
            }
            printf("%c", symbol);
        }
        printf("\n");
    }
}
void zad5(){  //ZAD5
    float inch;
    printf("Enter inches: ");
    scanf("%f", &inch);
    printf("MM: %.2f\n", inch*25.4);
    printf("CM: %.2f\n", inch*2.54);
    printf("DM: %.2f\n", inch*0.254);
    printf("M: %.2f\n", inch*0.0254);
}
void zad6(){  //ZAD6
    char ch;
    int i;
    printf("Enter a symbol: ");
    scanf("%c", &ch);
    for(i = 0; i < 10; i++)
    {
        printf("%c", ch);
    }
    printf("\n");
    for(i = 0; i < 3; i++)
    {
        printf("%c", ch);
        printf("        ");
        printf("%c\n", ch);
    }
    for(i = 0; i < 10; i++)
    {
        printf("%c", ch);
    }
}
void zad7(){  //ZAD7
    float degrees;
    printf("Enter degrees: ");
    scanf("%f", &degrees);
    printf("Radians: %.2f", degrees*0.0175);
}
void zad8(){  //ZAD8
    float lev;
    printf("Enter leva: ");
    scanf("%f", &lev);
    printf("Euro: %.2f\n", lev*1.95);
    printf("Dollars: %.2f\n", lev*1.66);
    printf("Pounds: %.2f\n", lev*2.22);    
}
void zad9(){  //ZAD9
    float a, b, h, s; 
    printf("Enter A, B, H: ");
    scanf("%f %f %f", &a, &b, &h);
    s = ((a+b)*h)/2;
    printf("Square: %.2f\n", s);    
}
void zad10(){ //ZAD10
    double degrees;
    double radians;
    double sin_value, cos_value, tan_value, cot_value;

    printf("Angle in degrees: ");
    scanf("%lf", &degrees);
    radians = degrees * 0.0175;
    sin_value = sin(radians);
    cos_value = cos(radians);
    tan_value = tan(radians);

    printf("\nSinus: %.4lf\n", sin_value);
    printf("Kosinus: %.4lf\n", cos_value);

    if (cos_value != 0) {
        cot_value = 1 / tan_value;
        printf("Tangens: %.4lf\n", tan_value);
        printf("Kotangens: %.4lf\n", cot_value);
    } else {
        printf("No tangens and cotangens.\n");
    }    
}


