import pandas as pd
from sklearn.ensemble import RandomForestClassifier
import joblib

# Load collected data
try:
    data = pd.read_csv("machine_data.csv", names=['vibration','temperature'])
except:
    print("No data available")
    exit()

# Simulated target: 0 = OK, 1 = failure
data['failure'] = 0  # Placeholder; in real scenario label historical failures

X = data[['vibration','temperature']]
y = data['failure']

model = RandomForestClassifier()
model.fit(X, y)
joblib.dump(model, "predictive_model.pkl")
print("Model trained and saved as predictive_model.pkl")
