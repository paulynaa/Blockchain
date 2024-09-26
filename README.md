# Užduoties aprašymas
## Bendri reikalavimai
1. Maišos funkcijos įėjimas bet kokio dydžio simbolių eilutė.
2. Maišos funkcijos išėjimas to paties, fiksuoto, dydžio rezultatas.
3. Maišos funkcija yra deterministinės.
4. Maišos funkcijos hash‘as bet kokiai input'o reikšmei yra apskaičiuojamas
greitai - efektyviai.
5. Iš hash funkcijos rezultato praktiškai neįmanoma atgaminti pradinio įvedimo.
6. Maišos funkcija yra atspari "kolizijai".
7. Bent minimaliai pakeitus įvedimą, pvz., vietoj "Lietuva" pateikus "lietuva", maišos
funkcijos rezultatas-maišos kodas turi skirtis iš esmės.

### Versijai 0.1 pavyko įgyvendinti šiuos reikalavimus: 1, 2, 3, 

## Reikalavimai versijai v0.1
1. Realizuoti hash'avimo generatorių C++ programavimo kalboje.
2. Programos realizavimas turi būti versijuojamas (pvz. v0.1 , v0.2 ir t.t.) git'e bei patalpintas asmeniniame Github viešoje repozicijoje.
3. Programos realizacijoje hash'avimui reikiamą input'ą, esantį išoriniame faile, reikia
nurodyti per Command Line Argument'ą.
4. Papildomai, turi būti realizuota galimybė input'ą įvesti ir ranka.
5. Repozicijos README.md faile aprašyti maišos funkcijos idėją pseudo-kodo stiliumi.
6. Atlikite eksperimentinę analizę, kurios metu įsitikinti, kad hash funkcija-generatorius iš tiesų pasižymi aukščiau aprašytais hash funkcijoms keliamais reikalavimais.
7. Atliktą tyrimą ir gautuosius rezultatus išsamiai aprašyti README.md faile.

### Versijai 0.1 pavyko realizuoti 1, 2, 4, 5, dalinai 6 ir 7 reikalavimus.

## Eksperimentinis tyrimas ir rezultatų analizė
1. Susikurti testinių įvedimo failų pavyzdžių, tokių kad:
+ Bent du failai būtų sudaryti tik iš vieno, tačiau skirtingo, simbolio.
+ Bent du failai būtų sudaryti iš daug (> 1000) atsitiktinai sugeneruotų simbolių.
+ Bent du failai būtų sudaryti iš daug (> 1000) simbolių, bet skirtųsi vienas nuo kito tik
vienu (pvz. vidurinėje pozicijoje esančiu) simboliu.
+ Tuščio failo.
2. Naudojant pirmame žingsnyje susikurtus testinius failus, kaip programos input'us,
įsitikinkti, kad hash funkcija atitinka aukščiau aprašytus reikalavimus.
3. Ištirti sukurtos hash funkcijos efektyvumą ir greitį. Tuo tikslu pirmiausiai suhash'uosiu vieną eilutę iš failo
konstitucija.txt ir išmatuosiu kiek laiko visa tai užtruko.
Tuomet kartosiu eksperimentą hash'uojant 2 eilutes, 4 eilutes, 8 eilutes ir t.t. Matuoti reikia tik programos veikimo laiką. Reiktų pateikti suvidurkintą hash'avimo laiko priklausomybę nuo eilučių skaičiaus. Rezultatą pavaizduosiu grafiškai.
4. Susigeneruoti bent 100 000 atsitiktinių simbolių eilučių ( string 'ų) porų, apsiribojant iki 1000 simbolių ilgiu. Toje pačioje poroje esančių string'ų ilgiai turi sutapti, tačiau skirtingos poros gali būti skirtingo ilgio.
5. Naudojant 4 žingsnyje sugeneruotas poras, patikrinti, ar visais atvejais gautieji porų
hash'ai nesutampa. O jeigu sutampta, tai kaip dažnai tai nutinka. Tokiu būdu (jei visuomet
hash'ai nesutampa) bent dalinai įsitikinti, kad hash funkcija atspari kolizijai.
6. Susigeneruoti bent 100 000 atsitiktinių simbolių eilučių ( string 'ų) porų, apsiribojant
iki 1000 simbolių eilučių ilgiu, taip, kad jos skirtųsi tik vienu simboliu
pvz.: (asdfg, bsdfg). Įvertinkite Jūsų gautų hash'ų procentinį "skirtingumą":
+ bitų lygmenyje;
+ hex'ų lygmenyje;
Išvesti minimalią, maksimalią ir vidurkines "skirtingumo" reikšmes. Tokiu būdu
įsitikinti, kaip gerai hash funkcija tenkina lavinos efektą.

# Darbo rezultatai
## Naudojimosi instrukcija
1. Paleidus programą, galime pasirinkti vieną iš 7 norimų veiksmų: 1. Įvesti ranka, 2. Tikrinti failus, sudarytus tik iš vieno simbolio, 3. Tikrinti failus, kuriuose yra daugiau nei 1000 simbolių, 4. Tikrinti failus su 1000 simbolių, kurie skiriasi tik vienu simboliu, 5. Atidaryti failą 'tuscias.txt', 6. Skaičiuoti failą 'konstitucija.txt', 7. Baigti programą.
2. Paspaudus 1, turime galimybę suvesti norimą tekstą ranka, kuris bus užhashintas.
3. Paspaudus 2, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su skirtingais simboliais juose.
4. Paspaudus 3, taip pat matysime 2 eilutes skirtingo hasho, nes bus apdoroti du failai su daugiau nei 1000 surandomintų simbolių.
5. Paspaudus 4, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su daugiau nei 1000 simbolių, kurie skirsis tik vienu simboliu.
6. Paspaudus 5, bus atidarytas tuščias failas, ....
7. Paspaudus 6, matysime kiek laiko užtruko skirtingo eilučių kiekio hashinimas.
8. Paspaudus 7, programa bus baigta ir uždaryta.


Faile hash.cpp aprašyta hash funkciją, kuri....

## Pseudokodas
1. hashSkaiciavimas(ivestis, asciiReiksme, hashMasyvas, buferis, laikinasMasyvas, laikinaKopija):
2. ivestiesIlgis ← ilgis(ivestis)
3. for i <- 0 to ivestiesIlgis - 1 do
4.         asciiReiksme ← ASCII reikšmė is ivestis[i]
5.         jei i = 0 then:
6.             inicializuotiHash(hashMasyvas, buferis, asciiReiksme)
7.         jei i > 1 then:
8.             kopijuotiMasyva(hashMasyvas, laikinasMasyvas)
9.             hashZingsnis1(hashMasyvas, laikinasMasyvas, asciiReiksme)
10.            hashZingsnis2(hashMasyvas, laikinasMasyvas, asciiReiksme)
11.            kopijuotiMasyva(hashMasyvas, laikinaKopija)
12.            hashZingsnis3(hashMasyvas, laikinasMasyvas, asciiReiksme, laikinaKopija)
13.    spausdintiHash(hashMasyvas)
14. inicializuotiHash(hashMasyvas, buferis, asciiReiksme):
15.    i ← 0
16.    pokytis ← asciiReiksme
17.    for eilute from 0 iki 3 do
18.        for stulpelis nuo 0 iki 15 do:
19.            hashMasyvas[i] ← buferis[(stulpelis + pokytis) mod 16]
20.            i ← i + 1
21.        pokytis ← pokytis * 2
22.    if asciiReiksme > 64 tada:
23.        pokytis ← asciiReiksme - 64
24.        i ← 0
25.        for eilute from 0 to (asciiReiksme // 16) - 1 do
26.            for stulpelis from 0 to (asciiReiksme // 4) - 1 kas (asciiReiksme // 16) do:
27.                hashMasyvas[i] ← buferis[(pokytis ^ 2) mod 16]
28.                i ← i + 1
29. kopijuotiMasyva(saltinisMasyvas, tikslasMasyvas):
30.    for i from 0 to 63 do
31.        tikslasMasyvas[i] ← saltinisMasyvas[i]
32. hashZingsnis1(hashMasyvas, buferis, asciiReiksme):
33.    zingsnioDydis ← if asciiReiksme > 64 then asciiReiksme - 64 + 1 else asciiReiksme:
34.    for i from 0 to 63 kas zingsnioDydis + 1 do
35.        hashMasyvas[i] ← buferis[i mod 16]
36. hashZingsnis2(hashMasyvas, buferis, asciiReiksme):
37.    zingsnioDydis ← asciiReiksme mod 16
38.    for i from 0 to 63 kas zingsnioDydis + 1 do
39.        hashMasyvas[i] ← buferis[i mod 16]
40. hashZingsnis3(hashMasyvas, buferis, asciiReiksme, laikinaKopija):
41.    zingsnioDydis ← if asciiReiksme > 64 then asciiReiksme - 64 + 1 else asciiReiksme:
42.    for i from 0 to 63 kas zingsnioDydis + 1 do
43.        if 2 * i < 64 then
44.            hashMasyvas[i] ← laikinaKopija[2 * i]
45.        else:
46.            hashMasyvas[i] ← laikinaKopija[(2 * i) mod 64]
47. spausdintiHash(hashMasyvas):
48.    i ← 0
49.    for eilute from 0 to 3 do
50.        for stulpelis from 0 to 15 do
51.            spausdinti hashMasyvas[i] + " "
52.            i ← i + 1
53.        spausdinti nauja eilute



## Programos greitis dirbant su failu "konstitucija.txt"

Lentelėje vaizduojama kiek vidutiniškai laiko programa hash'ina atitinkamai vieną, 2, 4, 8 ir t.t. eilutes.

|Eilučių skaičius|Vidurkis (sek.)|
|---|-----|
|1 |  s.| 
|2|  s.| 
|4|  s.| 
|8|  s.| 
|16|  s.| 
|32|  s.| 
|64|  s.| 
|128|  s.| 
|256|  s.| 
|612|  s.| 

