/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/24 15:38:56 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int start_parsing(t_cub3d *cub3d)
{
	char	*line;
	int		result;
	int		dir_result;
	//char	*map_line;

	result = EXIT_SUCCESS;

	while ((line = get_next_line(cub3d->fd)))
	{
		line = ft_strtrim(line, " ");
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
		else if (line[0] == '1' || line[0] == '0')
		{
			if (is_map_last(cub3d))
			{
				cub3d->map_1d  = NULL;
				while (line)
				{
					cub3d->map_1d = ft_strjoin(cub3d->map_1d, line);
					free(line);
					line = NULL;
					line = get_next_line(cub3d->fd);
				}
			}
		}
		else
		{
			ft_putendl_fd("\033[0;31m 📛Error Invalid Map 📛\033[0m", 2);
			result = EXIT_FAILURE;
		}
		free(line);
		if (result == EXIT_FAILURE)
			break;
	}
	return (result);
}

// int	start_parsing(t_cub3d *cub3d)
// {
// 	char	*line;

// 	line = get_next_line(cub3d->fd);
// 	while (line)
// 	{
// 		line = ft_strtrim(line, " ");
// 		if (line[0] == '\n')
// 		{
// 			free(line);
// 			line = get_next_line(cub3d->fd);
// 			continue ;
// 		}
// 		if (cardinal_direction(line) == 1)
// 		{
// 			if (parse_direction(cub3d, line) == 1)
// 			{
// 				free(line);			
// 				return (EXIT_FAILURE);
// 			}
// 		}
// 		else if (line[0] == 'F')
// 		{
// 			if (parse_floor_color(cub3d, line, 'F') == 1)
// 			{
// 				free(line);
// 				return (EXIT_FAILURE);
// 			}
// 		}
// 		else if (line[0] == 'C')
// 		{
// 			if (parse_floor_color(cub3d, line, 'C') == 1)
// 			{
// 				free(line);
// 				return (EXIT_FAILURE);
// 			}
// 		}
// 		else if (line[0] == '1' || line[0] == '0')
// 		{
// 			if (is_map_last(cub3d))
// 			{
// 				// printf("map is last\n");
// 			}
// 		}
// 		else
// 		{
// 			ft_putendl_fd("\033[0;31m 📛Error Invalid Map 📛\033[0m", 2);
// 			free(line);
// 			return (EXIT_FAILURE);
// 		}
// 		free(line);
// 		line = get_next_line(cub3d->fd);
// 	}
// 	free(line);
// 	return (EXIT_SUCCESS);
// }