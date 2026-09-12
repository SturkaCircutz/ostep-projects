#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

/* Global path information */
char *paths[100];
int path_count;


/* ---------- Helpers ---------- */

void print_error(void);

void init_path(void);

void free_path(void);

int find_program(char *command, char *full_path);

int tokenize(char *command, char **args);

void handle_builtin(char **args, int argc);


/* ---------- Main ---------- */

int main(int argc, char *argv[])
{
    /* 1. Check argc */

    /* 2. Open batch file or use stdin */

    /* 3. Initialize path to /bin */
    FILE * input;
    // char * s[1024];
    size_t  size = 0;
    char * line = NULL;
    if(argc == 1){
        input = stdin;
    }
    else if(argc == 2){
        input = fopen(argv[1], "r");
    }
    else{
        printf("it's an error");
        exit(1);
    }
    // while(fgets(s, sizeof(s), input) != NULL)
    char ** arr = malloc(sizeof(char *) * 1024);
    int count = 0;
    while(getline(&line, &size, input) != NULL){
        char * curr = malloc(strlen(line) + 1);
        int j = 0;
        int k = 0;
        while(line[j] != '\0'){
            if(line[j] == '&'){
                curr[k] = '\0';
                arr[count] = curr;
                count ++;
                k = 0;

                curr = malloc(strlen(line) + 1);
            }
            else{
                curr[k] = line[j];
                k++;
            }
            j++;
        }
        curr[k] = '\0';
        arr[count] = curr;
        count ++; 
        
    }
    while (1)
    {
        /* 4. Print prompt if interactive */

        /* 5. Read one line using getline */

        /* 6. If EOF -> exit */

        /* 7. Split line by '&' */

        /* 8. For each command */
        while (/* another command */)
        {
            /* a. Ignore empty command */

            /* b. Check for '>' */

            if (/* redirection exists */)
            {
                /* 
                 * Split into:
                 * command part
                 * file part
                 */

                /* Validate redirection */

                /* Tokenize command */

                /* Check built-in */

                /* Find executable */

                /* fork */

                if (/* child */)
                {
                    /* open file */
                    /* dup2 stdout */
                    /* dup2 stderr */
                    /* close file */

                    /* execv */

                    /* if execv fails -> error + exit */
                }
                else
                {
                    /* save child pid */
                }
            }
            else
            {
                /* Tokenize command */

                /* If empty -> continue */

                /* Check built-in */

                /* Find executable */

                /* fork */

                if (/* child */)
                {
                    /* execv */

                    /* if execv fails -> error + exit */
                }
                else
                {
                    /* save child pid */
                }
            }
        }

        /* 9. Wait for all children */
        for (/* every saved pid */)
        {
            waitpid(/* pid */, NULL, 0);
        }
    }

    /* 10. Cleanup */
}