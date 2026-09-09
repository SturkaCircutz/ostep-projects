#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search_stream(FILE *fp, char * term);
int main(int argc, char *argv[]) {

    if (argc == 1) {
        // usage message, exit 1
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    char *term = argv[1];

    if (argc == 2) {
        // no files: search stdin, then return 0
        search_stream(stdin, term);
        return 0;
    }

    for (int i = 2; i < argc; i++) {
        // fopen argv[i]
        // if NULL: error message, exit 1
        // search_stream(fp, term)
        // fclose
        FILE * fp = fopen(argv[i], "r");
        if(fp == NULL){
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        search_stream(fp, term);
        fclose(fp);
    }

    return 0;
}

void search_stream(FILE *fp, char *term) {
    // getline setup: a char * and a size_t, initialized
    // per man getline

    // while (getline(...) != -1) {
    //     if the term is in the line, print the line
    // }

    // free the buffer getline allocated
    char * line = NULL;
    size_t size = 0;
    while(getline(&line, &size, fp) != -1){
        if (strstr(line, term) != NULL){
            printf("%s", line);
        }
    }
    free(line);
}