/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:09:23 by ilyanar           #+#    #+#             */
/*   Updated: 2024/11/08 15:40:51 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"
#include <unistd.h>

void		LoopPrompt()
{
	std::string anim = CHARGEPROMPT;
	int			len = anim.length();

	std::cout << std::endl;
	for (int d = 0; d < len; d++)
    {
        std::cout << anim[d] << std::flush;
        usleep(40000);
		std::cout << "\033[D\033[K" << std::flush;
    }
    std::cout << std::endl << " ";
}

bool	IsAlphaString(const std::string &tmp)
{
	for (int d = 0; tmp[d]; d++)
		if (!std::isalpha(tmp[d]))
			return (false);
	return (true);
}

bool	IsNumberFormat(const std::string &str, size_t laine = 10)
{
	if (laine == 10){
		if (str.length() != laine || (str[0] != '0' && str[0] != '+'))
			return (false);
	}
	else
		if (str.length() != laine)
			return (false);
	for (int d = 0; str[d]; d++)
		if (!std::isdigit(str[d]))
			return (false);
	return (true);

}
