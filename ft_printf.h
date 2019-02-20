/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:18:42 by akorol            #+#    #+#             */
/*   Updated: 2019/01/15 15:16:37 by akorol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct		s_nigga
{
	char			*out;
	char const		*conv;
	char			width;
	char			sign;
	char			minus;
	char			plus;
	char			blank;
	int				arg;
	int				invalid;
	int				m_s;
	int				p_s;
	int				percent;
	int				hash;
	int				zero;
	int				dot;
	struct s_nigga	*next;
}					t_nigga;

char				*string_tuning_f(char *buf, char *str, t_nigga **nig);
void				add_sign_f(char *str, t_nigga **nig);
void				buf_tuning_f(char *str, t_nigga **nig);
void				fill_wz_zero(char *str);
char				*join_sign_f(char	*str, t_nigga **nig);
char				*piece_f_shit(char const *str, t_nigga **nig, va_list args);
char				*open_u_conv(t_nigga **nig, va_list args);
char				*conv_u(char *buf, t_nigga **nig, va_list args);
void				sign_func_o(char **buf, char *digits, t_nigga **nig);
void				merging_o(char *dest, char *digits, t_nigga **nig);
char				*open_o_conv(t_nigga **nig, va_list args);
char				*conv_o(char *buf, t_nigga **nig, va_list args);
void				process_piece_p(char const *fmt, t_nigga **nig, va_list args);
void				pick_width(char *fmt, t_nigga **nig);
void				pick_precision(char *fmt, t_nigga **nig);
void			    custom_strcpy(char *str1, char *str2);
void				length_comparator(t_nigga **nig, va_list args);
void				last_piece(char	*fin, t_nigga **nig);
void				process_piece_s(char const *fmt, t_nigga **nig, va_list args);
void				fill2(char *str, int len);
void				pre_tuner(char const **str, t_nigga **nig);
void				align_c(char *buf, t_nigga **nig, va_list args);
void				conversion_c(char *buf, t_nigga **nig, va_list args);
int					separation_vol3(char const *str, t_nigga **nig);
void				separation_vol2(char const * str, int *min, int len);
int				 	separation(char const *str, int len);
char				*process_piece_c(char const *str, t_nigga **nig);
char				*mod_itoa(long long value, t_nigga **nig);
void				exp_digits(char *buf, t_nigga **nig);
void				flag_tuning(t_nigga **nig);
char const			*next(char const *fmt);
void				push(char * dest, char *src);
void				sign_func_1(char **buf, char *digits, t_nigga **nig);
void				sign_func(char **buf, char *digits, t_nigga **nig);
void				sign_func_2(char **buf, char *digits, int len, t_nigga **nig);
void				sign_digits_func(char *dest, char **digits, t_nigga **nig);
void				merging(char *dest, char *digits, t_nigga **nig);
void				minus_flag(char *str, t_nigga **nig);
char				*conversion_d(char *buf, t_nigga **nig, va_list args);
char				*open_d_conversion(t_nigga **nig, va_list args);
t_nigga				*tuner(char const **point, t_nigga **nig, va_list args);
char				*ft_itoa_base(uintmax_t value, int base);
void				customize_flags(char const *s, t_nigga **nig);
void				customize_flags_2(char const *s, int i, t_nigga **lopata);
char const			*customize_string(char const *str, t_nigga **nig);
void				fill_my_nigga(t_nigga **nig);
char const			*double_percent_sign(char const *fmt, t_nigga **nig);
char const			*find_width_digits(char const *str, t_nigga **nig);
char const			*find_precision_digits(char const *str, t_nigga **nig);
int					find_greater(int a, int b);
void				fill_zero(char *buf, int size, int fill);
char				*take_piece(char *point);
char				*create_buffer(int	size);
void				check_min_width(char const *str, t_nigga **nig);
void				check_precision(char const *str, t_nigga **nig);
char				*check_for_size(char const *str, char *p, t_nigga **nig);
int					ft_printf(const char *restrict fmt, ...);
char				*process_piece(char const *str, t_nigga **nig);
void				pick_up_args(va_list args,
		char const *fmt, t_nigga **nig);

#endif
