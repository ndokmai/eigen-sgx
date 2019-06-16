#ifndef SHIM_HPP 
#define SHIM_HPP

#include <string>
#include <sgx_trts.h>

namespace std {
class streamsize {
};

int rand() {
    int buff = 0;
    sgx_read_rand((unsigned char *)&buff, sizeof(buff));
    return buff;
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
