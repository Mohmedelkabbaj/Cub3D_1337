/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 11:57:44 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	check_newline(char *map_1d)
{
	int	i;
	
	i = -1;
	while(map_1d[++i])
		if (map_1d[i] == '\n' && map_1d[i + 1] == '\n')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


int start_parsing(t_cub3d *cub3d)
{
	char	*line;
	int		result;
	int		dir_result;

	result = EXIT_SUCCESS;
	while ((line = get_next_line(cub3d->fd)))
	{
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		dir_result = cardinal_direction(line);
		if (dir_result == 1)
			result = parse_direction(cub3d, line);
		else if (line[0] == 'F' || line[0] == 'C')
			result = parse_floor_color(cub3d, line, line[0]);
		else if (is_map(line))
		{
			if (is_map_last(cub3d) == 1)
			{
				cub3d->map_1d  = NULL;
				cub3d->map_2d = NULL;
				if (line[0] != '\n' || line[0] != '\0' || line[0] != '\t' || line[0] != ' ')
				{
					while (line)
					{
						cub3d->map_1d = ft_strjoin(cub3d->map_1d, line);
						free(line);
						line = NULL;
						line = get_next_line(cub3d->fd);
					}
					if (map_check(cub3d) || check_newline(cub3d->map_1d))
						result = EXIT_FAILURE;
				}
				else
					result = EXIT_FAILURE;
			}
			else
				result = EXIT_FAILURE;
		}
		else
			result = EXIT_FAILURE;
		free(line);
		if (result == EXIT_FAILURE)
		{
			ft_putendl_fd("\033[0;31m 📛Error Invalid Map📛 \033[0m", 2);
			break;
		}
	}
	return (result);
}
