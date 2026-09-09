#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    for(size_t i = 1; i < argc; i++)
    {
        char s[1024];
        FILE * fp = fopen(argv[i], "r");
        if(fp == NULL){
            fprintf(stdout, "wcat: cannot open file\n");
            exit(1);
        }
        while(fgets(s, sizeof(s), fp) != NULL)
        {
            printf("%s", s);
        }
        fclose(fp);

    }
    return 0;
}