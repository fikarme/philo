// Assignment name  : ft_printf
// Expected files   : ft_printf.c
// Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
// --------------------------------------------------------------------------------

// Write a function named `ft_printf` that will mimic the real printf but
// it will manage only the following conversions: s,d and x.

// Your function must be declared as follows:

// int ft_printf(const char *, ... );

// Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
// To test your program compare your results with the true printf.

// Exemples of the function output:

// call: ft_printf("%s\n", "toto");
// out: toto$

// call: ft_printf("Magic %s is %d", "number", 42);
// out: Magic number is 42%

// call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// out: Hexadecimal for 42 is 2a$

// #include <unistd.h>
// #include <stdarg.h>

// void	put_string(char *string, int *length)
// {
// 	if (!string)
// 		string = "(null)";
// 	while (*string)
// 		*length += write(1, string++, 1);
// }

// void	put_digit(long long int number, int base, int *length)
// {
// 	char	*hexadecimal = "0123456789abcdef";

// 	if (number < 0)
// 	{
// 		number *= -1;
// 		*length += write(1, "-", 1);
// 	}
// 	if (number >= base)
// 		put_digit((number / base), base, length);
// 	*length += write(1, &hexadecimal[number % base], 1);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int length = 0;

// 	va_list	pointer;
// 	va_start(pointer, format);

// 	while (*format)
// 	{
// 		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
// 		{
// 			format++;
// 			if (*format == 's')
// 				put_string(va_arg(pointer, char *), &length);
// 			else if (*format == 'd')
// 				put_digit((long long int)va_arg(pointer, int), 10, &length);
// 			else if (*format == 'x')
// 				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
// 		}
// 		else
// 			length += write(1, format, 1);
// 		format++;
// 	}
// 	return (va_end(pointer), length);
// }

// ///////////

// #include <unistd.h>
// #include <stdarg.h>

// void	put_string(char *string, int *length)
// {
// 	if (!string)
// 		string = "(null)";
// 	while (*string)
// 		*length += write(1, string++, 1);
// }

// void	put_digit(long long int number, int base, int *length)
// {
// 	char	*hexadecimal = "0123456789abcdef";

// 	if (number < 0)
// 	{
// 		number *= -1;
// 		*length += write(1, "-", 1);
// 	}
// 	if (number >= base)
// 		put_digit((number / base), base, length);
// 	*length += write(1, &hexadecimal[number % base], 1);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int length = 0;

// 	va_list	pointer;
// 	va_start(pointer, format);

// 	while (*format)
// 	{
// 		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
// 		{
// 			format++;
// 			if (*format == 's')
// 				put_string(va_arg(pointer, char *), &length);
// 			else if (*format == 'd')
// 				put_digit((long long int)va_arg(pointer, int), 10, &length);
// 			else if (*format == 'x')
// 				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
// 		}
// 		else
// 			length += write(1, format, 1);
// 		format++;
// 	}
// 	return (va_end(pointer), length);
// }

// //////////

// #include <stdarg.h>
// #include <unistd.h>

// void	put_str(char *str, int *len);
// {
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		*len += write(1, str++, 1);
// }

// void	put_digit(long long int nbr, int base, int *len)
// {
// 	char	*hexa;

// 	hexa = "0123456789abcdef";
// 	if (nbr < 0)
// 	{
// 		nbr *= -1;
// 		*len += write(1, "-", 1);
// 	}
// 	if (nbr >= base)
// 		put_digit((nbr / base), base, len);
// 	*len += write(1, &hexa[nbr % base], 1);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int		len;
// 	va_list	ptr;

// 	len = 0;
// 	va_start(ptr, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == 's')
// 				put_str(va_arg(ptr, char *), &len);
// 			else if (*format == 'd')
// 				put_digit((long long int)va_arg(ptr, int), 10, &len);
// 			else if (*format == 'x')
// 				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
// 		}
// 		else
// 			len += write(1, format, 1);
// 		format++;
// 	}
// 	return (va_end(ptr), len);
// }

// /*
// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	int	size;

// 	size = 0;

// 	size = ft_printf("%s\n", "toto");
// 	printf("%d\n", size);
// 	size = printf("%s\n", "toto");
// 	printf("%d\n", size);
// 	size = ft_printf("Magic %s is %d\n", "number", 42);
// 	printf("%d\n", size);
// 	size = printf("Magic %s is %d\n", "number", 42);
// 	printf("%d\n", size);
// 	size = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
// 	printf("%d\n", size);
// 	size = printf("Hexadecimal for %d is %x\n", 42, 42);
// 	printf("%d\n", size);
// 	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
// 	printf("%d\n", size);
// 	size = ft_printf("%d %d %x\n", INT_MAX, INT_MIN, UINT_MAX);
// 	printf("%d\n", size);
// 	size = ft_printf("%d, %d\n", 0, -24);
// 	printf("%d\n", size);
// 	size = ft_printf("%d, %d\n", 0, -24);
// 	printf("%d\n", size);
// 	printf("%d\n", size);
// 	ft_printf("Hello world %\n");
// 	return (0);
// }
// */

// /////////

// #include <stdarg.h> // For va_lis, va_start, va_arg, va_copy, va_end
// #include <unistd.h> // For malloc, free, write

// void	put_str(char *str, int *len)
// {
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		*len += write(1, str++, 1);
// }

// void	put_digit(long long int nbr, int base, int *len)
// {
// 	char	*hexa;

// 	hexa = "0123456789abcdef";
// 	if (nbr < 0)
// 	{
// 		nbr *= -1;
// 		*len += write(1, "-", 1);
// 	}
// 	if (nbr >= base)
// 		put_digit((nbr / base), base, len);
// 	*len += write(1, &hexa[nbr % base], 1);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int			len;
// 	va_list		ptr;

// 	len = 0;
// 	va_start(ptr, format);
// 	while (*format)
// 	{
// 		if ((*format == '%') && *(format + 1))
// 		{
// 			format++;
// 			if (*format == 's')
// 				put_str(va_arg(ptr, char *), &len);
// 			else if (*format == 'd')
// 				put_digit((long long int)va_arg(ptr, int), 10, &len);
// 			else if (*format == 'x')
// 				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
// 		}
// 		else
// 			len += write(1, format, 1);
// 		format++;
// 	}
// 	return (va_end(ptr), len);
// }

// ////

// #include <stdarg.h>
// #include <unistd.h>

// int	ft_put_char(char c)
// {
// 	return (write(1, &c, 1));
// }

// int	ft_put_str(char *str)
// {
// 	int	len;

// 	len = 0;
// 	if (!str)
// 		str = "(null)";
// 	while (*str)
// 		len += write(1, str++, 1);
// 	return (len);
// }

// int	ft_put_digits(long long nbr, int base)
// {
// 	int	len;

// 	len = 0;
// 	if (nbr < 0)
// 	{
// 		nbr *= -1;
// 		len += write(1, "-", 1);
// 	}
// 	if (nbr >= base)
// 		len += ft_put_digits((nbr / base), base);
// 	len += ft_put_char("0123456789abcdef"[nbr % base]);
// 	return (len);
// }

// int	ft_printf(const char *format, ...)
// {
// 	int		idx;
// 	int		len;
// 	va_list	arg;

// 	idx = 0;
// 	len = 0;
// 	va_start(arg, format);
// 	while (format[idx])
// 	{
// 		if (format[idx] != '%')
// 			len += write(1, &format[idx], 1);
// 		else if (format[idx] == '%' && format[idx + 1])
// 		{
// 			idx++;
// 			if (format[idx] == 's')
// 				len += ft_put_str(va_arg(arg, char *));
// 			else if (format[idx] == 'x')
// 				len += ft_put_digits((long long)va_arg(arg, unsigned int), 16);
// 			else if (format[idx] == 'd')
// 				len += ft_put_digits((long long)va_arg(arg, int), 10);
// 		}
// 		idx++;
// 	}
// 	va_end(arg);
// 	return (len);
// }

// ////////

