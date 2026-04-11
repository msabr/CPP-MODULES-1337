#include <iostream>
//

int f()
{
    //stack
    int a = 10;
    throw 1;
}
int main()
{
    try
    {
        int *a = new int[10000000000000000];
    }
    catch(std::exception &s)
    {
        std::cout << s.what() << std::endl;
    }
    catch(const char *s)
    {
        std::cout << s ;
    }
    catch(int s)
    {
        std::cout << s ;
    }
    catch(float s)
    {
        std::cout << s ;
    }
    catch(double s)
    {
        std::cout << s ;
    }
    std::cout << "cccccccccccccc" << std::endl;
    return 0;
}