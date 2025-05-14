# > Programos naudojimosi instrukcija <

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

## **>Testavimo rezultatai (v3.0)<**

**Testavimo sąlygos:**

- CPU: i7-12700H; 2.70 GHz
- RAM: SODIMM; 16,0 GB
- SSD: Micron_2450; 954 GB
- Optimizavimas: `-O3`
- **Testavimo metodas:** Kiekvienas testas buvo atliekamas kelis kartus (ne mažiau nei tris) ir pateikiami laikų vidurkiai, gauti iš kelių bandymų. Laikai matuojami nuo programos pradžios iki pabaigos, apimant visus ir `std::vector` ir `Vector` veiksmus (skaitymas, skirstymas į grupes, rūšiavimas ir t. t.).

## 1. `std::vector` ir `Vector` klasių spartos palyginimas su skirtingais studentų įrašų kiekiais

### 1.1. Naudojant `std::vector`

| Failas           | Įrašų kiekis | Laikas (s)  |
|------------------|--------------|-------------|
| st100000.txt     | 100 000      | 0.805       |
| st1000000.txt    | 1 000 000    | 5.809       |
| st10000000.txt   | 10 000 000   | 80.505      |

### 1.2. Naudojant `Vector`

| Failas           | Įrašų kiekis | Laikas (s)  |
|------------------|--------------|-------------|
| st100000.txt     | 100 000      | 0.725       |
| st1000000.txt    | 1 000 000    | 5.850       |
| st10000000.txt   | 10 000 000   | 82.105      |

### 1.3. Išvada

Testavimo rezultatai parodė, kad `std::vector` ir `Vector` klasės pasižymi labai panašiu veikimo greičiu. Nors `std::vector` šiek tiek lenkia apdorojant labai didelius duomenų kiekius, `Vector` klasė taip pat demonstruoja stabilų ir pakankamai greitą veikimą.

## 2. `std::vector` ir `Vector` klasių spartos palyginimas naudojant `push_back()` funkciją

Lentelėje pateikiami rezultatai testų naudojant `push_back()` funkciją, su skirtingais `int` elementų kiekiais, taip pat nurodytas atminties realokacijų skaičius, kai vektorius pasiekia maksimalų dydį (100 000 000 elementų).

| Elementų skaičius | `std::vector` laikas (s) | `Vector` laikas (s) |
| ----------------- | ------------------------ | ------------------- |
| 10 000            | 0,002                    | 0,001               |
| 100 000           | 0,004                    | 0,005               |
| 1 000 000         | 0,010                    | 0,020               |
| 10 000 000        | 0,021                    | 0,017               |
| 100 000 000       | 0,170                    | 0,230               |
| Realloc skaičius  | 25                       | 22                  |

### 2.1. Išvada

Nors `Vector` klasė kai kuriais atvejais demonstruoja panašų ar net geresnį greitį nei `std::vector`, bendras našumas vis dėlto rodo, kad `std::vector` yra stabilesnis ir geriau pritaikytas didelio kiekio duomenų tvarkymui. Tai yra natūralu, atsižvelgiant į tai, kad `std::vector` yra plačiai optimizuotas ir testuotas sprendimas standartinėje C++ bibliotekoje.

<details>
<summary>2.2. Naudotas testavimo kodas (spausti čia kad peržiūrėti)</summary>
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
} }
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
} }
cout << "Vector v2 uzpildymo laikas: " << myVecTime.elapsed() << " sekundziu." << endl;
cout << "Vector v2 relokaciju skaicius: " << rellacations << endl;
system("pause");
</details> ```

## **>Vector klasės funkcijų aprašymas (v3.0)<**

## 1.1. Funkcijos pavadinimas

`push_back(const T&)`

## 1.2. Funkcijos paskirtis

Ši funkcija prideda naują elementą į vektoriaus pabaigą.

## 1.3. Veikimo principas

Jeigu konteinerio talpa yra pakankama, naujas elementas pridedamas į data[size], o size padidinamas vienetu. Jei talpa viršyta, iškviečiamas `reserve()`, talpa padidinama, sukuriamas naujas masyvas, esami elementai perkeliami, ir tada naujas elementas pridedamas.

## 1.4. Testavimo pavyzdys

```cpp
Vector<std::string> letters;
std::vector<std::string> std_letters;
letters.push_back("abc");
std_letters.push_back("abc");
REQUIRE(letters.size() == std_letters.size());
for (size_t i = 0; i < letters.size(); ++i) {
REQUIRE(letters[i] == std_letters[i]);
}
```

## 2.1. Funkcijos pavadinimas

`pop_back()`

## 2.2. Funkcijos paskirtis

Pašalina paskutinį elementą iš vektoriaus.

## 2.3. Veikimo principas

Funkcija sumažina `size_` reikšmę vienetu, efektyviai pašalindama paskutinį elementą. Jei T yra klasė, jos destruktorius turėtų būti iškviestas.

## 2.4. Testavimo pavyzdys

```cpp
Vector<std::string> pop_back_test{"one", "two", "three"};
std::vector<std::string> std_pop_back{"one", "two", "three"};
pop_back_test.pop_back();
std_pop_back.pop_back();
REQUIRE(pop_back_test.size() == std_pop_back.size());
for (size_t i = 0; i < pop_back_test.size(); ++i) {
REQUIRE(pop_back_test[i] == std_pop_back[i]);
}
```

## 3.1. Funkcijos pavadinimas

`resize(int newSize)`

## 3.2. Funkcijos paskirtis

Keičia vektoriaus dydį į nurodytą `newSize`.

## 3.3. Veikimo principas

Jeigu `newSize` yra didesnis nei esamas dydis, vektorius praplečiamas ir nauji elementai inicijuojami T() reikšme. Jei `newSize` mažesnis – pertekliniai elementai pašalinami.

## 3.4. Testavimo pavyzdys

```cpp
Vector<int> v;
REQUIRE(v.size() == 0);
REQUIRE(v.capacity() > 0);
v.resize(5);
REQUIRE(v.size() == 5);
REQUIRE(v[4] == 0);
```

## 4.1. Funkcijos pavadinimas

`operator[](int index)`

## 4.2. Funkcijos paskirtis

Leidžia prieiti prie elemento pagal jo indeksą.

## 4.3. Veikimo principas

Tikrina, ar indeksas yra galiojantis (0 ≤ index < size), kitu atveju meta išimtį. Grąžina nuorodą į atitinkamą `data_` masyvo elementą.

## 4.4. Testavimo pavyzdys

```cpp
Vector<int> numbers{2, 4, 6, 8};
std::vector<int> std_numbers{2, 4, 6, 8};
REQUIRE(numbers[1] == 4);
numbers[0] = 5;
std_numbers[0] = 5;
REQUIRE(numbers[0] == 5);
REQUIRE(std_numbers[0] == 5);
```

## 5.1. Funkcijos pavadinimas

`insert(int index, const T& value)`

## 5.2. Funkcijos paskirtis

Įterpia elementą į pasirinktą poziciją.

## 5.3. Veikimo principas

Jeigu reikia – plečia talpą `reserve`, po to perkelia visus elementus į dešinę nuo `index`, įterpia naują reikšmę ir padidina `size_`.

## 5.4. Testavimo pavyzdys

```cpp
Vector<int> ins_vec{1, 3, 4};
std::vector<int> ins_std_vec{1, 3, 4};
ins_vec.insert(1, 2);
ins_std_vec.insert(ins_std_vec.begin() + 1, 2);
REQUIRE(ins_vec.size() == ins_std_vec.size());
for (size_t i = 0; i < ins_vec.size(); ++i) {
REQUIRE(ins_vec[i] == ins_std_vec[i]);
}
```

## 6.1. Funkcijos pavadinimas

`clear()`

## 6.2. Funkcijos paskirtis

Pašalina visus vektoriaus elementus.

## 6.3. Veikimo principas

Nustato `size_ = 0`.

## 6.4. Testavimo pavyzdys

```cpp
std::vector<int> clearVec{1, 2, 3};
REQUIRE(clearVec.size() == 3);
clearVec.clear();
REQUIRE(clearVec.size() == 0);
REQUIRE(clearVec.empty() == true);
```
