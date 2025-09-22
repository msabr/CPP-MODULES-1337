/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 08:42:43 by msabr             #+#    #+#             */
/*   Updated: 2025/09/22 20:22:20 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : rawBits(0) {
}

Fixed::Fixed(const int intValue) {
	this->rawBits = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	this->rawBits = static_cast<int>(roundf(floatValue * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other){
	*this = other;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits() const {
	return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->rawBits) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->rawBits = other.getRawBits();
	}
	return *this;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->rawBits < other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->rawBits <= other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const {
	return this->rawBits > other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->rawBits >= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
	return this->rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->rawBits != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.getRawBits() != 0)
		return Fixed(this->toFloat() / other.toFloat());
		return Fixed(0);
}

Fixed& Fixed::operator++() { // Prefix increment
	this->rawBits++;
	return *this;
}

Fixed Fixed::operator++(int) { // Postfix increment
	Fixed temp = *this;
	this->rawBits++;
	return temp;
}

Fixed& Fixed::operator--() { // Prefix decrement
	this->rawBits--;
	return *this;
}

Fixed Fixed::operator--(int) { // Postfix decrement
	Fixed temp = *this;
	this->rawBits--;
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
