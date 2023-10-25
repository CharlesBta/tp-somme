#include <stdio.h>
#include <stdlib.h>

typedef struct Number{
    int value;
    struct Number* next;
}Number;

void add_item(Number ** list, int value){
    Number * item = malloc(sizeof(Number));
    item->value = value;
    item->next = *list;
    *list = item;
}

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

void separate_number(int number, Number *list){
    int divider = bigger_divider(number);
    while (divider > 1){
        add_item(list, get_number(number,divider));
        number %= divider;
        divider /= 10;
    }
}

int sum_numbers(Number *list){
    if(list == NULL) return 0;
    int sum = 0;
    while (list->next != NULL){
        sum += list->value;
        list = list->next;
    }
    sum += list->value;
    return sum;
}

int main() {
    int number = 34;
    int divider= 1;
    Number *list = NULL;
//    scanf("%d",&number);
//    printf("%d", get_number(number,divider));
    separate_number(number,list);
//    int sum = sum_numbers(list);
//    printf("%d",sum);
    return 0;
}
