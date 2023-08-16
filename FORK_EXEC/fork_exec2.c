#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
 
int main(void)
{
    while (1)
    {
        char line_buffer[200];
        int char_c = 0;
        char curr_sym = '\0';
        while (curr_sym != '\n')
        {
            curr_sym = getc(stdin);
            line_buffer[char_c++] = curr_sym;
        }
        line_buffer[char_c - 1] = '\0';//!!!!!!
        fwrite(line_buffer, sizeof(char), char_c, stdout);
 
        // split string into whitespaces and get seperate args
        char *exec_argv[10];
        exec_argv[0] = strtok(line_buffer, " ");
        for (int i = 1; exec_argv[i - 1] != NULL; i++)
        {
            exec_argv[i] = strtok(NULL, " ");
        }
        // for (int i = 0; i < 10; i++)
        // {
        //     printf("%s\n", exec_argv[i]);
        // }
 
        int pid = fork();
        if (pid == -1)
        {
            perror("Could not fork.\n");
            exit(-1);
        }
        else if (pid == 0)
        {
            // child
            printf("%s ", exec_argv[0]);
            printf("%s ", exec_argv[1]);
            execvp(exec_argv[0], exec_argv);
            perror("Exec failed.");
            exit(1);
        }
        else
        {
            // parent
            int wstatus;
            pid_t child_pid = wait(&wstatus);
            if (!WIFEXITED(wstatus))
            {
                perror("Child did not exit normaly.\n");
            }
            else
            {
                printf("Child return codde %d\n", WEXITSTATUS(wstatus));
            }
            return 0;
        }
    }
}