#pragma once

#include <string>
#include <vector>

class Generators
{
public:
    Generators();

    static void genModule();

    ~Generators();

private:
    static void genModuleFiles(bool, std::string,
        std::vector<std::pair<std::string, double>>,
        std::vector<std::pair<std::string, double>>,
        std::vector<std::string>);

    static void genModXmlFile(std::string,
        std::vector<std::pair<std::string, double>>,
        std::vector<std::pair<std::string, double>>,
        std::vector<std::string>);
    static bool getAnswer(std::string);
    static std::string getString(std::string);
    static double getDouble(std::string);
    static int getInt(std::string);
};

