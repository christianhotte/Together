# Together

## Where are the audio files?

Audio files are too large for git, so I’ve excluded them in .gitignore. Please download the media folder from [here](https://drive.google.com/file/d/1troc1jdZltuBdz8Lko4ik4d4s5EObzPD/view?usp=share_link), and place the unzipped folder in Together_Max.

## Why is `serial` not working in Max?

1. Check to see if the Max patch is the only program receiving serial communication on your computer. Do not open the Serial Monitor or Plotter in the Arduino IDE before or during you open the Max patch.
2. Check to see if it’s listening to the right port. You can change the serial port by clicking on the `serport` dropdown menu above the `serial` object.

##  When is the hold state triggered?

If the sensor is HIGH for 2.5 seconds, the corresponding tuning sound starts playing.

## When is the main state triggered?

When all three stations are in the hold state for more than 30 seconds, the main tracks start playing.

## Which sensor corresponds to which instrument?

Sensor 0 corresponds to cello, sensor 1 corresponds to guitar, sensor 2 corresponds to piano.
