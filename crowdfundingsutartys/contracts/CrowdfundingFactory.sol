// SPDX-License-Identifier: MIT
// besties power best team ever existed
pragma solidity ^0.8.0;

import {Crowdfunding} from "./Crowdfunding.sol";

contract CrowdfundingFactory {
    address public savininkas;
    bool public paused;

    struct Campaign {
        address campaignAddress;
        address savininkas;
        string pavadinimas;
        uint256 sukurimoLaikas;

    }

    Campaign[] public campaigns;
    mapping(address => Campaign[]) public userCampaigns;

    modifier TikSavininkas() {
        require(msg.sender == savininkas, "Ne savininkas");
        _;
    }

    modifier nePaused() {
        require(!paused, "Fondas sustabdytas");
        _;
    }

    constructor() {
        savininkas = msg.sender;
    }

    function sukurtiCampaign(
        string memory _pavadinimas,
        string memory _aprasymas,
        uint256 _tikslas,
        uint256 _laikasDienomis

     ) external nePaused {
        Crowdfunding naujaCampaign = new Crowdfunding(
            msg.sender,
            _pavadinimas,
            _aprasymas,
            _tikslas,
            _laikasDienomis
        );
        address campaignAddress = address(naujaCampaign);
        Campaign memory campaign = Campaign({
            campaignAddress: campaignAddress,
            savininkas: msg.sender,
            pavadinimas: _pavadinimas,
            sukurimoLaikas: block.timestamp
        });
        campaigns.push(campaign);
        userCampaigns[msg.sender].push(campaign);
    }

    function fondaiPagalAdresa(address _user) external view returns (Campaign[] memory) {
        return userCampaigns[_user];
    }

    function visiFondai() external view returns (Campaign[] memory) {
        return campaigns;
    }

    function togglePause() public TikSavininkas {
        paused = !paused;
    }

}