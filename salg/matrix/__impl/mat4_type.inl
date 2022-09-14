#include "../mat4_type.h"

namespace salg
{

mat4::mat4
(
    const scalar& m00, const scalar& m01, const scalar& m02, const scalar& m03,
    const scalar& m10, const scalar& m11, const scalar& m12, const scalar& m13,
    const scalar& m20, const scalar& m21, const scalar& m22, const scalar& m23,
    const scalar& m30, const scalar& m31, const scalar& m32, const scalar& m33
) : mat_base(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33)
{}

}
