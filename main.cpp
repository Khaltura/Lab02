#include <iostream>
#include <vector>

/**
 * @brief функция проверки входных данных 
 * 
 * @param input_1 - входное число
 * @return int - 1 если число подходит, 0 в противном случае
 */
int checkInput(int input_1)
{
    if(input_1 <= 64)
    {
        return 0;
    } else
    {
        return 1;
    }
}

std::vector<int> vozvedenie(int input_1, std::vector<int> vec)
{
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
    return vec;
}



int main() {
    int input_1;
    
    
    std::cout << "Введите положительное целое число больше 64: ";
    std::cin >> input_1;

   
    if (checkInput(input_1 == 0))
    {
        std::cout << "Число должно быть больше 64." << std::endl; 
        return 0;
    }

    std::vector<int> vec(1, 2); 

    /*
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
    */
   vec = vozvedenie(input_1, vec);
   
   
    std::cout << "2 в степени " << input_1 << " равно ";
    for (int i = vec.size() - 1; i >= 0; --i) {
        std::cout << vec[i];
    }
    std::cout << "\n";

    return 0;
}