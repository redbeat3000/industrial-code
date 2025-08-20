import pandas as pd
import paho.mqtt.client as mqtt
import json

# MQTT callback
def on_message(client, userdata, msg):
    data = json.loads(msg.payload)
    df = pd.DataFrame([data])
    df.to_csv("machine_data.csv", mode='a', header=False, index=False)
    print("Data saved:", data)

client = mqtt.Client()
client.on_message = on_message
client.connect("broker.hivemq.com", 1883, 60)
client.subscribe("factory/machine1")
client.loop_forever()
