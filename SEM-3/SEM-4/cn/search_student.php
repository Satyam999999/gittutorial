<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$db = $client->university;
$collection = $db->students;

if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST["roll_number"])) {
    $roll_number = $_POST["roll_number"];
    $student = $collection->findOne(["roll_number" => $roll_number]);

    if ($student) {
        echo "<h2>Student Details</h2>";
        echo "Name: " . $student["name"] . "<br>";
        echo "Email: " . $student["email"] . "<br>";
        echo "Marks: <br><ul>";
        foreach ($student["marks"] as $subject => $score) {
            echo "<li>$subject: $score</li>";
        }
        echo "</ul>";
    } else {
        echo "No student found with Roll Number: $roll_number";
    }
}
?>
