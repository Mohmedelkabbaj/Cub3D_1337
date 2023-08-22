/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 12:59:59 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	comma_check(char *line)
{
	int		i;
	int		comma;
	int		comma2;
	
	i = 0;
	comma = 0;
	comma2 = 0;

	while (line[i])
	{
		if (line[i] == ',')
		{
			comma++;
			if (line[i + 1] == ',')
				comma2++;
		}
		i++;
	}
	if (comma != 2 || comma2 != 0)
		return (1);
	return (0);
}

int result_length(char *line)
{
	int	i;
	int	count;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || ft_isalpha(line[i]) || line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

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
    // else if (rgb[0] == 'C' && ft_isdigit(rgb[0 + 1]))
    //     return (ft_substr(rgb, 0 + 1, ft_strlen(rgb) - 0));
    return (NULL);

}

int check(char *line)
{
    int i;
    

    i = 0;
    while (line[i])
    {
        
        if (ft_isdigit(line[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

void	parse_floor_color(t_cub3d *cub3d, char *line)
{
	char	**split;
    char    *rgb;
	
	if(comma_check(line) == 0)
	{
        rgb = cut_rgb(get_rgb(line));
        if (rgb != NULL)
        {
            split = ft_split(rgb, ',');
            if (check(split[0]) == 0 && check(split[1])== 0 && check(split[2])== 0)
            {          
                cub3d->floor.r = ft_atoi(split[0]);
                cub3d->floor.g = ft_atoi(split[1]);
                cub3d->floor.b = ft_atoi(split[2]);  
            }
            else
        {
            ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
            exit(EXIT_FAILURE);
        }
        }
        else
        {
            ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
            exit(EXIT_FAILURE);
        }
}
	else
	{
		ft_putendl_fd("\033[0;31m Error Invalid floor color\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	
}