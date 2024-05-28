/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungryk <seungryk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:53:23 by seungryk          #+#    #+#             */
/*   Updated: 2024/02/13 10:08:48 by seungryk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LEN 16

typedef struct s_flag
{
	int		width;
	int		minus;
	int		zero;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus_sign;
	int		minus_sign;
	int		type_len;
	char	type;
	void	*arg;
}				t_flag;

typedef struct s_write
{
	char	*ret;
	int		len;
	int		idx;
}				t_write;

/* ft_printf.c */
int			ft_printf(const char *s, ...);

/* ft_flag.c */
int			check_type(char c);
int			get_type_len(t_flag *op, char c, va_list ap);
int			check_first_flag(char c, t_flag *op);
int			get_len(const char *s, t_flag *op, char flag);
int			get_flag(const char *s, t_flag *op, va_list ap);

/* ft_write_printf.c */
void		get_zero(t_write *buf, t_flag *op);
char		*ft_argcpy(char c, t_write *buf, t_flag *op);
int			write_buf(t_flag *op, t_write *buf);

/* ft_flag_info.c */
void		get_prefix(t_write *buf, t_flag *op);
char		*get_argument(t_write *buf, t_flag *op);

/* ft_padding.c */
void		get_left_padding(t_write *buf, t_flag *op);
void		get_right_padding(t_write *buf, t_flag *op);

/* ft_printf_utils.c */
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_strset(char *dest, char c, int len);
int			ft_strncpy(char *dest, char *src, int len);
char		*ft_char(int c);

/* ft_len_info.c */
int			find_len(t_flag *op);

/* ft_init_free.c */
t_flag		*init_op(void);
t_write		*init_write(void);
int			free_op(t_flag **op);
int			free_buf(t_write **buf);
void		*ft_free(char *s);
#endif