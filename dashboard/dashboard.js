const mqtt = require('mqtt');
const client = mqtt.connect('wss://broker.hivemq.com:8000/mqtt');

client.on('connect', function () {
  client.subscribe('factory/machine1', function (err) {
    if (!err) console.log("Subscribed to MQTT topic");
  });
});

client.on('message', function (topic, message) {
  const data = JSON.parse(message.toString());
  document.getElementById('vibration').innerText = data.vibration;
  document.getElementById('temperature').innerText = data.temperature + '°C';
});
