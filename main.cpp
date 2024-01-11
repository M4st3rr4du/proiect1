#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

class Persoana {
protected:
    string nume;
    int varsta;

public:
    Persoana(const string& nume, int varsta)
            : nume(nume), varsta(varsta) {}

    virtual ~Persoana() {}

    virtual void afiseazaDetalii() const = 0;
    virtual unique_ptr<Persoana> clone() const = 0;
};

class Jucator : public Persoana {
private:
    string pozitie;
    int goluri;
    int paseDecisive;

public:
    Jucator(const string& nume, int varsta, const string& pozitie)
            : Persoana(nume, varsta), pozitie(pozitie), goluri(0), paseDecisive(0) {}

    void marcheazaGol() {
        goluri++;
    }

    void oferaPasaDecisiva() {
        paseDecisive++;
    }

    void afiseazaDetalii() const override {
        cout << "Jucator: " << nume << ", Varsta: " << varsta
             << ", Pozitie: " << pozitie
             << ", Goluri: " << goluri << ", Pase Decisive: " << paseDecisive << endl;
    }

    unique_ptr<Persoana> clone() const override {
        return make_unique<Jucator>(*this);
    }
};

class Antrenor : public Persoana {
private:
    int aniExperienta;

public:
    Antrenor(const string& nume, int varsta, int aniExperienta)
            : Persoana(nume, varsta), aniExperienta(aniExperienta) {}

    void motiveazaJucatorii() const {
        cout << "Antrenorul motiveaza jucatorii." << endl;
    }

    void afiseazaDetalii() const override {
        cout << "Antrenor: " << nume << ", Varsta: " << varsta
             << ", Ani de Experienta: " << aniExperienta << endl;
    }

    unique_ptr<Persoana> clone() const override {
        return make_unique<Antrenor>(*this);
    }
};

class Spectator : public Persoana {
private:
    string locatie;

public:
    Spectator(const string& nume, int varsta, const string& locatie)
            : Persoana(nume, varsta), locatie(locatie) {}

    void afiseazaDetalii() const override {
        cout << "Spectator: " << nume << ", Varsta: " << varsta
             << ", Locatie: " << locatie << endl;
    }

    unique_ptr<Persoana> clone() const override {
        return make_unique<Spectator>(*this);
    }
};

class EchipaFotbal {
private:
    string numeEchipa;
    unique_ptr<Persoana> liderEchipa;
    vector<unique_ptr<Persoana>> membriEchipa;

public:
    EchipaFotbal(const string& numeEchipa, unique_ptr<Persoana> lider)
            : numeEchipa(numeEchipa), liderEchipa(move(lider)) {}

    void adaugaMembriEchipa(unique_ptr<Persoana> membru) {
        membriEchipa.push_back(move(membru));
    }

    void afiseazaDetaliiEchipa() const {
        cout << "Echipa de Fotbal: " << numeEchipa << endl;
        cout << "Liderul Echipei:\n";
        liderEchipa->afiseazaDetalii();
        cout << "Membrii Echipei:\n";
        for (const auto& membru : membriEchipa) {
            membru->afiseazaDetalii();
        }
    }
};

int main() {
    // ...

    // Adaugare clase derivate in clasa de baza EchipaFotbal
    unique_ptr<Persoana> lider = make_unique<Antrenor>("Jose Mourinho", 50, 20);
    EchipaFotbal echipa("Real Madrid", move(lider));

    unique_ptr<Persoana> jucator1 = make_unique<Jucator>("Cristiano Ronaldo", 38, "Atacant");
    unique_ptr<Persoana> jucator2 = make_unique<Jucator>("Lionel Messi", 36, "Atacant");
    unique_ptr<Persoana> jucator3 = make_unique<Jucator>("Neymar Jr.", 31, "Atacant");

    echipa.adaugaMembriEchipa(move(jucator1));
    echipa.adaugaMembriEchipa(move(jucator2));
    echipa.adaugaMembriEchipa(move(jucator3));

    unique_ptr<Persoana> spectator1 = make_unique<Spectator>("Fan1", 25, "Tribuna A");
    unique_ptr<Persoana> spectator2 = make_unique<Spectator>("Fan2", 30, "Tribuna B");

    echipa.adaugaMembriEchipa(move(spectator1));
    echipa.adaugaMembriEchipa(move(spectator2));

    echipa.afiseazaDetaliiEchipa();

    // ...

    return 0;
}
