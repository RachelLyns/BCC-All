#include <iostream>
#include <string>
#include <cstring>






int contador_space(int a, int w, const char* vChar, int size, std::string modo){
    



    int space = 0;
    int position_left = 0;
    int position_right = 0;
    bool left = true;
    bool right = true;


    for (int b = 0; b < w; b++) {
        position_left = a+b;
        position_right = a+w-b-1;
        if((vChar[(position_left)] == ' ')&&(left == true)){
            space++;
        }else{
            if(modo == "Left"){
                return position_left;
            }
            left = false;
        }
        if(((vChar[(position_right )] == ' ')||(position_right > size))&&(right == true)){
            space++;
        }else{
            if(modo == "Right"){
                return position_right;
            }
            right = false;
        }
        if((left == false)&&(right == false)){
            if (modo == "Space"){
                return space;
            }
            
        }
        }

}
















int main() {
    std::string text = "aaaa  aaaa  aaaa  aaaa  aaaa  aaaa";
    int size = text.size();
    char vChar[size-1];
    int w = 24;
    int space = 0;

    std::cout << size << " Letras \n\n";
    strcpy(vChar, text.c_str());
    






    for (int a = 0; a < size-1; a) {
        std::cout << '|'<<' ';

        space = (contador_space(a, w, vChar, size, "Space"))/2;

        for (int c = 1; c < space; c++){
            std::cout << ' ';
        }
        int left = (contador_space(a, w, vChar, size, "Left"));
        int right = (contador_space(a, w, vChar, size, "Right"));

        for (int b = left; b <= right; b++) {
                std::cout << vChar[b];
        }

        for (int c = 1; c < space; c++){
            std::cout << ' ';
        }

        std::cout <<' ' <<'|'<<"\n";
        a = a + w;
    }
    











    return 0;

}






