/*
 * Copyright (c) 2013 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef HMDMANAGERWRAP_H
#define HMDMANAGERWRAP_H

#include <node.h>
#include <nan.h>
 
#include "HMDDevice.h"

using namespace v8;

/*! \struct AsyncDeviceRequest
 * 
 * Struct designed to handle state and data associated with asynchronous device communication requests.
 */
// struct AsyncDeviceRequest {
// 	uv_work_t workRequest;
// 	Persistent<Function> callback;
// 	const Arguments* context;

// 	HMDDevice* hmdDevice;
// 	void* requestData;
// };

/*! \class HMDManagerWrap
 * 
 * Node wrapped object class which acts as the main interface for the node-hmd module.
 */
class HMDManagerWrap : public node::ObjectWrap {
	private:
		HMDDevice* _hmdDevice;

		HMDManagerWrap(const char* classToken);
  		~HMDManagerWrap();
		static Persistent<Function> constructor;

  // 		static Handle<Value> GetDeviceInfoAsync(const Arguments& args);
		// static void GetDeviceInfoRequestAsync(uv_work_t *r);
		// static void GetDeviceInfoRequestAfterAsync(uv_work_t *r);
  // 		static Handle<Value> GetDeviceInfoSync(const Arguments& args);

  // 		static Handle<Value> GetDeviceOrientationAsync(const Arguments& args);
		// static void GetDeviceOrientationRequestAsync(uv_work_t *r);
		// static void GetDeviceOrientationRequestAfterAsync(uv_work_t *r);
  		static NAN_METHOD(GetDeviceOrientationSync);

	public:
  		static void Initialize(Handle<Object> target);
		static NAN_METHOD(New);
		HMDDevice* GetDevice();
};

#endif