# Naudojimosi instrukcija

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

---
---

## Efektyvumo Tyrimai (v1.1)

Šiame skyriuje pateikiami išsamūs našumo testų rezultatai, lyginant struktūros (struct) ir klasės (class) implementacijas naudojant tą pačią trečią strategiją su fiksuotu konteineriu – vektoriumi (std::vector).

- **CPU:** i7-12700H; 2.70 GHz
- **RAM:** SODIMM; 16,0 GB
- **SSD:** Micron_2450; 954 GB

## 1. **Struktūros** našumo testavimas su vektoriumi, taikant trečią strategiją (programos veikimo greitis ir .exe failo dydis)

### 1.1. Be optimizavimo

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 1.31115          | 889 156          |
| `st1000000.txt`  | 10.5171          | 889 156          |

### 1.2. Naudojant -O1

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 1.15939          | 1 146 455        |
| `st1000000.txt`  | 8.29775          | 1 146 455        |

### 1.3. Naudojant -O2

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 1.14631          | 1 185 457        |
| `st1000000.txt`  | 7.91273          | 1 185 457        |

### 1.4. Naudojant -O3

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 1.10491          | 1 389 320        |
| `st1000000.txt`  | 7.56451          | 1 389 320        |

## 2. **Klasės** našumo testavimas su vektoriumi, taikant trečią strategiją (programos veikimo greitis ir .exe failo dydis)

### 2.1. Be optimizavimo

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 3.94945          | 1 057 102        |
| `st1000000.txt`  | 16.1117          | 1 057 102        |

### 2.2. Naudojant -O1

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 3.6686           | 1 251 771        |
| `st1000000.txt`  | 13.3784          | 1 251 771        |

### 2.3. Naudojant -O2

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 3.63383          | 1 434 705        |
| `st1000000.txt`  | 13.4336          | 1 434 705        |

### 2.4. Naudojant -O3

| Failas           | Laikas (s)       | Baitai (B)       |
|------------------|------------------|------------------|
| `st100000.txt`   | 3.62861          | 2 002 652        |
| `st1000000.txt`  | 13.1949          | 2 002 652        |

## 3. Išvados

Struktūros (`struct`) yra ženkliai greitesnės ir sukuria kompaktiškesnius vykdomuosius failus nei klasės (`class`), todėl jų naudojimas yra geresnis pasirinkimas našumo kritinėse sistemose, kur nereikalingas OOP abstrakcijos lygis.
