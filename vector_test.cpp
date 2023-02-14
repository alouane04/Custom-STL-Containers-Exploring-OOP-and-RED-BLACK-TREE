/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:27:07 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/14 21:27:08 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

int vector_unit_tests()
{
	std::cout << YELLOW << "============================ 1 CONSTRUCTORS =======================" << RESET << std::endl ;
	
	std::cout << "===== Default constructor =====" << std::endl << std::endl;
	
	ft::vector<int> myvector;
	std::vector<int> stdvector;
	
	for (int i = 0; i < 10; i++)
	{
		myvector.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		stdvector.push_back(i);
	}
	
	std::cout << "===== fill constructor =====" << std::endl << std::endl;
	
	ft::vector<int> myvector2(10, 69);
	std::vector<int> stdvector2(10, 69);
	
	std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

	sleep(1);

	std::cout << YELLOW << "============================ 2 Iterators =======================" << RESET << std::endl ;
	
	std::cout << "===== begin =====" << std::endl << std::endl;
	
	ft::vector<int>::iterator ft_it = myvector.begin();
	std::vector<int>::iterator std_it = stdvector.begin();

	std::cout << "the begin of ft_it is: " << *ft_it << std::endl;
	std::cout << "the begin of std_it is: " << *std_it << std::endl;
	
	std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

	sleep(1);

	std::cout << YELLOW << "============================ 3 Size =======================" << RESET << std::endl ;
	
	std::cout << "===== size =====" << std::endl << std::endl;
	
	std::cout << "the size of myvector is: " << myvector.size() << std::endl;
	std::cout << "the size of stdvector is: " << stdvector.size() << std::endl;
	
	std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

	sleep(1);

	std::cout << YELLOW << "============================ 4 - Element access =======================" << RESET << std::endl ;
	
	std::cout << "===== operator[] =====" << std::endl << std::endl;
	
	std::cout << "the element of myvector[2] is: " << myvector[2] << std::endl;
	std::cout << "the element of stdvector[2] is: " << stdvector[2] << std::endl;
	
	std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

return (0);
} 
