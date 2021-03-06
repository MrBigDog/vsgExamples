#include <vsg/core/ref_ptr.h>
#include <vsg/core/observer_ptr.h>
#include <vsg/core/Object.h>
#include <vsg/core/Auxiliary.h>
#include <vsg/core/Visitor.h>

#include <vsg/maths/vec2.h>
#include <vsg/maths/vec3.h>
#include <vsg/maths/vec4.h>
#include <vsg/maths/mat4.h>
#include <vsg/maths/transform.h>

#include <vsg/io/stream.h>

#include <iostream>
#include <vector>
#include <chrono>
#include <cstddef>

int main(int /*argc*/, char** /*argv*/)
{

    vsg::vec2 v;

    v.x = 10.1f;
    v.y = 12.2f;


    std::cout<<"vec2(x="<<v.x<<", y="<<v.y<<")"<<std::endl;
    std::cout<<"vec2(r="<<v.r<<", g="<<v.g<<")"<<std::endl;
    std::cout<<"vec2(s="<<v.s<<", t="<<v.t<<")"<<std::endl;
    std::cout<<"vec2[0]=("<<v[0]<<", "<<v[1]<<")"<<std::endl;

    vsg::dvec3 n(2.0, 1.0, 0.5);
    std::cout<<"n(x="<<n.x<<", y="<<n.y<<", z="<<n.z<<")"<<std::endl;

    std::cout<<"n = "<<n<<std::endl;

    vsg::t_vec2<int> iv(2, 1);
    std::cout<<"iv = "<<iv<<std::endl;


    vsg::dvec4 colour(1.0, 0.9, 1.0, 0.5);
    std::cout<<"colour = ("<<colour<<")"<<std::endl;

    vsg::dmat4 mat;
    mat(3,0) = 102.3;
    std::cout<<"mat = "<<mat<<std::endl;

    vsg::t_mat4<short> cmat;
    std::cout<<"cmat = "<<cmat<<std::endl;
    std::cout<<"sizeof(cmat) = "<<sizeof(cmat)<<std::endl;

    vsg::ref_ptr<vsg::Object> object(new vsg::Object());
    object->setValue("matrix", mat);

    vsg::mat4 new_mat;
    if (object->getValue("matrix", new_mat))
    {
        std::cout<<"getValue(\"matrix\""<<new_mat<<std::endl;
    }


    vsg::mat4 proj = vsg::perspective(vsg::radians(45.0), 2.0, 0.1, 10.0);
    std::cout<<"proj = {"<<std::endl<<proj<<"}"<<std::endl;


    vsg::mat4 view = vsg::lookAt(vsg::vec3(2.0f, 2.0f, 2.0f), vsg::vec3(0.0f, 0.0f, 0.0f), vsg::vec3(0.0f, 0.0f, 1.0f));
    std::cout<<"view = {"<<std::endl<<view<<"}"<<std::endl;

    vsg::mat4 rot = vsg::rotate(vsg::radians(45.0f), 0.0f, 0.0f, 1.0f);
    std::cout<<"rot = {"<<rot<<"}"<<std::endl;

    constexpr vsg::mat4 trans = vsg::translate(vsg::vec3(1.0f, 2.0f, 3.0f));
    std::cout<<"trans = {"<<trans<<"}"<<std::endl;

    constexpr vsg::mat4 scale = vsg::scale(vsg::vec3(1.0f, 2.0f, 3.0f));
    std::cout<<"scale = {"<<scale<<"}"<<std::endl;

    // note VSG and OSG multiplication order reversed.
    vsg::mat4 result = scale*trans*rot;
    std::cout<<"result = {"<<result<<"}"<<std::endl;


    return 0;
}
