#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
int main() {
    std::unordered_set<std::string> phoneNumParts;
    std::vector<std::string> phoneNums;
    int testCaseNum;
    int phoneNum;
    bool consistent=true;
    std::string number;
    std::cin >> testCaseNum;
    for (int i = 0; i < testCaseNum; i++) {
        std::cin >> phoneNum;
        for (int j = 0; j < phoneNum; j++) {
            std::cin >> number;
            phoneNums.push_back(number);
            for(int k=0; k < number.length()-1; k++) {
                phoneNumParts.emplace(number.substr(0, k+1));
            }
        }
        for(int l = 0; l < phoneNums.size(); l++) {
            if(phoneNumParts.count(phoneNums[l])) {
                std::cout << "NO"<<std::endl;
                consistent=false;
                break;
            }
        }
        if(consistent)
            std::cout << "YES"<<std::endl;
        phoneNums.clear();
        phoneNumParts.clear();
        consistent=true;
    }
    return 0;
}
