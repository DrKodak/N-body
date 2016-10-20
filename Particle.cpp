#include <vector>
#include "Particle.h"
using namespace std;

void Particle::setPosition(double x, double y, double z)
{
	pos.resize(3);
	pos[0] = x;
	pos[1] = y;
	pos[2] = z;
}

void Particle::setVelocity(double x, double y, double z)
{
	vel.resize(3);
	vel[0] = x;
	vel[1] = y;
	vel[2] = z;
}

void Particle::setAcceleration(double x, double y, double z)
{
	accel.resize(3);
	accel[0] = x;
	accel[1] = y;
	accel[2] = z;
}

void Particle::setMass(double m)
{
	mass = m;
}
