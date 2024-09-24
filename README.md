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

# Rezultatai
## Naudojimosi instrukcija
1. 
Faile hash.cpp aprašyta hash funkciją, kuri....

![image](https://github.com/user-attachments/assets/3a138a6f-f76c-47fb-b697-45f527bfe11e)
1 var, pirma ideja
