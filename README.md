# Libft

Implementação em C de uma biblioteca. Esta biblioteca reúne funções de manipulação de caracteres, memória, strings, alocação e saída.

## Descrição

Esta é uma implementação didática das funções básicas que costumam ser usadas em projetos C, seguindo as especificações do projeto `libft`, um projeto de algoritmos. O objetivo é fornecer utilitários reutilizáveis em outros projetos em c e testáveis.

## Conteúdo principal

As funções públicas exportadas (de acordo com `libft.h`) incluem, entre outras:

### Caractere / Classe (ctype)

```
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);
```

### Memória

```
void	*ft_memset(void *ptr, int value, size_t num);
void	ft_bzero(void *ptr, size_t num);
void	*ft_memcpy(void *dest, const void *src, size_t num);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
```

### Strings

```
size_t	ft_strlcpy(char *dest, const char *src, size_t siz);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strrchr(char *str, int search_char);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlen(const char *str);
```

### Conversão / Utilitários

```
int	ft_atoi(const char *nptr);
```

### Saída (file descriptor)

```
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
```

> Observação: Para detalhes completos das assinaturas, consulte `libft.h`.

## Build

O repositório já contém um `Makefile` que compila a biblioteca. Para compilar manualmente a biblioteca (na raiz do repositório):

```bash
make
```

Isto deve gerar a `libft.a` conforme o `Makefile` presente.

## Testes

O repositório inclui uma pasta de testes em `tester/` com um conjunto de testes automatizados.

Para executar os testes de uma função ou de todo o conjunto, entre na pasta `tester` e execute:

```bash
cd tester
make m
```

O comando `make m` roda a suíte de testes preparada (ver `tester/README.md` e `tester/Makefile` para detalhes).

## Estrutura do repositório

- `*.c` : arquivos fonte da biblioteca (implementações).
- `libft.h` : cabeçalho com as assinaturas públicas.
- `Makefile` : regras para compilar a biblioteca.
- `tester/` : contém testes, scripts e Dockerfile para ambientes de teste.
