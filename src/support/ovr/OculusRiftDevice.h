/*
 * Copyright (c) 2013-2014 Geocent - Published under the MIT License.
 * See LICENSE for the full text of the license.
 */

#ifndef SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
#define SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_

#include <string>

#include "HMDDevice.h"
#include "OVR.h"

class OculusDeviceOrientation : public HMDDeviceOrientation {
 public:
    float* getYawReference() { return &this->_yaw; }
    float* getPitchReference() { return &this->_pitch; }
    float* getRollReference() { return &this->_roll; }
};

class OculusDevicePosition : public HMDDevicePosition {
 public:
    float* getXReference() { return &this->_x; }
    float* getYReference() { return &this->_y; }
    float* getZReference() { return &this->_z; }
};

class OculusRiftDevice : public HMDDevice {
 private:
    ovrHmd _hmd;
    OculusDeviceOrientation _deviceOrientation;
    OculusDevicePosition _devicePosition;

    void updateDevice();
 public:
    static const std::string classToken;

    OculusRiftDevice();
    ~OculusRiftDevice();
    void getDeviceInfo(HMDDeviceInfo* deviceInfo);
    void getDeviceOrientation(HMDDeviceOrientation* deviceOrientation);
    void getDevicePosition(HMDDevicePosition* devicePosition);
    void getDeviceQuat(HMDDeviceQuat* deviceQuat);
};

#endif  // SRC_SUPPORT_OVR_OCULUSRIFTDEVICE_H_
