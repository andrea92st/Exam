#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int match_space(FILE *f)
{
    int c;
    while ((c = fgetc(f)) != EOF)
    {
        if (!isspace(c))
        {
            ungetc(c, f);
            break;
        }
    }
    if (ferror(f))
        return -1;
    return 1;
}

int match_char(FILE *f, char c)
{
    int d = fgetc(f);
    if (d == EOF)
        return -1;
    if (d != c)
    {
        ungetc(d, f);
        return 0;
    }
    return 1;
}

int scan_char(FILE *f, va_list ap)
{
    int c = fgetc(f);
    if (c == EOF)
        return 0;
    char *dst = va_arg(ap, char *);
    *dst = (char)c;
    return 1;
}

int scan_int(FILE *f, va_list ap)
{
    int c;
    int sign = 1;
    long val = 0;
    int found = 0;

    match_space(f);
    c = fgetc(f);
    if (c == '-' || c == '+')
    {
        if (c == '-') sign = -1;
        c = fgetc(f);
    }

    while (c != EOF && isdigit(c))
    {
        found = 1;
        val = val * 10 + (c - '0');
        c = fgetc(f);
    }
    if (c != EOF)
        ungetc(c, f);

    if (!found)
        return 0;

    int *dst = va_arg(ap, int *);
    *dst = (int)(sign * val);
    return 1;
}

int scan_string(FILE *f, va_list ap)
{
    char *dst = va_arg(ap, char *);
    int c;
    int i = 0;

    match_space(f);

    while ((c = fgetc(f)) != EOF && !isspace(c))
    {
        dst[i++] = (char)c;
    }
    if (c != EOF)
        ungetc(c, f);

    if (i == 0)
        return 0;
    dst[i] = '\0';
    return 1;
}

int match_conv(FILE *f, const char **format, va_list ap)
{
    switch (**format)
    {
        case 'c':
            return scan_char(f, ap);
        case 'd':
            match_space(f);
            return scan_int(f, ap);
        case 's':
            match_space(f);
            return scan_string(f, ap);
        case EOF:
            return -1;
        default:
            return -1;
    }
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
    int nconv = 0;

    int c = fgetc(f);
    if (c == EOF)
        return EOF;
    ungetc(c, f);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (match_conv(f, &format, ap) != 1)
                break;
            else
                nconv++;
        }
        else if (isspace(*format))
        {
            if (match_space(f) == -1)
                break;
        }
        else if (match_char(f, *format) != 1)
            break;
        format++;
    }

    if (ferror(f))
        return EOF;
    return nconv;
}

int ft_scanf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int ret = ft_vfscanf(stdin, format, ap);
    va_end(ap);
    return ret;
}

#include <stdio.h>

int main(void)
{
    char c;
    int n;
    char s[100];

    printf("Tapez: X 123 bonjour\n");
    if (ft_scanf("%c %d %s", &c, &n, s) == 3)
        printf("lu: c='%c', n=%d, s=\"%s\"\n", c, n, s);
    else
        printf("erreur lecture\n");

    return 0;
}
