/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin <mmartin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/25 12:26:44 by mmartin           #+#    #+#             */
/*   Updated: 2014/03/27 17:41:02 by mmartin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include "ft_builtin.h"

void			ft_modify_pwd(t_data *d, char *path, int opt)
{
	char		**tab;
	char		*tmp;

	if (opt)
		tmp = getcwd(NULL, 0);
	else
		tmp = ft_strdup(path);
	tab = (char **)malloc(sizeof(char *) * 4);
	tab[0] = ft_strdup("setenv");
	tab[1] = ft_strdup("PWD");
	tab[2] = ft_strdup(tmp);
	tab[3] = NULL;
	ft_setenv(d, tab);
	free(tab[1]);
	free(tab[2]);
	tab[1] = ft_strdup("OLDPWD");
	tab[2] = ft_strdup(d->save_pwd);
	ft_setenv(d, tab);
	ft_free_tab(&tab);
	free(d->save_old);
	d->save_old = ft_strdup(d->save_pwd);
	free(d->save_pwd);
	d->save_pwd = ft_strdup(tmp);
	ft_strdel(&tmp);
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
