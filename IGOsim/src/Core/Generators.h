#pragma once

#include <string>

class Generators
{
public:
    Generators();

    static void genModule();

    ~Generators();

private:
    static bool getAnswer(std::string);
    static std::string getString(std::string);
    static double getDouble(std::string);
};

