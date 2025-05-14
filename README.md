# Programos naudojimosi instrukcija

Šis projektas naudoja CMake kompiliavimui ir yra suskirstytas pagal aiškią struktūrą su `include/` ir `src/` katalogais.

## ✅ Reikalavimai

Įsitikinkite, kad turite įdiegtus šiuos įrankius savo sistemoje:

- **C++ kompiliatorius** (pvz., GCC arba MSVC)
- **CMake** (bent 3.25 versija)

> **Pastaba:** Git nebūtinas, jei jau turite projekto failus.

---

## 🔧 Projekto paruošimas ir paleidimas

### 1. Projekto failų paruošimas

Jeigu dar neturite projekto aplanke, galite jį atsisiųsti arba nusiklonuoti iš saugyklos:

```sh
git clone <projekto_git_nuoroda>
cd <projekto_katalogas>
```

### 2. Paleidimas naudojant run.bat (Windows)

Norėdami automatiškai sukompiliuoti ir paleisti programą, tiesiog dukart spustelėkite failą:

```sh
run.bat
```

Šis failas:

- automatiškai sukuria `build/` katalogą (jeigu jo dar nėra),
- sugeneruoja ir sukompiliuoja projektą naudojant CMake,
- paleidžia sukurtą `.exe` failą (`Pazymiu_Skaiciuokle.exe`).

---

### Alternatyvus rankinis paleidimas (jei reikia)

Jei norite viską daryti per komandų eilutę:

```sh
cmake -B build -S .
cmake --build build
build\Pazymiu_Skaiciuokle.exe
```

## 🧪 Testavimas

Catch2 testų failas (`tests.cpp`) yra projekte, tačiau testai **nėra** įtraukiami į automatinį kompiliavimą.

Jeigu reikia paleisti testus:

1. Atidarykite projektą Visual Studio Code aplinkoje.
2. Suraskite ir paleiskite `tests.cpp` failą rankiniu būdu su integruotu Catch2 palaikymu.

## 📁 Projekto struktūra

- `include/` – antraštiniai failai (.h), kuriuose aprašomos klasės ir funkcijų prototipai.
- `src/` – pagrindinis programos kodas (.cpp).
- `CMakeLists.txt` – CMake konfigūracijos failas, skirtas kompiliavimui.
- `run.bat` – skriptas Windows sistemai, kuris automatizuoja kompiliavimą ir paleidimą.
- `README.md` – ši naudojimosi instrukcija.

### Dokumentacija

- `Dokumentacija.pdf` – projekto dokumentacija.
- `Doxyfile` – Doxygen konfigūracijos failas, skirtas automatiškai generuoti projekto dokumentaciją.
- `html/` – Doxygen generuota HTML dokumentacija.
- `latex/` – Doxygen generuota LaTeX dokumentacija.

### Catch2 testavimas

- `catch2/` – Catch2 testavimo sistema.

---
---
---

## Vector ir std::vector klasių spartos palyginimas

Lentelėje pateikiami vidutiniai užpildymo laikai (sekundėmis), naudojant `push_back()` funkciją, su skirtingais `int` elementų kiekiais, taip pat nurodytas atminties realokacijų skaičius, kai vektorius pasiekia maksimalų dydį (100 000 000 elementų).

| Elementų skaičius | `std::vector` laikas (s) | `Vector` laikas (s) |
|-------------------|--------------------------|---------------------|
| 10 000            | 0,002                    | 0,001               |
| 100 000           | 0,004                    | 0,005               |
| 1 000 000         | 0,010                    | 0,020               |
| 10 000 000        | 0,021                    | 0,017               |
| 100 000 000       | 0,170                    | 0,230               |
| Realloc skaičius  | 25                       | 22                  |

### Išvada

Nors `Vector` klasė kai kuriais atvejais demonstruoja panašų ar net geresnį greitį nei `std::vector`, bendras našumas vis dėlto rodo, kad `std::vector` yra stabilesnis ir geriau pritaikytas didelio kiekio duomenų tvarkymui. Tai yra natūralu, atsižvelgiant į tai, kad `std::vector` yra plačiai optimizuotas ir testuotas sprendimas standartinėje C++ bibliotekoje.

<details>
<summary>Naudotas testavimo kodas (spausti čia kad peržiūrėti)</summary>

```cpp
unsigned int sz = 10000000;
Timer stdVecTime;
int rellacations = 0;
size_t prevCapacity = 0;
std::vector<int> v1;
for (int i = 1; i <= sz; ++i) {
v1.push_back(i);
if (v1.capacity() != prevCapacity) {
++rellacations;
prevCapacity = v1.capacity();
}
}
cout << "std::vector v1 uzpildymo laikas: " << stdVecTime.elapsed() << " sekundziu." << endl;
cout << "std::vector v1 relokaciju skaicius: " << rellacations << endl;
Timer myVecTime;
rellacations = 0;
prevCapacity = 0;
Vector<int> v2;
for (int i = 1; i <= sz; ++i) {
v2.push_back(i);
if (v2.capacity() != prevCapacity) {
++rellacations;
prevCapacity = v2.capacity();
}
}
cout << "Vector v2 uzpildymo laikas: " << myVecTime.elapsed() << " sekundziu." << endl;
cout << "Vector v2 relokaciju skaicius: " << rellacations << endl;
system("pause");
</details> ```
