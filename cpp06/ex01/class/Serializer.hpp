/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:02:50 by ilyanar           #+#    #+#             */
/*   Updated: 2025/01/08 19:27:07 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
#include <iostream>

typedef struct s_data
{
	int	nb;
} Data;

class Serializer
{
	private:
	public:
		Serializer();
		virtual ~Serializer() = 0;
		Serializer(const Serializer &other);
		Serializer& operator=(const Serializer &other);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
