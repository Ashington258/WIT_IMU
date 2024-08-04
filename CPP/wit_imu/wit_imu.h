// wit_imu.h
#ifndef WIT_IMU_H
#define WIT_IMU_H

#include <stdint.h>

class IMUData
{
public:
    struct AccelData
    {
        float accelX;
        float accelY;
        float accelZ;
        float temperature;
    };

    struct GyroData
    {
        float gyroX;
        float gyroY;
        float gyroZ;
        float voltage;
    };

    struct AngleData
    {
        float roll;
        float pitch;
        float yaw;
        int version;
    };

    struct MagData
    {
        float magX;
        float magY;
        float magZ;
        float temperature;
    };

    AccelData accel;
    GyroData gyro;
    AngleData angle;
    MagData mag;

    IMUData() {}
    ~IMUData() {}

    unsigned char calculateChecksum(unsigned char data[]);
    int parseAccelData(unsigned char data[]);
    int parseGyroData(unsigned char data[]);
    int parseAngleData(unsigned char data[]);
    int parseMagData(unsigned char data[]);
    int parseIMUData(unsigned char data[]);
};

#endif // WIT_IMU_H