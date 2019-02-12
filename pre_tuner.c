
#include "ft_printf.h"

int		take_number(char **str)
{
	int		i;
	int		res;
	char	*buf;

	i = 0;
	while (ft_isdigit((*str)[i]))
		++i;
	buf = ft_strsub(*str, 0, i);
	res = ft_atoi(buf);
	(*str) += i;
	return (res);

}

void	skip_space(char **str, t_nigga **nig)
{
	int		i;
	int		res;

	i = 0;
	while ((*str) && (*str)[i] == ' ')
		++i;
	if ((*str) && ft_isdigit(**str))
		res = take_number(str + i);
	i = 0;
	while ((*str) && (*str)[i] == ' ')
		++i;
	
}

void	pre_tuner(char const **str, t_nigga **nig)
{
	skip_space((char **)str, nig);
}