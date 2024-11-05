# Blockchain
# versija v0.1
## reikalavimai
## igyvendinta
# versija v0.2
## reikalavimai
## igyvendinta
# naudojimosi instrukcija

# veikimas

# be lygiagretaus skaiciavimo
kandidatai
su 4 difficulty

![image](https://github.com/user-attachments/assets/2e9ed70c-c9cb-43c0-820c-c51981790968)


su 5 difficulty

![image](https://github.com/user-attachments/assets/74a1ec68-3e5b-4a5e-b5a0-d345e9a106a1)


tai yra visiškai įmanoma, kad bandymų limitas (maxAttempts) baigsis anksčiau nei bus pasiektas laiko limitas (maxDuration). Štai kodėl:

    Didelė skaičiavimo sparta: Jei blokai yra kasami greitai (skaiciavimas() funkcija vykdoma sparčiai), per nustatytą laiką gali būti atliktas didelis bandymų skaičius. Tokiu atveju, bandymų skaičius pasieks maxAttempts ribą prieš pasibaigiant maxDuration.

    Dabartinis kodas: Kadangi kiekvienas ciklas tikrina bandymų limitą prieš laiko ribą, pasiekus maxAttempts bus iš karto nutraukta bandymų seka tam kandidatui, net jei turima laiko riba dar nėra viršyta.


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


