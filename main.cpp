#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Jucator {
private:
    string nume;
    int varsta;
    string pozitie;
    int goluri;
    int paseDecisive;

public:
    Jucator(const string& nume, int varsta, const string& pozitie)
        : nume(nume), varsta(varsta), pozitie(pozitie), goluri(0), paseDecisive(0) {}

    Jucator(const Jucator& other) = default;
    Jucator& operator=(const Jucator& other) = default;
    ~Jucator() {}

    friend ostream& operator<<(ostream& os, const Jucator& jucator) {
        os << "Nume: " << jucator.nume << ", Varsta: " << jucator.varsta
           << ", Pozitie: " << jucator.pozitie
           << ", Goluri: " << jucator.goluri << ", Pase Decisive: " << jucator.paseDecisive;
        return os;
    }

    void marcheazaGol() {
        goluri++;
    }

    void oferaPasaDecisiva() {
        paseDecisive++;
    }


};


class Meci {
private:
    string adversar;
    int goluriPentru;
    int goluriImpotriva;

public:
    Meci(const string& adversar, int goluriPentru, int goluriImpotriva)
        : adversar(adversar), goluriPentru(goluriPentru), goluriImpotriva(goluriImpotriva) {}

    Meci(const Meci& other) = default;
    Meci& operator=(const Meci& other) = default;
    ~Meci() {}

    friend ostream& operator<<(ostream& os, const Meci& meci) {
        os << "Adversar: " << meci.adversar
           << ", Goluri Pentru: " << meci.goluriPentru
           << ", Goluri Impotriva: " << meci.goluriImpotriva;
        return os;
    }


};


class Antrenor {
private:
    string nume;
    int aniExperienta;

public:
    Antrenor(const string& nume, int aniExperienta)
        : nume(nume), aniExperienta(aniExperienta) {}

    Antrenor(const Antrenor& other) = default;
    Antrenor& operator=(const Antrenor& other) = default;
    ~Antrenor() {}

    friend ostream& operator<<(ostream& os, const Antrenor& antrenor) {
        os << "Nume: " << antrenor.nume
           << ", Ani de Experienta: " << antrenor.aniExperienta;
        return os;
    }

    void motiveazaJucatorii() {
        cout << "Antrenorul motiveaza jucatorii." << endl;
    }


};


class EchipaFotbal {
private:
    string numeEchipa;
    Antrenor antrenor;
    vector<Jucator> jucatori;
    vector<Meci> meciuriProgramate;

public:
    EchipaFotbal(const string& numeEchipa, const Antrenor& antrenor)
        : numeEchipa(numeEchipa), antrenor(antrenor) {}

    EchipaFotbal(const EchipaFotbal& other) = default;
    EchipaFotbal& operator=(const EchipaFotbal& other) = default;
    ~EchipaFotbal() {}

    void adaugaJucator(const Jucator& jucator) {
        jucatori.push_back(jucator);
    }

    void programeazaMeci(const Meci& meci) {
        meciuriProgramate.push_back(meci);
    }

    void afiseazaJucatori() const {
        for (const Jucator& jucator : jucatori) {
            cout << jucator << std::endl;
        }
    }

    void afiseazaMeciuri() const {
        for (const Meci& meci : meciuriProgramate) {
            std::cout << meci << std::endl;
        }
    }

    void motiveazaJucatorii() {
        antrenor.motiveazaJucatorii();
    }


};

int main() {
    Antrenor antrenor("Jose Mourinho", 20);
    EchipaFotbal echipa("Real Madrid", antrenor);

    Jucator jucator1("Cristiano Ronaldo", 38, "Atacant");
    Jucator jucator2("Lionel Messi", 36, "Atacant");
    Jucator jucator3("Neymar Jr.", 31, "Atacant");

    Meci meci1("Barcelona", 2, 1);
    Meci meci2("Liverpool", 3, 0);

    echipa.adaugaJucator(jucator1);
    echipa.adaugaJucator(jucator2);
    echipa.adaugaJucator(jucator3);

    echipa.programeazaMeci(meci1);
    echipa.programeazaMeci(meci2);

    cout << "Echipa de Fotbal: " << endl;
    cout << "Jucatori:\n";
    echipa.afiseazaJucatori();
    cout << "Meciuri:\n";
    echipa.afiseazaMeciuri();


   ifstream inputFile("tastatura.txt");
    if (inputFile.is_open()) {

    }

    return 0;
}