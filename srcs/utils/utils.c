
#include "../../include/cub3d.h"

int ft_check_name(char *name)
{
	if (ft_strlen(name) > 4)
		if (ft_strnstr(&name[ft_strlen(name) - 4], ".cub", 4))
			return (1);
	return (0);
}

char	*ft_subst(char *str, int s, int l, int flag)
{
	int		i;
	int		k;
	char	*res;

	if (ft_strle(str, '\0') < (s + l))
		l = ft_strle(str, '\0') - s;
	res = malloc((sizeof(char) * (l + 1)));
	k = 0;
	if (s >= 0 && (ft_strle((char *)str, '\0') > s))
	{
		i = s;
		while (str[i] && k < l)
			res[k++] = str[i++];
		res[k] = '\0';
		if (flag == 1)
			free(str);
		return (res);
	}
	res[k] = '\0';
	if (flag == 1)
		free(str);
	return (res);
}

void	clear_arr(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

int	ft_isdigit_char(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i])) == -1)
			return (0);
		i++;
	}
	return (1);
}

void	clear_and_exit(t_data *data)
{
	if (data->map)
	{
		if (data->map->map)
			clear_arr(data->map->map);
		if (data->map->we)
			free(data->map->we);
		if (data->map->no)
			free(data->map->no);
		if (data->map->ea)
			free(data->map->ea);
		if (data->map->so)
			free(data->map->so);
		free(data->map);
	}
	free(data);
	printf("GOOD BYE, MY FRIEND! I WILL MISS YOU!\n");
	exit (1);

}