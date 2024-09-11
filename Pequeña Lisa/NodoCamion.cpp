#include "NodoCamion.h"

NodoCamion::NodoCamion(Camion* _data): data(_data), next(nullptr) {}

Camion* NodoCamion::getData()
{
    return data;
}

NodoCamion* NodoCamion::getNext()
{
    return next;
}

void NodoCamion::setNext(NodoCamion* _next){
    this->next = next;
}
