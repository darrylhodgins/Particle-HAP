//
//  BH1750LightSensorAccessory.h
//  HKTester
//
//  Created by Lukas Jezny on 10/02/2019.
//  Copyright © 2019 Lukas Jezny. All rights reserved.
//

#ifndef BH1750LightSensorAccessory_hpp
#define BH1750LightSensorAccessory_hpp

#include "homekit/HKAccessory.h"
#include "HAPAccessoryDescriptor.h"
#include "BH1750/BH1750.h"

class BH1750LightSensorAccessory: public HAPAccessoryDescriptor {
private:
    BH1750 lightMeter = BH1750(0x23);
    floatCharacteristics *currentAmbilightChar;
    long lastReportMS = 0;
    long REPORT_PERIOD_MS = 5000;
    float lastValueLux = 0.0001;
    void sensorIdentity(bool oldValue, bool newValue, HKConnection *sender);
    std::string getCurrentAmbilightLevel (HKConnection *sender);
public:

    virtual void initAccessorySet();

    virtual int getDeviceType(){
        return deviceType_sensor;
    }
    virtual bool handle();
};

#endif /* BH1750LightSensorAccessory_hpp */
