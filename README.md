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
