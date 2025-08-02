/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 00:43:54 by msabr             #+#    #+#             */
/*   Updated: 2025/06/29 11:52:14 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
	private:
		Contact contacts[MAX_CONTACTS];
		int total;
		int next;

	public:
		PhoneBook();
		void addContact();
		void searchContact() const;
	};

#endif  // PHONEBOOK_HPP
