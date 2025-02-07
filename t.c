#include <stdio.h>
#include <string.h>

int main()
{
	printf("sadsad\n");
    const char s1[] = "pipoos";
    const char s2[] = "faskjfpwheqtpi43u86y430p8ghp4eoighwq;";

    int map[256] = {0};  // Store characters from s2
    int used[256] = {0}; // Keep track of printed characters

    int len = strlen(s2);
    for (int i = 0; i < len; i++)
    {
        map[(unsigned char)s2[i]] = 1; // Mark presence of characters
    }

    len = strlen(s1);
    for (int i = 0; i < len; i++)
    {
        if (map[(unsigned char)s1[i]] == 1) // If s1[i] is in s2, skip it
            continue;

        if (!used[(unsigned char)s1[i]]) // Print only once
        {
            printf("%c", s1[i]);
            used[(unsigned char)s1[i]] = 1;
        }
    }

    return 0;
}
