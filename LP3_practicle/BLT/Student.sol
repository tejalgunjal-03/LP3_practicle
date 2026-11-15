// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

// Student data management using structures, arrays, and fallback.
contract StudentManagement {
    // Structure to store one student's details.
    struct Student {
        uint256 id;
        string name;
        uint256 marks;
    }

    // Dynamic array of student records.
    Student[] public students;

    address public owner;

    constructor() {
        owner = msg.sender;
    }

    // Only the contract deployer can add or update student records.
    modifier onlyOwner() {
        require(msg.sender == owner, "Only owner can perform this action");
        _;
    }

    // Add a student record to the array.
    function addStudent(
        uint256 _id,
        string memory _name,
        uint256 _marks
    ) public onlyOwner {
        students.push(Student(_id, _name, _marks));
    }

    // Add bonus marks to a student using their array index.
    function bonusMarks(uint256 index, uint256 bonus) public onlyOwner {
        require(index < students.length, "Invalid student index");
        students[index].marks += bonus;
    }

    // Return student details using their array index.
    function getStudent(uint256 index)
        public
        view
        returns (uint256, string memory, uint256)
    {
        require(index < students.length, "Invalid student index");
        Student memory student = students[index];
        return (student.id, student.name, student.marks);
    }

    // Return the number of student records.
    function getStudentCount() public view returns (uint256) {
        return students.length;
    }

    // Called when Ether is sent with empty calldata.
    receive() external payable {}

    // Called when calldata does not match any function.
    fallback() external payable {}
}
