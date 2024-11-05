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

![image](https://github.com/user-attachments/assets/475dacc7-0d88-4f2b-8694-2ef7432affcc)


![image](https://github.com/user-attachments/assets/19a725e3-f150-4f93-9a56-b9409a219ba8)

Jei sistemoje numatytas gijų skaičius (pagal CPU branduolius) yra, tarkime, 4, OpenMP automatiškai paskirstys darbą 4 gijoms.

![image](https://github.com/user-attachments/assets/c0ce0a4c-ff57-4fdb-a0b2-f94d48e334ab)

toliau galime keisti giju skaiciu rankiniu budu:
su 5
![image](https://github.com/user-attachments/assets/9b0bdfb4-269a-4bd2-a81a-5ad51c4ee8a5)
su 10

1 gija
![image](https://github.com/user-attachments/assets/996297b6-d9b8-4fee-be7b-33f7d899a629)
.

![image](https://github.com/user-attachments/assets/b6fad8f8-5526-4202-a3ff-0f87c6871f14)
.
![image](https://github.com/user-attachments/assets/4b913ea6-112e-4d6d-8d84-fffc2548c382)
.
![image](https://github.com/user-attachments/assets/2bc8967b-9865-47cc-8a76-e629d5ab129c)
.
![image](https://github.com/user-attachments/assets/81fe883d-d4f8-495b-9b3b-84110c6851a1)


11, 24, nekyla auksciau 24 proc

2 gijos su 5
![image](https://github.com/user-attachments/assets/b22c3c47-2509-4a88-abb8-54aed25d42d6)
.
![image](https://github.com/user-attachments/assets/ce6e1546-6105-4733-ac15-148ef582c6ac)
.

![image](https://github.com/user-attachments/assets/04af7189-1753-4725-9805-311bc9d5bd98)
.

![image](https://github.com/user-attachments/assets/3dfd5cd7-44f2-45f9-bf3b-33f2edfda311)
.

![image](https://github.com/user-attachments/assets/3fc68024-9da1-496e-8636-9b57e1cd0e07)

nekyla auksciau 40, 36 vid,
4 gijos 5 difficulty
![image](https://github.com/user-attachments/assets/9edb7610-2f77-4071-ba97-eda08f8e8af4)
.
![image](https://github.com/user-attachments/assets/8537a164-5f74-4208-8b16-f730474321f9)
.

![image](https://github.com/user-attachments/assets/773911f9-7823-43eb-bad3-e043ceb6c8c6)
.
![image](https://github.com/user-attachments/assets/59000b4b-9257-44a1-91a8-67b4bbebf0dd)
.
![image](https://github.com/user-attachments/assets/a7b07890-e7ed-42d2-b858-edb84b42faf8)
.
![image](https://github.com/user-attachments/assets/2908b9ce-643b-4cd2-a057-5cc049433cb7)
.


 55proc, nekyla auksciau 63 , 

8 gijos 5 difficulty
![image](https://github.com/user-attachments/assets/a61ba917-6e6c-489c-bb28-220fa5343fa7)
.
![image](https://github.com/user-attachments/assets/dee5d288-c6cb-4099-a4c9-f3ee4f255389)
.
![image](https://github.com/user-attachments/assets/5dd2bfb1-da37-4c12-90e7-a7fccb2ce76b)
.
![image](https://github.com/user-attachments/assets/772a7a02-5784-4232-982d-2bcd6e0bc26b)
.


iki 75 proc 55, 15, nekyla auksciau 79
 rezultatu lentele

