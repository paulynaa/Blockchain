# Instaliavimas ir diegimas

## Node.js

Pasinaudojam nuoroda: 
https://nodejs.org/en

Spaudžiame Download:

![image](https://github.com/user-attachments/assets/af962581-a619-4a5a-9ef9-dbf769d4db42)

Patikrinam ar viskas gerai į CMD įvedę node -v

![image](https://github.com/user-attachments/assets/2a4d984a-84eb-4e2a-b938-b9acbd40e9db)

## Truffle IDE

https://archive.trufflesuite.com/docs/truffle/how-to/install/

Įsidiegę node, į terminalą suvedam :
npm install -g truffle

Patikrinam ar tvaringai susiinstaliavo:
truffle version.

## Ganache

https://archive.trufflesuite.com/ganache/

Paspaudus nuorodą aukščiau, spaudžiame Download:

![image](https://github.com/user-attachments/assets/01e7bfbe-c5ce-4d01-8b24-75e8124adccb)

## MetaMask

Parsisiunčiam MetaMask extension: https://metamask.io/download/

![image](https://github.com/user-attachments/assets/f6740e9c-0c27-4d34-9b84-65007bddc896)


https://metamask.io/

Čia pagrindiniame puslapyje spaudžiame "View MetaMask web" ir toliau "Connect MetaMask", suvedame savo slaptažodį:



# Case Study

Išmaniosios sutarties pagalba realizavau Crowdfunding (minios finansavimas) projektą, kuriame gali dalyvauti daug žmonių (remėjų), norinčių pafinansuoti tam tikrą projektą. 
? Savininkas iškelia savo projektą su nustatyta suma, kurią jis tikisi pasiekti per tam tikrą laiko atkarpą. Žmonės, susidomėję projektu, gali jį pafinansuoti, pervedant norimą pinigų sumą (ETH). Projektas yra sėkmingas tada, kai pasiekiama nustatyta pinigų suma, jam nepasibaigus. Savininkas gali išsiimti pinigus tik tuo atveju, kai pasiekiamas limitas. Jeigu projektas buvo nesėkmingas ir nustatytam laikui pasibaigus, pinigai yra grąžinami visiems remėjams.
Remėjai, priklausant nuo projekto tipo, gali gauti kažkokį finansinį arba materialų atlygį, tačiau mano mintis buvo padaryti aukojimo tipo crowdfunding'ą (pavaizduota diagramoje žemiau).

<img src="https://github.com/user-attachments/assets/46fd660d-d907-465d-bd69-5ee6b3af38e6" width="700" height="200">

Norint saugiai ir patikimai įgyvendinti šią idėją naudojama išmanioji sutartis (Etherium blokų grandinių tinkle), kuri padeda automatizuoti procesus.
Štai diagrama, kuri aiškiai vaizduoja įvykių eiliškumą:

![image](https://github.com/user-attachments/assets/58f9018a-bc97-4958-acf5-29d4ac7be24e)


Projekto savininkas sukuria projektą su tokiomis savybėmis:
- Minimalus lėšų tikslas.
- Galutinis terminas (timestamp formatu).

Vartotojai gali prisidėti prie projekto, siųsdami ETH.

Kai pasibaigia projekto laikotarpis:

- Jei lėšų tikslas pasiektas, kūrėjas gali atsiimti ETH.
- Jei lėšų tikslas nepasiektas, vartotojai gali susigrąžinti savo įnašus.


## Egzistuojantys sprendimai:

### Kickstarter

Kickstarter yra viena didžiausių pasaulyje sutelktinio finansavimo platformų. Projektų kūrėjai pateikia projektus, nustato finansavimo tikslą ir laikotarpį. Jei projektas surenka pakankamai lėšų, jos pervedamos kūrėjui. Jei ne, lėšos grąžinamos rėmėjams.
       
### Indiegogo

Kita populiari platforma, kuri leidžia rinkti lėšas dviem būdais: "viskas arba nieko" (kaip mano įgyvendintas modelis) ir "flexible funding" (kai surinktos lėšos perduodamos, net jei tikslas nepasiektas).
       
### Gitcoin Grants

Blockchain paremta platforma, kurioje projektai gali gauti finansavimą iš bendruomenės, naudojant kriptovaliutas.


## Decentralizuotas valdymas

Tradicinės platformos reikalauja trečiosiosios šalies įsikišimo lėšų valdymui(pvz., Kickstarter valdymas). Decentralizuotame valdyme (naudojant etherium blockchain) nėra šio tarpininko (nė viena institucija ar asmuo negali manipuliuoti lėšomis, o visi sandoriai yra viešai matomi Ethereum tinkle):

- Rėmėjai yra tikri, kad jų lėšos bus arba perduotos kūrėjui, arba grąžintos, priklausomai nuo sutarties sąlygų.
- Kūrėjas turi garantiją, kad lėšos bus automatiškai pervestos, kai pasieks tikslą.

(kodėl išmanioji sutartis garantuoja patikimumą?)


Išmaniosios sutartys automatizuoja visą procesą:

- Taisyklių vykdymas užprogramuotas, todėl nereikia trečiosios šalies įsikišimo.
- Tai sumažina administracinius kaštus.

  
