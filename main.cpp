#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

class Persoana {
    /**
    Base class representing a person.

    Attributes:
        nume (str): The name of the person.
        varsta (int): The age of the person.
    */
protected:
    string nume;
    int varsta;

public:
    /**
    Constructor for the Persoana class.

    Args:
        nume (str): The name of the person.
        varsta (int): The age of the person.
    */
    Persoana(const string& nume, int varsta)
            : nume(nume), varsta(varsta) {}

    /**
    Virtual destructor for the Persoana class.
    */
    virtual ~Persoana() {}

    /**
    Pure virtual function to display details of the person.
    */
    virtual void afiseazaDetalii() const = 0;

    /**
    Pure virtual function to clone the person object.
    Returns:
        unique_ptr<Persoana>: A unique pointer to a new Persoana object.
    */
    virtual unique_ptr<Persoana> clone() const = 0;
};

class Jucator : public Persoana {
    /**
    Derived class representing a player.

    Attributes:
        pozitie (str): The player's position.
        goluri (int): The number of goals scored by the player.
        paseDecisive (int): The number of decisive passes made by the player.
    */
private:
    string pozitie;
    int goluri;
    int paseDecisive;

public:
    /**
    Constructor for the Jucator class.

    Args:
        nume (str): The name of the player.
        varsta (int): The age of the player.
        pozitie (str): The player's position.
    */
    Jucator(const string& nume, int varsta, const string& pozitie)
            : Persoana(nume, varsta), pozitie(pozitie), goluri(0), paseDecisive(0) {}

    /**
    Method to record a goal scored by the player.
    */
    void marcheazaGol() {
        goluri++;
    }

    /**
    Method to record a decisive pass made by the player.
    */
    void oferaPasaDecisiva() {
        paseDecisive++;
    }

    /**
    Overridden method to display details of the player.
    */
    void afiseazaDetalii() const override {
        cout << "Jucator: " << nume << ", Varsta: " << varsta
             << ", Pozitie: " << pozitie
             << ", Goluri: " << goluri << ", Pase Decisive: " << paseDecisive << endl;
    }

    /**
    Overridden method to clone the Jucator object.
    Returns:
        unique_ptr<Persoana>: A unique pointer to a new Jucator object.
    */
    unique_ptr<Persoana> clone() const override {
        return make_unique<Jucator>(*this);
    }
};

class Antrenor : public Persoana {
    /**
    Derived class representing a coach.

    Attributes:
        aniExperienta (int): The number of years of experience of the coach.
    */
private:
    int aniExperienta;

public:
    /**
    Constructor for the Antrenor class.

    Args:
        nume (str): The name of the coach.
        varsta (int): The age of the coach.
        aniExperienta (int): The number of years of experience of the coach.
    */
    Antrenor(const string& nume, int varsta, int aniExperienta)
            : Persoana(nume, varsta), aniExperienta(aniExperienta) {}

    /**
    Method to motivate the players.
    */
    void motiveazaJucatorii() const {
        cout << "Antrenorul motiveaza jucatorii." << endl;
    }

    /**
    Overridden method to display details of the coach.
    */
    void afiseazaDetalii() const override {
        cout << "Antrenor: " << nume << ", Varsta: " << varsta
             << ", Ani de Experienta: " << aniExperienta << endl;
    }

    /**
    Overridden method to clone the Antrenor object.
    Returns:
        unique_ptr<Persoana>: A unique pointer to a new Antrenor object.
    */
    unique_ptr<Persoana> clone() const override {
        return make_unique<Antrenor>(*this);
    }
};

class Spectator : public Persoana {
    /**
    Derived class representing a spectator.

    Attributes:
        locatie (str): The location of the spectator.
    */
private:
    string locatie;

public:
    /**
    Constructor for the Spectator class.

    Args:
        nume (str): The name of the spectator.
        varsta (int): The age of the spectator.
        locatie (str): The location of the spectator.
    */
    Spectator(const string& nume, int varsta, const string& locatie)
            : Persoana(nume, varsta), locatie(locatie) {}

    /**
    Overridden method to display details of the spectator.
    */
    void afiseazaDetalii() const override {
        cout << "Spectator: " << nume << ", Varsta: " << varsta
             << ", Locatie: " << locatie << endl;
    }

    /**
    Overridden method to clone the Spectator object.
    Returns:
        unique_ptr<Persoana>: A unique pointer to a new Spectator object.
    */
    unique_ptr<Persoana> clone() const override {
        return make_unique<Spectator>(*this);
    }
};

class EchipaFotbal {
    /**
    Class representing a football team.

    Attributes:
        numeEchipa (str): The name of the football team.
        liderEchipa (unique_ptr<Persoana>): A unique pointer to the team leader.
        membriEchipa (vector<unique_ptr<Persoana>>): Vector of unique pointers to team members.
    */
private:
    string numeEchipa;
    unique_ptr<Persoana> liderEchipa;
    vector<unique_ptr<Persoana>> membriEchipa;

public:
    /**
    Constructor for the EchipaFotbal class.

    Args:
        numeEchipa (str): The name of the football team.
        lider (unique_ptr<Persoana>): A unique pointer to the team leader.
    */
    EchipaFotbal(const string& numeEchipa, unique_ptr<Persoana> lider)
            : numeEchipa(numeEchipa), liderEchipa(move(lider)) {}

    /**
    Method to add team members to the football team.

    Args:
        membru (unique_ptr<Persoana>): A unique pointer to a team member.
    */
    void adaugaMembriEchipa(unique_ptr<Persoana> membru) {
        membriEchipa.push_back(move(membru));
    }

    /**
    Method to display details of the football team.
    */
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



    return 0;
}
