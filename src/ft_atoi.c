#include "./../include/push_swap.h"

static int	ft_atoi_error(const char *str, int flag)
{
	int		i;

	i = 0;
	while (ft_isdigit(*str))
	{
		str++;
		i++;
	}
	if (i >= 20)
		return (flag);
	return (0);
}

static int	ft_atoi_overflow(unsigned long dest, int flag)
{
	unsigned long	max;

	max = 9223372036854775807;
	if (flag == 1)
	{
		if (dest > max)
			return (-1);
	}
	else if (flag == -1)
	{
		dest -= 1;
		if (dest > max)
			return (1);
	}
	return (0);
}

static unsigned long	ft_atoi_excute(const char *str, unsigned long dest)
{
	while (ft_isdigit(*str))
	{
		if (!(ft_isdigit(*str)))
			break ;
		dest = dest * 10 + *str - '0';
		str++;
	}
	return (dest);
}

long	ft_atoi(const char *str)
{
	unsigned long	dest;
	int				flag;

	dest = 0;
	flag = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		flag = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (ft_atoi_error(str, flag) == 1)
		return (-1);
	else if (ft_atoi_error(str, flag) == -1)
		return (0);
	dest = ft_atoi_excute(str, dest);
	if (ft_atoi_overflow(dest, flag) == -1)
		return (-1);
	else if (ft_atoi_overflow(dest, flag) == 1)
		return (0);
	return ((dest * flag));
}