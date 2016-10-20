#include <vector>
using namespace std;

#ifndef Particle_H
#define Particle_H

class Particle
{
public:
	double mass;
	

	vector <double> pos;
	vector <double> vel;
	vector <double> accel;

	void setPosition(double x, double y, double z);
	void setVelocity(double x, double y, double z);
	void setAcceleration(double x, double y, double z);
	void setMass(double);

};


#endif // !Particle_h
