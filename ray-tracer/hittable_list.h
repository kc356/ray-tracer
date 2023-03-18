#pragma once
#include "hittable.h"
#include <memory>
#include <vector>

using namespace std;

class hittable_list : public hittable
{
public:
	hittable_list() {}
	hittable_list(shared_ptr<hittable> object);

	void clear();
	void add(shared_ptr<hittable> object);

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	vector<shared_ptr<hittable>> objects;


};

