/* Auto-generated by genmsg_cpp for file /home/fri/ros/GestureRecognition/skeleton_markers/srv/skeleton_listener_service.srv */
#ifndef SKELETON_MARKERS_SERVICE_SKELETON_LISTENER_SERVICE_H
#define SKELETON_MARKERS_SERVICE_SKELETON_LISTENER_SERVICE_H
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

#include "ros/service_traits.h"




namespace skeleton_markers
{
template <class ContainerAllocator>
struct skeleton_listener_serviceRequest_ {
  typedef skeleton_listener_serviceRequest_<ContainerAllocator> Type;

  skeleton_listener_serviceRequest_()
  : randomArr(0)
  , randomGes(0)
  , state(0)
  {
  }

  skeleton_listener_serviceRequest_(const ContainerAllocator& _alloc)
  : randomArr(0)
  , randomGes(0)
  , state(0)
  {
  }

  typedef int64_t _randomArr_type;
  int64_t randomArr;

  typedef int64_t _randomGes_type;
  int64_t randomGes;

  typedef int64_t _state_type;
  int64_t state;


  typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct skeleton_listener_serviceRequest
typedef  ::skeleton_markers::skeleton_listener_serviceRequest_<std::allocator<void> > skeleton_listener_serviceRequest;

typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceRequest> skeleton_listener_serviceRequestPtr;
typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceRequest const> skeleton_listener_serviceRequestConstPtr;



template <class ContainerAllocator>
struct skeleton_listener_serviceResponse_ {
  typedef skeleton_listener_serviceResponse_<ContainerAllocator> Type;

  skeleton_listener_serviceResponse_()
  : flag(false)
  , success(false)
  {
  }

  skeleton_listener_serviceResponse_(const ContainerAllocator& _alloc)
  : flag(false)
  , success(false)
  {
  }

  typedef uint8_t _flag_type;
  uint8_t flag;

  typedef uint8_t _success_type;
  uint8_t success;


  typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator>  const> ConstPtr;
  boost::shared_ptr<std::map<std::string, std::string> > __connection_header;
}; // struct skeleton_listener_serviceResponse
typedef  ::skeleton_markers::skeleton_listener_serviceResponse_<std::allocator<void> > skeleton_listener_serviceResponse;

typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceResponse> skeleton_listener_serviceResponsePtr;
typedef boost::shared_ptr< ::skeleton_markers::skeleton_listener_serviceResponse const> skeleton_listener_serviceResponseConstPtr;


struct skeleton_listener_service
{

typedef skeleton_listener_serviceRequest Request;
typedef skeleton_listener_serviceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;
}; // struct skeleton_listener_service
} // namespace skeleton_markers

namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "dc272c5eafc32ad5db952c5a1d236447";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0xdc272c5eafc32ad5ULL;
  static const uint64_t static_value2 = 0xdb952c5a1d236447ULL;
};

template<class ContainerAllocator>
struct DataType< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "skeleton_markers/skeleton_listener_serviceRequest";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "int64 randomArr\n\
int64 randomGes\n\
int64 state\n\
\n\
";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros


namespace ros
{
namespace message_traits
{
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > : public TrueType {};
template<class ContainerAllocator> struct IsMessage< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator>  const> : public TrueType {};
template<class ContainerAllocator>
struct MD5Sum< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "91a5689a10e16d9b12670dd6bfaacabb";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> &) { return value(); } 
  static const uint64_t static_value1 = 0x91a5689a10e16d9bULL;
  static const uint64_t static_value2 = 0x12670dd6bfaacabbULL;
};

template<class ContainerAllocator>
struct DataType< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "skeleton_markers/skeleton_listener_serviceResponse";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct Definition< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "bool flag\n\
bool success\n\
\n\
\n\
";
  }

  static const char* value(const  ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator> struct IsFixedSize< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > : public TrueType {};
} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.randomArr);
    stream.next(m.randomGes);
    stream.next(m.state);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct skeleton_listener_serviceRequest_
} // namespace serialization
} // namespace ros


namespace ros
{
namespace serialization
{

template<class ContainerAllocator> struct Serializer< ::skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> >
{
  template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
  {
    stream.next(m.flag);
    stream.next(m.success);
  }

  ROS_DECLARE_ALLINONE_SERIALIZER;
}; // struct skeleton_listener_serviceResponse_
} // namespace serialization
} // namespace ros

namespace ros
{
namespace service_traits
{
template<>
struct MD5Sum<skeleton_markers::skeleton_listener_service> {
  static const char* value() 
  {
    return "02ed10f1db63e4153feab56164fcc314";
  }

  static const char* value(const skeleton_markers::skeleton_listener_service&) { return value(); } 
};

template<>
struct DataType<skeleton_markers::skeleton_listener_service> {
  static const char* value() 
  {
    return "skeleton_markers/skeleton_listener_service";
  }

  static const char* value(const skeleton_markers::skeleton_listener_service&) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "02ed10f1db63e4153feab56164fcc314";
  }

  static const char* value(const skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> > {
  static const char* value() 
  {
    return "skeleton_markers/skeleton_listener_service";
  }

  static const char* value(const skeleton_markers::skeleton_listener_serviceRequest_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct MD5Sum<skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "02ed10f1db63e4153feab56164fcc314";
  }

  static const char* value(const skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> &) { return value(); } 
};

template<class ContainerAllocator>
struct DataType<skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> > {
  static const char* value() 
  {
    return "skeleton_markers/skeleton_listener_service";
  }

  static const char* value(const skeleton_markers::skeleton_listener_serviceResponse_<ContainerAllocator> &) { return value(); } 
};

} // namespace service_traits
} // namespace ros

#endif // SKELETON_MARKERS_SERVICE_SKELETON_LISTENER_SERVICE_H

