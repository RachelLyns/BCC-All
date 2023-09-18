#include <iostream>
#include <string>
#include <cstring>






int contador_space(int a, int w, const char* vChar, int size){
    int space = 0;
    bool left = true;
    bool right = true;
     for (int b = 0; b < w; b++, a++) {
            if((vChar[(a+b)] == ' ')&&(left == true)){
                space++;
            }else{
                left = false;
            }
            if(((vChar[(a+w-b-1)] == ' ')||(a+w-b > size))&&(right == true)){
                space++;
            }else{
                right = false;
            }
        }
    return space;
}
















int main() {
    std::string text = "aaa aaa aaa aaa aaa aaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaa          aaaaaaaa";
    int size = text.size();
    char vChar[size-1];
    int w = 15;
    int space;

    std::cout << size << " Letras \n\n";
    strcpy(vChar, text.c_str());
    






    for (int a = 0; a < size-1; a) {
        std::cout << '| ';

        space = contador_space(a, w, vChar, size);

        for (int c = 1; c < space; c++){
            std::cout << ' ';
        }

        for (int b = 0; b < w; b++, a++) {
            if(a < size){
                std::cout << vChar[a];
            }
        }

        for (int c = 1; c < space; c++){
            std::cout << ' ';
        }

        std::cout << ' |\n';
    }
    











    return 0;

}






