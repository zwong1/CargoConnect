
// This mission does the stuff in the center of the board  (Truck drop off, slip roads down)
void centerMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	driveStraightGyroDistance(20, 2, 0, false);
	driveStraightGyroDistance(50, 10, 0, true);

	sideTurnUsingGyro(20, 45, false);



}


// This does the missions on the south wall.  (Door Deliver, Package Drop off)
void southWallMission()
{



}

// This does the missions on the east wall (Hellicopter, Cargo Ship)
void eastWallMission()
{



}

// This mission does the end mission
void endMission()
{


}





















//----------------------------------------------------------------------------------------------------
// Name:northWallMission
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------
void northWallMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	// Drive straight using the gyro to get on top of the line to follow
	driveStraightGyroDistance(30, 12, 0, true);



	// line follow for distance
	//lineFollowForDistance(30,15,  string colorSensorToUse, string edgeToUse, bool brakeMode


}

//----------------------------------------------------------------------------------------------------
// Name:blueBox
//----------------------------------------------------------------------------------------------------
// Description:
//----------------------------------------------------------------------------------------------------
//Inputs: None
//----------------------------------------------------------------------------------------------------

void blueBoxMission()
{

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);
	sleep(200);

	driveStraightGyroDistance(20, 2, 0, false);
	driveStraightGyroDistance(50, 18, 0, true);

	sideTurnUsingGyro(20, -90, false);


	driveStraightEncoderDistance(60,10,false);


}
