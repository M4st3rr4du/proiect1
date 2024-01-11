#ifndef ECHIPA_FOTBAL_H
#define ECHIPA_FOTBAL_H

#include <iostream>
#include <string>
#include <vector>
#include "Antrenor.h"
#include "Jucator.h"
#include "Meci.h"

class EchipaFotbal {
private:
    std::string numeEchipa;
    Antrenor antrenor;
    std::vector<Jucator*> jucatori;
    std::vector<Meci> meciuriProgramate;

public:
    EchipaFotbal(const std::string& numeEchipa, const Antrenor& antrenor);
    EchipaFotbal(const EchipaFotbal& other);
    EchipaFotbal& operator=(const EchipaFotbal& other);
    ~EchipaFotbal();

    void adaugaJucator(Jucator* jucator);
    void programeazaMeci(const Meci& meci);
    void afiseazaJucatori() const;
    void afiseazaMeciuri() const;
    void motiveazaJucatorii();
};

#endif // ECHIPA_FOTBAL_H