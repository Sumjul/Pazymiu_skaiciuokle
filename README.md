# Naujo funkcialumo aprašymas (v1.2)

## 📌 Metodai ir jų paskirtis

| Metodas                         | Paskirtis                                                                  |
|---------------------------------|----------------------------------------------------------------------------|
| `operator>>`                    | Leidžia įvesti studento duomenis per `cin` arba kitą `istream` srautą      |
| `operator<<`                    | Leidžia išvesti studento duomenis į `cout` arba kitą `ostream` srautą      |
| Kopijavimo konstruktorius       | Sukuria naują objektą iš esamo, išlaikydamas jo duomenis                   |
| Perkėlimo konstruktorius        | Efektyviai perkelia duomenis iš kito objekto                               |
| Kopijavimo priskyrimo operatorius | Priskiria vieno objekto reikšmes kitam                                   |
| Perkėlimo priskyrimo operatorius | Efektyviai perkelia reikšmes vienam objektui iš kito                      |

---

## 📥 Duomenų įvedimo būdai

| Būdas       | Paaiškinimas                                                                 |
|-------------|------------------------------------------------------------------------------|
| Rankinis    | Naudojama `cin >> student` sintaksė. Vartotojas įveda vardą, pavardę, pažymius |
| Automatinis | Studentų skaičius ir duomenys generuojami atsitiktinai                       |
| Iš failo    | Naudojama `ReadFromFile` funkcija. Duomenys skaitomi iš `.txt` failo         |

---

## 📤 Duomenų išvedimo būdai

| Tipas      | Paaiškinimas                                                                 |
|------------|------------------------------------------------------------------------------|
| Į ekraną   | Spausdinama per `operator<<` arba `printStudent()` funkciją                  |
| Į failą    | Naudojama `Output()` funkcija. Duomenys išvedami į `rezultatas.txt`          |

---
---

## Programos naudojimosi instrukcija

Šis projektas naudoja CMake kompiliavimui ir organizuoja kodą pagal standartinę struktūrą su atskirais include ir src katalogais.

## Reikalavimai

Prieš pradedant, įsitikinkite, kad turite įdiegtus šiuos įrankius:

- C++ kompiliatorius (pvz., GCC arba MSVC)

- CMake (bent jau 3.25 versija)

- Git (jei norite klonuoti iš saugyklos)

## Projekto paruošimas ir paleidimas

### Projekto klonavimas (jei reikia)

Jei projektas dar nėra jūsų kompiuteryje, galite jį nusiklonuoti naudodami komandą:

```sh
git clone <projekto_git_nuoroda>
cd <projekto_katalogas>
```

### Projekto kompiliavimas su CMake

Sukurkite naują katalogą, skirtą generuojamiems failams:

```sh
mkdir build

cd build
```

Generuokite projektą su CMake:

```sh
cmake ..
```

Paleiskite kompiliaciją:

```sh
cmake --build .
```

### Programos paleidimas

Po sėkmingo kompiliavimo galite paleisti programą:

```sh
./run
```

arba Windows sistemoje tiesiog dukart spustelėkite `run.bat` failą.

## Projekto struktūra

- `include/` – antraštiniai failai (.h, .hpp), kuriuose aprašomos klasės ir funkcijų prototipai.
- `src/` – pagrindinis programos kodas (.cpp).
- `CMakeLists.txt` – CMake konfigūracijos failas.
- `README.md` – ši naudojimosi instrukcija.
- `run.bat` – Windows skriptas greitam programos paleidimui.
