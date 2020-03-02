
#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

typedef struct		s_map
{
	int				x;
	int				y;
	int				**z;
}					t_map;

void				count_width_height(char *file, int *width, int *height);
int					map_creating(t_map *map, char *file);
//void				fill_z(char *file, int **numb, int width);

#endif
