#pragma once
#include "types.h"
#include "objects/object.h"

inline int c_MaxRaytracerDepth = 2;
inline double c_RayMaxLength = 1000.0;
inline double c_RayTerminateProbability = 0.01;
inline int c_TransmissiveSampleNum = 16;
inline int c_SpecularSampleNum = 16;
inline int c_IndirectSampleNum = 16;

Vec3 ReflectiveBounce(Vec3 normal, const Vec3& view, double cosTheta);

Vec3 SpecularImportanceSample(const Vec3& exact, double n, double cosTheta);

Vec3 TransmissiveBounce(const HitInfo& hitInfo, double cosTheta);

Vec3 DiffuseImportanceSample(Vec3 normal);