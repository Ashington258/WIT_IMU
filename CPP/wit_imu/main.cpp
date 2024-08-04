#include "wit_imu.h"

int main()
{
    IMUData imuData;
    unsigned char data[34]; // 假设数据长度为34
    // 填充数据...

    if (imuData.parseIMUData(data))
    {
        // 处理解析后的数据
    }

    return 0;
}
