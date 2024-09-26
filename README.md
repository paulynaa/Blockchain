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

### Versijai 0.1 pavyko įgyvendinti šiuos reikalavimus: 1, 2, 3, 4, 7, dalinai 5 ir 6.

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

### Versijai 0.1 pavyko realizuoti 1, 2, 3(yra trūkumų), kadangi hash funkcija dar turi trūkumų, 4, 5 ir 6 įgyvendinsiu versijoje v0.2.

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


## Pseudokodas
1.  hashSkaiciavimas(ivestis, asciiReiksme, hashMasyvas, buferis, laikinasMasyvas, laikinaKopija): 
2.  ivestiesIlgis ← ilgis(ivestis) 
3.  for i <- 0 to ivestiesIlgis - 1 do
- asciiReiksme ← ASCII reikšmė nuo 32 iki 127 is ivestis[i]
- jei i = 0 then:inicializuotiHash(hashMasyvas, buferis, asciiReiksme) 	
- jei i > 1 then: kopijuotiMasyva(hashMasyvas, laikinasMasyvas) 
4.  hashZingsnis1(hashMasyvas, laikinasMasyvas, asciiReiksme) 

5.  hashZingsnis2(hashMasyvas, laikinasMasyvas, asciiReiksme) 

6.  kopijuotiMasyva(hashMasyvas, laikinaKopija) 

7.  hashZingsnis3(hashMasyvas, laikinasMasyvas, asciiReiksme, laikinaKopija) 

8.  spausdintiHash(hashMasyvas) 

9.  inicializuotiHash(hashMasyvas, buferis, asciiReiksme): i ← 0

- pokytis ← asciiReiksme
- for nuo 0 iki 4:
- for nuo 0 iki 16 do:
- hashMasyvas[i] ← buferis[(stulpelis + pokytis) mod 16]
- i ← i + 1
- pokytis ← pokytis * 2 
10.  if asciiReiksme > 64 tada: 
- pokytis ← asciiReiksme - 64
- i ← 0
- for eilute from 0 to (asciiReiksme // 16) - 1 do
- for stulpelis from 0 to (asciiReiksme // 4) - 1 kas (asciiReiksme //  do:
- hashMasyvas[i] ← buferis[(pokytis ^ 2) mod 16]
- i ← i + 1 
11.  kopijuotiMasyva(saltinisMasyvas, tikslasMasyvas):
- for i from 0 to 64 do:
- tikslasMasyvas[i] ← saltinisMasyvas[i] 
12.  hashZingsnis1(hashMasyvas, buferis, asciiReiksme): 
- zingsnioDydis ← if asciiReiksme > 64 then asciiReiksme - 64 + 1 else asciiReiksme:
- for i from 0 to 64 kas zingsnioDydis + 1 do
- hashMasyvas[i] ← buferis[i mod 16] 
 13.  hashZingsnis2(hashMasyvas, buferis, asciiReiksme): 
- zingsnioDydis ← asciiReiksme mod 16
- for i from 0 to 64 kas zingsnioDydis + 1 do
- hashMasyvas[i] ← buferis[i mod 16] 
14.  hashZingsnis3(hashMasyvas, buferis, asciiReiksme, laikinaKopija): 
- zingsnioDydis ← if asciiReiksme > 64 then asciiReiksme - 64 + 1 else asciiReiksme:
- for i from 0 to 64 kas zingsnioDydis + 1 do
- if 2 * i < 64 then hashMasyvas[i] ← laikinaKopija[2 * i]
- else: hashMasyvas[i] ← laikinaKopija[(2 * i) mod 64] 
15.  spausdintiHash(hashMasyvas): 
- i ← 0
- for from 0 to 4 do
- for from 0 to 16 do
- spausdinti hashMasyvas[i] + " "
- i ← i + 1
- spausdinti nauja eilute 
16.  end


Aukščiau pateiktas detalus maišos generavimo pseudokodas.

## Eksperimentas su 2 failais sudarytais tik iš vieno simbolio

Pirmame faile yra simbolis "F", antrame "9". Rezultatas:

![image](https://github.com/user-attachments/assets/9da0ac47-c34b-4d71-84c2-c0f55e2e5b19)

## Eksperimentas su 2 failais sudarytais iš > 1000 skirtingų simbolių

Kadangi failų generavimui naudoju rand, tai šie failai skiriasi tik keliais simboliais, dėl to hashai yra beveik vienodi:

![image](https://github.com/user-attachments/assets/93e5f543-6a83-40f9-a987-240587bd4830)

## Eksperimentas su 2 failais, sudarytais iš > 1000 simbolių, kurie skiriasi tik vienu simboliu:

Hashas nesiskiria iš esmės, bet skirtumas yra.

![image](https://github.com/user-attachments/assets/8c85d26c-ba3f-45a5-857c-ce84844c1b01)


## Programos greitis dirbant su failu "konstitucija.txt"

Lentelėje vaizduojama kiek vidutiniškai laiko programa hash'ina atitinkamai vieną, 2, 4, 8 ir t.t. eilutes.

|Eilučių skaičius|Vidurkis (sek.)|
|---|-----|
|1 | 0,0107 s.| 
|2| 0,0103 s.| 
|4| 0,0195 s.| 
|8| 0,0372 s.| 
|16| 0,0748 s.| 
|32| 0,1671 s.| 
|64| 0,3123 s.| 
|128| 0,5857 s.| 
|256| 1,1964 s.| 


## Deterministinė

Kiekvieną kartą vedant tą patį žodį, gauname tą patį rezultatą:

### 1:

![image](https://github.com/user-attachments/assets/7acda4ff-71ad-4621-bff3-837217b7e048)

### 2:

![image](https://github.com/user-attachments/assets/010ba0f2-0bfe-4579-839d-fb12b678f2d2)

## Lavinos efektas

Įvedus žodį hash ir Hash, gauname skirtingus kodus:

![image](https://github.com/user-attachments/assets/38c552af-d7ee-485e-914f-3fc01d132dd7)

![image](https://github.com/user-attachments/assets/7083b1e8-d224-47e5-972f-ee6691a77f89)


## Stiprybės ir trūkumai
Kadangi dar nėra implementuota extended ASCII koduotė, tai programa nehashuoja lietuviškų ir tam tikrų simbolių. Taip pat kai yra nuskaitomas tuscias failas, programa hasho negražina, bet gaunamas toks outputas:

![image](https://github.com/user-attachments/assets/6796df69-22f6-4603-bcc5-a227367bf4ae)

Savo jėgomis sugebėjau sukurti tik tokią hash funkciją, kurios outputas nėra toks "surandomintas" kaip pvz.: SHA256. Taip pat mano funkcija nepakankamai gerai veikia su dideliu inputu. Ši versija netikrina ar hashas yra atsparus kolizijai, nėra atlikti testai 100 000 atsitiktinių simbolių eilučių poromis, bet hashas yra atsparus kolizijai su vienu simboliu, ilgesnį stringą koduoja taip:

![image](https://github.com/user-attachments/assets/aaf9acfa-3385-49d9-98e9-46e065f89377)

![image](https://github.com/user-attachments/assets/9b30d926-b809-4c56-bc93-31b724681058)

Šie trūkumai turėtų būti sutvarkyti sekančioje versijoje.
Stiprybės ir ką pavyko realizuoti: Maišos funkcija priima bet kokio dydžio simbolių eilutę. Maišos funkcijos išėjimas visuomet yra to paties dydžio rezultatas. Maišos funkcija yra deterministinė. Maišos funkcijos kodas bet kokiai input'o reikšmei yra apskaičiuojamas greitai - efektyviai. Atlikti eksperimentiniai tyrimai. Maišos funkcija tenkina lavinos efektą. Iš outputo beveik neįmanoma atgaminti inputo, nes tai priklauso nuo ASCII, kur visi simboliai nuo 32 iki 127 turės skirtingą hashą.



