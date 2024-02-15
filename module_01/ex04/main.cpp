/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdragan <rdragan@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 03:33:53 by rdragan           #+#    #+#             */
/*   Updated: 2023/10/10 14:36:04 by rdragan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	sed(std::string fileName, std::string s1, std::string s2)
{
	std::string	line;
	std::string replaceFileName = fileName + ".replace";

	std::fstream	myFile;
	std::fstream	myReplaceFile;
	size_t			index = 0;

	myFile.open(fileName.c_str(), std::ios::in);
	if (myFile.is_open())
	{
		myReplaceFile.open(replaceFileName.c_str(), std::ios::out);
		if (myReplaceFile.is_open())
		{
			int i = 0;
			while (std::getline(myFile, line))
			{
				index = line.find(s1);
				if (index != std::string::npos)
				{
					line.erase(index, s1.length());
					line.insert(index, s2);
					myReplaceFile << line << std::endl;
				}
				else
					myReplaceFile << line << std::endl;
				i++;
			}
			myReplaceFile.close();
		}
		else
		{
			std::cerr << "You don't have permissions to write to " << replaceFileName << std::endl;
			myFile.close();
			return ;
		}
		std::cout << "Creted " << replaceFileName << std::endl;
		myFile.close();
	}
	else
	{
		std::cerr << "File doesn't exists or you don't have permissions to read from it!" << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		sed(argv[1], argv[2], argv[3]);
	}
	else
	{
		std::cerr << "Invaid arguments!" << std::endl;
	}
	return (0);
}
