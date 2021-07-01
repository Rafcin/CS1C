#include <iostream>
#include <vector>

void reverse(std::string target, int start, int end) {
    if(start>=end) {
        std::cout << target << std::endl;
        return;
    }else {
        std::swap(target[start], target[end]);
        reverse(target, start + 1, end - 1);
    }
}

int main() {
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    reverse(alpha, 11, 18);
    reverse(alpha, 4, 22);
    return 0;
}
