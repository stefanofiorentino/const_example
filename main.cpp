#include <iostream>

struct base {
    virtual ~base();

    virtual void hello() {
        std::cout << "Hello, I'm base" << std::endl;
    }

    virtual void hello() const {
        std::cout << "Hello, I'm const base" << std::endl;
    }
};

base::~base() = default;

struct derived : public base {
    void hello() override {
        std::cout << "Hello, I'm derived" << std::endl;
    }

    void hello() const override {
        std::cout << "Hello, I'm const derived" << std::endl;
    }
};

int main() {
    base b;
    b.hello();

    derived d;
    d.hello();

    const base cb;
    cb.hello();

    const derived cd;
    cd.hello();

    return 0;
}
