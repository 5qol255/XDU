#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string name;

public:
    Animal(const char *nm = "A") : name("A")
    {
        if (nm != NULL)
            name = nm;
    }
    Animal(const string &nm) : name(nm) {}
    virtual void iam() { cout << "Animal " << name << " \n "; }
    void hello() { cout << "Animal::hello from " << name << " \n "; }
    void common() { cout << "Animal::common\n"; }
};

class Dog : public Animal
{
public:
    Dog(const string &name = "Dog") : Animal(name) {}
    void iam() { cout << "Dog " << name << " \n "; }
    void hello() { cout << "Dog::bark from " << name << " \n "; }
};

class Human : public Animal
{
public:
    Human(const string &name = "Human") : Animal(name) {}
    void iam() { cout << "Human " << name << " \n "; }
    void hello() { cout << "Human::hello from " << name << " \n "; }
};

class Man : public Human
{
public:
    Man(const string &name = "Man") : Human(name) {}
    void iam() { cout << "Man " << name << " \n "; }
    void hello() { cout << "Man::hello from " << name << " \n "; }
};

class Woman : public Human
{
public:
    Woman(const string &name = "Woman") : Human(name) {}
    void iam() { cout << "Woman " << name << " \n "; }
    void hello() { cout << "Woman::hello from " << name << " \n "; }
};

template <typename T>
void test(T &obj)
{
    obj.iam();
    obj.hello();
    obj.common();
}

template <typename T>
void test(T *obj)
{
    obj->iam();
    obj->hello();
    obj->common();
}

int main()
{
    Animal animal("Animal");
    Dog dog("Bruce");
    Human human("John");
    Man man("Tom");
    Woman woman("Jane");

    test(animal);
    test(dog);
    test(human);
    test(man);
    test(woman);

    Animal *ptr;
    ptr = &animal;
    test(ptr);
    test(&animal);

    ptr = &dog;
    test(ptr);
    test(&dog);

    ptr = &human;
    test(ptr);
    test(&human);

    ptr = &man;
    test(ptr);
    test(&man);

    ptr = &woman;
    test(ptr);
    test(&woman);

    return 0;
}