#include <stdio.h>

int main() {

    char operator =' ';
    int second_nbr;
    int first_nbr;

    printf("TP5: Les Conditions\n");
    printf("enter first nbr");
    scanf("%d", &first_nbr);
    printf("add an operator");
    scanf("%s", &operator);
    printf("enter second nbr");
    scanf("%d", &second_nbr);
/*
        if (operator == '*')
            printf("%d %c %d = %d", first_nbr, operator, second_nbr, first_nbr * second_nbr);
        else if (operator == '/')
            printf("%d %c %d = %d", first_nbr, operator, second_nbr, first_nbr / second_nbr);
        else if (operator == '+')
            printf("%d %c %d = %d", first_nbr, operator, second_nbr, first_nbr + second_nbr);
        else if (operator == '-')
            printf("%d %c %d = %d", first_nbr, operator, second_nbr, first_nbr - second_nbr);
        else if (operator == '%')
            printf("%d %c %d = %d", first_nbr, operator, second_nbr, first_nbr % second_nbr);
            */

    switch (operator){
        case '+':
            printf("%d %s %d = %d", first_nbr, &operator, second_nbr, first_nbr + second_nbr);
            return (0);
        case '-':
            printf("%d %s %d = %d", first_nbr, &operator, second_nbr, first_nbr - second_nbr);
            return (0);
        case '/':
            if (second_nbr != 0)
                printf("%d %s %d = %d", first_nbr, &operator, second_nbr, first_nbr / second_nbr);
            else
                printf("on divise pas par 0\n");
            return (0);

        case '*':
            printf("%d %s %d = %d", first_nbr, &operator, second_nbr, first_nbr * second_nbr);
            return (0);

        case '%':  if (second_nbr != 0)
                printf("%d %s %d = %d", first_nbr, &operator, second_nbr, first_nbr % second_nbr);
            else
                printf("on fait pas % 0\n");
            return (0);

        default:
            printf("non\n");
            return (0);
    }
    return 0;
}
