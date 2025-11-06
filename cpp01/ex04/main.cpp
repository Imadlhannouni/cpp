/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilhannou <ilhannou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:11:09 by ilhannou          #+#    #+#             */
/*   Updated: 2025/11/06 23:15:11 by ilhannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace(std::string text, std::string s1, std::string s2)
{
	std::string newline;

	newline = "";
	for (size_t i = 0; i < text.length(); )
	{
		if (text.substr(i, s1.length()) == s1)
		{
			newline += s2;
			i += s1.length();
		}
		else
		{
			newline += text[i];
			i++;
		}
	}
	return (newline);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	std::string file = argv[1];
	std::ifstream inputFile(file);
	if (inputFile)
	{
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		if (s1.empty())
		{
			std::cout << "arg2 is empty" << std::endl;
			return (1);
		}
		std::string text;
		std::ofstream outputFile(file + ".replace");
		if (!outputFile)
		{
			std::cout << "Error opening file" << std::endl;
			return (1);
		}
		while (std::getline(inputFile, text))
		{
			text = replace(text, s1, s2);
			outputFile << text << std::endl;
		}
		outputFile.close();
	}
	else
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	inputFile.close();
}