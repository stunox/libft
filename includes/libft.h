/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:10:34 by nbasheer          #+#    #+#             */
/*   Updated: 2024/10/13 11:26:12 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// malloc, free, write

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				index;
	struct s_list	*prev;
}					t_list;

int					ft_abs(int n);
int					ft_atoi(const char *str);
long long			ft_atoi_base(char *str, char *base);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				ft_lst_addback(t_list **lst, t_list *new);
void				ft_lst_addfront(t_list **lst, t_list *new);
t_list				*ft_lst_at(t_list *lst, int index);
void				ft_lst_clear(t_list **lst, void (*del)(void *));
void				ft_lst_delone(t_list *lst, void (*del)(void *));
void				ft_lst_iter(t_list *lst, void (*f)(void *));
t_list				*ft_lst_last(t_list *lst);
t_list				*ft_lst_map(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lst_max(t_list *lst);
t_list				*ft_lst_min(t_list *lst);
t_list				*ft_lst_new(void *content);
void				*ft_lst_popback(t_list **lst);
void				*ft_lst_popfront(t_list **lst);
void				ft_lst_reverse(t_list **lst);
t_list				*ft_lst_search(t_list *lst, void *content);
int					ft_lst_search_index(t_list *lst, void *content);
int					ft_lst_size_reverse(t_list *lst);
int					ft_lst_size(t_list *lst);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *ptr, int value, size_t num);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
char				**ft_pop_index(char **tab, int index);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd, int to_free);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd, int to_free);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strrepeat(char *str, int n);
void				ft_strreverse(char *str);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, size_t start, size_t len);
void				**ft_subtab(void **tab, int start, int end);
int					ft_tablen(void *tab);
void				ft_tabreverse(void *tab, int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_replace(char *str, char *replace);
int					ft_printf(const char *format, ...);
char				*get_first_word(char *str);
char				*get_next_line(int fd);
void				*init_mem(int len, int size, char type);
void				*ft_realloc(void *ptr, size_t size);
size_t				ft_memlen(void *ptr);

#endif /* LIBFT_H */