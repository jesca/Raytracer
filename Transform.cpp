#include <stdio.h>

 mat3 Transform::rotate( degrees, const vec3& axis) {
    // need to think about this
}


Matrix4f Transform::scale(float x, float y, float z) {
	return Matrix4f(sx, 0.0, 0.0, 0.0,
			0.0, sy, 0.0, 0.0,
		        0.0, 0.0, sz, 0.0,
		        0.0, 0.0, 0.0, 1.0);
}

Matrix4f Transform::translate(float x, float y, float z) {
	return Matrix4f(1.0, 0.0, 0.0, x,
				0.0, 1.0, 0.0, y,
				0.0, 0.0, 1.0, z,
				0.0, 0.0, 0.0, 1.0);
}


    
}
