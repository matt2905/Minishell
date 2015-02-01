/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:24:37 by mmartin           #+#    #+#             */
/*   Updated: 2015/02/01 16:27:20 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 512

# include <sys/shm.h>
# include "ft_struct_lib.h"

/*
**		ARRAY
*/

int				*ft_intnew(size_t size);
void			*ft_intzero(int *tab, size_t size);
void			ft_tabdel(char ***tab);
char			**ft_tabdup(char **tab);
size_t			ft_tablen(char **tab);
char			**ft_tabrealloc(char ***tab, char *str, size_t size);

/*
**		CONVERT
*/

double			ft_atof(const char *str);
unsigned int	ft_atoh(const char *str);
int				ft_atoi(const char *str);
unsigned long	ft_atoul(const char *str, int base);
char			*ft_itoa(long int n, size_t sys);
unsigned int	ft_itob(unsigned int n);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_uitoa(long unsigned int n, unsigned sys);

/*
**		DIVERS
*/

int				get_next_line(int const fd, char **line);
int				gnl_serveur(int const sock, char **line);

/*
**		GENERAL
*/

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memset(void *b, int c, size_t len);

/*
**		LIST
*/

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);

/*
**		MATH
*/

int				ft_pow(int n, int pow);

/*
**		REGEX
*/

char			*ft_preg_replace(char *patt, char *replace, char *sub);

/*
**		SHARE
*/

void			ft_semlock(int semid);
void			ft_semsetvalue(int semid, int semnum, int val);
void			ft_semunlock(int semid);
void			*ft_shmalloc(key_t key, int *shmid, size_t size);
void			ft_shmdt(void **shaddr);
void			ft_shmdel(int shmid);

/*
**		STRING
*/

char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *s1);
int				ft_strequ(char const *s1, char const *s2);
char			*ft_strimplode(char **tab);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncasecmp(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
char			*ft_strndup(const char *s1, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			**ft_strsplit_space(char *s);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_xstrjoin(char const *str, ...);
char			*ft_fstrjoin(char *s1, char const *s2);

/*
**		TEST
*/

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_ishexa(int c);
int				ft_islower(int c);
int				ft_isoctale(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isupper(int c);

/*
**		WRITE
*/

void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);

#endif
