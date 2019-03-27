# Duomenu apdorojimas (2 oji užduotis)

## Idiegimas (Unix kompiuteryje) naudojant clang kompiliatorių.

- `git clone https://github.com/vikuliukas/OOP_2_uzd.git`
- `cd OOP_2_uzd`
- `cd vector/deque arba list`
- `make`
- `./main`

## Versiju istorija

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
