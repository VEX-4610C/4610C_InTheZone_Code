void degmove(int distance)
{
	nMotorEncoder[frontLeft] = 0;
	if(distance > 0) // move forward
	{
		while(nMotorEncoder[frontLeft] < distance)
		{
			motor[frontLeft] = motor[backLeft] = 127;
			motor[frontRight] = motor[backRight] = 127;
		}
		motor[frontLeft] = motor[backLeft] = -15;
		motor[frontRight] = motor[backRight] = -15;
		wait1MSec(100);
		motor[frontLeft] = motor[backLeft] = 0;
		motor[frontRight] = motor[backRight] = 0;
	}
	else
	{
		while(nMotorEncoder[frontLeft] > distance)
		{
			motor[frontLeft] = motor[backLeft] = -127;
			motor[frontRight] = motor[backRight] = -127;
		}
		motor[frontLeft] = motor[backLeft] = 15;
		motor[frontRight] = motor[backRight] = 15;
		wait1MSec(100);
		motor[frontLeft] = motor[backLeft] = 0;
		motor[frontRight] = motor[backRight] = 0;
	}
}
void gyroturn(int degrees)
{
	SensorValue[gyro] = 0;
	if(degrees > 0) // turn right
	{
		while(SensorValue[gyro] < degrees)
		{
			motor[frontLeft] = motor[backLeft] = -127;
			motor[frontRight] = motor[backRight] = 127;
		}
		motor[frontLeft] = motor[backLeft] = 15;
		motor[frontRight] = motor[backRight] = -15;
		wait1MSec(100);
		motor[frontLeft] = motor[backLeft] = 0;
		motor[frontRight] = motor[backRight] = 0;
	}
	else
	{
		while(SensorValue[gyro] > degrees)
		{
			motor[frontLeft] = motor[backLeft] = 127;
			motor[frontRight] = motor[backRight] = -127;
		}
		motor[frontLeft] = motor[backLeft] = -15;
		motor[frontRight] = motor[backRight] = 15;
		wait1MSec(100);
		motor[frontLeft] = motor[backLeft] = 0;
		motor[frontRight] = motor[backRight] = 0;
	}
}
