#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

enum class LimbajeProgramare
{
    C,
    JavaScript,
    Java,
    PHP,
    Python
};

ostream &operator<<(ostream &os, LimbajeProgramare limbaj)
{
    switch (limbaj)
    {
    case LimbajeProgramare::C:
        os << "C" << endl;
        break;
    case LimbajeProgramare::Java:
        os << "Java" << endl;
        break;
    case LimbajeProgramare::JavaScript:
        os << "JavaScript" << endl;
        break;
    case LimbajeProgramare::PHP:
        os << "PHP" << endl;
        break;
    case LimbajeProgramare::Python:
        os << "Python" << endl;
        break;
    }
    return os;
}

class IProgramator
{
public:
    virtual LimbajeProgramare *getLimbaje() = 0;
    virtual void setLimbaje(LimbajeProgramare *limbaje, int limbajeStiute) = 0;
    virtual bool getIsSeniorDeveloper() = 0;
    virtual void setIsSeniorDeveloper(bool isSeniorDeveloper) = 0;
    virtual int getCafeleConsumate() = 0;
    virtual void setCafeleConsumate(int cafeleConsumate) = 0;
};

class IDesigner
{
public:
    virtual bool getAbonamentFigmaActiv() = 0;
    virtual int getNrDeMockups() = 0;
    virtual void setAbonamentFigmaActiv(bool abonamentFigmaActiv) = 0;
    virtual void setNrDeMockups(int nrDeMockups) = 0;
};

class Angajat : public IProgramator, public IDesigner
{
protected:
    int id;
    string nume;
    double salariu;
    int vechime;
    int nrProiecte;

    // getter & setter pentru accesibilitate
    bool getAbonamentFigmaActiv() { return false; }
    int getNrDeMockups() { return 0; }
    void setAbonamentFigmaActiv(bool abonamentFigmaActiv) {}
    void setNrDeMockups(int nrDeMockups) {}
    LimbajeProgramare *getLimbaje()
    {
        LimbajeProgramare *limbaje = new LimbajeProgramare[0];
        return limbaje;
    }
    void setLimbaje(LimbajeProgramare *limbaje, int limbajeStiute) {}
    bool getIsSeniorDeveloper() { return false; }
    void setIsSeniorDeveloper(bool isSeniorDeveloper) {}
    int getCafeleConsumate() { return 0; }
    void setCafeleConsumate(int cafeleConsumate) {}

public:
    Angajat()
    {
        this->id = rand();
        this->nume = "George Carlin";
        this->salariu = 2000.5;
        this->vechime = 4;
        this->nrProiecte = 2;
    }

    Angajat(string nume, double salariu, int vechime, int nrProiecte)
    {
        this->id = rand();
        this->nume = nume;
        this->salariu = salariu;
        this->vechime = vechime;
        this->nrProiecte = nrProiecte;
    }

    Angajat(const Angajat &a)
    {
        this->id = a.id;
        this->nume = a.nume;
        this->salariu = a.salariu;
        this->vechime = a.vechime;
        this->nrProiecte = a.nrProiecte;
    }

    Angajat &operator=(const Angajat &a)
    {
        this->id = a.id;
        this->nume = a.nume;
        this->salariu = a.salariu;
        this->vechime = a.vechime;
        this->nrProiecte = a.nrProiecte;
        return *this;
    }

    string getNume()
    {
        return this->nume;
    }

    void setNume(string nume)
    {
        this->nume = nume;
    }

    int getId()
    {
        return this->id;
    }

    double getSalariu()
    {
        return this->salariu;
    }

    void setSalariu(double salariu)
    {
        this->salariu = salariu;
    }

    int getVechime()
    {
        return this->vechime;
    }

    void setVechime(int vechime)
    {
        this->vechime = vechime;
    }

    int getNrProiecte()
    {
        return this->nrProiecte;
    }

    void setNrProiecte(int nrProiecte)
    {
        this->nrProiecte = nrProiecte;
    }

    virtual void display(ostream &os)
    {
        os << "ID: " << this->id << endl;
        os << "Nume: " << this->nume << endl;
        os << "Salariu: " << this->salariu << endl;
        os << "Vechime: " << this->vechime << endl;
        os << "Numar de proiecte la care participa: " << this->nrProiecte << endl;
    }

    virtual void readInput(istream &is)
    {
        is >> this->nume;
        is >> this->salariu;
        is >> this->nrProiecte;
        is >> this->vechime;
    }

    friend ostream &operator<<(ostream &os, Angajat *a)
    {
        a->display(os);
        return os;
    }

    friend istream &operator>>(istream &is, Angajat *a)
    {
        a->readInput(is);
        return is;
    }

    virtual void serialize(ostream &os) const
    {
        os.write((char *)&id, sizeof(id));
        os.write(nume.c_str(), nume.size() + 1);
        os.write((char *)&salariu, sizeof(salariu));
        os.write((char *)&vechime, sizeof(vechime));
        os.write((char *)&nrProiecte, sizeof(nrProiecte));
    }

    static Angajat *deserialize(istream &is)
    {
        int id;
        is.read((char *)&id, sizeof(id));

        string nume;
        char ch;
        while (is.get(ch) && ch != '\0')
            nume += ch;

        double salariu;
        is.read((char *)&salariu, sizeof(salariu));

        int vechime;
        is.read((char *)&vechime, sizeof(vechime));

        int nrProiecte;
        is.read((char *)&nrProiecte, sizeof(nrProiecte));

        return new Angajat(nume, salariu, vechime, nrProiecte);
    }

    virtual ~Angajat()
    {
        cout << "Dealocare " << this->nume << endl;
    }
};

class Designer : public Angajat
{
private:
    bool abonamentFigmaActiv;
    int nrDeMockups;

    // getter & setter pentru accesibilitate
    LimbajeProgramare *getLimbaje()
    {
        LimbajeProgramare *limbaje = new LimbajeProgramare[0];
        return limbaje;
    }
    void setLimbaje(LimbajeProgramare *limbaje, int limbajeStiute) {}
    bool getIsSeniorDeveloper() { return false; }
    void setIsSeniorDeveloper(bool isSeniorDeveloper) {}
    int getCafeleConsumate() { return 0; }
    void setCafeleConsumate(int cafeleConsumate) {}

public:
    Designer(string nume, double salariu, int nrProiecte, int vechime, bool abonamentFigmaActiv, int nrDeMockups) : Angajat(nume, salariu, vechime, nrProiecte)
    {
        this->abonamentFigmaActiv = abonamentFigmaActiv;
        this->nrDeMockups = nrDeMockups;
    }

    Designer(string nume, double salariu, int nrProiecte, int vechime) : Angajat(nume, salariu, vechime, nrProiecte)
    {
        this->abonamentFigmaActiv = true;
        this->nrDeMockups = 8;
    }

    Designer(const Designer &d)
    {
        this->abonamentFigmaActiv = d.abonamentFigmaActiv;
        this->nrDeMockups = d.nrDeMockups;

        this->salariu = d.salariu;
        this->nume = d.nume;
        this->vechime = d.vechime;
        this->nrProiecte = d.nrProiecte;
    }

    Designer &operator=(const Designer &d)
    {
        this->abonamentFigmaActiv = d.abonamentFigmaActiv;
        this->nrDeMockups = d.nrDeMockups;

        this->salariu = d.salariu;
        this->nume = d.nume;
        this->vechime = d.vechime;
        this->nrProiecte = d.nrProiecte;
        return *this;
    }

    bool getAbonamentFigmaActiv()
    {
        return this->abonamentFigmaActiv;
    }

    int getNrDeMockups()
    {
        return this->nrDeMockups;
    }

    void setAbonamentFigmaActiv(bool abonamentFigmaActiv)
    {
        this->abonamentFigmaActiv = abonamentFigmaActiv;
    }

    void setNrDeMockups(int nrDeMockups)
    {
        this->nrDeMockups = nrDeMockups;
    }

    void display(ostream &os) override
    {
        Angajat::display(os);
        os << (this->abonamentFigmaActiv ? "Are abonament Figma activ" : "Nu are abonament Figma activ") << endl;
        os << "Numarul de mockup-uri lucrate: " << this->nrDeMockups << endl;
    }

    void readInput(istream &is)
    {
        Angajat::readInput(is);
        is >> this->abonamentFigmaActiv;
        is >> this->nrDeMockups;
    }

    friend ostream &operator<<(ostream &os, Designer *d)
    {
        d->display(os);
        return os;
    }

    friend istream &operator>>(istream &is, Designer *d)
    {
        d->readInput(is);
        return is;
    }

    virtual ~Designer()
    {
        cout << "Dealocare designer " << this->nume << endl;
    }
};

class Programator : public Angajat
{
private:
    LimbajeProgramare *limbaje;
    int limbajeStiute;
    bool isSeniorDeveloper;
    int cafeleConsumate;

    // getter & setter pentru accesibilitate
    bool getAbonamentFigmaActiv() { return false; }
    int getNrDeMockups() { return 0; }
    void setAbonamentFigmaActiv(bool abonamentFigmaActiv) {}
    void setNrDeMockups(int nrDeMockups) {}

public:
    Programator(string nume, double salariu, int nrProiecte, int vechime, LimbajeProgramare *limbaje, bool isSeniorDeveloper, int cafeleConsumate, int limbajeStiute) : Angajat(nume, salariu, vechime, nrProiecte)
    {
        this->limbajeStiute = limbajeStiute;
        delete[] this->limbaje;
        this->limbaje = new LimbajeProgramare[this->limbajeStiute];
        for (int i = 0; i < this->limbajeStiute; i++)
        {
            this->limbaje[i] = limbaje[i];
        }
        this->isSeniorDeveloper = isSeniorDeveloper;
        this->cafeleConsumate = cafeleConsumate;
    }

    Programator(string nume, double salariu, int nrProiecte, int vechime) : Angajat(nume, salariu, vechime, nrProiecte)
    {
        this->limbajeStiute = 0;
        this->limbaje = new LimbajeProgramare[0];
        this->isSeniorDeveloper = false;
        this->cafeleConsumate = 6;
    }

    Programator(const Programator &p)
    {
        this->limbajeStiute = p.limbajeStiute;
        delete[] this->limbaje;
        this->limbaje = new LimbajeProgramare[this->limbajeStiute];
        for (int i = 0; i < this->limbajeStiute; i++)
        {
            this->limbaje[i] = p.limbaje[i];
        }
        this->isSeniorDeveloper = p.isSeniorDeveloper;
        this->cafeleConsumate = p.cafeleConsumate;

        this->salariu = p.salariu;
        this->nume = p.nume;
        this->vechime = p.vechime;
        this->nrProiecte = p.nrProiecte;
    }

    Programator &operator=(Programator &p)
    {
        this->limbajeStiute = p.limbajeStiute;
        delete[] this->limbaje;
        this->limbaje = new LimbajeProgramare[this->limbajeStiute];
        for (int i = 0; i < this->limbajeStiute; i++)
        {
            this->limbaje[i] = p.limbaje[i];
        }
        this->isSeniorDeveloper = p.isSeniorDeveloper;
        this->cafeleConsumate = p.cafeleConsumate;

        this->salariu = p.salariu;
        this->nume = p.nume;
        this->vechime = p.vechime;
        this->nrProiecte = p.nrProiecte;
        return *this;
    }

    LimbajeProgramare *getLimbaje()
    {
        return this->limbaje;
    }

    void setLimbaje(LimbajeProgramare *limbaje, int limbajeStiute)
    {
        this->limbajeStiute = limbajeStiute;
        delete[] this->limbaje;
        this->limbaje = new LimbajeProgramare[this->limbajeStiute];
        for (int i = 0; i < this->limbajeStiute; i++)
        {
            this->limbaje[i] = limbaje[i];
        }
    }

    bool getIsSeniorDeveloper()
    {
        return this->isSeniorDeveloper;
    }

    void setIsSeniorDeveloper(bool isSeniorDeveloper)
    {
        this->isSeniorDeveloper = isSeniorDeveloper;
    }

    int getCafeleConsumate()
    {
        return this->cafeleConsumate;
    }

    void setCafeleConsumate(int cafeleConsumate)
    {
        this->cafeleConsumate = cafeleConsumate;
    }

    void display(ostream &os) override
    {
        Angajat::display(os);
        os << "Nr limbajelor de programare stiute: " << this->limbajeStiute << endl;
        os << "Limbaje stiute: " << endl;
        for (int i = 0; i < this->limbajeStiute; i++)
        {
            os << this->limbaje[i];
        }
        os << (this->isSeniorDeveloper ? "Este senior" : "Nu este senior") << endl;
        os << "Cafele consumate: " << this->cafeleConsumate << endl;
    }

    void readInput(istream &is) override
    {
        Angajat::readInput(is);
        is >> this->cafeleConsumate;
        is >> this->isSeniorDeveloper;
    }

    friend ostream &operator<<(ostream &os, Programator *p)
    {
        p->display(os);
        return os;
    }

    friend istream &operator>>(istream &is, Programator *p)
    {
        p->readInput(is);
        return is;
    }

    virtual ~Programator()
    {
        delete[] this->limbaje;
        cout << "Dealocare programator " << this->nume << endl;
    }
};

class CompanieIT
{
private:
    string denumire;
    double cifraDeAfaceri;
    Angajat **angajati;
    int length;

public:
    string getDenumire()
    {
        return this->denumire;
    }

    double getCifraDeAfaceri()
    {
        return this->cifraDeAfaceri;
    }

    Angajat **getAngajati()
    {
        return this->angajati;
    }

    int getLength()
    {
        return this->length;
    }

    void setDenumire(string denumire)
    {
        this->denumire = denumire;
    }

    void setCifraDeAfaceri(double cifraDeAfaceri)
    {
        this->cifraDeAfaceri = cifraDeAfaceri;
    }

    void setAngajati(Angajat **angajati, int length)
    {
        delete[] this->angajati;
        this->angajati = new Angajat *[length];
        for (int i = 0; i < length; i++)
        {
            this->angajati[i] = angajati[i];
        }
    }

    CompanieIT()
    {
        this->length = 0;
        this->angajati = new Angajat *[0];
        this->denumire = "Luxoft";
        this->cifraDeAfaceri = 50'000'000;
    }

    CompanieIT(string denumire, double cifraDeAfaceri, Angajat **angajati, int length)
    {
        this->denumire = denumire;
        this->cifraDeAfaceri = cifraDeAfaceri;
        delete[] this->angajati;
        this->length = length;
        this->angajati = new Angajat *[this->length];
        for (int i = 0; i < length; i++)
        {
            this->angajati[i] = angajati[i];
        }
        delete[] angajati;
    }

    CompanieIT(const CompanieIT &c)
    {
        this->denumire = c.denumire;
        this->cifraDeAfaceri = c.cifraDeAfaceri;
        delete[] this->angajati;
        this->length = c.length;
        this->angajati = new Angajat *[this->length];
        for (int i = 0; i < c.length; i++)
        {
            this->angajati[i] = c.angajati[i];
        }
    }

    CompanieIT &operator=(const CompanieIT &c)
    {
        this->denumire = c.denumire;
        this->cifraDeAfaceri = c.cifraDeAfaceri;
        delete[] this->angajati;
        this->length = c.length;
        this->angajati = new Angajat *[this->length];
        for (int i = 0; i < c.length; i++)
        {
            this->angajati[i] = c.angajati[i];
        }
        return *this;
    }

    void operator+=(Angajat *angajat)
    {
        Angajat **temp = new Angajat *[this->length + 1];

        for (int i = 0; i < this->length; i++)
        {
            temp[i] = this->angajati[i];
        }

        temp[this->length] = angajat;
        this->length++;

        delete[] this->angajati;
        this->angajati = temp;
    }

    void operator-=(Angajat *angajat)
    {
        Angajat **temp = new Angajat *[this->length - 1];

        int contor = 0;
        for (int i = 0; i < this->length; i++)
        {
            if (this->angajati[i]->getId() != angajat->getId())
            {
                temp[contor] = this->angajati[i];
                contor++;
            }
        }

        this->length--;
        delete[] this->angajati;
        this->angajati = temp;
    }

    void scriereAngajatiInFisierBinar()
    {
        ofstream wf("angajati.dat", ios::out | ios::binary);

        if (!wf)
        {
            cerr << "Nu se poate deschide fisierul" << endl;
        }
        else
        {
            wf.write((char *)&length, sizeof(length));

            for (int i = 0; i < length; ++i)
            {
                angajati[i]->serialize(wf);
            }

            wf.close();

            if (!wf.good())
            {
                cerr << "Eroare la scrierea in fisier" << endl;
            }
        }
    }

    void citireAngajatiDinFisierBinar()
    {
        ifstream rf("angajati.dat", ios::in | ios::binary);
        if (!rf)
        {
            cerr << "Nu se poate deschide fisierul" << endl;
        }
        else
        {
            rf.read((char *)&length, sizeof(length));

            angajati = new Angajat *[length];

            for (int i = 0; i < length; ++i)
            {
                angajati[i] = Angajat::deserialize(rf);
            }

            rf.close();

            if (!rf.good())
            {
                cerr << "Eroare la citirea din fisier" << endl;
            }
        }
    }

    friend ostream &operator<<(ostream &os, const CompanieIT &list)
    {
        for (int i = 0; i < list.length; i++)
        {
            os << list.angajati[i] << endl;
        }
        return os;
    }

    friend istream &operator>>(istream &is, CompanieIT &list)
    {
        is >> list.denumire;
        is >> list.cifraDeAfaceri;
        return is;
    }

    Angajat *operator[](int index)
    {
        if (index >= this->length)
        {
            throw out_of_range("Index was out of range");
        }
        return this->angajati[index];
    }

    ~CompanieIT()
    {
        delete[] this->angajati;
    }
};

int main()
{
    LimbajeProgramare *limbaje = new LimbajeProgramare[3];
    limbaje[0] = LimbajeProgramare::C;
    limbaje[1] = LimbajeProgramare::JavaScript;
    limbaje[2] = LimbajeProgramare::Python;
    Angajat *programator = new Programator("George Carlin", 4500, 5, 2, limbaje, false, 12, 3);
    Angajat *designer = new Designer("John Doe", 6000, 10, 8);
    Angajat *designer1 = new Designer("Jane Marcus", 1500, 1, 1, false, 4);
    Angajat *programator1 = new Programator("Tim Berners Lee", 5000, 9, 3);

    CompanieIT companie;
    companie += programator;
    // companie += designer;
    companie += designer1;
    companie += programator1;

    // companie.scriereAngajatiInFisierBinar();
    // companie.citireAngajatiDinFisierBinar();
    cout << companie << endl;

    delete[] limbaje;
    delete programator;
    delete designer;
    delete designer1;
    delete programator1;
    return 0;
}