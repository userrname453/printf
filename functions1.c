#include "main.h"

/************************* OUTPUT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Outputs an unsigned integer
 * @types: List of arguments
 * @buffer: Array for managing output
 * @flags:  Determines active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Count of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
				   int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* OUTPUT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Outputs an unsigned integer in octal format
 * @types: List of arguments
 * @buffer: Array for managing output
 * @flags:  Determines active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Count of characters printed
 */
int print_octal(va_list types, char buffer[],
				int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** OUTPUT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Outputs an unsigned integer in hexadecimal format
 * @types: List of arguments
 * @buffer: Array for managing output
 * @flags:  Determines active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Count of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
					  int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
					   flags, 'x', width, precision, size));
}

/************* OUTPUT UNSIGNED NUMBER IN UPPERCASE HEXADECIMAL **************/
/**
 * print_hexa_upper - Outputs an unsigned integer in uppercase hexadecimal format
 * @types: List of arguments
 * @buffer: Array for managing output
 * @flags:  Determines active flags
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Count of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
					 int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
					   flags, 'X', width, precision, size));
}

/************** OUTPUT HEXADECIMAL NUMBER IN LOWER OR UPPER CASE **************/
/**
 * print_hexa - Outputs a hexadecimal number in either lower or upper case
 * @types: List of arguments
 * @map_to: Array of characters for mapping the number
 * @buffer: Array for managing output
 * @flags:  Determines active flags
 * @flag_ch: Character for the active flag
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Count of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
			   int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
/*Contributors: Juskins & MCCHANCE*/
