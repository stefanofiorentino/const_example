#include <iostream>

struct base {
    void hello() {
        std::cout << "hello" << std::endl;
    }

    void hello() const {
        std::cout << "const hello" << std::endl;
    }
};

int main() {
    {
        base b;
        b.hello();
    }
    {
        const base cb;
        cb.hello();
    }
    return 0;
}
