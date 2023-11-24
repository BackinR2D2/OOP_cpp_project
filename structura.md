# Structura sistemului de gestiune companie IT

1. Clasa de baza: **Angajat**
   - int id; - generat aleator folosind libraria cstdlib si rand();
   - string nume;
   - double salariu;
   - int vechime;
   - int nrProiecte;
2. Clase derivate:
   1. **Programator**
      - LimbajeProgramare \*limbaje; - am folosit un enum cu limbaje de programare
      - int limbajeStiute; - numarul de limbaje de programare stiute
      - bool isSeniorDeveloper;
      - int cafeleConsumate;
   2. **Designer**
      - bool abonamentFigmaActiv;
      - int nrDeMockups;
3. Clasa care sa contina un vector cu elemente de tipul clasei de baza: **CompanieIT**
   - string denumire; - denumirea companiei
   - double cifraDeAfaceri;
   - Angajat \*\*angajati; - vectorul de angajati
   - int length; - dimensiunea vectorului de angajati
