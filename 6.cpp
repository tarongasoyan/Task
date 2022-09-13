#include <iostream>
#include <vector>

void move_zeroes(std::vector<int>& nums);

int main() {
    std::vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(12);
    move_zeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
    }
    return 0;
}
void move_zeroes(std::vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
}