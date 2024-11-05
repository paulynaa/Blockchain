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
Jeigu siuntėjo balanso likutis yra mažesnis už transakcijos sumą, tokia transakcija yra atmetama ir laikoma nesėkminga, todėl nepridedamo jos į bloką.
Rankiniu būdu galima reguliuoti rėžius transakcijos sumos generavimui ir balanso generavimui, nuo ko priklauso galimas atmestų transakcijų kiekis. Pvz. nustatytas balanso galima suma nuo 100 iki 1 000 000, o transakcijos suma nuo 200 iki 200 0000. Gauname tiek sėkmingų ir atmestų transakcijų:

![image](https://github.com/user-attachments/assets/1f516086-c6a8-4cb5-9fdb-3176ea1d5b69)

Kadangi visos transakcijos (100 000) surašomos į blokus (po 100 transakcijų bloke), pagal atmestų transakcijų skaičių galime paskaičiuoti, kad 100-ajame bloke bus 39 transakcijos:

![image](https://github.com/user-attachments/assets/a23bc7e1-6f1a-43ce-9dea-7d3c38da4728)

Padidinę transakcijos sumos rėžius gausime daugiau atmestų transakcijų, ir mažiau sukurtų blokų. Pvz.:

![image](https://github.com/user-attachments/assets/de4de521-8614-4edb-bbd2-c7bce7de5aa6)

![image](https://github.com/user-attachments/assets/6488c365-20f4-4dbd-b0dc-72def27b8cd6)

## Transakcijos hasho tikrinimas
Tikriname ar transakcijosID yra tikrai deterministinis, tam rehashinam transakcijos informaciją ir lyginam jį su pradiniu transakcijosID.
Jeigu hashai nesutaps, tai tokia transakcija bus pridėta prie nesėkmingų ir neįtraukta į bloką, o ekrane galėsime matyti Klaidos pranešimą apie transakcijos hashų nesutapimą.
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

Pastebime, kad nespėjus išnaudoti viso laiko, pradedamas kasti kitas blokas. Taip yra dėl to, kad pasiekiamas bandymų limitas anksčiau nei išnaudojamas laikas. Štai kodėl taip gali būti:
Spartus skaičiavimas: Jei blokai yra kasami greitai, per nustatytą laiką gali būti atliktas didelis bandymų skaičius. Tokiu atveju, bandymų skaičius pasieks maxAttempts ribą prieš pasibaigiant maxDuration.

![image](https://github.com/user-attachments/assets/886577fa-af33-4f8e-8c22-565fc348dcdd)

Kodas: Kadangi kiekvienas ciklas tikrina bandymų limitą prieš laiko ribą, pasiekus maxAttempts bus iš karto nutraukta bandymų seka tam kandidatui, net jei turima laiko riba dar nėra pasiekta.

## igyvendinta

# versija v0.2
## reikalavimai
## igyvendinta
# naudojimosi instrukcija

Paleidus programą matysite transakcijų generavimo procesą (transakcijos nėra išvedamos į konsolę):

![image](https://github.com/user-attachments/assets/7993f170-528b-4f5f-aa7b-37ba5a3c4d8c)

 tai įvyks po to, jeigu vartotojų generavimas bus sėkmingas. Sugeneruotos transakcijos bus įtrauktos į bloką, t.y. iš viso bus išvesta 100 blokų su sekančia informacija: Bloko eilės numeris, Praeito bloko hash, Dabartinio bloko hash, Bloko maišos reikšmės sudėtingumas, Laiko žyma, Merkel Root hash, Nonce, Versija, Transakcijų kiekis bloke, Miner'is (pvz žemiau):
 
![image](https://github.com/user-attachments/assets/3c430348-b5d3-4161-bf0a-75d732f5566e)

Kai transakcijos bus įtrauktos į bloką, vartotojas galės pasirinki, ar jis nori peržiūrėti kažkurio bloko transakcijas. Jeigu vartotojas nori peržiūrėti transakcijas, jis turėtų įrašyti bloko eilės numerį, pvz.:

![image](https://github.com/user-attachments/assets/c900bc4c-4240-434b-aafe-7d8742788858)

Matysite siuntėjo Public Key, gavėjo Public Key, transakcijos sumą ir transakcijos ID, t.y. transakcijos duomenų maišos reikšmę.
Pasirinkus, kad nenorite tęsti transakcijų peržiūros, programa bus baigta.


# veikimas



# trukumu pasalinimas
v0.1 versijoje nebuvo igyvendinta ir ttt...

## oop


# papildomos uzduotys
# utxo 

UTXO (Unspent Transaction Output) modelis yra esminė transakcijų stebėjimo sistema, naudojama daugelyje blokų grandinių, pvz., Bitcoin tinkle. Jis užtikrina, kad kiekviena valiutos vieneto dalis būtų panaudota tik vieną kartą ir kad visi balansai būtų patikimi. UTXO modelis turi kelis privalumus ir pritaikymo atvejus, kurie gali būti naudingi jūsų programoje.
Kas yra UTXO modelis?

UTXO modelis reiškia "neišleistas transakcijos išvestis" (angl. Unspent Transaction Output). Kiekviena transakcija sukuria naujus UTXO, kuriuos galima naudoti būsimiems mokėjimams. UTXO apibrėžia konkrečius lėšų vienetus, susietus su naudotojo viešuoju raktu (arba adresu), kuriuos naudotojas gali išleisti būsimoms transakcijoms. Kiekviena transakcija sunaudoja ankstesnius UTXO kaip įėjimus ir sukuria naujus UTXO kaip išvestis.
Kaip UTXO modelis padeda jūsų programoje?

Jūsų programoje UTXO modelis padeda:

    Tiksliai sekti balansus: Naudojant UTXO, kiekvieno vartotojo balansą galima apibrėžti kaip visų jo neišleistų transakcijų sumą. Tai leidžia lengviau patikrinti, ar vartotojas turi pakankamai lėšų naujai transakcijai.

    Patikimumas ir apsauga nuo dvigubo išleidimo: Kadangi kiekvienas UTXO gali būti panaudotas tik vieną kartą, sistema automatiškai apsaugo nuo dvigubo išleidimo. Jei vartotojas bando panaudoti tą patį UTXO kelis kartus, sistema atmes antrąją transakciją kaip neleistiną.

    Greitesnis patikrinimas: Kiekvieną kartą, kai vartotojas nori atlikti transakciją, nereikia ieškoti visos transakcijų istorijos, kad patikrintumėte balansą. Vietoje to, galima tiesiog patikrinti neišleistus UTXO, todėl operacijos tampa efektyvesnės ir greitesnės.

    Lankstumas didesnėms ar mažesnėms transakcijoms: Jei vartotojo balansas sudarytas iš kelių skirtingų UTXO, galima pasirinkti jų kombinaciją, atitinkančią norimą sumą. Tai leidžia atlikti transakcijas pagal reikiamus dydžius ir efektyviai išlaikyti balanso būseną.

    Decentralizuota balanso stebėsena: Kadangi UTXO yra tiesioginės transakcijų išvestys, kiekvienas gali patikrinti turimus UTXO atviroje blokų grandinėje. Tai leidžia bet kam pasitikrinti transakcijų autentiškumą ir balanso teisingumą be tarpininkų.

Kaip tai pritaikyti jūsų programoje?

Jūsų programoje UTXO padeda tvarkyti balansus ir valdyti transakcijų įrašus:

    Balanso apskaičiavimas: Kai vartotojas bando atlikti transakciją, galite suskaičiuoti visų vartotojo turimų UTXO sumą, kad patikrintumėte balansą.
    Transakcijos sumos pasirinkimas: Kadangi vartotojo balansas susideda iš UTXO, galite pasirinkti tinkamus UTXO, kurie atitiktų reikiamą sumą transakcijai. Jei transakcijos suma mažesnė nei UTXO vertė, sukurkite „grąžos“ UTXO vartotojui.
    Nepanaudoti ir panaudoti UTXO: Kai transakcija atliekama, sunaudojate siuntėjo UTXO kaip įėjimą ir sukuriate naujus UTXO gavėjui (bei siuntėjui, jei yra grąžos). Tai užtikrina, kad panaudoti UTXO nebegalėtų būti naudojami kitose transakcijose.

Pavyzdys jūsų programos kontekste

Jūsų programoje, kai vartotojas bando atlikti transakciją:

    Surandate vartotojo turimus UTXO (getUTXOs funkcija).
    Pasirenkate tinkamą UTXO rinkinį (arba jų kombinaciją), kad suma atitiktų transakcijos vertę.
    Pažymite panaudotus UTXO kaip panaudotus ir sukurkite naujus UTXO gavėjui (ir grąžos UTXO siuntėjui, jei reikia).
    Atnaujinate UTXO baseiną (utxoPool), kad jame visada būtų naujausia neišleistų transakcijų išvestis.
# lygiagretus
openmp

Sužinojau maksimalų gijų skaičių su funkcija omp_get_max_threads();.


![image](https://github.com/user-attachments/assets/f7d5f2b9-78fc-4a30-b3a5-5cad4db7ee69)

![image](https://github.com/user-attachments/assets/c0ce0a4c-ff57-4fdb-a0b2-f94d48e334ab)

Rankiniam gijų skaičiaus nustatymui naudoju omp_set_num_threads();, nes kitaip OpenMP automatiškai naudos tik numatytą gijų skaičių.


Keičiame gijų skaičių rankiniu būdu:

![image](https://github.com/user-attachments/assets/7f999fbb-836a-4b00-a574-7db285330992)


Paleidau testus su kiekviena gija po 6 kartus, kad galima būtų paskaičiuoti vidutiniškai iš kurio kurio kasimo iškasamas blokas.
Programa vienu metu bando kasti blokus, paskirstydama darbą per skirtingas gijas. Testo rezultatas, tai kiek vidutiniškai buvo bandoma iškasti blokų, kol buvo iškastas bent vienas.
Visi testai buvo atliekami su difficulty=5.
## 1 gija
su 1 gija vidutiniskai is 10 kasimo
11, 24, nekyla auksciau 24 proc

## 2 gijos
2 gijos vidutiniskai is 13 kasimo
CPU apkrova vidutiniškai yra 36%, bet nekyla aukščiau 39%
## 4 gijos
4 gijos vidutinisksai is 10 kasimo
CPU apkrova vidutiniškai yra 53%, bet nekyla aukščiau 63%.

## 8 gijos
su 8 gijom vidutiniskai is 6 kasimo
CPU apkrova vidutiniškai 57%, bet nekyla aukščiau 79%

## CPU akrovos priklausomybė nuo gijų skaičiaus grafiškai
Grafike vaizduojama maksimali CPU apkrova (%) priklausomai nuo naudojamų gijų skaičiaus.
![image](https://github.com/user-attachments/assets/d742dfbf-0d92-40c4-bcf9-ea3bb8f8493f)


