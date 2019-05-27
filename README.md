﻿# Duomenu apdorojimas (2 oji užduotis)

## Idiegimas (Unix kompiuteryje).

- `git clone https://github.com/vikuliukas/OOP_3_uzd.git`
- `cd OOP_3_uzd`
- `make`
- `./main`

## Instrukcijos

- Pasirinkite kiek failų norite sugeneruoti, jei to daryti nenorite įveskite 0.
- Pasirinkite ar norite duomenis nuskaityti nuo failo ar suvesti ranka (suvedimui ranka įveskite 0, nuskaitimui nuo failo įveskite 1).
- Jei duomenis vedate ranka, nustoti vesti duomenis galite vietoje studento vardo įvedę 0.
- Jei duomenis skaitote nuo failo, tada įveskite failo pavadinimą (pvz. kursiokai1).
- Pasirinkite ar galutinį balą skaičiuoti pagal vidurį ar medianą (įveskite 0 - pagal vidurki, 1 - pagal mediana).

## Versiju istorija

# [v2.0](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v2.0)

- Google Unit Tests

```shell
#include "struktura.h"
#include "funkcijos.cpp"
#include "operatoriai.cpp"
#include <gtest/gtest.h>

studentas a;

TEST(ND_rezultatai, ar_vectorius_tuscias)
{
    ASSERT_EQ(0, a.ndrez_ar_tuscias());
}

TEST(ND_rezultatai, rezultatu_suma)
{
    ASSERT_EQ(24, a.ndrez_suma());
}

TEST(ND_rezultatai, rezultatu_skaicius)
{
    ASSERT_EQ(6, a.ndrez_dydis());
}

TEST(galutinis, skaiciuojant_pagal_mediana)
{
    ASSERT_EQ(5.6, mediana(a));
}

TEST(galutinis, skaiciuojant_pagal_vidurki)
{
    ASSERT_EQ(5.8, vidurkis(a));
}

int main(int argc, char **argv) {
    a.vardas("Viktorija");
    a.pavarde("Kabelyte");
    a.ndrez(1);
    a.ndrez(2);
    a.ndrez(3);
    a.ndrez(4);
    a.ndrez(5);
    a.ndrez(9);
    a.egzaminorez(7);

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
Gauti rezultatai:

```shell
[==========] Running 5 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from ND_rezultatai
[ RUN      ] ND_rezultatai.ar_vectorius_tuscias
[       OK ] ND_rezultatai.ar_vectorius_tuscias (0 ms)
[ RUN      ] ND_rezultatai.rezultatu_suma
[       OK ] ND_rezultatai.rezultatu_suma (0 ms)
[ RUN      ] ND_rezultatai.rezultatu_skaicius
[       OK ] ND_rezultatai.rezultatu_skaicius (0 ms)
[----------] 3 tests from ND_rezultatai (3 ms total)

[----------] 2 tests from galutinis
[ RUN      ] galutinis.skaiciuojant_pagal_mediana
[       OK ] galutinis.skaiciuojant_pagal_mediana (0 ms)
[ RUN      ] galutinis.skaiciuojant_pagal_vidurki
[       OK ] galutinis.skaiciuojant_pagal_vidurki (0 ms)
[----------] 2 tests from galutinis (2 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 2 test cases ran. (9 ms total)
[  PASSED  ] 5 tests.
```
***Prideta***

- Pridėtas katalogas `doxygen`, kuriame galima rasti programos dokumentaciją padaryta naudojant Doxygen.

**Koreguota**

- Pakeistos funkcijos `vidurkis` ir `mediana`, kad būtu lengviau daryti unit testus.

# [v1.5](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v1.5)

***Prideta***

- Pridėta abstrakčioji bazinė klasė  `zmogus`.

**Koreguota**

- Koreguota klasė `studentas`.

# [v1.21](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v1.21)

***Prideta***

- Pridėtas friend operatorius <<.

# [v1.2](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v1.2)

***Prideta***

- Pridėti operatoriai >,>=,<,<=,==,=!;
- Pridėtas failas operatoriai.cpp, kur bus sudėtos visos mano sukurtų operatorių funkcijos.

**Koreguota**

- Panaikinta funkcija Pagal_Galutini, vietoje jos naudojamas naujas operatorius >;
- Pakoreguotas makefile, jame priddėtas failas operatoriai.cpp.
- Koreguotas ReadMe failas.

# [v1.1](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v1.1)

- Palyginimas tarp struct ir class:

    Naudojant struct:
       ` Kai studentų skaičius 1000, visa programa užtruko 0.520879 sek.`
       ` Kai studentų skaičius 10000, visa programa užtruko 5.03412 sek.`
       ` Kai studentų skaičius 100000, visa programa užtruko 50.4217 sek.`

    Naudojant class:
       ` Kai studentų skaičius 1000, visa programa užtruko 0.536229 sek.`
       ` Kai studentų skaičius 10000, visa programa užtruko 5.35838 sek.`
       ` Kai studentų skaičius 100000, visa programa užtruko 52.5402 sek.`

- Palyginimas tarp skirtinų optimizacijų:

    Nenaudonat optimizacijos:
       ` Kai studentų skaičius 10000, visa programa užtruko  5.38348 sek. `
       ` Kai studentų skaičius 100000, visa programa užtruko 52.9167 sek. `

    -O1 :
       ` Kai studentų skaičius 10000, visa programa užtruko 4.12694 sek. `
       ` Kai studentų skaičius 100000, visa programa užtruko  40.2847 sek. `

    -O2 :
       ` Kai studentų skaičius 10000, visa programa užtruko 1.9451 sek. `
       ` Kai studentų skaičius 100000, visa programa užtruko 18.7614 sek. `

    -O3 :
       ` Kai studentų skaičius 10000, visa programa užtruko 2.00216 sek. `
       ` Kai studentų skaičius 100000, visa programa užtruko 19.1879 sek. `
    
**Koreguota**

- Iš struct pakeista į class.
- Pakoreguotos funkcijos, kad veiktu ir su class.

#Papildoma užduotis
# [p1.0](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/p1.0)

Papilodmos užduoties įdiegimas (Unix kompiuteryje) naudojant clang kompiliatorių.
- `git clone https://github.com/vikuliukas/OOP_2_uzd.git`
- `cd OOP_2_uzd`
- `cd Papildoma`
- `cd vector/deque`
- `make`
- `./main`
Instrukcijos:
- Pasirinkite kiek failų norite sugeneruoti, jei to daryti nenorite įveskite 0.
- Pasirinkite ar norite duomenis nuskaityti nuo failo ar suvesti ranka (suvedimui ranka įveskite 0, nuskaitimui nuo failo įveskite 1).
- Jei duomenis vedate ranka, nustoti vesti duomenis galite vietoje studento vardo įvedę 0.
- Jei duomenis skaitote nuo failo, tada įveskite failo pavadinimą (pvz. kursiokai1).
- Pasirinkite ar galutinį balą skaičiuoti pagal vidurį ar medianą (įveskite 0 - pagal visdurki, 1 - pagal mediana).
- Pasirinkite ar norite naudoti funkciją raskMinksrus(), ar iterpkKieti() (įveskite 0 - funkcijai raskMinkstus(), 1 - funkcijai iterpkKietus()).
- Programos įvykdymo laikai surašyti faile "bandymai".
Išvados:
- Jei naudojate std::vector, tada funkcija raskMinkstus() yra efektivesnė nei funkcija iterpkKietus().
- Jei naudojate std::deque, tada funkcija iterpkKietus() yra efektivesnė nei funkcija raskMinkstus().
- Jeigu jums reikia įterpti duomenis į konteinerio pradžią, tada std::deque turi funkciją, kuri yra skirta būtent tam.

***Prideta***

- Pridėtos funkcijos raskMinkstus ir iterpkKieta.
- Pridėta galimybė pasirinkti kiek pažymiu kiekvienas studentas turės sugeneruotuose failuose.
- Pridėta galimybė įvesti failo, iš kurio norite nuskaityti duomenis, pavadinimą.
- Pridėtas failas "bandymai", kuriame surašyti visi testavimo rezultatai.

**Koreguota**

- Pakeista spausdinmo funkcija.

# [v1.0](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v1.0)

***Prideta***

- Pridėta funkcija strategija_2.

**Koreguota**

- Fukcijos skaitymas pavadinimas pakeistas į strategija_1.
- Funkcijose vidurkis ir mediana galutiniam balui skaičiuoti pridėta round funcija (nes jei galutinis balas 4,9999 tada jis nepatenka į šaunuolius, tačiau output yra 5,00 nes suapvalina funkcija std::setprecision).
- Padaryti bandymai su skirtingomis strategijomis, tačiau laikas nelabai skiriasi, nes programoje abiem atvejais surikiuoja galutiniu balus ir tik tada juos perkialia į skirtingus konteinerius.

# [v0.52](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.52)

- Pataisytos visos programos versijos su skirtingais konteineriais pagal 0.42 versiją.
- Panaudoti duomenys ištrinami.

# [v0.51](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.51)

**Koreguota**

- Pataisyta versija 0.5, kad panaudoti duomenys būtu ištrinti.

# [v0.5](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.5)

***Prideta***

- Skirtingi aplankalai, kuriose sudėta skirtingos programos versijos naudojančios std::vector, std::list ir std::deque.

**Koreguota**

- Koreguota programos v0.41 versija su skirtingais konteineriais.
- Failas bandymai dabar saugo testavimų rezultatus, kurie rodo programos veikimo laiką naudojant skirtingus konteinerius.
- Pataisytas Makefilas.
- Papildytas README failas.

# [v0.42](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.42)

**Koreguota**

- Pakeista funkcija rand() į std::random_device.
- Žmogus gali pasirinkti kiek failų nori sugeneruoti (seniau galėjo tik 1).
- Ištrintos funcijos atsitiktinis ir pagal_pavarde.
- Rezultatų faile mokiniai surušiuoti pagal galutinius pažymius (seniau buvo pagal pavardes).

# [v0.41](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.41)

**Koreguota**

- Pataysyta versija 0.4. Programa dabar surikuoja studentus pagal galutinius pažymius ir tada nukopijuoja i skirtingus vektorius pagal galutini bala.
- Perdaryti testai, kuriu rezultatai išsaugoti faile bandymai (programa užtrunka ilgiau skirstydama i skirtingus vektorius nei iš karto rašant i failus).

# [v0.4](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.4)

***Prideta***

- irasymas.cpp ir skaitymas.cpp (skirtingi cpp failai, ka butu lengviau atskirti kas vyksta kai žmogus nori ivesti ar nuskaityti duomenis)
- Funkcija "failu_generavimas", kuri sukuria faila su atsitiktiniais duomenimis.
- Programa praneša jei faile yra per didelis skaicius prie pažymiu ar vietoje skaiciaus yra raide ir kurioje eiluteje yra tokia klaida.
- Pridetas failas "bandymai", kuriame buvo atlikta programos veikimo greicio analize (darant analize žmogus ranka nenurodinejo ar nori nuskaityti nuo failo ar pan., tai buvo nurodyta programos viduje, kad skaiciavimai butu tikslesni).

**Koreguota**

- Pataisyta, kad programa praneštu žmogui jei ka ivede neteisingai (dabar nebera problemos ir su pvz a1).
- Pataisytos funkcijos mediana ir vidurkis.
- Funcija "spausdinimas" neišveda rezultato i ekrana o išsaugo skirtinguose failuose pagal galutini bala.
- Pakeista biblioteka iš ctime i chrono.
- Pataisytas Makefilas.
- Papildytas README failas.

# [v0.3](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.3)

***Prideta***

-funcijos.cpp ir struktura.h

**Koreguota**

- Pakeista, kad programa praneštu žmogui, jei vietoje skaiciaus ivede raide ar netinkanti skaiciu ir leidžia ivesti iš naujo. (taciau yra problema jei reikia ivesti 1 o žmogus iveda pvz. a1)
- Duomenu skaitymo iš failo funkcija, programa praneša jei neranda failo.
- Pakeistas Makefilas.
- Papildytas README failas.

# [v0.2](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.2)

***Prideta***

- Duomenu skaitymo nuo failo funkcija.
- Funkcija, kuri pavardes surušiuoja abeceles tvarka.

**Koreguota**

- Rezultatus atsdausdina išlygiuotai pagal ilgiausia varda ir pavarde.
- Papildytas README failas.

# [v0.1](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.1)
	
***Prideta***

- Pirmine programos versija.
