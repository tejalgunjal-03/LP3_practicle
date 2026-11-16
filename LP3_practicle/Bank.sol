
 // SPDX-License-Identifier: MIT
pragma solidity ^0.8.34;

contract SimpleBank {

    address public owner;
    uint256 public balance;

    constructor() {
        owner = msg.sender;
        balance = 0;
    }

    // Deposit money
    function deposit(uint256 amount) public {
        require(msg.sender == owner, "Only owner can deposit");
        require(amount > 0, "Amount must be greater than zero");

        balance += amount;
    }

    // Withdraw money
    function withdraw(uint256 amount) public {
        require(msg.sender == owner, "Only owner can withdraw");
        require(amount > 0, "Amount must be greater than zero");
        require(amount <= balance, "Insufficient balance");

        balance -= amount;
    }

    // Show balance
    function getBalance() public view returns (uint256) {
        return balance;
    }
}
