/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:56:43 by ariahi            #+#    #+#             */
/*   Updated: 2023/02/14 21:24:09 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"

void compare_times(double first, double second)
{
    std::string result;

    double ratio = first / second;
    if (ratio > 1)
        result = "FT is " + std::to_string(ratio) + " is times faster than STD";
    else if (ratio < 1)
        result = "STD is " + std::to_string(1 / ratio) + " is times faster than FT";
    else
        result = "both are equal";
    std::cout<< BLUE << result << RESET << std::endl;
}

int main()
{

	std::cout << vector_unit_tests() << std::endl;
	std::cout << map_unit_tests() << std::endl;
	std::cout << set_unit_tests() << std::endl;

	return (0);
}
