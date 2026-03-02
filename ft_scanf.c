/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clwenhaj <clwenhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:53:44 by clwenhaj          #+#    #+#             */
/*   Updated: 2026/03/02 17:32:26 by clwenhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

void	skip_space(void)
{
	int c;
	while (isspace(c = fgetc(stdin)))
		;
	if (c != EOF)
		ungetc(c, stdin);
}

static int	scan_int(va_list ap)
{
	int	*dest;
	int	c;
	int	sign = 1;
	int	num = 0;

	dest = va_arg(ap, int *);
	skip_space();
	c = fgetc(stdin);
	if (c == '+' || c == '-')
	{
		if (c == '-')
			sign = -1;
		c = fgetc(stdin);
	}
	if (!isdigit(c))
		return (0);
	while (isdigit(c))
	{
		num = num * 10 + (c - '0');
		c = fgetc(stdin);
	}
	if (c != EOF)
		ungetc(c, stdin);
	*dest = num * sign;
	return (1);
}

static int	scan_string(va_list ap)
{
	char	*dest;
	int	c;
	int	i = 0;

	dest = va_arg(ap, char *);
	skip_space();
	c = fgetc(stdin);
	if (c == EOF)
		return (0);
	while (!isspace(c) && c != EOF)
	{
		dest[i++] = c;
		c = fgetc(stdin);
	}
	dest[i] = '\0';
	if (c != EOF)
		ungetc(c, stdin);
	return (1);
}

static int	scan_char(va_list ap)
{
	char	*dest;
	int	c;

	dest = va_arg(ap, char *);
	c = fgetc(stdin);
	if (c == EOF)
		return (0);
	*dest = c;
	return (1);
}



int	ft_scanf(const char *format, ...)
{
	va_list	ap;
	int	count = 0;
	int	c;

	va_start(ap, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' && scan_int(ap))
				count++;
			else if (*format == 's' && scan_string(ap))
				count++;
			else if (*format == 'c' && scan_char(ap))
				count++;
			else
				break;
		}
		else if (isspace(*format))
			skip_space();
		else
		{
			c = fgetc(stdin);
			if (c != *format)
				break;
		}
		format++;
	}	

	va_end(ap);
	return (count);	
}


int             main(void)
{
        char    c;
        int             d;
        char    s[100];

        int     retour = ft_scanf("%d %c %s", &d, &c, s);
        printf("retour = %d\n", retour);
        printf("d = %d ; c = %c ; s = %s\n", d, c, s);
        return (0);
}
