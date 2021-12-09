<img src="https://github.com/mayankofficial999/Contralert/blob/main/Device.jpg" width="900" height="900" /> 

# Contralert 
Contralert is a utility device which produces different sound tones for every issue created, pull request opened, and pull request closed using Github Actions.

## Setup and Installation
* Go to repo Settings/Secrets and add a new repository secret with name as MTQT_BROKER_PASSWORD and value as key.
* Now edit the .yaml files in .github/workflows with your details of mqqt broker for each topic i.e Issue Open , Pull Requet Open and Pull Request Closed.
   ```yaml
    protocol: mqtt
    host: hostname
    port: 1883
    topic: "mqtt-action/test"
    message: true
    username: 'your-username'
    password: ${{ secrets.MQTT_BROKER_PASSWORD }}
    ```
* Now connect a buzzer to NodeMCU gpio pin and enter the mqtt broker details in the .ino file.
* Upload the code to NodeMCU using Arduino IDE to the board and that's it.
* The device will connect to the MQTT Server and will generate a tone for respective Github Action.

## Usage
* Just power up your NodeMCU and connect the buzzer.
* Now you have your contralert device set up for notifications.

## Demo Video
[<img src="https://github.com/mayankofficial999/Contralert/blob/main/Device.jpg" width="400" height="400" />](https://youtu.be/MR4bHVhEVR0)

## Contributions

- Feel Free to Open a PR/Issue for any feature or bug(s).
- Make sure to follow the [community guidelines](https://docs.github.com/en/github/site-policy/github-community-guidelines) when contributing.
- Please open an issue if you want to ask a question/discuss anything about Contralert.
- Want to add an action? add a feature? Open an Issue!

## License
Licensed under [MIT License](https://opensource.org/licenses/MIT)
