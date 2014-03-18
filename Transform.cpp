#include <stdio.h>




Matrix4f Transform::scale(float sx, float sy, float sz) {
	return Matrix4f(sx, 0.0, 0.0, 0.0,
			0.0, sy, 0.0, 0.0,
		        0.0, 0.0, sz, 0.0,
		        0.0, 0.0, 0.0, 1.0);
}

Matrix4f Transform::translate(float t, float ty, float tz) {
	return Matrix4f(1.0, 0.0, 0.0, tx,
			0.0, 1.0, 0.0, ty,
			0.0, 0.0, 1.0, tz,
			0.0, 0.0, 0.0, 1.0);
}


    
}
