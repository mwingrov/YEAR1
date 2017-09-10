/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 11:45:06 by ckatz             #+#    #+#             */
/*   Updated: 2017/09/05 11:33:30 by mwingrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 ** 1: Initialse shell
 ** 2: Read arguements from std::in using get_next_line
 ** 3: Splitting the arguements into array of strings str_split
 ** 4: execute commands based on the first arguement entered
 ** 5: upon completion of preocess exit()
 **
 **
 **
 **
 **
 */

void		check_input(char **args)
{
	if (ft_strcmp(args[0], "echo") == 0)
		ft_putstr("echo works\n");
	else if (ft_strcmp(args[0], "cd") == 0)
		ft_putstr("directory changed\n");
	else	
		ft_putendl(ft_strjoin("zsh: command not found: ", args[0]));
}

void		read_line(char **args, int num_args)
{
	char	*line;
		
	if (get_next_line(0, &line) == 1)
	{	
		if (num_args > 0)
		{ 
			args = ft_strsplit(line, ' ');
			check_input(args);	
		}
		free(args);
	}
}

int			main(int argc, char **argv, char **env)
{	

	while (1)
	{
		ft_putstr("=> ");
		read_line(argv, argc);
	}
	return (0);
}
