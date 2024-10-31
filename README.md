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

# Reikalavimai versijai v0.1
1. Realizuoti supaprastintą "centralizuotą" blokų grandinę. Maišos funkcijai naudoti savo sukurtą funkciją.
2. Transakcijų ir blokų kūrimo procesas turi būti matomas. Sukurti funkcijas, kurios leidžia atspausdinti bet
kurią transakciją ir bloką. Išvedimo detalumas ir vizualumas turės įtakos balui.
3. Vietoj dvejetainio Merkle medžio, galite naudoti visų bloko transakcijų ID maišos reikšmę.
4. Saugumas yra labai svarbus blokų grandinėms, todėl naudokite gerąsias OOP praktikas (pvz., enkapsuliavimą,
konstruktorius, RAII idiomą).

# Naudojimosi instrukcija

Paleidus programą matysite transakcijų generavimo procesą (transakcijos nėra išvedamos į konsolę):

![image](https://github.com/user-attachments/assets/7993f170-528b-4f5f-aa7b-37ba5a3c4d8c)

 tai įvyks po to, jeigu vartotojų generavimas bus sėkmingas. Sugeneruotos transakcijos bus įtrauktos į bloką, t.y. iš viso bus išvesta 100 blokų su sekančia informacija: Bloko eilės numeris, Praeito bloko hash, Dabartinio bloko hash, Bloko maišos reikšmės sudėtingumas, Laiko žyma, Merkel Root hash, Nonce, Versija, Transakcijų kiekis bloke, Miner'is (pvz žemiau):
 
![image](https://github.com/user-attachments/assets/3c430348-b5d3-4161-bf0a-75d732f5566e)

Kai transakcijos bus įtrauktos į bloką, vartotojas galės pasirinki, ar jis nori peržiūrėti kažkurio bloko transakcijas. Jeigu vartotojas nori peržiūrėti transakcijas, jis turėtų įrašyti bloko eilės numerį, pvz.:

![image](https://github.com/user-attachments/assets/c900bc4c-4240-434b-aafe-7d8742788858)

Matysite siuntėjo Public Key, gavėjo Public Key, transakcijos sumą ir transakcijos ID, t.y. transakcijos duomenų maišos reikšmę.
Pasirinkus, kad nenorite tęsti transakcijų peržiūros, programa bus baigta.


# Veikimo principas

Programa sukuria 1 000 vartotojų, kiekvienam suteikia vardą (išrenka atsitiktinį vardą iš failo vardai.txt), viešąjį raktą ir pradinį balansą. Vartotojo duomenys saugomi vektoriuje vartotojai. Naudojama klasė Vartotojas.

Sugeneruojama 10 000 transakcijų, kiekviena transakcija tai atsitiktinės sumos pervedimas kitam vartotojui. Atlikus transakciją siuntėjo ir gavėjo balansai yra atnaujinami (dar nenaudojamas UTXO modelis). Naudojama klasė Transakcija. Reikalavimuose prašoma generavimo procesą atvaizduoti konsolėje, bet visas transakcijas (10 000) vaizduoti ekrane yra beprasmiška, todėl buvo nuspręsta pavaizduoti taip, kaip įklijuota aukščiau (Naudojimosi instrukcija).

Klasė Blokas naudojama darbui su blokų informacija. Kiekviename bloke talpinamos 100 atsitiktinių transakcijų. Apskaičiuojamas šių transakcijų Merkle Root maišos kodas ( hashina transakcijas ir poras, kol neliks tik vienas hashas) ir vykdomas Proof-of-Work procesas, ieškant bloko maišos, atitinkančios nustatytą sudėtingumo lygį (difficulty target). Sėkmingai sukūrus bloką, jis pridedamas prie blokų grandinės. Visi blokai yra išvedami į ekraną, o bloko transakcijas galima peržiūrėti savarankiškai įvedus bloko eilės numerį. Vedant informaciją į ekraną buvo pasiremta šiuo pvz.: https://www.blockchain.com/explorer/blocks/btc/868177 .
Į bloką įrašytos transakcijos yra ištrinamos iš vektoriaus ir procesas kartojamas kol neliks neįtrauktų transakcijų.

OOP praktikos:
Kapsuliacija: Visos klasės savybes ir metodus laiko privačius arba viešuosius, o neeksportuojami duomenys nėra tiesiogiai prieinami kitoms programos dalims. Tai užtikrina duomenų vientisumą, nes kitos klasės negali tiesiogiai keisti duomenų.

SRP: Programoje laikomasi SRP principo, nes kiekviena klasė turi tik jai priskirtą atsakomybę, pvz.: Transakcija klasė tvarko transakcijos duomenis ir jų hash'ų skaičiavimą, kai tuo tarpu Blokas rūpinasi bloko maišų skaičiavimu ir kita informacija.

# Tobulinimas
Versijoje v0.2 užtikrinti didesnį duomenų saugumą, naudoti UTXO modelį balansam, patobulinti informacijos išvedimo būdą į konsolę. Įvykdyti reikalavimus versijai v0.2.
