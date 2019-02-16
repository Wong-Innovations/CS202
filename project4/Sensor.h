#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
public:
    // Default Constructor
    Sensor();

    // Parametized Constructor
    Sensor(char* type, float extracost);

    // Setters
    void setType();
    void setExtracost();

    // Getters
    char* getType();
    float getExtraCost();

private:
    char m_type[256];
    float m_extracost;
    static int gps_cnt;
    static int camera_cnt;
    static int lidar_cnt;
    static int radar_cnt;
};


#endif