/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:44:09 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 03:19:02 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# define MAX_CONTACTS 8
# define MAX_CASES 10

# include <iostream>
# include <iomanip>
# include <string>

class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void	setInfo();
		void	displayFull() const;
		void	displayRow(int row) const;
};

#endif // CONTACT_HPP
