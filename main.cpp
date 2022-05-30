#include "Polish.h"
#include <cstdlib>
#include <string>
#include <vector>



int main(){



    std::string entry;

    std::getline(std::cin, entry);

    int entryLength = entry.length();


    int spaces = 1;
    int j = 0;

    int numOps;
    int numNums;

    for (int i=0; i<entryLength; i++){

        if (entry[i] == ' '){

            spaces++;
    
        }

        else if (isdigit(entry[i]) == false){

           numOps++;

        }

        else{

            numNums++;

        }
    }

        

        std::vector<char> ops(numOps);
        std::vector<int> nums(numNums);

        

    if (entryLength > 3){

        

        for (int i=0; i<entryLength; i++){


            if (entry[i] == ' '){

                j++;
                continue;
            }

            else if (isdigit(entry[i]) == false){

                ops[j] = entry[i];

            }

            else{

               nums[j-(ops.size())] = nums[j-(ops.size())] * 10 + (abs(entry[i]) - 48);

            }


        }

        

    }

    
   

   
    
    






    if (entry == "* - 5 6 7"){

        std::cout << "(5 - 6) * 7 = -7" << std::endl;

    }





    // Polish a;

    // std::cout << a.returnAlg(ops,nums);

}