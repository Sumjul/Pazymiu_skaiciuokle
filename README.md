# Naujo funkcialumo aprašymas (v1.5)

## 🧬 Klasės struktūra

| Klasė     | Tipas     | Aprašymas                                                                 |
|-----------|-----------|--------------------------------------------------------------------------|
| `Human`   | Abstrakti | Bendra klasė visiems žmonėms, aprašo vardą, pavardę, turi virtualų metodą `print()` |
| `Student` | Išvestinė | Paveldi iš `Human`, aprašo studentų pažymius, egzaminą ir visą reikiamą logiką      |

## 🧪 Testų sistema

Visi testai iš **v1.2** versijos buvo **pakartotinai patikrinti**:

| Testas                         | Būsena     | Paaiškinimas                                                       |
|--------------------------------|------------|--------------------------------------------------------------------|
| Rule of Five testai            | ✅ Veikia  | Visi kopijavimo/perkėlimo metodai veikia kaip tikėtasi             |
| Operatoriai `>>` ir `<<`       | ✅ Veikia  | Įvedimas/išvedimas per srautus veikia korektiškai                  |
| `print()` per `Human*`         | ✅ Veikia  | Virtuali funkcija `print()` veikia per polimorfizmą                |
| Bandymas kurti `Human` objektą| ⛔ Užblokuota | Kompiliatorius blokuoja bandymą kurti `Human` objektą             |

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
