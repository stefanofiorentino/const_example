#include <iostream>
#include <string>

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

    std::string const &get_name() const {
        return name;
    }

private:
    std::string name;
};

namespace {
    void hello(base &b) {
        b.hello();
    }

    void hello(base const &b) {
        b.hello();
    }
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

    std::string s = cd.get_name();
    std::string const s1 = cd.get_name();
    // std::string &s2 = cd.get_name(); // compile error
    std::string const &s3 = cd.get_name();
    // cd.get_name().append("."); // compile error

    return 0;
}
