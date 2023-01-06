/*================================================================
*  Author: LiuHanxu
*  Date: 2023-01-05
*  Description: 
================================================================*/

#include <iostream>
#include <boost/coroutine2/all.hpp>

void foo(boost::coroutines2::coroutine<void>::pull_type & sink1){
    std::cout << "a ";
    sink1();
    std::cout << "b ";
    sink1();
    std::cout << "c ";
}

int main(){
    boost::coroutines2::coroutine<void>::push_type source(foo);
    std::cout << "1 ";
    source();
    std::cout << "2 ";
    source();
    std::cout << "3 " << std::endl;
    return 0;
}
