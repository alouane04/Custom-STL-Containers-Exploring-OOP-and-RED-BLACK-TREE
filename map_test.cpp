/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:26:56 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/14 21:26:57 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

int map_unit_tests()
{
	double ft_start = 0 , ft_end = 0 , std_start = 0 , std_end = 0;
	std::cout << "============================ THE TEST BEGINS  =======================" << std::endl;


	std::cout << YELLOW << "============================ 1 - CONSTRUCTORS =======================" << RESET << std::endl ;

	std::cout << "===== Default constructor =====" << std::endl << std::endl;
		srand(time(NULL));
	
	FT_START;
	ft::map<char , int> ft_first;
		for ( int  i=  0; i < 10 ; i++)
		{
			ft_first.insert(ft::make_pair( 'a' + i ,  rand()% 100));
		}
		for (ft::map<char,int>::iterator it = ft_first.begin() ; it != ft_first.end() ; it++)
		{
			std::cout << CYAN << it->first <<  " => " << it->second << RESET << " |";
		}
		std::cout << std::endl;
	FT_END;

	STD_START;
	std::map<char , int> std_first;
	
		for ( int  i=  0; i < 10 ; i++)
		{
			std_first.insert(std::make_pair( 'a' + i  ,  rand() % 100));
		}
		for (std::map<char,int>::iterator it = std_first.begin(); it != std_first.end(); it++)
		{
			std::cout << MAGENTA << it->first << " => " << it->second  << RESET<< " |";
		}
		std::cout << std::endl;

	STD_END;

	std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
	COMPARE_TIMES;


	std::cout <<   "\n===== Range constructor =====" << std::endl << std::endl;
	FT_START;
	ft::map<char,int> ft_second (ft_first.begin(),ft_first.end());
	FT_END;
	STD_START;
	std::map<char,int> std_second (std_first.begin(),std_first.end());
	STD_END;
	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);

	std::cout << YELLOW << "\n============================ 2 - ITERATORS =======================" << RESET << std::endl ;

	std::cout << "\n===== begin =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int>::iterator ft_it = ft_first.begin() ;
	std::cout << "first element is: " << ft_it->first << " => " << ft_it->second << std::endl;
	FT_END;

	STD_START;
	std::map<char,int>::iterator std_it = std_first.begin() ;
	std::cout << "first element is: " << std_it->first << " => " << std_it->second << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== end =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int>::iterator ft_it_end = ft_first.end();
	ft_it_end--;
	std::cout << "last element is: " << ft_it_end->first << " => " << ft_it_end->second << std::endl;
	FT_END;

	STD_START;
	std::map<char,int>::iterator std_it_end = std_first.end();
	std_it_end--;
	std::cout << "last element is: " << std_it_end->first << " => " << std_it_end->second << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;


	sleep(1);

	std::cout << YELLOW << "\n============================ 3 SIZE =======================" << RESET << std::endl ;

	std::cout << "===== size =====" << std::endl << std::endl;

	FT_START;
	for (char c = 'a'; c <= 'z'; c++)
	{
		ft_first[c] = c;
	}
	std::cout << "ft_first size is :" << ft_first.size() << std::endl;
	FT_END;

	STD_START;
	for (char c = 'a'; c <= 'z'; c++)
	{
		std_first[c] = c;
	}
	std::cout << "std_first size is :" << std_first.size() << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);

	std::cout << YELLOW << "\n============================ 4 - ELEMENT ACCESS =======================" << RESET << std::endl ;

	std::cout << "\n===== operator[] =====" << std::endl << std::endl;

	FT_START;
	ft_first['a'] = 10;
	ft_first['b'] = 30;
	ft_first['c'] = 50;
	ft_first['d'] = 70;
	std::cout << "ft_first['b'] is " << ft_first['b'] << std::endl;
	FT_END;

	STD_START;
	std_first['a'] = 10;
	std_first['b'] = 30;
	std_first['c'] = 50;
	std_first['d'] = 70;
	std::cout << "std_first['b'] is " << std_first['b'] << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== at =====" << std::endl << std::endl;

	FT_START;
	std::cout << "ft_first.at('b') is " << ft_first.at('b') << std::endl;
	FT_END;

	STD_START;
	std::cout << "std_first.at('b') is " << ft_first.at('b') << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);
	std::cout << YELLOW << "\n============================ 5 - MODIFIERS =======================" << RESET << std::endl ;

	std::cout << "\n===== insert =====" << std::endl;

	FT_START;
	std::cout << MAGENTA<< "\n\n== for FT ==" << RESET <<std::endl;

	std::cout << "ft_second before insert contains:" << std::endl;
	
	for (ft::map<char,int>::iterator it=ft_second.begin(); it!=ft_second.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
		
	ft_second.insert (ft::pair<char,int>('*', 69));
	ft_second.insert (ft::pair<char,int>('+',69));
	
	std::cout << "ft_second after insert contains:" << std::endl;
	
	for (ft::map<char,int>::iterator it=ft_second.begin(); it!=ft_second.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	// try to insert a key that already exists
	std::cout << CYAN << "trying to insert the key (+ , 69) that already exists" << RESET << std::endl;

	ft::pair<ft::map<char , int>::iterator , bool> ft_ret;

	ft_ret = ft_second.insert (ft::pair<char,int> ('+', 69));

	if (ft_ret.second == false)
		std::cout << REDD << "+ already existed" <<RESET << std::endl;

	
	FT_END;

	STD_START;
	std::cout << MAGENTA<< "\n\n== for STD ==" << RESET <<std::endl;

	std::cout << "std_second before insert contains:" << std::endl;

	for (std::map<char,int>::iterator it=std_second.begin(); it!=std_second.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	std_second.insert (std::pair<char,int>('*', 69));
	std_second.insert (std::pair<char,int>('+', 69));

	std::cout << "std_second after insert contains:" << std::endl;

	for (std::map<char,int>::iterator it=std_second.begin(); it!=std_second.end(); ++it)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}

	std::cout << CYAN << "trying to insert the key (+ , 69) that already exists" << RESET << std::endl;
	
	std::pair<std::map<char , int>::iterator , bool> std_ret;
	
	std_ret = std_second.insert (std::pair<char,int> ('+', 69));
	
	if (std_ret.second == false)
		std::cout << REDD << "+ already existed" <<RESET << std::endl;
		
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

return (0);
}
