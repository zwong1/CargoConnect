
void setupGlobalVariables()
{

	// Setup parameters that may be different on different robots
	wheelDiameterInMM = 62.4;										// This is on the side of every lego wheel.
	widthBetweenWheelsInMM = 96.72; 						// Width between wheels in mm.  Each lift arm width is 7.44mm wide
	reflectedLightIntensityOnBlack = 12;				// Color sensor reading when reading black.
	reflectedLightIntensityOnWhite = 100; 			// Color Sensor reading when reading white.
	forwardMotorMovementIsPositive = false;  		// Do the encoders go posiitive when moving forward. (False = negative)

	// Setup the strings to pass in to the functions because we can't pass strings, but can pass variables.
	leftSensor = "leftSensor";
	rightSensor = "rightSensor";
	leftEdge = "leftEdge";
	rightEdge = "rightEdge";
	black = "black";
	white = "white";


}
