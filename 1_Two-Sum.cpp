#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//vector<int> num = {2, 7, 11, 15};
vector<int> num = {3,2,4};

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>result = {0,0};
    unordered_map<int, int> mapStudent;
    unordered_map<int, int>::iterator  iter;
    int i = 0;
// the location shoude be the value
    for (auto val : nums) {
        mapStudent[val] = i++;
    }

    i = 0;

    for(auto val : nums){
        iter = mapStudent.find(target - val);
        // make sure find the target and not the same element
        if(iter != mapStudent.end() && iter->second != i){
            cout<<i<<" "<<iter->second<<endl;
             result = {i, iter->second} ;
            return result;
        }
        i++;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    twoSum(num, 6);

    return 0;
}