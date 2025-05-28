<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$db = $client->university;
$collection = $db->students;

// Sample student data
$students = [
    [
        "name" => "Amit Sharma",
        "roll_number" => "B23CS101",
        "email" => "amit@college.edu",
        "course" => "BTech CSE",
        "marks" => ["maths" => 85, "physics" => 78, "computer_science" => 92]
    ],
    [
        "name" => "Neha Verma",
        "roll_number" => "B23CS102",
        "email" => "neha@college.edu",
        "course" => "BTech ECE",
        "marks" => ["maths" => 79, "physics" => 82, "electronics" => 88]
    ],
    [
        "name" => "Rahul Singh",
        "roll_number" => "B23CS103",
        "email" => "rahul@college.edu",
        "course" => "BTech IT",
        "marks" => ["maths" => 90, "physics" => 76, "computer_science" => 89]
    ],
    [
        "name" => "Priya Mehta",
        "roll_number" => "B23CS104",
        "email" => "priya@college.edu",
        "course" => "BTech ME",
        "marks" => ["maths" => 75, "physics" => 80, "mechanics" => 85]
    ],
    [
        "name" => "Suresh Yadav",
        "roll_number" => "B23CS105",
        "email" => "suresh@college.edu",
        "course" => "BTech Civil",
        "marks" => ["maths" => 70, "physics" => 74, "surveying" => 80]
    ]
];

// Insert data only if collection is empty
if ($collection->countDocuments() === 0) {
    $collection->insertMany($students);
    echo "Student records inserted successfully.";
} else {
    echo "Student records already exist.";
}
?>
