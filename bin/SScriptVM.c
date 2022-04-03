#include"../includes/SString.h"
int main(int argc,char* argv[]){
    String class string = new(String); //You must Init a class before using it and it will be the first element.And you mustn't delete it.
    
    String_out(string);
    getchar();
    return 0;
}