# Hacking a cheap electric kettle to control its temperature

## TODO

- Upload pictures
- Try to find correlation between sensors
- Redo experiment while putting sensor lower in the handle.

## Inspiration

[Kettle_wifi](https://github.com/OpHaCo/Kettle_wifi) ([Same project](https://www.hackster.io/lahorde/from-a-14-kettle-to-an-ikettle-d2b3f7?f=1))
- Thermometer is in the handle of the kettle (I don't quite understand how it is wired to the microcontroller (maybe via the copper plates ?))
- Use a relay to cut the current

[ATtiny85 Kettle Thermostat](https://hackaday.io/project/136-attiny85-kettle-thermostat)
- Use a piezo and a display
- Use a waterproof thermometer to put in the water

## Goal

The goal of this project is to be able to have 80°C water rather than boiling water using a a simple electric kettle (that has no other feature that boiling water). And to a larger extent to control the target temperature of the kettle.

"Control" ranges from "emit a sound when target T° is reached" to "stop the kettle when target T° is reached".

Projects involving kettle usually use kettle with controllable target temperature and add a Wi-Fi interface to interact with it. I found two project that do what I want, they also have the goal of having a Wi-Fi interface, which I don't.

## Uncertainties

- Noob in hacking things
- Components precision
- Making the circuit waterproof

## Journal

### 15/02/2021
- Idea pops up.
- Looking for info on the internet.
	- https://www.explainthatstuff.com/how-electric-kettles-work.html
- Take apart my kettle.
	- I spend a while figuring out how to remove the 2 [spanner screws](https://fr.ifixit.com/News/9907/bit-history-the-spanner). Used a toothbrush thanks to [WikiHow](https://www.wikihow.com/Unscrew-a-Screw-Without-a-Screwdriver). I melted the toothbrush too much. It took a while to file down the excess platic to make it fit in tiny space.
- Tried to use arduino with a thermometer. With the cable I have available I can't go further than the breadboard.


### 17/02/2021
- Order jump cables, waterproof DS18B20, and regular DS18B20 thermometer on aliexpress.
- Main questions are
	- Where to put the thermometer?
		- The thermometer can be on the base so it can easily be wired to the microcontroller, but it will be far away from the water, how will that impact the T° values.
		- It can be in the water or in the kettle. Then how to connect it to the microcontroller ?
	- What can be done to alert the user when target T° is reached?
		- Make a sound using a piezo at one (or many) fixed threshold.
		- Add a display to show the T°.
		- Stop the kettle using a relay.

For me, overrall, the main issue is getting a T° that is the closest to the real T°, and so, where to put the thermometer. If T° is not precise enough the project I won't continue this project.


### 10/03/2021
- Received everything from AliExpress
- Today's goal is to see the difference between the measured T° and the "real" T°.
- I put DS18B20 under the base, inside the handle and in the water. Also a long cooking thermometer in the water. Every second I print the temperature of every thermometer, and there's a button that I press every 10°C on the cooking thermometer.
- I do 2 experiments, one while boiling 50cl and one with 1L. To see how the mass of water affects the T°.
- For both experiment the thermometer in the handle wasn't under the water level (it could have been lower in the handle). The last plot in the notebook seem to confirm that this is important because with more water this thermometer has a higher value.
- The thermometer under the base isn't useful.

- I need to see whether there is a correlation between any thermometer and the "real" T°. For every point is there a coefficient to go from thermometer to "real" T° ?

- The maximum value should be stable accross different water volumes.

- Where is the thermometer located in fancy kettles ?