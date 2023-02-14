/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:26:45 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/14 21:26:47 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
#define COMMON_HPP

#include <sys/time.h>
#include <thread>
#include <unistd.h>
#include <__tree>
#include <cstdlib>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "set.hpp"
#include "map.hpp"

int map_unit_tests();
int set_unit_tests();
int vector_unit_tests();

void compare_times(double first, double second);

template <typename T>
void print_content(T& container) {
  for (typename T::iterator it=container.begin(); it!=container.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << std::endl;
}

#define CONTENT(X) print_content(X)

#define COMPARE_TIMES compare_times(ft_start - ft_end, std_start - std_end);

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

#endif