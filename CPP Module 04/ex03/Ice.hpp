/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:04:21 by msabr             #+#    #+#             */
/*   Updated: 2025/12/10 17:55:17 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        virtual ~Ice();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif
