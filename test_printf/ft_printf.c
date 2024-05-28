#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
int get_d_len(long long d)
{
    int cnt;

    cnt = 0;
    while (d)
    {
        cnt++;
        d /= 10;
    }
    return (cnt);
}

int get_d(long long d)
{
    int         cnt;
    long long   num;
    int         len;
    char        *ret;

    len = 0;
    num = 0;
    if (d < 0)
    {
        len += write(1, "-", 1);
        d *= -1;
    }
    else if (d == 0)
    {
        len += write(1, "0", 1);
        return (len);
    }
    num = d;
    cnt = get_d_len(num);
    ret = malloc(sizeof(char) * (cnt + 1));
    ret[cnt]= '\0';
    while (cnt--)
    {
        ret[cnt] = num % 10 + '0';
        num /= 10;
    }
    len += write(1, ret, ft_strlen(ret));
    free(ret);
    return (len);
}

int get_x(unsigned int x)
{
    const char      *hex = "0123456789abcdef";
    unsigned int    temp;
    int             cnt;
    int             len;
    char            *s;

    cnt = 0;
    temp = x;
    len = 0;
    if (x == 0)
    {
        len += write(1, "0", 1);
        return (len);
    }
    while (temp)
    {
        cnt++;
        temp /= 16;
    }
    s = malloc(sizeof(char) * (cnt + 1));
    s[cnt] = '\0';
    while (cnt--)
    {
        s[cnt] = hex[x % 16];
        x /= 16;
    }
    len = write(1, s, ft_strlen(s));
    free(s);
    return (len);
}

int get_s(char *s)
{
    int len;

    len = 0;
    if (s == NULL)
    {
        len = write(1, "(null)", 6);
        return (len);
    }
    len = write(1, s, ft_strlen(s));
    return (len);
}

int check_op(char c, void *arg)
{
    if (c == 'd')
        return (get_d((int)arg));
    else if (c == 'x')
        return (get_x((unsigned int)arg));
    else if (c == 's')
        return (get_s((char *)arg));
    else
        return (0);
}

int ft_printf(char *s, ...)
{
    int     i;
    int     temp;
    int     len;
    void    *arg;
    va_list ap;

    i = 0;
    temp = 0;
    len = 0;
    va_start(ap, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            arg = va_arg(ap, void *);
            temp = check_op(s[i], arg);
            if (temp < 0)
                return (-1);
            len += temp;
        }
        else
        {
            temp = write(1, &s[i], 1);
            if (temp < 0)
                return (-1);
            len += temp;
        }
        i++;
    }
    va_end(ap);
    return (len);
}

//int main(void)
//{
//    printf("len : %d\n", printf("%x\n", -10));
//    printf("len : %d\n", ft_printf("%x\n", -10));
//    return (0);
//}