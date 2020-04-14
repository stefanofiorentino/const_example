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
    static_assert(!std::is_const<decltype(s)>::value, "is const instead"); // static_assert is c++11
    static_assert(!std::is_reference<decltype(s)>::value, "is reference instead");

    std::string const s1 = cd.get_name();
    static_assert(std::is_const<decltype(s1)>::value, "isn't const instead");
    static_assert(!std::is_reference<decltype(s1)>::value, "is reference instead");

    // std::string &s2 = cd.get_name(); // compile error: trying to assign const-ref to ref
    static_assert(std::is_const<typename std::remove_reference<decltype(cd.get_name())>::type>::value, "isn't const instead");
    static_assert(std::is_reference<decltype(cd.get_name())>::value, "isn't reference instead");

    std::string const &s3 = cd.get_name();
    static_assert(std::is_const<typename std::remove_reference<decltype(s3)>::type>::value, "isn't const instead");
    static_assert(std::is_reference<decltype(s3)>::value, "isn't reference instead");
    // cd.get_name().append("."); // compile error: trying to mod a const ref

    return 0;
}
