/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:56:43 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/31 16:17:12 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"

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

template <typename T>
void print_content(T& container) {
  for (typename T::iterator it=container.begin(); it!=container.end(); ++it)
    std::cout << ' ' << *it;
    std::cout << std::endl;
}


#define CONTENT(X) print_content(X)


#define L_CYAN "\033[1;96m"
#define REDD "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define RESET "\033[0m"


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


int stack_unit_tests()
{
std::cout << "============================ THE TEST BEGINS  =======================" << std::endl;
std::cout << "============================ STACK UNIT TESTS =======================" << std::endl;

std::cout << YELLOW << "============================ 1 - CONSTRUCTORS =======================" << RESET << std::endl ;

std::cout << "===== Default constructor =====" << std::endl << std::endl;
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;

	// push back some numbers
	for (int i = 0; i < 10 ; i++)
	{
		ft_stack.push(i);
		std_stack.push(i);
	}

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << "===== copy constructor =====" << std::endl << std::endl;

	ft::stack<int> ft_stack2(ft_stack);
	std::stack<int> std_stack2(std_stack);

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;


std::cout << "===== assignment operator =====" << std::endl << std::endl;

	ft::stack<int> ft_stack3;
	std::stack<int> std_stack3;

	ft_stack3 = ft_stack;
	std_stack3 = std_stack;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

sleep(1);	
std::cout << YELLOW << "============================2 - MEMBER FUNCTIONS =======================" << RESET  << std::endl;

std::cout << "===== empty =====" << std::endl << std::endl;

	(ft_stack.empty()) ? std::cout << "ft_stack is empty" << std::endl : std::cout << "ft_stack is not empty" << std::endl;
	(std_stack.empty()) ? std::cout << "std_stack is empty" << std::endl : std::cout << "std_stack is not empty" << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << "===== size =====" << std::endl << std::endl;

	std::cout << "ft_stack size is " << ft_stack.size() << std::endl;
	std::cout << "std_stack size is " << std_stack.size() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << "===== top =====" << std::endl << std::endl;

	std::cout << "ft_stack top is " << ft_stack.top() << std::endl;
	std::cout << "std_stack top is " << std_stack.top() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << "===== push =====" << std::endl << std::endl;

	ft_stack.push(69);
	std_stack.push(69);

	std::cout << "ft_stack top is " << ft_stack.top() << std::endl;
	std::cout << "std_stack top is " << std_stack.top() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << "===== pop =====" << std::endl << std::endl;

	ft_stack.pop();
	std_stack.pop();

	std::cout << "ft_stack top is " << ft_stack.top() << std::endl;
	std::cout << "std_stack top is " << std_stack.top() << std::endl;

std::cout << GREEN << "===== OK ====="  << RESET << std::endl;

std::cout << YELLOW << "============================ 3 - RELATIONAL OPERATORS =======================" << RESET << std::endl;

std::cout << "mystack == mystack2  :" << ((ft_stack == ft_stack2) ? "true" : "false") << std::endl;
std::cout << "mystack != mystack2  :" << ((ft_stack != ft_stack2) ? "true" : "false") << std::endl;
std::cout << "mystack < mystack2  :" << ((ft_stack < ft_stack2) ? "true" : "false") << std::endl;
std::cout << "mystack <= mystack2  :" << ((ft_stack <= ft_stack2) ? "true" : "false") << std::endl;
std::cout << "mystack > mystack2  :" << ((ft_stack > ft_stack2) ? "true" : "false") << std::endl;
std::cout << "mystack >= mystack2  :" << ((ft_stack >= ft_stack2) ? "true" : "false") << std::endl;



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

	return (0);
}
