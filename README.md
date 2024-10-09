# Darbo rezultatai
Versijoje v0.2 buvo patobulintas mano v0.1 hash generatorius ir pridėti trūkstami eksperimentai, taip pat įgyvendintos papildomos užduotys. Šiai versijai buvo panaudotas šis kodas: https://gist.github.com/hak8or/8794351  , kurį integravau į savo kodą. Atlikti visi reikalavimuose nurodyti eksperimentai, o jų rezultatai pateikti žemiau. Dabartinė hash funkcija veikia akivaizdžiai geriau ir efektyviau, ką įrodo visi testai. Šioje versijoje naudojama extended ASCII, todėl nėra tos problemos, kuri buvo pirmoje versijoje(pvz. hashinant tuščią failą).

## Naudojimosi instrukcija
1. Paleidus programą, galime pasirinkti vieną iš 12 norimų veiksmų: 1. Įvesti ranka, 2. Tikrinti failus, sudarytus tik iš vieno simbolio, 3. Tikrinti failus, kuriuose yra daugiau nei 1000 simbolių, 4. Tikrinti failus su 1000 simbolių, kurie skiriasi tik vienu simboliu, 5. Atlikti testą su failu 'konstitucija.txt', 6. Atlikti testą kolizijom su 100 000 skirtingų simbolių porų, 7. Atlikti testą bitų ir hexų skirtingumui su 100 000 porų, kurios skiriasi tik vienu simboliu. 8. Nuskaitytį failą 'tuscias.txt', 9,10,11 skirti papildomų užduočių testams, 12. Baigti programą. 
2. Paspaudus 1, turime galimybę suvesti norimą tekstą ranka, kuris bus užhashintas.
3. Paspaudus 2, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su skirtingais simboliais juose.
4. Paspaudus 3, taip pat matysime 2 eilutes skirtingo hasho, nes bus apdoroti du failai su daugiau nei 1000 surandomintų simbolių.
5. Paspaudus 4, matysime 2 eilutes skirtingo hash'o, nes bus apdoroti du failai su daugiau nei 1000 simbolių, kurie skirsis tik vienu simboliu.
6. Paspaudus 5, matysime hash'ą tam tikrų eilučių ir laiką kiek tai užtruko padaryti.
7. Paspaudus 6, matysime kiek kartų sutapo hash'ai 100 000 eilučių skirtingų simbolių porų.
8. Paspaudus 7, matysime hash'ų procentinį skirtingumą bit'ų ir hex'ų lygmenyje iš 100 000 simbolių eilučių porų.
9. Paspaudus 8, matysime hash'ą tuščio failo.
10. Paspaudus 9, matysime 2 skirtingus hashus tos pačios simbolių sekos(pridėta druskos).
11. Paspaudus 10, matysime kiek kartų sutapo hashai tarp vienodų porų, pasikartojančių 100 000 kartų(salt, hiding)
12. Paspaudus 11, matysime kiek kartų sutapo hashai tarp mažo skirtingumo 100 000 porų(puzzlefriendly)
13. Paspaudus 12, programa bus baigta ir uždaryta.


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

![image](https://github.com/user-attachments/assets/23aa0144-8071-4f74-8694-ce6fa0e5183e)


## Atsparumas kolizijai

Net kelis kartus generuojant failą su 100 000 eilučių skirtingų simbolių poromis(25000 porų su 10 simbolių ilgiu, 25000 su 100, 25000 su 500, 25000 su 1000) ir tikrinant ar nėra kolizijų, rezultatas kiekvieną kartą lygus 0:

![image](https://github.com/user-attachments/assets/d7f7f038-2f26-499c-8e1a-9746ae0353e0)

## Tuščio failo testas
Kadangi ASCII koduotėj NULL turi reikšmę, tai gaunamas toks hashas:

![image](https://github.com/user-attachments/assets/ef5ba903-0a81-469a-a7eb-6638022e1562)


# Papildomos užduotys

1.	Objektyviai palyginti mano Hash funkcijos spartą su MD5 , SHA-1 , SHA-256 ar kita gerai žinoma hash funkcija.
2.	Parodyti, kad iš hash funkcijos rezultato (output'o) praktiškai neįmanoma atgaminti pradinio įvedimo (input'o), t. y., kaip hash funkcijoje realizuota hiding ir puzzlefriendliness savybės. 
3.	Reikia 3-4  grupės/pogrupio sukurtų hash funkcijų/generatorių apjungti/integruoti į mano programą. Tai gali būti ir visiškai nauja programa, kurioje būtų iškviečiamos visų sukurtos funkcijos.
- Tuomet atlikti anksčiau aprašytus eksperimentus su grupės/pogrupio kolegų sukurtais hash generatoriais. Gautus grupės/pogrupio rezultatus - agreguoti ir sureitinguoti.

## 1 papildoma
Kadangi mano hash generatorius yra panašus į SHA256, tai palyginsiu su tikru SHA256 generatoriumi ir SHA1.
Tam sukūriau atskirą programą, ir parsisiunčiau OpenSSL biblioteką. (prisegta "palyginimas.cpp")
Testo objektyvumui nusprendžiau paleisti programą per 2 skirtingus kompiuterius, kad rezultatai būtų nepriklausomi nuo geležies. Testo esmė: sugeneruojamas atsitiktinių simbolių rinkinys: 32 simbolių, 40, 80, 100, 200... ir hashinamas yra 10 kartų, po ko apskaičiuojamas vidutinis hashinimo laikas milisekundėmis su Mano Hash, SHA256, SHA1. Testavimas buvo atliktas daug kartų, kad atmesti įmanomus kompiuterio lagus.
Žemiau pateiktos skirtingų kompiuterių specifikacijos ir hashų greitis.
### Pirmas kompiuteris

![image](https://github.com/user-attachments/assets/6828e50c-37f4-4643-8eb4-71bbab7a64f6)

|Rand string ilgis| Mano Hash| SHA-256 | SHA-1 |
|---|-----|---------|-------|
|32 | 1,333179| 0,3388 | 0,65167 |
|40| 1,00617 | 0,29982 | 0,20053 |
|80| 0,90307 | 0,19979 | 0,30026 |
|100| 0,87083 | 0,25144 | 0,19995 |
|200| 0,90061 | 0,19971 | 0,35201 |
|400| 0,90582 | 0,25136 | 0,19757 |
|800| 1,12793 | 0,29986 | 0,30006 |

### Antras kompiuteris

![image](https://github.com/user-attachments/assets/e3325513-9fdf-4276-b9ad-bbe26fc6afd7)


|Rand string ilgis| Mano Hash| SHA-256 | SHA-1 |
|---|-----|---------|-------|
|32 | 0,86767 | 0,29918 | 0,69826 |
|40| 1,59585 | 0,59847 | 0,4986 |
|80| 1,19668 | 0,54934 | 0,69801 |
|100| 1,39646 | 0,99734 | 0,59837 |
|200| 1,39637 | 0,69811 | 0,49862 |
|400| 1,69547 | 0,79798 | 0,69811 |
|800| 1,69536 | 0,79788 | 0,89761 |

### Išvados
1 kompiuterio procesorius galingesnis 30% už 2 kompiuterį(informacija iš: https://cpu.userbenchmark.com/Compare/Intel-Core-i7-1165G7-vs-Intel-Core-i5-7400/m1195374vs3886 ). Taip testuojant per 2 kompiuterius greičiausiai veikia SHA256, SHA1 ir tada Mano Hash. Vidutiniškai 1 kompiuteris hashina 2+ kartus greičiau už 2 kompiuterį su SHA256 ir SHA1, bet ManoHash laikas lieka beveik nepakitęs. Darau išvada, kad geležies pakeitimas nedaro reikšminės įtakos mano hashui, bet kadangi SHA256 ir SHA1 yra žymiai optimalesni, tai jų greitis labiau priklauso nuo kompiuterio galingumo. 

## 2 papildoma
Be salt funkcijos tą pačią simbolių seką hashina vienodai

![image](https://github.com/user-attachments/assets/b20d6ad2-493e-43f0-bae7-d7038d6250ff)

![image](https://github.com/user-attachments/assets/24a18594-8774-4496-9d28-a0c7cff64b3f)

Salt(druska) padeda labiau apsaugoti duomenis nuo nuhackinimo, nes sukuriama papildoma individuali reikšmė prie mūsų įvestos simbolių sekos, todėl tom pačiom simbolių sekom bus išvedami skirtingi hashai.

Norėdama įsitikinti ar tikrai veikia salt programoje, sukūriau du failus su ta pačia simbolių seka, šiuo atveju abejuose failuose įrašiau "hash123" ir gavau skirtingas reikšmes:

![image](https://github.com/user-attachments/assets/09b165ee-5bee-440d-8afb-163a7f22c870)

Patikrinus net 1 000 000 skirtingų porų hashus, galima teigti, kad hash funkcija yra atspari kolizjai. Dėl to, kad yra 16^64 skirtingų įmanomų hashų, o pridėjus salt, hashai tampa labiau individualizuoti, negalime atkurti hasho, nebent turime pradinį inputą, jam sugeneruotą salt ir taip pat pradinį key. 

Su saltu dar atskirai patikrinu hiding savybę, t.y. sugeneruoju failą, kuriame yra 100 000 vienodų porų ir tikrinu ar nėra kolizijų:

![image](https://github.com/user-attachments/assets/f194032d-5039-46d6-acf8-51ee7df8d0c6)

Kadangi kiekvienam stringui yra sukuriamas individualus saltas, jų hashai skirsis.

Tikrinu puzzle friendliness savybę. Sukuriu failą, kuriame yra 100 000 panašių porų: pp1, pp2; pp3, pp4; pp5,pp6 ir tt. ir tikrinu ar nėra kolizijų:

![image](https://github.com/user-attachments/assets/49eed24e-cf56-40f0-8a5b-8312722b14cc)

Net kai toks nereikšmingas skirtumas tarp porų, kolizijų vis tiek nėra.


## 3 papildoma
Rezultatai: https://github.com/aran1ja/Blockchain/tree/v0.2

