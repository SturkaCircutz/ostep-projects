#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    if (argc == 1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    for (int f = 1; f < argc; f++){
        FILE * fp = fopen(argv[f], "r");
        if (fp == NULL){
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        int count; char c;
        while (fread(&count, sizeof(int), 1, fp) == 1)
        {
            if(fread(&c, sizeof(char), 1, fp) != 1){
                break;
            }
            for (int i = 0; i < count; i++){
                putchar(c);
            }
        }
        fclose(fp);
    }
    return 0;
}
