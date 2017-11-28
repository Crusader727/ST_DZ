#include <iostream>
#include <cmath>
#include <iomanip>

int CountOnes (int n) {
    int res = 0;
    while (n) {
      res++;
      n &= n-1;  // Забираем младшую единичку.
    }
    return res;
}

int getDivision(int a) {
    int poly = 11;
    if(a >= 64) {
        a ^= poly*8;
    }
    if(a >= 32) {
        a ^= poly*4;     
    }
    if(a >= 16) {
        a ^= poly*2;      
    }
    if(a >= 8) {
        a ^= poly;        
    }
    return a;
}
int main() {
        int input = 0;    
        std::cout << "Enter input value(ex: 1111)" << std::endl;
        for(int i = 4 ; i > 0; i--){
            char buf;
            std::cin >> buf;
            if(buf == '1') {
                input += pow(2,i-1);
            }
        }   
        int my_poly1 = 8;
        int my_poly2 = 2;
        int my_poly3 = 1;
        int encoded = (my_poly1*input)^(my_poly2*input)^(my_poly3*input);
        // std::cout << "Encoded: " << std::bitset<8>(encoded).to_string() << std::endl << std::endl;
        int arr[8];
        for(int i = 0; i < 128; i++) {
            if(i != encoded) {
                if(getDivision(i) != 0) {
                    arr[CountOnes(i^encoded)]++;
                }
            }
        }
        int C[] = {0,7,21,35,35,21,7,1};
        std::cout << std::right << std::setw(4) << "I" << std::setw(8) << "C(i,n)" << std::setw(6) << "No" << std::setw(8) << "Co" << std::endl;        
        for(int i = 1; i < 8; i++) {
            std::cout << std::right << std::setw(4) << i << std::setw(8) << C[i] << std::setw(6) << arr[i] << std::setw(8) << ((double)arr[i])/C[i] << std::endl;
        }
        
    return 0;
}