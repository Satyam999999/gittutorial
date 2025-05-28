<?php
require 'vendor/autoload.php'; // MongoDB Library

// Connect to MongoDB
$client = new MongoDB\Client("mongodb://localhost:27017");

// Select the 'university' database and 'students' collection
$db = $client->university;
$collection = $db->students;

echo "Connected to MongoDB. Database and collection will be created automatically if they don't exist.";
?>
