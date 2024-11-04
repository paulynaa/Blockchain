# Blockchain


kandidatai
su 4 difficulty

![image](https://github.com/user-attachments/assets/2e9ed70c-c9cb-43c0-820c-c51981790968)


su 5 difficulty

![image](https://github.com/user-attachments/assets/74a1ec68-3e5b-4a5e-b5a0-d345e9a106a1)


tai yra visiškai įmanoma, kad bandymų limitas (maxAttempts) baigsis anksčiau nei bus pasiektas laiko limitas (maxDuration). Štai kodėl:

    Didelė skaičiavimo sparta: Jei blokai yra kasami greitai (skaiciavimas() funkcija vykdoma sparčiai), per nustatytą laiką gali būti atliktas didelis bandymų skaičius. Tokiu atveju, bandymų skaičius pasieks maxAttempts ribą prieš pasibaigiant maxDuration.

    Dabartinis kodas: Kadangi kiekvienas ciklas tikrina bandymų limitą prieš laiko ribą, pasiekus maxAttempts bus iš karto nutraukta bandymų seka tam kandidatui, net jei turima laiko riba dar nėra viršyta.


