/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/19 17:08:25 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/cub3d.h"

int	fill_textures(char **split, t_cub3d *cub3d)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (split[i])
		i++;
	if (i == 2)
	{
		tmp = ft_strtrim(split[1], " ");
		if (tmp[0] == '.' && tmp[1] == '/')
		{
			if (split[0][0] == 'N' && split[0][1] == 'O')
				cub3d->north_texture = ft_strdup(tmp);
			else if (split[0][0] == 'S' && split[0][1] == 'O')
				cub3d->south_texture = ft_strdup(tmp);
			else if (split[0][0] == 'E' && split[0][1] == 'A')
				cub3d->east_texture = ft_strdup(tmp);
			else if (split[0][0] == 'W' && split[0][1] == 'E')
				cub3d->west_texture = ft_strdup(tmp);
			else
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

void    parse_direction(t_cub3d *cub3d, char *line)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i == 1)
	{
		if (fill_textures(split, cub3d) == 1)
			exit(EXIT_FAILURE);
	}
	else
		ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
}

void	start_parsing(t_cub3d *cub3d)
{
	char	*line;

	line = get_next_line(cub3d->fd);
	while (line)
	{
		line = ft_strtrim(line, " ");
		if (cardinal_direction(line) != -1)
			parse_direction(cub3d, line);
		else if (line[0] == 'F')
			parse_floor_color(cub3d, line);
		else if (line[0] == 'C')
			parse_ceiling_color(cub3d, line);
		else if (line[0] == '1' || line[0] == '0')
			parse_map(cub3d, line);
		else
			ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);/

		line = get_next_line(cub3d->fd);
	}
}