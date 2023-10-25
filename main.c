#include <stdio.h>
#include <stdlib.h>

int get_number(int number, int divider){
    return number/divider;
}

int bigger_divider(int number){
    int divider = 1;
    while (get_number(number,divider) > 0){
        divider *= 10;
    }
    return divider/10;
}

int sum_number(int number){
    int divider = bigger_divider(number);
    int sum = 0;
    while (divider > 0){
        sum += get_number(number,divider);
        number %= divider;
        divider /= 10;
    }
    return sum;
}

int main() {
    int number;
    printf("Enter number: ");
    scanf("%d",&number);
    printf("%d",sum_number(number));
    return 0;
}
