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


## HardHat

![image](https://github.com/user-attachments/assets/6a42af38-88d7-489c-a102-25a3efcb2998)

Hardhat is a development environment for Ethereum software. It consists of different components for editing, compiling, debugging and deploying your smart contracts and dApps, all of which work together to create a complete development environment.


## Goerli



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



# Remix IDE

https://remix.ethereum.org/#lang=en&optimize=false&runs=200&evmVersion=null&version=soljson-v0.8.26+commit.8a97fa7a.js

Parašius kodą, galime jį sukompiliuoti per Solidity compiler:

![image](https://github.com/user-attachments/assets/5b0f5ae9-5454-42cf-b2a9-64529d94a2d3)

Spaudžiame Compile *.sol :

![image](https://github.com/user-attachments/assets/80e4f7da-ab1a-4de5-b29d-8e1f0bafbeb9)

Žalia varnelė nurodo, kad nebuvo nustatyta jokių klaidų:

Skyriuje Deploy and Run Transactions randame mygtuką Deploy ir skyrelį Deplyed Contracts, kur galėsime pildyti norimus duomenis.

Visų pirmą sukuriame projektą ir spaudžiame transact:


![image](https://github.com/user-attachments/assets/fd4ab627-1c8a-4c50-bd17-4c394d9a08df)


Matome daug langelių, kuriuos galime pildyti ir atlikti transakcijas:

![image](https://github.com/user-attachments/assets/debc733b-c63a-4cd5-89e3-e7764b0045f2)

Pvz. sukuriame 2 skirtingus aukojimo lygius: mini ir maxi (kadangi skaičiuojama nuo 0, tai mini bus 0, maxi 1 pagal eiliškumą):

![image](https://github.com/user-attachments/assets/e87b57bb-e8fa-4b29-a372-f8013bd72d2f)

Su mygtuku getTiers patikriname ar lygiai buvo sėkmingai sukurti:

![image](https://github.com/user-attachments/assets/509bdfbd-8b26-4b4e-b0bf-30d850e47c1e)

Laukelyje finansuoti suvedame tierą (0 arba 1), priklausomai nuo norimos paaukoti sumos:

![image](https://github.com/user-attachments/assets/32acc0a6-f975-412c-a202-a4188148dd6f)

Paaukoję galime paspausti mygtuką Balansas ir matysime projekto balansą:

![image](https://github.com/user-attachments/assets/0fc310c7-aea4-4333-960d-5332eae0fb4c)

Taip pat paspaudę mygtuką getCampaignStatus, galime patikrinti projekto statusą, čia 0 = Vyksta, 1 = Pavyko, 2 = Nepavyko :

![image](https://github.com/user-attachments/assets/233f6b23-95cd-47f9-b7e3-bb249c5b8b41)


Porą kartu parėmus projektą patikrinam jo Balansą ir statusą:

![image](https://github.com/user-attachments/assets/73a1205b-6df0-4b78-9e77-c863bc0e127b)

![image](https://github.com/user-attachments/assets/f436bcb6-3d83-4ce2-91da-58d3d4aad561)

Nustatę savininko adresą, galime išsiimti pinigus:

![image](https://github.com/user-attachments/assets/de4f6e58-07a1-4c24-93f1-a8ca2ebd5e0f)

Po ko projekto balansas bus 0:

![image](https://github.com/user-attachments/assets/bd97a87a-40ba-40bb-9e30-ed02e1a295a6)


# Thirdweb deploy ir publish

install thirdweb

npx thirdweb create

![image](https://github.com/user-attachments/assets/e95e06f6-a605-4c42-9bf8-ca28afd313db)

Visual Studio Code, čia atidarome aplankalą, kuriame guli mūsų sutartis, ir sukuriame *.sol failus. Perkeliame iš Remixo kodus į VScode.

Turime susikurti ThirdWeb paskyrą, ir sukurti projektą, po ko gausime projekto PrivateKey. 

Po ko grįžtame į VScode ir atidarome terminalą, ten suvedame: npx thirdweb deploy -k (+PrivateKey).

![image](https://github.com/user-attachments/assets/639d9764-201c-47e9-a9e4-a23bb1c65f89)

Sekame nuorodą ir atsiduriame čia:

![image](https://github.com/user-attachments/assets/3ad64a3b-a374-4c83-b646-c382f1f4cc60)

Pasirenkame testinį tinklą Localhost.

Nustatymuose pakeičiam RPC URL iš Ganache.
Prieš tai atsidarę Ganache, išsaugom tinklą, paimam Index 1 accounto PrivateKey ir importuojam jį į MetaMask, sukurdami naują Accountą:

![image](https://github.com/user-attachments/assets/bf8f23fb-0a47-4654-b557-4d1e9bc6e3b0)


Spaudžiam Deploy Now.

MetaMask pop up'ins ir turėsim patvirtinti transakciją ir pasirašyti, iškart galime peržiūrėti sutartį paspaudę View Contract:

![image](https://github.com/user-attachments/assets/4a6a3cdd-376d-4f1c-b02b-5c5a844dd3b7)

Galime iškart tikrinti Ganache, ar sutartis susikūrė:

![image](https://github.com/user-attachments/assets/2c210299-1917-48d2-9db7-d726e08ef5d8)

Toliau einame į VScode ir terminale suvedam npx thirdweb publish -k ir pridedame PrivateKey

Gauname tokį outputą ir pereiname per pateiktą nuorodą: 

![image](https://github.com/user-attachments/assets/c058dcdf-712a-4098-aa5f-d3f1f3ba54cc)


Užpildome reikiamus laukus, pavadinima sutarties, aprašymą ir spaudžiam Deploy via factory, kad galėtume sekti per CrowdfundingFactory sutartį, kas deploy'ina sutartis.

![image](https://github.com/user-attachments/assets/2195be51-40be-492d-af2a-fb14787207f5)

Toliau paspaudę Publish contract, pasirašome per MetaMask.

Susikuriame naują testinį projektą, per MetaMask patvirtinam, kad būtų sumokėta už transakciją.

Patrikrinam ar projektas buvo sukurtas: 

![image](https://github.com/user-attachments/assets/57029438-52c1-4b2f-b8ff-81889f1c8de7)

Toliau grįžtame į sutarties deploy'inimą, čia spaudžiame Deploy Now:

![image](https://github.com/user-attachments/assets/0feb99a7-762c-4763-815f-5187c5596c11)

Supildome laukus ir spaudžiame Deploy Now:

![image](https://github.com/user-attachments/assets/303c5b95-7385-41a0-8a01-e9fda2a37480)



Atidarome CMD ir suvedame npx thirdweb create app

Framework pasirenkame Next.js, ir sukuriame pavadinimą.

Tada įrašome cd (pavadinimas) ir rašome code . 

Atsidarys VSCode, kuriame galėsime kurti Front-Endą.

Toliau atidarome CMD terminalą per VSCode ir suvedame yarn dev, galėsim stebėti kaip keičiasi mūsų tinklapis realiu laiku. 

Svarbu visur išsisaugoti Projekto adresą, Sutarties adresą, Naudojamos piniginės sutarties kūrimui adresą ir t.t.


# Išmaniosios sutarties testavimas testiniame tinkle Sepolia

Kad gaučiau nemokamų 0.05 ETH pereinu čia: 

https://cloud.google.com/application/web3/faucet/ethereum/sepolia

Suvedu piniginės adresą, pakeičių tinklą į Sepolia ir gaunu pinigų:

![image](https://github.com/user-attachments/assets/518347b0-3dfb-4c19-83fe-c09ba9587c04)


Prieš tai deployinant ir skelbiant sutartis, pridedant sumos lygius, pasirašant transakcijas, turėjau už viską sumokėti:

![image](https://github.com/user-attachments/assets/fdaace66-f8dc-43af-89a3-ea3a83c916f0)


Toliau prisijungus prie tinklapio, galime jungtis su įvairiais accountais, kurti savo projektus. Štai taip atrodo pagrindinis puslapis:

![image](https://github.com/user-attachments/assets/9421c93b-b46d-446b-af6e-cd5523e79602)

Čia viršuje dešinėje gali keisti accountą:

![image](https://github.com/user-attachments/assets/e4eede48-ff9f-4ac9-8d9c-076aaf8f3a21)

Štai ką mato "publisher", tai yra projektų savininkas, kuris gali readaguoti, pridėti naujus projektus, trinti:


![image](https://github.com/user-attachments/assets/66ba2c87-fdce-4f74-a8b8-76712b8a8fa0)


Paspaudęs Create Campaign gali pridėti naują projektą:

![image](https://github.com/user-attachments/assets/51a862cf-0cb7-4c05-a736-2b27721237b2)

Paspaudęs View Campaign, gali pašalinti, pakeisti, pridėti naujų lygių, redaguoti projektą:



Remėjai skyriuje Campaigns gali paspausti view camaigns ir pagal siūlomus lygius ir pasirinktą projektą, gali jį paremti:






# Etherscan

Kadangi depolyinau ir publishinau sutartis ir projektus su thirdweb pagalba, o kaip testinį tinklą naudojau Sepolia, chrome iškart galėjau pereiti į puslapį su transaction logs.
Po kiekvienos transakcijos galėjau peržiūrėti logus čia : https://sepolia.etherscan.io/tx/0xc0d599b76de24523d2c14ab810aa16dee9c23e7811793a226506a2510c45ccb1




