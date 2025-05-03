#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Person {
    char* name;
    int age;
public:
    Person();
    Person(const char* n, int a);
    Person(Person&& other) noexcept;
    Person& operator=(Person&& other) noexcept;
    ~Person();
    void show() const;
};

class Apartment {
    Person* people;
    int count;
public:
    Apartment();
    Apartment(int c);
    Apartment(Apartment&& other) noexcept;
    Apartment& operator=(Apartment&& other) noexcept;
    ~Apartment();
    void show() const;
};

class House {
    Apartment* apartments;
    int number;
public:
    House();
    House(int n);
    House(House&& other) noexcept;
    House& operator=(House&& other) noexcept;
    ~House();
    void show() const;
};
#pragma once
