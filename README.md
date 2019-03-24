# Duomenu apdorojimas (2 oji užduotis)

## Idiegimas (Unix kompiuteryje)

- `https://github.com/vikuliukas/OOP_2_uzd.git`
- `cd OOP_2_uzd`
- `make`
- `./main`

## Versiju istorija
# [v0.51](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.51)

**Koreguota**

- Visoms versijoms (std::vector, std::list ir std::deque) pataisytos programos, kad jos iÅ¡trintu nereikalinus, ar jau nukopijuotus duomenis.
- IÅ¡ naujo daryti bandymai, kurie suraÅ¡yti faile bandymai.

# [v0.5](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.5)

***Prideta***

- Skirtingi aplankalai, kuriose sudÄ—ta skirtingos programos versijos naudojanÄios std::vector, std::list ir std::deque.

**Koreguota**

- Koreguota programos v0.41 versija su skirtingais konteineriais.
- Failas bandymai dabar saugo testavimÅ³ rezultatus, kurie rodo programos veikimo laikÄ… naudojant skirtingus konteinerius.
- Pataisytas Makefilas.
- Papildytas README failas.

# [v0.42](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.42)

**Koreguota**

- Vietoje rand() funkcijos naudojamas std::random_device.
- Ištrinta "atsitiktinis" funcija.
- Žmogus gali pasirinkti, kad sugeneruotu kelis failus.
- Rezultatų failuose studentai surikuoti pagal galutinį balą, o ne pagal pavardes.

# [v0.41](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.41)

**Koreguota**

- Pataysyta versija 0.4. Programa dabar surikuoja studentus pagal galutinius pažymius ir tada nukopijuoja i skirtingus vektorius pagal galutini bala.
- Perdaryti testai, kuriu rezultatai išsaugoti faile bandymai (programa užtrunka ilgiau skirstydama i skirtingus vektorius nei iš karto rašant i failus).

# [v0.4](https://github.com/vikuliukas/OOP_2_uzd/releases/tag/v0.4)

***Prideta***

- irasymas.cpp ir skaitymas.cpp (skirtingi cpp failai, ka butu lengviau atskirti kas vyksta kai žmogus nori ivesti ar nuskaityti duomenis)
- Funkcija "failu_generavimas", kuri sukuria faila su atsitiktiniais duomenimis.
- Programa pradeša jei faile yra per didelis skaicius prie pažymiu ar vietoje skaiciaus yra raide ir kurioje eiluteje yra tokia klaida.
- Pridetas failas, kuriame buvo atlikta programos veikimo greicio analize (darant analize žmogus ranka nenurodinejo ar nori nuskaityti nuo failo ar pan., tai buvo nurodyta programos viduje, kad skaiciavimai butu tikslesni).

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
