#include "../mat4_func.h"

namespace salg
{

bool operator==(mat4 a, mat4 b)
{
    for (short i = 0; i < a.NUMELMS; i++)
        if (a.data[i] != b.data[i])
            return false;
    return true;
}

bool operator!=(mat4 a, mat4 b)
{
    return !(a == b);
}

bool operator>=(mat4 a, mat4 b)
{
    size_t c = 0;
    for (short i = 0; i < a.NUMELMS; i++)
        if (a.data[i] >= b.data[i])
            c++;
    return c == a.NUMELMS;
}

bool operator<=(mat4 a, mat4 b)
{
    size_t c = 0;
    for (short i = 0; i < a.NUMELMS; i++)
        if (a.data[i] <= b.data[i])
            c++;
    return c == a.NUMELMS;
}

bool operator<(mat4 a, mat4 b)
{
    size_t c = 0;
    for (short i = 0; i < a.NUMELMS; i++)
        if (a.data[i] < b.data[i])
            c++;
    return c == a.NUMELMS;
}

bool operator>(mat4 a, mat4 b)
{
    size_t c = 0;
    for (short i = 0; i < a.NUMELMS; i++)
        if (a.data[i] > b.data[i])
            c++;
    return c == a.NUMELMS;
}

mat4 max(mat4 a, mat4 b)
{
    if (a == b) return a;
    return (a > b) ? a : b;
}

mat4 min(mat4 a, mat4 b)
{
    if (a == b) return a;
    return (a < b) ? a : b;
}

mat4 translate(vec3 translation)
{
    mat4 t;
    t.m[0][3] = translation.x;
    t.m[1][3] = translation.y;
    t.m[2][3] = translation.z;  
    return t;
}

vec3 getTranslation(mat4 m)
{
    return { m.m[0][3], m.m[1][3], m.m[2][3] };
}

vec3 getScale(mat4 m)
{
    vec3 v(
        magnitude({m.m[0][0], m.m[0][1], m.m[0][2]}),
        magnitude({m.m[1][0], m.m[1][1], m.m[1][2]}),
        magnitude({m.m[2][0], m.m[2][1], m.m[2][2]})
    );
    return v;
}

transform_component decompose(mat4 m)
{
    mat4 mat = transpose(m);
    transform_component t;
    t.scale.data[0] = magnitude({mat.m[0][0], mat.m[0][1], mat.m[0][2]});
    t.scale.data[1] = magnitude({mat.m[1][0], mat.m[1][1], mat.m[1][2]});
    t.scale.data[2] = magnitude({mat.m[2][0], mat.m[2][1], mat.m[2][2]});

    orthoNormalize(mat);

    t.rotation.data[0] = atan2(mat.m[1][2], mat.m[2][2]);
    t.rotation.data[1] = atan2(-mat.m[0][2], sqrt(mat.m[1][2] * mat.m[1][2] + mat.m[2][2] * mat.m[2][2]));
    t.rotation.data[2] = atan2(mat.m[0][1], mat.m[0][0]);

    t.translation.data[0] = mat.m[3][0];
    t.translation.data[1] = mat.m[3][1];
    t.translation.data[2] = mat.m[3][2];

    return t;
}

void orthoNormalize(mat4& m)
{
    vec3 right(m.m[0][0], m.m[1][0], m.m[2][0]);
    normalize(right);

    m.m[0][0] = right.x;
    m.m[1][0] = right.y;
    m.m[2][0] = right.z;

    vec3 up(m.m[0][1], m.m[1][1], m.m[2][1]);
    normalize(up);
    m.m[0][1] = up.x;
    m.m[1][1] = up.y;
    m.m[2][1] = up.z;

    vec3 dir(m.m[0][2], m.m[1][2], m.m[2][2]);
    normalize(dir);
    m.m[0][2] = dir.x;
    m.m[1][2] = dir.y;
    m.m[2][2] = dir.z;
}

mat4 transpose(mat4 m)
{
    mat4 t;
    for (short l = 0; l < 4; l++)
        for (short c = 0; c < 4; c++)
            t.m[l][c] = m.m[c][l];
    return t;
}

mat4 scale(vec3 s)
{
    mat4 t;
    t.m[0][0] = s.x;
    t.m[1][1] = s.y;
    t.m[2][2] = s.z;
    return t;
}

mat4 rotateX(const scalar& angle)
{
    mat4 t;
    t.m[1][1] =  cos(angle);
    t.m[1][2] = -sin(angle);
    t.m[2][1] =  sin(angle);
    t.m[2][2] =  cos(angle);
    return t;
}

mat4 rotateY(const scalar& angle)
{
    mat4 t;
    t.m[0][0] =  cos(angle);
    t.m[0][2] =  sin(angle);
    t.m[2][0] = -sin(angle);
    t.m[2][2] =  cos(angle);
    return t;
}

mat4 rotateZ(const scalar& angle)
{
    mat4 t;
    t.m[0][0] =  cos(angle);
    t.m[0][1] = -sin(angle);
    t.m[1][0] =  sin(angle);
    t.m[1][1] =  cos(angle);
    return t;
}

mat4 rotate(const scalar& r, const scalar& i, const scalar& j, const scalar& k)
{
    mat4 t(
            1 - 2 * j * j - 2 * k * k,
			2 * i * j - 2 * k * r,
			2 * i * k + 2 * j * r,
			0.0f,

			2 * i * j + 2 * r * k,
			1 - 2 * i * i - 2 * k * k,
			2 * j * k - 2 * r * i,
			0.0f,

			2 * i * k - 2 * r * j,
			2 * j * k + 2 * r * i,
			1 - 2 * i * i - 2 * j * j,
			0.0f,

			0.0f,
			0.0f,
			0.0f,
			1.0f
    );
    return t;
}

mat4 frustrum(scalar bottom, scalar top, scalar left, scalar right, scalar near, scalar far)
{
    mat4 t(
            2.0f * near / (right - 1),
			0.0f,
			0.0f,
			0.0f,

			0.0f,
			2.0f * near / (top - bottom),
			0.0f,
			0.0f,

			(right + left) / (right - left),
			(top + bottom) / (top - bottom),
			-(far + near) / (far - near),
			-1.0f,

			0.0f,
			0.0f,
			-2.0f * far * near / (far - near),
			0.0f
    );
    return t;
}

mat4 perspectiveRH(scalar fovY, scalar aspect, scalar near, scalar far)
{
    scalar tanHalfFovY = tan(fovY / 2);
    mat4 t(
            1.0f / (tanHalfFovY * aspect),
			0.0f,
			0.0f,
			0.0f,

			0.0f,
			1 / tanHalfFovY,
			0.0f,
			0.0f,

			0.0f,
			0.0f,
			far / (near - far),
			-1.0f,

			0.0f,
			0.0f,
			-(far * near) / (far - near),
			0.0f
    );
    return t;
}

mat4 perspectiveLH(scalar fovY, scalar aspect, scalar near, scalar far) 
{
    scalar sinFov = sin(fovY * 0.5);
    scalar cosFov = cos(fovY * 0.5);
    scalar height = cosFov / sinFov;
    scalar width = height / aspect;
    scalar fRange = far / (far - near);

    mat4 tmp
    (
        width, 0, 0, 0,
        0, height, 0, 0, 
        0, 0, fRange, 0, 
        0, 0, -fRange * near, 0
    );
    return tmp;
}

mat4 orthographicRH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far)
{
    mat4 t(
            2 / (right - left),
			0.0f,
			0.0f,
			0.0f,

			0.0f,
			2 / (top - bottom),
			0.0f,
			0.0f,

			0.0f,
			0.0f,
			-2.0f / (far - near),
			0.0f,

			-((right + left) / (right - left)),
			-((top + bottom) / (top - bottom)),
			-(far + near) / (far - near),
			1.0f
    );
    return t;
}

mat4 orthographicLH(scalar left, scalar right, scalar bottom, scalar top, scalar near, scalar far)
{
    mat4 t(
            2 / (right - left),
			0.0f,
			0.0f,
			0.0f,

			0.0f,
			2 / (top - bottom),
			0.0f,
			0.0f,

			0.0f,
			0.0f,
			1.0f / (far - near),
			0.0f,

			-(right + left) / (right - left),
			-(top + bottom) / (top - bottom),
			-(near / (far - near)),
			1.0f
    );
    return t;
}

mat4 lookAt(vec3 fromPos, vec3 toPos, vec3 up)
{
    vec3 f = normalize(toPos - fromPos);
    vec3 s = normalize(cross(f, up));
    vec3 u = cross(s, f);

    mat4 t(
            s.x,
			u.x,
			-f.x,
			0.0f,

			s.y,
			u.y,
			-f.y,
			0.0f,

			s.z,
			u.z,
			-f.z,
			0.0f,

			-dot(s, fromPos),
			-dot(up, fromPos),
			dot(f, fromPos),
			1.0f
    );
    return t;
}

scalar determinant(mat4 m)
{
    return  
    m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0] - m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0] - m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0] + m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0] +
    m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] - m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] - m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1] + m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1] +
    m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] - m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1] - m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] + m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] +
    m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] - m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2] + m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2] +
    m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] - m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2] - m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] + m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] +
    m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] - m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] + m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] ;
}

mat4 inverse(mat4 m)
{
    mat4 t(
       m.m[1][2] *m.m[2][3] *m.m[3][1] -m.m[1][3] *m.m[2][2] *m.m[3][1] +m.m[1][3] *m.m[2][1] *m.m[3][2] -m.m[1][1] *m.m[2][3] *m.m[3][2] -m.m[1][2] *m.m[2][1] *m.m[3][3] +m.m[1][1] *m.m[2][2] *m.m[3][3],
       m.m[0][3] *m.m[2][2] *m.m[3][1] -m.m[0][2] *m.m[2][3] *m.m[3][1] -m.m[0][3] *m.m[2][1] *m.m[3][2] +m.m[0][1] *m.m[2][3] *m.m[3][2] +m.m[0][2] *m.m[2][1] *m.m[3][3] -m.m[0][1] *m.m[2][2] *m.m[3][3],
       m.m[0][2] *m.m[1][3] *m.m[3][1] -m.m[0][3] *m.m[1][2] *m.m[3][1] +m.m[0][3] *m.m[1][1] *m.m[3][2] -m.m[0][1] *m.m[1][3] *m.m[3][2] -m.m[0][2] *m.m[1][1] *m.m[3][3] +m.m[0][1] *m.m[1][2] *m.m[3][3],
       m.m[0][3] *m.m[1][2] *m.m[2][1] -m.m[0][2] *m.m[1][3] *m.m[2][1] -m.m[0][3] *m.m[1][1] *m.m[2][2] +m.m[0][1] *m.m[1][3] *m.m[2][2] +m.m[0][2] *m.m[1][1] *m.m[2][3] -m.m[0][1] *m.m[1][2] *m.m[2][3],
       m.m[1][3] *m.m[2][2] *m.m[3][0] -m.m[1][2] *m.m[2][3] *m.m[3][0] -m.m[1][3] *m.m[2][0] *m.m[3][2] +m.m[1][0] *m.m[2][3] *m.m[3][2] +m.m[1][2] *m.m[2][0] *m.m[3][3] -m.m[1][0] *m.m[2][2] *m.m[3][3],
       m.m[0][2] *m.m[2][3] *m.m[3][0] -m.m[0][3] *m.m[2][2] *m.m[3][0] +m.m[0][3] *m.m[2][0] *m.m[3][2] -m.m[0][0] *m.m[2][3] *m.m[3][2] -m.m[0][2] *m.m[2][0] *m.m[3][3] +m.m[0][0] *m.m[2][2] *m.m[3][3],
       m.m[0][3] *m.m[1][2] *m.m[3][0] -m.m[0][2] *m.m[1][3] *m.m[3][0] -m.m[0][3] *m.m[1][0] *m.m[3][2] +m.m[0][0] *m.m[1][3] *m.m[3][2] +m.m[0][2] *m.m[1][0] *m.m[3][3] -m.m[0][0] *m.m[1][2] *m.m[3][3],
       m.m[0][2] *m.m[1][3] *m.m[2][0] -m.m[0][3] *m.m[1][2] *m.m[2][0] +m.m[0][3] *m.m[1][0] *m.m[2][2] -m.m[0][0] *m.m[1][3] *m.m[2][2] -m.m[0][2] *m.m[1][0] *m.m[2][3] +m.m[0][0] *m.m[1][2] *m.m[2][3],
       m.m[1][1] *m.m[2][3] *m.m[3][0] -m.m[1][3] *m.m[2][1] *m.m[3][0] +m.m[1][3] *m.m[2][0] *m.m[3][1] -m.m[1][0] *m.m[2][3] *m.m[3][1] -m.m[1][1] *m.m[2][0] *m.m[3][3] +m.m[1][0] *m.m[2][1] *m.m[3][3],
       m.m[0][3] *m.m[2][1] *m.m[3][0] -m.m[0][1] *m.m[2][3] *m.m[3][0] -m.m[0][3] *m.m[2][0] *m.m[3][1] +m.m[0][0] *m.m[2][3] *m.m[3][1] +m.m[0][1] *m.m[2][0] *m.m[3][3] -m.m[0][0] *m.m[2][1] *m.m[3][3],
       m.m[0][1] *m.m[1][3] *m.m[3][0] -m.m[0][3] *m.m[1][1] *m.m[3][0] +m.m[0][3] *m.m[1][0] *m.m[3][1] -m.m[0][0] *m.m[1][3] *m.m[3][1] -m.m[0][1] *m.m[1][0] *m.m[3][3] +m.m[0][0] *m.m[1][1] *m.m[3][3],
       m.m[0][3] *m.m[1][1] *m.m[2][0] -m.m[0][1] *m.m[1][3] *m.m[2][0] -m.m[0][3] *m.m[1][0] *m.m[2][1] +m.m[0][0] *m.m[1][3] *m.m[2][1] +m.m[0][1] *m.m[1][0] *m.m[2][3] -m.m[0][0] *m.m[1][1] *m.m[2][3],
       m.m[1][2] *m.m[2][1] *m.m[3][0] -m.m[1][1] *m.m[2][2] *m.m[3][0] -m.m[1][2] *m.m[2][0] *m.m[3][1] +m.m[1][0] *m.m[2][2] *m.m[3][1] +m.m[1][1] *m.m[2][0] *m.m[3][2] -m.m[1][0] *m.m[2][1] *m.m[3][2],
       m.m[0][1] *m.m[2][2] *m.m[3][0] -m.m[0][2] *m.m[2][1] *m.m[3][0] +m.m[0][2] *m.m[2][0] *m.m[3][1] -m.m[0][0] *m.m[2][2] *m.m[3][1] -m.m[0][1] *m.m[2][0] *m.m[3][2] +m.m[0][0] *m.m[2][1] *m.m[3][2],
       m.m[0][2] *m.m[1][1] *m.m[3][0] -m.m[0][1] *m.m[1][2] *m.m[3][0] -m.m[0][2] *m.m[1][0] *m.m[3][1] +m.m[0][0] *m.m[1][2] *m.m[3][1] +m.m[0][1] *m.m[1][0] *m.m[3][2] -m.m[0][0] *m.m[1][1] *m.m[3][2],
       m.m[0][1] *m.m[1][2] *m.m[2][0] -m.m[0][2] *m.m[1][1] *m.m[2][0] +m.m[0][2] *m.m[1][0] *m.m[2][1] -m.m[0][0] *m.m[1][2] *m.m[2][1] -m.m[0][1] *m.m[1][0] *m.m[2][2] +m.m[0][0] *m.m[1][1] *m.m[2][2]
    );
    t *= determinant(m);
    return t;   
}

mat4 identity()
{
    return
    (
    mat4{
        1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
    }
    );
}

}
