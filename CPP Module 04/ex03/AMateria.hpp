/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 21:58:46 by msabr             #+#    #+#             */
/*   Updated: 2025/12/10 19:02:48 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const AMateria& other);
        AMateria(std::string const &type);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();

        std::string const & getType() const; // Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif