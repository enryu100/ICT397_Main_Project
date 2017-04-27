#pragma once

#include <math.h>

namespace types{
	struct Vector2D{
		float x;
		float y;

		Vector2D(){
			x = 0.0f;
			y = 0.0f;
		}

		Vector2D(float xx, float yy){
			x = xx;
			y = yy;
		}

		float length(){
			return (sqrt(x*x + y*y));
		}

		Vector2D normalise(){
			Vector2D normalVec = Vector2D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
			}

			return normalVec;
		}
	};

	struct Vector3D{
		float x;
		float y;
		float z;

		Vector3D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
		}

		Vector3D(float xx, float yy, float zz){
			x = xx;
			y = yy;
			z = zz;
		}

		float length(){
			return (sqrt(x*x + y*y + z*z));
		}

		Vector3D normalise(){
			Vector3D normalVec = Vector3D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}

		Vector3D crossProduct(Vector3D otherVec){
			Vector3D crossVec;

			crossVec.x = (this->y * otherVec.z) + (this->z * otherVec.y);
			crossVec.y = (this->z * otherVec.x) + (this->x * otherVec.z);
			crossVec.z = (this->x * otherVec.y) + (this->y * otherVec.x);

			return crossVec;
		}
	};

	struct Vector4D{
		float x;
		float y;
		float z;
		float w;

		Vector4D(){
			x = 0.0f;
			y = 0.0f;
			z = 0.0f;
			w = 1.0f;
		}

		Vector4D(float xx, float yy, float zz, float ww){
			x = xx;
			y = yy;
			z = zz;
			w = ww;
		}

		float length(){
			if(z != 0.0f)
				return (sqrt(x*x + y*y + z*z));
			else
				return 0.0f;
		}

		Vector4D normalise(){
			Vector4D normalVec = Vector4D();
			float length = this->length();

			if(length != 0){
				normalVec.x = x / length;
				normalVec.y = y / length;
				normalVec.z = z / length;
			}

			return normalVec;
		}
	};

	struct Matrix4x4{
		Vector4D columns[4];

		Matrix4x4(){
			columns[0] = Vector4D(1, 0, 0, 0);
			columns[1] = Vector4D(0, 1, 0, 0);
			columns[2] = Vector4D(0, 0, 1, 0);
			columns[3] = Vector4D(0, 0, 0, 1);
		}

		Matrix4x4(Vector4D col1, Vector4D col2, Vector4D col3, Vector4D col4){
			columns[0] = col1;
			columns[1] = col2;
			columns[2] = col3;
			columns[3] = col4;
		}
	};

	Vector4D operator*(const Matrix4x4& m, const Vector4D& v);
	Vector4D operator*(const Vector4D& v, const Matrix4x4& m);
	Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
}