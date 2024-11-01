#include <iostream>
#include <string>
int main(){
    std::string firstPrefix;
    std::string secondPrefix;
    std::string firstOperand;
    std::string operator_;
    std::string secondOperand;
    std::string result;
    std::cin>>firstOperand;
    std::cin>>operator_;
    std::cin>>secondOperand;
    std::cin>>result;
    std::cin>>result;
    //swap first and second operand prefixes and compare solution
    if(operator_=="+"&&std::stoi(firstOperand)+std::stoi(secondOperand)==std::stoi(result)) {
        std::cout<<firstOperand<<" + "<<secondOperand<<" = "<<result;
        return 0;
    }else if(std::stoi(firstOperand)*std::stoi(secondOperand)==std::stoi(result)) {
        std::cout<<firstOperand<<" * "<<secondOperand<<" = "<<result;
        return 0;
    }
    for(int firstLength=1;firstLength<firstOperand.length();firstLength++) {
        for(int secondLength=1;secondLength<secondOperand.length();secondLength++) {
            firstPrefix=firstOperand.substr(0,firstLength);
            secondPrefix=secondOperand.substr(0,secondLength);
            std::string firstNumber=secondPrefix+firstOperand.substr(firstLength);
            std::string secondNumber=firstPrefix+secondOperand.substr(secondLength);
            if (operator_=="+") {
                if(std::stoi(firstNumber)+std::stoi(secondNumber)==std::stoi(result)){
                    std::cout<<firstNumber<<" + "<<secondNumber<<" = "<<result;
                    return 0;
                }
            } else if(std::stoi(firstNumber)*std::stoi(secondNumber)==std::stoi(result)){
                std::cout<<firstNumber<<" * "<<secondNumber<<" = "<<result;
                return 0;
            }
        }
    }
    //swap first and result
    for(int firstLength=1;firstLength<firstOperand.length();firstLength++) {
        std::cout<<"second case ran\n";
        for(int secondLength=1;secondLength<result.length();secondLength++) {
            firstPrefix=firstOperand.substr(0,firstLength);
            secondPrefix=result.substr(0,secondLength);
            std::string firstNumber=secondPrefix+firstOperand.substr(firstLength);
            std::string secondNumber=firstPrefix+result.substr(secondLength);
            if (operator_=="+") {
                if(std::stoi(firstNumber)+std::stoi(secondOperand)==std::stoi(secondNumber)){
                    std::cout<<firstNumber<<" + "<<secondOperand<<" = "<<secondNumber;
                    return 0;
                }
            } else if(std::stoi(firstNumber)*std::stoi(secondOperand)==std::stoi(secondNumber)){
                std::cout<<firstNumber<<" * "<<secondOperand<<" = "<<secondNumber;
                return 0;
            }
        }
    }
    //swap second and result
    for(int firstLength=1;firstLength<secondOperand.length();firstLength++) {
        std::cout<<"third case ran\n";
        for(int secondLength=1;secondLength<result.length();secondLength++) {
            firstPrefix=secondOperand.substr(0,firstLength);
            secondPrefix=result.substr(0,secondLength);
            std::string firstNumber=secondPrefix+secondOperand.substr(firstLength);
            std::string secondNumber=firstPrefix+result.substr(secondLength);
            if (operator_=="+") {
                if(std::stoi(firstNumber)+std::stoi(firstOperand)==std::stoi(secondNumber)){
                    std::cout<<firstNumber<<" + "<<firstOperand<<" = "<<secondNumber;
                    return 0;
                }
            } else if(std::stoi(firstNumber)*std::stoi(firstOperand)==std::stoi(secondNumber)){
                std::cout<<firstNumber<<" * "<<firstOperand<<" = "<<secondNumber;
                return 0;
            }
        }
    }
}
