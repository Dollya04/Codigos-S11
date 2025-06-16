#include <stdio.h>

int main (int argc, char *argv[]) {

FILE *fp = fopen("data.txt", "r");
char c = fgetc(fp);
printf("%c", c);
fclose(fp);
    return 0;
}