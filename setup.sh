#!/bin/bash

echo "------------------------------"
echo "Industrial IoT Setup Script"
echo "------------------------------"

# Step 1: Check Python
if ! command -v python3 &> /dev/null
then
    echo "Python3 is not installed. Please install Python 3 before running this script."
    exit
fi

# Step 2: Install Python dependencies
echo "Installing Python dependencies..."
pip install --upgrade pip
pip install pandas paho-mqtt scikit-learn joblib

# Step 3: Run Data Processing
echo "Starting data processing script..."
python3 analytics/data_processing.py &

# Step 4: Train Predictive Model
echo "Training predictive model..."
python3 analytics/predictive_model.py

# Step 5: Completion message
echo "------------------------------"
echo "Setup Complete!"
echo "You can now open dashboard/index.html in your browser"
echo "or run the live dashboard via Node.js if configured."
echo "------------------------------"
