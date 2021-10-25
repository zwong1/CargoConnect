//----------------------------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------------------------------
// Description:
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//
//----------------------------------------------------------------------------------------------------
void driveStraightGyroDistance(float direction, float speed, float inches, bool brakeMode)
{

	// Dimensioning variables
	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;
	float degreesToMove;
	float gain;
	float rotations;


	rotations = inches / 7.717922162;

	// Increase the gain if the speed is greater
	gain = .01 * speed;

	degreesToMove = rotations * 360;

	// Remove the brakes if they are applied
	setDriveMotorsToCoast();

	// Reset the Motor Encoders
	resetDriveMotorEncoders();


	while (abs(getLeftMotorEncoder()) <= degreesToMove)
	{

		// Setpoint that we want to go in - actual current reading
		error = direction - getGyroDegrees(gyro);

		// Compute the correction factor
		correctionFactor = error * gain;

		speedLeft = speed + correctionFactor;
		speedRight = speed - correctionFactor;

		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);
	}


	turnOffDriveMotors();


	setBrakeMode(brakeMode);

}


//----------------------------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------------------------------
// Description:
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//
//----------------------------------------------------------------------------------------------------
void centerTurnUsingGyro(float degreesToTurn, float speedOfTurn, bool brakeMode)
{

	float gyroStartReading;							// The start value of the gyro
	float gyroEndReading;							// The value we want to end the while statement


	// Get the starting gyroscope reading
	gyroStartReading = getGyroDegrees(gyro);

	// Compute the end reading
	gyroEndReading = gyroStartReading + degreesToTurn - 10;


	if (degreesToTurn > 0)												// Turning to the right
	{

		setMotorSpeed(leftDrive, speedOfTurn);
		setMotorSpeed(rightDrive, -speedOfTurn);

		while (getGyroDegrees(gyro) < gyroEndReading)
		{

		}


		turnOffDriveMotors();


		setBrakeMode(brakeMode);


	}
	else																				// Turning to the left
	{

		setMotorSpeed(leftDrive, -speedOfTurn);
		setMotorSpeed(rightDrive, speedOfTurn);

		while (getGyroDegrees(gyro) > gyroEndReading)
		{

		}


		turnOffDriveMotors();


		setBrakeMode(brakeMode);



	}



}


//----------------------------------------------------------------------------------------------------
// Name:
//----------------------------------------------------------------------------------------------------
// Description:
//
//----------------------------------------------------------------------------------------------------
//Inputs:
//
//----------------------------------------------------------------------------------------------------
void sideTurnUsingGyro(float degreesToTurn, float speedOfTurn, bool brakeMode)
{

	float gyroStartReading;							// The start value of the gyro
	float gyroEndReading;							// The value we want to end the while statement


	// Get the starting gyroscope reading
	gyroStartReading = getGyroDegrees(gyro);

	// Compute the end reading
	gyroEndReading = gyroStartReading + degreesToTurn - 10;


	if (degreesToTurn >= 0)												// Turning to the right
	{

		setMotorSpeed(leftDrive, speedOfTurn);
		setMotorSpeed(rightDrive, 0);

		while (getGyroDegrees(gyro) < gyroEndReading)
		{

		}


	turnOffDriveMotors();


	setBrakeMode(brakeMode);


	}
	else																// Turning to the left
	{

		setMotorSpeed(leftDrive, 0);
		setMotorSpeed(rightDrive, speedOfTurn);

		while (getGyroDegrees(gyro) > gyroEndReading)
		{


		}


	}


	turnOffDriveMotors();


	setBrakeMode(brakeMode);



}
