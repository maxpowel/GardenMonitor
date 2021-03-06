//
// Created by alvaro on 8/08/15.
//

#include "BMP180Device.h"
#include "quantities.h"

BMP180Device::BMP180Device(){
    sensor_ = new Adafruit_BMP085_Unified();
    sensor_->begin();
}

const char * BMP180Device::getName(){
    return "bmp180";
}

const char * BMP180Device::getSensorType(){
    return "BMP180";
}

int BMP180Device::getValues(float *values){
    sensors_event_t event;
    sensor_->getEvent(&event);

    values[0] = event.pressure;
    float temperature;
    sensor_->getTemperature(&temperature);
    values[1] = temperature;

    return 2;
}

const int BMP180Device::getSensorQuantities(int quantities[]){
    quantities[0] = PRESSURE;
    quantities[1] = TEMPERATURE;
    return 2;
}

int BMP180Device::totalValues() {
    return 2;
}