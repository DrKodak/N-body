#include "Particle.h"
#include <iostream>
#include <math.h>
#include <iomanip>

const float			G = 6.673e-11F;
const double        M_Earth = 5.9736e24F;
const double        M_Sun = 1.9891e30F;
const double        AU = 1.4959787066e11;
//Time constants
const short int     hr = 3600;
const long int      day = 24 * hr;
const double        J_yr = 365.25*day;
const double        yr = 3.15581450e7;

const double		tim = day/32.0;

vector <double> gravity(Particle earth, Particle sun);
vector <double> update(vector <double>&, vector <double>, vector <double>, double tim);

int main()
{
	Particle Sun, Earth;
	int nSteps = 128;

	Earth.setPosition(0.983 * AU, 0, 0);		// At theta = 0
	Earth.setVelocity(0, 30043.424, 0);		// Velocity is all in y at the moment
	Earth.setAcceleration(0, 0, 0);
	
	Earth.setMass(M_Earth);

	Sun.setPosition(0, 0, 0);
	Sun.setVelocity(0, 0, 0);
	Sun.setAcceleration(0, 0, 0);
	Sun.setMass(M_Sun);

	Earth.accel = gravity(Earth, Sun);
	
	
	for (int i = 0; i < 366 *nSteps; i++) {
		vector <double> aOld = Earth.accel;
		vector <double > vOld = Earth.vel;
		Earth.setAcceleration(0, 0, 0);

		Earth.accel = gravity(Earth, Sun);
		Earth.vel = update(Earth.vel, Earth.accel, aOld, tim);
		Earth.pos = update(Earth.pos, Earth.vel, vOld, tim);

		if (i % nSteps == 0) {
			cout << setprecision(5) << i / nSteps << "     " << atan2(Earth.pos[1], Earth.pos[0])*180.0 / 3.14159
				<< "     " << "     " << Earth.pos[0] / AU << "      " <<
				Earth.pos[1] / AU << "     " << sqrt(Earth.vel[0] * Earth.vel[0] + Earth.vel[1] * Earth.vel[1]) << endl;
		}
	}


	cin.get();

	return 0;
}



vector <double> gravity(Particle earth, Particle sun)
{
	double mag = sqrt(((earth.pos[0] - sun.pos[0])*(earth.pos[0] - sun.pos[0]) +
		(earth.pos[1] - sun.pos[1])*(earth.pos[1] - sun.pos[1]) +
		(earth.pos[2] - sun.pos[2])*(earth.pos[2] - sun.pos[2])));
	earth.accel[0] = -(G * sun.mass) / (mag * mag) *  ((earth.pos[0] - sun.pos[0]) / mag);
	earth.accel[1] = -(G * sun.mass) / (mag * mag) *  ((earth.pos[1] - sun.pos[1]) / mag);
	earth.accel[2] = -(G * sun.mass) / (mag * mag) *  ((earth.pos[2] - sun.pos[2]) / mag);
	//cout << "magnitude " <<setprecision(10)<< mag << endl;
	//cout << "gravity " << earth.accel[0] << "  " << earth.accel[1] << endl;
	return earth.accel;
}

vector<double> update(vector <double>& vel, vector <double> aNew, vector <double> aOld, double tim)
{

	vel[0] = vel[0] + ((aOld[0] + aNew[0]) / 2)*tim;
	vel[1] = vel[1] + ((aOld[1] + aNew[1]) / 2)*tim;
	vel[2] = vel[2] + ((aOld[2] + aNew[2]) / 2)*tim;

	return vel;
}