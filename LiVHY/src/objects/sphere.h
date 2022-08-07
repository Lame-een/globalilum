#pragma once
#include "object.h"

class Sphere : public Object
{
public:
	Sphere(BRDF* brdf);
	Sphere(const Vec3& pos, double radius, BRDF* brdf);

	bool RayIntersect(const Ray& ray,
					  double& t, Vec3& normal) override;

	const Vec3 Position() const;
	const double Radius() const;
	const double Radius2() const;
private:
	Vec3 m_Position = Vec3(0.0);
	double m_Radius = 1.0;
	double m_Radius2 = 1.0;
};