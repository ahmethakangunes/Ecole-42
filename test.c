
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

void    ft_topper(unsigned int a, char *c)
{
    int dif;
    dif = 'a' - 'A';
    if (c[a])
    {
        if (c[a] >= 'a' && c[a] <= 'z')
            c[a] -= dif;
    }
}
void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int    i;
    i = 0;
    if(s != NULL && f != NULL)
    {
        while (s[i])
        {
            printf("%c",s[i]);
            (*f)(i, s);
            i++;
        }
    }
}
int main()
{
    char    *mel = "heeeeeyo";
    printf("hihi");
    ft_striteri(mel, &ft_topper);
    printf("%s",mel);
    return 0;
}