/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:26:44 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/16 16:15:24 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_builtin.h"

static void		ft_free(char **old, char **pwd, char **ptr, char ***tab)
{
	free(*old);
	free(*pwd);
	free(*ptr);
	ft_free_tab(tab);
}

void			ft_modify_pwd(t_data *d)
{
	char	*old;
	char	*pwd;
	char	*ptr;
	char	**tab;

	ptr = ft_getenv_list(d->my_env, "PWD");
	pwd = getcwd(NULL, 0);
	if (!ptr)
		old = ft_strdup(pwd);
	else
		old = ft_strdup(ptr + 4);
	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("PWD");
	tab[2] = ft_strdup(pwd);
	tab[3] = NULL;
	ft_setenv(d, tab);
	free(tab[1]);
	free(tab[2]);
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = ft_strdup(old);
	ft_setenv(d, tab);
	ft_free(&old, &pwd, &ptr, &tab);
}

static t_env	*ft_new_e(char *str)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	new->next = NULL;
	new->tab = str;
	return (new);
}

void			ft_add_env(t_env **env, char *str)
{
	if (*env == NULL)
		*env = ft_new_e(str);
	else
		ft_add_env(&((*env)->next), str);
}
