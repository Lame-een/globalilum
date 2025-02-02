#include "pch.h"
#include "ray.h"
//#include "glm/geometric.hpp"

Ray::Ray()
{
}

Ray::Ray(const Vec3& orig, const Vec3& dir)
	: m_Origin(orig), m_Dir(dir)
{
}

void Ray::Normalize()
{
	m_Dir = glm::normalize(m_Dir);
}

const Vec3& Ray::Origin() const
{
	return m_Origin;
}
void Ray::SetOrigin(const Vec3& point)
{
	m_Origin = point;	
}

const Vec3& Ray::Dir() const
{
	return m_Dir;
}
void Ray::SetDir(const Vec3& dir)
{
	m_Dir = dir;
}
