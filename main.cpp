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

void hello(base &b) {
    b.hello();
}

void hello(base const &b) {
    b.hello();
}

int main() {
    base b;
    ::hello(b);

    derived d;
    ::hello(d);

    const base cb;
    ::hello(cb);

    const derived cd;
    ::hello(cd);

    return 0;
}
