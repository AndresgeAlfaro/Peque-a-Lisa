#include "Date.h"

Date::Date(int d, int m, int a) : dia(d), mes(m), annio(a) {
    if (m < 1 || m > 12) {
        std::cout << "ERROR EN EL ANNIO\n";
    }
    if (d < 1 || d > diasYMeses(m, a)) {
        std::cout << "ERROR EN EL DIA Y EN EL MES\n";
    }
}

int Date::getDia() const
{
    return dia;
}

int Date::getMes() const
{
    return mes;
}

int Date::getAnnio() const
{
    return annio;
}

void Date::imprimirDate() const
{
    std::cout << (dia < 10 ? "0" : "") << dia << "/" << (mes < 10 ? "0" : "") << mes << "/" << annio << std::endl;
}



int Date::diasYMeses(int mes, int annio) const
{
    switch (mes) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return esannioviciesto(annio) ? 29 : 28;
    default:
        std::cout << "ERROR EN LA FECHA";
    }
}
