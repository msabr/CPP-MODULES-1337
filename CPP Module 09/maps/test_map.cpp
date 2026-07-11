#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> m;
    m[1] = "Sabir";
    m[1] = "Sabir2";
    m.insert(std::make_pair(2, "Mohamed"));
    m.insert(std::make_pair(2, "Mohamed2"));
    std::cout << m[1] << std::endl;
    std::cout << m[2] << std::endl;
    std::cout << m[100] << std::endl;
    // m.erase(2);
    // m.clear();
    // m.size();
    // m.empty();
    std::map<int, std::string>::iterator it;
    it = m.find(2);
    std::cout << it->second << std::endl;
    for (it = m.begin(); it!= m.end() ; ++it)
    {
        std::cout << "<" << it->first << "," << it->second << ">  ==> ";
    }
    std::cout << "NULL" << std::endl;
    return 0;
}