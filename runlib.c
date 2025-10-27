#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static void	ft_isalpha_test(void)
{
	printf("ft_isalpha('A') = %d\n", ft_isalpha('A'));
	printf("ft_isalpha('z') = %d\n", ft_isalpha('z'));
	printf("ft_isalpha('1') = %d\n", ft_isalpha('1'));
}

static void	ft_isdigit_test(void)
{
	printf("ft_isdigit('8') = %d\n", ft_isdigit('8'));
	printf("ft_isdigit('a') = %d\n", ft_isdigit('a'));
}

static void	ft_isalnum_test(void)
{
	printf("ft_isalnum('A') = %d\n", ft_isalnum('A'));
	printf("ft_isalnum('3') = %d\n", ft_isalnum('3'));
	printf("ft_isalnum('!') = %d\n", ft_isalnum('!'));
}

static void	ft_isascii_test(void)
{
	printf("ft_isascii(65) = %d\n", ft_isascii(65));
	printf("ft_isascii(200) = %d\n", ft_isascii(200));
}

static void	ft_isprint_test(void)
{
	printf("ft_isprint(32) = %d\n", ft_isprint(32));
	printf("ft_isprint(127) = %d\n", ft_isprint(127));
}

static void	test_is_functions(void)
{
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isascii_test();
	ft_isprint_test();
}

static void	ft_strlen_test(void)
{
	printf("ft_strlen('Hello') = %u\n", ft_strlen("Hello"));
	printf("ft_strlen('') = %u\n", ft_strlen(""));
}

static void	ft_strlcpy_test(void)
{
	char	buf[20];

	ft_strlcpy(buf, "HelloWorld", 6);
	printf("ft_strlcpy('HelloWorld', 6) -> '%s'\n", buf);
}

static void	ft_strlcat_test(void)
{
	char	dest[15];
	char	src[] = "World";
	size_t	len;

	ft_strlcpy(dest, "Hello", sizeof(dest));
	len = ft_strlcat(dest, src, sizeof(dest));
	printf("ft_strlcat result: '%s', return = %zu\n", dest, len);
}

static void	test_str_functions(void)
{
	ft_strlen_test();
	ft_strlcpy_test();
	ft_strlcat_test();
}

static void	ft_memset_test(void)
{
	char	str[50];

	strcpy(str, "Hello World");
	ft_memset(str + 5, '-', 3);
	printf("ft_memset('Hello World', '-', 3) -> %s\n", str);
}

static void	ft_bzero_test(void)
{
	char	str[20];

	strcpy(str, "abcdef");
	ft_bzero(str + 2, 3);
	printf("ft_bzero('abcdef', 3) -> %c%c%c%c%c%c\n",
		str[0], str[1], str[2], str[3], str[4], str[5]);
}

static void	ft_memcpy_test(void)
{
	char	buf[20];

	strcpy(buf, "1234567890");
	ft_memcpy(buf + 2, buf, 5);
	printf("ft_memcpy overlap (nao seguro): %s\n", buf);
}

static void	ft_memmove_test(void)
{
	char	buf[20];

	strcpy(buf, "abcdefghij");
	ft_memmove(buf + 2, buf, 5);
	printf("ft_memmove overlap (seguro): %s\n", buf);
}

static void	test_mem_functions(void)
{
	ft_memset_test();
	ft_bzero_test();
	ft_memcpy_test();
	ft_memmove_test();
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		test_is_functions();
		test_str_functions();
		test_mem_functions();
	}
	else
	{
		int	i;

		for (i = 1; i < argc; i++)
		{
			if (strcmp(argv[i], "is") == 0)
				test_is_functions();
			else if (strcmp(argv[i], "str") == 0)
				test_str_functions();
			else if (strcmp(argv[i], "mem") == 0)
				test_mem_functions();
			else if (strcmp(argv[i], "ft_isalpha") == 0)
				ft_isalpha_test();
			else if (strcmp(argv[i], "ft_isdigit") == 0)
				ft_isdigit_test();
			else if (strcmp(argv[i], "ft_isalnum") == 0)
				ft_isalnum_test();
			else if (strcmp(argv[i], "ft_isascii") == 0)
				ft_isascii_test();
			else if (strcmp(argv[i], "ft_isprint") == 0)
				ft_isprint_test();
			else if (strcmp(argv[i], "ft_strlen") == 0)
				ft_strlen_test();
			else if (strcmp(argv[i], "ft_strlcpy") == 0)
				ft_strlcpy_test();
			else if (strcmp(argv[i], "ft_strlcat") == 0)
				ft_strlcat_test();
			else if (strcmp(argv[i], "ft_memset") == 0)
				ft_memset_test();
			else if (strcmp(argv[i], "ft_bzero") == 0)
				ft_bzero_test();
			else if (strcmp(argv[i], "ft_memcpy") == 0)
				ft_memcpy_test();
			else if (strcmp(argv[i], "ft_memmove") == 0)
				ft_memmove_test();
			else
				printf("Funcao '%s' nao reconhecida.\n", argv[i]);
		}
	}
	return (0);
}
