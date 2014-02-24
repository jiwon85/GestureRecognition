/* Auto-generated by genmsg_cpp for file /home/fri/gestureRecognition/GestureRecognition/skeleton_markers/msg/Skeleton.msg */
#ifndef SKELETON_MARKERS_MESSAGE_SKELETON_H
#define SKELETON_MARKERS_MESSAGE_SKELETON_H
#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "ros/serialization.h"
#include "ros/builtin_message_traits.h"
#include "ros/message_operations.h"
#include "ros/time.h"

#include "ros/macros.h"

#include "ros/assert.h"

#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Quaternion.h"

namespace skeleton_markers
{
template <class ContainerAllocator>
struct Skeleton_ {
  typedef Skeleton_<ContainerAllocator> Type;

  Skeleton_()
  : header()
  , user_id(0)
  , name()
  , confidence()
  , position()
  , orientation()
  {
  }

  Skeleton_(const ContainerAllocator& _alloc)
  : header(_alloc)
  , user_id(0)
  , name(_alloc)
  , confidence(_alloc)
  , position(_alloc)
  , orientation(_alloc)
  {
  }

  typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
   ::std_msgs::Header_<ContainerAllocator>  header;

  typedef int32_t _user_id_type;
  int32_t user_id;

  typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _name_type;
  std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  name;

  typedef std::vector<float, typename ContainerAllocator::template rebind<float>::other >  _confidence_type;
  std::vector<float, typename ContainerAllocator::template rebind<float>::other >  confidence;

  typedef std::vector< ::geometry_msgs::Vector3_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Vector3_<ContainerAllocator> >::other >  _position_type;
  std::vector< ::geometry_msgs::Vector3_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Vector3_<ContainerAllocator> >::other >  position;

  typedef std::vector< ::geometry_msgs::Quaternion_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Quaternion_<ContainerAllocator> >::other >  _orientation_type;
  std::vector< ::geometry_msgs::Quaternion_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::geometry_msgs::Quaternion_<ContainerAllocator> >::other >  orientation;


  typedef boost::shared_ptr< ::skeleton_markers::Skeleton_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::skeleton_markers::Skeleton_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct Skeleton
typedef  ::skeleton_markers::Skeleton_<std::allocator<void> > Skeleton;

typedef boost::shared_ptr< ::skeleton_markers::Skeleton> SkeletonPtr;
typedef boost::shared_ptr< ::skeleton_markers::Skeleton const> SkeletonConstPtr;


template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const  ::skeleton_markers::Skeleton_<ContainerAllocator> & v)
{
  ros::message_operations::Printer< ::skeleton_markers::Skeleton_<ContainerAllocator> >::stream(s, "", v);
  return s;}

} // namespace skeleton_markers

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::Skeleton_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::Skeleton_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::skeleton_markers::Skeleton_<ContainerAllocator> > {
  static const char* value() 
  {
    return "34722af981b6a61700ff31df5a97c2e0";
  }

  static const char* value(const  ::skeleton_markers::Skeleton_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x34722af981b6a617ULL;
  static const uint64_t static_value2 = 0x00ff31df5a97c2e0ULL;
};

template<class ContainerAllocator>
struct DataType< ::skeleton_markers::Skeleton_<ContainerAllocator> > {
  static const char* value() 
  {
    return "skeleton_markers/Skeleton";
  }

  static const char* value(const  ::skeleton_markers::Skeleton_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::skeleton_markers::Skeleton_<ContainerAllocator> > {
  static const char* value() 
  {
    return "Header header\n\
int32 user_id\n\
string[] name\n\
float32[] confidence\n\
geometry_msgs/Vector3[] position\n\
geometry_msgs/Quaternion[] orientation\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.secs: seconds (stamp_secs) since epoch\n\
# * stamp.nsecs: nanoseconds since stamp_secs\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
\n\
";
  }

  static const char* value(const  ::skeleton_markers::Skeleton_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct HasHeader< ::skeleton_markers::Skeleton_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct HasHeader< const ::skeleton_markers::Skeleton_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::skeleton_markers::Skeleton_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.header);
    stream.next(m.user_id);
    stream.next(m.name);
    stream.next(m.confidence);
    stream.next(m.position);
    stream.next(m.orientation);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct Skeleton_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::skeleton_markers::Skeleton_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const  ::skeleton_markers::Skeleton_<ContainerAllocator> & v) 
  {
    s << indent << "header: ";
s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "user_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.user_id);
    s << indent << "name[]" << std::endl;
    for (size_t i = 0; i < v.name.size(); ++i)
    {
      s << indent << "  name[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name[i]);
    }
    s << indent << "confidence[]" << std::endl;
    for (size_t i = 0; i < v.confidence.size(); ++i)
    {
      s << indent << "  confidence[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.confidence[i]);
    }
    s << indent << "position[]" << std::endl;
    for (size_t i = 0; i < v.position.size(); ++i)
    {
      s << indent << "  position[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Vector3_<ContainerAllocator> >::stream(s, indent + "    ", v.position[i]);
    }
    s << indent << "orientation[]" << std::endl;
    for (size_t i = 0; i < v.orientation.size(); ++i)
    {
      s << indent << "  orientation[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::geometry_msgs::Quaternion_<ContainerAllocator> >::stream(s, indent + "    ", v.orientation[i]);
    }
  }
};


} // namespace message_operations
} // namespace ros

#endif // SKELETON_MARKERS_MESSAGE_SKELETON_H

