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
1. Input(char) -> X;
2. X transform ASCII koduotės decimal numerį -> naujas X;
3. X transform į 64 simbolius (string) iš Hex kuodotės
(if X>64 priduodam simbolius 2 kartus) -> naujas X
5. X yra laikinas "raktas".
4-6. szamanim z haszinimasam
7. Gaunamas X1 simbolis
8. X1 transform ASCII koduotės decimal numerį - naujas X1;
9. Naudojam X "raktą" 4-6... X1
10. repeat 4-6.

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

