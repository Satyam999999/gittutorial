<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$db = $client->university;
$collection = $db->students;

// Check if the index exists
$indexes = $collection->listIndexes();
$indexExists = false;

foreach ($indexes as $index) {
    if ($index->getKey() == ["roll_number" => 1]) {
        $indexExists = true;
        break;
    }
}

if (!$indexExists) {
    $collection->createIndex(["roll_number" => 1]);
    echo "Index created on 'roll_number'.";
} else {
    echo "Index already exists on 'roll_number'.";
}
?>
