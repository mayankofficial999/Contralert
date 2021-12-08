# Contralert 
Contralert is an amazing IoT device which produces different sound tones for each issue created , pull request opened and oull request closed using Github Actions.

## How to use
* Fork the repo
* Go to repo Settings/Secrets and add a new repository secret with name as MTQT_BROKER_PASSWORD and value as key.
* Now edit the .yaml files in .github/workflows with your details of mqqt broker for each topic i.e Issue Open , Pull Requet Open and Pull Request Closed.
   ```yaml
    protocol: mqtt
    host: broker.example.com
    port: 1883
    topic: "mqtt-action/test"
    message: ${{ github.sha }}
    username: 'mqtt'
    password: ${{ secrets.MQTT_BROKER_PASSWORD }}
    ```
* Now connect a buzzer to nodemcu gpio pin and enter the mqtt broker details in the .ino file.
* Upload the code to NodeMCU using Arduino IDE to the board and that's it.
* The device will connect to the MQTT Server and will generate a tone for respective Github Action.

## Contributions

- Feel Free to Open a PR/Issue for any feature or bug(s).
- Make sure to follow the [community guidelines](https://docs.github.com/en/github/site-policy/github-community-guidelines) when contributing.
- Please open an issue if you want to ask a question/discuss anything about Contralert.
- Want to add an action? add a feature? Open an Issue!

## License
Licensed under [MIT License](https://opensource.org/licenses/MIT)
