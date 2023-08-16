#include<stdio.h>
#include<unistd.h>
int main() {
    // execl("./infinite", "./infinite", NULL);
    // execlp("ls", "ls", "-la", NULL); // OK
    // execl("ls", "ls", "-la", NULL); // ls is not in current dir

    // char* argv[] = {"ls", "-la", NULL};
    // execvp("ls", argv);
    
    char* argv[] = {"grep", "PATH", NULL};
    execvp("grep", argv);
    perror("exec failed: ");
    return 1;
}