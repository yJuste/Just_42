/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef JUST_LIB_H
# define JUST_LIB_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// Structure

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//	---------- IS / TO ----------

int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_isprime(int n);
int			ft_ischar(char const *set, char c);

//	---------- ARRAYS ----------

char		**ft_split(const char *s, char c);
char		**ft_split_sep(char *str, char *charset);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_sep(char **strs, char *sep, size_t size);
char		*ft_strdup(const char *s1);

int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_memset(void *b, int c, size_t len);

int			ft_strcmp(const char *s1, const char *s2);
int			ft_strcspn(const char *s, const char *reject);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(char *str, char *to_find);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strcapitalize(char *str);
char		*ft_strlowcase(char *str);
char		*ft_strupcase(char *str);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strspn(const char *s, const char *accept);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

char		*ft_strtrim(char const *s1, char const *set);
const char	*ft_strpbrk(const char *s1, const char *s2);
const char	*ft_findchr(const char *s, int c);
const char	*ft_strtolower(const char *str);

void		ft_swap(int *a, int *b);
void		ft_swap_extra(char **a, char **b);
void		ft_putchar(char c);
void		ft_putstr(char *str);

//	---------- LISTES CHAINEES ----------

int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstprint(t_list *_list);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);

//	---------- CONVERSION ----------

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void		ft_hex(unsigned char c);

//	---------- ALLOCATION ----------

void		ft_bzero(void *s, size_t n);
void		*ft_malloc(size_t size);
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);

//	---------- MATHS ----------

void		ft_dual_digit(int nbr);
void		ft_putnbr(int nbr);
void		ft_putnbr_mini(int nbr);

int			ft_lcm(int a, int b);
int			ft_pgcd(int a, int b);
int			ft_factorial(int nbr);
int			ft_recursive_factorial(int nbr);
int			ft_is_prime(int nbr);
int			ft_find_next_prime(int nbr);
int			ft_iterative_power(int nbr, int power);
int			ft_recursive_power(int nbr, int power);
int			ft_sqrt(int nbr);
float		ft_sqrt_precise(float nbr);

int			*ft_range_up(int start, int end);
int			*ft_range_up_down(int start, int end);
int			*ft_rrange(int start, int end);

//	---------- BASE ----------

int			ft_len(int nbr, int base_len);
int			ft_atoi_base(char *str, char *base);
int			ft_check_base(char *base);
char		*ft_convert_base(char *nbr, char *base_from, char *base_to);
void		ft_putnbr_base(int nbr, char *base);

//	---------- FILE DESCRIPTOR ----------

void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

//	---------- TRANSCENDENTAL FUNCTIONS ----------

char		*ft_get_next_line(int fd);

#endif
