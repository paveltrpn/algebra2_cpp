#pragma once

#include <cmath>
#include <tuple>

using namespace std;

enum {_XC, _YC, _ZC, _WC};
enum mtrx_type {MTRX_IDTT, MTRX_ZERO};

constexpr float f_eps = 5.96e-08;
constexpr float deg_to_rad(float deg) {
	return deg * M_PI/180.0f;
}

class vec2_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		vec2_t &operator=(const vec2_t &v) {
			data[_XC] = v[_XC];
			data[_YC] = v[_YC];

			return (*this);
		};

		vec2_t(): 
			data{0.0, 0.0} {};
		
		vec2_t(const float x, const float y): 
			data{x, y} {};
		
		vec2_t(const vec2_t &v): 
			data{v[_XC], v[_YC]} {};

		~vec2_t() {};
	
	private:
		float data[2];
};

class vec3_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		vec3_t &operator=(const vec3_t &v) {
			data[_XC] = v[_XC];
			data[_YC] = v[_YC];
			data[_ZC] = v[_ZC];

			return (*this);
		};

		vec3_t(): 
			data{0.0, 0.0, 0.0} {};
		
		vec3_t(const float x, const float y, const float z): 
			data{x, y, z} {};
		
		vec3_t(const vec3_t &v): 
			data{v[_XC], v[_YC], v[_ZC]} {};

		~vec3_t() {};
	
	private:
		float data[3];
};

class vec4_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		vec4_t &operator=(const vec4_t &v) {
			data[_XC] = v[_XC];
			data[_YC] = v[_YC];
			data[_ZC] = v[_ZC];
			data[_WC] = v[_WC];

			return (*this);
		};

		vec4_t(): 
			data{0.0, 0.0, 0.0, 0.0} {};
		
		vec4_t(const float x, const float y, const float z, const float w): 
			data{x, y, z, w} {};
		
		vec4_t(const vec4_t &v): 
			data{v[_XC], v[_YC], v[_ZC], v[_WC]} {};

		~vec4_t() {};
	
	private:
		float data[4];
};

class mtrx2_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		mtrx2_t &operator=(const mtrx2_t &m) {
			for (int i = 0; i < 4; i++) {
				data[i] = m[i];
			}
			
			return (*this);
		};

		mtrx2_t(): 
			data{1.0f, 0.0f,
				 0.0f, 1.0f} {};

		mtrx2_t(float a00, float a01,
                float a10, float a11):
			data{a00, a01,
                 a10, a11} {};

		mtrx2_t(const mtrx2_t &m):
			data{m[0], m[1],
				 m[2], m[3]} {};
		
		mtrx2_t(float phi);
		
		~mtrx2_t() {};
	
	private:
		float data[4];
};

class mtrx3_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		mtrx3_t &operator=(const mtrx3_t &m) {
			for (int i = 0; i < 9; i++) {
				data[i] = m[i];
			}
			
			return (*this);
		};

		mtrx3_t(): 
			data{1.0f, 0.0f, 0.0f,
				 0.0f, 1.0f, 0.0f,
				 0.0f, 0.0f, 1.0f} {};

		mtrx3_t(float a00, float a01, float a02,
                float a10, float a11, float a12,
                float a20, float a21, float a22):
			data{a00, a01, a02,
                 a10, a11, a12,
                 a20, a21, a22} {};

		mtrx3_t(const mtrx3_t &m):
			data{m[0], m[1], m[2],
				 m[3], m[4], m[5],
				 m[6], m[7], m[8]} {};
		
		mtrx3_t(float yaw, float pitch, float roll);
		mtrx3_t(const vec3_t &ax, float phi);
		
		~mtrx3_t() {};
	
	private:
		float data[9];
};

class mtrx4_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		mtrx4_t &operator=(const mtrx4_t &m) {
			for (int i = 0; i < 16; i++) {
				data[i] = m[i];
			}
			
			return (*this);
		};

		mtrx4_t(): 
			data{1.0f, 0.0f, 0.0f, 0.0f,
				 0.0f, 1.0f, 0.0f, 0.0f,
				 0.0f, 0.0f, 1.0f, 0.0f,
				 0.0f, 0.0f, 0.0f, 1.0f} {};

		mtrx4_t(float a00, float a01, float a02, float a03,
                float a10, float a11, float a12, float a13,
                float a20, float a21, float a22, float a23,
                float a30, float a31, float a32, float a33):
			data {a00, a01, a02, a03,
                  a10, a11, a12, a13,
                  a20, a21, a22, a23,
                  a30, a31, a32, a33} {};

		mtrx4_t(const mtrx4_t &m):
			data{m[0],  m[1],  m[2],  m[3], 
				 m[4],  m[5],  m[6],  m[7], 
				 m[8],  m[9],  m[10], m[11],
				 m[12], m[13], m[14], m[15]} {};
		
		mtrx4_t(float yaw, float pitch, float roll);
		mtrx4_t(const vec3_t &ax, float phi);

		~mtrx4_t() {};
	
	private:
		float data[16];
};

class qtnn_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		qtnn_t &operator=(const qtnn_t &q) {
			data[_XC] = q[_XC];
			data[_YC] = q[_YC];
			data[_ZC] = q[_ZC];
			data[_WC] = q[_WC];

			return (*this);
		};

		qtnn_t(): 
			data{0.0, 0.0, 0.0, 0.0} {};
		
		qtnn_t(const float x, const float y, const float z, const float w): 
			data{x, y, z, w} {};

		qtnn_t(const vec3_t &v):
			data{v[_XC], v[_YC], v[_ZC], 0.0} {};
		
		qtnn_t(const qtnn_t &q): 
			data{q[_XC], q[_YC], q[_ZC], q[_WC]} {};

		qtnn_t(float yaw, float pitch, float roll);
		qtnn_t(const vec3_t &ax, float phi);
		
		~qtnn_t () {};
	
	private:
		float data[4];
};

class plane_t {
	public:
		float operator[](const int32_t id) const {
			return data[id];
		};

		float &operator[](const int32_t id) {
			return data[id];
		};

		plane_t &operator=(const plane_t &p) {
			data[_XC] = p[_XC];
			data[_YC] = p[_YC];
			data[_ZC] = p[_ZC];
			data[_WC] = p[_WC];

			return (*this);
		};

		plane_t(): 
			data{0.0, 0.0, 0.0, 0.0} {};
		
		plane_t(const float x, const float y, const float z, const float w): 
			data{x, y, z, w} {};

		plane_t(const vec3_t &v, float d); /*empty*/

		plane_t(const vec3_t &v1, const vec3_t &v2, const vec3_t &v3); /*empty*/

	private:
		float data[4];
};

/*	multidimensional array mapping, array[i][j]
	row-wise (C, C++):
	(0	1)
	(2	3)

	column-wise (Fortran, Matlab):
	(0	2)
	(1	3)
*/

constexpr int32_t id_rw(int32_t i, int32_t j, int32_t n) {
	return (i*n + j);
};

constexpr int32_t id_cw(int32_t i, int32_t j, int32_t n) {
	return (j*n + i);
};

void   vec2_show(const vec2_t &v);
float  vec2_lenght(const vec2_t &v);
vec2_t vec2_normalize(const vec2_t &v);
vec2_t vec2_scale(const vecT_t &v,const float scale);
vec2_t vec_invert(const vecT_t &v);
float  vec2_dot(const vecT_t &a, const vecT_t &b);
vec2_t vec_sum(const vecT_t &a, const vecT_t &b);
vec2_t vec2_sub(const vecT_t &a, const vecT_t &b);

void   vec3_show(vec3_t &v);
vec3_t vec3_copy(vec3_t &v);
vec3_t vec3_set(float x, float y, float z);
float  vec3_lenght(vec3_t &v);
vec3_t vec3_normalize(vec3_t &v);
vec3_t vec3_scale(vec3_t &v, float scale);
vec3_t vec3_invert(vec3_t &v);
float  vec3_dot(vec3_t &a, vec3_t &a);
vec3_t vec3_sum(vec3_t &a, vec3_t &b);
vec3_t vec3_sub(vec3_t &a, vec3_t &b);
vec3_t vec3_cross(vec3_t &a, vec3_t &b);

void   vec4_show(vec4_t &v)
vec4_t vec4_copy(v vec4_t) 
vec4_t vec4_set(float x, float y, float z, float w)
float  vec4_lenght(vec4_t &v)
vec4_t vec4_normalize(vec4_t &v) 
vec4_t vec4_scale(vec4_t &v, float sclae)
vec4_t vec4_invert(vec4_t &v)
float  vec4_dot(vec4_t &a, vec4_t &b)
vec4_t vec4Sum(a, b vec4_t) 
vec4_t vec4Sub(vec4_t &a, vec4_t &b)

void 	qtnn_show(const qtnn_t &q); 
float	qtnn_lenght(const qtnn_t &q);
qtnn_t	qtnn_normalize(const qtnn_t &q);
qtnn_t	qtnn_invert(const qtnn_t &q);
qtnn_t	qtnn_scale(const qtnn_t &q, float scale);
qtnn_t	qtnn_sum(const qtnn_t &a, const qtnn_t &b);
qtnn_t 	qtnn_sub(const qtnn_t &a, const qtnn_t &b);
float   qtnn_dot(const qtnn_t &a, const qtnn_t &b);
qtnn_t  qtnn_mult(const qtnn_t &a, const qtnn_t &b); 
qtnn_t  qtnn_mult_vec3(const qtnn_t a, const qtnn_t &b);
vec3_t  qtnn_to_vec3(const qtnn_t &q);
vec3_t  qtnn_transform_vec3(const qtnn_t &a, const vec3_t &b);

vec3_t 	plane_ray_insct(const vec3_t &rs, const vec3_t &re); /*empty*/
bool	point_in_trngl(const vec3_t &v1, 
					   const vec3_t &v2, 
					   const vec3_t &v3,
					   const vec3_t &point);
