/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 08:49:20 by hbretagn          #+#    #+#             */
/*   Updated: 2025/07/24 08:49:24 by hbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# include <unistd.h>

# define TRUE 1

# define FALSE 0

# define EVEN_MSG "I have an even number of arguments."

# define ODD_MSG "I have an odd number of arguments."

# define SUCCESS 1

# define EVEN(nb) (nb%2==0)

typedef int	t_bool;

#endif
