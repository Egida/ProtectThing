#ifndef ARGPARSE_H
#define ARGPARSE_H

#include <string>

struct Option {
    bool verbose;
    std::string bind;
};

class ArgParse {
public:
    static Option parse(int count, const char* args[]);
};

#endif // ARGPARSE_H
