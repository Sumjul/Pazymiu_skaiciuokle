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

## 1. **Struktūros** našumo testavimas su vektoriumi, taikant trečią strategiją

### 1.1. Be optimizavimo (greitis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.2. Be optimizavimo (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.3. Su -O1 (gretis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.4. Su -O1 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.5. Su -O2 (gretis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.6. Su -O2 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.7. Su -O3 (greitis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 1.8. Su -O3 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

## 2. **Klasės** našumo testavimas su vektoriumi, taikant trečią strategiją

### 2.1. Be optimizavimo (greitis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.2. Be optimizavimo (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.3. Su -O1 (gretis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.4. Su -O1 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.5. Su -O2 (gretis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.6. Su -O2 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.7. Su -O3 (greitis)

| Failas           | Laikas (s)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

### 2.8. Su -O3 (failo dydis)

| Failas           | Baitai (B)       |
|------------------|------------------|
| `st100000.txt`   |           |
| `st1000000.txt`  |           |

## 3. Išvados
