/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:27:17 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/14 21:27:18 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

int set_unit_tests()
{

    double ft_start , ft_end , std_start , std_end ;

    std::cout << YELLOW << "============================ 1 CONSTRUCTORS =======================" << RESET << std::endl ;

    std::cout << "===== Default constructor =====" << std::endl << std::endl;

    FT_START;
    ft::set<int> ft_set;

    for(int i = 0; i < 10; i++)
    {
    	ft_set.insert(i);
    }
    FT_END;

    STD_START;
    std::set<int> std_set;

    for(int i = 0; i < 10; i++)
    {
    	std_set.insert(i);
    }
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

    sleep(1);

    std::cout << YELLOW << "\n============================ 3 SIZE =======================" << RESET << std::endl ;

    std::cout << "===== size =====" << std::endl << std::endl;

    FT_START;
    std::cout << "ft_set size : " << ft_set.size() << std::endl;
    FT_END;

    STD_START;
    std::cout << "std_set size : " << std_set.size() << std::endl;
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
    return 0;
}
