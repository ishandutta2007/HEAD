// Generated by gencpp from file performances/SpeechOn.msg
// DO NOT EDIT!


#ifndef PERFORMANCES_MESSAGE_SPEECHON_H
#define PERFORMANCES_MESSAGE_SPEECHON_H

#include <ros/service_traits.h>


#include <performances/SpeechOnRequest.h>
#include <performances/SpeechOnResponse.h>


namespace performances
{

struct SpeechOn
{

typedef SpeechOnRequest Request;
typedef SpeechOnResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SpeechOn
} // namespace performances


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::performances::SpeechOn > {
  static const char* value()
  {
    return "5e0f7ed055cc5952042284a15e187ee8";
  }

  static const char* value(const ::performances::SpeechOn&) { return value(); }
};

template<>
struct DataType< ::performances::SpeechOn > {
  static const char* value()
  {
    return "performances/SpeechOn";
  }

  static const char* value(const ::performances::SpeechOn&) { return value(); }
};


// service_traits::MD5Sum< ::performances::SpeechOnRequest> should match 
// service_traits::MD5Sum< ::performances::SpeechOn > 
template<>
struct MD5Sum< ::performances::SpeechOnRequest>
{
  static const char* value()
  {
    return MD5Sum< ::performances::SpeechOn >::value();
  }
  static const char* value(const ::performances::SpeechOnRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::performances::SpeechOnRequest> should match 
// service_traits::DataType< ::performances::SpeechOn > 
template<>
struct DataType< ::performances::SpeechOnRequest>
{
  static const char* value()
  {
    return DataType< ::performances::SpeechOn >::value();
  }
  static const char* value(const ::performances::SpeechOnRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::performances::SpeechOnResponse> should match 
// service_traits::MD5Sum< ::performances::SpeechOn > 
template<>
struct MD5Sum< ::performances::SpeechOnResponse>
{
  static const char* value()
  {
    return MD5Sum< ::performances::SpeechOn >::value();
  }
  static const char* value(const ::performances::SpeechOnResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::performances::SpeechOnResponse> should match 
// service_traits::DataType< ::performances::SpeechOn > 
template<>
struct DataType< ::performances::SpeechOnResponse>
{
  static const char* value()
  {
    return DataType< ::performances::SpeechOn >::value();
  }
  static const char* value(const ::performances::SpeechOnResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // PERFORMANCES_MESSAGE_SPEECHON_H