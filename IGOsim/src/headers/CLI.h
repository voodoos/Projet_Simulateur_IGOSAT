#pragma once
#include "HCI.h"
class CLI :
    public HCI
{
public:
    /*!
    * \fn static CLI& getInstance()
    * \brief Retourne l'instance unique de CLI
    */
    static CLI& getInstance()
    {
        static CLI instance;
        return instance;
    }
    virtual ~CLI();

    void logv(std::string) const;


private:
    CLI(logLevel ll = INFO) {};
    CLI(CLI const&);              /*!< À ne pas implementer */
    void operator=(CLI const&);     /*!< À ne pas implementer */
};

