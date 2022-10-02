/*

Accept a string and change the case of each character of the string. Example “THIs Is a C
Program” changes to “thiS iS A c pROGRAM”.

*/

#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    int i;
    printf("Enter a string : ");
    gets(s);
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
    }
    printf("Changed string is  %s", s);
    return 0;
}