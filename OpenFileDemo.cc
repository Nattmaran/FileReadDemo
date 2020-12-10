#include <fstream>      // std::fstream
#include <iostream>
#include <sstream>

using namespace std;

class Animal {
    public:
        Animal() {};
        virtual void print() = 0;
};

class Cat: public Animal {
    public:
        Cat(string n, int a) : name{n}, age{a} {};
        string name;
        int age;
        void print() {
            cout << "Name: " << name << " Age: " << age;
        }
};

class Fish: public Animal {
    public:
        Fish(string n, int a, string c) : name{n}, age{a}, color{c} {};
        string name;
        int age;
        string color;
        void print() {
            cout << "Name: " << name << " Age: " << age << " Color: " << color;
        }
};


Animal* animalFactory(istringstream & line) {
    int animal_type;
    line >> animal_type;

    switch(animal_type) {
        case 0 :
            {
                string name;
                int age;

                line >> name;
                line >> age;
                return new Cat{name,age};
            }
            break;
        case 1 :
            {
                string name;
                int age;
                string color;

                line >> name;
                line >> age;
                line >> color;
                return new Fish{name,age,color};
            }
            break;

        default:
            throw "Fuck no animal";
    }
    throw "Error No such animal";
}

int main () {

  fstream fs;
  fs.open ("test.txt", fstream::in );

  string line;
  while(getline(fs,line)) {
    istringstream linestream{line};
    Animal* animal = animalFactory(linestream);
    animal->print();
    cout << endl;
  }

  fs.close();

  return 0;
}






