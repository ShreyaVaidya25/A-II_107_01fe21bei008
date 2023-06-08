#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
    char    str[10];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;

    fptr = fopen("map.fdf", "w");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    while (str[i] != '\0')
    {
        num = rand() % 10;
        num2 = num + '0';
        str[i] = num2;
        i += 1;
    }
    puts(str);
    fprintf(fptr,"%s", str);
    fclose(fptr);
    return (0);
}
