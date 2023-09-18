#include <iostream>
#include <string>
#include <cstring>

int main() {
    std::string text = "aaa aaa aaa aaa aaa aaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaa          aaaaaaaa";
    int size = text.size();
    char vChar[size-1];
    int w = 15;

    std::cout << size << " Letras \n\n";
    strcpy(vChar, text.c_str());
    






    for (int a = 0; a < size-1; a) {
        std::cout << "| ";
        for (int b = 0; b < w; b++, a++) {
            if(a < size){
                std::cout << vChar[a];
            }else{
                std::cout << " ";
            }
        }
        std::cout << " |\n";
    }
    











    return 0;

}








