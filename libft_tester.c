#include "libft.h"

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_stats
{
	int	total;
	int	passed;
}t_stats;

static void	print_header(void)
{
	printf("Esse projeto foi feito como parte do curriculo academico de João Gabriel.\n");
	printf("Proposito: Reimplementar funções essenciais da linguagem C para construir\n");
	printf("uma base solida de manipulacao de memoria, strings, caracteres e I/O.\n");
	printf("Descricao: Este tester compara a minha implementacao com o comportamento\n");
	printf("esperado (funcao original quando existe, ou comportamento da especificacao).\n\n");
}

static int	sign_of(int value)
{
	if (value < 0)
		return (-1);
	if (value > 0)
		return (1);
	return (0);
}

static size_t	ref_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static size_t	ref_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = strlen(dst);
	src_len = strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

static char	*ref_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && (i + j) < len && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

static void	report_result(t_stats *stats, const char *name,
		const char *input, const char *expected, const char *actual, int pass)
{
	stats->total++;
	if (pass)
		stats->passed++;
	printf("Teste: %s\n", name);
	printf("Entrada: %s\n", input);
	printf("Esperado: %s\n", expected);
	printf("Obtido: %s\n", actual);
	printf("Status: %s\n\n", pass ? "OK" : "FALHOU");
}

typedef void	(*t_fd_writer)(int fd, void *arg);

static char	*capture_fd_output(t_fd_writer writer, void *arg)
{
	int		fd[2];
	ssize_t	bytes;
	char	buffer[256];
	char	*result;

	if (pipe(fd) == -1)
		return (NULL);
	writer(fd[1], arg);
	close(fd[1]);
	bytes = read(fd[0], buffer, sizeof(buffer) - 1);
	close(fd[0]);
	if (bytes < 0)
		return (NULL);
	buffer[bytes] = '\0';
	result = malloc((size_t)bytes + 1);
	if (!result)
		return (NULL);
	memcpy(result, buffer, (size_t)bytes + 1);
	return (result);
}

typedef struct s_putc_arg
{
	char	c;
}t_putc_arg;

typedef struct s_puts_arg
{
	char	*s;
}t_puts_arg;

typedef struct s_putn_arg
{
	int	n;
}t_putn_arg;

static void	write_putchar(int fd, void *arg)
{
	t_putc_arg	*a;

	a = (t_putc_arg *)arg;
	ft_putchar_fd(a->c, fd);
}

static void	write_putstr(int fd, void *arg)
{
	t_puts_arg	*a;

	a = (t_puts_arg *)arg;
	ft_putstr_fd(a->s, fd);
}

static void	write_putendl(int fd, void *arg)
{
	t_puts_arg	*a;

	a = (t_puts_arg *)arg;
	ft_putendl_fd(a->s, fd);
}

static void	write_putnbr(int fd, void *arg)
{
	t_putn_arg	*a;

	a = (t_putn_arg *)arg;
	ft_putnbr_fd(a->n, fd);
}

static int	all_zero(const void *ptr, size_t n)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (p[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

static void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	map_upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return ((char)(c - 32));
	return (c);
}

static void	iteri_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c = (char)(*c - 32);
}

int	main(void)
{
	t_stats	stats;
	char	expected[256];
	char	actual[256];
	char	buf1[32];
	char	buf2[32];
	char	mem_a[16];
	char	mem_b[16];
	char	*tmp;
	char	**split;
	int	idx_expected;
	int	idx_actual;
	int	ret_expected;
	int	ret_actual;
	t_putc_arg	pc;
	t_puts_arg	ps;
	t_putn_arg	pn;

	stats.total = 0;
	stats.passed = 0;
	print_header();

	snprintf(expected, sizeof(expected), "%d", isalpha('A') != 0);
	snprintf(actual, sizeof(actual), "%d", ft_isalpha('A') != 0);
	report_result(&stats, "ft_isalpha", "c='A'", expected, actual,
		(ft_isalpha('A') != 0) == (isalpha('A') != 0));

	snprintf(expected, sizeof(expected), "%d", isdigit('7') != 0);
	snprintf(actual, sizeof(actual), "%d", ft_isdigit('7') != 0);
	report_result(&stats, "ft_isdigit", "c='7'", expected, actual,
		(ft_isdigit('7') != 0) == (isdigit('7') != 0));

	snprintf(expected, sizeof(expected), "%d", isalnum('Z') != 0);
	snprintf(actual, sizeof(actual), "%d", ft_isalnum('Z') != 0);
	report_result(&stats, "ft_isalnum", "c='Z'", expected, actual,
		(ft_isalnum('Z') != 0) == (isalnum('Z') != 0));

	snprintf(expected, sizeof(expected), "%d", 127 <= 127 && 127 >= 0);
	snprintf(actual, sizeof(actual), "%d", ft_isascii(127) != 0);
	report_result(&stats, "ft_isascii", "c=127", expected, actual,
		(ft_isascii(127) != 0) == 1);

	snprintf(expected, sizeof(expected), "%d", isprint(' ') != 0);
	snprintf(actual, sizeof(actual), "%d", ft_isprint(' ') != 0);
	report_result(&stats, "ft_isprint", "c=' '", expected, actual,
		(ft_isprint(' ') != 0) == (isprint(' ') != 0));

	snprintf(expected, sizeof(expected), "%d", (int)strlen("libft"));
	snprintf(actual, sizeof(actual), "%d", ft_strlen("libft"));
	report_result(&stats, "ft_strlen", "str=\"libft\"", expected, actual,
		ft_strlen("libft") == (int)strlen("libft"));

	memset(mem_a, 'x', sizeof(mem_a));
	memset(mem_b, 'x', sizeof(mem_b));
	ret_expected = (memset(mem_a, 'A', 5) == (void *)mem_a);
	ret_actual = (ft_memset(mem_b, 'A', 5) == (void *)mem_b);
	snprintf(expected, sizeof(expected), "ptr_ok=%d, bytes=%.5s", ret_expected, mem_a);
	snprintf(actual, sizeof(actual), "ptr_ok=%d, bytes=%.5s", ret_actual, mem_b);
	report_result(&stats, "ft_memset", "ptr='xxxxx...', value='A', num=5",
		expected, actual, ret_expected == ret_actual && memcmp(mem_a, mem_b, 5) == 0);

	memset(mem_a, 'B', sizeof(mem_a));
	memset(mem_b, 'B', sizeof(mem_b));
	memset(mem_a, 0, 6);
	ft_bzero(mem_b, 6);
	snprintf(expected, sizeof(expected), "primeiros 6 bytes zerados");
	snprintf(actual, sizeof(actual), "%s", all_zero(mem_b, 6) ? "sim" : "nao");
	report_result(&stats, "ft_bzero", "ptr='BBBBBB...', num=6", expected, actual,
		memcmp(mem_a, mem_b, sizeof(mem_a)) == 0);

	memset(mem_a, 0, sizeof(mem_a));
	memset(mem_b, 0, sizeof(mem_b));
	ret_expected = (memcpy(mem_a, "abcdef", 7) == (void *)mem_a);
	ret_actual = (ft_memcpy(mem_b, "abcdef", 7) == (void *)mem_b);
	snprintf(expected, sizeof(expected), "ptr_ok=%d, out=%s", ret_expected, mem_a);
	snprintf(actual, sizeof(actual), "ptr_ok=%d, out=%s", ret_actual, mem_b);
	report_result(&stats, "ft_memcpy", "dest, src=\"abcdef\", num=7",
		expected, actual, ret_expected == ret_actual && strcmp(mem_a, mem_b) == 0);

	strcpy(mem_a, "123456789");
	strcpy(mem_b, "123456789");
	memmove(mem_a + 2, mem_a, 5);
	ft_memmove(mem_b + 2, mem_b, 5);
	snprintf(expected, sizeof(expected), "%s", mem_a);
	snprintf(actual, sizeof(actual), "%s", mem_b);
	report_result(&stats, "ft_memmove", "overlap: move 5 bytes de [0] para [2]",
		expected, actual, strcmp(mem_a, mem_b) == 0);

	idx_expected = (int)((char *)memchr("bonjour", 'j', 7) - "bonjour");
	idx_actual = (int)((char *)ft_memchr("bonjour", 'j', 7) - "bonjour");
	snprintf(expected, sizeof(expected), "indice=%d", idx_expected);
	snprintf(actual, sizeof(actual), "indice=%d", idx_actual);
	report_result(&stats, "ft_memchr", "s=\"bonjour\", c='j', n=7", expected,
		actual, idx_expected == idx_actual);

	ret_expected = sign_of(memcmp("abc", "abd", 3));
	ret_actual = sign_of(ft_memcmp("abc", "abd", 3));
	snprintf(expected, sizeof(expected), "%d", ret_expected);
	snprintf(actual, sizeof(actual), "%d", ret_actual);
	report_result(&stats, "ft_memcmp", "s1=\"abc\", s2=\"abd\", n=3",
		expected, actual, ret_expected == ret_actual);

	memset(buf1, 0, sizeof(buf1));
	memset(buf2, 0, sizeof(buf2));
	ret_expected = (int)ref_strlcpy(buf1, "lib42", 4);
	ret_actual = (int)ft_strlcpy(buf2, "lib42", 4);
	snprintf(expected, sizeof(expected), "ret=%d, dst=%s", ret_expected, buf1);
	snprintf(actual, sizeof(actual), "ret=%d, dst=%s", ret_actual, buf2);
	report_result(&stats, "ft_strlcpy", "dstsize=4, src=\"lib42\"", expected,
		actual, ret_expected == ret_actual && strcmp(buf1, buf2) == 0);

	strcpy(buf1, "42");
	strcpy(buf2, "42");
	ret_expected = (int)ref_strlcat(buf1, "school", sizeof(buf1));
	ret_actual = (int)ft_strlcat(buf2, "school", sizeof(buf2));
	snprintf(expected, sizeof(expected), "ret=%d, dst=%s", ret_expected, buf1);
	snprintf(actual, sizeof(actual), "ret=%d, dst=%s", ret_actual, buf2);
	report_result(&stats, "ft_strlcat", "dst=\"42\", src=\"school\"", expected,
		actual, ret_expected == ret_actual && strcmp(buf1, buf2) == 0);

	tmp = ft_substr("42libftproject", 2, 5);
	snprintf(expected, sizeof(expected), "%s", "libft");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_substr", "s=\"42libftproject\", start=2, len=5",
		expected, actual, tmp && strcmp(tmp, "libft") == 0);
	free(tmp);

	snprintf(expected, sizeof(expected), "%d", toupper('a'));
	snprintf(actual, sizeof(actual), "%d", ft_toupper('a'));
	report_result(&stats, "ft_toupper", "c='a'", expected, actual,
		ft_toupper('a') == toupper('a'));

	snprintf(expected, sizeof(expected), "%d", tolower('D'));
	snprintf(actual, sizeof(actual), "%d", ft_tolower('D'));
	report_result(&stats, "ft_tolower", "c='D'", expected, actual,
		ft_tolower('D') == tolower('D'));

	idx_expected = (int)(strchr("libft", 'f') - "libft");
	idx_actual = (int)(ft_strchr("libft", 'f') - "libft");
	snprintf(expected, sizeof(expected), "indice=%d", idx_expected);
	snprintf(actual, sizeof(actual), "indice=%d", idx_actual);
	report_result(&stats, "ft_strchr", "str=\"libft\", search='f'", expected,
		actual, idx_expected == idx_actual);

	strcpy(buf1, "abca");
	idx_expected = (int)(strrchr(buf1, 'a') - buf1);
	idx_actual = (int)(ft_strrchr(buf1, 'a') - buf1);
	snprintf(expected, sizeof(expected), "indice=%d", idx_expected);
	snprintf(actual, sizeof(actual), "indice=%d", idx_actual);
	report_result(&stats, "ft_strrchr", "str=\"abca\", search='a'", expected,
		actual, idx_expected == idx_actual);

	ret_expected = sign_of(strncmp("abcd", "abcf", 4));
	ret_actual = sign_of(ft_strncmp("abcd", "abcf", 4));
	snprintf(expected, sizeof(expected), "%d", ret_expected);
	snprintf(actual, sizeof(actual), "%d", ret_actual);
	report_result(&stats, "ft_strncmp", "s1=\"abcd\", s2=\"abcf\", n=4",
		expected, actual, ret_expected == ret_actual);

	idx_expected = (int)(ref_strnstr("hello libft", "libft", 11) - "hello libft");
	idx_actual = (int)(ft_strnstr("hello libft", "libft", 11) - "hello libft");
	snprintf(expected, sizeof(expected), "indice=%d", idx_expected);
	snprintf(actual, sizeof(actual), "indice=%d", idx_actual);
	report_result(&stats, "ft_strnstr", "hay=\"hello libft\", needle=\"libft\", len=11",
		expected, actual, idx_expected == idx_actual);

	ret_expected = atoi("  -42abc");
	ret_actual = ft_atoi("  -42abc");
	snprintf(expected, sizeof(expected), "%d", ret_expected);
	snprintf(actual, sizeof(actual), "%d", ret_actual);
	report_result(&stats, "ft_atoi", "nptr=\"  -42abc\"", expected, actual,
		ret_expected == ret_actual);

	tmp = (char *)calloc(4, 2);
	buf1[0] = '\0';
	if (tmp && all_zero(tmp, 8))
		strcpy(buf1, "memoria zerada");
	else
		strcpy(buf1, "erro");
	free(tmp);
	tmp = (char *)ft_calloc(4, 2);
	buf2[0] = '\0';
	if (tmp && all_zero(tmp, 8))
		strcpy(buf2, "memoria zerada");
	else
		strcpy(buf2, "erro");
	free(tmp);
	report_result(&stats, "ft_calloc", "count=4, size=2", "memoria zerada", buf2,
		strcmp(buf1, buf2) == 0);

	tmp = strdup("libft");
	strcpy(expected, tmp ? tmp : "(null)");
	free(tmp);
	tmp = ft_strdup("libft");
	strcpy(actual, tmp ? tmp : "(null)");
	report_result(&stats, "ft_strdup", "s1=\"libft\"", expected, actual,
		tmp && strcmp(tmp, "libft") == 0);
	free(tmp);

	tmp = ft_strjoin("Hello", "42");
	snprintf(expected, sizeof(expected), "%s", "Hello42");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_strjoin", "s1=\"Hello\", s2=\"42\"", expected,
		actual, tmp && strcmp(tmp, "Hello42") == 0);
	free(tmp);

	tmp = ft_strtrim("***libft***", "*");
	snprintf(expected, sizeof(expected), "%s", "libft");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_strtrim", "s1=\"***libft***\", set=\"*\"",
		expected, actual, tmp && strcmp(tmp, "libft") == 0);
	free(tmp);

	split = ft_split("42|Libft|Tester", '|');
	snprintf(expected, sizeof(expected), "%s", "[42, Libft, Tester]");
	if (split && split[0] && split[1] && split[2] && !split[3])
		snprintf(actual, sizeof(actual), "[%s, %s, %s]", split[0], split[1], split[2]);
	else
		snprintf(actual, sizeof(actual), "%s", "(estrutura invalida)");
	report_result(&stats, "ft_split", "s=\"42|Libft|Tester\", c='|'", expected,
		actual, split && split[0] && split[1] && split[2] && !split[3]
		&& strcmp(split[0], "42") == 0 && strcmp(split[1], "Libft") == 0
		&& strcmp(split[2], "Tester") == 0);
	free_split(split);

	tmp = ft_itoa(-2147483648);
	snprintf(expected, sizeof(expected), "%d", INT_MIN);
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_itoa", "n=INT_MIN", expected, actual,
		tmp && strcmp(tmp, "-2147483648") == 0);
	free(tmp);

	tmp = ft_strmapi("abcdef", map_upper_even);
	snprintf(expected, sizeof(expected), "%s", "AbCdEf");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_strmapi", "s=\"abcdef\", f=upper_even", expected,
		actual, tmp && strcmp(tmp, "AbCdEf") == 0);
	free(tmp);

	strcpy(buf1, "abcdef");
	ft_striteri(buf1, iteri_upper_even);
	snprintf(expected, sizeof(expected), "%s", "AbCdEf");
	snprintf(actual, sizeof(actual), "%s", buf1);
	report_result(&stats, "ft_striteri", "s=\"abcdef\", f=upper_even_inplace",
		expected, actual, strcmp(buf1, "AbCdEf") == 0);

	pc.c = 'Z';
	tmp = capture_fd_output(write_putchar, &pc);
	snprintf(expected, sizeof(expected), "%s", "Z");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_putchar_fd", "c='Z', fd=pipe", expected, actual,
		tmp && strcmp(tmp, "Z") == 0);
	free(tmp);

	ps.s = "Teste";
	tmp = capture_fd_output(write_putstr, &ps);
	snprintf(expected, sizeof(expected), "%s", "Teste");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_putstr_fd", "s=\"Teste\", fd=pipe", expected,
		actual, tmp && strcmp(tmp, "Teste") == 0);
	free(tmp);

	ps.s = "Linha";
	tmp = capture_fd_output(write_putendl, &ps);
	snprintf(expected, sizeof(expected), "%s", "Linha\\n");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_putendl_fd", "s=\"Linha\", fd=pipe", expected,
		actual, tmp && strcmp(tmp, "Linha\n") == 0);
	free(tmp);

	pn.n = -214;
	tmp = capture_fd_output(write_putnbr, &pn);
	snprintf(expected, sizeof(expected), "%s", "-214");
	snprintf(actual, sizeof(actual), "%s", tmp ? tmp : "(null)");
	report_result(&stats, "ft_putnbr_fd", "n=-214, fd=pipe", expected, actual,
		tmp && strcmp(tmp, "-214") == 0);
	free(tmp);

	printf("Resumo: %d/%d testes passaram.\n", stats.passed, stats.total);
	if (stats.passed != stats.total)
		return (1);
	return (0);
}