#include "Polish.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>



int main(){



    std::string entry;

    std::getline(std::cin, entry);

    Polish a;

    
    std::cout << a.returnAlg(entry);

}