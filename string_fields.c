#include "main.h"

/**
 * get_precision - gets precision from format string
 * @p: format string
 * @params: parameters struct
 * @ap: argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	params->precision = d;
	return (p);
}
