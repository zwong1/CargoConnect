//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------
void turnOffDriveMotors()
{

	setMotorSpeed(leftDrive, 0);
	setMotorSpeed(rightDrive, 0);

}

//----------------------------------------------------------------------------------------------------
// Return the left motor encoder.   Because the encoder is backwards, we use this function to return the ngative.
//----------------------------------------------------------------------------------------------------
float getLeftMotorEncoder()
{

	return -nMotorEncoder[leftDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------

float getRightMotorEncoder()
{

	return -nMotorEncoder[rightDrive]; 													// Get the value of the left motor encoder, make it negative and assign it to the encoderValue

}

//----------------------------------------------------------------------------------------------------
// Sets the motors to apply the brake to not move.
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToBrake()
{

	setMotorBrakeMode(leftDrive,motorBrake);
	setMotorBrakeMode(rightDrive,motorBrake);

}

//----------------------------------------------------------------------------------------------------
// Sets the drive motors to coast
//----------------------------------------------------------------------------------------------------
void setDriveMotorsToCoast()
{

	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);

}

//----------------------------------------------------------------------------------------------------
// Sets all of the the motors to coast
//----------------------------------------------------------------------------------------------------
void setAllMotorsToCoast()
{
	setMotorBrakeMode(leftDrive,motorCoast);
	setMotorBrakeMode(rightDrive,motorCoast);
	setMotorBrakeMode(leftAttachment,motorCoast);
	setMotorBrakeMode(rightAttachment,motorCoast);
}


//----------------------------------------------------------------------------------------------------
// Reset all of the motor encoders
//----------------------------------------------------------------------------------------------------
void resetDriveMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
}


//----------------------------------------------------------------------------------------------------
// Reset all of the motor encoders
//----------------------------------------------------------------------------------------------------
void resetAllMotorEncoders()
{
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftAttachment] = 0;
	nMotorEncoder[rightAttachment] = 0;
}


//----------------------------------------------------------------------------------------------------
//
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
