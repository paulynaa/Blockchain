# Užduoties formuluotė
Sukurti "centralizuotą" blokų grandinę ir imituoti jos veikimą kuo realistiškiau.
1. Sugeneruoti ~1000 tinklo vartotojų, turinčių šiuos atributus:
- vardą,
- viešąjį raktą,
- atsitiktinį valiutos balansą.
2. Sugeneruoti ~10000 naujų transakcijų, kurios dar nėra įtrauktos į jokį bloką. Transakcijos struktūra turi turėti šiuos atributus:
- transakcijos ID,
- siuntėjas,
- gavėjas,
- suma.
3. Atsitiktinai pasirinkite 100 transakcijų iš transakcijų sąrašo ir pabandykite jas įtraukti į naują bloką.
4. Realizuokite naujų blokų kasimo procesą, naudojant Proof-of-Work (PoW) algoritmą. Tikslas – rasti naujo bloko
maišos reikšmę, atitinkančią Difficulty Target reikalavimą. Nulių skaičius priklauso
nuo jūsų sukurtos maišos funkcijos.
5. Suradus tinkamą naujo bloko maišos reikšmę:
- ištrinkite į bloką įtrauktas transakcijas iš transakcijų sąrašo;
- "įvykdykite" transakcijas, t.y. atnaujinkite vartotojų balansus;
- pridėkite naują bloką prie blokų grandinės.
# Versija v0.1
## Reikalavimai versijai
1. Realizuoti supaprastintą "centralizuotą" blokų grandinę. Maišos funkcijai naudoti savo sukurtą funkciją.
2. Transakcijų ir blokų kūrimo procesas turi būti matomas. Sukurti funkcijas, kurios leidžia atspausdinti bet
kurią transakciją ir bloką. Išvedimo detalumas ir vizualumas turės įtakos balui.
3. Vietoj dvejetainio Merkle medžio, galite naudoti visų bloko transakcijų ID maišos reikšmę.
4. Saugumas yra labai svarbus blokų grandinėms, todėl naudokite gerąsias OOP praktikas (pvz., enkapsuliavimą,
konstruktorius, RAII idiomą).

## Veikimo principas

Programa sukuria 1 000 vartotojų, kiekvienam suteikia vardą (išrenka atsitiktinį vardą iš failo vardai.txt), viešąjį raktą ir pradinį balansą. Vartotojo duomenys saugomi vektoriuje vartotojai. Naudojama klasė Vartotojas.

Sugeneruojama 10 000 transakcijų, kiekviena transakcija tai atsitiktinės sumos pervedimas kitam vartotojui. Atlikus transakciją siuntėjo ir gavėjo balansai yra atnaujinami (dar nenaudojamas UTXO modelis). Naudojama klasė Transakcija. Reikalavimuose prašoma generavimo procesą atvaizduoti konsolėje, bet visas transakcijas (10 000) vaizduoti ekrane yra beprasmiška, todėl buvo nuspręsta pavaizduoti taip, kaip įklijuota aukščiau (Naudojimosi instrukcija).

Klasė Blokas naudojama darbui su blokų informacija. Kiekviename bloke talpinamos 100 atsitiktinių transakcijų. Apskaičiuojamas šių transakcijų Merkle Root maišos kodas ( hashina transakcijas ir poras, kol neliks tik vienas hashas) ir vykdomas Proof-of-Work procesas, ieškant bloko maišos, atitinkančios nustatytą sudėtingumo lygį (difficulty target). Sėkmingai sukūrus bloką, jis pridedamas prie blokų grandinės. Visi blokai yra išvedami į ekraną, o bloko transakcijas galima peržiūrėti savarankiškai įvedus bloko eilės numerį. Vedant informaciją į ekraną buvo pasiremta šiuo pvz.: https://www.blockchain.com/explorer/blocks/btc/868177 .
Į bloką įrašytos transakcijos yra ištrinamos iš vektoriaus ir procesas kartojamas kol neliks neįtrauktų transakcijų.

OOP praktikos:
Kapsuliacija: Visos klasės savybes ir metodus laiko privačius arba viešuosius, o neeksportuojami duomenys nėra tiesiogiai prieinami kitoms programos dalims. Tai užtikrina duomenų vientisumą, nes kitos klasės negali tiesiogiai keisti duomenų.

SRP: Programoje laikomasi SRP principo, nes kiekviena klasė turi tik jai priskirtą atsakomybę, pvz.: Transakcija klasė tvarko transakcijos duomenis ir jų hash'ų skaičiavimą, kai tuo tarpu Blokas rūpinasi bloko maišų skaičiavimu ir kita informacija.


# Reikalavimai versijai v0.2
1. Jei v0.1 versijoje nenaudojame Merkle medžio, v0.2 versijoje Merkle Root Hash turi būti realizuotas pagal binarinio Merkle Tree veikimą.
2. Realizuoti transakcijų verifikavimą:
 - Balanso tikrinimas: Jei siuntėjo balansas yra mažesnis už siunčiamą sumą, transakcija turi būti atmesta.
 - Transakcijos maišos reikšmės tikrinimas: Patikrinti, ar transakcijos informacijos maišos reikšmė sutampa su transakcijos ID.
3. Patobulinti blokų kasimo procesą:
 - Sudaryti 5 potencialius blokus (kandidatus) iš ~100 atsitiktinai pasirinktų transakcijų. Transakcijos blokuose gali kartotis.
 - Atsitiktinai pasirinkti vieną bloką-kandidatą ir bandyti jį "kasti" tam tikrą laiką (pvz., 5 sekundes) arba iki tam tikro bandymų skaičiaus (pvz., 100000). Jei per tą laiką blokas nebuvo "iškastas", pasirinkti kitą bloką-kandidatą.
 - Jei nė vienas iš 5 blokų nebuvo "iškastas", pailginti kasimo laiką arba bandymų skaičių ir pakartoti procesą.

# Merkle Root Hash
Merkle Root Hash buvo realizuotas jau versijoje v0.1. Jis veikia tokiu būdu:
Prainių maišų sudarymas:
Pradžioje sudaromas maišų sąrašas, kuriame yra kiekvienos transakcijos ID (hash'as siuntėjo+gavėjo+sumos).
Medžio formavimas:
Kol maišų sąraše yra daugiau nei vienas elementas:
 - Jei yra nelyginis elementų skaičius, paskutinis elementas pridedamas dar kartą, kad būtų lyginis skaičius.
 - Paskui kiekviena pora elementų sujungiama ir jų maišos vertė apskaičiuojama bei pridedama į naują sąrašą.
Naujas sąrašas tampa pradiniu sąrašu, ir šis procesas kartojamas tol, kol lieka tik vienas elementas.
Galiausiai tas vienintelis likęs elementas ir yra Merkle Root, kuri grąžinama kaip rezultatas.

![image](https://github.com/user-attachments/assets/881d115b-b629-4b7c-966a-f8036dc3e9c1)

# Transakcijų verifikavimas
## Balanso tikrinimas
Jeigu siuntėjo balanso likutis yra mažesnis už transakcijos sumą, tokia transakcija yra atmetama ir laikoma nesėkminga, todėl nepridedame jos į bloką.
Rankiniu būdu galima reguliuoti rėžius transakcijos sumos generavimui ir balanso generavimui, nuo ko priklauso galimas atmestų transakcijų kiekis. Pvz. nustatytas balanso galima suma nuo 100 iki 1 000 000, o transakcijos suma nuo 200 iki 200 0000. Gauname tiek sėkmingų ir atmestų transakcijų:

![image](https://github.com/user-attachments/assets/1f516086-c6a8-4cb5-9fdb-3176ea1d5b69)

Kadangi visos transakcijos (100 000) surašomos į blokus (po 100 transakcijų bloke), pagal atmestų transakcijų skaičių galime paskaičiuoti, kad 100-ajame bloke bus 39 transakcijos:

![image](https://github.com/user-attachments/assets/a23bc7e1-6f1a-43ce-9dea-7d3c38da4728)

Padidinę transakcijos sumos rėžius gausime daugiau atmestų transakcijų, ir mažiau sukurtų blokų. Pvz.:

![image](https://github.com/user-attachments/assets/de4de521-8614-4edb-bbd2-c7bce7de5aa6)

![image](https://github.com/user-attachments/assets/6488c365-20f4-4dbd-b0dc-72def27b8cd6)

## Transakcijos hasho tikrinimas
Tikriname ar transakcijosID yra tikrai deterministinis, tam rehashinam transakcijos informaciją ir lyginam jį su pradiniu transakcijosID.
Jeigu hashai nesutaps, tai tokia transakcija bus pridėta prie nesėkmingų ir neįtraukta į bloką, o ekrane galėsime matyti klaidos pranešimą apie transakcijos hashų nesutapimą.
Toks patikrinimas leidžia įsitikinti ar mūsų realizuota hash funkcija gerai veikia, ir atmesti įmanomas problemas, kad jos neįsiveltų į blokus.

# Decentralizuotas blokų kasimas
Sukūriau pasirinkimą vartotojo patogumui, kuris leidžia kurti ir kasti visus blokus, su visom sugeneruotom transakcijom arba pasirinkti kasti 5 blokus-kandidatus.

![image](https://github.com/user-attachments/assets/81db86bc-da17-4d51-ac81-8853d495d18a)

Visų pirma yra sugeneruojami vartotojai ir transakcijos, atliekamas transakcijų verifikavimas, po ko vartotojas gali pasirinkti ką jis nori atlikti su tom transakcijom.
Pasirinkus 2 opciją, programa pradeda kasti 5 blokus, kiekvieno bloko kasimui skiriamos 5 sekundės ir 100 000 bandymų, kol vienas blokas nebus iškastas, jeigu po pirmos iteracijos nėra iškasto bloko, dvigubiname laiko ir bandymų limtą. Kartojame procesą kol nebus iškastas blokas.
Veikimo greitis priklauso nuo difficulty, kurį galiu rankiniu būdu keisti: 

![image](https://github.com/user-attachments/assets/f0c21af7-c30a-4782-af68-822335e255f7)

Rezultatas su 4 difficulty:

![image](https://github.com/user-attachments/assets/2e9ed70c-c9cb-43c0-820c-c51981790968)

Rezultatas su 5 difficulty:

![image](https://github.com/user-attachments/assets/74a1ec68-3e5b-4a5e-b5a0-d345e9a106a1)

Pastebime, kad nespėjus išnaudoti viso laiko, pradedamas kasti kitas blokas. Taip yra dėl to, kad pasiekiamas bandymų limitas anksčiau nei išnaudojamas laikas (jeigu padidiname bandymų limitą, tai blokas yra iškasamas žymiai greičiau). Štai kodėl taip gali būti:

Spartus skaičiavimas: Jei blokai yra kasami greitai, per nustatytą laiką gali būti atliktas didelis bandymų skaičius. Tokiu atveju, bandymų skaičius pasieks maxbandymu ribą prieš pasibaigiant maxlaikas.

![image](https://github.com/user-attachments/assets/886577fa-af33-4f8e-8c22-565fc348dcdd)

Kodas: Kadangi kiekvienas ciklas tikrina bandymų limitą prieš laiko ribą, pasiekus maxbandymu bus iš karto nutraukta bandymų seka tam kandidatui, net jei turima laiko riba dar nėra pasiekta.

# OOP praktikos

Enkapsuliacija: Klasės Vartotojas privatūs nariai (vardas, publicKey, balansas) užtikrina, kad vidus būtų pasiekiamas tik per viešus metodus, pvz., getVardas() ir t.t.. Tai apsaugo duomenis. 

Konstruktoriai: Konstruktoriai, pvz., Vartotojas() ir Transakcija(), užtikrina, kad objektai būtų tinkamai sukurti su pradiniais duomenimis.

RAII idioma: Funkcijoje vardoskaitymas() failų srautai uždaromi automatiškai, kai objektas praranda reikšmę. Tai užtikrina saugų išteklių valdymą be rankinio uždarymo. T.y. kad resursai būtų atlaisvinit.

Modulizavimas: Klasės ir funkcijos yra suskirstytos į atskirus failus, todėl kodas yra tvarkingesnis, su lengvesniu skaitymu ir priežiūra.

# Naudojimosi instrukcija

Paleidus programą matysite transakcijų apžvalgą: kiek yra sėkmingų ir nesėkmingų transakcijų, pvz.:
![image](https://github.com/user-attachments/assets/c9cd2557-0527-4b5a-be80-aa4a8b506797)

Toliau programa leis jums pasirinkti vieną iš dviejų galimų variantų:
1. Kurti ir kasti visus blokus
2. Kasti 5 blokų kandidatus.

![image](https://github.com/user-attachments/assets/fe87da1a-971d-43ad-8de4-6ef71ad3ea66)

Pasirinkus pirmą variantą ekrane matysite visus blokus, su bloko informacija:

![image](https://github.com/user-attachments/assets/ec3930ad-145d-4fce-8f61-c97dd76950db)


Toliau programa paklaus kurio bloko transakcijas norėtumėte peržiūrėti:

![image](https://github.com/user-attachments/assets/b8486044-d53d-42c7-8fe9-472cd14eb6f4)

Galėsite peržiūrėti visas to bloko transakcijas. Po to vėl matysite klausimą, ar norite tęsti transakcijų išvedimą, turite pasirinkti y=taip arba n=ne:

![image](https://github.com/user-attachments/assets/bd934f23-2071-493f-a031-5c93e76614fd)

Pasirinkę, kad nenorite tęsti programa bus baigta.

Pereiname prie 2 pasirinkimo: 5 kandidatų kasimo.
Pasirinkę šį variantą programa pradės kasti blokus, kiekvienam blokų kasimui skiriamas tam tikras laikas ir bandymų skaičius, kurie bus didinami kol neišsikas blokas. Apie sėkmingai iškastą bloką bus matomas pranešimas ekrane su nonce reikšme. Jeigu bandymų arba laiko limitas bus viršijamas, ekrane matysime pranešimą apie tai, ir bus pereita prie bandymo iškasti sekantį bloką. Jeigu po pirmo kandidatų kasimo nepavyko iškasti nei vieno bloko, programa apie tai praneš, pratęs limitus ir bandys dar kartą.


# Veikimo principas
Vartotojai ir Transakcijos yra sugeneruojamos atitinkamai pagal reikalavimus, po ko yra skaičiuojama kiek iš viso yra sėkmingų transakcijų, kurias saugome mempoole. Transakcija yra laikoma nesėkminga ir jeigu transakcijos ID nesutapo su transakcijos informacijos hashu. Toliau yra kuriami blokai. Pirmas blokas, arba Genesis blokas neturi įtrauktų transakcijų, todėl neturi ir Merkle Root Hasho, jo eilės numeris yra žymimas 0, o ankstesnio bloko hashas yra nulių rinkinys. Sekantys blokai turės iki 100 įtrauktų transakcijų, kurios yra įvykdomos po įtraukimo i bloką ir atnaujinami balansai. Paskirsčius visas transakcijas, jos yra ištrinamos iš mempoolo su mempool.erase();. Blokai sujungiami su prev_block_hash, sudarant blokų grandinę. Kasant 5 kandidatus, transakcijos taip pat yra įvykdomos įtraukus jas į bloką.
(mempoole laikomos nepatvirtintos transakcijos, kol kol jos nesulauks patvirtinimo/įvykdymo per mining'ą)


# Papildomos užduotys

## UTXO 

UTXO (Unspent Transaction Output) modelis užtikrina, kad kiekviena valiutos vieneto dalis būtų panaudota tik vieną kartą ir kad visi balansai būtų patikimi.
Kiekviena transakcija sukuria naujus UTXO, kuriuos galima naudoti būsimiems mokėjimams. UTXO apibrėžia konkrečius lėšų vienetus, susietus su naudotojo viešuoju raktu (publicKey), kuriuos naudotojas gali išleisti būsimoms transakcijoms. Kiekviena transakcija sunaudoja ankstesnius UTXO kaip įėjimus ir sukuria naujus UTXO kaip išvestis.
Programoje UTXO padeda tiksliai sekti balansus, apsaugo nuo pakartotinio balanso išleidimo, užtikrina veikimo efektyvumą, leidžia bet kam pasitikrinti transakcijų autentiškumą ir balansą be tarpininkų.
    Surandu vartotojo turimus UTXO (getUTXOs funkcija).
    Pasirenku tinkamą UTXO rinkinį, kad suma atitiktų transakcijos vertę.
    Pažymiu panaudotus UTXO kaip panaudotus ir sukurkiu naujus UTXO gavėjui (+ grąžą UTXO siuntėjui).
    Atnaujinu UTXO baseiną (utxoPool), kad jame visada būtų naujausia neišleistų transakcijų reikšmė.
    
## Lygiagretus blokų kasimas

Lygiagrečiajam skaičiavimui naudoju OpenMp.

Visų pirma sužinojau maksimalų gijų skaičių su funkcija omp_get_max_threads();.

![image](https://github.com/user-attachments/assets/f7d5f2b9-78fc-4a30-b3a5-5cad4db7ee69)

Rankiniam gijų skaičiaus nustatymui naudoju omp_set_num_threads();, nes kitaip OpenMP automatiškai naudos tik numatytą gijų skaičių.


Keičiame gijų skaičių rankiniu būdu:

![image](https://github.com/user-attachments/assets/7f999fbb-836a-4b00-a574-7db285330992)


Paleidau testus su kiekviena gija po 10 kartų, kad galima būtų paskaičiuoti vidutiniškai iš kurio kurio bandymo kasti iškasamas blokas.
Programa vienu metu bando kasti 5 blokus, paskirstydama darbą per skirtingas gijas. Testo rezultatas, tai iš kurio vidutiniškai karto buvo iškastas blokas.(1kartas = 1bloko kasimas)
Visi testai buvo atliekami su difficulty=5.

### 1 gija
Su 1 gija blokas iškasamas vidutiniškai iš 10 kasimo
CPU apkrova vidutiniškai yra 16%, bet nekyla aukščiau 24%
### 2 gijos
2 gijos vidutiniškai iškasa iš 13 kasimo
CPU apkrova vidutiniškai yra 36%, bet nekyla aukščiau 39%
### 4 gijos
4 gijos vidutiniškai iškasa iš 9 kasimo
CPU apkrova vidutiniškai yra 53%, bet nekyla aukščiau 63%.

### 8 gijos
Su 8 gijom blokas iškasamas vidutiniškai iš 6 kasimo
CPU apkrova vidutiniškai 57%, bet nekyla aukščiau 79%

### CPU akrovos priklausomybė nuo gijų skaičiaus grafiškai
Grafike vaizduojama maksimali CPU apkrova (%) priklausomai nuo naudojamų gijų skaičiaus.
![image](https://github.com/user-attachments/assets/d742dfbf-0d92-40c4-bcf9-ea3bb8f8493f)


