/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:09:12 by ilyanar           #+#    #+#             */
/*   Updated: 2025/02/06 19:11:06 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../class/Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other){(void)other;}

Serializer& Serializer::operator=(const Serializer &other){
	(void)other;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){return (reinterpret_cast<uintptr_t>(ptr));}

Data* Serializer::deserialize(uintptr_t raw){return (reinterpret_cast<Data*>(raw));}
