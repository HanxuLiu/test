/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-06
*  Description: 
================================================================*/

#include <iostream>
#include <boost/coroutine2/all.hpp>

void foo(boost::coroutines2::coroutine<int>::pull_type& sink)
{
    std::cout << "start coroutine\n";
    //sink();
    int a = sink().get();
    std::cout << a << std::endl;
    std::cout << "finish coroutine\n";
}

int main()
{
    boost::coroutines2::coroutine<int>::push_type source(foo);
    
    std::cout << "finish\n";
    source(0);
    source(5);
    return 0;
}
