#include <iostream>
using namespace std;

// Базовий клас
class Tree {
public:
    virtual void draw() const {
        // Віртуальний метод
        cout << "Base tree\n";
    }

    virtual ~Tree() = default; // Віртуальний деструктор
};

// Похідний клас 1
class Tree1 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 1:\n";
        cout << " /\\\n";
        cout << "//\\\\\n";
    }
};

// Похідний клас 2
class Tree2 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 2:\n";
        cout << " /\\\n";
        cout << "/**\\\n";
    }
};

// Похідний клас 3
class Tree3 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 3:\n";
        cout << " /\\\n";
        cout << "/++\\\n";
    }
};

int main() {
    // Масив вказівників на базовий клас
    Tree* trees[3];

    // Створення об'єктів
    trees[0] = new Tree1();
    trees[1] = new Tree2();
    trees[2] = new Tree3();

    // Виклик draw() для кожного дерева
    for (int i = 0; i < 3; ++i) {
        trees[i]->draw();
    }

    // Звільнення пам’яті
    for (int i = 0; i < 3; ++i) {
        delete trees[i];
    }

    return 0;
}
