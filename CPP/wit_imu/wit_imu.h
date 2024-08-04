/*
 * @Author: Ashington ashington258@proton.me
 * @Date: 2024-08-04 17:09:14
 * @LastEditors: Ashington ashington258@proton.me
 * @LastEditTime: 2024-08-04 18:32:40
 * @FilePath: \WIT_IMU\CPP\wit_imu\wit_imu.h
 * @Description: 请填写简介
 * 联系方式:921488837@qq.com
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
#ifndef WIT_IMU_H
#define WIT_IMU_H

#include <stdint.h>

#ifdef __cplusplus

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

// C 接口函数声明
extern "C"
{
    IMUData *createIMUData();                             // 创建 IMUData 实例
    void destroyIMUData(IMUData *imu);                    // 销毁 IMUData 实例
    int parseIMUData(IMUData *imu, unsigned char data[]); // 解析 IMU 数据
}

#endif // __cplusplus

#endif // WIT_IMU_H
