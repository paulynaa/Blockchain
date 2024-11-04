# Blockchain


kandidatai
su 4 difficulty

![image](https://github.com/user-attachments/assets/2e9ed70c-c9cb-43c0-820c-c51981790968)


su 5 difficulty

![image](https://github.com/user-attachments/assets/74a1ec68-3e5b-4a5e-b5a0-d345e9a106a1)


tai yra visiškai įmanoma, kad bandymų limitas (maxAttempts) baigsis anksčiau nei bus pasiektas laiko limitas (maxDuration). Štai kodėl:

    Didelė skaičiavimo sparta: Jei blokai yra kasami greitai (skaiciavimas() funkcija vykdoma sparčiai), per nustatytą laiką gali būti atliktas didelis bandymų skaičius. Tokiu atveju, bandymų skaičius pasieks maxAttempts ribą prieš pasibaigiant maxDuration.

    Dabartinis kodas: Kadangi kiekvienas ciklas tikrina bandymų limitą prieš laiko ribą, pasiekus maxAttempts bus iš karto nutraukta bandymų seka tam kandidatui, net jei turima laiko riba dar nėra viršyta.

utxo 

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

openmp
suzinojau numatyta giju skaiciu

![image](https://github.com/user-attachments/assets/19a725e3-f150-4f93-9a56-b9409a219ba8)

Jei sistemoje numatytas gijų skaičius (pagal CPU branduolius) yra, tarkime, 4, OpenMP automatiškai paskirstys darbą 4 gijoms.

![image](https://github.com/user-attachments/assets/c0ce0a4c-ff57-4fdb-a0b2-f94d48e334ab)

toliau galime keisti giju skaiciu rankiniu budu:
su 5
![image](https://github.com/user-attachments/assets/9b0bdfb4-269a-4bd2-a81a-5ad51c4ee8a5)
su 10


