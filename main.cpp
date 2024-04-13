#include <iostream>
#include <vector>

int main() {
    int input_1;
    
    
    std::cout << "Введите положительное целое число больше 64: ";
    std::cin >> input_1;

   
    if (input_1 <= 64) {
        std::cout << "Число должно быть больше 64. Попробуйте еще раз.\n";
        return 1;
    }


    std::vector<int> vec(1, 2); 

    
    for (int i = 1; i < input_1; ++i) {
        int carry = 0;
        for (int j = 0; j < vec.size(); ++j) {
            int product = vec[j] * 2 + carry;
            vec[j] = product % 10;
            carry = product / 10;
        }
        while (carry > 0) {
            vec.push_back(carry % 10);
            carry /= 10;
        }
    }

   
    std::cout << "2 в степени " << input_1 << " равно ";
    for (int i = vec.size() - 1; i >= 0; --i) {
        std::cout << vec[i];
    }
    std::cout << "\n";

    return 0;
}