#include "./../include/push_swap.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isspace(int c)
{
	c = (char)c;
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

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



int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while ((*str1 != '\0') && i < n - 1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		i++;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}