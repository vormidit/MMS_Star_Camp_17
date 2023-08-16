//Прави копие и пренасочва на файловия дескриптор за стандартен изход, който всъщност е файл който сме създали или отворили

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main() {
    int fd = open("output.txt", O_WRONLY | O_APPEND | O_CREAT);
    if(fd < 0) {
        perror("Could not open file");
        return 1;
    }
    int fddupped;
    if((fddupped = dup2(fd, STDOUT_FILENO)) == -1) {
        perror("DUP2 failed");
        return 1;
    };
    printf("NEW FD: %d\n", fddupped);
    // close(STDOUT_FILENO)
    // open("otput.txt", .....);
    // close(fd);
    printf("Hello World!\n");
    printf("Hello world2!\n");
    return 0;
}