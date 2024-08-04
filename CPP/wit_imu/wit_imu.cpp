/*
 * @Author: Ashington ashington258@proton.me
 * @Date: 2024-08-04 17:09:24
 * @LastEditors: Ashington ashington258@proton.me
 * @LastEditTime: 2024-08-04 17:25:10
 * @FilePath: \WIT_IMU\CPP\wit_imu.cpp
 * @Description: 请填写简介
 * 联系方式:921488837@qq.com
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
 */
// wit_imu.cpp
#include "wit_imu.h"

// 计算校验和函数
unsigned char IMUData::calculateChecksum(unsigned char data[]) {
    unsigned char checksum = 0;
    for (int i = 0; i < 10; i++) {
        checksum += data[i];
    }
    return checksum;
}

// 解析加速度数据函数
int IMUData::parseAccelData(unsigned char data[]) {
    if (calculateChecksum(data) != data[10]) {
        return 0;
    }
    short accelX_raw = (data[3] << 8) | data[2];
    accel.accelX = (float)accelX_raw / 32768.0 * 16.0;
    short accelY_raw = (data[5] << 8) | data[4];
    accel.accelY = (float)accelY_raw / 32768.0 * 16.0;
    short accelZ_raw = (data[7] << 8) | data[6];
    accel.accelZ = (float)accelZ_raw / 32768.0 * 16.0;
    short temp_raw = (data[9] << 8) | data[8];
    accel.temperature = (float)temp_raw / 100.0;
    return 1;
}

// 解析角速度数据函数
int IMUData::parseGyroData(unsigned char data[]) {
    if (calculateChecksum(data) != data[10]) {
        return 0;
    }
    short gyroX_raw = (data[3] << 8) | data[2];
    gyro.gyroX = (float)gyroX_raw / 32768.0 * 2000.0;
    short gyroY_raw = (data[5] << 8) | data[4];
    gyro.gyroY = (float)gyroY_raw / 32768.0 * 2000.0;
    short gyroZ_raw = (data[7] << 8) | data[6];
    gyro.gyroZ = (float)gyroZ_raw / 32768.0 * 2000.0;
    gyro.voltage = 0.0;
    return 1;
}

// 解析角度数据函数
int IMUData::parseAngleData(unsigned char data[]) {
    if (calculateChecksum(data) != data[10]) {
        return 0;
    }
    short roll_raw = (data[3] << 8) | data[2];
    angle.roll = (float)roll_raw / 32768.0 * 180.0;
    short pitch_raw = (data[5] << 8) | data[4];
    angle.pitch = (float)pitch_raw / 32768.0 * 180.0;
    short yaw_raw = (data[7] << 8) | data[6];
    angle.yaw = (float)yaw_raw / 32768.0 * 180.0;
    angle.version = (data[9] << 8) | data[8];
    return 1;
}

// 解析磁场数据函数
int IMUData::parseMagData(unsigned char data[]) {
    if (calculateChecksum(data) != data[10]) {
        return 0;
    }
    short magX_raw = (data[3] << 8) | data[2];
    mag.magX = (float)magX_raw;
    short magY_raw = (data[5] << 8) | data[4];
    mag.magY = (float)magY_raw;
    short magZ_raw = (data[7] << 8) | data[6];
    mag.magZ = (float)magZ_raw;
    short temp_raw = (data[9] << 8) | data[8];
    mag.temperature = (float)temp_raw / 100.0;
    return 1;
}

// 解析IMU数据函数
int IMUData::parseIMUData(unsigned char data[]) {
    // if (!parseAccelData(data, &accel)) return 0;
    // if (!parseGyroData(data + 11, &gyro)) return 0;
    if (!parseAngleData(data + 22)) return 0;
    // if (!parseMagData(data + 33, &mag)) return 0;
    return 1;
}
