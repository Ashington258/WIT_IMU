<!--
 * @Author: Ashington ashington258@proton.me
 * @Date: 2024-05-27 21:13:46
 * @LastEditors: Ashington ashington258@proton.me
 * @LastEditTime: 2024-08-01 11:49:55
 * @FilePath: \WIT_IMU\REDME.md
 * @Description: 请填写简介
 * 联系方式:921488837@qq.com
 * Copyright (c) 2024 by ${git_name_email}, All Rights Reserved. 
-->
# 说明

该项目为维特智能的 IMU 撰写了 API 接口

该部分主要关于解析来自 IMU 串口的数据，根据标准的解析数据流程，创建自己想要解析数据的结构体，并在进程函数中用结构体指针修改这些结构体的数据。

协议的具体格式需要查询维特智能官网。

## 注意事项

该文件已经包含了声明部分，请勿在主函数中重复声明。

## 调用示例

当串口数据传入时，选择性解析数据即可，函数高度封装

```C
uint8_t WITIMU_DATA[50];//定义一个缓冲区，用于接收串口数据
parseIMUData(WITIMU_DATA, &imuData);

```

## 注意

在接收阶段使用安全性测试`检测头帧和尾帧`，或者使用串口空闲中断和DMA，以及FIFO