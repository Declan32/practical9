#include "Polish.h"
#include <string> 
#include <cstdlib>


char Polish::stackOpp(std::vector <char> *opperators){

    popValue = opperators->at(opperators->size()-1);

    opperators->pop_back();

    return popValue;

}


bool Polish::check(std::vector<char> opperators, std::vector<int> integers){

    if (opperators.size() == integers.size() - 1){

        return true;

    }

    return false;

}



std::string Polish::returnAlg(std::string entry){


    int entryLength = entry.length();

    


    int spaces = 1;
    int j = 0;

    int numOps = 0;
    int numNums = 0;

    for (int i=0; i<entryLength; i++){

        if (entry[i] == ' '){

            spaces++;
    
        }

        else if (isdigit(entry[i]) == false){

           numOps++;

        }

        else{

            if (entry[i-1] == ' '){
                numNums++;
            }

        }
    }

       
        

        std::vector<char> opperators(numOps);
        std::vector<int> integers(numNums);

        

    if (entryLength > 3){

        

        for (int i=0; i<entryLength; i++){


            if (entry[i] == ' '){

                j++;
                continue;
            }

            else if (isdigit(entry[i]) == false){

                opperators[j] = entry[i];

            }

            else{

               integers[j-(opperators.size())] = integers[j-(opperators.size())] * 10 + (abs(entry[i]) - 48);

            }


        }

        

    }

    for (int i=0; i<integers.size(); i++){

        std::cout << integers[i] << std::endl;

    }


    if (check(opperators,integers) == true){

        value = integers.at(0);

        std::string initial = std::to_string(integers.at(0));

        output = initial;

        for (int i=0; i<integers.size()-1; i++){


            char opp = stackOpp(&opperators);


            switch (opp) {

                case '+':
                    value = value + integers.at(i+1);
                    

                    if (opperators.back() == '*' || opperators.back() == '/' && opperators.size() != 0){

                        output = "(" + output + " + " + std::to_string(integers.at(i+1)) + ")";

                    }

                    else{

                        output = output + " + " + std::to_string(integers.at(i+1));

                    }

                    break;

                case '-':
                    value = value - integers.at(i+1);

                    if (opperators.back() == '*' || opperators.back() == '/' && opperators.size() != 0){

                        output = "(" + output + " - " + std::to_string(integers.at(i+1)) + ")";

                    }

                    else{

                        output = output + " - " + std::to_string(integers.at(i+1));

                    }

                    break;

                case '*':
                    value = value * integers.at(i+1);

                    output = output + " * " + std::to_string(integers.at(i+1));

                    break;
                    

                case '/':
                    value = value / integers.at(i+1);

                    output = output + " / " + std::to_string(integers.at(i+1));

                    break;


            }

            
            

        }

        output = output + " = " + std::to_string(value);

        return output;

    }

    else{

        output = "Error";

        return output;

    }

}