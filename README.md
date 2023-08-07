# Temperature-based laptop cooling pad

# warning- the main script is still being improved and will be uploaded when finished

## Inspiration
- My laptop always overheats and thermal throttles on sustained loads (such as long code compiling, AI training) which degrades performance. I had the cooler from an old dead GPU lying around.
- I initially hooked the cooler up to 12-volt power and taped it to the bottom of the laptop but having it run all the time was not ideal, especially due to noise concerns
- Due to this, I developed this system to use an arduino and relay to control the fan, with a script on the computer checking if the moving average CPU temperature over the past minute is over a threshold to turn it on, and sending serial data

## How it works
- The C++ script runs the sensors command, and takes the output. It takes the temperature of the CPU, and calculates a moving average over the past minute. If the fan is off, and the moving average is above a threshold, it turns them on. If the fans are on, and the temperature average is 5 degrees or more lower than the threshold, it turns them off.
- The way it controls the fans is by sending serial data into the arduino. The arduino then triggers a relay (since it can only output 5v while the fan takes 12 v)

## how to use
- build a circuit as shown in the schematic, place the fan near the laptop so that it points into the air vents like in the picture, flash the program to the Arduino, and compile and run main.cpp. Select the correct serial port, and the program automatically sees the temperature and sends a serial signal to Arduino.
- you can have the program set to run on start up if you want
- To turn the fans on even when the laptop isn't running hot, you can use the override button. Change the arduino code in the commented location if you use a toggle switch instead of a button.  

## notes
- because of the turbo boosting of new 12-th gen chips, pulling 157w for boost and sustaining 55w, the temperature rises quickly on momentary loads. Literally pressing the Windows key a few times in rapid succession almost thermal-throttles the laptop (yes, in a high-performance mobile workstation. blame Intel and Dell), but it goes back down quickly
- When it is like this, the fan will keep turning on and off. This is why a 1-minute moving average is used.

