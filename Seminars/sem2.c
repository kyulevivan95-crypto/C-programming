#include <stdio.h>
#include <math.h>
void zad11();
void zad12();
void zad13();
void zad14();
void zad15();
void zad16();
int main(){
    int choice;
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice==0){
            printf("The program ended!");
        }

        switch(choice){
            case 11:
                zad11();
                break;
            case 12:
                zad12();
                break;
            case 13:
                zad13();
                break;
            case 14:
                zad14();
                break;
            case 15:
                zad15();
                break;
            case 16:
                zad16();
                break;
            default:
                printf("Wrong choice!\n");
        }
    }
    return 0;
}
void zad11(){     //ZAD11
    float x1, y1, x2, y2;
    float width, height, area;
    printf("Enter x1 and y1: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter x2 and y2: ");
    scanf("%f %f", &x2, &y2);
    width = fabs(x2 - x1);
    height = fabs(y2 - y1);
    area = width * height;
    printf("The area is %.2f\n", area);
}
void zad12(){    //ZAD12
    float x1, x2, x3, y1, y2, y3;
    float area;
    printf("Enter coordinates for A: ");
    scanf("%f %f", &x1, &y1);
    printf("Enter coordinates for B: ");
    scanf("%f %f", &x2, &y2);
    printf("Enter coordinates for C: ");
    scanf("%f %f", &x3, &y3);
    area = fabs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2;
    printf("Square is %.2f\n", area);
}
void zad13(){    //ZAD13
    double w, h;
    int w_cm, h_cm;
    int seats;
    printf("Enter a size (width, height): ");
    scanf("%lf %lf", &w, &h);
    w_cm = w * 100;
    h_cm = h * 100;
    w_cm = w_cm - 100;
    seats = (w_cm / 120) * (h_cm / 70);
    seats = seats - 3;
    printf("Seats: %d\n", seats);
}
void zad14(){     //ZAD14
    double priceVeg, priceFruit, kgVeg, kgFruit, totalLV, totalEuro;
    printf("Price for kg vegetables: ");
    scanf("%lf", &priceVeg);
    printf("Price for kg fruits: ");
    scanf("%lf", &priceFruit);
    printf("Kilograms vegetables: ");
    scanf("%lf", &kgVeg);
    printf("Kilograms fruits: ");
    scanf("%lf", &kgFruit);
    totalLV = (priceVeg * kgVeg) + (priceFruit * kgFruit);
    totalEuro = totalLV / 1.95;
    printf("Revenues in euro: %.2f\n", totalEuro);
}
void zad15(){     //ZAD15
    float tiles, minutes, tiles_area, pl_area, new_area;
    int playground, tiles_width, tiles_height;
    int bench, b_width, b_height, bench_area;
    printf("Playground size: ");
    scanf("%d", &playground);
    pl_area = playground * playground;
    printf("Enter a width and height for bench: ");
    scanf("%d %d", &b_width, &b_height);
    bench_area = b_width * b_height;
    printf("Enter a width and height for tiles: ");
    scanf("%d %d", &tiles_width, &tiles_height);
    tiles_area = tiles_width * tiles_height;
    new_area = pl_area - bench_area;
    tiles = new_area / tiles_area;
    minutes = tiles * 0.2;
    printf("Tiles: %.2f\n", tiles);
    printf("Time needed: %.2f\n", minutes);
}
void zad16(){     //ZAD16
    double N, M, rate, monthly_salary, yearly_salary, bonus, total_income, after_tax, income_leva, average_per_day;          
    printf("Days per month: ");
    scanf("%lf", &N);
    printf("Dollars per day: ");
    scanf("%lf", &M);
    printf("Dollars to leva rate: ");
    scanf("%lf", &rate);

    monthly_salary = N * M;
    yearly_salary = monthly_salary * 12;
    bonus = 2.5 * monthly_salary;

    total_income = yearly_salary + bonus;

    after_tax = total_income * 0.75;

    income_leva = after_tax * rate;

    average_per_day = income_leva / 365;

    printf("%.2lf\n", average_per_day);
}