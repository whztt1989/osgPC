#pragma once
#include "utility.h"
#include "ShareDataSingleton.h"

#include <osg/Drawable>
#include <osg/RenderInfo>
#include <osg/Object>
#include <osg/BufferObject>
#include <osg/Geometry>


namespace osgPC{ //namespace osgPC

/**
 * Deprecated. 2014.01.02
 * Render Point Cloud by using openGL code directly, other than OSG function.
 * New Class PointCloudGeometry is recommended.
 * Because PointCloudGeometry support better pick handler and more function supplied by OSG.
**/


class OSG_EXPORT PointCloudGeometry :
    public osg::Geometry
{
public:
    PointCloudGeometry();
    PointCloudGeometry(const PointCloudGeometry& pointcloud, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
    META_Object(osgPC, PointCloudGeometry);

    void setPointCloud(osg::Vec3Array* points, const Bounds3d& bounds, osg::Vec3 offset,
		unsigned short* intensities = nullptr, osg::Vec3Array* texColors = nullptr, OBJECTCLASS* c = nullptr);
    osg::Vec3Array* getPointCloud() const { return _points; }
    osg::Vec3Array* getPointCloudTexColors() const { return _texColors;  }
    osg::Vec3d	getOffset() const { return _offset; }
	Bounds3d	getBound() const { return _bounds; }
	unsigned short*	getIntensities() const { return _intensities; }

	void refreshDisplayMode(osgPC::pointColorMode cm);
	
protected:
    ~PointCloudGeometry(void);

private:
	void setColorsByAssignColor();
	void setColorsByTexture();
	void setColorsByHeight();
	void setColorByClass();
	void setColorsByIntensity();

    osg::ref_ptr<osg::Vec3Array>    _points;
    osg::ref_ptr<osg::Vec3Array>    _texColors;
	osg::ref_ptr<osg::Vec3Array>	_assignColors;
    Bounds3d			            _bounds;
    unsigned short*		            _intensities;
    osg::Vec3                       _offset;
	OBJECTCLASS*					_cs;
};

}//end namespace osgPC