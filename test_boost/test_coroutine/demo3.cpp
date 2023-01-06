/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-06
*  Description: 
================================================================*/

#include <iostream>
#include <boost/coroutine2/all.hpp>

void foo(boost::coroutines2::coroutine<int>::push_type & sink)
{
    std::cout << "start coroutine\n";
    sink(1);
    std::cout << "finish coroutine\n";
}


int main()
{
    boost::coroutines2::coroutine<int>::pull_type source(foo);
    std::cout << source.get() << std::endl;
    //std::cout << source() << std::endl;
    source();
    std::cout << "finish\n";
    return 0;
}
