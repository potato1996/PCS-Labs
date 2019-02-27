/* stack_safe.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int no_bof(char *str)
{
    size_t len = strlen(str);
    char* buffer = (char*) malloc((len + 1) * sizeof(char));
    if(buffer){
        strcpy(buffer, str);
        free(buffer);
        return 1;
    }
    else{
        return -1;
    }
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    no_bof(str);

    printf("Returned Properly\n");
    fclose(badfile);
    return 1;
}
