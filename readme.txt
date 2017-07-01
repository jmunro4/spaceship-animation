CPS 370
Professor Weaver
4/21/16

Group Members: Jonathan Munro, Andrew Boak, Edward Sepulveda

Instructions to run the program:
	Type in ‘make’ or ‘make main’ in order to compile the code.
	To run the program, type in ‘./main’ and click the left mouse button on the viewport to play/pause.

	Our movie follows a spaceship as it travels through an asteroid field. The clip can be run/paused by a mouse click by the user. The spaceship was plotted manually and drawn using glQuads. Our spaceship has a predetermined movement pattern that mimics evasive flight in order to avoid collision. Our spaceship also fires lasers consistantly to try and destroy the asteroid in its flight path.
	Every asteroid besides the one in the center of the screen has a random placement on the screen as it approaches the spaceship. The middle asteroid explodes into 3 smaller asteroid as if destroyed by the lasers, sending each particle in a randomly generated direction. Each asteroid also has an unique speed. 
	The asteroids, background, cockpit, and spaceship are all texture mapped differently, with each texture file provided. We used subdivided icosahedron in order to generate the shape of the asteroid. We also incorporated lighting onto the lasers in order to produce a more realistic feel to the scene. Each light is spawned every time a laser is, 1 unit above it's starting position, and they move together whilst firing.

The work was split between the three of us throughout the development of the project as follows:
	Jon worked on the creation of the spaceship and its movement, and texture mapping for the background.
	Debugging/testing	
	Random movement generation
	Asteroids and explosion particles

	Edward worked on texture mapping of the asteroids,  cockpit and spaceship.
	Debugging/testing
	Random movement generation
	Asteroids and explosion particles
	readme draft

	Andrew worked on the laser firing, lighting and trajectory.	
	Debugging/testing	
	Random movement generation
	Asteroids and explosion particles
