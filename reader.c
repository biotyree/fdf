
#include "fdf.h"

void		count_width_height(char *file, int *width, int *height)
{
	int		i;
	int		fd;
	char	*str;
	int		width_prev;
	
	fd = open(file, O_RDONLY, 0);
	while (get_next_line(fd, &str))
	{
		i = -1;
		width_prev = *width;
		*width = 0;
		while (str[++i])
		{
			if ((str[i] >= '0' && str[i] <= '9') && (str[i + 1] < '0' || str[i + 1] > '9'))
				(*width)++;
			if (str[i + 1] == '\0' || str[i + 1] == '\n')
				break ;
		}
		free (str);
		if(width_prev != *width && width_prev != 0)
		{
			close (fd);
			break ;
		}
		(*height)++;
	}
	free (str);
	close (fd);
}

void		fill_z(char *file, int **numb, int width)
{
	int		j;
	int		i;
	char	**tarr;
	int		fd;
	char	*str;

	fd = open(file, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &str))
	{
		j = 0;
		tarr = ft_strsplit(str, ' ');
		while (j < width)
			numb[i][j++] = ft_atoi(tarr[j]);
		i++;
		free(str);
	}
	free(str);
	close (fd);
}

int			map_creating(t_map *map, char *file)
{
	int i;
	int j;

	map->x = 0;
	map->y = 0;
	count_width_height(file, &(map->x), &(map->y));
	if((map->z = (int **)malloc(sizeof(int*) * (map->x))))
	{
		while (i < map->x)
		{
			if(!(map->z[i++] = (int *)malloc(sizeof(int) * (map->y))))
			{
				while(--i != -1)
					free(map->z[i]);
				free(map->z);
				return (0);
			}
		}
		fill_z(file, map->z, map->x);
		//printf("width - %d, height - %d\n", map->x, map->y);
	}
	return (1);
}