
#include "fdf.h"

int		main(int argc,char **argv)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	if (argc != 2)
	{
		write(1, "wrong number of arguments\n", 26);
		return (-1);
	}
	map_creating(map,argv[1]);
	
	int i;
	int j;
	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			printf("%3d", map->z[i][j]);
			j ++;
		}
		printf("\n");
		i++;
	}

	return (0);
}
