#pragma once
#include "material.h"

class lambertian : public material
{
public: 
	lambertian(const color& a) : alberdo(a) {};
	virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
	color alberdo;
};

