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

