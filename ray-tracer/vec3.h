#pragma once

#include <cmath>
#include <iostream>

class vec3
{
public:
	vec3();
	vec3(double e0, double e1, double e2);
public:
	double x() const;
	double y() const;
	double z() const;
public:
	vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);
	vec3& operator+=(const vec3& v);
	vec3& operator*=(const double t);
	vec3& operator/=(const double t);
public:
	double length() const;
	double length_squared() const;
public:
	inline static vec3 random();
	inline static vec3 random(double min, double max);
public:
	bool near_zero() const;
public:
	double e[3];
};

using point3 = vec3;   // 3D point
using color = vec3;    // RGB color
using namespace std;


inline ostream& operator<<(ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

inline vec3 random_in_unit_sphere();

vec3 random_unit_vector();

vec3 random_in_hemisphere(const vec3& normal);

vec3 reflect(const vec3& v, const vec3& n);