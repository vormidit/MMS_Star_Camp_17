/*символни низове:
От стандартния вход се въвежда цяло положително число (което има най-много 500 цифри). Напишете функция, която кодира низа и връща нов символен низ, за който е заделена динамична памет. Кодирането се случва по следния начин:
Ако една цифра е на четна позиция, тя се замества със съответстващата главна латинска буква. Например:
0 се замества с A 
1 се замества с B
2 се замества с C и т.н.
Ако една цифра е на нечетна позиция, тя се замества със символ, както е зададено в долната таблица:


Table:
0 -> !
1-> #
2->/
3->~
4->=
5->‘
6->\
7->>
8->.
9->,

Погрижете се за освобождаването на динамично заделената памет.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const char odd_symbols[] = "!#/~=`\\>.,";
char* encode_str(const char *str) {
    size_t n = strlen(str);
    char *new_str = malloc((n+1)*sizeof(char));//n+1 terminating symbol'\0'
    for(size_t i = 0; i < n;i++) {
        if(i % 2 == 0) {
            new_str[i] = str[i] - '0' + 'A';
        } else {
            new_str[i] = odd_symbols[str[i] - '0'];
        }
    }
    new_str[n] = '\0';//Terminating symbol adding
    return new_str;
}
int main() {
    char str[501];
    scanf("%s", str);
    char* new_str = encode_str(str);
    printf("%s\n", new_str);
    free(new_str);
    return 0;
}