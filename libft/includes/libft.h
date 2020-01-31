/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcenamor <rcenamor@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:33:10 by rcenamor          #+#    #+#             */
/*   Updated: 2020/01/31 15:03:53 by rcenamor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define INTMIN -2147483648
# define INTMAX 2147483647
# define UINTMAX 4294967295
# define LONGMIN -9223372036854775808
# define LONGMAX 9223372036854775807
# define ULONGMAX 18446744073709551615
# define INTMIN_S "-2147483648"
# define INTMAX_S "2147483647"
# define UINTMAX_S "4294967295"
# define LONGMIN_S "-9223372036854775808"
# define LONGMAX_S "9223372036854775807"
# define ULONGMAX_S "18446744073709551615"

# define BUFF_SIZE 1000
# define FD_LIMIT 4864
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	ssize_t		x;
	ssize_t		y;
}					t_point;

/*
** PART 1: Libc functions
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c,
		size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_sqrt(int nb);

/*
** PART 2: Additional functions
*/

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** PART 3: Bonus functions
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** PART 4: Extra functions
*/

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_ispunct(int c);
int					ft_isspace(int c);
int					ft_isgraph(int c);
int					ft_isxdigit(int c);
int					ft_count_digits(int n);
int					ft_abs(int i);
void				ft_strdel_2d(char **s2d);
int					get_next_line(const int fd, char **line);
char				*ft_strtrimc(char const *s, char c);
char				*ft_strnewc(size_t size, char c);
void				ft_putstr_2d(char **s2d);
void				ft_putnbr_array(int	*array, size_t len);
void				ft_set_point(t_point *point, ssize_t x, ssize_t y);
void				ft_set_point_grid(t_point *point, size_t position,
		size_t width);
int					*ft_arrnew(size_t len);
void				ft_arrdel(int **as);
int					*ft_arrnew_i(size_t len);
void				ft_arrpermut(int *arr, unsigned int len,
		unsigned long permuts, unsigned long permut);
void				ft_arrsort(int *arr, unsigned int len);
void				ft_arrsort_i(int *arr, unsigned int len,
		unsigned int start);
void				ft_swap(int *a, int *b);
unsigned long		ft_factorial(unsigned long nbr);
int					ft_file_line_count(int fd);
void				ft_puterr(char *msg, int err);
int					ft_count_words(char *str);
int					ft_len_count(char *str, int i);
char				**ft_split_whitespaces(char *str);

#endif
