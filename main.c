#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <assert.h> 

# define STRLEN(a)          printf("'%s' = %zu (%zu)\n", a, ft_strlen(a), strlen(a));
# define STRCMP(d, e)      printf("`%s`:`%s` = %d (%d)\n", (d ? d : "(null)"), (e ? e : "(null)"), ft_strcmp(d, e), strcmp(d, e));


extern size_t ft_strlen(const char *str);
extern int ft_strcmp(char const *s1, const char *s2);
extern char *ft_strcpy(char *dst, char const *src);


int main()
{
    int     i = 0;
    long    r = 0;
    char    buffer[100];
    char    *aux;
    char    *aux2;

    while (i < 100)
    {
        buffer[i] = 0;
        i++;
    }

    printf("Test: ==> ft_strlen\n");
    STRLEN("");
    STRLEN("abcd");
    STRLEN("ABCDEFG");
    STRLEN("0123456789abcdef");
    STRLEN("42");
    STRLEN("1");
    printf("Test OK\n");

    printf("\nTest: ==> ft_strcmp\n");
    STRCMP("", "");
    STRCMP("abcd", "abcd");
    STRCMP("abcd", "abce");
    STRCMP("abcd", "abcefgh");
    STRCMP("", "abcd");
    STRCMP("abcd", "");
    printf("Test OK\n");

    return 0;
}