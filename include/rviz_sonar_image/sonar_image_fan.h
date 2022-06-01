#ifndef RVIZ_SONAR_IMAGE_SONAR_IMAGE_VISUAL_H
#define RVIZ_SONAR_IMAGE_SONAR_IMAGE_VISUAL_H

#include <acoustic_msgs/RawSonarImage.h>

#include <OgreColourValue.h>
#include <OgreMaterial.h>


namespace Ogre
{
  class SceneManager;
  class SceneNode;
  class ManualObject;
  class Vector3;
  class Quaternion;
}

namespace rviz
{
  class MeshShape;
  class ROSImageTexture;
}

namespace rviz_sonar_image
{
class ColorMap;

class SonarImageFan
{
public:
  SonarImageFan( Ogre::SceneManager* scene_manager, Ogre::SceneNode* parent_node, std::shared_ptr<ColorMap> color_map);
  ~SonarImageFan();

  // if beam_number is negative, show all beams in the XY plane, otherwise
  // show selected beam in the XZ plane.
  void setMessage(const acoustic_msgs::RawSonarImage::ConstPtr& msg, uint32_t start_row, uint32_t end_row);

  void setFramePosition( const Ogre::Vector3& position );
  void setFrameOrientation( const Ogre::Quaternion& orientation );

private:
  Ogre::SceneNode* frame_node_;

  // The SceneManager, kept here only so the destructor can ask it to
  // destroy the ``frame_node_``.
  Ogre::SceneManager* scene_manager_;

  rviz::MeshShape* mesh_shape_;

  rviz::ROSImageTexture* texture_;
  std::shared_ptr<ColorMap> color_map_;
  float alpha_ = 0.8;
};

} // namespace rviz_sonar_image

#endif