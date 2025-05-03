#include "prog.h"
#include <iostream>
#include <cstring>

// === Person ===

Person::Person() : name(nullptr), age(0) {}

Person::Person(const char* n, int a) : age(a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
}

Person::Person(Person&& other) noexcept : name(other.name), age(other.age) {
    other.name = nullptr;
    other.age = 0;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        delete[] name;
        name = other.name;
        age = other.age;
        other.name = nullptr;
        other.age = 0;
    }
    return *this;
}

Person::~Person() {
    delete[] name;
}

void Person::show() const {
    std::cout << (name ? name : "Unknown") << " (" << age << ")\n";
}

// === Apartment ===

Apartment::Apartment() : people(nullptr), count(0) {}

Apartment::Apartment(int c) : count(c) {
    people = new Person[count];
    for (int i = 0; i < count; i++) {
        char n[20];
        int a;
        std::cout << "Name " << i + 1 << ": ";
        std::cin >> n;
        std::cout << "Age: ";
        std::cin >> a;
        people[i] = Person(n, a);
    }
}

Apartment::Apartment(Apartment&& other) noexcept : people(other.people), count(other.count) {
    other.people = nullptr;
    other.count = 0;
}

Apartment& Apartment::operator=(Apartment&& other) noexcept {
    if (this != &other) {
        delete[] people;
        people = other.people;
        count = other.count;
        other.people = nullptr;
        other.count = 0;
    }
    return *this;
}

Apartment::~Apartment() {
    delete[] people;
}

void Apartment::show() const {
    for (int i = 0; i < count; i++) {
        people[i].show();
    }
}

// === House ===

House::House() : apartments(nullptr), number(0) {}

House::House(int n) : number(n) {
    apartments = new Apartment[number];
    for (int i = 0; i < number; i++) {
        int c;
        std::cout << "People in apartment " << i + 1 << ": ";
        std::cin >> c;
        apartments[i] = Apartment(c);
    }
}

House::House(House&& other) noexcept : apartments(other.apartments), number(other.number) {
    other.apartments = nullptr;
    other.number = 0;
}

House& House::operator=(House&& other) noexcept {
    if (this != &other) {
        delete[] apartments;
        apartments = other.apartments;
        number = other.number;
        other.apartments = nullptr;
        other.number = 0;
    }
    return *this;
}

House::~House() {
    delete[] apartments;
}

void House::show() const {
    for (int i = 0; i < number; i++) {
        std::cout << "Apartment " << i + 1 << ":\n";
        apartments[i].show();
    }
}
