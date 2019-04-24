/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uvarly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:35:24 by uvarly            #+#    #+#             */
/*   Updated: 2019/04/17 18:31:24 by uvarly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFF_SIZE 1024

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_strcat(char *dst, const char *app);
char			*ft_strdup(const char *src);
char			*ft_strncat(char *dst, const char *app, size_t n);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strtrim(char const *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char const *haystack, char const *needle, size_t n);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
int				ft_isint(const char *str);
int				ft_isnum(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_lstpresent(t_list *list, char *str);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_numlen(int n);
int				ft_strcmp(const char *str1, const char *str2);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
int				ft_sqrt(int nb);
int				ft_tolower(int c);
int				ft_toupper(int c);

size_t			ft_lstlen(t_list *list);
size_t			ft_strlcat(char *dst, const char *app, size_t size);
size_t			ft_strlen(const char *s);

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *dest, size_t n);
void			ft_lstpushback(t_list **alst, \
								void *content, size_t content_size);
void			ft_lstpushfront(t_list **alst, \
								void *content, size_t content_size);
void			ft_lstprepend(t_list **alst, t_list *new);
void			ft_lstappend(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstfree(t_list **alst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_memdel(void **ap);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_sortinttab(int *table, size_t n);
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

int				get_next_line(const int fd, char **line);

#endif
