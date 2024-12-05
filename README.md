# Blockchain


Truffle IDE
node.js npm nvm

powershell

# installs fnm (Fast Node Manager)
winget install Schniz.fnm

# configure fnm environment
fnm env --use-on-cd | Out-String | Invoke-Expression

# download and install Node.js
fnm use --install-if-missing 22

# verifies the right Node.js version is in the environment
node -v # should print `v22.11.0`

# verifies the right npm version is in the environment
npm -v # should print `10.9.0`

https://nodejs.org/en

node gyp
https://github.com/nodejs/node-gyp#installation




https://youtu.be/coQ5dg8wM2o?si=ndnboNGUSRcBmqp-

![image](https://github.com/user-attachments/assets/7755cb02-f599-4672-81c2-aa2b19b48a9a)

ar prie networko gerai prisijunge tikrinam, gaunam pirmo acc balansa: web3.eth.getAccounts().then(accounts => {
  if (accounts.length > 0) {
    let firstAccount = accounts[0]; // Retrieve the first account
    return web3.eth.getBalance(firstAccount);
  } else {
    console.log("No accounts found.");
  }
}).then(balance => {
  if (balance !== undefined) {
    console.log("Balance in Wei:", balance);
    console.log("Balance in Ether:", web3.utils.fromWei(balance, 'ether'));
  }
}).catch(err => {
  console.error("Error:", err);
});

![image](https://github.com/user-attachments/assets/948b943f-59be-408b-9596-445a0e3eeb0f)

![image](https://github.com/user-attachments/assets/77529b8c-752d-4eb2-9af6-072f3220fa15)


balance in Ether is converted using web3.utils.fromWei(balance, 'ether')




crowdfunding
truffle init
truffle compile
truffle migrate

![image](https://github.com/user-attachments/assets/1d98b8ed-f6aa-4ef6-a707-7b1aaa90eef0)
Ganache
![image](https://github.com/user-attachments/assets/430e4792-2ee7-4fcd-8fe1-ee19e1ec4bc9)


Transaction

![image](https://github.com/user-attachments/assets/c8864656-647d-4d09-a1f1-2eeea2c7689f)

await instance.createProject(web3.utils.toWei('10', 'ether'), Math.floor(Date.now() / 1000) + 600, { from: '0x161863748B225478609DC57a527845E1b75EDA2c' });
Create a project with a funding goal of 10 Ether.
Set a deadline 10 minutes from now.
![image](https://github.com/user-attachments/assets/0e0069ae-683b-49dd-ac1f-84f22bad90d3)

![image](https://github.com/user-attachments/assets/47a9ed77-d669-400f-bddb-74634052ceb6)

problema su deployed, undefined


modelis?
    platforma, kurioje projektų kūrėjai gali pateikti projektus, o vartotojai (rėmėjai) gali siųsti ETH projektų finansavimui. Jei projektas surenka pakankamai lėšų per nustatytą laiką, lėšos išmokamos kūrėjui. Jei ne – rėmėjams grąžinami jų įnašai.


    Projektų kūrėjas sukuria projektą su tokiomis savybėmis:
        Minimalus lėšų tikslas.
        Galutinis terminas (timestamp formatu).
    Vartotojai gali prisidėti prie projekto, siųsdami ETH.
    Kai pasibaigia projekto laikotarpis:
        Jei lėšų tikslas pasiektas, kūrėjas gali atsiimti ETH.
        Jei lėšų tikslas nepasiektas, vartotojai gali susigrąžinti savo įnašus.

Šis modelis atspindi sutelktinio finansavimo (angl. crowdfunding) platformos logiką, kuri realiame gyvenime naudojama finansuoti įvairių tipų projektus – nuo technologinių naujovių iki socialinių iniciatyvų ar meno projektų.
panasus sprendimai

    Kickstarter
        Veikimas:
        Kickstarter yra viena didžiausių pasaulyje sutelktinio finansavimo platformų. Projektų kūrėjai pateikia projektus, nustato finansavimo tikslą ir laikotarpį. Jei projektas surenka pakankamai lėšų, jos pervedamos kūrėjui. Jei ne, lėšos grąžinamos rėmėjams.
       
    Indiegogo
        Veikimas:
        Kita populiari platforma, kuri leidžia rinkti lėšas su dviem modeliais: "viskas arba nieko" (panašu į jūsų modelį) ir "flexible funding" (kai surinktos lėšos perduodamos, net jei tikslas nepasiektas).
       
    Gitcoin Grants
        Veikimas:
        Blockchain paremta platforma, kurioje projektai gali gauti finansavimą iš bendruomenės, naudojant kriptovaliutas.

Tradicinės platformos reikalauja pasitikėjimo trečiosiomis šalimis, kurios valdo lėšas (pvz., Kickstarter valdymas). Blockchain pagrįstas modelis pašalina šį tarpininką:

    Rėmėjai yra tikri, kad jų lėšos bus arba perduotos kūrėjui, arba grąžintos, priklausomai nuo sutarties sąlygų.
    Kūrėjas turi garantiją, kad lėšos bus automatiškai pervestos, kai pasieks tikslą.

Decentralizuotas valdymas
Naudojant Ethereum blockchain, platforma tampa decentralizuota. Nė viena institucija ar asmuo negali manipuliuoti lėšomis, o visi sandoriai yra viešai matomi Ethereum tinkle.

Automatizavimas ir efektyvumas
Išmanieji kontraktai automatizuoja visą procesą:

    Taisyklių vykdymas užprogramuotas, todėl nereikia trečiosios šalies įsikišimo.
    Tai sumažina administracinius kaštus.

    
  
