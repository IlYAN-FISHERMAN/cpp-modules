/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:57:44 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/21 17:51:43 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <climits>
#include <iostream>

template <class T>int	easyfind(T content, int nb){
	for (size_t i = 0; content[i]; i++)
		if (content[i] == nb)
			return (nb);
	throw ("No number founded");
	return(0);
}

#endif
