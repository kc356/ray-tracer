#pragma once
#include "material.h"

class material;

class metal : public material
{
public:
	metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}
	virtual bool scatter(
		const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
	) const override;
public:
	color albedo;
	double fuzz;
};

