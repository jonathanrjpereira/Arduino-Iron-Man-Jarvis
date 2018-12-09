![Banner](https://github.com/jonathanrjpereira/Arduino-Iron-Man-Jarvis/blob/master/img/Banner-01.svg)

Jarvis is an A.I. who can respond according to the users thoughts and emotions, such as problems in Tony Stark's life that he tries to deal and help him with. Jarvis is Tony's personal and closest friend as well as his assistant in helping him in his work or when he does his super-hero job.

## Features

 - Jarvis Voice & Responses
 - Iron Man Suit Sound & Light Effects

## Prerequisites
**Hardware:**
1. [Arduino Nano](https://amzn.to/2SuBJSh)
2. [SD Card Reader Module](https://amzn.to/2L1Iqso)
3. [LM386 Audio Amplifier Module](https://amzn.to/2rnPiaL)

**Software Dependencies:**
1. Arduino library for asynchronous playback of PCM/WAV files direct from SD card. [TMRpcm](https://github.com/TMRh20/TMRpcm)
2. Arduino SD Card Library. [SD Library](https://www.arduino.cc/en/Reference/SD) 

## Working
**Audio Files:**

Start by converting all your audio files including voice commands & sound effects into 8-bit,Mono WAV Files. I recommend using [Audacity](https://www.audacityteam.org/) for this purpose. It's free & easy to use.

Store the coverted files on the SD card.

**Connect the Electronics:**

|Arduino|SD Card Module|
|--|--|
|4|CS|
|11|MOSI|
|12|MISO|
|13|SCK|

|Arduino|LM386 Module|
|--|--|
|9|Input|

The output of the Audio Module should be connected to a speaker. Adjust the module's potentiometer to change the Gain of the amplifier. This will may have varying results and may increase distortion.

Remember to connect the appropriate supply to both modules & don't forget to connect the GND pins of both modules to the Arduino.

**Reading & Playing the Audio Files:**

`tmrpcm.quality`sets the sampling rate. A default value of 1 results in a 2x Sampling rate.

`tmrpcm.setVolume` sets the Volume. Choose a value between 0-7.

`tmrpcm.play` will read the WAV file from the SD Card. It will then convert it into an analog signal which is inputed to the amplifier module. The system will play the WAV file for the desired duration depending upon the `delay()` value.

## Contributing

Are you a programmer, engineer or hobbyist who has a great idea for a new feature in this project? Maybe you have a good idea for a bug fix? Feel free to grab our code & schematics from Github and tinker with it. Don't forget to smash those ⭐️ & Pull Request buttons. [Contributor List](https://github.com/jonathanrjpereira/Arduino-Iron-Man-Jarvis/graphs/contributors)

Made with ❤️ by [Jonathan Pereira](https://github.com/jonathanrjpereira)
