
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Bank {

    mapping(address => uint) public balances;

    // Deposit money
    function deposit() public payable {
        require(msg.value > 0, "Enter valid amount");

        balances[msg.sender] += msg.value;
    }

    // Withdraw money
    function withdraw(uint amount) public {
        uint amountInWei = amount * 1 ether;

        require(amount > 0, "Invalid amount");
        require(
            balances[msg.sender] >= amountInWei,
            "Insufficient balance"
        );

        balances[msg.sender] -= amountInWei;

        payable(msg.sender).transfer(amountInWei);
    }

    // Show balance
    function showBalance() public view returns (uint) {
        return balances[msg.sender];
    }
}




***Follow these steps to fix it
Step 1: Change Value to zero
1. Open Remix IDE.
2. Go to Deploy & Run Transactions.
3. Find the Value field.
4. Enter 0.
5. Select Wei.
Important: Value must be 0 during deployment.
Step 2: Deploy again
1. Click Compile.
2. Click Deploy.
3. Wait for deployment to complete.
4. You should see Bank under Deployed Contracts.
Step 3: Deposit money

Now change the Value field:
Field	Enter
Value	5
Unit	Ether

Click deposit → Transact.

Step 4: Show balance

Click showBalance → Call.

Expected output:
5000000000000000000


Step 5: Withdraw money

Enter 2 in the withdraw input and click Transact.

Click showBalance again.

Expected output:
3000000000000000000


Remember this difference
Operation	Value field
Deploy contract	0 Wei
Deposit 5 ETH	5 Ether
Withdraw 2 ETH	0 Ether
Show balance	0 Ether

Your problem is not with the Solidity code or gas limit. It is because Value was set to 1 Wei during deployment. Change it to zero and deploy again.
***