// Lidar single point data structure NeuUnit
//
typedef struct NEUV_UNIT{
    // value of x, y, and z in point cloud 3d coordinate system
    int x;    
    int y;
    int z;

    // The RGB color value R of the point after video fusion
    uint8_t r; 
    uint8_t g;
    uint8_t b;

    /* uint8_6 lid; // internal call */
    uint8_t lid; // ? 
    uint8_t apd_id; // internal call
    
    uint16_t row; // the row value of the point
    uint16_t col; // the value of the column where the point is located

    uint32_t tof; //light light time
    
    uint8_t intensity; // reflectance value
    uint32_t timestamp; // timestamp

    uint8_t level; // internal call
    uint8_t tofts; // internal call
    uint8_t intensityts; // internal call 
}NeuvUnit;


// IMU data
typedef struct IMU_DATA{
    int32_t sec; // timestamp, seconds
    int32_t usec; // timestamp, microseconds
		  
    // 3d Cartesian roll coordinates, roll, yaw, and pitch
    int32_t roll;
    int32_t yaw;
    int32_t pitch;

    // four elements i, j, k, r
    int16_t quat_i; 
    int16_t quat_j;
    int16_t quat_k;
    int16_t quat_r;
}ImuData;

// GPS Data NeuGPRMC
typedef struct GPRMC{
    // Status: A = positioned, V = unpositioned
    uint8_t status;

    double utc; // UTC time
    
    // North and south latitude N/S
    char lat;
    // East and west longitude E/W
    char lon;

    // Latitude and longitude ddmm.mmmm, in degrees and minutes format
    double latitude;
    double longitude;

    double speed; //speed, knots, Knots
    double cource; // azimuth, degrees

    // UTC date in DDMMYY format
    uint32_t ddmmyy; 

    // Magnetic declination, (000-180) degrees
    double variation;

    // Magnetic declination direction, E = East, W = West
    char vardirection;

    char checksum; // Check code
}NeuGPRMC;

// Lidar status
typedef struct LASER_STATUS{
    uint8_t state; // Laser status on/off

    float temperature; // Laser temperature (Celsius degree)
    uint16_t pulserate; // Laser repetition rate (kHZ)

    uint16_t powervoltage; // Laser voltage (mV)
    uint16_t firstcurrent; // Laser primary current (mA)
    uint16_t secondcurrent; // Laser secondary current (Ma, default)
    float pulsewidth; // Laser pulse width ns
    uint16_t laserpower; // laser power (mW)

    float boardtemp; // Floor temperature
    float probe1temp; // Scan mirror 1 temperature
    float probe2temp; // Scan mirror 2 temperature
    float fpgatemp; // Core board temperature

    uint8_t evk1status; // Scan mirror 1 status
    uint8_t evk2status; // Scan mirror 2 status

    uint8_t spistatus; // SPI configuration status
    uint8_t imustatus; // IMU status
    uint32_t launchtimes; // Laser launch times per second
}NeuLaserStatus;

// Lidar information and status
typedef struct LIDAR_INFO_STATUS{

    // Product information:
    // -------------------
    // device model, serial number, manufacture, production date,
    // hardware version, software version, authntication code
    char device_type[32];
    char serial_number[32];
    char manufacture[32];
    char date_of_manufacture[32];
    char hardware_ver[32];
    char software_ver[32];
    char auth_code[32];

    // Horizontal and vertical field of view
    uint8_t horizontal_fov;
    uint8_t vertical_fov;

    // Maximum distance @500KHZ @10% reflectance (m)
    uint32_t max_distance;

    uint16_t accuracy; // Accuracy (mm) 
    uint16_t wave_length; // Laser wavelength (nm)

    uint32_t curr_time; // Current Lidar time UTC seconds
    uint32_t power_on_time; //Lidar start time UTC seconds

    uint16_t laser_power; // Laser power percentage
    uint16_t fps; // Frame rate
    uint16_t laser_rate; // Laser repetition rate

    uint8_t cam_status; // Camera switch status
    uint8_t lidar_status; // Laser switch status

    float lidar_temperature; // Laser temperature
}LidarInfoStatus;
