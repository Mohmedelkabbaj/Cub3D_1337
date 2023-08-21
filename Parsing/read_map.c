/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/21 15:37:38 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cub3d.h"

int	fill_textures(char **split, t_cub3d *cub3d)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
		i++;
	if (i == 2)
	{
		tmp = ft_strtrim(split[1], " ");
		if (tmp[0] == '.' && tmp[1] == '/')
		{
			if (split[0][0] == 'N' && split[0][1] == 'O')
				cub3d->parse_direct.north_texture = ft_strdup(tmp);
			else if (split[0][0] == 'S' && split[0][1] == 'O')
				cub3d->parse_direct.south_texture = ft_strdup(tmp);
			else if (split[0][0] == 'E' && split[0][1] == 'A')
				cub3d->parse_direct.east_texture = ft_strdup(tmp);
			else if (split[0][0] == 'W' && split[0][1] == 'E')
				cub3d->parse_direct.west_texture = ft_strdup(tmp);
			else
			
			{
				printf("Naaaaaaaaaaaaaaaaaaaaaaa\n");
				return (1);
			}
			free(tmp);
		}
		else
			return (free(tmp), 1);
	}
	else
		return (1);
	return (0);
}

//free double pointer
void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void    parse_direction(t_cub3d *cub3d, char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i == 2)
	{
		split[1] = ft_strtrim(split[1], "\n");
		if (fill_textures(split, cub3d) == 1)
		{
			free_array(split);
			ft_putendl_fd("\033[0;31m Error Invalid Textures\033[0m", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		free_array(split);
		ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
		exit(EXIT_FAILURE);
		
	}
}

void	start_parsing(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	while (line)
	{
		
		line = ft_strtrim(line, " ");
		if (cardinal_direction(line))
		{
			parse_direction(cub3d, line);
			free(line);
		}
		// else if (line[0] == 'F')
		// 	parse_floor_color(cub3d, line);
		// else if (line[0] == 'C')
		// 	parse_ceiling_color(cub3d, line);
		// else if (line[0] == '1' || line[0] == '0')
		// 	parse_map(cub3d, line);
		// else
		// {
			// ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
			// exit(EXIT_FAILURE);
		// }

		line = get_next_line(cub3d->fd);
	}
}