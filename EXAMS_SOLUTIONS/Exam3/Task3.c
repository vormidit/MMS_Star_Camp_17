/*A:(3т) Създайте следната структура:
struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[??];
};

Изберете подходящ размер за product_name, така че да не се добавят празни байтове при запазването на структурата в паметта.

Създайте масив от 40 продукта със следните случайни стойности:
old_price и new_price са десетични дроби между 4.99 и 100.45 с точност до 2 цифри след десетичната запетая.
product_type е символ измежду ‘A’, ‘B’, ‘C’ или ‘D’.
product_name се избира от масив с предварително избрани символни низове.
id е уникално положително число за всеки продукт.

Изпечатайте описателна информация за всеки продукт.


B:(4т) Сортирайте масива от продукти по следния начин:

Гледа се колко се е покачила цената на един продукт. По-напред ще бъдат сортирани продуктите, 
които са имали по-голямо покачване в цената. Покачването на цената се смята като (new_price - old_price).

Ако покачването в цената на 2 продукта е еднаква (ако разликата е по-малка от 0.01), 
то тогава се сравнява product_type. По-напред ще бъдат сортирани продуктите с лексикографски по-голям product_type. 
Например продуктът с product_type=’B’ ще бъде сортиран по-напред от този с product_type=’A’.

Ако product_type е еднакъв за два продукта, тогава се сравняват имената на продуктите. 
По-напред ще бъде сортиран продукт с лексикографски по-малък product_name.

Ако product_name е еднакъв за два продукта - сравняват се техните id-та. 
По-напред ще бъде сортират продукт с по-малко id.

Изпечатайте масива от продукти след сортирането.

C:(3т) Напишете функция, която записва съдържанието на масива от Product в бинарен файл.

Създайте отделна програма, която да прочита съдържанието на такъв бинарен файл и да изпечатва описателен текст за всеки продукт на стандартния изход.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct Product
{
     double old_price;
     double new_price;
     unsigned int id;
     char product_type;
     char product_name[3];
} Product;

Product arr[40];

char *names[] = {"AB", "BC", "CD", "DD", "DA", "AA"};
void init_arr() {
     
    for(size_t i = 0; i < 40; i++) {
        // 1. Числа от 499 до 10045
        // 2. Делим на 100.
        arr[i].old_price = (rand()%(10045 - 499) + 499)/100.;
        arr[i].new_price = (rand()%(10045 - 499) + 499)/100.;
        arr[i].id = i;
        arr[i].product_type = rand()%4 + 'A';
        strcpy(arr[i].product_name, names[rand()%6]);
    }
}
void print_arr() {
    for(size_t i = 0; i < 40; i++) {
        printf("id: %4u, new_p: %7.2f, old_p: %7.2f, type:%2c, name: %3s, price_delta: %f\n", arr[i].id, arr[i].new_price, arr[i].old_price, arr[i].product_type, arr[i].product_name, arr[i].new_price - arr[i].old_price);
    }
    printf("\n");
}
int cmp(const void *a, const void *b) {
    const Product *A = a, *B = b;
    double price_d_a = A->new_price - A->old_price;
    double price_d_b = B->new_price - B->old_price;

    if(fabs(price_d_a - price_d_b) >= 0.01) {
        return (price_d_a - price_d_b)*100;
    } else if(A->product_type != B->product_type) {
        return B->product_type - A->product_type;
    } else if(strcmp(A->product_name, B->product_name)) {
        return strcmp(A->product_name, B->product_name);
    } else {
        return A->id - B->id;
    }
}
int main() {
    init_arr();
    arr[0].new_price = 0;
    arr[0].old_price = 0;
    arr[1].new_price = 0;
    arr[1].old_price = 0;
    arr[2].new_price = 0;
    arr[2].old_price = 0;
    print_arr();
    qsort(arr, 40, sizeof(arr[0]), cmp);
    print_arr();

    FILE *f1 = fopen("output.bin", "w");
    fwrite(arr, sizeof(Product), 40, f1);
    fclose(f1);

    FILE *f2 = fopen("output.bin", "r");
    fread(arr, sizeof(Product), 40, f2);
    fclose(f2);
    return 0;
}