/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/26 21:38:35 by hamaarou         ###   ########.fr       */
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
	rgb = (char *)malloc(sizeof(char) * result_length(line) + 1);
	if (rgb == NULL)
		return (NULL);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
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
	char	*tmp;
	
	if (rgb[0] == 'F' && ft_isdigit(rgb[1]))
	{
		tmp = ft_substr(rgb, 0 + 1, ft_strlen(rgb) - 0);
		return (tmp);
	}
	else if (rgb[0] == 'C' && ft_isdigit(rgb[0 + 1]))
	{
		tmp = ft_substr(rgb, 0 + 1, ft_strlen(rgb) - 0);
	    return (tmp);
	}
		
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

int parse_floor_color(t_cub3d *cub3d, char *line, char type)
{
    char *rgb;
    char **split;
	char *tmp;

	split = NULL;
	line = ft_strtrim(line, " ");
	tmp = get_rgb(line);
	rgb = cut_rgb(tmp);
    if (comma_check(line) != 0 || rgb == NULL)
	{
        ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
        free_rgb(rgb, tmp);
        return (free(line), EXIT_FAILURE);
    }
    split = ft_split(rgb, ',');
    if (split == NULL || check_isdigit(split[0]) != 0 ||
        check_isdigit(split[1]) != 0 || check_isdigit(split[2]) != 0)
	{
		ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
		free_array(split);
		free_rgb(rgb, tmp);
		return (free(line), EXIT_FAILURE);
	}
    if (check_rang_rgb(cub3d, ft_atoi(split[0]), ft_atoi(split[1]), ft_atoi(split[2]), type) != 0)
	{
        ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
        free_array(split);
        free_rgb(rgb, tmp);
        return (free(line), EXIT_FAILURE);
    }
    free_array(split);
    free_rgb(rgb, tmp);
    return (free(line), EXIT_SUCCESS);
}
