//----------------------------------------------------------------------------------------------------
// Name: driveStraightGyroDistance
//----------------------------------------------------------------------------------------------------
// Description: we increase the gain if the speed is greater. Then we remove the breaks and reset motor
// encoders. We get the setpount the we wand to go in - the actual current reading. We then compute the
// correctionFactor (speedleft = speed + correctionFactor      speedRight = speed - correction factor)
// we then turn off drive motors and set the brake Mode
//----------------------------------------------------------------------------------------------------
//Inputs:   speed    		Float       	speed we want to go at
//          inchesToMove    Float           inches we want to movedata
//          brakeMode       Bool            coast or brake
//----------------------------------------------------------------------------------------------------
void driveStraightGyroDistance(float speed, float inchesToMove, float direction, bool brakeMode)
{

	// Dimensioning variables
	float error;
	float correctionFactor;
	float speedLeft;
	float speedRight;
	float degreesToMove;
	float gain;
	float rotations;


	rotations = inchesToMove / 7.717922162;

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

		speedLeft = speed - correctionFactor;
		speedRight = speed + correctionFactor;

		setMotorSpeed(leftDrive, speedLeft);
		setMotorSpeed(rightDrive, speedRight);
	}


	// Stop Motors
	turnOffDriveMotors();

	// Apply brakes if selected
	setBrakeMode(brakeMode);

}


//----------------------------------------------------------------------------------------------------
// Name: centerTurnUsingGyro
//----------------------------------------------------------------------------------------------------
// Description: we read the start value of the gyro, and we compute the end reading(the number we want
// the gyro to be reading at the end). If the degreesToTurn is great then 0 we are turning to the right.
// If the degreesToTurn is less then 0, we are turning to the left. Once it gets to that number, we turn
// off drive motors and set brakeMode to brake.
//----------------------------------------------------------------------------------------------------
//Inputs:    speed    		Float    		speed we want to go at
//           degreesToTurn  Float  			degrees we want to turn
//           brakeMode      Bool            coast or brake
//----------------------------------------------------------------------------------------------------
void centerTurnUsingGyro(float speed, float degreesToTurn,  bool brakeMode)
{

	float gyroStartReading;							// The start value of the gyro
	float gyroEndReading;	// The value we want to end the while statement
	float momentum;

	momentum = (speed/5);

	// Get the starting gyroscope reading
	gyroStartReading = getGyroDegrees(gyro);



	if (degreesToTurn > 0)												// Turning to the right
	{

		// Compute the end reading
		gyroEndReading = gyroStartReading + degreesToTurn - momentum;
		setMotorSpeed(leftDrive, speed);
		setMotorSpeed(rightDrive, -speed);

		while (getGyroDegrees(gyro) < gyroEndReading)
		{

		}


	}
	else																				// Turning to the left
	{
		// Compute the end reading
		gyroEndReading = gyroStartReading + degreesToTurn + momentum;

		setMotorSpeed(leftDrive, -speed);
		setMotorSpeed(rightDrive, speed);

		while (getGyroDegrees(gyro) > gyroEndReading)
		{

		}


	}


	// Stop Motors
	turnOffDriveMotors();

	// Apply brakes if selected
	setBrakeMode(brakeMode);


}


//----------------------------------------------------------------------------------------------------
// Name: sideTurnUsingGyro
//----------------------------------------------------------------------------------------------------
// Description: get the gyrosocpe reading at the very start, compute the end reading, if the degreesToTurn
// is greater that 0 we are turning to the right, if it is less then, we are turning to the left. Then
// we turn off drive motors and set brake mode.
//----------------------------------------------------------------------------------------------------
//Inputs:     speed   		Float   		speed we want to go at
//            degreesToTurn Float    		degrees we want to turn
//            brakeMode     Bool            coast or brake
//----------------------------------------------------------------------------------------------------
void sideTurnUsingGyro(float speed, float degreesToTurn,  bool brakeMode)
{

	float gyroStartReading;							// The start value of the gyro
	float gyroEndReading;							// The value we want to end the while statement
	float momentum;

	momentum = (speed/4);

	// Get the starting gyroscope reading
	gyroStartReading = getGyroDegrees(gyro);



	if (degreesToTurn > 0)												// Turning to the right
	{

		// Compute the end reading
		gyroEndReading = gyroStartReading + degreesToTurn - momentum;

		setMotorSpeed(leftDrive, speed);
		setMotorSpeed(rightDrive, 0);

		while (getGyroDegrees(gyro) < gyroEndReading)
		{

		}


	}
	else														// Turning to the left
	{

		// Compute the end reading
		gyroEndReading = gyroStartReading + degreesToTurn + momentum;

		setMotorSpeed(leftDrive, 0);
		setMotorSpeed(rightDrive, speed);

		while (getGyroDegrees(gyro) > gyroEndReading)
		{

		}


	}

	// Stop Motors
	turnOffDriveMotors();

	// Apply brakes if selected
	setBrakeMode(brakeMode);


}
