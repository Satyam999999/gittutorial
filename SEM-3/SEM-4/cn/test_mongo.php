<?php  
require 'vendor/autoload.php';  // Load Composer dependencies

try {
    // Connect to MongoDB
    $client = new MongoDB\Client("mongodb://localhost:27017");

    // Check if connection is successful
    echo "✅ Connected to MongoDB successfully!";
} catch (Exception $e) {
    echo "❌ Connection failed: " . $e->getMessage();
}
?>
