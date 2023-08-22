/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 18:59:37 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char	*get_rgb(char *line)
{
	int		i;
	int		j;
	char	*rgb;
	
	i = 0;
	j = 0;
	rgb = (char *)malloc(sizeof(char) * result_length(line) + 1); // 2 ==> comma
	while (line[i])
	{
		if (ft_isdigit(line[i]) || ft_isalpha(line[i]) || line[i] == ',')
		{
			rgb[j] = line[i];
			j++;
		}
		i++;
	}
	rgb[j] = '\0';
	return (rgb);
}

char    *cut_rgb(char *rgb)
{
	if (rgb[0] == 'F' && ft_isdigit(rgb[1]))
		return (ft_substr(rgb, 0 + 1, ft_strlen(rgb) - 0));
	else if (rgb[0] == 'C' && ft_isdigit(rgb[0 + 1]))
	    return (ft_substr(rgb, 0 + 1, ft_strlen(rgb) - 0));
	return (NULL);

}

int	check_rang_rgb(t_cub3d *cub3d, int r, int g, int b, char type)
{
	if (r >= 0 && r <= 255 &&
		g >= 0 && g <= 255 &&
		b >= 0 && b <= 255 && type == 'F')
	{
		cub3d->floor.r = r;
		cub3d->floor.g = g;
		cub3d->floor.b = b;
		return (0);
	}
	else if (r >= 0 && r <= 255 &&
		g >= 0 && g <= 255 &&
		b >= 0 && b <= 255 && type == 'C')
	{
		cub3d->ceiling.r = r;
		cub3d->ceiling.g = g;
		cub3d->ceiling.b = b;
		return (0);
	}
	return (1);
}

void	parse_floor_color(t_cub3d *cub3d, char *line, char type)
{
	char	*rgb;
	char	**split;
	
	rgb = cut_rgb(get_rgb(line));
	if (comma_check(line) != 0 || rgb == NULL)
	{
		ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	split = ft_split(rgb, ',');
	if (split == NULL || check_isdigit(split[0]) != 0 
		|| check_isdigit(split[1]) != 0 || check_isdigit(split[2]) != 0)
	{
		ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	if (check_rang_rgb(cub3d, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]), type) != 0)
	{
		ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
		exit(EXIT_FAILURE);
	}
}
