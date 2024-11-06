/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:06:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/21 23:39:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*void ft_leaks (){
	system("leaks a.out");
}*/

int	main(int argc, char **argv)
{
	t_map	*maps;

	if (argc != 2 || !check_ext(argv[1]))
		error();
	maps = malloc(sizeof(t_map));
	maps->map = read_and_check(argv[1], maps);
	if (maps->map)
	{
		start_game(maps);
	}
	printf("map: %p\n", maps->map);
	printf("t_map: %p\n", maps);
	free_map(maps->map);
	free(maps);
	return (0);
}
