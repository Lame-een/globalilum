#include "scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
	delete m_BVH;
}

/*
* O(N) implementation which bruteforces the check against every object.
bool Scene::Hit(const Ray& ray, double tMin, double tMax, HitInfo& hitInfo)
{
	hitInfo.t = std::numeric_limits<double>::max();
	HitInfo auxInfo = hitInfo;
	bool hit = false;
	for(auto obj : m_Objects)
	{
		if(obj->Hit(ray, tMin, tMax, auxInfo) && auxInfo.t < hitInfo.t)
		{
			hitInfo = auxInfo;
			hit = true;
		}
	}
	return hit;
}
*/

/// The function uses the BVH to quickly check if the ray hits any objects in
/// the scene.
bool Scene::Hit(const Ray& ray, double tMin, double tMax, HitInfo& hitInfo)
{
	return m_BVH->Hit(ray, tMin, tMax, hitInfo);
}

bool Scene::BoundingBox(AABB& outputBox) const
{
	return false;
};

std::vector<Object*> Scene::Objects()
{
	return m_Objects;
}

std::vector<Light*> Scene::Lights()
{
	return m_Lights;
}

void Scene::AddObject(Object* obj)
{
	m_Objects.push_back(obj);
}

void Scene::AddObject(TriangleMesh* obj)
{
	m_Objects.insert(m_Objects.end(), obj->Triangles().begin(), obj->Triangles().end());
}

void Scene::AddLight(Light* light)
{
	m_Lights.push_back(light);
}

void Scene::ConstructBvh()
{
	delete m_BVH;
	m_BVH = new BVHNode(m_Objects, 0, m_Objects.size());
}

const BVHNode* Scene::BVHRoot() const
{
	return m_BVH;
}

const RGB& Scene::Background() const
{
	return m_BackgroundColor;
}

void Scene::SetBackground(const RGB& rgb)
{
	m_BackgroundColor = rgb;
}