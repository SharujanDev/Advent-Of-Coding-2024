#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility> // for std::pair
#include <algorithm>
#include <unordered_map>
int main()
{
    std::ifstream inputFile("Day1-Data.txt");
    if(!inputFile.is_open())
    {
        std::cerr << "Error: Could not open file" << std::endl;
        return 1;
    }

    std::vector<int> left = {};
    std::vector<int> right = {};
    std::string line;

    while (std::getline(inputFile,line))
    {
        std::stringstream ss(line);
        std::string num1,num2;

        //Number needs to be split by comma
        if (std::getline(ss,num1,',') && std::getline(ss,num2,','))
        {
            left.push_back(std::stoi(num1));
            right.push_back(std::stoi(num2));
        }
    }

    sort(left.begin(),left.end());
    sort(right.begin(),right.end());

    int sum = 0;

    //challenge 1
    for (int i = 0; i < left.size();i++)
    {
        sum += abs(left[i]-right[i]);
    }

    std::cout << sum << std::endl;//1765812

    //challenge 2
    std::unordered_map<int,int> freqMap;
    sum = 0;
    for (int num: right) freqMap[num]++;

    for (int i = 0; i < left.size();i++)
    {
        sum += (left[i] * freqMap[left[i]]);
    }

    std::cout << sum << std::endl;

}