/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:56:43 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/13 15:08:25 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "map.hpp"

#include <sys/time.h>
#include <thread>
#include <unistd.h>
#include <__tree>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>



int map_unit_tests();
int set_unit_tests();
int stack_unit_tests();
int vector_unit_tests();

void compare_times(double first, double second);
void loading();

template <typename T>
void print_content(T& container) {
  for (typename T::iterator it=container.begin(); it!=container.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << std::endl;
}


#define CONTENT(X) print_content(X)

#define LOAD loading();

#define COMPARE_TIMES compare_times(ft_start - ft_end, std_start - std_end);

#define PRINT(...) std::cout, L_CYAN, __VA_ARGS__, RESET, "\n"


#define PRINT(...) std::cout, L_CYAN, __VA_ARGS__, RESET, "\n"



#define billboard " ██████╗ ██████╗ ███╗   ██╗████████╗ ██████╗ ███╗   ██╗██╗██████╗ ███████╗\n██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔═══██╗████╗  ██║██║██╔══██╗╚══███╔╝\n██║     ██║   ██║██╔██╗ ██║   ██║   ██║   ██║██╔██╗ ██║██║██████╔╝  ███╔╝ \n██║     ██║   ██║██║╚██╗██║   ██║   ██║   ██║██║╚██╗██║██║██╔══██╗ ███╔╝  \n╚██████╗╚██████╔╝██║ ╚████║   ██║   ╚██████╔╝██║ ╚████║██║██║  ██║███████╗ \n╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝    ╚═════╝ ╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝╚══════╝\n                                                                          "

#define L_CYAN "\033[1;96m"
#define REDD "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"

#define FT_START ft_start = clock();
#define FT_END  ft_end = clock();
#define STD_START std_start = clock();
#define STD_END  std_end = clock();

void loading()
{
    std::cout <<YELLOW << "loading: ";
    std::string points= "...";
    for (int i = 0; i < 3; i++)
    {
        std::cout << points.substr(0, i %3);
        std::cout.flush();
        sleep(1);
    }
    std::cout << RESET <<  std::endl;
}

void compare_times(double first, double second)
{
    std::string result;
    double ratio = first / second;
    if (ratio > 1)
        result = "FT is " + std::to_string(ratio) + " times faster than STD";
    else if (ratio < 1)
        result = "STD is " + std::to_string(1 / ratio) + " times faster than FT";
    else
        result = "both are equal";
    std::cout<< BLUE << result << RESET << std::endl;
}


int map_unit_tests()
{
	double ft_start = 0 , ft_end = 0 , std_start = 0 , std_end = 0;
	std::cout << "============================ THE TEST BEGINS  =======================" << std::endl;


	std::cout << YELLOW << "============================ 1 - CONSTRUCTORS =======================" << RESET << std::endl ;

	std::cout << "===== Default constructor =====" << std::endl << std::endl;
		srand(time(NULL)); // random seed to generate random numbers the does not repeat
	
		FT_START;
	ft::map<char , int> ft_first;
	for ( int  i=  0; i < 10 ; i++) { ft_first.insert(ft::make_pair( 'a' + i ,  rand()% 100));}
	for(ft::map<char,int>::iterator it = ft_first.begin() ; it != ft_first.end() ; it++) 
		std::cout << CYAN << it->first <<  " => " << it->second << RESET << " |";
	std::cout << std::endl;
	FT_END;

	STD_START;
	std::map<char , int> std_first;
	
		for ( int  i=  0; i < 10 ; i++) { std_first.insert(std::make_pair( 'a' + i  ,  rand() % 100));}
		for (std::map<char,int>::iterator it = std_first.begin(); it != std_first.end(); it++)
			std::cout << MAGENTA << it->first << " => " << it->second  << RESET<< " |";
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

	std::cout << "\n===== Copy constructor =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int> ft_third (ft_second);
	FT_END;

	STD_START;
	std::map<char,int> std_third (std_second);
	STD_END;
	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== assignement operator =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int> ft_fourth;
	ft_fourth = ft_second;
	FT_END;

	STD_START;
	std::map<char,int> std_fourth;
	std_fourth = std_second;
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


	std::cout << "\n===== rbegin =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int>::reverse_iterator ft_rit = ft_first.rbegin() ;
	std::cout << "first element is: " << ft_rit->first << " => " << ft_rit->second << std::endl;
	FT_END;

	STD_START;
	std::map<char,int>::reverse_iterator std_rit = std_first.rbegin() ;
	std::cout << "first element is: " << std_rit->first << " => " << std_rit->second << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== rend =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int>::reverse_iterator ft_rit_end = ft_first.rend();
	ft_rit_end--;
	std::cout << "last element is: " << ft_rit_end->first << " => " << ft_rit_end->second << std::endl;
	FT_END;

	STD_START;
	std::map<char,int>::reverse_iterator std_rit_end = std_first.rend();
	std_rit_end--;
	std::cout << "last element is: " << std_rit_end->first << " => " << std_rit_end->second << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);
	std::cout << YELLOW << "\n============================ 3 - CAPACITY/SIZE AND RELATED STUFF =======================" << RESET << std::endl ;

	std::cout << "\n===== empty =====" << std::endl << std::endl;

	FT_START;
	ft_first.clear();
	std::cout << "ft_first is " << (ft_first.empty() ? "empty" : "not empty") << std::endl;
	FT_END;

	STD_START;
	std_first.clear();
	std::cout << "std_first is " << (std_first.empty() ? "empty" : "not empty") << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== size =====" << std::endl << std::endl;

	FT_START;
	for (char c='a'; c<='z'; c++) {ft_first[c]=c;}
	std::cout << "ft_first size is :" << ft_first.size() << std::endl;
	FT_END;

	STD_START;
	for (char c='a'; c<='z'; c++) {std_first[c]=c;}
	std::cout << "std_first size is :" << std_first.size() << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== max_size =====" << std::endl << std::endl;

	FT_START;
	std::cout << "ft_first max_size is :" << ft_first.max_size() << std::endl;
	FT_END;

	STD_START;
	std::cout << "std_first max_size is :" << std_first.max_size() << std::endl;
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
		std::cout << it->first << " => " << it->second << std::endl;
	ft_second.insert ( ft::pair<char,int>('*',69) );
	ft_second.insert ( ft::pair<char,int>('+',69) );
	std::cout << "ft_second after insert contains:" << std::endl;
	for (ft::map<char,int>::iterator it=ft_second.begin(); it!=ft_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

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
		std::cout << it->first << " => " << it->second << std::endl;
	std_second.insert ( std::pair<char,int>('*',69) );
	std_second.insert ( std::pair<char,int>('+',69) );
	std::cout << "std_second after insert contains:" << std::endl;
	for (std::map<char,int>::iterator it=std_second.begin(); it!=std_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << CYAN << "trying to insert the key (+ , 69) that already exists" << RESET << std::endl;
	std::pair<std::map<char , int>::iterator , bool> std_ret;
	std_ret = std_second.insert (std::pair<char,int> ('+', 69));
	if (std_ret.second == false)
		std::cout << REDD << "+ already existed" <<RESET << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;


	std::cout << "\n===== erase =====" << std::endl << std::endl;

	FT_START;
	std::cout << "ft_second before erase contains:" << std::endl;
	for (ft::map<char,int>::iterator it=ft_second.begin(); it!=ft_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	ft_it = ft_second.begin();
	ft_second.erase (ft_it); // erasing by iterator
	ft_second.erase ('+'); // erasing by key
	std::cout << "elements erased" << std::endl;
	std::cout << "ft_second after erase contains:" << std::endl;
	for (ft::map<char,int>::iterator it=ft_second.begin(); it!=ft_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	FT_END;

	STD_START;
	std::cout << "std_second before erase contains:" << std::endl;
	for (std::map<char,int>::iterator it=std_second.begin(); it!=std_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std_it = std_second.begin();
	std_second.erase (std_it); // erasing by iterator
	std_second.erase ('+'); // erasing by key
	std::cout << "elements erased" << std::endl;
	std::cout << "std_second after erase contains:" << std::endl;
	for (std::map<char,int>::iterator it=std_second.begin(); it!=std_second.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== swap =====" << std::endl << std::endl;

	std::cout << MAGENTA<< "== for FT ==" << RESET <<std::endl;
	FT_START;
	ft_first.clear();
	ft_second.clear();
	for (char c='a'; c<='f'; c++) {ft_first[c]=c;}
	for (int i = 0 ; i < 10 ; i++) {ft_second[i]=i;}
	
	std::cout << "ft_first contains:" << std::endl;
	for (ft_it=ft_first.begin(); ft_it!=ft_first.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << " |	" ;
	std::cout << "\nft_second contains:" << std::endl;
	for (ft_it=ft_second.begin(); ft_it!=ft_second.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << " |	" ;

	ft_first.swap(ft_second);

	std::cout << "\n\nft_first contains:" << std::endl;
	for (ft_it=ft_first.begin(); ft_it!=ft_first.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << " |	" ;
	std::cout << "\nft_second contains:" << std::endl;
	for (ft_it=ft_second.begin(); ft_it!=ft_second.end(); ++ft_it)
		std::cout << ft_it->first << " => " << ft_it->second << " |	" ;

	FT_END;


	std::cout << MAGENTA<< "\n\n== for STD ==" << RESET <<std::endl;

	STD_START;
	std_first.clear();
	std_second.clear();
	for (char c='a'; c<='f'; c++) {std_first[c]=c;}
	for (int i = 0 ; i < 10 ; i++) {std_second[i]=i;}

	std::cout << "\nstd_first contains:" << std::endl;
	for (std_it=std_first.begin(); std_it!=std_first.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << " |	" ;
	std::cout << "\nstd_second contains:" << std::endl;
	for (std_it=std_second.begin(); std_it!=std_second.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << " |	" ;
	
	std_first.swap(std_second);

	std::cout << "\n\nstd_first contains:" << std::endl;
	for (std_it=std_first.begin(); std_it!=std_first.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << " |	" ;
	std::cout << "\nstd_second contains:" << std::endl;
	for (std_it=std_second.begin(); std_it!=std_second.end(); ++std_it)
		std::cout << std_it->first << " => " << std_it->second << " |	" ;
	
	STD_END;

	std::cout << GREEN << "\n===== OK ====="  << std::endl;
	COMPARE_TIMES;


	std::cout << "\n===== clear =====" << std::endl << std::endl;

	FT_START;
	ft_first.clear();
	ft_second.clear();
	std::cout << "containers cleared" << std::endl;
	FT_END;

	STD_START;
	std_first.clear();
	std_second.clear();
	std::cout << "containers cleared" << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	std::cout << "\n===== find =====" << std::endl << std::endl;

	FT_START;
	for (char c='a'; c<='z'; c++) {ft_first[c]=c;}
	ft_it = ft_first.find('z');
	if (ft_it != ft_first.end())
		std::cout << "element found: " << ft_it->first << " => " << ft_it->second << std::endl;
	else
		std::cout << "element not found" << std::endl;
	FT_END;

	STD_START;
	for (char c='a'; c<='z'; c++) {std_first[c]=c;}
	std_it = std_first.find('z');
	if (std_it != std_first.end())
		std::cout << "element found: " << std_it->first << " => " << std_it->second << std::endl;
	else
		std::cout << "element not found" << std::endl;

	STD_END;
	
	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;


	std::cout << "\n===== count =====" << std::endl << std::endl;

	FT_START;
	for (char c='a'; c<='z'; c++) {ft_first[c]=c;}
	std::cout << "ft_first contains " << ft_first.count('z') << " elements with key 'z'" << std::endl;
	FT_END;

	STD_START;
	for (char c='a'; c<='z'; c++) {std_first[c]=c;}
	std::cout << "std_first contains " << std_first.count('z') << " elements with key 'z'" << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;


	std::cout << "\n===== lower_bound =====" << std::endl << std::endl;

	FT_START;
	for (char c='a'; c<='z'; c++) {ft_first[c]=c;}
	ft_it = ft_first.lower_bound('z');
	if (ft_it != ft_first.end())
		std::cout << "lower bound found: " << ft_it->first << " => " << ft_it->second << std::endl;
	else
		std::cout << "lower bound not found" << std::endl;
	FT_END;

	STD_START;
	for (char c='a'; c<='z'; c++) {std_first[c]=c;}
	std_it = std_first.lower_bound('z');
	if (std_it != std_first.end())
		std::cout << "lower bound found: " << std_it->first << " => " << std_it->second << std::endl;
	else
		std::cout << "lower bound not found" << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;


	std::cout << "\n===== upper bound =====" << std::endl << std::endl;

	FT_START;
	for (char c='a'; c<='z'; c++) {ft_first[c]=c;}
	ft_it = ft_first.upper_bound('z');
	if (ft_it != ft_first.end())
		std::cout << "upper bound found: " << ft_it->first << " => " << ft_it->second << std::endl;
	else
		std::cout << "upper bound not found" << std::endl;
	FT_END;

	STD_START;
	for (char c='a'; c<='z'; c++) {std_first[c]=c;}
	std_it = std_first.upper_bound('z');
	if (std_it != std_first.end())
		std::cout << "upper bound found: " << std_it->first << " => " << std_it->second << std::endl;
	else
		std::cout << "upper bound not found" << std::endl;
	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);
	std::cout << YELLOW << "\n============================ 6 - EQUAL_RANGE =======================" << RESET << std::endl ;

 	
	std::cout << MAGENTA<< "\n\n== for FT ==" << RESET <<std::endl;

	FT_START;

	ft::map<char,int> ft_equal_range_map;

	ft_equal_range_map['a']=10;
	ft_equal_range_map['b']=20;
	ft_equal_range_map['c']=30;

	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = ft_equal_range_map.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';

	FT_END;
 
	std::cout << std::endl;

	std::cout << MAGENTA<< "\n\n== for STD ==" << RESET <<std::endl;
	STD_START;

	std::map<char,int> std_equal_range_map;

	std_equal_range_map['a']=10;
	std_equal_range_map['b']=20;
	std_equal_range_map['c']=30;

	std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret2;
	ret2 = std_equal_range_map.equal_range('b');
	
	std::cout << "lower bound points to: ";
	std::cout << ret2.first->first << " => " << ret2.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret2.second->first << " => " << ret2.second->second << '\n';

	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES;

	sleep(1);
	std::cout << YELLOW << "\n============================ 7 - OBSERVERS =======================" << RESET << std::endl ;

	std::cout << "\n===== key_comp =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int> ft_first2;
	ft::map<char,int>::key_compare ft_comp = ft_first2.key_comp();
	for (char c='a'; c<='z'; c++) {ft_first2[c]=c;}
	std::cout << "ft_first2 contains:";
	char ft_highest = ft_first2.rbegin()->first;     // key value of last element
	ft::map<char,int>::iterator ft_it2 = ft_first2.begin();
	do {
		std::cout << " " << ft_it2->first << ":" << ft_it2->second;
	} while ( ft_comp((*ft_it2++).first, ft_highest) );
	std::cout << std::endl;
	FT_END;

	STD_START;
	std::map<char,int> std_first2;
	std::map<char,int>::key_compare std_comp = std_first2.key_comp();
	for (char c='a'; c<='z'; c++) {std_first2[c]=c;}
	std::cout << "std_first2 contains:";
	char std_highest = std_first2.rbegin()->first;     // key value of last element
	std::map<char,int>::iterator std_it2 = std_first2.begin();
	do {
		std::cout << " " << std_it2->first << ":" << std_it2->second;
	} while ( std_comp((*std_it2++).first, std_highest) );

	std::cout << std::endl;
	STD_END;
	
	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES






	std::cout << "\n===== value_comp =====" << std::endl << std::endl;

	FT_START;
	ft::map<char,int> ft_first3;
	ft::map<char,int>::value_compare ft_comp2 = ft_first3.value_comp();
	for (char c='a'; c<='z'; c++) {ft_first3[c]=c;}
	std::cout << "ft_first3 contains:";
	ft::pair<char,int> ft_highest2 = *ft_first3.rbegin();          // last element
	ft::map<char,int>::iterator ft_it3 = ft_first3.begin();
	do {
		std::cout << " " << ft_it3->first << ":" << ft_it3->second;
	} while ( ft_comp2(*ft_it3++, ft_highest2) );
	std::cout << std::endl;
	FT_END;

	STD_START;
	std::map<char,int> std_first3;
	std::map<char,int>::value_compare std_comp2 = std_first3.value_comp();
	for (char c='a'; c<='z'; c++) {std_first3[c]=c;}
	std::cout << "std_first3 contains:";
	std::pair<char,int> std_highest2 = *std_first3.rbegin();          // last element
	std::map<char,int>::iterator std_it3 = std_first3.begin();
	do {
		std::cout << " " << std_it3->first << ":" << std_it3->second;
	} while ( std_comp2(*std_it3++, std_highest2) );
	std::cout << std::endl;
	STD_END;
	
	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES

	sleep(1);
	std::cout << YELLOW << "\n============================ 8 - COMPARAISON =======================" << RESET << std::endl ;

	std::cout << MAGENTA<< "\n\n== for FT ==" << RESET <<std::endl;

	FT_START;
	ft::map<char,int> ft_first4;
	ft::map<char,int> ft_second4;
	ft_first4['a']=10;
	ft_first4['b']=20;
	ft_first4['c']=30;
	ft_second4['a']=10;
	ft_second4['b']=20;
	ft_second4['c']=30;
	std::cout << "ft_first4 == ft_second4 ";
	(ft_first4==ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "ft_first4 != ft_second4 ";
	(ft_first4!=ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "ft_first4 < ft_second4 ";
	(ft_first4<ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "ft_first4 > ft_second4 ";
	(ft_first4>ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "ft_first4 <= ft_second4 ";
	(ft_first4<=ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "ft_first4 >= ft_second4 ";
	(ft_first4>=ft_second4) ? std::cout << ": True\n" : std::cout << ": False\n";
	FT_END;

	std::cout << MAGENTA<< "\n\n== for STD ==" << RESET <<std::endl;

	STD_START;
	std::map<char,int> std_first4;
	std::map<char,int> std_second4;
	std_first4['a']=10;
	std_first4['b']=20;
	std_first4['c']=30;
	std_second4['a']=10;
	std_second4['b']=20;
	std_second4['c']=30;

	std::cout << "std_first4 == std_second4 ";
	(std_first4==std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "std_first4 != std_second4 ";
	(std_first4!=std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "std_first4 < std_second4 ";
	(std_first4<std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "std_first4 > std_second4 ";
	(std_first4>std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "std_first4 <= std_second4 ";
	(std_first4<=std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	std::cout << "std_first4 >= std_second4 ";
	(std_first4>=std_second4) ? std::cout << ": True\n" : std::cout << ": False\n";

	STD_END;

	std::cout << GREEN << "===== OK ====="  << std::endl;
	COMPARE_TIMES
	
return (0);
}

int set_unit_tests()
{

double ft_start , ft_end , std_start , std_end ;

std::cout << "============================ THE TEST BEGINS  =======================" << std::endl;

std::cout << YELLOW << "============================ 1 - CONSTRUCTORS =======================" << RESET << std::endl ;

std::cout << "===== Default constructor =====" << std::endl << std::endl;

FT_START;
ft::set<int> ft_set;
for(int i = 0; i < 10; i++) {ft_set.insert(i);}
FT_END;

STD_START;
std::set<int> std_set;
for(int i = 0; i < 10; i++) {std_set.insert(i);}
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== Range constructor =====" << std::endl << std::endl;

FT_START;
ft::set<int> ft_set2(ft_set.begin(), ft_set.end());
FT_END;

STD_START;
std::set<int> std_set2(std_set.begin(), std_set.end());
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== Copy constructor =====" << std::endl << std::endl;

FT_START;
ft::set<int> ft_set3(ft_set2);
FT_END;

STD_START;
std::set<int> std_set3(std_set2);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


std::cout << "===== Assignement operator =====" << std::endl << std::endl;

FT_START;
ft_set3 = ft_set;
FT_END;

STD_START;
std_set3 = std_set;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


sleep(1);
std::cout << YELLOW << "============================ 2 - ITERATORS =======================" << RESET << std::endl ;

std::cout << "===== begin =====" << std::endl << std::endl;

FT_START;
ft::set<int>::iterator ft_it = ft_set.begin();
std::cout << "the first element is : " << *ft_it << std::endl;
FT_END;

STD_START;
std::set<int>::iterator std_it = std_set.begin();
std::cout << "the first element is : " << *std_it << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== end =====" << std::endl << std::endl;

FT_START;
ft::set<int>::iterator ft_it2 = ft_set.end();
--ft_it2;
std::cout << "the last element is : " << *ft_it2 << std::endl;
FT_END;

STD_START;
std::set<int>::iterator std_it2 = std_set.end();
--std_it2;
std::cout << "the last element is : " << *std_it2 << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


std::cout << "===== rbegin =====" << std::endl << std::endl;

FT_START;
ft::set<int>::reverse_iterator ft_rit = ft_set.rbegin();
std::cout << "the first element is : " << *ft_rit << std::endl;
FT_END;

STD_START;
std::set<int>::reverse_iterator std_rit = std_set.rbegin();
std::cout << "the first element is : " << *std_rit << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== rend =====" << std::endl << std::endl;

FT_START;
ft::set<int>::reverse_iterator ft_rit2 = ft_set.rend();
--ft_rit2;
std::cout << "the last element is : " << *ft_rit2 << std::endl;
FT_END;

STD_START;
std::set<int>::reverse_iterator std_rit2 = std_set.rend();
--std_rit2;
std::cout << "the last element is : " << *std_rit2 << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

sleep(1);
std::cout << YELLOW << "\n============================ 3 - CAPACITY/SIZE AND RELATED STUFF =======================" << RESET << std::endl ;


std::cout << "===== empty =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set is empty : " << ft_set.empty() << std::endl;
FT_END;

STD_START;
std::cout << "std_set is empty : " << std_set.empty() << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== size =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set size : " << ft_set.size() << std::endl;
FT_END;

STD_START;
std::cout << "std_set size : " << std_set.size() << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


std::cout << "===== max_size =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set max_size : " << ft_set.max_size() << std::endl;
FT_END;

STD_START;
std::cout << "std_set max_size : " << std_set.max_size() << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

sleep(1);
std::cout << YELLOW << "\n============================ 4 - MODIFIERS =======================" << RESET << std::endl ;

std::cout << "===== insert a value =====" << std::endl << std::endl;

FT_START;

std::cout << "ft_set before insert :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
ft_set.insert(42);
std::cout << "ft_set after insert :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);

FT_END;

STD_START;

std::cout << "std_set before insert :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);
std_set.insert(42);
std::cout << "std_set after insert :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


std::cout << "===== insert into a pos =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set before insert :\n"
<< "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
ft_set.insert(ft_set.begin(), -5);
std::cout << "ft_set after insert :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
FT_END;

STD_START;
std::cout << "std_set before insert :\n"
<< "size : " << std_set.size() << std::endl;
CONTENT(std_set);
std_set.insert(std_set.begin(), -5);
std::cout << "std_set after insert :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== insert a range =====" << std::endl << std::endl;

ft_set2.clear();
std_set2.clear();
FT_START;
std::cout << "ft_set2 before insert :\n";
std::cout << "size : " << ft_set2.size() << std::endl;
CONTENT(ft_set2);
ft_set2.insert(ft_set.begin(), ft_set.end());
std::cout << "ft_set2 after insert :\n";
std::cout << "size : " << ft_set2.size() << std::endl;
CONTENT(ft_set2);
FT_END;

STD_START;
std::cout << "std_set2 before insert :\n"
<< "size : " << std_set2.size() << std::endl;
CONTENT(std_set2);

std_set2.insert(std_set.begin(), std_set.end());

std::cout << "std_set2 after insert :\n";
std::cout << "size : " << std_set2.size() << std::endl;
CONTENT(std_set2);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;







std::cout  << "===== erase a pos =====" <<RESET << std::endl << std::endl;

FT_START;
std::cout << "ft_set before erase :\n"
<< "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
ft_set.erase(ft_set.begin());
std::cout << "42 erased from FT \n";
std::cout << "ft_set after erase :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
FT_END;

STD_START;
std::cout << "std_set before erase :\n"
<< "size : " << std_set.size() << std::endl;
CONTENT(std_set);
std_set.erase(std_set.begin());
std::cout << "42 erased from STD \n";
std::cout << "std_set after erase :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== erase by key =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set before erase :\n"
<< "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
ft_set.erase(42);
std::cout << "42 erased from FT \n";
std::cout << "ft_set after erase :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
FT_END;

STD_START;
std::cout << "std_set before erase :\n"
<< "size : " << std_set.size() << std::endl;
CONTENT(std_set);
std_set.erase(42);
std::cout << "42 erased from STD \n";
std::cout << "std_set after erase :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);

STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== erase a range =====" << std::endl << std::endl;

FT_START;
std::cout << "ft_set before erase :\n"
<< "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
ft_set.erase(ft_set.begin(), ft_set.end());
std::cout << "ft_set after erase :\n";
std::cout << "size : " << ft_set.size() << std::endl;
CONTENT(ft_set);
FT_END;

STD_START;
std::cout << "std_set before erase :\n"
<< "size : " << std_set.size() << std::endl;
CONTENT(std_set);
std_set.erase(std_set.begin(), std_set.end());
std::cout << "std_set after erase :\n";
std::cout << "size : " << std_set.size() << std::endl;
CONTENT(std_set);

STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== swap =====" << std::endl << std::endl;

FT_START;
std::cout << "FT swapped with FT \n";
ft_set.swap(ft_set);
FT_END;

STD_START;
std::cout << "STD swapped with STD \n";
std_set.swap(std_set);
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;


std::cout << "===== clear =====" << std::endl << std::endl;

FT_START;
std::cout << "FT cleared \n";
ft_set.clear();
FT_END;

STD_START;
std::cout << "STD cleared \n";
std_set.clear();
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

sleep(1);
std::cout << YELLOW << "\n============================ 5 - OBSERVERS =======================" << RESET << std::endl ;

std::cout << "===== find =====" << std::endl << std::endl;

ft_set.insert(42);
std_set.insert(42);
FT_START;
std::cout << "FT find 42 : " << *ft_set.find(42) << std::endl;
FT_END;

STD_START;
std::cout << "STD find 42 : " << *std_set.find(42) << std::endl;
STD_END;


std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== count =====" << std::endl << std::endl;

FT_START;
std::cout << "FT count 42 : " << ft_set.count(42) << std::endl;
FT_END;

STD_START;
std::cout << "STD count 42 : " << std_set.count(42) << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== lower_bound =====" << std::endl << std::endl;

FT_START;
std::cout << "FT lower_bound 42 : " << *ft_set.lower_bound(42) << std::endl;
FT_END;

STD_START;
std::cout << "STD lower_bound 42 : " << *std_set.lower_bound(42) << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== upper_bound =====" << std::endl << std::endl;

FT_START;
std::cout << "FT upper_bound 42 : " << *ft_set.upper_bound(42) << std::endl;
FT_END;

STD_START;
std::cout << "STD upper_bound 42 : " << *std_set.upper_bound(42) << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

std::cout << "===== equal_range =====" << std::endl << std::endl;

FT_START;
std::cout << "FT equal_range 42 : " << *ft_set.equal_range(42).first << std::endl;
FT_END;

STD_START;
std::cout << "STD equal_range 42 : " << *std_set.equal_range(42).first << std::endl;
STD_END;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
COMPARE_TIMES;

sleep(1);
std::cout << YELLOW << "\n============================ 6 - OPERATIONS =======================" << RESET << std::endl ;

	std::cout << MAGENTA<< "\n\n== for FT ==" << RESET <<std::endl;

    FT_START
    ft::set<int> ft_comp1;
    ft::set<int> ft_comp2;
    ft_comp1.insert(1);
    ft_comp1.insert(0);
    ft_comp1.insert(867);
    ft_comp2.insert(78);
    ft_comp2.insert(56);
    ft_comp2.insert(25);

    std::cout << "ft_comp1 == ft_comp2 : ";
    (ft_comp1 == ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "ft_comp1 != ft_comp2 : ";
    (ft_comp1 != ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "ft_comp1 < ft_comp2 : ";
    (ft_comp1 < ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "ft_comp1 > ft_comp2 : ";
    (ft_comp1 > ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "ft_comp1 <= ft_comp2 : ";
    (ft_comp1 <= ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "ft_comp1 >= ft_comp2 : ";
    (ft_comp1 >= ft_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    FT_END

    std::cout << MAGENTA<< "\n\n== for STD ==" << RESET <<std::endl;

    STD_START
    std::set<int> std_comp1;
    std::set<int> std_comp2;
    std_comp1.insert(1);
    std_comp1.insert(0);
    std_comp1.insert(867);
    std_comp2.insert(78);
    std_comp2.insert(56);
    std_comp2.insert(25);

    std::cout << "std_comp1 == std_comp2 : ";
    (std_comp1 == std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "std_comp1 != std_comp2 : ";
    (std_comp1 != std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "std_comp1 < std_comp2 : ";
    (std_comp1 < std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "std_comp1 > std_comp2 : ";
    (std_comp1 > std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "std_comp1 <= std_comp2 : ";
    (std_comp1 <= std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    std::cout << "std_comp1 >= std_comp2 : ";
    (std_comp1 >= std_comp2) ? std::cout << "true" << std::endl : std::cout << "false" << std::endl;

    STD_END

    std::cout << GREEN << "===== OK ====="  << RESET << std::endl;
    COMPARE_TIMES;

return 0;
}


 int vector_unit_tests()
{
std::cout << "============================ THE TEST BEGINS  =======================" << std::endl;
std::cout << YELLOW << "============================ 1 - CONSTRUCTORS =======================" << RESET << std::endl ;

std::cout << "===== Default constructor =====" << std::endl << std::endl;

ft::vector<int> myvector;
std::vector<int> stdvector;

for (int i = 0; i < 10; i++){myvector.push_back(i);};
for (int i = 0; i < 10; i++){stdvector.push_back(i);};

std::cout << "===== fill constructor =====" << std::endl << std::endl;

ft::vector<int> myvector2(10, 69);
std::vector<int> stdvector2(10, 69);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== range constructor =====" << std::endl << std::endl;

ft::vector<int> myvector3(myvector.begin(), myvector.end());
std::vector<int> stdvector3(stdvector.begin(), stdvector.end());
std::cout << GREEN << "===== OK ====="  << RESET << std::endl;



std::cout << "===== copy constructor =====" << std::endl << std::endl;

ft::vector<int> myvector4(myvector3);
std::vector<int> stdvector4(stdvector3);
std::cout << GREEN << "===== OK ====="  << RESET << std::endl;



std::cout << "===== operator= =====" << std::endl << std::endl;

ft::vector<int> myvector5;
myvector5 = myvector4;
std::cout << GREEN << "===== OK ====="  << RESET << std::endl;




sleep(1);

std::cout << YELLOW << "============================ 2 - Iterators =======================" << RESET << std::endl ;

std::cout << "===== begin =====" << std::endl << std::endl;

ft::vector<int>::iterator ft_it = myvector.begin();
std::vector<int>::iterator std_it = stdvector.begin();
std::cout << "the begin of ft_it is: " << *ft_it << std::endl;
std::cout << "the begin of std_it is: " << *std_it << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== end =====" << std::endl << std::endl;

ft::vector<int>::iterator ft_it2 = myvector.end();
std::vector<int>::iterator std_it2 = stdvector.end();
ft_it2--;std_it2--;
std::cout << "the end of ft_it is: " << *ft_it2 << std::endl;
std::cout << "the end of std_it is: " << *std_it2 << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== rbegin =====" << std::endl << std::endl;

ft::vector<int>::reverse_iterator ft_rit = myvector.rbegin();
std::vector<int>::reverse_iterator std_rit = stdvector.rbegin();

std::cout << "the rbegin of ft_rit is: " << *ft_rit << std::endl;
std::cout << "the rbegin of std_rit is: " << *std_rit << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== rend =====" << std::endl << std::endl;

ft::vector<int>::reverse_iterator ft_rit2 = myvector.rend();
std::vector<int>::reverse_iterator std_rit2 = stdvector.rend();
ft_rit2--;std_rit2--;
std::cout << "the rend of ft_rit is: " << *ft_rit2 << std::endl;
std::cout << "the rend of std_rit is: " << *std_rit2 << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


sleep(1);
std::cout << YELLOW << "============================ 3 - Capacity =======================" << RESET << std::endl ;

std::cout << "===== size =====" << std::endl << std::endl;

std::cout << "the size of myvector is: " << myvector.size() << std::endl;
std::cout << "the size of stdvector is: " << stdvector.size() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== max_size =====" << std::endl << std::endl;

std::cout << "the max_size of myvector is: " << myvector.max_size() << std::endl;
std::cout << "the max_size of stdvector is: " << stdvector.max_size() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== resize =====" << std::endl << std::endl;

myvector.resize(5);
stdvector.resize(5);

std::cout << "the size of myvector is: " << myvector.size() << std::endl;
std::cout << "the size of stdvector is: " << stdvector.size() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== capacity =====" << std::endl << std::endl;

std::cout << "the capacity of myvector is: " << myvector.capacity() << std::endl;
std::cout << "the capacity of stdvector is: " << stdvector.capacity() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== empty =====" << std::endl << std::endl;

std::cout << "the empty of myvector is: " << myvector.empty() << std::endl;
std::cout << "the empty of stdvector is: " << stdvector.empty() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== reserve =====" << std::endl << std::endl;

myvector.reserve(100);
stdvector.reserve(100);

std::cout << "the capacity of myvector is: " << myvector.capacity() << std::endl;
std::cout << "the capacity of stdvector is: " << stdvector.capacity() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


sleep(1);
std::cout << YELLOW << "============================ 4 - Element access =======================" << RESET << std::endl ;

std::cout << "===== operator[] =====" << std::endl << std::endl;

std::cout << "the element of myvector[2] is: " << myvector[2] << std::endl;
std::cout << "the element of stdvector[2] is: " << stdvector[2] << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== at =====" << std::endl << std::endl;

std::cout << "the element of myvector.at(2) is: " << myvector.at(2) << std::endl;
std::cout << "the element of stdvector.at(2) is: " << stdvector.at(2) << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== front =====" << std::endl << std::endl;

std::cout << "the element of myvector.front() is: " << myvector.front() << std::endl;
std::cout << "the element of stdvector.front() is: " << stdvector.front() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== back =====" << std::endl << std::endl;

std::cout << "the element of myvector.back() is: " << myvector.back() << std::endl;
std::cout << "the element of stdvector.back() is: " << stdvector.back() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


sleep(1);
std::cout << YELLOW << "============================ 5 - Modifiers =======================" << RESET << std::endl ;


std::cout << "===== assign with fill =====" << std::endl << std::endl;

myvector.assign(7, 100);
stdvector.assign(7, 100);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== assign with range =====" << std::endl << std::endl;


myvector.assign(myvector2.begin(), myvector2.end());
stdvector.assign(stdvector2.begin(), stdvector2.end());

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);



std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== push_back =====" << std::endl << std::endl;

myvector.push_back(200);
stdvector.push_back(200);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== pop_back =====" << std::endl << std::endl;

myvector.pop_back();
stdvector.pop_back();

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);


std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== insert single element =====" << std::endl << std::endl;

myvector.insert(myvector.begin(), 300);
stdvector.insert(stdvector.begin(), 300);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== insert fill =====" << std::endl << std::endl;

myvector.insert(myvector.begin(), 2, 400);
stdvector.insert(stdvector.begin(), 2, 400);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== insert range =====" << std::endl << std::endl;

myvector.insert(myvector.begin(), myvector2.begin(), myvector2.end());
stdvector.insert(stdvector.begin(), stdvector2.begin(), stdvector2.end());

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== erase single element =====" << std::endl << std::endl;

myvector.erase(myvector.begin());
stdvector.erase(stdvector.begin());

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== erase range =====" << std::endl << std::endl;

myvector.erase(myvector.begin(), myvector.end());
stdvector.erase(stdvector.begin(), stdvector.end());

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);


std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== swap =====" << std::endl << std::endl;



myvector.insert(myvector.begin(),5,42);
stdvector.insert(stdvector.begin(),5,42);

std::cout << "myvector and stdvector before swap contains: \n";
CONTENT(myvector);
CONTENT(stdvector);
std::cout << "myvector2 and stdvector2 before contains: \n";
CONTENT(myvector2);
CONTENT(stdvector2);

myvector.swap(myvector2);
stdvector.swap(stdvector2);

std::cout << CYAN << "\nswaping ... bip boop" << RESET << std::endl;


std::cout << "\nmyvector and stdvector after contains: \n";
CONTENT(myvector);
CONTENT(stdvector);
std::cout << "myvector2 and stdvector2 after contains: \n";
CONTENT(myvector2);
CONTENT(stdvector2);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== clear =====" << std::endl << std::endl;

myvector.clear();
stdvector.clear();

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);


std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== swap =====" << std::endl << std::endl;


myvector.swap(myvector2);
stdvector.swap(stdvector2);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


sleep(1);

std::cout << YELLOW << "============================ 6 - Allocator =======================" << RESET << std::endl ;

std::cout << "===== get_allocator =====" << std::endl << std::endl;

int * p;
int * p2;

p = myvector.get_allocator().allocate(5);
p2 = stdvector.get_allocator().allocate(5);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;



std::cout << "===== deallocate =====" << std::endl << std::endl;

myvector.get_allocator().deallocate(p,5);
stdvector.get_allocator().deallocate(p2,5);

std::cout << "myvector contains:";
CONTENT(myvector);
std::cout << "stdvector contains:";
CONTENT(stdvector);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

sleep(1);


std::cout << YELLOW << "============================ 7 - Relational operators =======================" << RESET << std::endl ;



    std::cout << "myvector == stdvector: ";
     (myvector == myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    std::cout << "myvector  != stdvector: ";
     (myvector != myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    std::cout << "myvector  < stdvector: ";
        (myvector < myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    std::cout << "myvector  <= stdvector: ";
        (myvector <= myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    std::cout << "myvector  > stdvector: ";
        (myvector > myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    std::cout << "myvector  >= stdvector: ";
        (myvector >= myvector2) ? std::cout << "true \n" : std::cout << "false \n" ;
    

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


return (0);
} 






int main()
{
//	int array[3] = {0, 1, 2};


	// ft::vector<int>	vec(10, 0);
	//std::vector<int>	vec(array, array + sizeof(array) / sizeof(int));

	// for (int i = 0; i < 3; i++)
	// 	vec.push_back(i);
	
	// for (ft::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	// 	std::cout << *it << std::endl;

	
	std::cout << vector_unit_tests() << std::endl;
	std::cout << map_unit_tests() << std::endl;
	std::cout << set_unit_tests() << std::endl;

	return (0);
}
