#include <iostream>
//

class a
{
    public:
        a()
        {
            std::cout << "constructor called" << std::endl;
        }
        ~a()
        {
            std::cout << "destructor called" << std::endl;
        }
        a(int a){std::cout << "int\n";}; 
        a(double a){std::cout << "float\n";};
        a(char a){std::cout << "char\n";};
};

int f()
{
    //stack
    int a = 10;
    throw 1;
}
int main()
{
    // a b('a');
    try
    {
        char *s= "hello";
        f();
        // int *a = new int[10000000000000000];
    }
    catch(std::exception &s)
    {
        std::cout << s.what() << std::endl;
    }
    catch( void *s)
    {
        std::cout << s ;
    }
    catch(int s)
    {
        std::cout << s ;
    }
    catch(char s)
    {
        std::cout << s ;
    }
    catch(double s)
    {
        std::cout << s ;
    }
    std::cout << "FIN" << std::endl;
    return 0;
}