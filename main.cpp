#define COMENT
#include <iostream>
#include "Foo.h"
#include <cstdlib>
#include <locale.h>

int main(int, char**){
   setlocale(LC_ALL, "ru");
   std::cout << "busy";
#ifdef COMENT
    int count;
    for (count=1; count<=10; count++)
    {
    int e = Foo( count);
    std::cout << "Julia Babulya" << " " << "Алина Balerina";
    }
#endif
   system("pause"); 
 
        return 0;
}
