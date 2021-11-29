//----------------------------------------------------------------------------------------------------
// Name: turnOffDriveMotors
//----------------------------------------------------------------------------------------------------
// Description:
//	   Turns off drve motors
//----------------------------------------------------------------------------------------------------
//Inputs:
//                None
//----------------------------------------------------------------------------------------------------
void turnOffDriveMotors()
{

	setMotorSpeed(leftDrive, 0);
	setMotorSpeed(rightDrive, 0);

}

//----------------------------------------------------------------------------------------------------
// Name: getLeftMotorEncoder
//----------------------------------------------------------------------------------------------------
// Description:
//	Return the left motor encoder.   Because the encoder is backwards, we use this function to
//	return the ngative.
//----------------------------------------------------------------------------------------------------
//Inputs:         None
//
//----------------------------------------------------------------------------------------------------
float getLeftMotorEncoder()
{

	return -nMotorEncoder[leftDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
// Name: getRightMotorEncoder
//----------------------------------------------------------------------------------------------------
// Description:  reads the number off of the right motor encoder
//
//----------------------------------------------------------------------------------------------------
//Inputs:       None
//
//----------------------------------------------------------------------------------------------------
float getRightMotorEncoder()
{

	return -nMotorEncoder[rightDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
// Name: setDriveMotorsToBrake
//----------------------------------------------------------------------------------------------------
// Description: Makes motors brake
//
//----------------------------------------------------------------------------------------------------
//Inputs:   None
//
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToBrake()
{

	setMotorBrakeMode(leftDrive,motorBrake);
	setMotorBrakeMode(rightDrive,motorBrake);

}

//----------------------------------------------------------------------------------------------------
// Name: setDriveMotorsToBrake
//----------------------------------------------------------------------------------------------------
// Description:        sets all the drive motors to brake
//
//----------------------------------------------------------------------------------------------------
//Inputs:          None
//
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToCoast()
{

	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);

}

//----------------------------------------------------------------------------------------------------
// Name: setAllMotorsToCoast
//----------------------------------------------------------------------------------------------------
// Description: sets all of the motors to coast
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//              None
//----------------------------------------------------------------------------------------------------
void setAllMotorsToCoast()
{
	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);
	setMotorBrakeMode(leftAttachment,motorCoast);
	setMotorBrakeMode(rightAttachment,motorCoast);
}


//----------------------------------------------------------------------------------------------------
// Name: resetDriveMotorEncoders
//----------------------------------------------------------------------------------------------------
// Description:       resets all of the drive motor encoders to 0
//
//----------------------------------------------------------------------------------------------------
//Inputs:        None
//
//----------------------------------------------------------------------------------------------------
void resetDriveMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
}


//----------------------------------------------------------------------------------------------------
// Name: resetAllMotorEncoders
//----------------------------------------------------------------------------------------------------
// Description:     all motor encoders reset to 0
//
//----------------------------------------------------------------------------------------------------
//Inputs:               None
//
//----------------------------------------------------------------------------------------------------
void resetAllMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftAttachment] = 0;
	nMotorEncoder[rightAttachment] = 0;
}


//----------------------------------------------------------------------------------------------------
// Name: setBrakeMode
//----------------------------------------------------------------------------------------------------
// Description: sets the brake mode to coast or brake
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//        brakeMode 	bool 	coast or brake
//----------------------------------------------------------------------------------------------------
void setBrakeMode(bool brakeMode)
{

	if (brakeMode)
	{
		// Set the brakes on the drive motors
		setMotorBrakeMode(leftDrive, motorBrake);
		setMotorBrakeMode(rightDrive, motorBrake);
	}
	else
	{
		// Set the motors to coast
		setMotorBrakeMode(leftDrive,motorCoast);
		setMotorBrakeMode(rightDrive,motorCoast);
	}


}


//----------------------------------------------------------------------------------------------------
// Name: driveForTime
//----------------------------------------------------------------------------------------------------
// Description: Drives for a certain period of time
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//	leftSpeed 		Float 	speed of the left motor
//      rightSpeed		Float 	speed of the right motor
//      seconds         	Float   seconds
//----------------------------------------------------------------------------------------------------
void driveForTime(float leftSpeed, float rightSpeed, float seconds)
{


	// set the motor speed
	setMotorSpeed(leftDrive, leftSpeed);
	setMotorSpeed(rightDrive, rightSpeed);


	// wait for a period of time

	sleep (seconds * 1000);


	// stop the motors
	setMotorSpeed(leftDrive, 0);
	setMotorSpeed(rightDrive, 0);



}






//----------------------------------------------------------------------------------------------------
// Name: cleanWheels
//----------------------------------------------------------------------------------------------------
// Description: Motors go 100% for 10 seconds
//
//----------------------------------------------------------------------------------------------------
//Inputs: None
//
//----------------------------------------------------------------------------------------------------
void cleanWheels()
{


	driveForTime (100,100,10);





}


void moveLeftAttachmentMotorDegrees (float speed, float degreesToMove, bool brakeMode)
{

  // if degrees is negative, set the speed to negative and make the degree a positive value.
  if (degreesToMove < 0)
	{
		speed  = -speed;
		degreesToMove = -degreesToMove;
	}

 	// Reset the motor encoder
 	resetMotorEncoder(leftAttachment);

  // Start the motor
	setMotorSpeed(leftAttachment, speed);

	// read the motor encoder
	while (abs(getMotorEncoder(leftAttachment)) < degreesToMove )
  {

  }

  // Stop the motor
	setMotorSpeed(leftAttachment, 0);


	// if the brake needs to applied, set the brake
	if (brakeMode)
	{
		// Set the brakes on the drive motors
		setMotorBrakeMode(leftAttachment, motorBrake);
	}
	else
	{
		// Set the motors to coast
		setMotorBrakeMode(leftAttachment,motorCoast);
	}



}


void moveRightAttachmentMotorDegrees (float speed, float degreesToMove, bool brakeMode)
{

  // if degrees is negative, set the speed to negative and make the degree a positive value.
  if (degreesToMove < 0)
	{
		speed  = -speed;
		degreesToMove = -degreesToMove;
	}

 	// Reset the motor encoder
 	resetMotorEncoder(rightAttachment);

  // Start the motor
	setMotorSpeed(rightAttachment, speed);

	// read the motor encoder
	while (abs(getMotorEncoder(rightAttachment)) < degreesToMove )
  {

  }

  // Stop the motor
	setMotorSpeed(rightAttachment, 0);


	// if the brake needs to applied, set the brake
	if (brakeMode)
	{
		// Set the brakes on the drive motors
		setMotorBrakeMode(rightAttachment, motorBrake);
	}
	else
	{
		// Set the motors to coast
		setMotorBrakeMode(rightAttachment,motorCoast);
	}



}
