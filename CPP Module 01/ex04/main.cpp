/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabr <msabr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 06:48:34 by msabr             #+#    #+#             */
/*   Updated: 2025/09/09 07:01:09 by msabr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static std::string ft_replace(std::string &line, std::string &s1, std::string &s2)
{
	std::string result;
	std::size_t pos;
	std::size_t start;

	if (s1.empty())
		return line;
	start = 0;
	while ((pos = line.find(s1, start)) != std::string::npos)
	{
		result.append(line.substr(start, pos - start));
		result.append(s2);
		start = pos + s1.length();
	}
	result.append(line.substr(start));
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty() || s2.empty() || filename.empty())
	{
		std::cerr << "Error:empty argument" << std::endl;
		return (1);
	}
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}

	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return (1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		output << ft_replace(line, s1, s2);
		if (!file.eof())
			output << std::endl;
	}

	file.close();
	output.close();
	return (0);
}
