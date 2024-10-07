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


# Darbo rezultatai
## Naudojimosi instrukcija
1. Paleidus programą, galime pasirinkti vieną iš 7 norimų veiksmų: 1. Įvesti ranka, 2. Tikrinti failus, sudarytus tik iš vieno simbolio, 3. Tikrinti failus, kuriuose yra daugiau nei 1000 simbolių, 4. Tikrinti failus su 1000 simbolių, kurie skiriasi tik vienu simboliu, 5. Atidaryti failą 'tuscias.txt', 6. Skaičiuoti failą 'konstitucija.txt', 7. Baigti programą.
2. Paspaudus 1, turime galimybę suvesti norimą tekstą ranka, kuris bus užhashintas.
3. Paspaudus 2, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su skirtingais simboliais juose.
4. Paspaudus 3, taip pat matysime 2 eilutes skirtingo hasho, nes bus apdoroti du failai su daugiau nei 1000 surandomintų simbolių.
5. Paspaudus 4, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su daugiau nei 1000 simbolių, kurie skirsis tik vienu simboliu.
6. Paspaudus 5, matysime hash'ą tam tikrų eilučių ir laiką kiek tai užtruko padaryti.
7. Paspaudus 6, matysime kiek kartų sutapo hash'ai 100 000 eilučių skirtingų simbolių porų.
8. Paspaudus 7, matysime hash'ų procentinį skirtingumą bit'ų ir hex'ų lygmenyje iš 100 000 simbolių eilučių porų.
9. Paspaudus 8, matysime hash'ą tuščio failo.
10. Paspaudus 9, programa bus baigta ir uždaryta.


## Pseudokodas v0.1
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


Aukščiau pateiktas detalus versijos v0.1 maišos generavimo pseudokodas.

## Eksperimentas su 2 failais sudarytais tik iš vieno simbolio

Pirmame faile yra simbolis "F", antrame "9". Rezultatas:

![image](https://github.com/user-attachments/assets/2eabc175-9772-4ff3-b87f-d55aa4dc9809)


## Eksperimentas su 2 failais sudarytais iš > 1000 skirtingų simbolių

![image](https://github.com/user-attachments/assets/644738de-474c-4170-be49-50a112b6506f)


## Eksperimentas su 2 failais, sudarytais iš > 1000 simbolių, kurie skiriasi tik vienu simboliu:

![image](https://github.com/user-attachments/assets/6863ef31-6589-4f2d-81a3-c2fa9e136310)

## Programos greitis dirbant su failu "konstitucija.txt"

Lentelėje vaizduojama kiek vidutiniškai laiko programa hash'ina atitinkamai vieną, 2, 4, 8 ir t.t. eilutes.

|Eilučių skaičius|Vidurkis (sek.)|
|---|-----|
|1 | 0,00245 s.| 
|2| 0 s.| 
|4| 0,00005 s.| 
|8| 0 s.| 
|16| 0,0015 s.| 
|32| 0,001 s.| 
|64| 0,0009 s.| 
|128| 0,00098 s.| 
|256| 0,00097 s.|
|512| 0,00029 s.|
|789| 0,002 s.|

## Deterministinė

Kiekvieną kartą vedant tą patį žodį, gauname tą patį rezultatą:

### 1:

![image](https://github.com/user-attachments/assets/9afcea0e-22ef-4407-a7aa-932799e84297)


### 2:

![image](https://github.com/user-attachments/assets/d67f28f4-0078-404a-899a-dcdcd7159e72)


## Lavinos efektas

Matome, kad ši versija turi gerą lavinos efektą, o rezultatai išlieka vienodi net kelis kartus atliekant testus, tikriausiai dėl to, kad naudoju rand funkciją generavimui, kuri nėra visiškai randominė(pseudo).

![image](https://github.com/user-attachments/assets/8b971dd8-1900-48de-87f6-18bbec1ab401)


## Atsparumas kolizijai

Net kelis kartus generuojant failą su 100 000 eilučių skirtingų simbolių poromis(25000 porų su 10 simbolių ilgiu, 25000 su 100, 25000 su 500, 25000 su 1000) ir tikrinant ar nėra kolizijų, rezultatas kiekvieną kartą lygus 0:

![image](https://github.com/user-attachments/assets/d7f7f038-2f26-499c-8e1a-9746ae0353e0)

## Tuščio failo testas
Kadangi ASCII koduotėj NULL turi reikšmę, tai gaunamas toks hashas:

![image](https://github.com/user-attachments/assets/ef5ba903-0a81-469a-a7eb-6638022e1562)


## Stiprybės ir trūkumai
Versijoje v0.2 buvo panaikinti visi trūkumai, kurie buvo v0.1. Papildžiau testais ir rezultatus aprašiau aukščiau. Dabartinis patobulintas kodas atitinka visus reikalavimus ir praeina testus. Kadangi tobulindama naudojausi įvairiais šaltiniais, tai pavyko padaryti beveik vienodą maišos funkciją su SHA256:

![image](https://github.com/user-attachments/assets/ca31ce3f-d25d-474b-9515-0547c45f6c3e)

![image](https://github.com/user-attachments/assets/632b7365-2986-417e-afcf-cc842c8b7006)

Taip pat vedant tą patį žodį tik pvz. iš didelės raidės ar su vienu skirtumu, hashas skiriasi iš esmės. Tą taip pat pavaizduoja eksperimentas su 1000 random simbolių, bet su vienu simbolio skirtumu.


# Papildomos užduotys

1.	Objektyviai palyginti mano Hash funkcijos spartą su MD5 , SHA-1 , SHA-256 ar kita gerai žinoma hash funkcija.
2.	Parodyti, kad iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o), t. y., kaip hash funkcijoje realizuota hiding ir puzzlefriendliness savybės. 
3.	Reikia 3-4  grupės/pogrupio sukurtų hash funkcijų/generatorių apjungti/integruoti į mano programą. Tai gali būti ir visiškai nauja programa, kurioje būtų iškviečiamos visų sukurtos funkcijos.
- Tuomet atlikti anksčiau aprašytus eksperimentus su grupės/pogrupio kolegų sukurtais hash generatoriais. Gautus grupės/pogrupio rezultatus - agreguoti ir sureitinguoti.

## 1 papildoma



## 2 papildoma
Be salt funkcijos tą pačią simbolių seką hashina vienodai

![image](https://github.com/user-attachments/assets/b20d6ad2-493e-43f0-bae7-d7038d6250ff)

![image](https://github.com/user-attachments/assets/24a18594-8774-4496-9d28-a0c7cff64b3f)

Salt(druska) padeda labiau apsaugoti duomenis nuo nuhackinimo, nes sukuriama papildoma individuali reikšmė prie mūsų įvestos simbolių sekos, todėl tom pačiom simbolių sekom bus išvedami skirtingi hashai.

Norėdama įsitikinti ar tikrai veikia salt programoje, sukūriau du failus su ta pačia simbolių seka, šiuo atveju abejuose failuose įrašiau "hash123" ir gavau skirtingas reikšmes:

![image](https://github.com/user-attachments/assets/09b165ee-5bee-440d-8afb-163a7f22c870)

Patikrinus net 1 000 000 skirtingų porų hashus, galima teigti, kad hash funkcija yra atspari kolizjai. Dėl to, kad yra 16^64 skirtingų įmanomų hashų, o pridėjus salt, hashai tampa labiau individualizuoti, negalime atkurti hasho, nebent turime pradinį inputą, jam sugeneruotą salt ir taip pat pradinį key. 


## 3 papildoma


