#include "cstring_vector.h"

int main()
{
    cstring_vector sv0;
    sv0.println();
    
    int const N1{ 3 };
    char* cstr_arr[N1] = { new char[] {"Hello"}, new char[] {" "},  new char[] {"world!"} };
   /* strcpy(cstr_arr[0], "Hello");
    strcpy(cstr_arr[0], " ");
    strcpy(cstr_arr[0], "world!");*/

    cstring_vector sv1(cstr_arr, N1);
    sv1.println();
    char const * consts_cstr_arr[] = {"Anything", "you", "like"};

    std::vector<std::string> str_vector{ "An", "you", "io" };
    cstring_vector sv22(str_vector);

    char str[] = "hello!";
    sv22.push_back(str);
    // sv22.println();







        
}
