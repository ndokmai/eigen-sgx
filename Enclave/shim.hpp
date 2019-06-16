#ifndef SHIM_HPP 
#define SHIM_HPP

#include <string>

namespace std {
class streamsize {
};

int rand() {
    return 0;
}

class ostream {
    public:
    size_t precision(streamsize& _);
    size_t width(int _);
    ostream& operator<<(float _);
    ostream& operator<<(const std::string& _);
};

class stringstream {
    public:
    void copyfmt(ostream& _);
    string str();
};
}

#endif
