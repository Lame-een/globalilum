#include "triangleMesh.h"

TriangleMesh::TriangleMesh()
{
}

/// faces should contain triples of indices describing a single triangle face.
TriangleMesh::TriangleMesh(const std::vector<Vec3>& vertices, const std::vector<Vec3i> faces, const BRDF* brdf)
	: Object(brdf)
{
	for(const Vec3i& face : faces)
	{
		m_Triangles.push_back(new Triangle(vertices[face[0]], vertices[face[1]], vertices[face[2]], brdf));
	}
}

TriangleMesh::~TriangleMesh()
{
	for(Object*& obj : m_Triangles)
	{
		delete obj;
	}
}

const std::vector<Object*>& TriangleMesh::Triangles() const
{
	return m_Triangles;
}

bool TriangleMesh::Hit(const Ray& ray, double tMin, double tMax, HitInfo& hitInfo)
{
	HitInfo auxInfo;
	bool hasHit = false;
	double hitDist = tMax;

	for(const auto& obj : m_Triangles)
	{
		if(obj->Hit(ray, tMin, hitDist, auxInfo))
		{
			hasHit = true;
			hitDist = auxInfo.t;
			hitInfo = auxInfo;
		}
	}

	return hasHit;
}

bool TriangleMesh::BoundingBox(AABB& outputBox) const
{
	if(m_Triangles.empty()) return false;

	AABB auxBox;
	bool firstBox = true;

	for(const auto& obj : m_Triangles)
	{
		if(!obj->BoundingBox(auxBox)) return false;

		if(firstBox)
		{
			outputBox = auxBox;
			firstBox = false;
		}
		else
		{
			outputBox.Surround(auxBox);
		}
	}

	return true;
}
