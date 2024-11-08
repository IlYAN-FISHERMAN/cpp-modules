/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfunction.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:11:27 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/08 14:14:15 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

bool Contact::getStatus() const{ return (this->_statut); }
