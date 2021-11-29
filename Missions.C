
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

	sleep(500);

	// Reset the gyroscoe and wait 100ms to settle
	resetGyro(gyro);

	sleep(200);

	// Drive straight using the gyro to get on top of the line to follow
	// driveStraightGyroDistance(30, 27.5, -2, true);
	driveStraightEncoderDistance(30, 26.5, true);

	// Turn using the gyro to get close and not get stuck on the yellow line
	sideTurnUsingGyro(10, 20, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, white, true);

	// Turn to the right until we see black.
	sideTurnUntilLine(10, rightSensor, black, true);

	// Turn to the right until we see white.
	sideTurnUntilLine(10, rightSensor, grey, true);


	lineFollowUntilLine(10,rightSensor,rightEdge,white,true);

	lineFollowUntilLine(10,rightSensor,rightEdge,black,true);

	moveRightAttachmentMotorDegrees(100,600,false);

	sleep(500);

	moveRightAttachmentMotorDegrees(100,-600,false);

	driveStraightEncoderDistance(15, 6.7, true);

	moveLeftAttachmentMotorDegrees(50,-280,false);

	centerTurnUsingGyro(10, 45, true);

	moveLeftAttachmentMotorDegrees(10,200,false);

	driveForTime(-30,-30,1.2);

	centerTurnUsingGyro(20, 120, true);

	driveForTime(75,75,1.5);

	setBrakeMode(false);

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
