<?php
require 'vendor/autoload.php';

$client = new MongoDB\Client("mongodb://localhost:27017");
$db = $client->university;
$collection = $db->students;

// Aggregation pipeline to calculate average marks
$pipeline = [
    ['$group' => [
        '_id' => null,
        'averageMarks' => ['$avg' => '$marks']
    ]]
];

$result = $collection->aggregate($pipeline)->toArray();
$averageMarks = $result[0]['averageMarks'] ?? 0;

echo "<b>The average marks of students: </b>" . round($averageMarks, 2);
?>
