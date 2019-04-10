#include <iostream> 
// using namespace  std; 
// void  main() /*  Error  main  must return  int */ 
int  main()
{
    int val; 
    std::cout << "int  main  function \n ";
    std::cin >> val; 
    std::cerr << val << " Val in  cerr\n"; 
    std::clog << val << " val in clog\n"; 
}
