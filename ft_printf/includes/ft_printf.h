/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbasheer <nbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 13:35:10 by nbasheer          #+#    #+#             */
/*   Updated: 2024/11/20 13:32:17 by nbasheer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	int		plus;
	int		space;
	int		hash;
	char	type;
	int		len;
}				t_flags;

typedef struct s_arg
{
	int				len;
	char			c;
	char			*str;
	void			*arg;
	long			nbr;
	char			additional;
}					t_arg;

void	init_flag(t_flags *flag, const char *format, int i);

t_arg	get_strs_arg(t_flags flag, va_list args);
t_arg	get_numbers_arg(t_flags flag, va_list args);
t_arg	get_arg(t_flags flag, va_list args);

void	print_pointer(t_flags flag, t_arg *arg);
void	print_strs(t_flags flag, t_arg *arg);
void	print_numbers(t_flags f, t_arg *a, int z, int sp);
void	print_hex(t_flags flag, t_arg *arg, int zeros, int sp);
void	print_conversion(t_flags flag, t_arg arg, int *ret);

char	*ft_stradd(char *str, char c);

int		nbrlen(long n);
int		nbrlen_hex(unsigned long long n);
void	put_u_nbr(unsigned int num);
int		h_neg(int n);

int		convert(const char *format, int i, va_list args, int *ret);
int		get_len(t_flags flag, t_arg arg);

void	ft_putstr(char *str, int to_free);
void	ft_putnbr(int n);
char	*ft_u_itoa(unsigned int n);
void	ft_putnbr_hex(unsigned long long n, char type);
int		print(const char *format, va_list args, int *ret);

int		max(int a, int b);
int		min(int a, int b);
char	*repeat_char(char c, int count);

int		ft_printf(const char *format, ...);

#endif // FT_PRINTF_H
