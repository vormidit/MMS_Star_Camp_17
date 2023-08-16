/*command line arguments
Напишете програма, която намира сумата на аргументите, подадени от командния ред.

Програмата може да приема 3 вида аргументи от командния ред:
целочислени аргументи в десетична бройна система, например 10, -21, 55.
числа с плаваща запетая, например 12.5, 3.14
Числа в шестнадесетична бройна система 0xff

Приемете, че:
Ако аргумент има точка в записа, то той е число с плаваща запетая
Ако аргумент започва със 0X или 0x, то той е число записано в шестнадесетична бройна система
В противен случай аргументът е цяло число, записано в десетична бройна система

Използвайте функциите от стандартната библиотека за да си улесните работата по обработването 
на аргументите от командния ред (напр. atoi, strtof, sscanf от string.h).
Примерно изпълнение:
$ ./sum_cli 10 12.5 0xff -21 55 0XA 3.14
Sum is 324.64
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]) {
    double sum = 0;
    for(size_t i = 1; i < argc; i++) {
        if(strstr(argv[i], ".")) {
            double curNum;
            sscanf(argv[i], "%lf", &curNum);
            sum += curNum;
        } else if(argv[i][0] == '0' && (argv[i][1] == 'x' || argv[i][1] == 'X')) {
            int curNum;
            sscanf(argv[i], "%x", &curNum);
            sum += curNum;
        } else {
            int curNum;
            sscanf(argv[i], "%d", &curNum);
            sum += curNum;
        }
    }
    printf("%lf\n", sum);
    sum = 0;
    for(size_t i = 1; i < argc; i++) {
        sum += atof(argv[i]);
    }
    printf("%lf\n", sum);
    return 0;
}