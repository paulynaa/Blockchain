// SPDX-License-Identifier: MIT
// Besties <3
pragma solidity ^0.8.0;

contract Crowdfunding {
    string public pavadinimas;
    string public aprasymas;
    uint256 public tikslas;
    uint256 public deadlainas;
    address public savininkas;
    bool public paused;


    enum CampaignState{Vyksta, Pavyko, Nepavyko}
    CampaignState public state;
    struct Tier {
        string pavadinimas;
        uint256 suma;
        uint256 finansuotojai;

    }

    struct remejas{
        uint256 pafinansavo;
        mapping(uint256 => bool) paremtiTiers;
    }

    Tier[] public tiers;

    mapping(address => remejas) public finansuotojai;

    modifier TikSavininkas(){
        require(msg.sender == savininkas, "Jus ne savininkas");
        _;
    }

    modifier CampaignOpen(){
        require(state == CampaignState.Vyksta, "Fondas nevyksta");
        _;
    }

    modifier nepaused(){
        require(!paused, "Sutartis sustabdyta.");
        _;
    }

    constructor (
        address _savininkas,
        string memory _pavadinimas,
        string memory _aprasymas,
        uint256 _tikslas,
        uint256 _laikasDienomis
        
    ){
        pavadinimas = _pavadinimas;
        aprasymas = _aprasymas;
        tikslas =_tikslas;
        deadlainas = block.timestamp + (_laikasDienomis * 1 days );
        savininkas = _savininkas;
        state = CampaignState.Vyksta;
    }

    function PatikrintiIrAtnaujintiFondoVeikima() internal {
        if(state == CampaignState.Vyksta){
            if(block.timestamp >= deadlainas){
                state = address(this).balance >= tikslas ? CampaignState.Pavyko : CampaignState.Nepavyko;
            } else {
                state = address(this).balance >= tikslas ? CampaignState.Pavyko : CampaignState.Vyksta ;
            }
        }
    }

    function finansuoti(uint256 _tierIndex) public payable CampaignOpen nepaused {
        require(_tierIndex < tiers.length,"nera tokio tiero" );
        require(msg.value == tiers[_tierIndex].suma,"Bloga mokejimo suma");

        tiers[_tierIndex].finansuotojai++;
        finansuotojai[msg.sender].pafinansavo += msg.value;
        finansuotojai[msg.sender].paremtiTiers[_tierIndex] = true;

        PatikrintiIrAtnaujintiFondoVeikima();
    }

    function pridetiTiera(
        string memory _pavadinimas,
        uint256 _suma
    ) public TikSavininkas{
        require(_suma > 0,"Suma turi buti didesne nei 0");
        tiers.push(Tier(_pavadinimas,_suma,0));
    }

    function istrintiTiera(uint256 _index) public TikSavininkas{
        require(_index < tiers.length,"Tieras neegzistuoja");
        tiers[_index] = tiers[tiers.length -1];
        tiers.pop();
    }

    function issiimtipinigus() public TikSavininkas {
        PatikrintiIrAtnaujintiFondoVeikima();
        require(state == CampaignState.Pavyko,"Fondas dar nepasibaige");

        uint256 balance = address(this).balance;
        require(balance > 0, "balansas lygus 0");

        payable(savininkas).transfer(balance);

    }

    function Balansas() public view returns (uint256){
        return address(this).balance;
    }

    function refund() public {
        PatikrintiIrAtnaujintiFondoVeikima();
        require(state == CampaignState.Nepavyko, "Grazinimai negalimi");
        uint256 kiek = finansuotojai[msg.sender].pafinansavo;
        require(kiek > 0, "Nepafinansavo nieko, kad butu grazinimas");
        finansuotojai[msg.sender].pafinansavo = 0;
        payable(msg.sender).transfer(kiek);
    }
    
    function pafinansavoTier(address _remejas, uint256 _tierIndex) public view returns(bool) {
            return finansuotojai[_remejas].paremtiTiers[_tierIndex];
    }

    function getTiers() public view returns (Tier[] memory) {
        return tiers;
    }

    function togglePause() public TikSavininkas {
        paused = !paused;
    }

    function getCampaignStatus() public view returns (CampaignState) {
        if (state == CampaignState.Vyksta && block.timestamp > deadlainas) {
            return address(this).balance >= tikslas ? CampaignState.Pavyko : CampaignState.Nepavyko;
        }
        return state;
    }

    function pailgintideadlaina(uint256 _pridetidienu)    public TikSavininkas CampaignOpen {
        deadlainas += _pridetidienu * 1 days;        
    }


}