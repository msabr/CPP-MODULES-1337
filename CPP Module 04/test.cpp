#include <iostream>

class Animal
{
    public:
        virtual void makeSound() const
        {
            std::cout << "Animal sound\n";
        }
        ~a(){std::cout << "destructer a\n";}

};

class Dog : public Animal
{
    public:
        void makeSound() const
        {
            std::cout << "Dog barks\n";
        }
        ~Dog(){std::cout << "destructer Dog\n";}
        virtual void ppp()
        {
            std::cout << "Dog barks\n";

        }
};
class Canich : public Dog
{
    public:
        void makeSound() const
        {
            std::cout << "Canich barks\n";
        }
        ~Canich(){std::cout << "destructer canich\n";}
};




int main() {
    Dog *a = new Canich();
    a->makeSound();
    return 0;
}