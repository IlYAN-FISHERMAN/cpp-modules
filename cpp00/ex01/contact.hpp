#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkSecret;
		bool		_statut;
	public:
		Contact(void);
		~Contact(void);
		bool	getStatus() const;
		void	setStatus(const bool stat);
		void	setFirstName(const std::string &str);
		void	setLastName(const std::string &str);
		void	setNickname(const std::string &str);
		void	setPhoneNumber(const std::string &str);
		void	setDarkSecret(const std::string &str);
		void	printPreData(const Contact &contact, int index) const;
		void	printIndexRep(void) const;
};

#endif
