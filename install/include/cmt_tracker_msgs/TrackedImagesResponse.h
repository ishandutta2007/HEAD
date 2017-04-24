// Generated by gencpp from file cmt_tracker_msgs/TrackedImagesResponse.msg
// DO NOT EDIT!


#ifndef CMT_TRACKER_MSGS_MESSAGE_TRACKEDIMAGESRESPONSE_H
#define CMT_TRACKER_MSGS_MESSAGE_TRACKEDIMAGESRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sensor_msgs/Image.h>

namespace cmt_tracker_msgs
{
template <class ContainerAllocator>
struct TrackedImagesResponse_
{
  typedef TrackedImagesResponse_<ContainerAllocator> Type;

  TrackedImagesResponse_()
    : names()
    , image()  {
    }
  TrackedImagesResponse_(const ContainerAllocator& _alloc)
    : names(_alloc)
    , image(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > , typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::other >  _names_type;
  _names_type names;

   typedef std::vector< ::sensor_msgs::Image_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sensor_msgs::Image_<ContainerAllocator> >::other >  _image_type;
  _image_type image;




  typedef boost::shared_ptr< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> const> ConstPtr;

}; // struct TrackedImagesResponse_

typedef ::cmt_tracker_msgs::TrackedImagesResponse_<std::allocator<void> > TrackedImagesResponse;

typedef boost::shared_ptr< ::cmt_tracker_msgs::TrackedImagesResponse > TrackedImagesResponsePtr;
typedef boost::shared_ptr< ::cmt_tracker_msgs::TrackedImagesResponse const> TrackedImagesResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace cmt_tracker_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'opencv_apps': ['/opt/ros/indigo/share/opencv_apps/cmake/../msg'], 'cmt_tracker_msgs': ['/home/icog-labs/hansonrobotics/HEAD/src/vision/cmt_tracker_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "836f70b8a7116abf1e74a5108693355e";
  }

  static const char* value(const ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x836f70b8a7116abfULL;
  static const uint64_t static_value2 = 0x1e74a5108693355eULL;
};

template<class ContainerAllocator>
struct DataType< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cmt_tracker_msgs/TrackedImagesResponse";
  }

  static const char* value(const ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string[] names\n\
sensor_msgs/Image[] image\n\
\n\
================================================================================\n\
MSG: sensor_msgs/Image\n\
# This message contains an uncompressed image\n\
# (0, 0) is at top-left corner of image\n\
#\n\
\n\
Header header        # Header timestamp should be acquisition time of image\n\
                     # Header frame_id should be optical frame of camera\n\
                     # origin of frame should be optical center of cameara\n\
                     # +x should point to the right in the image\n\
                     # +y should point down in the image\n\
                     # +z should point into to plane of the image\n\
                     # If the frame_id here and the frame_id of the CameraInfo\n\
                     # message associated with the image conflict\n\
                     # the behavior is undefined\n\
\n\
uint32 height         # image height, that is, number of rows\n\
uint32 width          # image width, that is, number of columns\n\
\n\
# The legal values for encoding are in file src/image_encodings.cpp\n\
# If you want to standardize a new string format, join\n\
# ros-users@lists.sourceforge.net and send an email proposing a new encoding.\n\
\n\
string encoding       # Encoding of pixels -- channel meaning, ordering, size\n\
                      # taken from the list of strings in include/sensor_msgs/image_encodings.h\n\
\n\
uint8 is_bigendian    # is this data bigendian?\n\
uint32 step           # Full row length in bytes\n\
uint8[] data          # actual matrix data, size is (step * rows)\n\
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
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.names);
      stream.next(m.image);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TrackedImagesResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cmt_tracker_msgs::TrackedImagesResponse_<ContainerAllocator>& v)
  {
    s << indent << "names[]" << std::endl;
    for (size_t i = 0; i < v.names.size(); ++i)
    {
      s << indent << "  names[" << i << "]: ";
      Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.names[i]);
    }
    s << indent << "image[]" << std::endl;
    for (size_t i = 0; i < v.image.size(); ++i)
    {
      s << indent << "  image[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sensor_msgs::Image_<ContainerAllocator> >::stream(s, indent + "    ", v.image[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CMT_TRACKER_MSGS_MESSAGE_TRACKEDIMAGESRESPONSE_H