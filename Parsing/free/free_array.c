/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:01 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 16:28:21 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//free double pointer
void	free_array(char **array)
{
	if (!array)
        return; // If the array is already NULL, nothing to free
    int i = 0;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}