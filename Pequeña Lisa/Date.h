#ifndef DATE_H
#define DATE_H
#include "Includes.h"

class Date {

public:

    Date(int , int , int);

    int getDia() const;

    int getMes() const;

    int getAnnio() const;

    void imprimirDate() const;

private:

    int dia;
    int mes;
    int annio;

    bool esannioviciesto(int annio) const {
        return (annio % 4 == 0 && annio % 100 != 0) || (annio % 400 == 0);
    }

    int diasYMeses(int, int ) const;


};

#endif // !DATE_H


