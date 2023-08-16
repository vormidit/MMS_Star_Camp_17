/*Създайте проста реализация на командата xxd.

Програмата приема 2 аргумента от командния ред:
filename
print_mode

Ако print_mode е -H, тогава се печата HEX DUMP на файла с име filename. Това означава, че се печата стойността на всеки байт от файла в шестнадесетична бройна система. Тази функционалност съответства на работата на командата xxd filename.

Ако print_mode е -B, тогава се печата стойността на всеки байт от файла в двоична бройна система. Тази функционалност съответства на работата на командата xxd -b filename.

Компилирайте програмата в executable файл с името my_xxd.
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<inttypes.h>
#include<string.h>
#include<stdlib.h>
// getHexDigit(10) ---> 'A'
// getHexDigit(3) ---> '3'
// getHexDigit(15) ---> 'F'
char getHexDigit(size_t decimal_digit) {
    if(decimal_digit <= 9) {
        return '0' + decimal_digit;
    } else {
        return 'A' + decimal_digit;
    }
}
int main(int argc, char* argv[]) {
    // File descriptors
    // 0 - standart input
    // 1 - standart output
    // 2 - standart error output
    write(1, "Hello world!", 12);

    fwrite("Hello world!\n", sizeof(char), 13, stdout);

    int fd = open(argv[1], O_RDONLY);
    if(fd == -1) {
        write(2, "Open error\n", 11);
        return -1;
    }

    uint8_t buf[10000];
    size_t file_size = lseek(fd, 0, SEEK_END);

    lseek(fd, 0, SEEK_SET);

    int bytes_read = read(fd, buf, file_size);
    if(bytes_read == -1) {
        write(2, "Read error\n", 11);
        exit(-1);
    }
    if(strcmp(argv[2], "-H") == 0) {
        char hex_buf[3];
        for (size_t i = 0; i < file_size; i++) {
            // printf("%x ", buf[i]);   Вариант 1 - без системни извиквания

            // First digit of hex number
            hex_buf[0] = getHexDigit(buf[i] >> 4);
            // hex_buf[0] = getHexDigit(buf[i] / 16);


            // Last digit of hex number
            hex_buf[1] = getHexDigit(buf[i] & 0xf);
            // hex_buf[1] = getHexDigit(buf[i] % 16);

            hex_buf[2] = ' ';

            write(STDOUT_FILENO, hex_buf, 3);
        }
    }
    if(strcmp(argv[2], "-Hfaster") == 0) {
        char *output_buf = malloc(3*file_size);
        if(!output_buf) {
            write(STDERR_FILENO, "Could not malloc!", 17);
            exit(-1);
        }
        for (size_t i = 0; i < file_size; i++) {
            // printf("%x ", buf[i]);   Вариант 1 - без системни извиквания

            // First digit of hex number
            output_buf[3*i + 0] = getHexDigit(buf[i] >> 4);

            // Last digit of hex number
            output_buf[3*i + 1] = getHexDigit(buf[i] & 0xf);

            output_buf[3*i + 2] = ' ';
        }
        write(STDOUT_FILENO, output_buf, 3*file_size);
        free(output_buf);
    }
    if(strcmp(argv[2], "-B") == 0) {
        char *output_buf = malloc((8 + 1)*file_size);
        if(!output_buf) {
            write(STDERR_FILENO, "Could not malloc!", 17);
            exit(-1);
        }
        for (size_t i = 0; i < file_size; i++) {
            // uint8_t temp = buf[i];
            for(int bit_index = 7; bit_index >= 0; bit_index--) {
                output_buf[i*9 + bit_index] = '0' + ((buf[i] >> bit_index)&1);

                // output_buf[i*9 + bit_index] = !!(1 << bit_index) & buf[i];


                // output_buf[i*9 + bit_index] = temp%2;
                // temp = temp / 2;
            }
            output_buf[i*9 + 8] = ' ';
        }
        write(STDOUT_FILENO, output_buf, 9*file_size);
        free(output_buf);
    }

    close(fd);
}