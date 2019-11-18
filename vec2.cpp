
#include <iostream>
#include <tuple>
#include <cmath>
#include "algebra2.h"

using namespace std;


void vec2_show(const vec2_t &v) {
	printf("%5.2f %5.2f\n", v[0], v[1]);
}

float vec2_lenght(const vec2_t &v) {
	return sqrt(vec2_dot(v,v));
}

vec2_t vec2_normalize(const vec2_t &v) {
	vec2_t rt;
	float len;

	len = vec_lenght(v);

	if (len != 0.0) {
		for (int i = 0; i < range; i++) {
			rt[i] = v[i] / len;
		}
	}

	return rt;
}

vec2_t	vec2_scale(const vecT_t &v,const float scale) {
	vecT_t rt;

	rt[0] = v[0] * scale;
	rt[1] = v[1] * scale;
	
	return rt;
}

vec2_t vec_invert(const vecT_t &v) {
	vec2_t rt;

	rt[0] = -v[0];
	rt[1] = -v[1];

	return rt;
}

float vec2_dot(const vecT_t &a, const vecT_t &b) {
	float rt = 0;

	rt = rt + a[0] * b[0] + a[1] * b[1];
	
	return rt;
}

vec2_t vec_sum(const vecT_t &a, const vecT_t &b) {
	vecT_t rt;

	rt[0] = a[0] + b[0];
	rt[1] = a[1] + b[1];

	return rt;
}

vec2_t vec2_sub(const vecT_t &a, const vecT_t &b) {
	vecT_t rt;

	rt[0] = a[0] - b[0];
	rt[1] = a[1] - b[1];

	return rt;
}

